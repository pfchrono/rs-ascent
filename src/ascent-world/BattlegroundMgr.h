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

#ifndef __BATTLEGROUNDMGR_H
#define __BATTLEGROUNDMGR_H

#define ANTI_CHEAT

class CBattleground;
class MapMgr;
class Player;
class Map;
class Group;

enum BattleGroundTypes
{
	BATTLEGROUND_ALTERAC_VALLEY		= 1,
	BATTLEGROUND_WARSONG_GULCH		= 2,
	BATTLEGROUND_ARATHI_BASIN		= 3,
	BATTLEGROUND_ARENA_2V2			= 4,
	BATTLEGROUND_ARENA_3V3			= 5,
	BATTLEGROUND_ARENA_5V5			= 6,
	BATTLEGROUND_EYE_OF_THE_STORM	= 7,
	BATTLEGROUND_NUM_TYPES			= 8,
};

struct BGScore
{
	uint32 KillingBlows;
	uint32 HonorableKills;
	uint32 Deaths;
	uint32 BonusHonor;
	uint32 DamageDone;
	uint32 HealingDone;

	// the max one for this is , for AV
	uint32 MiscData[5];
};

//Shady: mb use dbc?
const static uint32 BGMaximumPlayers[BATTLEGROUND_NUM_TYPES] = {
	0,							// 0
	40,							// AV
	10,							// WSG
	15,							// AB
	4,							// 2v2
	6,							// 3v3
	10,							// 5v5
	15,							// EOTS
};

const static uint32 BGMinimumPlayers[BATTLEGROUND_NUM_TYPES] = {
#ifndef ONLY_ONE_PERSON_REQUIRED_TO_JOIN_DEBUG
	0,							// 0
	0,							// AV
	5,							// WSG
	5,							// AB
	4,							// 2v2
	6,							// 3v3
	10,							// 5v5
	5,							// EotS
#else
	0,							// 0
	0,							// AV
	1,							// WSG
	1,							// AB
	2,							// 2v2
	2,							// 3v3
	2,							// 5v5
	1,							// EOTS
#endif
};

// bg score declarations
#define BG_SCORE_WSG_FLAG_CAPTURES 0
#define BG_SCORE_WSG_FLAG_RETURNS 1
#define BG_SCORE_AB_BASE_ASSAULTED 0
#define BG_SCORE_AB_BASE_DEFENDED 1
#define BG_SCORE_AV_GRAVEYARDS_ASSAULTED 0
#define BG_SCORE_AV_GRAVEYARDS_DEFENDED 1
#define BG_SCORE_AV_TOWERS_ASSAULTED 2
#define BG_SCORE_AV_TOWERS_DEFENDED 3
#define BG_SCORE_AV_MINES_CAPTURES 4
#define BG_SCORE_EOTS_FLAG_CAPTURES 0

#define SOUND_BATTLEGROUND_BEGIN			0xD6F
#define SOUND_HORDE_SCORES					8213
#define SOUND_ALLIANCE_SCORES				8173
#define SOUND_ALLIANCE_CAPTURE				8174
#define SOUND_HORDE_CAPTURE					8212
#define SOUND_ALLIANCE_RETURNED				8192
#define SOUND_HORDE_RETURNED				8192	// huh?
#define SOUND_HORDEWINS						8454
#define SOUND_ALLIANCEWINS					8455
#define SOUND_HORDE_BGALMOSTEND				0x2108
#define SOUND_ALLIANCE_BGALMOSTEND			0x2109

#define BG_PREPARATION			44521
#define BG_REVIVE_PREPARATION	44535
#define RESURRECT_SPELL			21074	// Spirit Healer Res
#define BG_DESERTER				26013
#define BG_INACTIVE				43681
#define BG_IDLE					43680

// AV define's
#define AV_UNCONTROLED_SNOWFALL_GRAVE			0x7AE //1 -> show uncontrolled

#define AV_CONTROLED_ICEBLOOD_TOWER_HORDE		0x569 //1 -> horde controled
#define AV_CONTROLED_TOWER_POINT_HORDE			0x568 //1 -> horde controled
#define AV_CONTROLED_FROSTWOLF_RELIFHUNT_HORDE	0x532 //1 -> horde controled
#define AV_CONTROLED_EAST_FROSTWOLF_TOWER_HORDE 0x567 //1 -> horde controled
#define AV_CONTROLED_WEST_FROSTWOLF_TOWER_HORDE 0x566 //1 -> horde controled
#define AV_CONTROLED_ICEBLOOD_GRAVE_HORDE		0x543 //1 -> horde controled
#define AV_CONTROLED_FROSTWOLF_GRAVE_HORDE		0x53A //1 -> horde controled

