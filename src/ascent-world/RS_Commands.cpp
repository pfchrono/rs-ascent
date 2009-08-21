/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2008 Ascent Team <http://www.ascentemu.com/>
 *
 * Custom Commands for the RockStar WoW Funserver.
 * http://www.fishstik.ca Please do not use these scripts for any other server
 * than the RockStar Funserver(http://fishstik.ca) as they were specially
 * scripted/modded for the server in question.
 * - Midnight, Egari, T0asT, other RS GMs
 *
 */
#include "StdAfx.h"

#pragma warning( disable : 4800 )

//
// Create a Guild Home for a guild.
//
bool ChatHandler::HandleGuildHomeCommand(const char* args, WorldSession *m_session)
{
	Player * plr;
	if(args && strlen(args) >= 2) // char name can be 2 letters
	{
		plr = objmgr.GetPlayer(args, false);
		if(!plr)
		{
			RedSystemMessage(m_session, "Unable to locate player %s.", args);		
			return true;
		}
	}else if(m_session->GetPlayer()->GetSelection()){
		plr = getSelectedChar(m_session);
	}else{
		RedSystemMessage(m_session, "Specified player not found and no player selected.");
		return true;
	}
	if(!plr || !plr->GetGuildId()) return false;
	uint32 PlrGuildID = plr->GetGuildId();
	uint32 locmap = m_session->GetPlayer()->GetMapId();
	float x = m_session->GetPlayer()->GetPositionX();
	float y = m_session->GetPlayer()->GetPositionY();
	float z = m_session->GetPlayer()->GetPositionZ();
	float o = m_session->GetPlayer()->GetOrientation();
	char message[256];
	std::stringstream query;
	query << "SELECT * FROM guildlocations WHERE `GuildID` = '" << PlrGuildID << "'";
	QueryResult * result = WorldDatabase.Query(query.str().c_str());
	if(result)
	{
		std::stringstream update;
		update << "UPDATE guildlocations SET `locmap` = '" << locmap << "',`x` = '" << x << "', `y` = '" << y << "', `z` = '" << z << "', `o` = '" << o << "' WHERE `GuildID` = '" << PlrGuildID << "'";
		WorldDatabase.Execute(update.str().c_str());
		sprintf(message, "Guild Home updated for Guild %s(%u)", plr->GetGuild()->GetGuildName(), PlrGuildID);
	}else{
		std::stringstream insert;
		insert << "INSERT INTO guildlocations VALUES ('" << PlrGuildID << "', '" << locmap << "', '" << x << "', '" << y << "', '" << z << "', '" << o << "')";
		WorldDatabase.Execute(insert.str().c_str());
		sprintf(message, "New Guild Home created for Guild %s(%u)", plr->GetGuild()->GetGuildName(), PlrGuildID);
	}
	sChatHandler.SystemMessage(m_session, message);
	Log.Notice("GuildLoc", message);
	return true;
}

bool ChatHandler::HandleGoToGuildHomeCommand(const char* args, WorldSession *m_session)
{
	Player * plr;
	if(args && strlen(args) >= 2) // char name can be 2 letters
	{
		plr = objmgr.GetPlayer(args, false);
		if(!plr)
		{
			RedSystemMessage(m_session, "Unable to locate player %s.", args);		
			return true;
		}
	}else if(m_session->GetPlayer()->GetSelection()){
		plr = getSelectedChar(m_session);
	}else{
		plr = m_session->GetPlayer();
	}
	if(!plr || !plr->GetGuildId()) return false;
	uint32 PlrGuildID = plr->GetGuildId();
	std::stringstream selQuery;
	selQuery << "SELECT * FROM guildlocations WHERE `GuildID` = '" << PlrGuildID << "'";
	QueryResult * qResult = WorldDatabase.Query(selQuery.str().c_str());
	if(qResult)
	{
		do
		{
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			Field			*fields = qResult->Fetch();
			uint32			locmap = fields[1].GetUInt32();
			float			x = fields[2].GetFloat();
			float			y = fields[3].GetFloat();
			float			z = fields[4].GetFloat();
			float			o = fields[5].GetFloat();
			LocationVector	LocVEC(x, y, z, o);
			/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
			m_session->GetPlayer()->SafeTeleport(locmap, 0, LocVEC);
			Log.Notice(	"GuildLoc",
						"Teleporting player %s(%u) to Home of Guild %s(%u)",
						m_session->GetPlayer(),
						m_session->GetPlayer()->GetLowGUID(),
						plr->GetGuild()->GetGuildName(),
						plr->GetGuildId()
						);
		}while(qResult->NextRow());
		delete qResult;
	}else{
		SystemMessage(m_session, "No guildhome found for that player's guild");
	}
	return true;
}

//
// Warn Player Commands
//
bool ChatHandler::HandleGenerateBugReport(const char *args, WorldSession * m_session)
{
	if( !sWorld.rsBugReportSys )
	{
		SystemMessage(m_session, "Command Disabled.");
		return false;
	}

	if(!*args) return false;

	m_session->CreateBugReport(args);

	return true;
}


bool ChatHandler::HandleWarnPlayerCommand(const char *args, WorldSession * m_session)
{
	if( !sWarnSystem.IsEnabled() )
	{
		SystemMessage(m_session, "Command Disabled.");
		return false;
	}

	if(!*args) return false;
	char *pname = strtok((char*)args, " ");
	if(!pname)
	{
		RedSystemMessage(m_session, "No name specified.");
		return false;
	}
	Player *warned = objmgr.GetPlayer((const char*)pname, false);
	if (warned)
	{
		char* pReason = strtok(NULL, " ");
		if( !pReason || strlen(pReason) < 3 )
		{
			RedSystemMessage(m_session, "You need to specify a valid reason!");
			return false;
		}
		else
		{
			sWarnSystem.AddWarn(m_session->GetPlayer(), warned, pReason);
			return true;
		}
	}
	else
	{
		return false; 
	}
}

bool ChatHandler::HandleWarnListCommand(const char *args, WorldSession * m_session)
{
	if( !sWarnSystem.IsEnabled() )
	{
		SystemMessage(m_session, "Command Disabled.");
		return false;
	}
	Player * Target = getSelectedChar(m_session, false);
	Player * SessionPlr = m_session->GetPlayer();
	if(SessionPlr->RS_getAccess() < RS_GAMEMASTER)
		Target = SessionPlr;

	sWarnSystem.ListWarns(SessionPlr, Target);
	return true;
}

bool ChatHandler::HandleWarnClearCommand(const char *args, WorldSession * m_session)
{
	if( !sWarnSystem.IsEnabled() )
	{
		SystemMessage(m_session, "Command Disabled.");
		return false;
	}
	if(!*args) return false;
	char *pname = strtok((char*)args, " ");
	if( !pname )
	{
		RedSystemMessage(m_session, "No name specified.");
		return false;
	}
	Player *chr = objmgr.GetPlayer((const char*)pname, false);
	sWarnSystem.ClearWarns(m_session->GetPlayer(), chr);
	return true;
}

bool ChatHandler::HandleWarnSingleDelCommand(const char *args, WorldSession * m_session)
{
	if( !sWarnSystem.IsEnabled() )
	{
		SystemMessage(m_session, "Command Disabled.");
		return false;
	}

	char * pCharacter = strtok((char*)args, " ");
	char * pWarnID =  strtok(NULL, "\n");
	Player * pPlayer = objmgr.GetPlayer(pCharacter, false);
	if(!pCharacter || !pWarnID || !pPlayer)
	{
		SystemMessage(m_session, "This function requires 2 arguments.");
		return false;
	}
	uint32 WarnID = atol(pWarnID);
	sWarnSystem.DelWarn(m_session->GetPlayer(), pPlayer, WarnID);
	return true;
}


//
// Report Player Commands
//
bool ChatHandler::HandleReportPlr(const char *args, WorldSession * m_session)
{
	if( !sWorld.rsReportPlr )
	{
		BlueSystemMessage(m_session, "Not enabled");
		return true;
	}
	if(!*args) return false;
	std::string pReason = "No reason";
	char *pname = strtok((char*)args, " ");
	if(!pname)
	{
		RedSystemMessage(m_session, "No name specified.");
		return true;
	}
	Player *chr = objmgr.GetPlayer((const char*)pname, false);
	if (chr)
	{	
		char *reason = strtok(NULL, "\n");
		if(reason)
		{
			pReason = reason;
		}else{
			RedSystemMessage(m_session, "You need to specify a reason!");
			return true;
		}
	}
	else
	{
		return true;
	}
	
	// Get Report ID
	QueryResult *countResult = CharacterDatabase.Query("SELECT MAX(ReportID) FROM plr_reports");
	uint32 reportID = 1;
	if(countResult != NULL)
	{
		reportID = countResult->Fetch()[0].GetUInt32() + 1;
		delete countResult;
	}

	// Get Report Details
	std::string ReporterChar = m_session->GetPlayer()->GetName();
	std::string ReporterAcct = m_session->GetAccountName();
	std::string ReporterIP = m_session->GetSocket()->GetRemoteIP();
	std::string ReportedChar = chr->GetName();
	std::string ReportedAcct = chr->GetSession()->GetAccountName();
	std::string ReportedIP = chr->GetSession()->GetSocket()->GetRemoteIP();
	
	// Build and Execute Report Query
	std::stringstream SQL;
	SQL << "INSERT INTO plr_reports VALUES ('" << reportID << "', '" << ReporterChar.c_str() << "', '" << ReporterAcct.c_str() << "', '" << ReporterIP.c_str() << "', '" << ReportedChar.c_str() << "', '" << ReportedAcct.c_str() << "', '" << ReportedIP.c_str() << "', '" << WorldDatabase.EscapeString(pReason.c_str()) << "')";
	WorldDatabase.Execute( SQL.str().c_str() );
	
	// Notify all online GMs that a report has been made and if none online refer player to the forums.
	int gm = 0;
	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession())
		{
			if(itr->second->GetSession()->CanUseCommand('a'))
			{
			SystemMessage(itr->second->GetSession(), "Player %s(%s[%s]) is trying to report player %s(%s[%s])", 
				ReporterChar.c_str(), 
				ReporterAcct.c_str(), 
				ReporterIP.c_str(),
				ReportedChar.c_str(), 
				ReportedAcct.c_str(), 
				ReportedIP.c_str() );
			SystemMessage(itr->second->GetSession(), "Reason: %s!", 
				pReason.c_str() );
				gm++;
			}
		}			
	}
	objmgr._playerslock.ReleaseReadLock();
	SystemMessage(m_session, "Player %s reported.", ReportedChar.c_str());
	if(gm < 1){
		SystemMessage(m_session, "There are no GMs online! Report on the forums!");
	}
	// Add notification in console for logging purposes.
	Log.Notice("PlrNotify", "=====================================\r\n");
	Log.Notice("PlrNotfiy", "Player %s(%s[%s]) is trying to report",
				ReporterChar.c_str(), 
				ReporterAcct.c_str(), 
				ReporterIP.c_str());
	Log.Notice("PlrNotify", "player %s(%s[%s])", 				
				ReportedChar.c_str(),
				ReportedAcct.c_str(), 
				ReportedIP.c_str() );
	Log.Notice("PlrNotify", "for: %s!", pReason.c_str());

	
	return true;
}

