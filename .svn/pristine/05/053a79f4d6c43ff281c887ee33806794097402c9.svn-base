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
// ID Code      : RL6410_Series_OsdGetFBShift.c
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
WORD ScalerOsdGetFBShiftValue(EnumOsdFrontBackShiftType enumOsdFrontBackShiftType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get Shift Vertical Boundary Size in Front/Back Mode
// Input Value  : enumOsdFrontBackShiftType   -> _OSD_FRONT_BACK_SHIFT_INSIDE or _OSD_FRONT_BACK_SHIFT_OUTSIDE
// Output Value : 0 ~ 4095
//--------------------------------------------------
WORD ScalerOsdGetFBShiftValue(EnumOsdFrontBackShiftType enumOsdFrontBackShiftType)
{
    switch(enumOsdFrontBackShiftType)
    {
        case _OSD_FRONT_BACK_SHIFT_INSIDE:
            return ((ScalerGetByte(P3A_5B_FRAME_CTRL_5B) << 4) | ((ScalerGetByte(P3A_5D_FRAME_CTRL_5D) & 0xF0) >> 4));

        case _OSD_FRONT_BACK_SHIFT_OUTSIDE:
            return ((ScalerGetByte(P3A_5C_FRAME_CTRL_5C) << 4) | (ScalerGetByte(P3A_5D_FRAME_CTRL_5D) & 0x0F));

        default:
            break;
    }

    return 0x0000;
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdGetFBShiftValue(_OSD_FRONT_BACK_SHIFT_INSIDE);
*/

