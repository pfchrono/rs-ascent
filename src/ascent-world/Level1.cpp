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

/////////////////////////////////////////////////
//  GM Chat Commands
//

#include "StdAfx.h"

bool ChatHandler::HandleServerAnnounceCommand(const char* args, WorldSession *m_session)
{
	if(!*args)
		return false;

	char pAnnounce[1024];
	snprintf((char*)pAnnounce, 1024, "[SERVER] %s", args);	// Adds BROADCAST:
	sWorld.SendWorldText(pAnnounce);	// send message
	sGMLog.writefromsession(m_session, "used server announce command, [%s]", args);

//	sWorld.SendForcedIRCMessage(pAnnounce);
	return true;
}


bool ChatHandler::HandleAnnounceCommand(const char* args, WorldSession *m_session)
{
	if( !*args || strlen(args) < 4 || strchr(args, '%'))
	{
		m_session->SystemMessage("Announces cannot contain the %% character and must be at least 4 characters.");
		return true;
	}

	char msg[1024];
	string input2;
	input2 = MSG_COLOR_GREEN;
	input2 += "[Staff]";
	input2 += "|Hplayer:";
	input2 += m_session->GetPlayer()->GetName();
	input2 += "|h[";
	input2 += m_session->GetPlayer()->GetName();
	input2 += "]|h:|r ";
	input2 += MSG_COLOR_YELLOW;
	snprintf((char*)msg, 1024, "%s%s |r", input2.c_str(), args);
	sWorld.SendWorldText(msg); // send message
	sGMLog.writefromsession(m_session, "used announce command, [%s]", args);
	return true;
}

bool ChatHandler::HandleGMAnnounceCommand(const char* args, WorldSession *m_session)
{
	if(!*args) return false;
	Player * pPlr = m_session->GetPlayer();
	if(!pPlr) return true;
	char GMAnnounce[1024];
	string input2;
	input2 = "|cffff6060[TEAM]<";

	if(pPlr->GetSession()->CanUseCommand('z')) 
		input2+="Admin";
	else if(pPlr->GetSession()->CanUseCommand('a')) 
		input2+="GM";
	else if(pPlr->GetSession()->CanUseCommand('b')) 
		input2+="Scripter";
	else if(pPlr->GetSession()->CanUseCommand('c'))
		input2+="Probe";

	input2+=">|r|c1f40af20";
	input2+=pPlr->GetName();
	input2+=":|r ";
	snprintf((char*)GMAnnounce, 1024, "%s%s", input2.c_str(), args);
	sWorld.SendGMWorldText(GMAnnounce);
	Log.Channel("[GMCHAT]","%s : %s", pPlr->GetName(), args);
	sChanLog.writefromsession(m_session, "[GMCHAT] %s : %s", pPlr->GetName(), args);
	sGMLog.writefromsession(m_session, "used team announce command, [%s]", args);
	return true;
}

bool ChatHandler::HandleWAnnounceCommand(const char* args, WorldSession *m_session)
{
	if(!*args)
		return false;

	Player * m_player = m_session->GetPlayer();

	char pAnnounce[1024];
	string input2;

	input2 = "|cffff6060<";
	if(m_player->RS_getAccess() == RS_ADMIN) input2+="Admin";
	else if(m_player->RS_getAccess() >= RS_PROBEGM) input2+="GM";
	input2+=">|r|c1f40af20";
	input2+=m_session->GetPlayer()->GetName();
	input2+=":|r ";
	snprintf((char*)pAnnounce, 1024, "%s%s", input2.c_str(), args);

	sWorld.SendWorldWideScreenText(pAnnounce); // send message
	sGMLog.writefromsession(m_session, "used wannounce command [%s]", args);
	//sWorld.SendForcedIRCMessage(pAnnounce);
	return true;
}

