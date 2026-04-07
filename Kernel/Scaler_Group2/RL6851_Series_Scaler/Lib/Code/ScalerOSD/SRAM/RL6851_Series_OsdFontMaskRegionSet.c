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
// ID Code      : RL6851_Series_OsdFontMaskRegionSet.c
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
void ScalerOsdFontMaskRegionSet(EnumOsdMapType enumOsdMapType, BYTE ucRowStart, BYTE ucRowEnd, BYTE ucColumnStart, BYTE ucColumnEnd);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : MASK Specific Region of Font A/B
// Input Value  : ucRowStart
// Input Value  : ucRowEnd
// Input Value  : ucColumnStart
// Input Value  : ucColumnEnd
// Output Value :
//--------------------------------------------------
void ScalerOsdFontMaskRegionSet(EnumOsdMapType enumOsdMapType, BYTE ucRowStart, BYTE ucRowEnd, BYTE ucColumnStart, BYTE ucColumnEnd)
{
    if(enumOsdMapType == _OSD_A)
    {
        // MASK Row Start/End of Font A
        ScalerSetBit(P3A_45_FRAME_CTRL_45, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (ucRowStart & 0x7F));
        ScalerSetBit(P3A_46_FRAME_CTRL_46, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (ucRowEnd & 0x7F));

        // MASK Column Start/End of Font A
        ScalerSetByte(P3A_49_FRAME_CTRL_49, ucColumnStart);
        ScalerSetByte(P3A_4A_FRAME_CTRL_4A, ucColumnEnd);
    }
    else
    {
        // MASK Row Start/End of Font B
        ScalerSetBit(P3A_47_FRAME_CTRL_47, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (ucRowStart & 0x7F));
        ScalerSetBit(P3A_48_FRAME_CTRL_48, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (ucRowEnd & 0x7F));

        // MASK Column Start/End of Font B
        ScalerSetByte(P3A_4B_FRAME_CTRL_4B, ucColumnStart);
        ScalerSetByte(P3A_4C_FRAME_CTRL_4C, ucColumnEnd);
    }
}

