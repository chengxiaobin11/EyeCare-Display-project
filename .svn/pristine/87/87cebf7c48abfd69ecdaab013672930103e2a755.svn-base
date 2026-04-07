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
// ID Code      : RL6851_Series_ScalerDataPortAccessGetDword.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerCommonRegLibInternalInclude.h"

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
DWORD ScalerGetDataPortDword(WORD usAddr, BYTE ucValue, bit bAutoInc);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get bytes from selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Address we want to Get
//                bAutoInc  --> Address auto increasing select
// Output Value : None
//--------------------------------------------------
DWORD ScalerGetDataPortDword(WORD usAddr, BYTE ucValue, bit bAutoInc)
{
    BYTE pucArray[4];
    memset(pucArray, 0x00, sizeof(pucArray));

    ScalerGetDataPortByte(usAddr, ucValue, 4, pucArray, bAutoInc);

    return ((DWORD)pucArray[0] << 24) +
           ((DWORD)pucArray[1] << 16) +
           ((DWORD)pucArray[2] << 8) +
           ((DWORD)pucArray[3] << 0);
}

