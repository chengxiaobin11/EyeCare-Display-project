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
// ID Code      : ScalerCommonHDCP2Interface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_HDCP_2_2_FUNCTION_GEN == _HDCP_2_2_GEN_2)
#if(_HDCP_2_2_SUPPORT == _ON)
extern void ScalerHdcp2DownLoadCalculateKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray, BYTE ucRSAType);
extern void ScalerHdcp2Handler(void);
extern void ScalerHdcp2IntHandler_EXINT0(void);
#if((_TMDS_HDCP_2_2_SUPPORT == _ON) && (_HDMI_PORT_EXIST == _ON))
extern void ScalerHdcp2ResetTMDSProc(BYTE ucInputPort);
#endif
extern bit ScalerHdcp2RxPairingCalculate(BYTE *pucHdcp2KPriv, BYTE ucIndex);
#endif
#endif
