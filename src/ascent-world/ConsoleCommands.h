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

#ifndef _CONSOLECOMMANDS_H
#define _CONSOLECOMMANDS_H

bool HandleAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleBanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleCancelCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleCreateAccountCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleInfoCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleAHBotCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleGMsCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleKickCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleMOTDCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleOnlinePlayersCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandlePlayerInfoCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleRehashCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleShutDownCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleUnbanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleWAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleWhisperCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleNameHashCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleSaveallPlayers(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleSAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleReloadAccounts(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleSendToChanCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleConsoleWBuffCommand(BaseConsole * pConsole, int argc, const char * argv[]);
bool HandleReloadTableCommand(BaseConsole * pConsole, int argc, const char* argv[]);

#endif
