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
// ID Code      : RL6449_Series_TMDSInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerTMDSInitial(BYTE ucInputPort);
extern void ScalerTMDSInterruptInitial(BYTE ucInputPort);
extern void ScalerTMDSSetDeOnlyModeConfig(EnumSourceSearchPort enumSourceSearchPort, EnumDeOnlyConfig enumDeonlyConfig);
extern EnumDeOnlyConfig ScalerTMDSGetDeOnlyModeConfig(EnumSourceSearchPort enumSourceSearchPort);
extern void ScalerTMDSVideoDetectEvent(EnumScalerTimerEventID enumEventID);
extern void ScalerTMDSResetProc(void);

#if(_HDMI_SUPPORT == _ON)
extern void ScalerTMDSHdmiAVMuteProc(void);
extern void ScalerTMDSHdmiWatchDog(BYTE ucWDType, bit bEnable);
extern void ScalerTMDSHdmiPacketDetectEvent(EnumScalerTimerEventID enumEventID);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern StructHdmiSpdInfo ScalerTMDSHdmiGetSpdPdInfo(EnumSourceSearchPort enumInputPort);
#endif

#if(_HDMI_2_0_SUPPORT == _ON)
extern void ScalerTMDSHdmiReadRequestTimerEnable_WDINT(bit bEnable);
extern void ScalerTMDSHdmi2FormatResetEvent(EnumScalerTimerEventID enumEventID);
extern void ScalerTMDSHdmiScrambleStatusReset(BYTE ucPortSelect);
extern void ScalerTMDSHdmiScrambleDetectTimeoutTimerEvent(EnumScalerTimerEventID enumEventID);
extern void ScalerTMDSScrambleDetectDisable(void);
#if(_TMDS_HDMI_2_0_SCDC_RR_CTS_SUPPORT == _ON)
extern void ScalerTMDSHdmiSetScdcInfo_EXINT0(BYTE ucInputPort);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern EnumFreeSyncSupport ScalerTMDSHdmiGetFreeSyncSupport_EXINT0(BYTE ucInputPort);
extern void ScalerTMDSHdmiSetAmdAupiScdcInfo_EXINT0(BYTE ucInputPort, bit bEnable);
#endif
#endif
#endif
#endif

extern void ScalerTMDSMacDdcSwitchCtrl(BYTE ucInputPort);
extern void ScalerTMDSFreqDetectDisable(void);
extern void ScalerTMDSFirstActiveProc(BYTE ucInputPort, BYTE ucSourceType);
extern bit ScalerTMDSHdcpEnabled(BYTE ucInputPort);
extern void ScalerTMDSHotPlugEvent(BYTE ucPortSelect);
extern void ScalerTMDSBeforeHotPlugEventProc(BYTE ucPortSelect, bit bDisableZ0);
extern void ScalerTMDSHotPlugLowProc(BYTE ucPortSelect);
extern void ScalerTMDSHotPlugHighProc(BYTE ucPortSelect, WORD usHpdTime);
extern void ScalerTMDSAfterHotPlugEventProc(BYTE ucPortSelect, bit bRestoreZ0);

#endif
