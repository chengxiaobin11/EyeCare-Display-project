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
// ID Code      : User_PCB_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// eDPTx 1.2 HBR2 FB/Lane Config
//--------------------------------------------------
#if((_PCB_TYPE == _RL6410_DEMO_A_1A4MHL2DP_DPTX_LVDS_eDP) || (_PCB_TYPE == _RL6410_QA_A_1A4MHL1DP1mDP_DPTX_LVDS_eDP) || (_PCB_TYPE == _RL6410_QA_B_1A6mDP_DPTX_LVDS_eDP))
#if(_PANEL_TYPE == _LG_LED_DP_27_QQHD)
#undef _PANEL_DPTX_1_2_FB_SWAP
#undef _PANEL_DPTX_1_2_LANE_SWAP
#undef _PANEL_DPTX_1_2_LANE_PN_SWAP
#define _PANEL_DPTX_1_2_FB_SWAP                 _ENABLE
#define _PANEL_DPTX_1_2_LANE_SWAP               _ENABLE
#define _PANEL_DPTX_1_2_LANE_PN_SWAP            _ENABLE
#endif
#endif

//--------------------------------------------------
// Include Data Exchange User Commonad Include
//--------------------------------------------------
#if((_D0_DP_REPEATER_TYPE == _REPEATER_RTS_TRANSLATOR) ||\
    (_D1_DP_REPEATER_TYPE == _REPEATER_RTS_TRANSLATOR))
#define _USER_DATA_EXCHANGE_INCLUDE             "RTD2014DataExchangeInclude.h"
#endif

