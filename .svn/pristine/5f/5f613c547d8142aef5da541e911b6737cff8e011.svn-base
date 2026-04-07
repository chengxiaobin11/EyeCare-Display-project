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
// ID Code      : ScalerTMDSRx3_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern StructHdmiSpdInfo g_stTmdsMacRx3SpdInfo;
#endif

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D3_TMDS_SUPPORT == _ON)
extern void ScalerTMDSRx3DviVideoSetting(void);
extern void ScalerTMDSRx3FirstActiveProc(BYTE ucSourceType);
extern void ScalerTMDSRx3SetDeOnlyModeConfig(EnumDeOnlyConfig enumDeonlyConfig);
extern EnumDeOnlyConfig ScalerTMDSRx3GetDeOnlyModeConfig(void);
extern void ScalerTMDSRx3PowerOffProc(void);
extern BYTE ScalerTMDSRx3TMDSVideoDetect(bit bWait);
extern void ScalerTMDSRx3TMDSVideoDetectEvent(void);
extern void ScalerTMDSRx3PSIntHandler_EXINT0(void);

#if(_D3_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSRx3HdmiAviPixelRepInfoChanged(void);
extern BYTE ScalerTMDSRx3HdmiGetAVIInfo(EnumAviInfoContent enumContent);
extern BYTE ScalerTMDSRx3HdmiGetColorDepth(void);
extern void ScalerTMDSRx3HdmiPacketDetectEvent(void);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern void ScalerTMDSRx3SpdInfoPacketDetect(bit bWait);
extern void ScalerTMDSRx3HdmiGetSpdInfo(void);
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
extern void ScalerTMDSRx3HDMI2HPDRRIRQEnable(bit bEnable);
extern void ScalerTMDSRx3SetScdcInfo_EXINT0(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern void ScalerTMDSRx3SetAmdAupiScdcInfo_EXINT0(bit bEnable);
#endif
#endif
extern void ScalerTMDSRx3ScrambleStatusReset(void);
extern void ScalerTMDSRx3ScrambleDetectTimeoutTimerEvent(void);
extern void ScalerTMDSRx3ScrambleDetectDisable(void);
extern void ScalerTMDSRx3Hdmi2FormatResetEvent(void);
extern void ScalerTMDSRx3ReadRequestProc_EXINT0(BYTE ucRROutCome);
extern void ScalerTMDSRx3ReadRequestTimerEventEnable_WDINT(bit bEnable);
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
extern bit ScalerTMDSRx3HdmiDeepColorProc(WORD usTmdsClkCnt);
#endif

#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
extern bit ScalerTMDSRx3TMDSNormalPreDetect(void);
extern bit ScalerTMDSRx3TMDSPSPreDetect(void);
#endif

#endif

extern void ScalerTMDSRx3HotPlugLowProc(void);
extern void ScalerTMDSRx3HotPlugHighProc(WORD usHpdTime);
#endif
