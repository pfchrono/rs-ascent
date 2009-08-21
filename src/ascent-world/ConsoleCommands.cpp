/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2008 Ascent Team <http://www.ascentemu.com/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "StdAfx.h"
#include <svn_revision.h>
#include "ConsoleCommands.h"

bool HandleInfoCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	uint32 clientsNum = (uint32)sWorld.GetSessionCount();

	int gm = 0;
	int count = 0;
	int avg = 0;
	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession())
		{
			count++;
			avg += itr->second->GetSession()->GetLatency();
			if(itr->second->RS_getAccess() >= RS_PROBEGM)
				gm++;
		}			
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================================\r\n");
	pConsole->Write("Server Information: \r\n");
	pConsole->Write("======================================================================\r\n");
	pConsole->Write("Server Revision: Ascent r%u/%s-%s-%s (ascentemu.com)\r\n", BUILD_REVISION, CONFIG, PLATFORM_TEXT, ARCH);
	pConsole->Write("Server Uptime: %s\r\n", sWorld.GetUptimeString().c_str());
	pConsole->Write("Current Players: %d (%d GMs, %d queued)\r\n", clientsNum, gm,  0);
	pConsole->Write("Active Thread Count: %u\r\n", ThreadPool.GetActiveThreadCount());
	pConsole->Write("Free Thread Count: %u\r\n", ThreadPool.GetFreeThreadCount());
	pConsole->Write("Average Latency: %.3fms\r\n", count ?  ((float)((float)avg / (float)count)) : 0.0f);
	pConsole->Write("SQL Query Cache Size (World): %u queries delayed\r\n", WorldDatabase.GetQueueSize());
	pConsole->Write("SQL Query Cache Size (Character): %u queries delayed\r\n", CharacterDatabase.GetQueueSize());
	pConsole->Write("======================================================================\r\n\r\n");

	return true;
}

bool HandleAHBotCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	string outstr = "";

	if(argc > 0)
	{
		for(int i = 1; i < argc; ++i)
		{
			outstr += argv[i];
			if((i+1) != (argc))
				outstr += " ";
		}
	}

	sAHBotMgr.AHBotConsoleCommands(pConsole, argc, outstr);

	return true;
}

bool HandleGMsCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	WorldPacket data;
	//bool first = true;

	pConsole->Write("There are the following GM's online on this server: \r\n");
	pConsole->Write("======================================================\r\n");
	pConsole->Write("| %21s | %15s | % 03s  |\r\n" , "Name", "Permissions", "Latency");
	pConsole->Write("======================================================\r\n");

	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		//if(itr->second->GetSession()->GetPermissionCount())
		if(itr->second->RS_getAccess() >= RS_PROBEGM)
		{
			pConsole->Write("| %21s | %15s | %03u ms |\r\n" , itr->second->GetName(), itr->second->GetSession()->GetPermissions(), itr->second->GetSession()->GetLatency());
		}
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================\r\n\r\n");
	return true;
}

bool HandleOnlinePlayersCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	WorldPacket data;
	//bool first = true;
/*
	pConsole->Write("There following players online on this server: \r\n");
	pConsole->Write("======================================================\r\n");
	pConsole->Write("| %21s | %15s | % 03s  |\r\n" , "Name", "Level", "Latency");
	pConsole->Write("======================================================\r\n");

	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second && itr->second->GetSession() &&  itr->second->GetSession()->GetPlayer())
		{
			pConsole->Write("| %21s | %15s | %03u ms |\r\n" , itr->second->GetName(), itr->second->GetSession()->GetPlayer()->getLevel(), itr->second->GetSession()->GetLatency());
		}
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================\r\n\r\n");
	*/
	return true;
}

void ConcatArgs(string & outstr, int argc, int startoffset, const char * argv[])
{
	for(int i = startoffset + 1; i < argc; ++i)
	{
		outstr += argv[i];
		if((i+1) != (argc))
			outstr += " ";
	}
}
bool HandleAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	ConcatArgs(outstr, argc, 0, argv);
	snprintf(pAnnounce, 1024, "%sConsole: |r%s", MSG_COLOR_LIGHTBLUE, outstr.c_str());
	sWorld.SendWorldText(pAnnounce); // send message
	sGMLog.writefromconsole("used announce command [%s]", outstr.c_str());
	pConsole->Write("Message sent.\r\n");
	return true;
}

