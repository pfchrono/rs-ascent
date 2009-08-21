/*
	 Scripted for the RockStar FunServer Egari, T0aST, Midnight, Pyro
	 http://www.fishstik.ca Please do not use these scripts for any other server
	 than the RockStar Funserver(http://fishstik.ca) as they were specially
	 scripted/modded for the server in question.
*/

#include "StdAfx.h"
#include "Setup.h"
#include "../EAS/EasyFunctions.h"

#ifdef WIN32
#pragma warning(disable:4305)		// warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

#define SendQuickMenu(textid) objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), textid, plr); \
	Menu->SendTo(plr);

class SCRIPT_DECL SpiritScreeches : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature *spirit = (Creature*)(pObject);
		if (spirit == NULL)
			return;

		if(plr->GetQuestLogForEntry(3520))
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2039, plr);
			Menu->AddItem( 0, "Goodbye", 1);

			if(AutoSend)
				Menu->SendTo(plr);
		}



	}

	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature *spirit = (Creature*)(pObject);
		if (spirit == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;

			case 1:
				{
					QuestLogEntry *en = plr->GetQuestLogForEntry(3520);
					if(en && en->GetMobCount(0) < en->GetQuest()->required_mobcount[0])
					{
						en->SetMobCount(0, en->GetMobCount(0) + 1);
						en->SendUpdateAddKill(0);
						en->UpdatePlayerFields();
					}
					if(!spirit)
						return;

					spirit->Despawn(1, 0);
					return;

				}
		}
	}

	void Destroy()
	{
		delete this;
	}
};

class ScreecherSpirit : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ScreecherSpirit);

	ScreecherSpirit(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		if(!_unit)
			return

		_unit->Despawn(60*1000, 0);
		Creature *cialo = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), 5307);
		if(!cialo)
			return;

		if(!cialo->isAlive())
			cialo->Despawn(1, 6*60*1000);
	}
};

class SCRIPT_DECL StewardOfTime : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* Plr, bool AutoSend)
	{
		GossipMenu *Menu;
		if(Plr->GetQuestLogForEntry(10279))
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 9978, Plr);
			Menu->AddItem( 0, "Please take me to the mater lair", 1);
			Menu->SendTo(Plr);
		}
	}

	void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
	{
		Creature* creat = static_cast<Creature*>(pObject);
		switch(IntId)
		{
		case 1:
			creat->CastSpell(Plr, dbcSpell.LookupEntry(34891), true);
			break;
		}
	}
}; 

class SCRIPT_DECL StrFever : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature *doctor = (Creature*)(pObject);
		if (doctor == NULL)
			return;

		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
		if(plr->GetQuestLogForEntry(348) && plr->GetItemInterface()->GetItemCount(2799, 0) && !plr->GetItemInterface()->GetItemCount(2797, 0))
			Menu->AddItem( 0, "I'm ready, Summon Him!", 1);

		if(AutoSend)
			Menu->SendTo(plr);
	}

	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature *doctor = (Creature*)(pObject);
		if (doctor == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;

			case 1:
			{
				plr->GetItemInterface()->RemoveItemAmt(2799, 1);
				doctor->CastSpell(doctor, dbcSpell.LookupEntry(12380), true);
				if(!plr == NULL || plr->GetMapMgr() == NULL || plr->GetMapMgr()->GetInterface() == NULL)
					return;
				Creature *firstenemy = sEAS.SpawnCreature(plr, 1511, -13770.5, -6.79, 42.8, 5.7 , 0);
				firstenemy->GetAIInterface()->MoveTo(-13727.8, -26.2, 46.15, 4.07);
				firstenemy->Despawn(10*60*1000, 0);
			}break;
		}
	}

	void Destroy()
	{
		delete this;
	}
};

class Beka : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Beka);
	Beka(Creature* pCreature) : CreatureAIScript(pCreature)  {}

	void OnDied(Unit* mKiller)
	{
		if(mKiller->IsPlayer())
		{
			Player* mPlayer = static_cast< Player* >( mKiller );
			if(mPlayer == NULL || mPlayer->GetMapMgr() == NULL || mPlayer->GetMapMgr()->GetInterface() == NULL)
				return;
			Creature * beka1 = sEAS.SpawnCreature(mPlayer, 1516, -13770.5, -6.79, 42.8, 5.7 , 0);
			beka1->GetAIInterface()->MoveTo(-13727.8, -26.2, 46.15, 4.07);
			beka1->Despawn(10*60*1000, 0);
		}
		else
		{
			Player* mPlayer = _unit->GetMapMgr()->GetInterface()->GetPlayerNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ());
			if(mPlayer)
			{
				if(mPlayer == NULL || mPlayer->GetMapMgr() == NULL || mPlayer->GetMapMgr()->GetInterface() == NULL)
					return;
				Creature * beka1 = sEAS.SpawnCreature(mPlayer, 1516, -13770.5, -6.79, 42.8, 5.7 , 0);
				beka1->GetAIInterface()->MoveTo(-13727.8, -26.2, 46.15, 4.07);
				beka1->Despawn(10*60*1000, 0);
			}
		}
	}
};

class Beka1 : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Beka1);
	Beka1(Creature* pCreature) : CreatureAIScript(pCreature)  {}

	void OnDied(Unit* mKiller)
	{
		if(mKiller->IsPlayer())
		{
			Player* mPlayer = static_cast< Player* >( mKiller );
			if(mPlayer == NULL || mPlayer->GetMapMgr() == NULL || mPlayer->GetMapMgr()->GetInterface() == NULL)
				return;
			Creature * beka1 = sEAS.SpawnCreature(mPlayer, 1514, -13770.5, -6.79, 42.8, 5.7, 0);
			beka1->GetAIInterface()->MoveTo(-13727.8, -26.2, 46.15, 4.07);
			beka1->Despawn(10*60*1000, 0);
		}
		else
		{
			Player* mPlayer = _unit->GetMapMgr()->GetInterface()->GetPlayerNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ());
			if(mPlayer)
			{
				if(mPlayer == NULL || mPlayer->GetMapMgr() == NULL || mPlayer->GetMapMgr()->GetInterface() == NULL)
					return;
				Creature * beka1 = sEAS.SpawnCreature(mPlayer, 1514, -13770.5, -6.79, 42.8, 5.7, 0);
				beka1->GetAIInterface()->MoveTo(-13727.8, -26.2, 46.15, 4.07);
				beka1->Despawn(10*60*1000, 0);
			}
		}
	}
};

class Beka2 : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Beka2);
	Beka2(Creature* pCreature) : CreatureAIScript(pCreature)  {}

	void OnDied(Unit* mKiller)
	{
		if( mKiller == NULL || mKiller->GetMapMgr() == NULL || mKiller->GetMapMgr()->GetInterface() == NULL )
			return;

		float SSX = mKiller->GetPositionX();
		float SSY = mKiller->GetPositionY();
		float SSZ = mKiller->GetPositionZ();

		Creature* doctor = mKiller->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 1449);
		if(doctor)
			doctor->Emote(EMOTE_ONESHOT_CHEER);
	}
};

class SCRIPT_DECL BloodscalpClanHeads : public QuestScript 
{ 
public:

	void OnQuestComplete( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		GameObject* skull1 = mTarget->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(SSX, SSY, SSZ, 2551);
		if(skull1)
			return;

		Creature* Kin_weelay = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 2519);
		if(Kin_weelay == NULL)
			return;

		string msg1 = "Ah. Good ";
		msg1 += mTarget->GetName();
		msg1 += ". Now let us see what tale these heads tell...";
		Kin_weelay->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, msg1.c_str());
		Kin_weelay->CastSpell(Kin_weelay, dbcSpell.LookupEntry(3644), false);
		skull1->Despawn(5000);
		GameObject* skull2 = mTarget->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(SSX, SSY, SSZ, 2551);
		if(skull2)
			skull2->Despawn(5000);

		TimedEvent *te = TimedEvent::Allocate(this, new CallbackP1<BloodscalpClanHeads, Player*>(this, &BloodscalpClanHeads::SayAfterCast, mTarget), 0, 5000, 1);
		mTarget->event_AddEvent(te);
	}

	void SayAfterCast(Player* plr)
	{
		if( plr == NULL || plr->GetMapMgr() == NULL || plr->GetMapMgr()->GetInterface() == NULL )
			return;

		float SSX = plr->GetPositionX();
		float SSY = plr->GetPositionY();
		float SSZ = plr->GetPositionZ();

		Creature* Kin_weelay = plr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 2519);
		if(Kin_weelay == NULL)
			return;
		string msg = "There, ";
		msg += plr->GetName();
		msg += ". You may now speak to the Bloodscalp chief and his witchdoctor.";
		Kin_weelay->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, msg.c_str());
	}
};

class SCRIPT_DECL BacktoBootyBay : public QuestScript 
{ 
public:

	void OnQuestComplete( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float X = mTarget->GetPositionX();
		float Y = mTarget->GetPositionY();
		float Z = mTarget->GetPositionZ();

		Creature* Crank = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(X, Y, Z, 2498);
		if(Crank)
		{
			string say = "Hm... if you're looking to adle wits. ";
			say += mTarget->GetName();
			say += ", then the secret behind Zanzil's zombies might just fo the trick!";
			Crank->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, say.c_str());
		}
	}
};

