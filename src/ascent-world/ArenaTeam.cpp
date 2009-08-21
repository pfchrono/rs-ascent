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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "StdAfx.h"

static const uint32 TeamCountToId[6] = {
	0,						// 0
	0,						// 1
	0,						// 2
	ARENA_TEAM_TYPE_2V2,	// 3
	ARENA_TEAM_TYPE_3V3,	// 4
	ARENA_TEAM_TYPE_5V5,	// 5
};

static const uint32 IdToTeamCount[6] = {
	3,
	4,
	5,
	0,
	0,
	0,
};

ArenaTeam::ArenaTeam(uint32 Type, uint32 Id)
{
	m_id = Id;
	m_type = Type;
	AllocateSlots(Type);
	m_leader = 0;
	m_emblemStyle = 0;
	m_emblemColour = 0;
	m_borderColour = 0;
	m_borderStyle = 0;
	m_backgroundColour = 0;
	m_stat_rating = 1500;
	m_stat_gamesplayedweek = 0;
	m_stat_gamesplayedseason = 0;
	m_stat_gameswonseason = 0;
	m_stat_gameswonweek = 0;
	m_stat_ranking = 0;
	m_queueSearchRange = 100;
}

ArenaTeam::ArenaTeam(Field * f)
{
	uint32 z = 0, i, guid;
	const char * data;
	int ret;

	m_id = f[z++].GetUInt32();
	m_type = f[z++].GetUInt32();
	m_leader = f[z++].GetUInt32();
	m_name = f[z++].GetString();
	m_emblemStyle = f[z++].GetUInt32();
	m_emblemColour = f[z++].GetUInt32();
	m_borderStyle = f[z++].GetUInt32();
	m_borderColour = f[z++].GetUInt32();
	m_backgroundColour = f[z++].GetUInt32();
	m_stat_rating = f[z++].GetUInt32();
	AllocateSlots(m_type);

	m_stat_gamesplayedweek = 0;
	m_stat_gamesplayedseason = 0;
	m_stat_gameswonseason = 0;
	m_stat_gameswonweek = 0;
	sscanf(f[z++].GetString(), "%u %u %u %u", &m_stat_gamesplayedweek, &m_stat_gameswonweek, &m_stat_gamesplayedseason, &m_stat_gameswonseason);

	m_stat_ranking = f[z++].GetUInt32();
	for(i = 0; i < m_slots; ++i)
	{
		data = f[z++].GetString();
		ret = sscanf(data, "%u %u %u %u %u %u", &guid, &m_members[i].Played_ThisWeek, &m_members[i].Won_ThisWeek,
			&m_members[i].Played_ThisSeason, &m_members[i].Won_ThisSeason, &m_members[i].PersonalRating);
		if(ret >= 5)
		{
			m_members[i].Info = objmgr.GetPlayerInfo(guid);
			if(m_members[i].Info)
			{
				m_members[i].Info->arenaTeam[m_type] = this;
				++m_memberCount;
			}
			if (ret == 5)
			{
				// In case PersonalRating is not in the string just set the rating to the team rating
				m_members[i].PersonalRating = m_stat_rating;
			}
		}
		else
			m_members[i].Info = NULL;
	}	
	m_queueSearchRange = 100;
}

void ArenaTeam::SendPacket(WorldPacket * data)
{
	PlayerInfo * info;
	for(uint32 i = 0; i < m_memberCount; ++i)
	{
		info = m_members[i].Info;
		if(info && info->m_loggedInPlayer)
			info->m_loggedInPlayer->GetSession()->SendPacket(data);
	}
	objmgr.SafeDeleteObj(data);
}

void ArenaTeam::Destroy()
{
	char buffer[1024];
	WorldPacket * data;
	vector<PlayerInfo*> tokill;
	uint32 i;
	tokill.reserve(m_memberCount);
	snprintf(buffer,1024, "The arena team, '%s', disbanded.", m_name.c_str());
	data = sChatHandler.FillSystemMessageData(buffer);
	SendPacket(data);
	delete data;

	for(i=0; i < m_memberCount; ++i)
	{
		if(m_members[i].Info)
			tokill.push_back(m_members[i].Info);
	}

	for(vector<PlayerInfo*>::iterator itr = tokill.begin(); itr != tokill.end(); ++itr)
	{
		RemoveMember(*itr);
	}

	objmgr.RemoveArenaTeam(this);
	delete this;
}

