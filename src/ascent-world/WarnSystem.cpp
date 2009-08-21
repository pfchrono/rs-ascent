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

initialiseSingleton( WarnSystem );

void PlrSendMessageToSet(Player * Plr, const char* msg)
{
	WorldPacket *data;
	data = sChatHandler.FillMessageData( CHAT_MSG_SAY, LANG_UNIVERSAL,  msg, Plr->GetGUID(), Plr->bGMTagOn ? 4 : 0 );
	Plr->SendMessageToSet( data, true );
	delete data;
	return;
}

void WarnSystem::ReachedPunishmentLevel(Player * Warner, Player *Warned, uint32 NewWarnCnt)
{
	// Gold punishment, on by default. It takes gold away depending on their New Warn Count.
	// 1000 gold is taken for each warning received after a first warning.
	// So warning 3 gets a 2000 gold fine. Warning 4 a 3000 gold fine. Etc.
	if(!Warner || !Warned || !Warner->GetSession() || !Warned->GetSession() || !NewWarnCnt)
		return;
	
	if( NewWarnCnt > 1) 
	{
		uint32 CopperPerGold = 10000;
		uint32 CoinageLevel = Warned->GetUInt32Value(PLAYER_FIELD_COINAGE);
		uint32 CoinageToLose = ((NewWarnCnt - 1)*1000*CopperPerGold);
		int32 NewCoinageLevel = CoinageLevel - CoinageToLose;
		if( NewCoinageLevel < 0 )
		{
			CoinageToLose = CoinageLevel;
/*
			if( NewWarnCnt == 2 )
				NewWarnCnt = 3;

			// If user has not enough gold he's either trying to get around it or
			// being a complete asshole while just having joined, so let's teach him a lesson! :D
			// Apply this punishment AND the punishment for the next warning.
*/
		}
		int32 ModValue = -1*(CoinageToLose);
		Warned->ModUnsigned32Value(PLAYER_FIELD_COINAGE, ModValue);
		if( ModValue != 0 ) //We shouldn't send a message if the player isn't losing any gold.
		{
			char msg[1024];
			sprintf(msg, "[WarnSys] I got warned and I just lost %u gold!", (int)(CoinageToLose/CopperPerGold));
			PlrSendMessageToSet(Warned, msg);
		}
		Warned->SaveToDB(false);
	}
	switch(NewWarnCnt)
	{
	case 3:
		{
			if( Warned->getLevel() == 1 ) //What else can we do to him?
				return;

			if( Warned->getLevel() <= 10 ) //Don't bug our characters
			{
				Warned->Reset_ToLevel1();
				PlrSendMessageToSet(Warned, "[WarnSys] I was deleveled to level 1.");
				Warned->SaveToDB(false);
				return;
			}

			uint32 NewLvl = Warned->getLevel() - 10;
			uint32 LvlsLost = Warned->getLevel() - NewLvl;
			LevelInfo * Info = objmgr.GetLevelInfo(Warned->getRace(), Warned->getClass(), NewLvl);
			if(!Info) return;
			if(LvlsLost > 0)
			{
				Warned->ApplyLevelInfo(Info, NewLvl);
				Warned->Reset_Talents();
				PlrSendMessageToSet(Warned, "[WarnSys] I lost 10 levels and my talents were reset.");
				Warned->SaveToDB(false);
			}
			sEventMgr.AddEvent(Warned,&Player::SoftDisconnect,EVENT_PLAYER_SOFT_DISCONNECT,5000,1,0);
			PlrSendMessageToSet(Warned, "[WarnSys] I will now be kicked. Kthxbai.");
			return;
		}break;
	case 6:
		{
			Warned->SafeTeleport(13, 0, 0, 0, 0, 0);
			Warned->m_silenced = true;
			/*~~~~~~~~~~~~~~~~~~~~~~~*/
			std::stringstream	my_sql;
			/*~~~~~~~~~~~~~~~~~~~~~~~*/
			const char * pDuration = "1h";
			int32 timeperiod = GetTimePeriodFromString(pDuration);
			if(timeperiod < 1) return;
			time_t expire_time = UNIXTIME + (time_t)timeperiod;
			string IP = Warned->GetSession()->GetSocket()->GetRemoteIP();
			IP.append("/32");
			char * pIp = (char*)IP.c_str();
			sLogonCommHandler.IPBan_Add( pIp, (uint32)expire_time, "Warn count 6 reached. Automatically temp-banned." );
			PlrSendMessageToSet(Warned, "[WarnSys] I have been temporarily banned and will be disconnected in 5 seconds.");
			sChatHandler.SystemMessage(Warned->GetSession(), "Warn count %u reached, you will now receive a temporary ban of 1 hour", NewWarnCnt);
			sWorld.DisconnectUsersWithAccount(Warned->GetSession()->GetAccountName().c_str(), Warner->GetSession());
			sLogonCommHandler.ReloadAccounts();
		}break;
	case 7: 
		{
			time_t expire_time = 0;
			string IP = Warned->GetSession()->GetSocket()->GetRemoteIP();
			IP.append("/32");
			char * pIp = (char*)IP.c_str();
			sLogonCommHandler.IPBan_Add( pIp, (uint32)expire_time, "Warn count 7 reached. Automatically perm-banned." );
			sChatHandler.SystemMessage(Warned->GetSession(), "Warn count %u reached, you will now receive a permanent ban", NewWarnCnt);
			PlrSendMessageToSet(Warned, "[WarnSys] I have been permanently banned and will be disconnected in 5 seconds.");
			sWorld.DisconnectUsersWithAccount(Warned->GetSession()->GetAccountName().c_str(), Warner->GetSession());
			sLogonCommHandler.ReloadAccounts();
		}break;
	}
	return;
}
void WarnSystem::AddWarn(Player * Warner, Player * Warned, const char  *reason)
{
	if(!Warner || !Warned || !Warner->GetSession() || !Warned->GetSession())
		return;

	std::string GMChar = Warner->GetName();
	std::string WarnedChar = Warned->GetName();
	std::string GMAcct = Warner->GetSession()->GetAccountName();
	std::string WarnedAcct = Warned->GetSession()->GetAccountName();
	std::string WarnedIP = Warned->GetSession()->GetSocket()->GetRemoteIP();
	
	std::stringstream GetWarnCount;
	GetWarnCount << "SELECT WarnID FROM WarnSystem WHERE ( WarnedAcct = '" << WorldDatabase.EscapeString(WarnedAcct.c_str()) << "' )";
	QueryResult * GWCresult = WorldDatabase.Query( GetWarnCount.str().c_str() );
	int WarnCount = 0;
	if( GWCresult )
	{
		do{
			WarnCount++;
		} while(GWCresult->NextRow());
		delete GWCresult;
	}
	uint32 newWarnID = WarnCount + 1;
	ReachedPunishmentLevel(Warner, Warned, newWarnID);
	
	std::stringstream mySql;
	mySql << "INSERT INTO WarnSystem VALUES ('" << newWarnID << "', '" << WorldDatabase.EscapeString(GMAcct.c_str()) << "', '" << WorldDatabase.EscapeString(WarnedChar.c_str()) << "', '" << WorldDatabase.EscapeString(WarnedAcct.c_str()) << "', '" << WorldDatabase.EscapeString(WarnedIP.c_str()) << "', '" << WorldDatabase.EscapeString(reason) << "')";
	WorldDatabase.Execute( mySql.str().c_str() );

	char pAnnounce[1024];
	snprintf((char*)pAnnounce, 1024, "[WarnSys] %s has been warned( #%u ) for: %s", Warned->GetName(), newWarnID, reason);	// Adds BROADCAST:
	sWorld.SendWorldText(pAnnounce); // send message
	sChatHandler.GreenSystemMessage(Warner->GetSession(), "You have warned %s for: %s", WarnedChar.c_str(), reason );
	sChatHandler.BlueSystemMessage(Warned->GetSession(), "You have been warned by %s for: %s", GMChar.c_str(), reason );
	Log.Notice("WarnSystem", "Player %s has been warned by %s for: %s", WarnedChar.c_str(), GMAcct.c_str(), reason );
	sGMLog.writefromsession(Warner->GetSession(), "warned(%u) player %s(%s) for %s", newWarnID, WarnedChar.c_str(), WarnedAcct.c_str(), reason);
	return;
}