class SCRIPT_DECL VoodooDues : public QuestScript 
{ 
public:

	void OnQuestComplete( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float X = mTarget->GetPositionX();
		float Y = mTarget->GetPositionY();
		float Z = mTarget->GetPositionZ();

		Creature* MacKinley = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(X, Y, Z, 2501);
		if(MacKinley)
		{
			string say = "Bah! ";
			say += mTarget->GetName();
			say += ", this foot won't budge!";
			MacKinley->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, say.c_str());
		}
	}
};

class DashelStonefist : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(DashelStonefist);
	DashelStonefist(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 12);
		_unit->SetStandState(STANDSTATE_STAND);
	}

	void OnDamageTaken(Unit* mAttacker, float fAmount)
	{
		uint32 chance = RandomUInt(100);
		if(chance < 15)
		{
			string say = "Now you're gonna get it good, ";
			say+=((Player*)mAttacker)->GetName();
			say+="!";
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, say.c_str());
		}
		if(_unit->GetUInt32Value(UNIT_FIELD_HEALTH)- fAmount<=_unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*0.2)
		{
			if(mAttacker->GetTypeId() == TYPEID_PLAYER)
			{
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
				RegisterAIUpdateEvent(1000);
				QuestLogEntry *qle = ((Player*)mAttacker)->GetQuestLogForEntry(1640);
				if(!qle)
					return;
				qle->SendQuestComplete();
			}
		}
	}

	void AIUpdate()
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Okay, okay! Enough fighting. No one else needs to get hurt.");
		_unit->RemoveNegativeAuras();
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 12);
		_unit->SetHealthPct(100);      
		_unit->GetAIInterface()->WipeTargetList();         
		_unit->GetAIInterface()->WipeHateList();
        _unit->GetAIInterface()->HandleEvent( EVENT_LEAVECOMBAT, _unit, 0);
        _unit->GetAIInterface()->disable_melee = true;
        _unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
	}
};

class SCRIPT_DECL TheMissingDiplomat : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* Dashel = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 4961);

		if(Dashel == NULL)
			return;

		Dashel->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 72);
		Dashel->GetAIInterface()->disable_melee = false;
		Dashel->GetAIInterface()->SetAllowedToEnterCombat(true);
	}
};

class ThePathoftheAdept : public GameObjectAIScript
{
public:
	ThePathoftheAdept(GameObject* goinstance) : GameObjectAIScript(goinstance) {}
	static GameObjectAIScript *Create(GameObject * GO) { return new ThePathoftheAdept(GO); }

	void OnActivate(Player * pPlayer)
	{
		if(!pPlayer)
			return;

		QuestLogEntry *qle = pPlayer->GetQuestLogForEntry(9692);
		if(qle == NULL)
			return;

		Creature *zelemar = sEAS.SpawnCreature(pPlayer, 17830, pPlayer->GetPositionX()+5, pPlayer->GetPositionY()+5, pPlayer->GetPositionZ(), pPlayer->GetOrientation(), 0);
		zelemar->Despawn(6*60*1000, 0);
	}
};


class SCRIPT_DECL PathoftheAdept : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature *lord = (Creature*)(pObject);
		if (lord == NULL)
			return;

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
			if(plr->GetQuestLogForEntry(9692))
			Menu->AddItem( 0, "Take Insignia", 1);

		if(AutoSend)
			Menu->SendTo(plr);
	}

	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature *lord = (Creature*)(pObject);
		if (lord == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;

			case 1:
			{
				sEAS.AddItem(24226, plr);
				return;
			}break;
		}
	}

	void Destroy()
	{
		delete this;
	}
};


class LordDawnstar : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(LordDawnstar);
	LordDawnstar(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_NPC_FLAGS, 1);
		_unit->SetStandState(7);
		_unit->setDeathState(CORPSE);
		_unit->GetAIInterface()->m_canMove = false;
	}
};

class SCRIPT_DECL MissingInAction : public QuestScript
{
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();


		Creature* creat = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 349);
				if(creat == NULL)
			return;
		creat->m_escorter = mTarget;
		creat->GetAIInterface()->setMoveType(11);
		creat->GetAIInterface()->StopMovement(3000);
		creat->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Okay let's do!");
		creat->SetUInt32Value(UNIT_NPC_FLAGS, 0);

		sEAS.CreateCustomWaypointMap(creat);
		sEAS.WaypointCreate(creat,-8769.745117f, -2186.538818f, 141.841599f, 3.457182f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8783.108398f, -2197.826416f, 140.165878f, 3.597175f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8828.141602f, -2188.636963f, 138.618134f, 4.815924f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8809.825195f, -2233.663574f, 144.356613f, 5.723056f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8795.662109f, -2242.221436f, 146.450958f, 5.408901f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8775.052734f, -2261.419922f, 149.575378f, 0.355398f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8690.659180f, -2241.627930f, 153.590225f, 5.829625f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8664.609375f, -2254.313232f, 154.770416f, 4.164592f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8675.779297f, -2278.719482f, 155.470612f, 4.643681f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8679.915039f, -2324.837646f, 155.916428f, 3.819015f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8760.700195f, -2386.090088f, 156.647003f, 4.206810f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8810.614258f, -2479.427246f, 133.146484f, 3.788514f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8927.923828f, -2590.238525f, 132.446716f, 3.439012f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-8992.492188f, -2607.978516f, 130.872818f, 2.472971f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-9123.129883f, -2498.676270f, 116.559822f, 1.946754f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-9165.129883f, -2376.718994f, 94.946968f, 2.406212f, 0, 256, 1826);
		sEAS.WaypointCreate(creat,-9278.547852f, -2296.741699f, 68.041824f, 2.861743f, 0, 256, 1826);
	}
};

class Corporal_Keeshan : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Corporal_Keeshan);
	Corporal_Keeshan(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if(iWaypointId == 19)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Tell Marshal Marris. I'm outta here!");
			_unit->Despawn(5000,1000);
			sEAS.DeleteWaypoints(_unit);
			if(_unit->m_escorter == NULL)
				return;
			Player* plr = _unit->m_escorter;
			_unit->m_escorter = NULL;
			plr->GetQuestLogForEntry(219)->SendQuestComplete();
		}
	}
};

class SCRIPT_DECL Lady_Jaina : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player * plr, bool AutoSend)
	{
		GossipMenu *Menu;
		if(plr->GetQuestLogForEntry(558))
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 7012, plr);
			Menu->AddItem(0, "I know this is rather silly but i have a young ward who is a bit shy and would like your autograph.", 1);
			Menu->SendTo(plr);
		}
	}

	void GossipSelectOption(Object* pObject, Player * plr, uint32 Id, uint32 IntId, const char * Code)
	{
		Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
		if(pObject==NULL)
			return;

		switch(IntId)
		{
		case 0: // Return to start
			GossipHello(pCreature, plr, true);
			break;
		case 1: // Give Item
			{
				plr->CastSpell(plr, dbcSpell.LookupEntry(23122),true);
				plr->Gossip_Complete();
				break;
			}
			break;
		}
	}

	void Destroy()
	{
		delete this;
	}
};

class SCRIPT_DECL Cairne : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player * plr, bool AutoSend)
	{
		GossipMenu *Menu;
		if(plr->GetQuestLogForEntry(925))
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 7013, plr);
			Menu->AddItem(0, "Give me hoofprint.", 1);
			Menu->SendTo(plr);
		}
	}

	void GossipSelectOption(Object* pObject, Player * plr, uint32 Id, uint32 IntId, const char * Code)
	{
		GossipMenu *Menu;
		Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
		if(pObject==NULL)
			return;

		switch(IntId)
		{
		case 0: // Return to start
			GossipHello(pCreature, plr, true);
			break;
		case 1: // Give Item
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 7014, plr);
				Menu->SendTo(plr);
				plr->CastSpell(plr, dbcSpell.LookupEntry(23123),true);
				break;
			}
			break;
		}
	}

	void Destroy()
	{
		delete this;
	}
};

class SCRIPT_DECL Veronia : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* Plr, bool AutoSend)
	{
		GossipMenu *Menu;
		if(Plr->GetQuestLogForEntry(10652))
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem( 0, "I'm ready", 1);
			Menu->SendTo(Plr);
		}
	}

	void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
	{
		Creature* creat = static_cast<Creature*>(pObject);
		switch(IntId)
		{
		case 1:
			creat->CastSpell(Plr, dbcSpell.LookupEntry(34905), true);
			break;
		}
	}
}; 

