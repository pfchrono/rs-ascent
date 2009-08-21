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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "StdAfx.h"

void Spell::SummonTotem(uint32 i) // Summon Totem
{
	if(!p_caster) 
		return;

	float x = p_caster->GetPositionX();
	float y = p_caster->GetPositionY();
	uint32 slot = m_spellInfo->EffectImplicitTargetA[i] - EFF_TARGET_TOTEM_EARTH;
	if(slot < 0 || slot > 3)
	{
		sLog.outDebug("Totem slot is : %u and max shoud be 3, i = %u , target = %u \n",slot,i,m_spellInfo->EffectImplicitTargetA[i]);
		return; // Just 4 totems
	}

	switch(m_spellInfo->EffectMiscValueB[i])
	{
	case SUMMON_TYPE_TOTEM_FIRE: 
		x -= 1.5f;
		y -= 1.5f;
		break;
	case SUMMON_TYPE_TOTEM_EARTH:
		x -= 1.5f;
		y += 1.5f;
		break;
	case SUMMON_TYPE_TOTEM_WATER:
		x += 1.5f;
		y -= 1.5f;
		break;
	case SUMMON_TYPE_TOTEM_AIR:
		x += 1.5f;
		y += 1.5f;
		break;
	default:
		break;
	}

	if(p_caster->m_TotemSlots[slot] != 0)
		p_caster->m_TotemSlots[slot]->TotemExpire();

	uint32 entry = GetProto()->EffectMiscValue[i];

	CreatureInfo* ci = CreatureNameStorage.LookupEntry(entry);
	if(!ci)
	{
		sLog.outDebug("Missing totem creature entry : %u \n",entry);
		return;
	}

	// Obtain the spell we will be casting.
	SpellEntry * TotemSpell = ObjectMgr::getSingleton().GetTotemSpell(GetProto()->Id);
	if(TotemSpell == 0) 
	{
		sLog.outDebug("Totem %u does not have any spells to cast, exiting\n",entry);
		return;
	}

	Creature * pTotem = p_caster->GetMapMgr()->CreateCreature(entry);

	p_caster->m_TotemSlots[slot] = pTotem;
	pTotem->SetTotemOwner(p_caster);
	pTotem->SetTotemSlot(slot);

	float landh = p_caster->GetMapMgr()->GetLandHeight(x,y);
	float landdiff = landh - p_caster->GetPositionZ();

	if (fabs(landdiff)>15)
		pTotem->Create(ci->Name, p_caster->GetMapId(), x, y, p_caster->GetPositionZ(), p_caster->GetOrientation());
	else
		pTotem->Create(ci->Name, p_caster->GetMapId(), x, y, landh, p_caster->GetOrientation());

	uint32 displayID = 0;

	if( p_caster->GetTeamInitial() == TEAM_HORDE ) // Totems for Horde use the female display fields
	{
		if ( ci->Female_DisplayID != 0 )
		{
			displayID = ci->Female_DisplayID;
		}
		else
		{
			if( ci->Male_DisplayID == 4587 )
				displayID = 19075;
			else if( ci->Male_DisplayID == 4588 )
				displayID = 19073;
			else if( ci->Male_DisplayID == 4589 )
				displayID = 19074;
			else if( ci->Male_DisplayID == 4590 )
				displayID = 19071;
			else if( ci->Male_DisplayID == 4683 )
				displayID = 19074;
			else
				displayID = ci->Male_DisplayID;
		}
	}
	else // Totems for Alliance use the male display fields
	{
		displayID = ci->Male_DisplayID;
	}

	// Set up the creature.
	pTotem->SetUInt32Value(OBJECT_FIELD_ENTRY, entry);
	pTotem->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
	pTotem->SetUInt64Value(UNIT_FIELD_CREATEDBY, p_caster->GetGUID());
	pTotem->SetUInt32Value(UNIT_FIELD_HEALTH, damage);
	pTotem->SetUInt32Value(UNIT_FIELD_MAXHEALTH, damage);
	pTotem->SetUInt32Value(UNIT_FIELD_POWER3, p_caster->getLevel() * 30);
	pTotem->SetUInt32Value(UNIT_FIELD_MAXPOWER3, p_caster->getLevel() * 30);
	pTotem->SetUInt32Value(UNIT_FIELD_LEVEL, p_caster->getLevel());
	pTotem->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
	pTotem->SetUInt32Value(UNIT_FIELD_BYTES_0, (1 << 8) | (2 << 16) | (1 << 24));
	pTotem->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED | UNIT_FLAG_SELF_RES);
	pTotem->SetUInt32Value(UNIT_FIELD_BASEATTACKTIME, 2000);
	pTotem->SetUInt32Value(UNIT_FIELD_BASEATTACKTIME_01, 2000);
	pTotem->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 1.0f);
	pTotem->SetFloatValue(UNIT_FIELD_COMBATREACH, 1.0f);
	pTotem->SetUInt32Value(UNIT_FIELD_DISPLAYID, displayID);
	pTotem->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, ci->Male_DisplayID); //blizzlike :P
	pTotem->SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
	pTotem->SetUInt32Value(UNIT_CREATED_BY_SPELL, GetProto()->Id);
	pTotem->SetUInt32Value(UNIT_FIELD_BYTES_2, 1 | (0x28 << 8));

	// Initialize faction stuff.
	pTotem->m_faction = p_caster->m_faction;
	pTotem->m_factionDBC = p_caster->m_factionDBC;

	//added by Zack : Some shaman talents are casted on player but it should be inherited or something by totems
	pTotem->InheritSMMods(p_caster);

	// Totems get spell damage and healing bonus from the Shaman
	for(int school=0;school<7;school++){
		pTotem->ModDamageDone[school] = (int32)(p_caster->GetUInt32Value( PLAYER_FIELD_MOD_DAMAGE_DONE_POS + school ) - (int32)p_caster->GetUInt32Value( PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + school ));
		pTotem->HealDoneMod[school] = p_caster->HealDoneMod[school];
	}

	// Set up AI, depending on our spells.
	uint32 j;
	for( j = 0; j < 3; ++j )
	{
		if( TotemSpell->Effect[j] == SPELL_EFFECT_APPLY_AREA_AURA || TotemSpell->Effect[j] == SPELL_EFFECT_PERSISTENT_AREA_AURA || TotemSpell->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_TRIGGER_SPELL )
		{
			break;
		}
	}
	// Setup complete. Add us to the world.
	pTotem->PushToWorld(m_caster->GetMapMgr());

	if(j != 3)
	{
		// We're an area aura. Simple. Disable AI and cast the spell.
		pTotem->DisableAI();
		pTotem->GetAIInterface()->totemspell = GetProto();

		Spell * pSpell = SpellPool.PooledNew();
		pSpell->Init(pTotem, TotemSpell, true, 0);

		SpellCastTargets targets;
		targets.m_destX = pTotem->GetPositionX();
		targets.m_destY = pTotem->GetPositionY();
		targets.m_destZ = pTotem->GetPositionZ();
		targets.m_targetMask = TARGET_FLAG_DEST_LOCATION;

		pSpell->prepare(&targets);
	}
	else
	{
		// We're a casting totem. Switch AI on, and tell it to cast this spell.
		pTotem->EnableAI();
		pTotem->GetAIInterface()->Init(pTotem, AITYPE_TOTEM, MOVEMENTTYPE_NONE, p_caster);
		pTotem->GetAIInterface()->totemspell = TotemSpell;
		int32 totemspelltimer = 3000, totemspelltime = 3000;	// need a proper resource for this.

		switch(TotemSpell->Id)
		{
		case 8167: //Poison Cleansing Totem
		case 8172: //Disease Cleansing Totem
		{
			if(TotemSpell->Id == 8167)
				TotemSpell = dbcSpell.LookupEntry( 8168 );	// Better to use this spell
			else
				TotemSpell = dbcSpell.LookupEntry( 8171 );
			pTotem->GetAIInterface()->totemspell = TotemSpell;
			totemspelltime =  5000;
			totemspelltimer = 0; //First tick done immediately
			break;
		}
		case 8146: //Tremor Totem
		{
			totemspelltime = 3000;
			totemspelltimer = 0; //First tick done immediately
			break;
		}
		case 8349: //Fire Nova Totem 1
		case 8502: //Fire Nova Totem 2
		case 8503: //Fire Nova Totem 3
		case 11306: //Fire Nova Totem 4
		case 11307: //Fire Nova Totem 5
		case 25535: //Fire Nova Totem 6
		case 25537: //Fire Nova Totem 7
		{
			totemspelltimer =  4000;
			// Improved Fire Totems
			SM_FIValue(p_caster->SM_FDur, &totemspelltimer, TotemSpell->SpellGroupType);
			totemspelltime = totemspelltimer;
			break;
		}
		default:
			break;
		}
		switch(m_spellInfo->NameHash)
		{
			case SPELL_HASH_STONECLAW_TOTEM:
			{
				totemspelltime = 30000; // Should be casted only once
				totemspelltimer = 0; // Casted immediately
			}break;
			default:
				break;
		}

		pTotem->GetAIInterface()->m_totemspelltimer = totemspelltimer;
		pTotem->GetAIInterface()->m_totemspelltime = totemspelltime;
	}

	//in case these are our elemental totems then we should set them up
	if(GetProto()->Id==2062)
	{
		pTotem->GetAIInterface()->Event_Summon_EE_totem(GetDuration());
		pTotem->DisableAI();
	}
	else if(GetProto()->Id==2894)
	{
		pTotem->GetAIInterface()->Event_Summon_FE_totem(GetDuration());
		pTotem->DisableAI();
	}

	// Set up the deletion event. The totem needs to expire after a certain time, or upon its death.
	sEventMgr.AddEvent(pTotem, &Creature::TotemExpire, EVENT_TOTEM_EXPIRE, GetDuration(), 1,0);
}