bool HandleWAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	ConcatArgs(outstr, argc, 0, argv);
	snprintf(pAnnounce, 1024, "%sConsole: |r%s", MSG_COLOR_LIGHTBLUE, outstr.c_str());
	sWorld.SendWorldWideScreenText(pAnnounce); // send message
	sGMLog.writefromconsole("used wannounce command [%s]", outstr.c_str());
	pConsole->Write("Message sent.\r\n");
	return true;
}
bool HandleWhisperCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	Player * pPlayer;
	string outstr;

	if(argc < 3)
		return false;

	pPlayer = objmgr.GetPlayer(argv[1]);

	if( pPlayer == NULL )
	{
		pConsole->Write("Could not find player, %s.\r\n", argv[1]);
		return true;
	}

	ConcatArgs(outstr, argc, 1, argv);

	if( sWorld.rsWhispInCon )
	{
		Log.Whisper("[WHISPER]", "<Console> to %s(%u): %s", pPlayer->GetName(), pPlayer->GetSession()->GetAccountId(), outstr.c_str());
	}
	sChatLog.writefromconsole("[WHISPER] To %s(%u): %s", pPlayer->GetName(), pPlayer->GetSession()->GetAccountId(), outstr.c_str());
			

	snprintf(pAnnounce, 1024, "%sConsole whisper: |r%s", MSG_COLOR_MAGENTA, outstr.c_str());

	pPlayer->BroadcastMessage(pAnnounce);
	pConsole->Write("Message sent to %s.\r\n", pPlayer->GetName());
	return true;
}

bool HandleSendToChanCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	string outstr;
	Channel * chan = channelmgr.GetChannel(argv[1], 1); 
	if(argc < 3)
		return false;

	if( chan == NULL )
	{
		pConsole->Write("Could not find channel, %s.\r\n", argv[1]);
		return true;
	}
	string channame = chan->m_name;
	ASCENT_TOLOWER(channame);

	ConcatArgs(outstr, argc, 1, argv);

	if( sWorld.rsChanInCon )
	{
		char tochan[1024];
		snprintf(tochan, 1024, "[CHANNEL][%s]", channame.c_str());
		Log.Channel(tochan, "<Console> : %s", outstr.c_str());
	}
	
	sChanLog.writefromconsole("[CHANNEL] %s : %s", channame.c_str(), outstr.c_str());

	snprintf(pAnnounce, 1024, "%s<Console>: |r%s", MSG_COLOR_MAGENTA, outstr.c_str());
	WorldPacket data(SMSG_CHANNEL_NOTIFY, strlen(pAnnounce)+100);
	data.SetOpcode(SMSG_MESSAGECHAT);
	data << uint8(CHAT_MSG_CHANNEL);
	data << uint32(0);
	data << uint64(0);		// guid - Don't display a name, so set guid to uint64 0... :x 
	data << uint32(0);	
	data << chan->m_name;
	data << uint64(0);
	data << uint32(strlen(pAnnounce)+1);
	data << pAnnounce;
	data << uint8(4);
	chan->SendToAll(&data);

	pConsole->Write("Message sent.\r\n");
	return true;
}

bool HandleKickCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 3)
		return false;

	char pAnnounce[1024];
	Player * pPlayer;
	string outstr;

	pPlayer = objmgr.GetPlayer(argv[1]);
	if( pPlayer == NULL || pPlayer->GetSession() == NULL || pPlayer->IsInWorld() == false )
	{
		pConsole->Write("Could not find player, %s.\r\n", argv[1]);
		return true;
	}
	ConcatArgs(outstr, argc, 1, argv);
	snprintf(pAnnounce, 1024, "%sConsole:|r %s was kicked from the server for: %s.", MSG_COLOR_LIGHTBLUE, pPlayer->GetName(), outstr.c_str());
	pPlayer->BroadcastMessage("You were kicked by the console for: %s", outstr.c_str());
	sWorld.SendWorldText(pAnnounce, NULL);
	sGMLog.writefromconsole("used kick command  on %s[%s] for %s", pPlayer->GetName(), pPlayer->GetSession()->GetAccountName(), outstr.c_str());
	pPlayer->Kick(5000);
	pConsole->Write("Kicked player %s.\r\n", pPlayer->GetName());
	return true;
}