bool ChatHandler::HandlePlrReportsGetCommand(const char* args, WorldSession *m_session)
{
	if( !sWorld.rsReportPlr )
	{
		BlueSystemMessage(m_session, "Not enabled");
		return true;
	}
	uint32 getCase = 1;
	if(!*args) getCase = 2;
	switch(getCase)
	{
	case 1: 
		{
			uint32 RepID = args ? atol(args) : 0;
			if(RepID == 0)
				return false;

			std::stringstream SQL;
			SQL << "SELECT * FROM plr_reports WHERE ReportID = '" << RepID << "'";
			QueryResult *result = WorldDatabase.Query( SQL.str().c_str() );
			if( result )
			{
				do
				{
					/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
					Field		*fields			= result->Fetch();
					uint32		ReportID		= fields[0].GetUInt32();
					string		ReporterChar	= fields[1].GetString();
					string		ReporterAcct	= fields[2].GetString();
					string		ReporterIP		= fields[3].GetString();
					string		ReportedChar	= fields[4].GetString();
					string		ReportedAcct	= fields[5].GetString();
					string		ReportedIP		= fields[6].GetString();
					string		Reason			= fields[7].GetString();
					/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
					GreenSystemMessage(m_session, "-------- Report %u ---------", ReportID ); // Display Reports.
					GreenSystemMessage(m_session, "ReportedAcct: %s", ReportedAcct.c_str() );
					GreenSystemMessage(m_session, "ReportedIP: %s", ReportedIP.c_str() );
					GreenSystemMessage(m_session, "ReporterAcct: %s", ReporterAcct.c_str() );
					GreenSystemMessage(m_session, "ReporterIP: %s", ReporterIP.c_str() );
					GreenSystemMessage(m_session, "Reason: %s", Reason.c_str() );
				}while (result->NextRow());
				delete result;
			}
			else
			{
				GreenSystemMessage(m_session, "There is no report with that ID!");
			}
		}break;
	case 2:
		{
			std::stringstream SQL;
			SQL << "SELECT * FROM plr_reports";
			QueryResult *result = WorldDatabase.Query( SQL.str().c_str() );
			if( result )
			{
				do
				{
					/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
					Field			*fields			= result->Fetch();
					uint32			ReportID		= fields[0].GetUInt32();
					string			ReporterChar	= fields[1].GetString();
					string			ReportedChar	= fields[4].GetString();
					/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
					GreenSystemMessage(m_session, "--------Report %u---------", ReportID ); // Display Reports.
					GreenSystemMessage(m_session, "ReporterChar: %s", ReporterChar.c_str() );
					GreenSystemMessage(m_session, "ReportedChar: %s", ReportedChar.c_str() );
				}while (result->NextRow());
				delete result;
			}
			else
			{
				GreenSystemMessage(m_session, "There are no reports to display!");
			}
		}break;

	}
	return true;
}
bool ChatHandler::HandlePlrReportsDeleteCommand(const char* args, WorldSession *m_session)
{
	if( !sWorld.rsReportPlr )
	{
		BlueSystemMessage(m_session, "Not enabled");
		return true;
	}
	if(!*args) return false;
	uint32 RepID = args ? atol(args) : 0;

	if(RepID == 0)
		return false;

	stringstream SQLcount;
	SQLcount << "SELECT ReportedChar FROM plr_reports WHERE ( ReportID = '" << RepID << "')";
	QueryResult *countResult = WorldDatabase.Query( SQLcount.str().c_str() );
	if( countResult )
	{
		do{
			string ReportedChar = countResult->Fetch()[0].GetString();
			sGMLog.writefromsession(m_session, "GM %s deleted Report %u of player %s", m_session->GetAccountName(), RepID, ReportedChar.c_str());
		}while( countResult->NextRow() );
		delete countResult;
		std::stringstream SQL_Q;
		SQL_Q << "DELETE FROM plr_reports WHERE ( ReportID = '" << RepID << "')";
		WorldDatabase.Execute( SQL_Q.str().c_str() );
	}
	else
	{
		SystemMessage(m_session, "There is no report by that ID");
	}
	return true;
}

