#include "StdAfx.h"
#include "Setup.h"

// Trenton Lighthammer
#define GOSSIP_TRENTON_LIGHTHAMMER    "Tell me more, Trenton."

class SCRIPT_DECL TrentonLighthammer_Gossip : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player * plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1758, plr);
        Menu->AddItem( 0, GOSSIP_TRENTON_LIGHTHAMMER, 1);
        
        if(AutoSend)
            Menu->SendTo(plr);
    }

    void GossipSelectOption(Object* pObject, Player * plr, uint32 Id, uint32 IntId, const char * Code)
    {
		if(pObject->GetTypeId()!=TYPEID_UNIT)
			return;
		
		GossipMenu * Menu;
        switch(IntId)
        {
        case 1:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1759, plr);
				Menu->SendTo(plr);
            }break;
		}
    }

    void Destroy()
    {
        delete this;
    }
};

void SetupTanarisGossip(ScriptMgr * mgr)
{
	GossipScript * TrentonLighthammerGossip = (GossipScript*) new TrentonLighthammer_Gossip;
	mgr->register_gossip_script(7804, TrentonLighthammerGossip); // Trenton Lighthammer

}
