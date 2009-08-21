//========================
//	Plastic Surgeon Kit
//		Made by Spidey
//------------------------
//	For more fun scripts
//	 visit AspireDev.org
//========================

#include "StdAfx.h"
#include "Setup.h"

#define SURGEONKIT 99005

#ifdef WIN32
#pragma warning(disable:4305)				// warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

class SCRIPT_DECL Surgeon : public GossipScript
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

void Surgeon::GossipHello(Object* pObject, Player * Plr, bool AutoSend)
{
	GossipMenu * Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 99005, Plr);
	Menu->AddItem(1, "Usable only once! Effect is reversible only if you buy another kit");
	Menu->AddItem(0, "Change Gender", 1);
	Menu->AddItem(0, "Change Race", 2);
	Menu->AddItem(1, "I've changed my mind", 100);
	if(AutoSend)
		Menu->SendTo(Plr);
};

void Surgeon::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	GossipMenu * Menu;
	switch(IntId)
	{
		case 0:
		{
			GossipHello(pObject, Plr, true);
		}break;
		case 1:
			{	 
				string MALE = "Male";
				string FEMALE = "Female";
				//0 = Male, 1 = Female
				char msg[128];
				sprintf(msg, "Change my gender to %s!", (Plr->getGender()? MALE.c_str():FEMALE.c_str()));
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 99005, Plr);
				Menu->AddItem(0, msg, 3);
				Menu->SendTo(Plr);
			}break;
		case 2:
			{
				uint8 pr = Plr->getRace();
				uint32 pf = Plr->GetTeam();
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 99005, Plr);
				if(pf == 1 && pr != RACE_BLOODELF)
					Menu->AddItem(0, "Blood Elf", 110);
				if(pf == 0 && pr != RACE_DRAENEI)
					Menu->AddItem(0, "Draenei", 111);
				if(pf == 0 && pr != RACE_DWARF)
					Menu->AddItem(0, "Dwarf", 103);
				if(pf == 0 && pr != RACE_GNOME)
					Menu->AddItem(0, "Gnome", 107);
				if(pf == 0 && pr != RACE_HUMAN)
					Menu->AddItem(0, "Human", 101);
				if(pf == 0 && pr != RACE_NIGHTELF)
					Menu->AddItem(0, "Night Elf", 104);
				if(pf == 1 && pr != RACE_ORC )
					Menu->AddItem(0, "Orc", 102);
				if(pf == 1 && pr != RACE_TAUREN)
					Menu->AddItem(0, "Tauren", 106);
				if(pf == 1 && pr != RACE_TROLL)
					Menu->AddItem(0, "Troll", 108);
				if(pf == 1 && pr != RACE_UNDEAD)
					Menu->AddItem(0, "Undead", 105);
				Menu->SendTo(Plr);
			}break;
		case 3:
			{
				//0 = Male, 1 = Female
				Plr->setGender(Plr->getGender() ? 0 : 1);
				Plr->GetItemInterface()->RemoveItemAmt(SURGEONKIT, 1);
				Plr->BroadcastMessage("Sex changed! Relog to see the effect!");
				Plr->Gossip_Complete();
			}break;
		case 100:
			{
				Plr->Gossip_Complete();
			}break;

		default:
		{
			Plr->setRace((uint8)(IntId - 100));
			Plr->GetItemInterface()->RemoveItemAmt(SURGEONKIT, 1);
			Plr->Gossip_Complete();
			Plr->BroadcastMessage("Race change complete. Relog to see the effect.");
		}break;

	}
};

void Surgeon::GossipEnd(Object * pObject, Player* Plr)
{
	GossipScript::GossipEnd(pObject, Plr);
}

void SetupSurgeon(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new Surgeon();
	mgr->register_item_gossip_script(SURGEONKIT, gs);
}