bool ChatHandler::HandleMorphAllInRange(const char* args, WorldSession *m_session)
{
	Player * GM = m_session->GetPlayer();
	uint32 ModelID = args ? atol(args) : 0;
	for(set<Player*>::iterator itr = GM->GetInRangePlayerSetBegin(); itr != GM->GetInRangePlayerSetEnd(); ++itr)
	{
		if((*itr)->IsPlayer())
		{
			Player * pPlayer = (*itr);
			pPlayer->SetUInt32Value(UNIT_FIELD_DISPLAYID, ModelID);
			pPlayer->SendAreaTriggerMessage("Yay! Costume party!! =D");
		}
	}
	GM->SendAreaTriggerMessage("Yay! Costume party!! =D");
	GM->SetUInt32Value(UNIT_FIELD_DISPLAYID, ModelID);

	SystemMessage(m_session, "Changed displayid of all players in range to: %u", ModelID);
	return true;
}

bool ChatHandler::HandleDeMorphAllInRange(const char* args, WorldSession *m_session)
{
	Player * GM = m_session->GetPlayer();
	for(set<Player*>::iterator itr = GM->GetInRangePlayerSetBegin(); itr != GM->GetInRangePlayerSetEnd(); ++itr)
	{
		if((*itr)->IsPlayer())
		{
			Player * pPlayer = (*itr);
			pPlayer->DeMorph();
			pPlayer->SendAreaTriggerMessage("Costume party is over :P");
		}
	}
	GM->DeMorph();
	GM->SendAreaTriggerMessage("Costume party is over :P");

	SystemMessage(m_session, "All players in range have been demorphed.");
	return true;
}