bool ChatHandler::HandleGMOnCommand(const char* args, WorldSession *m_session)
{
	/*uint32 newbytes = m_session->GetPlayer( )->GetUInt32Value(PLAYER_BYTES_2) | 0x8;
	m_session->GetPlayer( )->SetUInt32Value( PLAYER_BYTES_2, newbytes);

	GreenSystemMessage(m_session, "GM Flag Set.");*/
	if(m_session->GetPlayer()->bGMTagOn)
		RedSystemMessage(m_session, "GM Status Is Already On. Use !gmoff To Disable It.");
	else
	{
		m_session->GetPlayer()->setFaction(35);
		m_session->GetPlayer()->GodModeCheat = true;
		m_session->GetPlayer()->bInvincible = true;
		m_session->GetPlayer()->bGMTagOn = true;
		m_session->GetPlayer()->bCTagOn = true;
		m_session->GetPlayer()->SetFlag(PLAYER_FLAGS, PLAYER_FLAG_GM);	// <GM>
		BlueSystemMessage(m_session, "GM Flag Set. It will appear above your name and in chat messages until you use !gmoff.");
	}

	return true;
}


bool ChatHandler::HandleGMOffCommand(const char* args, WorldSession *m_session)
{
	uint8 race = m_session->GetPlayer()->getRace();
	//uint32 newbytes = m_session->GetPlayer( )->GetUInt32Value(PLAYER_BYTES_2) & ~(0x8);
	//m_session->GetPlayer( )->SetUInt32Value( PLAYER_BYTES_2, newbytes);

	//GreenSystemMessage(m_session, "GM Flag Unset.");
	GreenSystemMessage(m_session, "Unsetting GM Flag on yourself...");
	if(!m_session->GetPlayer()->bGMTagOn)
		RedSystemMessage(m_session, "GM Flag not set. Use !gmon to enable it.");
	else
	{
		m_session->GetPlayer()->setFaction(race);
		m_session->GetPlayer()->GodModeCheat = false;
		m_session->GetPlayer()->bInvincible = false;	
		m_session->GetPlayer()->bGMTagOn = false;
		m_session->GetPlayer()->bCTagOn = false;
		m_session->GetPlayer()->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAG_GM);	// <GM>
		BlueSystemMessage(m_session, "GM Flag Removed. <GM> Will no longer show in chat messages or above your name.");
	}

	return true;
}


bool ChatHandler::HandleGPSCommand(const char* args, WorldSession *m_session)
{
	Object *obj;

	uint64 guid = m_session->GetPlayer()->GetSelection();
	if (guid != 0)
	{
		if(!(obj = m_session->GetPlayer()->GetMapMgr()->GetUnit(guid)))
		{
			SystemMessage(m_session, "You should select a character or a creature.");
			return true;
		}
	}
	else
		obj = (Object*)m_session->GetPlayer();

	AreaTable * at = dbcArea.LookupEntry(obj->GetMapMgr()->GetAreaID(obj->GetPositionX(), obj->GetPositionY()));
	if(!at) return true;

	char buf[384];
	snprintf((char*)buf, 384, "|cff00ff00Current Position: |cffffffffMap: |cff00ff00%d |cffffffffZone: |cff00ff00%u |cffffffffArea: |cff00ff00%u |cffffffffX: |cff00ff00%f |cffffffffY: |cff00ff00%f |cffffffffZ: |cff00ff00%f |cffffffffOrientation: |cff00ff00%f|r",
		(unsigned int)obj->GetMapId(), at->ZoneId, at->AreaId, obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), obj->GetOrientation());

	SystemMessage(m_session, buf);

	return true;
}


