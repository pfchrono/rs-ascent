/****************************************************************************
 *
 * Auction House System
 * Copyright (c) 2007 Team Ascent
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0
 * License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to Creative Commons,
 * 543 Howard Street, 5th Floor, San Francisco, California, 94105, USA.
 *
 * EXCEPT TO THE EXTENT REQUIRED BY APPLICABLE LAW, IN NO EVENT WILL LICENSOR BE LIABLE TO YOU
 * ON ANY LEGAL THEORY FOR ANY SPECIAL, INCIDENTAL, CONSEQUENTIAL, PUNITIVE OR EXEMPLARY DAMAGES
 * ARISING OUT OF THIS LICENSE OR THE USE OF THE WORK, EVEN IF LICENSOR HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 *
 */

#include "StdAfx.h"
#include "MersenneTwister.h"
#include "Chat.h"
#include "../../src/ascent-world/CConsole.h"
#include <time.h>

initialiseSingleton( AHBot );

inline std::string MyConvertToString(const int arg)
{
	stringstream out;
	out << arg;
	return out.str();
}

inline std::string MyConvertToString(const uint32 arg)
{
	stringstream out;
	out << arg;
	return out.str();
}

inline std::string MyConvertToString(const float arg)
{
	stringstream out;
	out << arg;
	return out.str();
}

void AHBot::OnStart()
{
	return;
}

void AHBot::LoadSettings()
{
	m_ThreadTask = AHBOT_SLEEPING;

	m_LogLevel				= Config.AH_Config.GetIntDefault("Auctions", "LogLevel", 0);
	m_ClearOnStartup		= Config.AH_Config.GetIntDefault("Auctions", "ClearOnStartup", 0);
	m_RefreshInterval		= Config.AH_Config.GetIntDefault("Auctions", "RefreshInterval", 1);
	m_RefreshMinutes		= Config.AH_Config.GetIntDefault("Auctions", "RefreshMinutes", 60);
	m_LoadOnStartUp			= Config.AH_Config.GetIntDefault("Auctions", "LoadOnStartUp", 0);
	m_CleanMailboxes 		= Config.AH_Config.GetIntDefault("Auctions", "CleanMailboxes", 0);
	m_MinAuctions 			= Config.AH_Config.GetIntDefault("Auctions", "MinAuctions", 0);
	m_Houses 				= Config.AH_Config.GetStringDefault("Auctions", "Houses", "");
	m_AnnounceLoading 		= Config.AH_Config.GetIntDefault("Auctions", "WorldAnnounce", 0);
	m_ExpirationMinutes 	= Config.AH_Config.GetIntDefault("Auctions", "ExpirationMinutes", 1440);  // this is in minutes - (1440 = 1 day)
	m_RandomizeExpiration	= Config.AH_Config.GetIntDefault("Auctions", "RandomizeExpiration", 0);
	m_IncludeClasses 		= Config.AH_Config.GetStringDefault("Auctions", "IncludeClasses", "1,2,3,4,5,6,7,8,9,10,11,12,13,14,15");
	m_AllowQuestItems 		= Config.AH_Config.GetIntDefault("Auctions", "AllowQuestItems", 0);
	m_MinItemLevel 			= Config.AH_Config.GetIntDefault("Auctions", "MinItemLevel", 0);
	m_MaxItemLevel 			= Config.AH_Config.GetIntDefault("Auctions", "MaxItemLevel", INT_MAX);
	m_MinPlayerLevel		= Config.AH_Config.GetIntDefault("Auctions", "MinPlayerLevel", 0);
	m_MaxPlayerLevel 		= Config.AH_Config.GetIntDefault("Auctions", "MaxPlayerLevel", INT_MAX);
	m_MinItemQuality 		= Config.AH_Config.GetIntDefault("Auctions", "MinQuality", 1);
	m_MaxItemQuality 		= Config.AH_Config.GetIntDefault("Auctions", "MaxQuality", INT_MAX);
	m_MaxItemCount 			= Config.AH_Config.GetIntDefault("Auctions", "MaxItemCount", 0);
	m_MaxStack 				= Config.AH_Config.GetIntDefault("Auctions", "MaxStack", 2);
	m_CustomPrices			= Config.AH_Config.GetIntDefault("Auctions", "CustomPrices", 0);
	m_BuyoutMultiplier		= Config.AH_Config.GetFloatDefault("Auctions", "BuyoutMultiplier", 1);
	m_BidMultiplier			= Config.AH_Config.GetFloatDefault("Auctions", "BidMultiplier", 0);
	m_PlayerName 			= Config.AH_Config.GetStringDefault("Auctions", "PlayerName", "Ahbot");

	m_PlayerGuid = 0;

	QueryResult *resultPlayer = CharacterDatabase.Query("SELECT guid FROM characters WHERE name = '%s'", m_PlayerName.c_str());
	if(resultPlayer)
	{
		Field *fields = resultPlayer->Fetch();
		m_PlayerGuid = fields[0].GetUInt32();

		delete resultPlayer;
	}

	m_ThreadTask = AHBOT_STARTUP;

	return;
}