bool InducingVision(uint32 i, Spell * pSpell)
{
		if(!pSpell->p_caster) return true;
		Player *mTarget = pSpell->p_caster;
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return true;
		  Creature *creat = mTarget->GetMapMgr()->GetInterface()->SpawnCreature(2983, -2238.994873f, -408.009552f, -9.424423f, 5.753043f, true, false, 0, 0);
		  creat->GetAIInterface()->setMoveType(11);

		  sEAS.CreateCustomWaypointMap(creat);

		  sEAS.WaypointCreate(creat,-2240.521729f, -407.114532f, -9.424648f, 5.753043f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-2225.764404f, -419.251404f, -9.360950f, 5.575544f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-2200.883789f, -440.999634f, -5.606637f, 5.599899f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-2143.712646f, -468.068665f, -9.401191f, 0.797177f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-2100.811279f, -420.980194f, -5.322747f, 0.918914f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-2079.469482f, -392.465576f, -10.262321f, 0.930689f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-2043.699707f, -343.802155f, -6.971242f, 0.934694f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-2001.858521f, -242.533966f, -10.763200f, 0.952265f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1924.751343f, -119.969292f, -11.770116f, 0.754775f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1794.804565f, -7.919222f, -9.326016f, 0.711578f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1755.206421f, 72.430847f, 1.121445f, 1.103484f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1734.550049f, 116.842003f, -4.337420f, 3.350100f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1720.041870f, 125.933235f, -2.325089f, 0.903206f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1704.406860f, 183.596405f, 12.065074f, 0.691148f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1674.317261f, 201.597565f, 11.235887f, 0.475164f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1624.068726f, 223.555389f, 2.074259f, 0.416259f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1572.863403f, 234.714813f, 2.305119f, 0.781471f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1542.866943f, 277.896759f, 20.543165f, 1.256637f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1541.813232f, 316.415649f, 49.910889f, 1.248783f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1526.979126f, 329.664001f, 61.835552f, 1.182024f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1524.173584f, 335.237610f, 63.325703f, 1.173092f, 0, 256, 0);
		  sEAS.WaypointCreate(creat,-1513.968506f, 355.759338f, 63.064487f, 1.119193f, 0, 256, 0);
		  return true;
}


		
class The_Plains_Vision : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(The_Plains_Vision);
	The_Plains_Vision(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if(iWaypointId == 2)
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You follow me.");
		if(iWaypointId == 22)
		{
			sEAS.DeleteWaypoints(_unit);
			_unit->Despawn(500,0);
		}
	}
};

class Miran : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Miran);
	Miran(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if(iWaypointId == 7)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Thanks, I'm outta here!");
			_unit->Despawn(5000,1000);
			sEAS.DeleteWaypoints(_unit);
			if(_unit->m_escorter == NULL)
				return;
			Player* plr = _unit->m_escorter;
			_unit->m_escorter = NULL;
			plr->GetQuestLogForEntry(309)->SendQuestComplete();
		}
	}
};

bool BaronVardusAllowSpawn = true;

class SCRIPT_DECL WantedBaronVardus : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		if(BaronVardusAllowSpawn == true)
		{
			uint32 rand = RandomUInt(3);
			switch(rand)
			{
			case 0: mTarget->GetMapMgr()->GetInterface()->SpawnCreature(2306, 692.64f, -904.74f, 157.79f, 0, true, false, 0, 0)->Despawn(1800000, 0);
			case 1: mTarget->GetMapMgr()->GetInterface()->SpawnCreature(2306, 939.0f, -852.46f, 114.644f, 0, true, false, 0, 0)->Despawn(1800000, 0);
			case 2: mTarget->GetMapMgr()->GetInterface()->SpawnCreature(2306, 1184.07f, -553.43f, 71.3346f, 0, true, false, 0, 0)->Despawn(1800000, 0);
			case 3: mTarget->GetMapMgr()->GetInterface()->SpawnCreature(2306, 1001.20f, -793.93f, 108.65f, 0, true, false, 0, 0)->Despawn(1800000, 0);
			}
			BaronVardusAllowSpawn = false;
		}
	}
};

class Baron_Vardus : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Baron_Vardus);
	Baron_Vardus(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnDied(Unit *mKiller) 
	{
		BaronVardusAllowSpawn = true;
	}
};

class SCRIPT_DECL Prisoner12 : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;
		GossipMenu *Menu;
		Creature *Prisoner12 = (Creature*)(pObject);
		if (Prisoner12 == NULL)
			return;
		
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
		if(plr->GetQuestLogForEntry(9164))
			Menu->AddItem( 0, "Release Him.", 1);
	 
		if(AutoSend)
			Menu->SendTo(plr);
	}
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature *Prisoner12 = (Creature*)(pObject);
		if (Prisoner12 == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;
 
			case 1:
			{
			QuestLogEntry *en = plr->GetQuestLogForEntry(9164);
			if(en && en->GetMobCount(0) < en->GetQuest()->required_mobcount[0])
			{
				en->SetMobCount(0, en->GetMobCount(0) + 1);
				en->SendUpdateAddKill(0);
				en->UpdatePlayerFields();

				if(!Prisoner12)
					return;

				Prisoner12->Despawn(5000, 6*60*1000);
				Prisoner12->SetStandState(STANDSTATE_STAND);
				Prisoner12->SetUInt32Value(UNIT_NPC_EMOTESTATE, 7);
				return;
			}break;
			}
		}
	}
 
	void Destroy()
	{
		delete this;
	}
};


class SCRIPT_DECL Prisoner22 : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature *Prisoner22 = (Creature*)(pObject);
		if (Prisoner22 == NULL)
			return;
			
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
		if(plr->GetQuestLogForEntry(9164))
			Menu->AddItem( 0, "Release Him.", 1);
	 
		if(AutoSend)
			Menu->SendTo(plr);
	}
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature *Prisoner22 = (Creature*)(pObject);
		if (Prisoner22 == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;
 
			case 1:
			{
			QuestLogEntry *en = plr->GetQuestLogForEntry(9164);
			if(en && en->GetMobCount(1) < en->GetQuest()->required_mobcount[1])
			{
				en->SetMobCount(1, en->GetMobCount(1) + 1);
				en->SendUpdateAddKill(1);
				en->UpdatePlayerFields();

				if(!Prisoner22)
					return;

				Prisoner22->Despawn(5000, 6*60*1000);
				Prisoner22->SetStandState(STANDSTATE_STAND);
				Prisoner22->SetUInt32Value(UNIT_NPC_EMOTESTATE, 7);
				return;
			}break;
			}
		}
	}
 
	void Destroy()
	{
		delete this;
	}
};


class SCRIPT_DECL Prisoner32 : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature *Prisoner32 = (Creature*)(pObject);
		if (Prisoner32 == NULL)
			return;

		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
		if(plr->GetQuestLogForEntry(9164))
			Menu->AddItem( 0, "Release Him.", 1);
	 
		if(AutoSend)
			Menu->SendTo(plr);
	}
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature *Prisoner32 = (Creature*)(pObject);
		if (Prisoner32 == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;
 
			case 1:
			{
			QuestLogEntry *en = plr->GetQuestLogForEntry(9164);
			if(en && en->GetMobCount(2) < en->GetQuest()->required_mobcount[2])
			{
				en->SetMobCount(2, en->GetMobCount(2) + 1);
				en->SendUpdateAddKill(2);
				en->UpdatePlayerFields();

				if(!Prisoner32)
					return;

				Prisoner32->Despawn(5000, 6*60*1000);
				Prisoner32->SetStandState(STANDSTATE_STAND);
				Prisoner32->SetUInt32Value(UNIT_NPC_EMOTESTATE, 7);
				return;
			}break;
			}
		}
	}
 
	void Destroy()
	{
		delete this;
	}
};

class PrisonersatDeatholme : public CreatureAIScript
{
public:
  ADD_CREATURE_FACTORY_FUNCTION(PrisonersatDeatholme);
  PrisonersatDeatholme(Creature* pCreature) : CreatureAIScript(pCreature) {}

  void OnLoad()
  {
	_unit->SetStandState(STANDSTATE_DEAD);
	_unit->GetAIInterface()->m_canMove = false;
  }
};

class VanquishingAquantion : public GameObjectAIScript
{
public:
	VanquishingAquantion(GameObject* goinstance) : GameObjectAIScript(goinstance) {}
	static GameObjectAIScript *Create(GameObject * GO) { return new VanquishingAquantion(GO); }

	void OnActivate(Player * pPlayer)
	{
		if(!pPlayer)
			return;

		QuestLogEntry *qle = pPlayer->GetQuestLogForEntry(9174);
		if(qle == NULL)
			return;

		Creature *naga = sEAS.SpawnCreature(pPlayer, 16292, 7938, -7632, 114, 3.05, 0);
		naga->Despawn(6*60*1000, 0);
	}
};

#define SAY_DOC1 "I'm saved! Thank you, doctor!"
#define SAY_DOC2 "HOORAY! I AM SAVED!"
#define SAY_DOC3 "Sweet, sweet embrace... take me..."


struct Location
{
	float x, y, z, o;
};

static Location AllianceCoords[]=
{
	{-3742.2626, -4536.9624, 14.2759, 3.6178}, // Far Left Bed, Behind
	{-3750.0925, -4540.1699, 14.2712, 3.5404}, // Far Left Bed
	{-3754.2653, -4539.0634, 14.1620, 5.1827}, // Left Bed
	{-3757.5134, -4532.7343, 14.1667, 5.1497}, // Right Bed
	{-3755.9040, -4529.0385, 14.0517, 0.4200}, // Far Right Bed
	{-3749.5649, -4526.9609, 14.0764, 5.1297}  // Far Right Bed, Behind
};

static Location HordeCoords[]=
{
	{-1013.75, -3492.59, 62.62, 4.34}, // Left, Behind
	{-1017.72, -3490.92, 62.62, 4.34}, // Right, Behind
	{-1015.77, -3497.15, 62.82, 4.34}, // Left, Mid
	{-1019.51, -3495.49, 62.82, 4.34}, // Right, Mid
	{-1017.25, -3500.85, 62.98, 4.34}, // Left, front
	{-1020.95, -3499.21, 62.98, 4.34}  // Right, Front
};

