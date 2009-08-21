/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"
#include "../../src/ascent-world/Creature.h"
#pragma warning(disable : 4305) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#pragma warning(disable : 4018)
#pragma warning(disable : 4244)
class BeastBat :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastBat);
	SP_AI_Spell spells[14];

	BeastBat(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 14;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 SCREECH //
		 */
		spells[9].info = dbcSpell.LookupEntry(24423);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 12000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 23;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 15.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 8;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(24577);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 12000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 47;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 15.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 24;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(24578);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 12000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 55;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 15.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 48;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(24579);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 12000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 63;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 15.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 56;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(27051);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 12000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 0;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 15.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 64;
		spells[13].attackstoptimer = 2000;

		/* END SCREECH // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 8000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastBear :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastBear);
	SP_AI_Spell spells[18];

	BeastBear(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 18;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 CLAW //
		 */
		spells[9].info = dbcSpell.LookupEntry(16827);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 7;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 1;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(16828);
		spells[10].rangecheck = true;
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 15;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 30.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 8;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(16829);
		spells[11].rangecheck = true;
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 23;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 40.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 16;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(16830);
		spells[12].rangecheck = true;
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 31;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 50.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 24;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(16831);
		spells[13].rangecheck = true;
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 39;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 50.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 32;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(16832);
		spells[14].rangecheck = true;
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 47;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 50.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 40;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(3010);
		spells[15].rangecheck = true;
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].cooldown = 6000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 55;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 50.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 48;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(3009);
		spells[16].rangecheck = true;
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].cooldown = 6000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 63;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 50.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 56;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(27049);
		spells[17].rangecheck = true;
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].cooldown = 6000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 0;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 50.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 64;
		spells[17].attackstoptimer = 2000;

		/* END CLAW // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 7000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastBoar :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastBoar);
	SP_AI_Spell spells[29];

	BeastBoar(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 29;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 CHARGE //
		 */
		spells[9].info = dbcSpell.LookupEntry(7371);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 11;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 100.0f;
		spells[9].distancecheck = true;
		spells[9].proctimes = 1;
		spells[9].proctimes2 = 1;
		spells[9].reqlvl = 1;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(26177);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 23;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 100.0f;
		spells[10].distancecheck = true;
		spells[10].proctimes = 1;
		spells[10].proctimes2 = 1;
		spells[10].reqlvl = 12;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(26178);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 35;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 100.0f;
		spells[11].distancecheck = true;
		spells[11].proctimes = 1;
		spells[11].proctimes2 = 1;
		spells[11].reqlvl = 24;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(26179);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 47;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 100.0f;
		spells[12].distancecheck = true;
		spells[12].proctimes = 1;
		spells[12].proctimes2 = 1;
		spells[12].reqlvl = 36;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(26201);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 59;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 100.0f;
		spells[13].distancecheck = true;
		spells[13].proctimes = 1;
		spells[13].proctimes2 = 1;
		spells[13].reqlvl = 48;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(27685);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 67;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 100.0f;
		spells[14].distancecheck = true;
		spells[14].proctimes = 1;
		spells[14].proctimes2 = 1;
		spells[14].reqlvl = 60;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(27685);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].cooldown = 6000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 0;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 100.0f;
		spells[15].distancecheck = true;
		spells[15].proctimes = 1;
		spells[15].proctimes2 = 1;
		spells[15].reqlvl = 68;
		spells[15].attackstoptimer = 2000;

		/*
			 END CHARGE // ;
			 DASH //
		 */
		spells[16].info = dbcSpell.LookupEntry(23099);
		spells[16].targettype = TARGET_SELF;
		spells[16].instant = true;
		spells[16].cooldown = 6000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 39;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 100.0f;
		spells[16].distancecheck = true;
		spells[16].proctimes = 1;
		spells[16].proctimes2 = 1;
		spells[16].reqlvl = 30;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(23109);
		spells[17].targettype = TARGET_SELF;
		spells[17].instant = true;
		spells[17].cooldown = 6000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 49;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 100.0f;
		spells[17].distancecheck = true;
		spells[17].proctimes = 1;
		spells[17].proctimes2 = 1;
		spells[17].reqlvl = 40;
		spells[17].attackstoptimer = 2000;

		spells[18].info = dbcSpell.LookupEntry(23110);
		spells[18].targettype = TARGET_SELF;
		spells[18].instant = true;
		spells[18].cooldown = 6000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 59;
		spells[18].hpreqtocast = 100;
		spells[18].perctrigger = 100.0f;
		spells[18].distancecheck = true;
		spells[18].proctimes = 1;
		spells[18].proctimes2 = 1;
		spells[18].reqlvl = 50;
		spells[18].attackstoptimer = 2000;

		spells[19].info = dbcSpell.LookupEntry(23110);
		spells[19].targettype = TARGET_SELF;
		spells[19].instant = true;
		spells[19].cooldown = 6000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 0;
		spells[19].hpreqtocast = 100;
		spells[19].perctrigger = 100.0f;
		spells[19].distancecheck = true;
		spells[19].proctimes = 1;
		spells[19].proctimes2 = 1;
		spells[19].reqlvl = 60;
		spells[19].attackstoptimer = 2000;

		/*
			 END DASH // ;
			 GORE /
		 */
		spells[20].info = dbcSpell.LookupEntry(35290);
		spells[20].targettype = TARGET_ATTACKING;
		spells[20].rangecheck = true;
		spells[20].instant = true;
		spells[20].cooldown = 6000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 7;
		spells[20].hpreqtocast = 100;
		spells[20].perctrigger = 20.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 1;
		spells[20].attackstoptimer = 2000;

		spells[21].info = dbcSpell.LookupEntry(35291);
		spells[21].targettype = TARGET_ATTACKING;
		spells[21].instant = true;
		spells[21].rangecheck = true;
		spells[21].cooldown = 6000;
		spells[21].cooldown2 = 0;
		spells[21].maxlvl = 15;
		spells[21].hpreqtocast = 100;
		spells[21].perctrigger = 20.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 8;
		spells[21].attackstoptimer = 2000;

		spells[22].info = dbcSpell.LookupEntry(35292);
		spells[22].targettype = TARGET_ATTACKING;
		spells[22].instant = true;
		spells[22].rangecheck = true;
		spells[22].cooldown = 6000;
		spells[22].cooldown2 = 0;
		spells[22].maxlvl = 23;
		spells[22].hpreqtocast = 100;
		spells[22].perctrigger = 20.0f;
		spells[22].proctimes = 0;
		spells[22].proctimes2 = 0;
		spells[22].reqlvl = 16;
		spells[22].attackstoptimer = 2000;

		spells[23].info = dbcSpell.LookupEntry(35293);
		spells[23].targettype = TARGET_ATTACKING;
		spells[23].instant = true;
		spells[23].rangecheck = true;
		spells[23].cooldown = 6000;
		spells[23].cooldown2 = 0;
		spells[23].maxlvl = 31;
		spells[23].hpreqtocast = 100;
		spells[23].perctrigger = 20.0f;
		spells[23].proctimes = 0;
		spells[23].proctimes2 = 0;
		spells[23].reqlvl = 24;
		spells[23].attackstoptimer = 2000;

		spells[24].info = dbcSpell.LookupEntry(35294);
		spells[24].targettype = TARGET_ATTACKING;
		spells[24].instant = true;
		spells[24].rangecheck = true;
		spells[24].cooldown = 6000;
		spells[24].cooldown2 = 0;
		spells[24].maxlvl = 39;
		spells[24].hpreqtocast = 100;
		spells[24].perctrigger = 20.0f;
		spells[24].proctimes = 0;
		spells[24].proctimes2 = 0;
		spells[24].reqlvl = 32;
		spells[24].attackstoptimer = 2000;

		spells[25].info = dbcSpell.LookupEntry(35295);
		spells[25].targettype = TARGET_ATTACKING;
		spells[25].instant = true;
		spells[25].cooldown = 6000;
		spells[25].cooldown2 = 0;
		spells[25].rangecheck = true;
		spells[25].maxlvl = 47;
		spells[25].hpreqtocast = 100;
		spells[25].perctrigger = 20.0f;
		spells[25].proctimes = 0;
		spells[25].proctimes2 = 0;
		spells[25].reqlvl = 40;
		spells[25].attackstoptimer = 2000;

		spells[26].info = dbcSpell.LookupEntry(35296);
		spells[26].targettype = TARGET_ATTACKING;
		spells[26].instant = true;
		spells[26].cooldown = 6000;
		spells[26].rangecheck = true;
		spells[26].cooldown2 = 0;
		spells[26].maxlvl = 55;
		spells[26].hpreqtocast = 100;
		spells[26].perctrigger = 20.0f;
		spells[26].proctimes = 0;
		spells[26].proctimes2 = 0;
		spells[26].reqlvl = 48;
		spells[26].attackstoptimer = 2000;

		spells[27].info = dbcSpell.LookupEntry(35297);
		spells[27].targettype = TARGET_ATTACKING;
		spells[27].instant = true;
		spells[27].cooldown = 6000;
		spells[27].cooldown2 = 0;
		spells[27].rangecheck = true;
		spells[27].maxlvl = 62;
		spells[27].hpreqtocast = 100;
		spells[27].perctrigger = 20.0f;
		spells[27].proctimes = 0;
		spells[27].proctimes2 = 0;
		spells[27].reqlvl = 56;
		spells[27].attackstoptimer = 2000;

		spells[28].info = dbcSpell.LookupEntry(35298);
		spells[28].targettype = TARGET_ATTACKING;
		spells[28].instant = true;
		spells[28].rangecheck = true;
		spells[28].cooldown = 6000;
		spells[28].cooldown2 = 0;
		spells[28].maxlvl = 0;
		spells[28].hpreqtocast = 100;
		spells[28].perctrigger = 20.0f;
		spells[28].proctimes = 0;
		spells[28].proctimes2 = 0;
		spells[28].reqlvl = 63;
		spells[28].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastCarrionBird :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastCarrionBird);
	SP_AI_Spell spells[23];

	BeastCarrionBird(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 23;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 CLAW /
		 */
		spells[9].info = dbcSpell.LookupEntry(16827);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 7;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 1;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(16828);
		spells[10].rangecheck = true;
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 15;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 50.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 8;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(16829);
		spells[11].rangecheck = true;
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 23;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 50.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 16;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(16830);
		spells[12].rangecheck = true;
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 31;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 50.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 24;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(16831);
		spells[13].rangecheck = true;
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 39;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 50.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 32;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(16832);
		spells[14].rangecheck = true;
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 47;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 50.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 40;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(3010);
		spells[15].rangecheck = true;
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].cooldown = 6000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 55;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 50.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 48;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(3009);
		spells[16].rangecheck = true;
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].cooldown = 6000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 63;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 50.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 56;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(27049);
		spells[17].rangecheck = true;
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].cooldown = 6000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 0;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 50.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 64;
		spells[17].attackstoptimer = 2000;

		/*
			 END CLAW // ;
			 SCREEC
		 */
		spells[18].info = dbcSpell.LookupEntry(24423);
		spells[18].targettype = TARGET_ATTACKING;
		spells[18].instant = true;
		spells[18].cooldown = 12000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 23;
		spells[18].hpreqtocast = 100;
		spells[18].perctrigger = 15.0f;
		spells[18].proctimes = 0;
		spells[18].proctimes2 = 0;
		spells[18].reqlvl = 8;
		spells[18].attackstoptimer = 2000;

		spells[19].info = dbcSpell.LookupEntry(24577);
		spells[19].targettype = TARGET_ATTACKING;
		spells[19].instant = true;
		spells[19].cooldown = 12000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 47;
		spells[19].hpreqtocast = 100;
		spells[19].perctrigger = 15.0f;
		spells[19].proctimes = 0;
		spells[19].proctimes2 = 0;
		spells[19].reqlvl = 24;
		spells[19].attackstoptimer = 2000;

		spells[20].info = dbcSpell.LookupEntry(24578);
		spells[20].targettype = TARGET_ATTACKING;
		spells[20].instant = true;
		spells[20].cooldown = 12000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 55;
		spells[20].hpreqtocast = 100;
		spells[20].perctrigger = 15.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 48;
		spells[20].attackstoptimer = 2000;

		spells[21].info = dbcSpell.LookupEntry(24579);
		spells[21].targettype = TARGET_ATTACKING;
		spells[21].instant = true;
		spells[21].cooldown = 12000;
		spells[21].cooldown2 = 0;
		spells[21].maxlvl = 63;
		spells[21].hpreqtocast = 100;
		spells[21].perctrigger = 15.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 56;
		spells[21].attackstoptimer = 2000;

		spells[22].info = dbcSpell.LookupEntry(27051);
		spells[22].targettype = TARGET_ATTACKING;
		spells[22].instant = true;
		spells[22].cooldown = 12000;
		spells[22].cooldown2 = 0;
		spells[22].maxlvl = 0;
		spells[22].hpreqtocast = 100;
		spells[22].perctrigger = 15.0f;
		spells[22].proctimes = 0;
		spells[22].proctimes2 = 0;
		spells[22].reqlvl = 64;
		spells[22].attackstoptimer = 2000;

		/* END SCREECH // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastCat :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastCat);
	SP_AI_Spell spells[18];

	BeastCat(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 18;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 CLAW //
		 */
		spells[9].info = dbcSpell.LookupEntry(16827);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 7;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 1;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(16828);
		spells[10].rangecheck = true;
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 15;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 50.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 8;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(16829);
		spells[11].rangecheck = true;
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 23;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 50.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 16;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(16830);
		spells[12].rangecheck = true;
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 31;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 50.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 24;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(16831);
		spells[13].rangecheck = true;
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 39;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 50.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 32;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(16832);
		spells[14].rangecheck = true;
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 47;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 50.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 40;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(3010);
		spells[15].rangecheck = true;
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].cooldown = 6000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 55;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 50.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 48;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(3009);
		spells[16].rangecheck = true;
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].cooldown = 6000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 63;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 50.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 56;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(27049);
		spells[17].rangecheck = true;
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].cooldown = 6000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 0;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 50.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 64;
		spells[17].attackstoptimer = 2000;

		/* END CLAW // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastCrab :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastCrab);
	SP_AI_Spell spells[10];

	BeastCrab(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 10;

		/* CLAW // */
		spells[0].info = dbcSpell.LookupEntry(16827);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 1;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 1.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(16827);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 7;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 50.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 1;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(16828);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 15;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 50.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 8;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(16829);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 23;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 50.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 16;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(16830);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 50.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 24;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(16831);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 39;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 50.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(16832);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 47;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 50.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 40;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(3010);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 55;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 50.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 48;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(3009);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 63;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 50.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 56;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(27049);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 64;
		spells[9].attackstoptimer = 2000;

		/* END CLAW // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 8000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastCrocolisk :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastCrocolisk);
	SP_AI_Spell spells[9];

	BeastCrocolisk(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 9;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/* END BITE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastDragonhawk :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastDragonhawk);
	SP_AI_Spell spells[11];

	BeastDragonhawk(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 11;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 FIRE BREATH //
		 */
		spells[9].info = dbcSpell.LookupEntry(34889);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].rangecheck = true;
		spells[9].cooldown = 16000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 63;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 1;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(35323);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].rangecheck = true;
		spells[10].cooldown = 16000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 0;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 20.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 64;
		spells[10].attackstoptimer = 2000;

		/* END FIRE BREATH // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastGorilla :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastGorilla);
	SP_AI_Spell spells[13];

	BeastGorilla(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 13;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 THUNDER STOMP /
		 */
		spells[9].info = dbcSpell.LookupEntry(26090);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].rangecheck = true;
		spells[9].cooldown = 20000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 39;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 30;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(26187);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].rangecheck = true;
		spells[10].cooldown = 20000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 49;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 20.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 40;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(26188);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].rangecheck = true;
		spells[11].cooldown = 20000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 59;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 20.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 50;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(27063);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].rangecheck = true;
		spells[12].cooldown = 20000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 20.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 60;
		spells[12].attackstoptimer = 2000;

		/* END THUNDERSTOMP // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastHyena :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastHyena);
	SP_AI_Spell spells[9];

	BeastHyena(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 9;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/* END BITE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastNetherRay :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastNetherRay);
	SP_AI_Spell spells[9];

	BeastNetherRay(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 9;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/* END BITE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastOwl :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastOwl);
	SP_AI_Spell spells[15];

	BeastOwl(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 15;

		/* CLAW // */
		spells[0].info = dbcSpell.LookupEntry(16827);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 1;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 1.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(16827);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 7;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 50.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 1;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(16828);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 15;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 50.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 8;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(16829);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 23;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 50.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 16;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(16830);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 50.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 24;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(16831);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 39;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 50.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(16832);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 47;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 50.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 40;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(3010);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 55;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 50.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 48;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(3009);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 63;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 50.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 56;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(27049);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 64;
		spells[9].attackstoptimer = 2000;

		/*
			 END CLAW // ;
			 SCREECH //
		 */
		spells[10].info = dbcSpell.LookupEntry(24423);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 12000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 23;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 15.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 8;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(24577);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 12000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 47;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 15.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 24;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(24578);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 12000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 55;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 15.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 48;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(24579);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 12000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 63;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 15.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 56;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(27051);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].cooldown = 12000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 0;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 15.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 64;
		spells[14].attackstoptimer = 2000;

		/* END SCREECH // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastRaptor :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastRaptor);
	SP_AI_Spell spells[18];

	BeastRaptor(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 18;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 CLAW //
		 */
		spells[9].info = dbcSpell.LookupEntry(16827);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 7;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 1;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(16828);
		spells[10].rangecheck = true;
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 15;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 50.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 8;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(16829);
		spells[11].rangecheck = true;
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 23;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 50.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 16;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(16830);
		spells[12].rangecheck = true;
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 31;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 50.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 24;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(16831);
		spells[13].rangecheck = true;
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 39;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 50.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 32;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(16832);
		spells[14].rangecheck = true;
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 47;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 50.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 40;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(3010);
		spells[15].rangecheck = true;
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].cooldown = 6000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 55;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 50.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 48;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(3009);
		spells[16].rangecheck = true;
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].cooldown = 6000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 63;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 50.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 56;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(27049);
		spells[17].rangecheck = true;
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].cooldown = 6000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 0;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 50.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 64;
		spells[17].attackstoptimer = 2000;

		/* END CLAW // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastRavager :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastRavager);
	SP_AI_Spell spells[22];

	BeastRavager(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 22;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 DASH //
		 */
		spells[9].info = dbcSpell.LookupEntry(23099);
		spells[9].targettype = TARGET_SELF;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 39;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 100.0f;
		spells[9].distancecheck = true;
		spells[9].proctimes = 1;
		spells[9].proctimes2 = 1;
		spells[9].reqlvl = 30;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(23109);
		spells[10].targettype = TARGET_SELF;
		spells[10].instant = true;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 49;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 100.0f;
		spells[10].distancecheck = true;
		spells[10].proctimes = 1;
		spells[10].proctimes2 = 1;
		spells[10].reqlvl = 40;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(23110);
		spells[11].targettype = TARGET_SELF;
		spells[11].instant = true;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 59;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 100.0f;
		spells[11].distancecheck = true;
		spells[11].proctimes = 1;
		spells[11].proctimes2 = 1;
		spells[11].reqlvl = 50;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(23110);
		spells[12].targettype = TARGET_SELF;
		spells[12].instant = true;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 100.0f;
		spells[12].distancecheck = true;
		spells[12].proctimes = 1;
		spells[12].proctimes2 = 1;
		spells[12].reqlvl = 60;
		spells[12].attackstoptimer = 2000;

		/*
			 END DASH // ;
			 GORE /
		 */
		spells[13].info = dbcSpell.LookupEntry(35290);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].rangecheck = true;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 7;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 20.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 1;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(35291);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].rangecheck = true;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 15;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 20.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 8;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(35292);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].cooldown = 6000;
		spells[15].rangecheck = true;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 23;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 20.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 16;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(35293);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].cooldown = 6000;
		spells[16].rangecheck = true;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 31;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 20.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 24;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(35294);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].rangecheck = true;
		spells[17].cooldown = 6000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 39;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 20.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 32;
		spells[17].attackstoptimer = 2000;

		spells[18].info = dbcSpell.LookupEntry(35295);
		spells[18].targettype = TARGET_ATTACKING;
		spells[18].instant = true;
		spells[18].rangecheck = true;
		spells[18].cooldown = 6000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 47;
		spells[18].hpreqtocast = 100;
		spells[18].perctrigger = 20.0f;
		spells[18].proctimes = 0;
		spells[18].proctimes2 = 0;
		spells[18].reqlvl = 40;
		spells[18].attackstoptimer = 2000;

		spells[19].info = dbcSpell.LookupEntry(35296);
		spells[19].targettype = TARGET_ATTACKING;
		spells[19].instant = true;
		spells[19].rangecheck = true;
		spells[19].cooldown = 6000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 55;
		spells[19].hpreqtocast = 100;
		spells[19].perctrigger = 20.0f;
		spells[19].proctimes = 0;
		spells[19].proctimes2 = 0;
		spells[19].reqlvl = 48;
		spells[19].attackstoptimer = 2000;

		spells[20].info = dbcSpell.LookupEntry(35297);
		spells[20].targettype = TARGET_ATTACKING;
		spells[20].instant = true;
		spells[20].rangecheck = true;
		spells[20].cooldown = 6000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 62;
		spells[20].hpreqtocast = 100;
		spells[20].perctrigger = 20.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 56;
		spells[20].attackstoptimer = 2000;

		spells[21].info = dbcSpell.LookupEntry(35298);
		spells[21].targettype = TARGET_ATTACKING;
		spells[21].instant = true;
		spells[21].rangecheck = true;
		spells[21].cooldown = 6000;
		spells[21].cooldown2 = 0;
		spells[21].maxlvl = 0;
		spells[21].hpreqtocast = 100;
		spells[21].perctrigger = 20.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 63;
		spells[21].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastScorpion :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastScorpion);
	SP_AI_Spell spells[15];

	BeastScorpion(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 15;

		/* CLAW // */
		spells[0].info = dbcSpell.LookupEntry(16827);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 1;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 1.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(16827);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 7;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 1;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(16828);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 15;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 8;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(16829);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 23;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 16;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(16830);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 24;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(16831);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 39;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(16832);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 47;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 40;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(3010);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 55;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 20.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 48;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(3009);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 63;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 20.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 56;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(27049);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 64;
		spells[9].attackstoptimer = 2000;

		/*
			 END CLAW // ;
			 SCORPID POISON //
		 */
		spells[10].info = dbcSpell.LookupEntry(24640);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].rangecheck = true;
		spells[10].cooldown = 10000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 23;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 50.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 8;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(24583);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].rangecheck = true;
		spells[11].cooldown = 10000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 39;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 50.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 24;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(24586);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].rangecheck = true;
		spells[12].cooldown = 10000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 55;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 50.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 40;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(24587);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].rangecheck = true;
		spells[13].cooldown = 10000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 63;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 50.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 56;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(27060);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].rangecheck = true;
		spells[14].cooldown = 10000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 0;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 50.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 64;
		spells[14].attackstoptimer = 2000;

		/* END SCORPID POISON // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastSerpent :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastSerpent);
	SP_AI_Spell spells[12];

	BeastSerpent(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 12;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 POISON SPI
		 */
		spells[9].info = dbcSpell.LookupEntry(35387);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].rangecheck = true;
		spells[9].cooldown = 10000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 44;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 15;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(35389);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].rangecheck = true;
		spells[10].cooldown = 10000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 59;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 50.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 45;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(35392);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].rangecheck = true;
		spells[11].cooldown = 10000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 0;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 50.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 60;
		spells[11].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastSpider :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastSpider);
	SP_AI_Spell spells[9];

	BeastSpider(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 9;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/* END BITE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastSporeBat :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastSporeBat);
	SP_AI_Spell spells[1];

	BeastSporeBat(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* Uhhh... ? */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 1;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 50.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastTallStrider :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastTallStrider);
	SP_AI_Spell spells[9];

	BeastTallStrider(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 9;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/* END BITE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 8000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastTurtle :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastTurtle);
	SP_AI_Spell spells[10];

	BeastTurtle(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 10;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 TURTLE SHIELD /
		 */
		spells[9].info = dbcSpell.LookupEntry(26064);
		spells[9].targettype = TARGET_SELF;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].hpreqtocast = 30;
		spells[9].perctrigger = 10.0f;
		spells[9].proctimes = 1;
		spells[9].proctimes2 = 1;
		spells[9].reqlvl = 20;
		spells[9].attackstoptimer = 2000;

		/* END TURTLE SHIELD // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastWarpStalker :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastWarpStalker);
	SP_AI_Spell spells[19];

	BeastWarpStalker(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 19;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 CLAW //
		 */
		spells[9].info = dbcSpell.LookupEntry(16827);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 7;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 1;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(16828);
		spells[10].rangecheck = true;
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 15;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 50.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 8;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(16829);
		spells[11].rangecheck = true;
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 23;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 50.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 16;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(16830);
		spells[12].rangecheck = true;
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 31;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 50.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 24;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(16831);
		spells[13].rangecheck = true;
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 39;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 50.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 32;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(16832);
		spells[14].rangecheck = true;
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 47;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 50.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 40;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(3010);
		spells[15].rangecheck = true;
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].cooldown = 6000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 55;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 50.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 48;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(3009);
		spells[16].rangecheck = true;
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].cooldown = 6000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 63;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 50.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 56;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(27049);
		spells[17].rangecheck = true;
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].cooldown = 6000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 0;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 50.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 64;
		spells[17].attackstoptimer = 2000;

		/*
			 END CLAW // ;
			 WARP /
		 */
		spells[18].info = dbcSpell.LookupEntry(35346);
		spells[18].targettype = TARGET_ATTACKING;
		spells[18].instant = true;
		spells[18].cooldown = 6000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 0;
		spells[18].hpreqtocast = 100;
		spells[18].distancecheck = true;
		spells[18].perctrigger = 50.0f;
		spells[18].proctimes = 1;
		spells[18].proctimes2 = 1;
		spells[18].reqlvl = 60;
		spells[18].attackstoptimer = 2000;

		/* END WARP // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastWindSerpent :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastWindSerpent);
	SP_AI_Spell spells[15];

	BeastWindSerpent(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 15;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 LIGHTNING BREATH //
		 */
		spells[9].info = dbcSpell.LookupEntry(24844);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].rangecheck = true;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 11;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 15.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 1;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(25008);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].rangecheck = true;
		spells[10].instant = true;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 23;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 15.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 12;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(25009);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].rangecheck = true;
		spells[11].instant = true;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 35;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 15.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 24;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(25010);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].rangecheck = true;
		spells[12].instant = true;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 47;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 15.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 36;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(25011);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].rangecheck = true;
		spells[13].instant = true;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 59;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 15.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 48;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(25012);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].rangecheck = true;
		spells[14].instant = true;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 0;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 15.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 60;
		spells[14].attackstoptimer = 2000;

		/* END LIGHTNING BREATH // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 1500;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class BeastWolf :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BeastWolf);
	SP_AI_Spell spells[13];

	BeastWolf(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 13;

		/* BITE // */
		spells[0].info = dbcSpell.LookupEntry(17253);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17255);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 15;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17256);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 16;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17257);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 31;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17258);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 39;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 32;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17259);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 47;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 40;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(17260);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 55;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 48;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(17261);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 63;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 56;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27050);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 64;
		spells[8].attackstoptimer = 2000;

		/*
			 END BITE // ;
			 FURIOUS HOWL /
		 */
		spells[9].info = dbcSpell.LookupEntry(24604);
		spells[9].targettype = TARGET_SELF;
		spells[9].instant = true;
		spells[9].cooldown = 12000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 23;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 15.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 10;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(24605);
		spells[10].targettype = TARGET_SELF;
		spells[10].instant = true;
		spells[10].cooldown = 12000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 39;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 15.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 24;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(24603);
		spells[11].targettype = TARGET_SELF;
		spells[11].instant = true;
		spells[11].cooldown = 12000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 55;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 15.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 40;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(24597);
		spells[12].targettype = TARGET_SELF;
		spells[12].instant = true;
		spells[12].cooldown = 12000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 15.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 56;
		spells[12].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

