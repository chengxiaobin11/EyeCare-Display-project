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
// ID Code      : RL6851_Series_ScalerMDomainDisplayTimingGenDBEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "RL6851_Series_ScalerLibInternalInclude.h"

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
void ScalerMDomainDisplayTimingGenDBEnable(bit bEnable);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Display Timing Gen Double Buffer
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMDomainDisplayTimingGenDBEnable(bit bEnable)
{
    // Set Display Timing Gen Double Buffer
    if(bEnable == _ENABLE)
    {
        ScalerSetBit(P0_2F_DISPLAY_FORMAT_DOUBLE_BUFFER, ~(_BIT7 | _BIT6), _BIT7);
    }
    else
    {
        ScalerSetBit(P0_2F_DISPLAY_FORMAT_DOUBLE_BUFFER, ~(_BIT7 | _BIT6), 0x00);
    }
}