bool ArenaTeam::AddMember(PlayerInfo * info)
{
	uint32 base_field;
	Player * plr = info->m_loggedInPlayer;
	if(m_memberCount >= m_slots)
		return false;

	memset(&m_members[m_memberCount], 0, sizeof(ArenaTeamMember));
	m_members[m_memberCount].PersonalRating = 1500;
	m_members[m_memberCount++].Info = info;
	SaveToDB();

	if(plr)
	{
		base_field = (m_type*6) + PLAYER_FIELD_ARENA_TEAM_INFO_1_1;
		plr->SetUInt32Value(base_field, m_id);
		plr->SetUInt32Value(base_field+1,m_leader);
		plr->GetSession()->SystemMessage("You are now a member of the arena team, '%s'.", m_name.c_str());
	}

	info->arenaTeam[m_type] = this;
	return true;
}

bool ArenaTeam::RemoveMember(PlayerInfo * info)
{
	for(uint32 i = 0; i < m_memberCount; ++i)
	{
		if(m_members[i].Info == info)
		{
			/* memcpy all the blocks in front of him back (so we only loop O(members) instead of O(slots) */
			for(uint32 j = (i+1); j < m_memberCount; ++j)
				memcpy(&m_members[j-1], &m_members[j], sizeof(ArenaTeamMember));

			--m_memberCount;
			SaveToDB();

			if(info->m_loggedInPlayer)
				info->m_loggedInPlayer->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (m_type*6), 0);

			info->arenaTeam[m_type] = NULL;
			return true;
		}
	}

	return false;
}

void ArenaTeam::Stats(WorldSession *session)
{
	WorldPacket data(SMSG_ARENA_TEAM_STATS, 4*7);
	data << uint32(m_id);									// arena team id
	data << uint32(m_stat_rating);							// rating
	data << uint32(m_stat_gamesplayedweek);					// played
	data << uint32(m_stat_gameswonweek);					// wins(again o_O)
	data << uint32(m_stat_gamesplayedseason);				// games
	data << uint32(m_stat_gameswonseason);					// wins
	data << uint32(m_stat_ranking);							// rank
	session->SendPacket(&data);
}

void ArenaTeam::Query(WorldSession * session)
{
	WorldPacket data(SMSG_ARENA_TEAM_QUERY_RESPONSE, 4*7+m_name.size()+1);
	data << uint32(m_id);									// team id
	data << m_name;											// team name
	data << uint32(GetPlayersPerTeam());					// arena team type (2=2x2, 3=3x3 or 5=5x5)
	data << uint32(m_emblemStyle);							// emblem style?
	data << uint32(m_emblemColour);							// emblem color?
	data << uint32(m_borderStyle);							// border style?
	data << uint32(m_borderColour);							// border color?
	data << uint32(m_backgroundColour);						// background color?
	session->SendPacket(&data);
	sLog.outDebug("WORLD: Sent SMSG_ARENA_TEAM_QUERY_RESPONSE");
}

void ArenaTeam::Roster(WorldPacket & data)
{
	data.Initialize(SMSG_ARENA_TEAM_ROSTER);
	data.reserve(m_memberCount * 81 + 9);
	data << m_id;
	data << m_memberCount;
	data << GetPlayersPerTeam();

	for(uint32 i = 0; i < m_memberCount; ++i)
	{
		PlayerInfo* info = m_members[i].Info;
		// TODO : burlex figure out why this became null
		if( info != NULL )
		{
			data << uint64(info->guid);
			data << uint8( (info->m_loggedInPlayer != NULL) ? 1 : 0 );
			data << info->name;
			data << uint32( m_members[i].Info->guid == m_leader ? 0 : 1); // Unk
			data << uint8( info->lastLevel );
			data << uint8( info->cl );
			data << m_members[i].Played_ThisWeek;
			data << m_members[i].Won_ThisWeek;
			data << m_members[i].Played_ThisSeason;
			data << m_members[i].Won_ThisSeason;
			data << m_members[i].PersonalRating;
		}
	}
}

