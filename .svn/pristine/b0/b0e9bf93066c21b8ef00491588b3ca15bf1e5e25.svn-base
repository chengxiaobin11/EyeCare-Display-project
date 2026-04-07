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
// ID Code      : RTD2014UserInterfaceLocalDimming.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------


//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_LOCAL_DIMMING_SUPPORT == _ON)

#ifndef __USER_INTERFACE_LOCAL_DIMMING__
extern EnumLDActionMode UserInterfaceGetLocaldimmingActionMode(void);
extern EnumLDStatus UserInterfaceGetLocalDimmingStatus(void);
extern BYTE UserInterfaceGetLocalDimmingPWMSmoothLevel(void);
extern void UserInterfaceLocalDimmingAdjustPCM(void);
extern EnumLDStatus UserInterfaceGetLocalDimmingNoSupportStatus(void);
extern EnumLDPCHDRMode UserInterfaceGetPCHDRVerifyMode(void);

#if(_UNIFORMITY_SUPPORT == _ON)
extern EnumUniformityStatus UserInterfaceGetUniformityStatus(void);
#endif

#if(_LD_TUNNEL_DETECT_SUPPORT == _ON)
extern void UserInterfaceTunnelPatternDetectOff(void);
#endif

#endif // End of __USER_INTERFACE_LOCAL_DIMMING__

#endif // End of #if(_LOCAL_DIMMING_SUPPORT == _ON)
