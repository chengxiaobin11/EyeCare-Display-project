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
// ID Code      : RL6851_Series_ScalerDataPortAccessSetDword.c
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
void ScalerSetDataPortDword(WORD usAddr, BYTE ucValue1, DWORD ulValue2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set the value into selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue1  --> Data Port Value we want to set
//                ulValue2  --> Data Value we want to set
// Output Value : None
//--------------------------------------------------
void ScalerSetDataPortDword(WORD usAddr, BYTE ucValue1, DWORD ulValue2)
{
    ScalerSetDataPortByte(usAddr, ucValue1, (BYTE)(ulValue2 >> 24));
    ScalerSetDataPortByte(usAddr, ucValue1 + 1, (BYTE)(ulValue2 >> 16));
    ScalerSetDataPortByte(usAddr, ucValue1 + 2, (BYTE)(ulValue2 >> 8));
    ScalerSetDataPortByte(usAddr, ucValue1 + 3, (BYTE)(ulValue2 >> 0));
}

