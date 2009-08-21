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
#ifdef WIN32
#pragma warning(disable : 4305) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#endif

#define	PtF_TextID 700135
#define UTOFRIEND_COST 500000
#define FRIENDTOU_COST 250000

class SCRIPT_DECL PtF_Item : public GossipScript
{
public:
	bool IsValidAppearLocation(Player *_plr, Player *trgt)
	{
		if(!_plr || !trgt) return false;
		MapInfo * pMI = trgt->GetMapMgr()->GetMapInfo();
		if(!pMI 
			|| trgt->GetMapId() == 13 
			|| trgt->GetZoneId() == 267
			|| pMI->minlevel > _plr->getLevel()
			|| ( pMI->heroic_key_1 && !_plr->GetItemInterface()->GetItemCount(pMI->heroic_key_1, false) )
			|| ( pMI->heroic_key_2 && !_plr->GetItemInterface()->GetItemCount(pMI->heroic_key_2, false) )
			|| ( pMI->required_heroicspell && !_plr->HasSpell(pMI->required_heroicspell) )
			|| ( pMI->required_quest && !_plr->HasFinishedQuest(pMI->required_quest) )
			|| ( pMI->playerlimit != 0 && pMI->playerlimit >= trgt->GetMapMgr()->GetPlayerCount() )
			|| trgt->GetZoneId() == 267
			|| ( trgt->GetZoneId() == 2597 && _plr->RS_getAccess() < RS_VIP )
			|| ( trgt->GetZoneId() == 2557 && _plr->RS_getAccess() < RS_VIP )
			|| ( trgt->GetZoneId() == 876 && _plr->RS_getAccess() < RS_GAMEMASTER ) 
			|| pMI->required_access > _plr->RS_getAccess() )
			return false;
		else
			return true;
	}
	bool IsValidSummonLocation(Player *_plr, Player *trgt)
	{
		if(!_plr || !trgt) return false;
		MapInfo * pMI = _plr->GetMapMgr()->GetMapInfo();
		if( !pMI 
			|| trgt->GetMapId() == 13 
			|| _plr->GetMapId() == 13
			|| pMI->minlevel > trgt->getLevel()
			|| ( pMI->heroic_key_1 && !trgt->GetItemInterface()->GetItemCount(pMI->heroic_key_1, false) )
			|| ( pMI->heroic_key_2 && !trgt->GetItemInterface()->GetItemCount(pMI->heroic_key_2, false) )
			|| ( pMI->required_heroicspell && !trgt->HasSpell(pMI->required_heroicspell) )
			|| ( pMI->required_quest && !trgt->HasFinishedQuest(pMI->required_quest) )
			|| ( pMI->playerlimit != 0 && pMI->playerlimit >= _plr->GetMapMgr()->GetPlayerCount() )
			|| _plr->GetZoneId() == 267
			|| ( _plr->GetZoneId() == 2597 && trgt->RS_getAccess() < RS_VIP )
			|| ( _plr->GetZoneId() == 2557 && trgt->RS_getAccess() < RS_VIP )
			|| ( _plr->GetZoneId() == 876 && trgt->RS_getAccess() < RS_GAMEMASTER) 
			|| pMI->required_access > trgt->RS_getAccess())
			return false;
		else
			return true;
	}
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		if(Plr->RS_getAccess() > RS_PLAYER)
		{
			/*~~~~~~~~~~~~~~~~~~~~~*/
			GossipMenu	*Menu;
			/*~~~~~~~~~~~~~~~~~~~~~*/
			/* Hello (First) Menu. */
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), PtF_TextID, Plr);
			Menu->AddItem(0, "Friend Porter!", 99);
			Menu->AddItem(5, "- Appear to a friend - (cost 50g)", 1);
			Menu->AddItem(5, "- Summon a friend - (cost 25g)", 3);
			if(AutoSend) 
			{
				Menu->SendTo(Plr);
			}
		}else{
			sChatHandler.BlueSystemMessage(Plr->GetSession(), "You are not supposed to have this..");
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Item *pItem = (pObject->GetTypeId() == TYPEID_ITEM) ? (( Item * ) pObject) : NULL;
			if( pItem )
			{
				Plr->GetItemInterface()->RemoveItemAmt(pItem->GetEntry(), 1);
				sChatHandler.BlueSystemMessage(Plr->GetSession(), "....poof.....");
			}
		}
	}
	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		switch(IntId)
		{
		case 0: 
			{
				GossipHello(pObject, Plr, true);
			}break;
		case 1:
			{
				Plr->Gossip_Complete();
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), PtF_TextID, Plr);
				Menu->AddItem(5, "AppearCodeBox", 2, 1);
				Menu->SendTo(Plr);
			}break;
		case 2:
			{
				if(Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) < UTOFRIEND_COST)
				{
					Plr->BroadcastMessage("You don't have enough gold to teleport to another player.");
					return;
				}
				if( Code )
				{
					string sCode = string(Code);
					string lCode = sCode;
					ASCENT_TOLOWER(lCode);
					PlayerInfo *chrI = objmgr.GetPlayerInfoByName(sCode.c_str());
					if( !chrI )
					{
						sChatHandler.RedSystemMessage(Plr->GetSession(), "Couldn't find a character by that name.");
						Plr->Gossip_Complete();
						return;
					}
					Player * target = objmgr.GetPlayer(chrI->guid);
					if( !target || !target->IsInWorld())
					{	
						sChatHandler.RedSystemMessage(Plr->GetSession(), "Player not found or player is teleporting/flying.");
					}
					else
					{
						LocationVector targetPos(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation());
						if(Plr)
						{
							if( IsValidAppearLocation(Plr, target) )
							{
								if(!Plr->GetGroup() || !target->GetGroup() || Plr->GetGroup() != target->GetGroup())
								{
									sChatHandler.RedSystemMessage(Plr->GetSession(), "Failed. You need to be in the same group as target player");
									Plr->Gossip_Complete();
									return;
								}
								Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - UTOFRIEND_COST));
								Plr->Gossip_Complete();
								Plr->SafeTeleport(target->GetMapId(), target->GetInstanceID(), targetPos);
								char message[1024];
								sprintf(message, "used the friendship bracelet to port to player %s at m:%u x:%u y:%u z:%u", target->GetName(), target->GetMapId(), target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
								sWorld.LogWriteFromSession(Plr->GetSession(), GMLOG, message);
							}
							else
							{
								sChatHandler.RedSystemMessage(Plr->GetSession(), "Player is at an invalid location, please try again later!");
								Plr->Gossip_Complete();
							}
						}
					}
				}
			}break;
		case 3:
			{
				Plr->Gossip_Complete();
				GossipMenu * Menu;
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), PtF_TextID, Plr);
				Menu->AddItem(5, "SummonCodeBox", 4, 1);
				Menu->SendTo(Plr);
			}break;
		case 4:
			{
				if(Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) < FRIENDTOU_COST)
				{
					Plr->BroadcastMessage("You don't have enough gold to teleport to another player.");
					Plr->Gossip_Complete();
					return;
				}
				if( Code )
				{
					string sCode = string(Code);
					string lCode = sCode;
					ASCENT_TOLOWER(lCode);
					PlayerInfo *chrI = objmgr.GetPlayerInfoByName(sCode.c_str());
					if( !chrI )
					{
						sChatHandler.RedSystemMessage(Plr->GetSession(), "Couldn't find a character by that name.");
						Plr->Gossip_Complete();
						return;
					}
					Player * target = objmgr.GetPlayer(chrI->guid);
					if( !target || !target->IsInWorld())
					{	
						sChatHandler.RedSystemMessage(Plr->GetSession(), "Player not found or player is teleporting/flying.");
					}
					else
					{
						if(Plr)
						{
							if( IsValidSummonLocation(Plr, target) )
							{
								if(!Plr->GetGroup() || !target->GetGroup() || Plr->GetGroup() != target->GetGroup())
								{
									sChatHandler.RedSystemMessage(Plr->GetSession(), "Failed. You need to be in the same group as target player");
									Plr->Gossip_Complete();
									return;
								}
								Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - FRIENDTOU_COST));
								target->SummonRequest(Plr->GetLowGUID(), Plr->GetZoneId(), Plr->GetMapId(), Plr->GetInstanceID(), Plr->GetPosition());
							}
							else
							{
								sChatHandler.RedSystemMessage(Plr->GetSession(), "Player is at an invalid location, please try again later!");
							}
						}
					}
				}
				Plr->Gossip_Complete();
			}break;
		default:
			{
				GossipHello(pObject, Plr, true);
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

void SetupPortToFriends(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipScript	*PtFItem = ( GossipScript * ) new PtF_Item;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	mgr->register_item_gossip_script(700135, PtFItem); /* PtF_NPC */
}
