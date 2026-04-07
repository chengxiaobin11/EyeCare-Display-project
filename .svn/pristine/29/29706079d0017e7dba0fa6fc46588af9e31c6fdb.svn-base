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
// ID Code      : ScalerDPRx1HDCP2_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DP_HDCP_2_2_SUPPORT == _ON)
#if(_D1_DP_EXIST == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of HDCP 2.2 Authentication State
//--------------------------------------------------
#define GET_DP_RX1_HDCP2_MODE()                                   (ScalerGetBit(PB0_1A_HDCP_IRQ, _BIT1) == _BIT1)

//--------------------------------------------------
// DP HDCP2 Type Value Reg Address
//--------------------------------------------------
#define _REG_DP_RX1_HDCP2_TYPE_AES0_VALUE                         PB0_93_HDCP_TYPE_AES_0

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDpRx1Hdcp2Handler(void);
extern void ScalerDpRx1Hdcp2Handler_EXINT0(void);
extern void ScalerDpRx1Hdcp2ResetProc(void);
extern void ScalerDpRx1Hdcp2ResetProc_EXINT0(void);

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern void ScalerDpRx1Hdcp2SkeProc_WDINT(void);
extern void ScalerDpRx1Hdcp2HPrimeProc_WDINT(void);
extern void ScalerDpRx1Hdcp2AkeInitProc_WDINT(void);
#endif

#endif // End of #if(_D1_DP_EXIST == _ON)
#endif // End of #if(_DP_HDCP_2_2_SUPPORT == _ON)

