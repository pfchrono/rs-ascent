/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"

class Flayer :
	public CreatureAIScript
{
public:
	Flayer(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
	}

	void OnDied(Unit *mKiller)
	{
		float x = _unit->GetPositionX();
		float y = _unit->GetPositionY();
		float z = _unit->GetPositionZ();
		float o = _unit->GetOrientation();
		_unit->GetMapMgr()->GetInterface()->SpawnCreature(11064,x,y,z,o,true,false,0,0);
	}

	void Destroy()
	{
		delete ( Flayer * ) this;
	}

	static CreatureAIScript *Create(Creature *c)
	{
		return new Flayer(c);
	}
};

class SCRIPT_DECL Darrowshire_Spirit : public GossipScript
{
public:
	void GossipHello(Object * pObject, Player* Plr, bool AutoSend)
	{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			QuestLogEntry	*en = Plr->GetQuestLogForEntry(5211);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(en && en->GetMobCount(0) < en->GetQuest()->required_mobcount[0])
			{
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				uint32	newcount = en->GetMobCount(0) + 1;
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				en->SetMobCount(0, newcount);
				en->SendUpdateAddKill(0);
				en->UpdatePlayerFields();
			}
	
		GossipMenu *Menu;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 3873, Plr);

		if(AutoSend)
			Menu->SendTo(Plr);

		float x = Plr->GetPositionX();
		float y = Plr->GetPositionY();
		float z = Plr->GetPositionZ();

		Creature *Spirit = Plr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(x,y,z,11064);
		Spirit->Despawn(2000, 0);
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

void SetupEastern(ScriptMgr *mgr)
{
	GossipScript * gs = (GossipScript*) new Darrowshire_Spirit();
	mgr->register_gossip_script(11064, gs);
	mgr->register_creature_script(8532, &Flayer::Create);
}