bool ChatHandler::HandleKnockUp(const char* args, WorldSession *m_session)
{
	Player * GM = m_session->GetPlayer();
	float force = 35.0f;
	SpellEntry * SlowFall = dbcSpell.LookupEntryForced( 12438 );
	for(set<Player*>::iterator itr = GM->GetInRangePlayerSetBegin(); itr != GM->GetInRangePlayerSetEnd(); ++itr)
	{
		if((*itr)->IsPlayer() && (*itr)->isAlive() && (*itr)->GetSession())
		{
			Player * pPlayer = (*itr);
			pPlayer->KnockUp(force);
			pPlayer->CastSpell(pPlayer, SlowFall, true);
			pPlayer->SendAreaTriggerMessage("Up you go!!!!");
		}
	}
	GM->KnockUp(force);
	GM->CastSpell(GM, SlowFall, true);
	GM->SendAreaTriggerMessage("Up you go!!!!");
	return true;
}

bool ChatHandler::HandleNPCStandStateCommand(const char* args, WorldSession *m_session)
{
	uint8 standstate = (char*)args?atoi((char*)args):0;
	Creature* target = getSelectedCreature(m_session);
	
	if(!target || target->IsPlayer() || !target->isAlive()) 
		return false;

	target->SetStandState(standstate);
	uint32 sqlid = target->GetSQL_id();
	char QueryString[1024];
	sprintf(QueryString, "UPDATE creature_spawns SET standstate = '%u' WHERE id = '%u'", standstate, sqlid);
	WorldDatabase.Execute( QueryString );
	BlueSystemMessage(m_session, "StandState changed to %u", standstate);
	return true;
}

bool ChatHandler::HandleRangeBuffCommand(const char* args, WorldSession *m_session)
{
	uint32 SpellID = args ? atoi((char*)args) : 0;
	if(SpellID == 0)
		return false;
	Player * GM = m_session->GetPlayer();
	SpellEntry * SPELL = dbcSpell.LookupEntryForced( SpellID );
	if(!SPELL)
	{
		SystemMessage(m_session, "You need to use a valid spell!");
		return false;
	}
	for(set<Player*>::iterator itr = GM->GetInRangePlayerSetBegin(); itr != GM->GetInRangePlayerSetEnd(); ++itr)
	{
		if((*itr)->IsPlayer() && (*itr)->isAlive() && (*itr)->GetSession())
		{
			(*itr)->CastSpell((*itr), SPELL, true);
		}
	}
	GM->CastSpell(GM, SPELL, true);
	return true;
}

bool ChatHandler::HandleWaterWalkCommand(const char* args, WorldSession *m_session)
{
	Player * Plr = m_session->GetPlayer();
	bool flag;

	if(Plr->HasAura(10665))
		flag = false;
	else
		flag = true;

	Plr->SetWaterWalk(flag);

	if(flag)
		RedSystemMessage(m_session, "WaterWalk enabled.");
	else
		RedSystemMessage(m_session, "WaterWalk disabled.");

	return true;
}