bool ChatHandler::HandleKickCommand(const char* args, WorldSession *m_session)
{

	if(!*args)
	return false;
	char *pname = strtok((char*)args, " ");
	if(!pname)
	{
		RedSystemMessage(m_session, "No name specified.");
		return true;
	}
	Player *chr = objmgr.GetPlayer((const char*)pname, false);
	if (chr)
	{
		char *reason = strtok(NULL, "\n");
		std::string kickreason = "No reason";
		if(reason)
			kickreason = reason;

		BlueSystemMessage(m_session, "Attempting to kick %s from the server for \"%s\".", chr->GetName(), kickreason.c_str());
		sGMLog.writefromsession(m_session, "Kicked player %s from the server for %s", chr->GetName(), kickreason.c_str());
		if(!m_session->CanUseCommand('z') && chr->GetSession()->CanUseCommand('z'))
		{
			RedSystemMessage(m_session, "You cannot kick %s, as they are a higher level gm than you.", chr->GetName());
			return true;
		}
		/*if(m_session->GetSecurity() < chr->GetSession()->GetSecurity())
		{
			SystemMessage(m_session, "You cannot kick %s, as he is a higher GM level than you.", chr->GetName());
			return true;
		}*/ // we might have to re-work this

		char msg[200];
		snprintf(msg, 200, "%sGM: %s was kicked from the server by %s. Reason: %s", MSG_COLOR_RED, chr->GetName(), m_session->GetPlayer()->GetName(), kickreason.c_str());
		sWorld.SendWorldText(msg, NULL);
		//sWorld.SendIRCMessage(msg);
		SystemMessageToPlr(chr, "You are being kicked from the server by %s. Reason: %s", m_session->GetPlayer()->GetName(), kickreason.c_str());
		
		WorldPacket data;
		data.Initialize(SMSG_FORCE_MOVE_ROOT);
		data << chr->GetNewGUID();
		data << uint32(1);
		chr->SendMessageToSet(&data, true);

		chr->Kick(6000);
		
		return true;
	} 
	else 
	{
		RedSystemMessage(m_session, "Player is not online at the moment.");
		return true;
	}
	return true;
}

bool ChatHandler::HandleAddInvItemCommand(const char *args, WorldSession *m_session)
{
	uint32 itemid, count=1;
	int32 randomprop=0;

	if(strlen(args) < 1)
	{
		return false;
	}

	if(sscanf(args, "%u %u %d", &itemid, &count, &randomprop) < 1)
		return false;

	Player * chr = getSelectedChar( m_session, false );
	if ( chr == NULL )
		chr = m_session->GetPlayer();

	ItemPrototype* it = ItemPrototypeStorage.LookupEntry(itemid);
	if(it)
	{
		sGMLog.writefromsession(m_session, "used add item command, item id %u [%s] to %s", it->ItemId, it->Name1, chr->GetName());
		Item *item;
		item = objmgr.CreateItem( itemid, chr);
		item->SetUInt32Value(ITEM_FIELD_STACK_COUNT, ((count > it->MaxCount) ? it->MaxCount : count));
		if(it->Bonding==ITEM_BIND_ON_PICKUP)
			item->SoulBind();
		if(randomprop!=0)
		{
			if(randomprop<0)
				item->SetRandomSuffix(abs(int(randomprop)));
			else
				item->SetRandomProperty(randomprop);

			item->ApplyRandomProperties(false);
		}
	  
		if(!chr->GetItemInterface()->AddItemToFreeSlot(item))
		{
			m_session->SendNotification("No free slots were found in your inventory!");
			item->DeleteMe();
			return true;
		}

		char messagetext[512];
		snprintf(messagetext, 512, "Adding item %s (id: %d) to %s's inventory.", GetItemLinkByProto(it, m_session->language), (unsigned int)it->ItemId, chr->GetName());
		SystemMessage(m_session, messagetext);
//		snprintf(messagetext, 128, "%s added item %d (%s) to your inventory.", m_session->GetPlayer()->GetName(), (unsigned int)itemid, it->Name1);
		snprintf(messagetext, 512, "%s added item (id: %d) %s to your inventory.", m_session->GetPlayer()->GetName(), (unsigned int)it->ItemId, GetItemLinkByProto(it, chr->GetSession()->language));
		
		SystemMessageToPlr(chr,  messagetext);

		SlotResult *lr = chr->GetItemInterface()->LastSearchResult();
		chr->GetSession()->SendItemPushResult(item,false,true,false,true,lr->ContainerSlot,lr->Slot,count);

		return true;
	} else {
		RedSystemMessage(m_session, "Item %d is not a valid item!", itemid);
		return true;
	}
}

