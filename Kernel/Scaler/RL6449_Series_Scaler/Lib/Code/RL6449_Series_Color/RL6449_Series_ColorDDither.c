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
// ID Code      : RL6449_Series_ColorDDither.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _DITHER_TABLE_LENGTH    (144)
#define _TEMPORAL_TABLE_LENGTH  (32)

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
void ScalerColorDDitherLoadDitherTable(BYTE code *pucDitherTable, BYTE ucBankAddress);
void ScalerColorDDitherLoadTempoTable(BYTE code *pucTempoTable, BYTE ucBankAddress);
void ScalerColorDDitherLoadSetting(DWORD ulSettingOption);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust D Dither Setting
// Input Value  :
//                pucDitherTable : Dither Table Pointer
//                ucBankAddress : Bank Address
// Output Value : None
//--------------------------------------------------
void ScalerColorDDitherLoadDitherTable(BYTE code *pucDitherTable, BYTE ucBankAddress)
{
    if(pucDitherTable != _NULL_POINTER)
    {
        ScalerSetBit(P0_6A_D_DITHER_COMMON_CTRL1, ~(_BIT7 | _BIT6), 0x80);
        ScalerBurstWrite(pucDitherTable, _DITHER_TABLE_LENGTH, ucBankAddress, P0_69_D_DITHER_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        ScalerSetBit(P0_6A_D_DITHER_COMMON_CTRL1, ~(_BIT7 | _BIT6), 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust D Dither Setting
// Input Value  :
//                pucTempoTable : Temporal Table Pointer
//                ucBankAddress : Bank Address
// Output Value : None
//--------------------------------------------------
void ScalerColorDDitherLoadTempoTable(BYTE code *pucTempoTable, BYTE ucBankAddress)
{
    if(pucTempoTable != _NULL_POINTER)
    {
        ScalerSetBit(P0_6A_D_DITHER_COMMON_CTRL1, ~(_BIT7 | _BIT6), 0xC0);
        ScalerBurstWrite(pucTempoTable, _TEMPORAL_TABLE_LENGTH, ucBankAddress, P0_69_D_DITHER_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        ScalerSetBit(P0_6A_D_DITHER_COMMON_CTRL1, ~(_BIT7 | _BIT6), 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust D Dither Common Setting
// Input Value  : D Dither Setting Option
// Output Value : None
//--------------------------------------------------
void ScalerColorDDitherLoadSetting(DWORD ulSettingOption)
{
    BYTE ucData = 0;
    ScalerSetBit(P0_6A_D_DITHER_COMMON_CTRL1, ~(_BIT7 | _BIT6 | _BIT4 | _BIT1 | _BIT0), ulSettingOption & 0x000000FF);
    ScalerSetByte(P0_6B_D_DITHER_REGISTER_ADDR, _P0_69_PT_00_D_DITHER_COMMON_SET0);
    ScalerSetByte(P0_69_D_DITHER_DATA_ACCESS, (ulSettingOption & 0x0000FF00) >> 8);
    ScalerSetByte(P0_6B_D_DITHER_REGISTER_ADDR, _P0_69_PT_02_D_DITHER_COMMON_SET2);
    ScalerSetByte(P0_69_D_DITHER_DATA_ACCESS, (ulSettingOption & 0x00FF0000) >> 16);
    ScalerSetByte(P0_6B_D_DITHER_REGISTER_ADDR, _P0_69_PT_0D_D_DITHER_COMMON_CTRL2);
    ScalerSetByte(P0_69_D_DITHER_DATA_ACCESS, (ulSettingOption & 0xFF000000) >> 24);

    // reset frame counter
    ScalerSetByte(P0_6B_D_DITHER_REGISTER_ADDR, _P0_69_PT_01_D_DITHER_COMMON_SET1);
    ucData = ScalerGetByte(P0_69_D_DITHER_DATA_ACCESS) | _BIT7;
    ScalerSetByte(P0_6B_D_DITHER_REGISTER_ADDR, _P0_69_PT_01_D_DITHER_COMMON_SET1);
    ScalerSetByte(P0_69_D_DITHER_DATA_ACCESS, ucData);
}
