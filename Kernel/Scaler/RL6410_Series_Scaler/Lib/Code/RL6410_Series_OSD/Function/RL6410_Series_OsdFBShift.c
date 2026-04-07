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
// ID Code      : RL6410_Series_OsdFBShift.c
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
void ScalerOsdFBShiftEn(bit bEnable);
void ScalerOsdFBShiftValue(EnumOsdFrontBackShiftType enumOsdFrontBackShiftType, WORD usBoundaryValue);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Shift Enable in Front/Back Mode
// Input Value  : bEnable   -> _ENABLE or _DISABLE
// Output Value :
//--------------------------------------------------
void ScalerOsdFBShiftEn(bit bEnable)
{
    ScalerSetBit(P3A_5E_FRAME_CTRL_5E, ~_BIT7, ((BYTE)bEnable << 7));
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdFBShiftEn(_ENABLE);
*/


//--------------------------------------------------
// Description  : Set Shift Vertical Boundary Size in Front/Back Mode
// Input Value  : usShiftUpperBoundary -> 0 ~ 4095
//                usShiftLowerBoundary -> 0 ~ 4095
// Output Value :
//--------------------------------------------------
void ScalerOsdFBShiftValue(EnumOsdFrontBackShiftType enumOsdFrontBackShiftType, WORD usBoundaryValue)
{
    switch(enumOsdFrontBackShiftType)
    {
        case _OSD_FRONT_BACK_SHIFT_INSIDE:
            // For F/B mode OSD h shift value in boundary[11:4]
            ScalerSetByte(P3A_5B_FRAME_CTRL_5B, (usBoundaryValue >> 4));

            // For F/B mode OSD h shift value in boundary[0:3]
            ScalerSetBit(P3A_5D_FRAME_CTRL_5D, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (usBoundaryValue & 0x0F) << 4);
            break;


        case _OSD_FRONT_BACK_SHIFT_OUTSIDE:
            // For F/B mode OSD h shift value in boundary[11:4]
            ScalerSetByte(P3A_5C_FRAME_CTRL_5C, (usBoundaryValue >> 4));

            // For F/B mode OSD h shift value out of boundary [0:3]
            ScalerSetBit(P3A_5D_FRAME_CTRL_5D, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (usBoundaryValue & 0x0F));
            break;

        default:
            break;
    }
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdFBShiftValue(_OSD_FRONT_BACK_SHIFT_INSIDE, 1000);
*/

