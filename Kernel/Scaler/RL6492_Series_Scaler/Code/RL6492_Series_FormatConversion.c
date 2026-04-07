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
// ID Code      : RL6492_Series_FormatConversion.c No.0000
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
void ScalerFmtCnvInitialSetting(EnumSourceSearchPort enumSourceSearchPort);
EnumFormatConversionSourceType ScalerFmtCnvGetSourceType(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initialize for format conversion
// Input Value  : enumSourceSearchPort --> input port
// Output Value : None
//--------------------------------------------------
void ScalerFmtCnvInitialSetting(EnumSourceSearchPort enumSourceSearchPort)
{
    switch(enumSourceSearchPort)
    {
        case _A0_INPUT_PORT:

            // Set source index to A0
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_ADC << 4));
            break;

        case _D0_INPUT_PORT:
        case _D1_INPUT_PORT:
        case _D2_INPUT_PORT:

            // Set source index to D0
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D0 << 4));
            break;

        default:
            break;
    }

    // Reset Read Index
    ScalerSetBit(P31_0C_CTS_FIFO_CTRL, ~(_BIT1), 0x00);
}

//--------------------------------------------------
// Description  : Show format conversion input source
// Input Value  : NONE
// Output Value : Current format conversino source
//--------------------------------------------------
EnumFormatConversionSourceType ScalerFmtCnvGetSourceType(void)
{
    switch(ScalerGetBit(P31_00_FC_INPUT_SEL_P01, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4)
    {
        case 0x02:
            return _FC_SOURCE_ADC;

        case 0x03:
            if(ScalerGetBit(PB_00_HD_DP_SEL, (_BIT1 | _BIT0)) == 0x00)
            {
                return _FC_SOURCE_D0;
            }
            else
            {
                if(ScalerGetBit(P1D_16_BANDGAP_02, _BIT7) == 0)
                {
                    return _FC_SOURCE_D1;
                }
                else
                {
                    return _FC_SOURCE_D2;
                }
            }

        default:
            return _FC_SOURCE_NONE;
    }
}

