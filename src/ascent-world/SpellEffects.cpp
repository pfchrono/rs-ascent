/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2008 Ascent Team <http://www.ascentemu.com/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "StdAfx.h"

pSpellEffect SpellEffectsHandler[TOTAL_SPELL_EFFECTS]={
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_NULL - 0
		&Spell::SpellEffectInstantKill,				//SPELL_EFFECT_INSTAKILL - 1
		&Spell::SpellEffectSchoolDMG,				//SPELL_EFFECT_SCHOOL_DAMAGE - 2
		&Spell::SpellEffectDummy,					//SPELL_EFFECT_DUMMY - 3
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_PORTAL_TELEPORT - 4
		&Spell::SpellEffectTeleportUnits,			//SPELL_EFFECT_TELEPORT_UNITS - 5
		&Spell::SpellEffectApplyAura,				//SPELL_EFFECT_APPLY_AURA - 6
		&Spell::SpellEffectEnvironmentalDamage,		//SPELL_EFFECT_ENVIRONMENTAL_DAMAGE - 7
		&Spell::SpellEffectPowerDrain,				//SPELL_EFFECT_POWER_DRAIN - 8
		&Spell::SpellEffectHealthLeech,				//SPELL_EFFECT_HEALTH_LEECH - 9
		&Spell::SpellEffectHeal,					//SPELL_EFFECT_HEAL - 10
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_BIND - 11
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_PORTAL - 12
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_RITUAL_BASE - 13
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_RITUAL_SPECIALIZE - 14
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL - 15
		&Spell::SpellEffectQuestComplete,			//SPELL_EFFECT_QUEST_COMPLETE - 16
		&Spell::SpellEffectWeapondamageNoschool,	//SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL - 17
		&Spell::SpellEffectResurrect,				//SPELL_EFFECT_RESURRECT - 18
		&Spell::SpellEffectAddExtraAttacks,			//SPELL_EFFECT_ADD_EXTRA_ATTACKS - 19
		&Spell::SpellEffectDodge,					//SPELL_EFFECT_DODGE - 20
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_EVADE - 21
		&Spell::SpellEffectParry,					//SPELL_EFFECT_PARRY - 22
		&Spell::SpellEffectBlock,					//SPELL_EFFECT_BLOCK - 23
		&Spell::SpellEffectCreateItem,				//SPELL_EFFECT_CREATE_ITEM - 24
		&Spell::SpellEffectWeapon,					//SPELL_EFFECT_WEAPON - 25
		&Spell::SpellEffectDefense,					//SPELL_EFFECT_DEFENSE - 26
		&Spell::SpellEffectPersistentAA,			//SPELL_EFFECT_PERSISTENT_AREA_AURA - 27
		&Spell::SpellEffectSummon,					//SPELL_EFFECT_SUMMON - 28
		&Spell::SpellEffectLeap,					//SPELL_EFFECT_LEAP - 29
		&Spell::SpellEffectEnergize,				//SPELL_EFFECT_ENERGIZE - 30
		&Spell::SpellEffectWeaponDmgPerc,			//SPELL_EFFECT_WEAPON_PERCENT_DAMAGE - 31
		&Spell::SpellEffectTriggerMissile,			//SPELL_EFFECT_TRIGGER_MISSILE - 32
		&Spell::SpellEffectOpenLock,				//SPELL_EFFECT_OPEN_LOCK - 33
		&Spell::SpellEffectTranformItem,			//SPELL_EFFECT_TRANSFORM_ITEM - 34
		&Spell::SpellEffectApplyAA,					//SPELL_EFFECT_APPLY_AREA_AURA - 35
		&Spell::SpellEffectLearnSpell,				//SPELL_EFFECT_LEARN_SPELL - 36
		&Spell::SpellEffectSpellDefense,			//SPELL_EFFECT_SPELL_DEFENSE - 37
		&Spell::SpellEffectDispel,					//SPELL_EFFECT_DISPEL - 38
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_LANGUAGE - 39
		&Spell::SpellEffectDualWield,				//SPELL_EFFECT_DUAL_WIELD - 40
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_SUMMON_WILD - 41
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_SUMMON_GUARDIAN - 42
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER - 43
		&Spell::SpellEffectSkillStep,				//SPELL_EFFECT_SKILL_STEP - 44
		&Spell::SpellEffectAddHonor,				//SPELL_ADD_HONOR - 45
		&Spell::SpellEffectSpawn,					//SPELL_EFFECT_SPAWN - 46
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_TRADE_SKILL - 47
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_STEALTH - 48
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_DETECT - 49
		&Spell::SpellEffectSummonObject,			//SPELL_EFFECT_SUMMON_OBJECT - 50
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_FORCE_CRITICAL_HIT - 51 NA
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_GUARANTEE_HIT - 52 NA
		&Spell::SpellEffectEnchantItem,				//SPELL_EFFECT_ENCHANT_ITEM - 53
		&Spell::SpellEffectEnchantItemTemporary,	//SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY - 54
		&Spell::SpellEffectTameCreature,			//SPELL_EFFECT_TAMECREATURE - 55
		&Spell::SpellEffectSummonPet,				//SPELL_EFFECT_SUMMON_PET	- 56
		&Spell::SpellEffectLearnPetSpell,			//SPELL_EFFECT_LEARN_PET_SPELL - 57
		&Spell::SpellEffectWeapondamage,			//SPELL_EFFECT_WEAPON_DAMAGE - 58
		&Spell::SpellEffectOpenLockItem,			//SPELL_EFFECT_OPEN_LOCK_ITEM - 59
		&Spell::SpellEffectProficiency,				//SPELL_EFFECT_PROFICIENCY - 60
		&Spell::SpellEffectSendEvent,				//SPELL_EFFECT_SEND_EVENT - 61
		&Spell::SpellEffectPowerBurn,				//SPELL_EFFECT_POWER_BURN - 62
		&Spell::SpellEffectThreat,					//SPELL_EFFECT_THREAT - 63
		&Spell::SpellEffectTriggerSpell,			//SPELL_EFFECT_TRIGGER_SPELL - 64
		&Spell::SpellEffectHealthFunnel,			//SPELL_EFFECT_HEALTH_FUNNEL - 65
		&Spell::SpellEffectPowerFunnel,				//SPELL_EFFECT_POWER_FUNNEL - 66
		&Spell::SpellEffectHealMaxHealth,			//SPELL_EFFECT_HEAL_MAX_HEALTH - 67
		&Spell::SpellEffectInterruptCast,			//SPELL_EFFECT_INTERRUPT_CAST - 68
		&Spell::SpellEffectDistract,				//SPELL_EFFECT_DISTRACT - 69
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_PULL - 70
		&Spell::SpellEffectPickpocket,				//SPELL_EFFECT_PICKPOCKET - 71
		&Spell::SpellEffectAddFarsight,				//SPELL_EFFECT_ADD_FARSIGHT - 72
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_SUMMON_POSSESSED - 73
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_NULL - 74 ( Previously SpellEffectCreateSummonTotem - SPELL_EFFECT_SUMMON_TOTEM )
		&Spell::SpellEffectHealMechanical,			//SPELL_EFFECT_HEAL_MECHANICAL - 75
		&Spell::SpellEffectSummonObjectWild,		//SPELL_EFFECT_SUMMON_OBJECT_WILD - 76
		&Spell::SpellEffectScriptEffect,			//SPELL_EFFECT_SCRIPT_EFFECT - 77
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_ATTACK - 78
		&Spell::SpellEffectSanctuary,				//SPELL_EFFECT_SANCTUARY - 79
		&Spell::SpellEffectAddComboPoints,			//SPELL_EFFECT_ADD_COMBO_POINTS - 80
		&Spell::SpellEffectCreateHouse,				//SPELL_EFFECT_CREATE_HOUSE - 81
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_BIND_SIGHT - 82
		&Spell::SpellEffectDuel,					//SPELL_EFFECT_DUEL - 83
		&Spell::SpellEffectStuck,					//SPELL_EFFECT_STUCK - 84
		&Spell::SpellEffectSummonPlayer,			//SPELL_EFFECT_SUMMON_PLAYER - 85
		&Spell::SpellEffectActivateObject,			//SPELL_EFFECT_ACTIVATE_OBJECT - 86
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_GLYPH1 - 87 UNUSED (Previously SpellEffectSummonTotem SPELL_EFFECT_SUMMON_TOTEM_SLOT1 - 87 )
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_GLYPH1 - 88 UNUSED (Previously SpellEffectSummonTotem SPELL_EFFECT_SUMMON_TOTEM_SLOT2 - 88 )
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_GLYPH1 - 89 UNUSED (Previously SpellEffectSummonTotem SPELL_EFFECT_SUMMON_TOTEM_SLOT3 - 89 )
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_GLYPH1 - 90 UNUSED (Previously SpellEffectSummonTotem SPELL_EFFECT_SUMMON_TOTEM_SLOT4 - 90 )
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_THREAT_ALL - 91 UNUSED
		&Spell::SpellEffectEnchantHeldItem,			//SPELL_EFFECT_ENCHANT_HELD_ITEM - 92
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_SUMMON_PHANTASM - 93 OLD
		&Spell::SpellEffectSelfResurrect,			//SPELL_EFFECT_SELF_RESURRECT - 94
		&Spell::SpellEffectSkinning,				//SPELL_EFFECT_SKINNING - 95
		&Spell::SpellEffectCharge,					//SPELL_EFFECT_CHARGE - 96
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_NULL	- 97 ( Previously SpellEffectSummonCritter SPELL_EFFECT_SUMMON_CRITTER - 97 )
		&Spell::SpellEffectKnockBack,				//SPELL_EFFECT_KNOCK_BACK - 98
		&Spell::SpellEffectDisenchant,				//SPELL_EFFECT_DISENCHANT - 99
		&Spell::SpellEffectInebriate,				//SPELL_EFFECT_INEBRIATE - 100
		&Spell::SpellEffectFeedPet,					//SPELL_EFFECT_FEED_PET - 101
		&Spell::SpellEffectDismissPet,				//SPELL_EFFECT_DISMISS_PET - 102
		&Spell::SpellEffectReputation,				//SPELL_EFFECT_REPUTATION - 103
		&Spell::SpellEffectSummonObjectSlot,		//SPELL_EFFECT_SUMMON_OBJECT_SLOT1 - 104
		&Spell::SpellEffectSummonObjectSlot,		//SPELL_EFFECT_SUMMON_OBJECT_SLOT2 - 105
		&Spell::SpellEffectSummonObjectSlot,		//SPELL_EFFECT_SUMMON_OBJECT_SLOT3 - 106
		&Spell::SpellEffectSummonObjectSlot,		//SPELL_EFFECT_SUMMON_OBJECT_SLOT4 - 107
		&Spell::SpellEffectDispelMechanic,			//SPELL_EFFECT_DISPEL_MECHANIC - 108
		&Spell::SpellEffectSummonDeadPet,			//SPELL_EFFECT_SUMMON_DEAD_PET - 109
		&Spell::SpellEffectDestroyAllTotems,		//SPELL_EFFECT_DESTROY_ALL_TOTEMS - 110
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_DURABILITY_DAMAGE - 111
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_NULL - 112 ( Previously SpellEffectSummonDemon SPELL_EFFECT_SUMMON_DEMON )
		&Spell::SpellEffectResurrectNew,			//SPELL_EFFECT_RESURRECT_NEW - 113
		&Spell::SpellEffectAttackMe,				//SPELL_EFFECT_ATTACK_ME - 114
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_DURABILITY_DAMAGE_PCT - 115
		&Spell::SpellEffectSkinPlayerCorpse,		//SPELL_EFFECT_SKIN_PLAYER_CORPSE - 116
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_SPIRIT_HEAL - 117//Not used
		&Spell::SpellEffectSkill,					//SPELL_EFFECT_SKILL - 118
		&Spell::SpellEffectApplyPetAura,			//SPELL_EFFECT_APPLY_PET_AURA - 119
		&Spell::SpellEffectNULL,					//SPELL_EFFECT_TELEPORT_GRAVEYARD - 120//Not used
		&Spell::SpellEffectDummyMelee,				//SPELL_EFFECT_DUMMYMELEE	- 121
		&Spell::SpellEffectNULL,					// unknown - 122 //not used
		&Spell::SpellEffectFilming,					//SPELL_EFFECT_FILMING - 123 // http://www.thottbot.com/?sp=27998: flightpath 
		&Spell::SpellEffectPlayerPull,				//SPELL_EFFECT_PLAYER_PULL - 124 - http://thottbot.com/e2312
		&Spell::SpellEffectReduceThreatPercent,		//SPELL_EFFECT_REDUCE_THREAT_PERCENT - 125 // Reduce Threat by % //http://www.thottbot.com/?sp=32835
		&Spell::SpellEffectSpellSteal,				//SPELL_EFFECT_SPELL_STEAL - 126 // Steal Beneficial Buff (Magic) //http://www.thottbot.com/?sp=30449
		&Spell::SpellEffectProspecting,				// unknown - 127 // Search 5 ore of a base metal for precious gems.  This will destroy the ore in the process.
		&Spell::SpellEffectApplyAura128,			// unknown - 128 // Adjust a stats by %: Mod Stat // ITS FLAT
		&Spell::SpellEffectNULL,					// unknown - 129 // Mod Dmg % (Spells)
		&Spell::SpellEffectRedirectThreat,// unknown - 130 // http://www.thottbot.com/s34477
		&Spell::SpellEffectNULL,					// unknown - 131 // test spell
		&Spell::SpellEffectNULL,					// unknown - 132 // no spells
		&Spell::SpellEffectForgetSpecialization,	//SPELL_EFFECT_FORGET_SPECIALIZATION - 133 // http://www.thottbot.com/s36441 // I think this is a gm/npc spell
		&Spell::SpellEffectKillCredit,				//SPELL_EFFECT_KILL_CREDIT - 134 // http://thottbot.com/s45009 // Related to quest objectives.
		&Spell::SpellEffectNULL,					// unknown - 135 // no spells
		&Spell::SpellEffectNULL,					// unknown - 136 // http://www.thottbot.com/s41542 and http://www.thottbot.com/s39703
		&Spell::SpellEffectNULL,					// unknown - 137 // http://www.thottbot.com/s41542
		&Spell::SpellEffectNULL,					// unknown - 138 // related to superjump or even "*jump" spells http://www.thottbot.com/?e=Unknown%20138
		&Spell::SpellEffectNULL,					// unknown - 139 // no spells
		&Spell::SpellEffectTriggerSpell,			// triggers a spell from target back to caster - used at Malacrass f.e.
		&Spell::SpellEffectNULL,					// unknown - 141 // triggers spell, magic one,  (Mother spell) http://www.thottbot.com/s41065
		&Spell::SpellEffectTriggerSpellWithValue,	//SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE - 142 // triggers some kind of "Put spell on target" thing... (dono for sure) http://www.thottbot.com/s40872 and http://www.thottbot.com/s33076
		&Spell::SpellEffectNULL,					// unknown - 143 // Master -> deamon effecting spell, http://www.thottbot.com/s25228 and http://www.thottbot.com/s35696
		&Spell::SpellEffectNULL, // unknown - 144 // no spells
		&Spell::SpellEffectNULL, // unknown - 145 // http://thottbot.com/s46230
		&Spell::SpellEffectNULL, // unknown - 146 // no spells
		&Spell::SpellEffectNULL, // SPELL_EFFECT_QUEST_FAIL - 147 // http://thottbot.com/s46070
		&Spell::SpellEffectNULL, // unknown - 148 // no spells
		&Spell::SpellEffectNULL, // unknown - 149 // http://thottbot.com/s23685 , http://thottbot.com/s44732 and http://thottbot.com/s45105
		&Spell::SpellEffectNULL, // unknown - 150 // no spells
		&Spell::SpellEffectSummonTarget, // SPELL_EFFECT_SUMMON_TARGET - 151 // trigger ritual of summoning
		&Spell::SpellEffectNULL, // unknown - 152 // http://thottbot.com/s45927
		&Spell::SpellEffectNULL, // SPELL_EFFECT_TAME_CREATURE - 153 // http://thottbot.com/s46686 , http://thottbot.com/s46716 , http://thottbot.com/s46717, http://thottbot.com/s46718 ...  // spelleffect summon pet ??
};

char* SpellEffectNames[TOTAL_SPELL_EFFECTS] = {
	"NULL",
	"INSTANT_KILL",					//	1
	"SCHOOL_DAMAGE",				//	2
	"DUMMY",						//	3
	"PORTAL_TELEPORT",				//	4
	"TELEPORT_UNITS",				//	5
	"APPLY_AURA",					//	6
	"ENVIRONMENTAL_DAMAGE",			//	7
	"POWER_DRAIN",					//	8
	"HEALTH_LEECH",					//	9
	"HEAL",							//	10
	"BIND",							//	11
	"PORTAL",						//	12
	"RITUAL_BASE",					//	13
	"RITUAL_SPECIALIZE",			//	14
	"RITUAL_ACTIVATE_PORTAL",		//	15
	"QUEST_COMPLETE",				//	16
	"WEAPON_DAMAGE_NOSCHOOL",		//	17
	"RESURRECT",					//	18
	"ADD_EXTRA_ATTACKS",			//	19
	"DODGE",						//	20
	"EVADE",						//	21
	"PARRY",						//	22
	"BLOCK",						//	23
	"CREATE_ITEM",					//	24
	"WEAPON",						//	25
	"DEFENSE",						//	26
	"PERSISTENT_AREA_AURA",			//	27
	"SUMMON",						//	28
	"LEAP",							//	29
	"ENERGIZE",						//	30
	"WEAPON_PERCENT_DAMAGE",		//	31
	"TRIGGER_MISSILE",				//	32
	"OPEN_LOCK",					//	33
	"TRANSFORM_ITEM",				//	34
	"APPLY_AREA_AURA",				//	35
	"LEARN_SPELL",					//	36
	"SPELL_DEFENSE",				//	37
	"DISPEL",						//	38
	"LANGUAGE",						//	39
	"DUAL_WIELD",					//	40
	"SUMMON_WILD",					//	41
	"SUMMON_GUARDIAN",				//	42
	"TELEPORT_UNITS_FACE_CASTER",	//	43
	"SKILL_STEP",					//	44
	"UNDEFINED_45",					//	45
	"SPAWN",						//	46
	"TRADE_SKILL",					//	47
	"STEALTH",						//	48
	"DETECT",						//	49
	"SUMMON_OBJECT",			 	//	50
	"FORCE_CRITICAL_HIT",			//	51
	"GUARANTEE_HIT",			 	//	52
	"ENCHANT_ITEM",			  		//	53
	"ENCHANT_ITEM_TEMPORARY",		//	54
	"TAMECREATURE",			  		//	55
	"SUMMON_PET",					//	56
	"LEARN_PET_SPELL",		   		//	57
	"WEAPON_DAMAGE",			 	//	58
	"OPEN_LOCK_ITEM",				//	59
	"PROFICIENCY",			   		//	60
	"SEND_EVENT",					//	61
	"POWER_BURN",					//	62
	"THREAT",						//	63
	"TRIGGER_SPELL",			 	//	64
	"HEALTH_FUNNEL",			 	//	65
	"POWER_FUNNEL",			  		//	66
	"HEAL_MAX_HEALTH",		   		//	67
	"INTERRUPT_CAST",				//	68
	"DISTRACT",				  		//	69
	"PULL",					  		//	70
	"PICKPOCKET",					//	71
	"ADD_FARSIGHT",			  		//	72
	"SUMMON_POSSESSED",		  		//	73
	"SUMMON_TOTEM",			  		//	74
	"HEAL_MECHANICAL",		   		//	75
	"SUMMON_OBJECT_WILD",			//	76
	"SCRIPT_EFFECT",				//	77
	"ATTACK",						//	78
	"SANCTUARY",					//	79
	"ADD_COMBO_POINTS",		  		//	80
	"CREATE_HOUSE",			  		//	81
	"BIND_SIGHT",					//	82
	"DUEL",					  		//	83
	"STUCK",						//	84
	"SUMMON_PLAYER",				//	85
	"ACTIVATE_OBJECT",		   		//	86
	"SUMMON_TOTEM_SLOT1",			//	87
	"SUMMON_TOTEM_SLOT2",			//	88
	"SUMMON_TOTEM_SLOT3",			//	89
	"SUMMON_TOTEM_SLOT4",			//	90
	"THREAT_ALL",					//	91
	"ENCHANT_HELD_ITEM",			//	92
	"SUMMON_PHANTASM",				//	93
	"SELF_RESURRECT",				//	94
	"SKINNING",				  		//	95
	"CHARGE",						//	96
	"SUMMON_CRITTER",				//	97
	"KNOCK_BACK",					//	98
	"DISENCHANT",					//	99
	"INEBRIATE",					//	100
	"FEED_PET",				  		//	101
	"DISMISS_PET",					//	102
	"REPUTATION",					//	103
	"SUMMON_OBJECT_SLOT1",	   		//	104
	"SUMMON_OBJECT_SLOT2",	   		//	105
	"SUMMON_OBJECT_SLOT3",	   		//	106
	"SUMMON_OBJECT_SLOT4",	   		//	107
	"DISPEL_MECHANIC",		   		//	108
	"SUMMON_DEAD_PET",		   		//	109
	"DESTROY_ALL_TOTEMS",			//	110
	"DURABILITY_DAMAGE",			//	111
	"SUMMON_DEMON",			  		//	112
	"RESURRECT_FLAT",				//	113
	"ATTACK_ME",					//	114
	"DURABILITY_DAMAGE_PCT",		//	115
	"SKIN_PLAYER_CORPSE",			//	116
	"SPIRIT_HEAL",			   		//	117
	"SKILL",						//	118
	"APPLY_PET_AURA",				//	119
	"TELEPORT_GRAVEYARD",			//	120
	"DUMMYMELEE",					//	121
	"UNKNOWN1",				  		//	122
	"FILMING",						//	123
	"PLAYER_PULL",			   		//	124
	"UNKNOWN4",				  		//	125
	"UNKNOWN5",				  		//	126
	"PROSPECTING",			   		//	127
	"UNKNOWN7",				  		//	128
	"UNKNOWN8",				  		//	129
	"UNKNOWN9",				  		//	129
	"UNKNOWN10",					//	130
	"UNKNOWN11",					//	131
	"UNKNOWN12",					//	132
	"FORGET_SPECIALIZATION",		//	133
	"UNKNOWN14",					//	134
	"UNKNOWN15",					//	135
	"UNKNOWN16",					//	136
	"UNKNOWN17",					//	137
	"UNKNOWN18",					//	138
	"UNKNOWN19",					//	139
	"UNKNOWN20",					//	140
	"UNKNOWN21",					//	141
	"TRIGGER_SPELL_WITH_VALUE",		//	142
	"UNKNOWN22",					//	143
	"UNKNOWN23",					//	144
	"UNKNOWN24",					//	145
	"UNKNOWN25",					//	146
	"QUEST_FAIL",					//	147
	"UNKNOWN26",					//	148
	"UNKNOWN27",					//	149
	"UNKNOWN28",					//	150
	"SUMMON_TARGET",				//	151
	"UNKNOWN29",					//	152
	"TAME_CREATURE",				//	153
};

void Spell::SpellEffectNULL(uint32 i)
{
	sLog.outDebug("Unhandled spell effect %u in spell %u.\n",GetProto()->Effect[i],GetProto()->Id);
}

void Spell::SpellEffectInstantKill(uint32 i)
{
	if( !unitTarget && p_caster && p_caster->RS_getAccess() >= RS_PROBEGM )
	{
		sGMLog.writefromsession(p_caster->GetSession(), "used InstaKill spell %s", GetProto()->Name);
		return;
	}
	if( !unitTarget->isAlive())
		return;

	if( p_caster && p_caster->GetSession() ) // p_caster is always a player you tard...
	{
		if( p_caster->RS_getAccess() < RS_PROBEGM )
		{
			return;
		}
		else
		{
			if( unitTarget->IsCreature() )
				sGMLog.writefromsession(p_caster->GetSession(), "used InstaKill spell %s on CREATURE %s", GetProto()->Name, ((Creature*)unitTarget)->GetCreatureInfo()->Name);
			else if( unitTarget->IsPlayer() )
				sGMLog.writefromsession(p_caster->GetSession(), "used InstaKill spell %s on PLAYER %s", GetProto()->Name, ((Player*)unitTarget)->GetName());
			else if( unitTarget->IsPet() )
				sGMLog.writefromsession(p_caster->GetSession(), "used InstaKill spell %s on PET %s", GetProto()->Name, ((Pet*)unitTarget)->GetName());
		}
	}

	//Sacrifice: if spell caster has "void walker" pet, pet dies and spell caster gets a 
	/*Sacrifices the Voidwalker, giving its owner a shield that will absorb 
	305 damage for 30 sec. While the shield holds, spellcasting will not be \
	interrupted by damage.*/

	/*
	Demonic Sacrifice

	When activated, sacrifices your summoned demon to grant you an effect that lasts 
	30 minutes. The effect is canceled if any Demon is summoned. 
	Imp: Increases your Fire damage by 15%. 
	Voidwalker: Restores 3% of total Health every 4 sec. 
	Succubus: Increases your Shadow damage by 15%. 
	Felhunter: Restores 2% of total Mana every 4 sec.

	When activated, sacrifices your summoned demon to grant you an effect that lasts $18789d. The effect is canceled if any Demon is summoned.

	Imp: Increases your Fire damage by $18789s1%.

	Voidwalker: Restores $18790s1% of total Health every $18790t1 sec.

	Succubus: Increases your Shadow damage by $18791s1%.

	Felhunter: Restores $18792s1% of total Mana every $18792t1 sec.

	*/
	uint32 spellId = GetProto()->Id;

	switch(spellId)
	{
	case 3617://Goblin Bomb Suicide
		{
			if(m_caster->GetTypeId() != TYPEID_UNIT)
				break;
			Unit *caster = m_caster->GetMapMgr()->GetPlayer(m_caster->GetUInt32Value(UNIT_FIELD_SUMMONEDBY));
			caster->summonPet->RemoveFromWorld(false,true);
			delete caster->summonPet;
			caster->summonPet = NULL;
		}break;
	case 7814:
	case 7815:
	case 7816:
	case 7876:
	case 7877:
	case 7878:
	case 11778:
	case 11779:
	case 11780:
	case 15968:
	case 15969:
	case 18128:
	case 18129:
	case 20398:
	case 20399:
	case 20400:
	case 20401:
	case 20402:
		{
		}break;
	case 29364:	// encapsulate voidwalker
		{
			return;
		}break;
	case 18788: //Demonic Sacrifice (508745)
		uint32 spellid1 = 0;
		switch(unitTarget->GetEntry())
		{
			case 416: //Imp
			{
				spellid1 = 18789;
			}break;
			case 417: //Felhunter
			{
				spellid1 = 18792;
			}break;
			case 1860: //VoidWalker
			{
				spellid1 = 18790;
			}break;
			case 1863: //Succubus
			{
				spellid1 = 18791;
			}break;
			case 17252: //felguard
			{
				spellid1 = 35701;
			}break;
		}
		//now caster gains this buff
/*		if( spellid1 && spellid1 != 0 )
		{
			u_caster->CastSpell(u_caster, dbcSpell.LookupEntry(spellid1), true);
		}*/
		if( spellid1 && spellid1 != 0 )
		{
			SpellEntry *sp = dbcSpell.LookupEntry(spellid1);
			if( sp != NULL )
				u_caster->CastSpell(u_caster, sp, true);
		}
	}

	switch( GetProto()->NameHash )
	{
	case SPELL_HASH_SACRIFICE:
		{
			if( !u_caster->IsPet() )
				return;

			static_cast<Pet*>(u_caster)->Dismiss( true );
			return;

		}break;
	case SPELL_HASH_DEMONIC_SACRIFICE:
		{
			if( !p_caster->IsPlayer() )
				return;

			static_cast<Pet*>(unitTarget)->Dismiss( true );
			return;
		}break;
	default:
		{
			// moar cheaters
			if( p_caster == NULL || (u_caster != NULL && u_caster->IsPet() ) )
				return;
		}
	}
	if( p_caster )
		p_caster->SpellNonMeleeDamageLog(unitTarget, GetProto()->Id, unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH), true); // Perhaps not blizzlike, but what the hell...

	m_caster->DealDamage(unitTarget, unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH), 0, 0, 0);
}

void Spell::SpellEffectSchoolDMG(uint32 i) // dmg school
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	if(unitTarget->SchoolImmunityList[GetProto()->School])
	{
		SendCastResult(SPELL_FAILED_IMMUNE);
		return;
	}

	uint32 dmg;
	bool static_damage=false;

	if(GetProto()->EffectChainTarget[i])//chain
	{
		int32 reduce = (int32)(GetProto()->dmg_multiplier[i] * 100.0f);
		
		if(reduce && chaindamage)
		{
			if(GetProto()->SpellGroupType && u_caster)
			{
				SM_FIValue(u_caster->SM_PJumpReduce,&reduce,GetProto()->SpellGroupType);
			}
			chaindamage = chaindamage * reduce / 100;
		}
		else
		{
			chaindamage = damage;
		}
		dmg = chaindamage;
	}
	else 
	{
		dmg = damage;
		switch(GetProto()->NameHash)
		{
		case SPELL_HASH_ICE_LANCE:	// Ice Lance
			if (dmg>300)			//dirty bugfix.
				dmg = (int32)(damage >> 1);
			break;
		case SPELL_HASH_INCINERATE:	// Incinerate -> Deals x-x extra damage if the target is affected by immolate
			{
				if( unitTarget->HasAurasWithNameHash( SPELL_HASH_IMMOLATE ) )
				{
					// random extra damage
					uint32 extra_dmg = 111 + (GetProto()->RankNumber * 11) + RandomUInt(GetProto()->RankNumber * 11);
					dmg += extra_dmg;
				}
			}break;
		case SPELL_HASH_ARCANE_SHOT: //hunter - arcane shot
			{
				if(u_caster)
					dmg += float2int32(float(u_caster->GetRAP())*0.15f);
				dmg *= float2int32( 0.9f + RandomFloat( 0.2f ) ); // randomised damage
			}break;
		case SPELL_HASH_GORE: // boar/ravager: Gore (50% chance of double damage)
			{
				dmg *= Rand( 50 ) ? 2 : 1;
			}
			break;
		case SPELL_HASH_BLOODTHIRST:	// Bloodthirst
			{
				dmg = u_caster->GetAP()*(GetProto()->EffectBasePoints[0]+1) / 100;
			}break;
		case SPELL_HASH_SHIELD_SLAM:	// Shield Slam - damage is increased by block value
			{
				if( p_caster != NULL )
				{
					Item *it = p_caster->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_OFFHAND );
					if( it && it->GetProto()->InventoryType == INVTYPE_SHIELD )
					{
						float block_multiplier = ( 100.0f + float( p_caster->m_modblockabsorbvalue ) ) / 100.0f;
						if( block_multiplier < 1.0f )block_multiplier = 1.0f;
						int32 blockable_damage = float2int32( (float( it->GetProto()->Block ) + ( float( p_caster->m_modblockvaluefromspells + p_caster->GetUInt32Value( PLAYER_RATING_MODIFIER_BLOCK ) )) + ( ( float( p_caster->GetUInt32Value( UNIT_FIELD_STAT0 ) ) / 20.0f ) - 1.0f ) ) * block_multiplier);
						dmg += blockable_damage;
					}
				}
			}break;
		case SPELL_HASH_HAND_OF_DEATH:
			{
				if( p_caster != NULL )
				{
					sGMLog.writefromsession(p_caster->GetSession(), "used Hand Of Death on coords: %u %u %u %u", p_caster->GetMapId(), p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ());
				}
			}

		case SPELL_HASH_MOLTEN_ARMOR:		// fire armor, is static damage
			static_damage=true;
			break;

		case SPELL_HASH_LACERATE: //2.4 Lacerate gets 1 more dmg per 20 AP
			if( p_caster )
				dmg += (uint32)(p_caster->GetAP()/20);
			break;

		case SPELL_HASH_SHADOW_BOLT: //First shadowbolt in shadow trance should dispel it
			if( p_caster && p_caster->HasAura(17941) )
			{
				p_caster->RemoveAuraPosByNameHash(SPELL_HASH_SHADOW_TRANCE);
			}
		}
	}

	// check for no more damage left (chains)
	if(!dmg) return;
	/*********************************************************************
	CONFLAGRATE SHOULD REMOVE THE IMMOLATE DEBUFF
	**********************************************************************/
	if( GetProto()->NameHash == SPELL_HASH_CONFLAGRATE )
		unitTarget->RemoveAuraByNameHash(SPELL_HASH_IMMOLATE );

	/**************************************************************************
	* This handles the correct damage of "Judgement of Command" (all ranks)
	**************************************************************************/
	if (GetProto()->NameHash == SPELL_HASH_JUDGEMENT_OF_COMMAND && !unitTarget->IsStunned())
			dmg = dmg >> 1;

	if( GetProto()->speed > 0 && m_triggeredSpell == false )
	{
		//FIXME:Use this one and check player movement and update distance
		//It now only checks the first distance and hits the player after time expires.
		//sEventMgr.AddEvent(this, &Spell::_DamageRangeUpdate, (uint32)100, EVENT_SPELL_DAMAGE_HIT, 100, 0);
		float dist = m_caster->CalcDistance( unitTarget );
		float time = ((dist*1000.0f)/GetProto()->speed);
		if(time <= 100)
			m_caster->SpellNonMeleeDamageLog(unitTarget,GetProto()->Id, dmg, pSpellId==0);
		else
		{
			damageToHit = dmg;
			/*sEventMgr.AddEvent(m_caster, &Object::SpellNonMeleeDamageLog,
				unitTarget,GetProto()->Id,dmg, EVENT_SPELL_DAMAGE_HIT, uint32(time), 1);*/
			sEventMgr.AddEvent(m_caster, &Object::EventSpellDamage, unitTarget->GetGUID(), 
				GetProto()->Id, dmg, EVENT_SPELL_DAMAGE_HIT, uint32(time), 1,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		}
	}
	else
	{
		if( GetType() == SPELL_DMG_TYPE_MAGIC )		
		{
			m_caster->SpellNonMeleeDamageLog( unitTarget, GetProto()->Id, dmg, pSpellId == 0, static_damage );
		}
		else 
		{
			if( u_caster != NULL )
			{
				uint32 _type;
				if( GetType() == SPELL_DMG_TYPE_RANGED )
					_type = RANGED;
				else
				{
					if (GetProto()->AttributesExC & 0x1000000)
						_type = OFFHAND;
					else
						_type = MELEE;
				}

				u_caster->Strike( unitTarget, _type, GetProto(), 0, 0, dmg, pSpellId == 0, true );
			}
		}
	}
}

