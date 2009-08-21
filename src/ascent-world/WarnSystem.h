
#ifndef __WARNSYSTEM_H
#define __WARNSYSTEM_H

class SERVER_DECL WarnSystem :  public Singleton < WarnSystem >
{
	friend class ChatHandler;

public:
	void AddWarn(Player * Warner, Player * Warned, const char  *reason);
	void ReachedPunishmentLevel(Player * Warner, Player * Warned, uint32 NewWarnCnt);
	void DelWarn(Player * Warner, Player * Warned, uint32 WarnID);
    void ListWarns(Player * Warner, Player * Warned);
	void ClearWarns(Player * Warner, Player * Warned);
	bool IsEnabled(){ return sWorld.rsWarnSystem; };
};

#define sWarnSystem WarnSystem::getSingleton()

#endif