bool HandleShutDownCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	uint32 delay = 5;
	if(argc >= 2)
		delay = atoi(argv[1]);

	sGMLog.writefromconsole("used shutdown command (delay %u seconds)", delay);
	sMaster.m_ShutdownTimer = delay * 1000;
	sMaster.m_ShutdownEvent = true;
	pConsole->Write("Shutdown initiated.\r\n");
	return true;
}

bool HandleCancelCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Shutdown canceled.\r\n");
	sGMLog.writefromconsole("cancelled shutdown");
	sMaster.m_ShutdownTimer = 5000;
	sMaster.m_ShutdownEvent = false;
	return true;
}

bool HandleUptimeCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	string up = sWorld.GetUptimeString();
	pConsole->Write("Server Uptime: %s\r\n", up.c_str());
	return true;
}

bool HandleBanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 3)
		return false;

	int32 timeperiod = GetTimePeriodFromString(argv[2]);
	if(timeperiod < 0)
		return false;

	uint32 banned = (timeperiod ? (uint32)UNIXTIME+timeperiod : 1);

	char emptystring = 0;
	char * pReason;
	if( argc == 4 )
		pReason = (char *)argv[3];
	else 
		pReason = &emptystring;

	/// apply instantly in db
	sLogonCommHandler.Account_SetBanned(argv[1], banned, pReason);

	pConsole->Write("Account '%s' has been banned %s%s. The change will be effective imediatly.\r\n", argv[1], 
		timeperiod ? "until " : "forever", timeperiod ? ConvertTimeStampToDataTime(timeperiod+(uint32)UNIXTIME).c_str() : "");
	
	return true;
}

bool HandleUnbanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
		return false;

	sLogonCommHandler.Account_SetBanned(argv[1], 0, "");

	pConsole->Write("Account '%s' has been unbanned.\r\n", argv[1]);
	return true;
}

bool HandleCreateAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 5)
		return false;

	const char * username = argv[1];
	const char * password = argv[2];
	const char * email = argv[3];
	//uint32 flags = atoi(argv[4]);

	if(strlen(username) == 0 || strlen(password) == 0 || strlen(email) == 0)
		return false;

	/*string susername = CharacterDatabase.EscapeString(string(username));
	string spassword = CharacterDatabase.EscapeString(string(password));
	string semail = CharacterDatabase.EscapeString(string(email));

	sLogonCommHandler.LogonDatabaseSQLExecute("INSERT INTO accounts (login, password, email, flags) VALUES('%s','%s','%s',%u)",susername.c_str(), spassword.c_str(),
		semail.c_str(), flags); */

	pConsole->Write("Console account creation disabled.\r\n");
	return true;
}

bool HandleMOTDCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
	{
		pConsole->Write( "The current motd is: '%s'.\r\n", sWorld.GetMotd() );
	}
	else
	{
		char set_motd[1024];
		string outstr;
		ConcatArgs( outstr, argc, 0, argv );
		snprintf( set_motd, 1024, "%s", outstr.c_str() );

		sGMLog.writefromconsole("Set motd to %s", outstr.c_str());
		sWorld.SetMotd( set_motd );
		pConsole->Write( "The motd has been set to: '%s'.\r\n", sWorld.GetMotd() );
	}
	return true;
}

bool HandlePlayerInfoCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
		return false;

	Player * plr = objmgr.GetPlayer(argv[1]);
	if( plr == NULL )
	{
		pConsole->Write("Player not found.\r\n");
		return true;
	}
	pConsole->Write("======================================================\r\n");
	pConsole->Write("Player: %s\r\n", plr->GetName());
	pConsole->Write("Permissions: %s\r\n", plr->GetSession()->GetPermissions());
	pConsole->Write("Race: %s\r\n", plr->myRace->name1);
	pConsole->Write("Class: %s\r\n", plr->myClass->name);
	pConsole->Write("IP: %s\r\n", plr->GetSession()->GetSocket() ? plr->GetSession()->GetSocket()->GetRemoteIP().c_str() : "disconnected");
	pConsole->Write("Level: %u\r\n", plr->getLevel());
	pConsole->Write("Account: %s\r\n", plr->GetSession()->GetAccountNameS());
	pConsole->Write("======================================================\r\n");
	return true;
}

void TestConsoleLogin(string& username, string& password, uint32 requestno)
{
	if(strlen(username.c_str()) < 3 || strlen(password.c_str()) < 3)
		return;

	sLogonCommHandler.TestConsoleLogon(username, password, requestno);
}