/*
 =======================================================================================================================
		Demon types:
 =======================================================================================================================
 */
class DoomGuard :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(DoomGuard);
	SP_AI_Spell spells[5];

	DoomGuard(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 5;

		/* INTERCEPT // */
		spells[0].info = dbcSpell.LookupEntry(30151);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].distancecheck = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 20;
		spells[0].attackstoptimer = 2000;

		/*
			 END INTERCEPT // ;
			 CLEAVE /
		 */
		spells[1].info = dbcSpell.LookupEntry(30213);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 59;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 50;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(30219);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].rangecheck = true;
		spells[2].instant = true;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 67;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 60;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(30223);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].rangecheck = true;
		spells[3].instant = true;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 0;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 68;
		spells[3].attackstoptimer = 2000;

		/*
			 END CLEAVE // ;
			 ENRAGE /
		 */
		spells[4].info = dbcSpell.LookupEntry(29691);
		spells[4].targettype = TARGET_SELF;
		spells[4].instant = true;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 0;
		spells[4].hpreqtocast = 100;
		spells[4].hpreqtocast = 15;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 1;
		spells[4].proctimes2 = 1;
		spells[4].reqlvl = 0;
		spells[4].attackstoptimer = 2000;

		/* END RAGE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class Felhunter :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Felhunter);
	SP_AI_Spell spells[13];

	Felhunter(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 13;

		/* DEVOUR MAGIC // */
		spells[0].info = dbcSpell.LookupEntry(19505);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 10000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 37;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 30;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(19731);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 10000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 45;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 38;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(19734);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 10000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 53;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 46;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(19736);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 10000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 61;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 54;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(27276);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 10000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 69;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 62;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(27277);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 10000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 0;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 70;
		spells[5].attackstoptimer = 2000;

		/*
			 END DEVOUR MAGIC // ;
			 MANA BURN //
		 */
		spells[6].info = dbcSpell.LookupEntry(8129);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 20000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 31;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 24;
		spells[6].attackstoptimer = 4000;

		spells[7].info = dbcSpell.LookupEntry(8131);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 20000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 39;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 32;
		spells[7].attackstoptimer = 4000;

		spells[8].info = dbcSpell.LookupEntry(10874);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 20000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 47;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 40;
		spells[8].attackstoptimer = 4000;

		spells[9].info = dbcSpell.LookupEntry(10875);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 20000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 55;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 10.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 48;
		spells[9].attackstoptimer = 4000;

		spells[10].info = dbcSpell.LookupEntry(10876);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 20000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 62;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 10.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 56;
		spells[10].attackstoptimer = 4000;

		spells[11].info = dbcSpell.LookupEntry(25379);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 20000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 69;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 10.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 63;
		spells[11].attackstoptimer = 4000;

		spells[12].info = dbcSpell.LookupEntry(25380);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 20000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 10.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 70;
		spells[12].attackstoptimer = 4000;

		/* END MANA BURN // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class Imp :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Imp);
	SP_AI_Spell spells[8];

	Imp(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 8;

		/* FIREBOLT // */
		spells[0].info = dbcSpell.LookupEntry(3110);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 1500;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 80.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2800;

		spells[1].info = dbcSpell.LookupEntry(7799);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 1500;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 17;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 80.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2800;

		spells[2].info = dbcSpell.LookupEntry(7800);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 1500;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 27;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 80.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 18;
		spells[2].attackstoptimer = 2800;

		spells[3].info = dbcSpell.LookupEntry(7801);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 1500;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 37;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 80.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 28;
		spells[3].attackstoptimer = 2800;

		spells[4].info = dbcSpell.LookupEntry(7802);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 1500;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 47;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 80.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 38;
		spells[4].attackstoptimer = 2800;

		spells[5].info = dbcSpell.LookupEntry(11762);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 1500;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 57;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 80.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 48;
		spells[5].attackstoptimer = 2800;

		spells[6].info = dbcSpell.LookupEntry(11763);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 1500;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 67;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 80.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 58;
		spells[6].attackstoptimer = 2800;

		spells[7].info = dbcSpell.LookupEntry(27267);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 1500;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 0;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 80.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 68;
		spells[7].attackstoptimer = 2800;

		/* END FIREBOLT // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 1500;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class Succubus :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Succubus);
	SP_AI_Spell spells[7];

	Succubus(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 7;

		/* LASH OF PAIN // */
		spells[0].info = dbcSpell.LookupEntry(7814);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 12000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 27;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 20;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(7815);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 12000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 35;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 28;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(7816);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].rangecheck = true;
		spells[2].cooldown = 12000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 43;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 36;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(11778);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].rangecheck = true;
		spells[3].cooldown = 12000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 51;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 44;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(11779);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].rangecheck = true;
		spells[4].cooldown = 12000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 59;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 52;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(11780);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].rangecheck = true;
		spells[5].cooldown = 12000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 67;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 60;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(27274);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].rangecheck = true;
		spells[6].cooldown = 12000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 0;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 68;
		spells[6].attackstoptimer = 2000;

		/*
			 END LASH OF PAIN // ;
			 SEDUCTION //
		 */
		spells[6].info = dbcSpell.LookupEntry(6358);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 12000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 0;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 5.0f;
		spells[6].proctimes = 1;
		spells[6].proctimes2 = 1;
		spells[6].reqlvl = 0;
		spells[6].attackstoptimer = 8000;

		/* END OF SEDUCTION // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class VoidwalkerMob :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(VoidwalkerMob);
	SP_AI_Spell spells[7];

	VoidwalkerMob(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 7;

		/* CONSUME OF SHADOWS // */
		spells[0].info = dbcSpell.LookupEntry(17767);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 25;
		spells[0].hpreqtocast = 100;
		spells[0].hpreqtocast = 40;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 18;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(17850);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].cooldown = 4000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 33;
		spells[1].hpreqtocast = 100;
		spells[1].hpreqtocast = 40;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 1;
		spells[1].proctimes2 = 1;
		spells[1].reqlvl = 26;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(17851);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = true;
		spells[2].cooldown = 4000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 41;
		spells[2].hpreqtocast = 100;
		spells[2].hpreqtocast = 40;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 1;
		spells[2].proctimes2 = 1;
		spells[2].reqlvl = 34;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(17852);
		spells[3].targettype = TARGET_SELF;
		spells[3].instant = true;
		spells[3].cooldown = 4000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 49;
		spells[3].hpreqtocast = 100;
		spells[3].hpreqtocast = 40;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 1;
		spells[3].proctimes2 = 1;
		spells[3].reqlvl = 42;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(17853);
		spells[4].targettype = TARGET_SELF;
		spells[4].instant = true;
		spells[4].cooldown = 4000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 57;
		spells[4].hpreqtocast = 100;
		spells[4].hpreqtocast = 40;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 1;
		spells[4].proctimes2 = 1;
		spells[4].reqlvl = 50;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(17854);
		spells[5].targettype = TARGET_SELF;
		spells[5].instant = true;
		spells[5].cooldown = 4000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 65;
		spells[5].hpreqtocast = 100;
		spells[5].hpreqtocast = 40;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 1;
		spells[5].proctimes2 = 1;
		spells[5].reqlvl = 58;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(27272);
		spells[6].targettype = TARGET_SELF;
		spells[6].instant = true;
		spells[6].cooldown = 4000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 0;
		spells[6].hpreqtocast = 100;
		spells[6].hpreqtocast = 40;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 1;
		spells[6].proctimes2 = 1;
		spells[6].reqlvl = 66;
		spells[6].attackstoptimer = 2000;

		/* END CONSUME SHADOWS // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

/*
 =======================================================================================================================
		Elemental types:
 =======================================================================================================================
 */
class ElementalAir :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ElementalAir);
	SP_AI_Spell spells[10];

	ElementalAir(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 10;

		/* LIGHTNING SHIELD // */
		spells[0].info = dbcSpell.LookupEntry(34335);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 12000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(325);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].cooldown = 12000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 23;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 100.0f;
		spells[1].proctimes = 3;
		spells[1].proctimes2 = 3;
		spells[1].reqlvl = 16;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(905);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = true;
		spells[2].cooldown = 12000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 31;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 100.0f;
		spells[2].proctimes = 3;
		spells[2].proctimes2 = 3;
		spells[2].reqlvl = 24;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(945);
		spells[3].targettype = TARGET_SELF;
		spells[3].instant = true;
		spells[3].cooldown = 12000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 39;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 100.0f;
		spells[3].proctimes = 3;
		spells[3].proctimes2 = 3;
		spells[3].reqlvl = 32;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(8134);
		spells[4].targettype = TARGET_SELF;
		spells[4].instant = true;
		spells[4].cooldown = 12000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 47;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 100.0f;
		spells[4].proctimes = 3;
		spells[4].proctimes2 = 3;
		spells[4].reqlvl = 40;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(10431);
		spells[5].targettype = TARGET_SELF;
		spells[5].instant = true;
		spells[5].cooldown = 12000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 55;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 100.0f;
		spells[5].proctimes = 3;
		spells[5].proctimes2 = 3;
		spells[5].reqlvl = 48;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(10432);
		spells[6].targettype = TARGET_SELF;
		spells[6].instant = true;
		spells[6].cooldown = 12000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 61;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 100.0f;
		spells[6].proctimes = 3;
		spells[6].proctimes2 = 3;
		spells[6].reqlvl = 56;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(25469);
		spells[7].targettype = TARGET_SELF;
		spells[7].instant = true;
		spells[7].cooldown = 12000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 69;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 100.0f;
		spells[7].proctimes = 3;
		spells[7].proctimes2 = 3;
		spells[7].reqlvl = 62;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(25472);
		spells[8].targettype = TARGET_SELF;
		spells[8].instant = true;
		spells[8].cooldown = 12000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 100.0f;
		spells[8].proctimes = 3;
		spells[8].proctimes2 = 3;
		spells[8].reqlvl = 70;
		spells[8].attackstoptimer = 2000;

		/*
			 END LIGHTNING SHIELD // ;
			 LIGHTNING BOLT //
		 */
		spells[9].info = dbcSpell.LookupEntry(45291);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 10000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 15.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 52;
		spells[9].attackstoptimer = 2000;

		/* END LIGHTNING BOLT // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class ElementalEarth :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ElementalEarth);
	SP_AI_Spell spells[1];

	ElementalEarth(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* GROUND SMASH // */
		spells[0].info = dbcSpell.LookupEntry(38784);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 20000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 3.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class ElementalFire :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ElementalFire);
	SP_AI_Spell spells[15];

	ElementalFire(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 15;

		/* FIRE BLAST // */
		spells[0].info = dbcSpell.LookupEntry(34333);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 12000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(2137);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 12000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 21;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 14;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(2138);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 12000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 29;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 22;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(8412);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 12000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 37;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 30;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(8413);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 12000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 45;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 38;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(10197);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 12000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 53;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 46;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(10199);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 12000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 61;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 54;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(27078);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 12000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 69;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 62;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27079);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 12000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 70;
		spells[8].attackstoptimer = 2000;

		/*
			 END FIRE BLAST // ;
			 BLAST WAVE //
		 */
		spells[9].info = dbcSpell.LookupEntry(11113);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].rangecheck = true;
		spells[9].cooldown = 12000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 37;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 4.0f;
		spells[9].proctimes = 1;
		spells[9].proctimes2 = 1;
		spells[9].reqlvl = 30;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(13018);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].rangecheck = true;
		spells[10].cooldown = 12000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 45;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 4.0f;
		spells[10].proctimes = 1;
		spells[10].proctimes2 = 1;
		spells[10].reqlvl = 38;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(13019);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].rangecheck = true;
		spells[11].cooldown = 12000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 53;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 4.0f;
		spells[11].proctimes = 1;
		spells[11].proctimes2 = 1;
		spells[11].reqlvl = 46;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(13020);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].rangecheck = true;
		spells[12].cooldown = 12000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 61;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 4.0f;
		spells[12].proctimes = 1;
		spells[12].proctimes2 = 1;
		spells[12].reqlvl = 54;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(13021);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].rangecheck = true;
		spells[13].cooldown = 12000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 69;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 4.0f;
		spells[13].proctimes = 1;
		spells[13].proctimes2 = 1;
		spells[13].reqlvl = 62;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(27133);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].rangecheck = true;
		spells[14].cooldown = 12000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 0;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 4.0f;
		spells[14].proctimes = 1;
		spells[14].proctimes2 = 1;
		spells[14].reqlvl = 70;
		spells[14].attackstoptimer = 2000;

		/* END BLAST WAVE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

/*
 =======================================================================================================================
		moss elemental
 =======================================================================================================================
 */