void AHBot::SetThreadTask(AHBOT_THREAD_TASKS task)
{
	m_ThreadTask = task;
}

AHBOT_THREAD_TASKS AHBot::GetThreadTask()
{
	return m_ThreadTask;
}

bool AHBot::GetThreadTask(AHBOT_THREAD_TASKS task)
{
	return (m_ThreadTask == task);
}


bool ChatHandler::HandleAHBotCountCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotCountAH(NULL, m_session);
}

bool AHBot::AHBotCountAH(BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	QueryResult *result = CharacterDatabase.Query( "SELECT auctionHouse, COUNT(auctionId) FROM auctions GROUP BY auctionHouse" );
	if(!result)
	{
		delete result;

		QueryResult *resultHouses = WorldDatabase.Query( "SELECT DISTINCT `group` FROM auctionhouse ORDER BY `group`" );
		if(!resultHouses)
		{
			snprintf(msg, 200, "ERROR: No auction houses were found in the World database AuctionHouse table.");
			
			if ( m_session )
				sChatHandler.RedSystemMessage(m_session, msg);
			else
				{pConsole->Write(msg); pConsole->Write("\n");}

			return false;
		}

		do
		{
			Field *fields = resultHouses->Fetch();
			uint32 ahid = fields[0].GetUInt32();

			snprintf(msg, 200, "AH - > '%u' contains '0' auctions.", ahid);
				
			if ( m_session )
				sChatHandler.BlueSystemMessage(m_session, msg);
			else
				{pConsole->Write(msg); pConsole->Write("\n");}

		}while (resultHouses->NextRow());

		delete resultHouses;

		return false;
	}

	do
	{
		Field *fields = result->Fetch();
		uint32 ahid = fields[0].GetUInt32();
		uint32 ahcount = fields[1].GetUInt32();

		snprintf(msg, 200, "AH - > '%u' contains '%u' auctions.", ahid, ahcount);

		if ( m_session )
			sChatHandler.BlueSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

	}while (result->NextRow());

	delete result;

	return true;
}

bool ChatHandler::HandleAHBotRefreshCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotRefreshMinutesAH(string(args), NULL, m_session);
}

void AHBot::AHBotSendMessage(char msg, BaseConsole * pConsole, WorldSession *m_session)
{
	return;
}

bool AHBot::AHBotRefreshMinutesAH(string args, BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	if(args.length() == 0)
	{ 
		snprintf(msg, 200, "ERROR: You must specify a new refresh interval for AHBot.");

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
			{pConsole->Write(msg); pConsole->Write("\n");}

		return false;
	}

	int NewRefreshMinutes = atoi(args.c_str());

	if(NewRefreshMinutes < 5)
	{
		snprintf(msg, 200, "ERROR: The min refresh interval is 5 minutes, '%u' is too small.", NewRefreshMinutes);

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
			{pConsole->Write(msg); pConsole->Write("\n");}

		return false;
	}

	if(NewRefreshMinutes > 1440)
	{
		snprintf(msg, 200, "ERROR: The max refresh interval is 1,440 minutes, '%u' is too big.", NewRefreshMinutes);

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
			{pConsole->Write(msg); pConsole->Write("\n");}

		return false;
	}

	if(m_RefreshMinutes != NewRefreshMinutes)
	{
		sAHBotMgr.m_RefreshMinutes = NewRefreshMinutes;
		sAHBotMgr.m_ThreadTask = AHBOT_SETTINGS;

		snprintf(msg, 200, "Queued a new AHBot refresh minutes change to '%u'.", NewRefreshMinutes);
	}
	else
		snprintf(msg, 200, "There was no change in the refresh minutes because the interval is already '%u'.", m_RefreshMinutes);

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

bool ChatHandler::HandleAHBotLogLevelCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotLogLevelAH(string(args), NULL, m_session);
}

