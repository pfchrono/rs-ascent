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

initialiseSingleton( ChatHandler );
initialiseSingleton(CommandTableStorage);

ChatCommand * ChatHandler::getCommandTable()
{
	ASSERT(false);
	return 0;
}

ChatCommand * CommandTableStorage::GetSubCommandTable(const char * name)
{
	if(!strcmp(name, "modify"))
		return _modifyCommandTable;
	else if(!strcmp(name, "debug"))
		return _debugCommandTable;
	else if(!strcmp(name, "waypoint"))
		return _waypointCommandTable;
	else if(!strcmp(name, "gmTicket"))
		return _GMTicketCommandTable;
	else if(!strcmp(name, "gobject"))
		return _GameObjectCommandTable;
	else if(!strcmp(name, "battleground"))
		return _BattlegroundCommandTable;
	else if(!strcmp(name, "npc"))
		return _NPCCommandTable;
	else if(!strcmp(name, "cheat"))
		return _CheatCommandTable;
	else if(!strcmp(name, "account"))
		return _accountCommandTable;
	else if(!strcmp(name, "ahbot"))
		return _AHBotCommandTable;
	else if(!strcmp(name, "pet"))
		return _petCommandTable;
	else if(!strcmp(name, "recall"))
		return _recallCommandTable;
	else if(!strcmp(name, "honor"))
		return _honorCommandTable;
	else if(!strcmp(name, "guild"))
		return _GuildCommandTable;
	else if(!strcmp(name, "quest"))
		return _questCommandTable;
	else if(!strcmp(name, "warn"))
		return _warnCommandTable;
	else if(!strcmp(name, "title"))
		return _titleCommandTable;
	else if(!strcmp(name, "report"))
		return _reportCommandTable;
	else if(!strcmp(name, "bug"))
		return _bugReportCommandTable;
	else if(!strcmp(name, "instance"))
		return _instanceCommandTable;
	return 0;
}

#define dupe_command_table(ct, dt) this->dt = (ChatCommand*)allocate_and_copy(sizeof(ct)/* / sizeof(ct[0])*/, ct)
ASCENT_INLINE void* allocate_and_copy(uint32 len, void * pointer)
{
	void * data = (void*)malloc(len);
	memcpy(data, pointer, len);
	return data;
}

void CommandTableStorage::Load()
{
	QueryResult * result = WorldDatabase.Query("SELECT * FROM command_overrides");
	if(!result) return;

	do 
	{
		const char * name = result->Fetch()[0].GetString();
		const char * level = result->Fetch()[1].GetString();
		Override(name, level);
	} while(result->NextRow());
	delete result;
}

void CommandTableStorage::Override(const char * command, const char * level)
{
	ASSERT(level[0] != '\0');
	char * cmd = strdup(command);

	// find the command we're talking about
	char * sp = strchr(cmd, ' ');
	const char * command_name = cmd;
	const char * subcommand_name = 0;

	if(sp != 0)
	{
		// we're dealing with a subcommand.
		*sp = 0;
		subcommand_name = sp + 1;
	}

	size_t len1 = strlen(command_name);
	size_t len2 = subcommand_name ? strlen(subcommand_name) : 0;

	// look for the command.
	ChatCommand * p = &_commandTable[0];
	while(p->Name != 0)
	{
		if(!strnicmp(p->Name, command_name, len1))
		{
			// this is the one we wanna modify
			if(!subcommand_name)
			{
				// no subcommand, we can change it.
				p->CommandGroup = level[0];
				printf("Changing command level of command `%s` to %c.\n", p->Name, level[0]);
			}
			else
			{
				// assume this is a subcommand, loop the second set.
				ChatCommand * p2 = p->ChildCommands;
				if(!p2)
				{
					printf("Invalid command specified for override: %s\n", command_name);
				}
				else
				{
					while(p2->Name != 0)
					{
						if(!strnicmp("*",subcommand_name,1))
						{
								p2->CommandGroup = level[0];
								printf("Changing command level of command (wildcard) `%s`:`%s` to %c.\n", p->Name, p2->Name, level[0]);
						}else{
							if(!strnicmp(p2->Name, subcommand_name, len2))
							{
								// change the level
								p2->CommandGroup = level[0];
								printf("Changing command level of command `%s`:`%s` to %c.\n", p->Name, p2->Name, level[0]);
								break;
							}
						}
						p2++;
					}
					if(p2->Name == 0)
					{
						if(strnicmp("*",subcommand_name,1)) //Hacky.. meh.. -DGM
						{
							printf("Invalid subcommand referenced: `%s` under `%s`.\n", subcommand_name, p->Name);
						}
						break;
					}
				}
			}
			break;
		}
		++p;
	}

	if(p->Name == 0)
	{
		printf("Invalid command referenced: `%s`\n", command_name);
	}

	free(cmd);
}

void CommandTableStorage::Dealloc()
{
	free( _modifyCommandTable );

	/* RockStar Command Tables */
	free( _warnCommandTable );
	free( _titleCommandTable );
	free( _reportCommandTable);
	free( _bugReportCommandTable);
	/*-------------------------*/

	free( _debugCommandTable );
	free( _waypointCommandTable );
	free( _GMTicketCommandTable );
	free( _GameObjectCommandTable );
	free( _BattlegroundCommandTable );
	free( _NPCCommandTable );
	free( _CheatCommandTable );
	free( _accountCommandTable );
	free( _petCommandTable );
	free( _recallCommandTable );
	free( _honorCommandTable );
	free( _GuildCommandTable);
	free( _questCommandTable );
	free( _AHBotCommandTable );
	free( _instanceCommandTable );
	free( _commandTable );
}

