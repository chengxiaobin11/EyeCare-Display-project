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
// ID Code      : RL6851_Series_ScalerColorIDither.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerColorLibInternalInclude.h"


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _DITHER_TABLE_LENGTH    (24)
#define _TEMPORAL_TABLE_LENGTH  (4)

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
void ScalerColorIDitherLoadDitherTable(BYTE code *pucDitherTable, BYTE ucBankAddress);
void ScalerColorIDitherLoadSeqTable(BYTE code *pucSeqTable, BYTE ucSeqLength, BYTE ucBankAddress);
void ScalerColorIDitherLoadTemporalTable(BYTE code *pucTempoTable, BYTE ucBankAddress);
void ScalerColorIDitherLoadSetting(WORD usAdjustOption);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Adjust IDither Setting
// Input Value  :
//                pucDitherTable : Dither Table Pointer
//                ucBankAddress : Bank Address
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherLoadDitherTable(BYTE code *pucDitherTable, BYTE ucBankAddress)
{
    if(pucDitherTable != _NULL_POINTER)
    {
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), 0x80);
        ScalerBurstWrite(pucDitherTable, _DITHER_TABLE_LENGTH, ucBankAddress, P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust IDither Setting
// Input Value  :
//                pucDitherTable : Seq Table Pointer.
//                ucSeqLength : table len
//                ucBankAddress : Bank Address
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherLoadSeqTable(BYTE code *pucSeqTable, BYTE ucSeqLength, BYTE ucBankAddress)
{
    if(pucSeqTable != _NULL_POINTER)
    {
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), 0x40);
        ScalerBurstWrite(pucSeqTable, ucSeqLength, ucBankAddress, P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust IDither Setting
// Input Value  :
//                pucDitherTable : Temporal Table Pointer
//              ucBankAddress : Bank Address
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherLoadTemporalTable(BYTE code *pucTempoTable, BYTE ucBankAddress)
{
    if(pucTempoTable != _NULL_POINTER)
    {
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), 0xC0);
        ScalerBurstWrite(pucTempoTable, _TEMPORAL_TABLE_LENGTH, ucBankAddress, P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust IDither Setting
// Input Value  : usAdjustOption->Adjust setting
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherLoadSetting(WORD usAdjustOption)
{
    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), usAdjustOption & 0x001F);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (usAdjustOption & 0x7E00) >> 8);

#if(_IDITHER_TYPE == _IDITHER_GEN_3_4_SEQ_TRUNCATE_6_4_2_BIT)
    ScalerSetBit(P0_20_M1_DUMMY2, ~(_BIT7), (usAdjustOption & 0x0080));
#endif
}

