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
// ID Code      : ScalerColorHLWDDomainEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerColorLibInternalInclude.h"

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
void ScalerColorHLWDDomainEnable(EnumFunctionOnOFF enumOn);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable/Disable Ddomain HLW,
// Input Value  : EnumFunctionOnOFF
// Output Value : none
//--------------------------------------------------
void ScalerColorHLWDDomainEnable(EnumFunctionOnOFF enumOn)
{
    // If HLW Without Double Buffer, Wait for DEN Stop
    if(ScalerGlobalGetHLWDBStatus() == _FALSE)
    {
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    }

    if(enumOn == _FUNCTION_ON)
    {
        // Ddomain one HLW
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~_BIT0, _BIT0);
    }
    else // bOn == _OFF || bOn == _CLOCK_GATED
    {
        ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~_BIT0, 0x00);
    }
}

