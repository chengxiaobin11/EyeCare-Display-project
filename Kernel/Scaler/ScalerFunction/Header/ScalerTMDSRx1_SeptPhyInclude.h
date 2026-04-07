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
// ID Code      : ScalerTMDSRx1_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern StructHdmiSpdInfo g_stTmdsMacRx1SpdInfo;
#endif


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D1_TMDS_SUPPORT == _ON)
extern void ScalerTMDSRx1FirstActiveProc(BYTE ucSourceType);
extern void ScalerTMDSRx1SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig);
extern EnumDeOnlyConfig ScalerTMDSRx1GetDeOnlyModeConfig(void);
extern void ScalerTMDSRx1PowerOffProc(void);
extern void ScalerTMDSRx1TMDSVideoDetectEvent(void);

#if(_D1_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSRx1HdmiAviPixelRepInfoChanged(void);
extern bit ScalerTMDSRx1HdmiDeepColorProc(WORD usTmdsClkCnt);
extern void ScalerTMDSRx1HdmiPacketDetectEvent(void);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern void ScalerTMDSRx1SpdInfoPacketDetect(bit bWait);
extern void ScalerTMDSRx1HdmiGetSpdInfo(void);
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
extern void ScalerTMDSRx1Hdmi2FormatResetEvent(void);
extern void ScalerTMDSRx1ScrambleStatusReset(void);
extern void ScalerTMDSRx1ScrambleDetectTimeoutTimerEvent(void);
extern void ScalerTMDSRx1ScrambleDetectDisable(void);
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
extern void ScalerTMDSRx1SetScdcInfo_EXINT0(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern void ScalerTMDSRx1SetAmdAupiScdcInfo_EXINT0(bit bEnable);
#endif
#endif
#endif

#endif

extern void ScalerTMDSRx1HotPlugLowProc(void);
extern void ScalerTMDSRx1HotPlugHighProc(WORD usHpdTime);
#endif