bool ChatHandler::HandleSummonCommand(const char* args, WorldSession *m_session)
{
	if(!*args)
		return false;

	sGMLog.writefromsession(m_session, "summoned %s on map %u, %f %f %f", args, m_session->GetPlayer()->GetMapId(),m_session->GetPlayer()->GetPositionX(),m_session->GetPlayer()->GetPositionY(),m_session->GetPlayer()->GetPositionZ());

	Player * plr = m_session->GetPlayer();
	Player *chr = objmgr.GetPlayer(args, false);
	if( chr && chr->m_isGmInvisible < 2 )
	{
		// send message to user
		char buf[256];
		char buf0[256];
		if( chr->IsBeingTeleported() == true )
		{
			snprintf((char*)buf,256, "%s is already being teleported.", chr->GetName());
			SystemMessage(m_session, buf);
			return true;
		}
		if(!chr->RemoveTransporterStatus())
		{
			char buff[256];
			snprintf((char*)buf,256, "%s already being teleported.", chr->GetName());
			SystemMessage(m_session, buff);
			return true;
		}
		if( plr->RS_getAccess() < chr->RS_getAccess() || chr->m_isGmInvisible > INVIS_NONE )
		{
			snprintf((char*)buf,256, "%s is attempting to summon you!", plr->GetName());
			SystemMessageToPlr(chr, buf);
			chr->SummonRequest(plr->GetLowGUID(), plr->GetZoneId(), plr->GetMapId(), plr->GetInstanceID(), plr->GetPosition());
			snprintf((char*)buf0,256, "Summon request sent.", chr->GetName());
			SystemMessage(m_session, buf0);
			return true;
		}
		snprintf((char*)buf,256, "You are summoning %s.", chr->GetName());
		SystemMessage(m_session, buf);

		if(!(plr->m_isGmInvisible && chr->RS_getAccess() >= RS_SCRIPTER))
		{
			// send message to player
			snprintf((char*)buf0,256, "You are being summoned by %s.", m_session->GetPlayer()->GetName());
			SystemMessageToPlr(chr, buf0);
		}

		if(chr->GetTaxiState())
		{
			sEventMgr.RemoveEvents(chr, EVENT_PLAYER_TAXI_DISMOUNT);
			sEventMgr.RemoveEvents(chr, EVENT_PLAYER_TAXI_INTERPOLATE);
			chr->SetTaxiState(false);
			chr->SetTaxiPath(NULL);
			chr->UnSetTaxiPos();
			chr->m_taxi_ride_time = 0;
			chr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID , 0);
			chr->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNTED_TAXI);
			chr->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOCK_PLAYER);
			chr->SetPlayerSpeed(RUN, chr->m_runSpeed);
		}
		if(chr->m_TransporterGUID)
		{
			Transporter * pTrans = objmgr.GetTransporter(GUID_LOPART(chr->m_TransporterGUID));
			if(pTrans)
			{
				if(chr->m_lockTransportVariables == true)
				{
					char buff[256];
					snprintf((char*)buf,256, "%s is already being teleported.", chr->GetName());
					SystemMessage(m_session, buff);
					return true;
				}
				pTrans->RemovePlayer(chr);
				chr->m_CurrentTransporter = NULL;
				chr->m_TransporterGUID = 0;
			}
		}

		if( plr->GetMapMgr() == chr->GetMapMgr() )
		{
			chr->_Relocate(plr->GetMapId(),plr->GetPosition(),false,false,plr->GetInstanceID());
		}
		else
		{
			sEventMgr.AddEvent(chr,&Player::EventPortToGM,plr,0,1,1,0);
		}
	}
	else
	{
		PlayerInfo * pinfo = objmgr.GetPlayerInfoByName(args);
		if(!pinfo)
		{
			char buf[256];
			snprintf((char*)buf,256,"Player (%s) does not exist.", args);
			SystemMessage(m_session, buf);
		}
		else
		{
			Player * pPlayer = m_session->GetPlayer();
			char query[512];
			snprintf((char*) &query,512, "UPDATE characters SET mapId = %u, positionX = %f, positionY = %f, positionZ = %f, zoneId = %u WHERE guid = %u;",	pPlayer->GetMapId(), pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(), pPlayer->GetZoneId(), pinfo->guid);
			CharacterDatabase.Execute(query);
			char buf[256];
			snprintf((char*)buf,256,"(Offline) %s has been summoned.", pinfo->name);
			SystemMessage(m_session, buf);
		}
	}
	return true;
}