void Spell::SummonPossessed(uint32 i) // eye of kilrog
{
	/*
	m_target->DisableAI();
	pCaster->SetUInt64Value(UNIT_FIELD_SUMMON, 0);
	m_target->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, 0);
	pCaster->SetUInt64Value(UNIT_FIELD_CHARM, m_target->GetGUID());
	m_target->SetUInt64Value(UNIT_FIELD_CHARMEDBY, pCaster->GetGUID());
	pCaster->SetUInt64Value(PLAYER_FARSIGHT, m_target->GetGUID());
	pCaster->m_CurrentCharm = ((Creature*)m_target);
	m_target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED_CREATURE);
	pCaster->m_noInterrupt = 1;
	pCaster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOCK_PLAYER);

	WorldPacket data(SMSG_DEATH_NOTIFY_OBSOLETE);
	data << m_target->GetNewGUID() << uint8(1);
	pCaster->GetSession()->SendPacket(&data);
	*/

/*
	CreatureInfo *ci = CreatureNameStorage.LookupEntry(GetProto()->EffectMiscValue[i]);
	if( ci)
	{
		Creature* NewSummon = m_caster->GetMapMgr()->CreateCreature();
		// Create
		NewSummon->SetInstanceID(m_caster->GetInstanceID());
		NewSummon->Create( ci->Name, m_caster->GetMapId(), 
			m_caster->GetPositionX()+(3*(cos((float(M_PI)/2)+m_caster->GetOrientation()))), m_caster->GetPositionY()+(3*(cos((float(M_PI)/2)+m_caster->GetOrientation()))), m_caster->GetPositionZ(), m_caster->GetOrientation());

		// Fields
		NewSummon->SetUInt32Value(UNIT_FIELD_LEVEL,m_caster->GetUInt32Value(UNIT_FIELD_LEVEL));
		NewSummon->SetUInt32Value(UNIT_FIELD_DISPLAYID, ci->Male_DisplayID);
		NewSummon->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, ci->Male_DisplayID);
		NewSummon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, m_caster->GetGUID());
		NewSummon->SetUInt64Value(UNIT_FIELD_CREATEDBY, m_caster->GetGUID());
		NewSummon->SetUInt32Value(UNIT_FIELD_HEALTH , 100);
		NewSummon->SetUInt32Value(UNIT_FIELD_MAXHEALTH , 100);
		NewSummon->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 35);
		NewSummon->SetFloatValue(OBJECT_FIELD_SCALE_X,1.0f);
		NewSummon->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9 | UNIT_FLAG_PLAYER_CONTROLLED_CREATURE);

		//Setting faction
		NewSummon->_setFaction();
		NewSummon->m_temp_summon=true;

		// Add To World
		NewSummon->PushToWorld(m_caster->GetMapMgr());
		
		// Force an update on the player to create this guid.
		p_caster->ProcessPendingUpdates();

		//p_caster->SetUInt64Value(UNIT_FIELD_SUMMON, NewSummon->GetGUID());
		//p_caster->SetUInt64Value(PLAYER_FARSIGHT, NewSummon->GetGUID());
		//p_caster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOCK_PLAYER);
		p_caster->Possess(NewSummon);
	}*/
}

