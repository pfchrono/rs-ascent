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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "Base.h"

/************************************************************************/
/* Raid_BlackTemple.cpp Script								           */
/************************************************************************/

//////////////////////////////////////////////////////////////////////////
/////// Trash AIs

class TemplateAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(TemplateAI, MoonScriptCreatureAI);
	TemplateAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
	}
};

//////////////////////////////////////////////////////////////////////////
/////// Beast AIs

#define CN_DRAGON_TURTLE					22885
#define DRAGON_TRUTLE_SHELL_SHIELD			40087
#define DRAGON_TURTLE_WATER_SPIT			40086

class DragonTurtleAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(DragonTurtleAI, MoonScriptCreatureAI);
	DragonTurtleAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(DRAGON_TRUTLE_SHELL_SHIELD, Target_Self, 10, 0, 25);
		AddSpell(DRAGON_TURTLE_WATER_SPIT, Target_Current, 8, 2.5, 20, 0, 45);		// Random?
	}
};

#define CN_LEVIATHAN						22884
#define LEVIATHAN_DEBILITATING_SPRAY		40079
#define LEVIATHAN_POISON_SPIT				40078
#define LEVIATHAN_TAIL_SWEEP				40077

class LeviathanAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(LeviathanAI, MoonScriptCreatureAI);
	LeviathanAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(LEVIATHAN_DEBILITATING_SPRAY, Target_RandomPlayer, 8, 2.5, 20);
		AddSpell(LEVIATHAN_POISON_SPIT, Target_RandomPlayer, 7, 2.5, 25);
		AddSpell(LEVIATHAN_TAIL_SWEEP, Target_Self, 7, 0, 30);
	}
};

#define CN_MUTANT_WAR_HOUND					23232
#define MUTANT_WAR_HOUND_CLOUD_OF_DISEASE	41193

class MutantWarHoundAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(MutantWarHoundAI, MoonScriptCreatureAI);
	MutantWarHoundAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature) {}

	void OnDied(Unit *pKiller)
	{
		ParentClass::OnDied(pKiller);

		Aura *pAura = new Aura();
		if (pAura != NULL)
		{
			pAura->Init(dbcSpell.LookupEntry(MUTANT_WAR_HOUND_CLOUD_OF_DISEASE), 20000, _unit, _unit);
			_unit->AddAura(pAura);
		}
	}
};
// I don't have this creature in DB, so hasn't checked it yet
#define CN_SHADOWMOON_RIDING_HOUND					23083
#define SHADOWMOON_RIDING_HOUND_CARNIVOROUS_BITE	41092
#define SHADOWMOON_RIDING_HOUND_CHARGE				25821
#define SHADOWMOON_RIDING_HOUND_ENRAGE				8599

void SpellFunc_Charge(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType);

class ShadowmoonRidingHoundAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonRidingHoundAI, MoonScriptCreatureAI);
	ShadowmoonRidingHoundAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWMOON_RIDING_HOUND_CARNIVOROUS_BITE, Target_Current, 10, 0, 20, 0, 10);
		mCharge = AddSpell(SHADOWMOON_RIDING_HOUND_CHARGE, Target_Current, 0, 0, 0);
		AddSpellFunc(&SpellFunc_Charge, Target_RandomPlayer, 8, 0, 35);
		AddSpell(SHADOWMOON_RIDING_HOUND_ENRAGE, Target_Self, 6, 0, 40);
	}

	SpellDesc*	mCharge;
};

void SpellFunc_Charge(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType)
{
	ShadowmoonRidingHoundAI *pHoundAI = (pCreatureAI != NULL) ? (ShadowmoonRidingHoundAI*)pCreatureAI : NULL;
	if (pHoundAI != NULL)
	{
		Unit *pCurrentTarget = pHoundAI->GetUnit()->GetAIInterface()->GetNextTarget();
		if (pCurrentTarget != NULL && pCurrentTarget != pTarget)
		{
			pHoundAI->GetUnit()->GetAIInterface()->AttackReaction(pTarget, 500);
			pHoundAI->GetUnit()->GetAIInterface()->SetNextTarget(pTarget);
			pHoundAI->GetUnit()->GetAIInterface()->RemoveThreatByPtr(pCurrentTarget);
		}

		pHoundAI->CastSpell(pHoundAI->mCharge);
	}
}

//////////////////////////////////////////////////////////////////////////
/////// Demon AIs

#define	CN_SISTER_OF_PLEASURE				22964
#define	SISTER_OF_PLEASURE_GREATER_HEAL		41378
#define SISTER_OF_PLEASURE_HOLY_NOVA		41380
#define SISTER_OF_PLEASURE_SHARED_BONDS		41362
#define SISTER_OF_PLEASURE_SHELL_OF_LIFE	41381

class SisterOfPleasureAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(SisterOfPleasureAI, MoonScriptCreatureAI);
	SisterOfPleasureAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SISTER_OF_PLEASURE_GREATER_HEAL, Target_WoundedFriendly, 10, 2, 45);
		AddSpell(SISTER_OF_PLEASURE_HOLY_NOVA, Target_Self, 10, 0, 20);
		AddSpell(SISTER_OF_PLEASURE_SHARED_BONDS, Target_Current, 5, 0, 25);
		AddSpell(SISTER_OF_PLEASURE_SHELL_OF_LIFE, Target_Self, 7, 1, 45);
	}
};

#define	CN_SISTER_OF_PAIN					22956
#define	SISTER_OF_PAIN_LASH_OF_PAIN			41353
#define	SISTER_OF_PAIN_PAINFUL_RAGE			41369
#define	SISTER_OF_PAIN_SHADOW_WORD_PAIN		41355
#define	SISTER_OF_PAIN_SHARED_BONDS			41362
#define	SISTER_OF_PAIN_SHELL_OF_PAIN		41371

class SisterOfPainAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(SisterOfPainAI, MoonScriptCreatureAI);
	SisterOfPainAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SISTER_OF_PAIN_LASH_OF_PAIN, Target_Current, 10, 0, 25, 0, 10);
		AddSpell(SISTER_OF_PAIN_PAINFUL_RAGE, Target_Self, 5, 0, 60);
		AddSpell(SISTER_OF_PAIN_SHADOW_WORD_PAIN, Target_RandomPlayer, 10, 0, 25);
		AddSpell(SISTER_OF_PAIN_SHARED_BONDS, Target_Current, 5, 0, 25);
		AddSpell(SISTER_OF_PAIN_SHELL_OF_PAIN, Target_Self, 7, 1, 45);
	}
};

#define	CN_PRIESTESS_OF_DEMENTIA				22957
#define PRIESTESS_OF_DEMENTIA_CONFUSION			41397
#define PRIESTESS_OF_DEMENTIA_DEMENTIA			41404

class PriestessOfDementiaAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(PriestessOfDementiaAI, MoonScriptCreatureAI);
	PriestessOfDementiaAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(PRIESTESS_OF_DEMENTIA_CONFUSION, Target_Self, 8, 0, 30);
		AddSpell(PRIESTESS_OF_DEMENTIA_DEMENTIA, Target_Self, 5, 0, 60);
	}
};

#define	CN_PRIESTESS_OF_DELIGHT					22962
#define PRIESTESS_OF_DELIGHT_CURSE_OF_VITALITY	41351

class PriestessOfDelightAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(PriestessOfDelightAI, MoonScriptCreatureAI);
	PriestessOfDelightAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(PRIESTESS_OF_DELIGHT_CURSE_OF_VITALITY, Target_RandomPlayer, 10, 0, 30);
	}
};

#define	CN_ILLIDARI_NIGHTLORD					22855
#define ILLIDARI_NIGHTLORD_SUMMON_SHADOWFIENDS	39649
#define ILLIDARI_NIGHTLORD_SHADOW_INFERNO		39645
#define ILLIDARI_NIGHTLORD_FEAR					41150
#define ILLIDARI_NIGHTLORD_CURSE_OF_MENDING		39647

class IllidariNightlordAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariNightlordAI, MoonScriptCreatureAI);
	IllidariNightlordAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ILLIDARI_NIGHTLORD_SUMMON_SHADOWFIENDS, Target_Self, 7, 0, 45);			// does it work?
		AddSpell(ILLIDARI_NIGHTLORD_SHADOW_INFERNO, Target_Self, 10, 0, 25);
		AddSpell(ILLIDARI_NIGHTLORD_FEAR, Target_Self, 7, 1, 30);
		AddSpell(ILLIDARI_NIGHTLORD_CURSE_OF_MENDING, Target_RandomPlayer, 8, 2, 35);
	}
};

#define CN_ILLIDARI_HEARTSEEKER							23339
#define ILLIDARI_HEARTSEEKER_CURSE_OF_THE_BLEAKHEART	41170
#define ILLIDARI_HEARTSEEKER_RAPID_SHOT					41173
#define ILLIDARI_HEARTSEEKER_SHOOT						41169
#define ILLIDARI_HEARTSEEKER_SKELETON_SHOT				41171

void SpellFunc_RapidShot(SpellDesc * pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType);

class IllidariHeartseekerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariHeartseekerAI, MoonScriptCreatureAI);
	IllidariHeartseekerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ILLIDARI_HEARTSEEKER_CURSE_OF_THE_BLEAKHEART, Target_RandomPlayer, 8, 0, 40, 0, 30);
		mRapidShot = AddSpell(ILLIDARI_HEARTSEEKER_RAPID_SHOT, Target_Self, 0, 8, 0);						// I need to check mechanics (maybe it should speed up usage of Shoot spell (2x lesser freq))
		AddSpell(ILLIDARI_HEARTSEEKER_SHOOT, Target_Current, 80, 0, 1, 0, 30);
		AddSpell(ILLIDARI_HEARTSEEKER_SKELETON_SHOT, Target_RandomPlayer, 7, 0, 25, 0, 30);
		AddSpellFunc(&SpellFunc_RapidShot, Target_Current, 7, 8, 40, 0, 30);
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		if (GetRangeToUnit(pTarget) <= 30.0f)
		{
			SetBehavior(Behavior_Spell);
			SetCanMove(false);
		}
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();

		Unit *pTarget = _unit->GetAIInterface()->GetNextTarget();
		if (pTarget != NULL)
		{
			if (GetRangeToUnit(pTarget) <= 30.0f)
			{
				SetBehavior(Behavior_Spell);
				SetCanMove(false);
			}
		}
	}

	SpellDesc*	mRapidShot;
};

void SpellFunc_RapidShot(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType)
{
	IllidariHeartseekerAI *pHeartseeker = (pCreatureAI != NULL) ? (IllidariHeartseekerAI*)pCreatureAI : NULL;
	if (pHeartseeker != NULL)
	{
		pHeartseeker->CastSpell(pHeartseeker->mRapidShot);
	}
}

#define CN_ILLIDARI_FEARBRINGER					22954
#define ILLIDARI_FEARBRINGER_ILLIDARI_FLAMES	40938
#define ILLIDARI_FEARBRINGER_RAIN_OF_CHAOS		40946
#define ILLIDARI_FEARBRINGER_WAR_STOMP			40936

class IllidariFearbringerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariFearbringerAI, MoonScriptCreatureAI);
	IllidariFearbringerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ILLIDARI_FEARBRINGER_ILLIDARI_FLAMES, Target_Current, 8, 2, 25, 0, 10);
		AddSpell(ILLIDARI_FEARBRINGER_RAIN_OF_CHAOS, Target_RandomDestination, 7, 0, 35);
		AddSpell(ILLIDARI_FEARBRINGER_WAR_STOMP, Target_Self, 8, 0, 35);
	}
};

#define CN_ILLIDARI_DEFILER					22853
#define ILLIDARI_DEFILER_BANISH				39674
#define ILLIDARI_DEFILER_CURSE_OF_AGONY		39672
#define ILLIDARI_DEFILER_FEL_IMMOLATE		39670
#define ILLIDARI_DEFILER_RAIN_OF_CHAOS		39671

class IllidariDefilerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariDefilerAI, MoonScriptCreatureAI);
	IllidariDefilerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ILLIDARI_DEFILER_BANISH, Target_RandomPlayer, 8, 1, 30);
		AddSpell(ILLIDARI_DEFILER_CURSE_OF_AGONY, Target_RandomPlayer, 7, 0, 45);
		AddSpell(ILLIDARI_DEFILER_FEL_IMMOLATE, Target_RandomPlayer, 8, 2, 25);
		AddSpell(ILLIDARI_DEFILER_RAIN_OF_CHAOS, Target_RandomDestination, 7, 6, 35);
	}
};

#define CN_ILLIDARI_CENTURION				23337
#define ILLIDARI_CENTURION_CLEAVE			15284
#define ILLIDARI_CENTURION_SONIC_STRIKE		41168

class IllidariCenturionAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariCenturionAI, MoonScriptCreatureAI);
	IllidariCenturionAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ILLIDARI_CENTURION_CLEAVE, Target_Current, 10, 0, 20, 0, 10);
		AddSpell(ILLIDARI_CENTURION_SONIC_STRIKE, Target_Self, 8, 0, 35);
	}
};

#define CN_ILLIDARI_BONESLICER					22869
#define ILLIDARI_BONESLICER_CLOAK_OF_SHADOWS	39666
#define ILLIDARI_BONESLICER_GOUGE				24698
#define ILLIDARI_BONESLICER_SHADOWSTEP			41176

void SpellFunc_Gouge(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType);

class IllidariBoneslicerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariBoneslicerAI, MoonScriptCreatureAI);
	IllidariBoneslicerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ILLIDARI_BONESLICER_CLOAK_OF_SHADOWS, Target_Self, 8, 0, 25);
		mGouge = AddSpell(ILLIDARI_BONESLICER_GOUGE, Target_Current, 0, 0, 0);
		AddSpellFunc(&SpellFunc_Gouge, Target_Current, 7, 0, 25, 0, 10);
		AddSpell(ILLIDARI_BONESLICER_SHADOWSTEP, Target_Current, 7, 0, 30);
	}

	SpellDesc*	mGouge;
};

void SpellFunc_Gouge(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType)
{
	IllidariBoneslicerAI *pBoneslicer = (pCreatureAI != NULL) ? (IllidariBoneslicerAI*)pCreatureAI : NULL;
	if (pBoneslicer != NULL)
	{
		pBoneslicer->CastSpell(pBoneslicer->mGouge);
		Unit *pSecondHated = pBoneslicer->GetUnit()->GetAIInterface()->GetSecondHated();
		if (pSecondHated != NULL)
		{
			pBoneslicer->GetUnit()->GetAIInterface()->AttackReaction(pSecondHated, 2000);
			pBoneslicer->GetUnit()->GetAIInterface()->SetNextTarget(pSecondHated);
			pBoneslicer->GetUnit()->GetAIInterface()->RemoveThreatByPtr(pTarget);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
/////// Humanoid AIs

#define CN_ASHTONGUE_BATTLELORD					22844
#define ASHTONGUE_BATTLELORD_CLEAVE				15284
#define ASHTONGUE_BATTLELORD_CONCUSSION_BLOW	32588
#define ASHTONGUE_BATTLELORD_CONCUSSIVE_THROW	41182
#define ASHTONGUE_BATTLELORD_ENRAGE				34970

class AshtongueBattlelordAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueBattlelordAI, MoonScriptCreatureAI);
	AshtongueBattlelordAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_BATTLELORD_CLEAVE, Target_Current, 10, 0, 15, 0, 10);
		AddSpell(ASHTONGUE_BATTLELORD_CONCUSSION_BLOW, Target_Current, 8, 0, 30, 0, 10);
		AddSpell(ASHTONGUE_BATTLELORD_CONCUSSIVE_THROW, Target_RandomPlayerNotCurrent, 8, 0, 25, 10, 40);
		AddSpell(ASHTONGUE_BATTLELORD_ENRAGE, Target_Self, 4, 0, 50);
	}
};

#define CN_ASHTONGUE_DEFENDER					23216
#define ASHTONGUE_DEFENDER_DEBILITATING_STRIKE	41178
#define ASHTONGUE_DEFENDER_SHIELD_BASH			41180

class AshtongueDefenderAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueDefenderAI, MoonScriptCreatureAI);
	AshtongueDefenderAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_DEFENDER_DEBILITATING_STRIKE, Target_Current, 10, 0, 20, 0, 10);
		AddSpell(ASHTONGUE_DEFENDER_SHIELD_BASH, Target_Current, 7, 0, 25, 0, 10);
	}
};

#define CN_ASHTONGUE_ELEMENTALIST				23523
#define ASHTONGUE_ELEMENTALIST_LIGHTNING_BOLT	42024
#define ASHTONGUE_ELEMENTALIST_RAID_OF_FIRE		42023

class AshtongueElementalistAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueElementalistAI, MoonScriptCreatureAI);
	AshtongueElementalistAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_ELEMENTALIST_LIGHTNING_BOLT, Target_Current, 8, 1, 20, 0, 50);	// Random?
		AddSpell(ASHTONGUE_ELEMENTALIST_RAID_OF_FIRE, Target_RandomDestination, 6, 0, 25);
	}
};
// TO DO: Add Totem AIs
#define CN_ASHTONGUE_MYSTIC						22845
#define ASHTONGUE_MYSTIC_BLOODLUST				41185
#define ASHTONGUE_MYSTIC_CHAIN_HEAL				41114
#define ASHTONGUE_MYSTIC_CYCLONE_TOTEM			39589
#define ASHTONGUE_MYSTIC_FLAME_SHOCK			41115
#define ASHTONGUE_MYSTIC_FROST_SHOCK			41116
#define ASHTONGUE_MYSTIC_SEARING_TOTEM			39588
#define ASHTONGUE_MYSTIC_SUMMON_WINDFURY_TOTEM	39586

class AshtongueMysticAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueMysticAI, MoonScriptCreatureAI);
	AshtongueMysticAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_MYSTIC_BLOODLUST, Target_Self, 5, 0, 45);
		AddSpell(ASHTONGUE_MYSTIC_CHAIN_HEAL, Target_WoundedFriendly, 6, 2.5, 35);
		AddSpell(ASHTONGUE_MYSTIC_CYCLONE_TOTEM, Target_Self, 7, 0, 35);
		AddSpell(ASHTONGUE_MYSTIC_FLAME_SHOCK, Target_Current, 8, 0, 25, 0, 20);
		AddSpell(ASHTONGUE_MYSTIC_FROST_SHOCK, Target_Current, 8, 0, 25, 0, 20);
		AddSpell(ASHTONGUE_MYSTIC_SEARING_TOTEM, Target_Self, 7, 0, 35);
		AddSpell(ASHTONGUE_MYSTIC_SUMMON_WINDFURY_TOTEM, Target_Self, 7, 0, 35);
	}
};

#define CN_ASHTONGUE_PRIMALIST					22847
#define ASHTONGUE_PRIMALIST_MULTISHOT			41187
#define ASHTONGUE_PRIMALIST_SHOOT				41188
#define ASHTONGUE_PRIMALIST_SWEEPING_WING_CLIP	39584
#define ASHTONGUE_PRIMALIST_WYVERN_STRING		41186

class AshtonguePrimalistAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtonguePrimalistAI, MoonScriptCreatureAI);
	AshtonguePrimalistAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_PRIMALIST_MULTISHOT, Target_Current, 8, 0, 40, 0, 30);			// Target_Self - self dmg too (kill == crash)
		AddSpell(ASHTONGUE_PRIMALIST_SHOOT, Target_Current, 80, 0, 1, 0, 30);
		AddSpell(ASHTONGUE_PRIMALIST_SWEEPING_WING_CLIP, Target_Current, 8, 0, 15, 0, 10, true);
		AddSpell(ASHTONGUE_PRIMALIST_WYVERN_STRING, Target_RandomPlayer, 7, 0, 25, 0, 30);
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		if (GetRangeToUnit(pTarget) <= 30.0f)
		{
			SetBehavior(Behavior_Spell);
			SetCanMove(false);
		}
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();

		Unit *pTarget = _unit->GetAIInterface()->GetNextTarget();
		if (pTarget != NULL)
		{
			if (GetRangeToUnit(pTarget) <= 30.0f)
			{
				SetBehavior(Behavior_Spell);
				SetCanMove(false);
			}
		}
	}
};

#define CN_ASHTONGUE_ROGUE					23318
#define ASHTONGUE_ROGUE_DEBILITATING_POISON	41978
#define ASHTONGUE_ROGUE_EVISCERATE			41177

class AshtongueRogueAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueRogueAI, MoonScriptCreatureAI);
	AshtongueRogueAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_ROGUE_DEBILITATING_POISON, Target_Current, 7, 0, 30, 0, 10);
		AddSpell(ASHTONGUE_ROGUE_EVISCERATE, Target_Current, 10, 0, 15, 0, 10);
	}
};

#define CN_ASHTONGUE_SPIRITBINDER			23524
#define ASHTONGUE_SPIRITBINDER_CHAIN_HEAL	42027
#define ASHTONGUE_SPIRITBINDER_SPIRIT_HEAL	42317
#define ASHTONGUE_SPIRITBINDER_SPIRIT_HEAL2	42318
#define ASHTONGUE_SPIRITBINDER_SPIRIT_MEND	42025

class AshtongueSpiritbinderAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueSpiritbinderAI, MoonScriptCreatureAI);
	AshtongueSpiritbinderAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_SPIRITBINDER_CHAIN_HEAL, Target_WoundedFriendly, 7, 1, 25);
		if (_unit->GetMapMgr()->iInstanceMode != MODE_HEROIC)	// Guessed
			AddSpell(ASHTONGUE_SPIRITBINDER_SPIRIT_HEAL, Target_Self, 7, 0, 25);				// Weaker version
		else
			AddSpell(ASHTONGUE_SPIRITBINDER_SPIRIT_HEAL2, Target_Self, 7, 0, 25);				// Stronger version
		AddSpell(ASHTONGUE_SPIRITBINDER_SPIRIT_MEND, Target_WoundedFriendly, 8, 0, 25);
	}
};
// Completely guessed mechanics
#define CN_ASHTONGUE_STALKER					23374
#define ASHTONGUE_STALKER_BLIND					34654
#define ASHTONGUE_STALKER_INSTANT_POISON		41189
#define ASHTONGUE_STALKER_MINDNUMBING_POISON	41190
#define ASHTONGUE_STALKER_STEATH				34189

class AshtongueStalkerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueStalkerAI, MoonScriptCreatureAI);
	AshtongueStalkerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_STALKER_BLIND, Target_RandomPlayer, 7, 1, 25);				// Should be Blind - > Attack Next Target?
		AddSpell(ASHTONGUE_STALKER_INSTANT_POISON, Target_Current, 10, 0, 20, 0, 10);
		AddSpell(ASHTONGUE_STALKER_MINDNUMBING_POISON, Target_RandomPlayer, 8, 0, 20);
		ApplyAura(ASHTONGUE_STALKER_STEATH);
	}

	void OnCombatStart(Unit * pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		SpellDesc *pSpell = FindSpellById(ASHTONGUE_STALKER_BLIND);
		if (pSpell != NULL)
		{
			CastSpellNowNoScheduling(pSpell);
		}
	}

	void OnCombatStop(Unit * pTarget)
	{
		ParentClass::OnCombatStop(pTarget);
		if (IsAlive())
		{
			ApplyAura(ASHTONGUE_STALKER_STEATH);
		}
	}
};

#define CN_ASHTONGUE_STORMCALLER				22846
#define ASHTONGUE_STORMCALLER_CHAIN_LIGHTNING	41183
#define ASHTONGUE_STORMCALLER_LIGHTNING_BOLT	41184
#define ASHTONGUE_STORMCALLER_LIGHTNING_SHIELD	41151

class AshtongueStormcallerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueStormcallerAI, MoonScriptCreatureAI);
	AshtongueStormcallerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ASHTONGUE_STORMCALLER_CHAIN_LIGHTNING, Target_Current, 7, 3, 35, 0, 30);		// Random?
		AddSpell(ASHTONGUE_STORMCALLER_LIGHTNING_BOLT, Target_Current, 10, 2, 20);
		AddSpell(ASHTONGUE_STORMCALLER_LIGHTNING_SHIELD, Target_Self, 10, 0, 50);
	}
};

#define CN_BONECHEWER_BEHEMOTH					23196
#define BONECHEWER_BEHEMOTH_BEHEMOTH_CHARGE		41272
#define BONECHEWER_BEHEMOTH_ENRAGE				8269
#define BONECHEWER_BEHEMOTH_FEL_STOMP			41274
#define BONECHEWER_BEHEMOTH_FIERY_COMET			41277
#define BONECHEWER_BEHEMOTH_METEOR				41276

class BonechewerBehemothAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerBehemothAI, MoonScriptCreatureAI);
	BonechewerBehemothAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_BEHEMOTH_BEHEMOTH_CHARGE, Target_Current, 0, 0, 20);	// Mechanics are like charge on random target?
		AddSpell(BONECHEWER_BEHEMOTH_ENRAGE, Target_Self, 5, 0, 45);
		AddSpell(BONECHEWER_BEHEMOTH_FEL_STOMP, Target_Self, 7, 0, 30);
		AddSpell(BONECHEWER_BEHEMOTH_FIERY_COMET, Target_RandomDestination, 6, 1, 30);
		AddSpell(BONECHEWER_BEHEMOTH_METEOR, Target_RandomDestination, 5, 2, 40);
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		SpellDesc *pCharge = FindSpellById(BONECHEWER_BEHEMOTH_BEHEMOTH_CHARGE);
		if (pCharge != NULL)
		{
			CastSpellNowNoScheduling(pCharge);
		}
	}
};

#define CN_BONECHEWER_BLADE_FURY					23235
#define BONECHEWER_BLADE_FURY_WHIRLWIND				41194
#define BONECHEWER_BLADE_FURY_WHIRLWIND2			41195

class BonechewerBladeFuryAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerBladeFuryAI, MoonScriptCreatureAI);
	BonechewerBladeFuryAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_BLADE_FURY_WHIRLWIND, Target_Self, 7, 8, 40);	// Self / Current ?
	}
};

#define CN_BONECHEWER_BLOOD_PROPHET					23237
#define BONECHEWER_BLOOD_PROPHET_BLOOD_DRAIN		41238
#define BONECHEWER_BLOOD_PROPHET_BLOODBOLT			41229
#define BONECHEWER_BLOOD_PROPHET_ENRAGE				8269
#define BONECHEWER_BLOOD_PROPHET_PROPHECY_OF_BLOOD	41230
#define BONECHEWER_BLOOD_PROPHET_PROPHECY_OF_BLOOD2	41231

class BonechewerBloodProphetAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerBloodProphetAI, MoonScriptCreatureAI);
	BonechewerBloodProphetAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_BLOOD_PROPHET_BLOOD_DRAIN, Target_Current, 6, 5, 30, 0, 20);	// Random?
		AddSpell(BONECHEWER_BLOOD_PROPHET_BLOODBOLT, Target_RandomPlayer, 7, 1.5, 25);
		AddSpell(BONECHEWER_BLOOD_PROPHET_ENRAGE, Target_Self, 5, 0, 50);
		if (_unit->GetMapMgr()->iInstanceMode == MODE_HEROIC)						// Guessed
			AddSpell(BONECHEWER_BLOOD_PROPHET_PROPHECY_OF_BLOOD, Target_RandomPlayer, 10, 0, 30);
		else
			AddSpell(BONECHEWER_BLOOD_PROPHET_PROPHECY_OF_BLOOD2, Target_RandomPlayer, 10, 0, 30);
	}
};

#define CN_BONECHEWER_BRAWLER				23222
#define BONECHEWER_BRAWLER_FRENZY			41254

class BonechewerBrawlerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerBrawlerAI, MoonScriptCreatureAI);
	BonechewerBrawlerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_BRAWLER_FRENZY, Target_Self, 7, 0, 30);
	}
};

#define CN_BONECHEWER_COMBATANT				23239
#define BONECHEWER_COMBATANT_FRENZY			8269

class BonechewerCombatantAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerCombatantAI, MoonScriptCreatureAI);
	BonechewerCombatantAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_COMBATANT_FRENZY, Target_Self, 7, 0, 45);
	}
};

#define CN_BONECHEWER_SHIELD_DISCIPLE				23236
#define BONECHEWER_SHIELD_DISCIPLE_INTERVENE		41198
#define BONECHEWER_SHIELD_DISCIPLE_SHIELD_BASH		41197
#define BONECHEWER_SHIELD_DISCIPLE_SHIELD_WALL		41196
#define BONECHEWER_SHIELD_DISCIPLE_THROW_SHIELD		41213

class BonechewerShieldDiscipleAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerShieldDiscipleAI, MoonScriptCreatureAI);
	BonechewerShieldDiscipleAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_SHIELD_DISCIPLE_INTERVENE, Target_Current, 0, 0, 20);
		AddSpell(BONECHEWER_SHIELD_DISCIPLE_SHIELD_BASH, Target_Current, 8, 0, 25, 0, 10);
		AddSpell(BONECHEWER_SHIELD_DISCIPLE_SHIELD_WALL, Target_Self, 8, 0, 35);
		AddSpell(BONECHEWER_SHIELD_DISCIPLE_THROW_SHIELD, Target_RandomPlayer, 7, 0, 30);	// Current?
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		SpellDesc *pIntervene = FindSpellById(BONECHEWER_SHIELD_DISCIPLE_INTERVENE);
		if (pIntervene != NULL)
		{
			CastSpellNowNoScheduling(pIntervene);
		}
	}
};

#define CN_BONECHEWER_SPECTATOR					23223
#define BONECHEWER_SPECTATOR_CHARGE				36140
#define BONECHEWER_SPECTATOR_CLEAVE				40505
#define BONECHEWER_SPECTATOR_MORTAL_WOUND		25646
#define BONECHEWER_SPECTATOR_STRIKE				13446
#define BONECHEWER_SPECTATOR_SUNDER_ARMOR		13444

class BonechewerSpectatorAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerSpectatorAI, MoonScriptCreatureAI);
	BonechewerSpectatorAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_SPECTATOR_CHARGE, Target_Current, 0, 0, 20);
		AddSpell(BONECHEWER_SPECTATOR_CLEAVE, Target_Current, 10, 0, 25, 0, 10);
		AddSpell(BONECHEWER_SPECTATOR_MORTAL_WOUND, Target_Current, 7, 0, 15, 0, 10);
		AddSpell(BONECHEWER_SPECTATOR_STRIKE, Target_Current, 10, 0, 10, 0, 10);
		AddSpell(BONECHEWER_SPECTATOR_SUNDER_ARMOR, Target_Current, 7, 0, 20, 0, 10);
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		SpellDesc *pCharge = FindSpellById(BONECHEWER_SPECTATOR_CHARGE);
		if (pCharge != NULL)
		{
			CastSpellNowNoScheduling(pCharge);
		}
	}
};

#define CN_BONECHEWER_TASKMASTER				23028
#define BONECHEWER_TASKMASTER_DISGRUNTLED		40851
#define BONECHEWER_TASKMASTER_FURY				40845

class BonechewerTaskmasterAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerTaskmasterAI, MoonScriptCreatureAI);
	BonechewerTaskmasterAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_TASKMASTER_DISGRUNTLED, Target_Self, 0, 0, 45);	//5, 0, 45);	// Disabled for now (buffs players instead of Taskmasters)		
		AddSpell(BONECHEWER_TASKMASTER_FURY, Target_Self, 8, 0, 15);
	}
};

#define CN_BONECHEWER_WORKER					22963
#define BONECHEWER_WORKER_THROW_PICK			40844

class BonechewerWorkerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(BonechewerWorkerAI, MoonScriptCreatureAI);
	BonechewerWorkerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(BONECHEWER_WORKER_THROW_PICK, Target_RandomPlayer, 8, 0.5, 15);	// Current? Also shouldn't be cast once only?
	}
};

#define CN_CHARMING_COURTESAN					22955
#define CHARMING_COURTESAN_INFATUATION			41345
#define CHARMING_COURTESAN_POISONOUS_THROW		41346

class CharmingCourtesanAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(CharmingCourtesanAI, MoonScriptCreatureAI);
	CharmingCourtesanAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(CHARMING_COURTESAN_INFATUATION, Target_RandomPlayer, 7, 20, 40);
		AddSpell(CHARMING_COURTESAN_POISONOUS_THROW, Target_RandomPlayer, 8, 0, 20);
	}
};

#define CN_COILSKAR_GENERAL						22873
#define COILSKAR_GENERAL_BOOMING_VOICE			40080
#define COILSKAR_GENERAL_FREE_FRIEND			40081

class CoilskarGeneralAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(CoilskarGeneralAI, MoonScriptCreatureAI);
	CoilskarGeneralAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(COILSKAR_GENERAL_BOOMING_VOICE, Target_Self, 7, 0, 35);
		AddSpell(COILSKAR_GENERAL_FREE_FRIEND, Target_RandomFriendly, 7, 0, 20);	// SpellFunc to check incapacitating effects?
	}
};
// Is it Ranged unit throwing spears all the time?
#define CN_COILSKAR_HARPOONER					22874
#define COILSKAR_HARPOONER_HARPOONERS_MARK		40084
#define COILSKAR_HARPOONER_HOOKED_NET			40082
#define COILSKAR_HARPOONER_SPEAR_THROW			40083

class CoilskarHarpoonerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(CoilskarHarpoonerAI, MoonScriptCreatureAI);
	CoilskarHarpoonerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(COILSKAR_HARPOONER_HARPOONERS_MARK, Target_RandomPlayer, 7, 0, 35);		// I must link Dragon Turtle with Harpooner before scripting it
		AddSpell(COILSKAR_HARPOONER_HOOKED_NET, Target_RandomPlayer, 7, 0.5, 25);
		AddSpell(COILSKAR_HARPOONER_SPEAR_THROW, Target_Current, 8, 0, 15, 0, 40);			// Random? Also isn't it typical ranged unit? (using Spear Throw instead of Shoot/Shot spell?)
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		SpellDesc *pMark = FindSpellById(COILSKAR_HARPOONER_HARPOONERS_MARK);
		if (pMark != NULL)
		{
			CastSpellNowNoScheduling(pMark);
		}
	}
};

#define CN_COILSKAR_SEACALLER					22875
#define COILSKAR_SEACALLER_FORKED_LIGHTNING		40088
#define COILSKAR_SEACALLER_HURRICANE			40090
#define COILSKAR_SEACALLER_SUMMON_GEYSER		40091

class CoilskarSeacallerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(CoilskarSeacallerAI, MoonScriptCreatureAI);
	CoilskarSeacallerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(COILSKAR_SEACALLER_FORKED_LIGHTNING, Target_Self, 8, 2, 20);
		AddSpell(COILSKAR_SEACALLER_HURRICANE, Target_RandomDestination, 8, 20, 35);
		AddSpell(COILSKAR_SEACALLER_SUMMON_GEYSER, Target_RandomPlayer, 7, 2, 25);			// Npc to add to DB + AI
	}
};

#define CN_COILSKAR_SOOTHSAYER					22876
#define COILSKAR_SOOTHSAYER_HOLY_NOVA			40096
#define COILSKAR_SOOTHSAYER_RESTORATION			40097

class CoilskarSoothsayerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(CoilskarSoothsayerAI, MoonScriptCreatureAI);
	CoilskarSoothsayerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(COILSKAR_SOOTHSAYER_HOLY_NOVA, Target_Self, 10, 0, 20);
		AddSpell(COILSKAR_SOOTHSAYER_RESTORATION, Target_WoundedFriendly, 8, 1.5, 35);
	}
};

#define CN_COILSKAR_WRANGLER					22877
#define COILSKAR_WRANGLER_CLEAVE				15284
#define COILSKAR_WRANGLER_ELECTRIC_SPUR			40076
#define COILSKAR_WRANGLER_LIGHTNING_PROD		40066

class CoilskarWranglerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(CoilskarWranglerAI, MoonScriptCreatureAI);
	CoilskarWranglerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(COILSKAR_WRANGLER_CLEAVE, Target_Current, 10, 0, 20, 0, 10);
		AddSpell(COILSKAR_WRANGLER_ELECTRIC_SPUR, Target_Self, 8, 3, 45);					// Should fraize Leviathan, but it does not (core? or script? :<)
		AddSpell(COILSKAR_WRANGLER_LIGHTNING_PROD, Target_RandomPlayer, 8, 3, 25);
	}
};

#define CN_DRAGONMAW_SKY_STALKER				23030
#define DRAGONMAW_SKY_STALKER_IMMOLATION_ARROW	40872
#define DRAGONMAW_SKY_STALKER_SHOOT				40873

class DragonmawSkyStalkerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(DragonmawSkyStalkerAI, MoonScriptCreatureAI);
	DragonmawSkyStalkerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(DRAGONMAW_SKY_STALKER_IMMOLATION_ARROW, Target_Current, 8, 2, 15, 0, 40);
		AddSpell(DRAGONMAW_SKY_STALKER_SHOOT, Target_Current, 75, 0, 1, 0, 40);
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		if (GetRangeToUnit(pTarget) <= 40.0f)
		{
			SetBehavior(Behavior_Spell);
			SetCanMove(false);
		}
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();

		Unit *pTarget = _unit->GetAIInterface()->GetNextTarget();
		if (pTarget != NULL)
		{
			if (GetRangeToUnit(pTarget) <= 40.0f)
			{
				SetBehavior(Behavior_Spell);
				SetCanMove(false);
			}
		}
	}
};
// Should it run away from tank when he's close?
#define CN_DRAGONMAW_WIND_REAVER					23330
#define DRAGONMAW_WIND_REAVER_DOOM_BOLT				40876
#define DRAGONMAW_WIND_REAVER_FIREBALL				40877
#define DRAGONMAW_WIND_REAVER_FREEZE				40875

class DragonmawWindReaverAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(DragonmawWindReaverAI, MoonScriptCreatureAI);
	DragonmawWindReaverAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(DRAGONMAW_WIND_REAVER_DOOM_BOLT, Target_Current, 10, 1.5, 15, 0, 40);
		AddSpell(DRAGONMAW_WIND_REAVER_FIREBALL, Target_Current, 75, 2, 0, 0, 40);
		AddSpell(DRAGONMAW_WIND_REAVER_FREEZE, Target_RandomPlayer, 10, 2, 15);
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		if (GetRangeToUnit(pTarget) <= 40.0f)
		{
			SetBehavior(Behavior_Spell);
			SetCanMove(false);
		}
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();

		Unit *pTarget = _unit->GetAIInterface()->GetNextTarget();
		if (pTarget != NULL)
		{
			if (GetRangeToUnit(pTarget) <= 40.0f)
			{
				SetBehavior(Behavior_Spell);
				SetCanMove(false);
			}
		}
	}
};

#define CN_DRAGONMAW_WYRMCALLER					22960
#define DRAGONMAW_WYRMCALLER_CLEAVE				15284
#define DRAGONMAW_WYRMCALLER_FIXATE				40892
#define DRAGONMAW_WYRMCALLER_JAB				40895

class DragonmawWyrmcallerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(DragonmawWyrmcallerAI, MoonScriptCreatureAI);
	DragonmawWyrmcallerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(DRAGONMAW_WYRMCALLER_CLEAVE, Target_Current, 10, 0, 15, 0, 10);
		AddSpell(DRAGONMAW_WYRMCALLER_FIXATE, Target_RandomUnit, 7, 0, 20);
		AddSpell(DRAGONMAW_WYRMCALLER_JAB, Target_Current, 8, 0, 25, 0, 10);
	}
};

#define CN_ENSLAVED_SERVANT						22965
#define ENSLAVED_SERVANT_KIDNEY_SHOT			41389
#define ENSLAVED_SERVANT_UPPERCUT				41388

class EnslavedServantAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(EnslavedServantAI, MoonScriptCreatureAI);
	EnslavedServantAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ENSLAVED_SERVANT_KIDNEY_SHOT, Target_Current, 7, 0, 25, 0, 10);
		AddSpell(ENSLAVED_SERVANT_UPPERCUT, Target_RandomUnit, 8, 0, 20);

		mHealthResetTimer = -1;
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		mHealthResetTimer = AddTimer(45000);	// to check
	}

	void AIUpdate()
	{
		if (IsTimerFinished(mHealthResetTimer))
		{
			_unit->SetUInt32Value(UNIT_FIELD_HEALTH, _unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH));	// Found such note about this mob
			ResetTimer(mHealthResetTimer, 45000);
		}

		ParentClass::AIUpdate();
	}

	int32	mHealthResetTimer;
};

#define CN_HAND_OF_GOREFIEND				23172
#define HAND_OF_GOREFIEND_FRENZY			38166

class HandOfGorefiendAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(HandOfGorefiendAI, MoonScriptCreatureAI);
	HandOfGorefiendAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(HAND_OF_GOREFIEND_FRENZY, Target_Self, 6, 0, 45);
	}
};
// Mechanics are guessed. I'm also not sure if it's not typical caster unit
#define CN_ILLIDARI_ARCHON					23400
#define ILLIDARI_ARCHON_HEAL				41372
#define ILLIDARI_ARCHON_HOLY_SMITE			41370
#define ILLIDARI_ARCHON_MIND_BLAST			41374
#define ILLIDARI_ARCHON_POWER_WORD_SHIELD	41373
#define ILLIDARI_ARCHON_SHADOW_WORD_DEATH	41375
#define ILLIDARI_ARCHON_SHADOWFORM			29406

class IllidariArchonAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariArchonAI, MoonScriptCreatureAI);
	IllidariArchonAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		mIsShadowPriest = false;
		switch (RandomUInt(1))
		{
		case 0:
			AddSpell(ILLIDARI_ARCHON_HEAL, Target_WoundedFriendly, 5, 2, 30);
			AddSpell(ILLIDARI_ARCHON_HOLY_SMITE, Target_Current, 8, 2.5, 25, 0, 40);
			AddSpell(ILLIDARI_ARCHON_POWER_WORD_SHIELD, Target_Self, 7, 0, 35);
			break;
		case 1:
			AddSpell(ILLIDARI_ARCHON_MIND_BLAST, Target_Current, 8, 1.5, 25, 0, 30);
			AddSpell(ILLIDARI_ARCHON_SHADOW_WORD_DEATH, Target_RandomPlayer, 7, 0, 35);
			ApplyAura(ILLIDARI_ARCHON_SHADOWFORM);
			mIsShadowPriest = true;
			break;
		}
	}

	void OnCombatStop(Unit *pTarget)
	{
		ParentClass::OnCombatStop(pTarget);
		if (mIsShadowPriest && IsAlive())
		{
			ApplyAura(ILLIDARI_ARCHON_SHADOWFORM);
		}
	}

	void AIUpdate()
	{
		SpellDesc *pDeath = FindSpellById(ILLIDARI_ARCHON_SHADOW_WORD_DEATH);
		if (mIsShadowPriest && _unit->GetUInt32Value(UNIT_FIELD_HEALTH) <= 2500 && pDeath->mEnabled)
		{
			Spell *pCurrentSpell = _unit->GetCurrentSpell();
			if (pCurrentSpell != NULL && pCurrentSpell->pSpellId == pDeath->mInfo->Id)
			{
				pCurrentSpell->cancel();
			}
			for (SpellDescList::iterator itr = mQueuedSpells.begin(); itr != mQueuedSpells.end(); ++itr)
			{
				if ((*itr)->mInfo->Id == pDeath->mInfo->Id)
					mQueuedSpells.erase(itr);
			}
			for (SpellDescList::iterator itr = mScheduledSpells.begin(); itr != mScheduledSpells.end(); ++itr)
			{
				if ((*itr)->mInfo->Id == pDeath->mInfo->Id)
					mScheduledSpells.erase(itr);
			}

			pDeath->mEnabled = false;
		}

		ParentClass::AIUpdate();
	}

	bool	mIsShadowPriest;
};
// Couldn't find mechanics nowhere around the net, so kept it simple
#define CN_ILLIDARI_ASSASSIN				23403
#define ILLIDARI_ASSASSIN_PARALYZING_POISON	3609
#define ILLIDARI_ASSASSIN_VANISH			39667

class IllidariAssassinAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariAssassinAI, MoonScriptCreatureAI);
	IllidariAssassinAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ILLIDARI_ASSASSIN_PARALYZING_POISON, Target_Current, 8, 0, 25, 0, 10);
		AddSpell(ILLIDARI_ASSASSIN_VANISH, Target_Self, 7, 1, 30);
	}

	void AIUpdate()
	{
		if (_unit->HasAura(ILLIDARI_ASSASSIN_VANISH))
		{
			DelayNextAttack(1500);
		}

		ParentClass::AIUpdate();
	}
};
// I've parted it on frost and fire mage - correct me if it's wrong (also slap me if it's typical caster)
#define CN_ILLIDARI_BATTLEMAGE					23402
#define ILLIDARI_BATTLEMAGE_BLIZZARD			41382
#define ILLIDARI_BATTLEMAGE_FIREBALL			41383
#define ILLIDARI_BATTLEMAGE_FLAMESTRIKE			41379
#define ILLIDARI_BATTLEMAGE_FROSTBOLT			41384

class IllidariBattlemageAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariBattlemageAI, MoonScriptCreatureAI);
	IllidariBattlemageAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		switch (RandomUInt(1))
		{
		case 0:
			AddSpell(ILLIDARI_BATTLEMAGE_BLIZZARD, Target_RandomDestination, 8, 8, 35);
			AddSpell(ILLIDARI_BATTLEMAGE_FROSTBOLT, Target_Current, 15, 0, 10, 0, 40);
			break;
		case 1:
			AddSpell(ILLIDARI_BATTLEMAGE_FIREBALL, Target_Current, 15, 0, 10, 0, 40);
			AddSpell(ILLIDARI_BATTLEMAGE_FLAMESTRIKE, Target_RandomDestination, 8, 0, 40);
			break;
		}
	}
};

#define CN_ILLIDARI_BLOOD_LORD						23397
#define ILLIDARI_BLOOD_LORD_DIVINE_SHIELD			41367
#define ILLIDARI_BLOOD_LORD_HAMMER_OF_JUSTICE		13005
#define ILLIDARI_BLOOD_LORD_JUDGEMENT_OF_COMMAND	41368

class IllidariBloodLordAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(IllidariBloodLordAI, MoonScriptCreatureAI);
	IllidariBloodLordAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ILLIDARI_BLOOD_LORD_DIVINE_SHIELD, Target_Self, 8, 0, 30);
		AddSpell(ILLIDARI_BLOOD_LORD_HAMMER_OF_JUSTICE, Target_Current, 9, 0, 20, 0, 10);
		AddSpell(ILLIDARI_BLOOD_LORD_JUDGEMENT_OF_COMMAND, Target_Current, 8, 0, 25, 0, 10);
	}
};
// Should be summoned by Priestess of Dementia
#define CN_IMAGE_OF_DEMENTIA						23436
#define IMAGE_OF_DEMENTIA_WHRILWIND					41399
#define IMAGE_OF_DEMENTIA_WHIRLWIND2				41400

void SpellFunc_Whirlwind(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType);

class ImageOfDementiaAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ImageOfDementiaAI, MoonScriptCreatureAI);
	ImageOfDementiaAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		mWhirlwind = AddSpell(IMAGE_OF_DEMENTIA_WHRILWIND, Target_Self, 0, 15, 0);
		AddSpellFunc(&SpellFunc_Whirlwind, Target_Self, 15, 15, 35, 0, 10);
	}

	SpellDesc*	mWhirlwind;
};

void SpellFunc_Whirlwind(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType)
{
	ImageOfDementiaAI *Dementia = (pCreatureAI != NULL) ? (ImageOfDementiaAI*)pCreatureAI : NULL;
	if (Dementia != NULL)
	{
		Dementia->CastSpell(Dementia->mWhirlwind);
		Dementia->Despawn(25000);
	}
}

#define CN_SHADOWMOON_BLOOD_MAGE					22945
#define SHADOWMOON_BLOOD_MAGE_BLOOD_SIPHON			41068
#define SHADOWMOON_BLOOD_MAGE_BLOOD_BOLT			41072

class ShadowmoonBloodMageAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonBloodMageAI, MoonScriptCreatureAI);
	ShadowmoonBloodMageAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWMOON_BLOOD_MAGE_BLOOD_SIPHON, Target_Self, 8, 0, 35);
		AddSpell(SHADOWMOON_BLOOD_MAGE_BLOOD_BOLT, Target_RandomPlayer, 9, 3, 25);
	}
};

#define CN_SHADOWMOON_CHAMPION						22880
#define SHADOWMOON_CHAMPION_CHAOTIC_LIGHT			41063
#define SHADOWMOON_CHAMPION_WHIRLING_BLADE			41053

class ShadowmoonChampionAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonChampionAI, MoonScriptCreatureAI);
	ShadowmoonChampionAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWMOON_CHAMPION_CHAOTIC_LIGHT, Target_Current, 8, 0, 25, 0, 10);
		AddSpell(SHADOWMOON_CHAMPION_WHIRLING_BLADE, Target_RandomPlayer, 8, 1, 30);	// I must check its mechanics
	}
};

#define CN_SHADOWMOON_DEATHSHAPER					22882
#define SHADOWMOON_DEATHSHAPER_DEATH_COIL			41070
#define SHADOWMOON_DEATHSHAPER_DEMON_ARMOR			13787
#define SHADOWMOON_DEATHSHAPER_RAISE_DEAD			41071
#define SHADOWMOON_DEATHSHAPER_SHADOW_BOLT			41069

void SpellFunc_RaiseDead(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType);

class ShadowmoonDeathshaperAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonDeathshaperAI, MoonScriptCreatureAI);
	ShadowmoonDeathshaperAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWMOON_DEATHSHAPER_DEATH_COIL, Target_RandomPlayer, 7, 0, 30);
		AddSpell(SHADOWMOON_DEATHSHAPER_DEMON_ARMOR, Target_Self, 8, 0, 60);
		mRaiseDead = AddSpell(SHADOWMOON_DEATHSHAPER_RAISE_DEAD, Target_Self, 0, 1.5, 0);
		AddSpellFunc(&SpellFunc_RaiseDead, Target_RandomCorpse, 12, 1.5, 30);
		AddSpell(SHADOWMOON_DEATHSHAPER_SHADOW_BOLT, Target_Current, 75, 3, 0, 0, 40);	// Typical caster? Slap me if not...

		_unit->SetUInt32Value(UNIT_FIELD_POWER1, 100000);	// temporary way to set up mana of this unit
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		if (GetRangeToUnit(pTarget) <= 40.0f)
		{
			SetBehavior(Behavior_Spell);
			SetCanMove(false);
		}
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();

		Unit *pTarget = _unit->GetAIInterface()->GetNextTarget();
		if (pTarget != NULL)
		{
			if (GetRangeToUnit(pTarget) <= 40.0f)
			{
				SetBehavior(Behavior_Spell);
				SetCanMove(false);
			}
		}
	}

	SpellDesc*	mRaiseDead;
};

void SpellFunc_RaiseDead(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType)
{
	ShadowmoonDeathshaperAI *pDeathshaper = (pCreatureAI != NULL) ? (ShadowmoonDeathshaperAI*)pCreatureAI : NULL;
	if (pDeathshaper != NULL)
	{
		pDeathshaper->CastSpell(pDeathshaper->mRaiseDead);
		MoonScriptCreatureAI *pAI = pDeathshaper->SpawnCreature(23371, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), pTarget->GetOrientation());
		if (pAI != NULL)
		{
			pAI->GetUnit()->GetAIInterface()->StopMovement(2500);
			pAI->DelayNextAttack(2500);
		}

		static_cast<Creature*>(pTarget)->Despawn(3000, 0);
	}
}
// No entry in my DB, but AI may stay :)
#define CN_SHADOWMOON_FALLEN					23371

class ShadowmoonFallenAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonFallenAI, MoonScriptCreatureAI);
	ShadowmoonFallenAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AggroNearestPlayer(200);
	}
};

#define CN_SHADOWMOON_HOUNDMASTER						23018
#define SHADOWMOON_HOUNDMASTER_FLARE					41094
#define SHADOWMOON_HOUNDMASTER_FREEZING_TRAP			41085
#define SHADOWMOON_HOUNDMASTER_SHOOT					41093
#define SHADOWMOON_HOUNDMASTER_SILENCING_SHOT			41084
#define SHADOWMOON_HOUNDMASTER_SUMMON_RIDING_WARHOUND	39906
#define SHADOWMOON_HOUNDMASTER_VOLLEY					41091
#define SHADOWMOON_HOUNDMASTER_WING_CLIP				32908

class ShadowmoonHoundmasterAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonHoundmasterAI, MoonScriptCreatureAI);
	ShadowmoonHoundmasterAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWMOON_HOUNDMASTER_FLARE, Target_RandomDestination, 5, 0, 30);
		AddSpell(SHADOWMOON_HOUNDMASTER_FREEZING_TRAP, Target_Self, 5, 0, 30);
		AddSpell(SHADOWMOON_HOUNDMASTER_SHOOT, Target_Current, 70, 0, 1, 0, 30);
		AddSpell(SHADOWMOON_HOUNDMASTER_SILENCING_SHOT, Target_RandomPlayer, 6, 0, 35);
		AddSpell(SHADOWMOON_HOUNDMASTER_SUMMON_RIDING_WARHOUND, Target_Self, 5, 0, 45);
		AddSpell(SHADOWMOON_HOUNDMASTER_VOLLEY, Target_RandomDestination, 5, 1, 25);
		AddSpell(SHADOWMOON_HOUNDMASTER_WING_CLIP, Target_Current, 5, 0, 20, 0, 10, true);
	}

	void OnCombatStart(Unit *pTarget)
	{
		ParentClass::OnCombatStart(pTarget);
		if (GetRangeToUnit(pTarget) <= 30.0f)
		{
			SetBehavior(Behavior_Spell);
			SetCanMove(false);
		}
	}

	void AIUpdate()
	{
		ParentClass::AIUpdate();
		Unit *pTarget = _unit->GetAIInterface()->GetNextTarget();
		if (pTarget != NULL)
		{
			if (GetRangeToUnit(pTarget) <= 30.0f)
			{
				SetBehavior(Behavior_Spell);
				SetCanMove(false);
			}
		}
	}
};

#define CN_SHADOWMOON_REAVER					22879
#define SHADOWMOON_REAVER_SPELL_ABSORPTION		41034

class ShadowmoonReaverAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonReaverAI, MoonScriptCreatureAI);
	ShadowmoonReaverAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWMOON_REAVER_SPELL_ABSORPTION, Target_Self, 8, 0, 35);
	}
};

#define CN_SHADOWMOON_SOLDIER					23047
#define SHADOWMOON_SOLDIER_STRIKE				11976

class ShadowmoonSoldierAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonSoldierAI, MoonScriptCreatureAI);
	ShadowmoonSoldierAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWMOON_SOLDIER_STRIKE, Target_Current, 10, 0, 15, 0, 10);
	}
};
// Haven't found informations about Shield Wall ability
#define CN_SHADOWMOON_WEAPON_MASTER					23049
#define SHADOWMOON_WEAPON_MASTER_BATTLE_AURA		41106
#define SHADOWMOON_WEAPON_MASTER_BATTLE_STANCE		41099
#define SHADOWMOON_WEAPON_MASTER_BERSEKER_AURA		41107
#define SHADOWMOON_WEAPON_MASTER_BERSERKER_STANCE	41100
#define SHADOWMOON_WEAPON_MASTER_DEFENSIVE_AURA		41105
#define SHADOWMOON_WEAPON_MASTER_DEFENSIVE_STANCE	41101
#define SHADOWMOON_WEAPON_MASTER_KNOCK_AWAY			18813
#define SHADOWMOON_WEAPON_MASTER_MUTILATE			41103
#define SHADOWMOON_WEAPON_MASTER_WHIRLWIND			41097
#define SHADOWMOON_WEAPON_MASTER_WHIRLWIND2			41098
#define SHADOWMOON_WEAPON_MASTER_SHIELD_WALL		41104	// guessed, but close Id :)

void SpellFunc_DefensiveStance(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType);
void SpellFunc_BerserkerStance(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType);

class ShadowmoonWeaponMasterAI : public MoonScriptBossAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowmoonWeaponMasterAI, MoonScriptBossAI);
	ShadowmoonWeaponMasterAI(Creature *pCreature) : MoonScriptBossAI(pCreature)
	{
		AddPhaseSpell(1, AddSpell(SHADOWMOON_WEAPON_MASTER_KNOCK_AWAY, Target_Current, 9, 0, 25, 0, 10));
		AddPhaseSpell(1, AddSpell(SHADOWMOON_WEAPON_MASTER_MUTILATE, Target_Current, 8, 0, 30, 0, 10));
		AddPhaseSpell(2, AddSpell(SHADOWMOON_WEAPON_MASTER_KNOCK_AWAY, Target_Current, 9, 0, 25, 0, 10));
		AddPhaseSpell(2, AddSpell(SHADOWMOON_WEAPON_MASTER_SHIELD_WALL, Target_Self, 10, 0, 35));
		AddPhaseSpell(3, AddSpell(SHADOWMOON_WEAPON_MASTER_KNOCK_AWAY, Target_Current, 9, 0, 25, 0, 10));
		AddPhaseSpell(3, AddSpell(SHADOWMOON_WEAPON_MASTER_WHIRLWIND, Target_Self, 10, 15, 35));
		AddPhaseSpell(3, AddSpell(SHADOWMOON_WEAPON_MASTER_MUTILATE, Target_Current, 8, 0, 30, 0, 10));
		mDefensiveStance = AddSpellFunc(&SpellFunc_DefensiveStance, Target_Self, 0, 0, 0);
		mBerserkerStance = AddSpellFunc(&SpellFunc_BerserkerStance, Target_Self, 0, 0, 0);
		//SetDisplayWeaponIds(0, 0, 0, 0, 0, 0)	// Sword
		ApplyAura(SHADOWMOON_WEAPON_MASTER_BATTLE_STANCE);
		ApplyAura(SHADOWMOON_WEAPON_MASTER_BATTLE_AURA);
	}

	void OnCombatStop(Unit *pTarget)
	{
		ParentClass::OnCombatStop(pTarget);

		if (IsAlive())
		{
			RemoveAura(SHADOWMOON_WEAPON_MASTER_DEFENSIVE_AURA);
			RemoveAura(SHADOWMOON_WEAPON_MASTER_BERSEKER_AURA);
			//SetDisplayWeaponIds(0, 0, 0, 0, 0, 0)	// Sword
			ApplyAura(SHADOWMOON_WEAPON_MASTER_BATTLE_STANCE);
			ApplyAura(SHADOWMOON_WEAPON_MASTER_BATTLE_AURA);
		}
	}

	void AIUpdate()
	{
		if (GetPhase() == 1 && GetHealthPercent() <= 85)
		{
			SetPhase(2, mDefensiveStance);
			return;
		}
		if (GetPhase() == 2 && GetHealthPercent() <= 35)
		{
			SetPhase(3, mBerserkerStance);
			return;
		}

		ParentClass::AIUpdate();
	}

	SpellDesc*	mDefensiveStance;
	SpellDesc*	mBerserkerStance;
};

void SpellFunc_DefensiveStance(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType)
{
	ShadowmoonWeaponMasterAI *pWeaponMaster = (pCreatureAI != NULL) ? (ShadowmoonWeaponMasterAI*)pCreatureAI : NULL;
	if (pWeaponMaster != NULL)
	{
		pWeaponMaster->RemoveAura(SHADOWMOON_WEAPON_MASTER_BATTLE_AURA);
		//SetDisplayWeaponIds(0, 0, 0, 0, 0, 0)	// Axe + Shield
		pWeaponMaster->ApplyAura(SHADOWMOON_WEAPON_MASTER_DEFENSIVE_STANCE);
		pWeaponMaster->ApplyAura(SHADOWMOON_WEAPON_MASTER_DEFENSIVE_AURA);
	}
}

void SpellFunc_BerserkerStance(SpellDesc *pThis, MoonScriptCreatureAI *pCreatureAI, Unit *pTarget, TargetType pType)
{
	ShadowmoonWeaponMasterAI *pWeaponMaster = (pCreatureAI != NULL) ? (ShadowmoonWeaponMasterAI*)pCreatureAI : NULL;
	if (pWeaponMaster != NULL)
	{
		pWeaponMaster->RemoveAura(SHADOWMOON_WEAPON_MASTER_DEFENSIVE_AURA);
		//SetDisplayWeaponIds(0, 0, 0, 0, 0, 0)	// Sword
		pWeaponMaster->ApplyAura(SHADOWMOON_WEAPON_MASTER_BERSERKER_STANCE);
		pWeaponMaster->ApplyAura(SHADOWMOON_WEAPON_MASTER_BERSEKER_AURA);
		pWeaponMaster->Emote("Berserker stance! Attack them recklessly!", Text_Say, 0);
	}
}

#define CN_SPELLBOUND_ATTENDANT						22959
#define SPELLBOUND_ATTENDANT_KICK					41395
#define SPELLBOUND_ATTENDANT_SLEEP					41396

class SpellboundAttendantAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(SpellboundAttendantAI, MoonScriptCreatureAI);
	SpellboundAttendantAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SPELLBOUND_ATTENDANT_KICK, Target_Current, 9, 0, 25, 0, 10);
		AddSpell(SPELLBOUND_ATTENDANT_SLEEP, Target_RandomPlayerNotCurrent, 8, 1, 25);
	}
};

#define CN_TEMPLE_CONCUBINE							22939
#define TEMPLE_CONCUBINE_LOVE_TAP					41338
#define TEMPLE_CONCUBINE_POLYMORPH					41334

class TempleConcubineAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(TempleConcubineAI, MoonScriptCreatureAI);
	TempleConcubineAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(TEMPLE_CONCUBINE_LOVE_TAP, Target_Current, 9, 0, 25, 0, 10);
		AddSpell(TEMPLE_CONCUBINE_POLYMORPH, Target_RandomPlayerNotCurrent, 7, 1, 25);
	}
};

//////////////////////////////////////////////////////////////////////////
/////// Elemental AIs

#define CN_STORM_FURY				22848
#define STORM_FURY_STORM_BLINK		39581

void SpellFunc_StormBlink(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType);

class StormFuryAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(StormFuryAI, MoonScriptCreatureAI);
	StormFuryAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		mStormBlink = AddSpell(STORM_FURY_STORM_BLINK, Target_Self, 0, 1, 0);	// Mechanics was guessed
		AddSpellFunc(&SpellFunc_StormBlink, Target_RandomPlayerNotCurrent, 8, 0, 35);
	}

	void AIUpdate()
	{
		if (_unit->HasAura(STORM_FURY_STORM_BLINK))
		{
			DelayNextAttack(2000);
		}

		ParentClass::AIUpdate();
	}

	SpellDesc*	mStormBlink;
};

void SpellFunc_StormBlink(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType)
{
	StormFuryAI *pStormFuryAI = (pCreatureAI != NULL) ? (StormFuryAI*)pCreatureAI : NULL;
	if (pStormFuryAI != NULL)
	{
		Unit *pCurrentTarget = pStormFuryAI->GetUnit()->GetAIInterface()->GetNextTarget();
		if (pCurrentTarget == NULL)
			return;

		if (pTarget == pCurrentTarget)
			return;

		pStormFuryAI->ClearHateList();
		pStormFuryAI->GetUnit()->GetAIInterface()->AttackReaction(pTarget, 500);
		pStormFuryAI->GetUnit()->GetAIInterface()->SetNextTarget(pTarget);
		pStormFuryAI->GetUnit()->GetAIInterface()->RemoveThreatByPtr(pCurrentTarget);
		pStormFuryAI->CastSpell(pStormFuryAI->mStormBlink);
	}
}

#define CN_AQUEOUS_SURGER					22881
#define AQUEOUS_SURGER_POISON_BOLT_VOLLEY	40095

class AqueousSurgerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AqueousSurgerAI, MoonScriptCreatureAI);
	AqueousSurgerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(AQUEOUS_SURGER_POISON_BOLT_VOLLEY, Target_Self, 7, 0, 20);
	}
};

#define CN_AQUEOUS_SPAWN				22883
#define AQUEOUS_SPAWN_MERGE				40106
#define AQUEOUS_SPAWN_SLUDGE_NOVA		40102

class AqueousSpawnAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AqueousSpawnAI, MoonScriptCreatureAI);
	AqueousSpawnAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(AQUEOUS_SPAWN_MERGE, Target_Self, 7, 11, 45);
		AddSpell(AQUEOUS_SPAWN_SLUDGE_NOVA, Target_RandomPlayer, 8, 2.5, 20);
	}
};

#define CN_AQUEOUS_LORD					22878
#define AQUEOUS_LORD_CRASHING_WAVE		40100
#define AQUEOUS_LORD_VILE_SLIME			40099

void SpellFunc_SpawnAqueousSpawn(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType);

class AqueousLordAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AqueousLordAI, MoonScriptCreatureAI);
	AqueousLordAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(AQUEOUS_LORD_CRASHING_WAVE, Target_Self, 8, 0, 35);
		AddSpell(AQUEOUS_LORD_VILE_SLIME, Target_RandomPlayer, 10, 0, 25);
		AddSpellFunc(&SpellFunc_SpawnAqueousSpawn, Target_Self, 10, 0, 30);
	}
};

void SpellFunc_SpawnAqueousSpawn(SpellDesc* pThis, MoonScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType)
{
	AqueousLordAI *pAqueousLordAI = (pCreatureAI != NULL) ? (AqueousLordAI*)pCreatureAI : NULL;
	if (pAqueousLordAI != NULL)
	{
		MoonScriptCreatureAI *pSpawnAI = pAqueousLordAI->SpawnCreature(CN_AQUEOUS_SPAWN);
		if (pSpawnAI != NULL)
		{
			pSpawnAI->AggroRandomUnit(500);
			pSpawnAI->SetDespawnWhenInactive(true);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
/////// Mechanical AIs

#define CN_PROMENADE_SENTINEL				23394
#define PROMENADE_SENTINEL_L5_ARCANE_CHARGE	41360

class PromenadeSentinelAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(PromenadeSentinelAI, MoonScriptCreatureAI);
	PromenadeSentinelAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(PROMENADE_SENTINEL_L5_ARCANE_CHARGE, Target_RandomPlayer, 8, 2.7f, 35);
	}
};

//////////////////////////////////////////////////////////////////////////
/////// Uncategorized AIs

#define CN_ANGERED_SOUL_FRAGMENT			23398
#define ANGERED_SOUL_FRAGMENT_ANGER			41986

class AngeredSoulFragmentAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AngeredSoulFragmentAI, MoonScriptCreatureAI);
	AngeredSoulFragmentAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(ANGERED_SOUL_FRAGMENT_ANGER, Target_Self, 10, 3, 25);
	}
};

#define CN_ASHTONGUE_FERAL_SPIRIT				22849
#define ASHTONGUE_FERAL_SPIRIT_SPIRIT_BOND		39578	// won't be used for now
#define ASHTONGUE_FERAL_SPIRIT_CHARGE_FRENZY	39575	// won't be added for now (can cause crashes - self-kills)

class AshtongueFeralSpiritAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(AshtongueFeralSpiritAI, MoonScriptCreatureAI);
	AshtongueFeralSpiritAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
	}
};

//////////////////////////////////////////////////////////////////////////
/////// Undead AIs
// No NPC in DB - could not check it
#define CN_ENSLAVED_SOUL				23469
#define ENSLAVED_SOUL_SOUL_RELEASE		41542

class EnslavedSoulAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(EnslavedSoulAI, MoonScriptCreatureAI);
	EnslavedSoulAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature) {}

	void OnDied(Unit *mKiller)
	{
		ApplyAura(ENSLAVED_SOUL_SOUL_RELEASE);			// beg core to support OnDied casts
		ParentClass::OnDied(mKiller);
	}
};

#define CN_HUNGERING_SOUL_FRAGMENT					23401
#define HUNGERING_SOUL_FRAGMENT_CONSUMING_STRIKES	41248

class HungeringSoulFragmentAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(HungeringSoulFragmentAI, MoonScriptCreatureAI);
	HungeringSoulFragmentAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		ApplyAura(HUNGERING_SOUL_FRAGMENT_CONSUMING_STRIKES);
	}

	void OnCombatStop(Unit *pTarget)
	{
		ParentClass::OnCombatStop(pTarget);
		if (IsAlive())
		{
			ApplyAura(HUNGERING_SOUL_FRAGMENT_CONSUMING_STRIKES);
		}
	}
};

#define CN_SHADOWY_CONSTRUCT					23111
#define SHADOWY_CONSTRUCT_ATROPHY				40327

class ShadowyConstructAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(ShadowyConstructAI, MoonScriptCreatureAI);
	ShadowyConstructAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWY_CONSTRUCT_ATROPHY, Target_Current, 10, 0, 45, 0, 10);
	}
};

#define CN_SUFFERING_SOUL_FRAGMENT				23999
#define SUFFERING_SOUL_FRAGMENT_SOUL_BLAST		41245

class SufferingSoulFragmentAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(SufferingSoulFragmentAI, MoonScriptCreatureAI);
	SufferingSoulFragmentAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(SUFFERING_SOUL_FRAGMENT_SOUL_BLAST, Target_Self, 8, 2, 30);
	}
};
// Teron Gorefiend transforms random player into it with those abilities, but AI might be handy too (too overpowered?) - cannot check (no npc in DB)
#define CN_VANGEFUL_SPIRIT					23109
#define VANGEFUL_SPIRIT_SPIRIT_CHAINS		40175
#define VANGEFUL_SPIRIT_SPIRIT_LANCE		40157
#define VANGEFUL_SPIRIT_SPIRIT_SHIELD		40322
#define VANGEFUL_SPIRIT_SPIRIT_STRIKE		40325
#define VANGEFUL_SPIRIT_SPIRIT_VOLLEY		40314

class VangefulSpiritAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(VangefulSpiritAI, MoonScriptCreatureAI);
	VangefulSpiritAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(VANGEFUL_SPIRIT_SPIRIT_CHAINS, Target_Self, 8, 0, 25);
		AddSpell(VANGEFUL_SPIRIT_SPIRIT_LANCE, Target_RandomPlayer, 6, 0, 35);	// Current?
		AddSpell(VANGEFUL_SPIRIT_SPIRIT_SHIELD, Target_Self, 6, 0, 50);
		AddSpell(VANGEFUL_SPIRIT_SPIRIT_STRIKE, Target_Current, 9, 0, 15, 0, 10);
		AddSpell(VANGEFUL_SPIRIT_SPIRIT_VOLLEY, Target_Self, 4, 0, 40);
	}
};

#define CN_WRATHBONE_FLAYER				22953
#define WRATHBONE_FLAYER_CLEAVE			15496
#define WRATHBONE_FLAYER_IGNORED		39544

class WrathboneFlayerAI : public MoonScriptCreatureAI
{
	MOONSCRIPT_FACTORY_FUNCTION(WrathboneFlayerAI, MoonScriptCreatureAI);
	WrathboneFlayerAI(Creature *pCreature) : MoonScriptCreatureAI(pCreature)
	{
		AddSpell(WRATHBONE_FLAYER_CLEAVE, Target_Current, 10, 0, 15, 0, 10);
		AddSpell(WRATHBONE_FLAYER_IGNORED, Target_Current, 7, 0, 25, 0, 10);		// Current or random?
	}
};

// Bosses
//----------------------High Warlord Naj'entus--------------------------//

#define CN_NAJENTUS 22887

#define CRASHING_WAVE					40100	// Crashing Wave (2313-2687 Nature damage)
#define NEEDLE_SPINE					39835	// Needle Spine (3188-4312 Damage, AoE of 2375-2625 Aura): Fires a needle spine at an enemy target.
#define NEEDLE_SPINE_EXPLOSION			39968
#define TIDAL_SHIELD					39872	// Tidal Shield : Impervious to normal attack and spells. Regenerating health. Will deal 8500 frost damage to the raid when broken.
#define IMPALING_SPINE					39837
#define NAJENTUS_SPINE_GO				3264	// Campfire so it wont crash Real go is 185584 //Did not find it in any database (including drake's go's), tested with a chair, and it works
// There are also other sounds, but Idk where they should go (mostly specials and enrage - which erange spell is that O_O)
class NajentusAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(NajentusAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

    NajentusAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 4;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(CRASHING_WAVE);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = false;
		spells[0].perctrigger = 10.0f;
		spells[0].attackstoptimer = 1000;
		spells[0].cooldown = 15;

		spells[1].info = dbcSpell.LookupEntry(NEEDLE_SPINE);
		spells[1].targettype = TARGET_RANDOM_SINGLE;
		spells[1].instant = false;
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 2000;
		spells[1].cooldown = 10;
		spells[1].mindist2cast = 0.0f;
		spells[1].maxdist2cast = 60.0f;

		spells[2].info = dbcSpell.LookupEntry(TIDAL_SHIELD);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = false;
		spells[2].perctrigger = 0.0f;
		spells[2].attackstoptimer = 2000;
		spells[2].cooldown = 105;

		spells[3].info = dbcSpell.LookupEntry(IMPALING_SPINE);
		spells[3].targettype = TARGET_RANDOM_SINGLE;
		spells[3].instant = false;
		spells[3].perctrigger = 0.0f;
		spells[3].attackstoptimer = 2000;
		spells[3].cooldown = 20;
		spells[3].mindist2cast = 0.0f;
		spells[3].maxdist2cast = 60.0f;
    }

    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;

		uint32 t = (uint32)time(NULL);
		spells[2].casttime = t + 60;
		spells[3].casttime = t + 20;

		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You will die, in the name of Lady Vashj!");
		_unit->PlaySoundToSet(11450);

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

       RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Lord Illidan will... crush you.");
		_unit->PlaySoundToSet(11459);

		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		switch (RandomUInt(2))
		{
		case 1:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Time for you to go!");
			_unit->PlaySoundToSet(11456);
			break;
		default:
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Your success was short lived!");	// not sure
				_unit->PlaySoundToSet(11455);
			}
		}
	}

	void AIUpdate()
	{	// Disabled till I find way to make it dispellable like on blizz
		uint32 t = (uint32)time(NULL);
		/*if (t > spells[2].casttime)
		{
			_unit->setAttackTimer(spells[2].attackstoptimer, false);

			_unit->CastSpell(_unit, spells[2].info, spells[2].instant);

			spells[2].casttime = t + spells[2].cooldown;
			spells[1].casttime = t + 55;
			spells[3].casttime = t + 65;
			return;
		}*/

		if (t > spells[3].casttime)
		{
			switch (RandomUInt(2))
			{
			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Stick around!");
				_unit->PlaySoundToSet(11451);
				break;
			default:
				{
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I'll deal with you later!"); 
					_unit->PlaySoundToSet(11452);
				}
			}
			_unit->setAttackTimer(spells[3].attackstoptimer, false);

			CastSpellOnRandomTarget(3, spells[3].mindist2cast, spells[3].maxdist2cast, 0, 100);

			spells[3].casttime = t + spells[3].cooldown;
			return;
		}

		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
							//_unit->GetMapMgr()->GetInterface()->SpawnGameObject(NAJENTUS_SPINE_GO , target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.207343, true, 0, 0); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget && RandomTarget == _unit->GetAIInterface()->GetMostHated() && i == 3)
						continue;

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();
		}
	}

protected:

	int nrspells;
};

//------------------------------------
//          -= Supremus =-
//------------------------------------

#define CN_SUPREMUS 22898

//Abilities - Phase 1
#define MOLTEN_FLAME 40253 //Molten Flame: Blue-flamed fire sent along the ground in a straight line toward random players that deals 3325-3675 fire damage every 1 second while stood on. Ability used every 20 seconds.
#define HURTFUL_STRIKE 40126 //33813 //Hurtful Strike: A massive melee ability applied to the second highest on his aggro list. If there are no other melee targets in range, it will be performed on the main tank instead.

//Abilities - Phase 2
//Gaze: Supremus will target a random player and follow that target around for 10 seconds at 90% of normal movement speed. Switches targets after 10 seconds.
#define MOLTEN_PUNCH 40126 //Molten Punch: Once a targeted player is within a 40 yard range, Supremus will do a knockback ability for 5250 damage.
#define VOLCANIC_GAZER 42055 //Volcanic Geyser: Emoting "the ground begins to crack open", Supremus will summon small volcanoes that spit out blue flames for 4163-4837 fire damage in a 15 yard radius.

class SupremusAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(SupremusAI);
    SupremusAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		m_MoltenFlame = m_HurtfulStrike = m_MoltenPunch = m_VolcanicGazer = true;

        infoMoltenFlame = dbcSpell.LookupEntry(MOLTEN_FLAME);
		infoHurtfulStrike = dbcSpell.LookupEntry(HURTFUL_STRIKE);
		infoMoltenPunch =  dbcSpell.LookupEntry(MOLTEN_PUNCH);
		infoVolcanicGazer =  dbcSpell.LookupEntry(VOLCANIC_GAZER);
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Bear witness to the agent of your demise!");	// used when he kills Warden Mellichar
		_unit->PlaySoundToSet(11123);
		timer = 0;
    }

    void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
       RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I am merely one of... infinite multitudes.");
		_unit->PlaySoundToSet(11126);
		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		if (_unit->GetHealthPct() > 0)
		{
			int RandomSpeach;
			RandomSpeach=rand()%2;
			switch (RandomSpeach)
			{
			case 0:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Your fate is written!");	// this one needs verification
				_unit->PlaySoundToSet(11124);
				break;
			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "The chaos I have sown here is but a taste....");
				_unit->PlaySoundToSet(11125);
				break;
			}
		}
    }

    void AIUpdate()
    {	
		switch(m_phase)
        {
        case 1:
            {
                PhaseOne();
            }break;
        case 2:
            {
                PhaseTwo();
            }break;
        default:
            {
                m_phase = 1;
            };
        };
    }
	
	void PhaseOne()
	{
		timer++;

        uint32 val = RandomUInt(1000);

        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())//_unit->getAttackTarget())
        {
			if(m_MoltenFlame)
            {
				_unit->CastSpell(_unit, infoMoltenFlame, false);
                m_MoltenFlame = false;
                return;
            }

			else if(m_HurtfulStrike)
            {
                _unit->CastSpell(_unit, infoHurtfulStrike, false);
                m_HurtfulStrike = false;
                return;
            }

            if(val >= 0 && val <= 500)
            {
                _unit->setAttackTimer(6000, false);//6000
                m_MoltenFlame = true;
            }

            else if(val > 500 && val <= 1000)
            {
                _unit->setAttackTimer(4000, false);//2000
                m_HurtfulStrike = true;
            }
        }
		
		if(timer >= 45)
        {
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "We span the universe, as countless as the stars!");
			_unit->PlaySoundToSet(11131);
			timer = 0;
            m_phase = 2;
		}
	}

	void PhaseTwo()
	{
		timer++;

		uint32 val = RandomUInt(1000);

        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())//_unit->getAttackTarget())
        {
			if(m_MoltenPunch)
            {
				_unit->CastSpell(_unit, infoMoltenPunch, false);
                m_MoltenPunch = false;
                return;
            }

			else if(m_VolcanicGazer)
            {
				//_unit->SendChatMessage(CHAT_MSG_MONSTER_EMOTE, LANG_UNIVERSAL, "The ground begins to crack open");
                _unit->CastSpell(_unit, infoVolcanicGazer, false);
                m_VolcanicGazer = false;
                return;
				
            }

            if(val >= 0 && val <= 500)
            {
                _unit->setAttackTimer(6000, false);//6000
                m_MoltenPunch = true;
            }

            else if(val > 500 && val <= 1000)
            {
                _unit->setAttackTimer(4000, false);//2000
                m_VolcanicGazer = true;
            }
        }

		if(timer >= 45)
        {
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "We span the universe, as countless as the stars!");
			_unit->PlaySoundToSet(11131);
			timer = 0;
            m_phase = 1;
			
		}
	}


protected:
	uint32 timer;
	uint32 m_phase;
	bool m_MoltenFlame, m_HurtfulStrike, m_MoltenPunch, m_VolcanicGazer;
    SpellEntry *infoMoltenFlame, *infoHurtfulStrike,*infoMoltenPunch, *infoVolcanicGazer;
};

//------------------------------------
//    -= Shade Of Akama =-
//------------------------------------
#define CN_SHADE_OF_AKAMA 22841
#define CN_ASHTONGUE_CHANNELER 23421
#define CN_ASHTONGUE_SORCERER 23215

#define CN_ASHTONGUE_DEFENDER 23216
#define DEBILITATING_STRIKE 41178

#define CN_ASHTONGUE_ELEMENTALIST 23523
#define RAIN_OF_FIRE 42023

#define CN_ASHTONGUE_ROGUE 23318
#define DEBILITATING_POISON 41978

#define CN_ASHTONGUE_SPIRITBINDER 23524
#define SPIRIT_MEND 42025
#define CHAIN_HEAL 42027

//-------------------------Gurtogg Bloodboil----------------------------//

#define CN_GURTOGG_BLOODBOIL 22948

// Phase 1
#define BLOODBOIL		42005
#define ACIDIC_WOUND	40481
#define DISORIENT		32752
#define KNOCKBACK		38576

// Phase 2
#define FEL_RAGE1		40604
#define FEL_RAGE2		40594	// 40616 - doesn't work at all
#define ACID_GEYSER		40629

// Spells common for both phases
#define ARCING_SMASH	40599
#define FEL_ACID_BREATH	40595

class GurtoggAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(GurtoggAI);
	SP_AI_Spell spells[9];
	bool m_spellcheck[9];

    GurtoggAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 5;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(ARCING_SMASH);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].perctrigger = 0.0f;
		spells[0].attackstoptimer = 1000;
		spells[0].cooldown = 10;

		spells[1].info = dbcSpell.LookupEntry(FEL_ACID_BREATH);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = true;
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 2000;
		spells[1].cooldown = 15;

		// Phase 1
		spells[2].info = dbcSpell.LookupEntry(BLOODBOIL);
		spells[2].targettype = TARGET_VARIOUS;
		spells[2].instant = true;
		spells[2].perctrigger = 0.0f;
		spells[2].attackstoptimer = 2000;
		spells[2].cooldown = 10;

		// Not sure about this one system of casting
		spells[3].info = dbcSpell.LookupEntry(ACIDIC_WOUND);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].perctrigger = 10.0f;
		spells[3].attackstoptimer = 2000;
		spells[3].cooldown = 15;

		spells[4].info = dbcSpell.LookupEntry(DISORIENT);
		spells[4].targettype = TARGET_ATTACKING;
		spells[4].instant = true;
		spells[4].perctrigger = 7.0f;
		spells[4].attackstoptimer = 2000;
		spells[4].cooldown = 10;

		spells[5].info = dbcSpell.LookupEntry(KNOCKBACK);
		spells[5].targettype = TARGET_ATTACKING;
		spells[5].instant = true;
		spells[5].perctrigger = 0.0f;
		spells[5].attackstoptimer = 2000;
		spells[5].cooldown = 15;

		// Phase 2
		spells[6].info = dbcSpell.LookupEntry(ACID_GEYSER);
		spells[6].targettype = TARGET_DESTINATION;
		spells[6].instant = true;
		spells[6].perctrigger = 0.0f;
		spells[6].attackstoptimer = 2000;
		spells[6].cooldown = 10;

		spells[7].info = dbcSpell.LookupEntry(FEL_RAGE1);
		spells[7].targettype = TARGET_RANDOM_SINGLE;
		spells[7].instant = true;
		spells[7].perctrigger = 0.0f;
		spells[7].attackstoptimer = 2000;
		spells[7].cooldown = 90;
		spells[7].mindist2cast = 0.0f;
		spells[7].maxdist2cast = 60.0f;

		spells[8].info = dbcSpell.LookupEntry(FEL_RAGE2);
		spells[8].targettype = TARGET_RANDOM_SINGLE;
		spells[8].instant = true;
		spells[8].perctrigger = 0.0f;
		spells[8].attackstoptimer = 2000;
		spells[8].cooldown = 90;
		spells[8].mindist2cast = 0.0f;
		spells[8].maxdist2cast = 60.0f;

		LastThreat = 0;
		PhaseTimer = 0;
		Phase = 1;
    }

    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < 9; i++)
		{
			spells[i].casttime = 0;
		}

		spells[2].casttime = (uint32)time(NULL) + 10;

		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Horde will crush you!");
		_unit->PlaySoundToSet(11432);

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));

		PhaseTimer = (uint32)time(NULL) + 60;
		LastThreat = 0;
		Phase = 1;
    }

	void OnCombatStop(Unit *mTarget)
    {
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

		if (_unit->isAlive())
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I'll rip the meat from your bones!");
			_unit->PlaySoundToSet(11437);
		}

		RemoveAIUpdateEvent();

		LastThreat = 0;
		PhaseTimer = 0;
		Phase = 1;
    }

    void OnDied(Unit * mKiller)
    {
		_unit->PlaySoundToSet(11439);

		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		switch (RandomUInt(2))
		{
		case 1:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "More! I want more!");
			_unit->PlaySoundToSet(11434);
			break;
		default:
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Time to feast!");
				_unit->PlaySoundToSet(11433);
			}
		}
	}

	void AIUpdate()
	{
		uint32 t = (uint32)time(NULL);
		if (Phase == 1 && t > PhaseTimer)
		{
			spells[7].casttime = 0;

			PhaseTimer = 0;
			Phase = 2;
		}

		// Phase 1
		if (Phase == 1 && _unit->GetAIInterface()->GetNextTarget() && _unit->GetCurrentSpell() == NULL)
		{
			// Bloodboil
			if (t > spells[2].casttime)
			{
				_unit->setAttackTimer(spells[2].attackstoptimer, false);

				_unit->CastSpell(_unit, spells[2].info, spells[2].instant);

				spells[2].casttime = t + spells[2].cooldown;
				return;
			}

			// Arcing Smash
			if (t > spells[0].casttime)
			{
				_unit->setAttackTimer(spells[0].attackstoptimer, false);

				Unit *target = _unit->GetAIInterface()->GetNextTarget();
				_unit->CastSpell(target, spells[0].info, spells[0].instant);

				spells[0].casttime = t + spells[0].cooldown;
				return;
			}

			// Knockback
			if (t > spells[5].casttime)
			{
				_unit->setAttackTimer(spells[5].attackstoptimer, false);

				Unit *target = _unit->GetAIInterface()->GetNextTarget();
				_unit->CastSpell(target, spells[5].info, spells[5].instant);

				if (_unit->GetAIInterface()->GetSecondHated())
					_unit->GetAIInterface()->SetNextTarget(_unit->GetAIInterface()->GetSecondHated());

				spells[5].casttime = t + spells[5].cooldown;
				return;
			}
		}

		if (Phase == 2 && _unit->GetAIInterface()->GetNextTarget() && _unit->GetCurrentSpell() == NULL)
		{
			uint32 t = (uint32)time(NULL);

			// Fel Rage check
			if (t > spells[7].casttime - 62 && LastThreat != 0)
			{
				Unit *RageTarget = NULL;
				RageTarget = _unit->GetAIInterface()->GetNextTarget();
				if (RageTarget->FindAura(FEL_RAGE1) && RageTarget->FindAura(FEL_RAGE2))
				{
					_unit->GetAIInterface()->RemoveThreatByPtr(RageTarget);
					_unit->GetAIInterface()->AttackReaction(RageTarget, LastThreat, 0);

					LastThreat = 0;
				}
			}

			// Acid Geyser
			if (LastThreat != 0 && RandomUInt(5) == 1 && t > spells[6].casttime)
			{
				Unit *RageTarget = NULL;
				RageTarget = _unit->GetAIInterface()->GetNextTarget();
				if (RageTarget->FindAura(FEL_RAGE1) || RageTarget->FindAura(FEL_RAGE2))
				{
					_unit->setAttackTimer(spells[6].attackstoptimer, false);

					_unit->CastSpellAoF(RageTarget->GetPositionX(),RageTarget->GetPositionY(),RageTarget->GetPositionZ(), spells[6].info, spells[6].instant);

					spells[6].casttime = t + spells[6].cooldown;
					return;
				}
			}

			// Arcing Smash
			if (t > spells[0].casttime)
			{
				_unit->setAttackTimer(spells[0].attackstoptimer, false);

				Unit *target = _unit->GetAIInterface()->GetNextTarget();
				_unit->CastSpell(target, spells[0].info, spells[0].instant);

				spells[0].casttime = t + spells[0].cooldown;
				return;
			}

			// Fel Rage - not sure about system
			if (t > spells[7].casttime)
			{
				_unit->setAttackTimer(spells[7].attackstoptimer, false);

				std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
													/* If anyone wants to use this function, then leave this note!										 */
				for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
				{ 
					if (isHostile(_unit, (*itr)) && (*itr) != _unit && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID())
					{
						Unit* RandomTarget = NULL;
						RandomTarget = (Unit*)(*itr);

						if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= 0.0f && _unit->GetDistance2dSq(RandomTarget) <= 6400.0f && _unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))
						{
							TargetTable.push_back(RandomTarget);
						} 
					} 
				}

				if (!TargetTable.size())
					return;

				size_t RandTarget = rand()%TargetTable.size();

				Unit * RTarget = TargetTable[RandTarget];

				if (!RTarget)
					return;

				_unit->CastSpell(RTarget, spells[7].info, spells[7].instant);
				_unit->CastSpell(_unit, spells[8].info, spells[8].instant);

				LastThreat = _unit->GetAIInterface()->getThreatByPtr(RTarget);

				Unit *Target = _unit->GetAIInterface()->GetMostHated();
				uint32 MostHatedThreat = 0;
				if (Target)	// unneeded, but still safe check :P
				{
					MostHatedThreat = _unit->GetAIInterface()->getThreatByPtr(Target);
				}

				_unit->GetAIInterface()->AttackReaction(RTarget, MostHatedThreat + 100000, 0);

				TargetTable.clear();

				switch (RandomUInt(2))
				{
				case 1:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I'll rip the meat from your bones!");
					_unit->PlaySoundToSet(11438);
					break;
				default:
					{
						_unit->PlaySoundToSet(11437);
					}
				}

				spells[7].casttime = t + spells[7].cooldown;
				spells[6].casttime = t;
				return;
			}
		}

		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if ((i == 3 || i == 4) && Phase != 1)
					continue;

				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();

			if (i == 7 || i == 8)
			{
				//Aura *aura = new Aura(spells[7].info, 30000, _unit, RTarget);
				//if (aura)
				//	RTarget->AddAura(aura);
				RTarget->CastSpell(RTarget, spells[7].info, spells[7].instant);

				LastThreat = _unit->GetAIInterface()->getThreatByPtr(RTarget);
				Unit *Target = _unit->GetAIInterface()->GetNextTarget();
				RTarget->GetAIInterface()->AttackReaction(RTarget, _unit->GetAIInterface()->getThreatByPtr(Target) + 100000, 0);
			}
		}
	}

protected:

	uint32 LastThreat;
	uint32 PhaseTimer;
	uint32 Phase;
	int nrspells;
};

//----------------------------------------------------------------------//
//-------------------------Reliquary of Souls---------------------------//
//-------------------------Scripted by Plexor---------------------------//
//----------------------------------------------------------------------//

//------------------------------------
//    -= Essence of Suffering =-
//------------------------------------
#define CN_ESSENCEOFSUFFERING 23418

#define FIXATE 40414
#define ENRAGE_EOS 28798
#define SOUL_DRAIN 41303
#define AURA_OF_SUFFERING 41292

class EssenceOfSufferingAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(EssenceOfSufferingAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

    EssenceOfSufferingAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		// -- Number of spells to add --
		nrspells = 4;

		// --- Initialization ---
		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}
		// ----------------------
		
		// Create basic info for spells here, and play with it later , fill always the info, targettype and if is instant or not! 

		spells[0].info = dbcSpell.LookupEntry(FIXATE);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 10.0f;
		spells[0].attackstoptimer = 1000; // 1sec

		spells[1].info = dbcSpell.LookupEntry(ENRAGE_EOS);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 2000; // 2sec

		spells[2].info = dbcSpell.LookupEntry(SOUL_DRAIN);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].perctrigger = 5.0f;
		spells[2].attackstoptimer = 2000; // 2sec

		spells[3].info = dbcSpell.LookupEntry(AURA_OF_SUFFERING);
		spells[3].targettype = TARGET_SELF;
		spells[3].instant = true;
		spells[3].perctrigger = 10.0f;
		spells[3].attackstoptimer = 2000; // 2sec
    }

    void OnCombatStart(Unit* mTarget)
    {
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Pain and suffering are all that await you.");
		_unit->PlaySoundToSet(11415);
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
       RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I don't want to go back!");
		_unit->PlaySoundToSet(11420);
		Creature *cre = NULL;
        cre = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23419, 451.936981f, 210.566803f, 96.172195f, 5.576756f, true, false, 0, 0);
		if (cre)
		  cre->GetAIInterface()->setOutOfCombatRange(30000);
		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Look at what you made me do.");
		_unit->PlaySoundToSet(11417);
	}

	void AIUpdate()
	{
		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant);
							break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

protected:
	int nrspells;
};

//------------------------------------
//    -= EssenceOfDesire =-
//------------------------------------
#define CN_ESSENCEOFDESIRE 23419

#define RUNE_SHIELD 41431
#define DEADEN 41410
#define SPIRIT_SHOCK 41426
#define AURA_OF_DESIRE 41350

class EssenceOfDesireAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(EssenceOfDesireAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

    EssenceOfDesireAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		// -- Number of spells to add --
		nrspells = 4;

		// --- Initialization ---
		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}
		// ----------------------
		
		// Create basic info for spells here, and play with it later , fill always the info, targettype and if is instant or not! 

		spells[0].info = dbcSpell.LookupEntry(RUNE_SHIELD);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = false;
		spells[0].perctrigger = 10.0f;
		spells[0].attackstoptimer = 1000; // 1sec

		spells[1].info = dbcSpell.LookupEntry(DEADEN);
		spells[1].targettype = TARGET_ATTACKING;
		spells[1].instant = false;
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 2000; // 2sec

		spells[2].info = dbcSpell.LookupEntry(SPIRIT_SHOCK);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = false;
		spells[2].perctrigger = 5.0f;
		spells[2].attackstoptimer = 2000; // 2sec

		spells[3].info = dbcSpell.LookupEntry(AURA_OF_DESIRE);
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = true;
		spells[3].perctrigger = 10.0f;
		spells[3].attackstoptimer = 2000; // 2sec
    }

    void OnCombatStart(Unit* mTarget)
    {
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You can have anything you desire... for a price.");
		_unit->PlaySoundToSet(11408);
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
       RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I'll be waiting.");
		_unit->PlaySoundToSet(11413);
		_unit->GetMapMgr()->GetInterface()->SpawnCreature(23420, 492.303711f, 166.858704f, 94.477707f, 5.037445f, true, false, 0, 0);
		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Fulfilment is at hand.");
		_unit->PlaySoundToSet(11409);
	}

	void AIUpdate()
	{
		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

protected:
	int nrspells;
};
//------------------------------------
//    -= EssenceOfAnger =-
//------------------------------------
#define CN_ESSENCEOFANGER 23420

#define SEETHE 41520
#define SOUL_SCREAM 41545
#define SPITE 41377
#define AURA_OF_ANGER 41337

class EssenceOfAngerAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(EssenceOfAngerAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

    EssenceOfAngerAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		// -- Number of spells to add --
		nrspells = 4;

		// --- Initialization ---
		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}
		// ----------------------
		
		// Create basic info for spells here, and play with it later , fill always the info, targettype and if is instant or not! 

		spells[0].info = dbcSpell.LookupEntry(SEETHE);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = false;
		spells[0].perctrigger = 10.0f;
		spells[0].attackstoptimer = 1000; // 1sec

		spells[1].info = dbcSpell.LookupEntry(SOUL_SCREAM);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = false;
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 2000; // 2sec

		spells[2].info = dbcSpell.LookupEntry(SPITE);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].perctrigger = 5.0f;
		spells[2].attackstoptimer = 2000; // 2sec

		spells[3].info = dbcSpell.LookupEntry(AURA_OF_ANGER);
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = true;
		spells[3].perctrigger = 10.0f;
		spells[3].attackstoptimer = 2000; // 2sec
    }

    void OnCombatStart(Unit* mTarget)
    {
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Beware - I live.");
		_unit->PlaySoundToSet(11399);
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
       RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I won't be ignored.");
		_unit->PlaySoundToSet(11404);
		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Enough! No more!");
		_unit->PlaySoundToSet(11402);
		_unit->PlaySoundToSet(11401);
	}

	void AIUpdate()
	{
		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

protected:
	int nrspells;
};

//--------------------------Mother Shahraz------------------------------//

#define CN_MOTHER_SHAHRAZ 22947

#define SINFUL_BEAM				40827
#define SINISTER_BEAM			40859
#define VILE_BEAM				40860
#define WICKED_BEAM				40861

#define SABER_LASH				40810	// Should be 40816 but 40816 is not supported by core
#define FATAL_ATTRACTION		41001	// 40869 - needs more scripting
#define MS_ENRAGE				40743	// 40683
// Dunno where "spell" sounds/texts should go
class ShahrazAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(ShahrazAI);
	SP_AI_Spell spells[6];
	bool m_spellcheck[6];

    ShahrazAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 2;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(SABER_LASH);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = true;
		spells[0].perctrigger = 8.0f;
		spells[0].attackstoptimer = 1000;
		spells[0].cooldown = 15;

		spells[1].info = dbcSpell.LookupEntry(FATAL_ATTRACTION);
		spells[1].targettype = TARGET_RANDOM_SINGLE;
		spells[1].instant = true;
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 2000;
		spells[1].cooldown = 15;
		spells[1].mindist2cast = 10.0f;
		spells[1].maxdist2cast = 60.0f;

		spells[2].info = dbcSpell.LookupEntry(SINFUL_BEAM);
		spells[2].targettype = TARGET_RANDOM_SINGLE;
		spells[2].instant = true;
		spells[2].perctrigger = 0.0f;
		spells[2].attackstoptimer = 2000;
		spells[2].cooldown = 9;
		spells[2].mindist2cast = 0.0f;
		spells[2].maxdist2cast = 80.0f;
		
		spells[3].info = dbcSpell.LookupEntry(WICKED_BEAM);
		spells[3].targettype = TARGET_RANDOM_SINGLE;
		spells[3].instant = true;
		spells[3].perctrigger = 0.0f;
		spells[3].attackstoptimer = 2000;
		spells[3].cooldown = 9;
		spells[3].mindist2cast = 0.0f;
		spells[3].maxdist2cast = 80.0f;

		spells[4].info = dbcSpell.LookupEntry(VILE_BEAM);
		spells[4].targettype = TARGET_RANDOM_SINGLE;
		spells[4].instant = true;
		spells[4].perctrigger = 0.0f;
		spells[4].attackstoptimer = 2000;
		spells[4].cooldown = 9;
		spells[4].mindist2cast = 0.0f;
		spells[4].maxdist2cast = 80.0f;

		spells[5].info = dbcSpell.LookupEntry(SINISTER_BEAM);
		spells[5].targettype = TARGET_RANDOM_SINGLE;
		spells[5].instant = true;
		spells[5].perctrigger = 0.0f;
		spells[5].attackstoptimer = 2000;
		spells[5].cooldown = 9;
		spells[5].mindist2cast = 0.0f;
		spells[5].maxdist2cast = 80.0f;

		Enraged = false;
		AuraChange = 0;
		SoundTimer = 0;
    }

    void OnCombatStart(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "So, business... or pleasure?");
		_unit->PlaySoundToSet(11504);

		for (int i = 0; i < 6; i++)
			spells[i].casttime = 0;

		AuraChange = (uint32)time(NULL) + 15;
		Enraged = false;
		SoundTimer = 5;

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

		RemoveAIUpdateEvent();
    }
	
    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I wasn't finished.");
		_unit->PlaySoundToSet(11511);

		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		switch (RandomUInt(2))
		{
		case 1:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "So much for a happy ending.");
			_unit->PlaySoundToSet(11509);
			break;
		default:
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Easy come, easy go.");
				_unit->PlaySoundToSet(11508);
			}
		}
	}

	void AIUpdate()
	{
		SoundTimer++;
		if (_unit->GetAIInterface()->GetIsTaunted() && SoundTimer > 10)
		{
			switch (RandomUInt(3))
			{
			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I'm not impressed.");
				_unit->PlaySoundToSet(11502);
				break;
			case 2:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Enjoying yourselves?");
				_unit->PlaySoundToSet(11503);
				break;
			default:
				{
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You play, you pay.");
					_unit->PlaySoundToSet(11501);
				}
			}

			SoundTimer = 0;
		}

		if (!Enraged && _unit->GetHealthPct() <= 20)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Stop toying with my emotions!");
			_unit->PlaySoundToSet(11510);

			_unit->CastSpell(_unit, MS_ENRAGE, true);

			Enraged = true;
		}

		uint32 t = (uint32)time(NULL);

		// In normal way it is applied to players all around enemy caster =/
		if (t > AuraChange)
		{
			uint32 SpellId = 0;
			switch (RandomUInt(6))
			{
			case 1:
				SpellId = 40891;	// Arcane
				break;
			case 2:
				SpellId = 40882;	// Fire
				break;
			case 3:
				SpellId = 40896;	// Frost
				break;
			case 4:
				SpellId = 40897;	// Holy
				break;
			case 5:
				SpellId = 40883;	// Nature
				break;
			case 6:
				SpellId = 40880;	// Shadow
				break;
			default:
				{
					SpellId = 40880;	// Shadow
				}
			}

			//_unit->CastSpell(_unit, SpellId, true);
			Aura *aura = new Aura();
			if (aura)
			{
				aura->Init(dbcSpell.LookupEntry(SpellId), 15000, _unit, _unit);
				_unit->AddAura(aura);
			}

			AuraChange = t + 15;
		}

		if (t > spells[2].casttime)
		{
			uint32 SpellId = RandomUInt(4) + 1;
			if (SpellId < 2 || SpellId > 5)
				SpellId = 5;

			_unit->setAttackTimer(spells[2].attackstoptimer, false);

			CastSpellOnRandomTarget(SpellId, spells[2].mindist2cast, spells[2].maxdist2cast, 0, 100);

			spells[2].casttime = t + spells[2].cooldown;
			return;
		}

		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();
		}
	}

protected:

	uint32 SoundTimer;
	uint32 AuraChange;
	bool Enraged;
	int nrspells;
};

//-----------------------The Illidari Council---------------------------//

//------------------------------------
//    -=Veras Darkshadow  =-
//------------------------------------
#define CN_VERAS_DARKSHADOW 22952

#define DEADLY_POISON	41485
#define ENVENOM			41487
#define VANISH			41476

class VerasAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(VerasAI);
	SP_AI_Spell spells[3];
	bool m_spellcheck[3];

    VerasAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 1;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(DEADLY_POISON);
		spells[0].targettype = TARGET_RANDOM_SINGLE;
		spells[0].instant = true;
		spells[0].perctrigger = 12.0f;
		spells[0].attackstoptimer = 1000;
		spells[0].cooldown = 10;
		spells[0].mindist2cast = 0.0f;
		spells[0].maxdist2cast = 60.0f;

		spells[1].info = dbcSpell.LookupEntry(ENVENOM);
		spells[1].targettype = TARGET_RANDOM_SINGLE;
		spells[1].instant = true;
		spells[1].perctrigger = 0.0f;
		spells[1].attackstoptimer = 2000;
		spells[1].cooldown = 10;

		spells[2].info = dbcSpell.LookupEntry(VANISH);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = true;
		spells[2].perctrigger = 0.0f;
		spells[2].attackstoptimer = 32000;
		spells[2].cooldown = 85;

		Poisoned = false;
		Vanish = 0;
    }

    void OnCombatStart(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You wish to test me?");
		_unit->PlaySoundToSet(11524);

		for (int i = 0; i < 2; i++)
			spells[i].casttime = 0;

		uint32 t = (uint32)time(NULL);
		spells[2].casttime = t + 55;

		Poisoned = false;
		Vanish = 0;

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

	void OnCombatStop(Unit *mTarget)
    {
		_unit->GetAIInterface()->disable_melee = false;

        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

		RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You got lucky!");
		_unit->PlaySoundToSet(11527);

		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Valiant Effort.");
		_unit->PlaySoundToSet(11525);
	}

	void AIUpdate()
	{
		uint32 t = (uint32)time(NULL);
		if (t > Vanish)
		{
			_unit->GetAIInterface()->ClearHateList();
		}

		if (_unit->GetAIInterface()->GetNextTarget() && _unit->GetCurrentSpell() == NULL && !_unit->FindAura(VANISH))
		{
			uint32 t = (uint32)time(NULL);
			if (t > spells[2].casttime)
			{
				std::vector <Unit*> TargetTable;
				for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
				{ 
					if (isHostile(_unit, (*itr)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID())
					{
						Unit* Target = NULL;
						Target = (Unit*)(*itr);

						if (Target->isAlive() && _unit->GetDistance2dSq(Target) <= 30.0f && _unit->GetAIInterface()->getThreatByPtr(Target) > 0)
							TargetTable.push_back(Target);
					} 
				}

				if (TargetTable.size())
				{
					_unit->GetAIInterface()->ClearHateList();

					Unit *UnitToFollow = NULL;
					size_t Rand = rand()%TargetTable.size();
					UnitToFollow = TargetTable[Rand];

					if (UnitToFollow)
					{
						_unit->GetAIInterface()->AttackReaction(UnitToFollow, 10000, 0);
					}

					Vanish = t + 31;	// 31, coz there is 1-2 sec till he fights again after vanish aura is removed
				}

				_unit->setAttackTimer(spells[2].attackstoptimer, false);
				_unit->CastSpell(_unit, spells[2].info, spells[2].instant);

				spells[2].casttime = t + spells[2].cooldown;
				return;
			}

			if (_unit->GetAIInterface()->GetNextTarget() && t > spells[1].casttime && Poisoned && RandomUInt(3) != 1)
			{
				Unit *TargetToAttack = NULL;
				for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
				{ 
					if (isHostile(_unit, (*itr)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID())
					{
						Unit* PoisonedTarget = NULL;
						PoisonedTarget = (Unit*)(*itr);

						if (PoisonedTarget->isAlive() && _unit->GetAIInterface()->getThreatByPtr(PoisonedTarget) > 0 && PoisonedTarget->FindAura(DEADLY_POISON))
						{
							TargetToAttack = PoisonedTarget;
							break;
						} 
					} 
				}

				if (TargetToAttack)
				{
					_unit->CastSpell(TargetToAttack, spells[1].info, spells[1].instant);
				}

				spells[1].casttime = t + spells[1].cooldown;
				Poisoned = false;
				return;
			}
		}

		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

	void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget() && !_unit->FindAura(VANISH))
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}

					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

    void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();

			if (i == 0)
				Poisoned = true;
		}
	}

protected:

	uint32 Vanish;
	bool Poisoned;
	int nrspells;
};

//------------------------------------
//    -= High Nethermancer Zerevor  =-
//------------------------------------
#define CN_HIGH_NETHERMANCER_ZEREVOR 22950

#define ARCANE_BOLT			41483
#define BLIZZARD			41482
#define FLAMESTRIKE			41481
#define ARCANE_EXPLOSION	29973
#define DAMPEN_MAGIC		41478

class ZerevorAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(ZerevorAI);
	SP_AI_Spell spells[5];
	bool m_spellcheck[5];

    ZerevorAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 3;
		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(ARCANE_BOLT);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].perctrigger = 65.0f;
		spells[0].attackstoptimer = 2000;
		spells[0].cooldown = 0;

		spells[1].info = dbcSpell.LookupEntry(BLIZZARD);
		spells[1].targettype = TARGET_RANDOM_DESTINATION;
		spells[1].instant = true;
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 2000;
		spells[1].cooldown = 15;
		spells[1].mindist2cast = 0.0f;
		spells[1].maxdist2cast = 60.0f;

		spells[2].info = dbcSpell.LookupEntry(FLAMESTRIKE);
		spells[2].targettype = TARGET_RANDOM_DESTINATION;
		spells[2].instant = false;
		spells[2].perctrigger = 10.0f;
		spells[2].attackstoptimer = 2000;
		spells[2].cooldown = 15;
		spells[2].mindist2cast = 0.0f;
		spells[2].maxdist2cast = 60.0f;

		spells[3].info = dbcSpell.LookupEntry(DAMPEN_MAGIC);
		spells[3].targettype = TARGET_SELF;
		spells[3].instant = true;
		spells[3].perctrigger = 0.0f;
		spells[3].attackstoptimer = 2000;
		spells[3].cooldown = 60;	// not sure at all

		spells[4].info = dbcSpell.LookupEntry(ARCANE_EXPLOSION);
		spells[4].targettype = TARGET_VARIOUS;
		spells[4].instant = false;
		spells[4].perctrigger = 0.0f;
		spells[4].attackstoptimer = 11000;
		spells[4].cooldown = 0;

		ArcaneCheck = 0;
    }

    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;
		spells[3].casttime = (uint32)time(NULL) + spells[3].cooldown;

		if (_unit->GetDistance2dSq(mTarget) <= 1600.0f)
		{
			_unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);
			_unit->GetAIInterface()->StopMovement(1);
		}

		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Common... such a crude language. Bandal!");
		_unit->PlaySoundToSet(11440);

		_unit->CastSpell(_unit, spells[3].info, spells[3].instant);

		ArcaneCheck = 5;

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

		RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		//_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "BossDied");
		_unit->PlaySoundToSet(11443);

		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Shorel'aran.");
		_unit->PlaySoundToSet(11441);
	}

	void AIUpdate()
	{
		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);

		ArcaneCheck--;
		if (_unit->GetAIInterface()->GetNextTarget() && _unit->GetCurrentSpell() == NULL)
		{
			if (ArcaneCheck <= 0)
			{
				ArcaneCheck = 5;
				Unit *Target = NULL;
				Target = FindTargetForSpell();

				if (Target)
				{
					_unit->CastSpell(_unit, spells[4].info, spells[4].instant);
					return;
				}
			}

			uint32 t = (uint32)time(NULL);
			if (t > spells[3].casttime)
			{
				_unit->CastSpell(_unit, spells[3].info, spells[3].instant);

				spells[3].casttime = t + spells[3].cooldown;
				return;
			}

			if (_unit->GetDistance2dSq(_unit->GetAIInterface()->GetNextTarget()) >= 0.0f && _unit->GetDistance2dSq(_unit->GetAIInterface()->GetNextTarget()) <= 900.0f)
			{
				_unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);
				_unit->GetAIInterface()->StopMovement(1);
				
				float val = RandomFloat(100.0f);
				SpellCast(val);
			}
		}
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();
		}
	}

	// A bit rewritten FindTarget function
	Unit* FindTargetForSpell()
	{
		Unit* target = NULL;
		float distance = 5.0f;

		Unit *pUnit;
		float dist;

		for (std::set<Object*>::iterator itr = _unit->GetInRangeOppFactsSetBegin(); itr != _unit->GetInRangeOppFactsSetEnd(); itr++)
		{
			if((*itr)->GetTypeId() != TYPEID_UNIT && (*itr)->GetTypeId() != TYPEID_PLAYER)
				continue;

			pUnit = static_cast<Unit*>((*itr));

			if(pUnit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FEIGN_DEATH))
				continue;

			if(pUnit->m_invisible)
				continue;
			
			if(!pUnit->isAlive() || _unit == pUnit)
				continue;

			dist = _unit->GetDistance2dSq(pUnit);

			if(dist > distance*distance)
				continue;

			target = pUnit;
			break;
		}

		return target;
	}

