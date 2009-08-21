/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2008 Ascent Team <http://www.ascentemu.com/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "StdAfx.h"
void WorldSession::HandleAreaTriggerOpcode(WorldPacket & recv_data)
{
	if( !_player || !_player->IsInWorld() ) 
		 return;

	CHECK_PACKET_SIZE(recv_data, 4);
	uint32 id ;
	recv_data >> id;
	_HandleAreaTriggerOpcode(id);
}

enum AreaTriggerFailures
{
	AREA_TRIGGER_FAILURE_OK				= 0,
	AREA_TRIGGER_FAILURE_UNAVAILABLE	= 1,
	AREA_TRIGGER_FAILURE_NO_BC			= 2,
	AREA_TRIGGER_FAILURE_NO_HEROIC		= 3,
	AREA_TRIGGER_FAILURE_NO_RAID		= 4,
	AREA_TRIGGER_FAILURE_NO_ATTUNE_Q	= 5,
	AREA_TRIGGER_FAILURE_NO_ATTUNE_I	= 6,
	AREA_TRIGGER_FAILURE_LEVEL			= 7,
	AREA_TRIGGER_FAILURE_NO_GROUP		= 8,
	AREA_TRIGGER_FAILURE_NO_KEY			= 9,
	AREA_TRIGGER_FAILURE_LEVEL_HEROIC	= 10,
	AREA_TRIGGER_FAILURE_NO_CHECK		= 11,
	AREA_TRIGGER_FAILURE_NO_ACCESS		= 12,
	AREA_TRIGGER_FAILURE_NO_SPELLHEROIC	= 13,
};

const char * AreaTriggerFailureMessages[] = {
	"-",
	"This instance is unavailable",
	"You must have The Burning Crusade Expansion to access this content.",
	"Heroic mode unavailable for this instance.",
	"You must be in a raid group to pass through here.",
	"You do not have the required attunement to pass through here.", //TODO: Replace attunment with real itemname
	"You do not have the required attunement to pass through here.", //TODO: Replace attunment with real itemname
	"You must be at least level %u to pass through here.",
	"You must be in a party to pass through here.",
	"You do not have the required attunement to pass through here.", //TODO: Replace attunment with real itemname
	"You must be level 70 to enter heroic mode.",
	"-",
	"You do not have the required access level (%s) to enter.",
	"You have not yet proven to be a hero (spell: %s).",
};

uint32 CheckTriggerPrerequsites(AreaTrigger * pAreaTrigger, WorldSession * pSession, Player * pPlayer, MapInfo * pMapInfo)
{
	if(!pMapInfo || !pMapInfo->HasFlag(WMI_INSTANCE_ENABLED))
		return AREA_TRIGGER_FAILURE_UNAVAILABLE;

	if(!pSession->HasFlag(ACCOUNT_FLAG_XPACK_01) && pMapInfo->HasFlag(WMI_INSTANCE_XPACK_01))
		return AREA_TRIGGER_FAILURE_NO_BC;

	if(pMapInfo->required_access && pPlayer->RS_getAccess() < pMapInfo->required_access)
		return AREA_TRIGGER_FAILURE_NO_ACCESS;

	// These can be overridden by cheats/GM
	if(pPlayer->triggerpass_cheat)
		return AREA_TRIGGER_FAILURE_OK;

	if(pAreaTrigger->required_level && pPlayer->getLevel() < pAreaTrigger->required_level)
		return AREA_TRIGGER_FAILURE_LEVEL;

	if(pPlayer->iInstanceType >= MODE_HEROIC && pMapInfo->type != INSTANCE_MULTIMODE && pMapInfo->type != INSTANCE_NULL)
		return AREA_TRIGGER_FAILURE_NO_HEROIC;

	if(pMapInfo->required_heroicspell && !pPlayer->HasSpell(pMapInfo->required_heroicspell) && pPlayer->iInstanceType >= MODE_HEROIC && pMapInfo->type == INSTANCE_MULTIMODE && pMapInfo->type != INSTANCE_NULL)
		return AREA_TRIGGER_FAILURE_NO_SPELLHEROIC;

	if(pMapInfo->type == INSTANCE_RAID && (!pPlayer->GetGroup() || (pPlayer->GetGroup() && pPlayer->GetGroup()->GetGroupType() != GROUP_TYPE_RAID)))
		return AREA_TRIGGER_FAILURE_NO_RAID;

	if(pMapInfo->type == INSTANCE_MULTIMODE && !pPlayer->GetGroup() && pPlayer->iInstanceType >= MODE_HEROIC && pMapInfo->type != INSTANCE_NULL)
		return AREA_TRIGGER_FAILURE_NO_GROUP;

	if(pMapInfo && pMapInfo->required_quest && !pPlayer->HasFinishedQuest(pMapInfo->required_quest))
		return AREA_TRIGGER_FAILURE_NO_ATTUNE_Q;

	if(pMapInfo && pMapInfo->required_item && !pPlayer->GetItemInterface()->GetItemCount(pMapInfo->required_item, true))
		return AREA_TRIGGER_FAILURE_NO_ATTUNE_I;

	if ((pMapInfo->heroic_key_1 || pMapInfo->heroic_key_2) && 
		pPlayer->iInstanceType >= MODE_HEROIC && 
		pMapInfo->type == INSTANCE_MULTIMODE &&
		( !pPlayer->GetItemInterface()->GetItemCount(pMapInfo->heroic_key_1, false) || !pPlayer->GetItemInterface()->GetItemCount(pMapInfo->heroic_key_2, false) ) )
		return AREA_TRIGGER_FAILURE_NO_KEY;

	if(pPlayer->getLevel()<70 && pPlayer->iInstanceType>=MODE_HEROIC && pMapInfo->type != INSTANCE_NULL)
		return AREA_TRIGGER_FAILURE_LEVEL_HEROIC;

	return AREA_TRIGGER_FAILURE_OK;
}

