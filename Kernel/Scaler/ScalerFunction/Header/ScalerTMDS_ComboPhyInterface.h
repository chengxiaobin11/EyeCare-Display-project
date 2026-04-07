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
// ID Code      : ScalerTMDS_ComboPhyInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
extern StructHdmiSpdInfo g_stTmdsMacRx0SpdInfo;
#endif


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
#endif

#if(_UNDERSCAN_SUPPORT == _ON)
extern void ScalerTMDSSetPorchColor(BYTE ucInputPort, EnumColorSpace enumColorFormat);
#endif

#endif