protected:

	int ArcaneCheck;
	int nrspells;
};

//------------------------------------
//    -= Gathios the Shatterer =-
//------------------------------------
#define CN_GATHIOS_THE_SHATTERER 22949

#define HAMMER_OF_JUSTICE			41468
#define SEAL_OF_COMMAND				41469
#define SEAL_OF_BLOOD				41459
#define CONSECRATION				41541
#define BLESSING_OF_SPELL_WARDING	41451
#define BLESSING_OF_PROTECTION		41450
#define CHROMATIC_RESISTANCE_AURA	41453
#define DEVOTION_AURA				41452

class GathiosAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(GathiosAI);
	SP_AI_Spell spells[8];
	bool m_spellcheck[8];

    GathiosAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 3;

		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(HAMMER_OF_JUSTICE);
		spells[0].targettype = TARGET_RANDOM_SINGLE;
		spells[0].instant = true;
		spells[0].perctrigger = 10.0f;
		spells[0].attackstoptimer = 1000;
		spells[0].cooldown = 10;
		spells[0].mindist2cast = 10.0f;
		spells[0].maxdist2cast = 40.0f;

		// Next 2 spells share cooldowns (but couldn't have found infos about them)
		spells[1].info = dbcSpell.LookupEntry(SEAL_OF_COMMAND);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].perctrigger = 8.0f;
		spells[1].attackstoptimer = 2000;
		spells[1].cooldown = 30;

		spells[2].info = dbcSpell.LookupEntry(SEAL_OF_BLOOD);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = true;
		spells[2].perctrigger = 8.0f;
		spells[2].attackstoptimer = 2000;
		spells[2].cooldown = 30;

		spells[3].info = dbcSpell.LookupEntry(CONSECRATION); 
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = true;
		spells[3].perctrigger = 0.0f;
		spells[3].attackstoptimer = 2000;
		spells[3].cooldown = 30;

		// Next 2 spells share cooldowns
		spells[4].info = dbcSpell.LookupEntry(BLESSING_OF_SPELL_WARDING);  
		spells[4].targettype = TARGET_RANDOM_FRIEND;
		spells[4].instant = true;
		spells[4].perctrigger = 0.0f;
		spells[4].attackstoptimer = 2000;
		spells[4].cooldown = 15;
		
		spells[5].info = dbcSpell.LookupEntry(BLESSING_OF_PROTECTION); 
		spells[5].targettype = TARGET_RANDOM_FRIEND;
		spells[5].instant = true;
		spells[5].perctrigger = 0.0f;
		spells[5].attackstoptimer = 2000;
		spells[5].cooldown = 15;

		// Next 2 spells share cooldowns
		spells[6].info = dbcSpell.LookupEntry(CHROMATIC_RESISTANCE_AURA);
		spells[6].targettype = TARGET_RANDOM_FRIEND;
		spells[6].instant = true;
		spells[6].perctrigger = 0.0f;
		spells[6].attackstoptimer = 2000;
		spells[6].cooldown = 60;
		
		spells[7].info = dbcSpell.LookupEntry(DEVOTION_AURA); 
		spells[7].targettype = TARGET_RANDOM_FRIEND;
		spells[7].instant = true;
		spells[7].perctrigger = 0.0f;
		spells[7].attackstoptimer = 2000;
		spells[7].cooldown = 60;
    }

    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;

		uint32 t = (uint32)time(NULL);
		for (int i = 3; i < 8; i++)
			spells[i].casttime = t + spells[i].cooldown;

		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I have better things to do!");
		_unit->PlaySoundToSet(11422);

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

		RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Lord Illidan... I...");
		_unit->PlaySoundToSet(11425);

		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Selama amor'anore!");
		_unit->PlaySoundToSet(11423);
	}

	void AIUpdate()
	{
		if (_unit->GetAIInterface()->GetNextTarget() && _unit->GetCurrentSpell() == NULL)
		{
			uint32 t = (uint32)time(NULL);
			if (t > spells[3].casttime)
			{
				_unit->setAttackTimer(spells[3].attackstoptimer, false);

				_unit->CastSpell(_unit, spells[3].info, spells[3].instant);

				spells[3].casttime = t + spells[3].cooldown;
				return;
			}

			if (t > spells[4].casttime)
			{
				Unit *TargetToBuff = NULL;
				Unit *Malande = NULL;
				Unit *Zerevor = NULL;
				Unit *Veras = NULL;

				Malande = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), 22951);
				if (Malande && Malande->isAlive())
				{
					TargetToBuff = Malande;
					if (RandomUInt(10) == 1)
					{
						std::vector<Unit*> BuffTable;
						Zerevor = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), 22950);
						Veras = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), 22952);

						if (Zerevor && Zerevor->isAlive())
							BuffTable.push_back(Zerevor);
						if (Veras && Veras->isAlive())
							BuffTable.push_back(Veras);

						if (BuffTable.size())
						{
							size_t Target = rand()%BuffTable.size();
							TargetToBuff = BuffTable[Target];
						}
					}
				}

				else
				{
					std::vector<Unit*> BuffTable;
					Zerevor = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), 22950);
					Veras = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), 22952);

					if (Zerevor && Zerevor->isAlive())
						BuffTable.push_back(Zerevor);
					if (Veras && Veras->isAlive())
						BuffTable.push_back(Veras);

					if (BuffTable.size())
					{
						size_t Target = rand()%BuffTable.size();
						TargetToBuff = BuffTable[Target];
					}
				}

				if (TargetToBuff)
				{
					uint32 SpellId = BLESSING_OF_SPELL_WARDING;
					if (RandomUInt(2) == 1)
						SpellId = BLESSING_OF_PROTECTION;

					_unit->setAttackTimer(spells[4].attackstoptimer, false);

					_unit->CastSpell(TargetToBuff, SpellId, spells[4].instant);

					spells[4].casttime = t + spells[4].cooldown;
					return;
				}

				spells[4].casttime = t + spells[4].cooldown;
			}

			if (t > spells[6].casttime)
			{
				uint32 SpellId = CHROMATIC_RESISTANCE_AURA;
				if (RandomUInt(2) == 1)
					SpellId = DEVOTION_AURA;

				_unit->setAttackTimer(spells[6].attackstoptimer, false);

				_unit->CastSpell(_unit, SpellId, spells[6].instant);

				spells[6].casttime = t + spells[6].cooldown;
				return;
			}
		}

		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;

					if (i == 1 || i == 2)
					{
						spells[1].casttime = t + spells[1].cooldown;
						spells[2].casttime = t + spells[2].cooldown;
					}
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();
		}
	}

protected:

	int nrspells;
};

//------------------------------------
//    -= Lady Malande =-
//------------------------------------
#define CN_LADY_MALANDE 22951

#define DIVINE_WRATH		41472
#define REFLECTIVE_SHIELD	41475
#define EMPOWERED_SMITE		41471
#define CIRCLE_OF_HEALING	41455

class MalandeAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(MalandeAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

    MalandeAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 2;
		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;
		}

		spells[0].info = dbcSpell.LookupEntry(DIVINE_WRATH);
		spells[0].targettype = TARGET_RANDOM_SINGLE;
		spells[0].instant = false;
		spells[0].perctrigger = 9.0f;
		spells[0].attackstoptimer = 2000;
		spells[0].cooldown = 15;
		spells[0].mindist2cast = 0.0f;
		spells[0].maxdist2cast = 60.0f;

		spells[1].info = dbcSpell.LookupEntry(REFLECTIVE_SHIELD);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].perctrigger = 6.0f;
		spells[1].attackstoptimer = 2000;
		spells[1].cooldown = 30;

		spells[2].info = dbcSpell.LookupEntry(EMPOWERED_SMITE);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = false;
		spells[2].perctrigger = 0.0f;
		spells[2].attackstoptimer = 1000;
		spells[2].cooldown = 30;

		spells[3].info = dbcSpell.LookupEntry(CIRCLE_OF_HEALING);
		spells[3].targettype = TARGET_VARIOUS;
		spells[3].instant = false;
		spells[3].perctrigger = 0.0f;
		spells[3].attackstoptimer = 4000;
		spells[3].cooldown = 20;
    }

    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;

		uint32 t = (uint32)time(NULL);
		for (int i = 2; i < 4; i++)
			spells[i].casttime = t + spells[i].cooldown;

		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Flee or die!");
		_unit->PlaySoundToSet(11482);

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

       RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Destiny... awaits!");
		_unit->PlaySoundToSet(11485);

		RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "My work is done.");
		_unit->PlaySoundToSet(11483);
	}

	void AIUpdate()
	{
		if (_unit->GetAIInterface()->GetNextTarget() && _unit->GetCurrentSpell() == NULL)
		{
			uint32 t = (uint32)time(NULL);
			if (t > spells[2].casttime)
			{
				Unit *target = _unit->GetAIInterface()->GetNextTarget();
				_unit->CastSpell(target, spells[2].info, spells[2].instant);

				spells[2].casttime = t + spells[2].cooldown;
				return;
			}

			if (t > spells[3].casttime)
			{
				_unit->CastSpell(_unit, spells[3].info, spells[3].instant);

				spells[3].casttime = t + spells[3].cooldown;
				return;
			}
		}

		float val = (float)RandomFloat(100.0f);
        SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();
		}
	}

protected:

	int nrspells;
};

//--------------------------Teron Gorefiend-----------------------------//

#define CN_TERON_GOREFIEND 22871

#define DOOM_BLOSSOM		40188	// needs additional creature in DB
#define CRUSHING_SHADOWS	40243
#define INCINERATE			40239
#define SHADOW_OF_DEATH		40251	// need further scripting?
// Dunno where other sounds should go
class TeronGorefiendAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(TeronGorefiendAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

    TeronGorefiendAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 2;
		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;

		} 

		spells[0].info = dbcSpell.LookupEntry(DOOM_BLOSSOM); //summon visual effect 
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].perctrigger = 8.0f;
		spells[0].attackstoptimer = 1000;
		spells[0].cooldown = 25;

		spells[1].info = dbcSpell.LookupEntry(CRUSHING_SHADOWS);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = false;
		spells[1].perctrigger = 10.0f;
		spells[1].attackstoptimer = 1000;
		spells[1].cooldown = 20;

		spells[2].info = dbcSpell.LookupEntry(INCINERATE);
		spells[2].targettype = TARGET_RANDOM_SINGLE; 
		spells[2].instant = true;
		spells[2].perctrigger = 0.0f;
		spells[2].attackstoptimer = 1000;
		spells[2].cooldown = 20;
		spells[2].mindist2cast = 0.0f;
		spells[2].maxdist2cast = 45.0f;

		spells[3].info = dbcSpell.LookupEntry(SHADOW_OF_DEATH);
		spells[3].targettype = TARGET_RANDOM_SINGLE;
		spells[3].instant = false;
		spells[3].perctrigger = 0.0f;
		spells[3].attackstoptimer = 2000;
		spells[3].cooldown = 30;
		spells[3].mindist2cast = 0.0f;
		spells[3].maxdist2cast = 60.0f;
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Vengeance is mine!");
		_unit->PlaySoundToSet(11513);

		for (int i = 0; i < 4; i++)
			spells[i].casttime = 0;

		uint32 t = (uint32)time(NULL);
		spells[2].casttime = t + spells[2].cooldown;
		spells[3].casttime = t + 10;

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

	void OnTargetDied(Unit* mTarget)
    {
		if (_unit->GetHealthPct() > 0)	
		{
			switch (RandomUInt(2))
			{
			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "It gets worse...");
				_unit->PlaySoundToSet(11515);
				break;
			default:
				{
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I have use for you!");
					_unit->PlaySoundToSet(11514);
				}
			}
		}
    }

    void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "The wheel...spins...again....");
		_unit->PlaySoundToSet(11521);

		RemoveAIUpdateEvent();
    }

    void AIUpdate()
	{
		uint32 t = (uint32)time(NULL);
		if (t > spells[2].casttime)
		{
			_unit->setAttackTimer(spells[2].attackstoptimer, false);

			CastSpellOnRandomTarget(2, spells[2].mindist2cast, spells[2].maxdist2cast, 0, 100);

			spells[2].casttime = t + spells[2].cooldown;
		}

		if (t > spells[3].casttime)
		{
			_unit->setAttackTimer(spells[3].attackstoptimer, false);

			CastSpellOnRandomTarget(3, spells[3].mindist2cast, spells[3].maxdist2cast, 0, 100);

			spells[3].casttime = t + spells[3].cooldown;
		}

		float val = (float)RandomFloat(100.0f);
		SpellCast(val);
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();
		}
	}

protected:

	int nrspells;
};

//Shade of AkamaAI

#define CN_SHADE_OF_AKAMA 22841

#define SINFUL_BEAM0 00000

class ShadeofakamaAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(ShadeofakamaAI);
	SP_AI_Spell spells[1];
	bool m_spellcheck[1];

    ShadeofakamaAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 1;
		for(int i=0;i<nrspells;i++)
		{
			m_spellcheck[i] = false;

		} 
		spells[0].info = dbcSpell.LookupEntry(SINFUL_BEAM0);
		spells[0].targettype = TARGET_VARIOUS;
		spells[0].instant = false;
		spells[0].perctrigger = 0.0f;
		spells[0].attackstoptimer = 2000;

    }
    
    void OnCombatStart(Unit* mTarget)
    {
		hm = 100;
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

	void OnTargetDied(Unit* mTarget)
    {
		if (_unit->GetHealthPct() > 0)	
		{
			int RandomSpeach;
			RandomUInt(1000);
			RandomSpeach=rand()%3;
			switch (RandomSpeach)
			{
			case 0:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will not last much longer...");
				_unit->PlaySoundToSet(11385);
				break;
			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "It is time to free your soul from Illidan's grasp!");
				//_unit->PlaySoundToSet(11510);
				break;

			}
		}
    }

    void OnCombatStop(Unit *mTarget)
    {
		hm = 100;
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
		Creature *cre = NULL;
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I don't want to go back!");
		_unit->PlaySoundToSet(11420);
        cre = _unit->GetMapMgr()->GetInterface()->SpawnCreature(22990, 
        643.741f, 305.852f,
        271.689f, 0.00628f, 
        true, false, 0, 0); 
		//cre->GetAIInterface()->setOutOfCombatRange(30000);
       RemoveAIUpdateEvent();
    }

    void AIUpdate()
	{
		if(_unit->GetHealthPct() <= 85 && hm == 100) 
        {
            Creature *cre = NULL;
            for(int i = 0; i < 2; i++)
            {
                cre = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23421, 
                    _unit->GetPositionX(), _unit->GetPositionY(),
                    _unit->GetPositionZ(), _unit->GetOrientation(),
                    true, false, 0, 0);
				if (cre)
					cre->GetAIInterface()->setOutOfCombatRange(30000);
			}
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Abandon all hope! The legion has returned to finish what was begun so many years ago. This time there will be no escape!");
		_unit->PlaySoundToSet(10999);
		hm=85;
		}
		else if(_unit->GetHealthPct() <= 70 && hm == 85)
        {
            Creature *cre = NULL;
            for(int i = 0; i < 2; i++)
            {
                cre = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23215, 
                    _unit->GetPositionX(), _unit->GetPositionY(),
                    _unit->GetPositionZ(), _unit->GetOrientation(),
                    true, false, 0, 0); 
				if (cre)
					cre->GetAIInterface()->setOutOfCombatRange(30000);
			}
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Abandon all hope! The legion has returned to finish what was begun so many years ago. This time there will be no escape!");
		_unit->PlaySoundToSet(10999);
		hm=70;
		}
		else if(_unit->GetHealthPct() <= 55 && hm == 70)
        {
            Creature *cre = NULL;
            for(int i = 0; i < 2; i++)
            {
                cre = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23216, 
                    _unit->GetPositionX(), _unit->GetPositionY(),
                    _unit->GetPositionZ(), _unit->GetOrientation(),
                    true, false, 0, 0); 
				if (cre)
					cre->GetAIInterface()->setOutOfCombatRange(30000);
			}
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Abandon all hope! The legion has returned to finish what was begun so many years ago. This time there will be no escape!");
		_unit->PlaySoundToSet(10999);
		hm=55;
		}
		else if(_unit->GetHealthPct() <= 40 && hm == 55)
        {
            Creature *cre = NULL;
            for(int i = 0; i < 2; i++)
            {
                cre = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23523, 
                    _unit->GetPositionX(), _unit->GetPositionY(),
                    _unit->GetPositionZ(), _unit->GetOrientation(),
                    true, false, 0, 0); 
				if (cre)
					cre->GetAIInterface()->setOutOfCombatRange(30000);
			}
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Abandon all hope! The legion has returned to finish what was begun so many years ago. This time there will be no escape!");
		_unit->PlaySoundToSet(10999);
		hm=40;
		}
		else if(_unit->GetHealthPct() <= 25 && hm == 40)
        {
            Creature *cre = NULL;
            for(int i = 0; i < 5; i++)
            {
                cre = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23318, 
                    _unit->GetPositionX(), _unit->GetPositionY(),
                    _unit->GetPositionZ(), _unit->GetOrientation(),
                    true, false, 0, 0); 
				if (cre)
					cre->GetAIInterface()->setOutOfCombatRange(30000);
			}
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Abandon all hope! The legion has returned to finish what was begun so many years ago. This time there will be no escape!");
		_unit->PlaySoundToSet(10999);
		hm=25;
		}
		else if(_unit->GetHealthPct() <= 10 && hm == 25)
        {
            Creature *cre = NULL;
            for(int i = 0; i < 5; i++)
            {
                cre = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23524, 
                    _unit->GetPositionX(), _unit->GetPositionY(),
                    _unit->GetPositionZ(), _unit->GetOrientation(),
                    true, false, 0, 0); 
				if (cre)
					cre->GetAIInterface()->setOutOfCombatRange(30000);
			}
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Abandon all hope! The legion has returned to finish what was begun so many years ago. This time there will be no escape!");
		_unit->PlaySoundToSet(10999);
		hm=10;
		}
		else
		{
			float val = (float)RandomFloat(100.0f);
			SpellCast(val);
		}
	}

    void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}

					if (spells[i].speech != "")
					{
						_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, spells[i].speech.c_str());
						_unit->PlaySoundToSet(spells[i].soundid); 
					}

                  	m_spellcheck[i] = false;
					return;
				}

				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger))
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }
protected:

	int nrspells;
	int hm;
};

// ---    Illidan Encounter Event      --- //

/* Global Variables */

// Additional stuff
uint32 m_phase[1000000];	// dunno if it's enough (uint32 InstanceID -> 4,294,967,295)

// Events
uint32 DeathEvent[1000000];

#define WALK 0
#define RUN 256
#define FLY 768

// Global settings - comment to disable
#define USE_SHADOW_PRISON	// aggroes a lot of mobs/NPCs if they are not friendly to Illidan

struct Coords SearchPos[]=
{
	{ 744.743896f, 270.928619f, 352.996185f, 2.605572f },
	{ 742.240051f, 330.404205f, 352.996185f, 3.249600f },
	{ 686.947632f, 305.891022f, 353.192383f, 3.096451f },
	{ 676.432495f, 266.354828f, 353.264984f, 4.317750f },
	{ 674.560974f, 353.792755f, 352.996094f, 1.918359f }
};

/* Effect and Trigger AIs */

/* Door Event Trigger AI - Creature AI Class */

#define CN_DOOR_EVENT_TRIGGER	30001

class DoorEventTriggerAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(DoorEventTriggerAI);

    DoorEventTriggerAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
		_unit->GetAIInterface()->m_moveFly = true;
    }
};

/* Demon Fire AI - Creature AI Class */

#define CN_DEMON_FIRE	23069

#define DEMON_FIRE		40029

class DemonFireAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(DemonFireAI);

    DemonFireAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		_unit->CastSpell(_unit, dbcSpell.LookupEntry(DEMON_FIRE), true);
		_unit->GetAIInterface()->disable_melee = true;
		_unit->GetAIInterface()->m_canMove = false;
		_unit->m_noRespawn = true;
		_unit->Despawn(60000, 0);
    }

    void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
    }
};

/* Eye Beam Trigger AI - Creature AI Class */

#define CN_EYE_BEAM_TRIGGER	30000

#define EYE_BLAST			40017

class EyeBeamTriggerAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(EyeBeamTriggerAI);

    EyeBeamTriggerAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		_unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
		_unit->GetAIInterface()->disable_melee = true;
		_unit->GetAIInterface()->m_moveRun = true;
		_unit->m_noRespawn = true;
		_unit->Despawn(12000, 0);

		RegisterAIUpdateEvent(1000);
		WallCreating = false;
    }

    void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
    }

    void OnDied(Unit * mKiller)
    {
       RemoveAIUpdateEvent();
    }

    void AIUpdate()
    {
		if (WallCreating == false)
		{
			if (_unit->GetPositionX() == 642.240601f && _unit->GetPositionY() == 297.297180f && _unit->GetPositionZ() == 353.423401f)
				_unit->GetAIInterface()->MoveTo(707.019043f, 270.441772f, 352.996063f, 5.953270f);
			if (_unit->GetPositionX() == 641.197449f && _unit->GetPositionY() == 314.330963f && _unit->GetPositionZ() == 353.300262f)
				_unit->GetAIInterface()->MoveTo(706.592407f, 343.425568f, 352.996124f, 3.659908f);
			if (_unit->GetPositionX() == 657.239807f && _unit->GetPositionY() == 256.925568f && _unit->GetPositionZ() == 352.996094f)
				_unit->GetAIInterface()->MoveTo(706.593262f, 310.011475f, 353.693848f, 2.506154f);
			if (_unit->GetPositionX() == 657.913330f && _unit->GetPositionY() == 353.562775f && _unit->GetPositionZ() == 352.996185f)
				_unit->GetAIInterface()->MoveTo(706.751343f, 298.312683f, 353.653809f, 3.436852f);
			if (_unit->GetPositionX() == 707.019043f && _unit->GetPositionY() == 270.441772f && _unit->GetPositionZ() == 352.996063f)
				_unit->GetAIInterface()->MoveTo(642.240601f, 297.297180f, 353.423401f, 5.953270f);
			if (_unit->GetPositionX() == 706.592407f && _unit->GetPositionY() == 343.425568f && _unit->GetPositionZ() == 352.996124f)
				_unit->GetAIInterface()->MoveTo(641.197449f, 314.330963f, 353.300262f, 3.659908f);
			if (_unit->GetPositionX() == 706.593262f && _unit->GetPositionY() == 310.011475f && _unit->GetPositionZ() == 353.693848f)
				_unit->GetAIInterface()->MoveTo(657.239807f, 256.925568f, 352.996094f, 2.506154f);
			if (_unit->GetPositionX() == 706.751343f && _unit->GetPositionY() == 298.312683f && _unit->GetPositionZ() == 353.653809f)
				_unit->GetAIInterface()->MoveTo(657.913330f, 353.562775f, 352.996185f, 3.436852f);

			WallCreating = true;
		}

		_unit->CastSpell(_unit, dbcSpell.LookupEntry(EYE_BLAST), true);
    }

protected:

	bool WallCreating;
};

/* Flame Crash Effect AI - Creature AI Class */

#define CN_FLAME_CRASH	23336

#define FLAME_CRASH_EFFECT	40836

class FlameCrashAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(FlameCrashAI);

    FlameCrashAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		_unit->CastSpell(_unit, dbcSpell.LookupEntry(FLAME_CRASH_EFFECT), true);
		_unit->GetAIInterface()->disable_melee = true;
		_unit->GetAIInterface()->m_canMove = false;
		_unit->m_noRespawn = true;
		_unit->Despawn(120000, 0);
    }

    void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
    }
};

/* Blaze Effect AI - Creature AI Class */

#define CN_BLAZE	23259

#define BLAZE_EFFECT	40610

class BlazeAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(BlazeAI);

    BlazeAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		_unit->CastSpell(_unit, dbcSpell.LookupEntry(BLAZE_EFFECT), true);
		_unit->GetAIInterface()->disable_melee = true;
		_unit->GetAIInterface()->m_canMove = false;
		_unit->m_noRespawn = true;
		_unit->Despawn(60000, 0);
    }

	void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
    }
};

/* Misc Creature AIs */

/* Flame of Azzinoth AI - Creature AI Class */

#define CN_FLAME_OF_AZZINOTH	22997	

#define BLAZE			40637		// this one just summons mob that will trigger that fire cloud - doesn't spawn mob
#define FLAME_BLAST		40631
#define FOA_ENRAGE		40683	// 40683 or 40743
#define CHAOS_CHARGE	40497 // CHAOS_CHARGE 40497 CHARGE 40602

class FlameOfAzzinothAI : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(FlameOfAzzinothAI);
	SP_AI_Spell spells[4];
	bool m_spellcheck[4];

    FlameOfAzzinothAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		nrspells = 2;
		for (int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

		spells[0].info = dbcSpell.LookupEntry(BLAZE);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 30;
		spells[0].perctrigger = 7.0f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(FLAME_BLAST);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = true;
		spells[1].cooldown = 15;
		spells[1].perctrigger = 13.0f;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(CHAOS_CHARGE);
		spells[2].targettype = TARGET_ATTACKING;
		spells[2].instant = true;

		spells[3].info = dbcSpell.LookupEntry(FOA_ENRAGE);
		spells[3].targettype = TARGET_SELF;
		spells[3].instant = true;

		_unit->m_noRespawn = true;

		Enrage = false;
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;

		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
    }

    void OnCombatStop(Unit *mTarget)
    {
        _unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);
        RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
       RemoveAIUpdateEvent();
    }

    void AIUpdate()
	{
		if (Enrage == true)
		{
			_unit->CastSpell(_unit, spells[3].info, spells[3].instant);

			Enrage = false;
			return;
		}

		if (_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget() != NULL)
		{
			Unit *target = NULL;
			target = _unit->GetAIInterface()->GetNextTarget();

			if (_unit->GetDistance2dSq(target) >= 225.0f && _unit->GetDistance2dSq(target) <= 1225 && rand()%5 == 0)	// I must test this value (15-35yards for now)
			{
				_unit->CastSpell(target, spells[2].info, spells[2].instant);

				Enrage = true;
				return;
			}
		}

		float val = (float)RandomFloat(100.0f);
		SpellCast(val);
    }

	void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}

					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

