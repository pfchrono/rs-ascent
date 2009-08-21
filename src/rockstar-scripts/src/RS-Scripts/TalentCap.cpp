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

void ResetTalents(Player * Plr)
{
	uint32 TPCap = 76;
	uint32 l = Plr->getLevel();
	uint32 m = TPCap + 9;
	if( l < m ) return;
	Plr->Reset_Talents();
	if( l > m )
		l = m;
	
	std::stringstream CapCheck;
	uint32 TalentPoints = l - 9;
	Plr->SetUInt32Value(PLAYER_CHARACTER_POINTS1, TalentPoints); 
	CapCheck << "INSERT IGNORE INTO TalentPoints VALUES ('" // ignore errors xD
		<< Plr->GetLowGUID() 
		<< "', '" 
		<< Plr->getLevel() 
		<< "', '" 
		<< TalentPoints 
		<< "')";
	WorldDatabase.Execute( CapCheck.str().c_str() );
	Log.Debug("RS_TalentCOP", "Talents of %s[%u] ganked! Time for a Donut..", Plr->GetName(), Plr->GetLowGUID());
};

void TalentCAP(Player * Plr)
{
	//WorldSession * m_session = Plr->m_session();
	std::stringstream CheckForPlr;
	CheckForPlr << "SELECT COUNT(guid) FROM talentpoints WHERE guid = '" << Plr->GetLowGUID() << "'";
	QueryResult * CFPresult = WorldDatabase.Query( CheckForPlr.str().c_str() );
	if(CFPresult)
	{
		Log.Debug("RS_TalentCOP", "Found player %s[%u], not guilty!", Plr->GetName(), Plr->GetLowGUID());
		WorldDatabase.FreeQueryResult( CFPresult );
		return;
	}
	uint32 TPCAP = 76;
	uint32 m = TPCAP + 9;
	uint32 l = Plr->getLevel();
	if( l < m )
		return;

	uint32 TP = (l - 9);
	if( TP > TPCAP && !CFPresult )
		ResetTalents(Plr);	
	
	return;
}


void SetupCapHOOK(ScriptMgr *mgr)
{
	printf("\n");
	Log.Notice("RS_TalentCOP", "Locked and loaded for combat!");
	Log.Notice("RS_TalentCOP", "Getting out the shotgun...");
	mgr->register_hook(SERVER_HOOK_EVENT_ON_ENTER_WORLD, (void*)TalentCAP);
	Log.Notice("RS_TalentCOP", "Lets Rok!");
}
