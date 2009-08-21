#include "StdAfx.h"
#include "Setup.h"

/*
   EmoteScript.cpp Script ;
   Stormwind Bread Seller AI
 */
#define CN_ALDOR_MARKSMAN	19337

class UniversalEmoteAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(UniversalEmoteAI);

	UniversalEmoteAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent(1000);	/* let's sec 1sec AIUpdate voiding frequency -- first time when server starts */
		switch(pCreature->spawnid)
		{
		case 340268396:
			emoteID = EMOTE_ONESHOT_BOW;
			emoteTimerDefault = 5;
			break;

		default:
			{
				emoteID = EMOTE_ONESHOT_NONE;
				emoteID2 = EMOTE_ONESHOT_NONE;
				emoteTimerDefault = 0;
				emoteTimerDefault2 = 0;
			};
		}

		emoteTimer = emoteTimerDefault;
		emoteTimer2 = emoteTimerDefault2;
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
			emoteTimer--;
			emoteTimer2--;
			if(!emoteTimer && emoteTimer2)
			{
				_unit->Emote(emoteID);
				emoteTimer = emoteTimerDefault;
			}

			if(!emoteTimer2 && emoteTimer)
			{
				_unit->Emote(emoteID2);
				emoteTimer2 = emoteTimerDefault2;
			}

			if(!emoteTimer && !emoteTimer2)
			{
				/*~~~~~~~~~~~~~~~~~~~~~~~~*/
				int randomText = rand() % 2;
				/*~~~~~~~~~~~~~~~~~~~~~~~~*/

				switch(randomText)
				{
				case 0: _unit->Emote(emoteID); break;
				case 1: _unit->Emote(emoteID2); break;
				}

				emoteTimer = emoteTimerDefault;
				emoteTimer2 = emoteTimerDefault2;
			}
		}
	}

protected:
	int			emoteTimerDefault;	/* Timers in seconds! */
	EmoteType	emoteID;
	int			emoteTimerDefault2;
	EmoteType	emoteID2;
	int			emoteTimer;
	int			emoteTimer2;
};

void SetupEmoteScript(ScriptMgr *mgr)
{
	mgr->register_creature_script(CN_ALDOR_MARKSMAN, &UniversalEmoteAI::Create);
}