const char* GetPermissionsReq(AreaTrigger * pAreaTrigger)
{
	MapInfo *pMi = WorldMapInfoStorage.LookupEntry(pAreaTrigger->Mapid);
	static const char* permissions[9] =
	{"None","ACCESS_PLAYER", "ACCESS_VIP", "ACCESS_UBERVIP", "ACCESSS_PROBEGM", "ACCESS_SCRIPTER", "ACCESS_GAMEMASTER", "ACCESS_ADMIN", "ACCESS_LOCKED"};
	return permissions[pMi->required_access];
};

void WorldSession::_HandleAreaTriggerOpcode(uint32 id)
{		
	sLog.outDebug("AreaTrigger: %u", id);
	// Are we REALLY here?
	if( !_player || !_player->IsInWorld() )
		return;

	// Search quest log, find any exploration quests
	sHookInterface.OnAreaTrigger(GetPlayer(), id);

	AreaTriggerEntry* entry = dbcAreaTrigger.LookupEntry(id);
	AreaTrigger* pAreaTrigger = AreaTriggerStorage.LookupEntry(id);

	if( entry == NULL || pAreaTrigger == NULL )
	{
		//sLog.outDebug("Missing AreaTrigger: %u", id);
		return;
	}
	sHookInterface.OnAreaTrigger(GetPlayer(), id); //sun++ stuff - andy
	MapInfo * pMapInfo = WorldMapInfoStorage.LookupEntry(pAreaTrigger->Mapid);
	if( pMapInfo == NULL )
		return;

	if( _player->GetTaxiState() && pMapInfo->type != INSTANCE_NULL)
	{
		sLog.outString("%s entered trigger %u but was on a taxi, function returned.", _player->GetName(), id);
		return;
	}

	if( _player->RS_getAccess() == RS_ADMIN )
		sChatHandler.BlueSystemMessage( this, "[%sSystem%s] |rEntered areatrigger: %s%u. (%s)", MSG_COLOR_WHITE, MSG_COLOR_LIGHTBLUE, MSG_COLOR_SUBWHITE, id, pAreaTrigger ? pAreaTrigger->Name : "Unknown name" );

	sQuestMgr.OnPlayerExploreArea(GetPlayer(),id);
	
	// if in BG handle is triggers
	if( _player->m_bg )
	{
		_player->m_bg->HookOnAreaTrigger(_player, id);
		return;
	}

	// Hook for Scripted Areatriggers
	_player->GetMapMgr()->HookOnAreaTrigger(_player, id);

	if (pAreaTrigger == NULL) return;

	switch(pAreaTrigger->Type)
	{
	case ATTYPE_INSTANCE:
		{
			if(GetPlayer()->GetPlayerStatus() != TRANSFER_PENDING) //only ports if player is out of pendings
			{
				uint32 reason = CheckTriggerPrerequsites(pAreaTrigger, this, _player, WorldMapInfoStorage.LookupEntry(pAreaTrigger->Mapid));
				if(reason != AREA_TRIGGER_FAILURE_OK)
				{
					const char * pReason = AreaTriggerFailureMessages[reason];
					char msg[200];
					WorldPacket data(SMSG_AREA_TRIGGER_MESSAGE, 50);
					data << uint32(0);

					switch (reason)
					{
					case AREA_TRIGGER_FAILURE_NO_SPELLHEROIC:
						SpellEntry * sp;
						if(pMapInfo)
							sp = dbcSpell.LookupEntryForced(pMapInfo->required_heroicspell);
						if( sp )
							snprintf(msg,200,pReason,sp->Name);
						else
						{
							char sid[20];
							snprintf(sid,20,"%u",pMapInfo->required_heroicspell);
							snprintf(msg,200,pReason, sid);
						}
						data << msg;
						break;
					case AREA_TRIGGER_FAILURE_NO_ACCESS:
						snprintf(msg, 200,pReason,GetPermissionsReq(pAreaTrigger) );
						data << msg;
						break;
					case AREA_TRIGGER_FAILURE_LEVEL:
						snprintf(msg,200,pReason,pAreaTrigger->required_level);
						data << msg;
						break;
					case AREA_TRIGGER_FAILURE_NO_ATTUNE_I:
						{
							MapInfo * pMi = WorldMapInfoStorage.LookupEntry(pAreaTrigger->Mapid);
							ItemPrototype * pItem = ItemPrototypeStorage.LookupEntry(pMi->required_item);
							if(pItem)
								snprintf(msg,200,"You must have the item, `%s` to pass through here.",pItem->Name1);
							else
								snprintf(msg,200,"You must have the item, UNKNOWN to pass through here.");

							data << msg;
						}break;
					case AREA_TRIGGER_FAILURE_NO_ATTUNE_Q:
						{
							MapInfo * pMi = WorldMapInfoStorage.LookupEntry(pAreaTrigger->Mapid);
							Quest * pQuest = QuestStorage.LookupEntry(pMi->required_quest);
							if(pQuest)
								snprintf(msg,200,"You must have finished the quest, `%s` to pass through here.",pQuest->title);
							else
								snprintf(msg,200,"You must have finished the quest, UNKNOWN to pass through here.");

							data << msg;
						}break;
					case AREA_TRIGGER_FAILURE_NO_KEY:
						{
							MapInfo * pMi = WorldMapInfoStorage.LookupEntry(pAreaTrigger->Mapid);
							if(pMi->heroic_key_1 && pMi->heroic_key_2)
							{
								ItemPrototype * pKey1 = ItemPrototypeStorage.LookupEntry(pMi->heroic_key_1);
								ItemPrototype * pKey2 = ItemPrototypeStorage.LookupEntry(pMi->heroic_key_2);
								if(pKey1 && pKey2)
									snprintf(msg,200,"You must have the items, `%s` and `%s` to enter Heroic Mode.",pKey1->Name1,pKey2->Name1);
								else
									snprintf(msg,200,"You must have the item, UNKNOWN to pass through here.");
							}
							else if(pMi->heroic_key_1)
							{
								ItemPrototype * pKey1 = ItemPrototypeStorage.LookupEntry(pMi->heroic_key_1);
								if(pKey1)
									snprintf(msg,200,"You must have the item, `%s` to enter Heroic Mode.",pKey1->Name1);
								else
									snprintf(msg,200,"You must have the item, UNKNOWN to pass through here.");
							}
							else if(pMi->heroic_key_2)
							{
								ItemPrototype * pKey2 = ItemPrototypeStorage.LookupEntry(pMi->heroic_key_2);
								if(pKey2)
									snprintf(msg,200,"You must have the item, `%s` to enter Heroic Mode.",pKey2->Name1);
								else
									snprintf(msg,200,"You must have the item, UNKNOWN to pass through here.");
							}
							data << msg;
						}break;
					default:
						data << pReason;
						break;
					}

					data << uint8(0);
					SendPacket(&data);
					return;
				}

				GetPlayer()->SaveEntryPoint(pAreaTrigger->Mapid);
				GetPlayer()->SafeTeleport(pAreaTrigger->Mapid, 0, LocationVector(pAreaTrigger->x, pAreaTrigger->y, pAreaTrigger->z, pAreaTrigger->o));
			}
		}break;
	case ATTYPE_QUESTTRIGGER:
		{

		}break;
	case ATTYPE_INN:
		{
			// Inn
			if (!GetPlayer()->m_isResting) GetPlayer()->ApplyPlayerRestState(true);
		}break;
	case ATTYPE_TELEPORT:
		{
			if(GetPlayer()->GetPlayerStatus() != TRANSFER_PENDING) //only ports if player is out of pendings
			{
				GetPlayer()->SaveEntryPoint(pAreaTrigger->Mapid);
				GetPlayer()->SafeTeleport(pAreaTrigger->Mapid, 0, LocationVector(pAreaTrigger->x, pAreaTrigger->y, pAreaTrigger->z, pAreaTrigger->o));
			}
		}break;
	default:break;
	}
}
