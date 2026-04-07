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
// ID Code      : RL6410_Series_OsdFBShiftBoundary.c
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
void ScalerOsdFBShiftBoundarySize(WORD usUpperBoundary, WORD usLowerBoundary);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Shift Vertical Boundary Size in Front/Back Mode
// Input Value  : usUpperBoundary -> 0 ~ 4095
//                usLowerBoundary -> 0 ~ 4095
// Output Value :
//--------------------------------------------------
void ScalerOsdFBShiftBoundarySize(WORD usUpperBoundary, WORD usLowerBoundary)
{
    BYTE ucBoundary_L = 0x00;

    ScalerSetByte(P3A_8C_FRAME_CTRL_8C, (usUpperBoundary >> 4));         // OSD Vertical Upper Boundary [11:4]
    ScalerSetByte(P3A_8D_FRAME_CTRL_8D, (usLowerBoundary >> 4));         // OSD Vertical Lower Boundary [11:4]

    // OSD Vertical Upper Boundary [0:3]
    // OSD Vertical Lower Boundary [0:3]
    ucBoundary_L = (((usUpperBoundary & 0x0F) << 4) | (usLowerBoundary & 0x0F));
    ScalerSetByte(P3A_8E_FRAME_CTRL_8E, ucBoundary_L);
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdFBShiftBoundarySize(YSTART(100), YEND(1000));
*/

