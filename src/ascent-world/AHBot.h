/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _AHBOT_H
#define _AHBOT_H

#include "AHBotThread.h"
#include "BaseConsole.h"

class AHBot;
struct Auction;
class AuctionHouse;
class ChatHandler;

class AHBot : public Singleton <AHBot>
{
public:

	bool m_started;
	AHBOT_THREAD_TASKS m_ThreadTask;

	int m_LogLevel;
	int m_ClearOnStartup;
	int m_RefreshInterval;
	int m_RefreshMinutes;
	int m_LoadOnStartUp;
	int m_CleanMailboxes;
	int m_MinAuctions;
	string m_Houses;
	int m_AnnounceLoading;
	int m_ExpirationMinutes;
	int m_RandomizeExpiration;
	string m_IncludeClasses;
	int m_AllowQuestItems;
	int m_MinItemLevel;
	int m_MaxItemLevel;
	int m_MinPlayerLevel;
	int m_MaxPlayerLevel;
	int m_MinItemQuality;
	int m_MaxItemQuality;
	int m_MaxItemCount;
	int m_MaxStack;
	int m_CustomPrices;
	float m_BuyoutMultiplier;
	float m_BidMultiplier;
	string m_PlayerName;
	uint32 m_PlayerGuid;

	AuctionHouse * ah;
	uint32 itemsToAdd;
	Player * plr;

	void LoadSettings();
	void SetThreadTask(AHBOT_THREAD_TASKS task);
	AHBOT_THREAD_TASKS GetThreadTask();
	bool GetThreadTask(AHBOT_THREAD_TASKS task);
	void ModifyRemoveAuction(AuctionHouseDBC * dbc, Auction * auct);

	uint32 GetAnAuctioneer(Player *plr, uint32 AHid);

	void AHBotSendMessage(char msg, BaseConsole * pConsole, WorldSession *m_session);
	void AHBotConsoleCommands(BaseConsole * pConsole, int argc, string args);
	bool AHBotAutoAH(BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotClearAH(BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotConfigAH(BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotCountAH(BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotListAH(BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotLogLevelAH(string args, BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotLoadAH(string args, BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotPreloadAH(string args, BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotReloadAH(BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotUnLoadAH(string args, BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotTimeAH(BaseConsole * pConsole, WorldSession *m_session);
	bool AHBotRefreshMinutesAH(string args, BaseConsole * pConsole, WorldSession *m_session);

private:
	void OnStart();

public:
};

#define sAHBotMgr AHBot::getSingleton()

#endif