bool ChatHandler::HandleAppearCommand(const char* args, WorldSession *m_session)
{
	if(!*args)
		return false;

	Player *slf = m_session->GetPlayer();
	if(!slf) return true;
	Player *chr = objmgr.GetPlayer(args, false);
	if (chr && ( chr->m_isGmInvisible != INVIS_ADMIN || slf->RS_getAccess() == RS_ADMIN ) )
	{
		char buf[256];
		if( chr->IsBeingTeleported() ) 
		{
			snprintf((char*)buf,256, "%s is already being teleported.", chr->GetName());
			SystemMessage(m_session, buf);
			return true;
		}
		MapInfo * pMI = chr->GetMapMgr()->GetMapInfo();
		if(pMI && pMI->required_access > slf->RS_getAccess())
		{
			snprintf((char*)buf,256, "You do not have the required access level to go to this location.");
			SystemMessage(m_session, buf);
			return true;
		}
		if(chr->m_isGmInvisible && !slf->m_isGmInvisible)
		{
			SystemMessage(m_session, "Target unit is using GM Invis,");
			SystemMessage(m_session, "You need to turn on GM Invis to port to this player");
			return true;
		}

		snprintf((char*)buf,256, "Appearing at %s's location.", chr->GetName());	// -- europa
		SystemMessage(m_session, buf);
		if( slf->m_isGmInvisible == INVIS_NONE )
		{
			char buf0[256];
			snprintf((char*)buf0,256, "%s is appearing to your location.", slf->GetName());
			SystemMessageToPlr(chr, buf0);
		}

		//m_session->GetPlayer()->SafeTeleport(chr->GetMapId(), chr->GetInstanceID(), chr->GetPosition());
		//If the GM is on the same map as the player, use the normal safeteleport method
		if ( slf->GetMapId() == chr->GetMapId() && m_session->GetPlayer()->GetInstanceID() == chr->GetInstanceID() )
			slf->SafeTeleport(chr->GetMapId(),chr->GetInstanceID(),chr->GetPosition());
		else
			slf->SafeTeleport(chr->GetMapMgr(), chr->GetPosition());
		//The player and GM are not on the same map. We use this method so we can port to BG's (Above method doesn't support them)
	}
	else
	{
		char buf[256];
		snprintf((char*)buf,256, "Player (%s) does not exist or is not logged in.", args);
		SystemMessage(m_session, buf);
	}

	return true;
}

bool ChatHandler::HandleTaxiCheatCommand(const char* args, WorldSession *m_session)
{
	if (!*args)
		return false;

	int flag = atoi((char*)args);

	Player *chr = getSelectedChar(m_session);
	if (chr == NULL) return true;
	
	char buf[256];

	// send message to user
	if (flag != 0)
	{
		snprintf((char*)buf,256, "%s has all taxi nodes now.", chr->GetName());
	}
	else
	{
		snprintf((char*)buf,256, "%s has no more taxi nodes now.", chr->GetName());
	}
	GreenSystemMessage(m_session, buf);
	
	// send message to player
	if (flag != 0)
	{
		snprintf((char*)buf,256, "%s has given you all taxi nodes.",
			m_session->GetPlayer()->GetName());
	}
	else
	{
		snprintf((char*)buf,256, "%s has deleted all your taxi nodes.",
			m_session->GetPlayer()->GetName());
	}
	SystemMessage(chr->GetSession(), buf);

	for (uint8 i=0; i<8; i++)
	{
		if (flag != 0)
		{
			chr->SetTaximask(i, 0xFFFFFFFF);
		}
		else
		{
			chr->SetTaximask(i, 0);
		}
	}

	return true;
}