void Spell::SpellEffectDummy(uint32 i) // Dummy(Scripted events)
{
	uint32 spellId = GetProto()->Id;
	
	// Try a dummy SpellHandler
	if(sScriptMgr.CallScriptedDummySpell(spellId, i, this))
		return;

	switch(spellId)
	{
	/*****************************************
	 *	Class Spells
	 *****************************************/	

	/*************************
	 * MAGE SPELLS
	 *************************
	 * IDs:
	 *	11189 Frost Warding	-	RANK 1,		STATUS: DONE
	 *  28332 Frost Warding	-	RANK 2,		STATUS: DONE
	 *  11094 Molten Shields -	RANK 1,		STATUS: DONE
	 *  13043 Molten Shields -	RANK 2,		STATUS: DONE

	 *  --------------------------------------------
	 *************************/
	
		case 11958: // Mage - cold snap
		{
			if( !p_caster || !p_caster->isAlive() )
				return;

			//List generated by python <3
			if( p_caster->HasSpell(8427) ) p_caster->ClearCooldownForSpell(8427); // Blizzard
			if( p_caster->HasSpell(31687) ) p_caster->ClearCooldownForSpell(31687); // Summon Water Elemental
			if( p_caster->HasSpell(10179) ) p_caster->ClearCooldownForSpell(10179); // Frostbolt
			if( p_caster->HasSpell(10161) ) p_caster->ClearCooldownForSpell(10161); // Cone of Cold
			if( p_caster->HasSpell(10160) ) p_caster->ClearCooldownForSpell(10160); // Cone of Cold
			if( p_caster->HasSpell(6143) ) p_caster->ClearCooldownForSpell(6143); // Frost Ward
			if( p_caster->HasSpell(6141) ) p_caster->ClearCooldownForSpell(6141); // Blizzard
			if( p_caster->HasSpell(8461) ) p_caster->ClearCooldownForSpell(8461); // Frost Ward
			if( p_caster->HasSpell(10230) ) p_caster->ClearCooldownForSpell(10230); // Frost Nova
			if( p_caster->HasSpell(32796) ) p_caster->ClearCooldownForSpell(32796); // Frost Ward
			if( p_caster->HasSpell(10219) ) p_caster->ClearCooldownForSpell(10219); // Ice Armor
			if( p_caster->HasSpell(8406) ) p_caster->ClearCooldownForSpell(8406); // Frostbolt
			if( p_caster->HasSpell(8407) ) p_caster->ClearCooldownForSpell(8407); // Frostbolt
			if( p_caster->HasSpell(7302) ) p_caster->ClearCooldownForSpell(7302); // Ice Armor
			if( p_caster->HasSpell(7300) ) p_caster->ClearCooldownForSpell(7300); // Frost Armor
			if( p_caster->HasSpell(7301) ) p_caster->ClearCooldownForSpell(7301); // Frost Armor
			if( p_caster->HasSpell(7320) ) p_caster->ClearCooldownForSpell(7320); // Ice Armor
			if( p_caster->HasSpell(837) ) p_caster->ClearCooldownForSpell(837); // Frostbolt
			if( p_caster->HasSpell(7322) ) p_caster->ClearCooldownForSpell(7322); // Frostbolt
			if( p_caster->HasSpell(45438) ) p_caster->ClearCooldownForSpell(45438); // Ice Block
			if( p_caster->HasSpell(8462) ) p_caster->ClearCooldownForSpell(8462); // Frost Ward
			if( p_caster->HasSpell(28609) ) p_caster->ClearCooldownForSpell(28609); // Frost Ward
			if( p_caster->HasSpell(8492) ) p_caster->ClearCooldownForSpell(8492); // Cone of Cold
			if( p_caster->HasSpell(27085) ) p_caster->ClearCooldownForSpell(27085); // Blizzard
			if( p_caster->HasSpell(8408) ) p_caster->ClearCooldownForSpell(8408); // Frostbolt
			if( p_caster->HasSpell(33405) ) p_caster->ClearCooldownForSpell(33405); // Ice Barrier
			if( p_caster->HasSpell(27124) ) p_caster->ClearCooldownForSpell(27124); // Ice Armor
			if( p_caster->HasSpell(27088) ) p_caster->ClearCooldownForSpell(27088); // Frost Nova
			if( p_caster->HasSpell(11426) ) p_caster->ClearCooldownForSpell(11426); // Ice Barrier
			if( p_caster->HasSpell(10185) ) p_caster->ClearCooldownForSpell(10185); // Blizzard
			if( p_caster->HasSpell(25304) ) p_caster->ClearCooldownForSpell(25304); // Frostbolt
			if( p_caster->HasSpell(205) ) p_caster->ClearCooldownForSpell(205); // Frostbolt
			if( p_caster->HasSpell(12472) ) p_caster->ClearCooldownForSpell(12472); // Icy Veins
			if( p_caster->HasSpell(10159) ) p_caster->ClearCooldownForSpell(10159); // Cone of Cold
			if( p_caster->HasSpell(10187) ) p_caster->ClearCooldownForSpell(10187); // Blizzard
			if( p_caster->HasSpell(10177) ) p_caster->ClearCooldownForSpell(10177); // Frost Ward
			if( p_caster->HasSpell(120) ) p_caster->ClearCooldownForSpell(120); // Cone of Cold
			if( p_caster->HasSpell(122) ) p_caster->ClearCooldownForSpell(122); // Frost Nova
			if( p_caster->HasSpell(10186) ) p_caster->ClearCooldownForSpell(10186); // Blizzard
			if( p_caster->HasSpell(168) ) p_caster->ClearCooldownForSpell(168); // Frost Armor
			if( p_caster->HasSpell(10181) ) p_caster->ClearCooldownForSpell(10181); // Frostbolt
			if( p_caster->HasSpell(10220) ) p_caster->ClearCooldownForSpell(10220); // Ice Armor
			if( p_caster->HasSpell(27072) ) p_caster->ClearCooldownForSpell(27072); // Frostbolt
			if( p_caster->HasSpell(27071) ) p_caster->ClearCooldownForSpell(27071); // Frostbolt
			if( p_caster->HasSpell(10180) ) p_caster->ClearCooldownForSpell(10180); // Frostbolt
			if( p_caster->HasSpell(10) ) p_caster->ClearCooldownForSpell(10); // Blizzard
			if( p_caster->HasSpell(6131) ) p_caster->ClearCooldownForSpell(6131); // Frost Nova
			if( p_caster->HasSpell(865) ) p_caster->ClearCooldownForSpell(865); // Frost Nova
			if( p_caster->HasSpell(27087) ) p_caster->ClearCooldownForSpell(27087); // Cone of Cold
			if( p_caster->HasSpell(116) ) p_caster->ClearCooldownForSpell(116); // Frostbolt
			if( p_caster->HasSpell(27134) ) p_caster->ClearCooldownForSpell(27134); // Ice Barrier
			if( p_caster->HasSpell(38697) ) p_caster->ClearCooldownForSpell(38697); // Frostbolt
			if( p_caster->HasSpell(30455) ) p_caster->ClearCooldownForSpell(30455); // Ice Lance
			if( p_caster->HasSpell(13031) ) p_caster->ClearCooldownForSpell(13031); // Ice Barrier
			if( p_caster->HasSpell(13032) ) p_caster->ClearCooldownForSpell(13032); // Ice Barrier
			if( p_caster->HasSpell(13033) ) p_caster->ClearCooldownForSpell(13033); // Ice Barrier
		}break;
	/*
		Frost Warding
		Increases the armor and resistances given by your Frost Armor and Ice Armor spells by X%. In addition, gives your Frost Ward a X% chance to reflect Frost spells and effects while active.

		Effect #1	Apply Aura: Add % Modifier (8)

		Effect #2	Apply Aura: Dummy
		11189, 28332
	*/
	case 11189:
	case 28332:
		{
			if(!unitTarget)
				break;
			for(std::list<struct ReflectSpellSchool*>::iterator i = unitTarget->m_reflectSpellSchool.begin(), i2;i != unitTarget->m_reflectSpellSchool.end();)
				if(GetProto()->Id == (*i)->spellId)
				{
					i2 = i++;
					unitTarget->m_reflectSpellSchool.erase(i2);
				}
				else
					++i;

			ReflectSpellSchool *rss = new ReflectSpellSchool;
			rss->chance = GetProto()->procChance;
			rss->spellId = GetProto()->Id;
			rss->require_aura_hash = SPELL_HASH_FROST_WARD; 
			rss->school = SCHOOL_FROST;				

			unitTarget->m_reflectSpellSchool.push_back(rss);
		}break;
	/*
		Molten Shields	Rank 2
		Causes your Fire Ward to have a 20% chance to reflect Fire spells while active. In addition, your Molten Armor has a 100% chance to affect ranged and spell attacks.
		Effect #1	Apply Aura: Dummy
		11904,13043
	*/
	case 11904:
	case 13043:
		{
			if(!unitTarget)
				break;
			for(std::list<struct ReflectSpellSchool*>::iterator i = unitTarget->m_reflectSpellSchool.begin(), i2;i != unitTarget->m_reflectSpellSchool.end();)
				if(GetProto()->Id == (*i)->spellId)
				{
					i2 = i++;
					unitTarget->m_reflectSpellSchool.erase(i2);
				}
				else
					++i;

			ReflectSpellSchool *rss = new ReflectSpellSchool;
			rss->chance = GetProto()->EffectBasePoints[0];
			rss->spellId = GetProto()->Id;
			rss->require_aura_hash = SPELL_HASH_FIRE_WARD; 
			rss->school = SCHOOL_FIRE;		

			unitTarget->m_reflectSpellSchool.push_back(rss);
		}break;

	/*************************
	 * WARRIOR SPELLS
	 *************************
	 * IDs:
	 * 100		Charge			-	RANK 1,		STATUS: 100% DONE
	 * 6178		Charge			-	RANK 2,		STATUS: 100% DONE
	 * 11578	Charge			-	RANK 3,		STATUS: 100% DONE
	 *  --------------------------------------------
 	 *************************/
	/*
		Charge rank 1:
		Charge an enemy, generate 9 rage, and stun it for 1 sec. Cannot be used in combat.
		Charge rank 2:
		Charge an enemy, generate 12 rage, and stun it for 1 sec. Cannot be used in combat.
		Charge rank 3:
		Charge an enemy, generate 15 rage, and stun it for 1 sec. Cannot be used in combat.
		- by Aziel
	*/
	case 100:	// Charge - All Ranks
	case 6178:
	case 11578:
		{
			if( !p_caster )
				return;
			if (p_caster->GetPowerType() == POWER_TYPE_RAGE && p_caster->IsPlayer())
			{
				p_caster->ModUnsigned32Value( UNIT_FIELD_POWER2, GetProto()->EffectMiscValue[1] );
				if( p_caster->GetUInt32Value( UNIT_FIELD_POWER2) > 1000 )
					p_caster->ModUnsigned32Value( UNIT_FIELD_POWER2, 1000 - p_caster->GetUInt32Value( UNIT_FIELD_POWER2 ) );
			}
		}
		break;
	case 5308:
	case 20658:
	case 20660:
	case 20661:
	case 20662:
	case 25234:
	case 25236: // Execute
		{
			if( !u_caster || !u_caster->IsInWorld() || !unitTarget || !unitTarget->IsInWorld() || unitTarget->GetHealthPct() >= 20 || !m_spellInfo)
				return;
			int32 value = m_spellInfo->EffectBasePoints[i]+1;
			int32 currentRage = p_caster->GetUInt32Value(UNIT_FIELD_POWER2);
			value += (int32) (currentRage * m_spellInfo->dmg_multiplier[0]);
			u_caster->SetUInt32Value(UNIT_FIELD_POWER2,0); // We use all available rage
			SpellEntry *spellInfo = dbcSpell.LookupEntry(20647 );
			u_caster->Strike(unitTarget,MELEE,spellInfo,0,0,value,false,false);
		}break;
	/*************************
	 * ROGUE SPELLS
	 *************************
	 * IDs:
	 * 14185 Preparation		STATUS: DONE
	 * --------------------------------------------
	 * 35729 Cloak of Shadows	STATUS: DONE
	 * --------------------------------------------
	 *************************/

	/*
		Preparation
		When activated, this ability immediately finishes the cooldown on your Evasion, Sprint, Vanish, Cold Blood, Shadowstep and Premeditation abilities.		
		
		Effect	Dummy
	*/
	case 14185:
		{
			if( !p_caster )
				return;

			uint32 ClearSpellId[11] =
			{
			5277,	/* Evasion - Rank 1	*/
			26669,	/* Evasion - Rank 2	*/
			2983,	/* Sprint - Rank 1	*/
			8696,	/* Sprint - Rank 2	*/
			11305,	/* Sprint - Rank 3	*/
			1856,	/* Vanish - Rank 1	*/
			1857,	/* Vanish - Rank 2	*/
			26889,	/* Vanish - Rank 3	*/
			14177,	/* Cold Blood		*/
			14183,	/* Premeditation	*/
			36554	/* Shadowstep		*/
			};

			for(i = 0; i < 11; ++i)
			{
				if( p_caster->HasSpell( ClearSpellId[i] ) )
					p_caster->ClearCooldownForSpell( ClearSpellId[i] );
			}
		}break;
	/*
		Cloak of Shadows
		Instantly removes all existing harmful spell effects and increases your chance to resist all spells by 90% for 5 sec. Does not remove effects that prevent you from using Cloak of Shadows.
		
		Effect #1	Apply Aura: Mod Attacker Spell Hit Chance (126)
			Value: -90
		Effect #2	Trigger Spell
			Spell #35729 <--- THIS SPELL
	*/
	case 35729:
		{
			if( !unitTarget || !unitTarget->isAlive())
				return;

			Aura * pAura;
			for(uint32 i = MAX_POSITIVE_AURAS; i < MAX_AURAS; ++i)
			{
				pAura = unitTarget->m_auras[i];
				if( pAura != NULL && !pAura->IsPassive() && !pAura->IsPositive() && !(pAura->GetSpellProto()->Attributes & ATTRIBUTES_IGNORE_INVULNERABILITY) &&
					pAura->GetSpellProto()->School != 0 )
				{
					pAura->Remove();
				}
			}
		}break;

	/*************************
	 * DRUID SPELLS
	 *************************
	 * IDs:
	 * 34297 Improved Leader of the Pack RANK 1		STATUS: DONE
	 * 34300 Improved Leader of the Pack RANK 2		STATUS: DONE
	 * --------------------------------------------
	 *************************/

	/*
		Improved Leader of the Pack
		Your Leader of the Pack ability also causes affected targets to have a X% chance to heal themselves for X% of their total health when they critically hit with a melee or ranged attack. The healing effect cannot occur more than once every 6 sec.
		
		Effect #1	Apply Aura: Add Flat Modifier (12)
			Value: X
		Effect #2	Dummy
			Value: 100
	*/
	case 34297:
	case 34300:
		{
			if (!u_caster->IsPlayer())
				return;
			ProcTriggerSpell ILotP;
			ILotP.origId = 34299;
			ILotP.spellId = 34299;
			ILotP.procChance = 100;
			ILotP.procFlags = PROC_ON_CRIT_ATTACK | PROC_TARGET_SELF;
			ILotP.deleted = false;
			ILotP.caster = u_caster->GetGUID();
			ILotP.LastTrigger = 0;
			ILotP.groupRelation = 0;
			ILotP.weapon_damage_type = 0;
			u_caster->m_procSpells.push_back(ILotP);
		}break;
	/*
		Tree of Life (Passive)
		Instant
		Requires Tree of Life Form
		
		Effect #1	Dummy
					Value: 25
					Server-side script effect.
	
	case 5420:
		break;*/
	/*************************
	 * HUNTER SPELLS
	 *************************
	 * IDs:
	 * 35029 Focused Fire RANK 1		STATUS: ToDo
	 * 35030 Focused Fire RANK 2		STATUS: ToDo
	 * --------------------------------------------
	 *************************/

	/*
		Focused Fire
		All damage caused by you is increased by 1% while your pet is active and the critical strike chance of your Kill Command ability is increased by 10%.
		
		Effect #1	Dummy
			Value: 1

		Effect #2	Apply Aura: Add Flat Modifier (7)
			Value: 10

	*/
//	case 35029:
//	case 35030:
//		{
//		}break;

	// Aspect of the Viper
//	case 34074:
// 		{
			// included in the dummy aura for simplicity
// 		}break;
	case 23989: //Hunter readiness
		{
			if( p_caster->HasSpell(19263) ) p_caster->ClearCooldownForSpell(19263); // Deterrence
			if( p_caster->HasSpell(20910) ) p_caster->ClearCooldownForSpell(20910); // Counterattack
			if( p_caster->HasSpell(14268) ) p_caster->ClearCooldownForSpell(14268); // Wing Clip
			if( p_caster->HasSpell(136) ) p_caster->ClearCooldownForSpell(136); // Mend Pet
			if( p_caster->HasSpell(27044) ) p_caster->ClearCooldownForSpell(27044); // Aspect of the Hawk
			if( p_caster->HasSpell(27045) ) p_caster->ClearCooldownForSpell(27045); // Aspect of the Wild
			if( p_caster->HasSpell(14264) ) p_caster->ClearCooldownForSpell(14264); // Raptor Strike
			if( p_caster->HasSpell(14265) ) p_caster->ClearCooldownForSpell(14265); // Raptor Strike
			if( p_caster->HasSpell(3043) ) p_caster->ClearCooldownForSpell(3043); // Scorpid Sting
			if( p_caster->HasSpell(14267) ) p_caster->ClearCooldownForSpell(14267); // Wing Clip
			if( p_caster->HasSpell(14260) ) p_caster->ClearCooldownForSpell(14260); // Raptor Strike
			if( p_caster->HasSpell(14261) ) p_caster->ClearCooldownForSpell(14261); // Raptor Strike
			if( p_caster->HasSpell(14262) ) p_caster->ClearCooldownForSpell(14262); // Raptor Strike
			if( p_caster->HasSpell(14263) ) p_caster->ClearCooldownForSpell(14263); // Raptor Strike
			if( p_caster->HasSpell(1543) ) p_caster->ClearCooldownForSpell(1543); // Flare
			if( p_caster->HasSpell(34600) ) p_caster->ClearCooldownForSpell(34600); // Snake Trap
			if( p_caster->HasSpell(34120) ) p_caster->ClearCooldownForSpell(34120); // Steady Shot
			if( p_caster->HasSpell(13163) ) p_caster->ClearCooldownForSpell(13163); // Aspect of the Monkey
			if( p_caster->HasSpell(13161) ) p_caster->ClearCooldownForSpell(13161); // Aspect of the Beast
			if( p_caster->HasSpell(13165) ) p_caster->ClearCooldownForSpell(13165); // Aspect of the Hawk
			if( p_caster->HasSpell(20906) ) p_caster->ClearCooldownForSpell(20906); // Trueshot Aura
			if( p_caster->HasSpell(14266) ) p_caster->ClearCooldownForSpell(14266); // Raptor Strike
			if( p_caster->HasSpell(20905) ) p_caster->ClearCooldownForSpell(20905); // Trueshot Aura
			if( p_caster->HasSpell(5384) ) p_caster->ClearCooldownForSpell(5384); // Feign Death
			if( p_caster->HasSpell(20903) ) p_caster->ClearCooldownForSpell(20903); // Aimed Shot
			if( p_caster->HasSpell(20900) ) p_caster->ClearCooldownForSpell(20900); // Aimed Shot
			if( p_caster->HasSpell(20901) ) p_caster->ClearCooldownForSpell(20901); // Aimed Shot
			if( p_caster->HasSpell(25295) ) p_caster->ClearCooldownForSpell(25295); // Serpent Sting
			if( p_caster->HasSpell(25294) ) p_caster->ClearCooldownForSpell(25294); // Multi-Shot
			if( p_caster->HasSpell(25296) ) p_caster->ClearCooldownForSpell(25296); // Aspect of the Hawk
			if( p_caster->HasSpell(6991) ) p_caster->ClearCooldownForSpell(6991); // Feed Pet
			if( p_caster->HasSpell(20909) ) p_caster->ClearCooldownForSpell(20909); // Counterattack
			if( p_caster->HasSpell(1494) ) p_caster->ClearCooldownForSpell(1494); // Track Beasts
			if( p_caster->HasSpell(1495) ) p_caster->ClearCooldownForSpell(1495); // Mongoose Bite
			if( p_caster->HasSpell(1499) ) p_caster->ClearCooldownForSpell(1499); // Freezing Trap
			if( p_caster->HasSpell(19879) ) p_caster->ClearCooldownForSpell(19879); // Track Dragonkin
			if( p_caster->HasSpell(20043) ) p_caster->ClearCooldownForSpell(20043); // Aspect of the Wild
			if( p_caster->HasSpell(3034) ) p_caster->ClearCooldownForSpell(3034); // Viper Sting
			if( p_caster->HasSpell(13552) ) p_caster->ClearCooldownForSpell(13552); // Serpent Sting
			if( p_caster->HasSpell(13551) ) p_caster->ClearCooldownForSpell(13551); // Serpent Sting
			if( p_caster->HasSpell(13550) ) p_caster->ClearCooldownForSpell(13550); // Serpent Sting
			if( p_caster->HasSpell(13159) ) p_caster->ClearCooldownForSpell(13159); // Aspect of the Pack
			if( p_caster->HasSpell(13554) ) p_caster->ClearCooldownForSpell(13554); // Serpent Sting
			if( p_caster->HasSpell(13553) ) p_caster->ClearCooldownForSpell(13553); // Serpent Sting
			if( p_caster->HasSpell(19306) ) p_caster->ClearCooldownForSpell(19306); // Counterattack
			if( p_caster->HasSpell(27046) ) p_caster->ClearCooldownForSpell(27046); // Mend Pet
			if( p_caster->HasSpell(14269) ) p_caster->ClearCooldownForSpell(14269); // Mongoose Bite
			if( p_caster->HasSpell(15629) ) p_caster->ClearCooldownForSpell(15629); // Distracting Shot
			if( p_caster->HasSpell(982) ) p_caster->ClearCooldownForSpell(982); // Revive Pet
			if( p_caster->HasSpell(14325) ) p_caster->ClearCooldownForSpell(14325); // Hunter's Mark
			if( p_caster->HasSpell(14324) ) p_caster->ClearCooldownForSpell(14324); // Hunter's Mark
			if( p_caster->HasSpell(19878) ) p_caster->ClearCooldownForSpell(19878); // Track Demons
			if( p_caster->HasSpell(14326) ) p_caster->ClearCooldownForSpell(14326); // Scare Beast
			if( p_caster->HasSpell(14321) ) p_caster->ClearCooldownForSpell(14321); // Aspect of the Hawk
			if( p_caster->HasSpell(14320) ) p_caster->ClearCooldownForSpell(14320); // Aspect of the Hawk
			if( p_caster->HasSpell(14323) ) p_caster->ClearCooldownForSpell(14323); // Hunter's Mark
			if( p_caster->HasSpell(13543) ) p_caster->ClearCooldownForSpell(13543); // Mend Pet
			if( p_caster->HasSpell(13549) ) p_caster->ClearCooldownForSpell(13549); // Serpent Sting
			if( p_caster->HasSpell(27066) ) p_caster->ClearCooldownForSpell(27066); // Trueshot Aura
			if( p_caster->HasSpell(27067) ) p_caster->ClearCooldownForSpell(27067); // Counterattack
			if( p_caster->HasSpell(20190) ) p_caster->ClearCooldownForSpell(20190); // Aspect of the Wild
			if( p_caster->HasSpell(3045) ) p_caster->ClearCooldownForSpell(3045); // Rapid Fire
			if( p_caster->HasSpell(3044) ) p_caster->ClearCooldownForSpell(3044); // Arcane Shot
			if( p_caster->HasSpell(19577) ) p_caster->ClearCooldownForSpell(19577); // Intimidation
			if( p_caster->HasSpell(14290) ) p_caster->ClearCooldownForSpell(14290); // Multi-Shot
			if( p_caster->HasSpell(19574) ) p_caster->ClearCooldownForSpell(19574); // Bestial Wrath
			if( p_caster->HasSpell(14295) ) p_caster->ClearCooldownForSpell(14295); // Volley
			if( p_caster->HasSpell(14294) ) p_caster->ClearCooldownForSpell(14294); // Volley
			if( p_caster->HasSpell(2641) ) p_caster->ClearCooldownForSpell(2641); // Dismiss Pet
			if( p_caster->HasSpell(2643) ) p_caster->ClearCooldownForSpell(2643); // Multi-Shot
			if( p_caster->HasSpell(3661) ) p_caster->ClearCooldownForSpell(3661); // Mend Pet
			if( p_caster->HasSpell(3662) ) p_caster->ClearCooldownForSpell(3662); // Mend Pet
			if( p_caster->HasSpell(15630) ) p_caster->ClearCooldownForSpell(15630); // Distracting Shot
			if( p_caster->HasSpell(15631) ) p_caster->ClearCooldownForSpell(15631); // Distracting Shot
			if( p_caster->HasSpell(15632) ) p_caster->ClearCooldownForSpell(15632); // Distracting Shot
			if( p_caster->HasSpell(1130) ) p_caster->ClearCooldownForSpell(1130); // Hunter's Mark
			if( p_caster->HasSpell(24133) ) p_caster->ClearCooldownForSpell(24133); // Wyvern Sting
			if( p_caster->HasSpell(24132) ) p_caster->ClearCooldownForSpell(24132); // Wyvern Sting
			if( p_caster->HasSpell(13555) ) p_caster->ClearCooldownForSpell(13555); // Serpent Sting
			if( p_caster->HasSpell(27019) ) p_caster->ClearCooldownForSpell(27019); // Arcane Shot
			if( p_caster->HasSpell(781) ) p_caster->ClearCooldownForSpell(781); // Disengage
			if( p_caster->HasSpell(27015) ) p_caster->ClearCooldownForSpell(27015); // Disengage
			if( p_caster->HasSpell(27014) ) p_caster->ClearCooldownForSpell(27014); // Raptor Strike
			if( p_caster->HasSpell(27016) ) p_caster->ClearCooldownForSpell(27016); // Serpent Sting
			if( p_caster->HasSpell(14282) ) p_caster->ClearCooldownForSpell(14282); // Arcane Shot
			if( p_caster->HasSpell(14283) ) p_caster->ClearCooldownForSpell(14283); // Arcane Shot
			if( p_caster->HasSpell(14280) ) p_caster->ClearCooldownForSpell(14280); // Viper Sting
			if( p_caster->HasSpell(14281) ) p_caster->ClearCooldownForSpell(14281); // Arcane Shot
			if( p_caster->HasSpell(14286) ) p_caster->ClearCooldownForSpell(14286); // Arcane Shot
			if( p_caster->HasSpell(14287) ) p_caster->ClearCooldownForSpell(14287); // Arcane Shot
			if( p_caster->HasSpell(14284) ) p_caster->ClearCooldownForSpell(14284); // Arcane Shot
			if( p_caster->HasSpell(14285) ) p_caster->ClearCooldownForSpell(14285); // Arcane Shot
			if( p_caster->HasSpell(14288) ) p_caster->ClearCooldownForSpell(14288); // Multi-Shot
			if( p_caster->HasSpell(14289) ) p_caster->ClearCooldownForSpell(14289); // Multi-Shot
			if( p_caster->HasSpell(19386) ) p_caster->ClearCooldownForSpell(19386); // Wyvern Sting
			if( p_caster->HasSpell(19506) ) p_caster->ClearCooldownForSpell(19506); // Trueshot Aura
			if( p_caster->HasSpell(19503) ) p_caster->ClearCooldownForSpell(19503); // Scatter Shot
			if( p_caster->HasSpell(20736) ) p_caster->ClearCooldownForSpell(20736); // Distracting Shot
			if( p_caster->HasSpell(34490) ) p_caster->ClearCooldownForSpell(34490); // Silencing Shot
			if( p_caster->HasSpell(14303) ) p_caster->ClearCooldownForSpell(14303); // Immolation Trap
			if( p_caster->HasSpell(14302) ) p_caster->ClearCooldownForSpell(14302); // Immolation Trap
			if( p_caster->HasSpell(20904) ) p_caster->ClearCooldownForSpell(20904); // Aimed Shot
			if( p_caster->HasSpell(14305) ) p_caster->ClearCooldownForSpell(14305); // Immolation Trap
			if( p_caster->HasSpell(14304) ) p_caster->ClearCooldownForSpell(14304); // Immolation Trap
			if( p_caster->HasSpell(34074) ) p_caster->ClearCooldownForSpell(34074); // Aspect of the Viper
			if( p_caster->HasSpell(13809) ) p_caster->ClearCooldownForSpell(13809); // Frost Trap
			if( p_caster->HasSpell(14319) ) p_caster->ClearCooldownForSpell(14319); // Aspect of the Hawk
			if( p_caster->HasSpell(14316) ) p_caster->ClearCooldownForSpell(14316); // Explosive Trap
			if( p_caster->HasSpell(14317) ) p_caster->ClearCooldownForSpell(14317); // Explosive Trap
			if( p_caster->HasSpell(14310) ) p_caster->ClearCooldownForSpell(14310); // Freezing Trap
			if( p_caster->HasSpell(14311) ) p_caster->ClearCooldownForSpell(14311); // Freezing Trap
			if( p_caster->HasSpell(27018) ) p_caster->ClearCooldownForSpell(27018); // Viper Sting
			if( p_caster->HasSpell(13544) ) p_caster->ClearCooldownForSpell(13544); // Mend Pet
			if( p_caster->HasSpell(14327) ) p_caster->ClearCooldownForSpell(14327); // Scare Beast
			if( p_caster->HasSpell(6197) ) p_caster->ClearCooldownForSpell(6197); // Eagle Eye
			if( p_caster->HasSpell(1515) ) p_caster->ClearCooldownForSpell(1515); // Tame Beast
			if( p_caster->HasSpell(1462) ) p_caster->ClearCooldownForSpell(1462); // Beast Lore
			if( p_caster->HasSpell(1510) ) p_caster->ClearCooldownForSpell(1510); // Volley
			if( p_caster->HasSpell(1513) ) p_caster->ClearCooldownForSpell(1513); // Scare Beast
			if( p_caster->HasSpell(883) ) p_caster->ClearCooldownForSpell(883); // Call Pet
			if( p_caster->HasSpell(5116) ) p_caster->ClearCooldownForSpell(5116); // Concussive Shot
			if( p_caster->HasSpell(13795) ) p_caster->ClearCooldownForSpell(13795); // Immolation Trap
			if( p_caster->HasSpell(13542) ) p_caster->ClearCooldownForSpell(13542); // Mend Pet
			if( p_caster->HasSpell(14322) ) p_caster->ClearCooldownForSpell(14322); // Aspect of the Hawk
			if( p_caster->HasSpell(5118) ) p_caster->ClearCooldownForSpell(5118); // Aspect of the Cheetah
			if( p_caster->HasSpell(27025) ) p_caster->ClearCooldownForSpell(27025); // Explosive Trap
			if( p_caster->HasSpell(27020) ) p_caster->ClearCooldownForSpell(27020); // Distracting Shot
			if( p_caster->HasSpell(27021) ) p_caster->ClearCooldownForSpell(27021); // Multi-Shot
			if( p_caster->HasSpell(27022) ) p_caster->ClearCooldownForSpell(27022); // Volley
			if( p_caster->HasSpell(27023) ) p_caster->ClearCooldownForSpell(27023); // Immolation Trap
			if( p_caster->HasSpell(20902) ) p_caster->ClearCooldownForSpell(20902); // Aimed Shot
			if( p_caster->HasSpell(27068) ) p_caster->ClearCooldownForSpell(27068); // Wyvern Sting
			if( p_caster->HasSpell(13813) ) p_caster->ClearCooldownForSpell(13813); // Explosive Trap
			if( p_caster->HasSpell(27065) ) p_caster->ClearCooldownForSpell(27065); // Aimed Shot
			if( p_caster->HasSpell(36916) ) p_caster->ClearCooldownForSpell(36916); // Mongoose Bite
			if( p_caster->HasSpell(14271) ) p_caster->ClearCooldownForSpell(14271); // Mongoose Bite
			if( p_caster->HasSpell(34026) ) p_caster->ClearCooldownForSpell(34026); // Kill Command
			if( p_caster->HasSpell(19883) ) p_caster->ClearCooldownForSpell(19883); // Track Humanoids
			if( p_caster->HasSpell(19882) ) p_caster->ClearCooldownForSpell(19882); // Track Giants
			if( p_caster->HasSpell(19880) ) p_caster->ClearCooldownForSpell(19880); // Track Elementals
			if( p_caster->HasSpell(19885) ) p_caster->ClearCooldownForSpell(19885); // Track Hidden
			if( p_caster->HasSpell(19884) ) p_caster->ClearCooldownForSpell(19884); // Track Undead
			if( p_caster->HasSpell(14273) ) p_caster->ClearCooldownForSpell(14273); // Disengage
			if( p_caster->HasSpell(14272) ) p_caster->ClearCooldownForSpell(14272); // Disengage
			if( p_caster->HasSpell(14270) ) p_caster->ClearCooldownForSpell(14270); // Mongoose Bite
			if( p_caster->HasSpell(14274) ) p_caster->ClearCooldownForSpell(14274); // Distracting Shot
			if( p_caster->HasSpell(2973) ) p_caster->ClearCooldownForSpell(2973); // Raptor Strike
			if( p_caster->HasSpell(14279) ) p_caster->ClearCooldownForSpell(14279); // Viper Sting
			if( p_caster->HasSpell(2974) ) p_caster->ClearCooldownForSpell(2974); // Wing Clip
			if( p_caster->HasSpell(1978) ) p_caster->ClearCooldownForSpell(1978); // Serpent Sting
			if( p_caster->HasSpell(3111) ) p_caster->ClearCooldownForSpell(3111); // Mend Pet
			if( p_caster->HasSpell(1002) ) p_caster->ClearCooldownForSpell(1002); // Eyes of the Beast
			if( p_caster->HasSpell(19801) ) p_caster->ClearCooldownForSpell(19801); // Tranquilizing Shot
			if( p_caster->HasSpell(19434) ) p_caster->ClearCooldownForSpell(19434); // Aimed Shot
			if( p_caster->HasSpell(34477) ) p_caster->ClearCooldownForSpell(34477); // Misdirection
			if( p_caster->HasSpell(14318) ) p_caster->ClearCooldownForSpell(14318); // Aspect of the Hawk
		}break;
	/*************************
	 * PALADIN SPELLS
	 *************************
	 * IDs:
	 * 31789 Righteous Defense		STATUS: DONE
	 * --------------------------------------------
	 * 18350 illumination			STATUS: DONE
	 * --------------------------------------------
	 *************************/

	/*
		Righteous Defense
		Come to the defense of a friendly target, commanding up to 3 enemies attacking the target to attack the Paladin instead.
		
		Effect #1	Dummy
			Radius: 5 yards

		Effect #2	Trigger Spell
			Spell #31980
	*/
	case 31789:
		{
			//we will try to lure 3 enemies from our target
			if(!unitTarget || !u_caster)
				break;
			Unit *targets[3];
			int targets_got=0;
			for(std::set<Object*>::iterator itr = unitTarget->GetInRangeSetBegin(), i2; itr != unitTarget->GetInRangeSetEnd(); )
			{
				i2 = itr++;
				// don't add objects that are not units and that are dead
				if((*i2)->GetTypeId()!= TYPEID_UNIT || !((Unit*)(*i2))->isAlive())
					continue;

				Creature *cr=((Creature*)(*i2));
				if(cr->GetAIInterface()->GetNextTarget()==unitTarget)
					targets[targets_got++]=cr;
				if(targets_got==3)
					break;
			}
			for(int i=0;i<targets_got;i++)
			{
				//set threat to this target so we are the msot hated
				uint32 threat_to_him = targets[i]->GetAIInterface()->getThreatByPtr( unitTarget );
				uint32 threat_to_us = targets[i]->GetAIInterface()->getThreatByPtr(u_caster);
				int threat_dif = threat_to_him - threat_to_us;
				if(threat_dif>0)//should nto happen
					targets[i]->GetAIInterface()->modThreatByPtr(u_caster,threat_dif);
				targets[i]->GetAIInterface()->AttackReaction(u_caster,1,0);
				targets[i]->GetAIInterface()->SetNextTarget(u_caster);
			}
		}break;
	/*
		Illumination
		After getting a critical effect from your Flash of Light, Holy Light, or Holy Shock heal spell, gives you a X% chance to gain mana equal to 60% of the base cost of the spell.
		
		Effect #1	Apply Aura: Proc Trigger Spell
			Proc chance: 20%
			Spell #18350 <-- THIS SPELL	
		Effect #2	Apply Aura: Override Class Scripts (2689)
			Value: 60
	*/
	case 20473: //Holy Shock Rank 1
		{
			if( !u_caster || !u_caster->IsInWorld() || !unitTarget || !unitTarget->IsInWorld() )
				return;
			u_caster->CastSpell(unitTarget, isAttackable(u_caster, unitTarget) ? 25912 : 25914, false);
		}break;
	case 20969: //Holy Shock Rank 2
		{
			if( !u_caster || !u_caster->IsInWorld() || !unitTarget || !unitTarget->IsInWorld() )
				return;
			u_caster->CastSpell(unitTarget, isAttackable(u_caster, unitTarget) ? 25911 : 25913, false);
		}break;
	case 20970: //Holy Shock Rank 3
		{
			if( !u_caster || !u_caster->IsInWorld() || !unitTarget || !unitTarget->IsInWorld() )
				return;
			u_caster->CastSpell(unitTarget, isAttackable(u_caster, unitTarget) ? 25902 : 25903, false);
		}break;
	case 27174: //Holy Shock Rank 4
		{
			if( !u_caster || !u_caster->IsInWorld() || !unitTarget || !unitTarget->IsInWorld() )
				return;
			u_caster->CastSpell(unitTarget, isAttackable(u_caster, unitTarget) ? 27176 : 27175, false);
		}break;
	case 33072: //Holy Shock Rank 5
		{
			if( !u_caster || !u_caster->IsInWorld() || !unitTarget || !unitTarget->IsInWorld() )
				return;
			u_caster->CastSpell(unitTarget, isAttackable(u_caster, unitTarget) ? 33073 : 33074, false);
		}break;
	case 18350: // Illumination
		{
			switch( m_triggeredByAura==NULL ? pSpellId : m_triggeredByAura->GetSpellId() )
			{
			case 20210:
			case 20212:
			case 20213:
			case 20214:
			case 20215:
				{
					if(!p_caster) return;
					SpellEntry * sp = p_caster->last_heal_spell ? p_caster->last_heal_spell : GetProto();
					uint32 cost = float2int32( float( float(sp->manaCost) * 0.6f ) );
					p_caster->Energize( p_caster, 20272, cost, POWER_TYPE_MANA );
				}break;
			case 38443:
				{
					// Shaman - Skyshatter Regalia - Two Piece Bonus
					// it checks for earth, air, water, fire totems and triggers Totemic Mastery spell 38437.
					if(!p_caster) return;
					if(p_caster->m_TotemSlots[0] && p_caster->m_TotemSlots[1] && p_caster->m_TotemSlots[2] && p_caster->m_TotemSlots[3])
					{
						Aura *aur = AuraPool.PooledNew();
						aur->Init(dbcSpell.LookupEntry(38437), 5000, p_caster, p_caster);
						for( uint32 i=0; i<3; i++ ) 
							aur->AddMod( aur->GetSpellProto()->EffectApplyAuraName[i], aur->GetSpellProto()->EffectBasePoints[i]+1, aur->GetSpellProto()->EffectMiscValue[i], i );
						p_caster->AddAura(aur);
					}
				}break;
			default:
				return;
			}
		}break;
	/*************************
	 * PRIEST SPELLS
	 *************************
	 * IDs:
	 * 34433 Shadowfiend	STATUS: ToDo
	 *  --------------------------------------------
	 *************************/
	/*
		Creates a shadowy fiend to attack the target.  Caster receives mana when the Shadowfiend deals damage.  Lasts 15 sec.
		Effect #1	Summon (19668)
		Effect #2	Trigger Spell
					Spell #41967 <--- THIS SPELL
	*/
	/*case 41967:
		{
		}break;
	*/

	/*************************
	 * SHAMAN SPELLS
	 *************************
	 * IDs:
	 * NO SPELLS
	 * --------------------------------------------
	 *************************/

	/*************************
	 * WARLOCK SPELLS
	 *************************
	 * IDs:
	 * 19028 Soul Link				STATUS: ToDo
	 * --------------------------------------------
	 * 19028 soul link effect		STATUS: DONE
	 * --------------------------------------------
	 *************************/

	/*
		Soul Link
		When active, 20% of all damage taken by the caster is taken by your Imp, Voidwalker, Succubus, Felhunter, Felguard, or enslaved demon instead. That damage cannot be prevented. In addition, both the demon and master will inflict 5% more damage. Lasts as long as the demon is active and controlled.
		
		Effect	Dummy
	*/

//	case 19028:
//		{
//		}break;

	/*
		Soul Link - EFFECT
		20% of damage taken by master is split with demon. All damage increased by 5%.
	*/
	case 25228:
		{
			if(!u_caster || !u_caster->isAlive() || !unitTarget || !unitTarget->isAlive())
				return;
			uint32 pet_dmg = this->forced_basepoints[0]*20/100;
			if( pet_dmg )
			{
				unitTarget->ModUnsigned32Value(UNIT_FIELD_HEALTH,pet_dmg);
				unitTarget->DealDamage(u_caster,pet_dmg,0,0,25228,true);
			}
		}break;

	/*************************
		Non-Class spells
		- Done
	 *************************/
	/*
		Poultryizer
		Turns the target into a chicken for 15 sec. Well, that is assuming the transmogrification polarity has not been reversed...
	*/
	case 30507:
		{
			if( !unitTarget || !unitTarget->isAlive())
				return;

			u_caster->CastSpell(unitTarget->GetGUID(),30501,true);
		}break;
	/*
		Six Demon Bag
		Blasts enemies in front of you with the power of wind, fire, all that kind of thing!
	*/
	case 14537:
		{
			if( !unitTarget || !unitTarget->isAlive())
				return;

			uint32 ClearSpellId[6] = { 8401,8408,930,118,1680,10159 };
			int min = 1;
			uint32 effect = min + int( ((6-min)+1) * rand() / (RAND_MAX + 1.0) );
			
			u_caster->CastSpell(unitTarget, ClearSpellId[effect] ,true);
		}break;

	case 30427: // Extract Gas
		{
			bool check = false;
			uint32 cloudtype;
			Creature *creature;

			if(!p_caster)
				return;

			for(Object::InRangeSet::iterator i = p_caster->GetInRangeSetBegin(); i != p_caster->GetInRangeSetEnd(); ++i)
			{
				if((*i)->GetTypeId() == TYPEID_UNIT)
				{
					creature=static_cast<Creature *>((*i));
					cloudtype=creature->GetEntry();
					if(cloudtype == 24222 || cloudtype == 17408 || cloudtype == 17407 || cloudtype == 17378)
					{
						if(p_caster->GetDistance2dSq((*i)) < 400)
						{
							p_caster->SetSelection(creature->GetGUID());
							check = true;
							break;
						}
					}
				}
			}
			
			if(check)
			{
				uint32 item,count = 3+(rand()%3);
			
				if (cloudtype==24222) item=22572;//-air
				if (cloudtype==17408) item=22576;//-mana
				if (cloudtype==17407) item=22577;//-shadow
				if (cloudtype==17378) item=22578;//-water

				Item *add = p_caster->GetItemInterface()->FindItemLessMax(item, count, false);
				if (!add)
				{
					ItemPrototype* proto = ItemPrototypeStorage.LookupEntry(item);
					SlotResult slotresult;

					slotresult = p_caster->GetItemInterface()->FindFreeInventorySlot(proto);
					if(!slotresult.Result)
					{
						p_caster->GetItemInterface()->BuildInventoryChangeError(NULL, NULL, INV_ERR_INVENTORY_FULL);
						return;
					}
					Item * it=objmgr.CreateItem(item,p_caster);  
					it->SetUInt32Value( ITEM_FIELD_STACK_COUNT, count);
					p_caster->GetItemInterface()->SafeAddItem(it,slotresult.ContainerSlot, slotresult.Slot);
					creature->Despawn(3500,creature->GetProto()->RespawnTime);
				}
				else
				{
					add->SetCount(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + count);
					add->m_isDirty = true;
					creature->Despawn(3500,creature->GetProto()->RespawnTime);
				}
			}
		}break;

	//curse of agony(18230) = periodic damage increased in 
	//flag 2031678
/*	case 34120:
		{//steady shot
		if(unitTarget)
		if(unitTarget->IsDazed())
		{
//			u_caster->SpellNonMeleeDamageLog(unitTarget,spellId,damage,false);
			u_caster->SpellNonMeleeDamageLog(unitTarget,spellId,damage,pSpellId==0);
		}
		
		}break;*/
	case 1454://life tap
	case 1455:
	case 1456:
	case 11687:
	case 11688:
	case 11689:
	case 27222:
		{//converts base+1 points of health into mana
		if(!p_caster || !playerTarget)
			return;

		uint32 damage = ( ( ( GetProto()->EffectBasePoints[i] + 1 ) * ( 100 + playerTarget->m_lifetapbonus ) ) / 100 ) + ( ( playerTarget->GetDamageDoneMod( GetProto()->School ) * 80 ) / 100 );
		if( damage >= playerTarget->GetUInt32Value( UNIT_FIELD_HEALTH ) )
			return;
		p_caster->DealDamage( playerTarget, damage, 0, 0, spellId );
		p_caster->Energize( playerTarget, spellId, damage, POWER_TYPE_MANA );
		}break;
	case 974:
	case 32593:
	case 32594:
		{
			if(!pSpellId) return;
			SpellEntry *spellInfo = dbcSpell.LookupEntry(pSpellId);
			if(!spellInfo) return;
			uint32 heal32 = CalculateEffect(i,u_caster);
			unitTarget=u_caster; // Should heal caster :p
			if(heal32)
				Heal(heal32);
		}break;
	case 28730: //Arcane Torrent (Mana)
		{
			// for each mana tap, gives you (2.17*level+9.136) mana
			if( !unitTarget || !p_caster) 
				return;

			if(!unitTarget->isAlive() || unitTarget->getClass()==WARRIOR || unitTarget->getClass() == ROGUE)
				return;

			uint32 count = 0;
			for(uint32 x = 0; x < MAX_AURAS; ++x)
			{
				if(unitTarget->m_auras[x] && unitTarget->m_auras[x]->GetSpellId() == 28734)
				{
					unitTarget->m_auras[x]->Remove();
					++count;
				}
			}

			uint32 gain = (uint32)(count * (2.17*p_caster->getLevel()+9.136));
			p_caster->Energize( unitTarget, 28730, gain, POWER_TYPE_MANA );
		}break;
	case 39610://Mana Tide
		{
			if(unitTarget == NULL || unitTarget->isDead() || unitTarget->getClass() == WARRIOR || unitTarget->getClass() == ROGUE)
 				return;
 			uint32 gain = (uint32) (unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)*0.06);
			unitTarget->Energize( unitTarget, 16191, gain, POWER_TYPE_MANA );
		}break;
	case 20425: //Judgement of Command
	case 20961: //Judgement of Command
	case 20962: //Judgement of Command
	case 20967: //Judgement of Command
	case 20968: //Judgement of Command
	case 27172: //Judgement of Command
		{
			uint32 SpellID = GetProto()->EffectBasePoints[i]+1;
			Spell * spell=SpellPool.PooledNew();
			spell->Init(m_caster,dbcSpell.LookupEntry(SpellID),true,NULL);
			SpellCastTargets targets;
			targets.m_unitTarget = unitTarget->GetGUID();
			spell->prepare(&targets);
		}break;

	case 20577:// Cannibalize
		{
			if(!p_caster)
				return;
			bool check = false;
			float rad = GetRadius(i);
			rad *= rad;
			for(Object::InRangeSet::iterator i = p_caster->GetInRangeSetBegin(); i != p_caster->GetInRangeSetEnd(); ++i)
			{
				if((*i)->GetTypeId() == TYPEID_UNIT)
				{
					if(static_cast<Creature *>((*i))->getDeathState() == CORPSE)
					{
						CreatureInfo *cn = static_cast<Creature *>((*i))->GetCreatureInfo();
							if(cn && cn->Type == HUMANOID || cn->Type == UNDEAD)
							{
								if(p_caster->GetDistance2dSq((*i)) < rad)
								{
									check = true;
									break;
								}
							}
						
					}
				}
			}
			
			if(check)
			{
				p_caster->cannibalize = true;
				p_caster->cannibalizeCount = 0;
				sEventMgr.AddEvent(p_caster, &Player::EventCannibalize, uint32(7),
					EVENT_CANNIBALIZE, 2000, 5,0);
				p_caster->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CANNIBALIZE);
			}
		}break;
	case 23074:// Arcanite Dragonling
	case 23075:// Mithril Mechanical Dragonling
	case 23076:// Mechanical Dragonling
	case 23133:// Gnomish Battle Chicken
		{
			uint32 spell_id;
			switch(GetProto()->Id)
			{
				case 23074: spell_id =	19804;	break;
				case 23075: spell_id =	12749;	break;
				case 23076: spell_id =	4073;	break;
				case 23133: spell_id =	13166;	break;
				default: 
					return;
			}
			u_caster->CastSpell(u_caster,spell_id,true);
		}break;
	case 23725:// Gift of Life
		{
			if(!playerTarget)
				break;

			SpellCastTargets tgt;
			tgt.m_unitTarget = playerTarget->GetGUID();
			SpellEntry * inf = dbcSpell.LookupEntry(23782);
			Spell * spe = SpellPool.PooledNew();
			spe->Init(u_caster,inf,true,NULL);
			spe->prepare(&tgt);

		}break;
	case 12975:// Last Stand
		{
			if(!playerTarget)
				break;
			SpellCastTargets tgt;
			tgt.m_unitTarget = playerTarget->GetGUID();
			SpellEntry * inf =dbcSpell.LookupEntry(12976);
			Spell * spe = SpellPool.PooledNew();
			spe->Init(u_caster,inf,true,NULL);
			spe->prepare(&tgt);
		}break;
	/*************************
		Non-Class spells
		- ToDo
	 *************************/
	case 6668:// Red Firework
		{
			// Shoots a firework into the air that bursts into a thousand red stars
		}break;
	case 8344:// Universal Remote
		{
			//FIXME:Allows control of a mechanical target for a short time. It may not always work and may just root the machine or make it very very angry. Gnomish engineering at its finest.
		}break;
	case 9976:// Polly Eats the E.C.A.C.
		{
			//FIXME: Don't know what this does
		}break;
	case 10137:// Fizzule's Whistle
		{
			//FIXME:Blow on the whistle to let Fizzule know you're an ally
			//This item comes after a finish of quest at venture co.
			//You must whistle this every time you reach there to make Fizzule
			//ally to you.
		}break;
	case 11540:// Blue Firework
		{
			//Shoots a firework into the air that bursts into a thousand blue stars
		}break;
	case 11541:// Green Firework
		{
			//Shoots a firework into the air that bursts into a thousand green stars
		}break;
	case 11542:// Red Streaks Firework
		{
			//Shoots a firework into the air that bursts into a thousand red streaks
		}break;
	case 11543:// Red, White and Blue Firework
		{
			//Shoots a firework into the air that bursts into red, white and blue stars
		}break;
	case 11544:// Yellow Rose Firework
		{
			//Shoots a firework into the air that bursts in a yellow pattern
		}break;
	case 12151:// Summon Atal'ai Skeleton
		{
			//8324	Atal'ai Skeleton

			//FIXME:Add here remove in time event
		}break;
	case 13006:// Shrink Ray
		{
			//FIXME:Schematic is learned from the gnomish engineering trainer. The gnomish/gobblin engineering decision is made when you are lvl40+ and your engineering is 200+. Interestingly, however, when this item fails to shrink the target, it can do a variety of things, such as...
			//-Make you bigger (attack power +250)
			//-Make you smaller (attack power -250)
			//-Make them bigger (same effect as above)
			//-Make your entire party bigger
			//-Make your entire party smaller
			//-Make every attacking enemy bigger
			//-Make ever attacking enemy smaller
			//Works to your advantage for the most part (about 70% of the time), but don't use in high-pressure situations, unless you're going to die if you don't. Could tip the scales the wrong way.
			//Search for spells of this


			//13004 - grow <- this one
			//13010 - shrink <-this one
			//
		}break;
	case 13180:// Gnomish Mind Control Cap
		{
			// FIXME:Take control of humanoid target by chance(it can be player)
		}break;
	case 13278:// Gnomish Death Ray
		{
			// FIXME:The devices charges over time using your life force and then directs a burst of energy at your opponent
			//Drops life			
		}break;
	case 13280:// Gnomish Death Ray
		{
			//FIXME: Drop life
		}break;
	case 17816:// Sharp Dresser
		{
			//Impress others with your fashion sense
		}break;
	case 21343:// Snowball
		{
		}break;
	case 23645:// Hourglass Sand
		{
			//Indeed used at the Chromo fight in BWL. Chromo has a stunning debuff, uncleansable, unless you have hourglass sand. This debuff will stun you every 4 seconds, for 4 seconds. It is resisted a lot though. Mage's and other casters usually have to do this fight with the debuff on, healers, tanks and hunters will get some to cure themselves from the debuff
		}break;
	case 24325:// Pagle's Point Cast - Create Mudskunk Lure
		{
			//FIXME:Load with 5 Zulian Mudskunks, and then cast from Pagle's Point in Zul'Gurub
		}
	case 24392:// Frosty Zap
		{
			//FIXME:Your Frostbolt spells have a 6% chance to restore 50 mana when cast.
			//damage == 50
		}break;
	case 25822:// Firecrackers
		{
			//FIXME:Find firecrackers
		}break;
	case 26373:// Lunar Invititation
		{
			//FIXME: Teleports the caster from within Greater Moonlight
		}break;
	case 26374:// Elune's Candle
		{
			//FIXME:Shoots a firework at target
		}break;
	case 26889:// Give Friendship Bracelet
		{
			//Give to a Heartbroken player to cheer them up
			//laugh emote
		}break;
	case 27662:// Throw Cupid's Dart
		{
			//FIXME:Shoot a player, and Kwee Q. Peddlefeet will find them! (Only works on players with no current critter pets.)
		}break;
	case 28414:// Call Ashbringer
		{
			//http://www.thottbot.com/?i=53974
			if(!p_caster)
				return;

			uint32 ashcall = RandomUInt(12);
			switch(ashcall)
			{
			case 1:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8906) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "I... was... pure... once.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 2:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8907) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Fought... for... righteousness.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 3:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8908) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "I... was... once... called... Ashbringer.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 4:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8920) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Betrayed... by... my... order.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 5:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8921) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Destroyed... by... Kel'Thuzad.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 6:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8922) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Made... to serve.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 7:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8923) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "My... son... watched... me... die.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 8:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8924) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Crusades... fed his rage.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 9:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8925) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Truth... is... unknown... to him.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 10:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8926) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Scarlet... Crusade... is pure... no longer.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 11:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8927) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Balnazzar's... crusade... corrupted... my son.";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			case 12:
				{
					WorldPacket data;
					data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);
					data << uint32(8928) << unitTarget->GetGUID();
					p_caster->SendMessageToSet(&data, true);
					WorldPacket *crap;
					std::stringstream Reply;
					Reply << "Kill... them... all!";
					crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
					p_caster->GetSession()->SendPacket(crap);
				}break;
			}
		}break;
	case 28806:// Toss Fuel on Bonfire
		{
			//FIXME:Dont know what this dummy does
		}break;
	case 7669:// Bethor's Potion
		{
			// related to Hex of Ravenclaw,
			// its a dispell spell.
			//FIXME:Dont know whats the usage of this dummy
		}break;
	case 8283:// Snufflenose Command
		{
			//FIXME:Quest Blueleaf Tubers
			//For use on a Snufflenose Gopher
		}break;
	case 8913:// Sacred Cleansing
		{
			//FIXME:Removes the protective enchantments around Morbent Fel
			//Quest Morbent Fel
		}break;
	case 9962://Capture Treant
		{
			//Quest Treant Muisek 
		}break;
	case 10113:// Flare Gun's flare
		{
			//FIXME:Quest Deep Cover
			//1543 may need to cast this
			//2 flares and the /salute
		}break;
	case 10617:// Release Rageclaw
		{
			//Quest Druid of the Claw
			//Use on the fallen body of Rageclaw
		}break;
	case 11402:// Shay's Bell
		{
			//FIXME:Quest Wandering Shay
			//Ring to call Shay back to you
		}break;
	case 11548:// Summon Spider God
		{
			//FIXME:Quest Summoning Shadra (Elite)
			//Use at the Shadra'Alor Altar to summon the spider god
		}break;
	case 11610:// Gammerita Turtle Camera
		{
			//Quest The Super Snapper FX 
		}break;
	case 11886:// Capture Wildkin
		{
			//Quest Testing the Vessel
			//Shrink and Capture a Fallen Wildkin
		}break;
	case 11887:// Capture Hippogryph
		{
			//FIXME:Same with 11888
			//Quest Hippogryph Muisek 
		}break;
	case 11888:// Capture Faerie Dragon
		{
			//FIXME:Check Faerie Dragon Muisek is killed or not if its killed update quest
			//And allow create of fearie Dragon which is effect 1
			//Quest: Faerie Dragon Muisek
		}break;
	case 11889:// Capture Mountain Giant
		{
			//FIXME:Same with 11888
			//Quest: Mountain Giant Muisek
		}break;
	case 12189:// Summon Echeyakee
		{
			//3475	Echeyakee

			//FIXME:Quest Echeyakee
		}break;
	case 12283:// Xiggs Signal Flare
		{
			//Quest Signal for Pickup
			//To be used at the makeshift helipad in Azshara. It will summon Pilot Xiggs Fuselighter to pick up the tablet rubbings
		}break;
	case 12938:// Fel Curse
		{
			//FIXME:Makes near target killable(servants of Razelikh the Defiler)
		}break;
	case 14247:// Blazerunner Dispel
		{
			//FIXME:Quest Aquementas and some more
		}break;
	case 14250:// Capture Grark
		{
			//Quest Precarious Predicament
		}break;
	case 14813:// Rocknot's Ale
		{
			//you throw the mug
			//and the guy gets pissed well everyone gets pissed and he crushes the door so you can get past
			//maybe after like 30 seconds so you can get past.  but lke I said I have never done it myself 
			//so i am not 100% sure what happens.
		}break;
	case 15991://Revive Ringo
		{
			//Quest A Little Help From My Friends 
			//Revive Ringo with water
		}break;
	case 15998:// Capture Worg Pup
		{
			//FIXME:Ends Kibler's Exotic Pets (Dungeon) quest
		}break;
	case 16031:// Releasing Corrupt Ooze
		{
			//FIXME:Released ooze moves to master ooze and "Merged Ooze Sample"
			//occurs after some time.This item helps to finish quest
		}break;
	case 16378:// Temperature Reading
		{
			//FIXME:Quest Finding the Source
			//Take a reading of the temperature at a hot spot.
		}break;
	case 17166:// Release Umi's Yeti
		{
			//Quest Are We There, Yeti?
			//Select Umi's friend and click to release the Mechanical Yeti
		}break;
	case 17271:// Test Fetid Skull
		{
			//FIXME:Marauders of Darrowshire
			//Wave over a Fetid skull to test its resonance
		}break;
	case 18153:// Kodo Kombobulator
		{
			//FIXME:Kodo Roundup Quest
			//Kodo Kombobulator on any Ancient, Aged, or Dying Kodo to lure the Kodo to follow (one at a time)
		}break;
	case 19250:// Placing Smokey's Explosives
		{
			//This is something related to quest i think
		}break;
	case 19512:// Apply Salve
		{
			//FIXME:Cure a sickly animal afflicted by the taint of poisoning
		}break;
	case 20804:// Triage 
		{
			//Quest Triage
			//Use on Injured, Badly Injured, and Critically Injured Soldiers
		}break;
	case 21050:// Melodious Rapture
		{
			//Quest Deeprun Rat Roundup 
		}break;
	case 21332:// Aspect of Neptulon
		{
			//FIXME:Used on plagued water elementals in Eastern Plaguelands
			//Quest:Poisoned Water
		}break;
	case 21960:// Manifest Spirit
		{
			//FIXME:Forces the spirits of the first centaur Kahns to manifest in the physical world
			//thats a quest
			//its for maraudon i think
			//u use that on the spirit mobs
			//to release them
		}break;
	case 23359:// Transmogrify!
		{
			//Quest Zapped Giants 
			//Zap a Feralas giant into a more manageable form
		}break;
	case 27184:// Summon Mor Grayhoof
		{
			//16044	Mor Grayhoof Trigger
			//16080	Mor Grayhoof

			//Related to quests The Left Piece of Lord Valthalak's Amulet (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet (Dungeon)
		}break;
	case 27190:// Summon Isalien
		{
			//16045	Isalien Trigger
			//16097	Isalien

			//Related to quests The Left Piece of Lord Valthalak's Amulet (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet (Dungeon)
		}break;
	case 27191:// Summon the remains of Jarien and Sothos
		{
			/*
			16046	Jarien and Sothos Trigger
			16101	Jarien
			16103	Spirit of Jarien
			
			16102	Sothos
			16104	Spirit of Sothos
			*/

			//Related to quests The Left Piece of Lord Valthalak's Amulet (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet (Dungeon)
		}break;
	case 27201:// Summon the spirit of Kormok
		{
			/*16047	Kormok Trigger
			16118	Kormok
			*/
			//Related to quests The Left Piece of Lord Valthalak's Amulet (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet (Dungeon)
		}break;
	case 27202:// Summon Lord Valthalak
		{
			/*
			16042	Lord Valthalak
			16048	Lord Valthalak Trigger
			16073	Spirit of Lord Valthalak

			*/
			//Related to quests The Left Piece of Lord Valthalak's Amulet (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet (Dungeon)
		}break;
	case 27203:// Summon the spirits of the dead at haunted locations
		{
			//Related to quests The Left Piece of Lord Valthalak's Amulet (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet (Dungeon)
		}break;
	case 27517:// Use this banner at the Arena in Blackrock Depths to challenge Theldren
		{
			//This is used to make Theldren spawn at the place where it used
			//I couldnt find theldrin, and his men in creature names database
			//Someone has to write this and this is related to The Challange quest
			/*By moving to the center grate, you trigger the arena event. 
			A random group of mobs (spiders, worms, bats, raptors) spawns, 
			and you have to kill them. After the last one dies, and a small 
			break, a boss mob spawns. Successfully completing this event 
			turns the arena spectators from red to yellow*/
		}break;
	case 29858: //Soulshatter
		{
			if( !u_caster || !u_caster->isAlive() || !unitTarget || !unitTarget->isAlive() )
				return;

			u_caster->CastSpell(unitTarget, 32835, false);
		}break;
	}										 
}