bool AHBot::AHBotLogLevelAH(string args, BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	if(args.length() == 0)
	{
		snprintf(msg, 200, "ERROR: You must specify a new AHBot log level.");

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
			{pConsole->Write(msg); pConsole->Write("\n");}

		return false;
	}

	int NewLogLevel = atoi(args.c_str());
	if(NewLogLevel < 0)
		NewLogLevel = 0;

	if(NewLogLevel > 255)
		NewLogLevel = 9;

	if(m_LogLevel != NewLogLevel)
	{
		sAHBotMgr.m_LogLevel = NewLogLevel;
		sAHBotMgr.m_ThreadTask = AHBOT_SETTINGS;

		snprintf(msg, 200, "Queued a new AHBot log level change to '%u'.", NewLogLevel);
	}
	else
		snprintf(msg, 200, "There was no change in the log level because the log level is already '%u'.", m_LogLevel);

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

bool ChatHandler::HandleAHBotListCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotListAH(NULL, m_session);
}

bool AHBot::AHBotListAH(BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	QueryResult *result = WorldDatabase.Query( "SELECT DISTINCT `group` FROM auctionhouse ORDER BY `group`" );
	if(!result)
	{
		snprintf(msg, 200, "ERROR: No auction houses were found in the World database AuctionHouse table.");

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

		return false;
	}

	do
	{
		Field *fields = result->Fetch();
		uint32 ahid = fields[0].GetUInt32();

		snprintf(msg, 200, "AH - > '%u' was found.", ahid);

		if ( m_session )
			sChatHandler.BlueSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

	}while (result->NextRow());

	delete result;

	return true;
}

bool ChatHandler::HandleAHBotLoadCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotLoadAH(string(args), NULL, m_session);
}

bool AHBot::AHBotLoadAH(string args, BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	if(args.length() == 0)
	{
		snprintf(msg, 200, "You must at least specify a number of items to add to an auction house.");

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

		return false;
	}

	uint32 itemsToAdd = 0;
	uint32 AHid = 0;
	if(sscanf(args.c_str(), "%u %u", &itemsToAdd, &AHid) < 1)
	{
		snprintf(msg, 200, "You must at least specify a number of items to add to an auction house.");

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

		return true;
	}

	Player * plr = NULL;

	if ( m_session )
		plr = m_session->GetPlayer();

	// Get an auctioneer for the Auction House reference
	uint32 auctioneer = GetAnAuctioneer(plr, AHid);

	if(auctioneer == 0)
	{
		snprintf(msg, 200, "Unable to access an auctioneer for auction house '%u'.", AHid);

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

		return true;
	}

	// Create a reference to the Auction House
	AuctionHouse * ah = sAuctionMgr.GetAuctionHouse(auctioneer);
	if(!ah)
	{
		snprintf(msg, 200, "Unable to access auction house '%u' using auctioneer '%u'.", AHid, auctioneer);

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

		return true;
	}

	if(sLog.m_fileLogLevel >= 1)
	{
		if ( m_session )
			snprintf(msg, 200, "Player %s initiated an AH load of '%u' items for ah '%u'.", plr->GetName(), itemsToAdd, ah->GetID());
		else
			snprintf(msg, 200, "Player %s initiated an AH load of '%u' items for ah '%u'.", "[Console]", itemsToAdd, ah->GetID());

		{pConsole->Write(msg); pConsole->Write("\n");}
	}

	sAHBotMgr.plr = plr;
	sAHBotMgr.ah = ah;
	sAHBotMgr.itemsToAdd = itemsToAdd;
	sAHBotMgr.m_ThreadTask = AHBOT_LOAD;

	snprintf(msg, 200, "Queued the loading of AH `%u` with `%u` items using `%u`.", ah->GetID(), itemsToAdd, auctioneer);

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

bool ChatHandler::HandleAHBotPreLoadCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotPreloadAH(string(args), NULL, m_session);
}

