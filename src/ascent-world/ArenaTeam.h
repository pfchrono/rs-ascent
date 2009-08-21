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

#ifndef ASCENT_ARENATEAMS_H
#define ASCENT_ARENATEAMS_H

#define MAX_ARENA_SLOT 3

enum ArenaTeamCommandTypes
{
	ERR_ARENA_TEAM_CREATE_S					= 0x00,
	ERR_ARENA_TEAM_INVITE_SS				= 0x01,
//	ERR_ARENA_TEAM_QUIT_S					= 0x02,
	ERR_ARENA_TEAM_QUIT_S					= 0x03,
	ERR_ARENA_TEAM_FOUNDER_S				= 0x0C,			// need check, probably wrong...
};

enum ArenaTeamCommandErrors
{
//	ARENA_TEAM_PLAYER_NO_MORE_IN_ARENA_TEAM = 0x00,
	ERR_ARENA_TEAM_INTERNAL					= 0x01,
	ERR_ALREADY_IN_ARENA_TEAM				= 0x02,
	ERR_ALREADY_IN_ARENA_TEAM_S				= 0x03,
	ERR_INVITED_TO_ARENA_TEAM				= 0x04,
	ERR_ALREADY_INVITED_TO_ARENA_TEAM_S		= 0x05,
	ERR_ARENA_TEAM_NAME_INVALID				= 0x06,
	ERR_ARENA_TEAM_NAME_EXISTS_S			= 0x07,
	ERR_ARENA_TEAM_LEADER_LEAVE				= 0x08,
	ERR_ARENA_TEAM_PERMISSIONS				= 0x08,
	ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM		= 0x09,
	ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM_SS	= 0x0A,
	ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S		= 0x0B,
	ERR_ARENA_TEAM_NOT_ALLIED				= 0x0C,
};

enum ArenaTeamEvents
{
	ERR_ARENA_TEAM_JOIN						= 3,			// player name + arena team name
	ERR_ARENA_TEAM_LEAVE					= 4,			// player name + arena team name
	ERR_ARENA_TEAM_REMOVE					= 5,			// player name + arena team name + captain name
	ERR_ARENA_TEAM_LEADER_IS				= 6,			// player name + arena team name
	ERR_ARENA_TEAM_LEADER_CHANGED			= 7,			// old captain + new captain + arena team name
	ERR_ARENA_TEAM_DISBANDED				= 8,			// captain name + arena team name
};

struct ArenaTeamMember
{
	PlayerInfo * Info;
	uint32 Played_ThisWeek;
	uint32 Won_ThisWeek;
	uint32 Played_ThisSeason;
	uint32 Won_ThisSeason;
	uint32 PersonalRating;
};

class SERVER_DECL ArenaTeam
{
	void AllocateSlots(uint32 Type)
	{
		uint32 Slots = 0;
		if(Type == ARENA_TEAM_TYPE_2V2)
			Slots=4;
		else if(Type == ARENA_TEAM_TYPE_3V3)
			Slots=6;
		else if(Type == ARENA_TEAM_TYPE_5V5)
			Slots=10;
		ASSERT(Slots);
		m_members = new ArenaTeamMember[Slots];
		memset(m_members,0,sizeof(ArenaTeamMember)*Slots);
		m_slots = Slots;
		m_memberCount=0;
	}

public:

	uint32 m_queueSearchRange;
	uint32 m_id;
	uint32 m_type;
	uint32 m_leader;
	uint32 m_slots;
	string m_name;
	uint32 m_memberCount;
	ArenaTeamMember * m_members;

	uint32 m_emblemStyle;
	uint32 m_emblemColour;
	uint32 m_borderStyle;
	uint32 m_borderColour;
	uint32 m_backgroundColour;

	uint32 m_stat_rating;
	uint32 m_stat_gamesplayedweek;
	uint32 m_stat_gameswonweek;
	uint32 m_stat_gamesplayedseason;
	uint32 m_stat_gameswonseason;
	uint32 m_stat_ranking;

	ArenaTeam(uint32 Type, uint32 Id);
	ArenaTeam(Field * f);
	~ArenaTeam()
	{
		delete [] m_members;
	}

	void SendPacket(WorldPacket * data);

	void Query(WorldSession * session);

	void Roster(WorldPacket & data);
	void Inspect(WorldPacket & data);
	void Destroy();
	void SaveToDB();

	bool AddMember(PlayerInfo * info);
	bool RemoveMember(PlayerInfo * info);
	bool HasMember(uint32 guid);
	void SetLeader(PlayerInfo * info);

	void SendArenaTeamEventPacket(uint8 eventid, uint8 str_count, std::string str1, std::string str2 = NULL, std::string str3 = NULL);
	void Stats(WorldSession *session);
	void InspectStats(WorldSession *session);

	ArenaTeamMember * GetMember(PlayerInfo * info);
	ArenaTeamMember * GetMemberByGuid(uint32 guid);

	uint32 GetPlayersPerTeam()
	{
		switch(m_type)
		{
		case ARENA_TEAM_TYPE_2V2:
			return 2;

		case ARENA_TEAM_TYPE_3V3:
			return 3;

		case ARENA_TEAM_TYPE_5V5:
			return 5;
		}

		// never reached
		return 2;
	}
};

#endif		// ASCENT_ARENATEAMS_H
