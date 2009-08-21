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
#define STV_ZONE_ID		33
#define STV_KILL_ITEM	9090

// #define ONYX_NEW_ZONE_HOOK
void OnZone(Player *pPlayer, uint32 Zone)
{
/*#ifdef ONYX_NEW_ZONE_HOOK
	if( pPlayer->m_playerInfo->lastZone == 28 || pPlayer->GetZoneId() != 28 )
	{
		uint32 faction			= pPlayer->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE);
		if( faction == 1812 || faction == 1813 )
		{
			PlayerCreateInfo * py	= objmgr.GetPlayerCreateInfo(pPlayer->getRace(), pPlayer->getClass());
			pPlayer->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, py->factiontemplate);
		}
	}
#endif*/
	/*~~~~~~~~~~~~~~~*/
	uint32	banned = 1;
	/*~~~~~~~~~~~~~~~*/
	switch(Zone)
	{
	case (876):
		{
			if( !pPlayer->GetSession()->CanUseCommand('d') )
			{
				pPlayer->SafeTeleport(13, 0, 0, 0, 0, 0);
				pPlayer->m_silenced = true;

				/*~~~~~~~~~~~~~~~~~~~~~~~*/
				std::stringstream	my_sql;
				/*~~~~~~~~~~~~~~~~~~~~~~~*/

				sWorld.LogWriteFromSession(pPlayer->GetSession(), CHEATLOG, "got banned trying to access GM Island.");

				my_sql <<
					"UPDATE accounts SET banned = " <<
					banned <<
					" WHERE login = '" <<
					CharacterDatabase.EscapeString(string(pPlayer->GetSession()->GetAccountName())) <<
					"'";
				CharacterDatabase.Execute(my_sql.str().c_str());
				pPlayer->GetSession()->Disconnect();
				
				sWorld.CallAccountReload();
			}
			else
			{
				pPlayer->bInvincible = true;
			}

			return;
		}break;
/*#ifdef ONYX_NEW_ZONE_HOOK
	case (28):
		{
			uint32 faction			= pPlayer->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE);
			if( faction != 1812 || faction != 1813 )
			{
				if( pPlayer->GetItemInterface()->GetItemCount(8000000, true) > 1 )
				{
							pPlayer->setFaction(1813); // Titans
				}
				if( pPlayer->GetItemInterface()->GetItemCount(8000001, true) > 1 )
				{
					pPlayer->setFaction(1814); // Gods
				}
			}
		}break;
#endif*/
	}
}

void OnDeath(Player *pPlayer)
{
	if
	(
		(pPlayer->pLastAttacker == NULL)
	||	(pPlayer->pLastAttacker->GetTypeId() == TYPEID_PLAYER)
	||	(pPlayer->pLastAttacker != pPlayer)
	) return;

	if(pPlayer->getLevel() >= 20 || pPlayer->getLevel() <= 39)		/* 20-39 */
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	coinage = pPlayer->GetUInt32Value(PLAYER_FIELD_COINAGE);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		coinage -= (uint32) (( float ) coinage * 0.02f);			/* subtract 2% */
		pPlayer->SetUInt32Value(PLAYER_FIELD_COINAGE, coinage);
		sChatHandler.SystemMessage
			(
				pPlayer->GetSession(),
				"|cffFF0000No0b Mode: You have died! You lose 2%% of your gold!"
			);
		pPlayer->pLastAttacker = NULL;
	}
	else if(pPlayer->getLevel() >= 40 || pPlayer->getLevel() <= 59) /* 40-59 */
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	coinage = pPlayer->GetUInt32Value(PLAYER_FIELD_COINAGE);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		coinage -= (uint32) (( float ) coinage * 0.04f);			/* subtract 4% */
		pPlayer->SetUInt32Value(PLAYER_FIELD_COINAGE, coinage);
		sChatHandler.SystemMessage
			(
				pPlayer->GetSession(),
				"|cffFF0000Easy Mode: You have died! You lose 4%% of your gold!"
			);
		pPlayer->pLastAttacker = NULL;
	}
	else if(pPlayer->getLevel() >= 60 || pPlayer->getLevel() <= 79) /* 60-79 */
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	coinage = pPlayer->GetUInt32Value(PLAYER_FIELD_COINAGE);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		coinage -= (uint32) (( float ) coinage * 0.06f);			/* subtract 6% */
		pPlayer->SetUInt32Value(PLAYER_FIELD_COINAGE, coinage);
		sChatHandler.SystemMessage
			(
				pPlayer->GetSession(),
				"|cffFF0000Normal Mode: You have died! You lose 6%% of your gold!"
			);
		pPlayer->pLastAttacker = NULL;
	}
	else if(pPlayer->getLevel() >= 80 || pPlayer->getLevel() <= 99) /* 80-99 */
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	coinage = pPlayer->GetUInt32Value(PLAYER_FIELD_COINAGE);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		coinage -= (uint32) (( float ) coinage * 0.08f);			/* subtract 8% */
		pPlayer->SetUInt32Value(PLAYER_FIELD_COINAGE, coinage);
		sChatHandler.SystemMessage
			(
				pPlayer->GetSession(),
				"|cffFF0000Hard Mode: You have died! You lose 8%% of your gold!"
			);
		pPlayer->pLastAttacker = NULL;
	}
	else if(pPlayer->getLevel() <= 100)					/* 100+ */
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		uint32	coinage = pPlayer->GetUInt32Value(PLAYER_FIELD_COINAGE);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		coinage -= (uint32) (( float ) coinage * 0.1f); /* subtract 10% */
		pPlayer->SetUInt32Value(PLAYER_FIELD_COINAGE, coinage);
		sChatHandler.SystemMessage
			(
				pPlayer->GetSession(),
				"|cffFF0000Extreme Mode: You have died! You lose 10%% of your gold!"
			);
		pPlayer->pLastAttacker = NULL;
	}
}

bool OnSTVKillPlayer(Player *killer, Player *victum)
{
	if(killer->GetZoneId() == STV_ZONE_ID)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		Creature	*Announcer = killer->GetMapMgr()->GetSqlIdCreature(85599);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if(Announcer)
		{
			/*~~~~~~~~~~~~~~~~~*/
			char	killstr[200];
			/*~~~~~~~~~~~~~~~~~*/

			sprintf(killstr, "%s has just slain %s!", killer->GetName(), victum->GetName());
			Announcer->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, killstr);
		}

		/*
			 else { killer->BroadcastMessage("Error in STVHook.cpp Maybe mob is missing?
			 Alert an admin ASAP!");
			 }
		 */
	}

	return 1;
}

void SetupHooks(ScriptMgr *mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_ZONE, (void*)OnZone);
	mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, (void*)OnSTVKillPlayer);

/*
	mgr->register_hook(SERVER_HOOK_EVENT_ON_DEATH, &OnDeath);
*/
}
