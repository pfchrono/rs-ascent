#include "StdAfx.h"
#include "Setup.h"

/* Group Quest - Gods of Annoyance - Cow God AI */
#define WARSTOMP		16727
#define MORTALSTRIKE	32736
#define THUNDERCLAP		30633

class PattyAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(PattyAI);
	SP_AI_Spell spells[3];
	bool		m_spellcheck[3];

	PattyAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 2;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

		spells[0].info = dbcSpell.LookupEntry(WARSTOMP);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 50.0f;
		spells[0].cooldown = 20;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(MORTALSTRIKE);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 60.0f;
		spells[1].cooldown = 10;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(THUNDERCLAP);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].perctrigger = 50.0f;
		spells[2].cooldown = 15;
		spells[2].attackstoptimer = 1000;

		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;

		EventStart = false;
	}

	void OnCombatStart(Unit *mTarget)
	{
		_unit->SendChatMessage
			(
				CHAT_MSG_MONSTER_YELL,
				LANG_UNIVERSAL,
				"You dare attack the God of Cows? How foolish you really are."
			);
		RegisterAIUpdateEvent(1000);
		CastTime();
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You can run.. but you'll be back.. I know.");
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;
		RemoveAIUpdateEvent();
	}

	void CastTime()
	{
		for(int i = 0; i < nrspells; i++) spells[i].casttime = 0;
	}

	void OnTargetDied(Unit *mTarget)
	{
		if(_unit->GetHealthPct() == 0) return;

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	RandomSpeach = rand() % 2;
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		switch(RandomSpeach)
		{
		case 0:
			_unit->SendChatMessage
				(
					CHAT_MSG_MONSTER_YELL,
					LANG_UNIVERSAL,
					"You think Patty weak? You have thought wrong!"
				);
			break;

		case 1:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Don't make me do it again!");
			break;
		}
	}

	void OnDied(Unit *mKiller)
	{
		_unit->SendChatMessage
			(
				CHAT_MSG_MONSTER_YELL,
				LANG_UNIVERSAL,
				"You may have defeated me, but the annoyances, will continue..."
			);
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;
		RemoveAIUpdateEvent();

		EventStart = false;
		SpawnCounter = 0;
		PhaseTimer = 310;
		SpawnTimer = 0;
		GCounter = 0;
		m_phase = 0;
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
};

/* --The Frog God--* */
#define TIDAL		37730
#define VOLLEY		38837
#define FROSTBOLT	41486
#define WVOLLEY		38335
class FrogAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(FrogAI);
	SP_AI_Spell spells[3];
	bool m_spellcheck[3];

	FrogAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 2;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

		spells[0].info = dbcSpell.LookupEntry(TIDAL);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = false;
		spells[0].perctrigger = 90.0f;
		spells[0].cooldown = 20;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(VOLLEY);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = true;
		spells[1].perctrigger = 50.0f;
		spells[1].cooldown = 10;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(FROSTBOLT);
		spells[2].targettype = TARGET_VARIOUS;
		spells[2].instant = true;
		spells[2].perctrigger = 50.0f;
		spells[2].cooldown = 15;
		spells[2].attackstoptimer = 1000;

		spells[3].info = dbcSpell.LookupEntry(WVOLLEY);
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = true;
		spells[3].perctrigger = 60.0f;
		spells[3].cooldown = 20;
		spells[3].attackstoptimer = 1000;

		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;

		EventStart = false;
	}

	void OnCombatStart(Unit *mTarget)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You think you can defeat the Frog God?");
		RegisterAIUpdateEvent(1000);
		CastTime();
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

	void CastTime()
	{
		for(int i = 0; i < nrspells; i++) spells[i].casttime = 0;
	}

	void OnTargetDied(Unit *mTarget)
	{
		if(_unit->GetHealthPct() == 0) return;

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32 RandomSpeach = rand() % 2;
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		switch(RandomSpeach)
		{
		case 0:
			_unit->SendChatMessage
				(
					CHAT_MSG_MONSTER_YELL,
					LANG_UNIVERSAL,
					"I'll remember to give you a proper burial on a nice lillypad!"
				);
			break;

		case 1:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Going, so soon?");
			break;
		}
	}

	void OnDied(Unit *mKiller)
	{
		_unit->SendChatMessage
			(
				CHAT_MSG_MONSTER_YELL,
				LANG_UNIVERSAL,
				"You may have defeated me, but the annoyances, will continue..."
			);
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;
		RemoveAIUpdateEvent();

		EventStart = false;
		SpawnCounter = 0;
		PhaseTimer = 310;
		SpawnTimer = 0;
		GCounter = 0;
		m_phase = 0;
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		float val = ( float ) RandomFloat(100.0f);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		SpellCast(val);
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~*/
			float comulativeperc = 0;
			Unit	*target = NULL;
			/*~~~~~~~~~~~~~~~~~~~~~*/

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

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				uint32 t = (uint32) time(NULL);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
};