#define AV_CONTROLED_IRONDEEP_MINE_TROGG		0x550 //1 -> trogg controled
#define AV_CONTROLED_COLDTHOOT_MINE_KOBOLT		0x54D //1 -> kobolt controled

#define AV_CONTROLED_STORMPIKE_GRAVE_ALLIANCE	0x535 //1 -> alliance controled
#define AV_CONTROLED_STONEHEART_BUNKER_ALLIANCE	0x554 //1 -> alliance controled
#define AV_CONTROLED_ICEWING_BUNKER_ALLIANCE	0x553 //1 -> alliance controled
#define AV_CONTROLED_DUBALDER_NORTH_BUNKER_ALLIANCE  0x552 //1 -> alliance controled
#define AV_CONTROLED_DUBALDER_SOUTH_BUNKER_ALLIANCE  0x551 //1 -> alliance controled
#define AV_CONTROLED_STORMPIKE_AID_STATION_ALLIANCE  0x52D //1 -> alliance controled
#define AV_CONTROLED_STONEHEART_GRAVE_ALLIANCE  0x516 //1 -> alliance controled

/* get level grouping for player */
static inline uint32 GetLevelGrouping(uint32 level)
{
	if(level < 10)
		return 0;
	else if(level < 20)
		return 1;
	else if(level < 30)
		return 2;
	else if(level < 40)
		return 3;
	else if(level < 50)
		return 4;
	else if(level < 60)
		return 5;
	else if(level < 70)
		return 6;
	else
		return 7;
}
#define MAX_LEVEL_GROUP 8
#define MINIMUM_PLAYERS_ON_EACH_SIDE_FOR_BG 1
#define MAXIMUM_BATTLEGROUNDS_PER_LEVEL_GROUP 50
#define LEVEL_GROUP_70 7
#define BG_ANTI_CHEAT 1

class CBattlegroundManager : public Singleton<CBattlegroundManager>, public EventableObject
{
	/* Battleground Instance Map */
	map<uint32, CBattleground*> m_instances[BATTLEGROUND_NUM_TYPES];
	Mutex m_instanceLock;

	/* Max Id */
	uint32 m_maxBattlegroundId;
	
	/* Queue System */
	// Instance Id -> list<Player guid> [ BattlegroundType ] (instance 0 - first available)
	list<uint32> m_queuedPlayers[BATTLEGROUND_NUM_TYPES][MAX_LEVEL_GROUP];

	// Instance Id -> list<Group id> [BattlegroundType][LevelGroup]
	list<uint32> m_queuedGroups[BATTLEGROUND_NUM_TYPES];

	Mutex m_queueLock;

public:
	CBattlegroundManager();
	~CBattlegroundManager();

	/* Packet Handlers */
	void HandleBattlegroundListPacket(WorldSession * m_session, uint32 BattlegroundType);
	void HandleArenaJoin(WorldSession * m_session, uint32 BattlegroundType, uint8 as_group, uint8 rated_match);

	/* Player Logout Handler */
	void OnPlayerLogout(Player * plr);

	/* Handler On Update Event */
	void EventQueueUpdate();
	void EventQueueUpdate(bool forceStart);

	/* Handle GetBattlegroundQueue Command */
	void HandleGetBattlegroundQueueCommand(WorldSession * m_session);

	/* Handle Battleground Join */
	void HandleBattlegroundJoin(WorldSession * m_session, WorldPacket & pck);

	/* Remove Player From All Queues */
	void RemovePlayerFromQueues(Player * plr);
	void RemoveGroupFromQueues(Group * grp);

	/* Create a battleground instance of type x */
	CBattleground * CreateInstance(uint32 Type, uint32 LevelGroup);

	/* Can we create a new instance of type x level group y? (NO LOCK!) */
	bool CanCreateInstance(uint32 Type, uint32 LevelGroup);

	/* Deletes a battleground (called from MapMgr) */
	void DeleteBattleground(CBattleground * bg);

