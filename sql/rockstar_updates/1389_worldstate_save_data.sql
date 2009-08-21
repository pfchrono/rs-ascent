/*
SQLyog Enterprise - MySQL GUI v7.02 
MySQL - 5.1.26-rc-community : Database - summit
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

/*Table structure for table `worldstate_save_data` */

DROP TABLE IF EXISTS `worldstate_save_data`;

CREATE TABLE `worldstate_save_data` (
  `setting_id` varchar(50) NOT NULL,
  `setting_value` varchar(200) NOT NULL,
  PRIMARY KEY (`setting_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `worldstate_save_data` */

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
