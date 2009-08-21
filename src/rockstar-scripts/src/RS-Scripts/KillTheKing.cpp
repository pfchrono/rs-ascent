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
#include "StdAfx.h"
#include "Setup.h"

class HordeKingAI :
	public CreatureAIScript
{
public:
	HordeKingAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
	}

	void OnCombatStart(Unit *mTarget)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Alliance scum, how dare you challenge me?");
	}

	void OnDied(Unit *mKiller)
	{
		/*~~~~~~~~~~~~~~~~~~*/
		char	message[1024];
		/*~~~~~~~~~~~~~~~~~~*/

		snprintf(( char * ) message, 1024, "The Horde King has fallen! Alliance wins");
		sWorld.SendWorldText(message);
	}

	void Destroy()
	{
		delete ( HordeKingAI * ) this;
	}

	static CreatureAIScript *Create(Creature *c)
	{
		return new HordeKingAI(c);
	}
};

class AllianceKingAI :
	public CreatureAIScript
{
public:
	AllianceKingAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
	}

	void OnCombatStart(Unit *mTarget)
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Foolish Horde, you cannot defeat me!");
	}

	void OnDied(Unit *mKiller)
	{
		/*~~~~~~~~~~~~~~~~~~*/
		char	message[1024];
		/*~~~~~~~~~~~~~~~~~~*/

		snprintf(( char * ) message, 1024, "The Alliance King has fallen! Horde wins");
		sWorld.SendWorldText(message);
	}

	void Destroy()
	{
		delete ( AllianceKingAI * ) this;
	}

	static CreatureAIScript *Create(Creature *c)
	{
		return new AllianceKingAI(c);
	}
};

void SetupKillTheKing(ScriptMgr *mgr)
{
	mgr->register_creature_script(500033, &HordeKingAI::Create);
	mgr->register_creature_script(500023, &AllianceKingAI::Create);
}
