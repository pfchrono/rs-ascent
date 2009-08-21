/********************************************************
*			Scripted for the RockStar FunServer			*
*			Egari, T0aST, Midnight,Pyro					*
*			http://www.fishstik.ca						*
*														*
*			Please do not use these scripts for			*
*			any other server than the RockStar			*
*			Funserver(http://fishstik.ca) as they		*
*			were specially scripted/modded for the		*
*			server in question.							*
********************************************************/
//Original credit goes to Aldaus,Zymeth, and Ultra Spidey for the script

#include "StdAfx.h"
#include "Setup.h"

#define ALLIANCE_HEAD 7400098
#define HORDE_HEAD 7400099
#define TOKMSG "You don't have enough heads!"

class SCRIPT_DECL Coin : public GossipScript
{
public:
	void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
	void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
	void GossipEnd(Object * pObject, Player* Plr);
	void Destroy()
	{
		delete this;
	}
};

void Coin::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
//-----------------------------
//Setup Main Categories/Items
//-----------------------------
	GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);

	Menu->AddItem(0, "Trade in Horde Heads", 1);
	Menu->AddItem(0, "Trade in Alliance Heads", 2);

	if(AutoSend)
		Menu->SendTo(Plr);
}

bool HordeTrade(uint32 ItemId, uint8 reqAmt, Player* Plr)
{
	if(Plr->GetItemInterface()->GetItemCount(HORDE_HEAD, false)>=reqAmt) 
	{
		//remove tokens
		Plr->GetItemInterface()->RemoveItemAmt(HORDE_HEAD, reqAmt);
		//add item
		Item * pItem = objmgr.CreateItem(ItemId, Plr);
		Plr->GetItemInterface()->AddItemToFreeSlot(pItem);
		return true;
	}else{
		//not enough tokens
		return false;
	}
}

bool AllianceTrade(uint32 ItemId, uint8 reqAmt, Player* Plr)
{
	if(Plr->GetItemInterface()->GetItemCount(ALLIANCE_HEAD, false)>=reqAmt) 
	{
		//remove tokens
		Plr->GetItemInterface()->RemoveItemAmt(ALLIANCE_HEAD, reqAmt);
		//add item
		Item * pItem = objmgr.CreateItem(ItemId, Plr);
		Plr->GetItemInterface()->AddItemToFreeSlot(pItem);
		return true;
	}else{
		//not enough tokens
		return false;
	}
}

void Coin::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

	GossipMenu * Menu;
	switch(IntId)
	{
		case 0: // Return to start
			GossipHello(pCreature, Plr, true);
			break;

		case 1: //Horde Menu
			//Menu->AddItem(5, "20 Heads", 26);
			//Menu->AddItem(5, "40 Heads", 27);
			Menu->AddItem(5, "80 Heads", 3);
			Menu->AddItem(5, "120 Heads", 4);
			Menu->AddItem(0, "[Back]", 99);
			break;

		case 2: //Alliance Menu
			//Menu->AddItem(5, "20 Heads", 28);
			//Menu->AddItem(5, "40 Heads", 29);
			Menu->AddItem(5, "80 Heads", 5);
			Menu->AddItem(5, "120 Heads", 6);
			Menu->AddItem(0, "[Back]", 99);
			break;

		case 3: //80 H Heads
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Bracers", 10);
			Menu->AddItem(5, "Boots", 11);
			Menu->AddItem(5, "Back", 12);
			Menu->AddItem(5, "Shirt", 13);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 4: //120 H Heads
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Bracers", 14);
			Menu->AddItem(5, "Boots", 15);
			Menu->AddItem(5, "Back", 16);
			Menu->AddItem(5, "Shirt", 17);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 5: //80 A Heads
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Bracers", 18);
			Menu->AddItem(5, "Boots", 19);
			Menu->AddItem(5, "Back", 20);
			Menu->AddItem(5, "Shirt", 21);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 6: //120 A Heads
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Bracers", 22);
			Menu->AddItem(5, "Boots", 23);
			Menu->AddItem(5, "Back", 24);
			Menu->AddItem(5, "Shirt", 25);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 10: 
			if (HordeTrade(400021, 80, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 11: 
			if (HordeTrade(400023, 80, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 12: 
			if (HordeTrade(400025, 80, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 13: 
			if (HordeTrade(400027, 80, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 14: 
			if (HordeTrade(400022, 120, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 15: 
			if (HordeTrade(400024, 120, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 16: 
			if (HordeTrade(400026, 120, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 17: 
			if (HordeTrade(400028, 120, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 18: 
			if (AllianceTrade(400021, 80, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 19: 
			if (AllianceTrade(400023, 80, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;
			
		case 20: 
			if (AllianceTrade(400025, 80, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 21: 
			if (AllianceTrade(400027, 80, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 22: 
			if (AllianceTrade(400022, 120, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 23: 
			if (AllianceTrade(400024, 120, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 24: 
			if (AllianceTrade(400026, 120, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 25: 
			if (AllianceTrade(400028, 120, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 26: //20 H Heads
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Bag", 30);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
			break;
		case 27: //40 H Heads
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Bag", 31);
			Menu->SendTo(Plr);
			break;

		case 28: //20 A Heads
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Bag", 32);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 29: //40 A Heads
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Bag", 33);
			Menu->SendTo(Plr);
			break;

		case 30: 
			if (HordeTrade(400029, 20, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 31: 
			if (HordeTrade(400030, 40, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 32: 
			if (AllianceTrade(400029, 20, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 33: 
			if (AllianceTrade(400030, 40, Plr))
			{
				Plr->BroadcastMessage("|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",pItem->ItemId,pItem->Name1);
			}
			else 
			{
				Plr->BroadcastMessage(TOKMSG);
			}
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(0, "[Back]", 1);
			Menu->SendTo(Plr);
			break;

		case 99: //main menu
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Trade in Horde Heads", 1);
			Menu->AddItem(0, "Trade in Alliance Heads", 2);
			Menu->SendTo(Plr);
			break;
	}
}

void Coin::GossipEnd(Object * pObject, Player* Plr)
{
	GossipScript::GossipEnd(pObject, Plr);
}

void SetupVendor(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new Coin();
	mgr->register_gossip_script(810000, gs);
}