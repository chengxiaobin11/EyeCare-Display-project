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
// ID Code      : RL6851_Series_ScalerMbr.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_MBR__

#include "ScalerFunctionInclude.h"

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
#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
WORD g_usMbrDVTotal;
EnumMbrBacklightMode g_enumMbrBacklightMode = _BACKLIGHT_MODE_CONSTANT;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
EnumMbrBacklightMode ScalerMbrCheckBacklightMode(EnumMbrBacklightMode enumBacklightMode);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Kernel check/overwrite backlight mode if the mode
//                doesn't even support
// Input Value  : enumBacklightMode - user MBR backlight mode
// Output Value : altered backlight mode
//--------------------------------------------------
EnumMbrBacklightMode ScalerMbrCheckBacklightMode(EnumMbrBacklightMode enumBacklightMode)
{
    // If DRR enable but DRR MBR not supported, use constant backlight
#if(_DRR_SUPPORT == _ON)
    if(enumBacklightMode != _BACKLIGHT_MODE_CONSTANT)
    {
        if(ScalerDrrGetType() != _DRR_NONE_TYPE)
        {
            return _BACKLIGHT_MODE_CONSTANT;
        }
    }
#endif

    // If DRR MBR is selected but FW/DRR status/HW do not support, use constant backlight
    if(enumBacklightMode == _BACKLIGHT_MODE_STROBE_DRR_MBR)
    {
        return _BACKLIGHT_MODE_CONSTANT;
    }

    // If RTK Adv MBR is selected but FW/kernel status do not support, use constant backlight
    if(enumBacklightMode == _BACKLIGHT_MODE_STROBE_RTK_ADV_MBR)
    {
        return _BACKLIGHT_MODE_CONSTANT;
    }

    return enumBacklightMode;
}
#endif // End of #if(_MOTION_BLUR_REDUCTION_SUPPORT == _ON)

