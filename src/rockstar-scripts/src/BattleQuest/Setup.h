#ifndef _BG_SETUP_H
#define _BG_SETUP_H

#include "StdAfx.h"
#include "CustomClass.h"
#include "HookMgr.h"
/* A hook defined to ALL_MAPS will be called regardless of the Map ID */
#define ALL_MAPS 0xFFFFFFFF
/**
 * World PvP
 * Hellfire Peninsula
 */

// Tower Counter Value
#define WORLDSTATE_HELLFIRE_ALLIANCE_TOWERS_CONTROLLED			2476
#define WORLDSTATE_HELLFIRE_HORDE_TOWERS_CONTROLLED				2478

// Tower Counter Display
#define WORLDSTATE_HELLFIRE_TOWER_DISPLAY_ALLIANCE				2490
#define WORLDSTATE_HELLFIRE_TOWER_DISPLAY_HORDE					2489

// PvP Capture Bar
#define WORLDSTATE_HELLFIRE_PVP_CAPTURE_BAR_DISPLAY				2473
#define WORLDSTATE_HELLFIRE_PVP_CAPTURE_BAR_VALUE				2474

// The Stadium Control Point
#define WORLDSTATE_HELLFIRE_STADIUM_NEUTRAL						2472
#define WORLDSTATE_HELLFIRE_STADIUM_ALLIANCE					2471
#define WORLDSTATE_HELLFIRE_STADIUM_HORDE						2470

// The Overlook Control Point
#define WORLDSTATE_HELLFIRE_OVERLOOK_NEUTRAL					2482
#define WORLDSTATE_HELLFIRE_OVERLOOK_ALLIANCE					2480
#define WORLDSTATE_HELLFIRE_OVERLOOK_HORDE						2481

// Broken Hill Control Point
#define WORLDSTATE_HELLFIRE_BROKENHILL_NEUTRAL					2485
#define WORLDSTATE_HELLFIRE_BROKENHILL_ALLIANCE					2483
#define WORLDSTATE_HELLFIRE_BROKENHILL_HORDE					2484

// Zone ID, used in many places.
#define ZONE_HELLFIRE_PENINSULA									3483


typedef set<Group*> RaidList;

void SetupQuests(ScriptMgr * mgr);
void SetupHelper(ScriptMgr * mgr);
void SetupGeneral(ScriptMgr * mgr);
void RegisterMasterHooks(ScriptMgr * mgr);
void SetupPvPHellfirePeninsula(ScriptMgr *mgr);

#endif

