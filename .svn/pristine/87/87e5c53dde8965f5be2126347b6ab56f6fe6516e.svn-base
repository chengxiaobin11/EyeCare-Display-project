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
// ID Code      : ScalerDPRx1_SeptPhyInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_DP_HDCP14_REPEATER_BIT_DISABLE_FOR_TX_CLONE_OFF == _ON)
#define GET_DP_RX1_HDCP14_REPEATER_SUPPORT()                         (g_bDpRx1HdcpRepeaterBit)
#define SET_DP_RX1_HDCP14_REPEATER_SUPPORT(x)                        (g_bDpRx1HdcpRepeaterBit = (x))
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_DP_HDCP14_REPEATER_BIT_DISABLE_FOR_TX_CLONE_OFF == _ON)
extern bit g_bDpRx1HdcpRepeaterBit;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_D1_DP_EXIST == _ON)
extern void ScalerDpRx1AuxSet(void);
extern void ScalerDpRx1HDCPBlockReset(void);
#endif