bool AHBot::AHBotPreloadAH(string args, BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	uint32 AHid = 0;
	if(args.length() == 0)
		AHid = atol(args.c_str());

	// Default to AH 1
	if(AHid == 0)
		AHid = 1;

	Player * plr = NULL;

	if ( m_session )
		Player * plr = m_session->GetPlayer();

	// Get an auctioneer for the Auction House reference
	uint32 auctioneer = GetAnAuctioneer(plr, AHid);

	if(auctioneer == 0)
	{
		snprintf(msg, 200, "Unable to access an auctioneer for auction house '%u'.", AHid);

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

		return true;
	}

	// Create a reference to the Auction House
	AuctionHouse * ah = sAuctionMgr.GetAuctionHouse(auctioneer);
	if(!ah)
	{
		snprintf(msg, 200, "Unable to access auction house '%u' using auctioneer '%u'.", AHid, auctioneer);

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
		    {pConsole->Write(msg); pConsole->Write("\n");}

		return true;
	}

	if(!plr)
		plr = new Player( sAHBotMgr.m_PlayerGuid );

	sAHBotMgr.plr = plr;
	sAHBotMgr.ah = ah;
	sAHBotMgr.m_ThreadTask = AHBOT_PRELOAD;
	
	snprintf(msg, 200, "Queued the pre-loading of auction house '%u'.", ah->GetID());

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
	    {pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

bool ChatHandler::HandleAHBotUnloadCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotUnLoadAH(string(args), NULL, m_session);
}

bool AHBot::AHBotUnLoadAH(string args, BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	uint32 AHid = 0;
	if(args.length() > 0)
		AHid = atol(args.c_str());

	// Default to AH 1
	if(AHid == 0)
		AHid = 1;

	Player * plr = NULL;

	if ( m_session )
		plr = m_session->GetPlayer();

	// Get an auctioneer for the Auction House reference
	uint32 auctioneer = GetAnAuctioneer(plr, AHid);

	if(auctioneer == 0)
	{
		snprintf(msg, 200, "Unable to access an auctioneer for auction house '%u'.", AHid);

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
			{pConsole->Write(msg); pConsole->Write("\n");}

		return true;
	}

	// Create a reference to the Auction House
	AuctionHouse * ah = sAuctionMgr.GetAuctionHouse(auctioneer);
	if(!ah)
	{
		snprintf(msg, 200, "Unable to access auction house '%u' using auctioneer '%u'.", AHid, auctioneer);

		if ( m_session )
			sChatHandler.RedSystemMessage(m_session, msg);
		else
			{pConsole->Write(msg); pConsole->Write("\n");}

		return true;
	}

	if(sLog.m_fileLogLevel >= 1)
	{
		if ( m_session )
			snprintf(msg, 200, "Player %s initiated an unload for ah '%u'.", plr->GetName(), ah->GetID());
		else
			snprintf(msg, 200, "Player %s initiated an unload for ah '%u'.", "[Console]", ah->GetID());

		{pConsole->Write(msg); pConsole->Write("\n");}
	}

	sAHBotMgr.plr = plr;
	sAHBotMgr.ah = ah;
	sAHBotMgr.m_ThreadTask = AHBOT_UNLOAD;

	snprintf(msg, 200, "Queued the un-loading of auction house '%u'.", ah->GetID());

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

bool ChatHandler::HandleAHBotAutoCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotAutoAH(NULL, m_session);
}

bool AHBot::AHBotAutoAH(BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	Player * plr = NULL;

	if ( m_session )
		plr = m_session->GetPlayer();

	sAHBotMgr.plr = plr;
	sAHBotMgr.m_ThreadTask = AHBOT_UPDATE;
	
	snprintf(msg, 200, "Queued the updating of all the auction houses.");

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

bool ChatHandler::HandleAHBotReloadCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotReloadAH(NULL, m_session);
}

bool AHBot::AHBotReloadAH(BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	snprintf(msg, 200, "Queued the reloading of all the auction houses.");

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	// Refresh the auction houses
	sAuctionMgr.LoadAuctionHouses();

	return true;
}
bool ChatHandler::HandleAHBotClearCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotClearAH(NULL, m_session);
}

bool AHBot::AHBotClearAH(BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	Player * plr = NULL;

	if ( m_session )
		Player * plr = m_session->GetPlayer();

	sAHBotMgr.plr = plr;
	sAHBotMgr.m_ThreadTask = AHBOT_CLEAR;
	
	snprintf(msg, 200, "Queued the clearing of all auction houses.");

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

bool ChatHandler::HandleAHBotTimeCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotTimeAH(NULL, m_session);
}

