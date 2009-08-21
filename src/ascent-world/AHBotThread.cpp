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

#include "StdAfx.h"

#ifdef WIN32
static HANDLE m_abortEvent = INVALID_HANDLE_VALUE;
#endif

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

AHBotUpdaterThread::AHBotUpdaterThread()
{
	m_running = true;
	m_dirty = false;
}

AHBotUpdaterThread::~AHBotUpdaterThread()
{

}

void AHBotUpdaterThread::load_threadsettings()
{
	if(sLog.m_screenLogLevel >= 2)
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), load_threadsettings().", GetThreadId());

	while(!sAHBotMgr.GetThreadTask(AHBOT_STARTUP))
	{
		// Sleep/wait for 10,000 milliseconds (10 seconds)
#ifdef WIN32
		WaitForSingleObject(m_abortEvent, 10000);
#else
		Sleep(10000);
#endif
	}

	m_LogLevel = sAHBotMgr.m_LogLevel;
	m_ClearOnStartup = sAHBotMgr.m_ClearOnStartup;
	m_RefreshInterval = sAHBotMgr.m_RefreshInterval;
	m_RefreshMinutes = sAHBotMgr.m_RefreshMinutes;
	m_LoadOnStartUp = sAHBotMgr.m_LoadOnStartUp;
	m_CleanMailboxes = sAHBotMgr.m_CleanMailboxes;
	m_MinAuctions = sAHBotMgr.m_MinAuctions;
	m_Houses = sAHBotMgr.m_Houses;
	m_AnnounceLoading = sAHBotMgr.m_AnnounceLoading;
	m_ExpirationMinutes = sAHBotMgr.m_ExpirationMinutes;
	m_RandomizeExpiration = sAHBotMgr.m_RandomizeExpiration;
	m_IncludeClasses = sAHBotMgr.m_IncludeClasses;
	m_AllowQuestItems = sAHBotMgr.m_AllowQuestItems;
	m_MinItemLevel = sAHBotMgr.m_MinItemLevel;
	m_MaxItemLevel = sAHBotMgr.m_MaxItemLevel;
	m_MinPlayerLevel = sAHBotMgr.m_MinPlayerLevel;
	m_MaxPlayerLevel = sAHBotMgr.m_MaxPlayerLevel;
	m_MinItemQuality = sAHBotMgr.m_MinItemQuality;
	m_MaxItemQuality = sAHBotMgr.m_MaxItemQuality;
	m_MaxItemCount = sAHBotMgr.m_MaxItemCount;
	m_MaxStack = sAHBotMgr.m_MaxStack;
	m_CustomPrices = sAHBotMgr.m_CustomPrices;
	m_BuyoutMultiplier = sAHBotMgr.m_BuyoutMultiplier;
	m_BidMultiplier = sAHBotMgr.m_BidMultiplier;
	m_PlayerName = sAHBotMgr.m_PlayerName;
	m_PlayerGuid = sAHBotMgr.m_PlayerGuid;

	currenttime = UNIXTIME;

	last_mail_time = 0;
	last_update_time = 0;
    last_playeritems_time = 0;
}

void AHBotUpdaterThread::terminate()
{
	Log.Debug("AHBotUpdaterThread", "Thread('%u'), terminate()", GetThreadId());

	m_running = false;
#ifdef WIN32
	SetEvent(m_abortEvent);
#endif
}

bool AHBotUpdaterThread::has_mail_expired(time_t now_time, time_t last_time)
{
	// Time is in seconds, refreshInterval is in seconds
	// the sleep interval for this thread is 60 seconds, so we subtract that interval
	if(((uint32)now_time - (uint32)last_time) > (600 - 60)) return true;

	return false;
}

bool AHBotUpdaterThread::has_update_expired(time_t now_time, time_t last_time)
{
	// Time is in seconds, refreshInterval is in hours, so we multiply by 3600 seconds in one hour
	// the sleep interval for this thread is 60 seconds, so we subtract that interval
	//if(((uint32)now_time - (uint32)last_time) > ((m_RefreshInterval * 3600) - 60)) return true;

	// Time is in seconds, refreshInterval is in minutes, so we multiply by 60 seconds in one minute
	// the sleep interval for this thread is 60 seconds, so we subtract that interval
	if(((uint32)now_time - (uint32)last_time) > (((uint32)m_RefreshMinutes * 60) - 60)) return true;

	return false;
}

