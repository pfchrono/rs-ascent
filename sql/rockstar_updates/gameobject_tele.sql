/*
MySQL Data Transfer
Source Host: localhost
Source Database: rockstar
Target Host: localhost
Target Database: rockstar
Date: 22-8-2008 4:45:50
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for gameobject_tele
-- ----------------------------
CREATE TABLE `gameobject_tele` (
  `entry` int(10) unsigned NOT NULL,
  `map` int(10) unsigned NOT NULL,
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `o` float NOT NULL,
  `welcomeMsg` varchar(100) NOT NULL,
  `errorMsg` varchar(100) NOT NULL,
  `reqlevel` int(10) unsigned NOT NULL default '0',
  `reqfaction` int(10) NOT NULL default '-1',
  `reqaccess` int(10) unsigned NOT NULL default '0',
  `reqtbc` int(10) unsigned NOT NULL default '0',
  UNIQUE KEY `EntryUnique` (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `gameobject_tele` VALUES ('74000001', '37', '-618.95', '-283.428', '353', '0.98', '', '', '0', '-1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('700154', '30', '30.9569', '-302.92', '15.6921', '6.19679', '', '', '0', '-1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('700152', '530', '12933.3', '-6906.65', '5.26956', '3.53725', '', '', '0', '-1', '0', '1');
INSERT INTO `gameobject_tele` VALUES ('740008', '0', '-13226.2', '231.99', '33.29', '0.98', '', '', '0', '-1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('700010', '1', '-10745', '2422.51', '7.41', '0', '', '', '0', '-1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('610000', '530', '-363.34', '3159.77', '-95.95', '0', '', '', '0', '-1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('820011', '0', '-895.8', '1564.1', '41.8207', '0', 'Welcome to the Maze! *evil grin*', '', '0', '-1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('700020', '1', '7422.44', '-1579.46', '180.53', '6.06', '', 'Only Horde is to be allowed through this portal', '0', '1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('700021', '0', '-4637.5', '-1691.72', '505.284', '0', '', 'Only Alliance is to be allowed through this portal', '0', '0', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('820047', '1', '1806.04', '-4403.54', '-16.57', '0', '', 'You need to be level 90 to advance', '90', '-1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('820004', '269', '-1542.1', '7109.6', '32.8', '0', '', 'You need to be level 90 to advance', '90', '-1', '0', '0');
INSERT INTO `gameobject_tele` VALUES ('740005', '30', '23.9825', '-298.187', '14.3892', '0', '', '', '0', '-1', '0', '0');
