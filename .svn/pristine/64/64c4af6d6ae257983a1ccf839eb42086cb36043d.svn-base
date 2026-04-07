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
// ID Code      : ScalerCommonDataPortAccessGetSingleByte.c
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
BYTE ScalerGetDataPortSingleByte(WORD usAddr, BYTE ucValue);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get bytes from selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Address we want to Get
// Output Value : None
//--------------------------------------------------
BYTE ScalerGetDataPortSingleByte(WORD usAddr, BYTE ucValue)
{
    BYTE pucArray[1];
    memset(pucArray, 0x00, sizeof(pucArray));

    ScalerGetDataPortByte(usAddr, ucValue, 1, pucArray, _NON_AUTOINC);

    return pucArray[0];
}

