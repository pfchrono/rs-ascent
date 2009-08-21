/*
 * Moon++ Scripts for Ascent MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.	If not, see <http://www.gnu.org/licenses/>.
 */
#include "../ascent-world/StdAfx.h"
#include "Setup.h"
#define SKIP_ALLOCATOR_SHARING 1
#include <ScriptSetup.h>

extern "C" SCRIPT_DECL uint32 _exp_get_script_type()
{
	return SCRIPT_TYPE_MISC;
}

extern "C" SCRIPT_DECL void _exp_script_register(ScriptMgr* mgr)
{
	Servant(mgr);

	SetupCapHOOK(mgr);
	SetupGLinkedVendor(mgr);
	SetupCustom_Teleporters(mgr);
	Setup_Portals(mgr);
	SetupStormwindScript(mgr);
	SetupJustinius(mgr);
	SetupHooks(mgr);
	SetupPvPKill(mgr);
	SetupKillTheKing(mgr);
	SetupGeneric(mgr);
	SetupBloodsailStuff(mgr);
	SetupRandomScripts(mgr);
	SetupGoHandlers(mgr);
	SetupDruid(mgr);
	SetupPaladin(mgr);
	SetupShadowmoon(mgr);
	SetupHellfirePeninsula(mgr);
	SetupDJ(mgr);
	SetupPaladin(mgr);
	SetupBladeEdgeMountains(mgr);
	SetupTerrokarForest(mgr);
	SetupNagrand(mgr);
	SetupSilverpineForest(mgr);
	SetupTNGuard(mgr);
	SetupStandState(mgr);
	SetupItemGossip(mgr);
	SetupZangarmarsh(mgr);
	SetupUndercity(mgr);
	SetupAzuremystIsle(mgr);
	SetupUnGoro(mgr);
	SetupMage(mgr);
	SetupMage(mgr);
	SetupBarrens(mgr);
	SetupEastern(mgr);
	SetupAshenvale(mgr);
	SetupPeaceKeeperAI(mgr);
	SetupQuestHooks(mgr);
	SetupWarlockDSTEED(mgr);
	SetupPortToFriends(mgr);
	SetupIsleOfQuelDanas(mgr);
	SetupMoonMisc(mgr);
	// Added June 2nd 2008
	SetupTomeOfExp(mgr);
	SetupSurgeon(mgr);
	// Added July 1st 2008
	Setup_CustomGOSSIP(mgr);
	// Added July 28th 2008 - Midnight DarkMoon Stuff
	SetupDarkMoon(mgr);

	SetupScrollOfMorphing(mgr);
	Setup_KSlothAI(mgr);
	/* Using on new Script file for many quest fixes - Midnight */
	SetupMiscQuest(mgr);
	Log.Success("RS_Scripts", "Loaded with no problems.");
}

#ifdef WIN32

BOOL APIENTRY DllMain( HANDLE hModule, DWORD	ul_reason_for_call, LPVOID lpReserved )
{
	return TRUE;
}

#endif