protected:

	int nrspells;
	bool Enrage;
};

/* Akama AI - Creature Gossip Class */
 
#define SendQuickMenu(textid) objmgr.CreateGossipMenuForPlayer(&Menu, pCreature->GetGUID(), textid, plr); \
    Menu->SendTo(plr);
 
class AkamaGossip : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
        GossipMenu *Menu;
		Creature *Akama = (Creature*)(pObject);
		if (Akama == NULL)
			return;

		if (Akama->GetAIInterface()->getCurrentWaypoint() >= 10)
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 22992, plr);
			Menu->AddItem( 0, "We're ready to face Illidan.", 2);
		}

		else
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 22991, plr);
			Menu->AddItem( 0, "I'm ready, Akama.", 1);
		}
	 
		if(AutoSend)
			Menu->SendTo(plr);
    }
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
    {
		Creature *Akama = (Creature*)(pObject);
		if (Akama == NULL)
			return;

		switch (IntId)
		{
		case 0:
			GossipHello(pObject, plr, true);
			break;
		case 1:
			Akama->SetUInt32Value(UNIT_NPC_FLAGS, 0);

			Akama->GetAIInterface()->StopMovement(0);
			Akama->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
			Akama->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
			Akama->GetAIInterface()->setWaypointToMove(1);
			break;
		case 2:
			Akama->SetUInt32Value(UNIT_NPC_FLAGS, 0);

			Akama->GetAIInterface()->StopMovement(0);
			Akama->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
			Akama->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
			Akama->GetAIInterface()->setWaypointToMove(17);
			break;
		}
	}
 
    void Destroy()
    {
        delete this;
    }
};

/* Akama AI - Creature AI Class */

#define CN_AKAMA	22990

#define HEALING_POTION			40535
#define BLESSING_OF_KINGS		20217
#define AKAMA_DESPAWN			41242

// Door Event Spells
#define AKAMA_DOOR_FAIL			41271
#define AKAMA_DOOR_OPEN			41268
#define DEATHSWORN_DOOR_OPEN	41269
#define GATE_FAILURE			10390

static Coords ToIllidan[] = 
{
	{  },
	{ 660.248596f, 330.695679f, 271.688110f, 1.243284f },
	{ 671.172241f, 353.273193f, 271.689453f, 1.022600f },
	{ 694.227783f, 379.461365f, 271.792145f, 6.232135f },
	{ 724.159973f, 373.263275f, 282.614349f, 5.324218f },
	{ 747.034973f, 335.668274f, 307.047150f, 4.972365f },
	{ 755.477234f, 304.194580f, 312.167328f, 6.276120f },
	{ 771.809753f, 303.744873f, 313.563507f, 6.265894f },
	{ 778.550232f, 304.515198f, 318.818542f, 0.002354f },
	{ 789.564697f, 304.493652f, 319.759583f, 6.248631f },
	{ 799.598389f, 295.776642f, 319.760040f, 4.687257f },
	{ 799.054016f, 288.826660f, 320.030334f, 4.563174f },
	{ 794.595459f, 262.302856f, 341.463715f, 4.500343f },
	{ 794.396973f, 256.420471f, 341.463715f, 4.557680f },
	{ 783.355957f, 250.460892f, 341.463776f, 3.746361f },
	{ 764.988098f, 238.561462f, 353.646484f, 3.324606f },
	{ 749.337463f, 236.288681f, 352.997223f, 1.633631f },
	{ 751.941528f, 304.626221f, 352.996124f, 3.128243f },
	{ 747.236511f, 304.922913f, 352.996155f, 6.278462f },
	{ 747.834106f, 362.513977f, 352.996155f, 1.604554f }
};

class AkamaAI : public CreatureAIScript
{
public:
	friend class AkamaGossip;

    ADD_CREATURE_FACTORY_FUNCTION(AkamaAI);
	SP_AI_Spell spells[3];
	bool m_spellcheck[3];

    AkamaAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		for (int i = 1; i < 20; i++)
		{
			_unit->GetAIInterface()->addWayPoint(CreateWaypoint(i, 0, RUN));
		}

		nrspells = 1;
		for (int i = 0; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

		spells[0].info = dbcSpell.LookupEntry(BLESSING_OF_KINGS);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 600;	// 10 min
		spells[0].perctrigger = 15.0f;
		spells[0].attackstoptimer = 1000;

		spells[1].info = dbcSpell.LookupEntry(HEALING_POTION);
		spells[1].targettype = TARGET_SELF;
		spells[1].instant = true;
		spells[1].cooldown = 0;
		spells[1].perctrigger = 0.0f;
		spells[1].attackstoptimer = 1000;

		spells[2].info = dbcSpell.LookupEntry(AKAMA_DESPAWN);
		spells[2].targettype = TARGET_SELF;
		spells[2].instant = false;
		spells[2].cooldown = 0;
		spells[2].perctrigger = 0.0f;
		spells[2].attackstoptimer = 1000;

		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
		_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
		_unit->GetAIInterface()->SetAllowedToEnterCombat(false);

		m_phase[_unit->GetInstanceID()] = 0;
		EventChapter = 0;
		SoundLimiter = 0;
		EventTimer = 0;

		Udalo = Olum = NULL;

		if (!DeathEvent[_unit->GetInstanceID()])
			_unit->SetUInt32Value(UNIT_NPC_FLAGS, 1);
		else
		{
			_unit->SetUInt32Value(UNIT_NPC_FLAGS, 0);
			RegisterAIUpdateEvent(1000);

			EventChapter = 2;
		}
	}
    
    void OnCombatStart(Unit* mTarget)
    {
		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;

		SoundLimiter = 0;

		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);

		RegisterAIUpdateEvent(1000);
    }

    void OnCombatStop(Unit *mTarget)
    {
		if (m_phase[_unit->GetInstanceID()] > 0)
			_unit->GetAIInterface()->SetAllowedToEnterCombat(false);

		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
		_unit->GetAIInterface()->SetAIState(STATE_IDLE);
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);

		//RemoveAIUpdateEvent();
    }

	void OnTargetDied(Unit* mTarget)
    {
		if (_unit->GetHealthPct() > 0)
		{
			int RandomSpeach = rand()%2;
			switch (RandomSpeach)
			{
			case 0:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Illidan will pay!");
				_unit->PlaySoundToSet(11381);
				break;
			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "One step closer!");
				_unit->PlaySoundToSet(11382);
				break;
			}
		}
    }

	void OnDied(Unit * mKiller)
    {
		_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Fight on friends! Kill him and end the curse on my people!");	// not sure
		_unit->PlaySoundToSet(11391);

		RemoveAIUpdateEvent();

		EventTimer = 0;
    }

	void AIUpdate()
	{
		switch (EventChapter)
		{
		case 0:
			WayToIllidan();
			break;
		case 1:
			FightWithIllidan();
			break;
		case 2:
			EncounterEnd();
			break;
		}
	}

	void WayToIllidan()
	{
		if (_unit->GetAIInterface()->getCurrentWaypoint() == 6 && EventTimer > 0)
		{
			GameObject* Gate = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(774.7f, 304.6f, 314.85f, 185905);
			Unit* DoorTrigger = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(771.5f, 304.7f, 319.0f, CN_DOOR_EVENT_TRIGGER);
			if (Gate == NULL)
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "It's strange that Illidan doesn't protect himself against intruders." );
				_unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
				_unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

				_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
				_unit->GetAIInterface()->setWaypointToMove(7);

				if (Udalo != NULL)
				{
					Udalo->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Udalo->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

					Udalo = NULL;
				}
				if (Olum != NULL)
				{
					Olum->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Olum->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

					Olum = NULL;
				}

				RemoveAIUpdateEvent();

				EventTimer = 0;
				return;
			}

			switch (EventTimer)
			{
			case 2:
				_unit->SetFacing(6.248631f);
				break;
			case 6:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "The door is all that stands between us and the Betrayer. Stand aside, friends." );
				_unit->Emote(EMOTE_ONESHOT_TALK);
				break;
			case 10:		// here will be first try to break door (Akama himself only)
				if (DoorTrigger != NULL)
				{
					_unit->CastSpell(DoorTrigger, dbcSpell.LookupEntry(AKAMA_DOOR_FAIL), false);
					_unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, DoorTrigger->GetGUID());
					_unit->SetUInt32Value(UNIT_CHANNEL_SPELL, AKAMA_DOOR_FAIL);
				}
				break;
			case 19:		// here we will stop casting spell on door
				_unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
				_unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				break;
			case 20:
				_unit->Emote(EMOTE_ONESHOT_NO);
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I cannot do this alone..." );
				break;
			case 26:		// summoning two spirits to help Akama with breaking doors
				Udalo = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23410, 751.884705f, 311.270050f, 312.121185f, 0.047113f, true, false, 0, 0);
				Olum  = _unit->GetMapMgr()->GetInterface()->SpawnCreature(23411, 751.687744f, 297.408600f, 312.124817f, 0.054958f, true, false, 0, 0);
				if (Udalo != NULL)
				{
					Udalo->GetAIInterface()->SetAllowedToEnterCombat(false);
					Udalo->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);

					Udalo->m_noRespawn = true;
					Udalo->Despawn(45000, 0);
				}
				if (Olum != NULL)
				{
					Olum->GetAIInterface()->SetAllowedToEnterCombat(false);
					Olum->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);

					Olum->m_noRespawn = true;
					Olum->Despawn(45000, 0);
				}
				break;
			case 27:
				if (Udalo != NULL)
					Udalo->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You are not alone, Akama." );
				break;
			case 33:
				if (Olum != NULL)
					Olum->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Your people will always be with you." );
				break;
			case 38:			// Akama starts casting his spell again with both spirits
				if (DoorTrigger != NULL)
				{
					_unit->CastSpell(DoorTrigger, dbcSpell.LookupEntry(AKAMA_DOOR_OPEN), false);
					_unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, DoorTrigger->GetGUID());
					_unit->SetUInt32Value(UNIT_CHANNEL_SPELL, AKAMA_DOOR_OPEN);
				}
				break;
			case 39:
				if (DoorTrigger != NULL)
				{
					if (Udalo != NULL)
					{
						Udalo->CastSpell(DoorTrigger, dbcSpell.LookupEntry(DEATHSWORN_DOOR_OPEN), false);
						Udalo->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, DoorTrigger->GetGUID());
						Udalo->SetUInt32Value(UNIT_CHANNEL_SPELL, DEATHSWORN_DOOR_OPEN);
					}
					if (Olum != NULL)
					{
						Olum->CastSpell(DoorTrigger, dbcSpell.LookupEntry(DEATHSWORN_DOOR_OPEN), false);
						Olum->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, DoorTrigger->GetGUID());
						Olum->SetUInt32Value(UNIT_CHANNEL_SPELL, DEATHSWORN_DOOR_OPEN);
					}
				}
				break;
			case 48:			// Door has been broken and channel stopped
				Gate->SetUInt32Value(GAMEOBJECT_STATE, 0);
				if (DoorTrigger != NULL)
				{
					DoorTrigger->CastSpell(_unit, dbcSpell.LookupEntry(GATE_FAILURE), true);
				}
				break;
			case 49:
				_unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
				_unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);

				if (Udalo != NULL)
				{
					Udalo->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Udalo->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				}
				if (Olum != NULL)
				{
					Olum->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Olum->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				}
				break;
			case 52:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "I thank you for your aid, my brothers. Our people will be redeemed!" );
				_unit->Emote(EMOTE_ONESHOT_SALUTE);
				break;
			case 55:
				if (Udalo != NULL)
					Udalo->Emote(EMOTE_ONESHOT_SALUTE);
				if (Olum != NULL)
					Olum->Emote(EMOTE_ONESHOT_SALUTE);

				Udalo = NULL;
				Olum = NULL;
				break;
			case 58:
				_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
				_unit->GetAIInterface()->setWaypointToMove(7);
				RemoveAIUpdateEvent();
				break;
			}

			EventTimer++;
			if (EventTimer > 58)
				EventTimer = 0;
		}

		if (EventTimer > 0 && _unit->GetAIInterface()->getCurrentWaypoint() == 16)
		{
			EventTimer++;
			switch (EventTimer)
			{
			case 2:
				_unit->PlaySoundToSet(11388);
				_unit->SetFacing(2.113512f);
				break;
			case 17:
				_unit->SetUInt32Value(UNIT_NPC_FLAGS, 1);
				RemoveAIUpdateEvent();

				EventTimer = 0;
				break;
			}
		}

		if (EventTimer > 0 && _unit->GetAIInterface()->getCurrentWaypoint() == 17 && m_phase[_unit->GetInstanceID()] == 0)
		{
			Illidan = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(704.539001f, 305.282013f, 353.919006f, 22917);
			if (Illidan == NULL || !Illidan->isAlive())
			{
				RemoveAIUpdateEvent();

				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Not this time my friends." );
				_unit->CastSpell(_unit, spells[2].info, spells[2].instant);
				_unit->Despawn(0,0);

				EventTimer = 0;
				return;
			}

			switch(EventTimer)
			{
			case 1:
				_unit->SetFacing(3.126680f);
				break;
			case 2:
				Illidan->RemoveAura(39656);
				break;
			case 3:
		        Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Akama... your duplicity is hardly surprising. I should have slaughtered you and your malformed brethren long ago.");
				Illidan->PlaySoundToSet(11463);
				break;
			case 7:
				Illidan->Emote(EMOTE_ONESHOT_QUESTION);
				break;
			case 12:
				Illidan->Emote(EMOTE_ONESHOT_QUESTION);
				break;
			case 15:
		        _unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "We've come to end your reign, Illidan. My people and all of Outland shall be free!");
				_unit->PlaySoundToSet(11389);

				_unit->Emote(EMOTE_ONESHOT_POINT);
			    break;
			case 18:
				_unit->Emote(EMOTE_ONESHOT_TALK);
				break;
			case 22:
				_unit->Emote(EMOTE_ONESHOT_SALUTE);
				break;
			case 25:
		        Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Boldly said. But I remain unconvinced.");
				Illidan->PlaySoundToSet(11464);

				Illidan->Emote(EMOTE_ONESHOT_QUESTION);
			    break;
			case 28:
				Illidan->Emote(EMOTE_ONESHOT_QUESTION);
				break;
			case 32:
		        _unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "The time has come! The moment is at hand!");
				_unit->PlaySoundToSet(11380);

				_unit->Emote(EMOTE_ONESHOT_SHOUT);
				break;
			case 34:
				_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
				_unit->Emote(EMOTE_ONESHOT_ROAR);
				break;
			case 36:
				Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You are not prepared!");
				Illidan->PlaySoundToSet(11466);

				_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);

				Illidan->Emote(EMOTE_ONESHOT_CUSTOMSPELL05);
				break;
			case 38:
				Illidan->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
				break;
			case 40:
				GameObject* RightGate = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(745.07f, 241.802f, 354.292f, 200000);
				GameObject* LeftGate  = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(744.829f, 369.276f, 354.324f, 200001);
				if (RightGate != NULL)
					RightGate->SetUInt32Value(GAMEOBJECT_STATE, 1);
				if (LeftGate != NULL)
					LeftGate->SetUInt32Value(GAMEOBJECT_STATE, 1);
				
				_unit->GetAIInterface()->SetAllowedToEnterCombat(true);
				_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
				_unit->GetAIInterface()->SetAIState(STATE_IDLE);
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
				_unit->GetAIInterface()->m_canMove = true;

				_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
				_unit->GetAIInterface()->setWaypointToMove(0);

				Illidan->GetAIInterface()->SetAllowedToEnterCombat(true);
				Illidan->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
				Illidan->GetAIInterface()->m_canMove = true;

				RemoveAIUpdateEvent();

				_unit->GetAIInterface()->AttackReaction(Illidan, 1, 0);

				Unit *IllidanTarget = NULL;
				IllidanTarget = FindTarget();
				if (IllidanTarget == NULL)
				{
					IllidanTarget = _unit;
				}

				Illidan->GetAIInterface()->AttackReaction(IllidanTarget, 500, 0);

				EventChapter = 1;
				break;
			}

			EventTimer++;
			if (EventTimer > 40)
				EventTimer = 0;
		}
	}

	void FightWithIllidan()
	{
		SoundLimiter++;
		if (_unit->GetHealthPct() <= 15 && _unit->GetAIInterface()->GetNextTarget() != NULL)
		{
			if (SoundLimiter >= 15)
			{
				int RandomSpeach = rand()%2;
				switch (RandomSpeach)
				{
				case 0:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will not last much longer!");
					_unit->PlaySoundToSet(11385);
					break;
				case 1:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "No! Not yet!");
					_unit->PlaySoundToSet(11386);
					break;
				}

				SoundLimiter = 0;
			}

			if (_unit->GetAIInterface()->GetNextTarget()->GetTypeId() == TYPEID_UNIT)
			{
				Creature *Target = NULL;
				Target = (Creature*)_unit->GetAIInterface()->GetNextTarget();
				if (Target != NULL && Target->GetEntry() == 22917)
					_unit->CastSpell(_unit, spells[1].info, spells[1].instant);
			}
		}

		if ((_unit->GetAIInterface()->GetNextTarget() != NULL || EventTimer > 7) && _unit->GetAIInterface()->getCurrentWaypoint() < 18 && m_phase[_unit->GetInstanceID()] != 0)
		{
			if (_unit->GetAIInterface()->GetAllowedToEnterCombat() == true && EventTimer < 7)	// && Illidan && Illidan->GetHealthPct() > 85)
			{
				_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);

				float val = (float)RandomFloat(100.0f);
				SpellCast(val);
			}

			if ((Illidan == NULL || !Illidan->isAlive()) && EventTimer <= 7)
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Not this time my friends.");
				_unit->CastSpell(_unit, spells[2].info, spells[2].instant);
				_unit->Despawn(0,0);
			}

			if ((Illidan != NULL && Illidan->isAlive() && Illidan->GetHealthPct() <= 85 && EventTimer <= 7) || EventTimer > 7)
			{
				switch (EventTimer)
				{
				case 0:
					Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Come, my minions. Deal with this traitor as he deserves!");
					Illidan->PlaySoundToSet(11465);
					break;
				case 7:
					_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
					_unit->GetAIInterface()->SetAIState(STATE_IDLE);
					_unit->GetAIInterface()->SetNextTarget((Unit*)NULL);
					_unit->GetAIInterface()->WipeTargetList();
					_unit->GetAIInterface()->WipeHateList();

					_unit->GetAIInterface()->disable_melee = true;
					_unit->GetAIInterface()->m_canMove = false;

					Illidan->GetAIInterface()->RemoveThreatByPtr(_unit);	// Akama will stuck in place anyway if alone in combat with Illidan
					break;
				case 8:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will deal with these mongrels! Strike now, friends! Strike at the Betrayer!");
					_unit->PlaySoundToSet(11390);

					_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					break;
				case 9:
					_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
					break;
				case 10:
					_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					break;
				case 11:
					_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
					_unit->Emote(EMOTE_ONESHOT_EXCLAMATION);
					break;
				case 13:
					_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
					_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
					break;
				case 15:
					_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
					_unit->GetAIInterface()->m_canMove = true;

					_unit->GetAIInterface()->StopMovement(0);
					_unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
					_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
					_unit->GetAIInterface()->setWaypointToMove(18);

					RemoveAIUpdateEvent();

					//_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					break;
				}
				
				EventTimer++;
				if (EventTimer > 15)
					EventTimer = 0;
			}
		}
	}

	void EncounterEnd()
	{
		if (m_phase[_unit->GetInstanceID()] == 0 && DeathEvent[_unit->GetInstanceID()] >= 40)
		{	
			if (DeathEvent[_unit->GetInstanceID()] <= 41)
			{
				Unit *Maiev = NULL;
				for (int i = 0; i < 5; i++)
				{
					Maiev = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(SearchPos[i].mX, SearchPos[i].mY, SearchPos[i].mZ, 23197);
					if (Maiev != NULL && Maiev->isAlive())
					{
						MposX = Maiev->GetPositionX();
						MposY = Maiev->GetPositionY();
						MposZ = Maiev->GetPositionZ();
						MposO = Maiev->GetOrientation();

						break;
					}
				}
				// Akama is despawned if he can't find Maiev anywhere (better than going to position x = 0.0f y = 0.0f and z = 0.0f (cells too small)
				if (Maiev == NULL)
				{
					_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "Not this time my friends.");
					_unit->CastSpell(_unit, spells[2].info, spells[2].instant);
					_unit->Despawn(0,0);
				}
			}

			if (_unit->GetPositionX() == MposX && _unit->GetPositionY() == MposY && _unit->GetPositionZ() == MposZ && DeathEvent[_unit->GetInstanceID()] < 44)
				DeathEvent[_unit->GetInstanceID()] = 44;

			if (DeathEvent[_unit->GetInstanceID()] == 42)
			{
				_unit->GetAIInterface()->m_moveRun = true;
				_unit->GetAIInterface()->MoveTo(MposX, MposY, MposZ, MposO);
				_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);

				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(1000);

				DeathEvent[_unit->GetInstanceID()] = 43;

				//_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);	// dunno why this emote sometimes bugs facing
				//_unit->GetAIInterface()->SetNextTarget(Illidan);
			}

			if (DeathEvent[_unit->GetInstanceID()] >= 45)
			{
				switch (DeathEvent[_unit->GetInstanceID()])
				{
				case 45:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "The Light will fill these dismal halls once again. I swear it.");
					_unit->PlaySoundToSet(11387);

					Illidan = NULL;
					Illidan = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), 22917);
					if (Illidan != NULL)
						_unit->GetAIInterface()->SetNextTarget(Illidan);

					_unit->Emote(EMOTE_ONESHOT_TALK);
					break;
				case 49:
					_unit->Emote(EMOTE_ONESHOT_SALUTE);
					break;
				case 53:
					DeathEvent[_unit->GetInstanceID()] = 0;

					_unit->CastSpell(_unit, spells[2].info, spells[2].instant);
					_unit->Despawn(0,0);
					break;
				}
			}

			if (DeathEvent[_unit->GetInstanceID()] >= 44)
				DeathEvent[_unit->GetInstanceID()]++;
		}
	}

	void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					_unit->setAttackTimer(spells[i].attackstoptimer, false);
					spells[i].casttime = t + spells[i].cooldown;
					m_spellcheck[i] = true;
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

    void OnReachWP(uint32 iWaypointId, bool bForwards)
    {
		switch (iWaypointId)
		{
		case 6:
		case 16:
		case 17:
			RegisterAIUpdateEvent(1000);
			EventTimer = 1;
			break;
		case 19:
			_unit->Despawn(0, 0);
			break;
		case 20:
			DeathEvent[_unit->GetInstanceID()] = 49;
			break;
		default:
			{
				_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
				_unit->GetAIInterface()->setWaypointToMove(iWaypointId+1);
			}
		}
    }

    inline WayPoint* CreateWaypoint(int id, uint32 waittime, uint32 flags)
    {
        WayPoint * wp = _unit->CreateWaypointStruct();
        wp->id = id;
        wp->x = ToIllidan[id].mX;
        wp->y = ToIllidan[id].mY;
        wp->z = ToIllidan[id].mZ;
        wp->o = ToIllidan[id].mO;
        wp->waittime = waittime;
        wp->flags = flags;
        wp->forwardemoteoneshot = 0;
        wp->forwardemoteid = 0;
        wp->backwardemoteoneshot = 0;
        wp->backwardemoteid = 0;
        wp->forwardskinid = 0;
        wp->backwardskinid = 0;
        return wp;
    }

	// A bit rewritten FindTarget function
	Unit* FindTarget()
	{
		Unit* target = NULL;
		float distance = 70.0f;
		float z_diff;

		Unit *pUnit;
		float dist;

		for (std::set<Player*>::iterator itr = _unit->GetInRangePlayerSetBegin(); itr != _unit->GetInRangePlayerSetEnd(); itr++)
		{
			pUnit = static_cast<Unit*>((*itr));

			if(pUnit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FEIGN_DEATH))
				continue;

			z_diff = fabs(_unit->GetPositionZ() - pUnit->GetPositionZ());
			if(z_diff > 5.0f)
				continue;

			if(pUnit->m_invisible)
				continue;

			if(!pUnit->isAlive())
				continue;

			dist = Illidan->GetDistance2dSq(pUnit);

			if(dist > distance*distance)
				continue;

			distance = dist;
			target = pUnit;
		}

		return target;
	}

protected:

	float MposX, MposY, MposZ, MposO;
	uint32 SoundLimiter;
	uint32 EventChapter;
	uint32 EventTimer;
	Creature *Udalo;
	Creature *Olum;
	Unit *Illidan;
	int nrspells;
};

/* Maiev AI - Creature AI Class */

#define CN_MAIEV 23197

//#define TELEPORT_MAIEV 41221
#define TELEPORT 34673	// 34673, 41992

class MaievAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(MaievAI);
	SP_AI_Spell spells[1];

    MaievAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		spells[0].info = dbcSpell.LookupEntry(TELEPORT);
		spells[0].targettype = TARGET_SELF;
		spells[0].instant = true;
		spells[0].cooldown = 0;
		spells[0].perctrigger = 0.0f;
		spells[0].attackstoptimer = 0;

		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
		_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
		_unit->GetAIInterface()->SetAllowedToEnterCombat(false);

		SoundTimer = 0;

		RegisterAIUpdateEvent(250);
    }
    
    void OnCombatStart(Unit* mTarget)
    {
		//RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		//_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
    }

    void OnCombatStop(Unit *mTarget)
    {
        //_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        //_unit->GetAIInterface()->SetAIState(STATE_IDLE);

		//_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
        //RemoveAIUpdateEvent();
    }

    void OnDied(Unit * mKiller)
    {
       RemoveAIUpdateEvent();

	   SoundTimer = 0;
    }

	void OnDamageTaken(Unit *mAttacker, float fAmount)
	{
		_unit->SetUInt32Value(UNIT_FIELD_HEALTH, _unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH));
	}

    void AIUpdate()
    {
		_unit->SetUInt32Value(UNIT_FIELD_HEALTH, _unit->GetUInt32Value(UNIT_FIELD_MAXHEALTH));

		Unit *Illidan = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), 22917);

		if (DeathEvent[_unit->GetInstanceID()] == 0)
		{
			if (_unit->GetAIInterface()->GetNextTarget() != NULL && _unit->GetAIInterface()->m_canMove == true)
				SoundTimer++;

			float SayNaisha = (float)RandomFloat(100.0f);
			if ((SayNaisha < 2.5f && SoundTimer >= 100 && SoundTimer < 1330) || SoundTimer == 1361 || SoundTimer > 1400)
			{
				uint32 RandText;
				if (SoundTimer != 1361)
					RandText = rand()%3;
				if (SoundTimer == 1361)
					RandText = rand()%2;
				switch (RandText)	// Not sure if those both should be here, but couldn't find any relation when those are said on blizz
				{
					case 0:
						_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Bleed as I have bled!");	// not sure
						_unit->PlaySoundToSet(11494);

						SoundTimer = 0;
						break;
					case 1:
						_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "That is for Naisha!");
						_unit->PlaySoundToSet(11493);

						SoundTimer = 0;
						break;
					case 2:
						if (Illidan != NULL)
						{
							Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Feel the hatred of ten thousand years!");
							Illidan->PlaySoundToSet(11470);

							SoundTimer = 1337;
					}break;
				}
			}
		}

		if (DeathEvent[_unit->GetInstanceID()] > 0)
		{
			if ((DeathEvent[_unit->GetInstanceID()] <= 25 && Illidan != NULL) || (DeathEvent[_unit->GetInstanceID()] > 25))
			{
				switch (DeathEvent[_unit->GetInstanceID()])
				{
				case 1:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Ah, it is finished. You are beaten.");	// not sure
					_unit->PlaySoundToSet(11496);

					Illidan->Emote(EMOTE_ONESHOT_CUSTOMSPELL06);
					if(Illidan->GetCurrentSpell() != NULL)
						Illidan->GetCurrentSpell()->cancel();

					RemoveAIUpdateEvent();
					RegisterAIUpdateEvent(1000);
					break;
				case 2:
					Illidan->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_CUSTOMSPELL07);

					_unit->GetAIInterface()->SetNextTarget(Illidan);
					break;
				case 5:
					Illidan->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You have won... Maiev. But the huntress... is nothing without the hunt. You... are nothing... without me.");
					Illidan->PlaySoundToSet(11478);

					_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
					//MaievWeaponOff();
					break;
				case 25:{
					GameObject* RightGate = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(745.07f, 241.802f, 354.292f, 200000);
					GameObject* LeftGate  = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(744.829f, 369.276f, 354.324f, 200001);
					if (RightGate != NULL)
						RightGate->SetUInt32Value(GAMEOBJECT_STATE, 0);
					if (LeftGate != NULL)
						LeftGate->SetUInt32Value(GAMEOBJECT_STATE, 0);

					Illidan->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
					Illidan->SetUInt32Value(UNIT_FIELD_HEALTH,0);
					Illidan->setDeathState(JUST_DIED);
					}break;
				case 30:
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "He's right. I feel nothing. I am nothing.");
					_unit->PlaySoundToSet(11497);
					break;
				case 39:
					_unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_AKAMA, ToIllidan[19].mX, ToIllidan[19].mY, ToIllidan[19].mZ, ToIllidan[19].mO, true, false, 0, 0);	// we have one Akama already spawned so we don't need another one =/ (still it's freakin' workaround -.-')
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Farewell, champions.");
					_unit->PlaySoundToSet(11498);
					break;
				case 40:
					_unit->CastSpell(_unit, dbcSpell.LookupEntry(TELEPORT), true);
					break;
				case 41:
					RemoveAIUpdateEvent();

					_unit->Despawn(0,0);
					break;
				}

				if (DeathEvent[_unit->GetInstanceID()] <= 41)
					DeathEvent[_unit->GetInstanceID()]++;
			}

			else
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Farewell, champions.");
				_unit->PlaySoundToSet(11498);
				_unit->Despawn(0,0);
			}
		}
    }

protected:

	uint32 SoundTimer;
};

/* Illidan Stormrage AI - Creature AI Class */

#define CN_ILLIDAN_STORMRAGE 22917

// Normal Form Spells
#define SHEAR								41032  // +
#define DRAW_SOUL							40904  // +
#define FLAME_CRASH							40832  // +
#define MORTAL_STRIKE						37335  // +

// Demon Forms
#define DEMON_FORM1							40511  // +
#define DEMON_FORM2							40398  // +
#define DEMON_FORM3							40510  // +

// Demon Form Spells
#define SHADOW_BLAST						41078  // +
#define SUMMON_DEMON						41117  // - Core Support
#define FLAME_BURST							41131  // ? Haven't Tried	// 41126 is the right one, but it's spell that needs to be scripted

// Illidan's Glaive spells
#define SUMMON_GLAIVE						41466
#define GLAIVE_RETURNS						39873
#define THROW_GLAIVE1						39635
#define THROW_GLAIVE2						39849

// Phase 2 Spells
#define DEMON_FORM							40506
#define AURA_OF_DREAD						41142
#define FIREBALL							40598  // +
#define DARK_BARRAGE						40585  // ? Haven't Tried
#define SUMMON_TEAR_OF_AZZINOTH				39855  // +

#define EYE_BLAST1							39908
#define EYE_BLAST2							40017

#define TEAR_OF_AZZINOTH_CHANNEL			39857

// Phase 3 Spells
#define AGONIZING_FLAMES					40932  // ? Haven't Tried (Before Demon Form!)

// Phase 4 Spells

// Phase 5 Spells
#define ENRAGE								34971  // +

// Other spells
#define SHADOW_PRISON						40647  // +
#define SKULL_INTRO							39656  // + Works with RemoveAura
#define SUMMON_PARASITIC_SHADOWFIENDS		41915  // ? Haven't Tried
#define PARASITIC_SHADOWFIEND1				41914  // ? Haven't Tried
#define PARASITIC_SHADOWFIEND2				41913  // ? Haven't Tried

// Other macros
#define CN_BLADE_OF_AZZINOTH				22996

static Coords ForIllidan[] = 
{
	{  },
	{ 709.783203f, 305.073883f, 362.988770f, 1.546307f },	// Middle pos
	{ 678.703735f, 337.249664f, 362.988770f, 4.741172f },	// Eastern pos
	{ 679.968384f, 284.618011f, 362.988770f, 1.603503f },	// Western pos
	{ 680.798157f, 305.648743f, 353.192200f, 3.196716f }	// Land
};

static Coords UnitPos[]=
{
	{ 676.717346f, 322.445251f, 354.153320f, 5.732623f },	// Blade 1
	{ 677.368286f, 285.374725f, 354.242157f, 5.645614f }	// Blade 2
};

class IllidanStormrageAI : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(IllidanStormrageAI);
	SP_AI_Spell spells[15];
	bool m_spellcheck[15];

    IllidanStormrageAI(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		_unit->GetAIInterface()->addWayPoint(CreateWaypoint(1, 0, FLY));
		_unit->GetAIInterface()->addWayPoint(CreateWaypoint(2, 0, FLY));
		_unit->GetAIInterface()->addWayPoint(CreateWaypoint(3, 0, FLY));
		_unit->GetAIInterface()->addWayPoint(CreateWaypoint(4, 0, FLY));

		nrspells = 5;
		for (int i = 0 ; i < nrspells; i++)
		{
			m_spellcheck[i] = false;
			spells[i].casttime = 0;
		}

        spells[0].info = dbcSpell.LookupEntry(SHEAR);
		spells[0].targettype = TARGET_ATTACKING;
		spells[0].instant = false;
		spells[0].cooldown = 15;
		spells[0].perctrigger = 12.0f;
		spells[0].attackstoptimer = 1000;

        spells[1].info = dbcSpell.LookupEntry(DRAW_SOUL);
		spells[1].targettype = TARGET_VARIOUS;
		spells[1].instant = false;
		spells[1].cooldown = 0;
		spells[1].perctrigger = 0.0f;	// 6.0f	attacks himself too so it can cause crashes if he dies because of his own hit
		spells[1].attackstoptimer = 1000;

        spells[2].info = dbcSpell.LookupEntry(FLAME_CRASH);
		spells[2].targettype = TARGET_DESTINATION;
		spells[2].instant = false;
		spells[2].cooldown = 25;
		spells[2].perctrigger = 12.0f;
		spells[2].attackstoptimer = 1000;

        spells[3].info = dbcSpell.LookupEntry(MORTAL_STRIKE);
		spells[3].targettype = TARGET_ATTACKING;
		spells[3].instant = true;
		spells[3].cooldown = 20;
		spells[3].perctrigger = 8.0f;
		spells[3].attackstoptimer = 1000;

		spells[4].info = dbcSpell.LookupEntry(AGONIZING_FLAMES);
		spells[4].targettype = TARGET_RANDOM_DESTINATION;
		spells[4].instant = true;
		spells[4].cooldown = 25;
		spells[4].perctrigger = 7.0f;
		spells[4].attackstoptimer = 1000;
		spells[4].mindist2cast = 0.0f;
		spells[4].maxdist2cast = 30.0f;
		spells[4].minhp2cast = 0;
		spells[4].maxhp2cast = 100;

        spells[5].info = dbcSpell.LookupEntry(ENRAGE);
		spells[5].targettype = TARGET_SELF;
		spells[5].instant = true;
		spells[5].cooldown = 0;
		spells[5].perctrigger = 0.0f;
		spells[5].attackstoptimer = 1000;
		spells[5].speech = "You've wasted too much time mortals, now you shall fall!";
		spells[5].soundid = 11474;

        spells[6].info = dbcSpell.LookupEntry(SHADOW_BLAST);
		spells[6].targettype = TARGET_DESTINATION;
		spells[6].instant = false;
		spells[6].cooldown = 0;
		spells[6].perctrigger = 0.0f;
		spells[6].attackstoptimer = 1000;

        spells[7].info = dbcSpell.LookupEntry(SUMMON_DEMON);
		spells[7].targettype = TARGET_SELF;	// ?
		spells[7].instant = false;
		spells[7].cooldown = 0;
		spells[7].perctrigger = 0.0f;
		spells[7].attackstoptimer = 1000;

        spells[8].info = dbcSpell.LookupEntry(SHADOW_PRISON);
		spells[8].targettype = TARGET_VARIOUS;
		spells[8].instant = true;
		spells[8].cooldown = 0;
		spells[8].perctrigger = 0.0f;
		spells[8].attackstoptimer = 1000;

		/* Spells after this point are not counted when using the SpellCast() 
		   funct in AI and need to be manually triggered! :-D */
		spells[9].info = dbcSpell.LookupEntry(DEMON_FORM1);
		spells[9].instant = true;
		spells[9].cooldown = 0;
		spells[9].perctrigger = 0.0f;
		spells[9].attackstoptimer = 1000;

		spells[10].info = dbcSpell.LookupEntry(DEMON_FORM2);
		spells[10].instant = true;
		spells[10].cooldown = 0;
		spells[10].perctrigger = 0.0f;

		spells[11].info = dbcSpell.LookupEntry(DEMON_FORM3);
		spells[11].instant = true;
		spells[11].cooldown = 0;
		spells[11].perctrigger = 0.0f;

		spells[12].info = dbcSpell.LookupEntry(FIREBALL);
		spells[12].targettype = TARGET_RANDOM_DESTINATION;
		spells[12].instant = false;
		spells[12].cooldown = 0;
		spells[12].perctrigger = 0.0f;

		spells[13].info = dbcSpell.LookupEntry(DARK_BARRAGE);
		spells[13].targettype = TARGET_RANDOM_SINGLE;
		spells[13].instant = false;
		spells[13].cooldown = 0;
		spells[13].perctrigger = 0.0f;
		spells[13].cooldown = 44;

		spells[14].info = dbcSpell.LookupEntry(EYE_BLAST1);
		spells[14].instant = false;
		spells[14].cooldown = 0;
		spells[14].perctrigger = 0.0f;

		/* Setup Illidan */
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
		_unit->CastSpell(_unit, dbcSpell.LookupEntry(SKULL_INTRO), true);
		_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
		_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
		_unit->GetAIInterface()->m_canMove = false;

		/* Initialize variables and stuff, I Guess */
		FoA1 = FoA2 = Maiev = NULL;
		DeathEvent[_unit->GetInstanceID()] = 0;
		m_phase[_unit->GetInstanceID()] = 0;	// must be 0 to use it with some other stuff.
		DemonSoundRand = false;
		DemonPhaseTimer = 0;
		BladesEvent = 0;
		MaievDialog = 0;
		DemonPhase = 0;
    }

    void OnCombatStart(Unit* mTarget)
    {
		RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
		_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
		_unit->GetAIInterface()->m_canMove = true;

		DeathEvent[_unit->GetInstanceID()] = 0;
		m_phase[_unit->GetInstanceID()] = 1;
		DemonPhaseTimer = 0;
		DemonPhase = 0;

		for (int i = 0; i < nrspells; i++)
			spells[i].casttime = 0;
		spells[13].casttime = 0;
    }

	void OnTargetDied(Unit* mTarget)
    {
		if (_unit->GetHealthPct() > 0)
		{
			int RandomSpeach = rand()%2;
			switch (RandomSpeach)
			{
			case 0:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Who shall be next to taste my blades?!");
				_unit->PlaySoundToSet(11473);
				break;
			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "This is too easy!");
				_unit->PlaySoundToSet(11472);
				break;
			}
		}
    }

    void OnCombatStop(Unit *mTarget)
    {
		std::vector<Creature*> DespawnTable;	/* From M4ksiu - Big THX to Capt who learned me how to use std stuff <3	*/
												/* If anyone wants to use this function, then leave this note!			*/
		for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
		{ 
			if ((*itr)->GetTypeId()== TYPEID_UNIT && (*itr)->GetInstanceID() == _unit->GetInstanceID() && (*itr) != _unit)
			{
				Creature *CreatureToAdd = NULL;
				CreatureToAdd = (Creature*)(*itr);

				if (CreatureToAdd && CreatureToAdd->GetSQL_id() == 0 && (CreatureToAdd->GetEntry() == CN_FLAME_OF_AZZINOTH || 
					CreatureToAdd->GetEntry() == CN_BLADE_OF_AZZINOTH || (_unit->isAlive() && CreatureToAdd->GetEntry() == CN_MAIEV)))
				{
					DespawnTable.push_back(CreatureToAdd);
				} 
			} 
		}

		for (uint32 i = 0; i < DespawnTable.size(); i++)
		{
			Creature *CreatureToDespawn = DespawnTable[i];

			if (CreatureToDespawn)
				CreatureToDespawn->Despawn(0,0);
		}

		DespawnTable.clear();

		_unit->GetAIInterface()->SetAllowedToEnterCombat(true);
		_unit->GetAIInterface()->disable_melee = false;
		_unit->GetAIInterface()->m_moveFly = false;
		_unit->GetAIInterface()->m_canMove = true;

		RemoveAIUpdateEvent();

		_unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
		_unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
		_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
		_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
		if (_unit->FindAura(DEMON_FORM))
			_unit->RemoveAura(DEMON_FORM);
		_unit->SetFloatValue(OBJECT_FIELD_SCALE_X , 1.0f);

		_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
        _unit->GetAIInterface()->SetAIState(STATE_IDLE);

		DemonSoundRand = false;
		DemonPhaseTimer = 0;
		BladesEvent = 0;
		DemonPhase = 0;

		if (m_phase[_unit->GetInstanceID()] == 2)
		{
			_unit->Emote(EMOTE_ONESHOT_LAND);

			WorldPacket data(SMSG_MOVE_UNSET_HOVER, 13);
			data << _unit->GetNewGUID();
			data << uint32(0);
			_unit->SendMessageToSet(&data, false);

			float x = _unit->m_spawn->x;
			float y = _unit->m_spawn->y;
			float z = _unit->m_spawn->z;
			float o = _unit->m_spawn->o;
			
			_unit->GetAIInterface()->MoveTo(x, y, z, o);
		}

		if (_unit->isAlive())
			m_phase[_unit->GetInstanceID()] = 1;
		else
			m_phase[_unit->GetInstanceID()] = 0;

		FoA1 = FoA2 = NULL;
    }

    void OnDied(Unit * mKiller)
    {
		RemoveAIUpdateEvent();

		if (MaievDialog >= 28 && Maiev != NULL && Maiev->isAlive())	// it's workaround (added pointer check, coz if he dies when Maiev is not on battlefield then it will crash server)
		{
			_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
			_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
			_unit->SetUInt32Value(UNIT_FIELD_HEALTH, 1);
			if(_unit->GetCurrentSpell() != NULL)
			    _unit->GetCurrentSpell()->cancel();

			Maiev->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
			Maiev->GetAIInterface()->SetAIState(STATE_IDLE);
			Maiev->WipeTargetList();
			Maiev->WipeHateList();

			DeathEvent[_unit->GetInstanceID()] = 1;
			Maiev = NULL;
		}
		else
		{
			GameObject* RightGate = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(745.07f, 241.802f, 354.292f, 200000);
			GameObject* LeftGate  = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(744.829f, 369.276f, 354.324f, 200001);
			if (RightGate != NULL)
				RightGate->SetUInt32Value(GAMEOBJECT_STATE, 0);
			if (LeftGate != NULL)
				LeftGate->SetUInt32Value(GAMEOBJECT_STATE, 0);
		}
    }

	void AIUpdate()
	{
		if (DemonPhase > 0 && DemonPhase < 75)	// 0;9
		{
			DemonTrans();
		}
		else if (DemonPhase > 75 && DemonPhase < 134)	// 9;17
		{
			TransRevert();
		}
		else
		{
			if (m_phase[_unit->GetInstanceID()] == 1)	// First Phase (without demon form)
			{
				PhaseOne();
			}
			if (m_phase[_unit->GetInstanceID()] == 2)	// Second Phase (Fly phase)
			{
				PhaseTwo();
			}
			if (m_phase[_unit->GetInstanceID()] == 3)	// Third Phase normal form with ability to change into Demon
			{
				PhaseThree();
			}
			if (m_phase[_unit->GetInstanceID()] == 4)	// Fourth Phase Demon Form
			{
				PhaseFour();
			}
			if (m_phase[_unit->GetInstanceID()] == 5)	// Fifth Phase with ability to change into Demon and Enrage
			{
				PhaseFive();
			}
		}
	}

	void PhaseOne()
	{
		if (_unit->GetHealthPct() <= 65 && _unit->GetCurrentSpell() == NULL)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "I will not be touched by a rebels such as you!");	// not sure
			_unit->PlaySoundToSet(11479);

			_unit->GetAIInterface()->MoveTo(_unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ() + 10.0f, _unit->GetOrientation());
			_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
			_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
			_unit->GetAIInterface()->disable_melee = true;
			_unit->GetAIInterface()->m_moveFly = true;
			_unit->Emote(EMOTE_ONESHOT_LIFTOFF);

			WorldPacket data(SMSG_MOVE_SET_HOVER, 13);
            data << _unit->GetNewGUID();
            data << uint32(0);
            _unit->SendMessageToSet(&data, false);

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(500);

			m_phase[_unit->GetInstanceID()] = 2;
			CastCount = 5 + RandomUInt(2);
			TriggerSpawned = false;
			FireWallTimer = 0;
			LastFireWall = 0;
			BladesEvent = 1;
		}
		else
		{
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);	// in OnCombatStart or in Dialog part it doesn't work (in places I wanted to add it)
			float val = (float)RandomFloat(100.0f);
			SpellCast(val);
		}
	}

	void FoASummon()	// little hacky way to spawn them by pushing into world, but proper spell won't work now
	{					// we can eventually add them as pointers and trigger some events from here (like Blade's channeling)
		FoA1 = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_FLAME_OF_AZZINOTH, 672.039246f, 326.748322f, 354.206390f, 0.207343f, true, false, 0, 0);
		FoA2 = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_FLAME_OF_AZZINOTH, 673.008667f, 283.813660f, 354.267548f, 6.203853f, true, false, 0, 0);
		if (FoA1 != NULL)
		{
			Unit *Blade = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[0].mX, UnitPos[0].mY, UnitPos[0].mZ, CN_BLADE_OF_AZZINOTH);
			if (Blade != NULL)
			{
				Blade->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, FoA1->GetGUID());
				Blade->SetUInt32Value(UNIT_CHANNEL_SPELL, TEAR_OF_AZZINOTH_CHANNEL);
			}
		}
		if (FoA2 != NULL)
		{
			Unit *Blade = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[1].mX, UnitPos[1].mY, UnitPos[1].mZ, CN_BLADE_OF_AZZINOTH);
			if (Blade != NULL)
			{
				Blade->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, FoA2->GetGUID());
				Blade->SetUInt32Value(UNIT_CHANNEL_SPELL, TEAR_OF_AZZINOTH_CHANNEL);
			}
		}
	}

	void PhaseTwo()
	{
		if ((BladesEvent && BladesEvent < 20) || (BladesEvent > 24 && BladesEvent < 45))
		{
			switch (BladesEvent)
			{
			case 2:
				_unit->GetAIInterface()->StopMovement(0);
				_unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
				_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
				_unit->GetAIInterface()->setWaypointToMove(1);
				break;
			case 10:	// Blade1 fly
				_unit->CastSpell(_unit, dbcSpell.LookupEntry(THROW_GLAIVE2), false);
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Behold the flames of Azzinoth!");
				_unit->PlaySoundToSet(11480);
				break;
			case 12:
				for (int i = 0; i < 2; i++)
				{
					_unit->CastSpellAoF(UnitPos[i].mX, UnitPos[i].mY, UnitPos[i].mZ, dbcSpell.LookupEntry(THROW_GLAIVE1), false);
				}
				_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
				break;
			case 14:		// Blades spawn
				for (int i = 0; i < 2; i++)
				{
					Creature *Blade = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_BLADE_OF_AZZINOTH, UnitPos[i].mX, UnitPos[i].mY, UnitPos[i].mZ, UnitPos[i].mO, false, false, 0, 0);
					if (Blade != NULL)
					{
						Blade->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
						Blade->GetAIInterface()->SetAllowedToEnterCombat(false);
						Blade->m_noRespawn = true;
					}
				}
				break;
			case 18:		// Flames of Azzinoth Spawn + channeling
				FoASummon();
				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(1000);
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);

				CastCount = 5 + RandomUInt(2);
				TriggerSpawned = false;
				FireWallTimer = 0;
				break;
			case 29:
				for (int i = 0 ; i < 2; i++)
				{
					Creature *Blade = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[i].mX, UnitPos[i].mY, UnitPos[i].mZ, CN_BLADE_OF_AZZINOTH);
					if (Blade != NULL)
					{
						Blade->Despawn(0,0);
					}
				}
				break;
			case 30:		// Blades return
				_unit->CastSpell(_unit, dbcSpell.LookupEntry(GLAIVE_RETURNS), false);
				_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);	// he should also make something like jump emote when weapons are in his hands, but I can't find right one o_O
				break;
			case 34:{
				_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);	
				_unit->GetAIInterface()->m_moveFly = false;
				_unit->Emote(EMOTE_ONESHOT_LAND);

				WorldPacket data(SMSG_MOVE_UNSET_HOVER, 13);
				data << _unit->GetNewGUID();
				data << uint32(0);
				_unit->SendMessageToSet(&data, false);
				}break;
			case 40:	//36
				_unit->GetAIInterface()->SetAllowedToEnterCombat(true);
				_unit->GetAIInterface()->disable_melee = false;
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
				_unit->GetAIInterface()->m_canMove = true;
				_unit->GetAIInterface()->ClearHateList();

				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));

				DemonPhaseTimer = (uint32)time(NULL) + 60;
				m_phase[_unit->GetInstanceID()] = 3;
				TriggerSpawned = false;
				FireWallTimer = 0;
				MaievDialog = 0;
				break;
			}

			if (BladesEvent != 3)
				BladesEvent++;
		}
		else
		{
			uint32 FoADeaths = 2;
			if ((FoA1 != NULL && !FoA1->isAlive()) || FoA1 == NULL)
			{
				Unit *Blade = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[0].mX, UnitPos[0].mY, UnitPos[0].mZ, CN_BLADE_OF_AZZINOTH);
				if (Blade != NULL)
				{
					Blade->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Blade->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				}
				FoADeaths--;
				FoA1 = NULL;
			}
			if ((FoA2 != NULL && !FoA2->isAlive()) || FoA2 == NULL)
			{
				Unit *Blade = _unit->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(UnitPos[1].mX, UnitPos[1].mY, UnitPos[1].mZ, CN_BLADE_OF_AZZINOTH);
				if (Blade != NULL)
				{
					Blade->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					Blade->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
				}
				FoADeaths--;
				FoA2 = NULL;
			}

			FireWallTimer++;
			if (_unit->GetAIInterface()->getMoveType() != MOVEMENTTYPE_WANTEDWP && _unit->GetCurrentSpell() == NULL)
			{
				if (_unit->GetUInt32Value(UNIT_CHANNEL_SPELL) == 0)
				{
					if (FoADeaths == 0)
					{
						_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
						_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
						_unit->GetAIInterface()->m_canMove = true;
						if(_unit->GetCurrentSpell() != NULL)
							_unit->GetCurrentSpell()->cancel();

						_unit->GetAIInterface()->StopMovement(0);
						_unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
						_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
						_unit->GetAIInterface()->setWaypointToMove(4);

						return;
					}
					if (CastCount <= 0)
					{
						if (RandomUInt(2) == 1)	// Move right
						{
							CurrentWP++;
							if (CurrentWP > 3)
								CurrentWP = 1;
						}
						else					// Move left
						{
							CurrentWP--;
							if (CurrentWP < 1)
								CurrentWP = 3;
						}

						_unit->GetAIInterface()->StopMovement(0);
						_unit->GetAIInterface()->SetAIState(STATE_SCRIPTMOVE);
						_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
						_unit->GetAIInterface()->setWaypointToMove(CurrentWP);

						return;
					}
				}
				if (_unit->GetAIInterface()->getCurrentWaypoint() != 4)
				{
					if (FireWallTimer >= 30)
					{
						if (TriggerSpawned == false)
						{
							float posX;
							float posY;
							float posZ;

							uint32 RandomWall = rand()%8+1;
							while ((RandomWall == LastFireWall) || (RandomWall == LastFireWall - 4) || (RandomWall == LastFireWall + 4))
							{
								RandomWall = rand()%8+1;
							}

							switch (RandomWall)
							{
							case 1:
								posX = 642.240601f;
								posY = 297.297180f;
								posZ = 353.423401f;
								break;
							case 2:
								posX = 641.197449f;
								posY = 314.330963f;
								posZ = 353.300262f;
								break;
							case 3:
								posX = 657.239807f;
								posY = 256.925568f;
								posZ = 352.996094f;
								break;
							case 4:
								posX = 657.913330f;
								posY = 353.562775f;
								posZ = 352.996185f;
								break;
							case 5:
								posX = 707.019043f;
								posY = 270.441772f;
								posZ = 352.996063f;
								break;
							case 6:
								posX = 706.592407f;
								posY = 343.425568f;
								posZ = 352.996124f;
								break;
							case 7:
								posX = 706.593262f;
								posY = 310.011475f;
								posZ = 353.693848f;
								break;
							case 8:
								posX = 706.751343f;
								posY = 298.312683f;
								posZ = 353.653809f;
								break;
							}

							Unit *Trigger = NULL;
							Trigger = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_EYE_BEAM_TRIGGER, posX, posY, posZ, 0.0f, false, false, 0, 0);
							if (Trigger != NULL)
							{
								if (_unit->GetCurrentSpell() != NULL)
									_unit->GetCurrentSpell()->cancel();

								_unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, Trigger->GetGUID());
								_unit->SetUInt32Value(UNIT_CHANNEL_SPELL, EYE_BLAST1);
								_unit->CastSpell(Trigger, spells[14].info, true);

								_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Stare into the eyes of the Betrayer!");	// must check this
								_unit->PlaySoundToSet(11481);

								LastFireWall = RandomWall;
								TriggerSpawned = true;
								FireWallTimer = 30;
							}
							else
							{
								FireWallTimer = 0;
								LastFireWall = 0;
							}
						}
						if (TriggerSpawned == true && FireWallTimer >= 42)
						{
							_unit->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
							_unit->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
							_unit->RemoveAura(EYE_BLAST1);

							TriggerSpawned = false;
							FireWallTimer = 0;
						}
					}
					else if (_unit->GetAIInterface()->GetNextTarget())
					{
						Unit* target = NULL;
						target = _unit->GetAIInterface()->GetNextTarget();

						uint32 t = (uint32)time(NULL);
						uint32 Spell = RandomUInt(100);
						if (Spell >= 0 && Spell <= 25)
						{
							CastSpellOnRandomTarget(12, 0.0f, 60.0f, 0, 100);
							CastCount--;
						}
						if (Spell > 25 && Spell <= 35 && t > spells[13].casttime)
						{
							CastSpellOnRandomTarget(13, 0.0f, 60.0f, 0, 100);

							spells[13].casttime = t + spells[13].cooldown;
							CastCount--;
						}
					}
				}
			}
		}
	 }

	void PhaseThree()
	{
		if (_unit->GetHealthPct() <= 30 && MaievDialog == 0 && (DemonPhase <= 0 || DemonPhase >= 135 && _unit->GetCurrentSpell() == NULL))
		{
			#ifdef USE_SHADOW_PRISON
				_unit->GetAIInterface()->StopMovement(1);
				_unit->CastSpell(_unit, spells[8].info, spells[8].instant);
			#endif

			_unit->SetUInt64Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9);
			_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
			_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
			_unit->GetAIInterface()->disable_melee = true;
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
			_unit->GetAIInterface()->m_canMove = false;
			if(_unit->GetCurrentSpell() != NULL)		// keeping it for now, will delete it later anyway
				_unit->GetCurrentSpell()->cancel();

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(1000);

			MaievDialog = 1;
		}
		if (MaievDialog > 0 && MaievDialog < 32 && (DemonPhase <= 0 || DemonPhase >= 135))
		{
			switch (MaievDialog)
			{
			case 3:		// 3
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Is this it, mortals? Is this all the fury you can muster?");
				_unit->PlaySoundToSet(11476);
				break;
			case 6:		// 6
				_unit->Emote(EMOTE_ONESHOT_QUESTION);
				break;
			case 9:
				SpawnMaiev();
				break;
			case 10:
				Maiev->CastSpell(_unit, dbcSpell.LookupEntry(TELEPORT), true);

				_unit->GetAIInterface()->SetNextTarget(Maiev);
				break;
			case 11:	// 12
				Maiev->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Their fury pales before mine, Illidan. We have some unsettled business between us.");
				Maiev->PlaySoundToSet(11491);
				break;
			case 12:	// 13
				MaievWeaponOff();
				break;
			case 13:	// 14
				Maiev->Emote(EMOTE_ONESHOT_EXCLAMATION);
				break;
			case 18:	// 20
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Maiev... How is it even possible?");
				_unit->PlaySoundToSet(11477);
				break;
			case 21:	// 23
					//_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
				break;
			case 24:	// 27
				Maiev->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Ah, my long hunt is finally over. Today, Justice will be done!");
				Maiev->PlaySoundToSet(11492);

				Maiev->Emote(EMOTE_ONESHOT_EXCLAMATION);
				break;
			case 27:	// 30
				Maiev->Emote(EMOTE_ONESHOT_YES);
				break;
			case 28:	// 31
				Maiev->Emote(EMOTE_ONESHOT_ROAR);
				break;
			case 31:	//34
				_unit->GetAIInterface()->SetAllowedToEnterCombat(true);
				_unit->GetAIInterface()->disable_melee = false;
				_unit->SetUInt64Value(UNIT_FIELD_FLAGS, 0);
				_unit->GetAIInterface()->m_canMove = true;

				if (Maiev != NULL && Maiev->isAlive())
				{
					Maiev->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
					Maiev->GetAIInterface()->SetAllowedToEnterCombat(true);
					Maiev->GetAIInterface()->setCurrentAgent(AGENT_NULL);
					Maiev->GetAIInterface()->SetAIState(STATE_IDLE);
					Maiev->GetAIInterface()->m_canMove = true;

					Maiev->GetAIInterface()->AttackReaction(_unit, 1, 0);

					MaievWeaponOn();
				}
					
				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));

				DemonPhaseTimer = (uint32)time(NULL) + 60;	
				m_phase[_unit->GetInstanceID()] = 5;
				EnrageTimer = 10;
				break;
			}

			MaievDialog++;
		}
		else
		{
			uint32 t = (uint32)time(NULL);
			if (t > DemonPhaseTimer)
			{
				_unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);
				_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
				if(_unit->GetCurrentSpell() != NULL)
					_unit->GetCurrentSpell()->cancel();
				
				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(250);

				DemonPhase = 1;
			}
			else
			{
				if (DemonPhase < 1 || DemonPhase > 134)
				{
					_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);
					float val = (float)RandomFloat(100.0f);
					SpellCast(val);
				}
			}
		}
	}

	void DemonTrans()	// check and change how long spell 9 is in use on official
	{
		if(_unit->GetCurrentSpell() != NULL)
			_unit->GetCurrentSpell()->cancel();

		switch (DemonPhase)
		{	// let's give it 4 free triggers to not use melee attacks and spells
		case 5:
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 403);
			_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
			break;
		case 13:
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Behold the power... of the demon within!");
			_unit->PlaySoundToSet(11475);

			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 404);
			break;
		case 33:
			_unit->CastSpell(_unit, DEMON_FORM, true);
			_unit->SetFloatValue(OBJECT_FIELD_SCALE_X , 1.0f);
			break;
		case 43:
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 405);
			break;
		case 53:{
			_unit->GetAIInterface()->ClearHateList();

			Unit *NewTarget = NULL;
			NewTarget = FindTarget();
			if (NewTarget != NULL)
				_unit->GetAIInterface()->modThreatByPtr(NewTarget, 200);
		}break;
		case 61:	//63	//65	// he should also drop aggro and take new target (warlock should take it by dots casted before final change)
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));
			PhaseFour();

			DemonPhaseTimer = (uint32)time(NULL) + 30;
			m_phase[_unit->GetInstanceID()] = 4;
			DemonSoundRand = false;
			DemonPhase = 74;
			break;
		}

		DemonPhase++;
	}

	void TransRevert()	// same here to spell 9 (but not that much I think); also I am thinking about changing spells on emotes
	{
		if(_unit->GetCurrentSpell() != NULL)
			_unit->GetCurrentSpell()->cancel();

		switch (DemonPhase)
		{
		case 81:	// 1 diff is too long?
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 403);
			break;
		case 84:	//85
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 404);
			break;
		case 108:	//108	//109
			if (_unit->FindAura(DEMON_FORM))
				_unit->RemoveAura(DEMON_FORM);
			_unit->SetFloatValue(OBJECT_FIELD_SCALE_X , 1.0f);

			_unit->GetAIInterface()->ClearHateList();
			break;
		case 114:	//116	//117
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 405);
			break;
		case 118:
			_unit->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
			break;
		case 126:
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
			_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);

			if (MaievDialog == 0)
				m_phase[_unit->GetInstanceID()] = 3;
			else
			{
				EnrageTimer = rand()%10+11;
				m_phase[_unit->GetInstanceID()] = 5;
			}

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(_unit->GetUInt32Value(UNIT_FIELD_BASEATTACKTIME));

			DemonPhaseTimer = (uint32)time(NULL) + 60;
			DemonPhase = 135;
			break;
		}

		DemonPhase++;
	}

	void PhaseFour()
	{
		uint32 t = (uint32)time(NULL);
		if (t > DemonPhaseTimer || (_unit->GetHealthPct() <= 30 && MaievDialog == 0))
		{
			_unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(250);

			DemonSoundRand = false;
			DemonPhase = 76;
		}
		if (t <= DemonPhaseTimer - 26 && MaievDialog > 0 && !DemonSoundRand)
		{
			int Sound = rand()%3;	// 66% chance to say something, should work fine
			switch (Sound)
			{
			case 0:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You know nothing of power!");
				_unit->PlaySoundToSet(11469);

				DemonSoundRand = true;
				break;
			case 1:
				_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Such arrogance!");
				_unit->PlaySoundToSet(11471);

				DemonSoundRand = true;
				break;
			}
		}
		else
		{
			if (_unit->GetAIInterface()->GetNextTarget() != NULL && DemonPhase == 75 && _unit->GetCurrentSpell() == NULL)
			{
				Unit *target = NULL;
				target = _unit->GetAIInterface()->GetNextTarget();

				if (_unit->GetDistance2dSq(target) >= 0.0f && _unit->GetDistance2dSq(target) <= 4900.0f)
				{
					_unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);
					_unit->GetAIInterface()->StopMovement(1);

					int Spell = rand()%100;
					if (Spell >= 0 && Spell <= 80)
						_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[6].info, spells[6].instant);
					if (Spell > 80 && Spell <= 90) return;
						//_unit->CastSpell(_unit, spells[7].info, spells[7].instant);	// disabled for now as it can cause some unneeded animations			// both should have _unit as target
					if (Spell > 90 && Spell <= 100)
						_unit->CastSpell(_unit, spells[1].info, spells[1].instant);	// this one needs to be scripted
				}
				else
				{
					_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
				}
			}
		}
	}

	void PhaseFive()
	{
		EnrageTimer--;
		uint32 t = (uint32)time(NULL);
		if (t > DemonPhaseTimer)
		{
			_unit->GetAIInterface()->setCurrentAgent(AGENT_SPELL);
			_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
			if(_unit->GetCurrentSpell() != NULL)
				_unit->GetCurrentSpell()->cancel();

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(250);
			
			DemonPhase = 1;
		}
		if (!EnrageTimer)
		{
			_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You've wasted too much time mortals, now you shall fall!");
			_unit->PlaySoundToSet(11474);

			_unit->CastSpell(_unit, spells[5].info, spells[5].instant);

			return;
		}
		else
		{
			if (DemonPhase < 1 || DemonPhase > 134)
			{
				_unit->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_READY1H);

				float val = (float)RandomFloat(100.0f);
				SpellCast(val);
			}
		}
	}

	void SpellCast(float val)
    {
        if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			float comulativeperc = 0;
		    Unit *target = NULL;
			for(int i=0;i<nrspells;i++)
			{
				if(!spells[i].perctrigger) continue;
				
				if(m_spellcheck[i])
				{
					target = _unit->GetAIInterface()->GetNextTarget();
					switch(spells[i].targettype)
					{
						case TARGET_SELF:
						case TARGET_VARIOUS:
							_unit->CastSpell(_unit, spells[i].info, spells[i].instant); break;
						case TARGET_ATTACKING:
							_unit->CastSpell(target, spells[i].info, spells[i].instant); break;
						case TARGET_DESTINATION:
							_unit->CastSpellAoF(target->GetPositionX(),target->GetPositionY(),target->GetPositionZ(), spells[i].info, spells[i].instant); break;
						case TARGET_RANDOM_FRIEND:
						case TARGET_RANDOM_SINGLE:
						case TARGET_RANDOM_DESTINATION:
							CastSpellOnRandomTarget(i, spells[i].mindist2cast, spells[i].maxdist2cast, spells[i].minhp2cast, spells[i].maxhp2cast); break;
					}
					m_spellcheck[i] = false;
					return;
				}

				uint32 t = (uint32)time(NULL);
				if(val > comulativeperc && val <= (comulativeperc + spells[i].perctrigger) && t > spells[i].casttime)
				{
					if ((i == 4 && m_phase[_unit->GetInstanceID()] == 3) || i != 4)
					{
						_unit->setAttackTimer(spells[i].attackstoptimer, false);
						spells[i].casttime = t + spells[i].cooldown;
						m_spellcheck[i] = true;
					}
				}
				comulativeperc += spells[i].perctrigger;
			}
        }
    }

	void CastSpellOnRandomTarget(uint32 i, float mindist2cast, float maxdist2cast, int minhp2cast, int maxhp2cast)
	{
		if (!maxdist2cast) maxdist2cast = 100.0f;
		if (!maxhp2cast) maxhp2cast = 100;

		if(_unit->GetCurrentSpell() == NULL && _unit->GetAIInterface()->GetNextTarget())
        {
			std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
												/* If anyone wants to use this function, then leave this note!										 */
			for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
			{ 
				if (((spells[i].targettype == TARGET_RANDOM_FRIEND && isFriendly(_unit, (*itr))) || (spells[i].targettype != TARGET_RANDOM_FRIEND && isHostile(_unit, (*itr)) && (*itr) != _unit)) && ((*itr)->GetTypeId()== TYPEID_UNIT || (*itr)->GetTypeId() == TYPEID_PLAYER) && (*itr)->GetInstanceID() == _unit->GetInstanceID()) // isAttackable(_unit, (*itr)) && 
				{
					Unit* RandomTarget = NULL;
					RandomTarget = (Unit*)(*itr);

					if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) >= mindist2cast*mindist2cast && _unit->GetDistance2dSq(RandomTarget) <= maxdist2cast*maxdist2cast && ((RandomTarget->GetHealthPct() >= minhp2cast && RandomTarget->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND) || (_unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0 && isHostile(_unit, RandomTarget))))
					{
						TargetTable.push_back(RandomTarget);
					} 
				} 
			}

			if (_unit->GetHealthPct() >= minhp2cast && _unit->GetHealthPct() <= maxhp2cast && spells[i].targettype == TARGET_RANDOM_FRIEND)
				TargetTable.push_back(_unit);

			if (!TargetTable.size())
				return;

			size_t RandTarget = rand()%TargetTable.size();

			Unit * RTarget = TargetTable[RandTarget];

			if (!RTarget)
				return;

			switch (spells[i].targettype)
			{
			case TARGET_RANDOM_FRIEND:
			case TARGET_RANDOM_SINGLE:
				_unit->CastSpell(RTarget, spells[i].info, spells[i].instant); break;
			case TARGET_RANDOM_DESTINATION:
				_unit->CastSpellAoF(RTarget->GetPositionX(), RTarget->GetPositionY(), RTarget->GetPositionZ(), spells[i].info, spells[i].instant); break;
			}

			TargetTable.clear();
		}
	}

	void SpawnMaiev()	// this doesn't have collision checks! so keep in mind that Maiev can be spawned behind walls!
	{
		float xchange  = (float)RandomFloat(15.0f);
		float distance = 15.0f;

		float ychange = sqrt(distance*distance - xchange*xchange);

		if (rand()%2 == 1)
			xchange *= -1;
		if (rand()%2 == 1)
			ychange *= -1;

		float newposx = _unit->GetPositionX() + xchange;
		float newposy = _unit->GetPositionY() + ychange;

		Maiev = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_MAIEV, newposx, newposy, _unit->GetPositionZ() + 0.5f, 2.177125f, true, false, 0, 0);
		if (Maiev == NULL)
		{
			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(20000);

			MaievDialog = 30;
		}
		else
		{
			Maiev->GetAIInterface()->SetNextTarget(_unit);
		}
	}

	void MaievWeaponOff()
	{
		/*Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 44850);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_01, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_02, 218169346);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_03, 4);
		Maiev->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);*/
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 44850);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_01, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_02, 33488898);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_03, 781);
		Maiev->SetUInt32Value(UNIT_FIELD_BYTES_2, 0);
	}

	void MaievWeaponOn()
	{
		/*Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 44850);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 218169346);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_01, 4);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_02, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_03, 0);
		Maiev->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);*/	
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY, 44850);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO, 33488898);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_01, 781);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_02, 0);
		Maiev->SetUInt32Value(UNIT_VIRTUAL_ITEM_INFO_03, 0);
		Maiev->SetUInt32Value(UNIT_FIELD_BYTES_2, 1);
	}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
    {
		CurrentWP = iWaypointId;
		switch(iWaypointId)
		{
		case 1:
			_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
			_unit->GetAIInterface()->SetAIState(STATE_SCRIPTIDLE);
			_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
			_unit->GetAIInterface()->setWaypointToMove(0);

			if (BladesEvent < 4)
			{
				_unit->GetAIInterface()->ClearHateList();

				RemoveAIUpdateEvent();
				RegisterAIUpdateEvent(500);
				BladesEvent = 4;
			}

			CastCount = 5 + RandomUInt(2);
			break;
		case 2:
		case 3:
			_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
			_unit->GetAIInterface()->SetAIState(STATE_SCRIPTIDLE);
			_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
			_unit->GetAIInterface()->setWaypointToMove(0);

			CastCount = 5 + RandomUInt(2);
			break;
		case 4:
			_unit->GetAIInterface()->m_canMove = false;

			_unit->GetAIInterface()->setCurrentAgent(AGENT_NULL);
			_unit->GetAIInterface()->SetAIState(STATE_SCRIPTIDLE);
			_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_DONTMOVEWP);
			_unit->GetAIInterface()->setWaypointToMove(0);

			RemoveAIUpdateEvent();
			RegisterAIUpdateEvent(500);

			BladesEvent = 25;
			break;
		}
    }

	Unit *FindTarget()
	{
		std::vector<Unit*> TargetTable;		/* From M4ksiu - Big THX to Capt who helped me with std stuff to make it simple and fully working <3 */
											/* If anyone wants to use this function, then leave this note!										 */
		for(set<Object*>::iterator itr = _unit->GetInRangeSetBegin(); itr != _unit->GetInRangeSetEnd(); ++itr) 
		{ 
			if (isHostile(_unit, (*itr)) && (*itr)->GetTypeId() == TYPEID_PLAYER && (*itr)->GetInstanceID() == _unit->GetInstanceID())
			{
				Unit* RandomTarget = NULL;
				RandomTarget = (Unit*)(*itr);
				if (RandomTarget->isAlive() && _unit->GetDistance2dSq(RandomTarget) <= 10000.0f && _unit->GetDistance2dSq(RandomTarget) >= 0.0f && _unit->GetAIInterface()->getThreatByPtr(RandomTarget) > 0)
				{
					TargetTable.push_back(RandomTarget);
				} 
			} 
		}

		if (!TargetTable.size())
			return NULL;

		size_t RandTarget = rand()%TargetTable.size();
		Unit * RTarget = TargetTable[RandTarget];

		if (!RTarget)
			return NULL;

		TargetTable.clear();

		return RTarget;
	}

    inline WayPoint* CreateWaypoint(int id, uint32 waittime, uint32 flags)
    {
        WayPoint * wp = _unit->CreateWaypointStruct();
        wp->id = id;
        wp->x = ForIllidan[id].mX;
        wp->y = ForIllidan[id].mY;
        wp->z = ForIllidan[id].mZ;
        wp->o = ForIllidan[id].mO;
        wp->waittime = waittime;
        wp->flags = flags;
        wp->forwardemoteoneshot = 0;
        wp->forwardemoteid = 0;
        wp->backwardemoteoneshot = 0;
        wp->backwardemoteid = 0;
        wp->forwardskinid = 0;
        wp->backwardskinid = 0;
        return wp;
    }

