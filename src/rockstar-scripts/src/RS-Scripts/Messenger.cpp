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
#include "../EAS/EasyFunctions.h"

#define ANNOUNCE_INTERVAL					300000		//X milliseconds
#define ANNOUNCE_RANGE_SQR					(200*200)	//players in range of the anouncer will hear announcement
#define ANOUNCER_ID							6248
#define MSG_TO_ANNOUNCE						"Welcome to the Rockstar Funserver. Please remember to /join world to chat with other RS players, and /join gmhelp if there is an ingame emergency. Everyone is also encouraged to use the forums (fishstik.ca) and please* Vote for RS*. Help us Grow ^_^"
#define MSG_TYPE							CHAT_MSG_WHISPER

bool IsInrangeSQ( Object *t1, Object *t2,float sq_r)
{
	if( !t1 || !t2 )
		return false;

	float distx=t1->GetPositionX()-t2->GetPositionX();
	float disty=t1->GetPositionY()-t2->GetPositionY();
	float dist = distx*distx + disty*disty; 
	return dist <= sq_r;
}


class Announcer : public CreatureAIScript
{
public:

	//constructor
    Announcer(Creature* pCreature) : CreatureAIScript(pCreature) 
	{
		RegisterAIUpdateEvent( ANNOUNCE_INTERVAL );
		_unit->SetUInt32Value( UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_2 );
	}

	//this will be called with ANNOUNCE_INTERVAL interval
	void AIUpdate()
	{
		MapMgr *mgr = _unit->GetMapMgr();
		if( mgr )
		{
			PlayerStorageMap::iterator itr;
			WorldPacket *data;
			for( itr = mgr->m_PlayerStorage.begin(); itr!=mgr->m_PlayerStorage.end();itr++)
			{
				if( itr->second //can't imagine this getting to null though :P
					&& itr->second->isAlive() 
					&& itr->second->IsInWorld()
					&& IsInrangeSQ( _unit, itr->second, ANNOUNCE_RANGE_SQR)
					)
				{
					//can have multiple message types like self wisper :D
					data = sChatHandler.FillMessageData(MSG_TYPE, LANG_UNIVERSAL, MSG_TO_ANNOUNCE, itr->second->GetGUID(), itr->second->bGMTagOn ? 4 : 0  );
					itr->second->GetSession()->SendPacket(data);
				}
			}

		}
	}

	//create an anouncer object for this creature
    static CreatureAIScript *Create(Creature * c) { return new Announcer(c); }

	//destroy the anouncer object
    void Destroy() { delete (Announcer*)this; }

private:
};

void SetupAnnouncer(ScriptMgr * mgr)
{
	//this is to register the anouncer object to our creatures
    mgr->register_creature_script(ANOUNCER_ID, CCS(Announcer));
}
