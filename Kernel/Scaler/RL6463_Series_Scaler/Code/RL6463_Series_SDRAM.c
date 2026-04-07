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
// ID Code      : RL6463_Series_SDRAM.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

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
#if(_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM)
void ScalerSdramPowerEnable(bit bOn);
void ScalerSdramPinshareInitial(void);
void ScalerSdramMpllPowerDown(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM)
//--------------------------------------------------
// Description  : Sdram ScalerSdramPowerMode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramPowerEnable(bit bOn)
{
    if(bOn == _ON)
    {
        // Config for SDRAM MCM Mde
        ScalerSetBit(P4_00_SDR_CTRL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Disable Sdram CKE force low into Power down mode
        ScalerSetBit(P4_A6_SDR_SLEW_RATE, ~_BIT1, 0x00);

        // Precharge power down mode select
        ScalerSetBit(P4_B7_SDR_POWER_CTRL0, ~(_BIT5 | _BIT4), 0x00);

        // Delay Time us [5,x] Waiting for DDR setting
        DELAY_5US();

        // Inactive power down
        ScalerSetBit(P4_B7_SDR_POWER_CTRL0, ~_BIT7, 0x00);
    }
    else
    {
        // Config for SDRAM MCM Mde
        ScalerSetBit(P4_00_SDR_CTRL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Self Refresh mode select
        ScalerSetBit(P4_B7_SDR_POWER_CTRL0, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

        // Delay Time us [5,x] Waiting for DDR setting
        DELAY_5US();

        // Active power down
        ScalerSetBit(P4_B7_SDR_POWER_CTRL0, ~_BIT7, _BIT7);

        // Enable Sdram CKE force low into Power down mode
        ScalerSetBit(P4_A6_SDR_SLEW_RATE, ~_BIT1, _BIT1);

        // Config for Non-SDRAM MCM Mde
        ScalerSetBit(P4_00_SDR_CTRL, ~(_BIT1 | _BIT0), 0x00);
    }
}

//--------------------------------------------------
// Description  : Sdram Pinshare Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramPinshareInitial(void)
{
    ScalerSetByte(P4_01_SDR_CLK_CTRL0, 0x00);
    ScalerSetByte(P4_02_SDR_CMD_CTRL, 0x00);
    ScalerSetByte(P4_03_SDR_DQ_CTRL0, 0x00);
    ScalerSetByte(P4_04_SDR_DQ_CTRL1, 0x00);
    ScalerSetByte(P4_05_SDR_ADR_CTRL, 0x00);
    ScalerSetByte(P4_06_SDR_DQM_CTRL, 0x00);
}

//--------------------------------------------------
// Description  : SDRAM MPLL Power Down
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramMpllPowerDown(void)
{
    // Power off MPLL -> No MPLL
}
#endif