protected:

	uint32 DemonPhaseTimer;
	uint32 FireWallTimer;
	bool DemonSoundRand;
	uint32 LastFireWall;
	bool TriggerSpawned;
	uint32 BladesEvent;
	uint32 MaievDialog;
	uint32 CurrentWP;
	int EnrageTimer;
	int DemonPhase;
	int CastCount;
	int nrspells;
	Unit* Maiev;
	Unit* FoA1;
	Unit* FoA2;
};

void SetupBlackTemple(ScriptMgr * mgr)
{
	//////////////////////////////////////////////////////////////////////////////////////////
	///////// Mobs
	mgr->register_creature_script(CN_DRAGON_TURTLE, &DragonTurtleAI::Create);
	mgr->register_creature_script(CN_LEVIATHAN, &LeviathanAI::Create);
	mgr->register_creature_script(CN_MUTANT_WAR_HOUND, &MutantWarHoundAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_RIDING_HOUND, &ShadowmoonRidingHoundAI::Create);
	mgr->register_creature_script(CN_SISTER_OF_PLEASURE, &SisterOfPleasureAI::Create);
	mgr->register_creature_script(CN_SISTER_OF_PAIN, &SisterOfPainAI::Create);
	mgr->register_creature_script(CN_PRIESTESS_OF_DEMENTIA, &PriestessOfDementiaAI::Create);
	mgr->register_creature_script(CN_PRIESTESS_OF_DELIGHT, &PriestessOfDelightAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_NIGHTLORD, &IllidariNightlordAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_HEARTSEEKER, &IllidariHeartseekerAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_FEARBRINGER, &IllidariFearbringerAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_DEFILER, &IllidariDefilerAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_CENTURION, &IllidariCenturionAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_BONESLICER, &IllidariBoneslicerAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_BATTLELORD, &AshtongueBattlelordAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_DEFENDER, &AshtongueDefenderAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_ELEMENTALIST, &AshtongueElementalistAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_MYSTIC, &AshtongueMysticAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_PRIMALIST, &AshtonguePrimalistAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_ROGUE, &AshtongueRogueAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_SPIRITBINDER, &AshtongueSpiritbinderAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_STALKER, &AshtongueStalkerAI::Create);
	mgr->register_creature_script(CN_ASHTONGUE_STORMCALLER, &AshtongueStormcallerAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_BEHEMOTH, &BonechewerBehemothAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_BLADE_FURY, &BonechewerBladeFuryAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_BLOOD_PROPHET, &BonechewerBloodProphetAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_BRAWLER, &BonechewerBrawlerAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_COMBATANT, &BonechewerCombatantAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_SHIELD_DISCIPLE, &BonechewerShieldDiscipleAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_SPECTATOR, &BonechewerSpectatorAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_TASKMASTER, &BonechewerTaskmasterAI::Create);
	mgr->register_creature_script(CN_BONECHEWER_WORKER, &BonechewerWorkerAI::Create);
	mgr->register_creature_script(CN_CHARMING_COURTESAN, &CharmingCourtesanAI::Create);
	mgr->register_creature_script(CN_COILSKAR_GENERAL, &CoilskarGeneralAI::Create);
	mgr->register_creature_script(CN_COILSKAR_HARPOONER, &CoilskarHarpoonerAI::Create);
	mgr->register_creature_script(CN_COILSKAR_SEACALLER, &CoilskarSeacallerAI::Create);
	mgr->register_creature_script(CN_COILSKAR_SOOTHSAYER, &CoilskarSoothsayerAI::Create);
	mgr->register_creature_script(CN_COILSKAR_WRANGLER, &CoilskarWranglerAI::Create);
	mgr->register_creature_script(CN_DRAGONMAW_SKY_STALKER, &DragonmawSkyStalkerAI::Create);
	mgr->register_creature_script(CN_DRAGONMAW_WIND_REAVER, &DragonmawWindReaverAI::Create);
	mgr->register_creature_script(CN_DRAGONMAW_WYRMCALLER, &DragonmawWyrmcallerAI::Create);
	mgr->register_creature_script(CN_ENSLAVED_SERVANT, &EnslavedServantAI::Create);
	mgr->register_creature_script(CN_HAND_OF_GOREFIEND, &HandOfGorefiendAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_ARCHON, &IllidariArchonAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_ASSASSIN, &IllidariAssassinAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_BATTLEMAGE, &IllidariBattlemageAI::Create);
	mgr->register_creature_script(CN_ILLIDARI_BLOOD_LORD, &IllidariBloodLordAI::Create);
	mgr->register_creature_script(CN_IMAGE_OF_DEMENTIA, &ImageOfDementiaAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_BLOOD_MAGE, &ShadowmoonBloodMageAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_CHAMPION, &ShadowmoonChampionAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_DEATHSHAPER, &ShadowmoonDeathshaperAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_FALLEN, &ShadowmoonFallenAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_HOUNDMASTER, &ShadowmoonHoundmasterAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_REAVER, &ShadowmoonReaverAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_SOLDIER, &ShadowmoonSoldierAI::Create);
	mgr->register_creature_script(CN_SHADOWMOON_WEAPON_MASTER, &ShadowmoonWeaponMasterAI::Create);
	mgr->register_creature_script(CN_SPELLBOUND_ATTENDANT, &SpellboundAttendantAI::Create);
	mgr->register_creature_script(CN_TEMPLE_CONCUBINE, &TempleConcubineAI::Create);
	mgr->register_creature_script(CN_STORM_FURY, &StormFuryAI::Create);
	mgr->register_creature_script(CN_AQUEOUS_SURGER, &AqueousSurgerAI::Create);
	mgr->register_creature_script(CN_AQUEOUS_SPAWN, &AqueousSpawnAI::Create);
	mgr->register_creature_script(CN_AQUEOUS_LORD, &AqueousLordAI::Create);
	mgr->register_creature_script(CN_PROMENADE_SENTINEL, &PromenadeSentinelAI::Create);
	mgr->register_creature_script(CN_ANGERED_SOUL_FRAGMENT, &AngeredSoulFragmentAI::Create);
	//mgr->register_creature_script(CN_ASHTONGUE_FERAL_SPIRIT, &AshtongueFeralSpiritAI::Create);
	mgr->register_creature_script(CN_ENSLAVED_SOUL, &EnslavedSoulAI::Create);
	mgr->register_creature_script(CN_HUNGERING_SOUL_FRAGMENT, &HungeringSoulFragmentAI::Create);
	mgr->register_creature_script(CN_SHADOWY_CONSTRUCT, &ShadowyConstructAI::Create);
	mgr->register_creature_script(CN_SUFFERING_SOUL_FRAGMENT, &SufferingSoulFragmentAI::Create);
	mgr->register_creature_script(CN_VANGEFUL_SPIRIT, &VangefulSpiritAI::Create);
	mgr->register_creature_script(CN_WRATHBONE_FLAYER, &WrathboneFlayerAI::Create);

	//Bosses
	//mgr->register_creature_script(CN_SUPREMUS, &SupremusAI::Create);
	mgr->register_creature_script(CN_NAJENTUS, &NajentusAI::Create);
	mgr->register_creature_script(CN_GURTOGG_BLOODBOIL, &GurtoggAI::Create);
	/*mgr->register_creature_script(CN_ESSENCEOFSUFFERING, &EssenceOfSufferingAI::Create);
	mgr->register_creature_script(CN_ESSENCEOFDESIRE, &EssenceOfDesireAI::Create);
	mgr->register_creature_script(CN_ESSENCEOFANGER, &EssenceOfAngerAI::Create);*/
	mgr->register_creature_script(CN_MOTHER_SHAHRAZ, &ShahrazAI::Create);
	mgr->register_creature_script(CN_LADY_MALANDE, &MalandeAI::Create);
	mgr->register_creature_script(CN_GATHIOS_THE_SHATTERER, &GathiosAI::Create);
	mgr->register_creature_script(CN_HIGH_NETHERMANCER_ZEREVOR, &ZerevorAI::Create);
	mgr->register_creature_script(CN_VERAS_DARKSHADOW, &VerasAI::Create);
	mgr->register_creature_script(CN_TERON_GOREFIEND, &TeronGorefiendAI::Create);
	//mgr->register_creature_script(CN_SHADE_OF_AKAMA, &ShadeofakamaAI::Create); //test

	//Illidan Stormrage related
	GossipScript * AG = (GossipScript*) new AkamaGossip();
	mgr->register_gossip_script(CN_AKAMA, AG);

	mgr->register_creature_script(CN_DOOR_EVENT_TRIGGER, &DoorEventTriggerAI::Create);
	mgr->register_creature_script(CN_DEMON_FIRE, &DemonFireAI::Create);
	mgr->register_creature_script(CN_EYE_BEAM_TRIGGER, &EyeBeamTriggerAI::Create);
	mgr->register_creature_script(CN_FLAME_CRASH, &FlameCrashAI::Create);
	mgr->register_creature_script(CN_BLAZE, &BlazeAI::Create);
	mgr->register_creature_script(CN_FLAME_OF_AZZINOTH, &FlameOfAzzinothAI::Create);
	mgr->register_creature_script(CN_AKAMA, &AkamaAI::Create);
	mgr->register_creature_script(CN_MAIEV, &MaievAI::Create);
	mgr->register_creature_script(CN_ILLIDAN_STORMRAGE, &IllidanStormrageAI::Create);
}