void CommandTableStorage::Init()
{
	static ChatCommand modifyCommandTable[] =
	{
		{ "hp",					'b', NULL,										"Health Points/HP",			NULL,	UNIT_FIELD_HEALTH,			UNIT_FIELD_MAXHEALTH,	1 },
		{ "gender",				'a', &ChatHandler::HandleGenderChanger,			"Gender 0=male/1=female.",	NULL,	0, 							0, 						0 },
		{ "mana",				'b', NULL,										"Mana Points/MP",			NULL,	UNIT_FIELD_POWER1,			UNIT_FIELD_MAXPOWER1,	1 },
		{ "rage",				'b', NULL,										"Rage Points",				NULL,	UNIT_FIELD_POWER2,			UNIT_FIELD_MAXPOWER2,	1 },
		{ "energy",				'b', NULL,										"Energy Points",			NULL, 	UNIT_FIELD_POWER4,			UNIT_FIELD_MAXPOWER4,	1 },
		{ "level",	 			'b', &ChatHandler::HandleModifyLevelCommand,	"Level", 					NULL, 	0, 							0, 						0 },
		{ "strength",			'b', NULL,										"Modifies the strength value of the selected target.",	NULL,	UNIT_FIELD_STAT0,			0,		1 },
		{ "agility",			'b', NULL,										"Modifies the agility value of the selected target.",	NULL,	UNIT_FIELD_STAT1,			0,		1 },
		{ "intelligence",		'b', NULL,										"Modifies the intelligence value of the selected target.",NULL, UNIT_FIELD_STAT3,			0,		1 },
		{ "spirit",				'b', NULL,										"Modifies the spirit value of the selected target.",	NULL,	UNIT_FIELD_STAT4,			0,		1 },
		{ "holy",				'b', NULL,										"Modifies the holy resistance of selected target.",		NULL,	UNIT_FIELD_RESISTANCES_01,	0,		1 },
		{ "fire",				'b', NULL,										"Modifies the fire resistance of selected target.",		NULL,	UNIT_FIELD_RESISTANCES_02,	0,		1 },
		{ "nature",				'b', NULL,										"Modifies the nature resistance of selected target.",	NULL,	UNIT_FIELD_RESISTANCES_03,	0,		1 },
		{ "frost",				'b', NULL,										"Modifies the frost resistance of selected target.",	NULL,	UNIT_FIELD_RESISTANCES_04,	0,		1 },
		{ "shadow",				'b', NULL,										"Modifies the shadow resistance of selected target.",	NULL,	UNIT_FIELD_RESISTANCES_05,	0,		1 },
		{ "arcane",				'b', NULL,										"Modifies the arcane resistance of selected target.",	NULL,	UNIT_FIELD_RESISTANCES_06,	0,		1 },
		{ "ap",					'b', NULL,										"Modifies the attack power of the selected target.",	NULL,	UNIT_FIELD_ATTACK_POWER,	0,		1 },
		{ "rangeap",			'b', NULL,										"Modifies the range attack power of the selected target.",NULL,	UNIT_FIELD_RANGED_ATTACK_POWER, 0,	1 },
		{ "damage",	 			'b', NULL,										"Unit Damage Min/Max", 		NULL, 	UNIT_FIELD_MINDAMAGE,  		UNIT_FIELD_MAXDAMAGE,	2 },
		{ "scale",	  			'b', NULL,										"Size/Scale",		  		NULL, 	OBJECT_FIELD_SCALE_X, 		0,						2 },
		{ "gold",	   			'b', &ChatHandler::HandleModifyGoldCommand,		"Gold/Money/Copper",		NULL,	0,  						0,  					0 },
		{ "speed",	  			'b', &ChatHandler::HandleModifySpeedCommand,	"Movement Speed",			NULL,	0,  						0,  					0 },
		{ "nativedisplayid",	'a', NULL,  									"Native Display ID", 		NULL, 	UNIT_FIELD_NATIVEDISPLAYID, 0,			  			1 },
		{ "displayid" , 		'b', NULL,										"Display ID",		  		NULL, 	UNIT_FIELD_DISPLAYID,	   	0,			  			1 },
		{ "flags" ,	 			'b', NULL,										"Unit Flags",		  		NULL, 	UNIT_FIELD_FLAGS,		   	0,			  			1 },
		{ "faction",			'b', NULL,										"Faction Template",			NULL, 	UNIT_FIELD_FACTIONTEMPLATE, 0,						1 },
		{ "dynamicflags",		'b', NULL,										"Dynamic Flags",	   		NULL, 	UNIT_DYNAMIC_FLAGS,		 	0,			  			1 },
		{ "talentpoints",		'a', NULL,										"Talent Points",	   		NULL, 	PLAYER_CHARACTER_POINTS1,   0,			  			1 },
		{ "profpoints",			'a', NULL,										"Profession Points",	   	NULL, 	PLAYER_CHARACTER_POINTS2,   0,			  			1 },
		{ "happiness",			'a', NULL,										"Happiness",				NULL, 	UNIT_FIELD_POWER5,			UNIT_FIELD_MAXPOWER5, 	1 },
		{ "boundingradius",		'a', NULL,  									"Bounding Radius",	 		NULL, 	UNIT_FIELD_BOUNDINGRADIUS,	0,						2 },
		{ "combatreach",		'a', NULL,										"Combat Reach",				NULL, 	UNIT_FIELD_COMBATREACH, 	0, 						2 },
		{ "emotestate",			'a', NULL,										"NPC Emote State",	 		NULL, 	UNIT_NPC_EMOTESTATE, 		0, 						1 },
		{ "bytes",				'a', NULL,  									"Bytes",					NULL,	UNIT_FIELD_BYTES_0,			0,						1 },
		{ "index",				'z', &ChatHandler::HandleSetValue,				"<index> [value]",			NULL,	0,							0,						0 },
		{ NULL,					  0, NULL,										"",							NULL, 	0, 							0  						  }
	};
	dupe_command_table(modifyCommandTable, _modifyCommandTable);

	static ChatCommand warnCommandTable[] =
	{
		{ "add",				'c', &ChatHandler::HandleWarnPlayerCommand,		"Warns a player, Syntax: !warn add <playername> <reason>",						NULL, 0, 0, 0 },
		{ "list",				'1', &ChatHandler::HandleWarnListCommand,		"Warns a player, Syntax: !warn list <playername>",								NULL, 0, 0, 0 },
		{ "clearall",			'a', &ChatHandler::HandleWarnClearCommand,		"Clears warns from a player, Syntax: !warn clear <playername>",					NULL, 0, 0, 0 }, 
		{ "delete",				'a', &ChatHandler::HandleWarnSingleDelCommand,	"Deletes a warn from a player, Syntax: !warn delete <playername> <WarnID>",		NULL, 0, 0, 0 },
		{ NULL,			  		  0, NULL,										"",																				NULL, 0, 0	}
	};
	dupe_command_table(warnCommandTable, _warnCommandTable);

	static ChatCommand titleCommandTable[] =
	{
		{ "addpve",				'a', &ChatHandler::HandleAddPVETitle,			"Adds a PVE title to player. Syntax: !title addpve <entry>",			NULL, 0, 0, 0 },
		{ "addpvp",				'a', &ChatHandler::HandleAddPVPTitle,			"Adds a PVP title to player. Syntax: !title addpvp <entry>",			NULL, 0, 0, 0 },
		{ "removepve",			'a', &ChatHandler::HandleRemovePVETitle,		"Removes a PVE title from a player. Syntax: !title removepve <entry>",	NULL, 0, 0, 0 }, 
		{ "removepvp",			'a', &ChatHandler::HandleRemovePVPTitle,		"Removes a PVP title from a player. Syntax: !title removepvp <entry>",	NULL, 0, 0, 0 }, 
		{ "setpve",				'z', &ChatHandler::HandleKnownPVETitlesCommand,	"<bits>",																NULL, 0, 0,	0 },
		{ "setpvp",				'z', &ChatHandler::HandleKnownPVPTitlesCommand,	"<bits>",																NULL, 0, 0, 0 },
		{ NULL,			  		  0, NULL,										"",																		NULL, 0, 0	}
	};
	dupe_command_table(titleCommandTable, _titleCommandTable);

	static ChatCommand reportCommandTable[] =
	{
		{ "player",				'1', &ChatHandler::HandleReportPlr,					"Report a player, Syntax: !report player <playername> <reason>",	NULL, 0, 0, 0 },
		{ "get",				'c', &ChatHandler::HandlePlrReportsGetCommand,		"Get player reports, Syntax: !report get (<playername>)",			NULL, 0, 0, 0 },
		{ "delete",				'a', &ChatHandler::HandlePlrReportsDeleteCommand,	"Clears reports from a player, Syntax: !report clear <playername>",	NULL, 0, 0, 0 }, 
		{ NULL,					  0, NULL,											"",																	NULL, 0, 0  }
	};
	dupe_command_table(reportCommandTable, _reportCommandTable);

	static ChatCommand bugReportCommandTable[] =
	{
		{ "report",				'1', &ChatHandler::HandleGenerateBugReport,			"Report a bug, Syntax: !bug report <description>",					NULL, 0, 0, 0 },
		{ "list",				'c', &ChatHandler::HandleBugReportsListCommand,		"Get player reported bugs, Syntax: !bug list",						NULL, 0, 0, 0 },
		{ "getId",				'c', &ChatHandler::HandleGetBugReportByIdCommand,	"Clears reports from a player, Syntax: !bug getId <reportId>",		NULL, 0, 0, 0 }, 
		{ NULL,					  0, NULL,											"",																	NULL, 0, 0  }
	};
	dupe_command_table(bugReportCommandTable, _bugReportCommandTable);
	
	static ChatCommand debugCommandTable[] =
	{
		{ "infront",			'b', &ChatHandler::HandleDebugInFrontCommand, 	"",			NULL, 0, 0, 0},
		{ "showreact",  		'b', &ChatHandler::HandleShowReactionCommand, 	"",			NULL, 0, 0, 0},
		{ "aimove",				'b', &ChatHandler::HandleAIMoveCommand,			"",			NULL, 0, 0, 0},
		{ "dist",				'b', &ChatHandler::HandleDistanceCommand,		"",			NULL, 0, 0, 0},
		{ "face",				'b', &ChatHandler::HandleFaceCommand,			"",			NULL, 0, 0, 0},
		{ "moveinfo",			'b', &ChatHandler::HandleMoveInfoCommand,		"",			NULL, 0, 0, 0},
		{ "setbytes",			'b', &ChatHandler::HandleSetBytesCommand,		"",			NULL, 0, 0, 0},
		{ "getbytes",			'b', &ChatHandler::HandleGetBytesCommand,		"",			NULL, 0, 0, 0},
		{ "unroot",				'b', &ChatHandler::HandleDebugUnroot,			"",			NULL, 0, 0, 0},
		{ "root",				'b', &ChatHandler::HandleDebugRoot,				"",			NULL, 0, 0, 0},
		{ "landwalk",			'b', &ChatHandler::HandleDebugLandWalk,			"",			NULL, 0, 0, 0},
		{ "waterwalk",  		'b', &ChatHandler::HandleDebugWaterWalk,		"",			NULL, 0, 0, 0},
		{ "castspellne",		'b', &ChatHandler::HandleCastSpellNECommand,	".castspellne <spellid> - Casts spell on target (only plays animations, doesnt handle effects or range/facing/etc.", NULL, 0, 0, 0 },
		{ "aggrorange", 		'b', &ChatHandler::HandleAggroRangeCommand,		".aggrorange - Shows aggro Range of the selected Creature.", NULL, 0, 0, 0 },
		{ "knockback ", 		'b', &ChatHandler::HandleKnockBackCommand,		".knockback <value> - Knocks you back.", NULL, 0, 0, 0 },
		{ "fade ",				'b', &ChatHandler::HandleFadeCommand,			".fade <value> - calls ModThreatModifyer().", NULL, 0, 0, 0 },
		{ "threatMod ", 		'b', &ChatHandler::HandleThreatModCommand,		".threatMod <value> - calls ModGeneratedThreatModifyer().", NULL, 0, 0, 0 },
		{ "calcThreat ",		'b', &ChatHandler::HandleCalcThreatCommand,		".calcThreat <dmg> <spellId> - calculates threat.", NULL, 0, 0, 0 },
		{ "threatList ",		'b', &ChatHandler::HandleThreatListCommand,		".threatList  - returns all AI_Targets of the selected Creature.", NULL, 0, 0, 0 },
		{ "gettptime",			'b', &ChatHandler::HandleGetTransporterTime,	"grabs transporter travel time",NULL, 0, 0, 0 },
		{ "itempushresult",		'b', &ChatHandler::HandleSendItemPushResult,	"sends item push result", NULL, 0, 0, 0 },
		{ "setbit",	  			'z', &ChatHandler::HandleModifyBitCommand,		"",								NULL, 0, 0, 0},
		{ "setvalue",			'z', &ChatHandler::HandleModifyValueCommand,	"",								NULL, 0, 0, 0},
		{ "aispelltestbegin", 	'b', &ChatHandler::HandleAIAgentDebugBegin,		"", NULL, 0, 0, 0 },
		{ "aispelltestcontinue",'b', &ChatHandler::HandleAIAgentDebugContinue,	"", NULL, 0, 0, 0 },
		{ "aispelltestskip",	'b', &ChatHandler::HandleAIAgentDebugSkip,		"", NULL, 0, 0, 0 },
		{ "dumpcoords",			'b', &ChatHandler::HandleDebugDumpCoordsCommmand,"", NULL, 0, 0, 0 },
		{ "sendpacket",			'b', &ChatHandler::HandleSendpacket,			"<opcode ID>, <data>", NULL, 0, 0, 0 },
		{ "sqlquery",			'b', &ChatHandler::HandleSQLQueryCommand,		"<sql query>", NULL, 0, 0, 0 },
		{ "rangecheck",			'b', &ChatHandler::HandleRangeCheckCommand,		"Checks the 'yard' range and internal range between the player and the target.", NULL, 0, 0, 0 },
		{ "setallratings",		'b', &ChatHandler::HandleRatingsCommand,		"Sets rating values to incremental numbers based on their index.", NULL, 0, 0, 0 },
		{ "reloadscripts",		'z', &ChatHandler::HandleReloadScriptsCommand,			"", NULL, 0, 0, 0 },
		{ NULL,					'0', NULL,										"",								NULL, 0, 0  }
	};
	dupe_command_table(debugCommandTable, _debugCommandTable);

	static ChatCommand waypointCommandTable[] =
	{
		{ "add",				'b', &ChatHandler::HandleWPAddCommand,			"Add wp at current pos",		NULL, 0, 0, 0},
		{ "show",				'b', &ChatHandler::HandleWPShowCommand,			"Show wp's for creature",		NULL, 0, 0, 0},
		{ "hide",				'b', &ChatHandler::HandleWPHideCommand,			"Hide wp's for creature",		NULL, 0, 0, 0},
		{ "delete",				'b', &ChatHandler::HandleWPDeleteCommand,		"Delete selected wp",			NULL, 0, 0, 0},
		{ "movehere",			'b', &ChatHandler::HandleWPMoveHereCommand,		"Move to this wp",				NULL, 0, 0, 0},
		{ "flags",				'b', &ChatHandler::HandleWPFlagsCommand,		"Wp flags",						NULL, 0, 0, 0},
		{ "waittime",			'b', &ChatHandler::HandleWPWaitCommand,			"Wait time at this wp",			NULL, 0, 0, 0},
		{ "emote",				'b', &ChatHandler::HandleWPEmoteCommand,		"Emote at this wp",				NULL, 0, 0, 0},
		{ "skin",				'b', &ChatHandler::HandleWPSkinCommand,			"Skin at this wp",				NULL, 0, 0, 0},
		{ "change",				'b', &ChatHandler::HandleWPChangeNoCommand,		"Change at this wp",			NULL, 0, 0, 0},
		{ "info",				'b', &ChatHandler::HandleWPInfoCommand,			"Show info for wp",				NULL, 0, 0, 0},
		{ "movetype",			'b', &ChatHandler::HandleWPMoveTypeCommand,		"Movement type at wp",			NULL, 0, 0, 0},
		{ "generate",			'b', &ChatHandler::HandleGenerateWaypoints,		"Randomly generate wps",		NULL, 0, 0, 0},
		{ "save",				'b', &ChatHandler::HandleSaveWaypoints,			"Save all waypoints",			NULL, 0, 0, 0},
		{ "deleteall",			'b', &ChatHandler::HandleDeleteWaypoints,		"Delete all waypoints",			NULL, 0, 0, 0},
		{ "addfly",				'b', &ChatHandler::HandleWaypointAddFlyCommand,	"Adds a flying waypoint",		NULL, 0, 0, 0},
		{ NULL,					  0, NULL,										"",								NULL, 0, 0  }
	};
	dupe_command_table(waypointCommandTable, _waypointCommandTable);

	static ChatCommand GMTicketCommandTable[] =
	{
#ifdef GM_TICKET_MY_MASTER_COMPATIBLE
		{ "get",				'c', &ChatHandler::HandleGMTicketListCommand,				"Gets GM Ticket",					NULL, 0, 0, 0},
		{ "getId",				'c', &ChatHandler::HandleGMTicketGetByIdCommand,			"Gets GM Ticket by ID",				NULL, 0, 0, 0},
		{ "delId",				'c', &ChatHandler::HandleGMTicketRemoveByIdCommand,			"Deletes GM Ticket by ID",			NULL, 0, 0, 0},
#else
		{ "list",				'c', &ChatHandler::HandleGMTicketListCommand,				"Lists all active GM Tickets.",										NULL, 0, 0, 0 },
		{ "get",				'c', &ChatHandler::HandleGMTicketGetByIdCommand,			"Gets GM Ticket with ID x.",										NULL, 0, 0, 0 },
		{ "remove",				'c', &ChatHandler::HandleGMTicketRemoveByIdCommand,			"Removes GM Ticket with ID x.",										NULL, 0, 0, 0 },
		{ "deletepermanent",	'z', &ChatHandler::HandleGMTicketDeletePermanentCommand,	"Deletes GM Ticket with ID x permanently.",							NULL, 0, 0, 0 },
		{ "assign",				'c', &ChatHandler::HandleGMTicketAssignToCommand,			"Assignes GM Ticket with id x to GM y (if empty to your self).",	NULL, 0, 0, 0 },
		{ "release",			'c', &ChatHandler::HandleGMTicketReleaseCommand,			"Releases assigned GM Ticket with ID x.",							NULL, 0, 0, 0 },
		{ "comment",			'c', &ChatHandler::HandleGMTicketCommentCommand,			"Sets comment x to GM Ticket with ID y.",							NULL, 0, 0, 0 },
#endif
		{ "toggle",				'z', &ChatHandler::HandleGMTicketToggleTicketSystemStatusCommand, "Toggles the ticket system status.",							 NULL, 0, 0, 0 },
		{ NULL,					'0', NULL,														"",															  NULL, 0, 0, 0 }
	};
	dupe_command_table(GMTicketCommandTable, _GMTicketCommandTable);

	static ChatCommand GuildCommandTable[] =
	{
//		{ "renameguild", 			'a', &ChatHandler::HandleRenameGuildCommand, "Renames a guild.", NULL, 0, 0, 0 },
		{ "create",				'a', &ChatHandler::CreateGuildCommand,  			"Creates a guild.",								NULL, 0, 0, 0},
		{ "rename",				'a', &ChatHandler::HandleRenameGuildCommand, 		"Renames a guild.",								NULL, 0, 0, 0},
		{ "members",			'a', &ChatHandler::HandleGuildMembersCommand,		"Lists guildmembers and their ranks.",			NULL, 0, 0, 0},
		{ "removeplayer",		'a', &ChatHandler::HandleGuildRemovePlayerCommand,	"Removes a player from a guild.",				NULL, 0, 0, 0},
		{ "disband",			'a', &ChatHandler::HandleGuildDisbandCommand, 		"Disbands the guild of your target.",			NULL, 0, 0, 0},
		{ "makehome",			'a', &ChatHandler::HandleGuildHomeCommand, 			"Creates a home for your guild.",				NULL, 0, 0, 0},
		{ "gotohome",			'a', &ChatHandler::HandleGoToGuildHomeCommand,		"Teleports you to target player's guildhome.",	NULL, 0, 0, 0},
		{ NULL,					  0, NULL,											"",												NULL, 0, 0  }
	};
	dupe_command_table(GuildCommandTable, _GuildCommandTable);

	static ChatCommand GameObjectCommandTable[] =
	{
		{ "select",				'd', &ChatHandler::HandleGOSelect,		"Selects the nearest GameObject to you",						NULL, 0, 0, 0},
		{ "flags",				'd', &ChatHandler::HandleGOFlags,		"Sets the flags of the gameobject",								NULL, 0, 0, 0},
		{ "state",				'd', &ChatHandler::HandleGOState,		"Sets the state of the gameobject",								NULL, 0, 0, 0},
		{ "delete",				'd', &ChatHandler::HandleGODelete,		"Deletes selected GameObject",									NULL, 0, 0, 0},
		{ "spawn",				'd', &ChatHandler::HandleGOSpawn,		"Spawns a GameObject by ID",									NULL, 0, 0, 0},
		{ "info",				'b', &ChatHandler::HandleGOInfo,		"Gives you informations about selected GO", 					NULL, 0, 0, 0},
		{ "activate",			'b', &ChatHandler::HandleGOActivate,	"Activates/Opens the selected GO.",								NULL, 0, 0, 0},
		{ "enable",				'b', &ChatHandler::HandleGOEnable,		"Enables the selected GO for use.",								NULL, 0, 0, 0},
		{ "scale",				'b', &ChatHandler::HandleGOScale,		"Sets scale of selected GO",									NULL, 0, 0, 0},
		{ "animprogress",		'b', &ChatHandler::HandleGOAnimProgress,"Sets anim progress",											NULL, 0, 0, 0},
		{ "export",				'b', &ChatHandler::HandleGOExport,		"Exports the current GO selected",								NULL, 0, 0, 0},
		{ "move",				'b', &ChatHandler::HandleGOMove,		"Moves gameobject to player xyz",								NULL, 0, 0, 0},
		{ "rotate",				'b', &ChatHandler::HandleGORotate,		"<Axis> <Value> - Rotates the object. <Axis> x,y, Default o.",	NULL, 0, 0, 0 },
		{ NULL,					  0, NULL,								"",																NULL, 0, 0   }
	};
	dupe_command_table(GameObjectCommandTable, _GameObjectCommandTable);

	static ChatCommand BattlegroundCommandTable[] = 
	{
		{ "setbgscore",	'e', &ChatHandler::HandleSetBGScoreCommand,					   "<Teamid> <Score> - Sets battleground score. 2 Arguments.",	  NULL, 0, 0, 0 },
		{ "startbg",	   'e', &ChatHandler::HandleStartBGCommand,						  "Starts current battleground match.",							NULL, 0, 0, 0 },
		{ "pausebg",	   'e', &ChatHandler::HandlePauseBGCommand,						  "Pauses current battleground match.",							NULL, 0, 0, 0 },
		{ "bginfo",		'e', &ChatHandler::HandleBGInfoCommnad,						   "Displays information about current battleground.",			  NULL, 0, 0, 0 },
		{ "battleground",  'e', &ChatHandler::HandleBattlegroundCommand,					 "Shows BG Menu",												 NULL, 0, 0, 0 },
		{ "setworldstate", 'e', &ChatHandler::HandleSetWorldStateCommand,					"<var> <val> - Var can be in hex. WS Value.",					NULL, 0, 0, 0 },
		{ "setworldstates",'e', &ChatHandler::HandleSetWorldStatesCommand,					"<var> <val> - Var can be in hex. WS Value.",				   NULL, 0, 0, 0 },
		{ "playsound",	 'e', &ChatHandler::HandlePlaySoundCommand,						"<val>. Val can be in hex.",									 NULL, 0, 0, 0 },
		{ "setbfstatus",   'e', &ChatHandler::HandleSetBattlefieldStatusCommand,			 ".setbfstatus - NYI.",										   NULL, 0, 0, 0 },
		{ "leave",		 'e', &ChatHandler::HandleBattlegroundExitCommand,				 "Leaves the current battleground.",							  NULL, 0, 0, 0 },
		{ "getqueue",	  'z', &ChatHandler::HandleGetBattlegroundQueueCommand,			 "Gets common battleground queue information.",				   NULL, 0, 0, 0 },
		{ "forcestart",	'z', &ChatHandler::HandleInitializeAllQueuedBGsCommand, "Forces initialitation of all battlegrounds with active queue.", NULL, 0, 0, 0 },
		{ NULL,			'0', NULL,														"",															  NULL, 0, 0, 0 }
	};
	dupe_command_table(BattlegroundCommandTable, _BattlegroundCommandTable);

	static ChatCommand NPCCommandTable[] =
	{
		{ "vendoradditem",		'b', &ChatHandler::HandleItemCommand,			"Adds to vendor",				 																											NULL, 0, 0, 0},
		{ "vendorremoveitem",	'b',&ChatHandler::HandleItemRemoveCommand,		"Removes from vendor.",		   																												NULL, 0, 0, 0},
		{ "flags",				'b', &ChatHandler::HandleNPCFlagCommand,		"Changes NPC flags",			  																											NULL, 0, 0, 0},
		{ "emote",				'b', &ChatHandler::HandleEmoteCommand,			".emote - Sets emote state",	  																											NULL, 0, 0, 0},
		{ "delete",				'd', &ChatHandler::HandleDeleteCommand,			"Deletes mob from db and world.", 																											NULL, 0, 0, 0},
		{ "info",				'b', &ChatHandler::HandleNpcInfoCommand,		"Displays NPC information",	   																												NULL, 0, 0, 0},
		{ "addAgent",			'b', &ChatHandler::HandleAddAIAgentCommand,		".npc addAgent <agent> <procEvent> <procChance> <procCount> <spellId> <spellType> <spelltargetType> <spellCooldown> <floatMisc1> <Misc2>",	NULL, 0, 0, 0},
		{ "listAgent",			'b', &ChatHandler::HandleListAIAgentCommand,	".npc listAgent",																															NULL, 0, 0, 0},
		{ "say",				'b', &ChatHandler::HandleMonsterSayCommand,		".npc say <text> - Makes selected mob say text <text>.", 																					NULL, 0, 0, 0},
		{ "yell",				'b', &ChatHandler::HandleMonsterYellCommand,	".npc yell <Text> - Makes selected mob yell text <text>.", 																					NULL, 0, 0, 0},
		{ "come",				'b', &ChatHandler::HandleNpcComeCommand,		".npc come - Makes npc move to your position", 																								NULL, 0, 0, 0},
		{ "return",				'b', &ChatHandler::HandleNpcReturnCommand,		".npc return - Returns ncp to spawnpoint.", 																								NULL, 0, 0, 0},
		{ "spawn",				'd', &ChatHandler::HandleCreatureSpawnCommand,	".npc spawn - Spawns npc of entry <id>", 																									NULL, 0, 0, 0},
		{ "respawn",			'b', &ChatHandler::HandleCreatureRespawnCommand,".respawn - Respawns a dead npc from it's corpse.",																							NULL, 0, 0, 0 },
		{ "spawnlink",			'b', &ChatHandler::HandleNpcSpawnLinkCommand,	".spawnlink sqlentry", 																														NULL, 0, 0, 0},
		{ "possess",			'b', &ChatHandler::HandleNpcPossessCommand,		".npc possess - Possess an npc (mind control)", 																							NULL, 0, 0, 0},
		{ "unpossess",			'b', &ChatHandler::HandleNpcUnPossessCommand,	".npc unpossess - Unposses any currently possessed npc.", 																					NULL, 0, 0, 0},
		{ "standstate",			'b', &ChatHandler::HandleNPCStandStateCommand,	".npc standstate - Sets creature standstate.", 																								NULL, 0, 0, 0},
		{ "select",				'b', &ChatHandler::HandleNpcSelectCommand,		".npc select - selects npc closest", 																										NULL, 0, 0, 0},
		{ "bytes2",				'b', &ChatHandler::HandleNPCBytes2Command,		".npc bytes2 - sets the bytes2 field", 																										NULL, 0, 0, 0},
		{ NULL,					'2', NULL,										"",								   																											NULL, 0, 0   }
	};
	dupe_command_table(NPCCommandTable, _NPCCommandTable);

	static ChatCommand CheatCommandTable[] =
	{
		{ "status",				'm', &ChatHandler::HandleShowCheatsCommand, 		"Shows active cheats.",								NULL, 0, 0, 0 },
		{ "taxi",				'b', &ChatHandler::HandleTaxiCheatCommand,	 		"Enables all taxi nodes.",							NULL, 0, 0, 0 },
		{ "cooldown",   		'b', &ChatHandler::HandleCooldownCheatCommand, 		"Enables no cooldown cheat.",						NULL, 0, 0, 0 },
		{ "casttime",   		'b', &ChatHandler::HandleCastTimeCheatCommand, 		"Enables no cast time cheat.",						NULL, 0, 0, 0 },
		{ "power",				'd', &ChatHandler::HandlePowerCheatCommand, 		"Disables mana consumption etc.",					NULL, 0, 0, 0 },
		{ "god",				'd', &ChatHandler::HandleGodModeCommand, 			"Sets god mode, prevents you from taking damage.",	NULL, 0, 0, 0 },
		{ "fly",				'm', &ChatHandler::HandleFlyCommand, 				"Sets fly mode",									NULL, 0, 0, 0 },
		{ "land",				'm', &ChatHandler::HandleLandCommand, 				"Unsets fly mode",									NULL, 0, 0, 0 },
		{ "explore",			'b', &ChatHandler::HandleExploreCheatCommand, 		"Reveals the unexplored parts of the map.",			NULL, 0, 0, 0 },
		{ "flyspeed",			'm', &ChatHandler::HandleFlySpeedCheatCommand,		"Modifies fly speed.",								NULL, 0, 0, 0 },
		{ "stack",				'd', &ChatHandler::HandleStackCheatCommand,			"Enables aura stacking cheat.",						NULL, 0, 0, 0 },
		{ "triggerpass",		'd', &ChatHandler::HandleTriggerpassCheatCommand,	"Ignores area trigger prerequisites.",				NULL, 0, 0, 0 },
		{ "jumptotaxiend",		'z', &ChatHandler::HandleTaxiJumpToEndCommand,		"Jumps to end of taxi path",						NULL, 0, 0, 0 },
		{ NULL,			  		  0, NULL,											"",													NULL, 0, 0, 0 },
	};
	dupe_command_table(CheatCommandTable, _CheatCommandTable);

	static ChatCommand accountCommandTable[] =
	{
		{ "ban",	  			'a', &ChatHandler::HandleAccountBannedCommand,		"Ban account. .account ban name timeperiod",				NULL, 0, 0, 0 },
		{ "unban",	  			'z', &ChatHandler::HandleAccountUnbanCommand,		"Unbans account x.",										NULL, 0, 0, 0 },
		{ "level",	  			'z', &ChatHandler::HandleAccountLevelCommand,		"Sets gm level on account. Arguments: <user> <level>, etc.",NULL, 0, 0, 0 },
		{ "mute",	  			'a', &ChatHandler::HandleAccountMuteCommand,		"Mutes account for <timeperiod>.",							NULL, 0, 0, 0 },
		{ "unmute",	  			'a', &ChatHandler::HandleAccountUnmuteCommand,		"Unmutes account <x>",										NULL, 0, 0, 0 },
		{ "getinfo",  			'a', &ChatHandler::HandleGetAccountCommand,			"Gets account info of <character>.",						NULL, 0, 0, 0 },
		{ "reload",				'z', &ChatHandler::HandleReloadAccounts,			"reloads accounts.",										NULL, 0, 0, 0 },
		{ NULL, 				  0, NULL, 											"", 														NULL, 0, 0, 0 },
	};
	dupe_command_table(accountCommandTable, _accountCommandTable);

	static ChatCommand AHBotCommandTable[] =
	{
		{ "auto",		'z', &ChatHandler::HandleAHBotAutoCommand,		"Executes the automatic startup sequence",			NULL, 0, 0, 0},
		{ "clear",		'z', &ChatHandler::HandleAHBotClearCommand,		"Clears all the auctions from all auction houses",	NULL, 0, 0, 0},
		{ "config",		'z', &ChatHandler::HandleAHBotConfigCommand,	"Displays AHBot configuration information",			NULL, 0, 0, 0},
		{ "count",		'z', &ChatHandler::HandleAHBotCountCommand,		"Counts the number of auctions",					NULL, 0, 0, 0},
		{ "list",		'z', &ChatHandler::HandleAHBotListCommand,		"Lists the Auction Houses with their ids",			NULL, 0, 0, 0},
		{ "loglevel",	'z', &ChatHandler::HandleAHBotLogLevelCommand,	"Change the AHBot log level",						NULL, 0, 0, 0},
		{ "load",		'z', &ChatHandler::HandleAHBotLoadCommand,		"Loads the Auction House with x items",				NULL, 0, 0, 0},
		{ "reload",		'z', &ChatHandler::HandleAHBotReloadCommand,	"Re-loads all auction houses from SQL",				NULL, 0, 0, 0},
		{ "preload",	'z', &ChatHandler::HandleAHBotPreLoadCommand,	"Loads the Auction House from the AHBotItems table",	NULL, 0, 0, 0},
		{ "refresh",	'z', &ChatHandler::HandleAHBotRefreshCommand,	"Loads the Auction House from the AHBotItems table",	NULL, 0, 0, 0},
		{ "time",		'z', &ChatHandler::HandleAHBotTimeCommand,		"Display the current UNIXTIME used to calc expire",	NULL, 0, 0, 0},
		{ "unload",		'z', &ChatHandler::HandleAHBotUnloadCommand,	"Unloads auto-loaded items from the Auction House",	NULL, 0, 0, 0},

		{ NULL, 0, NULL, "", NULL, 0, 0, 0},
	};
	dupe_command_table(AHBotCommandTable, _AHBotCommandTable);

	static ChatCommand honorCommandTable[] =
	{
		{ "addpoints",			'a', &ChatHandler::HandleAddHonorCommand,					"Adds x amount of honor points/currency",					NULL, 0, 0, 0 },
		{ "addkills",			'a', &ChatHandler::HandleAddKillCommand,					"Adds x amount of honor kills",								NULL, 0, 0, 0 },
		{ "globaldailyupdate",	'a', &ChatHandler::HandleGlobalHonorDailyMaintenanceCommand,"Daily honor field moves",									NULL, 0, 0, 0 },
		{ "singledailyupdate",	'a', &ChatHandler::HandleNextDayCommand,					"Daily honor field moves for selected player only",			NULL, 0, 0, 0 },
		{ "pvpcredit",			'a', &ChatHandler::HandlePVPCreditCommand,					"Sends PVP credit packet, with specified rank and points",	NULL, 0, 0, 0 },
		{ NULL,					  0, NULL,													"",															NULL, 0, 0, 0 },
	};
	dupe_command_table(honorCommandTable, _honorCommandTable);

	static ChatCommand petCommandTable[] = 
	{
		{ "createpet",			'a', &ChatHandler::HandleCreatePetCommand,			"Creates a pet with <entry>.",	NULL, 0, 0, 0 },
		{ "renamepet",			'a', &ChatHandler::HandleRenamePetCommand,			"Renames a pet to <name>.",		NULL, 0, 0, 0 },
		{ "addspell",			'a', &ChatHandler::HandleAddPetSpellCommand,		"Teaches pet <spell>.",			NULL, 0, 0, 0 },
		{ "removespell",		'a', &ChatHandler::HandleRemovePetSpellCommand,		"Removes pet spell <spell>.",	NULL, 0, 0, 0 },
#ifdef USE_SPECIFIC_AIAGENTS
		{ "spawnbot",			'a', &ChatHandler::HandlePetSpawnAIBot,				".pet spawnbot <type> - spawn a helper bot for your aid", NULL, 0, 0, 0 },
#endif
		{ NULL,					  0, NULL,											"",								NULL, 0, 0, 0 },
	};
	dupe_command_table(petCommandTable, _petCommandTable);

	static ChatCommand recallCommandTable[] =
	{
		{ "list",				'2', &ChatHandler::HandleRecallListCommand,			"List recall locations",			NULL, 0, 0, 0},
//		{ "gm_list",			'd', &ChatHandler::HandleRecall_GMListCommand,		"List recall locations",			NULL, 0, 0, 0},
		{ "gm_add",				'd', &ChatHandler::HandleRecallGMOnlyAddCommand,	"Add recall location for GMs Only",	NULL, 0, 0, 0},
		{ "port",				'2', &ChatHandler::HandleRecallGoCommand,			"Port to recalled location",		NULL, 0, 0, 0},
		{ "add",				'a', &ChatHandler::HandleRecallAddCommand,			"Add recall location",				NULL, 0, 0, 0},
		{ "del",				'a', &ChatHandler::HandleRecallDelCommand,			"Remove a recall location",			NULL, 0, 0, 0},
		{ "portplayer", 		'a', &ChatHandler::HandleRecallPortPlayerCommand,	"recall ports player",				NULL, 0, 0, 0 },
		{ NULL,					  0, NULL,											"",									NULL, 0, 0, 0},
	};
	dupe_command_table(recallCommandTable, _recallCommandTable);

	static ChatCommand questCommandTable[] =
	{
		{ "addboth",   		'b', &ChatHandler::HandleQuestAddBothCommand,	"Add quest <id> to the targeted NPC as start & finish",	NULL, 0, 0, 0},
		{ "addfinish", 		'b', &ChatHandler::HandleQuestAddFinishCommand,	"Add quest <id> to the targeted NPC as finisher",		NULL, 0, 0, 0},
		{ "addstart",  		'b', &ChatHandler::HandleQuestAddStartCommand,	"Add quest <id> to the targeted NPC as starter",		NULL, 0, 0, 0},
		{ "delboth",   		'b', &ChatHandler::HandleQuestDelBothCommand,	"Delete quest <id> from the targeted NPC as start & finish",	NULL, 0, 0, 0},
		{ "delfinish", 		'b', &ChatHandler::HandleQuestDelFinishCommand,	"Delete quest <id> from the targeted NPC as finisher",	NULL, 0, 0, 0},
		{ "delstart",  		'b', &ChatHandler::HandleQuestDelStartCommand,	"Delete quest <id> from the targeted NPC as starter",	NULL, 0, 0, 0},
		{ "complete",  		'b', &ChatHandler::HandleQuestFinishCommand,	"Complete/Finish quest <id>",							NULL, 0, 0, 0},
		{ "finisher",  		'd', &ChatHandler::HandleQuestFinisherCommand,	"Lookup quest finisher for quest <id>",					NULL, 0, 0, 0},
		{ "item",	   		'b', &ChatHandler::HandleQuestItemCommand,		"Lookup itemid necessary for quest <id>",				NULL, 0, 0, 0},
		{ "list",	   		'd', &ChatHandler::HandleQuestListCommand,		"Lists the quests for the npc <id>",					NULL, 0, 0, 0},
		{ "load",	   		'b', &ChatHandler::HandleQuestLoadCommand,		"Loads quests from database",							NULL, 0, 0, 0},
		{ "lookup",	   		'b', &ChatHandler::HandleQuestLookupCommand,	"Looks up quest string x",								NULL, 0, 0, 0},
		{ "giver",	   		'd', &ChatHandler::HandleQuestGiverCommand,		"Lookup quest giver for quest <id>",					NULL, 0, 0, 0},
		{ "remove",	   		'b', &ChatHandler::HandleQuestRemoveCommand,	"Removes the quest <id> from the targeted player",		NULL, 0, 0, 0},
		{ "reward",	   		'd', &ChatHandler::HandleQuestRewardCommand,	"Shows reward for quest <id>",							NULL, 0, 0, 0},
		{ "status",	   		'b', &ChatHandler::HandleQuestStatusCommand,	"Lists the status of quest <id>",						NULL, 0, 0, 0},
		{ "spawn",	   		'd', &ChatHandler::HandleQuestSpawnCommand,		"Port to spawn location for quest <id>",				NULL, 0, 0, 0},
		{ "start",	   		'b', &ChatHandler::HandleQuestStartCommand,		"Starts quest <id>",									NULL, 0, 0, 0},
		{ NULL,				  0, NULL,										"",														NULL, 0, 0, 0},
	};
	dupe_command_table(questCommandTable, _questCommandTable);

	static ChatCommand commandTable[] = 
	{
		{ "lookupitem",				'd', &ChatHandler::HandleLookupItemCommand, 		"Looks up item string x.",	NULL, 0, 0, 0 },
		{ "lookupcreature", 		'd', &ChatHandler::HandleLookupCreatureCommand, 	"Looks up item string x.",	NULL, 0, 0, 0 },
		{ "lookupfaction",			'd', &ChatHandler::HandleLookupFactionCommand,		"Looks up faction string x.", NULL, 0, 0, 0 },
		{ "lookupquest",			'd', &ChatHandler::HandleQuestLookupCommand, 		"Looks up quest string x.", NULL, 0, 0, 0 },
		{ "lookupskill",			'd', &ChatHandler::HandleLookupSkillCommand,		"Looks up skill string x.", NULL, 0, 0, 0 },
		{ "lookupspell",			'd', &ChatHandler::HandleLookupSpellCommand, 		"Looks up spell string x.", NULL, 0, 0, 0 },
		{ "lookupobject",			'd', &ChatHandler::HandleLookupObjectCommand,		"Looks up gameobject string x.", NULL, 0, 0, 0 },
		{ "rename",					'a', &ChatHandler::HandleRenameCommand, 			"Renames character x to y.", NULL, 0, 0, 0 },
		{ "forcerename",			'a', &ChatHandler::HandleForceRenameCommand, 		"Forces character x to rename his char next login", NULL, 0, 0, 0 },
		{ "summon",					'd', &ChatHandler::HandleSummonCommand,				"Summons x to your position",	 NULL, 0, 0, 0},
		{ "showskill",				'1', &ChatHandler::HandleGetSkillCommand,			"Syntax: showskill <skillname> (bows, guns, crossbows, internal)",	NULL, 0, 0, 0},
		{ "getstanding",			'a', &ChatHandler::HandleGetStandingCommand, 		"Gets standing of faction %u.", NULL, 0, 0, 0 },
		{ "setstanding",			'a', &ChatHandler::HandleSetStandingCommand, 		"Sets stanging of faction %u.", NULL, 0, 0, 0 },
		{ "lockchar",				'a', &ChatHandler::HandleBanCharacterCommand,		"Bans character x with or without reason",			  NULL, 0, 0, 0},
		{ "unlockchar", 			'a', &ChatHandler::HandleUnBanCharacterCommand,		"Unbans character x",			 NULL, 0, 0, 0},
		{ "resetreputation",		'b', &ChatHandler::HandleResetReputationCommand, 	".resetreputation - Resets reputation to start levels. (use on characters that were made before reputation fixes.)", NULL, 0, 0, 0},
		{ "resetspells", 			'a', &ChatHandler::HandleResetSpellsCommand,   		".resetspells - Resets all spells to starting spells of targeted player. DANGEROUS.", NULL, 0, 0, 0 },
		{ "resettalents",			'a', &ChatHandler::HandleResetTalentsCommand,  		".resettalents - Resets all talents of targeted player to that of their current level. DANGEROUS.", NULL, 0, 0, 0 },
		{ "resetskills", 			'a', &ChatHandler::HandleResetSkillsCommand ,  		".resetskills - Resets all skills.", NULL, 0, 0, 0 },
		{ "resetalltalents",		'z', &ChatHandler::HandleResetAllTalents ,  		".resetalltalents - Resets all online players talents.", NULL, 0, 0, 0 },
		{ "levelup",				'a', &ChatHandler::HandleLevelUpCommand,			"Levelup <x> lvls",				   NULL, 0, 0, 0},
		{ "removeitem", 			'b', &ChatHandler::HandleRemoveItemCommand,			"Removes item %u count %u.", NULL, 0, 0, 0 },
		{ "unstuck",				'a', &ChatHandler::HandleUnStuckCommand, 			"Unstucks a Player.", NULL, 0, 0, 0 },
		{ "showitems",				'a', &ChatHandler::HandleShowItems, 				"Shows items of selected Player", NULL, 0, 0, 0 },
		{ "showskills",				'a', &ChatHandler::HandleShowSkills, 				"Shows skills of selecter Player", NULL, 0, 0, 0 },
		{ "removesickness",			'b', &ChatHandler::HandleRemoveRessurectionSickessAuraCommand,   "Removes ressurrection sickness from the target",  NULL, 0, 0, 0},
		{ "getskilllevel", 			'a', &ChatHandler::HandleGetSkillLevelCommand, 		"Gets the current level of a skill",NULL,0,0,0}, //DGM (maybe add to playerinfo?)
		{ "getskillinfo",			'a', &ChatHandler::HandleGetSkillsInfoCommand, 		"Gets all the skills from a player",NULL,0,0,0},
		{ "charinfo",				'a', &ChatHandler::HandleExtendedCharInfoCommand,	"Shows character info.",		NULL, 0, 0, 0},
		{ "learn",	   				'b', &ChatHandler::HandleLearnCommand,		 		"Learns spell",				   NULL, 0, 0, 0},
		{ "unlearn",	 			'b', &ChatHandler::HandleUnlearnCommand,	   		"Unlearns spell",				 NULL, 0, 0, 0},
		{ "learnskill",  			'b', &ChatHandler::HandleLearnSkillCommand,			".learnskill <skillid> (optional) <value> <maxvalue> - Learns skill id skillid.", NULL, 0, 0, 0},
		{ "advanceskill",			'b', &ChatHandler::HandleModifySkillCommand,   		"advanceskill <skillid> <amount, optional, default = 1> - Advances skill line x times..", NULL, 0, 0, 0},
		{ "removeskill", 			'b', &ChatHandler::HandleRemoveSkillCommand,   		".removeskill <skillid> - Removes skill",		 NULL, 0, 0, 0 },
		{ "increaseweaponskill",	'a', &ChatHandler::HandleIncreaseWeaponSkill, 		".increaseweaponskill <count> - Increase eqipped weapon skill x times (defaults to 1).", NULL, 0, 0, 0},
		{ "kill",					'd', &ChatHandler::HandleKillCommand,		  		".kill - Kills selected unit.",   NULL, 0, 0, 0},
		{ "killplr",   				'a', &ChatHandler::HandleKillByPlrCommand,		 	".kill <name> - Kills specified player", NULL , 0 , 0 , 0 },
		{ "advanceallskills",		'a', &ChatHandler::HandleAdvanceAllSkillsCommand,	"Advances all skills <x> points.", NULL, 0, 0, 0 },
		{ "repairitems",			'a', &ChatHandler::HandleRepairItemsCommand,		".repairitems - Repair all items from selected player",															  NULL, 0, 0, 0 },
		{ "additem",				'b', &ChatHandler::HandleAddInvItemCommand,			"",							   NULL, 0, 0, 0},
		{ "additemset",				'a', &ChatHandler::HandleAddItemSetCommand,			"Adds item set to inv.",		  NULL, 0, 0, 0 },
		{ "masssummon", 			'z', &ChatHandler::HandleMassSummonCommand,			".masssummon - Summons all players.", NULL, 0, 0, 0},
		{ "commands",				'1', &ChatHandler::HandleCommandsCommand,			"Shows Commands",				 NULL, 0, 0, 0},
		{ "help",					'1', &ChatHandler::HandleHelpCommand,				"Shows help for command",		 NULL, 0, 0, 0},
		{ "announce",				'd', &ChatHandler::HandleAnnounceCommand,			"Sends Msg To All",			   NULL, 0, 0, 0},
		{ "wannounce",  			'a', &ChatHandler::HandleWAnnounceCommand,			"Sends Widescreen Msg To All",	NULL, 0, 0, 0},
		{ "appear",					'd', &ChatHandler::HandleAppearCommand,				"Teleports to x's position.",	 NULL, 0, 0, 0},
		{ "kick",					'c', &ChatHandler::HandleKickCommand,		  		"Kicks player from server",	   NULL, 0, 0, 0},
		{ "revive",					'd', &ChatHandler::HandleReviveCommand,				"Revives you.",				   NULL, 0, 0, 0},
		{ "reviveplr",  			'd', &ChatHandler::HandleReviveStringcommand,  		".revive <name> - Revives specified player.",	  NULL, 0, 0, 0},
		{ "demorph",				'd', &ChatHandler::HandleDeMorphCommand,			"Demorphs from morphed model.",   NULL, 0, 0, 0},
		{ "mount",					'b', &ChatHandler::HandleMountCommand,		 		"Mounts into modelid x.",		 NULL, 0, 0, 0},
		{ "dismount",				'b', &ChatHandler::HandleDismountCommand,	  		"Dismounts.",					 NULL, 0, 0, 0},
		{ "gm",						'1', &ChatHandler::HandleGMListCommand,				"Shows active GM's",			  NULL, 0, 0, 0},
		{ "sendtogm",				'd', &ChatHandler::HandleGMAnnounceCommand, 		"Sends Msg to all online GMs", NULL, 0, 0, 0},
		{ "vip",					'a', &ChatHandler::HandleVIPListCommand,			"Shows active VIP's",			  NULL, 0, 0, 0},
		{ "gmoff",					'd', &ChatHandler::HandleGMOffCommand,		 		"Sets GM tag off",				NULL, 0, 0, 0},
		{ "gmon",					'd', &ChatHandler::HandleGMOnCommand,		 		"Sets GM tag on",				 NULL, 0, 0, 0},
		{ "ctag",					'2', &ChatHandler::HandleChatTagCommand,			"Sets Chat tag on",				 NULL, 0, 0, 0},
		{ "gps",					'1', &ChatHandler::HandleGPSCommand,		   		"Shows Position",				 NULL, 0, 0, 0},
		{ "info",					'1', &ChatHandler::HandleInfoCommand,		  		"Server info",					NULL, 0, 0, 0},
		{ "worldport",  			'd', &ChatHandler::HandleWorldPortCommand,	 		"",							   NULL, 0, 0, 0},
		{ "save",					'1', &ChatHandler::HandleSaveCommand,		  		"Save's your character",		  NULL, 0, 0, 0},
		{ "saveall",				'a', &ChatHandler::HandleSaveAllCommand,	   		"Save's all playing characters",  NULL, 0, 0, 0},
		{ "sannounce",				'a', &ChatHandler::HandleServerAnnounceCommand,		"Announce with the [SERVER] tag instead of your name",	NULL, 0, 0, 0},
		{ "start",					'1', &ChatHandler::HandleStartCommand,		 		"Teleport's you to a starting location",							   NULL, 0, 0, 0},
		{ "invincible", 			'd', &ChatHandler::HandleInvincibleCommand,			".invincible - Toggles INVINCIBILITY (mobs won't attack you)", NULL, 0, 0, 0},
		{ "invisible",  			'd', &ChatHandler::HandleInvisibleCommand,	 		".invisible - Toggles INVINCIBILITY and INVISIBILITY (mobs won't attack you and nobody can see you, but they can see your chat messages)", NULL, 0, 0, 0},
		{ "playerinfo",				'a', &ChatHandler::HandlePlayerInfo,		   		".playerinfo - Displays informations about the selected character (account...)", NULL, 0, 0, 0 },
		{ "addaura",				'z', &ChatHandler::HandleAddAuraCommand,			".addaura <spell> <duration>",		NULL, 0, 0, 0},
		{ "removeaura", 			'z', &ChatHandler::HandleRemoveAuraCommand,			".removeaura <spell>",				NULL, 0, 0, 0},

		{ "account",				'a', NULL,											"",				accountCommandTable,	0, 0, 0},
		{ "ahbot",					'z', NULL,											"",				AHBotCommandTable,		0, 0, 0},
		{ "battleground",			'a', NULL,									 		"",				BattlegroundCommandTable, 0, 0, 0},
		{ "bug",					'1', NULL,											"",				bugReportCommandTable,	0, 0, 0},
		{ "cheat",					'm', NULL,									 		"",				CheatCommandTable,		0, 0, 0},
		{ "debug",					'b', NULL,									 		"",				debugCommandTable,		0, 0, 0},
		{ "gmTicket",				'a', NULL,									 		"",				GMTicketCommandTable,	0, 0, 0},
		{ "gobject",				'd', NULL,									 		"",				GameObjectCommandTable,	0, 0, 0},
		{ "guild",					'a', NULL,									 		"",				GuildCommandTable,		0, 0, 0},
		{ "honor",					'a', NULL,									 		"",				honorCommandTable,		0, 0, 0},
		{ "modify",					'm', NULL,									 		"",				modifyCommandTable,		0, 0, 0},
		{ "npc",					'd', NULL,									 		"",				NPCCommandTable,		0, 0, 0},
		{ "pet",					'a', NULL,											"",				petCommandTable,		0, 0, 0},
		{ "quest",					'd', NULL,											"",				questCommandTable,		0, 0, 0},
		{ "recall",					'2', NULL,									 		"",				recallCommandTable,		0, 0, 0},
		{ "report",					'1', NULL,									 		"",				reportCommandTable,		0, 0, 0},
		{ "title",					'a', NULL,									 		"",				titleCommandTable,		0, 0, 0},
		{ "waypoint",				'a', NULL,									 		"",				waypointCommandTable,	0, 0, 0},
		{ "warn",					'1', NULL,									 		"",				warnCommandTable,		0, 0, 0},

		{ "getpos"	  ,				'b', &ChatHandler::HandleGetPosCommand,				"",							   NULL, 0, 0, 0},
		{ "clearcooldowns", 		'a', &ChatHandler::HandleClearCooldownsCommand,		"Clears all cooldowns for your class.", NULL, 0, 0, 0 },
		{ "removeauras",			'a', &ChatHandler::HandleRemoveAurasCommand,		"Removes all auras from target",  NULL, 0, 0, 0},
		{ "paralyze",				'b', &ChatHandler::HandleParalyzeCommand,			"Roots/Paralyzes the target.",	NULL, 0, 0, 0 },
		{ "unparalyze",				'b', &ChatHandler::HandleUnParalyzeCommand,			"Unroots/Unparalyzes the target.",NULL, 0, 0, 0 },
		{ "setmotd",				'z', &ChatHandler::HandleSetMotdCommand,			"Sets MOTD",					  NULL, 0, 0, 0 },
		{ "gotrig",					'b', &ChatHandler::HandleTriggerCommand,			"Warps to areatrigger <id>",	  NULL, 0, 0, 0 },
		{ "reloadtable",			'a', &ChatHandler::HandleDBReloadCommand,			"Reloads some of the database tables", NULL, 0, 0, 0 },
		{ "servershutdown", 		'z', &ChatHandler::HandleShutdownCommand,			"Initiates server shutdown in <x> seconds.", NULL, 0, 0, 0 },
		{ "serverrestart",			'z', &ChatHandler::HandleShutdownRestartCommand,	"Initiates server restart in <x> seconds.", NULL, 0, 0, 0 },
		{ "allowwhispers",			'b', &ChatHandler::HandleAllowWhispersCommand,		"Allows whispers from player <s> while in gmon mode.", NULL, 0, 0, 0 },
		{ "blockwhispers",			'b', &ChatHandler::HandleBlockWhispersCommand,		"Blocks whispers from player <s> while in gmon mode.", NULL, 0, 0, 0 },
		{ "killbyplayer",			'a', &ChatHandler::HandleKillByPlayerCommand,		"Disconnects the player with name <s>.", NULL, 0, 0, 0 },
		{ "killbyaccount",			'a', &ChatHandler::HandleKillBySessionCommand,		"Disconnects the session with account name <s>.", NULL, 0, 0, 0 },
		{ "killbyip",				'a', &ChatHandler::HandleKillByIPCommand,			"Disconnects the session with the ip <s>.", NULL, 0, 0, 0 },
		{ "castall",				'z', &ChatHandler::HandleCastAllCommand,			"Makes all players online cast spell <x>.", NULL, 0, 0, 0},
		{ "dispelall",				'z', &ChatHandler::HandleDispelAllCommand,			"Dispels all negative (or positive w/ 1) auras on all players.",NULL,0,0,0},
		{ "castspell",				'b', &ChatHandler::HandleCastSpellCommand,			".castspell <spellid> - Casts spell on target.",  NULL, 0, 0, 0 },
		{ "modperiod" ,				'a', &ChatHandler::HandleModPeriodCommand,			"Changes period of current transporter.", NULL, 0, 0, 0 },
		{ "npcfollow",				'a', &ChatHandler::HandleNpcFollowCommand,			"Sets npc to follow you", NULL, 0, 0, 0 },
		{ "nullfollow",				'a', &ChatHandler::HandleNullFollowCommand,			"Sets npc to not follow anything", NULL, 0, 0, 0 },
		{ "formationlink1", 		'a', &ChatHandler::HandleFormationLink1Command,		"Sets formation master.", NULL, 0, 0, 0 },
		{ "formationlink2", 		'a', &ChatHandler::HandleFormationLink2Command,		"Sets formation slave with distance and angle", NULL, 0, 0, 0 },
		{ "formationclear", 		'a', &ChatHandler::HandleFormationClearCommand,		"Removes formation from creature", NULL, 0, 0, 0 },
		{ "playall",				'a', &ChatHandler::HandleGlobalPlaySoundCommand,	"Plays a sound to the entire server.", NULL, 0, 0, 0 },
		{ "playsound",				'1', &ChatHandler::HandlePlaySoundCommand2, 		"Plays sound to the player.", NULL, 0, 0 ,0 },
		{ "addipban",				'a', &ChatHandler::HandleIPBanCommand, 				"Adds an address to the IP ban table: <address> [duration]\nDuration must be a number optionally followed by a character representing the calendar subdivision to use (h>hours, d>days, w>weeks, m>months, y>years, default minutes)\nLack of duration results in a permanent ban.", NULL, 0, 0, 0 },
		{ "delipban",				'a', &ChatHandler::HandleIPUnBanCommand, 			"Deletes an address from the IP ban table: <address>", NULL, 0, 0, 0},
		{ "rehash",					'z', &ChatHandler::HandleRehashCommand, 			"Reloads config file.", NULL, 0, 0, 0 },
		{ "createarenateam",		'a', &ChatHandler::HandleCreateArenaTeamCommands,	"Creates arena team", NULL, 0, 0, 0 },
		{ "whisperblock",			'b', &ChatHandler::HandleWhisperBlockCommand, 		"Blocks like .gmon except without the <GM> tag", NULL, 0, 0, 0 },
		{ "logcomment" ,			'b', &ChatHandler::HandleGmLogCommentCommand, 		"Adds a comment to the GM log for the admins to read." , NULL , 0 , 0 , 0 },
		{ "testlos",				'b', &ChatHandler::HandleCollisionTestLOS,			"tests los",					NULL, 0, 0, 0 },
		{ "testindoor",				'b', &ChatHandler::HandleCollisionTestIndoor,		"tests indoor",					NULL, 0, 0, 0 },
		{ "getheight",				'b', &ChatHandler::HandleCollisionGetHeight,		"Gets height",					NULL, 0, 0, 0 },
		{ "renameallinvalidchars",	'z', &ChatHandler::HandleRenameAllCharacter,		"Renames all invalid character names", NULL, 0,0, 0 },
		{ "fixscale",				'b', &ChatHandler::HandleFixScaleCommand,			"",								NULL, 0, 0, 0 },
		{ "addtrainerspell",		'b', &ChatHandler::HandleAddTrainerSpellCommand,	"",								NULL, 0, 0, 0 },
	
		{ "hover",					'd', &ChatHandler::HandleHoverCommand,				"Turns hover on/off.",			NULL, 0, 0, 0},
		{ "rangemorph",				'z', &ChatHandler::HandleMorphAllInRange,			"Morphs players in range",		NULL, 0, 0, 0},
		{ "rangedemorph",   		'z', &ChatHandler::HandleDeMorphAllInRange,			"Demorphs players in range",	NULL, 0, 0, 0},
		{ "rangecast",				'a', &ChatHandler::HandleRangeBuffCommand,			"Casts a spell within range",	NULL, 0, 0, 0},
		{ "worldbuff",				'a', &ChatHandler::HandleWorldBuffCommand,			"Gives all players online a buff", NULL, 0, 0, 0},
		{ "knockup",				'a', &ChatHandler::HandleKnockUp,					"Knocks you up in the air",		NULL, 0, 0, 0},
		{ "waterwalk",				'd', &ChatHandler::HandleWaterWalkCommand,			"Turns WaterWalk on/off.",		NULL, 0, 0, 0},
		{ "uptime",					'1', &ChatHandler::HandleUptimeCommand,				"Shows server uptime.",			NULL, 0, 0, 0},
		{ "isonline",				'1', &ChatHandler::HandleIsOnlineCommand,			"Is Online Command.",			NULL, 0, 0, 0},
		{ NULL,						  0, NULL,											"",								NULL, 0, 0  }
	};

	static ChatCommand instanceCommandTable[] =
	{
		{ "reset",	'z', &ChatHandler::HandleResetInstanceCommand,	 "Removes instance ID x from target player.",						 NULL, 0, 0, 0 },
		{ "resetall", 'a', &ChatHandler::HandleResetAllInstancesCommand, "Removes all instance IDs from target player.",					  NULL, 0, 0, 0 },
		{ "shutdown", 'z', &ChatHandler::HandleShutdownInstanceCommand,  "Shutdown instance with ID x (default is current instance).",		NULL, 0, 0, 0 },
		//{ "delete",   'z', &ChatHandler::HandleDeleteInstanceCommand,	"Deletes instance with ID x (default is current instance).",		 NULL, 0, 0, 0 },
		{ "info",	 'a', &ChatHandler::HandleGetInstanceInfoCommand,   "Gets info about instance with ID x (default is current instance).", NULL, 0, 0, 0 },
		{ "exit",	 'a', &ChatHandler::HandleExitInstanceCommand,	  "Exits current instance, return to entry point.",					NULL, 0, 0, 0 },
		{ NULL,	   '0', NULL,										 "",																  NULL, 0, 0, 0 }
	};
	dupe_command_table(instanceCommandTable, _instanceCommandTable);
	dupe_command_table(commandTable, _commandTable);

	/* set the correct pointers */
	ChatCommand * p = &_commandTable[0];
	while(p->Name != 0)
	{
		if(p->ChildCommands != 0)
		{
			// Set the correct pointer.
			ChatCommand * np = GetSubCommandTable(p->Name);
			ASSERT(np);
			p->ChildCommands = np;
		}
		++p;
	}
}

