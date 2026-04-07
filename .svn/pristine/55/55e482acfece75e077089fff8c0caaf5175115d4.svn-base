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
// ID Code      : RL6463_Series_LDO.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6463_SERIES_LDO__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#ifndef _76PIN_PIN_21
#if(_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == _ON)
#warning "NOTE: PCB_EMBEDDED_LDO_DETECT() Should Be _EMBEDDED_LDO_OFF when _IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT is _ON!!!"
#endif
#endif


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
void ScalerLDOPowerControl(EnumPowerStatus enumPorStatus);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : LDO Power Control.
// Input Value  : ucPorStatus    --> _POWER_STATUS_NORMAL/_POWER_STATUS_SAVING/_POWER_STATUS_OFF Select.
// Output Value : None
//--------------------------------------------------
void ScalerLDOPowerControl(EnumPowerStatus enumPorStatus)
{
    bit bLDOSupport = (_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == _OFF);

#ifdef _76PIN_PIN_21
    bLDOSupport = _TRUE;
#endif

    if((bLDOSupport == _TRUE) &&
       ((bit)PCB_EMBEDDED_LDO_DETECT() == _EMBEDDED_LDO_ON))
    {
        switch(enumPorStatus)
        {
            case _POWER_STATUS_NORMAL:

#if(_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == _ON)
                // Select LDO-D voltage output is 1.04V
                ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
#else
                // Select LDO-D voltage output is 1.0V
                ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
#endif

                break;

            case _POWER_STATUS_OFF:
            case _POWER_STATUS_SAVING:

                // Select LDO-D voltage output is 0.96V
                ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

                break;

            default:

                break;
        }
    }
    else
    {
        // Avoiding Complier Error
        enumPorStatus = enumPorStatus;

        // Disable LDO-D
        ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~_BIT7, 0x00);
    }
}


