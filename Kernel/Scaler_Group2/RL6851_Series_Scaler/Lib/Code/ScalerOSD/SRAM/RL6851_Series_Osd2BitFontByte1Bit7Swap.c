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
// ID Code      : RL6851_Series_Osd2BitFontByte1Bit7Swap.c
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
void ScalerOsd2BitFontByte1Bit7Swap(EnumOsd2BitCharBit7Type enumOsd2BitCharBit7Type);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : enumOsd2BitCharBit7Type -> _OSD_2BIT_CHAR_BIT7_BY_CHANGE_PALETTE or _OSD_2BIT_CHAR_BIT7_BY_SELECT_FONT
// Output Value :
//--------------------------------------------------
void ScalerOsd2BitFontByte1Bit7Swap(EnumOsd2BitCharBit7Type enumOsd2BitCharBit7Type)
{
    // Empty function in 6193
    enumOsd2BitCharBit7Type = enumOsd2BitCharBit7Type;
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsd2BitFontByte1Bit7Swap(_OSD_2BIT_CHAR_BIT7_BY_SELECT_FONT);
*/

