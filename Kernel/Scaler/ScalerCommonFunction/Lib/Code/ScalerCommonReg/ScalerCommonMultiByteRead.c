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
// ID Code      : ScalerCommonMultiByteRead.c
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

void ScalerRead(WORD usAddr, WORD usLength, BYTE *pucArray, bit bAutoInc);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Read data from registers of scaler and put it into an reading data array
// Input Value  : usAddr    --> Start address of register
//                usLength  --> Numbers of data we want to read
//                pArray    --> Pointer of the reading data array
//                bAutoInc  --> Address auto increasing select
// Output Value : None
//--------------------------------------------------
void ScalerRead(WORD usAddr, WORD usLength, BYTE *pucArray, bit bAutoInc)
{
    if(usLength != 0)
    {
        if(bAutoInc == _AUTOINC)
        {
            memcpy(pucArray, (BYTE xdata *)usAddr, usLength);
        }
        else
        {
            WORD usIndex = 0;

            for(usIndex = 0; usIndex < usLength; usIndex++)
            {
                pucArray[usIndex] = ScalerGetByte(usAddr);
            }
        }
    }
}