bool ChatHandler::HandleModifySpeedCommand(const char* args, WorldSession *m_session)
{
	WorldPacket data;

	if (!*args)
		return false;

	float Speed = (float)atof((char*)args);

	if (Speed > 255 || Speed < 1)
	{
		RedSystemMessage(m_session, "Incorrect value. Range is 1..255");
		return true;
	}

	Player *chr = getSelectedChar(m_session);
	if( chr == NULL )
		return true;

	if ( chr!=m_session->GetPlayer() )
		sGMLog.writefromsession( m_session, "modified speed of %s to %2.2f.",chr->GetName(), Speed );


	char buf[256];

	// send message to user
	BlueSystemMessage(m_session, "You set the speed of %s to %2.2f.", chr->GetName(), Speed);

	// send message to player
	snprintf((char*)buf,256, "%s set your speed to %2.2f.", m_session->GetPlayer()->GetName(), Speed);
	SystemMessage(chr->GetSession(), buf);

	chr->SetPlayerSpeed(RUN, Speed);
	chr->SetPlayerSpeed(SWIM, Speed);
	chr->SetPlayerSpeed(RUNBACK, Speed);
	chr->SetPlayerSpeed(FLY, Speed);

	return true;
}

bool ChatHandler::HandleLearnSkillCommand(const char *args, WorldSession *m_session)
{
	uint32 skill, min, max;
	min = max = 1;
	char *pSkill = strtok((char*)args, " ");
	if(!pSkill)
		return false;
	else
		skill = atol(pSkill);

	BlueSystemMessage(m_session, "Adding skill line %d", skill);

	char *pMin = strtok(NULL, " ");
	if(pMin)
	{
		min = atol(pMin);
		char *pMax = strtok(NULL, "\n");
		if(pMax)
			max = atol(pMax);
	} else {
		return false;
	}

	Player *plr = getSelectedChar(m_session, true);
	if(!plr) return false;
	if(plr->GetTypeId() != TYPEID_PLAYER) return false;
	sGMLog.writefromsession(m_session, "used add skill of %u %u %u on %s", skill, min, max, plr->GetName());

	plr->_AddSkillLine(skill, min, max);

	return true;
}

bool ChatHandler::HandleModifySkillCommand(const char *args, WorldSession *m_session)
{
	uint32 skill, min, max;
	min = max = 1;
	char *pSkill = strtok((char*)args, " ");
	if(!pSkill)
		return false;
	else
		skill = atol(pSkill);
	
	char *pMin = strtok(NULL, " ");
	uint32 cnt = 0;
	if(!pMin)
		cnt = 1;
	else
		cnt = atol(pMin);

	skill = atol(pSkill);
	
	BlueSystemMessage(m_session, "Modifying skill line %d. Advancing %d times.", skill, cnt);

	Player *plr = getSelectedChar(m_session, true);
	if(!plr) plr = m_session->GetPlayer();
	if(!plr) return false;
	sGMLog.writefromsession(m_session, "used modify skill of %u %u on %s", skill, cnt,plr->GetName());

	if(!plr->_HasSkillLine(skill))
	{
		SystemMessage(m_session, "Does not have skill line, adding.");
		plr->_AddSkillLine(skill, 1, 300);
	} else {
		plr->_AdvanceSkillLine(skill,cnt);
	}	   

	return true;
}

/// DGM: Get skill level command for getting information about a skill
bool ChatHandler::HandleGetSkillLevelCommand(const char *args, WorldSession *m_session)
{
	uint32 skill = 0;
	char *pSkill = strtok((char*)args, " ");
	if(!pSkill)
		return false;
	else 
		skill = atol(pSkill);

	Player *plr = getSelectedChar(m_session, true);
	if(!plr) return false;

	if(skill > SkillNameManager->maxskill)
	{
		BlueSystemMessage(m_session, "Skill: %u does not exists", skill);
		return false;
	}

	char * SkillName = SkillNameManager->SkillNames[skill];

	if (SkillName==0)
	{
		BlueSystemMessage(m_session, "Skill: %u does not exists", skill);
		return false;
	}
	
	if (!plr->_HasSkillLine(skill))
	{
		BlueSystemMessage(m_session, "Player does not have %s skill.", SkillName);
		return false;
	}

	uint32 nobonus = plr->_GetSkillLineCurrent(skill,false);
	uint32 bonus = plr->_GetSkillLineCurrent(skill,true) - nobonus;
	uint32 max = plr->_GetSkillLineMax(skill);

	BlueSystemMessage(m_session, "Player's %s skill has level: %u maxlevel: %u. (+ %u bonus)", SkillName,max,nobonus, bonus);
	return true;
}

