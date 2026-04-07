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
// ID Code      : ScalerTMDSRx5_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern StructHdmiSpdInfo g_stTmdsMacRx5SpdInfo;
#endif

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D5_TMDS_SUPPORT == _ON)
extern void ScalerTMDSRx5DviVideoSetting(void);
extern void ScalerTMDSRx5FirstActiveProc(BYTE ucSourceType);
extern void ScalerTMDSRx5SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig);
extern EnumDeOnlyConfig ScalerTMDSRx5GetDeOnlyModeConfig(void);
extern void ScalerTMDSRx5PowerOffProc(void);
extern void ScalerTMDSRx5SetPorchColor(EnumColorSpace enumColorFormat);
extern BYTE ScalerTMDSRx5TMDSVideoDetect(bit bWait);
extern void ScalerTMDSRx5TMDSVideoDetectEvent(void);

#if(_D5_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSRx5HdmiAviPixelRepInfoChanged(void);
extern bit ScalerTMDSRx5HdmiDeepColorProc(WORD usTmdsClkCnt);
extern BYTE ScalerTMDSRx5HdmiGetAVIInfo(EnumAviInfoContent enumContent);
extern BYTE ScalerTMDSRx5HdmiGetColorDepth(void);
extern void ScalerTMDSRx5HdmiPacketDetect(bit bWait);
extern void ScalerTMDSRx5HdmiPacketDetectEvent(void);
extern void ScalerTMDSRx5HdmiWatchDog(BYTE ucWDType, bit bEnable);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern void ScalerTMDSRx5SpdInfoPacketDetect(bit bWait);
extern void ScalerTMDSRx5HdmiGetSpdInfo(void);
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
extern void ScalerTMDSRx5ScrambleStatusReset(void);
extern void ScalerTMDSRx5ScrambleDetectTimeoutTimerEvent(void);
extern void ScalerTMDSRx5ScrambleDetectDisable(void);
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
extern void ScalerTMDSRx5SetScdcInfo_EXINT0(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern void ScalerTMDSRx5SetAmdAupiScdcInfo_EXINT0(bit bEnable);
#endif
#endif
#endif
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
extern bit ScalerTMDSRx5TMDSNormalPreDetect(void);
extern bit ScalerTMDSRx5TMDSPSPreDetect(void);
#endif

extern void ScalerTMDSRx5HotPlugLowProc(void);
extern void ScalerTMDSRx5HotPlugHighProc(WORD usHpdTime);
#endif