void WarnSystem::DelWarn(Player * Warner, Player * Warned, uint32 WarnID)
{
	if(!Warner || !Warner->GetSession() || !Warned || !Warned->GetSession())
		return;

	WorldSession *gmSession = Warner->GetSession();
	WorldSession *plrSession = Warned->GetSession();
	
	std::string GMAcct		= Warner->GetName();
	std::string GMSession	= gmSession->GetAccountName();
	std::string WarnedChar	= Warned->GetName();
	std::string WarnedAcct	= plrSession->GetAccountName();
	
	std::stringstream mySql;
	mySql << "DELETE FROM WarnSystem WHERE ( WarnedAcct = '" << WorldDatabase.EscapeString(WarnedAcct.c_str()) << "' AND WarnID = '" << WarnID << "')";
	WorldDatabase.Execute( mySql.str().c_str() );

	sChatHandler.SystemMessage(gmSession, "Warn Deleted.");
	sChatHandler.SystemMessage(plrSession, "Warn Deleted.");

	Log.Notice("WarnSystem", "GM %s[%s] has cleared warn %u from player %s(%s)", GMAcct.c_str(), GMSession.c_str(), WarnID, WarnedChar.c_str(), WarnedAcct.c_str());
	sGMLog.writefromsession(gmSession,"deleted warn %u from player %s(%s)", WarnID, WarnedChar.c_str(), WarnedAcct.c_str());
	return;
}

