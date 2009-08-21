/*
                      ,-.        _.---._     
                      |  `\.__.-''       `.   
                       \  _        _  ,.   \  
 ,+++=._________________)_||______|_|_||    |  ,_    _,   _, ,  ,  _, ___, _    ,_  
(_.ooo.===================||======|=|=||    |  |_)  / \, /   |_/  (_,' |  '|\   |_) 
   ~~'                 |  ~'      `~' o o  /  '| \ '\_/ '\_ '| \   _)  |   |-\ '| \ 
                        \   /~`\     o o  /    '  ` '      ` '  ` '    '   '  ` '  `
                         `~'    `-.____.-'  
						 Scripted for the RockStar FunServer by the RockStar Developers: Midnight, Egari, and T0aST.
						 http://www.fishstik.ca Please do not use these scripts for any other server
						 than the RockStar Funserver(http://fishstik.ca) as they were specially
						 scripted/modded for the server in question.
 */
#include "StdAfx.h"

initialiseSingleton( BugReporter );

void BugReporter::SetHighestGuid()
{
	QueryResult *result = CharacterDatabase.Query("SELECT MAX(ReportID) FROM bug_tracker");
	if(result)
	{
		m_reportId = result->Fetch()[0].GetUInt64() + 1;
		delete result;
	}

	Log.Notice("ObjectMgr", "HighGuid(BUGREPORTS) = %u", m_reportId - 1);
}

uint64 BugReporter::GenerateReportID()
{
	return m_reportId++;
}

void BugReporter::LoadBugReports()
{
	QueryResult *result = CharacterDatabase.Query( "SELECT `ReportID`, `reporterGuid`, `reporterAcct`, `reporterIP`, `charName`, `BugDesc`, `timestamp`, `status`, `assignedTo`, `comment` FROM bug_tracker WHERE `status` < %u ", BUG_REPORT_FIXED);

	BugReport * report;
	if(result == 0)
		return;

	do
	{
		Field *fields		= result->Fetch();

		report				= new BugReport;
		report->ReportID	= fields[0].GetUInt64();
		report->reporterGuid= fields[1].GetUInt64();
		report->reporterAcct= fields[2].GetString();
		report->reporterIP	= fields[3].GetString();
		report->charName	= fields[4].GetString();
		report->BugDesc		= fields[5].GetUInt32();
		report->timestamp	= fields[6].GetUInt32();
		report->status		= fields[7].GetUInt32();
		report->assignedTo	= fields[8].GetString();
		report->comment		= fields[9].GetString();

		AddReport(report, true);

	} while( result->NextRow() );

	Log.Notice("ObjectMgr", "%u active bug-reports loaded.", result->GetRowCount());
	delete result;
}

void BugReporter::SaveBugReport(BugReport* report, QueryBuffer * buf)
{
	std::stringstream ss;
	ss << "REPLACE INTO bug_tracker (`ReportID`, `reporterGuid`, `reporterAcct`, `reporterIP`, `charName`, `BugDesc`, `timestamp`, `status`, `assignedTo`, `comment`) VALUES(";
	ss << report->ReportID									<< ", ";
	ss << report->reporterGuid								<< ", '";
	ss << WorldDatabase.EscapeString(report->reporterAcct)	<< "', '";
	ss << WorldDatabase.EscapeString(report->reporterIP)	<< "', '";
	ss << WorldDatabase.EscapeString(report->charName)		<< "', '";
	ss << WorldDatabase.EscapeString(report->BugDesc)		<< "', ";
	ss << report->timestamp									<< ", ";
	ss << report->status									<< ", '";
	ss << WorldDatabase.EscapeString(report->assignedTo)	<< "', '";
	ss << WorldDatabase.EscapeString(report->comment)		<< "');";

	if(buf == NULL)
		WorldDatabase.ExecuteNA(ss.str( ).c_str( ));
	else
		buf->AddQueryStr(ss.str());
}

void BugReporter::AddReport(BugReport *report, bool startup)
{
	ASSERT( report );
	BugReport_List.push_back(report);

	// save
	if(!startup)
		SaveBugReport(report, NULL);
}

