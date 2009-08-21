/*
 * Moon++ Scripts for Ascent MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.	If not, see <http://www.gnu.org/licenses/>.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "../EAS/EasyFunctions.h"

class SCRIPT_DECL DraeneiFishingNet : public GossipScript
{
public:
	void GossipHello(Object * pObject, Player* Plr, bool AutoSend)
	{
		Item *item = (Item*)pObject;
		uint32 spellid = item->GetProto()->Spells[0].Id;
		Plr->CastSpell(Plr, dbcSpell.LookupEntry(spellid), false);

		QuestLogEntry *qle = Plr->GetQuestLogForEntry(9452);
		if(qle == NULL)
			return;

		uint8 chance = RandomUInt(10);
		if(chance <= 3)
		{
			sEAS.SpawnCreature(Plr, 17102, Plr->GetPositionX(), Plr->GetPositionY(), Plr->GetPositionZ(), Plr->GetOrientation(), 3*60*1000);
			return;
		}

		sEAS.AddItem(23614, Plr);

		qle->SendUpdateAddKill(1);
		qle->UpdatePlayerFields();

		Plr->Gossip_Complete();
	}
};

class SCRIPT_DECL InoculatingCrystal : public GossipScript
{
public:
	void GossipHello(Object * pObject, Player* Plr, bool AutoSend)
	{
		QuestLogEntry *qle = Plr->GetQuestLogForEntry(9303);
		if (qle == NULL) return;

		if (qle->CanBeFinished()) return;

		Item *item = (Item*)pObject;
		if (item == NULL) return;

		uint32 spellid = item->GetProto()->Spells[0].Id;
		Plr->CastSpell(Plr, spellid, false);

		Creature *pCreature = static_cast<Creature*>(Plr->GetMapMgr()->GetUnit(Plr->GetSelection()));
		if (pCreature == NULL)
		{
			Plr->BroadcastMessage("No creature selected.");
			return;
		}

		uint32 targetid = pCreature->GetEntry();
		if (targetid == 16518)
		{
			float posX = pCreature->GetPositionX();
			float posY = pCreature->GetPositionY();
			float posZ = pCreature->GetPositionZ();
			float posO = pCreature->GetOrientation();

			pCreature->Despawn(0, (3*60*1000));
			sEAS.SpawnCreature(Plr, 16534, posX, posY, posZ, posO, (2*60*1000));

			if (qle->GetMobCount(0) < qle->GetQuest()->required_mobcount[0])
			{
				qle->SetMobCount(0, qle->GetMobCount(0)+1);
				qle->SendUpdateAddKill(0);
				qle->UpdatePlayerFields();
			}
		}
		Plr->Gossip_Complete();
	}
};

void SetupAzuremystIsle(ScriptMgr *mgr)
{
	mgr->register_item_gossip_script(22962, CREATE_GOSSIPSCRIPT(InoculatingCrystal));
	mgr->register_item_gossip_script(23654, CREATE_GOSSIPSCRIPT(DraeneiFishingNet));
}
