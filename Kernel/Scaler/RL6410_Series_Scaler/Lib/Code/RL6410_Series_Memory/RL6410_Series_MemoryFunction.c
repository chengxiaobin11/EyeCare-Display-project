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
// ID Code      : RL6410_Series_MemoryFunction.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_MemoryLibInternalInclude.h"

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
DWORD ScalerMemoryCalculateNumberAndRemain(DWORD ulTotalSize, WORD usLength, bit bDummy);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Calculate the number and remain
// Input Value  : ulTotalSize --> Image total size
//                ucLength --> Length of SDRAM access
// Output Value : Number and Remain
//--------------------------------------------------
DWORD ScalerMemoryCalculateNumberAndRemain(DWORD ulTotalSize, WORD usLength, bit bDummy)
{
    if(bDummy == _TRUE)
    {
        /// In 6193, System Bridge data bus is 128 bits,
        ///   but its burst length and address unit is still 64 bits.
        ///   So NUM, LEN, and REM must be a multiple of 2.
        ulTotalSize += (ulTotalSize % 2);
    }

    if((ulTotalSize % usLength) != 0)
    {
        PDATA_WORD(0) = ulTotalSize / usLength; // Number
        PDATA_WORD(1) = ulTotalSize % usLength; // Remain
    }
    else
    {
        ulTotalSize = ulTotalSize - usLength;
        PDATA_WORD(0) = ulTotalSize / usLength; // Number
        PDATA_WORD(1) = usLength;               // Remain
    }

    return (((DWORD)PDATA_WORD(1) << 16) | PDATA_WORD(0));
}