bool AHBotUpdaterThread::has_playeritems_expired(time_t now_time, time_t last_time)
{
	// Time is in seconds, refreshInterval is in seconds
	// the sleep interval for this thread is 60 seconds, so we subtract that interval
	if(((uint32)now_time - (uint32)last_time) > (3600 - 60)) return true;

	return false;
}

bool AHBotUpdaterThread::run()
{
	Log.Debug("AHBotUpdaterThread", "Thread('%u'), run()", GetThreadId());

	m_busy = false;
#ifdef WIN32
	m_abortEvent = CreateEvent(NULL, NULL, FALSE, NULL);
#endif
	
	load_threadsettings();
	
	if(m_PlayerGuid == 0)
	{
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), run(), encountered m_PlayerGuid == 0", GetThreadId());
		m_running = false;
		terminate();
	}

	if(m_ClearOnStartup == 1)
		clear_auctionhouses();

	while(ThreadState != THREADSTATE_TERMINATE)
	{
		if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
			Log.Debug("AHBotUpdaterThread", "Thread('%u'), Looping, task('%u').", GetThreadId(), sAHBotMgr.GetThreadTask());

		m_busy = true;

		currenttime = UNIXTIME;

		// Was a reload of the settings triggered?
		if((m_running == true) && (sAHBotMgr.GetThreadTask(AHBOT_SETTINGS)))
		{
			load_threadsettings();
			sAHBotMgr.SetThreadTask(AHBOT_COMPLETE);
		}

		// Was an AH update triggered outside the normally scheduled cycle?
		if((m_running == true) && (sAHBotMgr.GetThreadTask(AHBOT_UPDATE)))
		{
			update_auctionhouse();
			sAHBotMgr.SetThreadTask(AHBOT_COMPLETE);
		}

		// Was an AH clear triggered?
		if((m_running == true) && (sAHBotMgr.GetThreadTask(AHBOT_CLEAR)))
		{
			clear_auctionhouses();
			sAHBotMgr.SetThreadTask(AHBOT_COMPLETE);
		}

		// Was an AH pre-load triggered?
		if((m_running == true) && (sAHBotMgr.GetThreadTask(AHBOT_PRELOAD)))
		{
			preload_auctionhouse(sAHBotMgr.ah);
			sAHBotMgr.SetThreadTask(AHBOT_COMPLETE);
		}

		// Was an AH load triggered?
		if((m_running == true) && (sAHBotMgr.GetThreadTask(AHBOT_LOAD)))
		{
			load_auctionhouse(sAHBotMgr.plr, sAHBotMgr.ah, sAHBotMgr.itemsToAdd);
			sAHBotMgr.SetThreadTask(AHBOT_COMPLETE);
		}

		// Was an AH unload triggered?
		if((m_running == true) && (sAHBotMgr.GetThreadTask(AHBOT_UNLOAD)))
		{
			unload_auctionhouse(sAHBotMgr.plr, sAHBotMgr.ah);
			sAHBotMgr.SetThreadTask(AHBOT_COMPLETE);
		}

		// Is it time for the next mailbox update?
		if ( m_CleanMailboxes == 1)
		{
			if ( ( m_running == true ) && ( has_mail_expired(currenttime, last_mail_time) ) )
				clean_mailboxes();
		}

		// Is it time for the next regular auction house update?
		if((m_running == true) && (has_update_expired(currenttime, last_update_time)))
			update_auctionhouse();

		// Is it time for the next playeritems update?
		if((m_running == true) && (has_playeritems_expired(currenttime, last_playeritems_time)))
			clean_playeritems();

		m_busy = false;

		// Was there a shutdown event?
		if(sMaster.m_ShutdownEvent == true)
			break;

		if(ThreadState == THREADSTATE_TERMINATE)
			break;

		// Sleep/wait for 60,000 milliseconds (1 minute)
#ifdef WIN32
		WaitForSingleObject(m_abortEvent, 60000);
#else
		Sleep(60000);
#endif
		if(!m_running)
			break;
	}

#ifdef WIN32
	CloseHandle(m_abortEvent);
#endif

	return true;
}

