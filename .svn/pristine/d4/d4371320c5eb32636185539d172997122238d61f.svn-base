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
// ID Code      : ScalerColorDDitherLoadSeqTable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerColorLibInternalInclude.h"

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
void ScalerColorDDitherLoadSeqTable(BYTE code *pucSeqTable, BYTE ucSeqLength, BYTE ucBankAddress);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust D Dither Setting
// Input Value  :
//                pucSeqTable : Seq Table Pointer
//                ucSeqLength : Seq Table Length
//                ucBankAddress : Bank Address
// Output Value : None
//--------------------------------------------------
void ScalerColorDDitherLoadSeqTable(BYTE code *pucSeqTable, BYTE ucSeqLength, BYTE ucBankAddress)
{
    if(pucSeqTable != _NULL_POINTER)
    {
        ScalerSetBit(P0_6A_D_DITHER_COMMON_CTRL1, ~(_BIT7 | _BIT6), 0x40);
        ScalerBurstWrite(pucSeqTable, ucSeqLength, ucBankAddress, P0_69_D_DITHER_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
        ScalerSetBit(P0_6A_D_DITHER_COMMON_CTRL1, ~(_BIT7 | _BIT6), 0x00);
    }
}

