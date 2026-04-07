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
// ID Code      : RL6851_Series_LDO.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6851_SERIES_LDO__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == _ON)
#warning "NOTE: PCB_EMBEDDED_LDO_DETECT() Should Be _EMBEDDED_LDO_OFF when _IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT is _ON!!!"
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
// Input Value  : ucPorStatus --> _POWER_STATUS_NORMAL/_POWER_STATUS_SAVING/_POWER_STATUS_OFF Select.
// Output Value : None
//--------------------------------------------------
void ScalerLDOPowerControl(EnumPowerStatus enumPorStatus)
{
#if(_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == _OFF)
    if((bit)PCB_EMBEDDED_LDO_DETECT() == _EMBEDDED_LDO_ON)
    {
        BYTE ucEfuseData = 0;

        switch(enumPorStatus)
        {
            case _POWER_STATUS_NORMAL:

                // Get eFuse Trim Data
                ScalerEfuseGetData(_OTPMEMORY_VCCK_LDO, 1, &ucEfuseData);

                // Check Data Value Exist or Not
                if(ucEfuseData != 0xFF)
                {
                    // Select LDO-D voltage output to Trimming value
                    ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), (ucEfuseData & (_BIT2 | _BIT1 | _BIT0)));
                }
                else
                {
                    // Select LDO-D voltage output is 0.90V
                    ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
                }

                break;

            case _POWER_STATUS_OFF:
            case _POWER_STATUS_SAVING:

                // Get eFuse Trim Data
                ScalerEfuseGetData(_OTPMEMORY_VCCK_LDO, 1, &ucEfuseData);

                // Check Data Value Exist or Not
                if(ucEfuseData != 0xFF)
                {
                    ucEfuseData = MAXOF((ucEfuseData & (_BIT2 | _BIT1 | _BIT0)), 1);

                    // Select LDO-D voltage output to Trimming value minus 1 level
                    ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), (ucEfuseData - 1));
                }
                else
                {
                    // Select LDO-D voltage output is 0.87V
                    ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
                }

                break;

            default:

                break;
        }
    }
    else
#endif
    {
        // Avoiding Complier Error
        enumPorStatus = enumPorStatus;

        // Disable LDO-D
        ScalerSetBit(P62_03_EBD_REGLATOR_D_CTRL1, ~_BIT7, 0x00);
    }
}

