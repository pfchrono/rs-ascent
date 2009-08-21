/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"
#ifdef WIN32
#pragma warning( once : 4305) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#endif

/* Just defining the Ring of Blood mobs */
#define BROKENTOE			18398
#define BROTHERS			18399
#define ROKDAR				18400
#define SKRAGATH			18401
#define WARMAUL_CHAMPION	18402
#define MOGOR				18069

void RingOfBlood(Player *pPlayer, Quest *pQuest)
{
	switch(pQuest->id)
	{
	case 9962:
		pPlayer->GetMapMgr()->GetInterface()->SpawnCreature
			(
				BROKENTOE,
				-706.24f,
				7868.00f,
				45.00f,
				1.856668f,
				true,
				false,
				0,
				0
			);
		break;

	case 9967:
		pPlayer->GetMapMgr()->GetInterface()->SpawnCreature
			(
				BROTHERS,
				-706.24f,
				7868.00f,
				45.00f,
				1.856668f,
				true,
				false,
				0,
				0
			);
		pPlayer->GetMapMgr()->GetInterface()->SpawnCreature
			(
				BROTHERS,
				-706.24f,
				7872.00f,
				45.00f,
				1.856668f,
				true,
				false,
				0,
				0
			);
		break;

	case 9970:
		pPlayer->GetMapMgr()->GetInterface()->SpawnCreature
			(
				ROKDAR,
				-706.24f,
				7868.00f,
				45.00f,
				1.856668f,
				true,
				false,
				0,
				0
			);
		break;

	case 9972:
		pPlayer->GetMapMgr()->GetInterface()->SpawnCreature
			(
				SKRAGATH,
				-706.24f,
				7868.00f,
				45.00f,
				1.856668f,
				true,
				false,
				0,
				0
			);
		break;

	case 9973:
		pPlayer->GetMapMgr()->GetInterface()->SpawnCreature
			(
				WARMAUL_CHAMPION,
				-706.24f,
				7868.00f,
				45.00f,
				1.856668f,
				true,
				false,
				0,
				0
			);
		break;

	case 9977:
		pPlayer->GetMapMgr()->GetInterface()->SpawnCreature
			(
				MOGOR,
				-706.24f,
				7868.00f,
				45.00f,
				1.856668f,
				true,
				false,
				0,
				0
			);
		break;
	}
}

void SetupQuestHooks(ScriptMgr *mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_QUEST_ACCEPT, &RingOfBlood);
}