class ElementalLife :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ElementalLife);
	SP_AI_Spell spells[2];

	ElementalLife(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 2;

		/* DAMAGE REDUCED PLAGUE // */
		spells[0].info = dbcSpell.LookupEntry(34335);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 20000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(40351);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 20000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 0;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 0;
		spells[1].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class ElementalMana :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ElementalMana);
	SP_AI_Spell spells[6];

	ElementalMana(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 6;

		/* DRAIN MANA // */
		spells[0].info = dbcSpell.LookupEntry(38860);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 10000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(6226);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 10000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 45;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 38;
		spells[1].attackstoptimer = 6000;

		spells[2].info = dbcSpell.LookupEntry(11703);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 10000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 53;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 46;
		spells[2].attackstoptimer = 6000;

		spells[3].info = dbcSpell.LookupEntry(11704);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 10000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 61;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 54;
		spells[3].attackstoptimer = 6000;

		spells[4].info = dbcSpell.LookupEntry(27221);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 10000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 69;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 62;
		spells[4].attackstoptimer = 6000;

		spells[5].info = dbcSpell.LookupEntry(30908);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 10000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 0;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 70;
		spells[5].attackstoptimer = 6000;

		/* END DRAIN MANA // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class ElementalShadow :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ElementalShadow);
	SP_AI_Spell spells[8];

	ElementalShadow(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 8;

		/* DRAIN LIFE // */
		spells[0].info = dbcSpell.LookupEntry(34338);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 10000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(699);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 10000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 29;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 22;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(709);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 10000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 37;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 30;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(7651);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 10000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 45;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 38;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(11699);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 10000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 53;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 46;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(11700);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 10000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 61;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 54;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(27219);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 10000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 69;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 62;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(27220);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 10000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 0;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 70;
		spells[7].attackstoptimer = 2000;

		/* END DRAIN LIFE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class ElementalWater :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ElementalWater);
	SP_AI_Spell spells[18];

	ElementalWater(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 18;

		/* FROSTBOLT // */
		spells[0].info = dbcSpell.LookupEntry(34334);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(205);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(837);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 19;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 3000;

		spells[3].info = dbcSpell.LookupEntry(7322);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 25;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 20;
		spells[3].attackstoptimer = 3000;

		spells[4].info = dbcSpell.LookupEntry(8406);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 26;
		spells[4].attackstoptimer = 3000;

		spells[5].info = dbcSpell.LookupEntry(8407);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 8000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 37;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 4000;

		spells[6].info = dbcSpell.LookupEntry(8408);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 8000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 43;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 38;
		spells[6].attackstoptimer = 4000;

		spells[7].info = dbcSpell.LookupEntry(10179);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 8000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 49;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 44;
		spells[7].attackstoptimer = 4000;

		spells[8].info = dbcSpell.LookupEntry(10180);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 8000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 55;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 50;
		spells[8].attackstoptimer = 4000;

		spells[9].info = dbcSpell.LookupEntry(10181);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 8000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 59;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 10.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 56;
		spells[9].attackstoptimer = 4000;

		spells[10].info = dbcSpell.LookupEntry(25304);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 8000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 62;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 10.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 60;
		spells[10].attackstoptimer = 4000;

		spells[11].info = dbcSpell.LookupEntry(27071);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 8000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 68;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 10.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 63;
		spells[11].attackstoptimer = 4000;

		spells[12].info = dbcSpell.LookupEntry(27072);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 8000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 10.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 69;
		spells[12].attackstoptimer = 4000;

		/*
			 END FROSTBOLT // ;
			 FROST NOVA //
		 */
		spells[13].info = dbcSpell.LookupEntry(122);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].rangecheck = true;
		spells[13].cooldown = 25000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 25;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 5.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 10;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(865);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].rangecheck = true;
		spells[14].cooldown = 25000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 39;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 5.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 26;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(6131);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].rangecheck = true;
		spells[15].cooldown = 25000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 53;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 5.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 40;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(10230);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].rangecheck = true;
		spells[16].cooldown = 25000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 66;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 5.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 54;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(27088);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].rangecheck = true;
		spells[17].cooldown = 25000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 0;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 5.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 67;
		spells[17].attackstoptimer = 2000;

		/* END FROST NOVA // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

/*
 =======================================================================================================================
		Humanoid types:
 =======================================================================================================================
 */
