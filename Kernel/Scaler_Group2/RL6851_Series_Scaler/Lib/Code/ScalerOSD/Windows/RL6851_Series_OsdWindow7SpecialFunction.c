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
// ID Code      : RL6851_Series_OsdWindow7SpecialFunction.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerOSDLibInternalInclude.h"

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
void ScalerOsdWindow7SpecialFunction(EnumOsdWindow7FunctionType enumOsdWindow7FunctionType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window 7 Special function
// Input Value  : enumOsdWindow7FunctionType   -> _OSD_WINDOW_7_FUNCTION_DISABLE                        or _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BOTH                  or
//                                                _OSD_WINDOW_7_FUNCTION_NO_BLENDING_FOREGROUND         or _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BACKGROUND            or
//                                                _OSD_WINDOW_7_FUNCTION_BLENDING_BOTH                  or _OSD_WINDOW_7_FUNCTION_MASK_REGION_APPEAR                or
//                                                _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL    or _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_FONT
// Output Value :
//--------------------------------------------------
void ScalerOsdWindow7SpecialFunction(EnumOsdWindow7FunctionType enumOsdWindow7FunctionType)
{
    if((enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BOTH) ||
       (enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_NO_BLENDING_FOREGROUND) ||
       (enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BACKGROUND) ||
       (enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_BLENDING_BOTH))
    {
        ScalerSetBit(P3A_09_FRAME_CTRL_09, ~(_BIT6 | _BIT5), _BIT5);  // 01: Blending (blending type 3)
        ScalerSetBit(P3A_21_FRAME_CTRL_21, ~(_BIT5 | _BIT4), ((enumOsdWindow7FunctionType - _OSD_WINDOW_7_FUNCTION_NO_BLENDING_BOTH) << 4));
    }
    else if(enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_MASK_REGION_APPEAR)
    {
        ScalerSetBit(P3A_09_FRAME_CTRL_09, ~(_BIT6 | _BIT5), _BIT6);  // 10: Window 7 mask region appear
    }
    else if((enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL) || (enumOsdWindow7FunctionType == _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_FONT))
    {
        ScalerSetBit(P3A_09_FRAME_CTRL_09, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));  // 11: Window 7 mask region transparent
        ScalerSetBit(P3A_07_FRAME_CTRL_07, ~_BIT3, ((enumOsdWindow7FunctionType - _OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL) << 3));
    }
    else
    {
        ScalerSetBit(P3A_09_FRAME_CTRL_09, ~(_BIT6 | _BIT5), 0x00);
    }
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdWindow7SpecialFunction(_OSD_WINDOW_7_FUNCTION_DISABLE);
*/
