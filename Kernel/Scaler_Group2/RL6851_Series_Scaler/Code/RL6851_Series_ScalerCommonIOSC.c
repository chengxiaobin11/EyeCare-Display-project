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
// ID Code      : RL6851_Series_ScalerCommonIOSC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_IOSC__

#include "ScalerCommonFunctionInclude.h"

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
void ScalerIOSCTrimming(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Internal Oscillator Triming.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerIOSCTrimming(void)
{
    SBYTE chcTempInx = 0;

    // Disable auto trimming.
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, 0x00);

    // Trim Resolution select, Fosc=counter * Fxtal / 1000
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT5, 0x00);

    // Wait time for Internal OSC Stable->15*2^10 Tref
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT4, _BIT4);

    // Wait time for trimming->4*2^10 Tref
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

#if(_INTERNAL_OSC_XTAL == _IOSC28000K)
    // Trimming comparason target 0x7A4 --> IOSC=28M at Xtal=14.318MHz
    ScalerSetByte(P6_A1_OSC_TRIM_CTRL1, 0xA4);
    ScalerSetBit(P6_A5_EMB_BGRES, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x07);
#endif

    // Switch to hardware Auto trimming result.
    ScalerSetBit(P6_A2_OSC_TRIM_CTRL2, ~_BIT7, 0x00);

    // Enable trimming
    ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, _BIT7);

    //-------Use manual mode go back recheck best step start --------
    // Wait for auto trimming stop, time-consuming ~= 3.36ms
    if(ScalerTimerPollingFlagProc(10, P6_A0_OSC_TRIM_CTRL0, _BIT6, _TRUE) == _FALSE)
    {
        return;
    }

    // Back up final result of auto trimming
    pData[0] = (ScalerGetBit(P6_A7_OSC_TRIM_CTRL3, (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)));
    pData[3] = pData[0];

    // Get target iosc cycle counter
    PDATA_WORD(5) = (ScalerGetBit(P6_A5_EMB_BGRES, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | ScalerGetByte(P6_A1_OSC_TRIM_CTRL1);

    // Initial variable
    PDATA_WORD(7) = 0xFFF;

    // Change to manual trimming mode
    ScalerSetBit(P6_A3_EMBEDDED_OSC_CTRL, ~_BIT6, 0x00);
    ScalerSetBit(P6_A2_OSC_TRIM_CTRL2, ~_BIT7, _BIT7);

    for(chcTempInx = -1; chcTempInx < 2; chcTempInx++)
    {
        if(((pData[0] == 0x00) && (chcTempInx == -1)) || ((pData[0] == 0x7F) && (chcTempInx == 1)))
        {
            continue;
        }

        pData[1] = pData[0] + chcTempInx;
        pData[2] = pData[1];

        // Apply trimming step
        ScalerSetBit(P6_A6_EMB_BGRES1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[1] & 0x7F);

        // Restart trimming
        ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, 0x00);
        ScalerSetBit(P6_A0_OSC_TRIM_CTRL0, ~_BIT7, _BIT7);

        // Polling trimming finished, time-cunsuming ~= 440us
        ScalerTimerPollingFlagProc(10, P6_A0_OSC_TRIM_CTRL0, _BIT6, _TRUE);

        // Get iosc cycle counter in current step
        PDATA_WORD(6) = (ScalerGetBit(P6_A5_EMB_BGRES, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) << 4) | ScalerGetByte(P6_A4_OSC_TRIM_CNT);

        // Record minimum step
        if(ABSDWORD(PDATA_WORD(6), PDATA_WORD(5)) < PDATA_WORD(7))
        {
            PDATA_WORD(7) = ABSDWORD(PDATA_WORD(6), PDATA_WORD(5));
            pData[3] = pData[2];
        }
    }

    // Apply the best trimming step
    ScalerSetBit(P6_A6_EMB_BGRES1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[3] & 0x7F);
    //-------Use manual mode go back recheck best step end , total time-consuming ~= 5.36ms ----------
}
