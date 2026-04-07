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
// ID Code      : ScalerTMDSRx2_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern StructHdmiSpdInfo g_stTmdsMacRx2SpdInfo;
#endif

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D2_TMDS_SUPPORT == _ON)
extern void ScalerTMDSRx2DviVideoSetting(void);
extern void ScalerTMDSRx2FirstActiveProc(BYTE ucSourceType);
extern void ScalerTMDSRx2SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig);
extern EnumDeOnlyConfig ScalerTMDSRx2GetDeOnlyModeConfig(void);
extern void ScalerTMDSRx2PowerOffProc(void);
extern BYTE ScalerTMDSRx2TMDSVideoDetect(bit bWait);
extern void ScalerTMDSRx2TMDSVideoDetectEvent(void);
extern void ScalerTMDSRx2PSIntHandler_EXINT0(void);

#if(_D2_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSRx2HdmiAviPixelRepInfoChanged(void);
extern BYTE ScalerTMDSRx2HdmiGetAVIInfo(EnumAviInfoContent enumContent);
extern BYTE ScalerTMDSRx2HdmiGetColorDepth(void);
extern void ScalerTMDSRx2HdmiPacketDetectEvent(void);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern void ScalerTMDSRx2SpdInfoPacketDetect(bit bWait);
extern void ScalerTMDSRx2HdmiGetSpdInfo(void);
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
extern void ScalerTMDSRx2HDMI2HPDRRIRQEnable(bit bEnable);
extern void ScalerTMDSRx2SetScdcInfo_EXINT0(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern void ScalerTMDSRx2SetAmdAupiScdcInfo_EXINT0(bit bEnable);
#endif
#endif
extern void ScalerTMDSRx2ScrambleStatusReset(void);
extern void ScalerTMDSRx2ScrambleDetectTimeoutTimerEvent(void);
extern void ScalerTMDSRx2ScrambleDetectDisable(void);
extern void ScalerTMDSRx2Hdmi2FormatResetEvent(void);
extern void ScalerTMDSRx2ReadRequestProc_EXINT0(BYTE ucRROutCome);
extern void ScalerTMDSRx2ReadRequestTimerEventEnable_WDINT(bit bEnable);
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT)
extern bit ScalerTMDSRx2HdmiDeepColorProc(WORD usTmdsClkCnt);
#endif

#endif

#if(_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT)
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
extern bit ScalerTMDSRx2TMDSNormalPreDetect(void);
extern bit ScalerTMDSRx2TMDSPSPreDetect(void);
#endif

#endif

extern void ScalerTMDSRx2HotPlugLowProc(void);
extern void ScalerTMDSRx2HotPlugHighProc(WORD usHpdTime);
#endif