bool HandleRehashCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Config file re-parsed.");
	sWorld.Rehash(true);
	return true;
}

bool HandleSaveallPlayers(BaseConsole * pConsole, int argc, const char * argv[])
{
	PlayerStorageMap::const_iterator itr;
	uint32 stime = now();
	uint32 count = 0;
	objmgr._playerslock.AcquireReadLock();
	for( itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++ )
	{
		if( itr->second->GetSession() )
		{
			itr->second->SaveToDB( false );
			count++;
		}
	}
	objmgr._playerslock.ReleaseReadLock();
	char msg[100];
	snprintf( msg, 100, "Saved all %d online players in %d msec.", (unsigned int)count, (unsigned int)((uint32)now() - stime) );
	sWorld.SendWorldText( msg );
	sWorld.SendWorldWideScreenText( msg );
	return true;
}

bool HandleSAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	ConcatArgs(outstr, argc, 0, argv);
	sGMLog.writefromconsole("used sannounce command [%s]", outstr.c_str());
	snprintf(pAnnounce, 1024, "%s[SERVER] |r%s", MSG_COLOR_LIGHTBLUE, outstr.c_str());
	sWorld.SendWorldText(pAnnounce); // send message
	sWorld.SendWorldWideScreenText(pAnnounce);
	pConsole->Write("Message sent to world.\r\n");
	return true;
}

bool HandleNameHashCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if( !argc )
		return false;
	string spname;
	ConcatArgs(spname, argc, 0, argv);
	pConsole->Write( "Name Hash for %s is 0x%X" , spname.c_str() , crc32((const unsigned char*)spname.c_str(), (unsigned int)spname.length()) );
	sWorld.Rehash(true);
	return true;
}

bool HandleReloadAccounts(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write( "Server will now attempt to reload accounts....\r\n" );
	sGMLog.writefromconsole("reloaded accounts");
	sLogonCommHandler.ReloadAccounts();
	return true;
};

bool HandleConsoleWBuffCommand(BaseConsole * pConsole, int argc, const char* argv[])
{
	static uint32 BUFFSPELLS[9] = { 25802, 25800, 25796, 25795, 25794, 25799, 25798, 25797, 15167, };
	for(int i = 0; i != 9; i++)
	{
		Player * plr;
		SpellEntry * info = dbcSpell.LookupEntry(BUFFSPELLS[i]);
		PlayerStorageMap::const_iterator itr;
		objmgr._playerslock.AcquireReadLock();
		for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
		{
			plr = itr->second;
			if(plr->GetSession() && plr->IsInWorld())
			{
				sEventMgr.AddEvent( static_cast< Unit* >( plr ), &Unit::EventCastSpell, static_cast< Unit* >( plr ), info, EVENT_PLAYER_CHECKFORCHEATS, 100, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );
			}
		}
		objmgr._playerslock.ReleaseReadLock();
	}
	char worldtext[1024];
	string input2;
	input2 = MSG_COLOR_GREEN;
	input2 += "[Staff] |r";
	input2 += "[< Console >]";
	input2 += "gave ";
	input2 += "his/her ";
	input2 += "blessing to the world.";
	snprintf((char*)worldtext, 1024, "%s|r", input2.c_str());
	sWorld.SendWorldText(worldtext); // send message
	sGMLog.writefromconsole("used the WorldBuff command");
	return true;
}

bool HandleReloadTableCommand(BaseConsole * pConsole, int argc, const char* argv[])
{
	char str[200];
	if(!(argv[1]) || argc < 3 || strlen(argv[1]) < 3 )
		return false;

	uint32 mstime = getMSTime();
	snprintf(str, 200, "%sServer-side reload of table `%s` initiated. The server may experience some lag while this occurs.",
		MSG_COLOR_LIGHTRED, argv[1]);
	sWorld.SendWorldText(str, 0);

	if( !Storage_ReloadTable(argv[1]) )
		snprintf(str, 256, "%sTable not found!", MSG_COLOR_LIGHTRED);
	else
		snprintf(str, 256, "%sTable reload completed in %u ms.", MSG_COLOR_LIGHTBLUE, (unsigned int)(getMSTime() - mstime));

	sWorld.SendWorldText(str, 0);
	sGMLog.writefromconsole("Console reloaded table %s", argv[1]);
	return true;
}