ChatHandler::ChatHandler()
{
	new CommandTableStorage;
	CommandTableStorage::getSingleton().Init();
	SkillNameManager = new SkillNameMgr;
}

ChatHandler::~ChatHandler()
{
	CommandTableStorage::getSingleton().Dealloc();
	delete CommandTableStorage::getSingletonPtr();
	delete SkillNameManager;
}

bool ChatHandler::hasStringAbbr(const char* s1, const char* s2)
{
	for(;;)
	{
		if( !*s2 )
			return true;
		else if( !*s1 )
			return false;
		else if( tolower( *s1 ) != tolower( *s2 ) )
			return false;
		s1++; s2++;
	}
}

void ChatHandler::SendMultilineMessage(WorldSession *m_session, const char *str)
{
	char * start = (char*)str, *end;
	for(;;)
	{
		end = strchr(start, '\n');
		if(!end)
			break;

		*end = '\0';
		SystemMessage(m_session, start);
		start = end + 1;
	}
	if(*start != '\0')
		SystemMessage(m_session, start);
}

bool ChatHandler::ExecuteCommandInTable(ChatCommand *table, const char* text, WorldSession *m_session)
{
	std::string cmd = "";

	// get command
	while (*text != ' ' && *text != '\0')
	{
		cmd += *text;
		text++;
	}

	while (*text == ' ') text++; // skip whitespace

	if(!cmd.length())
		return false;

	for(uint32 i = 0; table[i].Name != NULL; i++)
	{
		if(!hasStringAbbr(table[i].Name, cmd.c_str()))
			continue;

		if(table[i].CommandGroup != '0' && !m_session->CanUseCommand(table[i].CommandGroup))
			continue;

		if(table[i].ChildCommands != NULL)
		{
			if(!ExecuteCommandInTable(table[i].ChildCommands, text, m_session))
			{
				if(table[i].Help != "")
					SendMultilineMessage(m_session, table[i].Help.c_str());
				else
				{
					GreenSystemMessage(m_session, "Available Subcommands:");
					for(uint32 k=0; table[i].ChildCommands[k].Name;k++)
					{
						if(table[i].ChildCommands[k].CommandGroup == '0' || (table[i].ChildCommands[k].CommandGroup != '0' && m_session->CanUseCommand(table[i].ChildCommands[k].CommandGroup)))
							BlueSystemMessage(m_session, " %s - %s", table[i].ChildCommands[k].Name, table[i].ChildCommands[k].Help.size() ? table[i].ChildCommands[k].Help.c_str() : "No Help Available");
					}
				}
			}

			return true;
		}
		
		// Check for field-based commands
		if(table[i].Handler == NULL && (table[i].MaxValueField || table[i].NormalValueField))
		{
			bool result = false;
			if(strlen(text) == 0)
			{
				RedSystemMessage(m_session, "No values specified.");
			}
			if(table[i].ValueType == 2)
				result = CmdSetFloatField(m_session, table[i].NormalValueField, table[i].MaxValueField, table[i].Name, text);
			else
				result = CmdSetValueField(m_session, table[i].NormalValueField, table[i].MaxValueField, table[i].Name, text);
			if(!result)
				RedSystemMessage(m_session, "Must be in the form of (command) <value>, or, (command) <value> <maxvalue>");
		}
		else
		{
			if(!(this->*(table[i].Handler))(text, m_session))
			{
				if(table[i].Help != "")
					SendMultilineMessage(m_session, table[i].Help.c_str());
				else
				{
					RedSystemMessage(m_session, "Incorrect syntax specified. Try .help %s for the correct syntax.", table[i].Name);
				}
			}
		}

		return true;
	}
	return false;
}

