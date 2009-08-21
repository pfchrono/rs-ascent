/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
*/

#include "StdAfx.h"
#include "Setup.h"
#include "../EAS/EasyFunctions.h"

class SCRIPT_DECL Thunderheart : public GossipScript
{
public:
	void GossipHello( Object * pObject, Player* Plr, bool AutoSend )
	{
		GossipMenu *Menu;

		objmgr.CreateGossipMenuForPlayer( &Menu, pObject->GetGUID(), 25002, Plr );
		
		if ( !Plr->HasFinishedQuest(23) )
		{
			Menu->AddItem(0, "What can you tell me about the bear - Ursangous?", 1);
		}
		
		if ( !Plr->HasFinishedQuest(24) )
		{
			Menu->AddItem(0, "What can you tell me about the nightsaber cat - Shadumbra?", 2);
		}
		
		if ( !Plr->HasFinishedQuest(2) )
		{
			Menu->AddItem(0, "What can you tell me about the hippogryph - Sharptalon?", 3);
		}
				
		if( AutoSend )
			Menu->SendTo( Plr );
	}

	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		GossipMenu	*Menu;
		Creature	*pCreature = (pObject->GetTypeId() == TYPEID_UNIT) ? (( Creature * ) pObject) : NULL;
		
		if(pCreature == NULL) return;

		switch(IntId)
		{
		case 0:
			{
				GossipHello(pCreature, Plr, true);
			}
			break;
		
		case 1:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 25003, Plr);
				Menu->SendTo(Plr);
			}
			
		case 2:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 25004, Plr);
				Menu->SendTo(Plr);
			}
			
		case 3:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 25005, Plr);
				Menu->SendTo(Plr);
			}

		}
	}

	void GossipEnd( Object *pObject, Player *Plr )
	{
		GossipScript::GossipEnd( pObject, Plr );
	}

	void Destroy()
	{
		delete this;
	}
};

void SetupAshenvale( ScriptMgr *mgr )
{
	mgr->register_gossip_script( 12696, CREATE_GOSSIPSCRIPT( Thunderheart ) );
}
