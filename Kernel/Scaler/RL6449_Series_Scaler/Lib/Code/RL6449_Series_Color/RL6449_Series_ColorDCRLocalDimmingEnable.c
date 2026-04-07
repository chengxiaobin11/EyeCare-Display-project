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
// ID Code      : RL6449_Series_ColorDCRLocalDimmingEnable.c
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
void ScalerColorDCRLocalDimmingEnable(EnumFunctionOnOFF enumOn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : DCR Local Dimming Enable/Disable
// Input Value  : DCR Local Dimming Enable/Disable Option
// Output Value : none
//--------------------------------------------------
void ScalerColorDCRLocalDimmingEnable(EnumFunctionOnOFF enumOn)
{
    if(enumOn == _FUNCTION_ON)
    {
        ScalerSetDataPortBit(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_27_CTS_BRI_SET, ~_BIT0, _BIT0);
        ScalerSetBit(P7_C7_DCC_CTRL_0, ~_BIT7, _BIT7);
    }
    else
    {
        ScalerSetDataPortBit(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_27_CTS_BRI_SET, ~_BIT0, 0x00);
    }
}
