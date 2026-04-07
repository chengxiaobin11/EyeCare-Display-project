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
// ID Code      : RL6369_Series_ColorUltraVividEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6369_Series_ColorLibInternalInclude.h"

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
void ScalerColorUltraVividEnable(EnumFunctionOnOFF enumFunctionOnOff, EnumDBApply enumDBApply);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable / Disable / Clock Gated UltraVivid Function
// Input Value  : enumFunctionOnOff -> _ENABLE or _DISABLE or _CLCOK_GATED
// Output Value : None
//--------------------------------------------------
void ScalerColorUltraVividEnable(EnumFunctionOnOFF enumFunctionOnOff, EnumDBApply enumDBApply)
{
    if(enumFunctionOnOff == _FUNCTION_ON)
    {
        // Enable UltraVivid Function
        ScalerSetBit(P14_C0_LSR_CTRL, ~_BIT7, _BIT7);
        // Wait for Double Buffer
        ScalerGlobalIDDomainDBApply(enumDBApply);
    }
    else
    {
        // Disable UltraVivid Function
        ScalerSetBit(P14_C0_LSR_CTRL, ~_BIT7, 0x00);
        // Wait for Double Buffer
        ScalerGlobalIDDomainDBApply(enumDBApply);
    }
}