class HumanoidDruidFeral :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidDruidFeral);
	SP_AI_Spell spells[1];

	HumanoidDruidFeral(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* SHAPESHIFT BEAR - STILL DOESNT CHANGE MODEL ID ON CREATURE :( // */
		spells[0].info = dbcSpell.LookupEntry(18309);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		/* END SHAPESHIFT BEAR // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 3000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidDruidBalance :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidDruidBalance);
	SP_AI_Spell spells[22];

	HumanoidDruidBalance(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 22;

		/* WRATH // */
		spells[0].info = dbcSpell.LookupEntry(5176);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 5;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(5177);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 6;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(5178);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 21;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(5179);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 29;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 22;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(5180);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 37;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 30;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(6780);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 8000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 45;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 38;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(8905);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 8000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 53;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 46;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(9912);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 8000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 60;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 20.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 54;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(26984);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 8000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 68;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 20.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 61;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(26985);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 8000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 69;
		spells[9].attackstoptimer = 2000;

		/*
			 END WRATH // ;
			 MOONFIRE //
		 */
		spells[10].info = dbcSpell.LookupEntry(8921);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 6000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 9;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 10.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 4;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(8924);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 6000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 15;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 10.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 10;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(8925);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 6000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 21;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 10.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 16;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(8926);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = false;
		spells[13].cooldown = 6000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 27;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 10.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 22;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(8927);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = false;
		spells[14].cooldown = 6000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 33;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 10.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 28;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(8928);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = false;
		spells[15].cooldown = 6000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 39;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 10.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 34;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(8929);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = false;
		spells[16].cooldown = 6000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 45;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 10.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 40;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(9833);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = false;
		spells[17].cooldown = 6000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 51;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 10.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 46;
		spells[17].attackstoptimer = 2000;

		spells[18].info = dbcSpell.LookupEntry(9834);
		spells[18].targettype = TARGET_ATTACKING;
		spells[18].instant = false;
		spells[18].cooldown = 6000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 57;
		spells[18].hpreqtocast = 100;
		spells[18].perctrigger = 10.0f;
		spells[18].proctimes = 0;
		spells[18].proctimes2 = 0;
		spells[18].reqlvl = 52;
		spells[18].attackstoptimer = 2000;

		spells[19].info = dbcSpell.LookupEntry(9835);
		spells[19].targettype = TARGET_ATTACKING;
		spells[19].instant = false;
		spells[19].cooldown = 6000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 62;
		spells[19].hpreqtocast = 100;
		spells[19].perctrigger = 10.0f;
		spells[19].proctimes = 0;
		spells[19].proctimes2 = 0;
		spells[19].reqlvl = 58;
		spells[19].attackstoptimer = 2000;

		spells[20].info = dbcSpell.LookupEntry(26987);
		spells[20].targettype = TARGET_ATTACKING;
		spells[20].instant = false;
		spells[20].cooldown = 6000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 69;
		spells[20].hpreqtocast = 100;
		spells[20].perctrigger = 10.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 63;
		spells[20].attackstoptimer = 2000;

		spells[21].info = dbcSpell.LookupEntry(26988);
		spells[21].targettype = TARGET_ATTACKING;
		spells[21].instant = false;
		spells[21].cooldown = 6000;
		spells[21].cooldown2 = 0;
		spells[21].maxlvl = 0;
		spells[21].hpreqtocast = 100;
		spells[21].perctrigger = 10.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 70;
		spells[21].attackstoptimer = 2000;

		/* END MOONFIRE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidGeomancer :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidGeomancer);
	SP_AI_Spell spells[13];

	HumanoidGeomancer(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 13;

		/* FIREBALL // */
		spells[0].info = dbcSpell.LookupEntry(133);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 5;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(143);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 4000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 11;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 100.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 6;
		spells[1].attackstoptimer = 2500;

		spells[2].info = dbcSpell.LookupEntry(145);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 4000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 17;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 100.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 12;
		spells[2].attackstoptimer = 3000;

		spells[3].info = dbcSpell.LookupEntry(3140);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 4000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 23;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 100.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 18;
		spells[3].attackstoptimer = 3500;

		spells[4].info = dbcSpell.LookupEntry(8400);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 4000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 29;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 100.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 24;
		spells[4].attackstoptimer = 4000;

		spells[5].info = dbcSpell.LookupEntry(8401);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 4000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 35;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 100.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 30;
		spells[5].attackstoptimer = 4000;

		spells[6].info = dbcSpell.LookupEntry(8402);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 4000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 41;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 100.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 36;
		spells[6].attackstoptimer = 4000;

		spells[7].info = dbcSpell.LookupEntry(10148);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 4000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 47;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 100.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 42;
		spells[7].attackstoptimer = 4000;

		spells[8].info = dbcSpell.LookupEntry(10149);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 4000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 53;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 100.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 48;
		spells[8].attackstoptimer = 4000;

		spells[9].info = dbcSpell.LookupEntry(10150);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 4000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 59;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 100.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 54;
		spells[9].attackstoptimer = 4000;

		spells[10].info = dbcSpell.LookupEntry(10151);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 4000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 63;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 100.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 60;
		spells[10].attackstoptimer = 4000;

		spells[11].info = dbcSpell.LookupEntry(25306);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 4000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 67;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 100.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 64;
		spells[11].attackstoptimer = 4000;

		spells[12].info = dbcSpell.LookupEntry(27070);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 4000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 100.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 68;
		spells[12].attackstoptimer = 4000;

		/* END FIREBALL // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 1500;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidHunter :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidHunter);
	SP_AI_Spell spells[10];

	HumanoidHunter(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 10;

		/* ARCANE SHOT // */
		spells[0].info = dbcSpell.LookupEntry(3044);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 10000;
		spells[0].cooldown2 = 0;
		spells[0].distancecheck = true;
		spells[0].maxlvl = 11;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 80.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 6;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(14281);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 10000;
		spells[1].cooldown2 = 0;
		spells[1].distancecheck = true;
		spells[1].maxlvl = 19;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 80.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 12;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(14282);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 10000;
		spells[2].cooldown2 = 0;
		spells[2].distancecheck = true;
		spells[2].maxlvl = 27;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 80.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 20;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(14283);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 10000;
		spells[3].cooldown2 = 0;
		spells[3].distancecheck = true;
		spells[3].maxlvl = 35;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 80.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 28;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(14284);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 10000;
		spells[4].cooldown2 = 0;
		spells[4].distancecheck = true;
		spells[4].maxlvl = 43;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 80.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 36;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(14285);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 10000;
		spells[5].cooldown2 = 0;
		spells[5].distancecheck = true;
		spells[5].maxlvl = 51;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 80.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 44;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(14286);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 10000;
		spells[6].cooldown2 = 0;
		spells[6].distancecheck = true;
		spells[6].maxlvl = 59;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 80.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 52;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(14287);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 10000;
		spells[7].cooldown2 = 0;
		spells[7].distancecheck = true;
		spells[7].maxlvl = 68;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 80.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 60;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27019);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 10000;
		spells[8].cooldown2 = 0;
		spells[8].distancecheck = true;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 80.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 69;
		spells[8].attackstoptimer = 2000;

		/*
			 END ARCANE SHOT // ;
			 CONCUSSIVE SHOT //
		 */
		spells[9].info = dbcSpell.LookupEntry(5116);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 20000;
		spells[9].cooldown2 = 0;
		spells[9].distancecheck = true;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 100.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 8;
		spells[9].attackstoptimer = 2000;

		/* END CONCUSSIVE SHOT // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			/*~~~~~~~~~~~~~~~~~~~~~~~*/

			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(!spells[i].proctimes || spells[i].proctimes2)
				&&	(val <= spells[i].perctrigger)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(
						!spells[i].reqlvl
					||	(
							spells[i].reqlvl <= _unit->GetUInt32Value(UNIT_FIELD_LEVEL)
						&&	spells[i].reqlvl + 7 >= _unit->GetUInt32Value(UNIT_FIELD_LEVEL)
						)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
						break;

					case TARGET_VARIOUS:
						_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
						break;

					case TARGET_ATTACKING:
						_unit->CastSpell(target, spells[i].info, spells[i].instant);
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 1500;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidMageArcane :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidMageArcane);
	SP_AI_Spell spells[11];

	HumanoidMageArcane(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 11;

		/* ARCANE EXPLOSION */
		spells[0].info = dbcSpell.LookupEntry(1449);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 12000;
		spells[0].rangecheck = true;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 21;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 50.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 14;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(8437);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 12000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 29;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 50.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 22;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(8438);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].rangecheck = true;
		spells[2].cooldown = 12000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 37;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 50.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 30;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(8439);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].rangecheck = true;
		spells[3].cooldown = 12000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 45;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 50.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 38;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(10201);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].rangecheck = true;
		spells[4].cooldown = 12000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 53;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 50.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 46;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(10202);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].rangecheck = true;
		spells[5].cooldown = 12000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 61;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 50.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 54;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(27080);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].rangecheck = true;
		spells[6].cooldown = 12000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 69;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 50.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 62;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(27082);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].rangecheck = true;
		spells[7].cooldown = 12000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 0;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 50.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 70;
		spells[7].attackstoptimer = 2000;

		/* SLOW */
		spells[8].info = dbcSpell.LookupEntry(31589);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 25000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 50.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 50;
		spells[8].attackstoptimer = 2000;

		/* ARCANE POWER */
		spells[9].info = dbcSpell.LookupEntry(12042);
		spells[9].targettype = TARGET_SELF;
		spells[9].instant = true;
		spells[9].cooldown = 10000;
		spells[9].cooldown2 = 10000;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 1;
		spells[9].proctimes2 = 1;
		spells[9].reqlvl = 40;
		spells[9].attackstoptimer = 1000;

		/* ARCANE BLAST // */
		spells[10].info = dbcSpell.LookupEntry(30451);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 16000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 0;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 5.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 67;
		spells[10].attackstoptimer = 2000;

		/* END ARCANE BLAST // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 2000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidMageFire :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidMageFire);
	SP_AI_Spell spells[22];

	HumanoidMageFire(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 22;

		/* FIREBALL // */
		spells[0].info = dbcSpell.LookupEntry(133);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 5;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(143);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 11;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 100.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 6;
		spells[1].attackstoptimer = 2500;

		spells[2].info = dbcSpell.LookupEntry(145);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 17;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 100.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 12;
		spells[2].attackstoptimer = 3000;

		spells[3].info = dbcSpell.LookupEntry(3140);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 23;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 100.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 18;
		spells[3].attackstoptimer = 3500;

		spells[4].info = dbcSpell.LookupEntry(8400);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 29;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 100.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 24;
		spells[4].attackstoptimer = 4000;

		spells[5].info = dbcSpell.LookupEntry(8401);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 8000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 35;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 100.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 30;
		spells[5].attackstoptimer = 4000;

		spells[6].info = dbcSpell.LookupEntry(8402);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 8000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 41;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 100.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 36;
		spells[6].attackstoptimer = 4000;

		spells[7].info = dbcSpell.LookupEntry(10148);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 8000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 47;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 100.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 42;
		spells[7].attackstoptimer = 4000;

		spells[8].info = dbcSpell.LookupEntry(10149);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 8000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 53;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 100.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 48;
		spells[8].attackstoptimer = 4000;

		spells[9].info = dbcSpell.LookupEntry(10150);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 8000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 59;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 100.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 54;
		spells[9].attackstoptimer = 4000;

		spells[10].info = dbcSpell.LookupEntry(10151);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 8000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 63;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 100.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 60;
		spells[10].attackstoptimer = 4000;

		spells[11].info = dbcSpell.LookupEntry(25306);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 8000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 67;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 100.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 64;
		spells[11].attackstoptimer = 4000;

		spells[12].info = dbcSpell.LookupEntry(27070);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 8000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 100.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 68;
		spells[12].attackstoptimer = 4000;

		/*
			 END FIREBALL // ;
			 FIRE BLAST //
		 */
		spells[13].info = dbcSpell.LookupEntry(2137);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].cooldown = 12000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 21;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 10.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 14;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(2138);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].cooldown = 12000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 29;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 10.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 22;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(8412);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].cooldown = 12000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 37;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 10.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 30;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(8413);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].cooldown = 12000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 45;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 10.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 38;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(10197);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].cooldown = 12000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 53;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 10.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 46;
		spells[17].attackstoptimer = 2000;

		spells[18].info = dbcSpell.LookupEntry(10199);
		spells[18].targettype = TARGET_ATTACKING;
		spells[18].instant = true;
		spells[18].cooldown = 12000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 61;
		spells[18].hpreqtocast = 100;
		spells[18].perctrigger = 10.0f;
		spells[18].proctimes = 0;
		spells[18].proctimes2 = 0;
		spells[18].reqlvl = 54;
		spells[18].attackstoptimer = 2000;

		spells[19].info = dbcSpell.LookupEntry(27078);
		spells[19].targettype = TARGET_ATTACKING;
		spells[19].instant = true;
		spells[19].cooldown = 12000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 69;
		spells[19].hpreqtocast = 100;
		spells[19].perctrigger = 10.0f;
		spells[19].proctimes = 0;
		spells[19].proctimes2 = 0;
		spells[19].reqlvl = 62;
		spells[19].attackstoptimer = 2000;

		spells[20].info = dbcSpell.LookupEntry(27079);
		spells[20].targettype = TARGET_ATTACKING;
		spells[20].instant = true;
		spells[20].cooldown = 12000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 0;
		spells[20].hpreqtocast = 100;
		spells[20].perctrigger = 10.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 70;
		spells[20].attackstoptimer = 2000;

		/*
			 END FIRE BLAST // ;
			 FIRE WAR
		 */
		spells[21].info = dbcSpell.LookupEntry(27128);
		spells[21].targettype = TARGET_SELF;
		spells[21].instant = true;
		spells[21].cooldown = 15000;
		spells[21].cooldown2 = 5000;
		spells[21].maxlvl = 0;
		spells[21].hpreqtocast = 100;
		spells[21].perctrigger = 10.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 60;
		spells[21].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidMageFrost :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidMageFrost);
	SP_AI_Spell spells[18];

	HumanoidMageFrost(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 18;

		/* FROSTBOLT // */
		spells[0].info = dbcSpell.LookupEntry(116);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 4;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(205);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 100.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(837);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 19;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 100.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 3000;

		spells[3].info = dbcSpell.LookupEntry(7322);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 25;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 100.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 20;
		spells[3].attackstoptimer = 3000;

		spells[4].info = dbcSpell.LookupEntry(8406);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 100.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 26;
		spells[4].attackstoptimer = 3000;

		spells[5].info = dbcSpell.LookupEntry(8407);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 8000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 37;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 100.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 4000;

		spells[6].info = dbcSpell.LookupEntry(8408);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 8000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 43;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 100.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 38;
		spells[6].attackstoptimer = 4000;

		spells[7].info = dbcSpell.LookupEntry(10179);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 8000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 49;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 100.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 44;
		spells[7].attackstoptimer = 4000;

		spells[8].info = dbcSpell.LookupEntry(10180);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 8000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 55;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 100.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 50;
		spells[8].attackstoptimer = 4000;

		spells[9].info = dbcSpell.LookupEntry(10181);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 8000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 59;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 100.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 56;
		spells[9].attackstoptimer = 4000;

		spells[10].info = dbcSpell.LookupEntry(25304);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 8000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 62;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 100.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 60;
		spells[10].attackstoptimer = 4000;

		spells[11].info = dbcSpell.LookupEntry(27071);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 8000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 68;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 100.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 63;
		spells[11].attackstoptimer = 4000;

		spells[12].info = dbcSpell.LookupEntry(27072);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 8000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 100.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 69;
		spells[12].attackstoptimer = 4000;

		/*
			 END FROSTBOLT // ;
			 FROST NOVA //
		 */
		spells[13].info = dbcSpell.LookupEntry(122);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].rangecheck = true;
		spells[13].cooldown = 25000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 25;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 5.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 10;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(865);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].rangecheck = true;
		spells[14].cooldown = 25000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 39;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 5.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 26;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(6131);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].rangecheck = true;
		spells[15].cooldown = 25000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 53;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 5.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 40;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(10230);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = true;
		spells[16].rangecheck = true;
		spells[16].cooldown = 25000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 66;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 5.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 54;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(27088);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = true;
		spells[17].rangecheck = true;
		spells[17].cooldown = 25000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 0;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 5.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 67;
		spells[17].attackstoptimer = 2000;

		/* END FROST NOVA // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 3000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidPaladinProtection :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidPaladinProtection);
	SP_AI_Spell spells[5];

	HumanoidPaladinProtection(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 5;

		/* HAMMER OF JUSTICE // */
		spells[0].info = dbcSpell.LookupEntry(853);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 45000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 23;
		spells[0].hpreqtocast = 80;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 8;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(5588);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 45000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 39;
		spells[1].hpreqtocast = 80;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 24;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(5589);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 45000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 53;
		spells[2].hpreqtocast = 80;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 40;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(10308);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 45000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 0;
		spells[3].hpreqtocast = 80;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 54;
		spells[3].attackstoptimer = 2000;

		/*
			 END HAMMER OF JUSTICE // ;
			 DIVINE SHIELD //
		 */
		spells[4].info = dbcSpell.LookupEntry(642);
		spells[4].targettype = TARGET_SELF;
		spells[4].instant = true;
		spells[4].cooldown = 45000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 0;
		spells[4].hpreqtocast = 30;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 1;
		spells[4].proctimes2 = 1;
		spells[4].reqlvl = 40;
		spells[4].attackstoptimer = 2000;

		/* END DIVINE SHIELD // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidPaladinHoly :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidPaladinHoly);
	SP_AI_Spell spells[16];

	HumanoidPaladinHoly(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 16;

		/* HOLY LIGHT // */
		spells[0].info = dbcSpell.LookupEntry(635);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = false;
		spells[0].cooldown = 20000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 5;
		spells[0].hpreqtocast = 30;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(639);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = false;
		spells[1].cooldown = 20000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 30;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 6;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(647);
		spells[2].targettype = TARGET_VARIOUS;
		spells[2].instant = false;
		spells[2].cooldown = 20000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 21;
		spells[2].hpreqtocast = 30;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(1026);
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = false;
		spells[3].cooldown = 20000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 29;
		spells[3].hpreqtocast = 30;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 22;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(1042);
		spells[4].targettype = TARGET_VARIOUS;
		spells[4].instant = false;
		spells[4].cooldown = 20000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 37;
		spells[4].hpreqtocast = 30;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 30;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(3472);
		spells[5].targettype = TARGET_VARIOUS;
		spells[5].instant = false;
		spells[5].cooldown = 20000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 45;
		spells[5].hpreqtocast = 30;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 38;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(10328);
		spells[6].targettype = TARGET_VARIOUS;
		spells[6].instant = false;
		spells[6].cooldown = 20000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 53;
		spells[6].hpreqtocast = 30;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 46;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(10329);
		spells[7].targettype = TARGET_VARIOUS;
		spells[7].instant = false;
		spells[7].cooldown = 20000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 59;
		spells[7].hpreqtocast = 30;
		spells[7].perctrigger = 20.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 54;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(25292);
		spells[8].targettype = TARGET_VARIOUS;
		spells[8].instant = false;
		spells[8].cooldown = 20000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 69;
		spells[8].hpreqtocast = 30;
		spells[8].perctrigger = 20.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 60;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(27136);
		spells[9].targettype = TARGET_VARIOUS;
		spells[9].instant = false;
		spells[9].cooldown = 20000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 30;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 70;
		spells[9].attackstoptimer = 2000;

		/*
			 END HOLY LIGHT // ;
			 CONSECRATION //
		 */
		spells[10].info = dbcSpell.LookupEntry(26573);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].rangecheck = true;
		spells[10].cooldown = 25000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 29;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 10.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 20;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(20116);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].rangecheck = true;
		spells[11].cooldown = 25000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 39;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 10.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 30;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(20922);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].rangecheck = true;
		spells[12].cooldown = 25000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 49;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 10.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 40;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(20923);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].rangecheck = true;
		spells[13].cooldown = 25000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 59;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 10.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 50;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(20924);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].rangecheck = true;
		spells[14].cooldown = 25000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 69;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 10.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 60;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(27173);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].rangecheck = true;
		spells[15].cooldown = 25000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 0;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 10.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 70;
		spells[15].attackstoptimer = 2000;

		/* END CONSECRATION // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidPaladinRetribution :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidPaladinRetribution);
	SP_AI_Spell spells[6];

	HumanoidPaladinRetribution(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 6;

		/* SEAL OF COMMAND // */
		spells[0].info = dbcSpell.LookupEntry(20375);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 40000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 29;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 50.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 20;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(20915);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].cooldown = 40000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 39;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 50.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 30;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(20918);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = true;
		spells[2].cooldown = 40000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 49;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 50.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 40;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(20919);
		spells[3].targettype = TARGET_SELF;
		spells[3].instant = true;
		spells[3].cooldown = 40000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 59;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 50.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 50;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(20920);
		spells[4].targettype = TARGET_SELF;
		spells[4].instant = true;
		spells[4].cooldown = 40000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 69;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 50.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 60;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(27170);
		spells[5].targettype = TARGET_SELF;
		spells[5].instant = true;
		spells[5].cooldown = 40000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 0;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 50.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 70;
		spells[5].attackstoptimer = 2000;

		/* END SEAL OF COMMAND // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 1000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 2000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidPriestDiscipline :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidPriestDiscipline);
	SP_AI_Spell spells[12];

	HumanoidPriestDiscipline(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 12;

		/* POWER WORD SHIELD // */
		spells[0].info = dbcSpell.LookupEntry(17);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = true;
		spells[0].cooldown = 25000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 11;
		spells[0].hpreqtocast = 60;
		spells[0].perctrigger = 50.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 6;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(592);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = true;
		spells[1].cooldown = 25000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 17;
		spells[1].hpreqtocast = 60;
		spells[1].perctrigger = 50.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 12;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(600);
		spells[2].targettype = TARGET_VARIOUS;
		spells[2].instant = true;
		spells[2].cooldown = 25000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 60;
		spells[2].perctrigger = 50.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 18;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(3747);
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = true;
		spells[3].cooldown = 25000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 29;
		spells[3].hpreqtocast = 60;
		spells[3].perctrigger = 50.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(6065);
		spells[4].targettype = TARGET_VARIOUS;
		spells[4].instant = true;
		spells[4].cooldown = 25000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 35;
		spells[4].hpreqtocast = 60;
		spells[4].perctrigger = 50.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 30;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(6066);
		spells[5].targettype = TARGET_VARIOUS;
		spells[5].instant = true;
		spells[5].cooldown = 25000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 41;
		spells[5].hpreqtocast = 60;
		spells[5].perctrigger = 50.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 36;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(10898);
		spells[6].targettype = TARGET_VARIOUS;
		spells[6].instant = true;
		spells[6].cooldown = 25000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 47;
		spells[6].hpreqtocast = 60;
		spells[6].perctrigger = 50.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 42;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(10899);
		spells[7].targettype = TARGET_VARIOUS;
		spells[7].instant = true;
		spells[7].cooldown = 25000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 53;
		spells[7].hpreqtocast = 60;
		spells[7].perctrigger = 50.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 48;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(10900);
		spells[8].targettype = TARGET_VARIOUS;
		spells[8].instant = true;
		spells[8].cooldown = 25000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 59;
		spells[8].hpreqtocast = 60;
		spells[8].perctrigger = 50.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 54;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(10901);
		spells[9].targettype = TARGET_VARIOUS;
		spells[9].instant = true;
		spells[9].cooldown = 25000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 64;
		spells[9].hpreqtocast = 60;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 60;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(25217);
		spells[10].targettype = TARGET_VARIOUS;
		spells[10].instant = true;
		spells[10].cooldown = 25000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 69;
		spells[10].hpreqtocast = 60;
		spells[10].perctrigger = 50.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 65;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(25218);
		spells[11].targettype = TARGET_VARIOUS;
		spells[11].instant = true;
		spells[11].cooldown = 25000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 0;
		spells[11].hpreqtocast = 60;
		spells[11].perctrigger = 50.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 70;
		spells[11].attackstoptimer = 2000;

		/* END POWER WORD SHIELD // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 8000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidPriestHoly :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidPriestHoly);
	SP_AI_Spell spells[23];

	HumanoidPriestHoly(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 23;

		/* HEAL // */
		spells[0].info = dbcSpell.LookupEntry(2050);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = false;
		spells[0].cooldown = 15000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 3;
		spells[0].hpreqtocast = 40;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(2052);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = false;
		spells[1].cooldown = 15000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 9;
		spells[1].hpreqtocast = 40;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 4;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(2053);
		spells[2].targettype = TARGET_VARIOUS;
		spells[2].instant = false;
		spells[2].cooldown = 15000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 15;
		spells[2].hpreqtocast = 40;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 10;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(2054);
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = false;
		spells[3].cooldown = 15000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 21;
		spells[3].hpreqtocast = 40;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 16;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(2055);
		spells[4].targettype = TARGET_VARIOUS;
		spells[4].instant = false;
		spells[4].cooldown = 15000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 27;
		spells[4].hpreqtocast = 40;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 22;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(6063);
		spells[5].targettype = TARGET_VARIOUS;
		spells[5].instant = false;
		spells[5].cooldown = 15000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 33;
		spells[5].hpreqtocast = 40;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 28;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(6064);
		spells[6].targettype = TARGET_VARIOUS;
		spells[6].instant = false;
		spells[6].cooldown = 15000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 39;
		spells[6].hpreqtocast = 40;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 34;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(2060);
		spells[7].targettype = TARGET_VARIOUS;
		spells[7].instant = false;
		spells[7].cooldown = 15000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 45;
		spells[7].hpreqtocast = 40;
		spells[7].perctrigger = 20.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 40;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(10963);
		spells[8].targettype = TARGET_VARIOUS;
		spells[8].instant = false;
		spells[8].cooldown = 15000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 51;
		spells[8].hpreqtocast = 40;
		spells[8].perctrigger = 20.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 46;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(10964);
		spells[9].targettype = TARGET_VARIOUS;
		spells[9].instant = false;
		spells[9].cooldown = 15000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 57;
		spells[9].hpreqtocast = 40;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 52;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(10965);
		spells[10].targettype = TARGET_VARIOUS;
		spells[10].instant = false;
		spells[10].cooldown = 15000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 59;
		spells[10].hpreqtocast = 40;
		spells[10].perctrigger = 20.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 58;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(25314);
		spells[11].targettype = TARGET_VARIOUS;
		spells[11].instant = false;
		spells[11].cooldown = 15000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 62;
		spells[11].hpreqtocast = 40;
		spells[11].perctrigger = 20.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 60;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(25210);
		spells[12].targettype = TARGET_VARIOUS;
		spells[12].instant = false;
		spells[12].cooldown = 15000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 67;
		spells[12].hpreqtocast = 40;
		spells[12].perctrigger = 20.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 63;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(25213);
		spells[13].targettype = TARGET_VARIOUS;
		spells[13].instant = false;
		spells[13].cooldown = 15000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 0;
		spells[13].hpreqtocast = 40;
		spells[13].perctrigger = 20.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 68;
		spells[13].attackstoptimer = 2000;

		/*
			 END HEAL // ;
			 HOLY FIRE /
		 */
		spells[14].info = dbcSpell.LookupEntry(14914);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = false;
		spells[14].cooldown = 12000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 23;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 10.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 20;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(15262);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = false;
		spells[15].cooldown = 12000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 29;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 10.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 24;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(15263);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = false;
		spells[16].cooldown = 12000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 35;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 10.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 30;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(15264);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = false;
		spells[17].cooldown = 12000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 41;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 10.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 36;
		spells[17].attackstoptimer = 2000;

		spells[18].info = dbcSpell.LookupEntry(15265);
		spells[18].targettype = TARGET_ATTACKING;
		spells[18].instant = false;
		spells[18].cooldown = 12000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 47;
		spells[18].hpreqtocast = 100;
		spells[18].perctrigger = 10.0f;
		spells[18].proctimes = 0;
		spells[18].proctimes2 = 0;
		spells[18].reqlvl = 42;
		spells[18].attackstoptimer = 2000;

		spells[19].info = dbcSpell.LookupEntry(15266);
		spells[19].targettype = TARGET_ATTACKING;
		spells[19].instant = false;
		spells[19].cooldown = 12000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 53;
		spells[19].hpreqtocast = 100;
		spells[19].perctrigger = 10.0f;
		spells[19].proctimes = 0;
		spells[19].proctimes2 = 0;
		spells[19].reqlvl = 48;
		spells[19].attackstoptimer = 2000;

		spells[20].info = dbcSpell.LookupEntry(15267);
		spells[20].targettype = TARGET_ATTACKING;
		spells[20].instant = false;
		spells[20].cooldown = 12000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 59;
		spells[20].hpreqtocast = 100;
		spells[20].perctrigger = 10.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 54;
		spells[20].attackstoptimer = 2000;

		spells[21].info = dbcSpell.LookupEntry(15261);
		spells[21].targettype = TARGET_ATTACKING;
		spells[21].instant = false;
		spells[21].cooldown = 12000;
		spells[21].cooldown2 = 0;
		spells[21].maxlvl = 65;
		spells[21].hpreqtocast = 100;
		spells[21].perctrigger = 10.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 60;
		spells[21].attackstoptimer = 2000;

		spells[22].info = dbcSpell.LookupEntry(25384);
		spells[22].targettype = TARGET_ATTACKING;
		spells[22].instant = false;
		spells[22].cooldown = 12000;
		spells[22].cooldown2 = 0;
		spells[22].maxlvl = 0;
		spells[22].hpreqtocast = 100;
		spells[22].perctrigger = 10.0f;
		spells[22].proctimes = 0;
		spells[22].proctimes2 = 0;
		spells[22].reqlvl = 66;
		spells[22].attackstoptimer = 2000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidPriestShadow :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidPriestShadow);
	SP_AI_Spell spells[22];

	HumanoidPriestShadow(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 22;

		/* SHADOWFORM // */
		spells[0].info = dbcSpell.LookupEntry(15473);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 40;
		spells[0].attackstoptimer = 2000;

		/*
			 END SHADOWFORM // ;
			 SHADOW WORD PAIN //
		 */
		spells[1].info = dbcSpell.LookupEntry(589);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 30000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 9;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 4;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(594);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 30000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 17;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 10;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(970);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 30000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 25;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 18;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(992);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 30000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 33;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 26;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(2767);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 30000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 41;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 34;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(10892);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 30000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 49;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 42;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(10893);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 30000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 57;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 20.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 50;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(10894);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 30000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 64;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 20.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 58;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(25367);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 30000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 69;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 65;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(25368);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 30000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 0;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 20.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 70;
		spells[10].attackstoptimer = 2000;

		/*
			 END OF SHADOW WORD PAIN // ;
			 MIND BLAST //
		 */
		spells[11].info = dbcSpell.LookupEntry(8092);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 10000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 15;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 20.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 10;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(8102);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 10000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 21;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 20.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 16;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(8103);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = false;
		spells[13].cooldown = 10000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 27;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 20.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 22;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(8104);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = false;
		spells[14].cooldown = 10000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 33;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 20.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 28;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(3105);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = false;
		spells[15].cooldown = 10000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 39;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 20.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 34;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(8106);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = false;
		spells[16].cooldown = 10000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 45;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 20.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 40;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(10945);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = false;
		spells[17].cooldown = 10000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 51;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 20.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 46;
		spells[17].attackstoptimer = 2000;

		spells[18].info = dbcSpell.LookupEntry(10946);
		spells[18].targettype = TARGET_ATTACKING;
		spells[18].instant = false;
		spells[18].cooldown = 10000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 57;
		spells[18].hpreqtocast = 100;
		spells[18].perctrigger = 20.0f;
		spells[18].proctimes = 0;
		spells[18].proctimes2 = 0;
		spells[18].reqlvl = 52;
		spells[18].attackstoptimer = 2000;

		spells[19].info = dbcSpell.LookupEntry(10947);
		spells[19].targettype = TARGET_ATTACKING;
		spells[19].instant = false;
		spells[19].cooldown = 10000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 62;
		spells[19].hpreqtocast = 100;
		spells[19].perctrigger = 20.0f;
		spells[19].proctimes = 0;
		spells[19].proctimes2 = 0;
		spells[19].reqlvl = 58;
		spells[19].attackstoptimer = 2000;

		spells[20].info = dbcSpell.LookupEntry(25372);
		spells[20].targettype = TARGET_ATTACKING;
		spells[20].instant = false;
		spells[20].cooldown = 10000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 68;
		spells[20].hpreqtocast = 100;
		spells[20].perctrigger = 20.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 63;
		spells[20].attackstoptimer = 2000;

		spells[21].info = dbcSpell.LookupEntry(25375);
		spells[21].targettype = TARGET_ATTACKING;
		spells[21].instant = false;
		spells[21].cooldown = 10000;
		spells[21].cooldown2 = 0;
		spells[21].maxlvl = 0;
		spells[21].hpreqtocast = 100;
		spells[21].perctrigger = 20.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 69;
		spells[21].attackstoptimer = 2000;

		/* END MIND BLAST // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidRogueCombat :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidRogueCombat);
	SP_AI_Spell spells[16];

	HumanoidRogueCombat(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 16;

		/* SINISTER STRIKE // */
		spells[0].info = dbcSpell.LookupEntry(1752);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 5;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(1757);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 6;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(1758);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].rangecheck = true;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 21;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(1759);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].rangecheck = true;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 29;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 22;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(1760);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].rangecheck = true;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 37;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 30;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(8621);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].rangecheck = true;
		spells[5].cooldown = 8000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 45;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 38;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(11293);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].rangecheck = true;
		spells[6].cooldown = 8000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 53;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 46;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(11294);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].rangecheck = true;
		spells[7].cooldown = 8000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 61;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 54;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(26861);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].rangecheck = true;
		spells[8].cooldown = 8000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 69;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 62;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(26862);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].rangecheck = true;
		spells[9].cooldown = 8000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 10.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 70;
		spells[9].attackstoptimer = 2000;

		/*
			 END SINISTER STRIKE ;
			 GOUGE
		 */
		spells[10].info = dbcSpell.LookupEntry(1776);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].rangecheck = true;
		spells[10].cooldown = 8000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 17;
		spells[10].hpreqtocast = 60;
		spells[10].perctrigger = 20.0f;
		spells[10].proctimes = 1;
		spells[10].proctimes2 = 1;
		spells[10].reqlvl = 6;
		spells[10].attackstoptimer = 3500;

		spells[11].info = dbcSpell.LookupEntry(1777);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].rangecheck = true;
		spells[11].cooldown = 8000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 31;
		spells[11].hpreqtocast = 60;
		spells[11].perctrigger = 20.0f;
		spells[11].proctimes = 1;
		spells[11].proctimes2 = 1;
		spells[11].reqlvl = 18;
		spells[11].attackstoptimer = 3500;

		spells[12].info = dbcSpell.LookupEntry(8629);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].rangecheck = true;
		spells[12].cooldown = 8000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 45;
		spells[12].hpreqtocast = 60;
		spells[12].perctrigger = 20.0f;
		spells[12].proctimes = 1;
		spells[12].proctimes2 = 1;
		spells[12].reqlvl = 32;
		spells[12].attackstoptimer = 3500;

		spells[13].info = dbcSpell.LookupEntry(11285);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = true;
		spells[13].rangecheck = true;
		spells[13].cooldown = 8000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 59;
		spells[13].hpreqtocast = 60;
		spells[13].perctrigger = 20.0f;
		spells[13].proctimes = 1;
		spells[13].proctimes2 = 1;
		spells[13].reqlvl = 46;
		spells[13].attackstoptimer = 3500;

		spells[14].info = dbcSpell.LookupEntry(11286);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = true;
		spells[14].rangecheck = true;
		spells[14].cooldown = 8000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 66;
		spells[14].hpreqtocast = 60;
		spells[14].perctrigger = 20.0f;
		spells[14].proctimes = 1;
		spells[14].proctimes2 = 1;
		spells[14].reqlvl = 60;
		spells[14].attackstoptimer = 3500;

		spells[15].info = dbcSpell.LookupEntry(38764);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = true;
		spells[15].rangecheck = true;
		spells[15].cooldown = 8000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 0;
		spells[15].hpreqtocast = 60;
		spells[15].perctrigger = 20.0f;
		spells[15].proctimes = 1;
		spells[15].proctimes2 = 1;
		spells[15].reqlvl = 67;
		spells[15].attackstoptimer = 3500;

		/* END GOUGE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidRogueAssassination :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidRogueAssassination);
	SP_AI_Spell spells[1];

	HumanoidRogueAssassination(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* CHEAP SHOT // */
		spells[0].info = dbcSpell.LookupEntry(34243);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 14000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 1000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 2000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidRogueSubtlety :
	public CreatureAIScript /* AUTOMATIC STEALTH WHEN OUT OF COMBAT, NEVER TESTED THIS */
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidRogueSubtlety);
	SP_AI_Spell spells[1];

	HumanoidRogueSubtlety(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		spells[0].info = dbcSpell.LookupEntry(1784);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 0;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;
	}

	/*
	 ===================================================================================================================
			void OnCombatStart(Unit* mTarget) { gcd = 0;
			waittime = 4000;
			//RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
			}
	 ===================================================================================================================
	 */
	void OnCombatStop(Unit *mTarget)
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);

		/*
			 RemoveAIUpdateEvent();
		 */
		SpellCast();
	}

	void OnLoad()
	{
		SpellCast();
	}

	/*
	 ===================================================================================================================
			void OnDied(Unit * mKiller) { //RemoveAIUpdateEvent();
			} ;
			void AIUpdate() { SpellCast();
			}
	 ===================================================================================================================
	 */
	void SpellCast()
	{
		_unit->CastSpell(_unit, spells[0].info, spells[0].instant);
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidShamanRestoration :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidShamanRestoration);
	SP_AI_Spell spells[23];

	HumanoidShamanRestoration(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 23;

		/* HEAL // */
		spells[0].info = dbcSpell.LookupEntry(331);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = false;
		spells[0].cooldown = 20000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 5;
		spells[0].hpreqtocast = 40;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(332);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = false;
		spells[1].cooldown = 20000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 11;
		spells[1].hpreqtocast = 40;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 6;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(547);
		spells[2].targettype = TARGET_VARIOUS;
		spells[2].instant = false;
		spells[2].cooldown = 20000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 17;
		spells[2].hpreqtocast = 40;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 12;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(913);
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = false;
		spells[3].cooldown = 20000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 23;
		spells[3].hpreqtocast = 40;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 18;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(939);
		spells[4].targettype = TARGET_VARIOUS;
		spells[4].instant = false;
		spells[4].cooldown = 20000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 40;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 24;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(959);
		spells[5].targettype = TARGET_VARIOUS;
		spells[5].instant = false;
		spells[5].cooldown = 20000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 39;
		spells[5].hpreqtocast = 40;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(8005);
		spells[6].targettype = TARGET_VARIOUS;
		spells[6].instant = false;
		spells[6].cooldown = 20000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 47;
		spells[6].hpreqtocast = 40;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 40;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(10395);
		spells[7].targettype = TARGET_VARIOUS;
		spells[7].instant = false;
		spells[7].cooldown = 20000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 55;
		spells[7].hpreqtocast = 40;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 48;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(10396);
		spells[8].targettype = TARGET_VARIOUS;
		spells[8].instant = false;
		spells[8].cooldown = 20000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 62;
		spells[8].hpreqtocast = 40;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 56;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(25391);
		spells[9].targettype = TARGET_VARIOUS;
		spells[9].instant = false;
		spells[9].cooldown = 20000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 69;
		spells[9].hpreqtocast = 40;
		spells[9].perctrigger = 15.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 63;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(25396);
		spells[10].targettype = TARGET_VARIOUS;
		spells[10].instant = false;
		spells[10].cooldown = 20000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 0;
		spells[10].hpreqtocast = 40;
		spells[10].perctrigger = 15.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 70;
		spells[10].attackstoptimer = 2000;

		/*
			 END HEAL // ;
			 LIGHTNING BOLT //
		 */
		spells[11].info = dbcSpell.LookupEntry(403);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 8000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 7;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 20.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 1;
		spells[11].attackstoptimer = 1000;

		spells[12].info = dbcSpell.LookupEntry(529);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 8000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 13;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 20.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 8;
		spells[12].attackstoptimer = 1000;

		spells[13].info = dbcSpell.LookupEntry(548);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = false;
		spells[13].cooldown = 8000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 19;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 20.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 14;
		spells[13].attackstoptimer = 1000;

		spells[14].info = dbcSpell.LookupEntry(915);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = false;
		spells[14].cooldown = 8000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 25;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 20.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 20;
		spells[14].attackstoptimer = 1000;

		spells[15].info = dbcSpell.LookupEntry(943);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = false;
		spells[15].cooldown = 8000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 31;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 20.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 26;
		spells[15].attackstoptimer = 1000;

		spells[16].info = dbcSpell.LookupEntry(6041);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = false;
		spells[16].cooldown = 8000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 37;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 20.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 32;
		spells[16].attackstoptimer = 1000;

		spells[17].info = dbcSpell.LookupEntry(10391);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = false;
		spells[17].cooldown = 8000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 43;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 20.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 38;
		spells[17].attackstoptimer = 1000;

		spells[18].info = dbcSpell.LookupEntry(10392);
		spells[18].targettype = TARGET_ATTACKING;
		spells[18].instant = false;
		spells[18].cooldown = 8000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 49;
		spells[18].hpreqtocast = 100;
		spells[18].perctrigger = 20.0f;
		spells[18].proctimes = 0;
		spells[18].proctimes2 = 0;
		spells[18].reqlvl = 44;
		spells[18].attackstoptimer = 1000;

		spells[19].info = dbcSpell.LookupEntry(15207);
		spells[19].targettype = TARGET_ATTACKING;
		spells[19].instant = false;
		spells[19].cooldown = 8000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 55;
		spells[19].hpreqtocast = 100;
		spells[19].perctrigger = 20.0f;
		spells[19].proctimes = 0;
		spells[19].proctimes2 = 0;
		spells[19].reqlvl = 50;
		spells[19].attackstoptimer = 1000;

		spells[20].info = dbcSpell.LookupEntry(15208);
		spells[20].targettype = TARGET_ATTACKING;
		spells[20].instant = false;
		spells[20].cooldown = 8000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 61;
		spells[20].hpreqtocast = 100;
		spells[20].perctrigger = 20.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 56;
		spells[20].attackstoptimer = 1000;

		spells[21].info = dbcSpell.LookupEntry(25448);
		spells[21].targettype = TARGET_ATTACKING;
		spells[21].instant = false;
		spells[21].cooldown = 8000;
		spells[21].cooldown2 = 0;
		spells[21].maxlvl = 66;
		spells[21].hpreqtocast = 100;
		spells[21].perctrigger = 20.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 62;
		spells[21].attackstoptimer = 1000;

		spells[22].info = dbcSpell.LookupEntry(25449);
		spells[22].targettype = TARGET_ATTACKING;
		spells[22].instant = false;
		spells[22].cooldown = 8000;
		spells[22].cooldown2 = 0;
		spells[22].maxlvl = 0;
		spells[22].hpreqtocast = 100;
		spells[22].perctrigger = 20.0f;
		spells[22].proctimes = 0;
		spells[22].proctimes2 = 0;
		spells[22].reqlvl = 67;
		spells[22].attackstoptimer = 1000;

		/* END LIGHTNING BOLT // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidShamanElemental :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidShamanElemental);
	SP_AI_Spell spells[8];

	HumanoidShamanElemental(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 8;

		/* EARTH SHOCK // */
		spells[0].info = dbcSpell.LookupEntry(8042);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 4;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(8044);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(8045);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 23;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(8046);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 35;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 24;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(10412);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 47;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 36;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(10413);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 8000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 59;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 48;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(10414);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 8000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 68;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 60;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(25454);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 8000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 0;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 20.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 69;
		spells[7].attackstoptimer = 2000;

		/* END EARTH SHOCK // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidWarlockAffliction :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidWarlockAffliction);
	SP_AI_Spell spells[13];

	HumanoidWarlockAffliction(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 13;

		/* CORRUPTION // */
		spells[0].info = dbcSpell.LookupEntry(172);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 20000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 13;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(6222);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 22000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 23;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 14;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(6223);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 24000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 33;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 24;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(7648);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 26000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 43;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 34;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(11671);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 28000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 53;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 44;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(11672);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 30000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 64;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 54;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(27216);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 32000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 0;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 65;
		spells[6].attackstoptimer = 2000;

		/*
			 END OF CORRUPTION // ;
			 SIPHON LIFE
		 */
		spells[7].info = dbcSpell.LookupEntry(18265);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 20000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 37;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 15.0f;
		spells[7].proctimes = 1;
		spells[7].proctimes2 = 1;
		spells[7].reqlvl = 30;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(18879);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 20000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 47;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 15.0f;
		spells[8].proctimes = 1;
		spells[8].proctimes2 = 1;
		spells[8].reqlvl = 38;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(18880);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 20000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 57;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 15.0f;
		spells[9].proctimes = 1;
		spells[9].proctimes2 = 1;
		spells[9].reqlvl = 48;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(18881);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = true;
		spells[10].cooldown = 20000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 62;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 15.0f;
		spells[10].proctimes = 1;
		spells[10].proctimes2 = 1;
		spells[10].reqlvl = 58;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(27264);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = true;
		spells[11].cooldown = 20000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 69;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 15.0f;
		spells[11].proctimes = 1;
		spells[11].proctimes2 = 1;
		spells[11].reqlvl = 63;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(30911);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = true;
		spells[12].cooldown = 20000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 0;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 15.0f;
		spells[12].proctimes = 1;
		spells[12].proctimes2 = 1;
		spells[12].reqlvl = 70;
		spells[12].attackstoptimer = 2000;

		/* END SIPHON LIFE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidWarlockDestruction :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidWarlockDestruction);
	SP_AI_Spell spells[18];

	HumanoidWarlockDestruction(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 18;

		/* IMMOLATE // */
		spells[0].info = dbcSpell.LookupEntry(348);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 16000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 9;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(707);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 16000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 19;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 10;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(1094);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 16000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 29;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 20;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(2941);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 16000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 39;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 30;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(11665);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 16000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 49;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 40;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(11667);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 16000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 59;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 50;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(25309);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 16000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 69;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 60;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(27215);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 16000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 0;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 20.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 70;
		spells[7].attackstoptimer = 2000;

		/*
			 END IMMOLATE // ;
			 SHADOW BOLT //
		 */
		spells[8].info = dbcSpell.LookupEntry(686);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 10000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 5;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 20.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 1;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(695);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 10000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 11;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 6;
		spells[9].attackstoptimer = 2000;

		spells[10].info = dbcSpell.LookupEntry(705);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 10000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 19;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 20.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 12;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(1088);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 10000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 27;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 20.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 20;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(1106);
		spells[12].targettype = TARGET_ATTACKING;
		spells[12].instant = false;
		spells[12].cooldown = 10000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 35;
		spells[12].hpreqtocast = 100;
		spells[12].perctrigger = 20.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 28;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(7641);
		spells[13].targettype = TARGET_ATTACKING;
		spells[13].instant = false;
		spells[13].cooldown = 10000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 43;
		spells[13].hpreqtocast = 100;
		spells[13].perctrigger = 20.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 36;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(11659);
		spells[14].targettype = TARGET_ATTACKING;
		spells[14].instant = false;
		spells[14].cooldown = 10000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 51;
		spells[14].hpreqtocast = 100;
		spells[14].perctrigger = 20.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 44;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(11660);
		spells[15].targettype = TARGET_ATTACKING;
		spells[15].instant = false;
		spells[15].cooldown = 10000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 59;
		spells[15].hpreqtocast = 100;
		spells[15].perctrigger = 20.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 52;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(25307);
		spells[16].targettype = TARGET_ATTACKING;
		spells[16].instant = false;
		spells[16].cooldown = 10000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 67;
		spells[16].hpreqtocast = 100;
		spells[16].perctrigger = 20.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 60;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(27209);
		spells[17].targettype = TARGET_ATTACKING;
		spells[17].instant = false;
		spells[17].cooldown = 10000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 0;
		spells[17].hpreqtocast = 100;
		spells[17].perctrigger = 20.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 68;
		spells[17].attackstoptimer = 2000;

		/* END SHADOW BOLT // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidWarriorFury :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidWarriorFury);
	SP_AI_Spell spells[7];

	HumanoidWarriorFury(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 7;

		/* BERSERKER STANCE // */
		spells[0].info = dbcSpell.LookupEntry(2458);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 30;
		spells[0].attackstoptimer = 2000;

		/*
			 END BERSERKER // ;
			 SLAM //
		 */
		spells[1].info = dbcSpell.LookupEntry(1464);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].rangecheck = true;
		spells[1].cooldown = 12000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 37;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 30;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(8820);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].rangecheck = true;
		spells[2].cooldown = 12000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 45;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 38;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(11604);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].rangecheck = true;
		spells[3].cooldown = 12000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 53;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 46;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(11605);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].rangecheck = true;
		spells[4].cooldown = 12000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 60;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 54;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(25241);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].rangecheck = true;
		spells[5].cooldown = 12000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 68;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 61;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(25242);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].rangecheck = true;
		spells[6].cooldown = 12000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 0;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 15.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 69;
		spells[6].attackstoptimer = 2000;

		/* END SLAM // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidWarriorArms :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidWarriorArms);
	SP_AI_Spell spells[4];

	HumanoidWarriorArms(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 4;

		/* HAMSTRING // */
		spells[0].info = dbcSpell.LookupEntry(1715);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 20000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 31;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 8;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(7372);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 20000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 53;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 32;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(7373);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].rangecheck = true;
		spells[2].cooldown = 20000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 66;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 54;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(25212);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].rangecheck = true;
		spells[3].cooldown = 20000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 0;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 67;
		spells[3].attackstoptimer = 2000;

		/* END HAMSTRING // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidWarriorProtection :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidWarriorProtection);
	SP_AI_Spell spells[9];

	HumanoidWarriorProtection(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 9;

		/* DEFENSIVE STANCE // */
		spells[0].info = dbcSpell.LookupEntry(71);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		/*
			 END DEFENSIVE STANCE // ;
			 SHIELD SLAM //
		 */
		spells[1].info = dbcSpell.LookupEntry(8242);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 12000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 0;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 10;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(15655);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].rangecheck = true;
		spells[2].cooldown = 12000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 0;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 30;
		spells[2].attackstoptimer = 2000;

		/*
			 END SHIELD SLAM // ;
			 SUNDER ARMOR //
		 */
		spells[3].info = dbcSpell.LookupEntry(7386);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].rangecheck = true;
		spells[3].cooldown = 5000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 21;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 40.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 10;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(7405);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].rangecheck = true;
		spells[4].cooldown = 5000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 33;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 40.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 22;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(8380);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].rangecheck = true;
		spells[5].cooldown = 5000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 45;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 40.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 34;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(11596);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].rangecheck = true;
		spells[6].cooldown = 5000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 57;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 40.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 46;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(11597);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].rangecheck = true;
		spells[7].cooldown = 5000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 66;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 40.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 58;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(25225);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].rangecheck = true;
		spells[8].cooldown = 5000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 40.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 67;
		spells[8].attackstoptimer = 2000;

		/* END SUNDER ARMOR // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidWarriorBerserker :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidWarriorBerserker);
	SP_AI_Spell spells[1];

	HumanoidWarriorBerserker(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* ENRAGE // */
		spells[0].info = dbcSpell.LookupEntry(41305);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 20;
		spells[0].perctrigger = 50.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 20;
		spells[0].attackstoptimer = 2000;

		/* END ENRAGE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 2000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class HumanoidDruidRestoration :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HumanoidDruidRestoration);
	SP_AI_Spell spells[23];

	HumanoidDruidRestoration(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 23;

		/* WRATH // */
		spells[0].info = dbcSpell.LookupEntry(5176);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 5;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(5177);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 6;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(5178);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 21;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 20.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(5179);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 29;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 20.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 22;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(5180);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 37;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 20.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 30;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(6780);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 8000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 45;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 20.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 38;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(8905);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 8000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 53;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 20.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 46;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(9912);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 8000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 60;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 20.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 54;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(26984);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 8000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 68;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 20.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 61;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(26985);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 8000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 20.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 69;
		spells[9].attackstoptimer = 2000;

		/*
			 END WRATH // ;
			 HEALING TOUCH //
		 */
		spells[10].info = dbcSpell.LookupEntry(5185);
		spells[10].targettype = TARGET_VARIOUS;
		spells[10].instant = false;
		spells[10].cooldown = 20000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 7;
		spells[10].hpreqtocast = 40;
		spells[10].perctrigger = 20.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 1;
		spells[10].attackstoptimer = 2000;

		spells[11].info = dbcSpell.LookupEntry(5186);
		spells[11].targettype = TARGET_VARIOUS;
		spells[11].instant = false;
		spells[11].cooldown = 20000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 13;
		spells[11].hpreqtocast = 40;
		spells[11].perctrigger = 20.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 8;
		spells[11].attackstoptimer = 2000;

		spells[12].info = dbcSpell.LookupEntry(5187);
		spells[12].targettype = TARGET_VARIOUS;
		spells[12].instant = false;
		spells[12].cooldown = 20000;
		spells[12].cooldown2 = 0;
		spells[12].maxlvl = 19;
		spells[12].hpreqtocast = 40;
		spells[12].perctrigger = 20.0f;
		spells[12].proctimes = 0;
		spells[12].proctimes2 = 0;
		spells[12].reqlvl = 14;
		spells[12].attackstoptimer = 2000;

		spells[13].info = dbcSpell.LookupEntry(5188);
		spells[13].targettype = TARGET_VARIOUS;
		spells[13].instant = false;
		spells[13].cooldown = 20000;
		spells[13].cooldown2 = 0;
		spells[13].maxlvl = 25;
		spells[13].hpreqtocast = 40;
		spells[13].perctrigger = 20.0f;
		spells[13].proctimes = 0;
		spells[13].proctimes2 = 0;
		spells[13].reqlvl = 20;
		spells[13].attackstoptimer = 2000;

		spells[14].info = dbcSpell.LookupEntry(5189);
		spells[14].targettype = TARGET_VARIOUS;
		spells[14].instant = false;
		spells[14].cooldown = 20000;
		spells[14].cooldown2 = 0;
		spells[14].maxlvl = 31;
		spells[14].hpreqtocast = 40;
		spells[14].perctrigger = 20.0f;
		spells[14].proctimes = 0;
		spells[14].proctimes2 = 0;
		spells[14].reqlvl = 26;
		spells[14].attackstoptimer = 2000;

		spells[15].info = dbcSpell.LookupEntry(6778);
		spells[15].targettype = TARGET_VARIOUS;
		spells[15].instant = false;
		spells[15].cooldown = 20000;
		spells[15].cooldown2 = 0;
		spells[15].maxlvl = 37;
		spells[15].hpreqtocast = 40;
		spells[15].perctrigger = 20.0f;
		spells[15].proctimes = 0;
		spells[15].proctimes2 = 0;
		spells[15].reqlvl = 32;
		spells[15].attackstoptimer = 2000;

		spells[16].info = dbcSpell.LookupEntry(8903);
		spells[16].targettype = TARGET_VARIOUS;
		spells[16].instant = false;
		spells[16].cooldown = 20000;
		spells[16].cooldown2 = 0;
		spells[16].maxlvl = 43;
		spells[16].hpreqtocast = 40;
		spells[16].perctrigger = 20.0f;
		spells[16].proctimes = 0;
		spells[16].proctimes2 = 0;
		spells[16].reqlvl = 38;
		spells[16].attackstoptimer = 2000;

		spells[17].info = dbcSpell.LookupEntry(9758);
		spells[17].targettype = TARGET_VARIOUS;
		spells[17].instant = false;
		spells[17].cooldown = 20000;
		spells[17].cooldown2 = 0;
		spells[17].maxlvl = 49;
		spells[17].hpreqtocast = 40;
		spells[17].perctrigger = 20.0f;
		spells[17].proctimes = 0;
		spells[17].proctimes2 = 0;
		spells[17].reqlvl = 44;
		spells[17].attackstoptimer = 2000;

		spells[18].info = dbcSpell.LookupEntry(9888);
		spells[18].targettype = TARGET_VARIOUS;
		spells[18].instant = false;
		spells[18].cooldown = 20000;
		spells[18].cooldown2 = 0;
		spells[18].maxlvl = 55;
		spells[18].hpreqtocast = 40;
		spells[18].perctrigger = 20.0f;
		spells[18].proctimes = 0;
		spells[18].proctimes2 = 0;
		spells[18].reqlvl = 50;
		spells[18].attackstoptimer = 2000;

		spells[19].info = dbcSpell.LookupEntry(9889);
		spells[19].targettype = TARGET_VARIOUS;
		spells[19].instant = false;
		spells[19].cooldown = 20000;
		spells[19].cooldown2 = 0;
		spells[19].maxlvl = 59;
		spells[19].hpreqtocast = 40;
		spells[19].perctrigger = 20.0f;
		spells[19].proctimes = 0;
		spells[19].proctimes2 = 0;
		spells[19].reqlvl = 56;
		spells[19].attackstoptimer = 2000;

		spells[20].info = dbcSpell.LookupEntry(25297);
		spells[20].targettype = TARGET_VARIOUS;
		spells[20].instant = false;
		spells[20].cooldown = 20000;
		spells[20].cooldown2 = 0;
		spells[20].maxlvl = 63;
		spells[20].hpreqtocast = 40;
		spells[20].perctrigger = 20.0f;
		spells[20].proctimes = 0;
		spells[20].proctimes2 = 0;
		spells[20].reqlvl = 60;
		spells[20].attackstoptimer = 2000;

		spells[21].info = dbcSpell.LookupEntry(26978);
		spells[21].targettype = TARGET_VARIOUS;
		spells[21].instant = false;
		spells[21].cooldown = 20000;
		spells[21].cooldown2 = 0;
		spells[21].maxlvl = 68;
		spells[21].hpreqtocast = 40;
		spells[21].perctrigger = 20.0f;
		spells[21].proctimes = 0;
		spells[21].proctimes2 = 0;
		spells[21].reqlvl = 64;
		spells[21].attackstoptimer = 2000;

		spells[22].info = dbcSpell.LookupEntry(26979);
		spells[22].targettype = TARGET_VARIOUS;
		spells[22].instant = false;
		spells[22].cooldown = 20000;
		spells[22].cooldown2 = 0;
		spells[22].maxlvl = 0;
		spells[22].hpreqtocast = 40;
		spells[22].perctrigger = 20.0f;
		spells[22].proctimes = 0;
		spells[22].proctimes2 = 0;
		spells[22].reqlvl = 69;
		spells[22].attackstoptimer = 2000;

		/* END HEALING TOUCH // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 1000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		SpellCast();
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

/*
 =======================================================================================================================
		Undead types: use humanoid ;
		Dragonkin types:
 =======================================================================================================================
 */
