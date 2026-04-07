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
// ID Code      : RL6432_Series_ColorUltraVividGetStatus.c
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
bit ScalerColorUltraVividGetStatus(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get UltraVivid Status
// Input Value  : None
// Output Value : ON/OFF
//--------------------------------------------------
bit ScalerColorUltraVividGetStatus(void)
{
    if((ScalerGetBit(P11_A1_I_DLTI_CTRL_M1, _BIT0) == 0x00) &&
       (ScalerGetBit(P14_C0_LSR_CTRL, _BIT7) == 0x00) &&
       ((ScalerGetBit(P12_A0_SR_SHP_CTRL_0, (_BIT6 | _BIT5 | _BIT4)) == 0x00) &&
        (ScalerGetBit(P12_A1_SR_SHP_CTRL_1, (_BIT2 | _BIT1 | _BIT0)) == 0x00)))
    {
        return _OFF;
    }
    else
    {
        return _ON;
    }
}

