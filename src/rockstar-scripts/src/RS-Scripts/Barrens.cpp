	/*Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
			http://www.fishstik.ca Please do not use these scripts for any other server
			than the RockStar Funserver(http://fishstik.ca) as they were specially
			scripted/modded for the server in question.
	*/
#include "StdAfx.h"
#include "Setup.h"
#include "../EAS/EasyFunctions.h"

/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
 */
#include "StdAfx.h"
#include "Setup.h"
#include "../EAS/EasyFunctions.h"

/*
 =======================================================================================================================
		Tiragarde Keep Lieutenant Benedict
 =======================================================================================================================
 */
class BenedictQAI :
	public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(BenedictQAI);
	BenedictQAI(Creature *pCreature) :
	CreatureAIScript(pCreature)
	{
	}

	void OnDied(Unit *mKiller)
	{
		if(mKiller->IsPlayer())
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			uint32			objective = 2;
			QuestLogEntry	*en = (( Player * ) mKiller)->GetQuestLogForEntry(784);
			Quest			*quest = en->GetQuest();
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			if(en && en->GetMobCount(objective) < en->GetQuest()->required_mobcount[objective])
			{
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				uint32	newcount = en->GetMobCount(objective) + 1;
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				en->SetMobCount(objective, quest->required_mobcount[objective]);
				en->SendUpdateAddKill(objective);
				en->UpdatePlayerFields();
				return;
			}
		}
	}
};

class SCRIPT_DECL Mankriks_Wife :
public GossipScript
{
	public:
		void GossipHello( Object * pObject, Player* Plr, bool AutoSend )
	{
		GossipMenu *Menu;
		QuestLogEntry *qle = Plr->GetQuestLogForEntry( 4921 );

		objmgr.CreateGossipMenuForPlayer( &Menu, pObject->GetGUID(), 3557, Plr );
		if ( qle )
		{
			Menu->AddItem(0, "Inspect Body Further", 1);
		}
				
		if( AutoSend )
			Menu->SendTo( Plr );
	}

	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
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
				objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), 3558, Plr);
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
				QuestLogEntry	*en = Plr->GetQuestLogForEntry( 4921 );
				/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

				if(en && en->GetMobCount( 0 ) < en->GetQuest()->required_mobcount[0] )
				{
					/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
					uint32	newcount = en->GetMobCount( 0 ) + 1;
					/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

					en->SetMobCount( 0, newcount );
					en->SendUpdateAddKill( 0 );
					en->UpdatePlayerFields();
				}
				Menu->SendTo(Plr);
			}

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

class SCRIPT_DECL Naralex :
public GossipScript
{
	public:
		void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Creature *pCreature = (pObject->GetTypeId() == TYPEID_UNIT) ? (( Creature * ) pObject) : NULL;
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

			pCreature->CastSpell(Plr, 5232, 0);

			/*~~~~~~~~~~~~~~*/
			GossipMenu *Menu;
			/*~~~~~~~~~~~~~~*/

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 25006, Plr);

			if(AutoSend) Menu->SendTo(Plr);
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

void SetupBarrens(ScriptMgr *mgr)
{
	mgr->register_creature_script(3192, CREATE_CREATURESCRIPT(BenedictQAI));
	mgr->register_gossip_script(3678, CREATE_GOSSIPSCRIPT(Naralex));
	mgr->register_gossip_script(10668, CREATE_GOSSIPSCRIPT(Mankriks_Wife));
}