void Spell::SummonCritter(uint32 i)
{
	if(!u_caster || u_caster->IsInWorld() == false)
		return;

	uint32 SummonCritterID = GetProto()->EffectMiscValue[i];

	// GetProto()->EffectDieSides[i] has something to do with dismissing our critter
	// when it is 1, it means to just dismiss it if we already have it
	// when it is 0, it could mean to always summon a new critter, but there seems to be exceptions

	if(u_caster->critterPet)
	{
		// if we already have this critter, we will just dismiss it and return
		if(u_caster->critterPet->GetCreatureInfo() && u_caster->critterPet->GetCreatureInfo()->Id == SummonCritterID)
		{
			u_caster->critterPet->RemoveFromWorld(false,true);
			//delete u_caster->critterPet;
			u_caster->critterPet = NULL;
			return;
		}
		// this is a different critter, so we will dismiss our current critter and then go on to summon the new one
		else
		{
			u_caster->critterPet->RemoveFromWorld(false,true);
			//delete u_caster->critterPet;
			u_caster->critterPet = NULL;
		}
	}

	if(!SummonCritterID) return;

	CreatureInfo * ci = CreatureNameStorage.LookupEntry(SummonCritterID);
	CreatureProto * cp = CreatureProtoStorage.LookupEntry(SummonCritterID);

	if(!ci || !cp) return;

	Creature * pCreature = u_caster->GetMapMgr()->CreateCreature(SummonCritterID);
	pCreature->SetInstanceID(u_caster->GetMapMgr()->GetInstanceID());
	pCreature->Load(cp, m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation());
	pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 35);
	pCreature->_setFaction();
	pCreature->SetUInt32Value(UNIT_FIELD_LEVEL, 1);
	pCreature->GetAIInterface()->Init(pCreature,AITYPE_PET,MOVEMENTTYPE_NONE,u_caster);
	pCreature->GetAIInterface()->SetUnitToFollow(u_caster);
	pCreature->GetAIInterface()->SetUnitToFollowAngle(float(-(M_PI/2)));
	pCreature->GetAIInterface()->SetFollowDistance(GetRadius(GetProto()->EffectRadiusIndex[i]));
	pCreature->GetAIInterface()->disable_melee = true;
	pCreature->bInvincible = true;
	pCreature->PushToWorld(u_caster->GetMapMgr());
	u_caster->critterPet = pCreature;
}

