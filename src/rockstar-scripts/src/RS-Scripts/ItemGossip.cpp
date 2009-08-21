/*

	~~ Scripted for the RockStar FunServer ~~
		-- Egari, T0aST, Midnight, Pyro --
	http://www.fishstik.ca Please do not use these scripts for any other server
	than the RockStar Funserver(http://fishstik.ca) as they were specially
	scripted/modded for the server in question

 */
#include "StdAfx.h"
#include "Setup.h"
#include "../../src/ascent-world/ScriptMgr.h"
#ifdef WIN32
#pragma warning(disable : 4305) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#endif
class SCRIPT_DECL GuildPortItem :
	public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		if(Plr && Plr->CombatStatus.IsInCombat())
		{
			Plr->BroadcastMessage("You are in combat!");
		}

		if( !Plr->IsInWorld() || !Plr->GetSession() ) 
			return;

		if(!Plr->CombatStatus.IsInCombat() && Plr->GetGuildId() > 0)
		{
			sChatHandler.GreenSystemMessage
				(
					Plr->GetSession(),
					"You feel your fingers tingle as you touch the warm runed stone."
				);

			/*~~~~~~~~~~~~~~*/
			GossipMenu	*Menu;
			/*~~~~~~~~~~~~~~*/

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Go to your Guild location.", 75);
			if(AutoSend) Menu->SendTo(Plr);
		}

		if(!(Plr->GetGuildId() > 0))
		{
			sChatHandler.BlueSystemMessage
				(
					Plr->GetSession(),
					"You touch the stone but it feels cold and nothing happens."
				);
		}
	}

	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		switch(IntId)
		{
		case 75:
			{
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				uint32				PlayerGUILD = Plr->GetGuildId();
				std::stringstream	my_sql;
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				my_sql << "SELECT * FROM guildlocations WHERE `GuildID` = '" << PlayerGUILD << "'";

				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				QueryResult *result = WorldDatabase.Query(my_sql.str().c_str());
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				if(result)
				{
					do
					{
						/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
						Field			*fields = result->Fetch();
						uint32			locmap = fields[1].GetUInt32();
						float			x = fields[2].GetFloat();
						float			y = fields[3].GetFloat();
						float			z = fields[4].GetFloat();
						float			o = fields[5].GetFloat();
						LocationVector	LocVEC(x, y, z, o);
						/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

						Plr->SafeTeleport(locmap, 0, LocVEC);
						Log.Notice
							(
								"GuildLoc",
								"Teleporting player %s(%u) to Home of Guild %s(%u)",
								Plr->GetName(),
								Plr->GetLowGUID(),
								Plr->GetGuild()->GetGuildName(),
								Plr->GetGuildId()
							);
						Plr->Gossip_Complete();
					} while(result->NextRow());
					WorldDatabase.FreeQueryResult( result );
				}
				else
				{
					sChatHandler.RedSystemMessage
						(
							Plr->GetSession(),
							"The stone starts emitting a red glow [No location found]."
						);
					Plr->Gossip_Complete();
				}
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

class SCRIPT_DECL BScrollOfTele :
	public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		if(Plr->CombatStatus.IsInCombat())
		{
			Plr->BroadcastMessage("You are in combat!");
		}
		if(!Plr->CombatStatus.IsInCombat())
		{
			/*~~~~~~~~~~~~~~*/
			GossipMenu	*Menu;
			/*~~~~~~~~~~~~~~*/

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Try to read the spell written on the scroll...", 25);
			if(AutoSend) Menu->SendTo(Plr);
		}
	}

	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32				PlrGUID = Plr->GetLowGUID();
		Item				*pItem = (pObject->GetTypeId() == TYPEID_ITEM) ? (( Item * ) pObject) : NULL;
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		QueryResult *result = WorldDatabase.Query("SELECT * FROM saved_scroll_locations WHERE `playerGuid` = '%u'", PlrGUID);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		switch(IntId)
		{
		case 25:
			{
				/*~~~~~~~~~~~~~~*/
				GossipMenu	*Menu;
				/*~~~~~~~~~~~~~~*/
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TRAINER, "[Blessed Scroll of Teleport]", 25);
				Menu->AddItem(GOSSIP_ICON_TRAINER, "- Allows you to bookmark a location and return there later.", 25);
				if( result )
				{
					Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Return to your soulbound location.", 60);
					WorldDatabase.FreeQueryResult( result );
				}

				if( Plr->GetMapMgr()->GetMapId() == 530 || Plr->GetMapMgr()->GetMapId() == 0 || Plr->GetMapMgr()->GetMapId() == 1 )
					Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Bind your soul to this location.", 50);
				else
					Menu->AddItem(GOSSIP_ICON_INNKEEPER, "You cannot bind your soul to this location.");

				Menu->SendTo(Plr);
			}
			break;

		case 50:
			{
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				uint32	mapID = Plr->GetMapId();
				float	X = Plr->GetPositionX();
				float	Y = Plr->GetPositionY();
				float	Z = Plr->GetPositionZ();
				float	O = Plr->GetOrientation();
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if( result )
				{
					WorldDatabase.Execute("UPDATE saved_scroll_locations SET `mapID` = '%u', `x` = '%f', `y` = '%f', `z` = '%f', `o` = '%f' WHERE `playerGuid` = '%u'", mapID, X, Y, Z, O, PlrGUID);
					WorldDatabase.FreeQueryResult( result );
				}
				else
				{
					WorldDatabase.Execute("INSERT INTO saved_scroll_locations VALUES ('%u', '%u', '%f', '%f', '%f', '%f')", PlrGUID, mapID, X, Y, Z, O);
				}
				sChatHandler.SystemMessage(Plr->GetSession(), "Your soul has been bound to this location");
				Plr->Gossip_Complete();
			}
			break;

		case 60:
			{
				if( result )
				{
					do
					{
						/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
						Field			*fields = result->Fetch();
						uint32			mapID = fields[1].GetUInt32();
						float			X = fields[2].GetFloat();
						float			Y = fields[3].GetFloat();
						float			Z = fields[4].GetFloat();
						float			O = fields[5].GetFloat();
						LocationVector	LocVEC(X, Y, Z, O);
						/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
						Plr->SafeTeleport(mapID, 0, LocVEC);
						Plr->Gossip_Complete();
					} while(result->NextRow());
					WorldDatabase.FreeQueryResult( result );
				}
				else
				{
					/* This should never happen! */
					Log.Error
						(
							"GossipItems",
							"Returning to a soulbound location for %u which is non-existant. Line: 174", 
							PlrGUID
						);
				}

				if( pItem )
					Plr->GetItemInterface()->RemoveItemAmt(pItem->GetEntry(), 1);
				else
					Log.Error("GossipItems", "pItem is NULL! Check line 182!");

				Plr->Gossip_Complete();
			}
			break;

		default:
			GossipHello(pObject, Plr, true);
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

class SCRIPT_DECL Totem :
	public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		WorldSession * pSession = Plr->GetSession();
		if(Plr->CombatStatus.IsInCombat())
		{
			Plr->BroadcastMessage( "You are in combat!" );
		}
		else
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			uint8		race = Plr->getRace();
			GossipMenu	*Menu;
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[+]Portable RockStar Totem[+]", 99);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Remove Resurrection Sickness [250G]", 40);
			if
			(
				race == RACE_HUMAN
			||	race == RACE_DWARF
			||	race == RACE_NIGHTELF
			||	race == RACE_GNOME
			||	race == RACE_DRAENEI
			)
			{
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Stormwind", 50);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Ironforge", 51);
				if(pSession->HasFlag(ACCOUNT_FLAG_XPACK_01))
				{
					Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Exodar", 52);
				}

				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Darnassus", 53);
			}
			else
			{
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Orgrimar", 54);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Thunder Bluff", 55);
				if(pSession->HasFlag(ACCOUNT_FLAG_XPACK_01))
				{
					Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Silvermoon City", 56);
				}

				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Undercity", 57);
			}

			if(Plr->getLevel() >= 51)
			{
				if(pSession->HasFlag(ACCOUNT_FLAG_XPACK_01))
				{
					Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Shattrath", 58);
				}
			}

			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "RockStar Nation", 59);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "HearthStone", 60);
			if( Plr->RS_getAccess() >= RS_VIP )
			{
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "VIP Only Menu", 80);
			}

			if(AutoSend) Menu->SendTo(Plr);
		}
	}

	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		WorldSession * pSession = Plr->GetSession();
		/*~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		/*~~~~~~~~~~~~~~*/

		switch(IntId)
		{
		case 40:
			{
				if( !Plr->HasAura( 15007 ) )
				{
					sChatHandler.BlueSystemMessage(pSession, "You do not have Resurrection Sickness");
				}
				else
				{
					uint32 price = 250;
					uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
					uint32 priceincopper = price * 10000;
					int32 newgold = currentgold - priceincopper; 
					if( currentgold >= priceincopper )
					{ 
						Plr->RemoveAura( 15007 );
						Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, newgold);
						sChatHandler.GreenSystemMessage(pSession, "[+] Resurrection Sickness removed!");
					}
					else
					{
						sChatHandler.RedSystemMessage(pSession, "[-] You do not have enough gold!");
					}
				}
				Plr->Gossip_Complete();
			}
			break;
		case 50:
			{					/* Stormwind */
				Plr->SafeTeleport(0, 0, -8831.61, 622.666, 93.7787, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 51:
			{					/* Ironforge */
				Plr->SafeTeleport(0, 0, -4804.45, -1101.14, 498.807, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 52:
			{					/* Exodar */
				Plr->SafeTeleport(530, 0, -3796.24, -11710.9, -105.45, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 53:
			{					/* Darnassus */
				Plr->SafeTeleport(1, 0, 9952.07, 2278.46, 1341.39, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 54:
			{					/* Orgrimmar */
				Plr->SafeTeleport(1, 0, 1499.55, -4406.91, 23.1642, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 55:
			{					/* Thunder Bluff */
				Plr->SafeTeleport(1, 0, -1195.88, -56.5582, 160.034, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 56:
			{					/* Silvermoon City */
				Plr->SafeTeleport(530, 0, 9492.45, -7279.12, 14.3036, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 57:
			{					/* Undercity */
				Plr->SafeTeleport(0, 0, 1615.1, 239.786, -62.0774, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 58:
			{					/* Shattrath */
				Plr->SafeTeleport(530, 0, -1852, 5432, -10, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 59:
			{
				// Plr->SafeTeleport(1, 0, -8531.095703, 2011.018555, 101.049828, 0); /* RockStar Twisting Neither */
				Plr->SafeTeleport(30, 0, 23.982540, -298.187042, 14.389221, 0); /* RockStar Nation */
				Plr->Gossip_Complete();
			}
			break;

		case 60:
			{
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				/* HEARTHSTONE */
				LocationVector	LOC(Plr->GetBindPositionX(), Plr->GetBindPositionY(), Plr->GetBindPositionZ());
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				Plr->SafeTeleport(Plr->GetBindMapId(), 0, LOC);
				Plr->Gossip_Complete();
			}
			break;

		case 80:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				if( Plr->RS_getAccess() >= RS_UBERVIP )
				{
					Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Learn VIP Skill", 81);
				}

				if( Plr->RS_getAccess() >= RS_VIP )
				{
					Menu->AddItem(GOSSIP_ICON_INNKEEPER, "Teleport to VIP City", 82);
				}

				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[Exit]", 99);
				Menu->SendTo(Plr);
			}
			break;

		case 81:
			{					/* Add Internal skill for VIPs. */
				if(Plr->_HasSkillLine(769))
				{
					Plr->_RemoveSkillLine(769);
				}
				Plr->_AddSkillLine(769, 1, 1);
				sChatHandler.SystemMessage
					(
						pSession,
						"Skill added to character, you should now be able to wear custom VIP Equipment"
					);
				Plr->Gossip_Complete();
			}
			break;

		case 82:
			{					/* Teleport to (NEW) VIP City */
				Plr->SafeTeleport(1, 0, -3700.92, 817.024, 110.16, 0);
				Plr->Gossip_Complete();
			}
			break;

		case 99:
			{					/* Exit Menu */
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

class SCRIPT_DECL PortableDJ :
	public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		/*~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		/*~~~~~~~~~~~~~~*/

		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 200024, Plr);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Power of the Horde", 1);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Brewfest Songs", 2);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Menu Music", 4);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Lament of the Highborne", 5);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Darkmoon Faire", 6);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Darnassus Day", 7);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Exodar City", 8);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "IronForge", 9);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Tavern Dwarf", 10);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Page 2", 3);
		Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Page 3", 27);
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
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Party Goblin", 20);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Party Dwarfs", 19);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Drunken Dwarves", 21);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Drunken Goblin", 23);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Party Goblin", 24);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Drunk Fight", 25);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 3:
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 200024, Plr);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Silvermoon General Day", 11);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Orgrimmar Day", 12);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Ship Interior", 13);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Ship Exterior", 14);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Stormwind Day", 15);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Thunder Bluff Day", 16);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Undercity", 17);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Tavern Pirate", 18);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[Back]", 99);
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
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Naxxaramus Froswyrm Lair", 26);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Karazhan General", 28);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Shadowfang Keep", 29);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Ahn Qiraj Intro", 30);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Caverns of Time Retail", 31);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Naxxaramus Kel Thuzud", 32);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Karazhan Malchezaar", 33);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Black Temple Illidan Walk", 34);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[Back]", 99);
			Menu->SendTo(Plr);
			break;

		case 99:
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 200024, Plr);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Power of the Horde", 1);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Brewfest Songs", 2);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Menu Music", 4);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Lament of the Highborne", 5);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Darkmoon Faire", 6);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Darnassus Day", 7);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Exodar City", 8);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "IronForge", 9);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Tavern Dwarf", 10);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Page 2", 3);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "Page 3", 27);
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