bool ChatHandler::HandleGetSkillsInfoCommand(const char *args, WorldSession *m_session)
{
	Player *plr = getSelectedChar(m_session, true);
	if(!plr) return false;
	
	uint32 nobonus = 0;
	int32  bonus = 0;
	uint32 max = 0;

	BlueSystemMessage(m_session, "Player: %s has skills", plr->GetName() );

	for (uint32 SkillId = 0; SkillId <= SkillNameManager->maxskill; SkillId++)
	{
		if (plr->_HasSkillLine(SkillId))
		{
			char * SkillName = SkillNameManager->SkillNames[SkillId];
			if (!SkillName)
			{
				RedSystemMessage(m_session, "Invalid skill: %u", SkillId);
				continue;
			}

			nobonus = plr->_GetSkillLineCurrent(SkillId,false);
			bonus = plr->_GetSkillLineCurrent(SkillId,true) - nobonus;
			max = plr->_GetSkillLineMax(SkillId);

			BlueSystemMessage(m_session, "  %s: Value: %u, MaxValue: %u. (+ %d bonus)", SkillName, nobonus,max, bonus);
		}
	}

	return true;
}


bool ChatHandler::HandleRemoveSkillCommand(const char *args, WorldSession *m_session)
{
	uint32 skill = 0;
	char *pSkill = strtok((char*)args, " ");
	if(!pSkill)
		return false;
	else 
		skill = atol(pSkill);
	BlueSystemMessage(m_session, "Removing skill line %d", skill);

	Player *plr = getSelectedChar(m_session, true);
	if(plr && plr->_HasSkillLine(skill) ) //fix bug; removing skill twice will mess up skills
	{
		plr->_RemoveSkillLine(skill);
		sGMLog.writefromsession(m_session, "used remove skill of %u on %s", skill, plr->GetName());
		SystemMessageToPlr(plr, "%s removed skill line %d from you. ", m_session->GetPlayer()->GetName(), skill);
	}
	else
	{
		BlueSystemMessage(m_session, "Player doesn't have skill line %d", skill);
	}
	return true;
}


bool ChatHandler::HandleEmoteCommand(const char* args, WorldSession *m_session)
{
	uint32 emote = atoi((char*)args);
	Unit* target = this->getSelectedCreature(m_session);
	if(!target) return false;
	if(target) target->SetUInt32Value(UNIT_NPC_EMOTESTATE,emote);

	return true;
}

bool ChatHandler::HandleModifyGoldCommand(const char* args, WorldSession *m_session)
{
//	WorldPacket data;

	if ( *args == 0 )
		return false;

	Player *chr = getSelectedChar( m_session, true );
	if( chr == NULL ) return true;

	int32 total   = atoi( (char*)args );

	// gold = total / 10000;
	// silver = (total / 100) % 100;
	// copper = total % 100;
	uint32 gold   = (uint32) floor( (float)int32abs( total ) / 10000.0f );
	uint32 silver = (uint32) floor( ((float)int32abs( total ) / 100.0f) ) % 100;
	uint32 copper = int32abs2uint32( total ) % 100;
	
	sGMLog.writefromsession( m_session, "used modify gold on %s, gold: %d", chr->GetName(), total );

	int32 newgold = chr->GetUInt32Value( PLAYER_FIELD_COINAGE ) + total;

	if(newgold < 0)
	{
		BlueSystemMessage( m_session, "Taking all gold from %s's backpack...", chr->GetName() );
		GreenSystemMessageToPlr(chr, "%s took the all gold from your backpack.", m_session->GetPlayer()->GetName());
		newgold = 0;
	}
	else
	{
		if(total >= 0) {
			BlueSystemMessage( m_session,
				"Adding %u gold, %u silver, %u copper to %s's backpack...",
				gold, silver, copper,
				chr->GetName() );

			GreenSystemMessageToPlr( chr, "%s added %u gold, %u silver, %u copper to your backpack.",
				m_session->GetPlayer()->GetName(),
				gold, silver, copper );
		}
		else
		{
			BlueSystemMessage( m_session,
				"Taking %u gold, %u silver, %u copper from %s's backpack...",
				gold, silver, copper,
				chr->GetName() );

			GreenSystemMessageToPlr( chr, "%s took %u gold, %u silver, %u copper from your backpack.",
				m_session->GetPlayer()->GetName(),
				gold, silver, copper );
		}
	}

	chr->SetUInt32Value( PLAYER_FIELD_COINAGE, newgold );
	
	return true;
}

