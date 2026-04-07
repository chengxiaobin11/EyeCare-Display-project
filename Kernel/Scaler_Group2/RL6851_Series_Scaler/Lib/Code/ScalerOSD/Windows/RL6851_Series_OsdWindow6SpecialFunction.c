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
// ID Code      : RL6851_Series_OsdWindow6SpecialFunction.c
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
void ScalerOsdWindow6SpecialFunction(EnumOsdWindow6FunctionType enumOsdWindow6FunctionType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window 6 Special function
// Input Value  : enumOsdWindow6FunctionType   -> _OSD_WINDOW_6_FUNCTION_DISABLE                    or _OSD_WINDOW_6_FUNCTION_NO_BLENDING_BOTH                  or
//                                                _OSD_WINDOW_6_FUNCTION_NO_BLENDING_FOREGROUND     or _OSD_WINDOW_6_FUNCTION_NO_BLENDING_BACKGROUND            or
//                                                _OSD_WINDOW_6_FUNCTION_BLENDING_BOTH
// Output Value :
//--------------------------------------------------
void ScalerOsdWindow6SpecialFunction(EnumOsdWindow6FunctionType enumOsdWindow6FunctionType)
{
    if(enumOsdWindow6FunctionType != _OSD_WINDOW_6_FUNCTION_DISABLE)
    {
        ScalerSetBit(P3A_21_FRAME_CTRL_21, ~(_BIT6 | _BIT3 | _BIT2), (_BIT6 | ((enumOsdWindow6FunctionType - _OSD_WINDOW_6_FUNCTION_NO_BLENDING_BOTH) << 2)));
    }
    else
    {
        ScalerSetBit(P3A_21_FRAME_CTRL_21, ~(_BIT6 | _BIT3 | _BIT2), 0x00);
    }
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdWindow6SpecialFunction(_OSD_WINDOW_6_FUNCTION_NO_BLENDING_FOREGROUND);
*/
