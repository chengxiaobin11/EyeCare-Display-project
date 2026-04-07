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
// ID Code      : RL6851_Series_ScalerCommonTMDSInterface.h No.0000
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
#if(_HDMI_SUPPORT == _ON)
extern BYTE ScalerTMDSHdmiGetAVIInfo(BYTE ucInputPort, EnumAviInfoContent enumContent);
extern void ScalerTMDSSetPsWakeupHpdToggle(BYTE ucInputPort);
#if((_HDMI_2_0_SUPPORT == _ON) && (_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON))
extern void ScalerTMDSHDMI2HPDRRIRQEnable(BYTE ucInputPort, bit bEnable);
#endif
#endif

#if(_DVI_SUPPORT == _ON)
void ScalerTMDSRxAcOnInitial(void);
#endif