bool ChatHandler::HandleResetAllTalents(const char* args, WorldSession *m_session)
{
	uint32 PASS = args?atoi((char*)args):0;
	if(PASS != 1705)
	{
		sGMLog.writefromsession(m_session, "tried to reset EVERYONE's talents but entered wrong password.");
		return false;
	}
	PlayerStorageMap::const_iterator itr;
	Player * pPlr = NULL;
	uint32 t = 0;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second)
		{
			pPlr = itr->second;
			if(pPlr->getLevel() > 70)
			{
				pPlr->Reset_Talents();
				t++;
			}
		}
	}
	objmgr._playerslock.ReleaseReadLock();
	RedSystemMessage(m_session, "Reset talents %u", t);
	SystemMessage(m_session, "Reset talents of %u players!", t);
	sGMLog.writefromsession(m_session, "entered the right pass and reset talents of ALL players.");
	return true;
}

bool ChatHandler::HandleExtendedCharInfoCommand(const char* args, WorldSession *m_session)
{
	Player * plr;
	if(strlen(args) >= 2) // char name can be 2 letters
	{
		plr = objmgr.GetPlayer(args, false);
		if(!plr)
		{
			RedSystemMessage(m_session, "Can't find player %s.", args);		
			return true;
		}
	}
	else
	{
		plr = getSelectedChar(m_session, true);
	}
	if( !plr || !m_session->GetPlayer() )
		plr = m_session->GetPlayer();

	WorldSession *p_session = plr->GetSession();
	uint32 money			= plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
	uint32 TalentPoints		= plr->GetUInt32Value(PLAYER_CHARACTER_POINTS1);
	uint32 ProfPoints		= plr->GetUInt32Value(PLAYER_CHARACTER_POINTS2);
	uint32 Level			= plr->getLevel();
	uint32 CharGUID			= plr->GetLowGUID();
	std::string account		= plr->GetSession()->GetAccountName();
	GreenSystemMessage(m_session, "Player: %s(%u)[%s]", plr->GetName(), plr->GetLowGUID(), account.c_str());
	GreenSystemMessage(m_session, "Info: Level %u %s %s", Level, plr->getRaceC(), plr->getClassC());
	GreenSystemMessage(m_session, "Money: %u copper", money);
	GreenSystemMessage(m_session, "TalentPoints: %u | ProfPoints: %u", TalentPoints, ProfPoints);
	if( plr->HasWarns() )
	{
		RedSystemMessage(m_session, "%s has been warned %u times!", plr->GetName(), plr->HasWarns());
	}
	if( plr->HasReports() )
	{
		RedSystemMessage(m_session, "%s has been reported %u times!", plr->GetName(), plr->HasReports());
	}
	float Speed = plr->GetPlayerSpeed();
	GreenSystemMessage(m_session, "Player: %s", plr->GetName());
	GreenSystemMessage(m_session, "RunSpeed: %f", Speed);
	return true;
}

bool ChatHandler::HandleUptimeCommand(const char* args, WorldSession *m_session)
{
	SystemMessage(m_session, "Server has been up for %s", sWorld.GetUptimeString().c_str());
	return true;
}

bool ChatHandler::HandleIsOnlineCommand(const char* args, WorldSession *m_session)
{
	if(!*args) return false;
	char *pname = strtok((char*)args, " ");
	if(!pname)
	{
		RedSystemMessage(m_session, "No name specified.");
		return true;
	}
	PlayerInfo *chrI = objmgr.GetPlayerInfoByName(pname);
	if( !chrI )
	{
		RedSystemMessage(m_session, "Couldn't find a character by that name.");
		return true;
	}

	uint32 CharAcct = chrI->acct;
	std::stringstream PLR_q;
	PLR_q << "SELECT guid FROM characters WHERE ( acct = '" << CharAcct << "' )";
	QueryResult *qResult = CharacterDatabase.Query( PLR_q.str().c_str() );
	bool first = true;
	if(qResult)
	{
		do{
			uint32 GUID = qResult->Fetch()[0].GetUInt32();
			Player * plr = objmgr.GetPlayer(GUID);
			if( plr && plr->GetSession() && plr->IsInWorld() && plr->m_isGmInvisible == INVIS_NONE )
			{
				if( first ) 
				{
					GreenSystemMessage(m_session, "Characters online:");
					first = false;
				}
				SystemMessage(m_session, "%s", plr->GetName());
			}
		}while( qResult->NextRow() );
		delete qResult;
	}
	
	if( first )
	{
		SystemMessage(m_session, "There are no other characters of this user currently logged in.");
	}
	return true;
}