void Spell::SpellEffectTeleportUnits( uint32 i ) // Teleport Units
{
	uint32 spellId = GetProto()->Id;

	if( unitTarget == NULL )
		return;

	// Try a dummy SpellHandler
	if( sScriptMgr.CallScriptedDummySpell( spellId, i, this ) )
		return;

	// Shadowstep
	if( GetProto()->NameHash == SPELL_HASH_SHADOWSTEP && p_caster && p_caster->IsInWorld() )
	{
		/* this is rather tricky actually. we have to calculate the orientation of the creature/player, and then calculate a little bit of distance behind that. */
		float ang;
		if( unitTarget == m_caster )
		{
			/* try to get a selection */
 			unitTarget = m_caster->GetMapMgr()->GetUnit(p_caster->GetSelection());
//			if( (unitTarget == NULL ) || !isHostile(p_caster, unitTarget) || (unitTarget->CalcDistance(p_caster) > 25.0f)) //removed by Zack : no idea why hostile is used. Isattackable should give a wider solution range
			if( (unitTarget == NULL ) || !isAttackable(p_caster, unitTarget, !(GetProto()->c_is_flags & SPELL_FLAG_IS_TARGETINGSTEALTHED) ) || (unitTarget->CalcDistance(p_caster) > 28.0f))
				return;
		}

		if( unitTarget->GetTypeId() == TYPEID_UNIT )
		{
			if( unitTarget->GetUInt64Value( UNIT_FIELD_TARGET ) != 0 )
			{
				/* We're chasing a target. We have to calculate the angle to this target, this is our orientation. */
				ang = m_caster->calcAngle(m_caster->GetPositionX(), m_caster->GetPositionY(), unitTarget->GetPositionX(), unitTarget->GetPositionY());

				/* convert degree angle to radians */
				ang = ang * float(M_PI) / 180.0f;
			}
			else
			{
				/* Our orientation has already been set. */
				ang = unitTarget->GetOrientation();
			}
		}
		else
		{
			/* Players orientation is sent in movement packets */
			ang = unitTarget->GetOrientation();
		}

		// avoid teleporting into the model on scaled models
		const static float shadowstep_distance = 1.6f * unitTarget->GetFloatValue(OBJECT_FIELD_SCALE_X);
		float new_x = unitTarget->GetPositionX() - (shadowstep_distance * cosf(ang));
		float new_y = unitTarget->GetPositionY() - (shadowstep_distance * sinf(ang));
		
		/* Send a movement packet to "charge" at this target. Similar to warrior charge. */
		p_caster->z_axisposition = 0.0f;
		p_caster->SafeTeleport(p_caster->GetMapId(), p_caster->GetInstanceID(), LocationVector(new_x, new_y, (unitTarget->GetPositionZ() + 0.1f), unitTarget->GetOrientation()));
		
		return;
	}

	/* TODO: Remove Player From bg */

	if(unitTarget->GetTypeId() == TYPEID_PLAYER)
		HandleTeleport(spellId, unitTarget);
}

