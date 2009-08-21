/*
MySQL Data Transfer
Source Host: localhost
Source Database: rockstar
Target Host: localhost
Target Database: rockstar
Date: 31-8-2008 23:16:55
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for news_announcements
-- ----------------------------
CREATE TABLE `news_announcements` (
  `id` int(10) unsigned NOT NULL,
  `factionMask` int(11) NOT NULL,
  `timePeriod` int(10) unsigned NOT NULL,
  `message` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
