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
// ID Code      : ScalerCommonTMDSInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_HDMI_SUPPORT == _ON)
#if(_HDMI_2_0_SUPPORT == _ON)
extern StructScdcInfoSet g_stTmdsMacRxScdcInfoSet;

#if(_HDMI_5V_DETECT_BY_USER == _ON)
extern StructTMDS5vStatusByUser g_stTmdsMacRx5vStatusByUser;
#endif
#endif
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_HDMI_SUPPORT == _ON)
extern BYTE ScalerTMDSHdmiGetAVIInfo(BYTE ucInputPort, EnumAviInfoContent enumContent);
extern void ScalerTMDSSetPsWakeupHpdToggle(BYTE ucInputPort);
#if((_HDMI_2_0_SUPPORT == _ON) && (_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON))
extern void ScalerTMDSHDMI2HPDRRIRQEnable(BYTE ucInputPort, bit bEnable);
#endif

#if(_HDMI_2_0_SUPPORT == _ON)
extern void ScalerTMDSHdmiHpd5vPinCheckEvent(BYTE ucInputPort, bit bEnable);
extern BYTE ScalerTMDSHdmiGetHwVersion(void);
#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
extern void ScalerTMDSRxAllPortScdcEnableSetting(bit bEnable);
#endif
#endif

#endif

#if(_DVI_SUPPORT == _ON)
void ScalerTMDSRxAcOnInitial(void);
#endif

