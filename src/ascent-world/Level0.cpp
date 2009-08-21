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
//  Normal User Chat Commands
//

#include "StdAfx.h"
#include <svn_revision.h>

bool ChatHandler::ShowHelpForCommand(WorldSession *m_session, ChatCommand *table, const char* cmd)
{
	for(uint32 i = 0; table[i].Name != NULL; i++)
	{
		if(!hasStringAbbr(table[i].Name, cmd))
			continue;

		if(m_session->CanUseCommand(table[i].CommandGroup))
			continue;

		if(table[i].ChildCommands != NULL)
		{
			cmd = strtok(NULL, " ");
			if(cmd && ShowHelpForCommand(m_session, table[i].ChildCommands, cmd))
				return true;
		}

		if(table[i].Help == "")
		{
			SystemMessage(m_session, "There is no help for that command");
			return true;
		}

		SendMultilineMessage(m_session, table[i].Help.c_str());

		return true;
	}

	return false;
}

bool ChatHandler::HandleHelpCommand(const char* args, WorldSession *m_session)
{
//	ChatCommand *table = getCommandTable();
	WorldPacket data;

	if(!*args)
		return false;

	char* cmd = strtok((char*)args, " ");
	if(!cmd)
		return false;

	if(!ShowHelpForCommand(m_session, CommandTableStorage::getSingleton().Get(), cmd))
	{
		RedSystemMessage(m_session, "Sorry, no help was found for this command, or that command does not exist.");
	}

	return true;
}


bool ChatHandler::HandleCommandsCommand(const char* args, WorldSession *m_session)
{
	ChatCommand *table = CommandTableStorage::getSingleton().Get();
	WorldPacket data;

	std::string output;
	uint32 count = 0;

	output = "Available commands: \n\n";

	for(uint32 i = 0; table[i].Name != NULL; i++)
	{
		if(*args && !hasStringAbbr(table[i].Name, (char*)args))
			continue;

		if(table[i].CommandGroup != '0' && !m_session->CanUseCommand(table[i].CommandGroup))
			continue;

		switch(table[i].CommandGroup)
		{
		case 'z':
			{
				output+="|cffff6060";
				output+=table[i].Name;
				output+="|r, ";
			}
			break;
		case 'm':
			{
				output+="|cff00ffff";
				output+=table[i].Name;
				output+=", ";
			}
			break;
		case 'c':
			{
				output += "|cff00ff00";
				output += table[i].Name;
				output += "|r, ";
			}break;
		default:
			{
				output+="|cff00ccff";
				output+=table[i].Name;
				output+="|r, ";
			}
			break;
		}

		count++;
		if(count == 5)  // 5 per line
		{
			output += "\n";
			count = 0;
		}
	}
	if(count)
		output += "\n";


		//FillSystemMessageData(&data, table[i].Name);
		//m_session->SendPacket(&data);
	//}

	SendMultilineMessage(m_session, output.c_str());

	return true;
}

bool ChatHandler::HandleStartCommand(const char* args, WorldSession *m_session)
{
	Player *chr = m_session->GetPlayer();

	// cast spell Stuck
	chr->CastSpell(chr,7355,false);
	return true;
}