void Spell::SummonDemon(uint32 i)
{
	if(!p_caster/* || p_caster->getClass() != WARLOCK */) //summoning a demon shouldn't be warlock only, see spells 25005, 24934, 24810 etc etc
		return;
	Pet *pPet = p_caster->GetSummon();
	if(pPet)
	{
		pPet->Dismiss(false);
	}

	CreatureInfo *ci = CreatureNameStorage.LookupEntry(GetProto()->EffectMiscValue[i]);
	if(ci)
	{

		pPet = objmgr.CreatePet();
		pPet->SetInstanceID(p_caster->GetInstanceID());
		pPet->CreateAsSummon(GetProto()->EffectMiscValue[i], ci, NULL, p_caster, GetProto(), 1, 300000, this);
	}
	//Create Enslave Aura if its inferno spell
	if(GetProto()->Id == 1122)
	{
		SpellEntry *spellInfo = dbcSpell.LookupEntry(11726);
		
		Spell *sp=SpellPool.PooledNew();
		sp->Init((Object *)pPet,spellInfo,true,NULL);
		SpellCastTargets tgt;
		tgt.m_unitTarget=pPet->GetGUID();
		sp->prepare(&tgt);
	}
}

void Spell::SummonGuardian(uint32 i) // Summon Guardian
{
	//these are not pets. Just some creatures that will fight on your side. 
	//They follow you and attack your target but you cannot command them
	//number of creatures is actualy dmg (the usual formula), sometimes =3 sometimes =1
	

	if ( !(u_caster || g_caster) )
		return;


	uint32 cr_entry = GetProto()->EffectMiscValue[i];
	uint32 level = 0;

	float angle_for_each_spawn = -float(M_PI) * 2 / damage;
	for( int i = 0; i < damage; i++ )
	{
		float m_fallowAngle = angle_for_each_spawn * i;
		if ( g_caster ) 
		{
			u_caster = g_caster->m_summoner;
			g_caster->create_guardian(cr_entry,GetDuration(),m_fallowAngle, u_caster);
		}
		else
		{
			u_caster->create_guardian(cr_entry,GetDuration(),m_fallowAngle);
		}
	}
}