bool ChatHandler::HandleGetAccountCommand(const char* args, WorldSession *m_session)
{
	if(!*args) return false;
	char *pname = strtok((char*)args, " ");
	if(!pname)
	{
		RedSystemMessage(m_session, "No name specified.");
		return true;
	}
	PlayerInfo *chrI = objmgr.GetPlayerInfoByName(pname);
	if( !chrI )
	{
		RedSystemMessage(m_session, "Couldn't find a character by that name.");
		return true;
	}
	string blank = "NONE";
	uint32 CharAcct = chrI->acct;
	std::stringstream PLR_q, WARN_q;
	PLR_q << "SELECT acct, login, banned, lastip, email, flags, gm FROM accounts WHERE ( acct = '" << CharAcct << "' )";
	QueryResult *qResult = CharacterDatabase.Query( PLR_q.str().c_str() );
	GreenSystemMessage(m_session, "--------------------------");
	if(qResult)
	{
		uint32 acctId	=	qResult->Fetch()[0].GetUInt32();
		string login	=	qResult->Fetch()[1].GetString();
		uint32 banned	=	qResult->Fetch()[2].GetUInt32();
		string lastip	=	qResult->Fetch()[3].GetString();
		string email	=	qResult->Fetch()[4].GetString();
		uint8 flags		=	qResult->Fetch()[5].GetUInt32();
		string gm		=	qResult->Fetch()[6].GetString();

		string _lastip	=	(strlen(lastip.c_str()) > 3)?lastip:blank;
		string _email	=	(strlen(email.c_str()) > 3)?email:blank;

		GreenSystemMessage(m_session, "AccountID: %u", acctId);
		GreenSystemMessage(m_session, "LoginName: %s", login.c_str());
		GreenSystemMessage(m_session, "Banned: %u", banned);
		GreenSystemMessage(m_session, "Last IP: %s", _lastip.c_str());
		GreenSystemMessage(m_session, "Email: %s", _email.c_str());
		GreenSystemMessage(m_session, "TBC: %u", (flags?1:0));
		GreenSystemMessage(m_session, "GM: %s", gm.c_str());
		uint32 warncount = 0;
		WARN_q << "SELECT COUNT(*) as wCount FROM warnsystem WHERE WarnedAcct = '" << login.c_str() << "'";
		QueryResult *wResult = CharacterDatabase.Query( WARN_q.str().c_str() );
		if( wResult )
		{
			warncount = wResult->Fetch()[0].GetUInt32();
			delete wResult;
		}
		GreenSystemMessage(m_session, "Warns: %u", warncount);
		GreenSystemMessage(m_session, "--------------------------");
		delete qResult;
	}
	return true;
}

bool ChatHandler::HandleChatTagCommand(const char* args, WorldSession *m_session)
{
	if( !sWorld.rsChatTag )
	{
		BlueSystemMessage(m_session, "Not enabled!");
		return true;
	}	

	if(m_session->GetPlayer()->bCTagOn)
	{
		m_session->GetPlayer()->bCTagOn = false;
		BlueSystemMessage(m_session, "Chat Tag Off. It will no longer appear in chat channels.");
	}
	else
	{
		m_session->GetPlayer()->bCTagOn = true;
		BlueSystemMessage(m_session, "Chat Tag Set. It will now appear in chat channels");
	}
	return true;
}

bool ChatHandler::HandleReloadAccounts(const char* args, WorldSession *m_session)
{
	sLogonCommHandler.ReloadAccounts();
	SystemMessage(m_session, "Server will now attempt to reload accounts.");
	sGMLog.writefromsession(m_session, "reloaded accounts.");
	return true;
}

bool ChatHandler::HandleAddAuraCommand(const char* args, WorldSession *m_session)
{
	Unit *unt = getSelectedCreature(m_session, false);
	if(!unt)
		unt = getSelectedChar(m_session, false);

	char* pSpellID = strtok((char*)args, " ");
	if (!pSpellID) return false;
	uint32 SpellID  = atoi(pSpellID);

	int32 Duration = 600000;
	char * pDur = strtok(NULL, " ");
	if(pDur)
		Duration = ( atoi(pDur) * 1000 );

	if(!unt)
	{
		RedSystemMessage(m_session, "You need to select a valid creature or player.");
		return true;
	}
	Aura* aur = unt->FindAura( SpellID );
	if(!aur) // If no aura found, add it... Burn baby burn!
	{
		SpellEntry *spellInfo = dbcSpell.LookupEntry( SpellID );
		if(!spellInfo) return false;
		SpellCastTargets targets;
		targets.m_unitTarget = unt->GetGUID();
		Spell* sp = SpellPool.PooledNew(); 
		sp->Init( unt, spellInfo, true, NULL );
		if(!sp) return false;
		sp->prepare( &targets );
		aur = unt->FindAura( SpellID ); // Get aura
	}
	if(aur && Duration > 0)
		aur->SetDuration(Duration);

	return true;
}

bool ChatHandler::HandleRemoveAuraCommand(const char* args, WorldSession *m_session)
{
	Unit *unt = getSelectedCreature(m_session, false);
	if(!unt)
		unt = getSelectedChar(m_session, false);

	if(!unt)
	{
		RedSystemMessage(m_session, "You need to select a valid creature or player.");
		return true;
	}
	char* pSpellID = strtok((char*)args, " ");
	if (!pSpellID) return false;
	uint32 SpellID = atoi(pSpellID);
	if( !SpellID ) return false;

	SpellEntry * SE = dbcSpell.LookupEntryForced( SpellID );
	if( SE )
		unt->RemoveAura( SpellID );
	else
		return false;

	return true;
}

