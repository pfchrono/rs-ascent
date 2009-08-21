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

#include <string>
#include "StdAfx.h"

#ifndef WARPNPC_SCRIPTS_SETUP_H
#define WARPNPC_SCRIPTS_SETUP_H

#ifdef WIN32
/* warning C4305: 'argument' : truncation from 'double' to 'float' */
#pragma warning( disable : 4018 244 305 )
#endif

void	Servant(ScriptMgr * mgr);
void	SetupCapHOOK(ScriptMgr * mgr);
void	SetupGLinkedVendor(ScriptMgr * mgr);
void	SetupCustom_Teleporters(ScriptMgr * mgr);
void	Setup_Portals(ScriptMgr * mgr);
void	SetupStormwindScript(ScriptMgr * mgr);
void	SetupJustinius(ScriptMgr * mgr);
void	SetupHooks(ScriptMgr * mgr);
void	SetupPvPKill(ScriptMgr * mgr);
void	SetupKillTheKing(ScriptMgr * mgr);
void	SetupGeneric(ScriptMgr * mgr);
void	SetupBloodsailStuff(ScriptMgr * mgr);
void	SetupRandomScripts(ScriptMgr * mgr);
void	SetupGoHandlers(ScriptMgr * mgr);
void	SetupDruid(ScriptMgr * mgr);
void	SetupShadowmoon(ScriptMgr * mgr);
void	SetupHellfirePeninsula(ScriptMgr * mgr);
void	SetupDJ(ScriptMgr * mgr);
void	SetupPaladin(ScriptMgr * mgr);
void	SetupTerrokarForest(ScriptMgr * mgr);
void	SetupNagrand(ScriptMgr * mgr);
void	SetupSilverpineForest(ScriptMgr * mgr);
void	SetupTNGuard(ScriptMgr * mgr);
void	SetupStandState(ScriptMgr * mgr);
void	SetupItemGossip(ScriptMgr * mgr);
void	SetupZangarmarsh(ScriptMgr * mgr);
void	SetupUndercity(ScriptMgr * mgr);
void	SetupBladeEdgeMountains(ScriptMgr * mgr);
void	SetupAzuremystIsle(ScriptMgr * mgr);
void	SetupMage(ScriptMgr * mgr);
void	SetupBarrens(ScriptMgr * mgr);
void	SetupEastern(ScriptMgr *mgr);
void	SetupAshenvale(ScriptMgr * mgr);
void	SetupPeaceKeeperAI(ScriptMgr * mgr);
void	SetupQuestHooks(ScriptMgr * mgr);
void	SetupWarlockDSTEED(ScriptMgr *mgr);
void	SetupPortToFriends(ScriptMgr *mgr);
void	SetupIsleOfQuelDanas(ScriptMgr * mgr);
void	SetupMoonMisc(ScriptMgr *mgr);
void	SetupUnGoro(ScriptMgr * mgr);
// Added June 2nd 2008
void	SetupTomeOfExp(ScriptMgr * mgr);
void	SetupSurgeon(ScriptMgr * mgr);
// Added July 1st 2008
void	Setup_CustomGOSSIP(ScriptMgr * mgr);
// Added July 28th 2008 - Midnight Darkmoon Stuff
void	SetupDarkMoon(ScriptMgr * mgr);
/* Using on new Script file for many quest fixes - Midnight */
void	SetupMiscQuest(ScriptMgr * mgr);
void	Setup_KSlothAI(ScriptMgr * mgr);
void	SetupScrollOfMorphing(ScriptMgr * mgr);

struct SP_AI_Spell
{
	SpellEntry	*info;				/* spell info */
	char		targettype;			/* 0-self , 1-attaking target, .... */
	bool		instant;			/* does it is instant or not? */
	float		perctrigger;		/* % of the cast of this spell in a total of 100% of the attacks */
	float		hpreqtocast;		/* If hpreqtocast <= mobhp then cast */
	int			attackstoptimer;	/* stop the creature from attacking */
	int			soundid;			/* sound id in DBC */
	int			reqlvl;				/* Spell Level */
	std::string speech;				/* text displaied when spell was casted */
	uint32		cooldown;			/* spell cooldown */
	uint32		cooldown2;			/* spell cooldown */
	uint32		proctimes;
	uint32		proctimes2;
	uint32		casttime;			/* "time" left to cast spell */
	bool		distancecheck;
	int			maxlvl;
	bool		rangecheck;
};


enum 
{
	TARGET_SELF,
	TARGET_VARIOUS,
	TARGET_ATTACKING,
	TARGET_DESTINATION,
	TARGET_RANDOM_FRIEND,	// doesn't work yet
	TARGET_RANDOM_SINGLE,
	TARGET_RANDOM_DESTINATION,
};

inline Unit *GetRandomAlly(Unit *ptr, uint32 hpreq)
{
	if(!ptr || ptr->GetTypeId() != TYPEID_UNIT || !ptr->isAlive()) return 0;

	/*~~~~~~~~~~~~~~~~*/
	Unit	*ret = NULL;
	/*~~~~~~~~~~~~~~~~*/

	for(set < Object * >::iterator itr = ptr->GetInRangeSetBegin(); itr != ptr->GetInRangeSetEnd(); ++itr)
	{
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		Object	*obj = (Object *) (*itr);
		/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		if
		(
			obj->IsUnit()
		&&	isFriendly(obj, ptr)
		&&	(( Unit * ) obj)->GetHealthPct() <= hpreq
		&&	(( Unit * ) obj)->isAlive()
		&&	ptr->GetDistanceSq(obj) <= 625.0f
		)
		{
			ret = ( Unit * ) obj;
			break;
		}
	}

	if(ret == NULL)
		return 0;
	else
		return ret;
}

struct SP_AI_SpellF{
	SpellEntry *info;		// spell info
	char targettype;		// 0-self , 1-attaking target, ....
	bool instant;			// does it is instant or not?
	float perctrigger;		// % of the cast of this spell in a total of 100% of the attacks
	int attackstoptimer;	// stop the creature from attacking
	int soundid;			// sound id from DBC
	std::string speech;		// text displaied when spell was casted
	uint32 cooldown;		// spell cooldown
	uint32 casttime;		// "time" left to cast spell
	uint32 reqlvl;			// required level ? needed?
	float hpreqtocast;		// ? needed?
	float mindist2cast;		// min dist from caster to victim to perform cast (dist from caster >= mindist2cast)
	float maxdist2cast;		// max dist from caster to victim to perform cast (dist from caster <= maxdist2cast)
	int minhp2cast;			// min hp amount of victim to perform cast on it (health >= minhp2cast)
	int maxhp2cast;			// max hp amount of victim to perform cast on it (health <= maxhp2cast)
};

#endif WARPNPC_SCRIPTS_SETUP_H
