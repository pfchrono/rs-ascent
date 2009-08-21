/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question
 */
#include "StdAfx.h"
#include "Setup.h"

/* Justinius_Harbinger.cpp Script */
#define CN_JUSTINIUS	18966

class JustiniusAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(JustiniusAI);

	int timer_flashoflight;
	int timer_divineshield;
	int timer_sealofsacrifice;
	int timer_updateai;
	int timer_consecration;
	int timer_blessingofgreatermight;
	int timer_judgementofcommand;

	JustiniusAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		timer_updateai = 1500;
		timer_flashoflight = 8000;		/* flash of light */
		timer_divineshield = 60000;		/* divine shield */
		timer_sealofsacrifice = 30000;	/* blessing of sacrifice */
		timer_consecration = 30000;		/* blessing of sacrifice */
		timer_blessingofgreatermight = 30000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		RegisterAIUpdateEvent(timer_updateai);
	}

	void OnCombatStop(Unit *mTarget)
	{
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		RemoveAIUpdateEvent();
		_unit->Despawn(2000, 8000);
	}

	void AIUpdate()
	{
		UpdateTime();
		if(timer_flashoflight >= 8000)
		{
			/*~~~~~~~~~~~~~~~~~~~*/
			/*
				 loop through inrange units, find freindly units that arn't players, and if HP
				 is less then 50%, cast Flash of Light
			 */
			Unit	*holder = NULL;
			/*~~~~~~~~~~~~~~~~~~~*/

			for(set < Object * >::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr)
			{
				if(!isHostile(_unit, (*itr)) && (*itr)->GetTypeId() == TYPEID_UNIT)
				{
					holder = (Unit *) (*itr);
					if(holder->GetHealthPct() <= 75 && holder->isAlive())	/* dont cast on dead targets, lmao */
					{
						_unit->CastSpell(holder, 33641, false);
						_unit->GetAIInterface()->StopMovement(1500);		/* stop moving for duration of spell, so it
																			 * doesn't break */
						timer_flashoflight = 0;
						return;
					}
				}
			}

			/* if there was no one else to heal, he can heal himself */
			if(_unit->GetHealthPct() <= 75)
			{
				_unit->CastSpell(_unit, 33641, false);
				_unit->GetAIInterface()->StopMovement(1500);				/* stop moving for duration of spell, so it
																			 * doesn't break */
				timer_flashoflight = 0;
				return;
			}
		}

		if(timer_divineshield >= 60000 && _unit->GetHealthPct() < 25)
		{
			/*
				 if his HP is less then 25%, he will cast divine shield, divine shield needs to
				 have a cooldown so it isn't spamme
			 */
			_unit->CastSpell(_unit, 33581, false);
			timer_divineshield = 0;
			return;
		}

		if(timer_sealofsacrifice >= 30000 && _unit->GetAIInterface()->GetNextTarget()->GetTypeId() == TYPEID_UNIT)	/* players
																													 * don't
																													 * have
																													 * an
																													 * ai
																													 * interface
																													 * */
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			/* get the target of our target */
			Unit	*target = _unit->GetAIInterface()->GetNextTarget()->GetAIInterface()->GetNextTarget();
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(target && target != _unit && !isHostile(_unit, target) && target->GetTypeId() == TYPEID_UNIT)
			{
				_unit->CastSpell(target, 13903, false);
				timer_sealofsacrifice = 0;
				target = NULL;
				return;
			}
		}

		if(timer_consecration >= 60000)
		{
			_unit->CastSpell(_unit, 33559, false);
			timer_consecration = 0;
			return;
		}

		if(timer_blessingofgreatermight >= 30000)
		{
			_unit->CastSpell(_unit, 33564, false);
			timer_blessingofgreatermight = 0;
			return;
		}

		if(timer_judgementofcommand >= 3000 && RandomFloat(100.0f) <= 5)	/* 5% chance to cast */
		{
			_unit->CastSpell(_unit->GetAIInterface()->GetNextTarget(), 33554, false);
			timer_judgementofcommand = 0;
			return;
		}
	}

	void UpdateTime()
	{
		timer_flashoflight += timer_updateai;
		timer_divineshield += timer_updateai;
		timer_sealofsacrifice += timer_updateai;
		timer_consecration += timer_updateai;
		timer_blessingofgreatermight += timer_updateai;
		timer_judgementofcommand += timer_updateai;
	}
};

class RespawnAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(RespawnAI);

	RespawnAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
	}

	void OnDied(Unit *mKiller)
	{
		_unit->Despawn(2000, 8000);
	}
};

void SetupJustinius(ScriptMgr *mgr)
{
	mgr->register_creature_script(CN_JUSTINIUS, &JustiniusAI::Create);
}