void AHBotUpdaterThread::startup_auctionhouse(uint32 ahid, uint32 itemThreshold)
{
	if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), startup_auctionhouse('%u','%u')", GetThreadId(), ahid, itemThreshold);

	if((itemThreshold <= 0) || (ahid <= 0))
		return;

	uint32 auctioneer = 0;

	// auctioneer was renamed to creature_entry and AHid was renamed to group in revision 2311
	QueryResult *resultAunctioneer = WorldDatabase.Query("SELECT `creature_entry` FROM auctionhouse WHERE `group` = %u LIMIT 1", ahid);
	if(resultAunctioneer)
	{
		Field *fields = resultAunctioneer->Fetch();
		auctioneer = fields[0].GetUInt32();

		delete resultAunctioneer;
	}

	if(auctioneer <= 0)
	{
		sLog.outString("LoadAHBotAuctionsOnStartup: Unable to get an auctioneer for auction house '%u'", ahid);
		return;
	}

	// Create a reference to the Auction House
	AuctionHouse * ah = sAuctionMgr.GetAuctionHouse(auctioneer);
	if(!ah)
	{
		sLog.outString("LoadAHBotAuctionsOnStartup: Unable to access auction house '%u' using auctioneer '%u'", ahid, auctioneer);
		return;
	}

	// Pre-load the auction house with items stored in a table
	if(!preload_auctionhouse(ah))
	{
		sLog.outString("LoadAHBotAuctionsOnStartup: Failed to pre-load the auction house '%u'", ahid);
	}

	// Get the current number of auction in the AH
	uint32 currentAuctions = 0;
	QueryResult *resultAuctions = CharacterDatabase.Query("SELECT Count(auctionid) FROM auctions WHERE auctionhouse = %u", ahid);
	if(resultAuctions)
	{
		Field *fields = resultAuctions->Fetch();
		currentAuctions = fields[0].GetUInt32();

		delete resultAuctions;
	}

	// Does the current number of auctions meet or exceed the current configured threshold?
	if(currentAuctions >= itemThreshold)
		return;

	uint32 itemsToAdd = (itemThreshold - currentAuctions);
	if(itemsToAdd <= 0)
		return;

	if(!load_auctionhouse(ah, itemsToAdd))
	{
		sLog.outString("LoadAHBotAuctionsOnStartup: Failed to load the auction house '%u'", ahid);
		return;
	}

	return;
}

void AHBotUpdaterThread::update_auctionhouse()
{
	if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), update_auctionhouse()", GetThreadId());

	if((m_LoadOnStartUp == 1) && (m_MinAuctions >= 1))
	{
		if(m_Houses.find("0") != string::npos)	startup_auctionhouse(0, m_MinAuctions);
		if(m_Houses.find("1") != string::npos)	startup_auctionhouse(1, m_MinAuctions);
		if(m_Houses.find("2") != string::npos)	startup_auctionhouse(2, m_MinAuctions);
		if(m_Houses.find("3") != string::npos)	startup_auctionhouse(3, m_MinAuctions);
		if(m_Houses.find("4") != string::npos)	startup_auctionhouse(4, m_MinAuctions);
		if(m_Houses.find("5") != string::npos)	startup_auctionhouse(5, m_MinAuctions);
		if(m_Houses.find("6") != string::npos)	startup_auctionhouse(6, m_MinAuctions);
		if(m_Houses.find("7") != string::npos)	startup_auctionhouse(7, m_MinAuctions);
		if(m_Houses.find("8") != string::npos)	startup_auctionhouse(8, m_MinAuctions);
		if(m_Houses.find("9") != string::npos)	startup_auctionhouse(9, m_MinAuctions);
	}

	// Update the last auction house update time since it occurs on a recurring cycle
	last_update_time = currenttime;

	return;
}