bool AHBot::AHBotTimeAH(BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	uint32 maxAuctionTime = (uint32)(m_ExpirationMinutes * 60); // the configured maximum length of an auction
	uint32 minAuctionTime = (uint32)(maxAuctionTime / 8); // the derived minimum length of an auction
	uint32 minExpireTime = (uint32)UNIXTIME + minAuctionTime;
	uint32 maxExpireTime = (uint32)UNIXTIME + maxAuctionTime;

	snprintf(msg, 200, "UNIXTIME is %u, minExpireTime is %u, maxExpireTime is %u", (uint32)UNIXTIME, minExpireTime, maxExpireTime);

	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

bool ChatHandler::HandleAHBotConfigCommand(const char* args, WorldSession *m_session)
{
	return sAHBotMgr.AHBotConfigAH(NULL, m_session);
}

bool AHBot::AHBotConfigAH(BaseConsole * pConsole, WorldSession *m_session)
{
	char msg[200];

	if(pConsole)
		pConsole->Write("\n");

	snprintf(msg, 200, "AHBot configuration information:");
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tLoadOnStartUp = %u", m_LoadOnStartUp);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tClearOnStartup = %u", m_ClearOnStartup);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tCleanMailboxes = %u", m_CleanMailboxes);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tRefreshMinutes = %u", m_RefreshMinutes);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tExpirationMinutes = %u", m_ExpirationMinutes);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tRandomizeExpiration = %u", m_RandomizeExpiration);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tMinAuctions = %u", m_MinAuctions);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tHouses = %s", m_Houses.c_str());
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tWorldAnnounce = %u", m_AnnounceLoading);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tCustomPrices = %u", m_CustomPrices);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tBuyoutMultiplier = %u", m_BuyoutMultiplier);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tBidMultiplier = %u", m_BidMultiplier);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tLogLevel = %u", m_LogLevel);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tPlayerName = %s", m_PlayerName.c_str());
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	snprintf(msg, 200, "\tPlayerGuid = %u", m_PlayerGuid);
	if ( m_session )
		sChatHandler.BlueSystemMessage(m_session, msg);
	else
		{pConsole->Write(msg); pConsole->Write("\n");}

	return true;
}

void AHBot::ModifyRemoveAuction(AuctionHouseDBC * dbc, Auction * auct)
{
	// when owner is playerGuid, it was an automatically loaded item and can be ignored in some cases
	if (auct->Owner == sAHBotMgr.m_PlayerGuid)
	{
		// If we are our own highest bidder, then just expire the auction and delete the item
		if((auct->Owner == sAHBotMgr.m_PlayerGuid) && (auct->HighestBidder == sAHBotMgr.m_PlayerGuid))
		{
			auct->DeletedReason = AUCTION_REMOVE_EXPIRED;
			auct->pItem->DeleteFromDB();
		}

		if ( (sAHBotMgr.m_LogLevel >= 2) || (sLog.m_screenLogLevel > 1) )
			sLog.outString("Auction House %u: Removing auction %u because of reason %u.", dbc->id, auct->Id, auct->DeletedReason);
	}
}