#define A_RUNTOX -3742.96
#define A_RUNTOY -4531.52
#define A_RUNTOZ 11.91

#define H_RUNTOX -1016.44
#define H_RUNTOY -3508.48
#define H_RUNTOZ 62.96


const uint32 allianceSoldierId[3] =
{
	12938, // 12938 Injured Alliance Soldier
	12936, // 12936 Badly injured Alliance Soldier
	12937  // 12937 Critically injured Alliance Soldier
};

const uint32 hordeSoldierId[3] =
{
	12923, //12923 Injured Soldier
	12924, //12924 Badly injured Soldier
	12925  //12925 Critically injured Soldier
};

class InjuredSoldier : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(InjuredSoldier);
	InjuredSoldier(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_0, 16777472);
		_unit->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
		_unit->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_COMBAT);
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_1,7);

		uint32 sid = _unit->GetEntry();

		switch(sid)
		{
		case 12923:
		case 12938:
			_unit->SetHealthPct(75);
			break;
		case 12924:
		case 12936:
			_unit->SetHealthPct(50);
			break;
		case 12925:
		case 12937:
			_unit->SetHealthPct(25);
			break;
		}

	}
};

bool Triage(uint32 i, Spell *pSpell)
{
	// Unit* target = pSpell->GetUnitTarget();
	// if(!pSpell->p_caster || !target || target->GetTypeId() != TYPEID_UNIT) return true;
	if(!pSpell->p_caster || pSpell->GetUnitTarget() == NULL) return true;
		pSpell->p_caster->CastSpell(pSpell->GetUnitTarget(), dbcSpell.LookupEntry(746), true);
		QuestLogEntry *en = pSpell->p_caster->GetQuestLogForEntry(6624);

			if(en && en->GetMobCount(0) < en->GetQuest()->required_mobcount[0])
		{
		uint32 newcount = en->GetMobCount(0) + 1;
		en->SetMobCount(0, newcount);
		en->SendUpdateAddKill(0);
		en->UpdatePlayerFields();
		}
	// Creature* c_target = (Creature*)target;
	// if(!c_target) return true;

	// uint32 creatureID = c_target->GetEntry();

	// if(creatureID == 12937)
		// sQuestMgr.OnPlayerKill(pSpell->p_caster, c_target);

	return true;
}

#define BALOS_FRIENDLY_TIMER 120
class BalosJackenQAI : public CreatureAIScript
{
public:
   ADD_CREATURE_FACTORY_FUNCTION(BalosJackenQAI);
	BalosJackenQAI(Creature* pCreature) : CreatureAIScript(pCreature)  
   {
	  friendlyTimer=BALOS_FRIENDLY_TIMER;
   }

	void OnDamageTaken(Unit* mAttacker, float fAmount)
	{ 
	   // If Balos Jacken HP - fAmount < 20%
	   if (_unit->GetUInt32Value(UNIT_FIELD_HEALTH)- fAmount<=_unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*0.2)
	   {
		  //Missing: modify fAmount to prevent Balos Jacken death.
		  //{...}
		  //force player to loose target and stop melee auto-attack:
		  _unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
		  //start AIUpdate
		  RegisterAIUpdateEvent(1000);
	   }
	}

	void AIUpdate()
	{   
	  if (friendlyTimer==BALOS_FRIENDLY_TIMER)
	  {
		 // set Balos Jacken friendly and start friendlyTimer cooldown
		 _unit->RemoveNegativeAuras();
		 _unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 35);   
		 _unit->SetHealthPct(100);		 
		 _unit->GetAIInterface()->WipeTargetList();		 
		 _unit->GetAIInterface()->WipeHateList();
		 _unit->GetAIInterface()->HandleEvent( EVENT_LEAVECOMBAT, _unit, 0);
		 _unit->GetAIInterface()->disable_melee = true;
		 _unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		 //remove not_selectable flag:
		 _unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		 // decrease timer
		 friendlyTimer--;
	  }
	  else if (friendlyTimer==0)
		 {
			// set Balos Jacken unfriendly and reset FriendlyTimer
			_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 14);
			_unit->GetAIInterface()->disable_melee = false;
			_unit->GetAIInterface()->SetAllowedToEnterCombat(true);
			friendlyTimer=BALOS_FRIENDLY_TIMER;
			RemoveAIUpdateEvent();
		 }
	  else
	  {
		 //friendlyTimer decrease
		 friendlyTimer--;	  
	  }
   }

	void OnDied(Unit *Mkiller)
	{
	  RemoveAIUpdateEvent();
	}
protected:
   short friendlyTimer;
};

class SCRIPT_DECL Cleansing_of_the_Orb_of_Orahil : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* creat = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 6546);

		if(creat == NULL)
			return;
		
		creat->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Fine, if you ready to go!");
		
		TimedEvent *te = TimedEvent::Allocate(this, new CallbackP1<Cleansing_of_the_Orb_of_Orahil, Creature*>(this, &Cleansing_of_the_Orb_of_Orahil::SumDemon, creat), 0, 12000, 1);
		creat->event_AddEvent(te);
		
		creat->GetAIInterface()->setMoveType(11);
		creat->GetAIInterface()->StopMovement(3000);
		
		sEAS.CreateCustomWaypointMap(creat);
		sEAS.WaypointCreate(creat,-4036.163818f, -3383.940918f, 38.977619f, 2.181819f, 0, 56, 5375);
		sEAS.WaypointCreate(creat,-4037.754639f, -3376.272461f, 37.400284f, 0.002337f, 0, 56, 5375);
		sEAS.WaypointCreate(creat,-4028.081787f, -3376.667969f, 38.152534f, 5.775016f, 0, 56, 5375);
		sEAS.WaypointCreate(creat,-4018.655029f, -3382.780518f, 38.244286f, 5.688624f, 0, 56, 5375);
		sEAS.WaypointCreate(creat,-4018.655029f, -3382.780518f, 38.244286f, 5.688624f, 11000, 256, 5375);
		sEAS.WaypointCreate(creat,-4028.081787f, -3376.667969f, 38.152534f, 5.775016f, 0, 256, 5375);
		sEAS.WaypointCreate(creat,-4037.754639f, -3376.272461f, 37.400284f, 0.002337f, 0, 256, 5375);
		sEAS.WaypointCreate(creat,-4036.163818f, -3383.940918f, 38.977619f, 2.181819f, 0, 256, 5375);
		sEAS.WaypointCreate(creat,-4036.1638f, -3383.9409f, 38.9776f, -1.3662f, 0, 256, 5375);
		sEAS.WaypointCreate(creat,-4032.5759f, -3393.6271f, 38.9960f, 1.8883f, 0, 256, 5375);
	}

	void SumDemon(Creature *creat)
	{
		creat->GetMapMgr()->GetInterface()->SpawnCreature(6549, creat->GetPositionX(), creat->GetPositionY(), creat->GetPositionZ(), creat->GetOrientation(), true, false, 0, 0)->Despawn(120000, 0);
	}
};

class OverlordMokMorokk : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(OverlordMokMorokk);
	OverlordMokMorokk(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 23);
		_unit->SetStandState(STANDSTATE_STAND);
	}

	void OnDamageTaken(Unit* mAttacker, float fAmount)
	{
		uint32 chance = RandomUInt(100);
		if(chance < 25)
		{
			_unit->CastSpell(mAttacker, dbcSpell.LookupEntry(6749), true);
		}
		if(_unit->GetUInt32Value(UNIT_FIELD_HEALTH)- fAmount<=_unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*0.3)
		{
			if(mAttacker->GetTypeId() == TYPEID_PLAYER)
			{
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
				RegisterAIUpdateEvent(1000);
				QuestLogEntry *qle = ((Player*)mAttacker)->GetQuestLogForEntry(1173);
				if(!qle)
					return;
				qle->SendQuestComplete();
			}
		}
	}

	void AIUpdate()
	{
		_unit->RemoveNegativeAuras();
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 29);
		_unit->SetHealthPct(100);      
		_unit->GetAIInterface()->WipeTargetList();         
		_unit->GetAIInterface()->WipeHateList();
        _unit->GetAIInterface()->HandleEvent( EVENT_LEAVECOMBAT, _unit, 0);
        _unit->GetAIInterface()->disable_melee = true;
        _unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
	}
};

class SCRIPT_DECL ChallengeOverlordMokMorokk : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* Overlord = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 4500);

		if(Overlord == NULL)
			return;

		string say = "Puny ";
		say+=mTarget->GetName();
		say+=" wanna fight Overlord Mok'Morokk? Me beat you! Me boss here!";
		Overlord->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, say.c_str());
		Overlord->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 72);
		Overlord->GetAIInterface()->disable_melee = false;
		Overlord->GetAIInterface()->SetAllowedToEnterCombat(true);
	}
};