void Spell::SummonWild(uint32 i)		// Summon Wild
{
//	if(!u_caster || !u_caster->IsInWorld())
//		return;

	//these are some cretures that have your faction and do not respawn
	//number of creatures is actualy dmg (the usual formula), sometimes =3 sometimes =1
	uint32 cr_entry=GetProto()->EffectMiscValue[i];
	CreatureProto * proto = CreatureProtoStorage.LookupEntry(cr_entry);
	CreatureInfo * info = CreatureNameStorage.LookupEntry(cr_entry);
	if(!proto || !info)
	{
		sLog.outDetail("Warning : Missing summon creature template %u used by spell %u!",cr_entry,GetProto()->Id);
		return;
	}
	float x, y, z;
	if( m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION && m_targets.m_destX && m_targets.m_destY && m_targets.m_destZ )
	{
		x = m_targets.m_destX;
		y = m_targets.m_destY;
		z = m_targets.m_destZ;
	}
	else
	{
		x = u_caster->GetPositionX();
		y = u_caster->GetPositionY();
		z = u_caster->GetPositionZ();
	}
	for(int i=0;i<damage;i++)
	{
		float m_fallowAngle=-(float(M_PI)/2*i);
		x += (GetRadius(GetProto()->EffectRadiusIndex[i])*(cosf(m_fallowAngle+u_caster->GetOrientation())));
		y += (GetRadius(GetProto()->EffectRadiusIndex[i])*(sinf(m_fallowAngle+u_caster->GetOrientation())));
		float o = u_caster->GetOrientation();
		Creature * p = u_caster->GetMapMgr()->CreateCreature(cr_entry);
		//ASSERT(p);
		p->Load(proto, x, y, z, o);
		p->SetZoneId( m_caster->GetZoneId() );

		if ( p->GetProto() && p->GetProto()->Faction == 35 )
		{
			p->SetUInt64Value( UNIT_FIELD_SUMMONEDBY, m_caster->GetGUID() );
			p->SetUInt64Value( UNIT_FIELD_CREATEDBY, m_caster->GetGUID() );
			p->SetUInt32Value( UNIT_FIELD_FACTIONTEMPLATE, u_caster->GetUInt32Value( UNIT_FIELD_FACTIONTEMPLATE ) );
		}
		else
		{
			p->SetUInt32Value( UNIT_FIELD_FACTIONTEMPLATE, proto->Faction );
		}

		p->m_faction = dbcFactionTemplate.LookupEntry(proto->Faction);
		if(p->m_faction)
			p->m_factionDBC = dbcFaction.LookupEntry(p->m_faction->Faction);
		p->PushToWorld(u_caster->GetMapMgr());
		//make sure they will be desumonized (roxor)
		sEventMgr.AddEvent(p, &Creature::SummonExpire, EVENT_SUMMON_EXPIRE, GetDuration(), 1,0);
	}
}