class DragonkinWhelp :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(DragonkinWhelp);
	SP_AI_Spell spells[7];

	DragonkinWhelp(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 7;

		/* FIRE ATTACK // */
		spells[0].info = dbcSpell.LookupEntry(3606);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 19;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 50.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 10;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(6350);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 29;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 50.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 20;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(6351);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 39;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 50.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 30;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(6352);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 49;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 50.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 40;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(10435);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 59;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 50.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 50;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(10436);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 68;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 50.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 60;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(25530);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 0;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 50.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 69;
		spells[6].attackstoptimer = 2000;

		/* END FIRE ATTACK // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class DragonkinGeneral :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(DragonkinGeneral);
	SP_AI_Spell spells[6];

	DragonkinGeneral(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 6;

		/* FIRE SHIELD // */
		spells[0].info = dbcSpell.LookupEntry(2947);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 23;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 3.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 14;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(8316);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].cooldown = 4000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 33;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 3.0f;
		spells[1].proctimes = 1;
		spells[1].proctimes2 = 1;
		spells[1].reqlvl = 24;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(8317);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = true;
		spells[2].cooldown = 4000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 43;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 3.0f;
		spells[2].proctimes = 1;
		spells[2].proctimes2 = 1;
		spells[2].reqlvl = 34;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(11770);
		spells[3].targettype = TARGET_SELF;
		spells[3].instant = true;
		spells[3].cooldown = 4000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 53;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 3.0f;
		spells[3].proctimes = 1;
		spells[3].proctimes2 = 1;
		spells[3].reqlvl = 44;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(11771);
		spells[4].targettype = TARGET_SELF;
		spells[4].instant = true;
		spells[4].cooldown = 4000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 63;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 3.0f;
		spells[4].proctimes = 1;
		spells[4].proctimes2 = 1;
		spells[4].reqlvl = 54;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(27269);
		spells[5].targettype = TARGET_SELF;
		spells[5].instant = true;
		spells[5].cooldown = 4000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 0;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 3.0f;
		spells[5].proctimes = 1;
		spells[5].proctimes2 = 1;
		spells[5].reqlvl = 64;
		spells[5].attackstoptimer = 2000;

		/* END FIRE SHIELD // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class DragonkinWarrior :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(DragonkinWarrior);
	SP_AI_Spell spells[2];

	DragonkinWarrior(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 2;

		/* SHIELD SLAM // */
		spells[0].info = dbcSpell.LookupEntry(8242);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 12000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 29;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 10;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(15655);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 12000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 0;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 30;
		spells[1].attackstoptimer = 2000;

		/* END SHIELD SLAM // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class DragonkinMage :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(DragonkinMage);
	SP_AI_Spell spells[9];

	DragonkinMage(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 9;

		/* FIRE BLAST // */
		spells[0].info = dbcSpell.LookupEntry(2136);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 12000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 13;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 6;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(2137);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 12000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 21;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 10.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 14;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(2138);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 12000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 29;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 10.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 22;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(8412);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 12000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 37;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 10.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 30;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(8413);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 12000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 45;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 10.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 38;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(10197);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 12000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 53;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 10.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 46;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(10199);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 12000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 61;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 10.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 54;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(27078);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 12000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 69;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 10.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 62;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(27079);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 12000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 0;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 10.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 70;
		spells[8].attackstoptimer = 2000;

		/* END FIRE BLAST // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class DragonkinDrake :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(DragonkinDrake);
	SP_AI_Spell spells[1];

	DragonkinDrake(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* FLAME BREATH */
		spells[0].info = dbcSpell.LookupEntry(20712);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 16000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 50;
		spells[0].attackstoptimer = 2000;

		/* END FLAME BREATH // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

/*
 =======================================================================================================================
		Mechanical types:
 =======================================================================================================================
 */