bool ChatHandler::HandleTriggerCommand(const char* args, WorldSession* m_session)
{
	int32 instance_id;
	uint32 trigger_id;
	int valcount = sscanf(args, "%u %d", (unsigned int*)&trigger_id, (int*)&instance_id);
	if(!valcount)
		return false;
	if(valcount == 1)
		instance_id = 0;

	AreaTriggerEntry *entry = dbcAreaTrigger.LookupEntry(trigger_id);
	if(trigger_id == 0 || entry == NULL)
	{
		RedSystemMessage(m_session, "Could not find trigger %s", (args == NULL ? "NULL" : args));
		return true;
	}

	m_session->GetPlayer()->SafeTeleport(entry->mapid, instance_id, LocationVector(entry->x, entry->y,
		entry->z, entry->o));

	BlueSystemMessage(m_session, "Teleported to trigger %u on [%u][%.2f][%.2f][%.2f]", entry->id,
		entry->mapid, entry->x, entry->y, entry->z);
	return true;
}

bool ChatHandler::HandleUnlearnCommand(const char* args, WorldSession * m_session)
{
	Player * plr = getSelectedChar(m_session, true);
	if(plr == 0)
		return true;

	uint32 SpellId = atol(args);
	if(SpellId == 0)
	{
		RedSystemMessage(m_session, "You must specify a spell id.");
		return true;
	}

	sGMLog.writefromsession(m_session, "removed spell %u from %s", SpellId, plr->GetName());

	if(plr->HasSpell(SpellId))
	{
		GreenSystemMessageToPlr(plr, "Removed spell %u.", SpellId);
		plr->removeSpell(SpellId, false, false, 0);
	}
	else
	{
		RedSystemMessage(m_session, "That player does not have spell %u learnt.", SpellId);
	}

	return true;
}

bool ChatHandler::HandleHoverCommand(const char* args, WorldSession * m_session)
{
	Player * Plr = m_session->GetPlayer();
	bool flag;
	if(Plr->HasAura(11010))
		flag = false;
	else
		flag = true;

	Plr->SetHover(flag);

	if( flag )
		RedSystemMessage(m_session, "Hober enabled.");
	else
		RedSystemMessage(m_session, "Hover disabled.");

	return true;
}

bool ChatHandler::HandlePlaySoundCommand2(const char* args, WorldSession * m_session)
{
	// USAGE: .playsound #soundid
	// #soundid - ID decimal number from SoundEntries.dbc (1 column)
	// this file have about 5000 sounds.
	// In this realisation only caller can hear this sound.
	if( *args )
	{
		int dwSoundId = atoi((char*)args);
		if( dwSoundId >= 0 )
		{
			WorldPacket data(SMSG_PLAY_OBJECT_SOUND,4+8);
			data << uint32(dwSoundId) << m_session->GetPlayer()->GetGUID();
			m_session->SendPacket(&data);
			return true;
		}
	}
	return false;
}

bool ChatHandler::HandleNpcSpawnLinkCommand(const char* args, WorldSession *m_session)
{
	uint32 id;
	char sql[512];
	Creature* target = m_session->GetPlayer()->GetMapMgr()->GetCreature(GET_LOWGUID_PART(m_session->GetPlayer()->GetSelection()));
	if (!target)
		return false;

	int valcount = sscanf(args, "%u", (unsigned int*)&id);
	if(valcount)
	{
		snprintf(sql, 512, "UPDATE creature_spawns SET npc_respawn_link = '%u' WHERE id = '%u'", (unsigned int)id, (unsigned int)target->GetSQL_id());
		WorldDatabase.Execute( sql );
		BlueSystemMessage(m_session, "Spawn linking for this NPC has been updated: %u", id);
	}
	else
	{
		RedSystemMessage(m_session, "Sql entry invalid %u", id);
	}

	return true;
}