bool AHBotUpdaterThread::add_item(Player * tmpPlr, AuctionHouse * ah, uint32 itemToAdd, uint32 auctionExpire)
{
	if((m_LogLevel >= 2) && (m_PlayerGuid == 0))
	{
		sLog.outString("AHBotUpdaterThread::add_item() encountered m_PlayerGuid == 0");
		return false;
	}

	bool ok2AddItem = false;

	//If we can lookup the entry, it is a good itemid
	ItemPrototype* it = ItemPrototypeStorage.LookupEntry(itemToAdd);
	if (it)
	{
		ok2AddItem = true;

		if((ok2AddItem) && (m_IncludeClasses != ""))
		{
			string includeClasses = "," + m_IncludeClasses + ","; // tack a comma at the beginning and end - searching for 1 with the comma at the end - prevents finding class 1 when 10,11 are included

			string sClass = MyConvertToString(it->Class) + ",";

			if(!includeClasses.find(sClass)) // did we find the class in the list of included classes?
			{
				ok2AddItem = false;
				if(m_LogLevel >= 2)
					sLog.outString("AHBot Rejected '%u' - class '%u' ('%s') was not in '%s'", it->ItemId, it->Class, sClass.c_str(), includeClasses.c_str());
			}
		}

		// This should all be handled by the loops that call this routine using trackItemCount[]
		// Does the config file specify that we need to count the number of auctions with this item id?
		//if((ok2AddItem) && (m_MaxItemCount > 0))
		//{
		//	if((uint32)m_MaxItemCount <= ah->CountSpecificItemId(it->ItemId))
		//	{
		//		ok2AddItem = false;
		//		if(m_LogLevel >= 2)
		//			sLog.outString("AHBot Rejected item id '%u' because MaxItemCount was exceeded", it->ItemId);
		//	}
		//}

		// Exclude items that are needed by a quest
		if((m_AllowQuestItems == 0) && (it->QuestId != 0))
			ok2AddItem = false; 
		// Vip Crap to block
		if( it->RequiredSkill == 769 )
			ok2AddItem = false;
		if( it->ZoneNameID != 0 )
			ok2AddItem = false;
		// Dont add Our Custom RS Item's
		if( it->ItemId > 34141 )
			ok2AddItem = false;
		// Exclude items that don't meet the level standards
		if((it->ItemLevel < (uint32)m_MinItemLevel) || (it->ItemLevel > (uint32)m_MaxItemLevel))
			ok2AddItem = false;
			
		// Exclude items that don't meet the player level standards
		if((it->RequiredLevel < (uint32)m_MinPlayerLevel) || (it->RequiredLevel > (uint32)m_MaxPlayerLevel))
			ok2AddItem = false;
			
		// Exclude items that don't meet the quality standards
		if((it->Quality < (uint32)m_MinItemQuality) || (it->Quality > (uint32)m_MaxItemQuality))
			ok2AddItem = false;
			
		// Exclude items with an extended cost
		if( objmgr.HasExtendedCost( it->ItemId ) )
			ok2AddItem = false;

		// Exclude these bonding types
		if((it->Bonding == ITEM_BIND_ON_PICKUP) || (it->Bonding == ITEM_BIND_QUEST) || (it->Bonding == ITEM_BIND_QUEST2))
			ok2AddItem = false;

		// Is it still ok to add them item?
		if(ok2AddItem)
		{
			Item *itemTmp;
			itemTmp = objmgr.CreateItem(itemToAdd, tmpPlr, it);

			if(itemTmp)
			{
				uint32 stackCount = 1;

				// Can we stack more than 1 item at a time?
				if(it->MaxCount > 1)
				{
					// How many items should be in the stack?
					switch (m_MaxStack)
					{
					  case 0: // Only 1 of an item
						stackCount = 1;
						break;
					  case 1: // Random number between 1 and maxmimum
						stackCount = RandomUInt(it->MaxCount); // find a random number
						break;
					  case 2: // Maximum possible for the stack
						stackCount = it->MaxCount;
						break;
					  default: // Default to maximum possible
						stackCount = it->MaxCount;
					}

					if(stackCount <= 0)
						stackCount = 1;
				}

				// Is this a stackable item?
				itemTmp->SetUInt32Value(ITEM_FIELD_STACK_COUNT, stackCount);

				// This determines whether a chargeable item is expendable or non-expendable
				// Is this an expendable chargeable item?
				if(it->Spells[0].Charges < 0) // EXPENDABLE ITEM
				{
					//i_caster->ModUInt32Value(ITEM_FIELD_SPELL_CHARGES, 1); // remove 1 charge for an expendable item
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES, -2); //it->Spells[0].Charges
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES_01, it->Spells[1].Charges );
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES_02, it->Spells[2].Charges );
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES_03, it->Spells[3].Charges );
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES_04, it->Spells[4].Charges );
				}

				// Is this a non-expendable chargeable item?
				if(it->Spells[0].Charges > 0) // NON-EXPENDABLE ITEM
				{
					// i_caster->ModUInt32Value(ITEM_FIELD_SPELL_CHARGES, -1); // remove 1 charge for a non-expendable item
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES, 2); //it->Spells[0].Charges
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES_01, it->Spells[1].Charges );
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES_02, it->Spells[2].Charges );
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES_03, it->Spells[3].Charges );
					itemTmp->SetUInt32Value(ITEM_FIELD_SPELL_CHARGES_04, it->Spells[4].Charges );
				}

				// Remove the item from the world and the owner and save to database
				itemTmp->RemoveFromWorld();
				itemTmp->SetOwner(0);
				itemTmp->SaveToDB(INVENTORY_SLOT_NOT_SET, 0, true, NULL);

				uint32 buyout = 0; // the calculated buyout price of the item
				uint32 bid = 0; // the calculated bid price of the item

				// Calculate the standard buyout price first
				if(it->BuyPrice == 0)
					buyout = (uint32)(it->SellPrice * m_BuyoutMultiplier * 5); // Buyprice is typically 5X the sellprice
				else
					buyout = (uint32)(it->BuyPrice * m_BuyoutMultiplier);	

				if(m_CustomPrices == 1)
				{
					// We're using a custom buyout price based on the auction_house_statistics table
					QueryResult *resultCustomPrices = CharacterDatabase.Query("SELECT avgPrice FROM auction_house_statistics WHERE entry = %u",itemToAdd);
					if(resultCustomPrices)
					{
						Field *CustomPrices = resultCustomPrices->Fetch();
						buyout = CustomPrices[0].GetUInt32();
					}
					delete resultCustomPrices;
				}
				// buyout of 0 or less confuses the AH
				if(buyout <= 0)
					buyout = 1;

				// multiply the buyout by the number of items in the stack
				buyout = (uint32)(buyout * stackCount);

				// Calculate the bid price, including the number of items in the stack
				bid = (uint32)(it->BuyPrice * m_BidMultiplier * stackCount);
				if(bid < 0)
					bid = 0;

				// The buyout always needs to be larger than the bid
				if(buyout <= bid)
					buyout = bid + 1;

				// Create auction structure
				Auction * auct = new Auction;
				auct->BuyoutPrice = buyout;
				auct->Deleted = false;
				auct->DeletedReason = 0;
				auct->DepositAmount = 1;
				auct->ExpiryTime = auctionExpire;
				auct->HighestBid = bid;
				if(bid >= 1)
					auct->HighestBidder = m_PlayerGuid;
				else
					auct->HighestBidder = 0;
				auct->Id = sAuctionMgr.GenerateAuctionId();
				auct->Owner = m_PlayerGuid;
				auct->pItem = itemTmp;

				// Add to the auction house.
				ah->AddAuction(auct);
				auct->SaveToDB(ah->GetID());
			}
		}
	}

	return ok2AddItem;
}