int ChatHandler::ParseCommands(const char* text, WorldSession *session)
{
	if (!session)
		return 0;

	if(!*text)
		return 0;

	if(session->GetPermissionCount() == 0 && sWorld.m_reqGmForCommands)
		return 0;

	if(session->GetPlayer()->GetMapId() == 13 && session->GetPlayer()->RS_getAccess() < RS_PROBEGM )
		return 0;

	if(text[0] != '!' && text[0] != '.') // let's not confuse users
		return 0;

	/* skip '..' :P that pisses me off */
	if(text[1] == '.')
		return 0;

	text++;

	if(!ExecuteCommandInTable(CommandTableStorage::getSingleton().Get(), text, session))
	{
		SystemMessage(session, "There is no such command, or you do not have access to it.");
	}

	return 1;
}

WorldPacket * ChatHandler::FillMessageData( uint32 type, uint32 language, const char *message,uint64 guid , uint8 flag) const
{
	//Packet	structure
	//uint8		type;
	//uint32	language;
	//uint64	guid;
	//uint64	guid;
	//uint32	len_of_text;
	//char		text[];		 // not sure ? i think is null terminated .. not null terminated
	//uint8		afk_state;
	ASSERT(type != CHAT_MSG_CHANNEL);

	//channels are handled in channel handler and so on
	uint32 messageLength = (uint32)strlen((char*)message) + 1;

	WorldPacket *data = new WorldPacket(SMSG_MESSAGECHAT, messageLength + 30);

	*data << (uint8)type;
	*data << language;

	*data << guid;
	*data << uint32(0);

	*data << guid;

	*data << messageLength;
	*data << message;

	*data << uint8(flag);
	return data;
}

