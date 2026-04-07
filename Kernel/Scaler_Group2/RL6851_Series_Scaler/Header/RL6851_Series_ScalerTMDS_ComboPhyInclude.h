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
// ID Code      : RL6851_Series_ScalerTMDS_ComboPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern StructHdmiSpdInfo g_stTmdsMacRx0SpdInfo;
#endif

#if((_HDMI21_VRR_SUPPORT == _ON) || (_HDMI21_FVA_SUPPORT == _ON))
#if(_HDMI21_VRR_SUPPORT == _ON)
extern StructHdmi21EdidVrrCap g_stTmdsMacHdmi21EdidVrrCap;
#endif
#endif

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if((_TMDS_PAGE2_COMBO_EXIST == _ON) && (_DVI_SUPPORT == _ON))
extern void ScalerTMDSDviVideoSetting(BYTE ucInputPort);
extern void ScalerTMDSFreqDetectDisable(void);
extern void ScalerTMDSResetProc(void);
extern BYTE ScalerTMDSVideoDetect(bit bWait);
extern void ScalerTMDSVideoDetectEvent(EnumScalerTimerEventID enumEventID);

#if(_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSHdmiAviPixelRepInfoChanged(void);
extern bit ScalerTMDSHdmiDeepColorProc(WORD usTmdsClkCnt);
extern BYTE ScalerTMDSHdmiGetColorDepth(void);
extern void ScalerTMDSHdmiPacketDetect(bit bWait);
extern void ScalerTMDSHdmiPacketDetectEvent(EnumScalerTimerEventID enumEventID);
extern void ScalerTMDSHdmiWatchDog(BYTE ucWDType, bit bEnable);
extern BYTE ScalerTMDSRx0HdmiGetAVIInfo(EnumAviInfoContent enumContent);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern void ScalerTMDSRx0SpdInfoPacketDetect(bit bWait);
extern void ScalerTMDSRx0HdmiGetSpdInfo(void);
extern StructHdmiSpdInfo ScalerTMDSHdmiGetSpdPdInfo(EnumSourceSearchPort enumInputPort);
#endif

#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))
extern void ScalerTMDSClrHdmi21VtemReceived(void);
extern BYTE ScalerTMDSGetVicVfreqParameter(BYTE ucVicIndex);

#if(_HDMI21_VRR_SUPPORT == _ON)
extern bit ScalerTMDSMacRxGetHdmi21VrrStatus(void);
extern void ScalerTMDSMacRxSetEdidVrrCapability(BYTE ucInputPort, StructHdmi21EdidVrrCap stEdidVrrCap);
extern void ScalerTMDSMacRxClrEdidVrrCapability(BYTE ucInputPort);
#endif
#endif
#endif

#if(_UNDERSCAN_SUPPORT == _ON)
extern void ScalerTMDSSetPorchColor(BYTE ucInputPort, EnumColorSpace enumColorFormat);
#endif

extern void ScalerTMDSHotPlugLowProc(BYTE ucPortSelect);
extern void ScalerTMDSHotPlugHighProc(BYTE ucPortSelect, WORD usHpdTime);
#endif