void BugReporter::DelReport(WorldSession * m_session, uint64 bReportGuid)
{
	for(BugReportList::iterator i = BugReport_List.begin(); i != BugReport_List.end();)
	{
		if( (*i)->ReportID == bReportGuid )
		{
			switch( (*i)->status )
			{
			case BUG_REPORT_FIXED:
				{
					if( m_session != NULL )
						sChatHandler.GreenSystemMessage(m_session, "That bug was already fixed.");
				}break;
			case BUG_REPORT_CLOSED:
				{
					if( m_session != NULL )
						sChatHandler.RedSystemMessage(m_session, "That report was already closed.");
				}break;
			default:
				{
					(*i)->status = BUG_REPORT_CLOSED;
					SaveBugReport((*i), NULL);
				}
			}
			return;
		}
		++i;
	}
}

BugReport* BugReporter::GetReport(uint64 bReportGuid)
{
	for(BugReportList::iterator i = BugReport_List.begin(); i != BugReport_List.end();)
	{
		if((*i)->ReportID == bReportGuid)
		{
			return (*i);
		}
		++i;
	}
	return NULL;
}

void BugReporter::Destroy()
{
	Log.Notice("ObjectMgr", "Deleting bug-reports from memory...");
	for(BugReportList::iterator itr = BugReport_List.begin(); itr != BugReport_List.end(); ++itr)
		delete (*itr);
}

void WorldSession::CreateBugReport(const char * args)
{
	if(!*args)
		return;

	BugReport *report = new BugReport;
	report->ReportID		= sBugReporter.GenerateReportID();
	report->reporterGuid	= GetPlayer()->GetGUID();
	report->reporterAcct	= GetAccountName();
	report->reporterIP		= GetSocket()->GetRemoteIP();
	report->charName		= GetPlayer()->GetName();
	report->BugDesc			= args;
	report->timestamp		= (uint32)UNIXTIME;
	report->status			= BUG_REPORT_ACTIVE;
	report->assignedTo		= "Nobody";
	report->comment			= "None";

	sBugReporter.AddReport(report, false);

	char msg[128];
	sprintf(msg, "A new bug-report has been created with id: %u", report->ReportID);
	sWorld.SendGMWorldText( msg );
}

string GetStatusString(uint32 status)
{
	switch( status )
	{
	case BUG_REPORT_ACTIVE:
		return "Active";
	case BUG_REPORT_ASSIGNED:
		return "Assigned";
	case BUG_REPORT_FIXED:
		return "Fixed";
	case BUG_REPORT_CLOSED:
		return "Closed";
	}
	return NULL;
}

void BugReporter::ListReports(WorldSession *m_session, uint64 start)
{
	uint64 end = start + 5;
	uint64 count = 0;
	for(BugReportList::iterator itr = BugReport_List.begin(); itr != BugReport_List.end(); itr++)
	{
		if( (*itr) == NULL )
			continue;

		if((*itr)->status >= BUG_REPORT_FIXED)
			continue;

		if( (*itr)->ReportID < start )
			continue;

		std::stringstream ss;
		ss << "Bug Report - ID: " << (*itr)->ReportID << " - Plr: " << (*itr)->charName << " - Status: " << GetStatusString((*itr)->status);
		sChatHandler.SystemMessage(m_session, ss.str().c_str());

		count++;

		if( count == end )
		{
			sChatHandler.SystemMessage(m_session, "To display the next set of reports type, !bug list %u", end+1);
			break;
		}
	}
	if( count == 0 )
	{
		sChatHandler.SystemMessage(m_session, "There are no reports to display");
		return;
	}
}

bool ChatHandler::HandleBugReportsListCommand(const char* args, WorldSession *m_session)
{
	Player *cplr = m_session->GetPlayer();
	uint64 start = (args ? atoi(args) : 0);;

	if( start < 0 )
		return false;

	sBugReporter.ListReports(m_session, start);

	return true;
}


bool ChatHandler::HandleGetBugReportByIdCommand(const char* args, WorldSession *m_session)
{
	if(!*args)
		return false;

	Player *cplr = m_session->GetPlayer();

	uint32 reportID = atoi(args);
	if(reportID == NULL)
		return false;

	BugReport * report = sBugReporter.GetReport(reportID);
	if( report == NULL )
	{
		RedSystemMessage(m_session, "Unable to retrieve bugreport.");
		return true;
	}

	GreenSystemMessage(m_session,"=====================");
	GreenSystemMessage(m_session,"Bug Report ID: %u", report->ReportID);
	GreenSystemMessage(m_session,"Reporter: %s[%s - %s]", report->charName.c_str(), report->reporterAcct.c_str(), report->reporterIP.c_str());
	GreenSystemMessage(m_session,"Description: %s", report->BugDesc.c_str());
	GreenSystemMessage(m_session,"=====================");

	return true;
}

