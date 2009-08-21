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

void OnPvPKillPlayer(Player *pPlayer, Player *pVictim)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	uint32	atklvl = pPlayer->getLevel();
	uint32	viclvl = pVictim->getLevel();
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	if((pVictim == pPlayer) || (pVictim->GetTypeId() != TYPEID_PLAYER)) return;
	if((atklvl < 50) || (viclvl < 50)) return;
	if(atklvl > (viclvl + 10)) return;

	/*~~~~~~~~~~~~~~~~~~~~~~*/
	uint32	itemid, count = 1;
	/*~~~~~~~~~~~~~~~~~~~~~~*/

	if(pVictim->GetTeam() > 0)
		itemid = 7400099;
	else
		itemid = 7400098;

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	ItemPrototype	*proto = ItemPrototypeStorage.LookupEntry(itemid);
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	if(proto)
	{
		/*~~~~~~~~~~~~~~~~~~~*/
		Item		*add;
		SlotResult	slotresult;
		/*~~~~~~~~~~~~~~~~~~~*/

		sChatHandler.SystemMessage
			(
				pPlayer->GetSession(),
				"|cff33AA33You receive item: |cffffffff|Hitem:%u:0:0:0:0:0:0:0|h[%s]|h|r",
				proto->ItemId,
				proto->Name1
			);
		add = pPlayer->GetItemInterface()->FindItemLessMax(itemid, count, false);
		if(!add)
		{
			slotresult = pPlayer->GetItemInterface()->FindFreeInventorySlot(proto);
			if(!slotresult.Result)
			{
				pPlayer->GetItemInterface()->BuildInventoryChangeError(NULL, NULL, INV_ERR_INVENTORY_FULL);
				return;
			}

			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Item	*it = objmgr.CreateItem(itemid, pPlayer);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			it->SetUInt32Value(ITEM_FIELD_STACK_COUNT, count);
			pPlayer->GetItemInterface()->SafeAddItem(it, slotresult.ContainerSlot, slotresult.Slot);
		}
		else
		{
			add->SetCount(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + count);
			add->m_isDirty = true;
		}
	}
}

void SetupPvPKill(ScriptMgr *mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, (void*)OnPvPKillPlayer);
}
