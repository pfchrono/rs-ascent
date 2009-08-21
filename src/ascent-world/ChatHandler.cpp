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

extern std::string LogFileName;
extern bool bLogChat;

#ifndef WIN32
char * strupr(char *s)
{
	char *tmp = s;
	while (*s)
		*s = toupper(*s++);
	return tmp;
}
#endif

static const uint32 LanguageSkills[NUM_LANGUAGES] = {
	0,				// UNIVERSAL		0x00
	109,			// ORCISH			0x01
	113,			// DARNASSIAN		0x02
	115,			// TAURAHE			0x03
	0,				// -				0x04
	0,				// -				0x05
	111,			// DWARVISH			0x06
	98,				// COMMON			0x07
	139,			// DEMON TONGUE		0x08
	140,			// TITAN			0x09
	137,			// THALSSIAN		0x0A
	138,			// DRACONIC			0x0B
	0,				// KALIMAG			0x0C
	313,			// GNOMISH			0x0D
	315,			// TROLL			0x0E
	0,				// -				0x0F
	0,				// -				0x10
	0,				// -				0x11
	0,				// -				0x12
	0,				// -				0x13
	0,				// -				0x14
	0,				// -				0x15
	0,				// -				0x16
	0,				// -				0x17
	0,				// -				0x18
	0,				// -				0x19
	0,				// -				0x1A
	0,				// -				0x1B
	0,				// -				0x1C
	0,				// -				0x1D
	0,				// -				0x1E
	0,				// -				0x1F
	0,				// -				0x20
	673,			// -				0x21
	0,				// -				0x22
	759,			// -				0x23
};

string AddChatTagToMessage(string msg, Player * _player)
{
	if(_player->GetSession()->CanUseCommand('2') && _player->bCTagOn == true && (sWorld.rsChatTag || _player->RS_getAccess() >= RS_PROBEGM))
	{
		uint32 Player_Access = _player->RS_getAccess();
		
		if(!_player->bGMTagOn && Player_Access >= RS_PROBEGM)
			Player_Access = RS_UBERVIP;
			
		std::string msg2;
		switch(Player_Access)
		{
			case RS_VIP:
				{
					msg2 += "|cffBB85DD<VIP>|r ";
				}break;
			case RS_UBERVIP:
				{
					msg2 += "|cffB85CCB<Uber-VIP>|r ";
				}break;
			case RS_PROBEGM:
				{
					msg2 += "|cff76EEC6<ProbeGM>|r ";
				}break;
			case RS_SCRIPTER:
				{
					msg2 += "|cff00BFFF<Scripter>|r ";
				}break;
			case RS_GAMEMASTER:
				{
					msg2 += "|cffE20008<GM>|r ";
				}break;
			case RS_ADMIN:
				{
					msg2 += "|cffFF69FF<Admin>|r ";
				}break;
		}
		msg2 += "|r";
		msg2 += msg;
		msg = msg2;
	}
	return msg;
}

