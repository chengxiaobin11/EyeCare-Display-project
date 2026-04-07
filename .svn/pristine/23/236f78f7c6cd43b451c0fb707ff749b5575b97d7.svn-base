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
// ID Code      : RL6463_Series_TMDSInterface.h No.0000
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
#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
extern void ScalerTMDSIntHandler_EXINT0(void);
extern void ScalerTMDSPSIntHandler_EXINT0(void);

#if(_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSYUV420SupportCheck(BYTE ucInputPort);
#endif

extern bit ScalerTMDSPSPreDetect(BYTE ucInputPort);
extern bit ScalerTMDSNormalPreDetect(BYTE ucInputPort);
extern BYTE ScalerTMDSScanInputPort(BYTE ucInputPort, BYTE ucInputType);
extern bit ScalerTMDSStableDetect(BYTE ucInputPort, BYTE ucSourceType);
extern void ScalerTMDSHotPlugEvent(BYTE ucPortSelect);
extern void ScalerTMDSHdcp1p4AksvClear(BYTE ucInputPort);

#if(_DVI_SUPPORT == _ON)
extern void ScalerTMDSRxHdcpVersionCapabilitySwitch(EnumSourceSearchPort enumInputPort, EnumTmdsHdcpType enumTmdsHdcpType);
extern void ScalerTMDSRxAllPortChangeHdcpCap(EnumTmdsHdcpType enumTmdsHdcpType);
#endif
#endif