void Spell::SpellEffectApplyAura(uint32 i)	//	Apply Aura
{
	if(!unitTarget)
		return;
	// can't apply stuns/fear/polymorph/root etc on boss
	if ( !playerTarget )
	{
		if (u_caster && (u_caster != unitTarget))
		{
			Creature * c = (Creature*)( unitTarget );
			if (c)
			{

				/*
				Charm (Mind Control, enslave demon): 1
				Confuse (Blind etc): 2
				Fear: 4
				Root: 8
				Silence : 16
				Stun: 32
				Sheep: 64
				Banish: 128
				Sap: 256
				Taunt (aura): 512
				Decrease Speed (Hamstring) (aura): 1024
				Spell Haste (Curse of Tongues) (aura): 2048
				Interrupt Cast: 4096
				Mod Healing % (Mortal Strike) (aura): 8192
				Total Stats % (Vindication) (aura): 16384
				*/

				//Spells with Mechanic also add other ugly auras, but if the main aura is the effect --> immune to whole spell
				if (c->GetProto() && c->GetProto()->modImmunities)
				{
					bool immune = false;
					if (m_spellInfo->MechanicsType)
					{
						switch(m_spellInfo->MechanicsType)
						{
						case MECHANIC_CHARMED:
							if (c->GetProto()->modImmunities & 1)
								immune = true;
							break;
						case MECHANIC_DISORIENTED:
							if (c->GetProto()->modImmunities & 2)
								immune = true;
							break;
						case MECHANIC_FLEEING:
							if (c->GetProto()->modImmunities & 4)
								immune = true;
							break;
						case MECHANIC_ROOTED:
							if (c->GetProto()->modImmunities & 8)
								immune = true;
							break;
						case MECHANIC_SILENCED:
							if ( c->GetProto()->modImmunities & 16)
								immune = true;
							break;
						case MECHANIC_STUNNED:
							if (c->GetProto()->modImmunities & 32)
								immune = true;
							break;
						case MECHANIC_POLYMORPHED:
							if (c->GetProto()->modImmunities & 64)
								immune = true;
							break;
						case MECHANIC_BANISHED:
							if (c->GetProto()->modImmunities & 128)
								immune = true;
							break;
						}
					}
					else
					{
						// Spells wich do more than just one thing (damage and the effect) dont have a mechanic and we should only cancel the aura to be placed
						switch (m_spellInfo->EffectApplyAuraName[i])
						{
						case SPELL_AURA_MOD_CONFUSE:
							if (c->GetProto()->modImmunities & 2)
								immune = true;
							break;
						case SPELL_AURA_MOD_FEAR:
							if (c->GetProto()->modImmunities & 4)
								immune = true;
							break;
						case SPELL_AURA_MOD_TAUNT:
							if (c->GetProto()->modImmunities & 512)
								immune = true;
							break;
						case SPELL_AURA_MOD_STUN: // no idea if its needed, just to be sure
							if (c->GetProto()->modImmunities & 32)
								immune = true;
							break;
						case SPELL_AURA_MOD_SILENCE:
							if ((c->GetProto()->modImmunities & 4096) || (c->GetProto()->modImmunities & 16))
								immune = true;
							break;
						case SPELL_AURA_MOD_DECREASE_SPEED:
							if (c->GetProto()->modImmunities & 1024)
								immune = true;
							break;
						case SPELL_AURA_INCREASE_CASTING_TIME_PCT:
							if (c->GetProto()->modImmunities & 2048)
								immune = true;
							break;
						case SPELL_AURA_MOD_LANGUAGE: //hacky way to prefer that the COT icon is set to mob
							if (c->GetProto()->modImmunities & 2048)
								immune = true;
							break;
						case SPELL_AURA_MOD_HEALING_DONE_PERCENT:
							if (c->GetProto()->modImmunities & 8192)
								immune = true;
							break;
						case SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE:
							if (c->GetProto()->modImmunities & 16384)
								immune = true;
							break;
						}
					}
					if (immune)
						return;
				}
			}
		}
	}
	
	// avoid map corruption.
	if(unitTarget->GetInstanceID()!=m_caster->GetInstanceID())
		return;
//	if (!unitTarget->isAlive())
//		return;

	//check if we already have stronger aura
	Aura *pAura;

	std::map<uint32,Aura*>::iterator itr=unitTarget->tmpAura.find(GetProto()->Id);
	//if we do not make a check to see if the aura owner is the same as the caster then we will stack the 2 auras and they will not be visible client sided
	if(itr==unitTarget->tmpAura.end())
	{
		if( GetProto()->NameHash == SPELL_HASH_BLOOD_FRENZY && this->ProcedOnSpell )//Warrior's Blood Frenzy
			this->GetProto()->DurationIndex = this->ProcedOnSpell->DurationIndex;
		uint32 Duration = this->GetDuration();				
		
		// Handle diminishing returns, if it should be resisted, it'll make duration 0 here.
		if(!(GetProto()->Attributes & ATTRIBUTES_PASSIVE)) // Passive
			::ApplyDiminishingReturnTimer(&Duration, unitTarget, GetProto());

		if(!Duration)
		{
			//maybe add some resist messege to client here ?
			return;
		}
		pAura=AuraPool.PooledNew();
		if(g_caster && g_caster->GetUInt32Value(OBJECT_FIELD_CREATED_BY) && g_caster->m_summoner)
			 pAura->Init(GetProto(), Duration, g_caster->m_summoner, unitTarget);
		else
			pAura->Init(GetProto(), Duration, m_caster, unitTarget);

		pAura->pSpellId = pSpellId; //this is required for triggered spells
		
		unitTarget->tmpAura[GetProto()->Id] = pAura;		
	}
	else
	{
		 pAura=itr->second;
	}
	int32 miscValue;
	if(i_caster && m_caster->IsPlayer() && m_spellInfo->EffectApplyAuraName[i]==SPELL_AURA_PROC_TRIGGER_SPELL){
		miscValue = p_caster->GetItemInterface()->GetInventorySlotByGuid( i_caster->GetGUID() ); // Need to know on which hands attacks spell should proc
	}else{
		miscValue = m_spellInfo->EffectMiscValue[i];

	}
	pAura->AddMod(GetProto()->EffectApplyAuraName[i],damage,GetProto()->EffectMiscValue[i],i);

	switch(GetProto()->Id)
	{
	case 38177: // Blackwhelp Net
		{
			p_caster->CastSpell(unitTarget, 38178, true);
			((Creature*)unitTarget)->Despawn(1000, 360000);
		} break;
	}

}

void Spell::SpellEffectPowerDrain(uint32 i)  // Power Drain
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 powerField = UNIT_FIELD_POWER1+GetProto()->EffectMiscValue[i];
	uint32 curPower = unitTarget->GetUInt32Value(powerField);
	if( powerField == UNIT_FIELD_POWER1 && unitTarget->IsPlayer() )
	{
		Player* mPlayer = static_cast< Player* >( unitTarget );
		if( mPlayer->IsInFeralForm() )
			return;

		// Resilience - reduces the effect of mana drains by (CalcRating*2)%.
		damage *= float2int32( 1 - ( ( static_cast<Player*>(unitTarget)->CalcRating( PLAYER_RATING_MODIFIER_SPELL_CRIT_RESILIENCE ) * 2 ) / 100.0f ) );
	}
	uint32 amt = damage + ( ( u_caster->GetDamageDoneMod( GetProto()->School ) * 80 ) / 100 );
	
	if( amt > curPower )
		amt = curPower;

	unitTarget->SetUInt32Value( powerField, curPower - amt );

	u_caster->Energize( u_caster, GetProto()->Id, amt, GetProto()->EffectMiscValue[i] );
}

void Spell::SpellEffectHealthLeech(uint32 i) // Health Leech
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 curHealth = unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH);
	uint32 amt = damage;
	if(amt > curHealth)
	{
		amt = curHealth;
	}
	m_caster->DealDamage(unitTarget, damage, 0, 0, GetProto()->Id);

	uint32 playerCurHealth = m_caster->GetUInt32Value(UNIT_FIELD_HEALTH);
	uint32 playerMaxHealth = m_caster->GetUInt32Value(UNIT_FIELD_MAXHEALTH);

	if(playerCurHealth + amt > playerMaxHealth)
	{
		m_caster->SetUInt32Value(UNIT_FIELD_HEALTH, playerMaxHealth);
	}
	else
	{
		m_caster->SetUInt32Value(UNIT_FIELD_HEALTH, playerCurHealth + amt);
	}
}

void Spell::SpellEffectHeal(uint32 i) // Heal
{
	if(GetProto()->EffectChainTarget[i])//chain
	{
		if(!chaindamage)
		{
			chaindamage = damage;
			Heal((int32)chaindamage);
		}
		else
		{
			int32 reduce=GetProto()->EffectDieSides[i]+1;
			if(GetProto()->SpellGroupType && u_caster)
			{
				SM_FIValue(u_caster->SM_PJumpReduce,&reduce,GetProto()->SpellGroupType);
			}
			chaindamage -= (reduce * chaindamage) / 100;
			Heal((int32)chaindamage);
		}
	}
	else
	{
		//yep, the usual special case. This one is shaman talent : Nature's guardian
		//health is below 30%, we have a mother spell to get value from
		switch (GetProto()->Id)
		{
		case 31616:
			{
				if(unitTarget && unitTarget->IsPlayer() && pSpellId && unitTarget->GetHealthPct()<30)
				{
					//check for that 10 second cooldown
					SpellEntry *spellInfo = dbcSpell.LookupEntry(pSpellId );
					if(spellInfo)
					{
						//heal value is receivad by the level of current active talent :s
						//maybe we should use CalculateEffect(uint32 i) to gain SM benefits
						int32 value = 0;
						int32 basePoints = spellInfo->EffectBasePoints[i]+1;//+(m_caster->getLevel()*basePointsPerLevel);
						int32 randomPoints = spellInfo->EffectDieSides[i];
						if(randomPoints <= 1)
							value = basePoints;
						else
							value = basePoints + rand() % randomPoints;
						//the value is in percent. Until now it's a fixed 10%
						Heal(unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*value/100);
					}
				}
			}break;
		case 34299: //Druid: Improved Leader of the PAck
			{
				if (!unitTarget->IsPlayer() || !unitTarget->isAlive())
					break;

				Player* mPlayer = static_cast< Player* >( unitTarget );
				if( !mPlayer->IsInFeralForm() || (
					mPlayer->GetShapeShift() != FORM_CAT &&
					mPlayer->GetShapeShift() != FORM_BEAR &&
					mPlayer->GetShapeShift() != FORM_DIREBEAR ) )
					break;
				uint32 max = mPlayer->GetUInt32Value( UNIT_FIELD_MAXHEALTH );
				uint32 val = float2int32( ( ( mPlayer->FindAura( 34300 ) ) ? 0.04f : 0.02f ) * max );
				if (val)
					mPlayer->Heal(mPlayer,34299,(uint32)(val));
			}break;
		case 22845: // Druid: Frenzied Regeneration
			{
				if (!unitTarget->IsPlayer() || !unitTarget->isAlive())
					break;
				Player* mPlayer = static_cast< Player* >( unitTarget );
				if (!mPlayer->IsInFeralForm() || 
					(mPlayer->GetShapeShift() != FORM_BEAR &&
					mPlayer->GetShapeShift() != FORM_DIREBEAR))
					break;
				uint32 val = mPlayer->GetUInt32Value(UNIT_FIELD_POWER2);
				if (val>100)
					val = 100;
				mPlayer->SetUInt32Value(UNIT_FIELD_POWER2,mPlayer->GetUInt32Value(UNIT_FIELD_POWER2)-val);
				if (val)
					mPlayer->Heal(mPlayer,22845,uint32(val*2.5f));
			}break;
		case 18562: //druid - swiftmend
			{
				if( unitTarget )
				{
					uint32 new_dmg = 0;
					//consume rejuvenetaion and regrowth
					Aura * taura = unitTarget->FindAuraPosByNameHash( SPELL_HASH_REGROWTH ); //Regrowth
					if( taura != NULL && taura->GetSpellProto() != NULL)
					{
						uint32 amplitude = taura->GetSpellProto()->EffectAmplitude[1] / 1000;
						if( !amplitude )
							amplitude = 3;

						//our hapiness is that we did not store the aura mod amount so we have to recalc it
						Spell *spell = SpellPool.PooledNew();
						spell->Init( m_caster, taura->GetSpellProto(), false, NULL );
						uint32 healamount = spell->CalculateEffect( 1, unitTarget );
						SpellPool.PooledDelete( spell );
						new_dmg = healamount * 18 / amplitude;

						unitTarget->RemoveAura( taura );

						//do not remove flag if we still can cast it again
						if( !unitTarget->HasAurasWithNameHash( SPELL_HASH_REJUVENATION ) )
						{
							unitTarget->RemoveFlag( UNIT_FIELD_AURASTATE, AURASTATE_FLAG_REJUVENATE );	
							sEventMgr.RemoveEvents( unitTarget, EVENT_REJUVENATION_FLAG_EXPIRE );
						}
					}
					else
					{
						taura = unitTarget->FindAuraPosByNameHash( SPELL_HASH_REJUVENATION );//Rejuvenation
						if( taura != NULL && taura->GetSpellProto() != NULL )
						{
							uint32 amplitude = taura->GetSpellProto()->EffectAmplitude[0] / 1000;
							if( !amplitude )
								amplitude = 3;

							// our hapiness is that we did not store the aura mod amount so we have to recalc it
							Spell * spell = SpellPool.PooledNew();
							spell->Init( m_caster, taura->GetSpellProto(), false, NULL );
							uint32 healamount = spell->CalculateEffect( 0, unitTarget );
							SpellPool.PooledDelete( spell );
							new_dmg = healamount * 12 / amplitude;

							unitTarget->RemoveAura( taura );

							unitTarget->RemoveFlag( UNIT_FIELD_AURASTATE,AURASTATE_FLAG_REJUVENATE );
							sEventMgr.RemoveEvents( unitTarget,EVENT_REJUVENATION_FLAG_EXPIRE );
						}
					}
					if( new_dmg > 0 )
						Heal( (int32)new_dmg );
				}
			}break;
		default:
			Heal((int32)damage);
			break;
		}
	}
}

void Spell::SpellEffectQuestComplete(uint32 i) // Quest Complete
{
	if ( p_caster == NULL ) return;
	QuestLogEntry * en = p_caster->GetQuestLogForEntry( GetProto()->EffectMiscValue[i] );
	if ( en != NULL && !en->CanBeFinished() )
		en->SendQuestComplete();
}

//wand->
void Spell::SpellEffectWeapondamageNoschool(uint32 i) // Weapon damage + (no School)
{
	if(!unitTarget ||!u_caster)
		return;

	if( GetType() == SPELL_DMG_TYPE_RANGED && GetProto()->speed > 0.0f )
	{
		float time = (m_caster->CalcDistance(unitTarget) * 1000.0f) / GetProto()->speed;
		if(time <= 100.0f)
			u_caster->Strike( unitTarget, RANGED, GetProto(), 0, 0, 0, false, true );
		else
			sEventMgr.AddEvent(u_caster,&Unit::EventStrikeWithAbility,unitTarget->GetGUID(),
				GetProto(), (uint32)damage, EVENT_SPELL_DAMAGE_HIT, float2int32(time), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
	}
	else
		u_caster->Strike( unitTarget, ( GetType() == SPELL_DMG_TYPE_RANGED ? RANGED : MELEE ), GetProto(), damage, 0, 0, false, true );
}

void Spell::SpellEffectAddExtraAttacks(uint32 i) // Add Extra Attacks
{
	if(!u_caster)
		return;
	u_caster->m_extraattacks += damage;		
}

void Spell::SpellEffectDodge(uint32 i)
{
	//i think this actually enbles the skill to be able to dodge melee+ranged attacks
	//value is static and sets value directly which will be modified by other factors
	//this is only basic value and will be overwiten elsewhere !!!
//	if(unitTarget->IsPlayer())
//		unitTarget->SetFloatValue(PLAYER_DODGE_PERCENTAGE,damage);
}

void Spell::SpellEffectParry(uint32 i)
{
	if(unitTarget)
		unitTarget->setcanperry(true);
}

void Spell::SpellEffectBlock(uint32 i)
{
	//i think this actually enbles the skill to be able to block melee+ranged attacks
	//value is static and sets value directly which will be modified by other factors
//	if(unitTarget->IsPlayer())
//		unitTarget->SetFloatValue(PLAYER_BLOCK_PERCENTAGE,damage);
}

void Spell::SpellEffectCreateItem(uint32 i) // Create item 
{
	if(!p_caster)
		return;

	Item* newItem;
	Item *add;
	uint8 slot;
	SlotResult slotresult;

	skilllinespell* skill = objmgr.GetSpellSkill(GetProto()->Id);

	for(int j=0; j<3; j++) // now create the Items
	{
		ItemPrototype *m_itemProto;
		m_itemProto = ItemPrototypeStorage.LookupEntry( GetProto()->EffectSpellGroupRelation[j] );
		if (!m_itemProto)
			continue;

		if(GetProto()->EffectSpellGroupRelation[j] == 0)
			continue;

		uint32 item_count = damage;

		// tailoring specializations get +1 cloth bonus
		switch(GetProto()->Id)
		{
		case 36686: //Shadowcloth
			if(p_caster->HasSpell(26801)) item_count += 1;
			break;
		case 26751: // Primal Mooncloth
			if(p_caster->HasSpell(26798)) item_count += 1;
			break;
		case 31373: //Spellcloth
			if(p_caster->HasSpell(26797)) item_count += 1;
			break;
		}

		// item count cannot be more than allowed in a single stack
		if (item_count > m_itemProto->MaxCount)
			item_count = m_itemProto->MaxCount;

		// item count cannot be more than item unique value
		if (m_itemProto->Unique && item_count > m_itemProto->Unique)
			item_count = m_itemProto->Unique;

		if(p_caster->GetItemInterface()->CanReceiveItem(m_itemProto, item_count)) //reversed since it sends >1 as invalid and 0 as valid
		{
			SendCastResult(SPELL_FAILED_TOO_MANY_OF_ITEM);
			return;
		}

		slot = 0;
		add = p_caster->GetItemInterface()->FindItemLessMax(GetProto()->EffectSpellGroupRelation[j],1, false);
		if (!add)
		{
			slotresult = p_caster->GetItemInterface()->FindFreeInventorySlot(m_itemProto);
			if(!slotresult.Result)
			{
				  SendCastResult(SPELL_FAILED_TOO_MANY_OF_ITEM);
				  return;
			}
			
			newItem =objmgr.CreateItem(GetProto()->EffectSpellGroupRelation[i],p_caster);
			newItem->SetUInt64Value(ITEM_FIELD_CREATOR,m_caster->GetGUID());
			newItem->SetUInt32Value(ITEM_FIELD_STACK_COUNT, item_count);

			if (m_itemProto->RandomPropId)
			{
				RandomProps * iRandomProperty = lootmgr.GetRandomProperties(m_itemProto);
				newItem->SetRandomProperty(iRandomProperty->ID);
				newItem->ApplyRandomProperties(false);
			}
			if (m_itemProto->RandomSuffixId)
			{
				ItemRandomSuffixEntry * iRandomSuffix = lootmgr.GetRandomSuffix(m_itemProto);
				newItem->SetRandomSuffix(iRandomSuffix->id);
				newItem->ApplyRandomProperties(false);
			}

			if(p_caster->GetItemInterface()->SafeAddItem(newItem,slotresult.ContainerSlot, slotresult.Slot))
			{
				/*WorldPacket data(45);
				p_caster->GetSession()->BuildItemPushResult(&data, p_caster->GetGUID(), 1, item_count, GetProto()->EffectSpellGroupRelation[i] ,0,0xFF,1,0xFFFFFFFF);
				p_caster->SendMessageToSet(&data, true);*/
				p_caster->GetSession()->SendItemPushResult(newItem,true,false,true,true,slotresult.ContainerSlot,slotresult.Slot,item_count);
			} else {
				newItem->DeleteMe();
			}
		} 
		else 
		{
			//scale item_count down if total stack will be more than 20
			if(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + item_count > 20)
			{
				uint32 item_count_filled;
				item_count_filled = 20 - add->GetUInt32Value(ITEM_FIELD_STACK_COUNT);
				add->SetCount(20);
				add->m_isDirty = true;

				slotresult = p_caster->GetItemInterface()->FindFreeInventorySlot(m_itemProto);
				if(!slotresult.Result)
					item_count = item_count_filled;
				else
				{
					newItem =objmgr.CreateItem(GetProto()->EffectSpellGroupRelation[i],p_caster);
					newItem->SetUInt64Value(ITEM_FIELD_CREATOR,m_caster->GetGUID());
					newItem->SetUInt32Value(ITEM_FIELD_STACK_COUNT, item_count - item_count_filled);
					if(!p_caster->GetItemInterface()->SafeAddItem(newItem,slotresult.ContainerSlot, slotresult.Slot))
					{
						newItem->DeleteMe();
						item_count = item_count_filled;
					}
					else
						p_caster->GetSession()->SendItemPushResult(newItem, true, false, true, true, slotresult.ContainerSlot, slotresult.Slot, item_count);
				}
			}
			else
			{
				add->SetCount(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + item_count);
				add->m_isDirty = true;
				p_caster->GetSession()->SendItemPushResult(add, true,false,true,false,p_caster->GetItemInterface()->GetBagSlotByGuid(add->GetGUID()),0xFFFFFFFF,item_count);
			}

			/*WorldPacket data(45);
			p_caster->GetSession()->BuildItemPushResult(&data, p_caster->GetGUID(), 1, item_count, GetProto()->EffectSpellGroupRelation[i] ,0,0xFF,1,0xFFFFFFFF);
			p_caster->SendMessageToSet(&data, true);*/
		}
		if ( skill != NULL )
		{
			// skill up
			DetermineSkillUp( skill->skilline );

			// profession discoveries
			uint32 discovered_recipe = 0;
			std::set<ProfessionDiscovery*>::iterator itr = objmgr.ProfessionDiscoveryTable.begin();
			for ( ; itr != objmgr.ProfessionDiscoveryTable.end(); itr++ )
			{
				ProfessionDiscovery * pf = ( *itr );
				if ( pf != NULL && GetProto()->Id == pf->SpellId && p_caster->_GetSkillLineCurrent( skill->skilline ) >= pf->SkillValue && !p_caster->HasSpell( pf->SpellToDiscover ) && Rand( pf->Chance ) )
				{
					discovered_recipe = pf->SpellToDiscover;
					break;
				}
			}
			// if something discovered learn p_caster that recipe and broadcast message
			if ( discovered_recipe != 0 )
			{
				SpellEntry * se = dbcSpell.LookupEntry( discovered_recipe );
				if ( se != NULL )
				{
					p_caster->addSpell( discovered_recipe );
					WorldPacket * data;
					char msg[256];
					sprintf( msg, "%sDISCOVERY! %s has discovered how to create %s.|r", MSG_COLOR_GOLD, p_caster->GetName(), se->Name );
					data = sChatHandler.FillMessageData( CHAT_MSG_SYSTEM, LANG_UNIVERSAL,  msg, p_caster->GetGUID(), 0 );
					p_caster->GetMapMgr()->SendChatMessageToCellPlayers( p_caster, data, 2, 1, LANG_UNIVERSAL, p_caster->GetSession() );
					delete data;
				}
			}
		}
		p_caster->SaveToDB(false);
	}
}

void Spell::SpellEffectWeapon(uint32 i)
{
	if( playerTarget == NULL )
		return;

	uint32 skill = 0;
	uint32 spell = 0;

	switch( this->GetProto()->Id )
	{
	case 201:	// one-handed swords
		{
			skill = SKILL_SWORDS;
		}break;
	case 202:	// two-handed swords
		{
			skill = SKILL_2H_SWORDS;
		}break;
	case 203:	// Unarmed
		{
			skill = SKILL_UNARMED;
		}break;
	case 199:	// two-handed maces
		{
			skill = SKILL_2H_MACES;
		}break;
	case 198:	// one-handed maces
		{
			skill = SKILL_MACES;
		}break;
	case 197:	// two-handed axes
		{
			skill = SKILL_2H_AXES;
		}break;
	case 196:	// one-handed axes
		{
			skill = SKILL_AXES;
		}break;
	case 5011:	// crossbows
		{
			skill = SKILL_CROSSBOWS;
			spell = SPELL_RANGED_GENERAL;
		}break;
	case 227:	// staves
		{
			skill = SKILL_STAVES;
		}break;
	case 1180:	// daggers
		{
			skill = SKILL_DAGGERS;
		}break;
	case 200:	// polearms
		{
			skill = SKILL_POLEARMS;
		}break;
	case 15590:	// fist weapons
		{
			skill = SKILL_UNARMED;
		}break;
	case 264:	// bows
		{
			skill = SKILL_BOWS;
			spell = SPELL_RANGED_GENERAL;
		}break;
	case 266:	// guns
		{
			skill = SKILL_GUNS;
			spell = SPELL_RANGED_GENERAL;
		}break;
	case 2567:	// thrown
		{
			skill = SKILL_THROWN;
		}break;
	case 5009:	// wands
		{
			skill = SKILL_WANDS;
			spell = SPELL_RANGED_GENERAL;
		}break;
	//case 3386:	// spears
	//	skill = 0;	// ??!!
	//	break;
	default:
		{
			skill = 0;
			sLog.outDebug("WARNING: Could not determine skill for spell id %d (SPELL_EFFECT_WEAPON)", this->GetProto()->Id);
		}break;
	}

	// Don't add skills to players logging in.
	/*if((GetProto()->Attributes & ATTRIBUTES_PASSIVE) && playerTarget->m_TeleportState == 1)
		return;*/

	if(skill)
	{
		if(spell)
			playerTarget->addSpell(spell);

		// if we do not have the skill line
		if(!playerTarget->_HasSkillLine(skill))
		{
			playerTarget->_AddSkillLine(skill, 1, playerTarget->getLevel()*5);
		}
		else // unhandled.... if we have the skill line
		{
		}
	}
}

void Spell::SpellEffectDefense(uint32 i)
{
	//i think this actually enbles the skill to be able to use defense
	//value is static and sets value directly which will be modified by other factors
	//this is only basic value and will be overwiten elsewhere !!!
//	if(unitTarget->IsPlayer())
//		unitTarget->SetFloatValue(UNIT_FIELD_RESISTANCES,damage);
}

void Spell::SpellEffectPersistentAA(uint32 i) // Persistent Area Aura
{
	if(m_AreaAura == true || !m_caster->IsInWorld())
		return;
	//create only 1 dyn object
	uint32 dur = GetDuration();
	float r = GetRadius(i);

	//Note: this code seems to be useless
	//this must be only source point or dest point
	//this AREA aura it's apllied on area
	//it can'be on unit or self or item or object
	//uncomment it if i'm wrong
	//We are thinking in general so it might be useful later DK
	
	// grep: this is a hack!
	// our shitty dynobj system doesnt support GO casters, so we gotta
	// kinda have 2 summoners for traps that apply AA.
	DynamicObject * dynObj = m_caster->GetMapMgr()->CreateDynamicObject();
	 
	if(g_caster && g_caster->m_summoner && !unitTarget)
	{
		Unit * caster = g_caster->m_summoner;
		dynObj->Create(caster, this, g_caster->GetPositionX(), g_caster->GetPositionY(), 
			g_caster->GetPositionZ(), dur, r);
		m_AreaAura = true;
		return;
	}
		
	switch(m_targets.m_targetMask)
	{		
	case TARGET_FLAG_SELF:
		{
			dynObj->Create(u_caster, this,	m_caster->GetPositionX(), 
				m_caster->GetPositionY(), m_caster->GetPositionZ(), dur,r);		 
		}break;
	case TARGET_FLAG_UNIT:
		{
			if(!unitTarget||!unitTarget->isAlive())
				break;
			dynObj->Create( u_caster, this, unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(),
				dur, r);
		}break;
	case TARGET_FLAG_OBJECT:
		{
			if(!unitTarget)
				break;
			if(!unitTarget->isAlive())
				break;
			dynObj->Create(u_caster, this, unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(),
				dur, r);
		}break;
	case TARGET_FLAG_SOURCE_LOCATION:
		{
			dynObj->SetInstanceID(m_caster->GetInstanceID());
			dynObj->Create(u_caster, this, m_targets.m_srcX,
				m_targets.m_srcY, m_targets.m_srcZ, dur,r);
		}break;
	case TARGET_FLAG_DEST_LOCATION:
		{
			dynObj->SetInstanceID(m_caster->GetInstanceID());
			dynObj->Create(u_caster?u_caster:g_caster->m_summoner, this,
				m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ,dur,r);
		}break;
	default:
		return;
	}

	if(u_caster)
	if(GetProto()->ChannelInterruptFlags > 0)
	{
		u_caster->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT,dynObj->GetGUID());
		u_caster->SetUInt32Value(UNIT_CHANNEL_SPELL,GetProto()->Id);
	}
	m_AreaAura = true;	
}

