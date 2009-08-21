/*
SQLyog Enterprise - MySQL GUI v7.02 
MySQL - 5.1.26-rc-community : Database - summit
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

/*Table structure for table `worldstate_template` */

DROP TABLE IF EXISTS `worldstate_template`;

CREATE TABLE `worldstate_template` (
  `mapid` int(30) unsigned NOT NULL,
  `zone_mask` int(30) NOT NULL,
  `faction_mask` int(30) NOT NULL,
  `field_number` int(30) unsigned NOT NULL,
  `initial_value` int(30) NOT NULL,
  `comment` varchar(200) NOT NULL,
  PRIMARY KEY (`field_number`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `worldstate_template` */

insert  into `worldstate_template`(`mapid`,`zone_mask`,`faction_mask`,`field_number`,`initial_value`,`comment`) values (530,3483,-1,2476,0,'WORLDSTATE_HELLFIRE_ALLIANCE_TOWERS_CONTROLLED'),(530,3483,-1,2478,0,'WORLDSTATE_HELLFIRE_HORDE_TOWERS_CONTROLLED'),(530,3483,-1,2490,1,'WORLDSTATE_HELLFIRE_TOWER_DISPLAY_ALLIANCE'),(530,3483,-1,2489,1,'WORLDSTATE_HELLFIRE_TOWER_DISPLAY_HORDE'),(530,3483,-1,2473,0,'WORLDSTATE_HELLFIRE_PVP_CAPTURE_BAR_DISPLAY'),(530,3483,-1,2474,0,'WORLDSTATE_HELLFIRE_PVP_CAPTURE_BAR_VALUE'),(530,3483,-1,2472,1,'WORLDSTATE_HELLFIRE_STADIUM_NEUTRAL'),(530,3483,-1,2471,0,'WORLDSTATE_HELLFIRE_STADIUM_ALLIANCE'),(530,3483,-1,2470,0,'WORLDSTATE_HELLFIRE_STADIUM_HORDE'),(530,3483,-1,2482,1,'WORLDSTATE_HELLFIRE_OVERLOOK_NEUTRAL'),(530,3483,-1,2480,0,'WORLDSTATE_HELLFIRE_OVERLOOK_ALLIANCE'),(530,3483,-1,2481,0,'WORLDSTATE_HELLFIRE_OVERLOOK_HORDE'),(530,3483,-1,2485,1,'WORLDSTATE_HELLFIRE_BROKENHILL_NEUTRAL'),(530,3483,-1,2483,0,'WORLDSTATE_HELLFIRE_BROKENHILL_ALLIANCE'),(530,3483,-1,2484,0,'WORLDSTATE_HELLFIRE_BROKENHILL_HORDE'),(530,3518,-1,2502,0,'WORLDSTATE_HALAA_GUARD_DISPLAY_ALLIANCE'),(530,3518,-1,2503,0,'WORLDSTATE_HALAA_GUARD_DISPLAY_HORDE'),(530,3518,-1,2491,0,'WORLDSTATE_HALAA_GUARDS_REMAINING'),(530,3518,-1,2493,0,'WORLDSTATE_HALAA_GUARDS_REMAINING_MAX');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
