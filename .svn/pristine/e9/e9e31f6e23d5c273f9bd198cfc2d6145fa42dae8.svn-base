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
// ID Code      : RL6432_Series_ColorSetScalingDownMaskLSB.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6432_Series_ColorLibInternalInclude.h"


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
void ScalerColorSetScalingDownMaskLSB(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Scale Down Mask LSB
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerColorSetScalingDownMaskLSB(void)
{
    if(ScalerMDomainGetColorDepth() == _COLOR_DEPTH_8_BITS)
    {
        ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~_BIT0, _BIT0);
    }
    else
    {
        ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~_BIT0, 0x00);
    }
}
