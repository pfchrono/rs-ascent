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
 
									-- MASTER, I AM HERE TO SERVE! --
 */

#include "StdAfx.h"
#include "Setup.h"

#define RS_SECOND						1000	//(ms)
#define RS_MINUTE						60 * RS_SECOND

#define ANNOUNCE_INTERVAL_MINUTES		30

#define SETUP_INTERVAL					ANNOUNCE_INTERVAL_MINUTES * RS_MINUTE
#define MSG_TO_ANNOUNCE					"Welcome to the Rockstar Funserver. Please remember to /join world to chat with other RS players, and /join gmhelp if there is an ingame emergency. Everyone is also encouraged to use the forums (fishstik.ca) and please* Vote for RS*. Help us Grow ^_^"
#define USE_TIMED_EVENT_ANNOUNCE

class Serve
{
public:
	void Run();
	void Announce();
};

void Serve::Run()
{
	/*
	Log.Notice("RS_CodeMonkey", "---------------------------");
	Log.Notice("RS_CodeMonkey", "--RockStar Scripts Loaded--");
	Log.Notice("RS_CodeMonkey", "---------------------------");
	Log.Notice("RS_CodeMonkey", "--        Zug Zug!       --");
	Log.Notice("RS_CodeMonkey", "- CodeMonkey need cookies -");
	Log.Notice("RS_CodeMonkey", "--	   Ready for Work!    --");
	*/
}

void Serve::Announce()
{
	sWorld.SendWorldText(MSG_TO_ANNOUNCE);
}

void Servant(ScriptMgr * mgr)
{
	Serve Servant;
	TimedEvent * te = TimedEvent::Allocate(&Servant, new CallbackP0<Serve>(&Servant, &Serve::Run), 1, 6000, 1);
	sWorld.event_AddEvent(te);

#ifdef USE_TIMED_EVENT_ANNOUNCE
	Serve Announcer;
	TimedEvent * Ann = TimedEvent::Allocate(&Announcer, new CallbackP0<Serve>(&Announcer, &Serve::Announce), 1, SETUP_INTERVAL, 0);
	sWorld.event_AddEvent(Ann);
#endif
}
