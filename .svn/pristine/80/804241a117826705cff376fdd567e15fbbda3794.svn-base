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
// ID Code      : RL6369_Series_ColorUltraVividSetDisable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6369_Series_ColorLibInternalInclude.h"

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
bit ScalerColorUltraVividSetDisable(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set UltraVivid Status by SD FREESYNC Enable
// Input Value  : None
// Output Value : _FALSE/_TRUE
//--------------------------------------------------
bit ScalerColorUltraVividSetDisable(void)
{
    if(ScalerGetBit(P0_26_SD_FILTER_CONTROL_REG_M1, _BIT1) == 0x00)
    {
        return _FALSE;
    }
    else
    {
        return _TRUE;
    }
}

