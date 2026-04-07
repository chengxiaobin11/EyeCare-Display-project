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
// ID Code      : RL6449_Series_ColorPanelUniformityLDEnable.c
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
void ScalerColorPanelUniformityLDEnable(EnumFunctionOnOFF enumOn, EnumDBApply enumDBApply);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable Panel Uniformity Local Dimming Mode
// Input Value  : EnumFunctionOnOFF
// Output Value : None
//--------------------------------------------------
void ScalerColorPanelUniformityLDEnable(EnumFunctionOnOFF enumOn, EnumDBApply enumDBApply)
{
    if(enumOn == _FUNCTION_ON)
    {
        ScalerSetBit(P34_17_UN_LOCAL_DIMMING, ~(_BIT1 | _BIT0), _BIT0);
    }
    else if(enumOn == _FUNCTION_OFF)
    {
        ScalerSetBit(P34_17_UN_LOCAL_DIMMING, ~(_BIT1 | _BIT0), 0x00);
    }
    ScalerColorDDomainDBApply(enumDBApply);
}