void Spell::CreateSummonTotem(uint32 i)
{
	//Atalai Skeleton Totem
}

void Spell::SummonGeneric(uint32 i)
{
	if( !p_caster || !p_caster->IsInWorld() )
		return;

	u_caster->RemoveFieldSummon();

	/* This is for summon water elemenal, etc */
	CreatureInfo * ci = CreatureNameStorage.LookupEntry(GetProto()->EffectMiscValue[i]);
	CreatureProto * cp = CreatureProtoStorage.LookupEntry(GetProto()->EffectMiscValue[i]);
	if( !ci || !cp )
		return;

	if(GetProto()->EffectMiscValue[i] == 510)	// Water Elemental
	{
		Pet *summon = objmgr.CreatePet();
		summon->SetInstanceID(u_caster->GetInstanceID());
		summon->CreateAsSummon(GetProto()->EffectMiscValue[i], ci, NULL, p_caster, GetProto(), 1, 45000);
		summon->SetUInt32Value(UNIT_FIELD_LEVEL, p_caster->getLevel());
		summon->AddSpell(dbcSpell.LookupEntry(31707), true);
		summon->AddSpell(dbcSpell.LookupEntry(33395), true);
		summon->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
		summon->_setFaction();
		p_caster->m_tempSummon = summon;
	}
	else
	{
		Creature * pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
		ASSERT(pCreature != NULL);

		pCreature->Load(cp, p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), p_caster->GetOrientation());
		pCreature->_setFaction();
		pCreature->GetAIInterface()->Init(pCreature,AITYPE_PET,MOVEMENTTYPE_NONE,u_caster);
		pCreature->GetAIInterface()->SetUnitToFollow(p_caster);
		pCreature->GetAIInterface()->SetUnitToFollowAngle(float(-(M_PI/2)));
		pCreature->GetAIInterface()->SetFollowDistance(GetRadius(GetProto()->EffectRadiusIndex[i]));
		pCreature->SetUInt32Value(UNIT_FIELD_LEVEL, u_caster->getLevel());
		pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
		pCreature->_setFaction();
		pCreature->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, p_caster->GetGUID());
		pCreature->SetUInt64Value(UNIT_FIELD_CREATEDBY, p_caster->GetGUID());

		u_caster->SetUInt64Value(UNIT_FIELD_SUMMON, pCreature->GetGUID());

		if ( m_spellInfo->EffectMiscValue[i] == 19668 ) //shadowfiend
		{
			float parent_bonus = (float)(p_caster->GetDamageDoneMod(SCHOOL_SHADOW)*0.065f);
			pCreature->SetFloatValue(UNIT_FIELD_MINDAMAGE, pCreature->GetFloatValue(UNIT_FIELD_MINDAMAGE) + parent_bonus);
			pCreature->SetFloatValue(UNIT_FIELD_MAXDAMAGE, pCreature->GetFloatValue(UNIT_FIELD_MAXDAMAGE) + parent_bonus);
			pCreature->BaseDamage[0] += parent_bonus;
			pCreature->BaseDamage[1] += parent_bonus;
			//TODO add avoidance chance 75%
		}
		pCreature->PushToWorld(u_caster->GetMapMgr());
	}
}
