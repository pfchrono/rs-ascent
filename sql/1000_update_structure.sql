-- ----------------------------
-- Table structure for disconnectionqueue
-- ----------------------------
DROP TABLE IF EXISTS `disconnectionqueue`;
CREATE TABLE `disconnectionqueue` (
  `CharName` varchar(21) NOT NULL,
  PRIMARY KEY  (`CharName`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

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
-- Table structure for spell_spell_relation
-- ----------------------------
DROP TABLE IF EXISTS `spell_spell_relation`;
CREATE TABLE `spell_spell_relation` (
  `spellId` int(10) unsigned NOT NULL,
  `spellToLearn` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`spellId`,`spellToLearn`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

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

ALTER TABLE `creature_names` ADD COLUMN `GuardType` int(10) unsigned NOT NULL default '0';

ALTER TABLE `quests` ADD COLUMN `ReqAccess` int(10) unsigned NOT NULL default '0';

ALTER TABLE `quests` ADD COLUMN `reward_title` int(10) unsigned NOT NULL default '0' AFTER `CastSpell`;

ALTER TABLE `recall` ADD COLUMN `GMonly` int(30) unsigned NOT NULL default '0';

ALTER TABLE `worldmap_info` ADD COLUMN `required_access` int(10) unsigned NOT NULL default '0';

ALTER TABLE `items` ADD `Unrepairable` int(30) unsigned NOT NULL default '0';

ALTER TABLE `worldmap_info` ADD COLUMN `required_heroicspell` int(10) unsigned NOT NULL default '0' AFTER required_item;