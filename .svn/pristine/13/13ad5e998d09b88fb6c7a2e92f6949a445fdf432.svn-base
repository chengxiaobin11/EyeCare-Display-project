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
// ID Code      : RL6492_Series_ColorDCCEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6492_Series_ColorLibInternalInclude.h"

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
void ScalerColorDCCEnable(EnumFunctionOnOFF enumOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable DCC Function
// Input Value  : EnumFunctionOnOFF
// Output Value : None
//--------------------------------------------------
void ScalerColorDCCEnable(EnumFunctionOnOFF enumOn)
{
    if(enumOn == _FUNCTION_ON)
    {
        ScalerSetBit(P1_C7_DCLK_GATED_CTRL1, ~(_BIT5), _BIT5);
        ScalerSetBit(P7_C8_DCC_CTRL_1, ~_BIT7, _BIT7);
    }
    else if(enumOn == _FUNCTION_OFF)
    {
        ScalerSetBit(P7_C8_DCC_CTRL_1, ~_BIT7, 0x00);
    }
    else
    {
        ScalerSetBit(P7_C7_DCC_CTRL_0, ~_BIT7, 0x00);
        ScalerSetBit(P7_C8_DCC_CTRL_1, ~_BIT7, 0x00);
        ScalerTimerWaitForEvent(_EVENT_DEN_START);
        ScalerTimerDelayXms(2);
        ScalerSetBit(P1_C7_DCLK_GATED_CTRL1, ~(_BIT5), 0x00);
    }
}
