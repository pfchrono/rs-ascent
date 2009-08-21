/*
* Moon++ Scripts for Ascent MMORPG Server
* Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
* Copyright (C) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.	If not, see <http://www.gnu.org/licenses/>.
*/

#include "StdAfx.h"
#include "Setup.h"

//Crimson Hammersmith
class CrimsonHammersmith : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(CrimsonHammersmith);
	CrimsonHammersmith(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnCombatStart(Unit* mTarget)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Who Dares Disturb Me");
	}
};

//Corrupt Minor Manifestation Water Dead
class Corrupt_Minor_Manifestation_Water_Dead : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Corrupt_Minor_Manifestation_Water_Dead);
	Corrupt_Minor_Manifestation_Water_Dead(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnDied(Unit *mKiller)
	{
		float SSX = _unit->GetPositionX();
		float SSY = _unit->GetPositionY();
		float SSZ = _unit->GetPositionZ();
		float SSO = _unit->GetOrientation();

		_unit->GetMapMgr()->GetInterface()->SpawnCreature(5895, SSX, SSY+1, SSZ, SSO, true, false, 0, 0)->Despawn(600000, 0);
	}
};

class SavannahProwler : public CreatureAIScript
{
public:
	SavannahProwler(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		uint8 chance = RandomUInt(3);

		if(chance == 1)
			_unit->SetStandState(STANDSTATE_SLEEP); 
	}

	void OnCombatStart()
	{
		if(_unit->GetStandState() == STANDSTATE_SLEEP)
			_unit->SetStandState(0);
	}

	void Destroy()
	{
		delete (SavannahProwler*)this;
	}

	static CreatureAIScript *Create(Creature * c) { return new SavannahProwler(c); }
};

//Lazy Peons
class PeonSleepingAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(PeonSleepingAI);
	PeonSleepingAI(Creature* pCreature) : CreatureAIScript(pCreature) 
	{
		Unit * target = static_cast< Unit* >(_unit);
		SpellEntry * pSpellEntry = dbcSpell.LookupEntry(18795);
		sEventMgr.AddEvent( target ,&Unit::EventCastSpell , target , pSpellEntry , 0, 3000 + RandomUInt( 180000 ), 1, 1 );
	}
};

class PortalEffectSunwellIsle : public GameObjectAIScript
	{
	public:
					PortalEffectSunwellIsle(GameObject* goinstance) : GameObjectAIScript(goinstance) {}
					void OnActivate(Player * pPlayer)
					{
								if(pPlayer->getLevel() >= 70) // optional you can check for quest 11513
								{
									pPlayer->SafeTeleport(530, 530, 13001.9f, -6907.46f, 9.56139f, 0.616532f);
								}
								else if(pPlayer->getLevel() <= 69)
								{
								pPlayer->BroadcastMessage("You must be level 70 to use this!");
								}
					}
					static GameObjectAIScript *Create(GameObject * GO) { return new PortalEffectSunwellIsle(GO); }
	};
GameObjectAIScript * create_go17(GameObject * GO) { return new PortalEffectSunwellIsle(GO); }


void SetupMoonMisc(ScriptMgr *mgr)
{
	mgr->register_gameobject_script(187056, &PortalEffectSunwellIsle::Create);	
	mgr->register_creature_script(11120, &CrimsonHammersmith::Create);
	mgr->register_creature_script(5894, &Corrupt_Minor_Manifestation_Water_Dead::Create);
	mgr->register_creature_script(3425, &SavannahProwler::Create);
	mgr->register_creature_script(10556, &PeonSleepingAI::Create);
}