void ArenaTeam::SaveToDB()
{
	std::stringstream ss;
	uint32 i;
	ss << "REPLACE INTO arenateams VALUES("
		<< m_id << ","
		<< m_type << ","
		<< m_leader << ",'"
		<< m_name << "',"
		<< m_emblemStyle << ","
		<< m_emblemColour << ","
		<< m_borderStyle << ","
		<< m_borderColour << ","
		<< m_backgroundColour << ","
		<< m_stat_rating << ",'"
		<< m_stat_gamesplayedweek << " " << m_stat_gameswonweek << " "
		<< m_stat_gamesplayedseason << " " << m_stat_gameswonseason << "',"
		<< m_stat_ranking;

	for(i = 0; i < m_memberCount; ++i)
	{
		if(m_members[i].Info)
		{
			ss << ",'" << m_members[i].Info->guid << " " << m_members[i].Played_ThisWeek << " "
				<< m_members[i].Won_ThisWeek << " " << m_members[i].Played_ThisSeason << " "
				<< m_members[i].Won_ThisSeason << " " << m_members[i].PersonalRating << "'";
		}
		else
		{
			ss << ",'0 0 0 0 0 0'";
		}
	}

	for(; i < 10; ++i)
	{
		ss << ",'0 0 0 0 0 0'";
	}

	ss << ")";
	CharacterDatabase.Execute(ss.str().c_str());
}

bool ArenaTeam::HasMember(uint32 guid)
{
	for(uint32 i = 0; i < m_memberCount; ++i)
	{
		if(m_members[i].Info && m_members[i].Info->guid == guid)
			return true;
	}
	return false;
}

void ArenaTeam::SetLeader(PlayerInfo * info)
{
	uint32 old_leader = m_leader;
	char buffer[1024];
	WorldPacket * data;
	snprintf(buffer, 1024,"%s is now the captain of the arena team, '%s'.", info->name, m_name.c_str());
	data = sChatHandler.FillSystemMessageData(buffer);
	m_leader=info->guid;
	SendPacket(data);
	delete data;

	/* set the fields */
	for(uint32 i = 0; i < m_memberCount; ++i)
	{
		if(m_members[i].Info == info)		/* new leader */
		{
			if(m_members[i].Info->m_loggedInPlayer)
				m_members[i].Info->m_loggedInPlayer->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (m_type*6) + 1, 0);
		}
		else if(m_members[i].Info->guid == old_leader)
		{
			if(m_members[i].Info->m_loggedInPlayer)
				m_members[i].Info->m_loggedInPlayer->SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (m_type*6) + 1, 1);
		}
	}

	SaveToDB();
}

ArenaTeamMember * ArenaTeam::GetMember(PlayerInfo * info)
{
	for(uint32 i = 0; i < m_memberCount; ++i)
	{
		if(m_members[i].Info == info)
			return &m_members[i];
	}
	return NULL;
}

ArenaTeamMember * ArenaTeam::GetMemberByGuid(uint32 guid)
{
	for(uint32 i = 0; i < m_memberCount; ++i)
	{
		if(m_members[i].Info && m_members[i].Info->guid == guid)
			return &m_members[i];
	}
	return NULL;
}

void WorldSession::HandleArenaTeamRosterOpcode(WorldPacket & recv_data)
{
	uint8 slot;
	uint32 teamId;
	ArenaTeam * team;
	recv_data >> teamId;
	team = objmgr.GetArenaTeamById(teamId);
	if(team)
	{
		slot = TeamCountToId[team->m_type];
		WorldPacket data(1000);
		team->Roster(data);
		SendPacket(&data);
	}
}

void WorldSession::HandleArenaTeamQueryOpcode(WorldPacket & recv_data)
{
	ArenaTeam * team;
	uint32 team_id;
	recv_data >> team_id;

	team = objmgr.GetArenaTeamById(team_id);
	if(team != NULL)
	{
		team->Query(this);
		team->Stats(this);
	}
}

void WorldSession::HandleArenaTeamAddMemberOpcode(WorldPacket & recv_data)
{
	string player_name;
	uint32 teamId;
	recv_data >> teamId >> player_name;

	ArenaTeam * pTeam = objmgr.GetArenaTeamById(teamId);
	if( !pTeam )
		return;

	if(!pTeam->HasMember(GetPlayer()->GetLowGUID()))
	{
		SendNotInArenaTeamPacket(uint8(pTeam->GetPlayersPerTeam()));
		return;
	}

	Player * plr = objmgr.GetPlayer(player_name.c_str(), false);
	if(plr == NULL)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", player_name, ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
		return;
	}

	if(pTeam->m_leader != _player->GetLowGUID())
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
		return;
	}

	if(plr->getLevel() < 70)
	{
		SystemMessage("%s is not high enough level to join your team", plr->GetName());
		return;
	}

	if(plr->m_playerInfo->arenaTeam[pTeam->m_type] != NULL)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, plr->GetName(), "", ERR_ALREADY_IN_ARENA_TEAM_S);
		return;
	}

	if(plr->m_arenateaminviteguid != 0)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, plr->GetName(), "", ERR_ALREADY_INVITED_TO_ARENA_TEAM_S);
		return;
	}

	if(plr->GetTeam() != _player->GetTeam() && !HasGMPermissions())
	{
		SystemMessage("You cannot invite players from the opposing alliance");
		return;
	}

	if(pTeam->m_memberCount >= pTeam->GetPlayersPerTeam())
	{
		SystemMessage("%s is full.", pTeam->m_name);
		return;
	}

	plr->m_arenateaminviteguid = _player->m_playerInfo->arenaTeam[pTeam->m_type]->m_id;

	WorldPacket data(SMSG_ARENA_TEAM_INVITE, 40);
	data << _player->GetName();
	data << _player->m_playerInfo->arenaTeam[pTeam->m_type]->m_name;
	plr->GetSession()->SendPacket(&data);
}

