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

/* INCLUDES AND DEFINES */
#include "StdAfx.h"
#include "Setup.h"
#include "../../src/ascent-world/ScriptMgr.h"
#ifdef WIN32
#pragma warning(disable : 4305) /* warning C4305: 'argument' : truncation from 'double' to 'float' */
#endif

#define BEGIN_ID 710000
#define AV_NPC_1_ID 710007

/*	SCRIPTS */

QueryResult * RunDB(uint32 entry = 0)
{
	std::stringstream stdstr;
	if( entry == 0 )
	{
		stdstr << "SELECT * FROM gossip_npc";
	}
	else
	{
		stdstr << "SELECT * FROM gossip_npc WHERE npcid = '" << entry << "'";
	}
	QueryResult * pResult = WorldDatabase.Query( stdstr.str().c_str() );
	if( pResult )
		return pResult;
	else
		return NULL;
};

class SCRIPT_DECL GOSSIP_NPC_1 :	public GossipScript
{
public:
	void GossipHello(Object *pObject, Player *Plr, bool AutoSend)
	{
		Creature	*pCreature = (pObject->GetTypeId() == TYPEID_UNIT) ? (( Creature * ) pObject) : NULL;
		/*~~~~~~~~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		uint32		TextID = 820;
		/*~~~~~~~~~~~~~~~~~~~~~*/
		if(!pCreature)
			return;

		QueryResult * qResult = RunDB( pCreature->GetEntry() );
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), TextID, Plr);
		int textline = 0;
		if(qResult)
		{
			do
			{
				if(textline > 8) break;
				Field	*fields = qResult->Fetch();
				string menutext	= fields[1].GetString();
				uint32 textpage	= fields[2].GetUInt32();
				Menu->AddItem(5, menutext.c_str(), textpage);
				textline++;
			}while(qResult->NextRow());
			delete qResult;
		}
		if(AutoSend)
			Menu->SendTo(Plr);
	}
	void GossipSelectOption(Object *pObject, Player *Plr, uint32 Id, uint32 IntId, const char *Code)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		GossipMenu	*Menu;
		Creature	*pCreature = (pObject->GetTypeId() == TYPEID_UNIT) ? (( Creature * ) pObject) : NULL;
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		if(pCreature == NULL) return;
		if( IntId == 0 )
		{
			GossipHello(pCreature, Plr, true);
		}
		objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), IntId, Plr);
		Menu->AddItem(0, "<Back>");
		Menu->SendTo(Plr);

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

/* Setup */
void Setup_CustomGOSSIP(ScriptMgr *mgr)
{
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	GossipScript	*gs = ( GossipScript * ) new GOSSIP_NPC_1();
	/*-------------------------------------------------------*/

	QueryResult * qResult = RunDB();
	if(qResult)
	{
		do
		{
			Field	*fields = qResult->Fetch();
			uint32 entryid = fields[0].GetUInt32();
			mgr->register_gossip_script(entryid, gs);
		}while(qResult->NextRow());
		delete qResult;
	}
}
