/*
MySQL Data Transfer
Source Host: localhost
Source Database: rockstar
Target Host: localhost
Target Database: rockstar
Date: 31-8-2008 23:17:01
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for news_timers
-- ----------------------------
CREATE TABLE `news_timers` (
  `id` int(10) unsigned NOT NULL,
  `t` int(10) unsigned default NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
