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
// ID Code      : RTD2014UserInterfaceDimming.h No.0000
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
#if(_BACKLIGHT_DIMMING_SUPPORT == _ON)
extern EnumSDRCalibrationType UserInterfaceSDROCCOGCMode(void);
extern EnumSDRPCMStatus UserInterfaceGetSDRPCMMode(void);
extern EnumSDROGCStatus UserInterfaceGetSDROGCMode(void);
#if(_GLOBAL_DIMMING_SUPPORT == _ON)
#if(_OCC_PCM_GAMMA_SUPPORT == _ON)
extern EnumOCCPCMGammaCTMatrix UserInterfaceGetSDRPCMOCCGammaMode(void);
#endif
#endif
#endif // End of #if(_BACKLIGHT_DIMMING_SUPPORT == _ON)