class SCRIPT_DECL Item_BUFFR :	public GossipScript
{
protected:
	bool MoneyCost(Player * Plr, uint32 GoldAmount)
	{
		uint32 CurrentMoney = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
		uint32 PriceInCopper = GoldAmount * 10000;
		int32 newgold = CurrentMoney - PriceInCopper; 
		sChatHandler.SystemMessage(Plr->GetSession(), "[*] This item costs %u !", GoldAmount);
		if( CurrentMoney >= PriceInCopper && CurrentMoney > 1 )
		{ 
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, newgold);
			sChatHandler.GreenSystemMessage(Plr->GetSession(), "[+] Success!");
			return true;
		}
		else
		{
			sChatHandler.RedSystemMessage(Plr->GetSession(), "[-] You do not have enough gold!");
			return false;
		}
	}
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		Item * pItem = (pObject->GetTypeId()==TYPEID_ITEM)?((Item*)pObject):NULL;
		if( pItem == NULL )
		{
			sChatHandler.SystemMessage(Plr->GetSession(), "[*] pItem = NULL, report on forums");
			return;
		}
		if(Plr->CombatStatus.IsInCombat())
		{
			Plr->BroadcastMessage( "You are in combat!" );
		}
		else if( Plr->Cooldown_CanCast(pItem->GetProto(), 1) )
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			uint8		race = Plr->getRace();
			GossipMenu	*Menu;
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON,	"[+] Base Menu [+]", 1);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Healing [*]", 2);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*} Minor Buffs [*]", 3);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Protection [*]", 4);
			if(AutoSend) Menu->SendTo(Plr);
		}
		else
		{
			Plr->BroadcastMessage( "You can't use that right now!" );
		}
	}

	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		WorldSession * pSession = Plr->GetSession();
		/*~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		/*~~~~~~~~~~~~~~*/

		Item * pItem = (pObject->GetTypeId()==TYPEID_ITEM)?((Item*)pObject):NULL;
		if( pItem == NULL )
		{
			sChatHandler.SystemMessage(Plr->GetSession(), "[*] pItem = NULL, report on forums");
			return;
		}
		switch(IntId)
		{
		case 1:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON,	"[+] Base Menu [+]", 1);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Healing [*]", 2);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*} Minor Buffs [*]", 3);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Protection [*]", 4);
				Menu->SendTo(Plr);
			}break;
		case 2:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON,	"[+] Healing Menu [+]", 2);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Gift of the Xavian", 20);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Dark Mending", 21);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Super Rejuvenation Potion", 22);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Gift of Life", 23);
				Menu->SendTo(Plr);
			}break;

		case 20:
			{	// Gift of the Xavian - Heal: 10000
				if( MoneyCost(Plr, 200) )
				{
					Plr->CastSpell(Plr, 6925, true);
					Plr->Cooldown_AddItem(pItem->GetProto(), 1);
				}
				Plr->Gossip_Complete();
			}break;
		case 21:
			{	// Dark Mending - Heal: 4625-5375
				if( MoneyCost(Plr, 100) )
				{
					Plr->CastSpell(Plr, 39011, true);
					Plr->Cooldown_AddItem(pItem->GetProto(), 1);
				}
				Plr->Gossip_Complete();
			}break;
		case 22:
			{	// Super Rejuvenation Potion - Restores 1650 to 2750 mana and health
				if( MoneyCost(Plr, 40) )
				{
					Plr->CastSpell(Plr, 28517, true);
					Plr->Cooldown_AddItem(pItem->GetProto(), 1);
				}
				Plr->Gossip_Complete();
			}break;
		case 23:
			{	// Gift of Life - Heal: 1500
				if( MoneyCost(Plr, 15) )
				{
					Plr->CastSpell(Plr, 23783, true);
					Plr->Cooldown_AddItem(pItem->GetProto(), 1);
				}
				Plr->Gossip_Complete();
			}break;

		case 3:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON,	"[+} Minor Buffs [+]", 3);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] AQ - 40 Melee Buff", 30);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] AQ - 40 Caster Buff", 31);
				Menu->SendTo(Plr);
			}break;
		
		case 30:
			{
				if( MoneyCost(Plr, 80) )
				{
					Plr->CastSpell(Plr, 25795, true);
					Plr->Cooldown_AddItem(pItem->GetProto(), 1);
				}
				Plr->Gossip_Complete();
			}break;

		case 31:
			{
				if( MoneyCost(Plr, 80) )
				{
					Plr->CastSpell(Plr, 25798, true);
					Plr->Cooldown_AddItem(pItem->GetProto(), 1);
				}
				Plr->Gossip_Complete();
			}break;

		case 4:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON,	"[+] Protection [+]", 4);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER,	"[*] Divine Shield", 40);
				Menu->SendTo(Plr);
			}break;

		case 40:
			{
				if( MoneyCost(Plr, 100) )
				{
					Plr->CastSpell(Plr, 19753, true);
					Plr->Cooldown_AddItem(pItem->GetProto(), 1);
				}
				Plr->Gossip_Complete();
			}break;
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



void SetupItemGossip(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipScript	*gp = ( GossipScript * ) new GuildPortItem();
	GossipScript	*gs = ( GossipScript * ) new Totem();
	GossipScript	*ps = ( GossipScript * ) new PortableDJ();
	GossipScript	*bsot = ( GossipScript * ) new BScrollOfTele();
	GossipScript	*bffr = ( GossipScript * ) new Item_BUFFR();
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	mgr->register_item_gossip_script(700107, gp);
	mgr->register_item_gossip_script(60001, gs);
	mgr->register_item_gossip_script(75990, ps);
	mgr->register_item_gossip_script(700112, bsot); // Fixme Egari (Midnight)
	mgr->register_item_gossip_script(700133, bffr);
}