void Spell::SpellEffectSummon(uint32 i) // Summon
{
	switch(m_spellInfo->EffectMiscValueB[i])
	{
	case SUMMON_TYPE_GUARDIAN:		SummonGuardian(i);		return;
	case SUMMON_TYPE_WILD:			SummonWild(i);			return;
	case SUMMON_TYPE_DEMON:			SummonDemon(i);			return;
	case SUMMON_TYPE_CREATE_TOTEM:	CreateSummonTotem(i);	return;

	case SUMMON_TYPE_POSSESSED:
	case SUMMON_TYPE_POSSESSED2:
		{
			SummonPossessed(i);
		}break;

	case SUMMON_TYPE_SUMMON:
		{
			SummonGeneric(i);
		}break;

	case SUMMON_TYPE_CRITTER:
	case SUMMON_TYPE_CRITTER2:
	case SUMMON_TYPE_CRITTER3:
		{
			SummonCritter(i);
		}break;

	case SUMMON_TYPE_TOTEM_FIRE:
	case SUMMON_TYPE_TOTEM_EARTH:
	case SUMMON_TYPE_TOTEM_WATER:
	case SUMMON_TYPE_TOTEM_AIR:
		{
			SummonTotem(i);
		}break;

	case SUMMON_TYPE_UNK1:
	case SUMMON_TYPE_UNK2:
	case SUMMON_TYPE_UNK3:
	case SUMMON_TYPE_UNK4:
	case SUMMON_TYPE_UNK5:
		break;

	default:
		{
			SummonGeneric(i);
			sLog.outDebug("EffectSummonType: Unhandled summon type %u", m_spellInfo->EffectMiscValueB[i]);
		}break;
	}
}

void Spell::SpellEffectLeap(uint32 i) // Leap
{
	float radius = GetRadius(i);

	// remove movement impeding auras
	u_caster->RemoveAurasByInterruptFlag(AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN);

#ifndef COLLISION

	if(!p_caster) return;

	WorldPacket data(SMSG_MOVE_KNOCK_BACK, 50);
	data << p_caster->GetNewGUID();
	data << getMSTime();
	data << cosf(p_caster->GetOrientation()) << sinf(p_caster->GetOrientation());
	data << radius;
	data << float(-10.0f);
	p_caster->GetSession()->SendPacket(&data);
	//m_caster->SendMessageToSet(&data, true);
#else
	// Let's not allow players to blink trew gates.
	// Until we fix the real problem this will work.
	if(p_caster && p_caster->m_bg && !p_caster->m_bg->HasStarted())
		return;

	float ori = m_caster->GetOrientation();				
	float posX = m_caster->GetPositionX()+(radius*(cosf(ori)));
	float posY = m_caster->GetPositionY()+(radius*(sinf(ori)));
	float z = CollideInterface.GetHeight(m_caster->GetMapId(), posX, posY, m_caster->GetPositionZ() + 2.0f);
	if(z == NO_WMO_HEIGHT)		// not found height, or on adt
		z = m_caster->GetMapMgr()->GetLandHeight(posX,posY);

	if( fabs( z - m_caster->GetPositionZ() ) >= 10.0f )
		return;

	LocationVector dest(posX, posY, z + 2.0f, ori);
	LocationVector destest(posX, posY, dest.z, ori);
	LocationVector src(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ() + 2.0f);

	if(CollideInterface.GetFirstPoint(m_caster->GetMapId(), src, destest, dest, -1.5f))
	{
		// hit an object new point is in dest.
		// is this necessary?
		//dest.z = CollideInterface.GetHeight(m_caster->GetMapId(), dest.x, dest.y, dest.z + 2.0f);
	}
	else
		dest.z = z;

	dest.o = u_caster->GetOrientation();
	if(p_caster)
	{
		p_caster->blinked = true;
		p_caster->SafeTeleport( p_caster->GetMapId(), p_caster->GetInstanceID(), dest );
	}
	else
	{
		u_caster->SetPosition(dest, true);
	}
#endif
}

void Spell::SpellEffectEnergize(uint32 i) // Energize
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 POWER_TYPE=UNIT_FIELD_POWER1+GetProto()->EffectMiscValue[i];

	uint32 curEnergy = (uint32)unitTarget->GetUInt32Value(POWER_TYPE);
	uint32 maxEnergy = (uint32)unitTarget->GetUInt32Value(POWER_TYPE+6);
	uint32 modEnergy = 0;
	//yess there is always someone special : shamanistic rage - talent
	if(GetProto()->Id==30824)
		modEnergy = damage*GetUnitTarget()->GetAP()/100;
	//paladin illumination
	else if(GetProto()->Id==20272 && ProcedOnSpell)
	{
		SpellEntry *motherspell=dbcSpell.LookupEntry(pSpellId);
		if(motherspell)
			modEnergy = (motherspell->EffectBasePoints[0]+1)*ProcedOnSpell->manaCost/100;
	}
	//paladin - Spiritual Attunement 
	else if(GetProto()->Id==31786 && ProcedOnSpell)
	{
		SpellEntry *motherspell=dbcSpell.LookupEntry(pSpellId);
		if(motherspell)
		{
			//heal amount from procspell (we only proced on a heal spell)
			uint32 healamt=0;
			if(ProcedOnSpell->Effect[0]==SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[0]==SPELL_EFFECT_SCRIPT_EFFECT)
				healamt=ProcedOnSpell->EffectBasePoints[0]+1;
			else if(ProcedOnSpell->Effect[1]==SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[1]==SPELL_EFFECT_SCRIPT_EFFECT)
				healamt=ProcedOnSpell->EffectBasePoints[1]+1;
			else if(ProcedOnSpell->Effect[2]==SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[2]==SPELL_EFFECT_SCRIPT_EFFECT)
				healamt=ProcedOnSpell->EffectBasePoints[2]+1;
			modEnergy = (motherspell->EffectBasePoints[0]+1)*(healamt)/100;
		}
	}
	else if (GetProto()->Id==2687){
		modEnergy = damage;
		if( p_caster != NULL )
		{
			/*for(set<uint32>::iterator itr = p_caster->mSpells.begin(); itr != p_caster->mSpells.end(); ++itr)
			{
				if(*itr == 12818)
					modEnergy += 60;
				else if(*itr == 12301)
					modEnergy += 30;
			}*/
			if(p_caster->mSpells.find(12818) != p_caster->mSpells.end())
				modEnergy += 60;
			if(p_caster->mSpells.find(12301) != p_caster->mSpells.end())
				modEnergy += 30;
		}
	}
	else
		modEnergy = damage;

	if( unitTarget->HasAura( 17619 ) ) 
	{
		modEnergy = uint32( modEnergy * 1.4f );	  
	}

	u_caster->Energize( unitTarget, GetProto()->Id, modEnergy, GetProto()->EffectMiscValue[i] );
}

void Spell::SpellEffectWeaponDmgPerc(uint32 i) // Weapon Percent damage
{
	if(!unitTarget || !u_caster)
		return;

	if( GetType() == SPELL_DMG_TYPE_MAGIC )
	{
		float fdmg = (float)CalculateDamage( u_caster, unitTarget, MELEE, 0, GetProto() );
		uint32 dmg = float2int32(fdmg*(float(damage/100.0f)));
		u_caster->SpellNonMeleeDamageLog(unitTarget, GetProto()->Id, dmg, false, false, false);
	}
	else
	{
		uint32 _type;
		if( GetType() == SPELL_DMG_TYPE_RANGED )
			_type = RANGED;
		else
		{
			if (GetProto()->AttributesExC & 0x1000000)
				_type = OFFHAND;
			else
				_type = MELEE;
		}

		u_caster->Strike( unitTarget, _type, GetProto(), add_damage, damage, 0, false, true );
	}
}

void Spell::SpellEffectTriggerMissile(uint32 i) // Trigger Missile
{
	//Used by mortar team
	//Triggers area affect spell at destinatiom
	if(!m_caster)
		return;

	uint32 spellid = GetProto()->EffectTriggerSpell[i];
	if(spellid == 0)
		return;

	SpellEntry *spInfo = dbcSpell.LookupEntry(spellid);
	if(!spInfo)
		return;

	float spellRadius = GetRadius(i);

	//triggered missile handles the radius and stuff
	if (spellRadius == 0.0f)
	{
		Spell* newspell = SpellPool.PooledNew();
		newspell->Init(m_caster, spInfo, true, NULL);
		SpellCastTargets t;

		t=m_targets;

		//use unit target
		if (m_targets.m_unitTarget && m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget) != NULL)
		{
			t.m_targetMask |= TARGET_FLAG_DEST_LOCATION;
			t.m_destX=m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget)->GetPositionX();
			t.m_destY=m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget)->GetPositionY();
			t.m_destZ=m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget)->GetPositionZ();
			t.m_srcX=t.m_destX;
			t.m_srcY=t.m_destY;
			t.m_srcZ=t.m_destZ;
		}

		newspell->prepare(&t);
	}

	for(std::set<Object*>::iterator itr = m_caster->GetInRangeSetBegin(); itr != m_caster->GetInRangeSetEnd(); itr++ )
	{
		if(!((*itr)->IsUnit()) || !((Unit*)(*itr))->isAlive())
			continue;
		Unit *t=(Unit*)(*itr);
	
		float r;
		float d=m_targets.m_destX-t->GetPositionX();
		r=d*d;
		d=m_targets.m_destY-t->GetPositionY();
		r+=d*d;
		d=m_targets.m_destZ-t->GetPositionZ();
		r+=d*d;
		if(sqrt(r)> spellRadius)
			continue;
		
		if(!isAttackable(m_caster, (Unit*)(*itr)))//Fixme only enemy targets?
			continue;

		Spell * sp = SpellPool.PooledNew();
		sp->Init(m_caster,spInfo,true,NULL);
		SpellCastTargets tgt;
		tgt.m_unitTarget=(*itr)->GetGUID();
		sp->prepare(&tgt);
	}
}

void Spell::SpellEffectOpenLock(uint32 i) // Open Lock
{
	if(!p_caster)
		return;
		
	uint8 loottype = 0;

	uint32 locktype=GetProto()->EffectMiscValue[i];
	switch(locktype)
	{
		case LOCKTYPE_PICKLOCK:
		{
			uint32 v = 0;
			uint32 lockskill = p_caster->_GetSkillLineCurrent(SKILL_LOCKPICKING);

			if(itemTarget)
			{	
				if(!itemTarget->locked)
					return;
						
				Lock *lock = dbcLock.LookupEntry( itemTarget->GetProto()->LockId );
				if(!lock) return;
				for(int i=0;i<5;i++)
					if(lock->locktype[i] == 2 && lock->minlockskill[i] && lockskill >= lock->minlockskill[i])
					{
						v = lock->minlockskill[i];
						itemTarget->locked = false;
						itemTarget->SetFlag(ITEM_FIELD_FLAGS,4); // unlock
						DetermineSkillUp(SKILL_LOCKPICKING,v/5);
						break;
					}
			}
			else if(gameObjTarget)
			{
				GameObjectInfo *info = GameObjectNameStorage.LookupEntry(gameObjTarget->GetEntry());
				if(!info || gameObjTarget->GetUInt32Value(GAMEOBJECT_STATE) == 0) return;
				Lock *lock = dbcLock.LookupEntry( info->SpellFocus );
				if(lock == 0)
					return;

				for(int i=0;i<5;i++)
				{
					if(lock->locktype[i] == 2 && lock->minlockskill[i] && lockskill >= lock->minlockskill[i])
					{
						v = lock->minlockskill[i];
						gameObjTarget->SetUInt32Value(GAMEOBJECT_FLAGS, 0);
						gameObjTarget->SetUInt32Value(GAMEOBJECT_STATE, 1);
						//Add Fill GO loot here
						if(gameObjTarget->loot.items.size() == 0)
						{
							lootmgr.FillGOLoot(&gameObjTarget->loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
							DetermineSkillUp(SKILL_LOCKPICKING,v/5); //to prevent free skill up
						}
						loottype = LOOT_CORPSE;
						//End of it
						break;
					}
				}
			}
		}
		break;
		case LOCKTYPE_HERBALISM:
		{
			if(!gameObjTarget) return;	  
			
			uint32 v = gameObjTarget->GetGOReqSkill();
			bool bAlreadyUsed = false;
		 
			if(Rand(100.0f)) // 3% chance to fail//why?
			{
				if( static_cast< Player* >( m_caster )->_GetSkillLineCurrent( SKILL_HERBALISM ) < v )
				{
					//SendCastResult(SPELL_FAILED_LOW_CASTLEVEL);
					return;
				}
				else
				{
					if( gameObjTarget->loot.items.size() == 0 )
					{
						lootmgr.FillGOLoot(&gameObjTarget->loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
					}
					else
						bAlreadyUsed = true;
				}
				loottype = LOOT_SKINNING;
			}
			else
			{
				/*
				if(rand()%100 <= 30)
				{
					//30% chance to not be able to reskin on fail
					((Creature*)unitTarget)->Skinned = true;
					WorldPacket *pkt=unitTarget->BuildFieldUpdatePacket(UNIT_FIELD_FLAGS,0);
					static_cast< Player* >( m_caster )->GetSession()->SendPacket(pkt);
					delete pkt;

				}*/
				SendCastResult(SPELL_FAILED_TRY_AGAIN);
			}
			//Skill up
			if(!bAlreadyUsed) //Avoid cheats with opening/closing without taking the loot
				DetermineSkillUp(SKILL_HERBALISM,v/5); 
		}
		break;
		case LOCKTYPE_MINING:
		{
			if(!gameObjTarget) return;

			uint32 v = gameObjTarget->GetGOReqSkill();
			bool bAlreadyUsed = false;

			if( Rand( 100.0f ) ) // 3% chance to fail//why?
			{
				if( static_cast< Player* >( m_caster )->_GetSkillLineCurrent( SKILL_MINING ) < v )
				{
					//SendCastResult(SPELL_FAILED_LOW_CASTLEVEL);
					return;
				}
				else if( gameObjTarget->loot.items.size() == 0 )
				{
					lootmgr.FillGOLoot(&gameObjTarget->loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
				}	
				else
					bAlreadyUsed = true;

				loottype = LOOT_SKINNING;
			}
			else
			{
				SendCastResult(SPELL_FAILED_TRY_AGAIN);
			}
			//Skill up
			if(!bAlreadyUsed) //Avoid cheats with opening/closing without taking the loot
				DetermineSkillUp(SKILL_MINING,v/5);
		}
		break;
		case LOCKTYPE_SLOW_OPEN: // used for BG go's
		{
			if(!gameObjTarget ) return;
			if(p_caster && p_caster->m_bg)
				if(p_caster->m_bg->HookSlowLockOpen(gameObjTarget,p_caster,this))
					return;

			uint32 spellid = !gameObjTarget->GetInfo()->Unknown1 ? 23932 : gameObjTarget->GetInfo()->Unknown1;
			SpellEntry*en=dbcSpell.LookupEntry(spellid);
			Spell * sp = SpellPool.PooledNew();
			sp->Init(p_caster,en,true,NULL);
			SpellCastTargets tgt;
			tgt.m_unitTarget=gameObjTarget->GetGUID();
			sp->prepare(&tgt);
			return;
		}	
		break;
		case LOCKTYPE_QUICK_CLOSE:
			{
				if(!gameObjTarget ) return;
				gameObjTarget->EventCloseDoor();
			}
		break;
		default://not profession
		{
			if(!gameObjTarget ) return;

			if( gameObjTarget->GetUInt32Value( GAMEOBJECT_TYPE_ID ) == GAMEOBJECT_TYPE_GOOBER)
					CALL_GO_SCRIPT_EVENT(gameObjTarget, OnActivate)(static_cast<Player*>(p_caster));
			
			if(sQuestMgr.OnActivateQuestGiver(gameObjTarget, p_caster))
				return;

			if(sQuestMgr.OnGameObjectActivate(p_caster, gameObjTarget))
			{
				p_caster->UpdateNearbyGameObjects();
				return;
			}

			if(gameObjTarget->loot.items.size() == 0)
			{
				lootmgr.FillGOLoot(&gameObjTarget->loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
			}
			loottype= LOOT_CORPSE;
		}
		break;
	};
	if( gameObjTarget != NULL && gameObjTarget->GetUInt32Value( GAMEOBJECT_TYPE_ID ) == GAMEOBJECT_TYPE_CHEST)
		static_cast< Player* >( m_caster )->SendLoot( gameObjTarget->GetGUID(), loottype );
}

void Spell::SpellEffectOpenLockItem(uint32 i)
{
	Unit* caster = u_caster;
	if(!caster && i_caster)
		caster = i_caster->GetOwner();

	if(!gameObjTarget || !gameObjTarget->IsInWorld()) 
		return;
	
	if( caster && caster->IsPlayer() && sQuestMgr.OnGameObjectActivate( (static_cast<Player*>(caster)), gameObjTarget ) )
		static_cast<Player*>(caster)->UpdateNearbyGameObjects();

	CALL_GO_SCRIPT_EVENT(gameObjTarget, OnActivate)(static_cast<Player*>(caster));
	gameObjTarget->SetUInt32Value(GAMEOBJECT_STATE, 0);	

	if( gameObjTarget->GetEntry() == 183146)
	{
		gameObjTarget->Despawn(1);
		return;
	}

	if( gameObjTarget->GetUInt32Value( GAMEOBJECT_TYPE_ID ) == GAMEOBJECT_TYPE_CHEST)
	{
		lootmgr.FillGOLoot(&gameObjTarget->loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
		if(gameObjTarget->loot.items.size() > 0)
		{
			((Player*)caster)->SendLoot(gameObjTarget->GetGUID(),LOOT_CORPSE);
		}
	}

	if( gameObjTarget->GetUInt32Value( GAMEOBJECT_TYPE_ID ) == GAMEOBJECT_TYPE_DOOR)
		gameObjTarget->SetUInt32Value(GAMEOBJECT_FLAGS, 33);

	if(gameObjTarget->GetMapMgr()->GetMapInfo()->type==INSTANCE_NULL)//dont close doors for instances
		sEventMgr.AddEvent(gameObjTarget,&GameObject::EventCloseDoor, EVENT_GAMEOBJECT_DOOR_CLOSE,10000,1,0);
	
	sEventMgr.AddEvent(gameObjTarget, &GameObject::Despawn, (uint32)1, EVENT_GAMEOBJECT_ITEM_SPAWN, 6*60*1000, 1, 0);
}

void Spell::SpellEffectProficiency(uint32 i)
{
	uint32 skill = 0;
	skilllinespell* skillability = objmgr.GetSpellSkill(GetProto()->Id);
	if (skillability)
		skill = skillability->skilline;
	skilllineentry* sk = dbcSkillLine.LookupEntry(skill);
	if(skill)
	{
		if(playerTarget)
		{
			if(playerTarget->_HasSkillLine(skill))
			{
				// Increase it by one
				// playerTarget->AdvanceSkillLine(skill);
			}
			else
			{
				// Don't add skills to players logging in.
				/*if((GetProto()->Attributes & 64) && playerTarget->m_TeleportState == 1)
					return;*/

				if(sk && sk->type == SKILL_TYPE_WEAPON)
					playerTarget->_AddSkillLine(skill, 1, 5*playerTarget->getLevel());
				else
					playerTarget->_AddSkillLine(skill, 1, 1);				
			}
		}
	}
}

void Spell::SpellEffectSendEvent(uint32 i) //Send Event
{
	//This is mostly used to trigger events on quests or some places
	SpellEntry * proto = GetProto();
	if( proto == NULL )
		return;

	//use target, could be null, but were passing spell too so caster can be taken from spell easier
	sScriptMgr.CreateScriptClassForEvent(proto->EffectMiscValue[i], unitTarget, NULL, this);

	uint32 spellId = proto->Id;

	// Try a dummy SpellHandler
	if(sScriptMgr.CallScriptedDummySpell(spellId, i, this))
		return;

	switch(spellId)
	{
	// WSG Flags
	case 23333:
	case 23335:
		{
			if (p_caster && p_caster->m_bg) {
				/* set the flag holder */
				p_caster->m_bgHasFlag = true;

				if( p_caster->GetTeam() == 1 )
					p_caster->m_bg->SendChatMessage( CHAT_MSG_BG_EVENT_HORDE, p_caster->GetGUID(), "The Alliance flag was picked up by %s!", p_caster->GetName() );
				else
					p_caster->m_bg->SendChatMessage( CHAT_MSG_BG_EVENT_ALLIANCE, p_caster->GetGUID(), "The Horde flag was picked up by %s!", p_caster->GetName() );
			}
		}break;

	// Place Loot
	case 25720: // Places the Bag of Gold at the designated Drop-Off Point.
		{

		}break;

	// Item - Cleansing Vial DND
	case 29297: // Empty the vial near the Bones of Aggonar to cleanse the waters of their demonic taint.
		{
			QuestLogEntry *en=p_caster->GetQuestLogForEntry(9427);
			if(!en)
				return;
			en->SendQuestComplete();
		}break;

	//Warlock: Summon Succubus Quest
	case 8674:
	case 9223:
	case 9224:
		{
			CreatureInfo * ci = CreatureNameStorage.LookupEntry(5677);
			CreatureProto * cp = CreatureProtoStorage.LookupEntry(5677);
			if( !ci || !cp )
				return;

			Creature * pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
			pCreature->Load(cp, p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), p_caster->GetOrientation());
			pCreature->_setFaction();
			pCreature->GetAIInterface()->Init(pCreature,AITYPE_AGRO,MOVEMENTTYPE_NONE);
			pCreature->GetAIInterface()->taunt(p_caster,true);
			pCreature->_setFaction();
			pCreature->PushToWorld(p_caster->GetMapMgr());
			sEventMgr.AddEvent(pCreature, &Creature::SafeDelete, EVENT_CREATURE_REMOVE_CORPSE,60000, 1, 0);
		}break;

	//Warlock: Summon Voidwalker Quest
	case 30208:
	case 9221:
	case 9222:
	case 7728:
		{
			CreatureInfo * ci = CreatureNameStorage.LookupEntry(5676);
			CreatureProto * cp = CreatureProtoStorage.LookupEntry(5676);
			if( !ci || !cp )
				return;

			Creature * pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
			pCreature->Load(cp, p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), p_caster->GetOrientation());
			pCreature->_setFaction();
			pCreature->GetAIInterface()->Init(pCreature,AITYPE_AGRO,MOVEMENTTYPE_NONE);
			pCreature->GetAIInterface()->taunt(p_caster,true);
			pCreature->_setFaction();
			pCreature->PushToWorld(p_caster->GetMapMgr());
			sEventMgr.AddEvent(pCreature, &Creature::SafeDelete, EVENT_CREATURE_REMOVE_CORPSE,60000, 1, 0);
		}break;

	//Warlock: Summon Felhunter Quest
	case 8712:
		{
			CreatureInfo * ci = CreatureNameStorage.LookupEntry(6268);
			CreatureProto * cp = CreatureProtoStorage.LookupEntry(6268);
			if( !ci || !cp )
				return;

			Creature * pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
			pCreature->Load(cp, p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), p_caster->GetOrientation());
			pCreature->_setFaction();
			pCreature->GetAIInterface()->Init(pCreature,AITYPE_AGRO,MOVEMENTTYPE_NONE);
			pCreature->GetAIInterface()->taunt(p_caster,true);
			pCreature->_setFaction();
			pCreature->PushToWorld(p_caster->GetMapMgr());
			sEventMgr.AddEvent(pCreature, &Creature::SafeDelete, EVENT_CREATURE_REMOVE_CORPSE,60000, 1, 0);
		}break;

	//Item: Douse Eternal Flame
	case 31497:
		{	
			QuestLogEntry *en=p_caster->GetQuestLogForEntry(9737);
			if(!en)
				return;
			en->SendQuestComplete();

			Creature *Aurius = p_caster->GetMapMgr()->GetSqlIdCreature(52359);
			if(!Aurius)
				return;
#pragma warning(disable : 4305)
			Aurius->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 14);
			Aurius->GetMapMgr()->GetInterface()->SpawnCreature(17910, 3676.666,-3631.520,139.944,5.32, true, true, 0, 0);
			Aurius->GetMapMgr()->GetInterface()->SpawnCreature(17911, 3673.011,-3630.626,139.944,5.32, true, true, 0, 0);
			Aurius->GetMapMgr()->GetInterface()->SpawnCreature(17912, 3670.827,-3632.145,139.944,5.32, true, true, 0, 0);
			Aurius->GetMapMgr()->GetInterface()->SpawnCreature(17913, 3673.352,-3633.446,139.944,5.32, true, true, 0, 0);
			Aurius->GetMapMgr()->GetInterface()->SpawnCreature(17914, 3670.076,-3635.723,139.944,5.32, true, true, 0, 0);
			Aurius->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "For the Light!");
		}break;
	}
}

void Spell::SpellEffectApplyAA(uint32 i) // Apply Area Aura
{
	if(!unitTarget || !unitTarget->isAlive())
		return;
	if(u_caster!=unitTarget)
		return;

	Aura*pAura;
	std::map<uint32,Aura*>::iterator itr=unitTarget->tmpAura.find(GetProto()->Id);
	if(itr==unitTarget->tmpAura.end())
	{
		pAura = AuraPool.PooledNew();
		pAura->Init(GetProto(),GetDuration(),m_caster,unitTarget);
		
		unitTarget->tmpAura [GetProto()->Id]= pAura;
	
		float r=GetRadius(i);
		if(!sEventMgr.HasEvent(pAura, EVENT_AREAAURA_UPDATE))		/* only add it once */
			sEventMgr.AddEvent(pAura, &Aura::EventUpdateAA,r*r, EVENT_AREAAURA_UPDATE, 1000, 0,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);	

	}else 
	{
		pAura=itr->second;	
	}
 
	pAura->AddMod(GetProto()->EffectApplyAuraName[i],damage,GetProto()->EffectMiscValue[i],i);
}

void Spell::SpellEffectLearnSpell(uint32 i) // Learn Spell
{
	if(playerTarget == 0 && unitTarget && unitTarget->IsPet())
	{
		// bug in target map fill?
		//playerTarget = m_caster->GetMapMgr()->GetPlayer((uint32)m_targets.m_unitTarget);
		SpellEffectLearnPetSpell(i);
		return;
	}

	if( GetProto()->Id == 483 )		// "Learning"
	{
		if( !i_caster || !p_caster )
			return;

		uint32 spellid = 0;
		for(int i = 0; i < 5; ++i)
		{
			if( i_caster->GetProto()->Spells[i].Trigger == LEARNING && i_caster->GetProto()->Spells[i].Id != 0 )
			{
				spellid = i_caster->GetProto()->Spells[i].Id;
				break;
			}
		}

		if( !spellid || !dbcSpell.LookupEntryForced(spellid) )
			return;

		// learn me!
		p_caster->addSpell( spellid );

		// no normal handler
		return;
	}

	if(playerTarget)
	{
		/*if(u_caster && isHostile(playerTarget, u_caster))
			return;*/

		uint32 spellToLearn = GetProto()->EffectTriggerSpell[i];
		playerTarget->addSpell(spellToLearn);
		//smth is wrong here, first we add this spell to player then we may cast it on player...
		SpellEntry *spellinfo = dbcSpell.LookupEntry(spellToLearn);
		// Learn and/or remove related spells.
		switch(spellinfo->Id)
 		{
/*		-- Learn Related Spells --		*/
		case 266: // Guns -- Learn Shoot
			playerTarget->addSpell(3018);
			if(!playerTarget->_HasSkillLine(SKILL_GUNS))
				playerTarget->_AddSkillLine(SKILL_GUNS, 1, playerTarget->getLevel()*5);
			break;
		case 364: // Bows -- Learn Shoot
			playerTarget->addSpell(SPELL_RANGED_GENERAL);
			if(!playerTarget->_HasSkillLine(SKILL_BOWS))
				playerTarget->_AddSkillLine(SKILL_BOWS, 1, playerTarget->getLevel()*5);
			break;
		case 5009: // Wands -- Learn Shoot
			playerTarget->addSpell(5019);
			if(!playerTarget->_HasSkillLine(SKILL_WANDS))
				playerTarget->_AddSkillLine(SKILL_WANDS, 1, playerTarget->getLevel()*5);
			break;
/*		-- Remove Related Spells --		*/
		case 26801: //Shadoweave Tailoring
			playerTarget->removeSpell(26798,false,false,0); //Mooncloth Tailoring
			playerTarget->removeSpell(26797,false,false,0); //Spellfire Tailoring
 			break;
		case 26798: // Mooncloth Tailoring
			playerTarget->removeSpell(26801,false,false,0); //Shadoweave Tailoring
			playerTarget->removeSpell(26797,false,false,0); //Spellfire Tailoring
 			break;
		case 26797: //Spellfire Tailoring
			playerTarget->removeSpell(26801,false,false,0); //Shadoweave Tailoring
			playerTarget->removeSpell(26798,false,false,0); //Mooncloth Tailoring
 			break;
 		case 10656: //Dragonscale Leatherworking
			playerTarget->removeSpell(10658,false,false,0); //Elemental Leatherworking
			playerTarget->removeSpell(10660,false,false,0); //Tribal Leatherworking
 			break;
 		case 10658: //Elemental Leatherworking
			playerTarget->removeSpell(10656,false,false,0); //Dragonscale Leatherworking
			playerTarget->removeSpell(10660,false,false,0); //Tribal Leatherworking
 			break;
 		case 10660: //Tribal Leatherworking
			playerTarget->removeSpell(10656,false,false,0); //Dragonscale Leatherworking
			playerTarget->removeSpell(10658,false,false,0); //Elemental Leatherworking
 			break;
 		case 28677: //Elixir Master
			playerTarget->removeSpell(28675,false,false,0); //Potion Master
			playerTarget->removeSpell(28672,false,false,0); //Transmutation Maste
 			break;
 		case 28675: //Potion Master
			playerTarget->removeSpell(28677,false,false,0); //Elixir Master
			playerTarget->removeSpell(28672,false,false,0); //Transmutation Maste
 			break;
 		case 28672: //Transmutation Master
			playerTarget->removeSpell(28675,false,false,0); //Potion Master
			playerTarget->removeSpell(28677,false,false,0); //Elixir Master
 			break;
 		case 20219: //Gnomish Engineer
			playerTarget->removeSpell(20222,false,false,0); //Goblin Engineer
 			break;
 		case 20222: //Goblin Engineer
			playerTarget->removeSpell(20219,false,false,0); //Gnomish Engineer
 			break;
 		case 9788: //Armorsmith
			playerTarget->removeSpell(9787,false,false,0); //Weaponsmith
			playerTarget->removeSpell(17039,false,false,0); //Master Swordsmith
			playerTarget->removeSpell(17040,false,false,0); //Master Hammersmith
			playerTarget->removeSpell(17041,false,false,0); //Master Axesmith
 			break;
 		case 9787: //Weaponsmith
			playerTarget->removeSpell(9788,false,false,0); //Armorsmith
 			break;
 		case 17041: //Master Axesmith
			playerTarget->removeSpell(9788,false,false,0); //Armorsmith
			playerTarget->removeSpell(17040,false,false,0); //Master Hammersmith
			playerTarget->removeSpell(17039,false,false,0); //Master Swordsmith
 			break;
 		case 17040: //Master Hammersmith
			playerTarget->removeSpell(9788,false,false,0); //Armorsmith
			playerTarget->removeSpell(17039,false,false,0); //Master Swordsmith
			playerTarget->removeSpell(17041,false,false,0); //Master Axesmith
 			break;
 		case 17039: //Master Swordsmith
			playerTarget->removeSpell(9788,false,false,0); //Armorsmith
			playerTarget->removeSpell(17040,false,false,0); //Master Hammersmith
			playerTarget->removeSpell(17041,false,false,0); //Master Axesmith
 			break;
 		}
		for(uint32 i=0;i<3;i++)
			if(	spellinfo->Effect[i] == SPELL_EFFECT_WEAPON ||
				spellinfo->Effect[i] == SPELL_EFFECT_PROFICIENCY ||
				spellinfo->Effect[i] == SPELL_EFFECT_DUAL_WIELD )
			{
				Spell *sp = SpellPool.PooledNew();
				sp->Init(unitTarget, spellinfo, true, NULL);
				SpellCastTargets targets;
				targets.m_unitTarget = unitTarget->GetGUID();
				targets.m_targetMask = 0x02;
				sp->prepare(&targets);
				break;
			}
		return;
	}

	// if we got here... try via pet spells..
	SpellEffectLearnPetSpell(i);
}

