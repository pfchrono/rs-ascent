/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"
#include "../EAS/EasyFunctions.h"

/*
 =======================================================================================================================
		Tiragarde Keep Lieutenant Benedict
 =======================================================================================================================
 */
class BenedictQAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BenedictQAI);
	BenedictQAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
	}

	void OnDied(Unit *mKiller)
	{
		if(mKiller->IsPlayer())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			uint32			objective = 2;
			QuestLogEntry	*en = (( Player * ) mKiller)->GetQuestLogForEntry(784);
			Quest			*quest = en->GetQuest();
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(en && en->GetMobCount(objective) < en->GetQuest()->required_mobcount[objective])
			{
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				uint32	newcount = en->GetMobCount(objective) + 1;
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				en->SetMobCount(objective, quest->required_mobcount[objective]);
				en->SendUpdateAddKill(objective);
				en->UpdatePlayerFields();
				return;
			}
		}
	}
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

void SetupDurotar(ScriptMgr *mgr)
{
	mgr->register_creature_script(3192, CREATE_CREATURESCRIPT(BenedictQAI));
	mgr->register_creature_script(10556, CREATE_CREATURESCRIPT(PeonSleepingAI));
	mgr->register_creature_script(11120, CREATE_CREATURESCRIPT(CrimsonHammersmith));
	mgr->register_creature_script(5894, CREATE_CREATURESCRIPT(Corrupt_Minor_Manifestation_Water_Dead));
	mgr->register_creature_script(3425, CREATE_CREATURESCRIPT(SavannahProwler));

}
