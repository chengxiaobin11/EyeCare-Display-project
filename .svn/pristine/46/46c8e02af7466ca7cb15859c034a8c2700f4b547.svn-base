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
// ID Code      : RL6449_Series_ColorPanelUniformityLDSramToggle.c
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
void ScalerColorPanelUniformityLDSramToggle(EnumDBApply enumDBApply);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Toggle uniformity sram in local dimming mode
// Input Value  : enumDBApply
// Output Value : None
//--------------------------------------------------
void ScalerColorPanelUniformityLDSramToggle(EnumDBApply enumDBApply)
{
    if(ScalerGetBit(P34_17_UN_LOCAL_DIMMING, _BIT1) == _BIT1)
    {
        ScalerSetBit(P34_17_UN_LOCAL_DIMMING, ~_BIT1, 0x00);
    }
    else
    {
        ScalerSetBit(P34_17_UN_LOCAL_DIMMING, ~_BIT1, _BIT1);
    }
    ScalerColorDDomainDBApply(enumDBApply);
}

