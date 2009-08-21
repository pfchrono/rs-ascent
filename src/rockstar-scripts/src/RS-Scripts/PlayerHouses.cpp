
#include "Setup.h"

#define HOUSESPAWNITEMID 1
#define HOUSEKEYITEMID 3

#ifdef WIN32
#pragma warning(once: 4305)// warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

class SCRIPT_DECL HouseSpawnrItem : public GossipScript
{
public:
    void GossipHello(Object * pObject, Player* Plr, bool AutoSend)
	{
		GossipMenu *Menu;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		Menu->AddItem(4, "[Player Housing]");
		Menu->AddItem(0, "Spawn a house!!", 1);
		if(AutoSend) 
			Menu->SendTo(Plr);
	
	}
    void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
	{
		uint32 acct			= 0;
		uint32 homestatus	= 0;
		acct				= Plr->GetSession()->GetAccountId();
		if( !acct ) 
			return;
		QueryResult *getHomeStatus = NULL;
		getHomeStatus = CharacterDatabase.Query("SELECT `hashouse` FROM `accounts` WHERE `acct` = '%s'", acct);
		if( getHomeStatus )
		{
			homestatus = getHomeStatus->Fetch()[0].GetUInt32();
			delete getHomeStatus;
		}
		if( homestatus != 0 )
		{
			Plr->BroadcastMessage("You already have a house!");
			return;
		}


		float locX = Plr->GetPositionX();
		float locY = Plr->GetPositionY();
		float locZ = Plr->GetPositionZ();
		float locO = Plr->GetOrientation();
		float height = 0.6510f;
		float locZp = locZ + height;

		switch( IntId )
		{
		case 0:
			{
				GossipHello(pObject, Plr, true);
			}break;
        case 1: // Is Horde
			{
				if( Plr->GetTeam() == 0 )
				{
					if( Plr->GetAreaID() == 440 )
					{		
						CharacterDatabase.Execute("UPDATE accounts SET hashouse = 1 WHERE acct='%u'", acct); // Update data in accounts table.
						CharacterDatabase.Execute("INSERT INTO houselocation (acct, team, mapId, posX, posY, posZ) VALUES (%u, %u, %u, %f, %f, %f)", acct, Plr->GetTeam(), Plr->GetMapId(), Plr->GetPositionX(), Plr->GetPositionY(), locZp); // Insert data
						Plr->GetMapMgr()->GetInterface()->SpawnGameObject(70040, locX, locY, locZp, locO, true, 0, 0);
						Plr->GetItemInterface()->RemoveItemAmt(HOUSESPAWNITEMID, 1);
						Plr->GetItemInterface()->AddItemToFreeSlot(objmgr.CreateItem(HOUSEKEYITEMID, Plr));
						Plr->BroadcastMessage("You have spawned a Two Story House");
					}
					else
					{
						Plr->BroadcastMessage("You cannot spawn that here!");
					} 
				}
				if( Plr->GetTeam() == 1 ) // Is Alliance?
				{
					if( Plr->GetAreaID() == 51 )
					{		
						CharacterDatabase.Execute("UPDATE accounts SET hashouse = 1 WHERE acct='%u'", acct); // Update data in accounts table.
						CharacterDatabase.Execute("INSERT INTO houselocation (acct, team, mapId, posX, posY, posZ) VALUES (%u, %u, %u, %f, %f, %f)", acct, Plr->GetTeam(), Plr->GetMapId(), Plr->GetPositionX(), Plr->GetPositionY(), locZp); // Insert data
						Plr->GetMapMgr()->GetInterface()->SpawnGameObject(70040, locX, locY, locZp, locO, true, 0, 0);
						Plr->GetItemInterface()->RemoveItemAmt(HOUSESPAWNITEMID, 1);
						Plr->GetItemInterface()->AddItemToFreeSlot(objmgr.CreateItem(HOUSEKEYITEMID, Plr));
						Plr->BroadcastMessage("You have spawned a Two Story House");
					}
					else
					{
						Plr->BroadcastMessage("You cannot spawn that here!");
					} 
				}
			}break;
		default:
			GossipHello(pObject, Plr, true);
		}
		Plr->Gossip_Complete();
	}
    void GossipEnd(Object * pObject, Player* Plr)
	{
		GossipScript::GossipEnd(pObject, Plr);
	}
	void Destroy()
	{
		delete this;
	}
};


class SCRIPT_DECL KeyGossipScript : public GossipScript
{
public:
    void GossipHello(Object * pObject, Player* Plr, bool AutoSend)
	{
		GossipMenu *Menu;
		uint32 TextID = 112230;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);
		Menu->AddItem(10, "Go into your house", 1);
		if(AutoSend)
			Menu->SendTo(Plr);
	}
    void GossipSelectOption(GossipMenu * Menu, Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
	{
		uint32	acct	= 0;
		uint32	M		= 0;
		float	X		= 0;
		float	Y		= 0;
		float	Z		= 0;

		acct = Plr->GetSession()->GetAccountId();
		if( !acct)
			return;
        
		QueryResult *getHomeLocation = CharacterDatabase.Query("SELECT mapId, posX, posY, posZ FROM houselocation WHERE acct = '%u'", acct);
		if( !getHomeLocation )
			return;

		switch(IntId)
		{
        case 0:
			{
				GossipHello(pObject, Plr, true);
			}break;
		case 1: //Teleport to house
			{
				M = getHomeLocation->Fetch()[0].GetUInt32();
				X = getHomeLocation->Fetch()[1].GetUInt32();
				Y = getHomeLocation->Fetch()[2].GetUInt32();
				Z = getHomeLocation->Fetch()[3].GetUInt32();
				Plr->Gossip_Complete();
				Plr->EventTeleport(M, X, Y, Z);
				delete getHomeLocation;
			}break;
		}
	}
    void GossipEnd(Object * pObject, Player* Plr)
	{
		GossipScript::GossipEnd(pObject, Plr);
	}
	void Destroy()
	{
		delete this;
	}
};

void SetupSpawnPlayerHouses(ScriptMgr * mgr)
{
	GossipScript * h = ( GossipScript* ) new HouseSpawnrItem();
	GossipScript * k = ( GossipScript* ) new KeyGossipScript();
   	mgr->register_item_gossip_script(HOUSESPAWNITEMID, h);
	mgr->register_item_gossip_script(HOUSEKEYITEMID, k);
}