class PrivateHendel : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(PrivateHendel);
	PrivateHendel(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 12);
		_unit->SetStandState(STANDSTATE_STAND);
	}

	void OnDamageTaken(Unit* mAttacker, float fAmount)
	{
		if(_unit->GetUInt32Value(UNIT_FIELD_HEALTH)- fAmount<=_unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*0.37)
		{
			if(mAttacker->GetTypeId() == TYPEID_PLAYER)
			{
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
				RegisterAIUpdateEvent(1000);
				QuestLogEntry *qle = ((Player*)mAttacker)->GetQuestLogForEntry(1324);
				if(!qle)
					return;
				qle->SendQuestComplete();
			}
		}
	}
					
	void AIUpdate()
	{
		_unit->Emote(EMOTE_STATE_KNEEL);
		_unit->RemoveNegativeAuras();
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 12);
		_unit->SetHealthPct(100);      
		_unit->GetAIInterface()->WipeTargetList();         
		_unit->GetAIInterface()->WipeHateList();
        _unit->GetAIInterface()->HandleEvent( EVENT_LEAVECOMBAT, _unit, 0);
        _unit->GetAIInterface()->disable_melee = true;
        _unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
	}
};

class SCRIPT_DECL TheMissingDiplomat2 : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* Dashel = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 4966);

		if(Dashel == NULL)
			return;

		Dashel->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 72);
		Dashel->GetAIInterface()->disable_melee = false;
		Dashel->GetAIInterface()->SetAllowedToEnterCombat(true);
	}
};

class SCRIPT_DECL ProtectingtheShipment : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();


		Creature* creat = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 5644);
		if(creat == NULL)
			return;		
		creat->m_escorter = mTarget;   
		creat->GetAIInterface()->setMoveType(11);
		creat->GetAIInterface()->StopMovement(3000);
		creat->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Ts...... I must be removed from this lair");
		creat->SetUInt32Value(UNIT_NPC_FLAGS, 0);

		sEAS.CreateCustomWaypointMap(creat);
		sEAS.WaypointCreate(creat,-336.599213f, 1764.957275f, 139.517746f, 4.461932f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-338.992798f, 1750.499023f, 139.414673f, 5.318010f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-327.872040f, 1734.572388f, 139.331665f, 3.382010f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-350.114044f, 1728.984741f, 139.337723f, 2.514144f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-372.413940f, 1745.675293f, 139.382660f, 3.872884f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-386.453796f, 1736.851685f, 137.771500f, 3.790415f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-400.639496f, 1728.250488f, 131.174881f, 3.511599f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-431.880005f, 1713.812378f, 127.584572f, 3.704021f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-453.655090f, 1700.086670f, 120.951744f, 4.261652f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-465.082306f, 1677.391113f, 111.065910f, 4.866406f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-462.129944f, 1665.744507f, 108.106010f, 4.257726f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-477.037445f, 1630.453857f, 99.003723f, 4.787863f, 1, 256, 3791);
		sEAS.WaypointCreate(creat,-474.509247f, 1590.814453f, 94.546768f, 5.197841f, 1, 256, 3791);
	}
};

class Dalinda_Malem  : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Dalinda_Malem );
	Dalinda_Malem (Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if(iWaypointId == 13)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Thanks, these orcs wanted me to weld in the boiler");
			_unit->Despawn(5000,1000);
			sEAS.DeleteWaypoints(_unit);
			if(_unit->m_escorter == NULL)
				return;
			Player* plr = _unit->m_escorter;
			_unit->m_escorter = NULL;
			plr->GetQuestLogForEntry(1440)->SendQuestComplete();
		}
	}
};

class TheKesselRun : public QuestScript
{	
public:
  void OnQuestStart(Player * mTarget, QuestLogEntry * qLogEntry)
  {
    if(!mTarget)
		return;
    if(!mTarget->HasSpell(30829))
      mTarget->CastSpell(mTarget, 30829, true);
  }
};



class SCRIPT_DECL TheKesselRun1 : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
		if(!plr)
			return;

        GossipMenu *Menu;
		Creature *highchief = (Creature*)(pObject);
		if (highchief == NULL)
			return;

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
			if(plr->GetQuestLogForEntry(9663))
			Menu->AddItem( 0, "Warn him", 1);
	 
		if(AutoSend)
			Menu->SendTo(plr);
    }
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
    {
		if(!plr)
			return;

		Creature *highchief = (Creature*)(pObject);
		if (highchief == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;
 
			case 1:
			{
			QuestLogEntry *en = plr->GetQuestLogForEntry(9663);
			if(en && en->GetMobCount(0) < en->GetQuest()->required_mobcount[0])
			{
				en->SetMobCount(0, en->GetMobCount(0) + 1);
				en->SendUpdateAddKill(0);
				en->UpdatePlayerFields();
				return;
			}break;
			}
		}
	}
 
    void Destroy()
    {
        delete this;
    }
};


class SCRIPT_DECL TheKesselRun2 : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
		if(!plr)
			return;

        GossipMenu *Menu;
		Creature *highchief = (Creature*)(pObject);
		if (highchief == NULL)
			return;

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
			if(plr->GetQuestLogForEntry(9663))
			Menu->AddItem( 0, "Warn him", 1);
	 
		if(AutoSend)
			Menu->SendTo(plr);
    }
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
    {
		if(!plr)
			return;

		Creature *highchief = (Creature*)(pObject);
		if (highchief == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;
 
			case 1:
			{
			QuestLogEntry *en = plr->GetQuestLogForEntry(9663);
			if(en && en->GetMobCount(1) < en->GetQuest()->required_mobcount[1])
			{
				en->SetMobCount(1, en->GetMobCount(1) + 1);
				en->SendUpdateAddKill(1);
				en->UpdatePlayerFields();
				return;
			}break;
			}
		}
	}
 
    void Destroy()
    {
        delete this;
    }
};


class SCRIPT_DECL TheKesselRun3 : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
		if(!plr)
			return;

        GossipMenu *Menu;
		Creature *highchief = (Creature*)(pObject);
		if (highchief == NULL)
			return;

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
			if(plr->GetQuestLogForEntry(9663))
			Menu->AddItem( 0, "Warn him", 1);
	 
		if(AutoSend)
			Menu->SendTo(plr);
    }
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
    {
		if(!plr)
			return;

		Creature *highchief = (Creature*)(pObject);
		if (highchief == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;
 
			case 1:
			{
			QuestLogEntry *en = plr->GetQuestLogForEntry(9663);
			if(en && en->GetMobCount(2) < en->GetQuest()->required_mobcount[2])
			{
				en->SetMobCount(2, en->GetMobCount(2) + 1);
				en->SendUpdateAddKill(2);
				en->UpdatePlayerFields();
				return;
			}break;
			}
		}
	}
 
    void Destroy()
    {
        delete this;
    }
};

//-----------------------------------------------------------------------------------------------------------------------

int fulborgskilled = 0;


class SavingPrincessStillpine : public GameObjectAIScript
{
public:
	SavingPrincessStillpine(GameObject* goinstance) : GameObjectAIScript(goinstance) {}
	static GameObjectAIScript *Create(GameObject * GO) { return new SavingPrincessStillpine(GO); }

	void OnActivate(Player * pPlayer)
	{
		if(!pPlayer)
			return;

		QuestLogEntry *qle = pPlayer->GetQuestLogForEntry(9667);
		if(qle == NULL)
			return;

		if(qle->GetMobCount(0) < qle->GetQuest()->required_mobcount[0])
		{
			qle->SetMobCount(0, qle->GetMobCount(0)+1);
			qle->SendUpdateAddKill(0);
			qle->UpdatePlayerFields();
		}

		Creature *princess = pPlayer->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(), 17682);
		if(!princess)
			return;

		princess->Despawn(1000, 6*60*1000);
		return;
	}
};

class HighChiefBristlelimb : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(HighChiefBristlelimb);
	HighChiefBristlelimb(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnDied(Unit *mKiller)
	{
		fulborgskilled++;
		if(mKiller->IsPlayer())
		{
			Player* mPlayer = static_cast< Player* >( mKiller );

			if(fulborgskilled > 8&& mPlayer->GetQuestLogForEntry( 9667 ))
			{
				_unit->GetMapMgr()->GetInterface()->SpawnCreature(17702, -2419, -12166, 33, 3.45f, true, false, 0, 0)->Despawn(18000000, 0);
				fulborgskilled = 0;
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Chief, we need your help!");
			}
		}
	}

};

class HeroesofOld : public QuestScript
{	
public:
  void OnQuestStart(Player * mTarget, QuestLogEntry * qLogEntry)
  {
	  if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
		  return;

	Creature *spawncheckcr = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(mTarget->GetPositionX(), mTarget->GetPositionY(), mTarget->GetPositionZ(), 7750);

	if(!spawncheckcr)
	{
		Creature *general = sEAS.SpawnCreature(mTarget, 7750, -10619, -2997, 28.8, 4, 0);
		general->Despawn(3*60*1000, 0);
	}

	GameObject *spawncheckgobj = mTarget->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(mTarget->GetPositionX(), mTarget->GetPositionY(),mTarget->GetPositionZ(), 141980);

	if(!spawncheckgobj)
	{
		GameObject *generalsbox = sEAS.SpawnGameobject(mTarget, 141980, -10622, -2994, 28.6, 4, 4);
		sEAS.GameobjectDelete(generalsbox, 3*60*1000);
	}
  }
};