WorldPacket* ChatHandler::FillSystemMessageData(const char *message) const
{
	uint32 messageLength = (uint32)strlen((char*)message) + 1;

	WorldPacket * data = new WorldPacket(SMSG_MESSAGECHAT, 30 + messageLength);
	*data << (uint8)CHAT_MSG_SYSTEM;
	*data << (uint32)LANG_UNIVERSAL;
	
	*data << (uint64)0; // Who cares about guid when there's no nickname displayed heh ?
	*data << (uint32)0;
	*data << (uint64)0;

	*data << messageLength;
	*data << message;

	*data << uint8(0);

	return data;
}

Player * ChatHandler::getSelectedChar(WorldSession *m_session, bool showerror)
{
	uint64 guid;
	Player *chr;

	if (m_session == NULL || m_session->GetPlayer() == NULL) return NULL;

	guid = m_session->GetPlayer()->GetSelection();
	
	if (guid == 0)
	{
		if(showerror) 
			GreenSystemMessage(m_session, "Auto-targeting self.");
		chr = m_session->GetPlayer(); // autoselect
	}
	else
		chr = m_session->GetPlayer()->GetMapMgr()->GetPlayer((uint32)guid);
	
	if(chr == NULL)
	{
		if(showerror) 
			RedSystemMessage(m_session, "This command requires that you select a player.");
		return NULL;
	}

	return chr;
}

