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
// ID Code      : RL6410_Series_ColorSampling420to422D3Enable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_ColorLibInternalInclude.h"

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
void ScalerColor420To422D3Enable(EnumFunctionOnOFF enumFunctionOnOFF);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable / Disable 420To422 for D3 source
// Input Value  : Enable or Disable
// Output Value : None
//--------------------------------------------------
void ScalerColor420To422D3Enable(EnumFunctionOnOFF enumFunctionOnOFF)
{
    if(enumFunctionOnOFF == _FUNCTION_ON)
    {
        WORD usCount = 0;

        ScalerSetBit(P31_31_YUV420_TO_422_CTL_D2D3, ~_BIT4, _BIT4);
        ScalerSetBit(P31_33_YUV420_TO_YUV422_D3, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0)); // Set FIFO start point = 3

        do
        {
            if(usCount != 0)
            {
                ScalerSetBit(P72_A6_TMDS_OUTCTL, ~_BIT3, _BIT3); // Enable Clock
                ScalerSetBit(P31_33_YUV420_TO_YUV422_D3, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3), 0x00); // Disable 420 function & FIFO
            }

            ScalerSetBit(P72_A6_TMDS_OUTCTL, ~_BIT3, 0x00); // Clock gated
            ScalerSetBit(P31_33_YUV420_TO_YUV422_D3, ~(_BIT7 | _BIT5 | _BIT4), _BIT7); // Enable 420 function
            ScalerSetBit(P31_33_YUV420_TO_YUV422_D3, ~(_BIT5 | _BIT4 | _BIT3), _BIT3); // Enable FIFO
            ScalerSetBit(P31_33_YUV420_TO_YUV422_D3, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4)); // Clear underflow/overflow flag
            usCount = usCount + 1;
        }
        while(ScalerGetBit(P31_33_YUV420_TO_YUV422_D3, _BIT5) == _BIT5); // if underflow occured

        ScalerSetBit(P72_A6_TMDS_OUTCTL, ~_BIT3, _BIT3); // Enable clock
    }
    else
    {
        ScalerSetBit(P31_33_YUV420_TO_YUV422_D3, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3), 0x00);
        ScalerSetBit(P31_34_YUV420_TO_YUV422_HSTM0_D2D3, ~_BIT6, 0x00); // reset duplicate mode
    }
}

