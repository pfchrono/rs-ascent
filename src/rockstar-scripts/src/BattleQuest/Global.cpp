#include "Global.h"

void SetupGlobal()
{
	Global::Initialize();
}

void Global::Initialize()
{
	CREATE_HOOK(ew5,EnterWorldHook,ALL_MAPS,&Global::FixWorld);
	CREATE_HOOK(ww1,EnterWorldHook,0,&Global::EnterWorld);
	CREATE_HOOK(ww2,EnterWorldHook,1,&Global::EnterWorld);
	CREATE_HOOK(ww3,EnterWorldHook,530,&Global::EnterWorld);
}

void Global::FixWorld(Player * pPlayer)
{
	if(pPlayer->m_bg)
		return;

	pPlayer->RemoveAura(32727);
	pPlayer->RemoveAura(32725);
	pPlayer->RemoveAura(32724);
	pPlayer->RemoveAura(44521);
}

void Global::EnterWorld(Player * pPlayer)
{
	if(!pPlayer->isDead())
		return;

	pPlayer->ResurrectPlayer();

	if(!pPlayer->HasSpell(7266))
		pPlayer->addSpell(7266);
}