Creature * ChatHandler::getSelectedCreature(WorldSession *m_session, bool showerror)
{
	uint64 guid;
	Creature *creature = NULL;

	if (m_session == NULL || m_session->GetPlayer() == NULL) return NULL;

	guid = m_session->GetPlayer()->GetSelection();
	if(GET_TYPE_FROM_GUID(guid) == HIGHGUID_TYPE_PET)
		creature = m_session->GetPlayer()->GetMapMgr()->GetPet( GET_LOWGUID_PART(guid) );
	else if(GET_TYPE_FROM_GUID(guid) == HIGHGUID_TYPE_UNIT)
		creature = m_session->GetPlayer()->GetMapMgr()->GetCreature( GET_LOWGUID_PART(guid) );
	
	if(creature != NULL)
		return creature;
	else
	{
		if(showerror) 
			RedSystemMessage(m_session, "This command requires that you select a creature.");
		return NULL;
	}
}

Unit * ChatHandler::getSelectedUnit(WorldSession *m_session, bool showerror)
{
	if(!m_session || !m_session->GetPlayer() )
		return NULL;

	uint64 guid;
	Unit *pU = NULL;

	Player * plr = m_session->GetPlayer();
	guid = m_session->GetPlayer()->GetSelection();
	
	if(plr->GetMapMgr() == NULL)
	{
		sLog.outError("%s (%d): NULL pointer", __FUNCTION__, __LINE__);
		if(showerror) 
			RedSystemMessage(m_session, "An error has occured (Invalid MapMgr).");
		return NULL;
	}
	if(GET_TYPE_FROM_GUID(guid) == HIGHGUID_TYPE_UNIT)
		pU = plr->GetMapMgr()->GetUnit( guid );

	if(pU != NULL)
		return pU;
	else
	{
		if(showerror) 
			RedSystemMessage(m_session, "This command requires that you select a creature.");
		return NULL;
	}
}

