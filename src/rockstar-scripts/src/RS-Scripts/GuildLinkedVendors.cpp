/*
                      ,-.        _.---._
                      |  `\.__.-''       `.
                       \  _        _  ,.   \
 ,+++=._________________)_||______|_|_||    |  ,_    _,   _, ,  ,  _, ___, _    ,_
(_.ooo.===================||======|=|=||    |  |_)  / \, /   |_/  (_,' |  '|\   |_)
   ~~'                 |  ~'      `~' o o  /  '| \ '\_/ '\_ '| \   _)  |   |-\ '| \
                        \   /~`\     o o  /    '  ` '      ` '  ` '    '   '  ` '  `
                         `~'    `-.____.-'
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question
 */
#include "StdAfx.h"
#include "Setup.h"
#include "../EAS/EasyFunctions.h"

#ifdef WIN32
#pragma warning( once : 4305 ) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#endif

class SCRIPT_DECL GLinkedVendor : public GossipScript
{
public:
	char msg[1024];

	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		/*~~~~~~~~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		uint32		TextID = 1;
		/*~~~~~~~~~~~~~~~~~~~~~*/
		/* Hello (First) Menu. */
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);
		Menu->AddItem(GOSSIP_ICON_TRAINER, "[GLV] Guild Linked Vendor <RockStar>", 30);
		Menu->AddItem(GOSSIP_ICON_VENDOR, "I would like to browse your goods", 31);
		Menu->AddItem(GOSSIP_ICON_GEAR, "[EXIT]", 99);
		if(AutoSend) Menu->SendTo(Plr);
	}
	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		Creature	*pCreature = (pObject->GetTypeId() == TYPEID_UNIT) ? (( Creature * ) pObject) : NULL;
		if(pCreature == NULL) return;
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32 reqGuildID = -1;
		uint32 reqGuildRank = -1;
		switch(IntId)
		{
		case 0:
			{
				GossipHello(pCreature, Plr, true);
			}
			break;
		case 30:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
				Menu->AddItem(GOSSIP_ICON_TRAINER, "[GLV] Guild Linked Vendor <RockStar>", 30);
				Menu->AddItem(GOSSIP_ICON_VENDOR, "I would like to browse your goods", 31);
				Menu->AddItem(GOSSIP_ICON_GEAR, "[EXIT]", 99);
				Menu->SendTo(Plr);
			}break;
		case 31:
			{
				char msg[1024];
				GuildRank * gRank = Plr->GetGuildRankS();
								int GLV_Send = 0;

				stringstream sqlQ;
				sqlQ << "SELECT reqGuildID, reqGuildRank FROM guildlinkedvendors WHERE entry = '" 
					<< pCreature->GetEntry() 
					<< "'";
				QueryResult * GLVresult = WorldDatabase.Query( sqlQ.str().c_str() );
				
				if( GLVresult )
				{
					do{
						Field *	fields	= GLVresult->Fetch();
						reqGuildID		= fields[0].GetUInt32();
						reqGuildRank	= fields[1].GetUInt32();
						if( Plr->GetGuildId() != reqGuildID && reqGuildID != 0 )
						{
							GLV_Send = 1;
						}else if( gRank->iId > reqGuildRank && reqGuildRank >= 0 ){
							GLV_Send = 2;
						}else{
							GLV_Send = 3;
						}
					}while( GLVresult->NextRow() );
					WorldDatabase.FreeQueryResult( GLVresult ); 
				}
				switch( GLV_Send )
				{
					case 0:
						sprintf(msg, "[GLV] Database error! Report on the forums!");
						break;
					case 1:
						sprintf(msg, "Sorry %s, but you do not belong to the right guild.", Plr->GetName());
						break;
					case 2:
						sprintf(msg, "Sorry %s, but you need a higher guild rank!", Plr->GetName());
						break;
					case 3:
						Plr->GetSession()->SendInventoryList(pCreature);
						break;
				}
				if( GLV_Send != 3 ) pCreature->SendChatMessageToPlayer(CHAT_MSG_MONSTER_WHISPER, LANG_UNIVERSAL, msg, Plr);
						Plr->Gossip_Complete();
			}break;	
		case 99:
			{
				Plr->Gossip_Complete();
			}break;
		}
	}
	void GossipEnd(Object *pObject, Player *Plr)
	{
		GossipScript::GossipEnd(pObject, Plr);
	}
	void Destroy()
	{
		delete this;
	}
};

void SetupGLinkedVendor(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipScript	*gs = ( GossipScript * ) new GLinkedVendor();
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	/*~~~~~~~~~~~~~~~~~~~~~~~~*/
	std::stringstream	my_sql;
	QueryResult			*result;
	/*~~~~~~~~~~~~~~~~~~~~~~~~*/
	my_sql << "SELECT entry FROM guildlinkedvendors";
	result = WorldDatabase.Query(my_sql.str().c_str());
	/*~~~~~~~~~~~*/
	uint32	Id = 0;
	/*~~~~~~~~~~~*/
	if(result)
	{
		do
		{
			Id = result->Fetch()[0].GetUInt32();
			mgr->register_gossip_script(Id, gs);
		} while(result->NextRow());
		WorldDatabase.FreeQueryResult( result );
	}
}
