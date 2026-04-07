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
// ID Code      : RL6449_Series_ColorDDomainDBApply.c
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
void ScalerColorDDomainDBApply(EnumDBApply enumDBApply);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Set D domain double buffer apply
// Input Value  : DB apply polling/ no polling/ none
// Output Value : None
//--------------------------------------------------
void ScalerColorDDomainDBApply(EnumDBApply enumDBApply)
{
    if(ScalerGlobalGetIDCode() >= _RL6449_VER_D_ID_CODE)
    {
        if(enumDBApply != _DB_APPLY_NONE)
        {
            // Check D domain status
            if((ScalerGetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, _BIT0) == 0x00) ||
               (GET_DPLL_POWER_STATUS() == _FALSE))
            {
                return;
            }
        }

        switch(enumDBApply)
        {
            case _DB_APPLY_NO_POLLING:

                // Set D apply bit
                ScalerSetBit(P31_B0_D_DB_CTRL0, ~(_BIT6), (_BIT6));

                break;

            case _DB_APPLY_POLLING:

                // Set D apply bit
                ScalerSetBit(P31_B0_D_DB_CTRL0, ~(_BIT6), (_BIT6));

                if(enumDBApply == _DB_APPLY_POLLING)
                {
                    // Wait D double buffer
                    ScalerTimerPollingFlagProc(_DOUBLE_BUFFER_WAIT_TIME, P31_B0_D_DB_CTRL0, (_BIT6), 0);
                }

                break;

            default:

                break;
        }
    }
}
