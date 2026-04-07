/********************************************************************************/
/*   Copyright (c) 2021 Realtek Semiconductor Corp. All rights reserved.        */
/*                                                                              */
/*   SPDX-License-Identifier: LicenseRef-Realtek-Proprietary                    */
/*                                                                              */
/*   This software component is confidential and proprietary to Realtek         */
/*   Semiconductor Corp. Disclosure, reproduction, redistribution, in whole     */
/*   or in part, of this work and its derivatives without express permission    */
/*   is prohibited.                                                             */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6851_QC_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//************************************  For RL6410  *********************************************
// 1. RL6410_Project.h:
//    (1). _PCB_TYPE = _RL6410_QA_B_1A6mDP_DPTX_LVDS_eDP
//    (2). _PANEL_TYPE = _AUO_LED_DP_32_UHD
//    (3). _OSD_TYPE = _NONE_OSD
//      #define _OSD_TYPE                               _NONE_OSD
//
//      #define _OSD_INCLUDE                            "NoneInclude.h"
//      #define _USER_FUNCTION_INCLUDE                  "NoneUserInclude.h"
//      #define _USER_TIMER_INCLUDE                     "NoneTimerInclude.h"
//      #define _FACTORY_INCLUDE                        "NoneFactoryInclude.h"
//      #define _USER_HWIIC_INCLUDE                     "NoneHWIICInclude.h"
//
// 2. Debug.h:
//    -> _DEBUG_MESSAGE_QC = _ON
// 3. RTD2014Function, RTD2014Osd, RTDFactory:
//    -> Option for Group -> Include in Target Build -> Disable
// 4. NoneFunction, NoneOsd, NoneFactory:
//    -> Option for Group -> Include in Target Build -> Enable
// 5. RL6410_Series_QC_BIST.c ~ RL6410_Series_QC_OSD.c:
//    -> Option for File -> Include in Target Build -> Enable
// 6. RL6410_Project_Link.lin:
//    -> Option for Target -> User -> Run User Programs After Build -> Run #1 -> Diable
// 7. RL6410_Project_Link.lin :
//    -> Specify QC Code Bank in Keil C BL51 Misc By Modified Following:
/*
COMMON(?PR?SYSTIMERINTPROC0?SYSTIMER, ?PR?SYSTIMERINTPROC1?SYSTIMER, ?PR?SYSTIMERINTPROC2?SYSTIMER,?PR?SYSTIMERWDINTPROC?SYSTIMER)
BANK0(?CO?SYSSOURCE, ?CO?SCALERVGATOP, ?CO?SCALERGDIPHYTX)
BANK2(?CO?SCALERPLL, ?CO?RL6410_SERIES_COLOR*, ?CO?OSDDRAWWINDOW, ?CO?SCALERDDR3)
BANK3(?CO?RL6410_SERIES_SCALING, ?CO?RL6410_SERIES_DPRX0HDCP2, ?CO?RL6410_SERIES_DPRX1HDCP2)
BANK5(?CO?USERCOMMONMODESEARCH, ?CO?USERCOMMONDDCCIFUNCTION, ?CO?USERCOMMONINTERFACE, ?CO?USERCOMMONNVRAMSYSTEM)
BANK9(?CO?RL6410_SERIES_QC_COLOR_DDOMAIN_V)
BANK10(?CO?RL6410_SERIES_QC_COLOR_DDOMAIN_IV)
BANK11(?CO?NONE*, ?CO?RL6410_SERIES_QC_MAIN, ?CO?RL6410_SERIES_QC_COLOR_IMDOMAIN)
BANK12(?CO?RL6410_SERIES_QC_COLOR_DDOMAIN)
BANK13(?CO?RL6410_SERIES_QC_COLOR_DDOMAIN_II)
BANK14(?CO?RL6410_SERIES_QC_COLOR_DDOMAIN_III, ?CO?RL6410_SERIES_QC_OD_FRC, ?CO?RL6410_SERIES_QC_DSPC)
BANK15(?CO?RL6410_SERIES_QC_OSD, ?CO?RL6410_SERIES_QC_BIST)
*/
//***********************************************************************************************

//--------------------------------------------------
// QC type Options
//--------------------------------------------------
#define _RL6410_WITH_4P                                         1
#define _RL6410_WITHOUT_4P                                      2

#define _QC_TYPE                                                _RL6410_WITH_4P

#undef _MEMORY_SIZE_CONFIG
#define _MEMORY_SIZE_CONFIG                                     _1G_16BIT_DDR3_2PCS

#if(_QC_TYPE == _RL6410_WITH_4P)
#define _QC_4P_MODE_                                            _ON
#else
#define _QC_4P_MODE_                                            _OFF
#endif

