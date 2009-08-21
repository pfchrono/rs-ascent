/* Created by Jhonnut for Ascent in accordance with their license. */
#include "StdAfx.h"
#include "Setup.h"

/* warlock */
#define BLOODSAIL_WARLOCK	1564

#define SHADOW_BOLT			7641
#define CURSE_OF_WEAKNESS	11707
#define DISARM				13534

class BLOODSAILwarlockAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BLOODSAILwarlockAI);
	SP_AI_Spell spells[3];
	bool		m_spellcheck[3];

	BLOODSAILwarlockAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 3;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(SHADOW_BOLT);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 62.37f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(CURSE_OF_WEAKNESS);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 0.96f;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(DISARM);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].perctrigger = 0.66f;
		spells[2].attackstoptimer = 1000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		float	val = ( float ) RandomFloat(100.0f);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		SpellCast(val);
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~*/
			float	comulativeperc = 0;
			Unit	*target = NULL;
			/*~~~~~~~~~~~~~~~~~~~~~~~*/

			for(int i = 0; i < nrspells; i++)
			{
				if(!spells[i].perctrigger) continue;

				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
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

					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}

				comulativeperc += spells[i].perctrigger;
			}
		}
	}

protected:
	int nrspells;
};

#define BLOODSAIL_MAGE		1562

#define FIRE_BALL			8402
#define SHADOW_WORD_PAIN	10895
#define NET					41580

class BLOODSAILmageAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BLOODSAILmageAI);
	SP_AI_Spell spells[3];
	bool		m_spellcheck[3];

	BLOODSAILmageAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 3;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(FIRE_BALL);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 53.72f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(SHADOW_WORD_PAIN);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 0.05f;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(NET);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].perctrigger = 0.88f;
		spells[2].attackstoptimer = 1000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		float	val = ( float ) RandomFloat(100.0f);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		SpellCast(val);
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~*/
			float	comulativeperc = 0;
			Unit	*target = NULL;
			/*~~~~~~~~~~~~~~~~~~~~~~~*/

			for(int i = 0; i < nrspells; i++)
			{
				if(!spells[i].perctrigger) continue;

				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
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

					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}

				comulativeperc += spells[i].perctrigger;
			}
		}
	}

protected:
	int nrspells;
};

#define BLOODSAIL_ELDER_MAGUS	1653

#define FIRE_BALL				8402
#define FLAME_STRIKE			8423
#define FIRE_NOVA				11306
#define GOUGE					8629

class BLOODSAILeldermagusAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BLOODSAILeldermagusAI);
	SP_AI_Spell spells[4];
	bool		m_spellcheck[4];

	BLOODSAILeldermagusAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 4;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(FIRE_BALL);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 30.99f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(FLAME_STRIKE);
		spells[1].targettype = TARGET_DESTINATION;
		spells[1].instant = true;
		spells[1].perctrigger = 27.75f;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(FIRE_NOVA);
		spells[2].targettype = TARGET_DESTINATION;
		spells[2].instant = true;
		spells[2].perctrigger = 7.71f;
		spells[2].attackstoptimer = 1000;

		spells[3].info = dbcSpell.LookupEntry(GOUGE);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].perctrigger = 1.12f;
		spells[3].attackstoptimer = 1000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		float	val = ( float ) RandomFloat(100.0f);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		SpellCast(val);
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~*/
			float	comulativeperc = 0;
			Unit	*target = NULL;
			/*~~~~~~~~~~~~~~~~~~~~~~~*/

			for(int i = 0; i < nrspells; i++)
			{
				if(!spells[i].perctrigger) continue;

				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
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

					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}

				comulativeperc += spells[i].perctrigger;
			}
		}
	}

protected:
	int nrspells;
};

#define BLOODSAIL_SWASHBUCKLER	1563

#define KICK					1768
#define DISARM1					13534

class BLOODSAILswashbucklerAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BLOODSAILswashbucklerAI);
	SP_AI_Spell spells[2];
	bool		m_spellcheck[2];

	BLOODSAILswashbucklerAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 2;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(KICK);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].perctrigger = 6.61f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(DISARM1);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 5.15f;
		spells[1].attackstoptimer = 1000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		float	val = ( float ) RandomFloat(100.0f);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		SpellCast(val);
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~*/
			float	comulativeperc = 0;
			Unit	*target = NULL;
			/*~~~~~~~~~~~~~~~~~~~~~~~*/

			for(int i = 0; i < nrspells; i++)
			{
				if(!spells[i].perctrigger) continue;

				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
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

					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}

				comulativeperc += spells[i].perctrigger;
			}
		}
	}

protected:
	int nrspells;
};

#define BLOODSAIL_SEADOG	1565

#define POISON				16401
#define GOUGE1				8629
#define BACKSTAB			8721
class BLOODSAILseadogAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BLOODSAILseadogAI);
	SP_AI_Spell spells[2];
	bool		m_spellcheck[2];

	BLOODSAILseadogAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 2;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(POISON);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].perctrigger = 23.43f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(GOUGE1);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 10.06f;
		spells[1].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(BACKSTAB);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 3.75f;
		spells[1].attackstoptimer = 1000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit *mKiller)
	{
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		float	val = ( float ) RandomFloat(100.0f);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		SpellCast(val);
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~*/
			float	comulativeperc = 0;
			Unit	*target = NULL;
			/*~~~~~~~~~~~~~~~~~~~~~~~*/

			for(int i = 0; i < nrspells; i++)
			{
				if(!spells[i].perctrigger) continue;

				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
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

					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}

				comulativeperc += spells[i].perctrigger;
			}
		}
	}

protected:
	int nrspells;
};

void SetupBloodsailStuff(ScriptMgr *mgr)
{
	mgr->register_creature_script(BLOODSAIL_SWASHBUCKLER, &BLOODSAILswashbucklerAI::Create);
	mgr->register_creature_script(BLOODSAIL_ELDER_MAGUS, &BLOODSAILeldermagusAI::Create);
	mgr->register_creature_script(BLOODSAIL_MAGE, &BLOODSAILmageAI::Create);
	mgr->register_creature_script(BLOODSAIL_WARLOCK, &BLOODSAILwarlockAI::Create);
	mgr->register_creature_script(BLOODSAIL_SEADOG, &BLOODSAILseadogAI::Create);
}