class MechanicalGuard :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(MechanicalGuard);
	SP_AI_Spell spells[1];

	MechanicalGuard(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* STOMP // */
		spells[0].info = dbcSpell.LookupEntry(12612);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 20000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 10.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 20;
		spells[0].attackstoptimer = 2000;

		/* END STOMP // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class MechanicalGun :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(MechanicalGun);
	SP_AI_Spell spells[1];

	MechanicalGun(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* CANNON BLAST // */
		spells[0].info = dbcSpell.LookupEntry(36238);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 3000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2500;

		/* END CANNON BLAST // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 2000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class MechanicalMedium :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(MechanicalMedium);
	SP_AI_Spell spells[1];

	MechanicalMedium(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* MAGIC RESISTANCE // */
		spells[0].info = dbcSpell.LookupEntry(29718);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 4000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].hpreqtocast = 40;
		spells[0].perctrigger = 50.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 30;
		spells[0].attackstoptimer = 2000;

		/* END MAGIC RESISTANCE // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 5000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

/*
 =======================================================================================================================
		Giant types:
 =======================================================================================================================
 */
class GiantMolten :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(GiantMolten);
	SP_AI_Spell spells[1];

	GiantMolten(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* FIRE ABSORB // */
		spells[0].info = dbcSpell.LookupEntry(28511);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 50.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 1000;

		/* END FIRE ABSORB // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 3000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class GiantStone :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(GiantStone);
	SP_AI_Spell spells[2];

	GiantStone(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 2;

		/* ARMOR BUFFS & DEBUFFS // */
		spells[0].info = dbcSpell.LookupEntry(34199);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 10000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 50.0f;
		spells[0].hpreqtocast = 30;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 30;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(16928);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 0;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 20.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 0;
		spells[1].attackstoptimer = 1000;

		/* END ARMOR // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class GiantWater :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(GiantWater);
	SP_AI_Spell spells[5];

	GiantWater(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 5;

		/* FROST NOVA // */
		spells[0].info = dbcSpell.LookupEntry(122);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 25000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 25;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 5.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 10;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(865);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 25000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 39;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 5.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 26;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(6131);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].rangecheck = true;
		spells[2].cooldown = 25000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 53;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 5.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 40;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(10230);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].rangecheck = true;
		spells[3].cooldown = 25000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 66;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 5.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 54;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(27088);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].rangecheck = true;
		spells[4].cooldown = 25000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 0;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 5.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 67;
		spells[4].attackstoptimer = 2000;

		/* END FROST NOVA // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class GiantBeast :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(GiantBeast);
	SP_AI_Spell spells[10];

	GiantBeast(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 10;

		/* CLAW // */
		spells[0].info = dbcSpell.LookupEntry(16827);
		spells[0].rangecheck = true;
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].cooldown = 6000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 1;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 1.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(16827);
		spells[1].rangecheck = true;
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].cooldown = 6000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 7;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 50.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 1;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(16828);
		spells[2].rangecheck = true;
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].cooldown = 6000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 15;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 50.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 8;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(16829);
		spells[3].rangecheck = true;
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 6000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 23;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 50.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 16;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(16830);
		spells[4].rangecheck = true;
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].cooldown = 6000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 50.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 24;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(16831);
		spells[5].rangecheck = true;
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].cooldown = 6000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 39;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 50.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 2000;

		spells[6].info = dbcSpell.LookupEntry(16832);
		spells[6].rangecheck = true;
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = true;
		spells[6].cooldown = 6000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 47;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 50.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 40;
		spells[6].attackstoptimer = 2000;

		spells[7].info = dbcSpell.LookupEntry(3010);
		spells[7].rangecheck = true;
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = true;
		spells[7].cooldown = 6000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 55;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 50.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 48;
		spells[7].attackstoptimer = 2000;

		spells[8].info = dbcSpell.LookupEntry(3009);
		spells[8].rangecheck = true;
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = true;
		spells[8].cooldown = 6000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 63;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 50.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 56;
		spells[8].attackstoptimer = 2000;

		spells[9].info = dbcSpell.LookupEntry(27049);
		spells[9].rangecheck = true;
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = true;
		spells[9].cooldown = 6000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 0;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 50.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 64;
		spells[9].attackstoptimer = 2000;

		/* END CLAW // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 6000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class GiantFungal :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(GiantFungal);
	SP_AI_Spell spells[1];

	GiantFungal(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* POISON // */
		spells[0].info = dbcSpell.LookupEntry(38208);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 10000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 20.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		/* END POISON // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

/*
 =======================================================================================================================
		Murloc types - use humanoid ;
		Special types: ;
		ThunderLizard Poisoner Ooze Stormer (centaur & others)
 =======================================================================================================================
 */
