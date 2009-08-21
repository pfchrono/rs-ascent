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



/*--------------------------------------------------------------------------------------------------------*/
// Crisis at the Sunwell

class ScryingOrb : public GameObjectAIScript
{
public:
	ScryingOrb(GameObject* goinstance) : GameObjectAIScript(goinstance) {}
	static GameObjectAIScript *Create(GameObject * GO) { return new ScryingOrb(GO); }

	void OnActivate(Player * pPlayer)
	{
		if(!pPlayer || !pPlayer->GetSession() || !pPlayer->GetMapMgr() || !pPlayer->GetMapMgr()->GetInterface())
			return;

		QuestLogEntry *qle = pPlayer->GetQuestLogForEntry(11490);
			if(qle)
		{
			float SSX = pPlayer->GetPositionX();
			float SSY = pPlayer->GetPositionY();
			float SSZ = pPlayer->GetPositionZ();
			
			GameObject* Orb = pPlayer->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords( SSX, SSY, SSZ, 187578);
			if (Orb)
			{
				uint32 triggercinematic = 164;
			#ifdef USING_BIG_ENDIAN
				swap32(&triggercinematic);
			#endif
				pPlayer->GetSession()->OutPacket(SMSG_TRIGGER_CINEMATIC, 4, &triggercinematic);
				
				Orb->SetUInt32Value(GAMEOBJECT_STATE, 0);
					qle->SetMobCount(0, 1);
					qle->SendUpdateAddKill(0);
					qle->UpdatePlayerFields();
				sEAS.SpawnCreature(pPlayer, 24848, 231.900223, -280.878021, -6.808758, 1.747514, 4*60*1000);

			}
			return;
		}
		else
		{
			pPlayer->BroadcastMessage("Missing required quest : The Scryer's Scryer");
		}
	}
};



/*--------------------------------------------------------------------------------------------------------*/
// Erratic Behavior

bool ConvertingSentry(uint32 i, Spell* pSpell)
{
	Player *caster = pSpell->p_caster;
	if(caster == NULL)
		return false;

	Creature *target = static_cast<Creature*>(pSpell->GetUnitTarget());
	if(target == NULL)
		return false;

	if( caster->GetUInt32Value(UNIT_FIELD_SUMMON) == 24981 )
		return false;

	// Erratic Sentry: 24972
	if(target->GetEntry() != 24972)
		return false;

	if(!target->isAlive())
		return false;

	target->Despawn(1, 2*60*1000);

	caster->CastSpell(caster, 45009, true);

	return true;
}

void SetupIsleOfQuelDanas(ScriptMgr * mgr)
{
	mgr->register_gameobject_script(187578, &ScryingOrb::Create);
	mgr->register_dummy_spell(44997, &ConvertingSentry);
}