bool ChatHandler::HandleInfoCommand(const char* args, WorldSession *m_session)
{
	WorldPacket data;

//	uint32 clientsNum = (uint32)sWorld.GetSessionCount();

	int gmCount		= 0;
	int plrCount	= 0;
	int avgLat		= 0;
	int vipCount	= 0;
	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		Player * plr = (itr->second);
		if(plr && plr->GetSession())
		{
			avgLat += plr->GetSession()->GetLatency();
			if( plr->RS_getAccess() >= RS_PROBEGM && plr->bGMTagOn )
				gmCount++;
			else if( plr->RS_getAccess() >= RS_VIP )
				vipCount++;
			else
				plrCount++;
		}
	}
	objmgr._playerslock.ReleaseReadLock();
	GreenSystemMessage(m_session, "Server Revision: |r%sAscent %s r%u %s)", MSG_COLOR_WHITE,
		BUILD_TAG, BUILD_REVISION, ARCH, MSG_COLOR_LIGHTBLUE);
	GreenSystemMessage(m_session, "Last update on %s - %s", BUILD_TIME, BUILD_DATE);
	GreenSystemMessage(m_session, "Last update by %s@%s", BUILD_USER, BUILD_WORKSTATION);
	GreenSystemMessage(m_session, "Server Uptime: |r%s", sWorld.GetUptimeString().c_str());
	GreenSystemMessage(m_session, "Current Players: |r%d", plrCount);
	GreenSystemMessage(m_session, "Current VIPs: |r%d", vipCount);
	GreenSystemMessage(m_session, "Current Active GMs: |r%d", gmCount);

	// Wowza how did I miss this?
	int totalCount = gmCount + vipCount + plrCount;
	GreenSystemMessage(m_session, "Users in world: |r%d", totalCount);
	GreenSystemMessage(m_session, "Average Latency: |r%.3fms", (float)((float)avgLat / (float)totalCount));

/*
	GreenSystemMessage(m_session, "Active Thread Count: |r%u", ThreadPool.GetActiveThreadCount());
	GreenSystemMessage(m_session, "Free Thread Count: |r%u", ThreadPool.GetFreeThreadCount());
	GreenSystemMessage(m_session, "SQL Query Cache Size (World): |r%u queries delayed", WorldDatabase.GetQueueSize());
	GreenSystemMessage(m_session, "SQL Query Cache Size (Character): |r%u queries delayed", CharacterDatabase.GetQueueSize());
*/
	return true;
}


bool ChatHandler::HandleNYICommand(const char* args, WorldSession *m_session)
{
	RedSystemMessage(m_session, "Not yet implemented.");
	return true;
}

bool ChatHandler::HandleDismountCommand(const char* args, WorldSession *m_session)
{
	Unit *m_target = NULL;

	Player *p_target = getSelectedChar(m_session, false);

	if(p_target)
		m_target = p_target;
	else
	{
		Creature *m_crt = getSelectedCreature(m_session, false);
		if(m_crt)
			m_target = m_crt;
	}

	if(!m_target)
	{
		RedSystemMessage(m_session, "No target found.");
		return true;
	}

	if(m_target->GetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID) == 0)
	{
		RedSystemMessage(m_session, "Target is not mounted.");
		return true;
	}

	if(p_target && p_target->m_MountSpellId)
		p_target->RemoveAura(p_target->m_MountSpellId);

	m_target->SetUInt32Value( UNIT_FIELD_MOUNTDISPLAYID , 0);
	//m_target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNTED_TAXI);

	BlueSystemMessage(m_session, "Now unmounted.");
	return true;
}


bool ChatHandler::HandleSaveCommand(const char* args, WorldSession *m_session)
{
	WorldPacket data;
	Player * plr = m_session->GetPlayer();
	if( plr && ( ( now() - plr->m_lastSave < 30000 ) || m_session->CanUseCommand('s') ) )
	{
		plr->SaveToDB(false);
		GreenSystemMessage(m_session, "Player saved to DB");
	}
	else
	{
		RedSystemMessage(m_session, "Your character was saved less than 5 minutes ago.");
	}
	m_session->SendPacket( &data );
	return true;
}

bool ChatHandler::HandleGMListCommand(const char* args, WorldSession *m_session)
{
	WorldPacket data;
	bool first = true;

	bool isAdmin = ( m_session->GetPlayer()->RS_getAccess() == RS_ADMIN );

	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession()->GetPermissionCount())
		{
			if( itr->second->GetSession()->HasGMPermissions() 
				&& ( ( itr->second->bGMTagOn == true && itr->second->m_isGmInvisible == INVIS_NONE ) 
					|| isAdmin )
			)
			{
				if( first )
				{
					GreenSystemMessage(m_session, "There are following active GMs on this server:");
					first = false;
				}

				char cPermissions[1024];
				if(	itr->second->RS_getAccess() == RS_ADMIN )
					sprintf(cPermissions, "Admin/Dev");
				else if( itr->second->RS_getAccess() == RS_GAMEMASTER )
					sprintf(cPermissions, "GameMaster");
				else if( itr->second->RS_getAccess() == RS_SCRIPTER )
					sprintf(cPermissions, "Scripter");
				else if( itr->second->RS_getAccess() == RS_PROBEGM )
					sprintf(cPermissions, "Probe-GM");

				SystemMessage(m_session, "%s [%s]", itr->second->GetName(), cPermissions);

			}
		}
	}
	objmgr._playerslock.ReleaseReadLock();

	if(first)
		SystemMessage(m_session, "There are no GMs currently logged in on this server.");

	return true;
}

