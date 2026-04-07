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
// ID Code      : RL6449_Series_ColorSampling420to422D2D3Enable.c
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
void ScalerColor420To422D2D3Enable(EnumSourceSearchPort enumSourceSearchPort, EnumFunctionOnOFF enumFunctionOnOFF);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable / Disable 420To422 for D2 source
// Input Value  : Enable or Disable
// Output Value : None
//--------------------------------------------------
void ScalerColor420To422D2D3Enable(EnumSourceSearchPort enumSourceSearchPort, EnumFunctionOnOFF enumFunctionOnOFF)
{
    enumSourceSearchPort = enumSourceSearchPort;

    if(enumFunctionOnOFF == _FUNCTION_ON)
    {
        WORD usCount = 0;
        WORD usOutctl = (enumSourceSearchPort == _D2_INPUT_PORT) ? P71_A6_TMDS_OUTCTL : P72_A6_TMDS_OUTCTL;

        ScalerSetBit(P31_31_YUV420_TO_422_CTL, ~_BIT6, _BIT6);
        ScalerSetBit(P31_32_YUV420_TO_YUV422, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0)); // Set FIFO start point = 3

        do
        {
            if(usCount != 0)
            {
                ScalerSetBit(usOutctl, ~_BIT3, _BIT3); // Enable Clock
                ScalerSetBit(P31_32_YUV420_TO_YUV422, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3), 0x00); // Disable 420 function & FIFO
            }

            ScalerSetBit(usOutctl, ~_BIT3, 0x00); // Clock gated
            ScalerSetBit(P31_32_YUV420_TO_YUV422, ~(_BIT7 | _BIT5 | _BIT4), _BIT7); // Enable 420 function
            ScalerSetBit(P31_32_YUV420_TO_YUV422, ~(_BIT5 | _BIT4 | _BIT3), _BIT3); // Enable FIFO
            ScalerSetBit(P31_32_YUV420_TO_YUV422, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4)); // Clear underflow/overflow flag
            usCount = usCount + 1;
        }
        while(ScalerGetBit(P31_32_YUV420_TO_YUV422, _BIT5) == _BIT5); // if underflow occured

        ScalerSetBit(usOutctl, ~_BIT3, _BIT3); // Enable clock
    }
    else
    {
        ScalerSetBit(P31_32_YUV420_TO_YUV422, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3), 0x00);
        ScalerSetBit(P31_34_YUV420_TO_YUV422_HSTM0, ~_BIT7, 0x00); // reset duplicate mode
    }
}