bool AHBotUpdaterThread::preload_auctionhouse(AuctionHouse * ah)
{
	char msg[200];

	if((m_LogLevel >= 2) && (m_PlayerGuid == 0))
	{
		sLog.outString("AHBotUpdaterThread::preload_auctionhouse() encountered m_PlayerGuid == 0");
		return false;
	}

	if(!ah)
	{
		if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
			Log.Debug("AHBotUpdaterThread", "Thread('%u'), preload_auctionhouse(INVALID_AH)", GetThreadId());
		return false;
	}

	if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), preload_auctionhouse('%u')", GetThreadId(), ah->GetID());

	uint32 currentTime = getMSTime();

	// If configured to make a world announce, then this is the time...
	if( m_AnnounceLoading == 1 )
	{
		snprintf(msg, 200, "AHBot is attempting to pre-load AH '%u'", ah->GetID());

		sWorld.SendWorldWideScreenText(msg); // send message to players

		if( m_LogLevel >= 1 )
			sLog.outString(msg); // send message to console
	}

	// Get the current pre-defined items to load into the auction house
	QueryResult *resultAuctions = CharacterDatabase.Query("SELECT itemid, itemcount FROM ahbotitems WHERE auctionhouse = %u", ah->GetID());
	if(resultAuctions)
	{
		// We only need a dummy player, the item is quickly taken away from the player and placed in the auction house
		Player * tmpPlr = new Player(m_PlayerGuid);

		// Save the current MaxStack setting
		uint32 previousStack = m_MaxStack;

		m_MaxStack = 2; // Force to a full stack of each item

		uint32 auctionExpire = (uint32)UNIXTIME + (uint32)(m_ExpirationMinutes * 60); // the time the auctions will expire

		do
		{
			Field *fields = resultAuctions->Fetch();
			uint32 itemId = fields[0].GetUInt32();
			uint32 itemCount = fields[1].GetUInt32();

			uint32 itemExisting = ah->CountSpecificItemId(itemId);

			if(itemExisting >= itemCount)
				itemCount = 0;

			if(itemCount > 0)
			{
				for (uint32 i = 0; i < itemCount; i++)
				{
					add_item(tmpPlr, ah, itemId, auctionExpire);
				}
			}

		}while (resultAuctions->NextRow());

		delete resultAuctions;

		// Restore the previous MaxStack setting
		m_MaxStack = previousStack;

		//Remove the dummy player from the world
		tmpPlr->RemoveFromWorld();
	}

	// If configured to make a world announce, then this is the time...
	if ( m_AnnounceLoading == 1 )
	{
		snprintf(msg, 200, "AHBot finished pre-loading AH '%u' in %u ms", ah->GetID(), getMSTime() - currentTime);

		sWorld.SendWorldWideScreenText(msg); // send message to players

		if( m_LogLevel >= 1 )
			sLog.outString(msg); // send message to console
	}

	return true;
}