bool ChatHandler::HandleVIPListCommand(const char* args, WorldSession *m_session)
{
	WorldPacket data;
	bool first = true;

	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		//if(itr->second->GetSession()->GetPermissionCount())
		if(itr->second)
		{
			Player * plr = itr->second;
			if( plr 
				&& ( plr->RS_getAccess() == RS_VIP 
					|| plr->RS_getAccess() == RS_UBERVIP 
					|| ( plr->RS_getAccess() >= RS_PROBEGM && plr->bGMTagOn == false ) 
					)
				)
			{
				if(first)
				{
					GreenSystemMessage(m_session, "There are following active VIP's on this server:");
					first = false;
				}

				if( plr->RS_getAccess() >= RS_PROBEGM && plr->bGMTagOn == false )
					SystemMessage(m_session, "%s [12m]", plr->GetName());
				else
					SystemMessage(m_session, "%s [%s]", plr->GetName(), plr->GetSession()->GetPermissions());
			}
		}
	}
	objmgr._playerslock.ReleaseReadLock();

	if(first)
		SystemMessage(m_session, "There are no VIPs currently logged in on this server.");

	return true;
}

bool ChatHandler::HandleRangeCheckCommand( const char *args , WorldSession *m_session )
{
	WorldPacket data;
	uint64 guid = m_session->GetPlayer()->GetSelection();
	m_session->SystemMessage( "=== RANGE CHECK ===" );
	if (guid == 0)
	{
		m_session->SystemMessage("No selection imo.");
		return true;
	}

	Unit *unit = m_session->GetPlayer()->GetMapMgr()->GetUnit( guid );
	if(!unit)
	{
		m_session->SystemMessage("Invalid selection imo.");
		return true;
	}
	float DistSq = unit->GetDistanceSq( static_cast<Object*>(m_session->GetPlayer()) );
	m_session->SystemMessage( "GetDistanceSq  :   %u" , FL2UINT( DistSq ) );
	LocationVector locvec( m_session->GetPlayer()->GetPositionX() , m_session->GetPlayer()->GetPositionY() , m_session->GetPlayer()->GetPositionZ() );
	float DistReal = unit->CalcDistance( locvec );
	m_session->SystemMessage( "CalcDistance   :   %u" , FL2UINT( DistReal ) );
	float Dist2DSq = unit->GetDistance2dSq( static_cast<Object*>(m_session->GetPlayer()) );
	m_session->SystemMessage( "GetDistance2dSq:   %u" , FL2UINT( Dist2DSq ) );
	return true;
}

bool ChatHandler::HandleGmLogCommentCommand( const char *args , WorldSession *m_session )
{
	if(!args || !strlen(args)) return false;
	BlueSystemMessage(m_session, "Added Logcomment: %s",args);
	sGMLog.writefromsession(m_session,"Logcomment: %s", args);
	return true;
}

bool ChatHandler::HandleRatingsCommand( const char *args , WorldSession *m_session )
{
	m_session->SystemMessage("Ratings!!!");
	Player* m_plyr = getSelectedChar(m_session, false);
	for( uint32 i = 0; i < 24; i++ )
	{
		m_plyr->ModUnsigned32Value( PLAYER_FIELD_COMBAT_RATING_1 + i, i );
	}
	m_plyr->UpdateStats();
	return true;
}

