
#ifndef __BUGREPORTSYSTEM_H
#define __BUGREPORTSYSTEM_H

struct BugReport
{
	uint64 ReportID;
	uint64 reporterGuid;
	std::string reporterAcct;
	std::string reporterIP;
	std::string charName;
	std::string BugDesc;
	uint32 timestamp;
	uint32 status;
	std::string assignedTo;
	std::string comment;
};

typedef std::list<BugReport*>	BugReportList;

enum BugReportStatus
{
	BUG_REPORT_ACTIVE	= 0,
	BUG_REPORT_ASSIGNED	= 1,
	BUG_REPORT_FIXED	= 2,
	BUG_REPORT_CLOSED	= 3,
};

class SERVER_DECL BugReporter :  public Singleton < BugReporter >
{
	friend class ChatHandler;

public:
	uint64 m_reportId;

	BugReportList	BugReport_List;
	uint64 GenerateReportID();
	void SetHighestGuid();

	void LoadBugReports();
	void SaveBugReport(BugReport* report, QueryBuffer * buf);

	void Destroy();

	void AddReport(BugReport *report, bool startup);
	void DelReport(WorldSession * m_session, uint64 bReportGuid);
	BugReport* GetReport(uint64 reportId);

	void ListReports(WorldSession *m_session, uint64 start = 0);
};

#define sBugReporter BugReporter::getSingleton()

#endif // #ifndef __BUGREPORTSYSTEM_H