void WorldSession::HandleArenaTeamRemoveMemberOpcode(WorldPacket & recv_data)
{
	ArenaTeam * team;
	uint8 slot;
	uint32 teamId;
	string name;
	PlayerInfo * inf;
	recv_data >> teamId >> name;

	team = objmgr.GetArenaTeamById(teamId);
	if(!team)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM);
		return;
	}

	slot = team->m_type;

	if( (team = _player->m_playerInfo->arenaTeam[slot]) == NULL )
	{
		SendNotInArenaTeamPacket(uint8(team->GetPlayersPerTeam()));
		return;
	}

	if(team->m_leader != _player->GetLowGUID())
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
		return;
	}

	if( (inf = objmgr.GetPlayerInfoByName(name.c_str())) == NULL )
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", name.c_str(), ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
		return;
	}

	if( inf->guid == team->m_leader )
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_LEADER_LEAVE);
		return;
	}

	if(!team->HasMember(inf->guid))
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, inf->name, team->m_name, ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM_SS);
		return;
	}

	if(team->RemoveMember(inf))
	{
		team->SendArenaTeamEventPacket(ERR_ARENA_TEAM_REMOVE, 3, inf->name, team->m_name, _player->GetName());
		SystemMessage("Removed %s from the arena team '%s'.", inf->name, team->m_name.c_str());
	}
}

void WorldSession::HandleArenaTeamInviteAcceptOpcode(WorldPacket & recv_data)
{
	ArenaTeam * team;

	if(_player->m_arenateaminviteguid == 0)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_INTERNAL);
		return;
	}

	team = objmgr.GetArenaTeamById(_player->m_arenateaminviteguid);
	_player->m_arenateaminviteguid=0;
	if(team == 0)
	{
		return;
	}

	if(team->m_memberCount >= team->m_slots)
	{
		SystemMessage("That team is now full.");
		return;
	}

	if(_player->m_playerInfo->arenaTeam[team->m_type] != NULL)		/* shouldn't happen */
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_JOIN, "", "", ERR_ALREADY_IN_ARENA_TEAM);
		return;
	}

	if(team->AddMember(_player->m_playerInfo))
	{
		team->SendArenaTeamEventPacket(ERR_ARENA_TEAM_JOIN, 2, _player->GetName(), team->m_name);
	}
	else
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_INTERNAL);
	}
}

void WorldSession::HandleArenaTeamInviteDenyOpcode(WorldPacket & recv_data)
{
	ArenaTeam * team;
	if(_player->m_arenateaminviteguid == 0)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_INTERNAL);
		return;
	}

	team = objmgr.GetArenaTeamById(_player->m_arenateaminviteguid);
	_player->m_arenateaminviteguid=0;
	if(team == NULL)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_INTERNAL);
		return;
	}

	Player * plr = objmgr.GetPlayer(team->m_leader);
	if(plr != NULL)
		plr->GetSession()->SystemMessage("%s denied your arena team invitation for %s.", _player->GetName(), team->m_name.c_str());
}

void WorldSession::HandleArenaTeamLeaveOpcode(WorldPacket & recv_data)
{
	ArenaTeam * team;
	uint32 teamId;
	recv_data >> teamId;

	team = objmgr.GetArenaTeamById(teamId);

	if(!team)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_INTERNAL);
		return;
	}

	if( (team = _player->m_playerInfo->arenaTeam[team->m_type]) == NULL )
	{
		SendNotInArenaTeamPacket(uint8(team->GetPlayersPerTeam()));
		return;
	}

	if(team->m_leader == _player->GetLowGUID())
	{
		if( team->m_memberCount > 1 )
		{
			SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, "", "", ERR_ARENA_TEAM_LEADER_LEAVE);
			return;
		}
		else if( team->m_memberCount == 1 )
		{
			team->Destroy();
			return;
		}
	}

	if(team->RemoveMember(_player->m_playerInfo))
	{
		team->SendArenaTeamEventPacket(ERR_ARENA_TEAM_LEAVE, 2, _player->GetName(), team->m_name, "");
	}

	SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, team->m_name, "", 0);
}