bool AHBotUpdaterThread::load_auctionhouse(Player * plr, AuctionHouse * ah, uint32 itemsToAdd)
{
	char msg[200];

	if((m_LogLevel >= 2) && (m_PlayerGuid == 0))
	{
		sLog.outString("AHBotUpdaterThread::load_auctionhouse() encountered m_PlayerGuid == 0");
		return false;
	}

	bool finished = load_auctionhouse(ah, itemsToAdd);

	if(finished)
		snprintf(msg, 200, "AHBot finished re-loading AH '%u'", ah->GetID());
	else
		snprintf(msg, 200, "AHBot did NOT finish re-loading AH '%u'", ah->GetID());

	if(plr)
	{
		if(plr->IsInWorld())
			plr->GetSession()->SendNotification(msg);
		else
			sLog.outString(msg);
	}

	return finished;
}

bool AHBotUpdaterThread::load_auctionhouse(AuctionHouse * ah, uint32 itemsToAdd)
{
	char msg[200];

	if ( ( m_LogLevel >= 2 ) && ( m_PlayerGuid == 0 ) )
	{
		sLog.outString("AHBotUpdaterThread::load_auctionhouse() encountered m_PlayerGuid == 0");
		return false;
	}

	if ( ( sLog.m_screenLogLevel >= 2 ) || ( m_LogLevel >= 1 ) )
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), load_auctionhouse('%u', '%u')", GetThreadId(), ah->GetID(), itemsToAdd);

	if ( itemsToAdd <= 0 )
		return false;

	uint32 currentTime = getMSTime();

	// If configured to make a world announce, then this is the time...
	if ( m_AnnounceLoading == 1 )
	{
		snprintf(msg, 200, "AHBot is attempting to re-load AH '%u'", ah->GetID());

		sWorld.SendWorldWideScreenText(msg); // send message to players

		if ( m_LogLevel >= 1 )
			sLog.outString(msg); // send message to console
	}

	//Get the current maximum entry in the items table
	uint32 maxItemId = 34141;
	QueryResult *resultMaxId = WorldDatabase.Query("SELECT MAX(entry) FROM items");
	if ( resultMaxId )
	{
		Field *fields = resultMaxId->Fetch();
		maxItemId = fields[0].GetUInt32();

		delete resultMaxId;
	}

	uint32 randDatabaseValue = 0; // the random value from the database
	uint32 maxRandDataBaseVal = 0; // the maximum random value in the dayabase
	uint32 maxCountOfRandomItem = 0; // the maximum stack value

	// This is supposed to place the table/array into the heap and bypass stack limitations???
	uint8 *trackItemCount;
	//trackItemCount = new uint8[500000];

	try
		{
			trackItemCount = new uint8[500000];
		}

		catch (std::bad_alloc &)
		{
			Log.Debug("AHBotUpdaterThread", "Thread('%u'), load_auctionhouse - trackItemCount exception was caught properly.", GetThreadId());
			trackItemCount = NULL;
		}
		catch (...)
		{
			Log.Debug("AHBotUpdaterThread", "Thread('%u'), load_auctionhouse - trackItemCount exception was NOT caught properly.", GetThreadId());
			trackItemCount = NULL;
		}

	// Was memory successfully allocated for the table/array?
	if ( ( trackItemCount != NULL ) && ( m_MaxItemCount > 0 ) )
	{
		//fill with the m_MaxItemCount from ascent.conf
		for( uint32 i = 0; i < 500000; i++ )
			trackItemCount[i] = m_MaxItemCount; // m_MaxItemCount may or may not be 0
	}

	if ( m_CustomPrices == 1 )
	{
		QueryResult *resultmaxRandDataBaseVal = CharacterDatabase.Query("SELECT SUM(volume) FROM auction_house_statistics");
		if ( resultmaxRandDataBaseVal )
		{
			Field *fields = resultmaxRandDataBaseVal->Fetch();
			maxRandDataBaseVal = fields[0].GetUInt32();

			delete resultmaxRandDataBaseVal;
		}
	}

	if ( m_LogLevel >= 2 )
		sLog.outString("AHBot is using maximum item id '%u'", maxItemId);

	// We only need a dummy player, the item is quickly taken away from the player and placed in the auction house
	Player * tmpPlr = new Player( m_PlayerGuid);

	uint32 itemLoopMax = itemsToAdd * 1000; // I know the random number generator is going to hit on some missing items, so lets limit the amount of looping it does
	uint32 itemCount = 0; // the number of auction items actually added
	uint32 itemLoops = 0; // the number of times the loops has executed, whether or not an item was added
	uint32 itemRandom = 0; // the random item id to be added

	uint32 maxAuctionTime = (uint32)(m_ExpirationMinutes * 60); // the configured maximum length of an auction
	uint32 minAuctionTime = (uint32)(maxAuctionTime / 8); // the derived minimum length of an auction

	if ( minAuctionTime < 1800 )
		minAuctionTime = 1800; // 30 minutes

	if ( minAuctionTime > maxAuctionTime )
		maxAuctionTime = minAuctionTime * 2;

	uint32 minExpireTime = (uint32)UNIXTIME + minAuctionTime;
	uint32 maxExpireTime = (uint32)UNIXTIME + maxAuctionTime;

	uint32 auctionExpire = maxExpireTime; // the default is the the actual maximum time the auctions will expire
	uint32 randomExpire = 0;

	uint32 diffExpireTime = maxExpireTime - minExpireTime;

	while ( ( itemCount < itemsToAdd ) && ( itemLoops <= itemLoopMax ) )
	{
		itemLoops++;

		if ( itemCount != itemsToAdd )
		{
			itemRandom = RandomUInt(maxItemId); // find a random number first
			// Are we using custom prices? Let's wee if we can find a random item from the database instead
			if ( m_CustomPrices == 1 )
			{
				randDatabaseValue = RandomUInt(maxRandDataBaseVal); // find a random number to pick from the database
				
				// Find a matching item from the database
				QueryResult *resultMatchingItem = CharacterDatabase.Query("SELECT entry, stack FROM auction_house_statistics WHERE `min` <= %u AND `max` >= %u", randDatabaseValue, randDatabaseValue);
				if ( resultMatchingItem )
				{
					Field *fields = resultMatchingItem->Fetch();
					itemRandom = fields[0].GetUInt32();
					maxCountOfRandomItem = fields[1].GetUInt32();
					delete resultMatchingItem;
				}

				// Was memory successfully allocated for the tracking table?
				if ( ( trackItemCount != NULL )  && ( m_MaxItemCount > 0 ) && ( itemRandom >= 0 ) && ( itemRandom <= 500000 ) && ( maxCountOfRandomItem > 1 ) )
				{
					//This item has just been added so setup the counter that we will decrement every time a new one is added (c = (a>b) ? a : b;)
					if ( ( trackItemCount[itemRandom] == (uint32)m_MaxItemCount ) && ( maxCountOfRandomItem < (uint32)m_MaxItemCount ) )
							trackItemCount[itemRandom] = maxCountOfRandomItem;

				} // (( trackItemCount != NULL ) && ( itemRandom >= 0 ) && ( itemRandom <= 500000 ) && ( maxCountOfRandomItem > 1 ))

			} // ( m_CustomPrices == 1 )

			// Was memory successfully allocated for the tracking table and are we tacking the item count?
			if ( ( trackItemCount != NULL )  && ( m_MaxItemCount > 0 ) )
			{
				// Has this item already been added to the auction house during this session the maximum number of times?
				if ( trackItemCount[itemRandom] == 0 )
				{
					if ( m_LogLevel >= 2 )
						sLog.outString("AHBot Rejected item id '%u' because MaxItemCount was exceeded", itemRandom);
					continue;
				}
				else
					trackItemCount[itemRandom]--; //  decrement the tracking counter
			}

			if ( ( m_RandomizeExpiration == 1 ) && ( diffExpireTime > 0 ) )
			{
				randomExpire = RandomUInt(diffExpireTime); // find a random number
				auctionExpire = minExpireTime + randomExpire;
			}

			if ( add_item(tmpPlr, ah, itemRandom, auctionExpire) )
				itemCount++;
		}
	}

	// Release the table/array and the memory associated with it
	if ( trackItemCount != NULL )
		delete [] trackItemCount;

	//Remove the dummy player from the world
	tmpPlr->RemoveFromWorld();

	// If configured to make a world announce, then this is the time...
	if ( m_AnnounceLoading == 1 )
	{
		snprintf(msg, 200, "AHBot finished re-loading AH '%u' in %u ms", ah->GetID(), getMSTime() - currentTime);

		sWorld.SendWorldWideScreenText(msg); // send message to players

		if ( m_LogLevel >= 1 )
			sLog.outString(msg); // send message to console
	}

	return true;
}