void WarnSystem::ListWarns(Player * Warner, Player * Warned)
{
	if(!Warner || !Warner->GetSession() )
	{
		return;
	}
	WorldSession * gm_session = Warner->GetSession();
	if(!Warned) 
	{
		sChatHandler.SystemMessage(gm_session, "You have to select an online player!");
		return; // If character doesn't exist or isn't online, return error.
	}
	bool IsGameMaster = (Warner->RS_getAccess() >= RS_PROBEGM)?true:false;
	
	/* MySql Query Building */
	std::string WarnedChar = Warned->GetName(); // Getting Player Name
	std::string WarnedAcct = Warned->GetSession()->GetAccountName(); // Getting Player Account.
	std::stringstream mySql;
	mySql << "SELECT * FROM WarnSystem WHERE ( WarnedAcct = '" << WorldDatabase.EscapeString(WarnedAcct.c_str()) << "' )";
	QueryResult * result = WorldDatabase.Query( mySql.str().c_str() );
		
	/* Query Result Handling */
	if(result)
	{
		do
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Field			*fields = result->Fetch();
			uint32			WarnID = fields[0].GetUInt32();
			string			GMAcct = fields[1].GetString();
			string			WarnedChar = fields[2].GetString();
			string			WarnedAcct = fields[3].GetString();
			string			WarnedIP = fields[4].GetString();
			string			pReason = fields[5].GetString();
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	
			sChatHandler.GreenSystemMessage(gm_session, "--------------------------"); // Display Warn number and reasons.
			sChatHandler.GreenSystemMessage(gm_session, "WarnID: %u", WarnID );
			sChatHandler.GreenSystemMessage(gm_session, "Warned on: %s", WarnedChar.c_str());
			if(IsGameMaster) 
			{
				sChatHandler.GreenSystemMessage(gm_session, "Warned by: %s", GMAcct.c_str() );
			}
			sChatHandler.GreenSystemMessage(gm_session, "Reason: %s", pReason.c_str() );
		} while(result->NextRow());
		delete result;
	}
	else
	{
		sChatHandler.GreenSystemMessage(gm_session, "No warns found.");
	}
	return;
}

void WarnSystem::ClearWarns(Player * Warner, Player *  Warned)
{
	if(!Warner || !Warner->GetSession() )
	{
		return;
	}
	WorldSession * gm_session = Warner->GetSession();
	// Getting Player Info
	if( !Warned ) 
	{
		sChatHandler.SystemMessage(gm_session, "No player found!");
		return; // If character doesn't exist or isn't online, return error.
	}
	
	// Get required info from both GM and player.
	std::string WarnedChar = Warned->GetName(); 
	std::string WarnedAcct = Warned->GetSession()->GetAccountName();
	std::string GMAcct = gm_session->GetAccountName();
	std::string GM_IP = gm_session->GetSocket()->GetRemoteIP();

	/* MySql Query Building */
	std::stringstream mySql;
	mySql << "DELETE FROM WarnSystem WHERE ( WarnedAcct = '" << WorldDatabase.EscapeString(WarnedAcct.c_str()) << "')";
	WorldDatabase.Execute( mySql.str().c_str() );
	
	sChatHandler.GreenSystemMessage(gm_session, "Warns cleared!");
	sChatHandler.GreenSystemMessage(Warned->GetSession(), "Your warns were cleared!");
	Log.Notice("WarnSystem", "GM %s[%s] has cleared the warns from player %s(%s)", GMAcct.c_str(), GM_IP.c_str(), WarnedChar.c_str(), WarnedAcct.c_str());
	return;
}


