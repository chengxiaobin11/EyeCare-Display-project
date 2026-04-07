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
// ID Code      : RL6410_Series_OsdFontScalingUp.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_OSDLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerOsdFontScalingUpRatio(EnumOsdFontScalingRatioType enumRatio);
void ScalerOsdFontScalingUpBoundaryCodition(EnumOsdFontScalingBoundaryType enumBoundary);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OSD Font Scale Up Ratio
// Input Value  : enumRatio
// Output Value :
// Note         : Scale_Ratio is recommended to set BEFORE Font_Scale_En.
//               If users want to change scale ratio, the recommended flow is Disable OSD -> Set new Scale_Ratio -> Enable OSD.
//               Font Scale up, Double Width/Height, and Auto Rotation&Remap. These three features cannot be open at the same time.
//--------------------------------------------------
void ScalerOsdFontScalingUpRatio(EnumOsdFontScalingRatioType enumRatio)
{
    ScalerSetBit(P3A_43_FRAME_CTRL_43, ~(_BIT4 | _BIT3 | _BIT2), (enumRatio << 2));
}

//--------------------------------------------------
// Description  : OSD Font Scale Up Boundary Condition
// Input Value  : enumRatio
// Output Value :
//--------------------------------------------------
void ScalerOsdFontScalingUpBoundaryCodition(EnumOsdFontScalingBoundaryType enumBoundary)
{
    ScalerSetBit(P3A_43_FRAME_CTRL_43, ~(_BIT1 | _BIT0), enumBoundary);
}
