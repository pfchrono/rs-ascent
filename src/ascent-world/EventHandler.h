
#ifndef __EVENTHANDLER_H
#define __EVENTHANDLER_H

class rsEventTeleport
{
	public:
		rsEventTeleport();
		void AddNewEvent(Player * starter, const char * name);
		void ModifyDetails(Player * starter);
		void TeleportToEvent(Player * Plr);

		uint32	Index;
		uint32	StarterGUID;
		uint32	EventType;
		uint32	EventRestriction;
		uint32	EntryFee;
		uint32	FeeType;
		uint32	ReqEntryLevel;
		string	EventName;
		uint32	MapID;
		float	PosX;
		float	PosY;
		float	PosZ;
		uint32	Open;
};

class EventIterator : public Singleton < EventIterator >
{
	public:
		EventIterator();
		void LoadEventsFromDB();
		void SaveToDB();
		void AddNewEvent(Player *Plr);
		void ListEventsToPlayer(Player * Plr);

		rsEventTeleport *GetEventByIndex(uint32 Index);
		rsEventTeleport *GetEventByStarter(Player * Plr);
		
		vector<rsEventTeleport*> GetVector();
		vector<rsEventTeleport*>::iterator GetItr(); 
		uint32 LastIndex;
		map<uint32, uint32> LastMap;
		ASCENT_INLINE uint32 GetLastIndex() { return LastIndex; }

	protected:
		static Mutex ItrMutex;
		vector<rsEventTeleport*> EventVector;
		vector<rsEventTeleport*>::iterator rsEventItr;
		map<uint32, uint32>::iterator LMapItr;

};

#define sEventIterator EventIterator::getSingleton()

#endif
