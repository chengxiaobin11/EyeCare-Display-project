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
// ID Code      : RL6851_Series_ScalerTconGlobalEnable.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerTconLibInternalInclude.h"

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
void ScalerTconGlobalEnable(bit bEnable);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Set Tcon global control
// Input Value  : bEnable --> Tcon global enable
// Output Value : None
//--------------------------------------------------
void ScalerTconGlobalEnable(bit bEnable)
{
    if(bEnable == _ON)
    {
        ScalerSetDataPortBit(P15_A3_TCON_ADDR, _P15_A4_PT_00_TC_CTRL0, ~(_BIT7 | _BIT2), (_BIT7 | _BIT2));
    }
    else
    {
        ScalerSetDataPortBit(P15_A3_TCON_ADDR, _P15_A4_PT_00_TC_CTRL0, ~_BIT7, 0x00);
    }
}