class SCRIPT_DECL HeroesofOld1 : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature *general = (Creature*)(pObject);
		if (general == NULL)
			return;

		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
		if(plr->GetQuestLogForEntry(2702) || plr->HasFinishedQuest(2702))
			Menu->AddItem( 0, "I need to speak with Corporal.", 1);
	 
		if(AutoSend)
			Menu->SendTo(plr);
	}
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature *general = (Creature*)(pObject);
		if (general == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;
 
			case 1:
			{
				Creature *spawncheckcr = plr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), 7750);

				if(!spawncheckcr)
				{
					Creature *general = sEAS.SpawnCreature(plr, 7750, -10619, -2997, 28.8, 4, 0);
					general->Despawn(3*60*1000, 0);
				}

				GameObject *spawncheckgobj = plr->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), 141980);

				if(!spawncheckgobj)
				{
					GameObject *generalsbox = sEAS.SpawnGameobject(plr, 141980, -10622, -2994, 28.6, 4, 4);
					sEAS.GameobjectDelete(generalsbox, 3*60*1000);
				}
			}
		}
	}
 
	void Destroy()
	{
		delete this;
	}
};

class SCRIPT_DECL SunkenTreasure : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* creat = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 2768);
		if(creat == NULL)
			return;
		creat->m_escorter = mTarget;   
		creat->GetAIInterface()->setMoveType(11);
		creat->GetAIInterface()->StopMovement(3000);
		creat->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Defens Me!");
		creat->SetUInt32Value(UNIT_NPC_FLAGS, 0);

		sEAS.CreateCustomWaypointMap(creat);
		sEAS.WaypointCreate(creat,-2078.054443f, -2091.207764f, 9.526212f, 4.770276f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2076.626465f, -2109.960449f, 14.320494f, 4.821321f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2072.851074f, -2123.574219f, 18.482662f, 5.623996f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2063.878906f, -2132.617920f, 21.430487f, 5.512474f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2051.495117f, -2145.205811f, 20.500065f, 5.481060f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2044.748291f, -2152.411377f, 20.158432f, 5.437863f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2044.748291f, -2152.411377f, 20.158432f, 5.437863f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2044.748291f, -2152.411377f, 20.158432f, 5.437863f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2044.748291f, -2152.411377f, 20.158432f, 5.437863f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2044.748291f, -2152.411377f, 20.158432f, 5.437863f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2051.495117f, -2145.205811f, 20.500065f, 5.481060f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2063.878906f, -2132.617920f, 21.430487f, 5.512474f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2072.851074f, -2123.574219f, 18.482662f, 5.623996f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2076.626465f, -2109.960449f, 14.320494f, 4.821321f, 0, 256, 4049);
		sEAS.WaypointCreate(creat,-2078.054443f, -2091.207764f, 9.526212f, 4.770276f, 0, 256, 4049);
	}
};

class Professor_Phizzlethorpe : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Professor_Phizzlethorpe);
	Professor_Phizzlethorpe(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if(iWaypointId == 15)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Thanks, I found the fact that, it searched");
			_unit->Despawn(5000,1000);
			sEAS.DeleteWaypoints(_unit);
			if(_unit->m_escorter == NULL)
				return;
			Player* plr = _unit->m_escorter;
			_unit->m_escorter = NULL;
			plr->GetQuestLogForEntry(665)->SendQuestComplete();
		}
	}
};

/************************************************************************/
/*										  Arximag Teleport  Azshara													*/
/************************************************************************/

class SCRIPT_DECL ArximagTeleportDown : public GossipScript
{
public:
	void Destroy()
	{
		delete this;
	}
	void GossipHello(Object* pObject, Player * Plr, bool AutoSend)
	{
		GossipMenu *Menu;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1994, Plr);

		Menu->AddItem(0, "[i am, ready]", 1);

		if(AutoSend)
			Menu->SendTo(Plr);
	}
	void GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
	{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
	{
		return;
		}
		GossipMenu * Menu;
		switch(IntId)
		{
		case 0:
			GossipHello(pObject, Plr, true);
			break;
		case 1:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1994, Plr);
				 Plr->EventTeleport(1, 3649.567627, -4705.155762, 120.966309);
			}break;
		}
	}
};

class SCRIPT_DECL ArximagTeleportUp : public GossipScript
{
public:
	void Destroy()
	{
		delete this;
	}
	void GossipHello(Object* pObject, Player * Plr, bool AutoSend)
	{
		GossipMenu *Menu;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);

		Menu->AddItem(0, "[i am, ready]", 1);


		if(AutoSend)
			Menu->SendTo(Plr);
	}
	void GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
	{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
	{
		return;
		}

		GossipMenu * Menu;
		switch(IntId)
		{
		case 0:
			GossipHello(pObject, Plr, true);
			break;
		case 1:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				 Plr->EventTeleport(1, 3778.438721, -4612.299805, 227.253922);
			}break;
		}
	}
};

class SCRIPT_DECL HomewardBound : public QuestScript
{
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* creat = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 10427);
		if(creat == NULL)
			return;
		creat->m_escorter = mTarget;
		creat->GetAIInterface()->setMoveType(11);
		creat->GetAIInterface()->SetAllowedToEnterCombat(false);
		creat->GetAIInterface()->StopMovement(3000);
		creat->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Please help me, you gotta protect me and stuff, I can't fight on my own!");
		creat->SetUInt32Value(UNIT_NPC_FLAGS, 0);

		sEAS.CreateCustomWaypointMap(creat);
		sEAS.WaypointCreate(creat,-5005.66f, -882.705f, -6.05186f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4968.67f, -937.131f, -4.99042f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4968.03f, -958.455f, -5.53631f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4968.48f, -986.432f, -4.80345f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4975.32f, -998.646f, -5.12671f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4970.91f, -1014.12f, -5.47358f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4963.23f, -1026.1f, -4.9985f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4957.29f, -1035.31f, -5.62972f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4952.49f, -1042.99f, -8.61785f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4946.27f, -1053.72f, -15.9727f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4936.83f, -1054.79f, -22.0583f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4929.3f, -1054.22f, -25.8246f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4917.66f, -1051.53f, -30.242f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4909.1f, -1049.48f, -33.0802f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4902.48f, -1052.76f, -33.4847f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4904.48f, -1056.73f, -33.8546f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4910.38f, -1064.18f, -38.8506f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4914.76f, -1069.12f, -42.8664f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4918.88f, -1073.68f, -45.7238f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4924.54f, -1078.76f, -48.3099f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4931.68f, -1084.4f, -51.0179f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4926.66f, -1090.7f, -53.2325f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4919.66f, -1096.19f, -53.3382f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4911.05f, -1099.43f, -53.7044f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4903.92f, -1102.06f, -54.9974f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4897.52f, -1101.48f, -55.4563f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4896.49f, -1104.66f, -55.2742f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4894.82f, -1110.74f, -53.9336f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4892.71f, -1118.51f, -51.0561f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4888.98f, -1125.24f, -50.4447f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4884.62f, -1131.47f, -50.44f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4880.34f, -1137.57f, -50.5127f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4875.03f, -1144.52f, -50.5812f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4868.65f, -1152.74f, -50.9722f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4860.4f, -1160.88f, -50.6212f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4854.03f, -1167.17f, -49.6659, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4849.72f, -1171.42f, -48.9519f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4844.17f, -1176.9f, -48.3381f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4841.19f, -1182.11f, -48.7754f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4836.73f, -1189.87f, -49.3734f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4841.24f, -1195.48f, -49.4889f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4848.26f, -1198.64f, -49.3465f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4855.31f, -1202.44f, -48.8531f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4862.2f, -1206.18f, -48.6235f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4869.06f, -1209.9f, -46.1434f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4877.32f, -1214.39f, -44.1166f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4885.63f, -1218.9f, -43.5811f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4893.63f, -1223.24f, -42.5644f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4899.27f, -1228.69f, -42.2637f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4906.03f, -1235.23f, -41.9083f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4911.57f, -1240.58f, -42.9282f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4916.96f, -1245.79f, -43.973f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4921.24f, -1249.92f, -45.7031f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4924.52f, -1256.67f, -46.0392f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4927.78f, -1263.37f, -46.5725f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4932.77f, -1273.62f, -47.139f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4935.51f, -1279.24f, -47.1182f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4935.57f, -1285.64f, -46.7144f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4935.14f, -1293.67f, -46.2301f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4934.16f, -1302.12f, -46.1045f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4933.4f, -1308.37f, -46.5583f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4931.24f, -1315.97f, -47.6485f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4929.03f, -1323.71f, -48.8701f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4926.87f, -1331.31f, -49.926f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4922.54f, -1338.16f, -50.7557f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4917.05f, -1344.31f, -51.2097f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4910.32f, -1348.82f, -51.5222f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4903.97f, -1353.76f, -50.9117f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4901.07f, -1361.11f, -51.4375f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4901.38f, -1369.51f, -52.6119f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4904.58f, -1376.73f, -52.6119f, 3.098398f, 0, 256, 9900);
		sEAS.WaypointCreate(creat,-4910.54f, -1378.76f, -52.6119f, 3.098398f, 0, 256, 9900);
	}
};

