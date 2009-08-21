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

class SCRIPT_DECL RaceStart_TeleportNPC :	public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend);
	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code);
	void GossipEnd(Object *pObject, Player *Plr);
	void Destroy()
	{
		delete this;
	}
};

void RaceStart_TeleportNPC::GossipHello(Object *pObject, Player *Plr, bool AutoSend)
{
	/*~~~~~~~~~~~~~~~~~~~~~*/
	GossipMenu	*Menu;
	uint32 TextID = 700136;
	/*~~~~~~~~~~~~~~~~~~~~~*/
	/* Hello (First) Menu. */
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);
	Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Yes, what options do I have?", 1);
	if(AutoSend) Menu->SendTo(Plr);
}

void RaceStart_TeleportNPC::GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipMenu	*Menu;
	Creature	*pCreature = (pObject->GetTypeId() == TYPEID_UNIT) ? (( Creature * ) pObject) : NULL;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	uint32 RaceId = 0;
	uint32 TextID = 700136;
	if(pCreature == NULL) return;
	switch(IntId)
	{
	case 1:
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID + 1, Plr);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "-[ Race Start Porter ]-", 1);
			if(Plr->GetTeam() == 0)
			{
				Menu->AddItem(GOSSIP_ICON_TAXI, "Human", 11);
				Menu->AddItem(GOSSIP_ICON_TAXI, "Dwarf", 13);
				Menu->AddItem(GOSSIP_ICON_TAXI, "Night Elf", 14);
				Menu->AddItem(GOSSIP_ICON_TAXI, "Gnome", 17);
				Menu->AddItem(GOSSIP_ICON_TAXI, "Draenei", 21);
			}
			else 
			{
				Menu->AddItem(GOSSIP_ICON_TAXI, "Orc", 12);
				Menu->AddItem(GOSSIP_ICON_TAXI, "Undead", 15);
				Menu->AddItem(GOSSIP_ICON_TAXI, "Tauren", 16);
				Menu->AddItem(GOSSIP_ICON_TAXI, "Troll", 18);
				Menu->AddItem(GOSSIP_ICON_TAXI, "Blood-Elf", 20);
			}
			Menu->SendTo(Plr);
		}break;
	}

	if( IntId != 1 )
	{
		RaceId = IntId - 10;
		uint32 mapId;
		switch( RaceId )
		{
		case 1:
			{
				mapId = 0;
				LocationVector pVEC(-8949.95, -132.493, 83.5312, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 2:
			{
				mapId = 1;
				LocationVector pVEC(-618.5185, -4251.67, 38.718, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 3:
			{
				mapId = 0;
				LocationVector pVEC(1676.35, 1677.45, 121.67, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 4:
			{
				mapId = 1;
				LocationVector pVEC(10311.3, 832.463, 1326.41, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 5:
			{
				mapId = 0;
				LocationVector pVEC(1676.35, 1677.45, 121.67, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 6:
			{
				mapId = 1;
				LocationVector pVEC(-2917.58, -257.98, 52.9968, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 7:
			{
				mapId = 0;
				LocationVector pVEC(-6237.02, 329.659, 382.703, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 8:
			{
				mapId = 1;
				LocationVector pVEC(-618.518, -4251.67, 38.718, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 10:
			{
				mapId = 530;
				LocationVector pVEC(10349.6, -6357.29, 33.4026, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		case 11:
			{
				mapId = 530;
				LocationVector pVEC(-3961.64, -13931.2, 100.615, 0);
				Plr->SafeTeleport(mapId, 0, pVEC);
			}break;
		}
		Plr->Gossip_Complete();
	}
}

void RaceStart_TeleportNPC::GossipEnd(Object *pObject, Player *Plr)
{
	GossipScript::GossipEnd(pObject, Plr);
}

class SCRIPT_DECL TeleportNPC :
	public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend);
	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code);
	void GossipEnd(Object *pObject, Player *Plr);
	void Destroy()
	{
		delete this;
	}
};

void TeleportNPC::GossipHello(Object *pObject, Player *Plr, bool AutoSend)
{
	/*~~~~~~~~~~~~~~~~~~~~~*/
	GossipMenu	*Menu;
	uint32		TextID = 820;
	/*~~~~~~~~~~~~~~~~~~~~~*/

	/* Hello (First) Menu. */
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);
	Menu->AddItem(5, "Set Bindpoint Here", 98);
	Menu->AddItem(5, "Check Your Deposit Box", 63);
	if(Plr->GetTeam() > 0)
	{
		Menu->AddItem(0, "Horde Cities", 1);
	}
	else
	{
		Menu->AddItem(0, "Alliance Cities", 2);
	}

	Menu->AddItem(0, "Neutral Outposts in Azeroth", 40);
	if(Plr->GetSession()->HasFlag(ACCOUNT_FLAG_XPACK_01))
	{
		Menu->AddItem(0, "Outland Locations", 3);
		Menu->AddItem(0, "Outland Instances", 215);
	}

	Menu->AddItem(0, "RockStar Locations", 20);
	Menu->AddItem(0, "Azeroth Instances", 200);
	if(Plr->RS_getAccess() >= RS_PROBEGM)
	{
		Menu->AddItem(0, "GameMaster Only", 80);
	}

	if(Plr->RS_getAccess() >= RS_VIP)
	{
		Menu->AddItem(0, "VIPs Only", 60);
	}

	if(AutoSend) Menu->SendTo(Plr);
}

void TeleportNPC::GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipMenu	*Menu;
	Creature	*pCreature = (pObject->GetTypeId() == TYPEID_UNIT) ? (( Creature * ) pObject) : NULL;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
			/* Horde */
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			if(Plr->GetSession()->HasFlag(ACCOUNT_FLAG_XPACK_01))
			{
				Menu->AddItem(5, "Silvermoon", 4);
			}

			Menu->AddItem(5, "Orgrimmar", 5);
			Menu->AddItem(5, "Thunderbluff", 6);
			Menu->AddItem(5, "UnderCity", 7);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
		}
		break;

	case 2:
		{
			/* Alliance */
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			if(Plr->GetSession()->HasFlag(ACCOUNT_FLAG_XPACK_01))
			{
				Menu->AddItem(5, "The Exodar", 8);
			}

			Menu->AddItem(5, "Stormwind", 9);
			Menu->AddItem(5, "Ironforge", 10);
			Menu->AddItem(5, "Darnassus", 11);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
		}
		break;

	case 3:						/* Outland */
		{
			if(Plr->getLevel() < 50)
			{
				sChatHandler.SystemMessage(Plr->GetSession(), "You do not qualify for entry to Outland. Req L50.");
				Plr->PlaySound(11466, true);
				Plr->Gossip_Complete();
			}
			else
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
				Menu->AddItem(5, "Shattrath", 19);
				Menu->AddItem(5, "Hellfire Peninsula", 12);
				Menu->AddItem(5, "Zangermarsh", 13);
				Menu->AddItem(5, "Nagrand", 14);
				Menu->AddItem(5, "Blades Edge Mountains", 15);
				Menu->AddItem(5, "Netherstorm", 16);
				Menu->AddItem(5, "Terokkar Forest", 17);
				Menu->AddItem(5, "Shadowmoon Valley", 18);
				Menu->AddItem(0, "[Back]", 99);
				Menu->SendTo(Plr);
			}
		}
		break;

	/* Horde submenu */
	case 4:						/* Silvermoon */
		{
			Plr->EventTeleport(530, 9400.486328, -7278.376953, 14.206780);
			Plr->Gossip_Complete();
		}
		break;

	case 5:						/* Orgrimmar */
		{
			Plr->EventTeleport(1, 1371.068970, -4370.801758, 26.052483);
			Plr->Gossip_Complete();
		}
		break;

	case 6:						/* ThunderBluff */
		{
			Plr->EventTeleport(1, -1304.569946, 205.285004, 68.681396);
			Plr->Gossip_Complete();
		}
		break;

	case 7:						/* UnderCity */
		{
			Plr->EventTeleport(0, 2050.203125, 285.650604, 56.994549);
			Plr->Gossip_Complete();
		}
		break;

	/* Alliance Menu */
	case 8:						/* Exodar */
		{
			Plr->EventTeleport(530, -4072.202393, -12014.337891, -1.277277);
			Plr->Gossip_Complete();
		}
		break;

	case 9:						/* Stormwind */
		{
			Plr->EventTeleport(0, -9100.480469, 406.950745, 92.594185);
			Plr->Gossip_Complete();
		}
		break;

	case 10:					/* Ironforge */
		{
			Plr->EventTeleport(0, -5028.265137, -825.976563, 495.301575);
			Plr->Gossip_Complete();
		}
		break;

	case 11:					/* Darnassus */
		{
			Plr->EventTeleport(1, 9985.907227, 1971.155640, 1326.815674);
			Plr->Gossip_Complete();
		}
		break;

	/* Outland Menu */
	case 12:					/* Hellfire Peninsula */
		{
			Plr->EventTeleport(530, -248.160004, 922.348999, 84.379799);
			Plr->Gossip_Complete();
		}
		break;

	case 13:					/* Zangermarsh */
		{
			Plr->EventTeleport(530, -225.863632, 5405.927246, 22.346397);
			Plr->Gossip_Complete();
		}
		break;

	case 14:					/* Nagrand */
		{
			Plr->EventTeleport(530, -468.232330, 8418.666016, 28.031298);
			Plr->Gossip_Complete();
		}
		break;

	case 15:					/* Blades Edge Mountains */
		{
			Plr->EventTeleport(530, 1471.672852, 6828.047852, 107.759239);
			Plr->Gossip_Complete();
		}
		break;

	case 16:					/* Netherstorm */
		{
			Plr->EventTeleport(530, 3396.123779, 4182.208008, 137.097992);
			Plr->Gossip_Complete();
		}
		break;

	case 17:					/* Terokkar Forest */
		{
			Plr->EventTeleport(530, -1202.426636, 5313.692871, 33.774723);
			Plr->Gossip_Complete();
		}
		break;

	case 18:					/* Shadowmoon Valley */
		{
			Plr->EventTeleport(530, -2859.522461, 3182.34773, 10.008426);
			Plr->Gossip_Complete();
		}
		break;

	case 19:					/* Shattrath */
		{
			Plr->EventTeleport(530, -1722.58, 5382.7, 1.47504);
			Plr->Gossip_Complete();
		}
		break;

	case 20:					/* RockStar Locations */
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "RockStar Nation", 21);
			if(Plr->GetTeam() > 0)
			{
				Menu->AddItem(5, "Horde Shopping Center", 22);
			}
			else
			{
				Menu->AddItem(5, "Alliance Shopping Center", 23);
			}
			Menu->AddItem(5, "Leveling Road", 34);
			if(Plr->IsInGuild())
								Menu->AddItem(5, "Guild Home Shopping Center", 33);

			Menu->AddItem(5, "The Maze *evil grin*", 70);
			Menu->AddItem(5, "RockStar Hall of Fame", 24);
			Menu->AddItem(5, "The Horadric Cube", 32);
			Menu->AddItem(5, "The Trade District", 35);
			Menu->AddItem(0, "RockStar Instances (L70+)", 25);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
		}
		break;

	case 21:
		{
			Plr->EventTeleport(30, 23.982540, -298.187042, 14.389221);
//			Plr->EventTeleport(1, -8522.118164, 2014.756836, 104.804131);	/* RockStar Twisting Neither */
			Plr->Gossip_Complete();
		}
		break;

	case 22:
		{
			Plr->EventTeleport(1, 7420.126953, -1580.293579, 180.401123);	/* RockStar Horde Shopping Center */
			Plr->Gossip_Complete();
		}
		break;

	case 23:
		{
			Plr->EventTeleport(0, -4637.501953, -1691.715332, 504.284424);	/* RockStar Alliance Shopping Center */
			Plr->Gossip_Complete();
		}
		break;

	case 24:
		{
			Plr->EventTeleport(0, -188.830902, 1729.001587, 90.907333);		/* RockStar Hall of Fame */
			Plr->Gossip_Complete();
		}
		break;

	case 25:
		{
			if(Plr->getLevel() < 70)
			{
				sChatHandler.RedSystemMessage
					(
						Plr->GetSession(),
						"You do not qualify for entry to the RockStar Instances. L70+"
					);
				Plr->PlaySound(11466, true);
				Plr->Gossip_Complete();
			}
			else
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
				Menu->AddItem(5, "Cove of the Demonhunters", 26);
				if(Plr->GetSession()->HasFlag(ACCOUNT_FLAG_XPACK_01))
				{
					Menu->AddItem(5, "Home of the Shadowmancers", 27);
				}

				Menu->AddItem(5, "The Corrupted", 28);
				Menu->AddItem(5, "Murloc's Cavern", 29);
				if(Plr->getLevel() >= 90  /*|| Plr->RS_getAccess() >= RS_UBERVIP*/)
				{
					Menu->AddItem(5, "FPS Area", 30);
				}
				Menu->AddItem(5, "Baal's Domain of Destruction", 31);
				Menu->AddItem(5, "Naxxramas", 209);
				Menu->AddItem(0, "[Back]", 20);
				Menu->SendTo(Plr);
			}
		}
		break;

	case 26:
		{
			Plr->EventTeleport(1, -10745, 2422.51, 7.133469);				/* Cove of the Demonhunters */
			Plr->Gossip_Complete();
		}
		break;

	case 27:
		{
			Plr->EventTeleport(530, -363.34, 3159.77, -95.95);				/* Home of the Shadowmancers */
			Plr->Gossip_Complete();
		}
		break;

	case 28:
		{
			Plr->EventTeleport(0, 1235.696411, -2596.299805, 89.968056);	/* Scholomance */
			Plr->Gossip_Complete();
		}
		break;

	case 29:
		{
			Plr->EventTeleport(1, -732.543945, -2221.730225, 19.016033);	/* Wailing Caverns */
			Plr->Gossip_Complete();
		}
		break;

	case 30:
		{
			Plr->EventTeleport(269, -1539, 7106.5, 32.2);					/* FPS Area */
			Plr->Gossip_Complete();
		}
		break;

	case 31:
		{
			Plr->EventTeleport(1, 1802.9, -4398.7, -18.3);					/* Baal's Domain of Destruction */
			Plr->Gossip_Complete();
		}
		break;

	case 32:
		{
			Plr->EventTeleport(37, -618.95, -283.428, 353);					/* Horadric Cube */
			Plr->Gossip_Complete();
		}
		break;

	case 33:
		{
			Plr->EventTeleport(1, -8392.49, -4268.76, 18.9916);
			Plr->Gossip_Complete();
		}
		break;

	case 34:
		{
			Plr->EventTeleport(1, 4614.97, -3855.93, 944.121);
			Plr->Gossip_Complete();
		}
		break;

	case 35:
		{
			Plr->EventTeleport(37, -20.91, 959.62, 348.45);
			Plr->Gossip_Complete();
		}
		break;

	case 40:
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Booty Bay", 41);
			Menu->AddItem(5, "Cenarion Hold", 42);
			Menu->AddItem(5, "Gadgetzan", 43);
			Menu->AddItem(5, "Light's Hope Chapel", 44);
			Menu->AddItem(5, "Everlook", 45);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
		}
		break;

	case 41:
		{
			Plr->EventTeleport(0, -14406.600000, 419.353000, 22.390700);	/* BB */
			Plr->Gossip_Complete();
		}
		break;

	case 42:
		{
			Plr->EventTeleport(1, -6831.205078, 762.235291, 43.255608);		/* CenarionHold */
			Plr->Gossip_Complete();
		}
		break;

	case 43:
		{
			Plr->EventTeleport(1, -7124.131836, -3818.932129, 8.410748);	/* Gadget */
			Plr->Gossip_Complete();
		}
		break;

	case 44:
		{
			Plr->EventTeleport(0, 2278.364258, -5311.157227, 87.200989);	/* LHC */
			Plr->Gossip_Complete();
		}
		break;

	case 45:
		{
			Plr->EventTeleport(1, 6721.44, -4659.09, 720.893);				/* Everlook */
			Plr->Gossip_Complete();
		}
		break;

	case 50:	/* Working Items */
		{
			if(Plr->RS_getAccess() == RS_ADMIN)
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
				Menu->AddItem(0, "[Back]", 80);
				Menu->SendTo(Plr);
			}
			else
			{
				Plr->PlaySound(11466, true);
				Plr->Gossip_Complete();
			}
		}
		break;

	case 60:
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			if(Plr->RS_getAccess() >= RS_VIP)
			{
				Menu->AddItem(5, "Teleport to VIP City", 62);
			}

			Menu->AddItem(0, "[Back]", 99);
			if(Plr->RS_getAccess() >= RS_UBERVIP)
			{
				Menu->AddItem(5, "Learn VIP Skill", 61);
				if(pCreature->HasItems())
										Menu->AddItem(5, "What do you have for me?", 64);
			}

			Menu->SendTo(Plr);
		}
		break;

	case 61:	/* Add Internal skill for VIPs. */
		{
			if(Plr->_HasSkillLine(769))
			{
				Plr->_RemoveSkillLine(769);
			}

			Plr->_AddSkillLine(769, 1, 1);
			sChatHandler.SystemMessage
				(
					Plr->GetSession(),
					"Skill added to character, you should now be able to wear custom VIP Equipment"
				);
			Plr->Gossip_Complete();
		}
		break;

	case 62:	/* Teleport to VIP City */
		{
			/*
				 Plr->EventTeleport(1, 4829, -1965, 1074.566528);
				 //OLD VIP CITY
			 */
			Plr->SafeTeleport(1, 0, -3700.92, 817.024, 110.16, 0);	/* NEW VIP CITY */
			Plr->Gossip_Complete();
		}
		break;

	case 63:	/* banker */
		{
			Plr->GetSession()->SendBankerList(pCreature);
		}break;
	case 64:
		{
			Plr->GetSession()->SendInventoryList(pCreature);
		}break;

	case 70:	/* Maze *evil grin* */
		{
			Plr->EventTeleport(0, -895.799988, 1564.099976, 42.820267);
		}
		break;

	case 80:	/* GM Locations */
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "GM Island", 81);
			Menu->AddItem(5, "Programmers Isle", 82);
			Menu->AddItem(5, "Horde Shopping Center", 22);
			Menu->AddItem(5, "Alliance Shopping Center", 23);
			Menu->AddItem(5, "Emerald Forest", 83);
			Menu->AddItem(0, "[Back]", 99);
			Menu->AddItem(5, "Add GM Internal", 84);
			Menu->SendTo(Plr);
		}
		break;

	case 81:	/* GM Island */
		{
			Plr->EventTeleport(1, 16222.100000, 16252.100000, 12.587200);
			Plr->Gossip_Complete();
		}
		break;

	case 82:	/* Programmers Isle */
		{
			Plr->EventTeleport(451, 16304.200000, 16318.100000, 69.440000);
			Plr->Gossip_Complete();
		}
		break;

	case 83:	/* Emerald Forest */
		{
			Plr->EventTeleport(169, 2732.930000, -3319.630000, 101.284000);
			Plr->Gossip_Complete();
		}
		break;

	case 84:	/* Add Internal skill for GMs. */
		{
			if(Plr->_HasSkillLine(769))
			{
				Plr->_RemoveSkillLine(769);
			}

			Plr->_AddSkillLine(769, 500, 500);
			sChatHandler.SystemMessage
				(
					Plr->GetSession(),
					"Skill added to character, you should now be able to wear custom GM Equipment"
				);
			Plr->Gossip_Complete();
		}
		break;

	case 98:	/* BINDER */
		{
			Plr->GetSession()->SendInnkeeperBind(pCreature);
		}
		break;

	case 200:	/* Azeroth Instances */
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Shadowfang Keep", 201);
			Menu->AddItem(5, "Scarlet Monastery", 202);
			Menu->AddItem(5, "Zul'Farrak", 203);
			Menu->AddItem(5, "Stratholme", 211);
			Menu->AddItem(5, "Scholomance", 210);
			Menu->AddItem(5, "Blackrock Spire", 212);
			Menu->AddItem(5, "Onyxia's Lair", 208);
			Menu->AddItem(5, "Molten Core", 207);
			Menu->AddItem(5, "Zul'Gurub", 204);
			Menu->AddItem(5, "Karazhan", 213);
			Menu->AddItem(5, "Ahn'Qirai 20", 205);
			Menu->AddItem(5, "Ahn'Qirai 40", 206);
			Menu->AddItem(5, "Caverns of Times", 214);
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
		}
		break;

	case 201:	/* Shadowfang Keep */
		{
			Plr->EventTeleport(0, -247.038574, 1532.205444, 77.415085); /* 0 130 -247.038574 1532.205444 77.415085
																		 * 1.200086 */
			Plr->Gossip_Complete();
		}
		break;

	case 202:	/* Scarlet Monastery */
		{
			Plr->EventTeleport(0, 2868.383301, -754.688965, 160.333069);
			Plr->Gossip_Complete();
		}
		break;

	case 203:	/* Zul'Farrak */
		{
			Plr->EventTeleport(1, -6813.025879, -2888.890625, 8.899631);
			Plr->Gossip_Complete();
		}
		break;

	case 204:	/* Zul'Gurub */
		{
			Plr->EventTeleport(0, -11919.266602, -837.796875, 29.111784);
			Plr->Gossip_Complete();
		}
		break;

	case 205:	/* Ahn'Qirai 20 */
		{
			Plr->EventTeleport(1, -8418.5000, 1505.939941, 31.823200);
			Plr->Gossip_Complete();
		}
		break;

	case 206:	/* Ahn'Qirai 40 */
		{
			Plr->EventTeleport(1, -8238.570313, 1992.060059, 129.072006);
			Plr->Gossip_Complete();
		}
		break;

	case 207:	/* Molten Core */
		{
			Plr->EventTeleport(230, 1163.346313, -414.418610, -94.746201);
			Plr->Gossip_Complete();
		}
		break;

	case 208:	/* Onyxia */
		{
			Plr->EventTeleport(1, -4732.371582, -3744.167480, 55.414684);
			Plr->Gossip_Complete();
		}
		break;

	case 209:	/* Naxxramas */
		{
			Plr->EventTeleport(533, 3006.06, -3436.72, 293.891);
			Plr->Gossip_Complete();
		}
		break;

	case 210:	/* Scholomance */
		{
			Plr->EventTeleport(0, 1264.198853, -2559.014648, 94.128304);
			Plr->Gossip_Complete();
		}
		break;

	case 211:	/* Stratholme */
		{
			Plr->EventTeleport(0, 3359.447021, -3378.766846, 144.782501);
			Plr->Gossip_Complete();
		}
		break;

	case 212:	/* Black Rock Spire */
		{
			Plr->EventTeleport(0, -7527.129883, -1224.997437, 285.733002);
			Plr->Gossip_Complete();
		}
		break;

	case 213:	/* Karazan */
		{
			Plr->EventTeleport(0, -11122.913086, -2014.498779, 47.079350);
			Plr->Gossip_Complete();
		}
		break;

	case 214:	/* Caverns of Times */
		{
			Plr->EventTeleport(1, -8478.153320, -4304.361816, -208.442352);
			Plr->Gossip_Complete();
		}
		break;

	case 215:	/* Outland Instances */
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);

			/*
				 Menu->AddItem(5, "Hellfire Ramparts", 216);
			 */
			Menu->AddItem(5, "The Blood Furnace", 217);
			Menu->AddItem(5, "The Shattered Halls", 218);
			Menu->AddItem(5, "The Underbog", 219);
			Menu->AddItem(5, "The Slave Pens", 220);
			Menu->AddItem(5, "The Steamvault", 221);
			Menu->AddItem(5, "Mana-Tombs", 222);
			Menu->AddItem(5, "Auchenai Crypts", 223);
			Menu->AddItem(5, "Sethekk Halls", 224);
			Menu->AddItem(5, "Shadow Labyrinth", 225);

			/*
				 Menu->AddItem(5, "The Mechanar", 226);
				 Menu->AddItem(5, "The Botanica", 227);
				 Menu->AddItem(5, "The Arcatraz", 228);
			 */
			Menu->AddItem(0, "[Back]", 99);
			Menu->SendTo(Plr);
		}
		break;

	case 216:	/* Hellfire Ramparts */
		{
			Plr->EventTeleport(530, -360.670990, 3071.899902, -15.097700);
		}
		break;

	case 217:	/* The Blood Furnace */
		{
			Plr->EventTeleport(530, -303.506012, 3164.820068, 31.742500);
		}
		break;

	case 218:	/* The Shattered Halls */
		{
			Plr->EventTeleport(530, -311.083527, 3083.291748, -3.745923);
		}
		break;

	case 219:	/* The Underbog */
		{
			Plr->EventTeleport(530, 777.088989, 6763.450195, -72.062561);
		}
		break;

	case 220:	/* The Slave Pens */
		{
			Plr->EventTeleport(530, 719.507996, 6999.339844, -73.074303);
		}
		break;

	case 221:	/* The Steamvault */
		{
			Plr->EventTeleport(530, 816.590027, 6934.669922, -80.544601);
		}
		break;

	case 222:	/* Mana-Tombs */
		{
			Plr->EventTeleport(530, -3079.810059, 4943.040039, -101.046997);
		}
		break;

	case 223:	/* Auchenai Crypts */
		{
			Plr->EventTeleport(530, -3361.959961, 5225.770020, -101.047997);
		}
		break;

	case 224:	/* Sethekk Halls */
		{
			Plr->EventTeleport(530, -3362.219971, 4660.410156, -101.049004);
		}
		break;

	case 225:	/* Shadow Labyrinth */
		{
			Plr->EventTeleport(530, -3645.060059, 4943.620117, -101.047997);
		}
		break;

	/*
		 case 226: // The Mechanar { Plr->EventTeleport(530, 2862.409912, 1546.089966, 252.158691);
		 }break;
		 case 227: // The Botanica { Plr->EventTeleport(530, 3413.649902, 1483.319946, 182.837997);
		 }break;
		 case 228: // The Arcatraz { Plr->EventTeleport(530, 3311.598145, 1332.745117, 505.557251);
		 }break;
	 */
	case 99:	/* main menu */
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Set Bindpoint Here", 98);
			Menu->AddItem(5, "Check Your Deposit Box", 63);
			if(Plr->GetTeam() > 0)
			{
				Menu->AddItem(0, "Horde Cities", 1);
			}
			else
			{
				Menu->AddItem(0, "Alliance Cities", 2);
			}

			Menu->AddItem(0, "Neutral Outposts in Azeroth", 40);
			Menu->AddItem(0, "RockStar Locations", 20);
			Menu->AddItem(0, "Azeroth Instances", 200);
			if( Plr->GetSession()->HasFlag(ACCOUNT_FLAG_XPACK_01) )
			{
				Menu->AddItem(0, "Outland Locations", 3);
				Menu->AddItem(0, "Outland Instances", 215);
			}

			if( Plr->RS_getAccess() >= RS_PROBEGM )
			{
				Menu->AddItem(0, "GameMaster Only", 80);
			}

			if( Plr->RS_getAccess() >= RS_VIP )
			{
				Menu->AddItem(0, "VIPs Only", 60);
			}

			Menu->SendTo(Plr);
		}
		break;
	}
}

void TeleportNPC::GossipEnd(Object *pObject, Player *Plr)
{
	GossipScript::GossipEnd(pObject, Plr);
}

void SetupCustom_Teleporters(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipScript	*gs;
	gs = ( GossipScript * ) new TeleportNPC();
	mgr->register_gossip_script(75000, gs);
	gs = ( GossipScript * ) new RaceStart_TeleportNPC();
	mgr->register_gossip_script(75002, gs);
}
