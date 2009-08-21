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

class SCRIPT_DECL Item_Morpher :	public GossipScript
{
protected:
	bool MoneyCost(Player * Plr, uint32 GoldAmount)
	{
		uint32 CurrentMoney = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
		uint32 PriceInCopper = GoldAmount * 10000;
		int32 newgold = CurrentMoney - PriceInCopper; 
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
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[+] Morpher Base Menu [+]", 99);
			if(Plr->RS_getAccess() >= RS_VIP)
			{
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[*] VIP Morphs [*]", 7);
			}
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Animal", 1);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Boss", 2);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Mob", 3);
			Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Friendly", 4);
			Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[-] Demorph [-]", 5);
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
		case 1:
			{					/* Base Menu */
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[+] Animal Menu [+]", 1);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Cat", 10);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Rabbit", 11);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Snake", 12);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Chicken", 13);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[-] Back [-]", 99);
				Menu->SendTo(Plr);
			}
			break;
			/*--------------
				Animals
			--------------*/
		case 10: // Cat
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11709);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 11: // Rabbit
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 328);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 12: // Snake
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 7409);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 13: // Chicken
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 6193);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
			/*--------------
				Bosses
			--------------*/
		case 2:
			{					/* Boss Menu */
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[+] Boss Menu [+]", 2);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] KSloth Demon", 20);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] KSloth Necro", 21);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Shadowmancer Malicia", 22);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Diablo", 23);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[-] Back [-]", 99);
				Menu->SendTo(Plr);
			}
			break;
		case 20: // KSloth Demon
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 7570);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 21: // KSloth Necro
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16279);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 22: // Shadowmancer Malicia
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11835);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 23: // Diablo
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10992);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
			/*--------------
				Mobs
			--------------*/
		case 3:
			{					/* Base Menu */
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[+] Mob Menu [+]", 3);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Voidwraith", 30);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] TN Guardian", 31);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Goblin", 32);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Mana Wyrm", 33);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[-] Back [-]", 99);
				Menu->SendTo(Plr);
			}
			break;
		case 30: // Voidwraith
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 18955);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 31: // TN Guardian
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 15347);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 32: // Goblin
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 7160);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 33: // Mana Wyrm
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16217);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;

			/*-------------------
				Friendly NPC
			-------------------*/
		case 4:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[+] FriendlyNPC Menu [+]", 4);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Armstone", 40);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Lady Sylvanas", 41);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Garg'ar", 42);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Murky", 43);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[-] Back [-]", 99);
				Menu->SendTo(Plr);
			}
			break;
		case 40: // Armstone
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 21418);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 41: // Lady Sylvanas
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11657);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 42: // Garg'ar
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 14792);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;
		case 43: // Murky
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 15369);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				}
				Plr->Gossip_Complete();
			}break;

		case 5:
			{
				Plr->DeMorph();
				Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
				Plr->Gossip_Complete();
			}break;

		case 7: // VIP Menu
			{					/* Base Menu */
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[+] Morpher VIP Menu [+]", 7);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Tyrael", 71);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[-] Back [-]", 99);
				Menu->SendTo(Plr);
			}
			break;

		case 71: // Tyrael
			{
				if( MoneyCost(Plr, 200) )
				{
					Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 25900);
					Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.5f);
				}
				Plr->Gossip_Complete();
			}break;

		case 99:
			{					/* Base Menu */
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[+] Morpher Base Menu [+]", 99);
				if(Plr->RS_getAccess() >= RS_VIP)
				{
					Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[*] VIP Morphs [*]", 7);
				}
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Animal", 1);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Boss", 2);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Mob", 3);
				Menu->AddItem(GOSSIP_ICON_INNKEEPER, "[*] Friendly", 4);
				Menu->AddItem(GOSSIP_ICON_TXTBALLOON, "[-] Demorph [-]", 5);
				Menu->SendTo(Plr);
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

void SetupScrollOfMorphing(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipScript	*mrph_Item = ( GossipScript * ) new Item_Morpher();
	mgr->register_item_gossip_script(700114, mrph_Item);
}