class MiscThunderLizard :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(MiscThunderLizard);
	SP_AI_Spell spells[12];

	MiscThunderLizard(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 12;

		/* LIGHTNING BOLT // */
		spells[0].info = dbcSpell.LookupEntry(403);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 2000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(529);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 2000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 100.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(548);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 3000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 19;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 100.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 1000;

		spells[3].info = dbcSpell.LookupEntry(915);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 3000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 25;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 100.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 20;
		spells[3].attackstoptimer = 1000;

		spells[4].info = dbcSpell.LookupEntry(943);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 3000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 100.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 26;
		spells[4].attackstoptimer = 1000;

		spells[5].info = dbcSpell.LookupEntry(6041);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 3000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 37;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 100.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 1000;

		spells[6].info = dbcSpell.LookupEntry(10391);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 3000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 43;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 100.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 38;
		spells[6].attackstoptimer = 1000;

		spells[7].info = dbcSpell.LookupEntry(10392);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 3000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 49;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 100.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 44;
		spells[7].attackstoptimer = 1000;

		spells[8].info = dbcSpell.LookupEntry(15207);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 3000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 55;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 100.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 50;
		spells[8].attackstoptimer = 1000;

		spells[9].info = dbcSpell.LookupEntry(15208);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 3000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 61;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 100.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 56;
		spells[9].attackstoptimer = 1000;

		spells[10].info = dbcSpell.LookupEntry(25448);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 3000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 66;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 100.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 62;
		spells[10].attackstoptimer = 1000;

		spells[11].info = dbcSpell.LookupEntry(25449);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 3000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 0;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 100.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 67;
		spells[11].attackstoptimer = 1000;

		/* END LIGHTNING BOLT // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 0;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 1500;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class MiscPoisoner :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(MiscPoisoner);
	SP_AI_Spell spells[6];

	MiscPoisoner(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 6;

		/* ROGUE'S DEADLY POISON // */
		spells[0].info = dbcSpell.LookupEntry(2818);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 8000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 29;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 20;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(2819);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].rangecheck = true;
		spells[1].cooldown = 8000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 39;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 15.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 30;
		spells[1].attackstoptimer = 2000;

		spells[2].info = dbcSpell.LookupEntry(11353);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].rangecheck = true;
		spells[2].cooldown = 8000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 49;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 15.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 40;
		spells[2].attackstoptimer = 2000;

		spells[3].info = dbcSpell.LookupEntry(11354);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].rangecheck = true;
		spells[3].cooldown = 8000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 59;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 15.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 50;
		spells[3].attackstoptimer = 2000;

		spells[4].info = dbcSpell.LookupEntry(25349);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].rangecheck = true;
		spells[4].cooldown = 8000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 69;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 15.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 60;
		spells[4].attackstoptimer = 2000;

		spells[5].info = dbcSpell.LookupEntry(26968);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].rangecheck = true;
		spells[5].cooldown = 8000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 0;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 15.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 70;
		spells[5].attackstoptimer = 2000;

		/* END ROGUE'S DEADLY POISON // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 4000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class MiscOoze :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(MiscOoze);
	SP_AI_Spell spells[1];

	MiscOoze(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* REDUCE ARMOR BY 15% // */
		spells[0].info = dbcSpell.LookupEntry(36836);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].rangecheck = true;
		spells[0].cooldown = 20000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 15.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 2000;

		/* END REDUCE ARMOR // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 3000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class MiscStormer :
	public CreatureAIScript /* SAME AS LIZARD BUT GCD = 8000 */
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(MiscStormer);
	SP_AI_Spell spells[12];

	MiscStormer(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 12;

		/* LIGHTNING BOLT // */
		spells[0].info = dbcSpell.LookupEntry(403);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 2000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 7;
		spells[0].hpreqtocast = 100;
		spells[0].perctrigger = 100.0f;
		spells[0].proctimes = 0;
		spells[0].proctimes2 = 0;
		spells[0].reqlvl = 1;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(529);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].cooldown = 2000;
		spells[1].cooldown2 = 0;
		spells[1].maxlvl = 13;
		spells[1].hpreqtocast = 100;
		spells[1].perctrigger = 100.0f;
		spells[1].proctimes = 0;
		spells[1].proctimes2 = 0;
		spells[1].reqlvl = 8;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(548);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].cooldown = 3000;
		spells[2].cooldown2 = 0;
		spells[2].maxlvl = 19;
		spells[2].hpreqtocast = 100;
		spells[2].perctrigger = 100.0f;
		spells[2].proctimes = 0;
		spells[2].proctimes2 = 0;
		spells[2].reqlvl = 14;
		spells[2].attackstoptimer = 1000;

		spells[3].info = dbcSpell.LookupEntry(915);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = false;
		spells[3].cooldown = 3000;
		spells[3].cooldown2 = 0;
		spells[3].maxlvl = 25;
		spells[3].hpreqtocast = 100;
		spells[3].perctrigger = 100.0f;
		spells[3].proctimes = 0;
		spells[3].proctimes2 = 0;
		spells[3].reqlvl = 20;
		spells[3].attackstoptimer = 1000;

		spells[4].info = dbcSpell.LookupEntry(943);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = false;
		spells[4].cooldown = 3000;
		spells[4].cooldown2 = 0;
		spells[4].maxlvl = 31;
		spells[4].hpreqtocast = 100;
		spells[4].perctrigger = 100.0f;
		spells[4].proctimes = 0;
		spells[4].proctimes2 = 0;
		spells[4].reqlvl = 26;
		spells[4].attackstoptimer = 1000;

		spells[5].info = dbcSpell.LookupEntry(6041);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = false;
		spells[5].cooldown = 3000;
		spells[5].cooldown2 = 0;
		spells[5].maxlvl = 37;
		spells[5].hpreqtocast = 100;
		spells[5].perctrigger = 100.0f;
		spells[5].proctimes = 0;
		spells[5].proctimes2 = 0;
		spells[5].reqlvl = 32;
		spells[5].attackstoptimer = 1000;

		spells[6].info = dbcSpell.LookupEntry(10391);
		spells[6].targettype = TARGET_ATTACKING;
		spells[6].instant = false;
		spells[6].cooldown = 3000;
		spells[6].cooldown2 = 0;
		spells[6].maxlvl = 43;
		spells[6].hpreqtocast = 100;
		spells[6].perctrigger = 100.0f;
		spells[6].proctimes = 0;
		spells[6].proctimes2 = 0;
		spells[6].reqlvl = 38;
		spells[6].attackstoptimer = 1000;

		spells[7].info = dbcSpell.LookupEntry(10392);
		spells[7].targettype = TARGET_ATTACKING;
		spells[7].instant = false;
		spells[7].cooldown = 3000;
		spells[7].cooldown2 = 0;
		spells[7].maxlvl = 49;
		spells[7].hpreqtocast = 100;
		spells[7].perctrigger = 100.0f;
		spells[7].proctimes = 0;
		spells[7].proctimes2 = 0;
		spells[7].reqlvl = 44;
		spells[7].attackstoptimer = 1000;

		spells[8].info = dbcSpell.LookupEntry(15207);
		spells[8].targettype = TARGET_ATTACKING;
		spells[8].instant = false;
		spells[8].cooldown = 3000;
		spells[8].cooldown2 = 0;
		spells[8].maxlvl = 55;
		spells[8].hpreqtocast = 100;
		spells[8].perctrigger = 100.0f;
		spells[8].proctimes = 0;
		spells[8].proctimes2 = 0;
		spells[8].reqlvl = 50;
		spells[8].attackstoptimer = 1000;

		spells[9].info = dbcSpell.LookupEntry(15208);
		spells[9].targettype = TARGET_ATTACKING;
		spells[9].instant = false;
		spells[9].cooldown = 3000;
		spells[9].cooldown2 = 0;
		spells[9].maxlvl = 61;
		spells[9].hpreqtocast = 100;
		spells[9].perctrigger = 100.0f;
		spells[9].proctimes = 0;
		spells[9].proctimes2 = 0;
		spells[9].reqlvl = 56;
		spells[9].attackstoptimer = 1000;

		spells[10].info = dbcSpell.LookupEntry(25448);
		spells[10].targettype = TARGET_ATTACKING;
		spells[10].instant = false;
		spells[10].cooldown = 3000;
		spells[10].cooldown2 = 0;
		spells[10].maxlvl = 66;
		spells[10].hpreqtocast = 100;
		spells[10].perctrigger = 100.0f;
		spells[10].proctimes = 0;
		spells[10].proctimes2 = 0;
		spells[10].reqlvl = 62;
		spells[10].attackstoptimer = 1000;

		spells[11].info = dbcSpell.LookupEntry(25449);
		spells[11].targettype = TARGET_ATTACKING;
		spells[11].instant = false;
		spells[11].cooldown = 3000;
		spells[11].cooldown2 = 0;
		spells[11].maxlvl = 0;
		spells[11].hpreqtocast = 100;
		spells[11].perctrigger = 100.0f;
		spells[11].proctimes = 0;
		spells[11].proctimes2 = 0;
		spells[11].reqlvl = 67;
		spells[11].attackstoptimer = 1000;

		/* END LIGHTNING BOLT // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 8000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

class MiscShield :
	public CreatureAIScript /* SAME AS LIZARD BUT GCD = 8000 */
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(MiscShield);
	SP_AI_Spell spells[12];

	MiscShield(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 1;

		/* REDUCE DAMAGE A LOT // */
		spells[0].info = dbcSpell.LookupEntry(36513);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 2000;
		spells[0].cooldown2 = 0;
		spells[0].maxlvl = 0;
		spells[0].hpreqtocast = 30;
		spells[0].perctrigger = 40.0f;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 1;
		spells[0].reqlvl = 0;
		spells[0].attackstoptimer = 1000;

		/* REDUCE DAMAGE A LOT // */
	}

	void OnCombatStart(Unit *mTarget)
	{
		gcd = 0;
		waittime = 4000;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].cooldown2 = 0;
			spells[i].proctimes2 = spells[i].proctimes;
		}

		waittime = 0;
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	atime = _unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(gcd > atime)
			gcd -= atime;
		else
			gcd = 0;
		for(int i = 0; i < nrspells; i++)
		{
			if(spells[i].cooldown2 > atime)
				spells[i].cooldown2 -= atime;
			else
				spells[i].cooldown2 = 0;
			if(waittime > atime)
				waittime -= atime;
			else
				waittime = 0;
		}

		SpellCast();
	}

	void SpellCast()
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Unit	*target = NULL;
			Unit	*targetally = NULL;
			uint32	unitlevel = _unit->GetUInt32Value(UNIT_FIELD_LEVEL);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(_unit->GetCreatureInfo() && _unit->GetCreatureInfo()->Rank > 0) unitlevel += 8;	/* elites cast higher
																								 * level spells */
			for(int i = 0; i < nrspells; i++)
			{
				if(gcd) return;
				didcast = 0;

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				float	val = ( float ) RandomFloat(100.0f);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					(val <= spells[i].perctrigger)
				&&	(!waittime)
				&&	(!spells[i].cooldown2)
				&&	(!spells[i].reqlvl || spells[i].reqlvl <= unitlevel)
				&&	(!spells[i].maxlvl || spells[i].maxlvl >= unitlevel)
				&&	(!spells[i].proctimes || spells[i].proctimes2)
				&&	(
						spells[i].distancecheck != true
					||	(
							spells[i].distancecheck == true
						&&	spells[i].targettype == TARGET_ATTACKING
						&&	_unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) >= 10.0f
						)
					)
				&&	(
						spells[i].rangecheck != true
					||	(spells[i].rangecheck == true && spells[i].targettype == TARGET_ATTACKING && _unit->CalcDistance(_unit->GetAIInterface()->GetNextTarget()) <= 8.0f)
					)
				)
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_VARIOUS:
						targetally = GetRandomAlly(_unit, spells[i].hpreqtocast);
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast)
						{
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						else if
							(
								targetally
							&&	targetally->GetHealthPct() <= spells[i].hpreqtocast
							&&	_unit->CalcDistance(targetally) <= 30.0f
							)
						{
							_unit->CastSpell(targetally, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_ATTACKING:
						if(_unit->GetHealthPct() <= spells[i].hpreqtocast && _unit->CalcDistance(target) <= 30.0f)
						{
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							didcast = 1;
						}
						break;

					case TARGET_DESTINATION:
						_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						break;
					}

					if(didcast == 1)
					{
						if(spells[i].proctimes2 > 0) spells[i].proctimes2--;
						spells[i].cooldown2 = spells[i].cooldown;
						gcd = 8000;
						return;
					}
				}
			}
		}
	}

protected:
	int		nrspells;
	uint32	gcd;
	uint32	waittime;
	bool	didcast;
};

