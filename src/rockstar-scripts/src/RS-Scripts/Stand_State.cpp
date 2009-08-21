/*
	 Author: Legend Title: Stand_State.cpp Purpose: This program will set the stand
	 states of different NPCs throughout the WoW world. You can select what state
	 they will be in and what NPC is effected. License: You may redistribute and
	 alter this freely, but must give credit to me!
 */
#include "StdAfx.h"
#include "Setup.h"

class SIT_STATE :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(SIT_STATE);

	SIT_STATE(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		_unit->SetStandState(1);
	}
};

class SLEEP_STATE :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(SLEEP_STATE);

	SLEEP_STATE(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		_unit->SetStandState(3);
	}
};

class DEAD_STATE :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(DEAD_STATE);

	DEAD_STATE(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		_unit->SetStandState(7);
	}
};

class KNEEL_STATE :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(KNEEL_STATE);

	KNEEL_STATE(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		_unit->SetStandState(8);
	}
};

void SetupStandState(ScriptMgr *mgr)
{
	mgr->register_creature_script(413, &SIT_STATE::Create);
	mgr->register_creature_script(1414, &SIT_STATE::Create);
	mgr->register_creature_script(1415, &SIT_STATE::Create);
	mgr->register_creature_script(1457, &SIT_STATE::Create);
	mgr->register_creature_script(4451, &SIT_STATE::Create);
	mgr->register_creature_script(5738, &SIT_STATE::Create);
	mgr->register_creature_script(8403, &SIT_STATE::Create);
	mgr->register_creature_script(10599, &SIT_STATE::Create);
	mgr->register_creature_script(10600, &SIT_STATE::Create);
	mgr->register_creature_script(10721, &SIT_STATE::Create);
	mgr->register_creature_script(15171, &SIT_STATE::Create);
	mgr->register_creature_script(15367, &SIT_STATE::Create);
	mgr->register_creature_script(16554, &SIT_STATE::Create);
	mgr->register_creature_script(17520, &SIT_STATE::Create);
	mgr->register_creature_script(20407, &SIT_STATE::Create);
	mgr->register_creature_script(24437, &SIT_STATE::Create);
	mgr->register_creature_script(24435, &SIT_STATE::Create);

	mgr->register_creature_script(2107, &SLEEP_STATE::Create);
	mgr->register_creature_script(2486, &SLEEP_STATE::Create);
	mgr->register_creature_script(2852, &SLEEP_STATE::Create);
	mgr->register_creature_script(3888, &SLEEP_STATE::Create);
	mgr->register_creature_script(4052, &SLEEP_STATE::Create);
	mgr->register_creature_script(4996, &SLEEP_STATE::Create);
	mgr->register_creature_script(5736, &SLEEP_STATE::Create);
	mgr->register_creature_script(5915, &SLEEP_STATE::Create);
	mgr->register_creature_script(7903, &SLEEP_STATE::Create);
	mgr->register_creature_script(7904, &SLEEP_STATE::Create);
	mgr->register_creature_script(9999, &SLEEP_STATE::Create);
	mgr->register_creature_script(10556, &SLEEP_STATE::Create);
	mgr->register_creature_script(15190, &SLEEP_STATE::Create);
	mgr->register_creature_script(16971, &SLEEP_STATE::Create);
	mgr->register_creature_script(17117, &SLEEP_STATE::Create);
	mgr->register_creature_script(17263, &SLEEP_STATE::Create);
	mgr->register_creature_script(17508, &SLEEP_STATE::Create);
	mgr->register_creature_script(18812, &SLEEP_STATE::Create);
	mgr->register_creature_script(20355, &SLEEP_STATE::Create);

	mgr->register_creature_script(80525, &DEAD_STATE::Create);
	mgr->register_creature_script(17849, &DEAD_STATE::Create);
	mgr->register_creature_script(10668, &DEAD_STATE::Create);
	mgr->register_creature_script(17062, &DEAD_STATE::Create);
	mgr->register_creature_script(17508, &DEAD_STATE::Create);
	mgr->register_creature_script(16852, &DEAD_STATE::Create);
	mgr->register_creature_script(20561, &DEAD_STATE::Create);
	mgr->register_creature_script(3891, &DEAD_STATE::Create);
	mgr->register_creature_script(16804, &DEAD_STATE::Create);
	mgr->register_creature_script(18480, &DEAD_STATE::Create);

	mgr->register_creature_script(3140, &KNEEL_STATE::Create);
	mgr->register_creature_script(3644, &KNEEL_STATE::Create);
	mgr->register_creature_script(3650, &KNEEL_STATE::Create);
	mgr->register_creature_script(5042, &KNEEL_STATE::Create);
	mgr->register_creature_script(8396, &KNEEL_STATE::Create);
	mgr->register_creature_script(12427, &KNEEL_STATE::Create);
	mgr->register_creature_script(12429, &KNEEL_STATE::Create);
	mgr->register_creature_script(12430, &KNEEL_STATE::Create);
	mgr->register_creature_script(16546, &KNEEL_STATE::Create);
	mgr->register_creature_script(16723, &KNEEL_STATE::Create);
	mgr->register_creature_script(16807, &KNEEL_STATE::Create);
	mgr->register_creature_script(17073, &KNEEL_STATE::Create);
	mgr->register_creature_script(17515, &KNEEL_STATE::Create);
	mgr->register_creature_script(17519, &KNEEL_STATE::Create);
	mgr->register_creature_script(18813, &KNEEL_STATE::Create);
	mgr->register_creature_script(24305, &KNEEL_STATE::Create);
}
