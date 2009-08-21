#include "StdAfx.h"
#include "Setup.h"
#include "../../../ascent-world/WorldSession.h"
#ifdef WIN32
#pragma warning(disable : 4305) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#endif
class SCRIPT_DECL DJ :
	public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		/*~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		/*~~~~~~~~~~~~~~*/

		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 200024, Plr);
		Menu->AddItem(0, "Power of the Horde", 1);
		Menu->AddItem(0, "Brewfest Songs", 2);
		Menu->AddItem(0, "Menu Music", 4);
		Menu->AddItem(0, "Lament of the Highborne", 5);
		Menu->AddItem(0, "Darkmoon Faire", 6);
		Menu->AddItem(0, "Darnassus Day", 7);
		Menu->AddItem(0, "Exodar City", 8);
		Menu->AddItem(0, "IronForge", 9);
		Menu->AddItem(0, "Tavern Dwarf", 10);
		Menu->AddItem(0, "Page 2", 3);
		Menu->AddItem(0, "Page 3", 27);
		if(AutoSend) Menu->SendTo(Plr);
	}

	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		/*~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		/*~~~~~~~~~~~~~~*/

		switch(IntId)
		{
		case 0:
			GossipHello(pObject, Plr, true);
			break;

		case 1:
			Plr->PlaySound(11803, true);
			Plr->Gossip_Complete();
			break;

		case 2:
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 200024, Plr);
			Menu->AddItem(0, "Party Goblin", 20);
			Menu->AddItem(0, "Party Dwarfs", 19);
			Menu->AddItem(0, "Drunken Dwarves", 21);
			Menu->AddItem(0, "Drunken Goblin", 23);
			Menu->AddItem(0, "Party Goblin", 24);
			Menu->AddItem(0, "Drunk Fight", 25);
			Menu->AddItem(5, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 3:
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 200024, Plr);
			Menu->AddItem(0, "Silvermoon General Day", 11);
			Menu->AddItem(0, "Orgrimmar Day", 12);
			Menu->AddItem(0, "Ship Interior", 13);
			Menu->AddItem(0, "Ship Exterior", 14);
			Menu->AddItem(0, "Stormwind Day", 15);
			Menu->AddItem(0, "Thunder Bluff Day", 16);
			Menu->AddItem(0, "Undercity", 17);
			Menu->AddItem(0, "Tavern Pirate", 18);
			Menu->AddItem(5, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 4:					/* Burning Crusade Title Theme */
			Plr->PlaySound(10925, true);
			Plr->Gossip_Complete();
			break;

		case 5:					/* Lament Of The Highborne */
			Plr->PlaySound(10896, true);
			Plr->Gossip_Complete();
			break;

		case 6:					/* Darkmoon Faire Music */
			Plr->PlaySound(8440, true);
			Plr->Gossip_Complete();
			break;

		case 7:					/* Darnassus Day */
			Plr->PlaySound(4210, true);
			Plr->Gossip_Complete();
			break;

		case 8:					/* Exodar City */
			Plr->PlaySound(9133, true);
			Plr->Gossip_Complete();
			break;

		case 9:					/* Ironforge */
			Plr->PlaySound(4162, true);
			Plr->Gossip_Complete();
			break;

		case 10:				/* Dwarf */
			Plr->PlaySound(11806, true);
			Plr->Gossip_Complete();
			break;

		case 11:				/* Silvermoon Day */
			Plr->PlaySound(9131, true);
			Plr->Gossip_Complete();
			break;

		case 12:				/* Orgrimmar Day */
			Plr->PlaySound(4185, true);
			Plr->Gossip_Complete();
			break;

		case 13:				/* Ship Interior */
			Plr->PlaySound(4216, true);
			Plr->Gossip_Complete();
			break;

		case 14:				/* Ship Exterior */
			Plr->PlaySound(4215, true);
			Plr->Gossip_Complete();
			break;

		case 15:				/* Stormwind Day */
			Plr->PlaySound(4198, true);
			Plr->Gossip_Complete();
			break;

		case 16:				/* Thunderbluff Day */
			Plr->PlaySound(4202, true);
			Plr->Gossip_Complete();
			break;

		case 17:				/* Undercity */
			Plr->PlaySound(4163, true);
			Plr->Gossip_Complete();
			break;

		case 18:				/* Tavern Pirate */
			Plr->PlaySound(11805, true);
			Plr->Gossip_Complete();
			break;

		case 19:				/* Brewfest Dwarf */
			Plr->PlaySound(11810, true);
			Plr->Gossip_Complete();
			break;

		case 20:				/* Brewfest Goblin */
			Plr->PlaySound(11811, true);
			Plr->Gossip_Complete();
			break;

		case 21:				/* Brewfest Dwarf 2 */
			Plr->PlaySound(11812, true);
			Plr->Gossip_Complete();
			break;

		case 22:				/* Brewfest Dwarf 3 */
			Plr->PlaySound(11813, true);
			Plr->Gossip_Complete();
			break;

		case 23:				/* Brewfest Goblin 2 */
			Plr->PlaySound(11814, true);
			Plr->Gossip_Complete();
			break;

		case 24:				/* Brewfest Goblin 3 */
			Plr->PlaySound(11815, true);
			Plr->Gossip_Complete();
			break;

		case 25:				/* Brewfest Battle */
			Plr->PlaySound(11832, true);
			Plr->Gossip_Complete();
			break;

		case 26:				/* Naxxaramus Frostwyrm */
			Plr->PlaySound(8680, true);
			Plr->Gossip_Complete();
			break;

		case 28:				/* Karazhan General */
			Plr->PlaySound(12154, true);
			Plr->Gossip_Complete();
			break;

		case 29:				/* Shadowfang Keep */
			Plr->PlaySound(4221, true);
			Plr->Gossip_Complete();
			break;

		case 30:				/* Ahn'Qiraj Intro */
			Plr->PlaySound(8493, true);
			Plr->Gossip_Complete();
			break;

		case 31:				/* CoT Zone Retail */
			Plr->PlaySound(10900, true);
			Plr->Gossip_Complete();
			break;

		case 32:				/* Naxxaramus Kelthuzud */
			Plr->PlaySound(8889, true);
			Plr->Gossip_Complete();
			break;

		case 33:				/* Karazhan Malchezaar */
			Plr->PlaySound(8889, true);
			Plr->Gossip_Complete();
			break;

		case 34:				/* Black Temple Illidan Walk */
			Plr->PlaySound(11698, true);
			Plr->Gossip_Complete();
			break;

		case 27:
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 200024, Plr);
			Menu->AddItem(0, "Naxxaramus Froswyrm Lair", 26);
			Menu->AddItem(0, "Karazhan General", 28);
			Menu->AddItem(0, "Shadowfang Keep", 29);
			Menu->AddItem(0, "Ahn Qiraj Intro", 30);
			Menu->AddItem(0, "Caverns of Time Retail", 31);
			Menu->AddItem(0, "Naxxaramus Kel Thuzud", 32);
			Menu->AddItem(0, "Karazhan Malchezaar", 33);
			Menu->AddItem(0, "Black Temple Illidan Walk", 34);
			Menu->AddItem(5, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 99:
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 200024, Plr);
			Menu->AddItem(0, "Power of the Horde", 1);
			Menu->AddItem(0, "Brewfest Songs", 2);
			Menu->AddItem(0, "Menu Music", 4);
			Menu->AddItem(0, "Lament of the Highborne", 5);
			Menu->AddItem(0, "Darkmoon Faire", 6);
			Menu->AddItem(0, "Darnassus Day", 7);
			Menu->AddItem(0, "Exodar City", 8);
			Menu->AddItem(0, "IronForge", 9);
			Menu->AddItem(0, "Tavern Dwarf", 10);
			Menu->AddItem(0, "Page 2", 3);
			Menu->AddItem(0, "Page 3", 27);
			Menu->SendTo(Plr);
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

protected:
};

void SetupDJ(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipScript	*gs = ( GossipScript * ) new DJ();
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	mgr->register_gossip_script(30011, gs);
}
