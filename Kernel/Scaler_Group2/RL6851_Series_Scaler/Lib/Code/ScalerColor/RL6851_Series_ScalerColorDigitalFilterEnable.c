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
// ID Code      : RL6851_Series_ScalerColorDigitalFilterEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerColorLibInternalInclude.h"

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
void ScalerColorDigitalFilterEnable(EnumFunctionOnOFF enumOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//-------------------------------------------------
// Description  : Set digital filter Enable
// Input Value  : EnumFunctionOnOFF
// Output Value : None
//-------------------------------------------------
void ScalerColorDigitalFilterEnable(EnumFunctionOnOFF enumOn)
{
    BYTE ucCtrlReg = 0;

    if(enumOn == _FUNCTION_ON)
    {
        ScalerSetBit(P0_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT5 | _BIT4));
        ucCtrlReg = ScalerGetByte(P0_99_DIGITAL_FILTER_PORT);

        // write extension data separately to avoid autoinc
        ScalerSetBit(P0_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT5 | _BIT4));
        ScalerSetByte(P0_99_DIGITAL_FILTER_PORT, (ucCtrlReg | (_BIT7 | _BIT6 | _BIT5)));
    }
    else
    {
        ScalerSetBit(P0_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT5 | _BIT4));
        ucCtrlReg = ScalerGetByte(P0_99_DIGITAL_FILTER_PORT);

        // write extension data separately to avoid autoinc
        ScalerSetBit(P0_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT6 | _BIT5 | _BIT4));
        ScalerSetByte(P0_99_DIGITAL_FILTER_PORT, (ucCtrlReg & (~(_BIT7 | _BIT6 | _BIT5))));
    }
}
