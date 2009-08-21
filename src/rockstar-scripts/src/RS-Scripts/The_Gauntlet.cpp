#include "StdAfx.h"
#include "Setup.h"

/************************************************************************/
/* EVENT AREA - Kokoruki's "The Gaunlet".		                   		*/
/************************************************************************/

/****************** 
*--	QuirkAI	--* 
******************* 
QUIRK-(ID)15398 (HP)10,500,000 (M)10,000,000 (DMG)5,100-9,500 (SPEED)1.7 (LEVEL)134 ELITE RARE BOSS.
**(ages of preservation)#23780 = 40% proc random HP = self cast 2 min CD
**(ages of ragneros)#20620 = 40% proc random HP = self cast 10 min CD 
**(volcanic geyser)#40118 = 70% proc random HP (aoe) 7 sec CD

**(acid geyser)#38739 = 100% proc 50% HP (aoe) 20 sec CD
**(agonizing armor)#36836 = 100% proc 25% HP = tank *1 min CD 
*msg on enter combat: When tis is over you will not want me as a pet!
*msg on player death: We are sick of being tied down.....Bring IT!
*msg on npc death: I will.......have.....REVENge............GIRGGGGGGGLLLLLLLEEEEEE!!!!!
*/

#define AEGIS_OF_PRESERVATION 23780
#define AEGIS_OF_RAGNAROS 20620
#define VOLCANIC_GEYSER 42052
#define ACID_GEYSER 38739
#define AGONIZING_ARMOR 36836

class QuirkAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(QuirkAI);
	SP_AI_Spell spells[5];
	bool m_spellcheck[5];

    QuirkAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 5;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

        spells[0].info = dbcSpell.LookupEntryForced( AEGIS_OF_PRESERVATION );
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = false;
		spells[0].perctrigger = 40.0f;
		spells[0].cooldown = 120;
		spells[0].attackstoptimer = 2000;
		spells[0].hpreqtocast = 95;

		spells[1].info = dbcSpell.LookupEntryForced( AEGIS_OF_RAGNAROS );
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = false;
		spells[1].perctrigger = 40.0f;
		spells[1].cooldown = 600;
		spells[1].attackstoptimer = 2000;
		spells[1].hpreqtocast = 85;

		spells[2].info = dbcSpell.LookupEntryForced( VOLCANIC_GEYSER );
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;
		spells[2].perctrigger = 70.0f;
		spells[2].cooldown = 7;
		spells[2].attackstoptimer = 2000;
		spells[2].hpreqtocast = 99;

		spells[3].info = dbcSpell.LookupEntryForced( ACID_GEYSER );
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].perctrigger = 100.0f;
		spells[3].cooldown = 20;
		spells[3].attackstoptimer = 2000;
		spells[3].hpreqtocast = 50;
		
		spells[4].info = dbcSpell.LookupEntryForced( AGONIZING_ARMOR );
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].perctrigger = 100.0f;
		spells[4].cooldown = 60;
		spells[4].attackstoptimer = 2000;
		spells[4].hpreqtocast = 25;

		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;

		EventStart = false;
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "When tis is over you will not want me as a pet!");
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
		for(int i=0;i<nrspells;i++)
			spells[i].casttime = 0;
	}

	void OnTargetDied(Unit* mTarget)
	{
		if (_unit->GetHealthPct() == 0) return;
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "We are sick of being tied down.....Bring IT!");
	}

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will..have...REVENge....GIRGGGLLLLEEE!!!!!");
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
		if(_unit->GetHealthPct() == 50 || _unit->GetHealthPct() == 25)
		{
			nrspells++;
		}
		float val = (float)RandomFloat(100.0f);
		SpellCast(val);
	}

	void SpellCast(float val)
    {
		// 60% proc@75%hp & 50%hp & 25%hp (aoe)*15 sec CD = on death msg: 
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;

				if(m_spellcheck[i] && (_unit->GetHealthPct() <= spells[i].hpreqtocast))
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}



					if (spells[i].speech != "")
					{
						_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, spells[i].speech.c_str());
						_unit->PlaySoundToSet(spells[i].soundid); 
					}

					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(((val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger)) || i == 1) && t > spells[i].casttime)
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
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
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
	int RS_Phase;
};

/****************** 
*--	SquirtAI	--* 
******************* 
SQUIRT-(ID)7937 (HP)110,000 (M)15,000 (DMG)400-510 (SPEED)1.4 (LEVEL)85 ELITE
(acid splash)#32139 = 60% proc@75%hp & 50%hp & 25%hp (aoe)*15 sec CD 
on death msg: ha! you have much yet to see! */

