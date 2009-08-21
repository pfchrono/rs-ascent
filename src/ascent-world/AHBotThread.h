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

#ifndef _AHBOTTHREAD_H
#define _AHBOTTHREAD_H

#include "AHBot.h"
#include "../../src/ascent-world/Master.h"
#include "../ascent-shared/Threading/Condition.h"

class AuctionHouse;

enum AHBOT_THREAD_TASKS
{
	AHBOT_SLEEPING  = 0,
	AHBOT_STARTUP	= 1,
	AHBOT_UPDATE	= 2,
	AHBOT_PRELOAD	= 3,
	AHBOT_LOAD		= 4,
	AHBOT_UNLOAD	= 5,
	AHBOT_COMPLETE  = 6,
	AHBOT_CLEAR     = 7,
	AHBOT_SETTINGS  = 8,
};

class AHBotUpdaterThread : public CThread
{
	bool m_running;
	bool m_busy;
	bool m_dirty;

	time_t currenttime;
	time_t last_update_time;
	time_t last_mail_time;
	time_t last_playeritems_time;

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

public:
	AHBotUpdaterThread();
	~AHBotUpdaterThread();

	bool run();
	void terminate();

	void load_threadsettings();

	bool has_mail_expired(time_t now_time, time_t last_time);
	bool has_update_expired(time_t now_time, time_t last_time);
	bool has_playeritems_expired(time_t now_time, time_t last_time);

	void update_auctionhouse();
	bool add_item(Player * plr, AuctionHouse * ah, uint32 itemToAdd, uint32 auctionExpire);
	bool preload_auctionhouse(AuctionHouse * ah);
	bool load_auctionhouse(AuctionHouse * ah, uint32 itemsToAdd);
	bool load_auctionhouse(Player * plr, AuctionHouse * ah, uint32 itemsToAdd);
	void unload_auctionhouse(Player * plr, AuctionHouse * ah);
	void startup_auctionhouse(uint32 ahid, uint32 itemThreshold);

	void clean_mailboxes();
	void clean_playeritems();
	void clear_auctionhouses();
};

#endif