void AHBotUpdaterThread::unload_auctionhouse(Player * plr, AuctionHouse * ah)
{
	char msg[200];

	if((m_LogLevel >= 2) && (m_PlayerGuid == 0))
	{
		sLog.outString("AHBotUpdaterThread::unload_auctionhouse() encountered m_PlayerGuid == 0");
		return;
	}

	if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), unload_auctionhouse('%u')", GetThreadId(), ah->GetID());

	uint32 currentTime = getMSTime();

	// If configured to make a world announce, then this is the time...
	if ( m_AnnounceLoading == 1 )
	{
		snprintf(msg, 200, "AHBot is attempting to unload AH '%u'", ah->GetID());

		sWorld.SendWorldWideScreenText(msg); // send message to players

		if( m_LogLevel >= 1 )
			sLog.outString(msg); // send message to console
	}

	// Having this in the AH class makes it easier to implement
	ah->UnloadAHBotAuctions();

	// Trigger the auction house deletion queue before the normal cycle
	ah->UpdateDeletionQueue();

	// If configured to make a world announce, then this is the time...
	if ( m_AnnounceLoading == 1 )
	{
		snprintf(msg, 200, "AHBot finished unloading AH '%u' in %u ms", ah->GetID(), getMSTime() - currentTime);

		sWorld.SendWorldWideScreenText(msg); // send message to players

		if( m_LogLevel >= 1 )
			sLog.outString(msg); // send message to console

		if(plr)
		{
			if(plr->IsInWorld())
				plr->GetSession()->SendNotification(msg);
		}
		else
			sLog.outString(msg);
	}

	return;
}

