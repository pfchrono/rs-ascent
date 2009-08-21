/*
	The RockStar FunServer ~ Egari, T0aST, Midnight
	For use with GUARDTYPE_PVP (Anti-PVP Guard).
 */
#include "StdAfx.h"
#include "Setup.h"

#define NET 12024
class PeaceKeeperAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(PeaceKeeperAI);
	SP_AI_Spell spells[1];
	bool m_spellcheck[1];

	PeaceKeeperAI(Creature* pCreature) : CreatureAIScript(pCreature)
	{
		// -- Number of spells to add --
		nrspells = 1;
		// --- Initialization ---
		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}
		// ----------------------
		spells[0].info = dbcSpell.LookupEntry(NET);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 91.7f;
		spells[0].attackstoptimer = 1000;
		spells[0].cooldown = 60;
		spells[0].proctimes = 1;
		spells[0].proctimes2 = 0;

			 	_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;
	}
	
	void OnCombatStart(Unit* mTarget)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Not on my watch!");
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		for(int i = 0; i < nrspells; i++)
		{
			spells[i].proctimes2 = 0;
		}
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		RemoveAIUpdateEvent();
	}

	void OnDied(Unit * mKiller)
	{
		RemoveAIUpdateEvent();
	}

	void AIUpdate()
	{
		float val = (float)RandomFloat(100.0f);
		SpellCast(val);
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && (_unit->GetAIInterface()->GetNextTarget()))
		{
			float	comulativeperc = 0;
			Unit	*target = NULL;
			for(int i = 0; i < nrspells; i++)
			{
				if( spells[i].proctimes2 >= spells[i].proctimes ) continue;
				if(!spells[i].perctrigger) continue;
				if(m_spellcheck[i])
				{
					spells[i].proctimes2++;
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
					case TARGET_SELF:
					case TARGET_VARIOUS:
						{
						_unit->CastSpell(_unit, spells[i].info, spells[i].instant);
						}break;

					case TARGET_ATTACKING:
						{
						_unit->CastSpell(target, spells[i].info, spells[i].instant);
						}break;

					case TARGET_DESTINATION:
						{
							_unit->CastSpellAoF
							(
								target->GetPositionX(),
								target->GetPositionY(),
								target->GetPositionZ(),
								spells[i].info,
								spells[i].instant
							);
						}break;
					}

					m_spellcheck[i] = false;
					return;
				}

				if((val > comulativeperc) && (val <= (comulativeperc + spells[i].perctrigger)))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
		}
	}
	
	void Destroy()
	{
		delete ( PeaceKeeperAI * ) this;
	}

protected:

	int nrspells;
};

void SetupPeaceKeeperAI(ScriptMgr * mgr)
{
	mgr->register_creature_script(1944, &PeaceKeeperAI::Create);
	mgr->register_creature_script(3379, &PeaceKeeperAI::Create);
	mgr->register_creature_script(3502, &PeaceKeeperAI::Create);
	mgr->register_creature_script(4624, &PeaceKeeperAI::Create);
	mgr->register_creature_script(9460, &PeaceKeeperAI::Create);
	mgr->register_creature_script(11190, &PeaceKeeperAI::Create);
	mgr->register_creature_script(15724, &PeaceKeeperAI::Create);
	mgr->register_creature_script(16096, &PeaceKeeperAI::Create);
	mgr->register_creature_script(16283, &PeaceKeeperAI::Create);
	mgr->register_creature_script(20484, &PeaceKeeperAI::Create);
	mgr->register_creature_script(20485, &PeaceKeeperAI::Create);
	mgr->register_creature_script(22494, &PeaceKeeperAI::Create);
	mgr->register_creature_script(22826, &PeaceKeeperAI::Create);
	mgr->register_creature_script(23636, &PeaceKeeperAI::Create);
	mgr->register_creature_script(23721, &PeaceKeeperAI::Create);
	/*
	mgr->register_creature_script(24689, &PeaceKeeperAI::Create);
	mgr->register_creature_script(25575, &PeaceKeeperAI::Create); Wretched Bruisers in MT anti-PVP guards?? wtf?
	*/
	mgr->register_creature_script(25992, &PeaceKeeperAI::Create);
}