void AHBot::AHBotConsoleCommands(BaseConsole * pConsole, int argc, string args)
{
	string cmd = "";
	bool ok2ShowHelp = false;

	if((args.length() > 0) && (argc > 0))
	{
		cmd = string(args);
		ASCENT_TOLOWER(cmd);

		if(cmd.find("help") != std::string::npos)
			ok2ShowHelp = true;
	}
	else
		ok2ShowHelp = true;

	if(ok2ShowHelp == true)
	{
		pConsole->Write("\n");
		pConsole->Write("ahbot console commands are:\n");
		pConsole->Write("  auto     - triggers the automatic startup event\n");
		pConsole->Write("  clear    - clears ALL auctions from ALL auction houses\n");
		pConsole->Write("  config   - shows AHBot configuration information\n");
		pConsole->Write("  count    - counts the auctions on all the auction houses\n");
		pConsole->Write("  help     - displays this information\n");
		pConsole->Write("  list     - lists the available auction houses\n");
		pConsole->Write("  load     - loads an auction house <required itemsToAdd> <optional AHId>\n");
		pConsole->Write("  reload   - Re-loads all auction houses from SQL\n");
		pConsole->Write("  loglevel - Change the AHBot log level\n");
		pConsole->Write("  preload  - triggers the pre-loading of the auction houses\n");
		pConsole->Write("  unload   - unloads an auction house <required AHId>\n");
		pConsole->Write("  refresh  - Change the refresh interval\n");
		pConsole->Write("  time     - shows the current UNIXTIME\n");
		pConsole->Write("");

		return;
	}

	size_t pos = 0;

	if(cmd.find("auto") != std::string::npos)
	{
		pos = cmd.find("auto");
		cmd.replace(pos, 4, "");

		sAHBotMgr.AHBotAutoAH(pConsole, NULL);
	}

	if(cmd.find("time") != std::string::npos)
	{
		pos = cmd.find("time");
		cmd.replace(pos, 4, "");

		sAHBotMgr.AHBotTimeAH(pConsole, NULL);
	}

	if(cmd.find("config") != std::string::npos)
	{
		pos = cmd.find("config");
		cmd.replace(pos, 6, "");

		sAHBotMgr.AHBotConfigAH(pConsole, NULL);
	}

	if(cmd.find("refresh") != std::string::npos)
	{
		pos = cmd.find("refresh");
		cmd.replace(pos, 7, "");

		sAHBotMgr.AHBotRefreshMinutesAH(cmd, pConsole, NULL);
	}

	if(cmd.find("clear") != std::string::npos)
	{
		pos = cmd.find("clear");
		cmd.replace(pos, 5, "");

		sAHBotMgr.AHBotClearAH(pConsole, NULL);
	}

	if(cmd.find("count") != std::string::npos)
	{
		pos = cmd.find("count");
		cmd.replace(pos, 5, "");

		sAHBotMgr.AHBotCountAH(pConsole, NULL);
	}

	if(cmd.find("list") != std::string::npos)
	{
		pos = cmd.find("list");
		cmd.replace(pos, 4, "");

		sAHBotMgr.AHBotListAH(pConsole, NULL);
	}

	if(cmd.find("loglevel") != std::string::npos)
	{
		pos = cmd.find("loglevel");
		cmd.replace(pos, 8, "");

		sAHBotMgr.AHBotLogLevelAH(cmd, pConsole, NULL);
	}

	if(cmd.find("preload") != std::string::npos)
	{
		pos = cmd.find("preload");
		cmd.replace(pos, 7, "");

		sAHBotMgr.AHBotPreloadAH(cmd, pConsole, NULL);
	}

	if(cmd.find("reload") != std::string::npos)
	{
		pos = cmd.find("reload");
		cmd.replace(pos, 6, "");

		sAHBotMgr.AHBotReloadAH(pConsole, NULL);
	}

	if(cmd.find("unload") != std::string::npos)
	{
		pos = cmd.find("unload");
		cmd.replace(pos, 6, "");

		sAHBotMgr.AHBotUnLoadAH(cmd, pConsole, NULL);
	}

	if(cmd.find("load") != std::string::npos)
	{
		pos = cmd.find("load");
		cmd.replace(pos, 4, "");

		sAHBotMgr.AHBotLoadAH(cmd, pConsole, NULL);
	}

	return;
}

uint32 AuctionHouse::CountSpecificItemId(uint32 itemid)
{
	uint32 count = 0;

	HM_NAMESPACE::hash_map<uint32, Auction*>::iterator itr = auctions.begin();
	Auction * auct;
	for(; itr != auctions.end();)
	{
		auct = itr->second;
		++itr;

		if(auct->pItem->GetEntry() == itemid)
			++count;
	}

	return count;
}

void AuctionHouse::UnloadAHBotAuctions()
{
	auctionLock.AcquireReadLock();
	removalLock.Acquire();

	HM_NAMESPACE::hash_map<uint32, Auction*>::iterator itr = auctions.begin();
	Auction * auct;
	for(; itr != auctions.end();)
	{
		auct = itr->second;
		++itr;

		if(auct->Owner == sAHBotMgr.m_PlayerGuid)
			QueueDeletion(auct, AUCTION_REMOVE_EXPIRED);
	}

	removalLock.Release();
	auctionLock.ReleaseReadLock();
}