void WorldSession::HandleMessagechatOpcode( WorldPacket & recv_data )
{
	CHECK_PACKET_SIZE(recv_data, 9);
	WorldPacket *data;
	if(!_player->IsInWorld())
		return;

	uint32 type;
	int32 lang;

	const char * pMisc = 0;
	const char * pMsg = 0;
	recv_data >> type;
	recv_data >> lang;

	if( lang >= NUM_LANGUAGES )
		return;

	if(GetPlayer()->IsBanned())
	{
		GetPlayer()->BroadcastMessage("You cannot do that when banned.");
		return;
	}

	if(lang != -1 && GetPlayer()->RS_getAccess() < RS_SCRIPTER && sWorld.flood_lines)
	{
		/* flood detection, wheeee! */
		if(UNIXTIME >= floodTime)
		{
			floodLines = 0;
			floodTime = UNIXTIME + sWorld.flood_seconds;
		}

		if((++floodLines) > sWorld.flood_lines)
		{
			if(sWorld.flood_message)
				_player->BroadcastMessage("Your message has triggered serverside flood protection. You can speak again in %u seconds.", floodTime - UNIXTIME);

			return;
		}
	}

	std::stringstream irctext;
	irctext.rdbuf()->str("");
	std::string msg;
	msg.reserve(256);

	//arghhh STFU. I'm not giving you gold or items NOOB
	/*switch(type)
	{
	case CHAT_MSG_EMOTE:
	case CHAT_MSG_SAY:
	case CHAT_MSG_YELL:
	case CHAT_MSG_WHISPER:
	case CHAT_MSG_CHANNEL:
		{*/
			if( m_muted && m_muted >= (uint32)UNIXTIME )
			{
				SystemMessage("Your voice is currently muted by a moderator.");
				return;
			}
/*		}break;
	}
*/
	switch(type)
	{
		case CHAT_MSG_EMOTE:
		{
			recv_data >> msg;

			if( lang > LANG_UNIVERSAL )
				lang = LANG_UNIVERSAL;

			if(GetPlayer()->m_modlanguage >=0)
				data = sChatHandler.FillMessageData( CHAT_MSG_EMOTE, GetPlayer()->m_modlanguage,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );
			else if( lang == LANG_UNIVERSAL )
				data = sChatHandler.FillMessageData( CHAT_MSG_EMOTE, CanUseCommand('0') ? LANG_UNIVERSAL : lang,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );
			else	
				data = sChatHandler.FillMessageData( CHAT_MSG_EMOTE, CanUseCommand('c') ? LANG_UNIVERSAL : lang,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );

			GetPlayer()->SendMessageToSet( data, true, false );

			sChatLog.writefromsession(this, "[EMOTE] : %s", msg.c_str());
			//sLog.outString("[emote] %s: %s", _player->GetName(), msg.c_str());
			delete data;

			pMsg=msg.c_str();
			pMisc=0;

		}break;
	case CHAT_MSG_SAY:
		{
			recv_data >> msg;

			if( !strcmp(msg.c_str(), "\n") )
				return;

			if( lang > LANG_UNIVERSAL )
				lang = LANG_UNIVERSAL;

			if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
				break;

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}

			if(GetPlayer()->m_modlanguage >=0)
			{
				data = sChatHandler.FillMessageData( CHAT_MSG_SAY, GetPlayer()->m_modlanguage,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );
				GetPlayer()->SendMessageToSet( data, true );
			}
			else
			{
				data = sChatHandler.FillMessageData( CHAT_MSG_SAY, lang, msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );
				SendChatPacket(data, 1, lang, this);
				for(set<Player*>::iterator itr = _player->m_inRangePlayers.begin(); itr != _player->m_inRangePlayers.end(); ++itr)
				{
					(*itr)->GetSession()->SendChatPacket(data, 1, lang, this);
				}
			}

			if( lang == LANG_UNIVERSAL )
				sChatLog.writefromsession(this, "[SAY] : %s", msg.c_str());

			//sLog.outString("[say] %s: %s", _player->GetName(), msg.c_str());
			objmgr.SafeDeleteObj(data);
			pMsg=msg.c_str();
			pMisc=0;
		} break;
	case CHAT_MSG_PARTY:
	case CHAT_MSG_RAID:
	case CHAT_MSG_RAID_LEADER:
	case CHAT_MSG_RAID_WARNING:
		{
			recv_data >> msg;

			if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
				break;

			if( lang > LANG_UNIVERSAL )
				lang = LANG_UNIVERSAL;

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}

			Group *pGroup = _player->GetGroup();
			if(pGroup == NULL) break;
			
			if(GetPlayer()->m_modlanguage >=0)
				data = sChatHandler.FillMessageData( type, GetPlayer()->m_modlanguage,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );
			else
				data = sChatHandler.FillMessageData( type, (CanUseCommand('0') && lang != -1) ? LANG_UNIVERSAL : lang, msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0);

			if(type == CHAT_MSG_PARTY && pGroup->GetGroupType() == GROUP_TYPE_RAID)
			{
				// only send to that subgroup
				SubGroup * sgr = _player->GetGroup() ?
					_player->GetGroup()->GetSubGroup(_player->GetSubGroup()) : 0;

				if(sgr)
				{
					_player->GetGroup()->Lock();
					for(GroupMembersSet::iterator itr = sgr->GetGroupMembersBegin(); itr != sgr->GetGroupMembersEnd(); ++itr)
					{
						if((*itr)->m_loggedInPlayer)
							(*itr)->m_loggedInPlayer->GetSession()->SendChatPacket(data, 1, lang, this);
					}
					_player->GetGroup()->Unlock();
				}
			}
			else
			{
				SubGroup * sgr;
				for(uint32 i = 0; i < _player->GetGroup()->GetSubGroupCount(); ++i)
				{
					sgr = _player->GetGroup()->GetSubGroup(i);
					_player->GetGroup()->Lock();
					for(GroupMembersSet::iterator itr = sgr->GetGroupMembersBegin(); itr != sgr->GetGroupMembersEnd(); ++itr)
					{
						if((*itr)->m_loggedInPlayer)
							(*itr)->m_loggedInPlayer->GetSession()->SendChatPacket(data, 1, lang, this);
					}
					_player->GetGroup()->Unlock();
				}
			}
			if( lang == LANG_UNIVERSAL )
				sChatLog.writefromsession(this, "[PARTY] : %s", msg.c_str());

			//sLog.outString("[party] %s: %s", _player->GetName(), msg.c_str());
			delete data;
			pMsg=msg.c_str();
			pMisc=0;
		} break;
		case CHAT_MSG_GUILD:
		{
			recv_data >> msg;
			if( lang > LANG_UNIVERSAL )
				lang = LANG_UNIVERSAL;

			if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
			{
				break;
			}

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}

			if(_player->m_playerInfo->guild)
			{
				_player->m_playerInfo->guild->GuildChat(msg.c_str(), this, lang);
				if( lang == LANG_UNIVERSAL )
					sChanLog.writefromsession(this, "[GUILD] %s : %s", _player->GetGuild()->GetGuildName(), msg.c_str());
			}

			pMsg=msg.c_str();
			pMisc=0;
		} break;
	case CHAT_MSG_OFFICER:
		{
			recv_data >> msg;

			if( !strcmp(msg.c_str(), "\n") )
				return;

			if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
				break;

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}
			if(lang > LANG_UNIVERSAL) 
			{
				lang = LANG_UNIVERSAL;
				if(_player->m_playerInfo->guild)
				{
					_player->m_playerInfo->guild->OfficerChat(msg.c_str(), this, lang);
					sChanLog.writefromsession(this, "[OFFICER] %s : %s", _player->GetGuild()->GetGuildName(), msg.c_str());
				}
			}
			pMsg=msg.c_str();
			pMisc=0;
		} break;
	case CHAT_MSG_YELL:
		{
			recv_data >> msg;

			if( lang > LANG_UNIVERSAL )
				lang = LANG_UNIVERSAL;

			if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
				break;

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}
			if(lang > 0 && LanguageSkills[lang] && _player->_HasSkillLine(LanguageSkills[lang]) == false)
				return;

			if( lang == LANG_UNIVERSAL )
				data = sChatHandler.FillMessageData( CHAT_MSG_YELL, (CanUseCommand('0') && lang != -1) ? LANG_UNIVERSAL : lang,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );

			if( GetPlayer()->m_modlanguage >= 0 )
				data = sChatHandler.FillMessageData( CHAT_MSG_YELL, GetPlayer()->m_modlanguage,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );
			else
				data = sChatHandler.FillMessageData( CHAT_MSG_YELL, (CanUseCommand('c') && lang != -1) ? LANG_UNIVERSAL : lang,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );

			//SendPacket(data);
			//sWorld.SendZoneMessage(data, GetPlayer()->GetZoneId(), this);
			_player->GetMapMgr()->SendChatMessageToCellPlayers(_player, data, 2, 1, lang, this);
			objmgr.SafeDeleteObj(data);
			if( lang == LANG_UNIVERSAL )
				sChatLog.writefromsession(this, "[YELL] : %s",  msg.c_str());
			//sLog.outString("[yell] %s: %s", _player->GetName(), msg.c_str());
			pMsg=msg.c_str();
			pMisc=0;
		} break;
	case CHAT_MSG_WHISPER:
		{
			std::string to = "",tmp;
			recv_data >> to >> msg;

			if( !strcmp(msg.c_str(), "WIM_") )
				return;

			if( lang > LANG_UNIVERSAL )
				lang = LANG_UNIVERSAL;

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}
			string csole = strupr(const_cast<char*>(to.c_str()));
			if( csole == "CONSOLE" )
			{
				sLog.outColor(TBLUE, "[Whisper][%s]: %s", _player->GetName() , msg.c_str());
				sLog.outColor(TNORMAL, "\r\n");
				if( lang == LANG_UNIVERSAL )
					sChatLog.writefromsession(this, "[WHISPER] To [Console]: %s", msg.c_str());
				_player->BroadcastMessage("|cffdd80e6To [Console]: %s|r", msg.c_str());
				csole = "";
				break;
			}
			Player *player = objmgr.GetPlayer(to.c_str(), false);
			if(!player)
			{
				data = new WorldPacket(SMSG_CHAT_PLAYER_NOT_FOUND, to.length() + 1);
				*data << to;
				SendPacket(data);
				objmgr.SafeDeleteObj(data);
				break;
			}

			// Check that the player isn't a gm with his status on
			if(_player->RS_getAccess() < RS_GAMEMASTER && player->bGMTagOn && player->gmTargets.count(_player) == 0)
			{
				// Build automated reply
				string Reply = "This Game Master did not receive your whisper. Please request help through the 'gmhelp' channel if you need to speak to a GM. This is an automatic message.";
				data = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.c_str(), player->GetGUID(), 3);
				SendPacket(data);
				objmgr.SafeDeleteObj(data);
				break;
			}

			if(lang > LANG_UNIVERSAL && LanguageSkills[lang] && _player->_HasSkillLine(LanguageSkills[lang]) == false)
				return;

			if( lang == LANG_UNIVERSAL )
				data = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, ((CanUseCommand('0') || player->GetSession()->CanUseCommand('0')) && lang != -1) ? LANG_UNIVERSAL : lang,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );

			if( player->Social_IsIgnoring( _player->GetLowGUID() ) )
			{
				data = sChatHandler.FillMessageData( CHAT_MSG_IGNORED, LANG_UNIVERSAL,  msg.c_str(), player->GetGUID(), _player->bGMTagOn ? 4 : 0 );
				SendPacket(data);
				objmgr.SafeDeleteObj(data);
			}
			else
			{
				if( GetPlayer()->m_modlanguage >=0 )
					data = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, GetPlayer()->m_modlanguage,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );
				else
					data = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, ((CanUseCommand('c') || player->GetSession()->CanUseCommand('c')) && lang != -1) ? LANG_UNIVERSAL : lang,  msg.c_str(), _player->GetGUID(), _player->bGMTagOn ? 4 : 0 );

				player->GetSession()->SendPacket(data);
				objmgr.SafeDeleteObj(data);
			}

			//Sent the to Users id as the channel, this should be fine as it's not used for wisper
			data = sChatHandler.FillMessageData(CHAT_MSG_WHISPER_INFORM, LANG_UNIVERSAL,msg.c_str(), player->GetGUID(), player->bGMTagOn ? 4 : 0  );
			SendPacket(data);
			objmgr.SafeDeleteObj(data);

			if(player->HasFlag(PLAYER_FLAGS, 0x02))
			{
				// Has AFK flag, autorespond.
				data = sChatHandler.FillMessageData(CHAT_MSG_AFK, LANG_UNIVERSAL,  player->m_afk_reason.c_str(),player->GetGUID(), _player->bGMTagOn ? 4 : 0);
				SendPacket(data);
				objmgr.SafeDeleteObj(data);
			}
			else if(player->HasFlag(PLAYER_FLAGS, 0x04))
			{
				// Has AFK flag, autorespond.
				data = sChatHandler.FillMessageData(CHAT_MSG_DND, LANG_UNIVERSAL, player->m_afk_reason.c_str(),player->GetGUID(), _player->bGMTagOn ? 4 : 0);
				SendPacket(data);
				objmgr.SafeDeleteObj(data);
			}
			if( sWorld.rsWhispInCon )
			{
				if( lang == LANG_UNIVERSAL )
					Log.Whisper("[WHISPER]", "%s(%u) to %s(%u): %s", _player->GetName(), _player->GetSession()->GetAccountId(), player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
			}
			if( lang == LANG_UNIVERSAL )
				sChatLog.writefromsession(this, "[WHISPER] To %s(%u): %s", player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());

			//sLog.outString("[whisper] %s to %s: %s", _player->GetName(), to.c_str(), msg.c_str());
			pMsg=msg.c_str();
			pMisc=to.c_str();
		} break;
	case CHAT_MSG_CHANNEL:
		{
			std::string channel = "";
			recv_data >> channel;
			recv_data >> msg;
			std::string lower_chan = channel;
			ASCENT_TOLOWER(lower_chan);

			if( !strcmp(msg.c_str(), "\n") )
				return;

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}

			if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
				break;

			if( sWorld.rsChanInCon && lang >
				LANG_UNIVERSAL )
			{
				if(		!RSASCENT_MATCH(lower_chan, "events") 
					&&	!RSASCENT_MATCH(lower_chan, "gemchanneldefault")
					&&	!RSASCENT_MATCH(lower_chan, "rs")
					&&	!RSASCENT_MATCH(lower_chan, "globalcomm")
					&&	!RSASCENT_MATCH(lower_chan, "crbz2016i1")
					&&	!RSASCENT_MATCH(lower_chan, "crbz2014I1")
					)
				{
					char chan[256];
					sprintf(chan, "[CHANNEL][%s]", channel.c_str());
					Log.Channel(chan, "%s: %s", _player->GetName(), msg.c_str());
//					if( lang == LANG_UNIVERSAL )
					sChanLog.writefromsession(this, "[CHANNEL] %s : %s", lower_chan.c_str(), msg.c_str());
				}
			}

			msg = AddChatTagToMessage(msg, _player);
			
			Channel *chn = channelmgr.GetChannel(channel.c_str(),GetPlayer()); 
			if(chn) 
			{
				chn->Say(GetPlayer(), msg.c_str(), NULL, false);
			}
			/*if(strcmp(channel.c_str(), sWorld.getGmClientChannel().c_str()) == 0)
				if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
					break;*/

			//sLog.outString("[%s] %s: %s", channel.c_str(), _player->GetName(), msg.c_str());
			pMsg=msg.c_str();
			pMisc=channel.c_str();

		} break;
	case CHAT_MSG_AFK:
		{
			std::string reason;
			recv_data >> reason;
			GetPlayer()->SetAFKReason(reason);

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}
			/* WorldPacket *data, WorldSession* session, uint32 type, uint32 language, const char *channelName, const char *message*/
			if(GetPlayer()->HasFlag(PLAYER_FLAGS, 0x02))
			{
				GetPlayer()->RemoveFlag(PLAYER_FLAGS, 0x02);
				if(sWorld.GetKickAFKPlayerTime())
					sEventMgr.RemoveEvents(GetPlayer(),EVENT_PLAYER_SOFT_DISCONNECT);
			}
			else
			{
				GetPlayer()->SetFlag(PLAYER_FLAGS, 0x02);

				if( GetPlayer()->m_bg )
					GetPlayer()->m_bg->RemovePlayer( GetPlayer(), false );

				if(sWorld.GetKickAFKPlayerTime() && GetPlayer()->RS_getAccess() < RS_PROBEGM)
					sEventMgr.AddEvent(GetPlayer(),&Player::SoftDisconnect,EVENT_PLAYER_SOFT_DISCONNECT,sWorld.GetKickAFKPlayerTime(),1,0);
			}
		} break;
	case CHAT_MSG_DND:
		{
			std::string reason;
			recv_data >> reason;
			GetPlayer()->SetAFKReason(reason);

			if(g_chatFilter->Parse(msg) == true)
			{
				SystemMessage("Your chat message was blocked by a server-side filter.");
				return;
			}

			if(GetPlayer()->HasFlag(PLAYER_FLAGS, 0x04))
				GetPlayer()->RemoveFlag(PLAYER_FLAGS, 0x04);
			else
			{
				GetPlayer()->SetFlag(PLAYER_FLAGS, 0x04);
			}		  
		} break;
	default:
		sLog.outError("CHAT: unknown msg type %u, lang: %u", type, lang);
	}

	if(pMsg)
		sHookInterface.OnChat(_player, type, lang, pMsg, pMisc);
}

