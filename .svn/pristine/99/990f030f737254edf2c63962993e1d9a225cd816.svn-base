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
// ID Code      : RL6851_Series_ScalerMbrInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
#define GET_MBR_DVTOTAL()                       (g_usMbrDVTotal)
#define SET_MBR_DVTOTAL(x)                      (g_usMbrDVTotal = (x))

#define GET_MBR_BACKLIGHT_MODE()                (g_enumMbrBacklightMode)
#define GET_MBR_BACKLIGHT_MODE_EXINT0()         (g_enumMbrBacklightMode)
#define SET_MBR_BACKLIGHT_MODE(x)               (g_enumMbrBacklightMode = (x))
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
extern WORD g_usMbrDVTotal;
extern EnumMbrBacklightMode g_enumMbrBacklightMode;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
extern EnumMbrBacklightMode ScalerMbrCheckBacklightMode(EnumMbrBacklightMode enumBacklightMode);
#endif

