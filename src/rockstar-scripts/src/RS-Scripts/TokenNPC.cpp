/*
   Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
   http://www.fishstik.ca Please do not use these scripts for any other server
   than the RockStar Funserver(http://fishstik.ca) as they were specially
   scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"
#ifdef WIN32
#pragma warning(disable : 4305) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#endif

#define REQAMT		4
#define BROKENTOKEN	500011
#define RSTOKEN		700016

class SCRIPT_DECL TokenNPC : public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		/*~~~~~~~~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		uint32		TextID = 820;
		/*~~~~~~~~~~~~~~~~~~~~~*/
		/* Hello (First) Menu. */
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);
		Menu->AddItem(5, "Exchange 4 Broken Tokens for a RockStar Token", 30);
		if(AutoSend) Menu->SendTo(Plr);
	}
	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		Creature	*pCreature = (pObject->GetTypeId() == TYPEID_UNIT) ? (( Creature * ) pObject) : NULL;
		if(pCreature == NULL) return;
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		switch(IntId)
		{
		case 0:
			{
				GossipHello(pCreature, Plr, true);
			}
			break;

		case 10:
			{
				if(Plr->GetItemInterface()->GetItemCount(BROKENTOKEN, false) >= REQAMT) 
				{
					Plr->GetItemInterface()->RemoveItemAmt(BROKENTOKEN, REQAMT);
					Item * pItem = objmgr.CreateItem(RSTOKEN, Plr);
					Plr->GetItemInterface()->AddItemToFreeSlot(pItem);
				}
				else
				{
					sChatHandler.RedSystemMessage(Plr->GetSession(), "You do not have enough Broken Tokens");
				}
				Plr->Gossip_Complete();	
			}
			break;
		}
	}
	void GossipEnd(Object *pObject, Player *Plr)
	{
		GossipScript::GossipEnd(pObject, Plr);
	}
	void Destroy()
	{
		delete this;
	}
};

void SetupTokenNPC(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipScript	*tnpc = ( GossipScript * ) new TokenNPC;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	mgr->register_gossip_script(75000, tnpc); /* Totem */
}
