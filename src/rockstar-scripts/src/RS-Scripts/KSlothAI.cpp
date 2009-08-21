#include "StdAfx.h"
#include "Setup.h"

/************************************************************************/
/* RAID AREA - Dias' Cove of the Demon Hunters - K'sloth AI.".			*/
/************************************************************************/

/*
global KSlothEnter = function(Plr)	.SendChatMessage("I will not enslave you, no, I will DESTROY you all!");
global KSlothNecroKill = function(Plr)	.SendChatMessage("Please! I do not wish to kill any longer, finish me!");
global KSlothDemonKill = function(Plr)	.SendChatMessage("Hahahah, you are no match for me!");
global KSlothMorphed = function(Plr)
{
	.SendChatMessage("What.. What is this!? What is happening!?");
	.Emote(15);
	.RegisterTimer(7000, KSlothAfraid, 1);
};
global KSlothAfraid = function(mob, plr)
{
	.SendChatMessage("What.. Has happened? Please!! FINISH ME!!! Before the Evil takes over again.. And beware... beware.. mala..");
};
global KSlothMorph = function(mob, plr)	.SpawnMonster(700000, -10663.35, 2085.031, -45.8243);
*/

#define FIRE_SHIELD 37434
#define HEALING_POTION 40535


class KSlothAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(KSlothAI);
	SP_AI_SpellF spells[2];
	bool m_spellcheck[2];

    KSlothAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 2;
		necro_morphed = 0;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

		
		spells[0].info = dbcSpell.LookupEntry(FIRE_SHIELD);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 1800;	/* 10 min */
		spells[0].perctrigger = 15.0f;
		spells[0].attackstoptimer = 1000;
		spells[0].hpreqtocast = 80;

		spells[1].info = dbcSpell.LookupEntry(HEALING_POTION);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].cooldown = 3600; 
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 1000;
		spells[1].hpreqtocast = 40;

       	_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;

		EventStart = false;
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will not enslave you, no, I will DESTROY you all!");
		RegisterAIUpdateEvent(1000);
		CastTime();
    }

	void CastTime()
	{
		for(int i = 0; i < nrspells; i++) spells[i].casttime = 0;
	}

	void AIUpdate()
    {
		if(_unit->GetHealthPct() <= 20.0f && necro_morphed == 0)
		{
			necro_morphed = 1;
			_unit->SetUInt32Value(UNIT_FIELD_DISPLAYID , 16279);
			_unit->SetFloatValue(OBJECT_FIELD_SCALE_X , 1.1f);
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "What.. What is this!? What is happening!?");
		}
		if(_unit->GetHealthPct() > 20.0f && necro_morphed == 1 && _unit->CombatStatus.IsInCombat())
		{
			necro_morphed = 0;
			_unit->SetUInt32Value(UNIT_FIELD_DISPLAYID , 7570);
			_unit->SetFloatValue(OBJECT_FIELD_SCALE_X , 1.0f);
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Ahhh, I can feel the power!!!");
		}
		float	val = ( float ) RandomFloat(100.0f);
		SpellCast(val);
	}

    void OnCombatStop(Unit *mTarget)
    {
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;
		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
	{
		if (_unit->GetHealthPct() == 0) return;
		switch(necro_morphed)
		{
		case 0: 
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Hahahah, you are no match for me!");
			break;
		case 1:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Please! I do not wish to kill any longer, finish me!");
			break;
		}
	}

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "What.. Has happened? Please!!");
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "FINISH ME!!! Before the Evil takes over again.. And beware.. beware.. mala..");
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->SetUInt32Value(UNIT_FIELD_DISPLAYID , 16279);
		_unit->GetAIInterface()->m_canMove = true;
		RemoveAIUpdateEvent();
		necro_morphed = 0;
		
		EventStart = false;
		SpawnCounter = 0;
		PhaseTimer = 310;
		SpawnTimer = 0;
		GCounter = 0;
		m_phase = 0;
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
				

				if(m_spellcheck[i] && (_unit->GetHealthPct() <= spells[i].hpreqtocast) )
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

					case TARGET_RANDOM_FRIEND:
					case TARGET_RANDOM_SINGLE:
					case TARGET_RANDOM_DESTINATION:
						CastSpellOnRandomTarget
						(
							i,
							spells[i].mindist2cast,
							spells[i].maxdist2cast,
							spells[i].minhp2cast,
							spells[i].maxhp2cast
						);
						break;
					}

					if(spells[i].speech != "")
					{
						_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, spells[i].speech.c_str());
						_unit->PlaySoundToSet(spells[i].soundid);
					}

					m_spellcheck[i] = false;
					return;
				}

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				uint32	t = (uint32) time(NULL);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if
				(
					((val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger)) || i == 1)
				&&	t > spells[i].casttime
				)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}

				comulativeperc += spells[i].perctrigger;
			}
		}
	}

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if(!maxdist2cast) maxdist2cast = 100.0f;
		if(!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			std::vector<Unit *> TargetTable;	/* From M4ksiu - Big THX to Capt who helped me with std stuff to make
												 * it simple and fully working <3 */
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			/* If anyone wants to use this function, then leave this note! */
			for(set < Object * >::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr)
			{
				if
				(
					(
						(spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr)))
					||	(spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)
					)
				&&	((*itr)->GetTypeId() == TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER)
				&&	(*itr)->GetInstanceID() == _unit->GetInstanceID()
				)	/* isAttackable(_unit, (*itr)) && */
				{
					/*~~~~~~~~~~~~~~~~~~~~~~~~~*/
					Unit	*RandomTarget = NULL;
					/*~~~~~~~~~~~~~~~~~~~~~~~~~*/

					RandomTarget = (Unit *) (*itr);

					if
					(
						RandomTarget->isAlive()
					&&	_unit->GetDistance2dSq(RandomTarget) >= mindist2cast * mindist2cast
					&&	_unit->GetDistance2dSq(RandomTarget) <= maxdist2cast * maxdist2cast
					&&	(
							(
								RandomTarget->GetHealthPct() >= minhp2cast
							&&	RandomTarget->GetHealthPct() <= maxhp2cast
							&&	spells[i].targettype == TARGET_RANDOM_FRIEND
							)
						||	(
									_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0
								&&	isHostile(_unit, RandomTarget)
								)
						)
					)
					{
						TargetTable.push_back(RandomTarget);
					}
				}
			}

			if
			(
				_unit->GetHealthPct() >= minhp2cast
			&&	_unit->GetHealthPct() <= maxhp2cast
			&&	spells[i].targettype == TARGET_RANDOM_FRIEND
			) TargetTable.push_back(_unit);

			if(!TargetTable.size()) return;

			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			size_t RandTarget = rand() % TargetTable.size();
			Unit	*RTarget = TargetTable[RandTarget];
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(!RTarget) return;

			switch(spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant);
				break;

			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF
					(
						RTarget->GetPositionX(),
						RTarget->GetPositionY(),
						RTarget->GetPositionZ(),
						spells[i].info,
						spells[i].instant
					);
				break;
			}

			TargetTable.clear();
		}
	}

protected:
	uint32 SpawnCounter;
	uint32 HelpDialog;
	uint32 SpawnTimer;
	uint32 PhaseTimer;
	uint32 WaveTimer;
	uint32 GCounter;
	bool EventStart;
	uint32 m_phase;
	int nrspells;
	int necro_morphed;
};

void Setup_KSlothAI(ScriptMgr * mgr)
{
	mgr->register_creature_script(870001, &KSlothAI::Create);
}
