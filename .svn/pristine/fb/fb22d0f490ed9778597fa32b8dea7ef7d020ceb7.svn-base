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
// ID Code      : RL6449_Series_ColorIAPSGainEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_ColorLibInternalInclude.h"

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
void ScalerColorIAPSGainEnable(EnumFunctionOnOFF enumOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable IAPS Gain Function
// Input Value  : EnumFunctionOnOFF
// Output Value : None
//--------------------------------------------------
void ScalerColorIAPSGainEnable(EnumFunctionOnOFF enumOn)
{
    if(enumOn == _FUNCTION_ON)
    {
        // Enable Soft Clamp and Iaps Gain
        ScalerSetBit(P7_E0_IAPS_GAIN_CTRL_M1, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Enable Double Buffer
        ScalerSetBit(P7_E4_IAPS_GAIN_DB_CTRL_M1, ~(_BIT0), _BIT0);
    }
    else
    {
        ScalerSetBit(P7_E0_IAPS_GAIN_CTRL_M1, ~(_BIT0), 0x00);
    }
}