void ChatHandler::SystemMessage(WorldSession *m_session, const char* message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024, message,ap);
	WorldPacket * data = FillSystemMessageData(msg1);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::ColorSystemMessage(WorldSession *m_session, const char* colorcode, const char *message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024, message,ap);
	char msg[1024];
	snprintf(msg, 1024, "%s%s|r", colorcode, msg1);
	WorldPacket * data = FillSystemMessageData(msg);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::RedSystemMessage(WorldSession *m_session, const char *message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	char msg[1024];
	snprintf(msg, 1024,"%s%s|r", MSG_COLOR_LIGHTRED/*MSG_COLOR_RED*/, msg1);
	WorldPacket * data = FillSystemMessageData(msg);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::GreenSystemMessage(WorldSession *m_session, const char *message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024, message,ap);
	char msg[1024];
	snprintf(msg, 1024, "%s%s|r", MSG_COLOR_GREEN, msg1);
	WorldPacket * data = FillSystemMessageData(msg);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::BlueSystemMessage(WorldSession *m_session, const char *message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024, message,ap);
	char msg[1024];
	snprintf(msg, 1024,"%s%s|r", MSG_COLOR_LIGHTBLUE, msg1);
	WorldPacket * data = FillSystemMessageData(msg);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::RedSystemMessageToPlr(Player* plr, const char *message, ...)
{
	if( !message || !plr || !plr->GetSession() ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	RedSystemMessage(plr->GetSession(), (const char*)msg1);
}

void ChatHandler::GreenSystemMessageToPlr(Player* plr, const char *message, ...)
{
	if( !message || !plr || !plr->GetSession() ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	GreenSystemMessage(plr->GetSession(), (const char*)msg1);
}

void ChatHandler::BlueSystemMessageToPlr(Player* plr, const char *message, ...)
{
	if( !message || !plr || !plr->GetSession() ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	BlueSystemMessage(plr->GetSession(), (const char*)msg1);
}

void ChatHandler::SystemMessageToPlr(Player *plr, const char* message, ...)
{
	if( !message || !plr || !plr->GetSession() ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	SystemMessage(plr->GetSession(), msg1);
}

bool ChatHandler::CmdSetValueField(WorldSession *m_session, uint32 field, uint32 fieldmax, const char *fieldname, const char *args)
{
	char* pvalue;
	uint32 mv, av;

	if(!args || !m_session) return false;

	pvalue = strtok((char*)args, " ");
	if (!pvalue)
		return false;
	else
		av = atol(pvalue);

	if(fieldmax)
	{
		char* pvaluemax = strtok(NULL, " ");
		if (!pvaluemax)
			return false;
		else
			mv = atol(pvaluemax);
	}
	else
	{
		mv = 0;
	}

	if ( ( av <= 0 || av > mv ) && mv > 0)
	{  
		RedSystemMessage(m_session, "Values are invalid. Value must be < max (if max exists), and both must be > 0.");
		return true;
	}
	if( av < 0 || mv < 0 )
	{  
		RedSystemMessage(m_session, "Values are invalid. Value must be < max (if max exists), and both must be > 0.");
		return true;
	}
	if(fieldmax)
	{
		if(mv < av || mv <= 0)
		{
			RedSystemMessage(m_session, "Values are invalid. Value must be < max (if max exists), and both must be > 0.");
			return true;
		}
	}

	Player *plr = getSelectedChar(m_session, false);
	if(plr)
	{
		sGMLog.writefromsession(m_session, "used modify field value: %s, %u on %s", fieldname, av, plr->GetName());
		if(fieldmax)
		{
			BlueSystemMessage(m_session, "You set the %s of %s to %d/%d.", fieldname, plr->GetName(), av, mv);
			GreenSystemMessageToPlr(plr, "%s set your %s to %d/%d.", m_session->GetPlayer()->GetName(), fieldname, av, mv);
		}
		else
		{
			BlueSystemMessage(m_session, "You set the %s of %s to %d.", fieldname, plr->GetName(), av);
			GreenSystemMessageToPlr(plr, "%s set your %s to %d.", m_session->GetPlayer()->GetName(), fieldname, av);
		}

		if(field == UNIT_FIELD_STAT1) av /= 2;
		if(field == UNIT_FIELD_BASE_HEALTH) 
		{
			plr->SetUInt32Value(UNIT_FIELD_HEALTH, av);
		}

		plr->SetUInt32Value(field, av);

		if(fieldmax) {
			plr->SetUInt32Value(fieldmax, mv);
		}
	}
	else
	{
		Creature *cr = getSelectedCreature(m_session, false);
		if(cr)
		{
			if(!(field < UNIT_END && fieldmax < UNIT_END)) return false;
			std::string creaturename = "Unknown Being";
			if(cr->GetCreatureInfo())
				creaturename = cr->GetCreatureInfo()->Name;
			if(fieldmax)
				BlueSystemMessage(m_session, "Setting %s of %s to %d/%d.", fieldname, creaturename.c_str(), av, mv);
			else
				BlueSystemMessage(m_session, "Setting %s of %s to %d.", fieldname, creaturename.c_str(), av);
			sGMLog.writefromsession(m_session, "used modify field value: [creature]%s, %u on %s", fieldname, av, creaturename.c_str());
			if(field == UNIT_FIELD_STAT1) av /= 2;
			if(field == UNIT_FIELD_BASE_HEALTH) 
				cr->SetUInt32Value(UNIT_FIELD_HEALTH, av);

			switch(field)
			{
			case UNIT_FIELD_FACTIONTEMPLATE:
				{
					if(cr->m_spawn)
						WorldDatabase.Execute("UPDATE creature_spawns SET faction = %u WHERE entry = %u", av, cr->m_spawn->entry);
				}break;
			case UNIT_NPC_FLAGS:
				{
					if(cr->GetProto())
						WorldDatabase.Execute("UPDATE creature_proto SET npcflags = %u WHERE entry = %u", av, cr->GetProto()->Id);
				}break;
			}

			cr->SetUInt32Value(field, av);

			if(fieldmax) {
				cr->SetUInt32Value(fieldmax, mv);
			}
			// reset faction
			if(field == UNIT_FIELD_FACTIONTEMPLATE)
				cr->_setFaction();

			cr->SaveToDB();
		}
		else
		{
			RedSystemMessage(m_session, "Invalid Selection.");
		}
	}
	return true;
}

bool ChatHandler::CmdSetFloatField(WorldSession *m_session, uint32 field, uint32 fieldmax, const char *fieldname, const char *args)
{
	char* pvalue;
	float mv, av;

	if(!args || !m_session) return false;

	pvalue = strtok((char*)args, " ");
	if (!pvalue)
		return false;
	else
		av = (float)atof(pvalue);

	if(fieldmax)
	{
		char* pvaluemax = strtok(NULL, " ");
		if (!pvaluemax)
			return false;
		else
			mv = (float)atof(pvaluemax);
	}
	else
	{
		mv = 0;
	}

	if (av <= 0)
	{  
		RedSystemMessage(m_session, "Values are invalid. Value must be < max (if max exists), and both must be > 0.");
		return true;
	}
	if(fieldmax)
	{
		if(mv < av || mv <= 0)
		{
			RedSystemMessage(m_session, "Values are invalid. Value must be < max (if max exists), and both must be > 0.");
			return true;
		}
	}

	Player *plr = getSelectedChar(m_session, false);
	if(plr)
	{  
		sGMLog.writefromsession(m_session, "used modify field value: %s, %f on %s", fieldname, av, plr->GetName());
		if(fieldmax)
		{
			BlueSystemMessage(m_session, "You set the %s of %s to %.1f/%.1f.", fieldname, plr->GetName(), av, mv);
			GreenSystemMessageToPlr(plr, "%s set your %s to %.1f/%.1f.", m_session->GetPlayer()->GetName(), fieldname, av, mv);
		}
		else
		{
			BlueSystemMessage(m_session, "You set the %s of %s to %.1f.", fieldname, plr->GetName(), av);
			GreenSystemMessageToPlr(plr, "%s set your %s to %.1f.", m_session->GetPlayer()->GetName(), fieldname, av);
		}
		plr->SetFloatValue(field, av);
		if(fieldmax) plr->SetFloatValue(fieldmax, mv);
	}
	else
	{
		Creature *cr = getSelectedCreature(m_session, false);
		if(cr)
		{
			if(!(field < UNIT_END && fieldmax < UNIT_END)) return false;
			std::string creaturename = "Unknown Being";
			if(cr->GetCreatureInfo())
				creaturename = cr->GetCreatureInfo()->Name;
			if(fieldmax)
				BlueSystemMessage(m_session, "Setting %s of %s to %.1f/%.1f.", fieldname, creaturename.c_str(), av, mv);
			else
				BlueSystemMessage(m_session, "Setting %s of %s to %.1f.", fieldname, creaturename.c_str(), av);
			cr->SetFloatValue(field, av);
			sGMLog.writefromsession(m_session, "used modify field value: [creature]%s, %f on %s", fieldname, av, creaturename.c_str());
			if(fieldmax) {
				cr->SetFloatValue(fieldmax, mv);
			}
			//cr->SaveToDB();
		}
		else
		{
			RedSystemMessage(m_session, "Invalid Selection.");
		}
	}
	return true;
}

bool ChatHandler::HandleGetPosCommand(const char* args, WorldSession *m_session)
{
	if(!args || !m_session) return false;

	/*if(m_session->GetPlayer()->GetSelection() == 0) return false;
	Creature *creature = objmgr.GetCreature(m_session->GetPlayer()->GetSelection());

	if(!creature) return false;
	BlueSystemMessage(m_session, "Creature Position: \nX: %f\nY: %f\nZ: %f\n", creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ());
	return true;*/

	uint32 spell = atol(args);
	SpellEntry *se = dbcSpell.LookupEntry(spell);
	if(se)
		BlueSystemMessage(m_session, "SpellIcon for %d is %d", se->Id, se->field114);
	return true;
}