void WorldSession::CastOnAllPlayers(uint32 spellid)
{
	if(!CanUseCommand('a'))
		return;

	Player * plr;
	SpellEntry * info = dbcSpell.LookupEntry(spellid);
	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		plr = itr->second;
		if(plr->GetSession() && plr->IsInWorld())
		{
			if(plr->GetMapMgr() != GetPlayer()->GetMapMgr())
			{
				sEventMgr.AddEvent( static_cast< Unit* >( plr ), &Unit::EventCastSpell, static_cast< Unit* >( plr ), info, EVENT_PLAYER_CHECKFORCHEATS, 100, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );
			}
			else
			{
				Spell* sp = SpellPool.PooledNew(); 
				sp->Init(plr, info, true, 0);
				SpellCastTargets targets(plr->GetGUID());
				sp->prepare(&targets);
			}
		}
	}
	objmgr._playerslock.ReleaseReadLock();
}

bool ChatHandler::HandleWorldBuffCommand(const char* args, WorldSession *m_session)
{
	Player * self = m_session->GetPlayer();
	if(!self) return true;
	static uint32 BUFFSPELLS[9] = { 25802, 25800, 25796, 25795, 25794, 25799, 25798, 25797, 15167, };
	for(int i = 0; i != 9; i++)
	{
		m_session->CastOnAllPlayers(BUFFSPELLS[i]);
	}
	char worldtext[1024];
	string input2;
	input2 = MSG_COLOR_GREEN;
	input2 += "[Staff] |r";
	input2 += "|Hplayer:";
	input2 += m_session->GetPlayer()->GetName();
	input2 += "|h";
	input2 += m_session->GetPlayer()->GetName();
	input2 += "|h ";
	input2 += "gave ";
	input2 += (self->getGender()?"her":"his");
	input2 += " blessing to the world.";
	snprintf((char*)worldtext, 1024, "%s|r", input2.c_str());
	sWorld.SendWorldText(worldtext); // send message
	sGMLog.writefromsession(m_session, "used the WorldBuff command");
	return true;
}

bool ChatHandler::HandleTaxiJumpToEndCommand(const char* args, WorldSession *m_session)
{
	Player * pr = m_session->GetPlayer();
	if( !pr || !pr->IsInWorld() ) return true;
	if( !pr->GetTaxiPath() || !pr->GetTaxiState() )
	{
		RedSystemMessage(m_session, "You are not on a flight path!");
		return true;
	}
	TaxiPath * TP = pr->GetTaxiPath();
	if(TP)
	{
		uint32 PathCost = TP->GetPrice();
		if( pr->GetUInt32Value(PLAYER_FIELD_COINAGE) < TP->GetPrice() )
		{
			SystemMessage(m_session, "You need to pay the cost of the flightpath to do this!");
			WorldPacket data(SMSG_ACTIVATETAXIREPLY, 4);
			data << uint32( 3 );
			pr->GetSession()->SendPacket( &data );
			return false;
		}
		pr->JumpToEndTaxiNode(TP);
		pr->SetTaxiPath(NULL);
	}
	return true;
}

bool ChatHandler::HandleGetSkillCommand(const char *args, WorldSession * m_session)
{
	if(!(*args) || strlen(args) < 3) return false;
	std::string sArg = args;
	ASCENT_TOLOWER(sArg);
	Player * plr;
	if( m_session->GetPlayer()->RS_getAccess() >= RS_PROBEGM )
	{
		plr = getSelectedChar(m_session, false);
	}
	else
	{
		plr = m_session->GetPlayer();
	}
	if(!plr) return false;
	uint32 SkillId = 0;
	if(!strcmp(sArg.c_str(), "guns"))
		SkillId = SKILL_GUNS;
	if(!strcmp(sArg.c_str(), "crossbows"))
		SkillId = SKILL_CROSSBOWS;
	if(!strcmp(sArg.c_str(), "bows"))
		SkillId = SKILL_BOWS;
	if(!strcmp(sArg.c_str(), "internal"))
		SkillId = SKILL_INTERNAL;

	skilllineentry * sle = dbcSkillLine.LookupEntryForced(SkillId);
	if(sle && plr->_HasSkillLine(sle->id))
	{
		SystemMessage(m_session, "%s skill: [%u / %u]", sle->Name, plr->_GetSkillLineCurrent(sle->id, true), plr->_GetSkillLineMax(sle->id));
		return true;
	}
	return false;
}