class Paoka_Swiftmountain : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Paoka_Swiftmountain);
	Paoka_Swiftmountain(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if(iWaypointId == 72)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I appreciate the help you have shown Pao'ka. I hope this covers any misfortunes this deed has cost you.");
			_unit->Despawn(5000,1000);
			sEAS.DeleteWaypoints(_unit);
			if(_unit->m_escorter == NULL)
				return;
			Player* plr = _unit->m_escorter;
			_unit->m_escorter = NULL;
			plr->GetQuestLogForEntry(4770)->SendQuestComplete();
		}
	}
};

class SCRIPT_DECL RumorsforKravel : public QuestScript
{
public:

	void OnQuestComplete( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* creat = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 4452);
		if(creat == NULL)
			return;

		string msg = "Hahah! ";
		msg += mTarget->GetName();
		msg += ", you make quite a partner!";
		creat->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, msg.c_str());
		creat->Emote(EMOTE_ONESHOT_LAUGH);
	}
};

class SCRIPT_DECL TheDormantShade : public QuestScript
{
public:
	void OnQuestComplete( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		Creature *creat = mTarget->GetMapMgr()->GetInterface()->SpawnCreature(1946, 2467.314f, 14.8471f, 23.5950f, 0, true, false, 0, 0);
		creat->Despawn(60000,0);
		creat->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have disturbed my rest. Now face my wrath!");
	}
};

class CalvinMontague : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(CalvinMontague);
	CalvinMontague(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 68);
		_unit->SetStandState(STANDSTATE_STAND);
	}

	void OnDamageTaken(Unit* mAttacker, float fAmount)
	{
		if(_unit->GetHealthPct() < 10)
		{
			if(mAttacker->GetTypeId() == TYPEID_PLAYER)
			{
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
				RegisterAIUpdateEvent(1000);
				QuestLogEntry *qle = ((Player*)mAttacker)->GetQuestLogForEntry(590);
				if(!qle)
					return;
				qle->SendQuestComplete();
			}
		}
	}

	void AIUpdate()
	{
		_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Okay, okay! Enough fighting.");
		_unit->RemoveNegativeAuras();
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 68);
		_unit->SetStandState(STANDSTATE_SIT);
		_unit->CastSpell(_unit, dbcSpell.LookupEntry(433), true);
		TimedEvent *te = TimedEvent::Allocate(this, new CallbackP1<CalvinMontague, Creature*>(this, &CalvinMontague::Stand, _unit), 0, 18000, 1);
		_unit->event_AddEvent(te);
		_unit->GetAIInterface()->WipeTargetList();         
		_unit->GetAIInterface()->WipeHateList();
        _unit->GetAIInterface()->HandleEvent( EVENT_LEAVECOMBAT, _unit, 0);
        _unit->GetAIInterface()->disable_melee = true;
        _unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
	}

	void Stand(Creature* creat)
	{
		creat->SetStandState(STANDSTATE_STAND);
	}
};

class SCRIPT_DECL ARoguesDeal  : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* Dashel = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 6784);

		if(Dashel == NULL)
			return;

		Dashel->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 28);
		Dashel->GetAIInterface()->disable_melee = false;
		Dashel->GetAIInterface()->SetAllowedToEnterCombat(true);
	}
};

class SCRIPT_DECL FieldsofGrief : public QuestScript 
{ 
public:

	void OnQuestComplete( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* Zealot = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 1931);

		if(Zealot == NULL)
			return;

		Zealot->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I. . . I. . .don't. . .feel. . .right. . .");
		sEAS.EventCastSpell(Zealot, Zealot, 3287, 3000);
		Zealot->GetAIInterface()->setMoveType(11);
		Zealot->GetAIInterface()->StopMovement(3000);


		sEAS.CreateCustomWaypointMap(Zealot);

		sEAS.WaypointCreate(Zealot, 2289.649658f, 237.001389f, 27.089531f, 1.323f, 0, 256, 0);
		sEAS.WaypointCreate(Zealot, 2291.700928f, 235.561844f, 27.089531f, 1.323f, 0, 256, 0);
		sEAS.WaypointCreate(Zealot, 2292.835693f, 240.636948f, 27.089531f, 1.323f, 0, 256, 0);
		sEAS.WaypointCreate(Zealot, 2288.737305f, 240.503952f, 27.088022f, 1.323f, 0, 256, 0);
		sEAS.WaypointCreate(Zealot, 2287.812744f, 236.320938f, 27.088022f, 1.323f, 0, 256, 0);
		sEAS.WaypointCreate(Zealot, 2292.643033f, 240.513489f, 27.088022f, 1.323f, 0, 256, 0);
		sEAS.WaypointCreate(Zealot, 2289.628418f, 239.908279f, 27.088022f, 1.323f, 0, 256, 0);
	}
};

class Zealot : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Zealot);
	Zealot(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if(!_unit->HasAura(3287))
			return;
		if(iWaypointId == 2)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "My mind. . .me flesh. . .I'm. . .rotting. . . .!");
		}

		if(iWaypointId == 7)
		{
			_unit->CastSpell(_unit, dbcSpell.LookupEntry(5), true);
		}
	}
};

class SCRIPT_DECL Quest_Grimoire_Business : public QuestScript
{
public:
	void OnQuestStart(Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		sEAS.SpawnCreature(mTarget, 22911, 3279.67f, 4640.77f, 216.526f, 1.3516f, 2*60*1000);
	}

};

class SCRIPT_DECL Quest_Maggocs_Treasure_Chest : public QuestScript
{
public:
	void OnQuestStart(Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		mTarget->GetMapMgr()->GetInterface()->SpawnCreature(20600, 2001.76f, 5164.77f, 265.19f, 5.5148f, true, false, 0, 0);
	}

};

class SCRIPT_DECL Quest_Grulloc_Has_Two_Skulls : public QuestScript
{
public:
	void OnQuestStart(Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		sEAS.SpawnCreature(mTarget, 20216, 2687.46f, 5541.14f, -1.93669f, 3.52847f, 2*60*1000);
	}

};

class SCRIPT_DECL Quest_Zuluhed_the_Whacked : public QuestScript
{
public:
	void OnQuestStart(Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		sEAS.SpawnCreature(mTarget, 11980, -4177.39f, 376.289f, 117.78f, 2.7381f, 2*60*1000);
	}

};

#define QUEST_CLUCK		 3861
#define ITEM_CHICKEN_FEED   11109

class Chicken : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Chicken);
	Chicken(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 12);
		_unit->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
		RegisterAIUpdateEvent(120000);
	}

	void AIUpdate()
	{
		if(_unit->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
			OnLoad();
	}
};

class SCRIPT_DECL TheSummoning : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature *windwatcher = (Creature*)(pObject);
		if (windwatcher == NULL)
			return;

		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
		if(plr->GetQuestLogForEntry(1713))
			Menu->AddItem( 0, "I'm ready, Summon Him!", 1);

		if(AutoSend)
			Menu->SendTo(plr);
	}

	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature *windwatcher = (Creature*)(pObject);
		if (windwatcher == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;

			case 1:
			{
			if(plr == NULL || plr->GetMapMgr() == NULL || plr->GetMapMgr()->GetInterface() == NULL)
				return;
				Creature *whirlwind = plr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), 6239);
				if(whirlwind != NULL)
				{
					if(!whirlwind->isAlive())
					{
						whirlwind->Delete();
					}
					else
						return;
				}

				whirlwind = sEAS.SpawnCreature(plr, 6239, plr->GetPositionX()+7, plr->GetPositionY()+7, plr->GetPositionZ(), plr->GetOrientation(), 0);
				whirlwind->Despawn(5*60*1000, 0);
			}break;
		}
	}

	void Destroy()
	{
		delete this;
	}
};

class Bartleby : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Bartleby);
	Bartleby(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 11);
		_unit->setEmoteState(7);
	}

	void OnDamageTaken(Unit* mAttacker, float fAmount)
	{
		if(_unit->GetUInt32Value(UNIT_FIELD_HEALTH)- fAmount<=_unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*0.37)
		{
			if(mAttacker->GetTypeId() == TYPEID_PLAYER)
			{
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
				RegisterAIUpdateEvent(1000);
				QuestLogEntry *qle = ((Player*)mAttacker)->GetQuestLogForEntry(1640);
				if(!qle)
					return;
				qle->SendQuestComplete();
			}
		}
	}

	void AIUpdate()
	{
		_unit->RemoveNegativeAuras();
		_unit->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 11);
		_unit->SetHealthPct(100);      
		_unit->GetAIInterface()->WipeTargetList();         
		_unit->GetAIInterface()->WipeHateList();
        _unit->GetAIInterface()->HandleEvent( EVENT_LEAVECOMBAT, _unit, 0);
        _unit->GetAIInterface()->disable_melee = true;
        _unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
	}

	void OnDied(Unit *Mkiller)
    {
      RemoveAIUpdateEvent();
    }

};

class SCRIPT_DECL BeatBartleby : public QuestScript 
{ 
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* Bartleby = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 6090);

		if(Bartleby == NULL)
			return;

		Bartleby->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 168);
		Bartleby->GetAIInterface()->disable_melee = false;
		Bartleby->GetAIInterface()->SetAllowedToEnterCombat(true);
	}
};

class SCRIPT_DECL TheDefiasBrotherhood : public QuestScript
{
public:

	void OnQuestStart( Player * mTarget, QuestLogEntry * qLogEntry)
	{
		if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
			return;
		float SSX = mTarget->GetPositionX();
		float SSY = mTarget->GetPositionY();
		float SSZ = mTarget->GetPositionZ();

		Creature* creat = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SSX, SSY, SSZ, 467);