void Spell::SpellEffectSpellDefense(uint32 i)
{
	//used to enable this ability. We use it all the time ...
}

void Spell::SpellEffectLearnPetSpell(uint32 i)
{
	/*if(unitTarget && m_caster->GetTypeId() == TYPEID_PLAYER)
	{
		if(unitTarget->IsPet() && unitTarget->GetTypeId() == TYPEID_UNIT)
		{
			static_cast< Player* >(m_caster)->AddPetSpell(GetProto()->EffectTriggerSpell[i], unitTarget->GetEntry());
		}
	}*/

	if(unitTarget && unitTarget->IsPet() && p_caster)
	{
		Pet * pPet = static_cast<Pet*>( unitTarget );
		if(pPet->IsSummon())
			p_caster->AddSummonSpell(unitTarget->GetEntry(), GetProto()->EffectTriggerSpell[i]);
		
		pPet->AddSpell( dbcSpell.LookupEntry( GetProto()->EffectTriggerSpell[i] ), true );

		// Send Packet
		WorldPacket data(SMSG_SET_AURA_SINGLE, 22);
		data << pPet->GetGUID() << uint8(0) << uint32(GetProto()->EffectTriggerSpell[i]) << uint32(-1) << uint32(0);
		p_caster->GetSession()->SendPacket(&data);
	}
}

void Spell::SpellEffectDispel(uint32 i) // Dispel
{
	if(!u_caster || !unitTarget)
		return;

	Aura *aur;
	uint32 start,end;
	if(isAttackable(u_caster,unitTarget))
	{
		start=0;
		end=MAX_POSITIVE_AURAS;
		if (unitTarget->SchoolImmunityList[GetProto()->School])
			return;
	}
	else
	{
		start=MAX_POSITIVE_AURAS;
		end=MAX_AURAS;
	}
	
	WorldPacket data(SMSG_SPELLDISPELLOG, 16);

	bool finish = false;

	for(uint32 x=start;x<end;x++)
	if(unitTarget->m_auras[x])
	{
		bool auraRemoved = false;
		aur = unitTarget->m_auras[x];
		//Nothing can dispel resurrection sickness;
		if(!aur->IsPassive() && !(aur->GetSpellProto()->Attributes & ATTRIBUTES_IGNORE_INVULNERABILITY))
		{
			if(GetProto()->DispelType == DISPEL_ALL)
			{
				unitTarget->HandleProc( PROC_ON_PRE_DISPELL_AURA_VICTIM , u_caster , GetProto(), aur->GetSpellId() );

				data.clear();
				data << m_caster->GetNewGUID();
				data << unitTarget->GetNewGUID();
				data << (uint32)1;//probably dispel type
				data << aur->GetSpellId();
				m_caster->SendMessageToSet(&data,true);
				unitTarget->RemoveAura(aur);
				auraRemoved = true;

				if(!--damage)
					finish = true;
			}
			else if(aur->GetSpellProto()->DispelType == GetProto()->EffectMiscValue[i])
			{
				unitTarget->HandleProc( PROC_ON_PRE_DISPELL_AURA_VICTIM , u_caster , GetProto(), aur->GetSpellId() );

				data.clear();
				data << m_caster->GetNewGUID();
				data << unitTarget->GetNewGUID();
				data << (uint32)1;
				data << aur->GetSpellId();
				m_caster->SendMessageToSet(&data,true);
				unitTarget->RemoveAllAuras(aur->GetSpellProto()->Id,aur->GetCasterGUID());
				auraRemoved = true;

				if(!--damage)
					finish = true;
			}	
			
			if (auraRemoved)
			{
				if( aur->GetSpellProto()->NameHash == SPELL_HASH_UNSTABLE_AFFLICTION )
				{
					SpellEntry *spellInfo = dbcSpell.LookupEntry(31117);
					if ( spellInfo != NULL )
					{
						Spell *spell = SpellPool.PooledNew();
						spell->Init(u_caster, spellInfo ,true, NULL);
						spell->forced_basepoints[0] = (aur->GetSpellProto()->EffectBasePoints[0]+1)*9; //damage effect
						spell->ProcedOnSpell = GetProto();
						spell->pSpellId = aur->GetSpellId();
						SpellCastTargets targets;
						targets.m_unitTarget = u_caster->GetGUID();
						spell->prepare(&targets);
					}
				}
				else if ( aur->GetSpellProto()->NameHash == SPELL_HASH_LIFEBLOOM )
				{
					Spell* spell=SpellPool.PooledNew();
					spell->Init(aur->GetCaster(), aur->GetSpellProto(), true, NULL);
					spell->SetUnitTarget( unitTarget );
					spell->Heal( aur->mod->m_amount );
				}
			}

		}
		if (finish)
			return;
	}
}

void Spell::SpellEffectDualWield(uint32 i)
{
	if(m_caster->GetTypeId() != TYPEID_PLAYER) 
		return;

	Player *pPlayer = static_cast< Player* >( m_caster );

	if( !pPlayer->_HasSkillLine( SKILL_DUAL_WIELD ) )
		 pPlayer->_AddSkillLine( SKILL_DUAL_WIELD, 1, 1 );
	
	//	Increase it by one
	//	dual wield is 1/1 , it never increases it's not even displayed in skills tab

	//	note: probably here must be not caster but unitVictim
}

void Spell::SpellEffectSkillStep(uint32 i) // Skill Step
{
	Player*target;
	if(m_caster->GetTypeId() != TYPEID_PLAYER)
	{
		// Check targets
		if( m_targets.m_unitTarget )
		{
			target = objmgr.GetPlayer((uint32)m_targets.m_unitTarget);
			if( target == NULL ) 
				return;
		}
		else
			return;
	}
	else
	{
		target = static_cast< Player* >( m_caster );
	}
	
	uint32 skill = GetProto()->EffectMiscValue[i];
	if( skill == 242 )
		skill = SKILL_LOCKPICKING; // somehow for lockpicking misc is different than the skill :s

	skilllineentry* sk = dbcSkillLine.LookupEntry( skill );

	if( sk == NULL )
		return;

	uint32 max = 1;
	switch( sk->type )
	{
		case SKILL_TYPE_PROFESSION:
		case SKILL_TYPE_SECONDARY:
			max = damage * 75;
			break;
		case SKILL_TYPE_WEAPON:
			max = 5 * target->getLevel();
			break;
		case SKILL_TYPE_CLASS:
		case SKILL_TYPE_ARMOR:
			if( skill == SKILL_LOCKPICKING )
				max = damage * 75;
			else
				max = 1;
			break;
		default: //u cant learn other types in game
			return;
	};

	if( target->_HasSkillLine( skill ) )
	{
		target->_ModifySkillMaximum( skill, max );
	}		
	else
	{
		// Don't add skills to players logging in.
		/*if((GetProto()->Attributes & 64) && playerTarget->m_TeleportState == 1)
			return;*/

		if( sk->type == SKILL_TYPE_PROFESSION )
			target->ModUnsigned32Value( PLAYER_CHARACTER_POINTS2, -1 );

		if( skill == SKILL_RIDING )
			target->_AddSkillLine( skill, max, max );
		else
			target->_AddSkillLine( skill, 1, max );
	}

	//professions fix, for unknow reason when u learn profession it 
	//does not teach find herbs for herbalism etc. moreover there is no spell
	//in spell.dbc that would teach u this. It means blizz does it in some tricky way too
	/*switch( skill )
	{
	case SKILL_ALCHEMY:
		target->addSpell( 2330 );//Minor Healing Potion
		target->addSpell( 2329 );//Elixir of Lion's Strength
		target->addSpell( 7183 );//Elixir of Minor Defense
		break;
	case SKILL_ENCHANTING:
		target->addSpell( 7418 );//Enchant Bracer - Minor Health
		target->addSpell( 7428 );//Enchant Bracer - Minor Deflection
		target->addSpell( 7421 );//Runed Copper Rod
		target->addSpell( 13262 );//Disenchant
		break;
	case SKILL_HERBALISM:
		target->addSpell( 2383 );//find herbs
		break;
	case SKILL_MINING:
		target->addSpell( 2657 );//smelt copper
		target->addSpell( 2656 );//smelting
		target->addSpell( 2580 );//find minerals
		break;
	case SKILL_FIRST_AID:
		target->addSpell( 3275 );//Linen Bandage
		break;
	case SKILL_TAILORING:
		target->addSpell( 2963 );//Bolt of Linen Cloth

		target->addSpell( 2387 );//Linen Cloak
		target->addSpell( 2393 );//White Linen Shirt
		target->addSpell( 3915 );//Brown Linen Shirt
		target->addSpell( 12044 );//Simple Linen Pants
		break;
	case SKILL_LEATHERWORKING:
		target->addSpell( 2149 );//Handstitched Leather Boots
		target->addSpell( 2152 );//Light Armor Kit
		target->addSpell( 2881 );//Light Leather
		target->addSpell( 7126 );//Handstitched Leather Vest
		target->addSpell( 9058 );//Handstitched Leather Cloak
		target->addSpell( 9059 );//Handstitched Leather Bracers
		break;
	case SKILL_ENGINERING:
		target->addSpell( 3918 );//Rough Blasting Powder
		target->addSpell( 3919 );//Rough Dynamite
		target->addSpell( 3920 );//Crafted Light Shot
		break;
	case SKILL_COOKING:
		target->addSpell( 2538 );//Charred Wolf Meat
		target->addSpell( 2540 );//Roasted Boar Meat
		target->addSpell( 818 );//Basic Campfire
		target->addSpell( 8604 );//Herb Baked Egg
		break;
	case SKILL_BLACKSMITHING:
		target->addSpell( 2660 );//Rough Sharpening Stone
		target->addSpell( 2663 );//Copper Bracers
		target->addSpell( 12260 );//Rough Copper Vest
		target->addSpell( 2662 );//Copper Chain Pants
		target->addSpell( 3115 );//Rough Weightstone
		break;
	case SKILL_JEWELCRAFTING:
		target->addSpell( 25255 );// Delicate Copper Wire
		target->addSpell( 25493 );// Braided Copper Ring
		target->addSpell( 26925 );// Woven Copper Ring
		target->addSpell( 32259 );// Rough Stone Statue
		break;
	};*/
}

void Spell::SpellEffectSummonObject(uint32 i)
{
	if( !p_caster )
		return;

	uint32 entry = GetProto()->EffectMiscValue[i];

	uint32 mapid = u_caster->GetMapId();
	float px = u_caster->GetPositionX();
	float py = u_caster->GetPositionY();
	float pz = u_caster->GetPositionZ();
	float orient = m_caster->GetOrientation();
	float posx = 0,posy = 0,posz = 0;

	if( entry == GO_FISHING_BOBBER )
	{
		float co = cos( orient );
		float si = sin( orient );
		MapMgr * map = m_caster->GetMapMgr();
		Spell * spell = u_caster->GetCurrentSpell();

		float r;
		for( r = 20; r > 10; r-- )
		{
			posx = px+r*co;
			posy = py+r*si;
			if( !(map->GetWaterType( posx, posy ) & 1) )//water
				continue;
			posz = map->GetWaterHeight( posx, posy );
			if( posz > map->GetLandHeight( posx, posy ) )//water
				break;
		}

		posx = px + r * co;
		posy = py + r * si;

		// Todo / Fix me: This should be loaded / cached
		uint32 zone = p_caster->GetAreaID();
		if( zone == 0 ) // If the player's area ID is 0, use the zone ID instead
			zone = p_caster->GetZoneId();

		uint32 minskill;
		FishingZoneEntry *fishentry = FishingZoneStorage.LookupEntry( zone );
		if( !fishentry ) // Check database if there is fishing area / zone information, if not, return
			return;

		// Todo / Fix me: Add fishskill to the calculations
		minskill = fishentry->MinSkill;
		spell->SendChannelStart( 20000 ); // 30 seconds
		/*spell->SendSpellStart();
		spell->SendCastResult(SPELL_CANCAST_OK);
		spell->SendSpellGo ();*/

		GameObject *go = u_caster->GetMapMgr()->CreateGameObject(GO_FISHING_BOBBER);

		go->CreateFromProto( GO_FISHING_BOBBER, mapid, posx, posy, posz, orient );
		go->SetUInt32Value( GAMEOBJECT_FLAGS, 0 );
		go->SetUInt32Value( GAMEOBJECT_STATE, 0 );
		go->SetUInt64Value( OBJECT_FIELD_CREATED_BY, m_caster->GetGUID() );
		u_caster->SetUInt64Value( UNIT_FIELD_CHANNEL_OBJECT, go->GetGUID() );

		go->SetInstanceID( m_caster->GetInstanceID() );
		go->PushToWorld( m_caster->GetMapMgr() );

		if( lootmgr.IsFishable( zone ) ) // Only set a 'splash' if there is any loot in this area / zone
		{
			uint32 seconds = RandomUInt(17) + 2;
			sEventMgr.AddEvent( go, &GameObject::FishHooked, static_cast< Player* >( m_caster ), EVENT_GAMEOBJECT_FISH_HOOKED, seconds * 1000, 1, 0 );
		}
		sEventMgr.AddEvent( go, &GameObject::EndFishing, static_cast< Player* >( m_caster ),false, EVENT_GAMEOBJECT_END_FISHING, 20000, 1, 0 );
		p_caster->SetSummonedObject( go );
	}
	else
	{
		posx=px;
		posy=py;		
		GameObjectInfo * goI = GameObjectNameStorage.LookupEntry(entry);
		if(!goI)
		{
			if( p_caster != NULL )
			{
				sChatHandler.BlueSystemMessage(p_caster->GetSession(), "non-existant gameobject %u tried to be created by SpellEffectSummonObject. Report to devs!", entry);
			}
			return;
		}

		if( m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION && m_targets.m_destX && m_targets.m_destY && m_targets.m_destZ )
		{
			posx = m_targets.m_destX;
			posy = m_targets.m_destY;
			pz = m_targets.m_destZ;
		}

		GameObject *go = m_caster->GetMapMgr()->CreateGameObject(entry);

		go->SetInstanceID(m_caster->GetInstanceID());
		go->CreateFromProto(entry,mapid,posx,posy,pz,orient);
		go->SetUInt32Value(GAMEOBJECT_STATE, 1);
		go->SetUInt64Value(OBJECT_FIELD_CREATED_BY,m_caster->GetGUID());
		go->PushToWorld(m_caster->GetMapMgr());
		sEventMgr.AddEvent(go, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1,0);
		if ( entry == 17032 ) // this is a portal
		{
			// enable it for party only
			go->SetUInt32Value( GAMEOBJECT_STATE, 0 );
			//disable by default
			WorldPacket * pkt = go->BuildFieldUpdatePacket( GAMEOBJECT_STATE, 1 );
			SubGroup * pGroup = p_caster->GetGroup() ? p_caster->GetGroup()->GetSubGroup(p_caster->GetSubGroup()) : NULL;

			if ( pGroup != NULL )
			{
				p_caster->GetGroup()->Lock();
				for ( GroupMembersSet::iterator itr = pGroup->GetGroupMembersBegin(); itr != pGroup->GetGroupMembersEnd(); ++itr )
				{
					if( (*itr)->m_loggedInPlayer && m_caster != (*itr)->m_loggedInPlayer )
						(*itr)->m_loggedInPlayer->GetSession()->SendPacket( pkt );
				}
				p_caster->GetGroup()->Unlock();
			}
			delete pkt;
		}
		else if ( entry == 36727 || entry == 177193 ) // Portal of Summoning and portal of doom
		{
			//Player * pTarget = p_caster->GetMapMgr()->GetPlayer( p_caster->GetSelection() );
			Player * pTarget = objmgr.GetPlayer( (uint32)p_caster->GetSelection() );
			if ( pTarget == NULL || !pTarget->IsInWorld() )
				return;
			go->m_ritualmembers[0] = p_caster->GetLowGUID();
			go->m_ritualcaster = p_caster->GetLowGUID();
			go->m_ritualtarget = pTarget->GetLowGUID();
			go->m_ritualspell = GetProto()->Id;
		}
		else if ( entry == 186811 || entry == 181622 ) // ritual of refreshment, ritual of souls
		{
			go->m_ritualmembers[0] = p_caster->GetLowGUID();
			go->m_ritualcaster = p_caster->GetLowGUID();
			go->m_ritualtarget = 0;
			go->m_ritualspell = GetProto()->Id;
		}
		else if ( entry == 186812 || entry == 181621 ) // Refreshment Table, Soulwell
		{
			go->charges = goI->sound1;
		}
		else	//	Lightwell,if there is some other type -- add it
		{
			go->charges = 5;	//	Max 5 charges
		}
		p_caster->SetSummonedObject(go);
	}
}

void Spell::SpellEffectEnchantItem(uint32 i) // Enchant Item Permanent
{
	if(!itemTarget || !p_caster) return;
	EnchantEntry * Enchantment = dbcEnchant.LookupEntry(GetProto()->EffectMiscValue[i]);
	if(!Enchantment) return;

	if( p_caster->RS_getAccess() >= RS_PROBEGM && itemTarget->GetOwner() != p_caster )
		sGMLog.writefromsession(p_caster->GetSession(), "enchanted item for %s", itemTarget->GetOwner()->GetName());

	//remove other perm enchantment that was enchanted by profession
	itemTarget->RemoveProfessionEnchant();
	int32 Slot = itemTarget->AddEnchantment(Enchantment, 0, true, true, false, 0);
	if(Slot < 0)
		return; // Apply failed
			
	DetermineSkillUp(SKILL_ENCHANTING);
}

void Spell::SpellEffectEnchantItemTemporary(uint32 i)  // Enchant Item Temporary
{
	if(!itemTarget || !p_caster) return;
	uint32 Duration = damage > 1 ? damage : 1800;

	// dont allow temporary enchants unless we're the owner of the item
	if(itemTarget->GetOwner() != p_caster)
		return;

	EnchantEntry * Enchantment = dbcEnchant.LookupEntry(GetProto()->EffectMiscValue[i]);
	if(!Enchantment) return;

	itemTarget->RemoveEnchantment(1);
	int32 Slot = itemTarget->AddEnchantment(Enchantment, Duration, false, true, false, 1);
	if(Slot < 0)
		return; // Apply failed

	skilllinespell* skill = objmgr.GetSpellSkill(GetProto()->Id);
	if(skill)
		DetermineSkillUp(skill->skilline,itemTarget->GetProto()->ItemLevel);
}

void Spell::SpellEffectTameCreature(uint32 i)
{
	Creature* tame = ( ( unitTarget->GetTypeId() == TYPEID_UNIT ) ? static_cast< Creature* >( unitTarget ) : NULL );
	if( tame == NULL )
		return;

	if(!p_caster)
		return;

	// Remove target
	tame->GetAIInterface()->HandleEvent(EVENT_LEAVECOMBAT, p_caster, 0);
	Pet *pPet = objmgr.CreatePet();
	pPet->SetInstanceID(p_caster->GetInstanceID());
	pPet->CreateAsSummon(tame->GetEntry(), tame->GetCreatureInfo(), tame, p_caster, NULL, 2, 0);
	//tame->SafeDelete();
	//delete tame;
	tame->Despawn(0,tame->GetProto()? tame->GetProto()->RespawnTime:0);
}

void Spell::SpellEffectSummonPet(uint32 i) //summon - pet
{
	if(GetProto()->Id == 883)
	{
		// "Call Pet" spell
		if(!p_caster)
			return;

		if(p_caster->GetSummon() != 0)
		{
			p_caster->GetSession()->SendNotification("You already have a pet summoned.");
			return;
		}

		uint32 petno = p_caster->GetUnstabledPetNumber();

		if(petno)
		{
			p_caster->SpawnPet(petno);
		}
		else
		{
			WorldPacket data(SMSG_AREA_TRIGGER_MESSAGE, 50);
			data << uint32(0) << "You do not have any pets to call." << uint8(0);
			p_caster->GetSession()->SendPacket(&data);
		}
		return;
	}
	
	//uint32 entryId = GetProto()->EffectMiscValue[i];

	//VoidWalker:torment, sacrifice, suffering, consume shadows
	//Succubus:lash of pain, soothing kiss, seduce , lesser invisibility
	//felhunter:	 Devour Magic,Paranoia,Spell Lock,	Tainted Blood
 
	if(!p_caster || p_caster->getClass() != WARLOCK)
		return;
	
	// remove old pet
	Pet *old = static_cast< Player* >(m_caster)->GetSummon();
	if(old)
		old->Dismiss(false);		
	
	CreatureInfo *ci = CreatureNameStorage.LookupEntry(GetProto()->EffectMiscValue[i]);
	if(ci)
	{
		//if demonic sacrifice auras are still active, remove them
		//uint32 spids[] = { 18789, 18790, 18791, 18792, 35701, 0 };
		//p_caster->RemoveAuras(spids);
		p_caster->RemoveAura(18789);
		p_caster->RemoveAura(18790);
		p_caster->RemoveAura(18791);
		p_caster->RemoveAura(18792);
		p_caster->RemoveAura(35701);

		Pet *summon = objmgr.CreatePet();
		summon->SetInstanceID(m_caster->GetInstanceID());
		summon->CreateAsSummon(GetProto()->EffectMiscValue[i], ci, NULL, p_caster, GetProto(), 1, 0);
	}
}

void Spell::SpellEffectWeapondamage( uint32 i ) // Weapon damage +
{
	if( unitTarget == NULL || u_caster == NULL )
		return;

	//Hackfix for Mangle
	if( GetProto()->NameHash == SPELL_HASH_MANGLE__CAT_ && u_caster->IsPlayer() )
		static_cast< Player* >( u_caster )->AddComboPoints( unitTarget->GetGUID(), 1 );

	// Hacky fix for druid spells where it would "double attack".
	if( GetProto()->Effect[2] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE || GetProto()->Effect[1] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE )
	{
		add_damage += damage;
		return;
	}

	uint32 _type;
	if( GetType() == SPELL_DMG_TYPE_RANGED )
		_type = RANGED;
	else
	{
		if (GetProto()->AttributesExC & 0x1000000)
			_type =  OFFHAND;
		else
			_type = MELEE;
	}
	u_caster->Strike( unitTarget, _type, GetProto(), damage, 0, 0, false, true );
}

void Spell::SpellEffectPowerBurn(uint32 i) // power burn
{
	if(!unitTarget)
		return;
	if(!unitTarget->isAlive())
		return;
	if (unitTarget->GetPowerType() != POWER_TYPE_MANA)
		return;
	if( unitTarget->IsPlayer() )
	{
		Player* mPlayer = static_cast< Player* >( unitTarget );
		if( mPlayer->IsInFeralForm() )
			return;

		// Resilience - reduces the effect of mana drains by (CalcRating*2)%.
		damage *= float2int32( 1 - ( ( static_cast<Player*>(unitTarget)->CalcRating( PLAYER_RATING_MODIFIER_SPELL_CRIT_RESILIENCE ) * 2 ) / 100.0f ) );
	}
	int32 mana = (int32)min( (int32)unitTarget->GetUInt32Value( UNIT_FIELD_POWER1 ), damage );
	unitTarget->ModUnsigned32Value( UNIT_FIELD_POWER1, -mana );
	
	m_caster->SpellNonMeleeDamageLog(unitTarget,GetProto()->Id, (uint32)(mana * GetProto()->Effectunknown[i]), pSpellId==0,true);
}

void Spell::SpellEffectThreat(uint32 i) // Threat
{
	if(!unitTarget || !unitTarget->isAlive() )
		return;

	int32 amount = GetProto()->EffectBasePoints[i];
	if (GetProto()->SpellGroupType)
	{
		SM_FIValue(u_caster->SM_FMiscEffect, &amount, GetProto()->SpellGroupType);
		SM_PIValue(u_caster->SM_PMiscEffect, &amount, GetProto()->SpellGroupType);
	}	

	bool chck = unitTarget->GetAIInterface()->modThreatByPtr(u_caster, amount);
	if(chck == false)
		unitTarget->GetAIInterface()->AttackReaction(u_caster,1,0);	
}

void Spell::SpellEffectTriggerSpell(uint32 i) // Trigger Spell
{
	SpellEntry *entry = dbcSpell.LookupEntry(GetProto()->EffectTriggerSpell[i]);
	if (entry == NULL) return;

	SpellCastTargets targets = m_targets;
	Spell *sp = SpellPool.PooledNew();
	sp->Init(m_caster,entry,true,NULL);
	sp->prepare(&targets);
}

void Spell::SpellEffectHealthFunnel(uint32 i) // Health Funnel
{
	if(!unitTarget)
		return;		
	if(!unitTarget->isAlive() || !unitTarget->IsPet())
		return;

	//does not exist
}

void Spell::SpellEffectPowerFunnel(uint32 i) // Power Funnel
{
	if(!unitTarget)
		return;		
	if(!unitTarget->isAlive() || !unitTarget->IsPet())
		return;

	//does not exist
}

void Spell::SpellEffectHealMaxHealth(uint32 i) // Heal Max Health
{
	if( unitTarget == NULL || !unitTarget->isAlive() )
		return;

	uint32 dif = unitTarget->GetUInt32Value( UNIT_FIELD_MAXHEALTH ) - unitTarget->GetUInt32Value( UNIT_FIELD_HEALTH );
	if( !dif )
	{
		SendCastResult( SPELL_FAILED_ALREADY_AT_FULL_HEALTH );
		return;
	}

	if( unitTarget->GetTypeId() == TYPEID_PLAYER)
	{
		 SendHealSpellOnPlayer( static_cast< Player* >( m_caster ), static_cast< Player* >( unitTarget ), dif, false );
	}
	unitTarget->ModUnsigned32Value( UNIT_FIELD_HEALTH, dif );
}

void Spell::SpellEffectInterruptCast(uint32 i) // Interrupt Cast
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	if(!playerTarget)
	{
		if (u_caster && (u_caster != unitTarget))
		{
			unitTarget->GetAIInterface()->AttackReaction(u_caster, 1, m_spellInfo->Id);
			Creature *c = (Creature*)( unitTarget );
			if (c && c->GetProto() && c->GetProto()->modImmunities)
			{
				if (c->GetProto()->modImmunities & 2048)
					return;
			}
		}
	}
	// FIXME:This thing prevent target from spell casting too but cant find.
	uint32 school=0;
	if(unitTarget->GetCurrentSpell())
	{
		school=unitTarget->GetCurrentSpell()->GetProto()->School;
	}
	unitTarget->InterruptSpell();
	if(school)//prevent from casts in this school
	{
		int32 duration = GetDuration();
		if(unitTarget->IsPlayer()){		// Check for interruption reducing talents
			int32 DurationModifier = static_cast< Player* >( unitTarget )->MechanicDurationPctMod[MECHANIC_INTERRUPTED];
			if(DurationModifier >= - 100)
				duration = (duration*(100+DurationModifier))/100;
		}
		unitTarget->SchoolCastPrevent[school]=duration+getMSTime();
		// TODO: visual!
	}
}

void Spell::SpellEffectDistract(uint32 i) // Distract
{
	//spellId 1725 Distract:Throws a distraction attracting the all monsters for ten sec's
	if(!unitTarget)
		return;
	if(!unitTarget->isAlive())
		return;

	if(m_targets.m_destX != 0.0f || m_targets.m_destY != 0.0f || m_targets.m_destZ != 0.0f)
	{
//		unitTarget->GetAIInterface()->MoveTo(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, 0);
		uint32 Stare_duration=GetDuration();
		if(Stare_duration>30*60*1000)
			Stare_duration=10000;//if we try to stare for more then a half an hour then better not stare at all :P (bug)
		float newo=unitTarget->calcRadAngle(unitTarget->GetPositionX(),unitTarget->GetPositionY(),m_targets.m_destX,m_targets.m_destY);
		unitTarget->GetAIInterface()->StopMovement(Stare_duration);
		unitTarget->SetFacing(newo);
	}

	//Smoke Emitter 164870
	//Smoke Emitter Big 179066
	//Unit Field Target of 
}

void Spell::SpellEffectPickpocket(uint32 i) // pickpocket
{
	//Show random loot based on roll,	
	if(!unitTarget)
		return; // impossible..
	if(!p_caster)
		return;

	if(unitTarget->GetTypeId() != TYPEID_UNIT)
		return;

	Creature *target = static_cast<Creature*>( unitTarget );
	if(target->IsPickPocketed() || (target->GetCreatureInfo() && target->GetCreatureInfo()->Type != HUMANOID))
	{
		SendCastResult(SPELL_FAILED_TARGET_NO_POCKETS);
		return;
	}
			
	lootmgr.FillPickpocketingLoot(&((Creature*)unitTarget)->loot,unitTarget->GetEntry());

	uint32 _rank = ((Creature*)unitTarget)->GetCreatureInfo() ? ((Creature*)unitTarget)->GetCreatureInfo()->Rank : 0;
	unitTarget->loot.gold = float2int32((_rank+1) * unitTarget->getLevel() * (RandomUInt(5) + 1) * sWorld.getRate(RATE_MONEY));

	p_caster->SendLoot(unitTarget->GetGUID(), LOOT_PICKPOCKETING );
	target->SetPickPocketed(true);
}