bool ChatHandler::SendCastResult_Debug(const char* args, WorldSession* m_session)
{
	char* pErrorID = strtok((char*)args, " ");
	if (!pErrorID) return false;
	uint32 ErrorID = atoi(pErrorID);
	if( !ErrorID ) return false;
	packetSMSG_CASTRESULT pe;
	pe.SpellId = 0;
	pe.ErrorMessage = ErrorID;
	pe.MultiCast = 0;
	m_session->OutPacket( SMSG_CAST_FAILED, sizeof( packetSMSG_CASTRESULT ), &pe );
	return true;
}

bool ChatHandler::HandleKnownPVPTitlesCommand(const char* args, WorldSession * m_session)
{
	if(!*args)
		return false;

	uint64 bitmask = atoi((char*)args);
	Player *chr = getSelectedChar(m_session);
	if(!chr) return false;
	chr->SetUInt64Value(PLAYER_FIELD_KNOWN_PVPTITLES, bitmask);
	SystemMessage(m_session, "Done, set bitmask at %u.", bitmask);
	return true;
}

bool ChatHandler::HandleKnownPVETitlesCommand(const char* args, WorldSession * m_session)
{
	if(!*args)
		return false;

	uint64 bitmask = atoi((char*)args);
	Player *chr = getSelectedChar(m_session);
	if(!chr) return false;
	chr->SetUInt64Value(PLAYER_FIELD_KNOWN_PVETITLES, bitmask);
	SystemMessage(m_session, "Done, set bitmask at %u.", bitmask);
	return true;
}

bool ChatHandler::HandleAddPVPTitle(const char* args, WorldSession * m_session)
{
	if(!*args) return false;
	uint32 TitleID = atoi((char*)args);
	Player *chr = getSelectedChar(m_session);
	CharTitlesEntry * ct = dbcCharTitle.LookupEntryForced( TitleID );
	if( chr && ct )
		chr->AddTitle(ct, TITLE_TYPE_PVP, false);

	return true;
}

bool ChatHandler::HandleAddPVETitle(const char* args, WorldSession * m_session)
{
	if(!*args) return false;
	uint32 TitleID = atoi((char*)args);
	Player *chr = getSelectedChar(m_session);
	CharTitlesEntry * ct = dbcCharTitle.LookupEntryForced( TitleID );
	if( chr && ct )
		chr->AddTitle(ct, TITLE_TYPE_PVE, false);

	return true;
}

bool ChatHandler::HandleRemovePVPTitle(const char* args, WorldSession * m_session)
{
	if(!*args) return false;
	uint32 TitleID = atoi((char*)args);
	Player *chr = getSelectedChar(m_session);
	CharTitlesEntry * ct = dbcCharTitle.LookupEntryForced( TitleID );
	if( chr && ct )
		chr->RemoveTitle(ct, TITLE_TYPE_PVP, false);

	return true;
}

bool ChatHandler::HandleRemovePVETitle(const char* args, WorldSession * m_session)
{
	if(!*args) return false;
	uint32 TitleID = atoi((char*)args);
	Player *chr = getSelectedChar(m_session);
	CharTitlesEntry * ct = dbcCharTitle.LookupEntryForced( TitleID );
	if( chr && ct )
		chr->RemoveTitle(ct, TITLE_TYPE_PVE, false);

	return true;
}

bool ChatHandler::HandleSetValue(const char* args, WorldSession * m_session)
{
	if(!*args)
		return false;

	char* px = strtok((char*)args, " ");
	char* py = strtok(NULL, " ");
	char* pz = strtok(NULL, " ");

	if (!px || !py)
		return false;

	Unit* target = getSelectedChar(m_session);
	if(!target)
		return false;

	uint64 guid = target->GetGUID();

	uint32 Opcode = (uint32)atoi(px);
	if(Opcode >= target->GetValuesCount())
	{
		return false;
	}
	uint32 iValue;
	float fValue;
	bool isint32 = true;
	if(pz)
	{
		isint32 = (bool)atoi(pz);
	}
	if(isint32)
	{
		iValue = (uint32)atoi(py);
		target->SetUInt32Value( Opcode , iValue );
	}
	else
	{
		fValue = (float)atof(py);
		target->SetFloatValue( Opcode , fValue );
	}

	return true;
}

bool ChatHandler::HandleNPCBytes2Command(const char *args, WorldSession *m_session)
{
	uint32 bytes2 = (char*)args?atoi((char*)args):0;
	Creature* target = getSelectedCreature(m_session);

	if(!target || target->IsPlayer() || !target->isAlive())
		return false;

	target->SetUInt32Value(UNIT_FIELD_BYTES_2, bytes2);
	uint32 sqlid = target->GetSQL_id();
	char QueryString[1024];
	sprintf(QueryString, "UPDATE creature_spawns SET bytes2 = '%u' WHERE id = '%u'", bytes2, sqlid);
	WorldDatabase.Execute( QueryString );
	BlueSystemMessage(m_session, "Bytes2 changed to %u", bytes2);
	return true;
}

bool ChatHandler::HandleReloadScriptsCommand(const char *args, WorldSession *m_session)
{
#ifdef EGARI_DEBUG
	sScriptMgr.UnloadScripts();
	sScriptMgr.LoadScripts();
#endif
	return true;
}