	/* Build SMSG_BATTLEFIELD_STATUS */
	void SendBattlefieldStatus(Player * plr, uint32 Status, uint32 Type, uint32 InstanceID, uint32 Time, uint32 MapId, uint8 RatedMatch);

	/* Gets ArenaTeam info from group */
	uint32 GetArenaGroupQInfo(Group * group, int type, uint32 *avgRating);

	/* Creates an arena with groups group1 and group2 */
	int CreateArenaType(int type, Group * group1, Group * group2);

	/* Add player to bg team */
	void AddPlayerToBgTeam(CBattleground * bg, deque<uint32> *playerVec, uint32 i, uint32 j, int Team);

	/* Add player to bg */
	void AddPlayerToBg(CBattleground * bg, deque<uint32> *playerVec, uint32 i, uint32 j);
};

class CBattleground : public EventableObject
{
protected:
	/* Groups */
	Group * m_groups[2];

	time_t m_nextPvPUpdateTime;
	MapMgr * m_mapMgr;
	uint32 m_id;
	uint32 m_type;
	uint32 m_levelGroup;
	uint32 m_deltaRating[2];

public:
	/* Team->Player Map */
	set<Player*> m_players[2];
	void Lock() { m_mainLock.Acquire(); }
	void Unlock() { m_mainLock.Release(); }
	ASCENT_INLINE bool IsArena() { return (m_type >= BATTLEGROUND_ARENA_2V2 && m_type <= BATTLEGROUND_ARENA_5V5); }

protected:
	/* World States. This should be moved to mapmgr instead for world pvp :/ */
	map<uint32, uint32> m_worldStates;

	/* PvP Log Data Map */
	map<uint32, BGScore> m_pvpData;

	/* Lock for all player data */
	Mutex m_mainLock;

	/* Player count per team */
	uint32 m_playerCountPerTeam;

	/* "pending" players */
	set<uint32> m_pendPlayers[2];

	/* starting time */
	uint32 m_startTime;
	bool m_started;

	/* countdown stuff */
	uint32 m_countdownStage;

	/* winner stuff */
	bool m_ended;
	uint8 m_losingteam;

	/* resurrect queue */
	map<Creature*, set<uint32> > m_resurrectMap;
	uint32 m_lastResurrect;

	bool m_isWeekend;

public:

	void SendChatMessage(uint32 Type, uint64 Guid, const char * Format, ...);

	/* Hook Functions */
	virtual void HookOnPlayerDeath(Player * plr) = 0;

	/* Repopping - different battlegrounds have different ways of handling this */
	virtual bool HookHandleRepop(Player * plr) = 0;

	/* In CTF battlegrounds mounting will cause you to lose your flag. */
	virtual void HookOnMount(Player * plr) = 0;

	/* Only used in CTF (as far as I know) */
	virtual void HookFlagDrop(Player * plr, GameObject * obj) = 0;
	virtual void HookFlagStand(Player * plr, GameObject * obj) = 0;

	/* Used when a player kills a unit/player */
	virtual void HookOnPlayerKill(Player * plr, Unit * pVictim) = 0;
	virtual void HookOnHK(Player * plr) = 0;

	/* On Area Trigger */
	virtual void HookOnAreaTrigger(Player * plr, uint32 id) = 0;

	/* On Shadow Sight */
	virtual void HookOnShadowSight() = 0;

	/* Retrieval Functions */
	ASCENT_INLINE uint32 GetId() { return m_id; }
	ASCENT_INLINE uint32 GetLevelGroup() { return m_levelGroup; }
	ASCENT_INLINE MapMgr* GetMapMgr() { return m_mapMgr; }
	
	/* Creating a battleground requires a pre-existing map manager */
	CBattleground(MapMgr * mgr, uint32 id, uint32 levelgroup, uint32 type);
	virtual ~CBattleground();

	/* Has it ended? */
	ASCENT_INLINE bool HasEnded() { return m_ended; }
	/* Has it started? */
	ASCENT_INLINE bool HasStarted() { return m_started; }

	/* Send our current world states to a player . */
	void SendWorldStates(Player * plr);

	/* Send the pvp log data of all players to this player. */
	void SendPVPData(Player * plr);

	/* Get the starting position for this team. */
	virtual LocationVector GetStartingCoords(uint32 Team) = 0;

