/*
MySQL Data Transfer
Source Host: localhost
Source Database: whydb
Target Host: localhost
Target Database: whydb
Date: 6-10-2008 22:24:40
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for bug_tracker
-- ----------------------------
CREATE TABLE `bug_tracker` (
  `ReportID` int(11) NOT NULL,
  `reporterGuid` int(11) NOT NULL,
  `reporterAcct` varchar(32) NOT NULL,
  `reporterIP` varchar(16) NOT NULL,
  `charName` varchar(21) NOT NULL,
  `BugDesc` varchar(255) NOT NULL,
  `timestamp` text,
  `status` int(11) NOT NULL,
  `assignedTo` varchar(21) NOT NULL,
  `comment` varchar(255) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