void Spell::SpellEffectAddFarsight(uint32 i) // Add Farsight
{
	if(!p_caster)
		return;

	float x = m_targets.m_destX;
	float y = m_targets.m_destY;
	float z = m_targets.m_destZ;
	if(x == 0)
		x = m_targets.m_srcX;
	if(y == 0)
		y = m_targets.m_srcY;
	if(z == 0)
		z = m_targets.m_srcZ;

	DynamicObject * dynObj = p_caster->GetMapMgr()->CreateDynamicObject();
	dynObj->Create(u_caster, this, x, y, z, GetDuration(), GetRadius(i));

	ASSERT(dynObj);
/*
	if( dynObj == NULL ) //i <3 burlex :P
	{
		delete dynObj;
		return;
	}
*/
	dynObj->SetUInt32Value(OBJECT_FIELD_TYPE, 65);
	dynObj->SetUInt32Value(DYNAMICOBJECT_BYTES, 0x80000002);
	dynObj->SetInstanceID(p_caster->GetInstanceID());	
	p_caster->SetUInt64Value(PLAYER_FARSIGHT, dynObj->GetGUID());

	p_caster->GetMapMgr()->ChangeFarsightLocation(p_caster, dynObj);
}

void Spell::SpellEffectHealMechanical(uint32 i)
{
	if(!unitTarget)
		return;
	if(unitTarget->GetTypeId() != TYPEID_UNIT)
		return;
	if(((Creature*)unitTarget)->GetCreatureInfo()->Type != MECHANICAL)
		return;

	Heal((int32)damage);
}

void Spell::SpellEffectSummonObjectWild(uint32 i)
{
	if(!u_caster)
		return;

	// spawn a new one
	GameObject *GoSummon = u_caster->GetMapMgr()->CreateGameObject(GetProto()->EffectMiscValue[i]);
	if(!GoSummon->CreateFromProto(GetProto()->EffectMiscValue[i],
		m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation() ))
	{
		delete GoSummon;
		return;
	}
	
	GoSummon->SetInstanceID(m_caster->GetInstanceID());
	GoSummon->SetUInt32Value(GAMEOBJECT_LEVEL, u_caster->getLevel());
	GoSummon->SetUInt64Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUID());
	GoSummon->SetUInt32Value(GAMEOBJECT_STATE, 0);
	GoSummon->PushToWorld(u_caster->GetMapMgr());
	GoSummon->SetSummoned(u_caster);
	
	sEventMgr.AddEvent(GoSummon, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1,0);
}

void Spell::SpellEffectScriptEffect(uint32 i) // Script Effect
{
	uint32 spellId = GetProto()->Id;

	// Try a dummy SpellHandler
	if(sScriptMgr.CallScriptedDummySpell(spellId, i, this))
		return;

	switch(spellId)
	{

	// Arcane Missiles
	/*
	case 5143://Rank 1
	case 5144://Rank 2
	case 5145://Rank 3
	case 8416://Rank 4
	case 8417://Rank 5
	case 10211://Rank 6
	case 10212://Rank 7
	case 25345://Rank 8
	{
		if(m_tmpAffect == 0)
		{
			Affect* aff = new Affect(GetProto(),GetDuration(sSpellDuration.LookupEntry(GetProto()->DurationIndex)),m_GetGUID(),m_caster);
			m_tmpAffect = aff;
		}
		if(GetProto()->EffectBasePoints[0] < 0)
			m_tmpAffect->SetNegative();

		m_tmpAffect->SetPeriodicTriggerSpell(GetProto()->EffectTriggerSpell[0],GetProto()->EffectAmplitude[0],damage);
	}break;
	*/

	// Warlock Healthstones, just how much health does a lock need?
	case 6201:		// Minor Healthstone
		if (p_caster->HasSpell(18692))
		{
			CreateItem(19004);
			break;
		}
		if (p_caster->HasSpell(18693))
		{
			CreateItem(19005);
			break;
		}
		CreateItem(5512);
		break;
	case 6202:		// Lesser Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(19007);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(19006);
			break;
		}
		CreateItem(5511);
		break;
	case 5699:		// Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(19009);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(19008);
			break;
		}
		CreateItem(5509);
		break;
	case 11729:		// Greater Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(19011);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(19010);
			break;
		}
		CreateItem(5510);
		break;
	case 11730:		// Major Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(19013);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(19012);
			break;
		}
		CreateItem(9421);
		break;
	case 27230:		// Master Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(22105);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(22104);
			break;
		}
		CreateItem(22103);
		break;

	// Holy Light
	case 635:
	case 639:
	case 647:
	case 1026:
	case 1042:
	case 3472:
	case 10328:
	case 10329:
	case 10348:
	case 25292:
	case 27135:
	case 27136:
	//Flash of light
	case 19750:
	case 19939:
	case 19940:
	case 19941:
	case 19942:
	case 19943:
	case 27137:
		if( u_caster->HasAura( 20216 ) )
			Heal((int32)damage, true);
		else
			Heal((int32)damage);
	break;

	// Judgement
	case 20271:
		{
			if(!unitTarget || !p_caster) return;

			SpellEntry * en = dbcSpell.LookupEntry(p_caster->judgespell);
			Spell * sp = SpellPool.PooledNew();
			sp->Init(p_caster,en,true,NULL);
			SpellCastTargets tgt;
			tgt.m_unitTarget=unitTarget->GetGUID();
			tgt.m_targetMask=TARGET_FLAG_UNIT;
			sp->judgement = true;
			sp->prepare(&tgt);
			p_caster->RemoveAura(p_caster->Seal);
		}break;
	//warlock - Master Demonologist
	case 23784:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0;
			uint32 inc_resist_by_level = 0;
			uint32 inc_resist_by_level_spell = 0;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23759;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23760;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23761;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 0;
				inc_resist_by_level_spell = 23762;
				inc_resist_by_level = 20;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35702;
				inc_resist_by_level_spell = 23762;
				inc_resist_by_level = 10;
			}
			if( casted_spell_id )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init(  unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;
	case 23830:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0;
			uint32 inc_resist_by_level = 0;
			uint32 inc_resist_by_level_spell = 0;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23826;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23841;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23833;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 1;
				inc_resist_by_level_spell = 23837;
				inc_resist_by_level = 40;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35703;
				inc_resist_by_level_spell = 23837;
				inc_resist_by_level = 20;
			}
			if( casted_spell_id )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init( unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;
	case 23831:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0;
			uint32 inc_resist_by_level = 0;
			uint32 inc_resist_by_level_spell = 0;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23827;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23842;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23834;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 0;
				inc_resist_by_level_spell = 23838;
				inc_resist_by_level = 60;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35704;
				inc_resist_by_level_spell = 23838;
				inc_resist_by_level = 30;
			}
			if( casted_spell_id )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init(  unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;
	case 23832:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0;
			uint32 inc_resist_by_level = 0;
			uint32 inc_resist_by_level_spell = 0;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23828;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23843;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23835;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 0;
				inc_resist_by_level_spell = 23839;
				inc_resist_by_level = 80;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35705;
				inc_resist_by_level_spell = 23839;
				inc_resist_by_level = 40;
			}
			if( casted_spell_id )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init( unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;
	case 34026: //Hunter: Kill Command
		{
			// in this case unitTarget == pet
			if( p_caster == NULL || unitTarget == NULL || unitTarget->getDeathState() != ALIVE )
				return;

			AI_Spell* Sp = static_cast< Pet* >( unitTarget )->CreateAISpell( dbcSpell.LookupEntry( 34027 ) );

			Unit* tgt = p_caster->GetMapMgr()->GetUnit( p_caster->GetSelection() );

			if( tgt != NULL && isAttackable( p_caster, tgt ) )
			{
				unitTarget->GetAIInterface()->AttackReaction( tgt, 1 );
				unitTarget->GetAIInterface()->SetNextTarget( tgt );
			}
			else if( unitTarget->CombatStatus.GetPrimaryAttackTarget() == 0 )
				return;				
			unitTarget->GetAIInterface()->SetNextSpell( Sp );
			//TODO: Kill Command - return to previous pet target after cast
		}break; 
	case 35708:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0;
			uint32 inc_resist_by_level = 0;
			uint32 inc_resist_by_level_spell = 0;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23829;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23844;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23836;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 0;
				inc_resist_by_level_spell = 23840;
				inc_resist_by_level = 100;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35706;
				inc_resist_by_level_spell = 23840;
				inc_resist_by_level = 50;
			}
			if( casted_spell_id )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init( unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULL );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPool.PooledNew();
				sp->Init( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULL );
//				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;

	case 24751:		//Trick or Treat
		{
			uint32 chance = RandomUInt(1);
			switch(chance)
			{
			case 0:		//Tricked bat, cat, frog, human ghost, kitten, skeleton, ninja or snake
				{
					uint32 chance1 = RandomUInt(7);
					uint32 displayid;
					switch(chance1)
					{
					case 0:
						displayid = 10992; //diablo
						break;
					case 1:
						displayid = 7550; //skeleton
						break;
					case 2:
						displayid = (playerTarget->getGender() == 1) ? 10481:10478; //ghost
						break;
					case 3:
						displayid = 5556; //cat
						break;
					case 4:
						displayid = 6296; //frog
						break;
					case 5:
						displayid = (playerTarget->getGender() == 1) ? 4618:4617; //ninja
						break;
					case 6:
						displayid = 1206; //snake
						break;
					case 7:
						displayid = 8808; //bat
						break;
					}
					u_caster->CastSpell(playerTarget,24753,true);
					playerTarget->SetUInt32Value(UNIT_FIELD_DISPLAYID, displayid);
					sEventMgr.AddEvent(playerTarget, &Player::DemorphEvent, EVENT_UNK, 45000, 1,0);
				}break;
			case 1:		//Treated
				{
					u_caster->CastSpell(playerTarget, 24715, true);
					break;
				}break;
			}
		}break;

		case 5784:
		case 23161: // Warlock: ( Felsteed / Dreadsteed ) summon visual
			{
				if(p_caster == NULL)return;

				Spell *sp = SpellPool.PooledNew();
				sp->Init( p_caster, dbcSpell.LookupEntry( 31725 ), true, NULL );
				sp->bRadSet[0] = true;
				sp->Rad[0] = (10.0f * p_caster->GetFloatValue(OBJECT_FIELD_SCALE_X));
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
			}break;
	}
}

void Spell::SpellEffectSanctuary(uint32 i) // Stop all attacks made to you
{
	if(!u_caster)
		return;

	//warning this causes crashes !
//	Object::InRangeSet::iterator itr = u_caster->GetInRangeOppFactsSetBegin();
//	Object::InRangeSet::iterator itr_end = u_caster->GetInRangeOppFactsSetEnd();
	//use these instead
	Object::InRangeSet::iterator itr = u_caster->GetInRangeSetBegin();
	Object::InRangeSet::iterator itr_end = u_caster->GetInRangeSetEnd();
	Unit * pUnit;

	if(u_caster->IsPlayer())
		static_cast<Player*>(u_caster)->RemoveAllAuraType(SPELL_AURA_MOD_ROOT);

	for( ; itr != itr_end; ++itr )
		if( (*itr)->IsUnit() )
		{
			pUnit = static_cast<Unit*>(*itr);

			if( pUnit && pUnit->GetTypeId() == TYPEID_UNIT )
				pUnit->GetAIInterface()->RemoveThreatByPtr( unitTarget );
		}
}

void Spell::SpellEffectAddComboPoints(uint32 i) // Add Combo Points
{
	if(!p_caster)
		return;

	//if this is a procspell Ruthlessness (maybe others later)
	if(pSpellId && GetProto()->Id==14157)
	{
		//it seems this combo adding procspell is going to change combopoint count before they will get reseted. We add it after the reset
		/* burlex - this is wrong, and exploitable.. :/ if someone uses this they will have unlimited combo points */
		//re-enabled this by Zack. Explained why it is used + recheked to make sure initialization is good ...
		// while casting a spell talent will trigger uppon the spell prepare faze
		// the effect of the talent is to add 1 combo point but when triggering spell finishes it will clear the extra combo point
		p_caster->m_spellcomboPoints += damage;
		return;
	}
	p_caster->AddComboPoints(p_caster->GetSelection(), damage);
}

void Spell::SpellEffectCreateHouse(uint32 i) // Create House
{


}

void Spell::SpellEffectDuel(uint32 i) // Duel
{
	if(!p_caster)
		return;
	if(!p_caster->isAlive())
		return;

	if (p_caster->IsStealth())
	{
		SendCastResult(SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED);
		return; // Player is stealth
	}
	if(!playerTarget)
		return;
	if(playerTarget == p_caster)
		return;

	/* not implemented yet
	TODO: dueling zones ? ( SPELL_FAILED_NO_DUELING )
	if (player->IsInvisible())
	{
		SendCastResult(SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE);
		return;
	}
	*/
	if(p_caster->m_bg)
	{
		SendCastResult(SPELL_FAILED_NO_DUELING);
		return;
	}
	//Player *pTarget = sObjHolder.GetObject<Player>(player->GetSelection());		//	hacky.. and will screw up if plr is deselected..
	if (!playerTarget)
	{
		SendCastResult(SPELL_FAILED_BAD_TARGETS);
		return; // invalid Target
	}
	if (!playerTarget->isAlive())
	{
		SendCastResult(SPELL_FAILED_TARGETS_DEAD);
		return; // Target not alive
	}
	if (playerTarget->hasStateFlag(UF_ATTACKING))
	{
		SendCastResult(SPELL_FAILED_TARGET_IN_COMBAT);
		return; // Target in combat with another unit
	}
	if (playerTarget->DuelingWith != NULL)
	{
		SendCastResult(SPELL_FAILED_TARGET_DUELING);
		return; // Already Dueling
	}

	p_caster->RequestDuel(playerTarget);
}

void Spell::SpellEffectStuck(uint32 i)
{
	if(!playerTarget || playerTarget != p_caster)
		return;

	sEventMgr.AddEvent(playerTarget,&Player::EventTeleport,playerTarget->GetBindMapId(),playerTarget->GetBindPositionX(),playerTarget->GetBindPositionY(),
		playerTarget->GetBindPositionZ(),EVENT_PLAYER_TELEPORT,50,1,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
	/*
	playerTarget->SafeTeleport(playerTarget->GetBindMapId(), 0, playerTarget->GetBindPositionX(), playerTarget->GetBindPositionY(), playerTarget->GetBindPositionZ(), 3.14f);*/
}

void Spell::SpellEffectSummonPlayer(uint32 i)
{
	if( playerTarget == NULL )
		return;

	// vojta: from 2.4 players can be summoned on another map
	//if( m_caster->GetMapMgr()->GetMapInfo() && m_caster->GetMapMgr()->GetMapInfo()->type != INSTANCE_NULL && m_caster->GetMapId() != playerTarget->GetMapId())
	//	return;

	if(!m_caster->GetMapMgr()->GetMapInfo())
		// MapInfo doesn't exist.
		return;

	if(!playerTarget->triggerpass_cheat)
	// Only run requirement checks if player doesn't have the trigger cheat enabled.
	{
		if(playerTarget->getLevel() < m_caster->GetMapMgr()->GetMapInfo()->minlevel && m_caster->GetMapMgr()->GetMapInfo()->mapid != 530)
			// Summoned Player doesn't meet the level requirements for the map, and the map isn't Outland.
			return;

		if(m_caster->GetMapMgr()->GetMapInfo()->required_quest && !playerTarget->HasFinishedQuest(m_caster->GetMapMgr()->GetMapInfo()->required_quest))
			// The Map has a quest requirement and the target player has not completed it yet.
			return;

		if(m_caster->GetMapMgr()->GetMapInfo()->required_item && !playerTarget->GetItemInterface()->GetItemCount(m_caster->GetMapMgr()->GetMapInfo()->required_item, false))
			// The Map has an item requirement and the target player doesn't have that item in their inventory.
			return;

		if(m_caster->GetMapMgr()->GetMapInfo()->heroic_key_1 || m_caster->GetMapMgr()->GetMapInfo()->heroic_key_2)
		{
			// The Map has one or more heroic keys.
			if( ( m_caster->GetMapMgr()->GetMapInfo()->heroic_key_1 && playerTarget->GetItemInterface()->GetItemCount(m_caster->GetMapMgr()->GetMapInfo()->heroic_key_1, false) == 0 )
				|| ( m_caster->GetMapMgr()->GetMapInfo()->heroic_key_2 && playerTarget->GetItemInterface()->GetItemCount(m_caster->GetMapMgr()->GetMapInfo()->heroic_key_2, false) == 0)
				)
			{
				return;
			}
		}			
	}
	
	playerTarget->SummonRequest(m_caster->GetLowGUID(), m_caster->GetZoneId(), m_caster->GetMapId(),
		m_caster->GetInstanceID(), m_caster->GetPosition());
}

void Spell::SpellEffectActivateObject(uint32 i) // Activate Object
{
	/*if(!p_caster)
		return;

	if(!gameObjTarget)
		return;

	gameObjTarget->SetUInt32Value(GAMEOBJECT_DYN_FLAGS, 1);

	sEventMgr.AddEvent(gameObjTarget, &GameObject::Deactivate, EVENT_GAMEOBJECT_DEACTIVATE, GetDuration(), 1);*/
}

void Spell::SpellEffectSelfResurrect(uint32 i)
{
	if(!p_caster || !unitTarget)
		return;
	if(playerTarget->isAlive())
		return;
	uint32 mana;
	uint32 health;
	uint32 class_ = unitTarget->getClass();

	switch(GetProto()->Id)
	{
	case 3026:
	case 20758:
	case 20759:
	case 20760:
	case 20761:
	case 27240:
		{
			health = GetProto()->EffectMiscValue[i];
			mana = -damage;
		}break;
	case 21169: //Reincarnation. Ressurect with 20% health and mana
		{
			int32 amt = 20;
			if( GetProto()->SpellGroupType)
			{
				SM_FIValue(unitTarget->SM_FMiscEffect,&amt,GetProto()->SpellGroupType);
				SM_PIValue(unitTarget->SM_PMiscEffect,&amt,GetProto()->SpellGroupType);
			}
			health = uint32((unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*amt)/100);
			mana = uint32((unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)*amt)/100);
		}
		break;
	default:
		{
			if(damage < 0) return;
			health = uint32(unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*damage/100);
			mana = uint32(unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)*damage/100);
		}break;
	}

	if(class_==WARRIOR||class_==ROGUE)
		mana=0;
	
	playerTarget->m_resurrectHealth = health;
	playerTarget->m_resurrectMana = mana;

	playerTarget->ResurrectPlayer();
	playerTarget->SetMovement(MOVE_UNROOT, 1);

	playerTarget->SetUInt32Value(PLAYER_SELF_RES_SPELL, 0);

	if(GetProto()->Id==21169)
		AddCooldown();
}

void Spell::SpellEffectSkinning(uint32 i)
{
	if( unitTarget == NULL || unitTarget->IsPlayer())
		return;

	Creature * uTarget = unitTarget->IsCreature()?static_cast<Creature*>(unitTarget):NULL;
	if( !uTarget || !(lootmgr.IsSkinnable(uTarget->GetEntry())) )
	{
		SendCastResult(SPELL_FAILED_TARGET_UNSKINNABLE);
		return;
	}
	uint32 sk = static_cast< Player* >( m_caster )->_GetSkillLineCurrent( SKILL_SKINNING );
	uint32 lvl = unitTarget->getLevel();
	if( ( sk >= lvl * 5 ) || ( ( sk + 100 ) >= lvl * 10 ) )
	{
		//Fill loot for Skinning
		lootmgr.FillSkinningLoot(&(uTarget)->loot,uTarget->GetEntry());
		static_cast< Player* >( m_caster )->SendLoot( uTarget->GetGUID(), LOOT_SKINNING );
		
		//Not skinable again
		uTarget->BuildFieldUpdatePacket( p_caster, UNIT_FIELD_FLAGS, 0 );

		//still lootable
		//pkt=unitTarget->BuildFieldUpdatePacket(UNIT_DYNAMIC_FLAGS,U_DYN_FLAG_LOOTABLE);
		//static_cast< Player* >( m_caster )->GetSession()->SendPacket(pkt);
		//delete pkt;
		if( !(uTarget->Skinned) )
			DetermineSkillUp(SKILL_SKINNING,sk<lvl*5?sk/5:lvl);

		uTarget->Skinned = true;
	}
	else
	{
		SendCastResult(SPELL_FAILED_MIN_SKILL);
	}
}

void Spell::SpellEffectCharge(uint32 i)
{
	if(!unitTarget)
		return;
	//if(!p_caster) who said units can't charge? :P
	//	return;
	if(!unitTarget->isAlive())
		return;
	if (u_caster->IsStunned() || u_caster->m_rooted || u_caster->IsPacified() || u_caster->IsFeared())
		return;

	float x, y, z;
	float dx,dy;

	//if(unitTarget->GetTypeId() == TYPEID_UNIT)
	//	if(unitTarget->GetAIInterface())
	//		unitTarget->GetAIInterface()->StopMovement(5000);
	if(unitTarget->GetPositionX() == 0.0f || unitTarget->GetPositionY() == 0.0f)
		return;
	
	dx=unitTarget->GetPositionX()-m_caster->GetPositionX();
	dy=unitTarget->GetPositionY()-m_caster->GetPositionY();
	if(dx == 0.0f || dy == 0.0f)
		return;

	float d = sqrt(dx*dx+dy*dy)-unitTarget->GetFloatValue(UNIT_FIELD_BOUNDINGRADIUS)-m_caster->GetFloatValue(UNIT_FIELD_BOUNDINGRADIUS);
	float alpha = atanf(dy/dx);
	if(dx<0)
		alpha += float(M_PI);

	x = d*cosf(alpha)+m_caster->GetPositionX();
	y = d*sinf(alpha)+m_caster->GetPositionY();
	z = unitTarget->GetPositionZ();

	uint32 time = uint32( (m_caster->CalcDistance(unitTarget) / ((m_caster->m_runSpeed * 3.5) * 0.001f)) + 0.5);

	WorldPacket data(SMSG_MONSTER_MOVE, 50);
	data << m_caster->GetNewGUID();
	data << m_caster->GetPositionX();
	data << m_caster->GetPositionY();
	data << m_caster->GetPositionZ();
	data << getMSTime();
	data << uint8(0x00);
	data << uint32(0x00000100);
	data << time;
	data << uint32(1);
	data << x << y << z;
	if(unitTarget->GetTypeId() == TYPEID_UNIT)
		unitTarget->GetAIInterface()->StopMovement(2000);

	u_caster->SendMessageToSet(&data, true);
	
	u_caster->SetPosition(x,y,z,alpha,true);
	u_caster->addStateFlag(UF_ATTACKING);
	u_caster ->smsg_AttackStart( unitTarget );
	if( p_caster )
		p_caster->EventAttackStart();

	u_caster->setAttackTimer(time, false);
	u_caster->setAttackTimer(time, true);

	// trigger an event to reset speedhack detection
	if( p_caster )
	{
		p_caster->EventAttackStart();
		p_caster->SpeedCheatDelay( time + 1000 );
		p_caster->z_axisposition = 0.0f;
	}
}

void Spell::SpellEffectPlayerPull( uint32 i )
{
	if( unitTarget == NULL || !unitTarget->isAlive())
		return;

	// calculate destination, use target to target for Z, we don't increase distance for Z difference :)
	float pullD = unitTarget->CalcDistance( m_caster->GetPositionX(), m_caster->GetPositionY(), unitTarget->GetPositionZ() ) - unitTarget->GetFloatValue( UNIT_FIELD_BOUNDINGRADIUS ) - m_caster->GetFloatValue( UNIT_FIELD_BOUNDINGRADIUS ) - 1.0f;
	float pullO = unitTarget->calcRadAngle( unitTarget->GetPositionX(), unitTarget->GetPositionY(), m_caster->GetPositionX(), m_caster->GetPositionY() );
	float pullX = unitTarget->GetPositionX() + pullD * cosf( pullO );
	float pullY = unitTarget->GetPositionY() + pullD * sinf( pullO );
	float pullZ = m_caster->GetPositionZ() + 0.3f;
	uint32 time = uint32( pullD * 42.0f );

	unitTarget->SetOrientation( pullO );

	if (pullD == 0)
		return;

	if (playerTarget != NULL)
	{
		WorldPacket data(SMSG_MOVE_KNOCK_BACK, 50);
		data << playerTarget->GetNewGUID();
		data << getMSTime();
		data << cosf(pullO) << sinf(pullO);
		data << float(pullD);
		data << float(-(float)m_spellInfo->EffectMiscValue[i]/10);
		playerTarget->GetSession()->SendPacket(&data);
//		playerTarget->DelaySpeedHack(5000);
	}
	else
	{
		unitTarget->SetPosition(pullX, pullY, pullZ, pullO);
		WorldPacket data( SMSG_MONSTER_MOVE, 60 );
		data << unitTarget->GetNewGUID();
		data << unitTarget->GetPositionX() << unitTarget->GetPositionY() << unitTarget->GetPositionZ();
		data << getMSTime();
		data << uint8( 4 );
		data << pullO;
		data << uint32( 0x00000100 );
		data << time;
		data << uint32( 1 );
		data << pullX << pullY << pullZ;
		unitTarget->SendMessageToSet( &data, true ); 
	}

	//remove mount auras if possible
	if (playerTarget)
	{
		if (playerTarget->m_MountSpellId != 0)
			playerTarget->RemoveAura(playerTarget->m_MountSpellId);
		if (playerTarget->flying_aura != 0 && playerTarget->GetShapeShift() == 0)
			playerTarget->RemoveAura(playerTarget->flying_aura);
	}
}

void Spell::SpellEffectKnockBack(uint32 i)
{
	if(unitTarget == NULL || !unitTarget->isAlive())
		return;

	float dx, dy;
	float value1 = float(GetProto()->EffectBasePoints[i]+1);
	float value2 = float(GetProto()->EffectMiscValue[i]);
	float proportion;
	value2 ? proportion = value1/value2 : proportion = 0;

	if(proportion)
	{
		value1 = value1 / (10 * proportion);
		value2 = value2 / 10 * proportion;
	}
	else
	{
		value2 = value1 / 10;
		value1 = 0.1f;
	}

	dx = sinf(m_caster->GetOrientation());
	dy = cosf(m_caster->GetOrientation());

		//set the position
	if (unitTarget->IsCreature())
	{
		float x=unitTarget->GetPositionX()+(value1*dy);
		float y=unitTarget->GetPositionY()+(value1*dx);
		float z=unitTarget->GetPositionZ();
		unitTarget->SetPosition(x, y, z, 0);
		WorldPacket data(SMSG_MONSTER_MOVE, 50);
		data << unitTarget->GetNewGUID();
		data << unitTarget->GetPositionX();
		data << unitTarget->GetPositionY();
		data << unitTarget->GetPositionZ();
		data << getMSTime();
		data << uint8( 4 );
		data << unitTarget->calcRadAngle(unitTarget->GetPositionX(), unitTarget->GetPositionY(), m_caster->GetPositionX(), m_caster->GetPositionY());
		data << uint32(0x00000400);
		data << 500;
		data << uint32(1);
		data << x << y << z;
		unitTarget->SendMessageToSet(&data, true);
		unitTarget->GetAIInterface()->StopMovement(2000);
	}

	//unitTarget->SendMessageToSet(&data, true);

	if (playerTarget != NULL)
	{
		WorldPacket data(SMSG_MOVE_KNOCK_BACK, 50);
		data << unitTarget->GetNewGUID();
		data << getMSTime();
		data << dy << dx;
		data << value1;
		data << -value2;
		playerTarget->blinked = true;
		playerTarget->GetSession()->SendPacket(&data);
	}
}

void Spell::SpellEffectDisenchant( uint32 i )
{
	if( p_caster == NULL )
		return;

	Item* it = p_caster->GetItemInterface()->GetItemByGUID( m_targets.m_itemTarget );
	if( it == NULL )
	{
		SendCastResult( SPELL_FAILED_CANT_BE_DISENCHANTED );
		return;
	}

	//Fill disenchanting loot
	p_caster->SetLootGUID( it->GetGUID() );
	if( !it->loot )
	{
		it->loot = new Loot;
		lootmgr.FillDisenchantingLoot( it->loot, it->GetEntry() );
	}

	Log.Debug( "SpellEffect", "Succesfully disenchanted item %d", uint32( itemTarget->GetEntry() ) );
	p_caster->SendLoot( itemTarget->GetGUID(), LOOT_DISENCHANTING );

	//We can increase Enchanting skill up to 60 
	uint32 skill = p_caster->_GetSkillLineCurrent( SKILL_ENCHANTING );
	if( skill && skill < 60 )
	{
		if( Rand( 100.0f - float( skill ) * 0.75f ) )
		{
			uint32 SkillUp = float2int32( 1.0f * sWorld.getRate( RATE_SKILLRATE ) );
			if( skill + SkillUp > 60 )
				SkillUp = 60 - skill;

			p_caster->_AdvanceSkillLine( SKILL_ENCHANTING, SkillUp );
		}
	}
	if( it == i_caster )
		i_caster = NULL;
}

void Spell::SpellEffectInebriate(uint32 i) // lets get drunk!
{
	if(!p_caster)
		return;

	// Drunkee!
	uint8 b2 = m_caster->GetByte(PLAYER_BYTES_3,1);
	b2 += damage;	// 10 beers will get you smassssshed!

	m_caster->SetByte(PLAYER_BYTES_3,1,b2>90?90:b2);
	sEventMgr.RemoveEvents(p_caster, EVENT_PLAYER_REDUCEDRUNK);
	sEventMgr.AddEvent(p_caster, &Player::EventReduceDrunk, false, EVENT_PLAYER_REDUCEDRUNK, 300000, 0,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
}

void Spell::SpellEffectFeedPet(uint32 i) // Feed Pet
{
	// food flags and food level are checked in Spell::CanCast()
	if(!itemTarget || !p_caster)
		return;
	
	Pet *pPet = p_caster->GetSummon();
	if(!pPet)
		return;

	/**	Cast feed pet effect
	- effect is item level and pet level dependent, aura ticks are 35, 17, 8 (*1000) happiness
	- http://petopia.brashendeavors.net/html/articles/basics_feeding.shtml */
	int8 deltaLvl = pPet->getLevel() - itemTarget->GetProto()->ItemLevel;
	damage /= 1000; //damage of Feed pet spell is 35000
	if(deltaLvl > 10) damage = damage >> 1;//divide by 2
	if(deltaLvl > 20) damage = damage >> 1;
	damage *= 1000;

	SpellEntry *spellInfo = dbcSpell.LookupEntry(GetProto()->EffectTriggerSpell[i]);
	Spell *sp= SpellPool.PooledNew();
	sp->Init((Object *)p_caster,spellInfo,true,NULL);
	sp->forced_basepoints[0] = damage;
	SpellCastTargets tgt;
	tgt.m_unitTarget=pPet->GetGUID();
	sp->prepare(&tgt);

	if(itemTarget->GetUInt32Value(ITEM_FIELD_STACK_COUNT)>1)
	{
		itemTarget->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT, -1);
		itemTarget->m_isDirty=true;
	}
	else
	{
		p_caster->GetItemInterface()->SafeFullRemoveItemByGuid(itemTarget->GetGUID());
		itemTarget=NULL;
	}
}