	/* Send a packet to the entire battleground */
	void DistributePacketToAll(WorldPacket * packet);

	/* send a packet to only this team */
	void DistributePacketToTeam(WorldPacket * packet, uint32 Team);

	/* play sound to this team only */
	void PlaySoundToTeam(uint32 Team, uint32 Sound);

	/* play sound to all */
	void PlaySoundToAll(uint32 Sound);

	/* Full? */
	ASCENT_INLINE bool IsFull() { return !(HasFreeSlots(0) || HasFreeSlots(1)); }

	/* Are we full? */
/*	bool HasFreeSlots(uint32 Team, uint32 type) {
		bool res;
		m_mainLock.Acquire();
		if (type >= BATTLEGROUND_ARENA_2V2 && type <= BATTLEGROUND_ARENA_5V5)
		{
			res = ((uint32)m_players[Team].size() + m_pendPlayers[Team].size() < BGMaximumPlayers[type]);
		}
		else
		{
			uint32 size[2];
			size[0] = (uint32)m_players[0].size() + m_pendPlayers[0].size();
			size[1] = (uint32)m_players[1].size() + m_pendPlayers[1].size();
			res = (size[Team] < BGMaximumPlayers[type]) && (((int)size[Team] - (int)size[1-Team]) <= 0);
		}
		m_mainLock.Release();
		return res; 
	}*/

	bool HasFreeSlots(uint32 Team) 
	{
		m_mainLock.Acquire(); 
		bool res = ((m_players[Team].size() + m_pendPlayers[Team].size()) < m_playerCountPerTeam);
		m_mainLock.Release(); 
		return res; 
	}

	/* Add Player */
	void AddPlayer(Player * plr, uint32 team);
	virtual void OnAddPlayer(Player * plr) = 0;

	/* Remove Player */
	void RemovePlayer(Player * plr, bool logout);
	virtual void OnRemovePlayer(Player * plr) = 0;

	/* Port Player */
	void PortPlayer(Player * plr, bool skip_teleport = false);
	virtual void OnCreate() = 0;

	/* Remove pending player */
	void RemovePendingPlayer(Player * plr);

	/* Gets the number of free slots */
	uint32 GetFreeSlots(uint32 t, uint32 type)
	{
		m_mainLock.Acquire();
		size_t s = BGMaximumPlayers[type] - m_players[t].size() - m_pendPlayers[t].size();
		m_mainLock.Release();
		return (uint32)s;
	}

	GameObject * SpawnGameObject(uint32 entry, float x, float y, float z, float o, uint32 flags, uint32 faction, float scale);
	Creature * SpawnCreature(uint32 entry,float x, float y, float z, float o);
	void UpdatePvPData();

	ASCENT_INLINE uint32 GetStartTime() { return m_startTime; }
	ASCENT_INLINE uint32 GetType() { return m_type; }

	// events should execute in the correct context
	int32 event_GetInstanceID();
	void EventCreate();

	virtual const char * GetName() = 0;
	void EventCountdown();

	virtual void Start();
	virtual void OnStart() {}
	void Close();
	virtual void OnClose() {}

//	void SetWorldState(uint32 Index, uint32 Value);
	Creature * SpawnSpiritGuide(float x, float y, float z, float o, uint32 horde);

	ASCENT_INLINE uint32 GetLastResurrect() { return m_lastResurrect; }
	void AddSpiritGuide(Creature * pCreature);
	void RemoveSpiritGuide(Creature * pCreature);
	void QueuePlayerForResurrect(Player * plr, Creature * spirit_healer);
	void RemovePlayerFromResurrect(Player * plr, Creature * spirit_healer);
	void EventResurrectPlayers();
	virtual bool CanPlayerJoin(Player * plr);
	virtual bool CreateCorpse(Player * plr) { return true; }
	virtual bool HookSlowLockOpen(GameObject * pGo, Player * pPlayer, Spell * pSpell) { return false; }

	void BuildPvPUpdateDataPacket(WorldPacket * data);
	virtual uint8 Rated() { return 0; }
	void OnPlayerPushed(Player* plr);
	void QueueAtNearestSpiritGuide(Player *plr, Creature *old);
	virtual void SetIsWeekend(bool isweekend) {}
};

#define BattlegroundManager CBattlegroundManager::getSingleton( )

	
#endif
