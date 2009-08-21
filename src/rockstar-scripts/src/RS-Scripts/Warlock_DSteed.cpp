/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"

class XorothianOrb :	public GameObjectAIScript
{
public:
	XorothianOrb(GameObject *goinstance) :
	GameObjectAIScript(goinstance)
	{
	}
	void OnActivate(Player *pPlayer)
	{
		pPlayer->GetMapMgr()->GetInterface()->SpawnGameObject(179668, -37.4365, 812.756, -29.5358, 4.1512, false, 0, 0);
		pPlayer->GetMapMgr()->GetInterface()->SpawnGameObject(179673, -39.357, 797.293,	-29.5357, 1.40351, false, 0, 0);
		pPlayer->GetMapMgr()->GetInterface()->SpawnGameObject(179674, -21.7048,	812.782, -29.5357, 3.20992, false, 0, 0);
		pPlayer->GetMapMgr()->GetInterface()->SpawnGameObject(179672, -46.1138,	824.698, -29.5357, 5.27552, false, 0, 0);
		pPlayer->GetMapMgr()->GetInterface()->SpawnCreature(14502, -38.5699, 812.7372, 29.5357, 2.5698, true, false, 0, 0);
		_gameobject->Despawn( 2000 );
	}
	static GameObjectAIScript *Create(GameObject *GO)
	{
		return new XorothianOrb(GO);
	}
};
GameObjectAIScript *create_go12(GameObject *GO)
{
	return new XorothianOrb(GO);
}


class XDreadSteed :
	public CreatureAIScript
{
public:
	XDreadSteed(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
	}

	void OnDied(Unit *mKiller)
	{
		float x = _unit->GetPositionX();
		float y = _unit->GetPositionY();
		float z = _unit->GetPositionZ();
		float o = _unit->GetOrientation();
		_unit->GetMapMgr()->GetInterface()->SpawnCreature(14504,x,y,z,o,true,false,0,0);
	}

	void Destroy()
	{
		delete ( XDreadSteed * ) this;
	}

	static CreatureAIScript *Create(Creature *c)
	{
		return new XDreadSteed(c);
	}
};

void SetupWarlockDSTEED(ScriptMgr *mgr)
{
	mgr->register_gameobject_script(7000089, &XorothianOrb::Create);
	mgr->register_creature_script(8532, &XDreadSteed::Create);
}