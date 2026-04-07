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
// ID Code      : RL6851_Series_ScalerTMDS_ComboPhyInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
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
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if((_TMDS_PAGE2_COMBO_EXIST == _ON) && (_DVI_SUPPORT == _ON))

#if(_HDMI_SUPPORT == _ON)
extern BYTE ScalerTMDSRx0HdmiGetAVIInfo(EnumAviInfoContent enumContent);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern void ScalerTMDSRx0SpdInfoPacketDetect(bit bWait);
extern void ScalerTMDSRx0HdmiGetSpdInfo(void);
extern StructHdmiSpdInfo ScalerTMDSHdmiGetSpdPdInfo(EnumSourceSearchPort enumInputPort);
#endif

#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))

#if(_HDMI21_VRR_SUPPORT == _ON)
extern bit ScalerTMDSMacRxGetHdmi21VrrStatus(void);
extern void ScalerTMDSMacRxSetEdidVrrCapability(BYTE ucInputPort, StructHdmi21EdidVrrCap stEdidVrrCap);
extern void ScalerTMDSMacRxClrEdidVrrCapability(BYTE ucInputPort);
#endif

#if(_HDMI21_FVA_SUPPORT == _ON)
extern BYTE ScalerTMDSMacRxHdmi21GetFvaFactor(void);
extern WORD ScalerTMDSMacRxCalFvaVfreqMax(StructFreeSyncEdidInfo *pstCatchEdidInfo, BYTE ucFavFactor);
#endif
#endif
#endif

#if(_UNDERSCAN_SUPPORT == _ON)
extern void ScalerTMDSSetPorchColor(BYTE ucInputPort, EnumColorSpace enumColorFormat);
#endif

#endif
