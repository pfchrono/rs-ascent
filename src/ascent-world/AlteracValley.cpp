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

//mines
#define AV_IDM_CAPTURED_ALLIANCE 1358
#define AV_IDM_CAPTURED_HORDE 1359
#define AV_IDM_CAPTURED_NEUTRAL 1360 //set on start

#define AV_CTM_CAPTURED_ALLIANCE 1355
#define AV_CTM_CAPTURED_HORDE 1356
#define AV_CTM_CAPTURED_NEUTRAL 1357 //set on start

//graveyards
#define AV_SHGY_CAPTURED_HORDE 1301
#define AV_SHGY_CAPTURED_ALLIANCE 1302 //set on start
#define AV_SHGY_CONTESTED_HORDE 1303
#define AV_SHGY_CONTESTED_ALLIANCE 1304

#define AV_SFGY_UNCONTROLLED 1966 //set on start

#define AV_S_FWRH_CAPTURED_HORDE 1346 //set on start

#define AV_IBGY_CAPTURED_HORDE 1347 //set on start

#define AV_FWGY_CAPTURED_HORDE 1338 //set on start

#define AV_SPGY_CAPTURED_ALLIANCE 1333 //set on start

#define AV_FWRH_CAPTURED_ALLIANCE 1329
#define AV_FWRH_CAPTURED_HORDE 1330 //set on start
#define AV_FWRH_CONTESTED_ALLIANCE 1331
#define AV_FWRH_CONTESTED_HORDE 1332

//towers
#define AV_SHB_DESTROYED 1373
#define AV_SHB_CAPTURED_ALLIANCE 1364 //set on start
#define AV_SHB_CONTESTED_HORDE 1381

#define AV_WFWT_DESTROYED 1365
#define AV_WFWT_CAPTURED_HORDE 1382 //set on start
#define AV_WFWT_CONTESTED_ALLIANCE 1387

#define AV_EFWT_DESTROYED 1366
#define AV_EFWT_CAPTURED_HORDE 1383 //set on start
#define AV_EFWT_CONTESTED_ALLIANCE 1388

#define AV_TP_DESTROYED 1367
#define AV_TP_CAPTURED_HORDE 1384 //set on start
#define AV_TP_CONTESTED_ALLIANCE 1389

#define AV_IBT_DESTROYED 1368
#define AV_IBT_CAPTURED_HORDE 1385 //set on start
#define AV_IBT_CONTESTED_ALLIANCE 1390

#define AV_SHB_DESTROYED 1373
#define AV_SHB_CAPTURED_ALLIANCE 1364 //set on start
#define AV_SHB_CONTESTED_ALLIANCE 1377 //unused
#define AV_SHB_CONTESTED_HORDE 1381

#define AV_DBSB_DESTROYED 1370
#define AV_DBSB_CAPTURED_ALLIANCE 1361 //set on start
#define AV_DBSB_CONTESTED_HORDE 1378

#define AV_DBNB_DESTROYED 1371
#define AV_DBNB_CAPTURED_ALLIANCE 1362 //set on start
#define AV_DBNB_CONTESTED_HORDE 1379

#define AV_IWB_DESTROYED 1372
#define AV_IWB_CAPTURED_ALLIANCE 1363 //set on start
#define AV_IWB_CONTESTED_HORDE 1380

//unknowns
#define AV_UNK_1 1386 //set on start



//these are set (similar to bgflag and bgflag2 in other bgs)
#define BGFLAG 0x0A25
#define BGFLAG2 0
