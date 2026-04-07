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
// ID Code      : RL6851_Series_ScalerCommonPower.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_POWER__

#include "ScalerCommonFunctionInclude.h"

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
void ScalerPowerXtalPower(BYTE ucOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Xtal Power Control.
// Input Value  : ucOn    --> On/Off Select.
// Output Value : None
//--------------------------------------------------
void ScalerPowerXtalPower(BYTE ucOn)
{
    if(ucOn == _ON)
    {
        // Xtal has power down
        if(ScalerGetBit(P80_0E_XTAL_CTRL0, _BIT7) == 0x00)
        {
            // Bit4~3 : 00 --> XI/XO Pad Driving to Strong
            ScalerSetBit(P80_0F_XTAL_CTRL1, ~(_BIT4 | _BIT3), 0x00);

            // Power On External Xtal
            ScalerSetBit(P80_0E_XTAL_CTRL0, ~_BIT7, _BIT7);

            // Waiting for xtal stable.
            ScalerTimerDelayXms(6);
        }

        // Bit4~3 : 00 --> XI/XO Pad Driving to weak
        ScalerSetBit(P80_0F_XTAL_CTRL1, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
    }
    else
    {
        // Power down External Xtal
        ScalerSetBit(P80_0E_XTAL_CTRL0, ~_BIT7, 0x00);

        // Bit4~3 : 00 --> XI/XO Pad Driving to weak
        ScalerSetBit(P80_0F_XTAL_CTRL1, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
    }
}