void SetupGeneric(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~*/
	uint32	spider = 1;
	uint32	wolf = 1;
	uint32	wserpent = 1;
	uint32	wstalker = 1;
	uint32	turtle = 1;
	uint32	tallstrider = 1;
	uint32	serpent = 1;
	uint32	scorpion = 1;
	uint32	bat = 1;
	uint32	bear = 1;
	uint32	boar = 1;
	uint32	cbird = 1;
	uint32	cat = 1;
	uint32	crab = 1;
	uint32	croc = 1;
	uint32	dhawk = 1;
	uint32	gorilla = 1;
	uint32	hyena = 1;
	uint32	nray = 1;
	uint32	owl = 1;
	uint32	raptor = 1;
	uint32	fhunter = 1;
	uint32	imp = 1;
	/*~~~~~~~~~~~~~~~~~~~~*/

	if(tallstrider == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '12'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastTallStrider::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(imp == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '23'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &Imp::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(fhunter == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '15'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &Felhunter::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(raptor == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '11'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastRaptor::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(owl == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '26'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastOwl::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(nray == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '34'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastNetherRay::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(hyena == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '25'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastHyena::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(gorilla == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '9'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastGorilla::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(dhawk == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '30'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastDragonhawk::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(croc == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '6'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastCrocolisk::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(crab == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '8'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastCrab::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(cat == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '2'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastCat::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(cbird == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '7'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastCarrionBird::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(boar == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '5'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastBoar::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(bear == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '4'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastBear::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(bat == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '24'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastBat::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(scorpion == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '20'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastScorpion::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(serpent == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '35'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastSerpent::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(spider == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '3'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastSpider::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(turtle == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '21'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastTurtle::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(wstalker == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '32'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastWarpStalker::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(wolf == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '1'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastWolf::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	if(wserpent == 1)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/
		std::stringstream	my_sql;
		QueryResult			*result;
		/*~~~~~~~~~~~~~~~~~~~~~~~~*/

		my_sql << "SELECT * FROM creature_names where family = '27'";
		result = WorldDatabase.Query(my_sql.str().c_str());

		/*~~~~~~~~~~~*/
		uint32	Id = 0;
		/*~~~~~~~~~~~*/

		if(result)
		{
			do
			{
				Id = result->Fetch()[0].GetUInt32();
				mgr->register_creature_script(Id, &BeastWindSerpent::Create);
			} while(result->NextRow());
			WorldDatabase.FreeQueryResult( result );
		}
	}

	mgr->register_creature_script(38, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(48, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(61, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(92, &ElementalEarth::Create);
	mgr->register_creature_script(94, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(97, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(99, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(100, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(103, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(116, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(121, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(127, &HumanoidHunter::Create);
	mgr->register_creature_script(171, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(203, &HumanoidMageFrost::Create);
	mgr->register_creature_script(300, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(314, &MiscPoisoner::Create);
	mgr->register_creature_script(315, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(327, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(334, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(335, &DragonkinWhelp::Create);
	mgr->register_creature_script(397, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(426, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(429, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(430, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(431, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(436, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(437, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(440, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(441, &DragonkinWhelp::Create);
	mgr->register_creature_script(446, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(448, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(453, &HumanoidDruidRestoration::Create);
	mgr->register_creature_script(456, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(458, &HumanoidHunter::Create);
	mgr->register_creature_script(474, &HumanoidMageFrost::Create);
	mgr->register_creature_script(476, &HumanoidGeomancer::Create);
	mgr->register_creature_script(481, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(485, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(501, &HumanoidDruidRestoration::Create);
	mgr->register_creature_script(517, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(518, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(520, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(533, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(587, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(589, &HumanoidMageArcane::Create);
	mgr->register_creature_script(594, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(595, &HumanoidHunter::Create);
	mgr->register_creature_script(597, &HumanoidWarriorBerserker::Create);
	mgr->register_creature_script(599, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(619, &HumanoidMageArcane::Create);
	mgr->register_creature_script(660, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(667, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(669, &HumanoidHunter::Create);
	mgr->register_creature_script(670, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(672, &HumanoidPriestDiscipline::Create);
	mgr->register_creature_script(679, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(697, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(701, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(703, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(710, &HumanoidMageFrost::Create);
	mgr->register_creature_script(732, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(740, &DragonkinWhelp::Create);
	mgr->register_creature_script(741, &DragonkinWhelp::Create);
	mgr->register_creature_script(742, &DragonkinGeneral::Create);
	mgr->register_creature_script(743, &DragonkinGeneral::Create);
	mgr->register_creature_script(744, &DragonkinGeneral::Create);
	mgr->register_creature_script(745, &DragonkinGeneral::Create);
	mgr->register_creature_script(752, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(759, &HumanoidHunter::Create);
	mgr->register_creature_script(761, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(762, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(763, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(764, &ElementalLife::Create);
	mgr->register_creature_script(766, &ElementalLife::Create);
	mgr->register_creature_script(780, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(783, &HumanoidWarriorBerserker::Create);
	mgr->register_creature_script(787, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(819, &BeastHyena::Create);
	mgr->register_creature_script(891, &HumanoidMageFire::Create);
	mgr->register_creature_script(909, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(910, &HumanoidMageArcane::Create);
	mgr->register_creature_script(937, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(939, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(940, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(941, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(950, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(1009, &HumanoidDruidRestoration::Create);
	mgr->register_creature_script(1013, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(1030, &MiscOoze::Create);
	mgr->register_creature_script(1033, &MiscOoze::Create);
	mgr->register_creature_script(1036, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(1038, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(1043, &DragonkinWhelp::Create);
	mgr->register_creature_script(1044, &DragonkinWhelp::Create);
	mgr->register_creature_script(1052, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(1057, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(1060, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(1069, &DragonkinWhelp::Create);
	mgr->register_creature_script(1096, &HumanoidGeomancer::Create);
	mgr->register_creature_script(1116, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(1165, &HumanoidGeomancer::Create);
	mgr->register_creature_script(1166, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(1174, &HumanoidGeomancer::Create);
	mgr->register_creature_script(1181, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(1183, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(1197, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(1200, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(1251, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(1253, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(1364, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(1489, &HumanoidHunter::Create);
	mgr->register_creature_script(1490, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(1522, &HumanoidMageFrost::Create);
	mgr->register_creature_script(1535, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(1536, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(1538, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(1539, &HumanoidMageArcane::Create);
	mgr->register_creature_script(1544, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(1562, &HumanoidMageFire::Create);
	mgr->register_creature_script(1564, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(1653, &HumanoidMageFire::Create);
	mgr->register_creature_script(1660, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(1662, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(1664, &HumanoidPaladinProtection::Create);
	mgr->register_creature_script(1726, &HumanoidMageFire::Create);
	mgr->register_creature_script(1753, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(1782, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(1784, &HumanoidMageFrost::Create);
	mgr->register_creature_script(1789, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(1804, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(1826, &HumanoidMageFire::Create);
	mgr->register_creature_script(1831, &HumanoidHunter::Create);
	mgr->register_creature_script(1833, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(1834, &HumanoidPaladinHoly::Create);
	mgr->register_creature_script(1835, &HumanoidMageArcane::Create);
	mgr->register_creature_script(1838, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(1846, &HumanoidPaladinRetribution::Create);
	mgr->register_creature_script(1852, &HumanoidMageFrost::Create);
	mgr->register_creature_script(1867, &HumanoidMageFrost::Create);
	mgr->register_creature_script(1888, &HumanoidMageArcane::Create);
	mgr->register_creature_script(1889, &HumanoidMageFrost::Create);
	mgr->register_creature_script(1895, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(1913, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(1914, &HumanoidMageFrost::Create);
	mgr->register_creature_script(1915, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(1940, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(1947, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(2091, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(2120, &HumanoidMageArcane::Create);
	mgr->register_creature_script(2244, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(2255, &HumanoidMageFire::Create);
	mgr->register_creature_script(2257, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(2260, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(2268, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(2270, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(2304, &HumanoidPaladinProtection::Create);
	mgr->register_creature_script(2305, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(2318, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(2319, &HumanoidMageArcane::Create);
	mgr->register_creature_script(2335, &HumanoidMageFire::Create);
	mgr->register_creature_script(2344, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(2345, &HumanoidHunter::Create);
	mgr->register_creature_script(2346, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(2369, &HumanoidHunter::Create);
	mgr->register_creature_script(2370, &HumanoidMageFrost::Create);
	mgr->register_creature_script(2371, &HumanoidMageFrost::Create);
	mgr->register_creature_script(2376, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(2377, &HumanoidHunter::Create);
	mgr->register_creature_script(2387, &HumanoidMageArcane::Create);
	mgr->register_creature_script(2534, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(2550, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(2554, &HumanoidHunter::Create);
	mgr->register_creature_script(2555, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(2558, &HumanoidWarriorBerserker::Create);
	mgr->register_creature_script(2567, &HumanoidMageFrost::Create);
	mgr->register_creature_script(2570, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(2573, &HumanoidMageFrost::Create);
	mgr->register_creature_script(2584, &HumanoidPaladinProtection::Create);
	mgr->register_creature_script(2585, &HumanoidPaladinRetribution::Create);
	mgr->register_creature_script(2587, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(2589, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(2590, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(2591, &HumanoidMageFire::Create);
	mgr->register_creature_script(2592, &ElementalEarth::Create);
	mgr->register_creature_script(2597, &HumanoidPaladinRetribution::Create);
	mgr->register_creature_script(2598, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(2599, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(2607, &HumanoidPaladinHoly::Create);
	mgr->register_creature_script(2611, &GiantStone::Create);
	mgr->register_creature_script(2640, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(2642, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(2643, &HumanoidWarriorBerserker::Create);
	mgr->register_creature_script(2645, &HumanoidHunter::Create);
	mgr->register_creature_script(2646, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(2647, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(2648, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(2652, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(2655, &MiscOoze::Create);
	mgr->register_creature_script(2656, &MiscOoze::Create);
	mgr->register_creature_script(2692, &HumanoidHunter::Create);
	mgr->register_creature_script(2693, &HumanoidHunter::Create);
	mgr->register_creature_script(2718, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(2720, &HumanoidMageFrost::Create);
	mgr->register_creature_script(2723, &MechanicalGuard::Create);
	mgr->register_creature_script(2725, &DragonkinWhelp::Create);
	mgr->register_creature_script(2735, &ElementalEarth::Create);
	mgr->register_creature_script(2736, &ElementalEarth::Create);
	mgr->register_creature_script(2742, &HumanoidPriestDiscipline::Create);
	mgr->register_creature_script(2743, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(2745, &ElementalFire::Create);
	mgr->register_creature_script(2751, &MechanicalGuard::Create);
	mgr->register_creature_script(2754, &GiantStone::Create);
	mgr->register_creature_script(2760, &ElementalFire::Create);
	mgr->register_creature_script(2761, &ElementalWater::Create);
	mgr->register_creature_script(2762, &ElementalAir::Create);
	mgr->register_creature_script(2780, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(2781, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(2782, &HumanoidPriestDiscipline::Create);
	mgr->register_creature_script(2892, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(2894, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(2907, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(2919, &ElementalEarth::Create);
	mgr->register_creature_script(2944, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(4462, &HumanoidHunter::Create);
	mgr->register_creature_script(4463, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(4464, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(4467, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(4468, &MiscOoze::Create);
	mgr->register_creature_script(4481, &HumanoidPaladinProtection::Create);
	mgr->register_creature_script(4493, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(4494, &HumanoidMageFrost::Create);
	mgr->register_creature_script(5414, &MiscPoisoner::Create);
	mgr->register_creature_script(5418, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(5839, &HumanoidGeomancer::Create);
	mgr->register_creature_script(5850, &ElementalFire::Create);
	mgr->register_creature_script(5852, &ElementalFire::Create);
	mgr->register_creature_script(5853, &MechanicalGuard::Create);
	mgr->register_creature_script(5854, &MechanicalGuard::Create);
	mgr->register_creature_script(5855, &ElementalEarth::Create);
	mgr->register_creature_script(5860, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(5861, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(5862, &HumanoidGeomancer::Create);
	mgr->register_creature_script(5975, &HumanoidMageFire::Create);
	mgr->register_creature_script(5978, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(5993, &BeastBoar::Create);
	mgr->register_creature_script(6004, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(6005, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(6006, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(6008, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(6009, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(6011, &DoomGuard::Create);
	mgr->register_creature_script(6093, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(6123, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(6570, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(7025, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(7026, &HumanoidMageFire::Create);
	mgr->register_creature_script(7028, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(7029, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(7031, &ElementalEarth::Create);
	mgr->register_creature_script(7032, &ElementalEarth::Create);
	mgr->register_creature_script(7033, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(7034, &HumanoidMageFire::Create);
	mgr->register_creature_script(7036, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(7039, &MechanicalGuard::Create);
	mgr->register_creature_script(7040, &DragonkinGeneral::Create);
	mgr->register_creature_script(7041, &DragonkinMage::Create);
	mgr->register_creature_script(7042, &DragonkinGeneral::Create);
	mgr->register_creature_script(7043, &DragonkinMage::Create);
	mgr->register_creature_script(7044, &DragonkinDrake::Create);
	mgr->register_creature_script(7046, &DragonkinDrake::Create);
	mgr->register_creature_script(7047, &DragonkinWhelp::Create);
	mgr->register_creature_script(7049, &DragonkinWhelp::Create);
	mgr->register_creature_script(7053, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(7068, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(7069, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(7070, &HumanoidPriestDiscipline::Create);
	mgr->register_creature_script(7071, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(7072, &HumanoidPaladinProtection::Create);
	mgr->register_creature_script(7073, &HumanoidPaladinRetribution::Create);
	mgr->register_creature_script(7074, &HumanoidMageFire::Create);
	mgr->register_creature_script(7075, &HumanoidMageFrost::Create);
	mgr->register_creature_script(7372, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(7379, &HumanoidMageFire::Create);
	mgr->register_creature_script(7665, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(7669, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(7846, &DragonkinDrake::Create);
	mgr->register_creature_script(7871, &HumanoidHunter::Create);
	mgr->register_creature_script(7995, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(7996, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(8281, &ElementalFire::Create);
	mgr->register_creature_script(8296, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(8298, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(8439, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(8522, &ElementalWater::Create);
	mgr->register_creature_script(8526, &HumanoidMageFrost::Create);
	mgr->register_creature_script(8546, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(8550, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(8551, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(8561, &HumanoidHunter::Create);
	mgr->register_creature_script(8596, &BeastHyena::Create);
	mgr->register_creature_script(8597, &BeastHyena::Create);
	mgr->register_creature_script(8606, &MiscOoze::Create);
	mgr->register_creature_script(8607, &MiscOoze::Create);
	mgr->register_creature_script(8636, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(8675, &Felhunter::Create);
	mgr->register_creature_script(8717, &DoomGuard::Create);
	mgr->register_creature_script(8718, &Felhunter::Create);
	mgr->register_creature_script(8837, &ElementalWater::Create);
	mgr->register_creature_script(8976, &DragonkinDrake::Create);
	mgr->register_creature_script(8977, &HumanoidWarriorArms::Create);
	//mgr->register_creature_script(8996, &VoidwalkerMob::Create);
	mgr->register_creature_script(9448, &HumanoidPaladinProtection::Create);
	mgr->register_creature_script(9449, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(9450, &HumanoidPriestDiscipline::Create);
	mgr->register_creature_script(9451, &HumanoidMageFire::Create);
	mgr->register_creature_script(9452, &HumanoidMageArcane::Create);
	mgr->register_creature_script(9776, &Imp::Create);
	mgr->register_creature_script(9777, &Imp::Create);
	mgr->register_creature_script(9778, &Imp::Create);
	mgr->register_creature_script(9779, &Imp::Create);
	mgr->register_creature_script(10119, &GiantMolten::Create);
	mgr->register_creature_script(10580, &MiscPoisoner::Create);
	mgr->register_creature_script(10605, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(10608, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(10823, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(10928, &Succubus::Create);
	mgr->register_creature_script(10930, &HumanoidHunter::Create);
	mgr->register_creature_script(11290, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(11346, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(11355, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(11383, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(11611, &HumanoidPaladinProtection::Create);
	mgr->register_creature_script(11613, &HumanoidHunter::Create);
	mgr->register_creature_script(11878, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(12396, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(12496, &DragonkinDrake::Create);
	mgr->register_creature_script(14267, &HumanoidWarriorBerserker::Create);
	mgr->register_creature_script(17235, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(17613, &HumanoidMageArcane::Create);
	mgr->register_creature_script(2007, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(2203, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(2205, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(2206, &HumanoidHunter::Create);
	mgr->register_creature_script(2337, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(3113, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(3130, &MiscThunderLizard::Create);
	mgr->register_creature_script(3131, &MiscThunderLizard::Create);
	mgr->register_creature_script(3183, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(3198, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(3239, &MiscThunderLizard::Create);
	mgr->register_creature_script(3240, &MiscThunderLizard::Create);
	mgr->register_creature_script(3258, &HumanoidHunter::Create);
	mgr->register_creature_script(3260, &HumanoidMageFrost::Create);
	mgr->register_creature_script(3261, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(3263, &HumanoidGeomancer::Create);
	mgr->register_creature_script(3265, &HumanoidHunter::Create);
	mgr->register_creature_script(3267, &HumanoidMageFrost::Create);
	mgr->register_creature_script(3268, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(3269, &HumanoidGeomancer::Create);
	mgr->register_creature_script(3271, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(3375, &HumanoidGeomancer::Create);
	mgr->register_creature_script(3382, &HumanoidHunter::Create);
	mgr->register_creature_script(3385, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(3386, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(3438, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(3457, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(3458, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(3664, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(3715, &HumanoidMageFrost::Create);
	mgr->register_creature_script(3717, &HumanoidMageFrost::Create);
	mgr->register_creature_script(3725, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(3728, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(3743, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(3748, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(3750, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(3752, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(3757, &HumanoidMageFire::Create);
	mgr->register_creature_script(3759, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(3763, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(3770, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(3771, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(3772, &DoomGuard::Create);
	mgr->register_creature_script(3774, &Felhunter::Create);
	mgr->register_creature_script(3801, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(3922, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(3924, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(3928, &MiscOoze::Create);
	mgr->register_creature_script(3991, &HumanoidGeomancer::Create);
	mgr->register_creature_script(4021, &MiscOoze::Create);
	mgr->register_creature_script(4036, &ElementalFire::Create);
	mgr->register_creature_script(4051, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(4641, &HumanoidDruidRestoration::Create);
	mgr->register_creature_script(4642, &MiscStormer::Create);
	mgr->register_creature_script(4663, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(4726, &MiscThunderLizard::Create);
	mgr->register_creature_script(5236, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(5237, &HumanoidMageFire::Create);
	mgr->register_creature_script(5239, &HumanoidMageFire::Create);
	mgr->register_creature_script(5240, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(5254, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(5473, &HumanoidMageFire::Create);
	mgr->register_creature_script(5475, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(5615, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(5617, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(5623, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(5647, &HumanoidMageFire::Create);
	mgr->register_creature_script(5824, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(5899, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(6071, &Felhunter::Create);
	mgr->register_creature_script(6115, &DoomGuard::Create);
	mgr->register_creature_script(6127, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(6129, &HumanoidMageFire::Create);
	mgr->register_creature_script(6131, &HumanoidMageFire::Create);
	mgr->register_creature_script(6190, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(6193, &HumanoidMageFrost::Create);
	mgr->register_creature_script(6195, &HumanoidMageFrost::Create);
	mgr->register_creature_script(6198, &HumanoidMageFire::Create);
	mgr->register_creature_script(6199, &HumanoidPriestHoly::Create);
	mgr->register_creature_script(6375, &MiscStormer::Create);
	mgr->register_creature_script(7092, &MiscOoze::Create);
	mgr->register_creature_script(7100, &ElementalLife::Create);
	mgr->register_creature_script(7101, &ElementalLife::Create);
	mgr->register_creature_script(7106, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(7107, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(7110, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(7111, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(7112, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(7113, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(7115, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(7118, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(7120, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(7125, &Felhunter::Create);
	mgr->register_creature_script(7132, &ElementalWater::Create);
	mgr->register_creature_script(7153, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(7154, &HumanoidDruidRestoration::Create);
	mgr->register_creature_script(7158, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(7437, &HumanoidMageFire::Create);
	mgr->register_creature_script(7439, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(7441, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(7461, &Succubus::Create);
	mgr->register_creature_script(7462, &Felhunter::Create);
	mgr->register_creature_script(7463, &DoomGuard::Create);
	mgr->register_creature_script(7524, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(7726, &HumanoidDruidFeral::Create);
	mgr->register_creature_script(7727, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(8408, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(9454, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(9862, &DoomGuard::Create);
	mgr->register_creature_script(9878, &ElementalFire::Create);
	mgr->register_creature_script(9879, &ElementalFire::Create);
	mgr->register_creature_script(10198, &GiantStone::Create);
	mgr->register_creature_script(10648, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(10659, &DragonkinWhelp::Create);
	mgr->register_creature_script(10660, &DragonkinWhelp::Create);
	mgr->register_creature_script(10760, &HumanoidGeomancer::Create);
	mgr->register_creature_script(11576, &ElementalAir::Create);
	mgr->register_creature_script(11682, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(11683, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(11697, &Succubus::Create);
	mgr->register_creature_script(11880, &HumanoidPaladinRetribution::Create);
	mgr->register_creature_script(11881, &HumanoidGeomancer::Create);
	mgr->register_creature_script(11882, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(11913, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(12178, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(14342, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(14428, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(14458, &ElementalWater::Create);
	mgr->register_creature_script(5355, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(16769, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(16772, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(16810, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(16863, &BeastBoar::Create);
	mgr->register_creature_script(16873, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(16878, &HumanoidWarriorBerserker::Create);
	mgr->register_creature_script(16880, &BeastBoar::Create);
	mgr->register_creature_script(16901, &MiscOoze::Create);
	mgr->register_creature_script(16904, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(16905, &HumanoidMageFire::Create);
	mgr->register_creature_script(16906, &DoomGuard::Create);
	mgr->register_creature_script(16929, &MiscShield::Create);
	mgr->register_creature_script(16937, &HumanoidGeomancer::Create);
	mgr->register_creature_script(16950, &Felhunter::Create);
	mgr->register_creature_script(16954, &DoomGuard::Create);
	mgr->register_creature_script(16960, &Succubus::Create);
	mgr->register_creature_script(16966, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(17014, &VoidwalkerMob::Create);
	mgr->register_creature_script(17088, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(17135, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(17142, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(17143, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(17146, &HumanoidMageFire::Create);
	mgr->register_creature_script(17147, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(17150, &HumanoidMageArcane::Create);
	mgr->register_creature_script(17152, &DoomGuard::Create);
	mgr->register_creature_script(17156, &ElementalEarth::Create);
	mgr->register_creature_script(17157, &ElementalEarth::Create);
	mgr->register_creature_script(17158, &ElementalAir::Create);
	mgr->register_creature_script(17160, &ElementalAir::Create);
	mgr->register_creature_script(17981, &VoidwalkerMob::Create);
	mgr->register_creature_script(18077, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(18079, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(18087, &HumanoidMageFrost::Create);
	mgr->register_creature_script(18113, &HumanoidHunter::Create);
	mgr->register_creature_script(18114, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(18116, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(18118, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(18121, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(18124, &GiantFungal::Create);
	mgr->register_creature_script(18159, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(18351, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(18352, &HumanoidHunter::Create);
	mgr->register_creature_script(18450, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(18451, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(18455, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(18457, &HumanoidHunter::Create);
	mgr->register_creature_script(18539, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(18850, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(18855, &HumanoidMageFire::Create);
	mgr->register_creature_script(18857, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(18864, &ElementalMana::Create);
	mgr->register_creature_script(18865, &ElementalAir::Create);
	mgr->register_creature_script(18866, &ElementalMana::Create);
	mgr->register_creature_script(18870, &VoidwalkerMob::Create);
	mgr->register_creature_script(18872, &HumanoidPaladinRetribution::Create);
	mgr->register_creature_script(18873, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(18881, &ElementalEarth::Create);
	mgr->register_creature_script(18977, &DoomGuard::Create);
	mgr->register_creature_script(19188, &GiantStone::Create);
	mgr->register_creature_script(19190, &DoomGuard::Create);
	mgr->register_creature_script(19298, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(19408, &Succubus::Create);
	mgr->register_creature_script(19410, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(19411, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(19413, &HumanoidMageFire::Create);
	mgr->register_creature_script(19415, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(19422, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(19442, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(19457, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(19459, &DoomGuard::Create);
	mgr->register_creature_script(19527, &VoidwalkerMob::Create);
	mgr->register_creature_script(19543, &HumanoidMageArcane::Create);
	mgr->register_creature_script(19545, &HumanoidMageFrost::Create);
	mgr->register_creature_script(19546, &HumanoidMageArcane::Create);
	mgr->register_creature_script(19635, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(19642, &HumanoidMageArcane::Create);
	mgr->register_creature_script(19643, &HumanoidMageArcane::Create);
	mgr->register_creature_script(19653, &ElementalWater::Create);
	mgr->register_creature_script(19657, &HumanoidMageArcane::Create);
	mgr->register_creature_script(19701, &HumanoidMageFire::Create);
	mgr->register_creature_script(19707, &HumanoidHunter::Create);
	mgr->register_creature_script(19732, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(19757, &ElementalFire::Create);
	mgr->register_creature_script(19762, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(19767, &HumanoidMageFrost::Create);
	mgr->register_creature_script(19768, &HumanoidMageFrost::Create);
	mgr->register_creature_script(19789, &HumanoidMageFrost::Create);
	mgr->register_creature_script(19796, &HumanoidMageFire::Create);
	mgr->register_creature_script(19826, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(19830, &HumanoidMageArcane::Create);
	mgr->register_creature_script(19831, &HumanoidWarriorArms::Create);
	mgr->register_creature_script(19852, &Felhunter::Create);
	mgr->register_creature_script(19853, &DoomGuard::Create);
	mgr->register_creature_script(19881, &HumanoidMageArcane::Create);
	mgr->register_creature_script(19926, &HumanoidMageFire::Create);
	mgr->register_creature_script(19947, &HumanoidMageFrost::Create);
	mgr->register_creature_script(19952, &HumanoidGeomancer::Create);
	mgr->register_creature_script(19985, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(19989, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(19992, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(19994, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(19996, &HumanoidMageFire::Create);
	mgr->register_creature_script(19998, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(20079, &ElementalWater::Create);
	mgr->register_creature_script(20089, &HumanoidMageFrost::Create);
	mgr->register_creature_script(20115, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(20134, &HumanoidMageArcane::Create);
	mgr->register_creature_script(20135, &HumanoidMageFire::Create);
	mgr->register_creature_script(20139, &HumanoidMageArcane::Create);
	mgr->register_creature_script(20207, &HumanoidHunter::Create);
	mgr->register_creature_script(20221, &HumanoidGeomancer::Create);
	mgr->register_creature_script(20248, &HumanoidMageArcane::Create);
	mgr->register_creature_script(20270, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(20397, &HumanoidMageFire::Create);
	mgr->register_creature_script(20416, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(20435, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(20452, &HumanoidRogueAssassination::Create);
	mgr->register_creature_script(20454, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(20458, &HumanoidShamanElemental::Create);
	mgr->register_creature_script(20474, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(20483, &HumanoidMageFrost::Create);
	mgr->register_creature_script(20512, &HumanoidPriestShadow::Create);
	mgr->register_creature_script(20514, &ElementalFire::Create);
	mgr->register_creature_script(20563, &HumanoidWarriorFury::Create);
	mgr->register_creature_script(20614, &HumanoidMageArcane::Create);
	mgr->register_creature_script(20684, &HumanoidMageFrost::Create);
	mgr->register_creature_script(20872, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(20878, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(20887, &Imp::Create);
	mgr->register_creature_script(20920, &HumanoidMageFire::Create);
	mgr->register_creature_script(20934, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(21021, &Imp::Create);
	mgr->register_creature_script(21047, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(21050, &ElementalEarth::Create);
	mgr->register_creature_script(21059, &ElementalWater::Create);
	mgr->register_creature_script(21060, &ElementalAir::Create);
	mgr->register_creature_script(21065, &HumanoidMageFrost::Create);
	mgr->register_creature_script(21089, &HumanoidWarriorProtection::Create);
	mgr->register_creature_script(21178, &HumanoidRogueCombat::Create);
	mgr->register_creature_script(21285, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(21300, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(21302, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(21370, &HumanoidMageArcane::Create);
	mgr->register_creature_script(21383, &HumanoidMageArcane::Create);
	mgr->register_creature_script(21387, &DragonkinWhelp::Create);
	mgr->register_creature_script(21503, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(21505, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(21637, &HumanoidHunter::Create);
	mgr->register_creature_script(21649, &HumanoidDruidBalance::Create);
	mgr->register_creature_script(21660, &HumanoidMageArcane::Create);
	mgr->register_creature_script(21718, &HumanoidPriestDiscipline::Create);
	mgr->register_creature_script(21720, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(21721, &DragonkinWhelp::Create);
	mgr->register_creature_script(21725, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(21728, &ElementalWater::Create);
	mgr->register_creature_script(21809, &HumanoidHunter::Create);
	mgr->register_creature_script(21878, &BeastBoar::Create);
	mgr->register_creature_script(21902, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(21911, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(22017, &HumanoidMageArcane::Create);
	mgr->register_creature_script(22019, &HumanoidMageFire::Create);
	mgr->register_creature_script(22061, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(22081, &HumanoidWarlockDestruction::Create);
	mgr->register_creature_script(22180, &BeastBoar::Create);
	mgr->register_creature_script(22254, &HumanoidWarlockAffliction::Create);
	mgr->register_creature_script(22291, &DoomGuard::Create);
	mgr->register_creature_script(22298, &ElementalFire::Create);
	mgr->register_creature_script(22308, &HumanoidHunter::Create);
	mgr->register_creature_script(22387, &HumanoidShamanRestoration::Create);
	mgr->register_creature_script(22461, &MechanicalGun::Create);
}