uint32 AHBot::GetAnAuctioneer(Player *plr, uint32 AHid)
{
	uint32 auctioneer = 0;
	uint32 ah_faction = 1; // Alliance = 1, Horde = 2, Neutral = 3

	//If no AH id was specified, try to find one...
	if(AHid == 0)
	{
		//if this is not a null session
		if(plr)
		{
			//Get the player's faction in case there is no auctioneer targeted
			ah_faction = plr->GetTeam(); // _getFaction();

			//see if the player targeted something
			uint32 guid = GUID_LOPART(plr->GetSelection());
			if (guid != 0)
			{
				Creature *unit = plr->GetMapMgr()->GetCreature(guid);
				if(unit)
				{
					if(unit->auctionHouse != 0)
						auctioneer = unit->GetEntry();
				}
			}
		}
	}

	//if nothing was found yet, do a lookup from the database
	if(auctioneer == 0)
	{
		if(AHid != 0)
			ah_faction = AHid;

		QueryResult *resultAunctioneer2 = WorldDatabase.Query("SELECT `creature_entry` FROM auctionhouse WHERE `group` = %u LIMIT 1", ah_faction);
		if(resultAunctioneer2)
		{
			Field *fields = resultAunctioneer2->Fetch();
			auctioneer = fields[0].GetUInt32();

			delete resultAunctioneer2;
		}
	}

	return auctioneer;
}

void Container::Create( uint32 itemid, Player *owner, ItemPrototype *proto )
{
	m_itemProto = proto;
	ASSERT(m_itemProto);

	SetUInt32Value( OBJECT_FIELD_ENTRY, itemid );
	SetUInt64Value( ITEM_FIELD_OWNER, owner->GetGUID() );
	SetUInt64Value( ITEM_FIELD_CONTAINED, owner->GetGUID() );
	SetUInt32Value( ITEM_FIELD_STACK_COUNT, 1 );
	SetUInt32Value( CONTAINER_FIELD_NUM_SLOTS, m_itemProto->ContainerSlots);

	m_Slot = new Item*[m_itemProto->ContainerSlots];
	memset(m_Slot, 0, sizeof(Item*)*(m_itemProto->ContainerSlots));

	m_owner = owner;
}

void Item::Create( uint32 itemid, Player *owner, ItemPrototype *proto )
{
	SetUInt32Value( OBJECT_FIELD_ENTRY, itemid );
 
	SetUInt64Value( ITEM_FIELD_OWNER, owner->GetGUID() );
	SetUInt64Value( ITEM_FIELD_CONTAINED, owner->GetGUID() );
	SetUInt32Value( ITEM_FIELD_STACK_COUNT, 1 );

	m_itemProto = proto;
	ASSERT(m_itemProto);
	 
	SetUInt32Value( ITEM_FIELD_SPELL_CHARGES , m_itemProto->Spells[0].Charges );
	SetUInt32Value( ITEM_FIELD_SPELL_CHARGES_01 , m_itemProto->Spells[1].Charges );
	SetUInt32Value( ITEM_FIELD_SPELL_CHARGES_02 , m_itemProto->Spells[2].Charges );
	SetUInt32Value( ITEM_FIELD_SPELL_CHARGES_03 , m_itemProto->Spells[3].Charges );
	SetUInt32Value( ITEM_FIELD_SPELL_CHARGES_04 , m_itemProto->Spells[4].Charges );
	SetUInt32Value( ITEM_FIELD_MAXDURABILITY, m_itemProto->MaxDurability);
	SetUInt32Value( ITEM_FIELD_DURABILITY, m_itemProto->MaxDurability);

	m_owner = owner;
	if(m_itemProto->LockId > 1)
		locked = true;
	else
		locked = false;
}

Item * ObjectMgr::CreateItem(uint32 entry, Player * owner, ItemPrototype * proto)
{
	if(proto == 0) return 0;

	if(proto->InventoryType == INVTYPE_BAG)
	{
		Container * pContainer = new Container(HIGHGUID_TYPE_CONTAINER,GenerateLowGuid(HIGHGUID_TYPE_CONTAINER));
		pContainer->Create(entry, owner, proto);
		pContainer->SetUInt32Value(ITEM_FIELD_STACK_COUNT, 1);
		return pContainer;
	}
	else
	{
		Item * pItem = ItemPool.PooledNew();
		pItem->Init( HIGHGUID_TYPE_ITEM, GenerateLowGuid(HIGHGUID_TYPE_ITEM) );
		pItem->Create(entry, owner, proto);
		pItem->SetUInt32Value(ITEM_FIELD_STACK_COUNT, 1);
		return pItem;
	}
}