/* Group Quest - Gods of Annoyance - Snake God AI */
#define PSPIT	36694
#define PVOLLEY 40095
#define PSPRAY	30043
#define CUREME	43581

class SnakeAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(SnakeAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

	SnakeAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		nrspells = 3;

		for(int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

		spells[0].info = dbcSpell.LookupEntry(PSPIT);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 90.0f;
		spells[0].cooldown = 13;
		spells[0].attackstoptimer = 2000;

		spells[1].info = dbcSpell.LookupEntry(PVOLLEY);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = true;
		spells[1].perctrigger = 80.0f;
		spells[1].cooldown = 10;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(PSPRAY);
		spells[2].targettype = TARGET_VARIOUS;
		spells[2].instant = true;
		spells[2].perctrigger = 50.0f;
		spells[2].cooldown = 10;
		spells[2].attackstoptimer = 1000;

		spells[3].info = dbcSpell.LookupEntry(CUREME);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].perctrigger = 90.0f;
		spells[3].cooldown = 7;
		spells[3].attackstoptimer = 1000;

		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;

		EventStart = false;
	}

	void OnCombatStart(Unit *mTarget)
	{
		_unit->SendChatMessage
			(
				CHAT_MSG_MONSTER_YELL,
				LANG_UNIVERSAL,
				"Hisssss... How dare you...sss..attack..hisss... Ms. Hissyfit! The god of the snakes!"
			);
		RegisterAIUpdateEvent(1000);
		CastTime();
	}

	void OnCombatStop(Unit *mTarget)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "HHhhhhhhhhiiiiisssss....!");
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;
		RemoveAIUpdateEvent();
	}

	void CastTime()
	{
		for(int i = 0; i < nrspells; i++) spells[i].casttime = 0;
	}

	void OnTargetDied(Unit *mTarget)
	{
		if(_unit->GetHealthPct() == 0) return;

		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32 RandomSpeach = rand() % 2;
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		switch(RandomSpeach)
		{
		case 0:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "The poison, has defeated another.");
			break;

		case 1:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I bet you wont try that again!");
			break;
		}
	}

	void OnDied(Unit *mKiller)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "YYou.. have.. done..well....");
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;
		RemoveAIUpdateEvent();

		EventStart = false;
		SpawnCounter = 0;
		PhaseTimer = 310;
		SpawnTimer = 0;
		GCounter = 0;
		m_phase = 0;
	}

	void AIUpdate()
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		float val = ( float ) RandomFloat(100.0f);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		SpellCast(val);
	}

	void SpellCast(float val)
	{
		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
		{
			/*~~~~~~~~~~~~~~~~~~~~~*/
			float comulativeperc = 0;
			Unit	*target = NULL;
			/*~~~~~~~~~~~~~~~~~~~~~*/

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

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				uint32 t = (uint32) time(NULL);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
};

void SetupTehGods(ScriptMgr *mgr)
{
	mgr->register_creature_script(1300002, &PattyAI::Create);
	mgr->register_creature_script(1300006, &FrogAI::Create);
	mgr->register_creature_script(1300007, &SnakeAI::Create);
}
