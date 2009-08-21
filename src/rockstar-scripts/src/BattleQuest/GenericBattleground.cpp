#include "GenericBattleground.h"

void SetupGenericBGs()
{
	GenericBattleground::Initialize();
}

void GenericBattleground::Initialize()
{
	CREATE_HOOK(kp1, KillPlayerHook, AB_MAP, &GenericBattleground::OnKillPlayer)
	CREATE_HOOK(kp2, KillPlayerHook, WSG_MAP, &GenericBattleground::OnKillPlayer)
	CREATE_HOOK(kp4, KillPlayerHook, EOTS_MAP, &GenericBattleground::OnKillPlayer)
	CREATE_HOOK(af1, ArenaFinishHook, ALL_MAPS, &GenericBattleground::OnArenaFinish)
	CREATE_HOOK(af2, KillPlayerHook, ALL_MAPS, &GenericBattleground::OnKillPlayer)
}

void GenericBattleground::OnArenaFinish(Player * pPlayer, uint32 type, ArenaTeam * pTeam, bool victory, bool rated)
{
	if(!victory)
		return;

	if(pPlayer == NULL || pTeam == NULL)
		return;

	uint32 badges = 1 + type;
	if(rated)
	{
		uint32 r = RandomUInt(100);
		if(r < 15)
		{
			badges = badges * 2;
			pPlayer->BroadcastMessage("You have earned double gold from this rated arena match!");
		}
	}

	pPlayer->BroadcastMessage("Congratulations on your victory. You will receive %u gold.", badges);

	uint32 reward = badges * 100000;
	pPlayer->ModUnsigned32Value(PLAYER_FIELD_COINAGE, reward);
}

void GenericBattleground::OnKillPlayer(Player * pPlayer, Player * pVictim)
{
	if( pPlayer == NULL || pVictim == NULL || pPlayer != pVictim )
		return;

	Group * pGroup = pPlayer->GetGroup();
	if( pGroup == NULL )
	{
		pPlayer->BroadcastMessage("You've been awarded 10 gold for slaying %s", pVictim->GetName());
		pPlayer->ModUnsigned32Value(PLAYER_FIELD_COINAGE, 100000);
	}
	else
	{
		std::vector<Player*> GroupMembers;
		std::set<Player*> PotentialHealers;
		pPlayer->GetGroup()->Lock();
		for(uint8 i = 0; i < pPlayer->GetGroup()->GetSubGroupCount(); i++)
		{
			SubGroup * pSubGroup = pPlayer->GetGroup()->GetSubGroup(i);
			if(!pSubGroup) continue;

			GroupMembersSet::iterator itr = pSubGroup->GetGroupMembersBegin();
			for(; itr != pSubGroup->GetGroupMembersEnd(); itr++)
			{
				PlayerInfo * pi = *itr;
				if(!pi) continue;

				Player * tPlr = pi->m_loggedInPlayer;
				if(!tPlr) 
					continue;

				// Ineligible due to distance.
				if(tPlr->GetDistance2dSq(pPlayer) > 80.0f && tPlr != pPlayer)
					continue;
				
				GroupMembers.push_back(pi->m_loggedInPlayer);
			}
		}

		// Pick a number, any number!
		if(GroupMembers.size() > 0)
		{
			uint32 reward = RandomUInt(GroupMembers.size() - 1);
			GroupMembers[reward]->ModUnsigned32Value(PLAYER_FIELD_COINAGE, 100000);
			GroupMembers[reward]->BroadcastMessage("You've been awarded 10 gold for slaying %s.", pVictim->GetName());
		}
		pPlayer->GetGroup()->Unlock();
	}
}

void GenericBattleground::GiveBadge(Player * pPlayer)
{
	if(pPlayer == NULL)
		return;

	uint32 item_count = 1;
	Item *pReward;
	SlotResult res;
	if( ( pReward = pPlayer->GetItemInterface()->FindItemLessMax(29434, item_count, false) ) == NULL )
	{
		res = pPlayer->GetItemInterface()->FindFreeInventorySlot( ItemPrototypeStorage.LookupEntry(29434) );
		if( !res.Result )
		{
			pPlayer->BroadcastMessage("Could not add badge. Make sure you have room in your inventory.");
			return;
		}

		pReward = objmgr.CreateItem(29434, pPlayer);
		pReward->SetUInt32Value(ITEM_FIELD_STACK_COUNT, item_count);
		pReward->m_isDirty = true;
		if( !pPlayer->GetItemInterface()->SafeAddItem(pReward, res.ContainerSlot, res.Slot) )
		{
			if( !pPlayer->GetItemInterface()->AddItemToFreeSlot(pReward) )
				delete pReward;
		}
		pPlayer->GetSession()->SendItemPushResult(pReward,true,false,true,false,res.ContainerSlot,res.Slot, item_count);
	}
	else
	{
		pReward->m_isDirty = true;
		pReward->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT, item_count);

		res.ContainerSlot = pPlayer->GetItemInterface()->GetBagSlotByGuid(pReward->GetGUID());
		res.Slot = -1;
		pPlayer->GetSession()->SendItemPushResult(pReward,true,false,true,true,res.ContainerSlot,res.Slot, item_count);
	}	
}

