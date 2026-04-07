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
// ID Code      : RL6851_Series_OsdSramGetDataInit.c
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
void ScalerOsdSramGetDataInit(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get SRAM address value
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerOsdSramGetDataInit(void)
{
    BYTE uc3A41 = 0;
    BYTE uc0093 = 0;

    uc3A41 = ScalerGetByte(P3A_41_FRAME_CTRL_41);
    uc0093 = ScalerGetByte(P0_93_OSD_MISC_PORT);

    ScalerSetBit(P0_93_OSD_MISC_PORT, ~_BIT7, 0x00); // disable osd double buffer

    if((uc3A41 & _BIT0) == _BIT0) // OSD Auto Rotation Enable
    {
        // _OSD_ROTATE_DEGREE_90 or _OSD_ROTATE_DEGREE_270
        ScalerSetByte(P3A_41_FRAME_CTRL_41, ((uc3A41 & (~(_BIT3 | _BIT0))) | _BIT3)); // rotate to cw0
        ScalerOsdFontLibraryRotation();

        ScalerSetByte(P3A_41_FRAME_CTRL_41, ((uc3A41 & (~(_BIT3 | _BIT0))) | _BIT3 | _BIT0)); // rotate to current direction
        ScalerSetBit(P3A_02_FRAME_CTRL_02, ~(_BIT0), 0x00); // osd disable
        ScalerOsdFontLibraryRotation();
    }
    else
    {
        // _OSD_ROTATE_DEGREE_0
        ScalerSetBit(P3A_41_FRAME_CTRL_41, ~_BIT3, _BIT3); // rotate
        ScalerOsdFontLibraryRotation();

        ScalerSetBit(P3A_41_FRAME_CTRL_41, ~(_BIT3 | _BIT0), (_BIT3 | _BIT0));
        ScalerSetBit(P3A_02_FRAME_CTRL_02, ~(_BIT0), 0x00); // osd disable
        ScalerOsdFontLibraryRotation();
        ScalerSetBit(P3A_41_FRAME_CTRL_41, ~_BIT0, 0x00); // rotate to cw0
    }

    ScalerSetBit(P3A_33_FRAME_CTRL_33, ~_BIT4, _BIT4);
    ScalerSetByte(P0_93_OSD_MISC_PORT, uc0093);
}