void AHBotUpdaterThread::clean_mailboxes()
{
	if ( ( m_PlayerGuid != 0 ) && ( m_CleanMailboxes == 1 ) )
	{
		// If any mail slips through to the AHBot character, then delete it
		CharacterDatabase.Execute("DELETE FROM mailbox WHERE player_guid = %u AND message_type = %u", m_PlayerGuid, AUCTION);

		if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
			Log.Debug("AHBotUpdaterThread", "Thread('%u'), clean_mailboxes(%u)", GetThreadId(), m_PlayerGuid);
	}

	// Update the last time the mailbox was updated since it executes on a recurring cycle
	last_mail_time = currenttime;

	return;
}

void AHBotUpdaterThread::clean_playeritems()
{
	if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), clean_playeritems()", GetThreadId());

	// Update the last time the playeritems was updated since it executes on a recurring cycle
	last_playeritems_time = currenttime;

	return;
}

void AHBotUpdaterThread::clear_auctionhouses()
{
	char msg[200];

	if((sLog.m_screenLogLevel >= 2) || (m_LogLevel >= 1))
		Log.Debug("AHBotUpdaterThread", "Thread('%u'), clear_auctionhouses()", GetThreadId());

	// If configured to make a world announce, then this is the time...
	if ( m_AnnounceLoading == 1 )
	{
		snprintf(msg, 200, "AHBot is attempting to clear all auction houses");

		sWorld.SendWorldWideScreenText(msg); // send message to players

		if( m_LogLevel >= 1 )
			sLog.outString(msg); // send message to console
	}

	CharacterDatabase.Execute("DELETE FROM auctions");
	CharacterDatabase.Execute("DELETE FROM playeritems WHERE ownerguid = 0");

	// Refresh the auction houses now that they are empty
	sAuctionMgr.LoadAuctionHouses();

	// If configured to make a world announce, then this is the time...
	if ( m_AnnounceLoading == 1 )
	{
		snprintf(msg, 200, "AHBot has cleared and reloaded all auction houses");

		sWorld.SendWorldWideScreenText(msg); // send message to players

		if( m_LogLevel >= 1 )
			sLog.outString(msg); // send message to console
	}
}