void WorldSession::HandleArenaTeamDisbandOpcode(WorldPacket & recv_data)
{
	ArenaTeam * team;
	uint32 teamId;
	recv_data >> teamId;

	team = objmgr.GetArenaTeamById(teamId);
	if(!team)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_INTERNAL);
		return;
	}

	if( (team = _player->m_playerInfo->arenaTeam[team->m_type]) == NULL )
	{
		SendNotInArenaTeamPacket(uint8(team->GetPlayersPerTeam()));
		return;
	}

	if(team->m_leader != _player->GetLowGUID())
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
		return;
	}

	team->SendArenaTeamEventPacket(ERR_ARENA_TEAM_DISBANDED, 2, _player->GetName(), team->m_name, "");

	team->Destroy();
}

void WorldSession::HandleArenaTeamPromoteOpcode(WorldPacket & recv_data) 
{
	uint32 teamId;
	uint8 slot;
	string name;
	ArenaTeam * team;
	PlayerInfo * inf;
	recv_data >> teamId >> name;

	team = objmgr.GetArenaTeamById(teamId);
	if(!team)
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_INTERNAL);
		return;
	}

	slot = team->m_type;

	if( slot >= NUM_ARENA_TEAM_TYPES )
		return;

	if( (team = _player->m_playerInfo->arenaTeam[slot]) == NULL )
	{
		SendNotInArenaTeamPacket(uint8(team->GetPlayersPerTeam()));
		return;
	}

	if(team->m_leader != _player->GetLowGUID())
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
		return;
	}

	if( (inf = objmgr.GetPlayerInfoByName(name.c_str())) == NULL )
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", name.c_str(), ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
		return;
	}

	if(!team->HasMember(inf->guid))
	{
		SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, inf->name, team->m_name, ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM_SS);
		return;
	}

	team->SendArenaTeamEventPacket(ERR_ARENA_TEAM_LEADER_CHANGED, 3, _player->GetName(), inf->name, team->m_name);

	team->SetLeader(inf);
}

void WorldSession::SendArenaTeamCommandResult(uint32 unk1, std::string str1, std::string str2, uint32 unk3)
{
	WorldPacket data(SMSG_ARENA_TEAM_COMMAND_RESULT, 4+str1.length()+1+str2.length()+1+4);
	data << unk1;
	data << str1;
	data << str2;
	data << unk3;
	SendPacket(&data);
}

void ArenaTeam::SendArenaTeamEventPacket(uint8 eventid, uint8 str_count, std::string str1, std::string str2, std::string str3)
{
	WorldPacket *data = new WorldPacket(SMSG_ARENA_TEAM_EVENT, 1+1+1);
	*data << eventid;
	*data << str_count;
	switch(str_count)
	{
		case 1:
			*data << str1;
			break;
		case 2:
			*data << str1;
			*data << str2;
			break;
		case 3:
			*data << str1;
			*data << str2;
			*data << str3;
			break;
	}
	SendPacket(data);
}

void WorldSession::SendNotInArenaTeamPacket(uint8 type)
{
	WorldPacket data(SMSG_ARENA_ERROR, 4+1);				// You are not in a %uv%u arena team
	uint32 unk = 0;
	data << uint32(unk);									// unk(0)
	if(!unk)
		data << uint8(type);								// team type (2=2v2,3=3v3,5=5v5), can be used for custom types...
	SendPacket(&data);
}

void ArenaTeam::InspectStats(WorldSession *session)
{
	Player * plr = session->GetPlayer();
	if(plr == NULL)
		return;

	WorldPacket data(MSG_INSPECT_ARENA_TEAMS, 8+1+4*6);
	data << uint64(plr->GetGUID());							// player guid
	data << uint8(m_type);									// slot (0...2)
	data << uint32(m_id);									// arena team id
	data << uint32(m_stat_rating);							// rating
	data << uint32(m_stat_gamesplayedweek);					// games
	data << uint32(m_stat_gameswonweek);					// wins
	data << uint32(m_stat_gamesplayedseason);				// played (count of all games, that played...)
	data << uint32(m_stat_ranking);							// ranking
	session->SendPacket(&data);
}
