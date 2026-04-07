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
// ID Code      : ScalerCommonDataPortAccessSetWord.c
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
void ScalerSetDataPortWord(WORD usAddr, BYTE ucValue1, WORD usValue2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set the value into selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue1  --> Data Port Value we want to set
//                usValue2  --> Data Value we want to set
// Output Value : None
//--------------------------------------------------
void ScalerSetDataPortWord(WORD usAddr, BYTE ucValue1, WORD usValue2)
{
    ScalerSetDataPortByte(usAddr, ucValue1, HIBYTE(usValue2));
    ScalerSetDataPortByte(usAddr, ucValue1 + 1, LOBYTE(usValue2));
}