#define ACID_SPLASH 32139
class SquirtAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(SquirtAI);
	SP_AI_Spell spells[1];
	bool m_spellcheck[1];
	
    SquirtAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 1;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

        spells[0].info = dbcSpell.LookupEntryForced( ACID_SPLASH );
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 100.0f;
		spells[0].cooldown = 20;
		spells[0].attackstoptimer = 2000;

		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;

		EventStart = false;
		phase = false;
    }
    
    void OnCombatStart(Unit* mTarget)
    {
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
		for(int i=0;i<nrspells;i++)
			spells[i].casttime = 0;
	}

	void OnTargetDied(Unit* mTarget)
	{
		if (_unit->GetHealthPct() == 0) return;
	}

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Hah! You have much yet to see!!");
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
		float val = (float)RandomFloat(100.0f);
		SpellCast(val);	
	}

	void SpellCast(float val)
    {
		// 60% proc@75%hp & 50%hp & 25%hp (aoe)*15 sec CD = on death msg: 
		int UnitHP = _unit->GetHealthPct();
		if
		(		(UnitHP < 77 && UnitHP > 73) 
			||	(UnitHP < 52 && UnitHP > 48)
			||	(UnitHP < 27 && UnitHP > 23)
		){
			return;
		}


        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}



					if (spells[i].speech != "")
					{
						_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, spells[i].speech.c_str());
						_unit->PlaySoundToSet(spells[i].soundid); 
					}

					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(((val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger)) || i == 1) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }

		phase = false;
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
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
	bool phase;
	uint32 m_phase;
	int nrspells;
};



/******************
*--	POPPA CRAWL	--* 
*******************
POPPA CRAWL-(ID)18269 (HP)400,000 (M)100,000 (DMG)1,000-1,100 (SPEED)2.7 (LEVEL)108
(adementite shell)#33479 = 20% proc random HP = self cast *1 min CD
(agonizing armor)#36836 = 50% proc random HP = tank *1 min CD 
*/

#define ADAMANTITESHELL 33479
#define AGONIZINGARMOR 36836
class PoppaCrawlAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(PoppaCrawlAI);
	SP_AI_Spell spells[2];
	bool m_spellcheck[2];

    PoppaCrawlAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 2;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

        spells[0].info = dbcSpell.LookupEntryForced( ADAMANTITESHELL );
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = false;
		spells[0].perctrigger = 20.0f;
		spells[0].cooldown = 60;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntryForced( AGONIZINGARMOR );
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 50.0f;
		spells[1].cooldown = 60;			
		spells[1].attackstoptimer = 1000;
		spells[1].mindist2cast = 0.0f;
		spells[1].maxdist2cast = 50.0f;
		
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;

		EventStart = false;
    }
    
    void OnCombatStart(Unit* mTarget)
    {
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
		for(int i=0;i<nrspells;i++)
			spells[i].casttime = 0;
	}

	void OnTargetDied(Unit* mTarget)
	{
		if (_unit->GetHealthPct() == 0) return;
	}

    void OnDied(Unit * mKiller)
    {
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
		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

	void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}



					if (spells[i].speech != "")
					{
						_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, spells[i].speech.c_str());
						_unit->PlaySoundToSet(spells[i].soundid); 
					}

					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(((val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger)) || i == 1) && t > spells[i].casttime)
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
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
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

/******************
*--	RED EYE		--* 
*******************
RED EYE-(ID)16587 (HP)1,250,000 (M)1,000,000 (DMG)2,000-2,200 (SPEED)1.4 (LEVEL)121 ELITE
**(acid geyser)#38739 = 60% proc random HP (aoe) 20 sec CD 
on enter combat msg: this is gonna sting a bit!.....
on death msg:pure luck!...
player death msg:told ya it was gonna sting!
*/
#define ACID_GEYSER 38739
class RedEyeAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(RedEyeAI);
	SP_AI_Spell spells[1];
	bool m_spellcheck[1];

    RedEyeAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 1;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

        spells[0].info = dbcSpell.LookupEntryForced( ACID_GEYSER );
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 60.0f;
		spells[0].cooldown = 20;
		spells[0].attackstoptimer = 2000;

		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;

		EventStart = false;
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "This is gonna sting a bit!.....");
        RegisterAIUpdateEvent(1000);
		CastTime();
    }

    void OnCombatStop(Unit *mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Hehehe!");
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
		_unit->GetAIInterface()->disable_melee = false;
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->GetAIInterface()->m_canMove = true;
        RemoveAIUpdateEvent();

    }

	void CastTime()
	{
		for(int i=0;i<nrspells;i++)
			spells[i].casttime = 0;
	}

	void OnTargetDied(Unit* mTarget)
	{
		if (_unit->GetHealthPct() == 0) return;
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Told ya it was gonna sting!");
	}

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Pure luck I tell ya!...");
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
		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

	void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}



					if (spells[i].speech != "")
					{
						_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, spells[i].speech.c_str());
						_unit->PlaySoundToSet(spells[i].soundid); 
					}

					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(((val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger)) || i == 1) && t > spells[i].casttime)
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
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
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

void Setup_TheGaunlet(ScriptMgr * mgr)
{
	mgr->register_creature_script(810010, &QuirkAI::Create);
	mgr->register_creature_script(810001, &SquirtAI::Create);
	mgr->register_creature_script(810004, &PoppaCrawlAI::Create);
	mgr->register_creature_script(810007, &RedEyeAI::Create);
}
