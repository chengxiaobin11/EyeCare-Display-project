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
// ID Code      : RL6851_Series_ScalerDPRx0HDCP2Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DP_HDCP_2_2_SUPPORT == _ON)
#if(_D0_DP_EXIST == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _REG_DP_RX0_HDCP2_ADDR_A3                               (PB7_A3_AUX_RESERVE3)
#define _REG_DP_RX0_HDCP2_ADDR_A4                               (PB7_A4_AUX_RESERVE4)
#define _REG_DP_RX0_HDCP2_ADDR_A5                               (PB7_A5_AUX_RESERVE5)
#define _REG_DP_RX0_HDCP2_ADDR_FB                               (PB7_FB_DP0_MANUAL_DPCD_IRQ)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

#endif // End of #if(_D0_DP_EXIST == _ON)
#endif // End of #if(_DP_HDCP_2_2_SUPPORT == _ON)