				if(creat == NULL)
			return;
		creat->m_escorter = mTarget;
		creat->GetAIInterface()->setMoveType(11);
		creat->GetAIInterface()->SetAllowedToEnterCombat(false);
		creat->GetAIInterface()->StopMovement(3000);
		creat->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Okay let's do this, you gotta protect me and stuff, I can't fight on my own!");
		creat->SetUInt32Value(UNIT_NPC_FLAGS, 0);

		sEAS.CreateCustomWaypointMap(creat);
		sEAS.WaypointCreate(creat,-10521.876953f, 1064.410278f, 54.820744f, 3.220135f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10548.616211f, 1072.964111f, 49.694920f, 3.345799f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10596.891602f, 1057.281982f, 38.864330f, 3.451828f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10663.427734f, 1030.475952f, 32.725643f, 3.098398f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10715.894531f, 1030.825317f, 33.473114f, 3.165157f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10754.050781f, 1016.978821f, 32.843971f, 3.443188f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10917.114258f, 997.355408f, 35.466064f, 3.314383f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10937.306641f, 1020.598755f, 36.644848f, 1.488332f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10933.578125f, 1058.460571f, 36.027996f, 1.472624f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10958.590820f, 1105.329224f, 36.635437f, 2.076595f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10895.253906f, 1248.348877f, 33.385048f, 1.176529f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10890.806641f, 1297.475708f, 34.488716f, 1.698819f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10917.052734f, 1419.003296f, 42.823147f, 1.804847f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10948.415039f, 1422.049927f, 43.411053f, 3.332447f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-10989.025391f, 1410.501953f, 42.863670f, 2.673498f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-11016.258789f, 1434.814697f, 42.987415f, 2.005909f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-11024.154297f, 1488.091064f, 43.177536f, 1.566087f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-11048.541992f, 1513.367798f, 43.154915f, 2.369550f, 0, 256, 0);
		sEAS.WaypointCreate(creat,-11065.412109f, 1526.429321f, 43.328102f, 3.068554f, 0, 256, 0);
	}
};

class The_Defias_Traitor : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(The_Defias_Traitor);
	The_Defias_Traitor(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		if(iWaypointId == 19)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Tell your master that this is where Van Cleef is hiding. I'm outta here!");
			_unit->Despawn(5000,1000);
			sEAS.DeleteWaypoints(_unit);
			if(_unit->m_escorter == NULL)
				return;
			Player* plr = _unit->m_escorter;
			_unit->m_escorter = NULL;
			plr->GetQuestLogForEntry(155)->SendQuestComplete();
		}
	}
};

void SetupMiscQuest(ScriptMgr * mgr)
{
	/* ArathiHighlands */
	mgr->register_creature_script(2768, CCS(Professor_Phizzlethorpe));
	mgr->register_quest_script(665, CQS(SunkenTreasure));

	/* Azshara */
	mgr->register_gossip_script(8399, CGS(ArximagTeleportDown)); 
	mgr->register_gossip_script(8395, CGS(ArximagTeleportUp)); 

	/* Blasted Lands */
	mgr->register_quest_script(2702, CQS(HeroesofOld));
	mgr->register_gossip_script(7572, CGS(HeroesofOld1));

	/* Bloodmyst Isle */
	mgr->register_quest_script(9663, CQS(TheKesselRun));
	mgr->register_gossip_script(17440, CGS(TheKesselRun1));
	mgr->register_gossip_script(17116, CGS(TheKesselRun2));
	mgr->register_gossip_script(17240, CGS(TheKesselRun3));
	mgr->register_gameobject_script(181928, CGOS(SavingPrincessStillpine));
	mgr->register_creature_script(17320, CCS(HighChiefBristlelimb));
	mgr->register_creature_script(17321, CCS(HighChiefBristlelimb));

	/* Desolace */
	mgr->register_creature_script(5644, CCS(Dalinda_Malem));
	mgr->register_quest_script(1440, CQS(ProtectingtheShipment));

	/* Dustwallow Marsh */
	mgr->register_creature_script(5089, CCS(BalosJackenQAI));
	mgr->register_quest_script(4961, CQS(Cleansing_of_the_Orb_of_Orahil));
	mgr->register_quest_script(1955, CQS(Cleansing_of_the_Orb_of_Orahil));
   	mgr->register_creature_script(4500, CCS(OverlordMokMorokk));
	mgr->register_quest_script(1173, CQS(ChallengeOverlordMokMorokk));
	mgr->register_creature_script(4966, CCS(PrivateHendel));
	mgr->register_quest_script(1324, CQS(TheMissingDiplomat2));

	/* First Aid */
	mgr->register_creature_script(12923, CCS(InjuredSoldier));
	mgr->register_creature_script(12924, CCS(InjuredSoldier));
	mgr->register_creature_script(12925, CCS(InjuredSoldier));
	mgr->register_creature_script(12936, CCS(InjuredSoldier));
	mgr->register_creature_script(12937, CCS(InjuredSoldier));
	mgr->register_creature_script(12938, CCS(InjuredSoldier));
	mgr->register_dummy_spell(20804, CDS(Triage));

	/* Ghostlands */
	mgr->register_gossip_script(16208, CGS(Prisoner12));
	mgr->register_gossip_script(16206, CGS(Prisoner22));
	mgr->register_gossip_script(16209, CGS(Prisoner32));
	mgr->register_creature_script(16208, CCS(PrisonersatDeatholme));
	mgr->register_creature_script(16206, CCS(PrisonersatDeatholme));
	mgr->register_creature_script(16209, CCS(PrisonersatDeatholme));
	mgr->register_gameobject_script(181157, CGOS(VanquishingAquantion));

	/* Hillsbrad Foothills */
	mgr->register_creature_script(2306, CCS(Baron_Vardus));
	mgr->register_quest_script(566, CQS(WantedBaronVardus));

	/* Loch Modan */
	mgr->register_creature_script(1379, CCS(Miran));
	mgr->register_quest_script(309, CQS(ProtectingtheShipment));

	/* Mulgore */
	mgr->register_creature_script(2983, CCS(The_Plains_Vision));
	mgr->register_dummy_spell(4981, CDS(InducingVision));

	/* Netherstorm */
	mgr->register_gossip_script(20162, CGS(Veronia));
	
	/* Quest Gossip */
	mgr->register_gossip_script(4968, CGS(Lady_Jaina));
	mgr->register_gossip_script(3057, CGS(Cairne));

	/* Redridge Mountains */
	mgr->register_creature_script(349, CCS(Corporal_Keeshan));
	mgr->register_quest_script(219, CQS(MissingInAction));

	/* Silvermoon City */
	mgr->register_gameobject_script(182024, CGOS(ThePathoftheAdept));
	mgr->register_gossip_script(17832, CGS(PathoftheAdept));
	mgr->register_creature_script(17832, CCS(LordDawnstar));

	/* Stormwind */
	mgr->register_creature_script(4961, CCS(DashelStonefist));
	mgr->register_quest_script(1447, CQS(TheMissingDiplomat));

	/* Stranglethorn Vale */
	mgr->register_gossip_script(1449, CGS(StrFever));
	mgr->register_creature_script(1511, CCS(Beka));
	mgr->register_creature_script(1516, CCS(Beka1));
	mgr->register_quest_script(584, CQS(BloodscalpClanHeads));
	mgr->register_quest_script(1118, CQS(BacktoBootyBay));
	mgr->register_quest_script(609, CQS(VoodooDues));

	/* Tanaris */
	mgr->register_gossip_script(8612, CGS(SpiritScreeches));
	mgr->register_creature_script(8612, CCS(ScreecherSpirit));
	mgr->register_gossip_script(20142, CGS(StewardOfTime));

	/* Thousand Needles */
	mgr->register_creature_script(10427, CCS(Paoka_Swiftmountain));
	mgr->register_quest_script(4770, CQS(HomewardBound));
	mgr->register_quest_script(1117, CQS(RumorsforKravel));

	/* Tirisfal Glades */
	mgr->register_quest_script(410, CQS(TheDormantShade));
	mgr->register_creature_script(6784, CCS(CalvinMontague));
	mgr->register_quest_script(590, CQS(ARoguesDeal));
	mgr->register_quest_script(407, CQS(FieldsofGrief));
	mgr->register_creature_script(1931, CCS(Zealot));

	/* Unsorted Quests */
	mgr->register_quest_script(10998, CQS(Quest_Grimoire_Business));
	mgr->register_quest_script(10996, CQS(Quest_Maggocs_Treasure_Chest));
	mgr->register_quest_script(10995, CQS(Quest_Grulloc_Has_Two_Skulls));
	mgr->register_quest_script(10866, CQS(Quest_Zuluhed_the_Whacked));
	mgr->register_creature_script(620, CCS(Chicken));

	/* Warrior Quests */
	mgr->register_gossip_script(6176, CGS(TheSummoning));
	mgr->register_creature_script(6090, CCS(Bartleby));
	mgr->register_quest_script(1640, CQS(BeatBartleby));

	/* Westfall - Defias */
	mgr->register_quest_script(155, CQS(TheDefiasBrotherhood));
	mgr->register_creature_script(467, CCS(The_Defias_Traitor));
}