void Spell::SpellEffectRedirectThreat(uint32 i)
{
	if (!p_caster || !unitTarget)
		return;

	if ((unitTarget->GetTypeId() == TYPEID_PLAYER && p_caster->GetGroup() != static_cast<Player *>(unitTarget)->GetGroup()) || (unitTarget->GetTypeId() == TYPEID_UNIT && !unitTarget->IsPet()))
		return;

	p_caster->SetMisdirectionTarget(unitTarget->GetGUID());
}

void Spell::SpellEffectReduceThreatPercent(uint32 i)
{
	if (!unitTarget || !unitTarget->IsCreature() || !u_caster || unitTarget->GetAIInterface()->getThreatByPtr(u_caster) == 0)
		return;

		unitTarget->GetAIInterface()->modThreatByPtr(u_caster, (int32)unitTarget->GetAIInterface()->getThreatByPtr(u_caster) * damage / 100);
}

void Spell::SpellEffectReputation(uint32 i)
{
	if(!playerTarget)
		return;

	//playerTarget->modReputation(GetProto()->EffectMiscValue[i], damage, true);
	playerTarget->ModStanding(GetProto()->EffectMiscValue[i], damage);
}

void Spell::SpellEffectSummonObjectSlot(uint32 i)
{
	if(!u_caster || !u_caster->IsInWorld())
		return;

	GameObject *GoSummon = NULL;

	uint32 slot=GetProto()->Effect[i] - SPELL_EFFECT_SUMMON_OBJECT_SLOT1;
	GoSummon = u_caster->m_ObjectSlots[slot] ? u_caster->GetMapMgr()->GetGameObject(u_caster->m_ObjectSlots[slot]) : 0;
	u_caster->m_ObjectSlots[slot] = 0;

	if( GoSummon )
	{
		if(GoSummon->GetInstanceID() != u_caster->GetInstanceID())
			GoSummon->ExpireAndDelete();
		else
		{
			if( GoSummon->IsInWorld() )
				GoSummon->RemoveFromWorld(true);
			delete GoSummon;
		}
	}


	// spawn a new one
	GoSummon = u_caster->GetMapMgr()->CreateGameObject(GetProto()->EffectMiscValue[i]);
	if(! GoSummon->CreateFromProto(GetProto()->EffectMiscValue[i], m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation() ))
	{
		delete GoSummon;
		return;
	}
	
	GoSummon->SetUInt32Value(GAMEOBJECT_LEVEL, u_caster->getLevel());
	GoSummon->SetUInt64Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUID()); 
	GoSummon->SetInstanceID(m_caster->GetInstanceID());

	if(GoSummon->GetUInt32Value(GAMEOBJECT_TYPE_ID) == GAMEOBJECT_TYPE_TRAP)
	{
		GoSummon->invisible = true;
		GoSummon->invisibilityFlag = INVIS_FLAG_TRAP;
		GoSummon->charges = 1;
		GoSummon->checkrate = 1;
		sEventMgr.AddEvent(GoSummon, &GameObject::TrapSearchTarget, EVENT_GAMEOBJECT_TRAP_SEARCH_TARGET, 100, 0,0);
	}
	else
	{
		sEventMgr.AddEvent(GoSummon, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1,0);
	}
	GoSummon->PushToWorld(m_caster->GetMapMgr());
	GoSummon->SetSummoned(u_caster);
	u_caster->m_ObjectSlots[slot] = GoSummon->GetUIdFromGUID();
}

void Spell::SpellEffectDispelMechanic(uint32 i)
{
	if( !unitTarget || !unitTarget->isAlive() )
		return;
	/* this was already working before...
	uint32 sMisc = GetProto()->EffectMiscValue[i];

	for( uint32 x = 0; x<MAX_AURAS; x++ )
	{
		if( unitTarget->m_auras[x] && !unitTarget->m_auras[x]->IsPositive())
		{
			if( unitTarget->m_auras[x]->GetSpellProto()->MechanicsType == sMisc )
				unitTarget->m_auras[x]->Remove();
		}
	}
	*/
	unitTarget->RemoveAllAurasByMechanic( GetProto()->EffectMiscValue[i] , GetProto()->EffectBasePoints[i] , false );

	/*Shady: if it's about Daze spell - dismount should be done by RemoveAllAurasByMechanic.
	We don't need useless code or hackfixes here, so commented.*/
	//if( playerTarget && GetProto()->NameHash == SPELL_HASH_DAZED && playerTarget->IsMounted() )
	//	playerTarget->RemoveAura(playerTarget->m_MountSpellId);
}

void Spell::SpellEffectSummonDeadPet(uint32 i)
{//this is pet resurrect
	if(!p_caster) 
		return;
	Pet *pPet = p_caster->GetSummon();
	if(pPet)
	{
		if( GetProto()->SpellGroupType)
		{
			SM_FIValue(p_caster->SM_FMiscEffect,&damage,GetProto()->SpellGroupType);
			SM_PIValue(p_caster->SM_PMiscEffect,&damage,GetProto()->SpellGroupType);
		}

		pPet->SetUInt32Value( UNIT_DYNAMIC_FLAGS, 0 );
		pPet->SetUInt32Value( UNIT_FIELD_HEALTH, ( uint32 )( ( pPet->GetUInt32Value(UNIT_FIELD_MAXHEALTH) * damage ) / 100 ));
		pPet->setDeathState( ALIVE );
		pPet->GetAIInterface()->HandleEvent( EVENT_FOLLOWOWNER, pPet, 0 );
		sEventMgr.RemoveEvents( pPet, EVENT_PET_DELAYED_REMOVE );
		pPet->SendSpellsToOwner();
	}
}

/* This effect has 2 functions
 * 1. It delete's all current totems from the player
 * 2. It returns a percentage of the mana back to the player
 *
 * Bur kick my ass if this is not safe:P
*/

void Spell::SpellEffectDestroyAllTotems(uint32 i)
{
	if(!p_caster || !p_caster->IsInWorld()) return;

	float RetreivedMana = 0.0f;
	for(uint32 x=0;x<4;x++)
	{
		// atm totems are considert creature's
		if(p_caster->m_TotemSlots[x])
		{
			uint32 SpellID = p_caster->m_TotemSlots[x]->GetUInt32Value(UNIT_CREATED_BY_SPELL);
			SpellEntry * sp = dbcSpell.LookupEntry(SpellID);
			if (!sp)
				continue;

			float pts = float(GetProto()->EffectBasePoints[i]+1) / 100.0f;
			RetreivedMana += float(sp->manaCost) * pts;

			p_caster->m_TotemSlots[x]->TotemExpire();
		}

		if(p_caster->m_ObjectSlots[x])
		{
			GameObject * obj = p_caster->GetMapMgr()->GetGameObject(p_caster->m_ObjectSlots[x]);
			if(obj)
			{
				obj->ExpireAndDelete();
			}
			p_caster->m_ObjectSlots[x] = 0;
		}
	}

	p_caster->Energize( p_caster, GetProto()->Id, uint32( RetreivedMana ), POWER_TYPE_MANA );
}

void Spell::SpellEffectResurrect(uint32 i) // Resurrect (Flat)
{
	if(!playerTarget)
	{
		if(!corpseTarget)
		{
			// unit resurrection handler
			if(unitTarget)
			{
				if(unitTarget->GetTypeId()==TYPEID_UNIT && unitTarget->IsPet() && unitTarget->isDead())
				{
					uint32 hlth = ((uint32)GetProto()->EffectBasePoints[i] > unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)) ? unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH) : (uint32)GetProto()->EffectBasePoints[i];
					uint32 mana = ((uint32)GetProto()->EffectBasePoints[i] > unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)) ? unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1) : (uint32)GetProto()->EffectBasePoints[i];

					if(!unitTarget->IsPet())
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					else
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_PET_DELAYED_REMOVE);
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					unitTarget->SetUInt32Value(UNIT_FIELD_HEALTH, hlth);
					unitTarget->SetUInt32Value(UNIT_FIELD_POWER1, mana);
					unitTarget->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
					unitTarget->setDeathState(ALIVE);
					((Creature*)unitTarget)->Tagged=false;
					((Creature*)unitTarget)->TaggerGuid=false;
					((Creature*)unitTarget)->loot.gold=0;
					((Creature*)unitTarget)->loot.looters.clear();
					((Creature*)unitTarget)->loot.items.clear();
				}
			}

			return;
		}
		playerTarget = objmgr.GetPlayer(corpseTarget->GetUInt32Value(CORPSE_FIELD_OWNER));
		if(!playerTarget) return;
	}

	if(playerTarget->isAlive() || !playerTarget->IsInWorld())
		return;

	uint32 health = GetProto()->EffectBasePoints[i];
	uint32 mana = GetProto()->EffectMiscValue[i];

	playerTarget->m_resurrectHealth = health;
	playerTarget->m_resurrectMana = mana;

	SendResurrectRequest(playerTarget);
	playerTarget->SetMovement(MOVE_UNROOT, 1);
}

void Spell::SpellEffectAttackMe(uint32 i)
{
	if(!unitTarget)
		return;
	if(!unitTarget->isAlive())
		return;

	unitTarget->GetAIInterface()->AttackReaction(u_caster,1,0);	
}

void Spell::SpellEffectSkinPlayerCorpse(uint32 i)
{
	Corpse * corpse = 0;
	if(!playerTarget)
	{
		// means we're "skinning" a corpse
		corpse = objmgr.GetCorpse((uint32)m_targets.m_unitTarget);	// hacky
	}
	else if(playerTarget->getDeathState() == CORPSE)	// repopped while we were casting 
	{
		corpse = objmgr.GetCorpse(playerTarget->GetLowGUID());
	}

	if(!m_caster->IsPlayer()) 
		return;
 
	if(playerTarget && !corpse)
	{
		if(!playerTarget->m_bg || !playerTarget->isDead())
			return;

		// Set all the lootable stuff on the player. If he repops before we've looted, we'll set the flags
		// on corpse then :p

		playerTarget->bShouldHaveLootableOnCorpse = false;
		playerTarget->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
		playerTarget->SetFlag(UNIT_DYNAMIC_FLAGS, U_DYN_FLAG_LOOTABLE);

		// Send the loot.
		p_caster->SendLoot(playerTarget->GetGUID(), LOOT_SKINNING);

		// Send a message to the died player, telling him he has to resurrect at the graveyard.
		// Send an empty corpse location too, :P
		
		playerTarget->GetSession()->OutPacket(SMSG_PLAYER_SKINNED, 1, "\x00");
		playerTarget->GetSession()->OutPacket(MSG_CORPSE_QUERY, 1, "\x00");

		// don't allow him to spawn a corpse
		playerTarget->bCorpseCreateable = false;

		// and.. force him to the graveyard and repop him.
		playerTarget->RepopRequestedPlayer();

	}else if(corpse)
	{
		// find the corpses' owner
		Player * owner = objmgr.GetPlayer(corpse->GetUInt32Value(CORPSE_FIELD_OWNER));
		if(owner)
		{
			if(owner->m_bg == NULL)
				return;

			owner->GetSession()->OutPacket(SMSG_PLAYER_SKINNED, 1, "\x00");
			owner->GetSession()->OutPacket(MSG_CORPSE_QUERY, 1, "\x00");
		}

		if(corpse->GetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS) != 1)
			corpse->SetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS, 1); // sets it so you can loot the plyr
		
		// remove skinnable flag
		corpse->SetUInt32Value(CORPSE_FIELD_FLAGS, 5);

		// remove owner association
		corpse->SetUInt64Value(CORPSE_FIELD_OWNER, 0);
		corpse->SetCorpseState(CORPSE_STATE_BONES);
		corpse->DeleteFromDB();
		objmgr.CorpseAddEventDespawn(corpse);

		// send loot
		p_caster->SendLoot(corpse->GetGUID(), LOOT_SKINNING);
	}
}

void Spell::SpellEffectSkill(uint32 i)
{
	// Used by professions only
	// Effect should be renamed in RequireSkill

	if ( !p_caster || p_caster->_GetSkillLineMax(GetProto()->EffectMiscValue[i]) >= uint32( damage * 75 ) )
		return;
	
	if ( p_caster->_HasSkillLine( GetProto()->EffectMiscValue[i]) )
		p_caster->_ModifySkillMaximum( GetProto()->EffectMiscValue[i], uint32( damage * 75 ) );
	else
		p_caster->_AddSkillLine( GetProto()->EffectMiscValue[i], 1, uint32( damage * 75 ) );
}

void Spell::SpellEffectApplyPetAura(uint32 i)
{
	SpellEffectApplyAura(i);
}

void Spell::SpellEffectDummyMelee( uint32 i ) // Normalized Weapon damage +
{

	if( unitTarget == NULL || u_caster == NULL )
		return;

	if( GetProto()->NameHash == SPELL_HASH_OVERPOWER && p_caster != NULL ) //warrior : overpower - let us clear the event and the combopoint count
	{
		p_caster->NullComboPoints(); //some say that we should only remove 1 point per dodge. Due to cooldown you can't cast it twice anyway..
		sEventMgr.RemoveEvents( p_caster, EVENT_COMBO_POINT_CLEAR_FOR_TARGET );
	}
	else if( GetProto()->NameHash == SPELL_HASH_DEVASTATE)
	{
		//count the number of sunder armors on target
		uint32 sunder_count=0;
		SpellEntry *spellInfo=dbcSpell.LookupEntry(25225);
		for(uint32 x = MAX_POSITIVE_AURAS; x < MAX_AURAS; ++x)
		{
			if(unitTarget->m_auras[x] && unitTarget->m_auras[x]->GetSpellProto()->NameHash == SPELL_HASH_SUNDER_ARMOR)
			{
				sunder_count++;
				spellInfo=unitTarget->m_auras[x]->GetSpellProto();
			}
		}
		if(!spellInfo)
			return; //omg how did this happen ?
		//we should also cast sunder armor effect on target with or without dmg
		Spell *spell = SpellPool.PooledNew();
		spell->Init(u_caster, spellInfo ,true, NULL);
		spell->ProcedOnSpell = GetProto();
		spell->pSpellId=GetProto()->Id;
		SpellCastTargets targets(unitTarget->GetGUID());
		spell->prepare(&targets);
		if(!sunder_count)
			return; //no damage = no joy
		damage = damage*sunder_count;
	}
	else if( GetProto()->NameHash == SPELL_HASH_CRUSADER_STRIKE ) // Crusader Strike - refreshes *all* judgements, not just your own
	{
		for( int x = MAX_POSITIVE_AURAS; x < MAX_AURAS; x ++ ) // there are only debuff judgements anyway :P
		{
			if( unitTarget->m_auras[x] && unitTarget->m_auras[x]->GetSpellProto()->BGR_one_buff_from_caster_on_1target == SPELL_TYPE_INDEX_JUDGEMENT )
			{
				// Refresh it!
				// oh noes, they don't stack...
				Aura * aur = unitTarget->m_auras[x];
				SpellEntry * spinfo = aur->GetSpellProto();
				aur->Remove();
				Spell * sp = SpellPool.PooledNew();
				sp->Init( this->u_caster , spinfo , true , NULL );
				
				SpellCastTargets tgt;
				tgt.m_unitTarget = unitTarget->GetGUID();
				sp->prepare( &tgt );
			}
		}
	}
	//Hemorrhage
	if( p_caster != NULL && GetProto()->NameHash == SPELL_HASH_HEMORRHAGE )
		p_caster->AddComboPoints(p_caster->GetSelection(), 1);

	switch( GetProto()->Id )
	{
			// AMBUSH
	case 8676: add_damage = 70; return; break;			// r1
	case 8724: add_damage = 100; return; break;			// r2
	case 8725: add_damage = 125; return; break;			// r3
	case 11267: add_damage = 185; return; break;		// r4
	case 11268: add_damage = 230; return; break;		// r5
	case 11269: add_damage = 290; return; break;		// r6
	case 27441: add_damage = 335; return; break;		// r7

			// BACKSTAB
	case 53: add_damage = 15; return; break;			// r1
	case 2589: add_damage = 30; return; break;			// r2
	case 2590: add_damage = 48; return; break;			// r3
	case 2591: add_damage = 69; return; break;			// r4
	case 8721: add_damage = 90; return; break;			// r5
	case 11279: add_damage = 135; return; break;		// r6
	case 11280: add_damage = 165; return; break;		// r7
	case 11281: add_damage = 210; return; break;		// r8
	case 25300: add_damage = 225; return; break;		// r9
	case 26863: add_damage = 255; return; break;		// r10
	}

	// rogue ambush etc
	for (uint32 x =0;x<3;x++)
	{
		if(GetProto()->Effect[x] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE)
		{
			add_damage = damage * (GetProto()->EffectBasePoints[x]+1) /100;
			return;
		}
	}

	//rogue - mutilate ads dmg if target is poisoned
	uint32 pct_dmg_mod = 100;
	if(	GetProto()->NameHash == SPELL_HASH_MUTILATE && unitTarget->IsPoisoned() )
		pct_dmg_mod = 150;

	uint32 _type;
	if( GetType() == SPELL_DMG_TYPE_RANGED )
		_type = RANGED;
	else
	{
		if (GetProto()->AttributesExC & 0x1000000)
			_type = OFFHAND;
		else
			_type = MELEE;
	}
	u_caster->Strike( unitTarget, _type, GetProto(), damage, pct_dmg_mod, 0, false, true );
}

void Spell::SpellEffectFilming( uint32 i )
{
	if (!playerTarget || !playerTarget->isAlive() || !u_caster)
		return;

	if(playerTarget->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOCK_PLAYER))
		return;

	TaxiPath* taxipath = sTaxiMgr.GetTaxiPath(GetProto()->EffectMiscValue[0]);
	if( !taxipath )
		return;

	TaxiNode* taxinode = sTaxiMgr.GetTaxiNode( taxipath->GetSourceNode() );
	if( !taxinode )
		return;

	uint32 modelid =0;

	if( playerTarget->GetTeam() )
	{
		CreatureInfo* ci = CreatureNameStorage.LookupEntry( taxinode->horde_mount );
		if(!ci) return;
		modelid = ci->Male_DisplayID;
		if(!modelid) return;
	}
	else
	{
		CreatureInfo* ci = CreatureNameStorage.LookupEntry( taxinode->alliance_mount );
		if(!ci) return;
		modelid = ci->Male_DisplayID;
		if(!modelid) return;
	}

	if(playerTarget->GetSummon() != NULL)
	{
		if(playerTarget->GetSummon()->GetUInt32Value(UNIT_CREATED_BY_SPELL) > 0)
			playerTarget->GetSummon()->Dismiss(false);										// warlock summon -> dismiss
		else
			playerTarget->GetSummon()->Remove( false, true, false );						// hunter pet -> just remove for later re-call
	}

	playerTarget->TaxiStart(taxipath, modelid, 0);
}

void Spell::SpellEffectSpellSteal( uint32 i )
{
	if (!unitTarget || !u_caster || !unitTarget->isAlive())
		return;
	if(unitTarget->IsPlayer() && p_caster && p_caster != static_cast< Player* >(unitTarget))
	{
		if(static_cast< Player* >(unitTarget)->IsPvPFlagged())
			p_caster->SetPvPFlag();
	}

	Aura *aur;
	uint32 start, end;
	if(isAttackable(u_caster,unitTarget))
	{
		start=0;
		end=MAX_POSITIVE_AURAS;
	}
	else
		return;
	
	WorldPacket data(SMSG_SPELLDISPELLOG, 16);

	for(uint32 x=start;x<end;x++)
	if(unitTarget->m_auras[x])
	{
		aur = unitTarget->m_auras[x];
		if(aur->GetSpellId() != 15007 && !aur->IsPassive()
//			&& aur->IsPositive()	// Zack : We are only checking positiv auras. There is no meaning to check again
			) //Nothing can dispel resurrection sickness
		{
			if(aur->GetSpellProto()->DispelType == DISPEL_MAGIC)
			{
				data.clear();
				data << m_caster->GetNewGUID();
				data << unitTarget->GetNewGUID();
				data << (uint32)1;
				data << aur->GetSpellId();
				m_caster->SendMessageToSet(&data,true);

				uint32 aurdur = ( aur->GetDuration()>120000 ? 120000 : aur->GetDuration() );
				Aura *aura = AuraPool.PooledNew();
				aura->Init(aur->GetSpellProto(), aurdur, u_caster, u_caster );
				uint32 aur_removed = unitTarget->RemoveAllPosAuraByNameHash( aur->GetSpellProto()->NameHash );
				for ( uint32 i = 0; i < 3; i++ )
				{
					if ( aura->GetSpellProto()->Effect[i] )
					{
						aura->AddMod( aura->GetSpellProto()->EffectApplyAuraName[i], aura->GetSpellProto()->EffectBasePoints[i]+1, aura->GetSpellProto()->EffectMiscValue[i], i );
					}
				}
				if( aura->GetSpellProto()->procCharges > 0 )
				{
					Aura *aur = NULL;
					for(uint32 i = 0; i<aur_removed-1; i++)
					{
						aur = AuraPool.PooledNew();
						aur->Init( aura->GetSpellProto(), aurdur, u_caster, u_caster );
						u_caster->AddAura(aur);
						aur = NULL;
					}
					if(!(aura->GetSpellProto()->procFlags & PROC_REMOVEONUSE))
					{
						SpellCharge charge;
						charge.count=aur_removed;
						charge.spellId=aura->GetSpellId();
						charge.ProcFlag=aura->GetSpellProto()->procFlags;
						charge.lastproc = 0;
						u_caster->m_chargeSpells.insert(make_pair(aura->GetSpellId(),charge));
					}
				}
				u_caster->AddAura(aura);
				break;
			}			
		}
	}
}

void Spell::SpellEffectProspecting(uint32 i)
{
	if(!p_caster) return;

	if(!itemTarget) // this should never happen
	{
		SendCastResult(SPELL_FAILED_CANT_BE_PROSPECTED);
		return;
	}

	//Fill Prospecting loot
	p_caster->SetLootGUID(itemTarget->GetGUID());
	if( !itemTarget->loot )
		{
			itemTarget->loot = new Loot;
			lootmgr.FillProspectingLoot( itemTarget->loot , itemTarget->GetEntry());
		}

	if ( itemTarget->loot->items.size() > 0 )
	{
		Log.Debug("SpellEffect","Succesfully prospected item %d", uint32(itemTarget->GetEntry()));
		p_caster->SendLoot( itemTarget->GetGUID(), LOOT_PROSPECTING );
	} 
	else // this should never happen either
	{
		Log.Debug("SpellEffect","Prospecting failed, item %d has no loot", uint32(itemTarget->GetEntry()));
		SendCastResult(SPELL_FAILED_CANT_BE_PROSPECTED);
	}
}

void Spell::SpellEffectResurrectNew(uint32 i)
{
	//base p =hp,misc mana
	if(!playerTarget)
	{
		if(!corpseTarget)
		{
			// unit resurrection handler
			if(unitTarget)
			{
				if(unitTarget->GetTypeId()==TYPEID_UNIT && unitTarget->IsPet() && unitTarget->isDead())
				{
					uint32 hlth = ((uint32)GetProto()->EffectBasePoints[i] > unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)) ? unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH) : (uint32)GetProto()->EffectBasePoints[i];
					uint32 mana = ((uint32)GetProto()->EffectBasePoints[i] > unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)) ? unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1) : (uint32)GetProto()->EffectBasePoints[i];

					if(!unitTarget->IsPet())
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					else
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_PET_DELAYED_REMOVE);
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					unitTarget->SetUInt32Value(UNIT_FIELD_HEALTH, hlth);
					unitTarget->SetUInt32Value(UNIT_FIELD_POWER1, mana);
					unitTarget->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
					unitTarget->setDeathState(ALIVE);
					((Creature*)unitTarget)->Tagged=false;
					((Creature*)unitTarget)->TaggerGuid=false;
					((Creature*)unitTarget)->loot.gold=0;
					((Creature*)unitTarget)->loot.looters.clear();
					((Creature*)unitTarget)->loot.items.clear();
				}
			}

			return;
		}
		playerTarget = objmgr.GetPlayer(corpseTarget->GetUInt32Value(CORPSE_FIELD_OWNER));
		if(!playerTarget) return;
	}

	if(playerTarget->isAlive() || !playerTarget->IsInWorld())
		return;
	//resurr
	//playerTarget->resurrector = p_caster->GetLowGUID();
	playerTarget->m_resurrectMapId = p_caster->GetMapId();
	playerTarget->m_resurrectInstanceID = p_caster->GetInstanceID();
	playerTarget->m_resurrectPosition = p_caster->GetPosition();
	playerTarget->m_resurrectHealth = damage;
	playerTarget->m_resurrectMana = GetProto()->EffectMiscValue[i];

	SendResurrectRequest( playerTarget );
}

void Spell::SpellEffectTranformItem(uint32 i)
{
	bool result;
	AddItemResult result2;

	if(!i_caster)
		return;
	uint32 itemid=GetProto()->EffectSpellGroupRelation[i];
	if(!itemid)
		return;

	//Save durability of the old item
	Player * owner=i_caster->GetOwner();
	uint32 dur= i_caster->GetUInt32Value(ITEM_FIELD_DURABILITY);
	//	int8 slot=owner->GetItemInterface()->GetInventorySlotByGuid(i_caster->GetGUID());
	//	uint32 invt=i_caster->GetProto()->InventoryType;

	result = owner->GetItemInterface()->SafeFullRemoveItemByGuid(i_caster->GetGUID());
	if(!result)
	{
		//something went wrong if this happen, item doesnt exist, so it wasnt destroyed.
		return;
	}

	i_caster = NULL;

	Item *it=objmgr.CreateItem(itemid,owner);
	it->SetDurability(dur);
	//additem

	//additem
	result2 = owner->GetItemInterface()->AddItemToFreeSlot(it);
	if(!result2) //should never get here
	{
		owner->GetItemInterface()->BuildInventoryChangeError(NULL,NULL,INV_ERR_BAG_FULL);
		it->DeleteMe();
	}
}

void Spell::SpellEffectEnvironmentalDamage(uint32 i)
{
	if(!playerTarget)
		return;

	if(unitTarget->SchoolImmunityList[GetProto()->School])
	{
		SendCastResult(SPELL_FAILED_IMMUNE);
		return;
	}
	//this is GO, not unit	
	m_caster->SpellNonMeleeDamageLog(unitTarget,GetProto()->Id,damage, pSpellId==0);

	WorldPacket data(SMSG_ENVIRONMENTALDAMAGELOG, 13);
	data << unitTarget->GetGUID();
	data << uint8(DAMAGE_FIRE);
	data << uint32(damage);
	unitTarget->SendMessageToSet( &data, true );
}

void Spell::SpellEffectDismissPet(uint32 i)
{
	// remove pet.. but don't delete so it can be called later
	if(!p_caster)
		return;

	Pet *pPet = p_caster->GetSummon();
	if(!pPet)
		return;
	pPet->Remove(true, true, true);
}

void Spell::SpellEffectEnchantHeldItem( uint32 i )
{
	if( playerTarget == NULL )
		return;

	Item * item = playerTarget->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_MAINHAND );
	if( item == NULL )
		return;

	uint32 Duration = 1800; // Needs to be found in dbc.. I guess?
	switch( GetProto()->NameHash )
	{
		case SPELL_HASH_WINDFURY_TOTEM_EFFECT: // Windfury Totem Effect
		{
			Duration = 10;
		}
		case SPELL_HASH_FLAMETONGUE_TOTEM_EFFECT: // Flametongue Totem Effect
		{
			Duration = 10;
		}
	}

	EnchantEntry * Enchantment = dbcEnchant.LookupEntry( GetProto()->EffectMiscValue[i] );
	if( Enchantment == NULL )
		return;

	if (m_spellInfo->NameHash == SPELL_HASH_WINDFURY_TOTEM_EFFECT && item->HasEnchantmentOnSlot( 1 ) && item->GetEnchantment( 1 )->Enchantment != Enchantment) //dirty fix for Windfury totem not overwriting existing enchantments
		return;

	item->RemoveEnchantment( 1 );
	item->AddEnchantment( Enchantment, Duration, false, true, false, 1 );
}

void Spell::SpellEffectAddHonor(uint32 i)
{
	if( playerTarget == NULL )
		return;
	uint32 val = GetProto()->EffectBasePoints[i];

	if( GetProto()->AttributesExB & FLAGS3_UNK4 )val /= 10;

	val += 1;

	HonorHandler::AddHonorPointsToPlayer( playerTarget, val );

	WorldPacket data(SMSG_PVP_CREDIT, 16);
	data << val;
	data << uint64(0);
	data << uint32(5);
	playerTarget->GetSession()->SendPacket(&data);
}

void Spell::SpellEffectSpawn(uint32 i)
{
	// this effect is mostly for custom teleporting
	switch(GetProto()->Id)
	{
		case 10418: // Arugal spawn-in spell , teleports it to 3 locations randomly sneeking players (bastard ;P)
		{
			if(!u_caster || u_caster->IsPlayer())
				return;

			static float coord[3][3]= {{-108.9034f,2129.5678f,144.9210f},{-108.9034f,2155.5678f,155.678f},{-77.9034f,2155.5678f,155.678f}};

			int i = (int)(rand()%3);
			u_caster->GetAIInterface()->SendMoveToPacket(coord[i][0],coord[i][1],coord[i][2],0.0f,0,u_caster->GetAIInterface()->getMoveFlags());
		}
	}
}

void Spell::SpellEffectApplyAura128(uint32 i)
{
	if(GetProto()->EffectApplyAuraName[i] != 0)
		SpellEffectApplyAura(i);
}

void Spell::SpellEffectTriggerSpellWithValue(uint32 i)
{
	if( unitTarget == NULL )
		return;

	SpellEntry* TriggeredSpell = dbcSpell.LookupEntryForced(GetProto()->EffectTriggerSpell[i]);
	if( TriggeredSpell == NULL )
		return;

	Spell * sp = SpellPool.PooledNew();
	sp->Init(m_caster,dbcSpell.LookupEntry(TriggeredSpell->Id),true,NULL);

	for(uint32 x=0;x<3;x++)
	{
		if( i==x )
			sp->forced_basepoints[x] = damage;	//prayer of mending should inherit heal bonus ?
		else
			sp->forced_basepoints[x] = TriggeredSpell->EffectBasePoints[i];

	}

	SpellCastTargets tgt(unitTarget->GetGUID());
	sp->prepare(&tgt);
}

void Spell::SpellEffectSummonTarget(uint32 i) // ritual of summoning
{
	if ( unitTarget == NULL )
		return;
/*
	Spell * sp = SpellPool.PooledNew();
	sp->Init( m_caster, dbcSpell.LookupEntry( GetProto()->EffectTriggerSpell[i] ), true, NULL );
	SpellCastTargets tgt( unitTarget->GetGUID() );
	sp->prepare( &tgt );
*/
	SpellEffectTriggerSpell( i );
}

void Spell::SpellEffectForgetSpecialization(uint32 i)
{
	if (!playerTarget)
		return;

	uint32 spellid = GetProto()->EffectTriggerSpell[i];
	playerTarget->removeSpell( spellid, false, false, 0);

	sLog.outDebug("Player %u have forgot spell %u from spell %u ( caster: %u)", playerTarget->GetLowGUID(), spellid, GetProto()->Id, m_caster->GetLowGUID());
}

void Spell::SpellEffectKillCredit(uint32 i)
{
	if( !m_caster ) return;
	Player * pPlayer = ((m_caster->IsPlayer())?((Player*)m_caster):NULL);
	if( pPlayer == NULL ) return;
	Quest * qst;
	for( uint32 i = 0; i < 25; ++i )
	{
		if( pPlayer->GetQuestLogInSlot(i) != NULL )
		{
			qst = pPlayer->GetQuestLogInSlot(i)->GetQuest();
			for( uint32 j = 0; j < 5; ++j )
				if( qst->required_mob[j] == m_spellInfo->EffectMiscValue[i] )
					pPlayer->GetQuestLogInSlot(i)->SendUpdateAddKill(j);
		}
	}
}
