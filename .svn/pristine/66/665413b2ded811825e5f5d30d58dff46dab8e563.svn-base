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
// ID Code      : ScalerCommonMultiByteWrite.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerCommonRegLibInternalInclude.h"

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

void ScalerWrite(WORD usAddr, WORD usLength, BYTE *pucArray, bit bAutoInc);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Write a data array into registers
// Input Value  : usAddr    --> Start address of register
//                usLength  --> Numbers of data we want to write
//                pArray    --> Pointer of the writing data array
//                bAutoInc  --> Address auto increasing select
// Output Value : None
//--------------------------------------------------
void ScalerWrite(WORD usAddr, WORD usLength, BYTE *pucArray, bit bAutoInc)
{
    if(usLength != 0)
    {
        if(bAutoInc == _AUTOINC)
        {
            memcpy((BYTE xdata *)usAddr, pucArray, usLength);
        }
        else
        {
            WORD usIndex = 0;

            for(usIndex = 0; usIndex < usLength; usIndex++)
            {
                ScalerSetByte(usAddr, pucArray[usIndex]);
            }
        }
    }
}