void WorldSession::HandleTextEmoteOpcode( WorldPacket & recv_data )
{
	CHECK_PACKET_SIZE(recv_data, 16);
	if(!_player->IsInWorld() || !_player->isAlive())
		return;

	uint64 guid;
	uint32
		text_emote,
		unk,
		namelen =1;
	const char* name =" ";

	recv_data >> text_emote;
	recv_data >> unk;
	recv_data >> guid;

	Unit * pUnit = _player->GetMapMgr()->GetUnit(guid);
	if(pUnit)
	{
		if( pUnit->IsPlayer() )
		{
			name = static_cast< Player* >( pUnit )->GetName();
			namelen = (uint32)strlen(name) + 1;
		}
		else if ( pUnit->IsPet() )
		{
			Pet * p = static_cast<Pet*>(pUnit);
			if(p->GetName().c_str())
			{
				name = p->GetName().c_str();
				namelen = (uint32)strlen(name) + 1;
			}
			else if(p->GetCreatureInfo())
			{
				name = p->GetCreatureInfo()->Name;
				namelen = (uint32)strlen(name) + 1;
			}
			else
			{
				name = 0;
				namelen = 0;
			}
		}	
		else if(pUnit->GetTypeId() == TYPEID_UNIT)
		{
			Creature * p = static_cast<Creature*>(pUnit);
			if(p->GetCreatureInfo())
			{
				name = p->GetCreatureInfo()->Name;
				namelen = (uint32)strlen(name) + 1;
			}
			else
			{
				name = 0;
				namelen = 0;
			}
		}
	}

	emoteentry *em = dbcEmoteEntry.LookupEntry(text_emote);
	if(em)
	{
		WorldPacket data(SMSG_EMOTE, 28 + namelen);

		sHookInterface.OnEmote(_player, (EmoteType)em->textid);
		if(pUnit)
			CALL_SCRIPT_EVENT(pUnit,OnEmote)(_player,(EmoteType)em->textid);

		switch(em->textid)
		{
			case EMOTE_STATE_SLEEP:
			case EMOTE_STATE_SIT:
			case EMOTE_STATE_KNEEL:
			case EMOTE_STATE_DANCE:
				{
					_player->SetUInt32Value(UNIT_NPC_EMOTESTATE, em->textid);
				}break;
		}

		data << (uint32)em->textid;
		data << (uint64)GetPlayer()->GetGUID();
		GetPlayer()->SendMessageToSet(&data, true); //If player receives his own emote, his animation stops.

		data.Initialize(SMSG_TEXT_EMOTE);
		data << (uint64)GetPlayer()->GetGUID();
		data << (uint32)text_emote;
		data << unk;
		data << (uint32)namelen;
		if( namelen > 1 )	data.append(name, namelen);
		else				data << (uint8)0x00;

		GetPlayer()->SendMessageToSet(&data, true);
	}
}

void WorldSession::HandleReportSpamOpcode(WorldPacket & recvPacket)
{
	CHECK_PACKET_SIZE(recvPacket, 29);

	// the 0 in the out packet is unknown
	GetPlayer()->GetSession()->OutPacket(SMSG_COMPLAIN_RESULT, 1, 0 );

	/* This whole thing is guess-work */
	uint8 unk1;
	uint64 reportedGuid;
	uint32 unk2;
	uint32 messagetype;
	uint32 unk3;
	uint32 unk4;
	std::string message;
	recvPacket >> unk1 >> reportedGuid >> unk2 >> messagetype >> unk3 >> unk4 >> message;

	Player * rPlayer = objmgr.GetPlayer((uint32)reportedGuid);
	if(!rPlayer)
		return;

}
