-- ----------------------------
-- Table structure for ai_agents
-- ----------------------------
DROP TABLE IF EXISTS `ai_agents`;
CREATE TABLE `ai_agents` (
  `entry` int(11) unsigned NOT NULL default '0',
  `type` smallint(5) unsigned NOT NULL default '0',
  `event` int(11) unsigned NOT NULL default '0',
  `chance` int(11) unsigned NOT NULL default '0',
  `maxcount` int(11) unsigned NOT NULL default '0',
  `spell` int(11) unsigned NOT NULL default '0',
  `spelltype` int(11) unsigned NOT NULL default '0',
  `targettype` int(11) unsigned NOT NULL default '0',
  `cooldown` int(8) NOT NULL default '0',
  `floatMisc1` float NOT NULL default '0',
  `Misc2` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`type`,`spell`),
  UNIQUE KEY `a` (`entry`,`spell`,`type`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='AI System';

-- ----------------------------
-- Table structure for ai_threattospellid
-- ----------------------------
DROP TABLE IF EXISTS `ai_threattospellid`;
CREATE TABLE `ai_threattospellid` (
  `spell` int(11) unsigned NOT NULL default '0',
  `mod` int(11) NOT NULL default '0',
  PRIMARY KEY  (`spell`),
  UNIQUE KEY `a` (`spell`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='AI System';

-- ----------------------------
-- Table structure for areatriggers
-- ----------------------------
DROP TABLE IF EXISTS `areatriggers`;
CREATE TABLE `areatriggers` (
  `entry` int(11) unsigned NOT NULL default '0',
  `type` tinyint(3) unsigned default '0',
  `map` int(11) unsigned default NULL,
  `screen` int(11) unsigned default NULL,
  `name` varchar(100) default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `required_honor_rank` int(11) unsigned NOT NULL default '0',
  `required_level` tinyint(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`),
  UNIQUE KEY `a` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Trigger System';

-- ----------------------------
-- Table structure for auctionhouse
-- ----------------------------
DROP TABLE IF EXISTS `auctionhouse`;
CREATE TABLE `auctionhouse` (
  `id` int(32) NOT NULL auto_increment,
  `creature_entry` bigint(64) unsigned NOT NULL default '0',
  `group` int(32) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `a` (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=39 DEFAULT CHARSET=latin1 COMMENT='Auction House';

-- ----------------------------
-- Table structure for banned_phrases
-- ----------------------------
DROP TABLE IF EXISTS `banned_phrases`;
CREATE TABLE `banned_phrases` (
  `phrase` varchar(250) collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`phrase`),
  UNIQUE KEY `a` (`phrase`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for clientaddons
-- ----------------------------
DROP TABLE IF EXISTS `clientaddons`;
CREATE TABLE `clientaddons` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `name` varchar(50) character set utf8 collate utf8_unicode_ci default NULL,
  `crc` bigint(20) unsigned default NULL,
  `banned` int(10) unsigned NOT NULL default '0',
  `showinlist` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `a` (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=153 DEFAULT CHARSET=latin1 COMMENT='Client Addons';

-- ----------------------------
-- Table structure for command_overrides
-- ----------------------------
DROP TABLE IF EXISTS `command_overrides`;
CREATE TABLE `command_overrides` (
  `command_name` varchar(100) NOT NULL,
  `access_level` varchar(10) NOT NULL,
  PRIMARY KEY  (`command_name`),
  UNIQUE KEY `a` (`command_name`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Commands System';

-- ----------------------------
-- Table structure for creature_formations
-- ----------------------------
DROP TABLE IF EXISTS `creature_formations`;
CREATE TABLE `creature_formations` (
  `spawn_id` int(10) unsigned NOT NULL default '0',
  `target_spawn_id` int(10) unsigned NOT NULL default '0',
  `follow_angle` float NOT NULL default '0',
  `follow_dist` float NOT NULL default '0',
  PRIMARY KEY  (`spawn_id`),
  UNIQUE KEY `a` (`spawn_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Creature System';

-- ----------------------------
-- Table structure for creature_names
-- ----------------------------
DROP TABLE IF EXISTS `creature_names`;
CREATE TABLE `creature_names` (
  `entry` int(10) unsigned NOT NULL default '0',
  `name` varchar(100) NOT NULL,
  `subname` varchar(100) NOT NULL,
  `info_str` varchar(500) NOT NULL,
  `Flags1` int(10) unsigned default '0',
  `type` int(10) unsigned default '0',
  `family` int(10) unsigned default '0',
  `rank` int(10) unsigned default '0',
  `unk4` int(10) unsigned default '0',
  `spelldataid` int(10) unsigned default NULL,
  `male_displayid` int(30) NOT NULL,
  `female_displayid` int(30) NOT NULL,
  `male_displayid2` int(30) NOT NULL default '0',
  `female_displayid2` int(30) NOT NULL default '0',
  `unknown_float1` float NOT NULL default '1',
  `unknown_float2` float NOT NULL default '1',
  `civilian` int(4) unsigned default NULL,
  `leader` tinyint(3) unsigned default NULL,
  `GuardType` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`),
  UNIQUE KEY `a` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Creature System';

-- ----------------------------
-- Table structure for creature_names_localized
-- ----------------------------
DROP TABLE IF EXISTS `creature_names_localized`;
CREATE TABLE `creature_names_localized` (
  `id` int(30) unsigned NOT NULL,
  `language_code` varchar(5) character set latin1 NOT NULL,
  `name` varchar(100) character set latin1 NOT NULL,
  `subname` varchar(100) character set latin1 NOT NULL,
  PRIMARY KEY  (`id`,`language_code`),
  KEY `lol` (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for creature_proto
-- ----------------------------
DROP TABLE IF EXISTS `creature_proto`;
CREATE TABLE `creature_proto` (
  `entry` int(30) unsigned NOT NULL default '0',
  `minlevel` int(30) unsigned NOT NULL,
  `maxlevel` int(30) unsigned NOT NULL,
  `faction` int(30) unsigned NOT NULL default '0',
  `minhealth` int(30) unsigned NOT NULL,
  `maxhealth` int(30) unsigned NOT NULL,
  `mana` int(30) unsigned NOT NULL default '0',
  `scale` float NOT NULL default '0',
  `npcflags` int(30) unsigned NOT NULL default '0',
  `attacktime` int(30) unsigned NOT NULL default '0',
  `attacktype` int(4) NOT NULL default '0',
  `mindamage` float NOT NULL default '0',
  `maxdamage` float NOT NULL default '0',
  `rangedattacktime` int(30) unsigned NOT NULL default '0',
  `rangedmindamage` float unsigned NOT NULL default '0',
  `rangedmaxdamage` float unsigned NOT NULL default '0',
  `mountdisplayid` int(30) unsigned NOT NULL default '0',
  `equipmodel1` int(30) unsigned NOT NULL default '0',
  `equipinfo1` int(30) unsigned NOT NULL default '0',
  `equipslot1` int(30) unsigned NOT NULL default '0',
  `equipmodel2` int(30) unsigned NOT NULL default '0',
  `equipinfo2` int(30) unsigned NOT NULL default '0',
  `equipslot2` int(30) unsigned NOT NULL default '0',
  `equipmodel3` int(30) unsigned NOT NULL default '0',
  `equipinfo3` int(30) unsigned NOT NULL default '0',
  `equipslot3` int(30) unsigned NOT NULL default '0',
  `respawntime` int(30) unsigned NOT NULL default '0',
  `armor` int(30) unsigned NOT NULL default '0',
  `resistance1` int(30) unsigned NOT NULL default '0',
  `resistance2` int(30) unsigned NOT NULL default '0',
  `resistance3` int(30) unsigned NOT NULL default '0',
  `resistance4` int(30) unsigned NOT NULL default '0',
  `resistance5` int(30) unsigned NOT NULL default '0',
  `resistance6` int(30) unsigned NOT NULL default '0',
  `combat_reach` float NOT NULL default '0',
  `bounding_radius` float NOT NULL default '0',
  `auras` longtext NOT NULL,
  `boss` int(11) unsigned NOT NULL default '0',
  `money` int(30) NOT NULL default '0',
  `invisibility_type` int(30) unsigned NOT NULL,
  `death_state` int(30) unsigned NOT NULL,
  `walk_speed` float NOT NULL default '2.5',
  `run_speed` float NOT NULL default '8',
  `fly_speed` float NOT NULL default '14',
  `extra_a9_flags` int(30) NOT NULL default '0',
  `spell1` int(30) NOT NULL default '0',
  `spell2` int(30) NOT NULL default '0',
  `spell3` int(30) NOT NULL default '0',
  `spell4` int(30) NOT NULL default '0',
  `spell_flags` int(30) NOT NULL default '0',
  PRIMARY KEY  (`entry`),
  UNIQUE KEY `ID` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Creature System';

-- ----------------------------
-- Table structure for creature_quest_finisher
-- ----------------------------
DROP TABLE IF EXISTS `creature_quest_finisher`;
CREATE TABLE `creature_quest_finisher` (
  `id` int(11) unsigned NOT NULL default '0',
  `quest` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 ROW_FORMAT=FIXED COMMENT='Creature System';

-- ----------------------------
-- Table structure for creature_quest_starter
-- ----------------------------
DROP TABLE IF EXISTS `creature_quest_starter`;
CREATE TABLE `creature_quest_starter` (
  `id` int(11) unsigned NOT NULL default '0',
  `quest` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 ROW_FORMAT=FIXED COMMENT='Creature System';

-- ----------------------------
-- Table structure for creature_spawns
-- ----------------------------
DROP TABLE IF EXISTS `creature_spawns`;
CREATE TABLE `creature_spawns` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `entry` int(30) NOT NULL,
  `map` int(30) NOT NULL,
  `position_x` float NOT NULL,
  `position_y` float NOT NULL,
  `position_z` float NOT NULL,
  `orientation` float NOT NULL,
  `movetype` int(30) NOT NULL default '0',
  `displayid` int(30) unsigned NOT NULL default '0',
  `faction` int(30) NOT NULL default '14',
  `flags` int(30) NOT NULL default '0',
  `bytes` int(30) NOT NULL default '0',
  `bytes2` int(30) NOT NULL default '0',
  `emote_state` int(30) NOT NULL default '0',
  `npc_respawn_link` int(30) NOT NULL default '0',
  `channel_spell` int(30) NOT NULL default '0',
  `channel_target_sqlid` int(30) NOT NULL default '0',
  `channel_target_sqlid_creature` int(30) NOT NULL default '0',
  `standstate` int(10) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `b` (`map`)
) ENGINE=MyISAM AUTO_INCREMENT=4660668 DEFAULT CHARSET=latin1 COMMENT='Spawn System';

-- ----------------------------
-- Table structure for creature_staticspawns
-- ----------------------------
DROP TABLE IF EXISTS `creature_staticspawns`;
CREATE TABLE `creature_staticspawns` (
  `id` int(30) unsigned NOT NULL auto_increment,
  `entry` int(30) NOT NULL,
  `Map` int(30) NOT NULL,
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `o` float NOT NULL,
  `movetype` int(30) NOT NULL default '0',
  `displayid` int(30) unsigned NOT NULL default '0',
  `factionid` int(30) NOT NULL default '35',
  `flags` int(30) NOT NULL default '0',
  `bytes` int(30) NOT NULL default '0',
  `bytes2` int(30) NOT NULL default '0',
  `emote_state` int(30) NOT NULL default '0',
  `npc_respawn_link` int(30) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `id` (`id`),
  KEY `a` (`Map`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Spawn System';

-- ----------------------------
-- Table structure for creature_timed_emotes
-- ----------------------------
DROP TABLE IF EXISTS `creature_timed_emotes`;
CREATE TABLE `creature_timed_emotes` (
  `spawnid` int(10) unsigned NOT NULL default '0',
  `rowid` int(10) unsigned NOT NULL default '0',
  `type` tinyint(1) unsigned NOT NULL default '1',
  `value` int(10) unsigned NOT NULL default '0',
  `msg` text,
  `msg_type` int(10) unsigned NOT NULL default '0',
  `msg_lang` int(10) unsigned NOT NULL default '0',
  `expire_after` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`spawnid`,`rowid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for creature_waypoints
-- ----------------------------
DROP TABLE IF EXISTS `creature_waypoints`;
CREATE TABLE `creature_waypoints` (
  `spawnid` int(10) unsigned NOT NULL default '0',
  `waypointid` int(10) unsigned NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `waittime` int(10) unsigned NOT NULL default '0',
  `flags` int(10) unsigned NOT NULL default '0',
  `forwardemoteoneshot` tinyint(3) unsigned NOT NULL default '0',
  `forwardemoteid` int(10) unsigned NOT NULL default '0',
  `backwardemoteoneshot` tinyint(3) unsigned NOT NULL default '0',
  `backwardemoteid` int(10) unsigned NOT NULL default '0',
  `forwardskinid` int(10) unsigned NOT NULL default '0',
  `backwardskinid` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`spawnid`,`waypointid`),
  UNIQUE KEY `a` (`spawnid`,`waypointid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Creature System';

-- ----------------------------
-- Table structure for creatureloot
-- ----------------------------
DROP TABLE IF EXISTS `creatureloot`;
CREATE TABLE `creatureloot` (
  `index` int(11) unsigned NOT NULL auto_increment,
  `entryid` int(11) NOT NULL default '0',
  `itemid` int(11) NOT NULL default '0',
  `percentchance` float NOT NULL default '0',
  `heroicpercentchance` float NOT NULL default '0',
  `mincount` int(30) NOT NULL default '1',
  `maxcount` int(30) NOT NULL default '1',
  `ffa_loot` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entryid`,`itemid`,`percentchance`,`heroicpercentchance`,`mincount`,`maxcount`),
  UNIQUE KEY `index` (`index`)
) ENGINE=MyISAM AUTO_INCREMENT=40002874 DEFAULT CHARSET=latin1 PACK_KEYS=0 ROW_FORMAT=FIXED COMMENT='Loot System';

-- ----------------------------
-- Table structure for gameobject_tele
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_tele`;
CREATE TABLE `gameobject_tele` (
  `entry` int(10) unsigned NOT NULL,
  `map` int(10) unsigned NOT NULL,
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `o` float NOT NULL,
  UNIQUE KEY `EntryUnique` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for disenchantingloot
-- ----------------------------
DROP TABLE IF EXISTS `disenchantingloot`;
CREATE TABLE `disenchantingloot` (
  `index` int(11) NOT NULL auto_increment,
  `entryid` int(11) unsigned NOT NULL default '0',
  `itemid` int(11) unsigned NOT NULL default '25',
  `percentchance` float NOT NULL default '0',
  `heroicpercentchance` float default '0',
  `mincount` int(30) default '1',
  `maxcount` int(30) default '1',
  `ffa_loot` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`index`)
) ENGINE=MyISAM AUTO_INCREMENT=21244 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for fishing
-- ----------------------------
DROP TABLE IF EXISTS `fishing`;
CREATE TABLE `fishing` (
  `Zone` int(10) unsigned NOT NULL default '0',
  `MinSkill` int(10) unsigned default NULL,
  `MaxSkill` int(10) unsigned default NULL,
  UNIQUE KEY `Zone` (`Zone`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Fishing System';

-- ----------------------------
-- Table structure for fishingloot
-- ----------------------------
DROP TABLE IF EXISTS `fishingloot`;
CREATE TABLE `fishingloot` (
  `index` int(11) unsigned NOT NULL auto_increment,
  `entryid` int(11) unsigned NOT NULL default '0',
  `itemid` int(11) unsigned NOT NULL default '0',
  `percentchance` float NOT NULL default '0',
  `heroicpercentchance` float NOT NULL default '0',
  `mincount` int(11) unsigned NOT NULL default '1',
  `maxcount` int(11) unsigned NOT NULL default '1',
  `ffa_loot` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`index`),
  UNIQUE KEY `index` (`index`)
) ENGINE=MyISAM AUTO_INCREMENT=2229 DEFAULT CHARSET=latin1 COMMENT='Loot System';

-- ----------------------------
-- Table structure for gameobject_names
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_names`;
CREATE TABLE `gameobject_names` (
  `entry` int(10) unsigned NOT NULL default '0',
  `Type` int(10) unsigned NOT NULL default '0',
  `DisplayID` int(10) unsigned NOT NULL default '0',
  `Name` varchar(100) character set utf8 collate utf8_unicode_ci NOT NULL,
  `spellfocus` int(10) unsigned NOT NULL default '0',
  `sound1` int(10) unsigned NOT NULL default '0',
  `sound2` int(10) unsigned NOT NULL default '0',
  `sound3` int(10) unsigned NOT NULL default '0',
  `sound4` int(10) unsigned NOT NULL default '0',
  `sound5` int(10) unsigned NOT NULL default '0',
  `sound6` int(10) unsigned NOT NULL default '0',
  `sound7` int(10) unsigned NOT NULL default '0',
  `sound8` int(10) unsigned NOT NULL default '0',
  `sound9` int(10) unsigned NOT NULL default '0',
  `unknown1` int(10) unsigned NOT NULL default '0',
  `unknown2` int(10) unsigned NOT NULL default '0',
  `unknown3` int(10) unsigned NOT NULL default '0',
  `unknown4` int(10) unsigned NOT NULL default '0',
  `unknown5` int(10) unsigned NOT NULL default '0',
  `unknown6` int(10) unsigned NOT NULL default '0',
  `unknown7` int(10) unsigned NOT NULL default '0',
  `unknown8` int(10) unsigned NOT NULL default '0',
  `unknown9` int(10) unsigned NOT NULL default '0',
  `unknown10` int(10) unsigned NOT NULL default '0',
  `unknown11` int(10) unsigned NOT NULL default '0',
  `unknown12` int(10) unsigned NOT NULL default '0',
  `unknown13` int(10) unsigned NOT NULL default '0',
  `unknown14` int(10) unsigned NOT NULL default '0',
  UNIQUE KEY `entry` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Gameobject System';

-- ----------------------------
-- Table structure for gameobject_names_localized
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_names_localized`;
CREATE TABLE `gameobject_names_localized` (
  `entry` int(30) NOT NULL,
  `language_code` varchar(5) character set latin1 NOT NULL,
  `name` varchar(100) character set latin1 NOT NULL,
  PRIMARY KEY  (`entry`,`language_code`),
  KEY `lol` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for gameobject_quest_finisher
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_quest_finisher`;
CREATE TABLE `gameobject_quest_finisher` (
  `id` int(11) unsigned NOT NULL default '0',
  `quest` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Quest System';

-- ----------------------------
-- Table structure for gameobject_quest_item_binding
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_quest_item_binding`;
CREATE TABLE `gameobject_quest_item_binding` (
  `entry` int(11) NOT NULL default '0',
  `quest` int(11) NOT NULL default '0',
  `item` int(11) NOT NULL default '0',
  `item_count` int(11) NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Quest System';

-- ----------------------------
-- Table structure for gameobject_quest_pickup_binding
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_quest_pickup_binding`;
CREATE TABLE `gameobject_quest_pickup_binding` (
  `entry` int(11) NOT NULL default '0',
  `quest` int(11) NOT NULL default '0',
  `required_count` int(11) NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Quest System';

-- ----------------------------
-- Table structure for gameobject_quest_starter
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_quest_starter`;
CREATE TABLE `gameobject_quest_starter` (
  `id` int(11) unsigned NOT NULL default '0',
  `quest` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Quest System';

-- ----------------------------
-- Table structure for gameobject_spawns
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_spawns`;
CREATE TABLE `gameobject_spawns` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `Entry` int(10) unsigned NOT NULL default '0',
  `map` int(10) unsigned NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `Facing` float NOT NULL default '0',
  `orientation1` float NOT NULL default '0',
  `orientation2` float NOT NULL default '0',
  `orientation3` float NOT NULL default '0',
  `orientation4` float NOT NULL default '0',
  `State` int(10) unsigned NOT NULL default '0',
  `Flags` int(10) unsigned NOT NULL default '0',
  `Faction` int(10) unsigned NOT NULL default '0',
  `Scale` float NOT NULL default '0',
  `stateNpcLink` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `Map` (`map`)
) ENGINE=MyISAM AUTO_INCREMENT=2200058 DEFAULT CHARSET=cp1251 COLLATE=cp1251_general_cs PACK_KEYS=0 ROW_FORMAT=FIXED COMMENT='Spawn System';

-- ----------------------------
-- Table structure for gameobject_staticspawns
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_staticspawns`;
CREATE TABLE `gameobject_staticspawns` (
  `id` int(30) NOT NULL auto_increment,
  `entry` int(30) NOT NULL,
  `map` int(11) NOT NULL default '0',
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `facing` float NOT NULL,
  `o` float NOT NULL,
  `o1` float NOT NULL,
  `o2` float NOT NULL,
  `o3` float NOT NULL,
  `state` int(11) NOT NULL default '0',
  `flags` int(30) NOT NULL default '0',
  `faction` int(11) NOT NULL default '0',
  `scale` float NOT NULL,
  `respawnNpcLink` int(11) NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Spawn System';

-- ----------------------------
-- Table structure for gameobject_tele
-- ----------------------------
DROP TABLE IF EXISTS `gameobject_tele`;
CREATE TABLE `gameobject_tele` (
  `entry` int(10) unsigned NOT NULL,
  `map` int(10) unsigned NOT NULL,
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `o` float NOT NULL,
  UNIQUE KEY `EntryUnique` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for gossip_npc
-- ----------------------------
DROP TABLE IF EXISTS `gossip_npc`;
CREATE TABLE `gossip_npc` (
  `npcid` int(10) unsigned NOT NULL,
  `menutext` varchar(255) NOT NULL,
  `textpage` int(10) unsigned NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for graveyards
-- ----------------------------
DROP TABLE IF EXISTS `graveyards`;
CREATE TABLE `graveyards` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `zoneid` int(10) unsigned NOT NULL default '0',
  `adjacentzoneid` int(10) unsigned NOT NULL default '0',
  `mapid` int(10) unsigned NOT NULL default '0',
  `faction` int(10) unsigned NOT NULL default '0',
  `name` varchar(255) character set utf8 collate utf8_unicode_ci NOT NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `index` (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1299 DEFAULT CHARSET=latin1 COMMENT='Graveyard System';

-- ----------------------------
-- Table structure for guildlinkedvendors
-- ----------------------------
DROP TABLE IF EXISTS `guildlinkedvendors`;
CREATE TABLE `guildlinkedvendors` (
  `entry` int(10) unsigned NOT NULL default '0',
  `reqGuildID` int(30) NOT NULL default '0',
  `reqGuildRank` int(30) NOT NULL,
  PRIMARY KEY  (`entry`),
  UNIQUE KEY `UniqueEntry` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for guildlocations
-- ----------------------------
DROP TABLE IF EXISTS `guildlocations`;
CREATE TABLE `guildlocations` (
  `GuildID` int(10) unsigned NOT NULL,
  `locmap` int(10) unsigned NOT NULL default '0',
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `z` float NOT NULL default '0',
  `o` float NOT NULL default '0',
  PRIMARY KEY  (`GuildID`),
  UNIQUE KEY `Unique` (`GuildID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for item_quest_association
-- ----------------------------
DROP TABLE IF EXISTS `item_quest_association`;
CREATE TABLE `item_quest_association` (
  `item` int(11) NOT NULL default '0',
  `quest` int(11) NOT NULL default '0',
  `item_count` int(11) NOT NULL default '0',
  UNIQUE KEY `item` (`item`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Quest System';

-- ----------------------------
-- Table structure for item_randomprop_groups
-- ----------------------------
DROP TABLE IF EXISTS `item_randomprop_groups`;
CREATE TABLE `item_randomprop_groups` (
  `entry_id` int(30) NOT NULL,
  `randomprops_entryid` int(30) NOT NULL,
  `chance` float NOT NULL,
  PRIMARY KEY  (`entry_id`,`randomprops_entryid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Item System';

-- ----------------------------
-- Table structure for item_randomsuffix_groups
-- ----------------------------
DROP TABLE IF EXISTS `item_randomsuffix_groups`;
CREATE TABLE `item_randomsuffix_groups` (
  `entry_id` int(30) NOT NULL,
  `randomsuffix_entryid` int(30) NOT NULL,
  `chance` float NOT NULL,
  PRIMARY KEY  (`entry_id`,`randomsuffix_entryid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Item System';

-- ----------------------------
-- Table structure for itemloot
-- ----------------------------
DROP TABLE IF EXISTS `itemloot`;
CREATE TABLE `itemloot` (
  `index` int(11) unsigned NOT NULL auto_increment,
  `entryid` int(11) unsigned NOT NULL default '0',
  `itemid` int(11) unsigned NOT NULL default '25',
  `percentchance` float NOT NULL default '0',
  `heroicpercentchance` float NOT NULL default '0',
  `mincount` int(11) unsigned NOT NULL default '1',
  `maxcount` int(11) unsigned NOT NULL default '1',
  `ffa_loot` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`index`),
  UNIQUE KEY `index` (`index`),
  KEY `i_gameobj_loot_entry` (`entryid`)
) ENGINE=MyISAM AUTO_INCREMENT=5198 DEFAULT CHARSET=latin1 COMMENT='Loot System';

-- ----------------------------
-- Table structure for itempages
-- ----------------------------
DROP TABLE IF EXISTS `itempages`;
CREATE TABLE `itempages` (
  `entry` int(10) unsigned NOT NULL default '0',
  `text` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `next_page` int(10) unsigned NOT NULL default '0',
  UNIQUE KEY `entry` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Item System';

-- ----------------------------
-- Table structure for itempages_localized
-- ----------------------------
DROP TABLE IF EXISTS `itempages_localized`;
CREATE TABLE `itempages_localized` (
  `entry` int(30) NOT NULL,
  `language_code` varchar(5) character set latin1 NOT NULL,
  `text` text character set latin1 NOT NULL,
  PRIMARY KEY  (`entry`,`language_code`),
  KEY `a` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for itempetfood
-- ----------------------------
DROP TABLE IF EXISTS `itempetfood`;
CREATE TABLE `itempetfood` (
  `entry` int(11) NOT NULL,
  `food_type` int(11) NOT NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for items
-- ----------------------------
DROP TABLE IF EXISTS `items`;
CREATE TABLE `items` (
  `entry` int(255) unsigned NOT NULL default '0',
  `class` int(30) NOT NULL default '0',
  `subclass` int(30) NOT NULL default '0',
  `field4` int(10) NOT NULL default '-1',
  `name1` varchar(255) NOT NULL,
  `name2` varchar(255) NOT NULL default '',
  `name3` varchar(255) NOT NULL default '',
  `name4` varchar(255) NOT NULL default '',
  `displayid` int(70) unsigned NOT NULL default '0',
  `quality` int(30) NOT NULL default '0',
  `flags` int(30) NOT NULL default '0',
  `buyprice` int(30) NOT NULL default '0',
  `sellprice` int(30) NOT NULL default '0',
  `inventorytype` int(30) NOT NULL default '0',
  `allowableclass` int(30) NOT NULL default '0',
  `allowablerace` int(30) NOT NULL default '0',
  `itemlevel` int(30) NOT NULL default '0',
  `requiredlevel` int(30) NOT NULL default '0',
  `RequiredSkill` int(30) NOT NULL default '0',
  `RequiredSkillRank` int(30) NOT NULL default '0',
  `RequiredSkillSubRank` int(30) NOT NULL default '0',
  `RequiredPlayerRank1` int(30) NOT NULL default '0',
  `RequiredPlayerRank2` int(30) NOT NULL default '0',
  `RequiredFaction` int(30) NOT NULL default '0',
  `RequiredFactionStanding` int(30) NOT NULL default '0',
  `Unique` int(30) NOT NULL default '0',
  `maxcount` int(30) NOT NULL default '0',
  `ContainerSlots` int(30) NOT NULL default '0',
  `stat_type1` int(30) NOT NULL default '0',
  `stat_value1` int(30) NOT NULL default '0',
  `stat_type2` int(30) NOT NULL default '0',
  `stat_value2` int(30) NOT NULL default '0',
  `stat_type3` int(30) NOT NULL default '0',
  `stat_value3` int(30) NOT NULL default '0',
  `stat_type4` int(30) NOT NULL default '0',
  `stat_value4` int(30) NOT NULL default '0',
  `stat_type5` int(30) NOT NULL default '0',
  `stat_value5` int(30) NOT NULL default '0',
  `stat_type6` int(30) NOT NULL default '0',
  `stat_value6` int(30) NOT NULL default '0',
  `stat_type7` int(30) NOT NULL default '0',
  `stat_value7` int(30) NOT NULL default '0',
  `stat_type8` int(30) NOT NULL default '0',
  `stat_value8` int(30) NOT NULL default '0',
  `stat_type9` int(30) NOT NULL default '0',
  `stat_value9` int(30) NOT NULL default '0',
  `stat_type10` int(30) NOT NULL default '0',
  `stat_value10` int(30) NOT NULL default '0',
  `dmg_min1` float NOT NULL default '0',
  `dmg_max1` float NOT NULL default '0',
  `dmg_type1` int(30) NOT NULL default '0',
  `dmg_min2` float NOT NULL default '0',
  `dmg_max2` float NOT NULL default '0',
  `dmg_type2` int(30) NOT NULL default '0',
  `dmg_min3` float NOT NULL default '0',
  `dmg_max3` float NOT NULL default '0',
  `dmg_type3` int(30) NOT NULL default '0',
  `dmg_min4` float NOT NULL default '0',
  `dmg_max4` float NOT NULL default '0',
  `dmg_type4` int(30) NOT NULL default '0',
  `dmg_min5` float NOT NULL default '0',
  `dmg_max5` float NOT NULL default '0',
  `dmg_type5` int(30) NOT NULL default '0',
  `armor` int(30) NOT NULL default '0',
  `holy_res` int(30) NOT NULL default '0',
  `fire_res` int(30) NOT NULL default '0',
  `nature_res` int(30) NOT NULL default '0',
  `frost_res` int(30) NOT NULL default '0',
  `shadow_res` int(30) NOT NULL default '0',
  `arcane_res` int(30) NOT NULL default '0',
  `delay` int(30) NOT NULL default '0',
  `ammo_type` int(30) NOT NULL default '0',
  `range` float NOT NULL default '0',
  `spellid_1` int(30) NOT NULL default '0',
  `spelltrigger_1` int(30) NOT NULL default '0',
  `spellcharges_1` int(30) NOT NULL default '0',
  `spellcooldown_1` int(30) NOT NULL default '0',
  `spellcategory_1` int(30) NOT NULL default '0',
  `spellcategorycooldown_1` int(30) NOT NULL default '0',
  `spellid_2` int(30) NOT NULL default '0',
  `spelltrigger_2` int(30) NOT NULL default '0',
  `spellcharges_2` int(30) NOT NULL default '0',
  `spellcooldown_2` int(30) NOT NULL default '0',
  `spellcategory_2` int(30) NOT NULL default '0',
  `spellcategorycooldown_2` int(30) NOT NULL default '0',
  `spellid_3` int(30) NOT NULL default '0',
  `spelltrigger_3` int(30) NOT NULL default '0',
  `spellcharges_3` int(30) NOT NULL default '0',
  `spellcooldown_3` int(30) NOT NULL default '0',
  `spellcategory_3` int(30) NOT NULL default '0',
  `spellcategorycooldown_3` int(30) NOT NULL default '0',
  `spellid_4` int(30) NOT NULL default '0',
  `spelltrigger_4` int(30) NOT NULL default '0',
  `spellcharges_4` int(30) NOT NULL default '0',
  `spellcooldown_4` int(30) NOT NULL default '0',
  `spellcategory_4` int(30) NOT NULL default '0',
  `spellcategorycooldown_4` int(30) NOT NULL default '0',
  `spellid_5` int(30) NOT NULL default '0',
  `spelltrigger_5` int(30) NOT NULL default '0',
  `spellcharges_5` int(30) NOT NULL default '0',
  `spellcooldown_5` int(30) NOT NULL default '0',
  `spellcategory_5` int(30) NOT NULL default '0',
  `spellcategorycooldown_5` int(30) NOT NULL default '0',
  `bonding` int(30) NOT NULL default '0',
  `description` varchar(255) NOT NULL default '',
  `page_id` int(30) NOT NULL default '0',
  `page_language` int(30) NOT NULL default '0',
  `page_material` int(30) NOT NULL default '0',
  `quest_id` int(30) NOT NULL default '0',
  `lock_id` int(30) NOT NULL default '0',
  `lock_material` int(30) NOT NULL default '0',
  `sheathID` int(30) NOT NULL default '0',
  `randomprop` int(30) NOT NULL default '0',
  `unk203_1` int(11) NOT NULL default '0',
  `block` int(30) NOT NULL default '0',
  `itemset` int(30) NOT NULL default '0',
  `MaxDurability` int(30) NOT NULL default '0',
  `ZoneNameID` int(30) NOT NULL default '0',
  `mapid` int(30) default NULL,
  `bagfamily` int(30) NOT NULL default '0',
  `TotemCategory` int(30) default NULL,
  `socket_color_1` int(30) default NULL,
  `unk201_3` int(30) NOT NULL default '0',
  `socket_color_2` int(30) default NULL,
  `unk201_5` int(30) NOT NULL default '0',
  `socket_color_3` int(30) default NULL,
  `unk201_7` int(30) NOT NULL default '0',
  `socket_bonus` int(30) default NULL,
  `GemProperties` int(30) default NULL,
  `ReqDisenchantSkill` int(30) NOT NULL default '-1',
  `unk2` int(30) NOT NULL default '0',
  `Unrepairable` int(30) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`),
  UNIQUE KEY `entry` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Item System';

-- ----------------------------
-- Table structure for items_extendedcost
-- ----------------------------
DROP TABLE IF EXISTS `items_extendedcost`;
CREATE TABLE `items_extendedcost` (
  `ItemId` int(30) NOT NULL,
  `CostId` int(30) NOT NULL,
  PRIMARY KEY  (`ItemId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for items_localized
-- ----------------------------
DROP TABLE IF EXISTS `items_localized`;
CREATE TABLE `items_localized` (
  `entry` int(30) NOT NULL,
  `language_code` varchar(5) character set utf8 NOT NULL,
  `name` varchar(255) character set utf8 NOT NULL,
  `description` varchar(255) character set utf8 NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for map_checkpoint
-- ----------------------------
DROP TABLE IF EXISTS `map_checkpoint`;
CREATE TABLE `map_checkpoint` (
  `entry` int(30) NOT NULL,
  `prereq_checkpoint_id` int(30) NOT NULL,
  `creature_id` int(30) NOT NULL,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Map System';

-- ----------------------------
-- Table structure for npc_gossip_textid
-- ----------------------------
DROP TABLE IF EXISTS `npc_gossip_textid`;
CREATE TABLE `npc_gossip_textid` (
  `creatureid` int(10) unsigned NOT NULL default '0',
  `textid` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`creatureid`),
  UNIQUE KEY `index` (`creatureid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='NPC System';

-- ----------------------------
-- Table structure for npc_monstersay
-- ----------------------------
DROP TABLE IF EXISTS `npc_monstersay`;
CREATE TABLE `npc_monstersay` (
  `entry` int(10) unsigned NOT NULL default '0',
  `event` int(10) unsigned NOT NULL default '0',
  `chance` float NOT NULL default '0',
  `language` int(10) unsigned NOT NULL default '0',
  `type` int(10) unsigned NOT NULL default '0',
  `monstername` longtext character set utf8 collate utf8_unicode_ci,
  `text0` longtext character set utf8 collate utf8_unicode_ci,
  `text1` longtext character set utf8 collate utf8_unicode_ci,
  `text2` longtext character set utf8 collate utf8_unicode_ci,
  `text3` longtext character set utf8 collate utf8_unicode_ci,
  `text4` longtext character set utf8 collate utf8_unicode_ci
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='NPC System';

-- ----------------------------
-- Table structure for npc_text
-- ----------------------------
DROP TABLE IF EXISTS `npc_text`;
CREATE TABLE `npc_text` (
  `entry` int(10) unsigned NOT NULL default '0',
  `prob0` float NOT NULL default '0',
  `text0_0` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `text0_1` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `lang0` int(10) unsigned NOT NULL default '0',
  `em0_0` int(10) unsigned NOT NULL default '0',
  `em0_1` int(10) unsigned NOT NULL default '0',
  `em0_2` int(10) unsigned NOT NULL default '0',
  `em0_3` int(10) unsigned NOT NULL default '0',
  `em0_4` int(10) unsigned NOT NULL default '0',
  `em0_5` int(10) unsigned NOT NULL default '0',
  `prob1` float NOT NULL default '0',
  `text1_0` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `text1_1` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `lang1` int(10) unsigned NOT NULL default '0',
  `em1_0` int(10) unsigned NOT NULL default '0',
  `em1_1` int(10) unsigned NOT NULL default '0',
  `em1_2` int(10) unsigned NOT NULL default '0',
  `em1_3` int(10) unsigned NOT NULL default '0',
  `em1_4` int(10) unsigned NOT NULL default '0',
  `em1_5` int(10) unsigned NOT NULL default '0',
  `prob2` float NOT NULL default '0',
  `text2_0` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `text2_1` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `lang2` int(10) unsigned NOT NULL default '0',
  `em2_0` int(10) unsigned NOT NULL default '0',
  `em2_1` int(10) unsigned NOT NULL default '0',
  `em2_2` int(10) unsigned NOT NULL default '0',
  `em2_3` int(10) unsigned NOT NULL default '0',
  `em2_4` int(10) unsigned NOT NULL default '0',
  `em2_5` int(10) unsigned NOT NULL default '0',
  `prob3` float NOT NULL default '0',
  `text3_0` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `text3_1` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `lang3` int(10) unsigned NOT NULL default '0',
  `em3_0` int(10) unsigned NOT NULL default '0',
  `em3_1` int(10) unsigned NOT NULL default '0',
  `em3_2` int(10) unsigned NOT NULL default '0',
  `em3_3` int(10) unsigned NOT NULL default '0',
  `em3_4` int(10) unsigned NOT NULL default '0',
  `em3_5` int(10) unsigned NOT NULL default '0',
  `prob4` float NOT NULL default '0',
  `text4_0` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `text4_1` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `lang4` int(10) unsigned NOT NULL default '0',
  `em4_0` int(10) unsigned NOT NULL default '0',
  `em4_1` int(10) unsigned NOT NULL default '0',
  `em4_2` int(10) unsigned NOT NULL default '0',
  `em4_3` int(10) unsigned NOT NULL default '0',
  `em4_4` int(10) unsigned NOT NULL default '0',
  `em4_5` int(10) unsigned NOT NULL default '0',
  `prob5` float NOT NULL default '0',
  `text5_0` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `text5_1` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `lang5` int(10) unsigned NOT NULL default '0',
  `em5_0` int(10) unsigned NOT NULL default '0',
  `em5_1` int(10) unsigned NOT NULL default '0',
  `em5_2` int(10) unsigned NOT NULL default '0',
  `em5_3` int(10) unsigned NOT NULL default '0',
  `em5_4` int(10) unsigned NOT NULL default '0',
  `em5_5` int(10) unsigned NOT NULL default '0',
  `prob6` float NOT NULL default '0',
  `text6_0` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `text6_1` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `lang6` int(10) unsigned NOT NULL default '0',
  `em6_0` int(10) unsigned NOT NULL default '0',
  `em6_1` int(10) unsigned NOT NULL default '0',
  `em6_2` int(10) unsigned NOT NULL default '0',
  `em6_3` int(10) unsigned NOT NULL default '0',
  `em6_4` int(10) unsigned NOT NULL default '0',
  `em6_5` int(10) unsigned NOT NULL default '0',
  `prob7` float NOT NULL default '0',
  `text7_0` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `text7_1` longtext character set utf8 collate utf8_unicode_ci NOT NULL,
  `lang7` int(10) unsigned NOT NULL default '0',
  `em7_0` int(10) unsigned NOT NULL default '0',
  `em7_1` int(10) unsigned NOT NULL default '0',
  `em7_2` int(10) unsigned NOT NULL default '0',
  `em7_3` int(10) unsigned NOT NULL default '0',
  `em7_4` int(10) unsigned NOT NULL default '0',
  `em7_5` int(10) unsigned NOT NULL default '0',
  UNIQUE KEY `entry` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='NPC System';

-- ----------------------------
-- Table structure for npc_text_localized
-- ----------------------------
DROP TABLE IF EXISTS `npc_text_localized`;
CREATE TABLE `npc_text_localized` (
  `entry` int(30) NOT NULL,
  `language_code` varchar(5) character set latin1 NOT NULL,
  `text0` varchar(200) character set latin1 NOT NULL,
  `text0_1` varchar(200) character set latin1 NOT NULL,
  `text1` varchar(200) character set latin1 NOT NULL,
  `text1_1` varchar(200) character set latin1 NOT NULL,
  `text2` varchar(200) character set latin1 NOT NULL,
  `text2_1` varchar(200) character set latin1 NOT NULL,
  `text3` varchar(200) character set latin1 NOT NULL,
  `text3_1` varchar(200) character set latin1 NOT NULL,
  `text4` varchar(200) character set latin1 NOT NULL,
  `text4_1` varchar(200) character set latin1 NOT NULL,
  `text5` varchar(200) character set latin1 NOT NULL,
  `text5_1` varchar(200) character set latin1 NOT NULL,
  `text6` varchar(200) character set latin1 NOT NULL,
  `text6_1` varchar(200) character set latin1 NOT NULL,
  `text7` varchar(200) character set latin1 NOT NULL,
  `text7_1` varchar(200) character set latin1 NOT NULL,
  PRIMARY KEY  (`entry`,`language_code`),
  KEY `lol` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for objectloot
-- ----------------------------
DROP TABLE IF EXISTS `objectloot`;
CREATE TABLE `objectloot` (
  `index` int(11) unsigned NOT NULL auto_increment,
  `entryid` int(11) unsigned NOT NULL default '0',
  `itemid` int(11) unsigned NOT NULL default '0',
  `percentchance` float NOT NULL default '0',
  `heroicpercentchance` float NOT NULL default '0',
  `mincount` int(11) unsigned NOT NULL default '1',
  `maxcount` int(11) unsigned NOT NULL default '1',
  `ffa_loot` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`index`),
  UNIQUE KEY `index` (`index`),
  KEY `entryid` (`entryid`)
) ENGINE=MyISAM AUTO_INCREMENT=5327 DEFAULT CHARSET=latin1 COMMENT='Loot System';

-- ----------------------------
-- Table structure for petdefaultspells
-- ----------------------------
DROP TABLE IF EXISTS `petdefaultspells`;
CREATE TABLE `petdefaultspells` (
  `entry` int(11) NOT NULL default '0',
  `spell` int(11) NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Pet System';

-- ----------------------------
-- Table structure for pickpocketingloot
-- ----------------------------
DROP TABLE IF EXISTS `pickpocketingloot`;
CREATE TABLE `pickpocketingloot` (
  `index` int(11) unsigned NOT NULL auto_increment,
  `entryid` int(11) unsigned NOT NULL default '0',
  `itemid` int(11) unsigned NOT NULL default '25',
  `percentchance` float NOT NULL default '100',
  `heroicpercentchance` float default '0',
  `mincount` int(30) default '1',
  `maxcount` int(30) default '1',
  `ffa_loot` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`index`),
  UNIQUE KEY `index` (`index`)
) ENGINE=MyISAM AUTO_INCREMENT=14130 DEFAULT CHARSET=latin1 COMMENT='Loot System';

-- ----------------------------
-- Table structure for playercreateinfo
-- ----------------------------
DROP TABLE IF EXISTS `playercreateinfo`;
CREATE TABLE `playercreateinfo` (
  `Index` tinyint(3) unsigned NOT NULL auto_increment,
  `race` tinyint(3) unsigned NOT NULL default '0',
  `factiontemplate` int(10) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `mapID` int(10) unsigned NOT NULL default '0',
  `zoneID` int(10) unsigned NOT NULL default '0',
  `positionX` float NOT NULL default '0',
  `positionY` float NOT NULL default '0',
  `positionZ` float NOT NULL default '0',
  `displayID` smallint(5) unsigned NOT NULL default '0',
  `BaseStrength` tinyint(3) unsigned NOT NULL default '0',
  `BaseAgility` tinyint(3) unsigned NOT NULL default '0',
  `BaseStamina` tinyint(3) unsigned NOT NULL default '0',
  `BaseIntellect` tinyint(3) unsigned NOT NULL default '0',
  `BaseSpirit` tinyint(3) unsigned NOT NULL default '0',
  `BaseHealth` int(10) unsigned NOT NULL default '0',
  `BaseMana` int(10) unsigned NOT NULL default '0',
  `BaseRage` int(10) unsigned NOT NULL default '0',
  `BaseFocus` int(10) unsigned NOT NULL default '0',
  `BaseEnergy` int(10) unsigned NOT NULL default '0',
  `attackpower` int(10) unsigned NOT NULL default '0',
  `mindmg` float NOT NULL default '0',
  `maxdmg` float NOT NULL default '0',
  PRIMARY KEY  (`Index`)
) ENGINE=MyISAM AUTO_INCREMENT=56 DEFAULT CHARSET=latin1 COMMENT='Player System';

-- ----------------------------
-- Table structure for playercreateinfo_bars
-- ----------------------------
DROP TABLE IF EXISTS `playercreateinfo_bars`;
CREATE TABLE `playercreateinfo_bars` (
  `race` tinyint(3) unsigned default NULL,
  `class` tinyint(3) unsigned default NULL,
  `button` int(10) unsigned default NULL,
  `action` int(10) unsigned default NULL,
  `type` int(10) unsigned default NULL,
  `misc` int(10) unsigned default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Player System';

-- ----------------------------
-- Table structure for playercreateinfo_items
-- ----------------------------
DROP TABLE IF EXISTS `playercreateinfo_items`;
CREATE TABLE `playercreateinfo_items` (
  `indexid` tinyint(3) unsigned NOT NULL default '0',
  `protoid` int(10) unsigned NOT NULL default '0',
  `slotid` tinyint(3) unsigned NOT NULL default '0',
  `amount` int(10) unsigned NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Player System';

-- ----------------------------
-- Table structure for playercreateinfo_skills
-- ----------------------------
DROP TABLE IF EXISTS `playercreateinfo_skills`;
CREATE TABLE `playercreateinfo_skills` (
  `indexid` tinyint(3) unsigned NOT NULL default '0',
  `skillid` int(10) unsigned NOT NULL default '0',
  `level` int(10) unsigned NOT NULL default '0',
  `maxlevel` int(10) unsigned NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Player System';

-- ----------------------------
-- Table structure for playercreateinfo_spells
-- ----------------------------
DROP TABLE IF EXISTS `playercreateinfo_spells`;
CREATE TABLE `playercreateinfo_spells` (
  `indexid` tinyint(3) unsigned NOT NULL default '0',
  `spellid` smallint(5) unsigned NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Player System';

-- ----------------------------
-- Table structure for plr_reports
-- ----------------------------
DROP TABLE IF EXISTS `plr_reports`;
CREATE TABLE `plr_reports` (
  `ReportID` int(10) unsigned NOT NULL,
  `ReporterChar` varchar(21) NOT NULL,
  `ReporterAcct` varchar(20) NOT NULL,
  `ReporterIP` varchar(15) NOT NULL,
  `ReportedChar` varchar(21) NOT NULL,
  `ReportedAcct` varchar(20) NOT NULL,
  `ReportedIP` varchar(15) NOT NULL,
  `Reason` varchar(255) NOT NULL,
  PRIMARY KEY  (`ReportID`),
  UNIQUE KEY `RepIDUnique` (`ReportID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for professiondiscoveries
-- ----------------------------
DROP TABLE IF EXISTS `professiondiscoveries`;
CREATE TABLE `professiondiscoveries` (
  `SpellId` int(10) unsigned NOT NULL default '0',
  `SpellToDiscover` int(10) unsigned NOT NULL default '0',
  `SkillValue` int(10) unsigned NOT NULL default '0',
  `Chance` float NOT NULL default '0',
  PRIMARY KEY  (`SpellId`,`SpellToDiscover`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for prospectingloot
-- ----------------------------
DROP TABLE IF EXISTS `prospectingloot`;
CREATE TABLE `prospectingloot` (
  `index` int(11) unsigned NOT NULL auto_increment,
  `entryid` int(11) unsigned NOT NULL default '0',
  `itemid` int(11) unsigned NOT NULL default '25',
  `percentchance` float NOT NULL default '0',
  `heroicpercentchance` float NOT NULL default '0',
  `mincount` int(11) unsigned NOT NULL default '1',
  `maxcount` int(11) unsigned NOT NULL default '1',
  `ffa_loot` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`index`),
  UNIQUE KEY `index` (`index`)
) ENGINE=MyISAM AUTO_INCREMENT=84 DEFAULT CHARSET=latin1 COMMENT='Loot System';

-- ----------------------------
-- Table structure for quests
-- ----------------------------
DROP TABLE IF EXISTS `quests`;
CREATE TABLE `quests` (
  `entry` int(10) unsigned NOT NULL default '0',
  `ZoneId` int(10) unsigned NOT NULL default '0',
  `sort` int(10) unsigned NOT NULL default '0',
  `flags` int(10) unsigned NOT NULL default '0',
  `MinLevel` int(10) unsigned NOT NULL default '0',
  `questlevel` int(10) unsigned NOT NULL default '0',
  `Type` int(10) unsigned NOT NULL default '0',
  `RequiredRaces` int(10) unsigned NOT NULL default '0',
  `RequiredClass` int(10) unsigned NOT NULL default '0',
  `ReqAccess` int(10) unsigned NOT NULL default '0',
  `RequiredTradeskill` int(10) unsigned NOT NULL default '0',
  `RequiredTradeskillValue` int(5) unsigned NOT NULL default '0',
  `RequiredRepFaction` int(10) unsigned NOT NULL default '0',
  `RequiredRepValue` int(10) unsigned NOT NULL default '0',
  `LimitTime` int(10) unsigned NOT NULL default '0',
  `SpecialFlags` int(10) unsigned NOT NULL default '0',
  `PrevQuestId` int(10) unsigned NOT NULL default '0',
  `NextQuestId` int(10) unsigned NOT NULL default '0',
  `srcItem` int(10) unsigned NOT NULL default '0',
  `SrcItemCount` int(10) unsigned NOT NULL default '0',
  `Title` char(255) NOT NULL,
  `Details` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `Objectives` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `CompletionText` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `IncompleteText` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `EndText` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `ObjectiveText1` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `ObjectiveText2` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `ObjectiveText3` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `ObjectiveText4` text character set utf8 collate utf8_unicode_ci NOT NULL,
  `ReqItemId1` int(10) unsigned NOT NULL default '0',
  `ReqItemId2` int(10) unsigned NOT NULL default '0',
  `ReqItemId3` int(10) unsigned NOT NULL default '0',
  `ReqItemId4` int(10) unsigned NOT NULL default '0',
  `ReqItemCount1` int(10) unsigned NOT NULL default '0',
  `ReqItemCount2` int(10) unsigned NOT NULL default '0',
  `ReqItemCount3` int(10) unsigned NOT NULL default '0',
  `ReqItemCount4` int(10) unsigned NOT NULL default '0',
  `ReqKillMobOrGOId1` int(10) unsigned NOT NULL default '0',
  `ReqKillMobOrGOId2` int(10) unsigned NOT NULL default '0',
  `ReqKillMobOrGOId3` int(10) unsigned NOT NULL default '0',
  `ReqKillMobOrGOId4` int(10) unsigned NOT NULL default '0',
  `ReqKillMobOrGOCount1` int(10) unsigned NOT NULL default '0',
  `ReqKillMobOrGOCount2` int(10) unsigned NOT NULL default '0',
  `ReqKillMobOrGOCount3` int(10) unsigned NOT NULL default '0',
  `ReqKillMobOrGOCount4` int(10) unsigned NOT NULL default '0',
  `ReqCastSpellId1` int(11) NOT NULL default '0',
  `ReqCastSpellId2` int(11) NOT NULL default '0',
  `ReqCastSpellId3` int(11) NOT NULL default '0',
  `ReqCastSpellId4` int(11) NOT NULL default '0',
  `RewChoiceItemId1` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemId2` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemId3` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemId4` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemId5` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemId6` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemCount1` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemCount2` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemCount3` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemCount4` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemCount5` int(10) unsigned NOT NULL default '0',
  `RewChoiceItemCount6` int(10) unsigned NOT NULL default '0',
  `RewItemId1` int(10) unsigned NOT NULL default '0',
  `RewItemId2` int(10) unsigned NOT NULL default '0',
  `RewItemId3` int(10) unsigned NOT NULL default '0',
  `RewItemId4` int(10) unsigned NOT NULL default '0',
  `RewItemCount1` int(10) unsigned NOT NULL default '0',
  `RewItemCount2` int(10) unsigned NOT NULL default '0',
  `RewItemCount3` int(10) unsigned NOT NULL default '0',
  `RewItemCount4` int(10) unsigned NOT NULL default '0',
  `RewRepFaction1` int(10) unsigned NOT NULL default '0',
  `RewRepFaction2` int(10) unsigned NOT NULL default '0',
  `RewRepValue1` int(10) NOT NULL default '0',
  `RewRepValue2` int(10) NOT NULL default '0',
  `RewRepLimit` int(10) unsigned NOT NULL default '0',
  `RewMoney` int(10) NOT NULL default '0',
  `RewXP` int(10) unsigned NOT NULL default '0',
  `RewSpell` int(10) unsigned NOT NULL default '0',
  `CastSpell` int(10) unsigned NOT NULL default '0',
  `PointMapId` int(10) unsigned NOT NULL default '0',
  `PointX` float NOT NULL default '0',
  `PointY` float NOT NULL default '0',
  `PointOpt` int(10) unsigned NOT NULL default '0',
  `RewardMoneyAtMaxLevel` int(10) unsigned NOT NULL default '0',
  `ExploreTrigger1` int(10) unsigned NOT NULL default '0',
  `ExploreTrigger2` int(10) unsigned NOT NULL default '0',
  `ExploreTrigger3` int(10) unsigned NOT NULL default '0',
  `ExploreTrigger4` int(10) unsigned NOT NULL default '0',
  `RequiredQuest1` int(10) unsigned NOT NULL default '0',
  `RequiredQuest2` int(10) unsigned NOT NULL default '0',
  `RequiredQuest3` int(10) unsigned NOT NULL default '0',
  `RequiredQuest4` int(10) unsigned NOT NULL default '0',
  `ReceiveItemId1` int(10) unsigned NOT NULL default '0',
  `ReceiveItemId2` int(10) unsigned NOT NULL default '0',
  `ReceiveItemId3` int(10) unsigned NOT NULL default '0',
  `ReceiveItemId4` int(10) unsigned NOT NULL default '0',
  `ReceiveItemCount1` int(10) unsigned NOT NULL default '0',
  `ReceiveItemCount2` int(10) unsigned NOT NULL default '0',
  `ReceiveItemCount3` int(10) unsigned NOT NULL default '0',
  `ReceiveItemCount4` int(10) unsigned NOT NULL default '0',
  `IsRepeatable` int(11) NOT NULL default '0',
  PRIMARY KEY  (`entry`),
  UNIQUE KEY `entry` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Quests System';

-- ----------------------------
-- Table structure for quests_localized
-- ----------------------------
DROP TABLE IF EXISTS `quests_localized`;
CREATE TABLE `quests_localized` (
  `entry` int(30) NOT NULL,
  `language_code` varchar(5) character set latin1 NOT NULL,
  `Title` text character set latin1 NOT NULL,
  `Details` text character set latin1 NOT NULL,
  `Objectives` text character set latin1 NOT NULL,
  `CompletionText` text character set latin1 NOT NULL,
  `IncompleteText` text character set latin1 NOT NULL,
  `EndText` text character set latin1 NOT NULL,
  `ObjectiveText1` text character set latin1 NOT NULL,
  `ObjectiveText2` text character set latin1 NOT NULL,
  `ObjectiveText3` text character set latin1 NOT NULL,
  `ObjectiveText4` text character set latin1 NOT NULL,
  PRIMARY KEY  (`entry`,`language_code`),
  KEY `lol` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- ----------------------------
-- Table structure for recall
-- ----------------------------
DROP TABLE IF EXISTS `recall`;
CREATE TABLE `recall` (
  `id` bigint(20) unsigned NOT NULL auto_increment,
  `name` varchar(100) NOT NULL,
  `MapId` int(10) unsigned NOT NULL default '0',
  `positionX` float NOT NULL default '0',
  `positionY` float NOT NULL default '0',
  `positionZ` float NOT NULL default '0',
  `GMonly` int(30) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=759 DEFAULT CHARSET=utf8 COMMENT='Tele Command';

-- ----------------------------
-- Table structure for reputation_creature_onkill
-- ----------------------------
DROP TABLE IF EXISTS `reputation_creature_onkill`;
CREATE TABLE `reputation_creature_onkill` (
  `creature_id` int(30) NOT NULL,
  `faction_change_alliance` int(30) NOT NULL,
  `faction_change_horde` int(30) NOT NULL,
  `change_value` int(30) NOT NULL,
  `rep_limit` int(30) NOT NULL,
  KEY `index` (`creature_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Creature System';

-- ----------------------------
-- Table structure for reputation_faction_onkill
-- ----------------------------
DROP TABLE IF EXISTS `reputation_faction_onkill`;
CREATE TABLE `reputation_faction_onkill` (
  `faction_id` int(30) NOT NULL,
  `change_factionid_alliance` int(30) NOT NULL,
  `change_deltamin_alliance` int(30) NOT NULL,
  `change_deltamax_alliance` int(30) NOT NULL,
  `change_factionid_horde` int(30) NOT NULL,
  `change_deltamin_horde` int(30) NOT NULL,
  `change_deltamax_horde` int(30) NOT NULL,
  KEY `factindex` (`faction_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Creature System';

-- ----------------------------
-- Table structure for reputation_instance_onkill
-- ----------------------------
DROP TABLE IF EXISTS `reputation_instance_onkill`;
CREATE TABLE `reputation_instance_onkill` (
  `mapid` int(30) NOT NULL,
  `mob_rep_reward` int(30) NOT NULL,
  `mob_rep_limit` int(30) NOT NULL,
  `boss_rep_reward` int(30) NOT NULL,
  `boss_rep_limit` int(30) NOT NULL,
  `faction_change_alliance` int(30) NOT NULL,
  `faction_change_horde` int(30) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Creature System';

-- ----------------------------
-- Table structure for saved_scroll_locations
-- ----------------------------
DROP TABLE IF EXISTS `saved_scroll_locations`;
CREATE TABLE `saved_scroll_locations` (
  `playerGuid` int(6) unsigned NOT NULL,
  `mapID` int(10) NOT NULL,
  `X` float NOT NULL,
  `Y` float NOT NULL,
  `Z` float NOT NULL,
  `O` float NOT NULL,
  PRIMARY KEY  (`playerGuid`),
  UNIQUE KEY `Unique` (`playerGuid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for skinningloot
-- ----------------------------
DROP TABLE IF EXISTS `skinningloot`;
CREATE TABLE `skinningloot` (
  `index` int(11) unsigned NOT NULL auto_increment,
  `entryid` int(10) unsigned NOT NULL default '0',
  `itemid` int(10) unsigned NOT NULL default '0',
  `percentchance` float NOT NULL default '0',
  `heroicpercentchance` float default '0',
  `mincount` int(30) default '1',
  `maxcount` int(30) default '1',
  `ffa_loot` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`index`),
  UNIQUE KEY `index` (`index`)
) ENGINE=MyISAM AUTO_INCREMENT=2912 DEFAULT CHARSET=latin1 COMMENT='Loot System';

-- ----------------------------
-- Table structure for spell_coef_override
-- ----------------------------
DROP TABLE IF EXISTS `spell_coef_override`;
CREATE TABLE `spell_coef_override` (
  `id` double default NULL,
  `name` varchar(300) default NULL,
  `Dspell_coef_override` float default NULL,
  `OTspell_coef_override` float default NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for spell_disable
-- ----------------------------
DROP TABLE IF EXISTS `spell_disable`;
CREATE TABLE `spell_disable` (
  `spellid` int(30) NOT NULL,
  `replacement_spellid` int(30) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Spell System';

-- ----------------------------
-- Table structure for spell_disable_trainers
-- ----------------------------
DROP TABLE IF EXISTS `spell_disable_trainers`;
CREATE TABLE `spell_disable_trainers` (
  `spellid` int(30) NOT NULL,
  `replacement_spellid` int(30) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Trainer System';

-- ----------------------------
-- Table structure for spell_effects_override
-- ----------------------------
DROP TABLE IF EXISTS `spell_effects_override`;
CREATE TABLE `spell_effects_override` (
  `spellId` int(30) NOT NULL default '0',
  `EffectID` int(30) NOT NULL,
  `Disable` int(30) NOT NULL,
  `Effect` int(30) NOT NULL default '0',
  `BasePoints` int(30) NOT NULL default '0',
  `ApplyAuraName` int(30) NOT NULL default '0',
  `SpellGroupRelation` int(30) NOT NULL default '0',
  `MiscValue` int(30) NOT NULL default '0',
  `TriggerSpell` int(30) NOT NULL default '0',
  `ImplicitTargetA` int(30) NOT NULL default '0',
  `ImplicitTargetB` int(30) NOT NULL default '0',
  PRIMARY KEY  (`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for spell_proc
-- ----------------------------
DROP TABLE IF EXISTS `spell_proc`;
CREATE TABLE `spell_proc` (
  `spellID` int(30) NOT NULL default '0',
  `ProcOnNameHash` int(30) unsigned NOT NULL default '0',
  PRIMARY KEY  (`spellID`,`ProcOnNameHash`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for spell_proc_data
-- ----------------------------
DROP TABLE IF EXISTS `spell_proc_data`;
CREATE TABLE `spell_proc_data` (
  `name_hash` int(30) NOT NULL,
  `proc_chance` int(30) NOT NULL,
  `forced_proc_flags` int(30) NOT NULL default '-1',
  PRIMARY KEY  (`name_hash`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for spell_spell_relation
-- ----------------------------
DROP TABLE IF EXISTS `spell_spell_relation`;
CREATE TABLE `spell_spell_relation` (
  `spellId` int(10) unsigned NOT NULL,
  `spellToLearn` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`spellId`,`spellToLearn`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for spellfixes
-- ----------------------------
DROP TABLE IF EXISTS `spellfixes`;
CREATE TABLE `spellfixes` (
  `spellId` int(30) NOT NULL default '0',
  `procFlags` int(30) NOT NULL default '0',
  `SpellGroupType` int(30) NOT NULL default '0',
  `procChance` int(30) NOT NULL default '0',
  `procCharges` int(30) NOT NULL default '0',
  PRIMARY KEY  (`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for spelloverride
-- ----------------------------
DROP TABLE IF EXISTS `spelloverride`;
CREATE TABLE `spelloverride` (
  `overrideId` int(10) unsigned NOT NULL default '0',
  `spellId` int(10) unsigned NOT NULL default '0',
  UNIQUE KEY `overrideId` (`overrideId`,`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Spell System';

-- ----------------------------
-- Table structure for talentpoints
-- ----------------------------
DROP TABLE IF EXISTS `talentpoints`;
CREATE TABLE `talentpoints` (
  `guid` int(6) unsigned NOT NULL default '0',
  `LevelAtReset` int(3) NOT NULL default '1',
  `TalentPoints` int(30) NOT NULL default '1',
  PRIMARY KEY  (`guid`),
  UNIQUE KEY `Unique_guid` (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for teleport_coords
-- ----------------------------
DROP TABLE IF EXISTS `teleport_coords`;
CREATE TABLE `teleport_coords` (
  `id` int(10) unsigned NOT NULL default '0',
  `name` char(255) character set utf8 collate utf8_unicode_ci NOT NULL,
  `mapId` int(10) unsigned NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `totrigger` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='World System';

-- ----------------------------
-- Table structure for totemspells
-- ----------------------------
DROP TABLE IF EXISTS `totemspells`;
CREATE TABLE `totemspells` (
  `spell` int(10) unsigned NOT NULL default '0',
  `castspell1` int(10) unsigned NOT NULL default '0',
  `castspell2` int(10) unsigned NOT NULL default '0',
  `castspell3` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`spell`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Spell System';

-- ----------------------------
-- Table structure for trainer_defs
-- ----------------------------
DROP TABLE IF EXISTS `trainer_defs`;
CREATE TABLE `trainer_defs` (
  `entry` int(11) unsigned NOT NULL default '0',
  `required_skill` int(11) unsigned NOT NULL default '0',
  `required_skillvalue` int(11) unsigned default '0',
  `req_class` int(11) unsigned NOT NULL default '0',
  `trainer_type` int(11) unsigned NOT NULL default '0',
  `trainer_ui_window_message` text,
  `can_train_gossip_textid` int(11) NOT NULL,
  `cannot_train_gossip_textid` int(11) NOT NULL,
  PRIMARY KEY  (`entry`),
  UNIQUE KEY `entry` (`entry`),
  KEY `entry_2` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Trainer System';

-- ----------------------------
-- Table structure for trainer_spells
-- ----------------------------
DROP TABLE IF EXISTS `trainer_spells`;
CREATE TABLE `trainer_spells` (
  `entry` int(11) unsigned NOT NULL default '0',
  `cast_spell` int(11) unsigned NOT NULL default '0',
  `learn_spell` int(11) unsigned NOT NULL default '0',
  `spellcost` int(11) unsigned NOT NULL default '0',
  `reqspell` int(11) unsigned NOT NULL default '0',
  `reqskill` int(11) unsigned NOT NULL default '0',
  `reqskillvalue` int(11) unsigned NOT NULL default '0',
  `reqlevel` int(11) unsigned NOT NULL default '0',
  `deletespell` int(11) unsigned NOT NULL default '0',
  `is_prof` tinyint(1) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`cast_spell`,`learn_spell`),
  KEY `entry` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Trainer System';

-- ----------------------------
-- Table structure for trainerspelloverride
-- ----------------------------
DROP TABLE IF EXISTS `trainerspelloverride`;
CREATE TABLE `trainerspelloverride` (
  `spellid` int(10) unsigned NOT NULL default '0',
  `cost` int(10) unsigned NOT NULL default '0',
  `requiredspell` int(10) unsigned NOT NULL default '0',
  `deletespell` int(10) unsigned NOT NULL default '0',
  `requiredskill` int(10) unsigned NOT NULL default '0',
  `requiredskillvalue` int(10) unsigned NOT NULL default '0',
  `reqlevel` int(10) unsigned NOT NULL default '0',
  `requiredclass` int(10) unsigned NOT NULL default '0',
  UNIQUE KEY `spellid` (`spellid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Trainer System';

-- ----------------------------
-- Table structure for transport_creatures
-- ----------------------------
DROP TABLE IF EXISTS `transport_creatures`;
CREATE TABLE `transport_creatures` (
  `transport_entry` int(10) unsigned NOT NULL,
  `creature_entry` int(10) unsigned NOT NULL,
  `position_x` float NOT NULL,
  `position_y` float NOT NULL,
  `position_z` float NOT NULL,
  `orientation` float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for transport_data
-- ----------------------------
DROP TABLE IF EXISTS `transport_data`;
CREATE TABLE `transport_data` (
  `entry` int(10) unsigned NOT NULL default '0',
  `name` text character set utf8 collate utf8_unicode_ci,
  `period` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='World System';

-- ----------------------------
-- Table structure for unit_display_sizes
-- ----------------------------
DROP TABLE IF EXISTS `unit_display_sizes`;
CREATE TABLE `unit_display_sizes` (
  `DisplayID` int(11) unsigned NOT NULL,
  `halfsize` float NOT NULL default '1',
  `modelid` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`DisplayID`),
  UNIQUE KEY `DisplayID` (`DisplayID`),
  KEY `DisplayID_2` (`DisplayID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

-- ----------------------------
-- Table structure for vendors
-- ----------------------------
DROP TABLE IF EXISTS `vendors`;
CREATE TABLE `vendors` (
  `entry` int(10) unsigned NOT NULL default '0',
  `item` int(10) unsigned NOT NULL default '0',
  `amount` int(11) NOT NULL default '0',
  `max_amount` int(11) NOT NULL default '0',
  `inctime` bigint(20) NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='NPC System';

-- ----------------------------
-- Table structure for warnsystem
-- ----------------------------
DROP TABLE IF EXISTS `warnsystem`;
CREATE TABLE `warnsystem` (
  `WarnID` int(10) unsigned NOT NULL,
  `GMAcct` varchar(20) NOT NULL,
  `WarnedChar` varchar(21) NOT NULL,
  `WarnedAcct` varchar(20) NOT NULL,
  `WarnedIP` varchar(15) NOT NULL,
  `pReason` varchar(255) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for weather
-- ----------------------------
DROP TABLE IF EXISTS `weather`;
CREATE TABLE `weather` (
  `zoneId` int(11) unsigned NOT NULL default '0',
  `high_chance` int(11) unsigned NOT NULL default '0',
  `high_type` int(11) unsigned NOT NULL default '0',
  `med_chance` int(11) unsigned NOT NULL default '0',
  `med_type` int(11) unsigned NOT NULL default '0',
  `low_chance` int(11) unsigned NOT NULL default '0',
  `low_type` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`zoneId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Weather System';

-- ----------------------------
-- Table structure for wordfilter_character_names
-- ----------------------------
DROP TABLE IF EXISTS `wordfilter_character_names`;
CREATE TABLE `wordfilter_character_names` (
  `regex_match` varchar(500) NOT NULL,
  `regex_ignore_if_matched` varchar(500) NOT NULL default ''
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for wordfilter_chat
-- ----------------------------
DROP TABLE IF EXISTS `wordfilter_chat`;
CREATE TABLE `wordfilter_chat` (
  `regex_match` varchar(500) NOT NULL,
  `regex_ignore_if_matched` varchar(500) NOT NULL default ''
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for worldmap_info
-- ----------------------------
DROP TABLE IF EXISTS `worldmap_info`;
CREATE TABLE `worldmap_info` (
  `entry` int(10) unsigned NOT NULL default '0',
  `screenid` int(10) unsigned default '0',
  `type` int(10) unsigned default '0',
  `maxplayers` int(10) unsigned default '0',
  `minlevel` int(10) unsigned default '1',
  `repopx` float default '0',
  `repopy` float default '0',
  `repopz` float default '0',
  `repopentry` int(10) unsigned default '0',
  `area_name` varchar(100) character set utf8 collate utf8_unicode_ci default '0',
  `flags` int(10) unsigned NOT NULL default '0',
  `cooldown` int(10) unsigned NOT NULL default '0',
  `lvl_mod_a` int(10) unsigned NOT NULL default '0',
  `required_quest` int(10) unsigned NOT NULL default '0',
  `required_item` int(10) unsigned NOT NULL default '0',
  `required_heroicspell` int(10) unsigned NOT NULL default '0',
  `heroic_keyid_1` int(30) NOT NULL default '0',
  `heroic_keyid_2` int(30) NOT NULL default '0',
  `viewingDistance` float NOT NULL default '80',
  `required_checkpoint` int(30) NOT NULL default '0',
  `required_access` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='World System';

-- ----------------------------
-- Table structure for zoneguards
-- ----------------------------
DROP TABLE IF EXISTS `zoneguards`;
CREATE TABLE `zoneguards` (
  `zone` int(10) unsigned NOT NULL,
  `horde_entry` int(10) unsigned default NULL,
  `alliance_entry` int(10) unsigned default NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='World System';


