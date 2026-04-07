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
// ID Code      : ScalerTMDSRx4_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern StructHdmiSpdInfo g_stTmdsMacRx4SpdInfo;
#endif

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D4_TMDS_SUPPORT == _ON)
extern void ScalerTMDSRx4DviVideoSetting(void);
extern void ScalerTMDSRx4FirstActiveProc(BYTE ucSourceType);
extern void ScalerTMDSRx4SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig);
extern EnumDeOnlyConfig ScalerTMDSRx4GetDeOnlyModeConfig(void);
extern void ScalerTMDSRx4PowerOffProc(void);
extern void ScalerTMDSRx4SetPorchColor(EnumColorSpace enumColorFormat);
extern BYTE ScalerTMDSRx4TMDSVideoDetect(bit bWait);
extern void ScalerTMDSRx4TMDSVideoDetectEvent(void);

#if(_D4_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSRx4HdmiAviPixelRepInfoChanged(void);
extern BYTE ScalerTMDSRx4HdmiGetAVIInfo(EnumAviInfoContent enumContent);
extern BYTE ScalerTMDSRx4HdmiGetColorDepth(void);
extern void ScalerTMDSRx4HdmiPacketDetect(bit bWait);
extern void ScalerTMDSRx4HdmiPacketDetectEvent(void);
extern void ScalerTMDSRx4HdmiWatchDog(BYTE ucWDType, bit bEnable);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern void ScalerTMDSRx4SpdInfoPacketDetect(bit bWait);
extern void ScalerTMDSRx4HdmiGetSpdInfo(void);
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT)
extern bit ScalerTMDSRx4HdmiDeepColorProc(WORD usTmdsClkCnt);
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
extern void ScalerTMDSRx4ScrambleStatusReset(void);
extern void ScalerTMDSRx4ScrambleDetectTimeoutTimerEvent(void);
extern void ScalerTMDSRx4ScrambleDetectDisable(void);
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
extern void ScalerTMDSRx4SetScdcInfo_EXINT0(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern void ScalerTMDSRx4SetAmdAupiScdcInfo_EXINT0(bit bEnable);
#endif
#endif
#endif
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT)
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
extern bit ScalerTMDSRx4TMDSNormalPreDetect(void);
extern bit ScalerTMDSRx4TMDSPSPreDetect(void);
#endif

#endif

extern void ScalerTMDSRx4HotPlugLowProc(void);
extern void ScalerTMDSRx4HotPlugHighProc(WORD usHpdTime);
#endif
