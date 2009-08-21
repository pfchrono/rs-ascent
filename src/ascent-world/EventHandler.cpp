/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2008 Ascent Team <http://www.ascentemu.com/>
 *
 * Custom Commands for the RockStar WoW Funserver.
 * http://www.fishstik.ca Please do not use these scripts for any other server
 * than the RockStar Funserver(http://fishstik.ca) as they were specially
 * scripted/modded for the server in question.
 * - Midnight, Egari, T0asT, other RS GMs
 *
 */


#include "StdAfx.h"
#ifndef __EVENTHANDLER_H
	#include "EventHandler.h"
#endif

initialiseSingleton( EventIterator );
Mutex EventIterator::ItrMutex;

rsEventTeleport::rsEventTeleport()
{
	Index				=	0;
	StarterGUID			=	0;
	EventType			=	0;
	EventRestriction	=	0;
	EntryFee			=	0;
	FeeType				=	0;
	ReqEntryLevel		=	0;
	EventName			=	"";
	MapID				=	0;
	PosX				=	0.00;
	PosY				=	0.00;
	PosZ				=	0.00;
	Open				=	0;
}

EventIterator::EventIterator()
{
	LastIndex = 0;
}

void EventIterator::AddNewEvent(Player * Plr)
{
		rsEventTeleport *ET		=	new rsEventTeleport();
		ET->Index				=	LastIndex + 1;
		ET->StarterGUID			=	Plr->GetLowGUID();
		ET->EventType			=	0;
		ET->EventRestriction	=	0;
		ET->EntryFee			=	0;
		ET->FeeType				=	0;
		ET->ReqEntryLevel		=	0;
		ET->EventName			=	"";
		ET->MapID				=	Plr->GetMapId();
		ET->PosX				=	Plr->GetPositionX();
		ET->PosY				=	Plr->GetPositionY();
		ET->PosZ				=	Plr->GetPositionZ();
		ET->Open				=	0;

		EventVector.push_back(ET);
}

void EventIterator::ListEventsToPlayer(Player * Plr)
{
	if( Plr == NULL || Plr->GetSession() == NULL )
		return;

	WorldSession * pSession = Plr->GetSession();
	for(rsEventItr = EventVector.begin(); rsEventItr != EventVector.end(); rsEventItr++)
	{
		rsEventTeleport *Itr = (*rsEventItr);
		if(Itr == NULL)
			continue;
		
		Player * host = objmgr.GetPlayer( Itr->StarterGUID );
		if( !host )
			continue;

		sChatHandler.SystemMessage(pSession, "Event: %u", Itr->Index);
		sChatHandler.SystemMessage(pSession, "- ReqLvl: %u", Itr->ReqEntryLevel);
		sChatHandler.SystemMessage(pSession, "- Host: %s", host->GetName());
		sChatHandler.SystemMessage(pSession, "- Name: %s", Itr->EventName.c_str());
		sChatHandler.SystemMessage(pSession, "- Open: %u", Itr->Open);
	}
}

void EventIterator::SaveToDB()
{
	QueryBuffer * buf = NULL;
	for(rsEventItr = EventVector.begin(); rsEventItr != EventVector.end(); rsEventItr++)
	{
		rsEventTeleport *Itr = (*rsEventItr);
		if(Itr == NULL)
			continue;

		std::stringstream ss;
		ss	<< "REPLACE INTO `event_storage` VALUES ('"
			<< Itr->Index << "', '"
			<< Itr->StarterGUID << "', '"
			<< Itr->EventType << "', '"
			<< Itr->EventRestriction << "', '"
			<< Itr->EntryFee << "', '"
			<< Itr->FeeType << "', '"
			<< Itr->ReqEntryLevel << "', '"
			<< Itr->EventName << "', '"
			<< Itr->MapID << "', '"
			<< Itr->PosX << "', '"
			<< Itr->PosY << "', '"
			<< Itr->PosZ << "', '"
			<< Itr->Open << "')";

		buf->AddQueryStr(ss.str());
		if(buf)
			WorldDatabase.AddQueryBuffer(buf);
	}
}

void EventIterator::LoadEventsFromDB()
{
	QueryResult *eTeleport = WorldDatabase.Query("SELECT * FROM `event_storage`");
	ItrMutex.Acquire();
	if(EventVector.empty() == false)
	{
		for(rsEventItr = EventVector.begin(); rsEventItr != EventVector.end(); rsEventItr++)
		{
			delete (*rsEventItr);
		}
		EventVector.clear();
	}
	ItrMutex.Release();

	if(eTeleport)
	{
		do
		{
			Field *Fields = eTeleport->Fetch();
			rsEventTeleport *ET		=	new rsEventTeleport();
			ET->Index				=	Fields[0].GetUInt32();
			ET->StarterGUID			=	Fields[1].GetUInt32();
			ET->EventType			=	Fields[2].GetUInt32();
			ET->EventRestriction	=	Fields[3].GetUInt32();
			ET->EntryFee			=	Fields[4].GetUInt32();
			ET->FeeType				=	Fields[5].GetUInt32();
			ET->ReqEntryLevel		=	Fields[6].GetUInt32();
			ET->EventName			=	Fields[7].GetString();
			ET->MapID				=	Fields[8].GetUInt32();
			ET->PosX				=	Fields[9].GetFloat();
			ET->PosY				=	Fields[10].GetFloat();
			ET->PosZ				=	Fields[11].GetFloat();
			ET->Open				=	Fields[12].GetUInt32();
			
			EventVector.push_back(ET);

			LastIndex++;

		}while(eTeleport->NextRow());
	}
	WorldDatabase.FreeQueryResult(eTeleport);
}

rsEventTeleport *EventIterator::GetEventByIndex(uint32 Index)
{
	ItrMutex.Acquire();
	for(rsEventItr = EventVector.begin(); rsEventItr != EventVector.end(); rsEventItr++)
	{
		rsEventTeleport *Itr = (*rsEventItr);
		if(Itr->Index == Index)
		{
			ItrMutex.Release();
			return Itr;
		}
	}
	ItrMutex.Release();
	return NULL;
}

rsEventTeleport *EventIterator::GetEventByStarter(Player * Plr)
{
	ItrMutex.Acquire();
	for(rsEventItr = EventVector.begin(); rsEventItr != EventVector.end(); rsEventItr++)
	{
		rsEventTeleport *Itr = (*rsEventItr);
		if(Itr->StarterGUID == Plr->GetLowGUID())
		{
			ItrMutex.Release();
			return Itr;
		}
	}
	ItrMutex.Release();
	return NULL;
}

vector<rsEventTeleport*> EventIterator::GetVector()
{
	return EventVector;
}

vector<rsEventTeleport*>::iterator EventIterator::GetItr()
{
	return rsEventItr;
}
