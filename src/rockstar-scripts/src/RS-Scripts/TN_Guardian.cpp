/*
                      ,-.        _.---._
                      |  `\.__.-''       `.
                       \  _        _  ,.   \
 ,+++=._________________)_||______|_|_||    |  ,_    _,   _, ,  ,  _, ___, _    ,_
(_.ooo.===================||======|=|=||    |  |_)  / \, /   |_/  (_,' |  '|\   |_)
   ~~'                 |  ~'      `~' o o  /  '| \ '\_/ '\_ '| \   _)  |   |-\ '| \
                        \   /~`\     o o  /    '  ` '      ` '  ` '    '   '  ` '  `
                         `~'    `-.____.-'
						 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
						 http://www.fishstik.ca Please do not use these scripts for any other server
						 than the RockStar Funserver(http://fishstik.ca) as they were specially
						 scripted/modded for the server in question.
 */
/* TN Guardian AI Stuff by Midnight for Rockstar Funserver */
#include "StdAfx.h"
#include "Setup.h"

/* TN Guardian */
#define TN_GUARD		770000

#define CRYSTAL_PRISON	32361
#define STUN_FOREVER	23775
#define STRANGE_AURA	32407

class TN_GUARDAI :	public CreatureAIScript
{
public:
		ADD_CREATURE_FACTORY_FUNCTION(TN_GUARDAI);
	SP_AI_Spell spells[3];
	bool m_spellcheck[3];

	TN_GUARDAI(Creature *pCreature) :	CreatureAIScript(pCreature)
	{
		nrspells = 3;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(CRYSTAL_PRISON);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 72.37f;
		spells[0].attackstoptimer = 1000;
		spells[0].cooldown = 10;

		spells[1].info = dbcSpell.LookupEntry(STUN_FOREVER);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 25.96f;
		spells[1].attackstoptimer = 1000;
		spells[1].cooldown = 10;

		spells[2].info = dbcSpell.LookupEntry(STRANGE_AURA);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].perctrigger = 65.66f;
		spells[2].attackstoptimer = 1000;
	}

	void OnCombatStart(Unit *mTarget)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Prepare to die mortal!");
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
	}

	void OnTargetDied(Unit *mTarget)
	{
		/*~~~~~~~~~~~~~*/
		char	msg[200];
		/*~~~~~~~~~~~~~*/

		if(mTarget->GetTypeId() == TYPEID_PLAYER)
		{
			sprintf(msg, "You will never learn, %s.", static_cast< Player * >(mTarget)->GetName());
		}
		else if(mTarget->IsPet())
		{
			sprintf(msg, "You will never learn, %s.", static_cast< Pet * >(mTarget)->GetName().c_str());
		}

		_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, msg);
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
		if(_unit->GetCurrentSpell() == NULL && (_unit->GetAIInterface()->GetNextTarget()))
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
		delete ( TN_GUARDAI * ) this;
	}

protected:
	int nrspells;
};

void SetupTNGuard(ScriptMgr *mgr)
{
	mgr->register_creature_script(TN_GUARD, &TN_GUARDAI::Create);
}
