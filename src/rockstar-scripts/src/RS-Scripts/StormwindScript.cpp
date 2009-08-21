/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"

/*
	 StormwindScript.cpp Script ;
	 Stormwind Bread Seller AI
 */
#define CN_THOMAS_MILLER	3518

class StormwindBreadSellerAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(StormwindBreadSellerAI);

	StormwindBreadSellerAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent(1000);	/* let's sec 1sec AIUpdate voiding frequency -- first time when server starts */
		sayText = rand() % 31 + 30;		/* 0-30 + 30 == 30-60 voids :P (so 1 void == 1 sec so! 30-60 voids == 30-60 sec
										 * :P) */
	}

	void OnSpawn()
	{
		RegisterAIUpdateEvent(1000);	/* let's sec 1sec AIUpdate voiding frequency -- everytime creature is killed
										 * and respawned */
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
		if(_unit->isAlive() && !(_unit->CombatStatus.IsInCombat())) /* we don't want mob to say anything about bread
																	 * when fighting :P */
		{
			sayText--;
			if(!sayText)
			{
				sayText = rand() % 31 + 30;

				/*~~~~~~~~~~~~~~~~~~~~*/
				int TextID = rand() % 4;
				/*~~~~~~~~~~~~~~~~~~~~*/

				switch(TextID)
				{
				case 0:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Fresh bread for sale!");
					break;

				case 1:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Freshly baked bread for sale!");
					break;

				case 2:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Rolls, buns and bread. Baked fresh!");
					break;

				case 3:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Warm, wholesome bread!");
					break;
				}
			}
		}
	}

protected:
	int sayText;	/* AIUpdate triggering count needed to check if creature will say anything. */
};

/* Stormwind Poor Guys AI */
#define CN_TOPPER_MCNABB	1402

class StormwindPoorGuyOneAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(StormwindPoorGuyOneAI);

	StormwindPoorGuyOneAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent(1000);
		sayText = rand() % 21 + 40;
	}

	void OnSpawn()
	{
		RegisterAIUpdateEvent(1000);
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
		if(_unit->isAlive() && !(_unit->CombatStatus.IsInCombat()))
		{
			sayText--;
			if(!sayText)
			{
				sayText = rand() % 21 + 40;

				/*~~~~~~~~~~~~~~~~~~~~*/
				int TextID = rand() % 6;
				/*~~~~~~~~~~~~~~~~~~~~*/

				switch(TextID)
				{
				case 0:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Alms for the poor?");
					break;

				case 1:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Could ye spare some coin?");
					break;

				case 2:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Help a poor bloke out?");
					break;

				case 3:
					_unit->SendChatMessage
						(
							CHAT_MSG_MONSTER_SAY,
							LANG_UNIVERSAL,
							"Spare some change for a poor blind man? ...What do you mean I'm not blind? ...I'M NOT BLIND! I CAN SEE!! It's a miracle!"
						);
					break;

				case 4:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Shine yer armor for a copper.");
					break;

				case 5:
					_unit->SendChatMessage
						(
							CHAT_MSG_MONSTER_SAY,
							LANG_UNIVERSAL,
							"It's all their fault, stupid Alliance army. Just had to build their towers right behind my farm."
						);
					break;
				}
			}
		}
	}

protected:
	int sayText;
};

#define CN_MORRIS_LAWRY 1405

class StormwindPoorGuyTwoAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(StormwindPoorGuyTwoAI);

	StormwindPoorGuyTwoAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent(1000);
		sayText = rand() % 21 + 40;
	}

	void OnSpawn()
	{
		RegisterAIUpdateEvent(1000);
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
		if(_unit->isAlive() && !(_unit->CombatStatus.IsInCombat()))
		{
			sayText--;
			if(!sayText)
			{
				sayText = rand() % 21 + 40;

				/*~~~~~~~~~~~~~~~~~~~~*/
				int TextID = rand() % 6;
				/*~~~~~~~~~~~~~~~~~~~~*/

				switch(TextID)
				{
				case 0:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Alms for the poor?");
					break;

				case 1:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Could ye spare some coin?");
					break;

				case 2:
					_unit->SendChatMessage
						(
							CHAT_MSG_MONSTER_SAY,
							LANG_UNIVERSAL,
							"I will gladly pay you Tuesday for a hamburger today"
						);
					break;

				case 3:
					_unit->SendChatMessage
						(
							CHAT_MSG_MONSTER_SAY,
							LANG_UNIVERSAL,
							"It's all their fault, stupid orcs. Had to burn my farm to the ground."
						);
					break;

				case 4:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Help a poor bloke out?");
					break;

				case 5:
					_unit->SendChatMessage
						(
							CHAT_MSG_MONSTER_SAY,
							LANG_UNIVERSAL,
							"Spare some change for a poor blind man? ...What do you mean I'm not blind? ...I'M NOT BLIND! I CAN SEE!! It's a miracle!"
						);
					break;
				}
			}
		}
	}

protected:
	int sayText;
};

#define CN_OL_BEASLEY	1395

class StormwindPoorGuyThreeAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(StormwindPoorGuyThreeAI);

	StormwindPoorGuyThreeAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent(1000);
		sayText = rand() % 21 + 40;
	}

	void OnSpawn()
	{
		RegisterAIUpdateEvent(1000);
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
		if(_unit->isAlive() && !(_unit->CombatStatus.IsInCombat()))
		{
			sayText--;
			if(!sayText)
			{
				sayText = rand() % 21 + 40;

				/*~~~~~~~~~~~~~~~~~~~~*/
				int TextID = rand() % 6;
				/*~~~~~~~~~~~~~~~~~~~~*/

				switch(TextID)
				{
				case 0:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Alms for the poor?");
					break;

				case 1:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Shine yer armor for a copper.");
					break;

				case 2:
					_unit->SendChatMessage
						(
							CHAT_MSG_MONSTER_SAY,
							LANG_UNIVERSAL,
							"I will gladly pay you Tuesday for a hamburger today"
						);
					break;

				case 3:
					_unit->SendChatMessage
						(
							CHAT_MSG_MONSTER_SAY,
							LANG_UNIVERSAL,
							"It's all their fault, stupid orcs. Had to burn my farm to the ground."
						);
					break;

				case 4:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Help a poor bloke out?");
					break;

				case 5:
					_unit->SendChatMessage
						(
							CHAT_MSG_MONSTER_SAY,
							LANG_UNIVERSAL,
							"Spare some change for a poor blind man? ...What do you mean I'm not blind? ...I'M NOT BLIND! I CAN SEE!! It's a miracle!"
						);
					break;
				}
			}
		}
	}

protected:
	int sayText;
};

void SetupStormwindScript(ScriptMgr *mgr)
{
	mgr->register_creature_script(CN_THOMAS_MILLER, &StormwindBreadSellerAI::Create);
	mgr->register_creature_script(CN_TOPPER_MCNABB, &StormwindPoorGuyOneAI::Create);
	mgr->register_creature_script(CN_MORRIS_LAWRY, &StormwindPoorGuyTwoAI::Create);
	mgr->register_creature_script(CN_OL_BEASLEY, &StormwindPoorGuyThreeAI::Create);
}
