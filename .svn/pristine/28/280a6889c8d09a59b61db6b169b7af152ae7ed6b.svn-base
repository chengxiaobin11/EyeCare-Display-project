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
// ID Code      : RL6851_Series_ScalerColorWaitDDomainDBApply.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerColorLibInternalInclude.h"

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
bit ScalerColorWaitDDomainDBApply(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Wait D-Domain double buffer Ready
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerColorWaitDDomainDBApply(void)
{
#if(_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_I)
    if(ScalerGetBit(P31_B0_D_DB_CTRL0, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6))
    {
        // Check D domain status
        if((ScalerGetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, _BIT0) == 0x00) ||
           (GET_DPLL_POWER_STATUS() == _FALSE))
        {
            return _FALSE;
        }

        // Wait D double buffer
        return ScalerTimerPollingFlagProc(_DOUBLE_BUFFER_WAIT_TIME, P31_B0_D_DB_CTRL0, (_BIT6), 0);
    }
#endif

    return _TRUE;
}
