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
// ID Code      : RL6463_Series_ColorDCRReadResult.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6463_Series_ColorLibInternalInclude.h"

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
DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumDCRReadOption);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Read DCR Histogram Result
// Input Value  : DCR Histogram Information Option
// Output Value : DCR Histogram Information
// Note         : When get _DCR_ABOVE_TH_VAL(8bit or 10bit), should get _DCR_ABOVE_TH_VAL_HIGH / _DCR_ABOVE_TH_VAL_10BIT_HIGH first
//              : then get _DCR_ABOVE_TH_VAL / _DCR_ABOVE_TH_VAL_10BIT
//--------------------------------------------------
DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumDCRReadOption)
{
    DWORD ulResult = 0;

    if(GET_DCR_READY_STATUS() == _FALSE)
    {
        return 0;
    }

    switch(enumDCRReadOption)
    {
        case _DCR_ABOVE_TH1_NUM:
            ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_02_DCR_ABOVE_TH1_NUM_2 << 2) | _BIT1 | _BIT0);
            ScalerRead(P7_D9_DCR_DATA_PORT, 3, pData, _NON_AUTOINC);

            ulResult = TO_DWORD(0, pData[0], pData[1], pData[2]);
            break;

        case _DCR_ABOVE_TH1_VAL:
            ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_05_DCR_ABOVE_TH1_VAL_4 << 2) | _BIT1 | _BIT0);
            ScalerRead(P7_D9_DCR_DATA_PORT, 4, pData, _NON_AUTOINC);

            ulResult = TO_DWORD(pData[0], pData[1], pData[2], pData[3]);
            break;

        case _DCR_ABOVE_TH1_VAL_HIGH:
            ulResult = 0;
            break;

        case _DCR_HIGH_LV_VAL_R:
            ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_14_DCR_HIGH_LV_VAL_R_1 << 2) | _BIT1 | _BIT0);

            ulResult = ScalerGetByte(P7_D9_DCR_DATA_PORT);
            break;

        case _DCR_LOW_LV_VAL_R:
            ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_15_DCR_LOW_LV_VAL_R_1 << 2) | _BIT1 | _BIT0);

            ulResult = ScalerGetByte(P7_D9_DCR_DATA_PORT);
            break;

        case _DCR_HIGH_LV_VAL_G:
            ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_1A_DCR_HIGH_LV_VAL_G_1 << 2) | _BIT1 | _BIT0);

            ulResult = ScalerGetByte(P7_D9_DCR_DATA_PORT);
            break;

        case _DCR_LOW_LV_VAL_G:
            ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_1B_DCR_LOW_LV_VAL_G_1 << 2) | _BIT1 | _BIT0);

            ulResult = ScalerGetByte(P7_D9_DCR_DATA_PORT);
            break;

        case _DCR_HIGH_LV_VAL_B:
            ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_20_DCR_HIGH_LV_VAL_B_1 << 2) | _BIT1 | _BIT0);

            ulResult = ScalerGetByte(P7_D9_DCR_DATA_PORT);
            break;

        case _DCR_LOW_LV_VAL_B:
            ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_21_DCR_LOW_LV_VAL_B_1 << 2) | _BIT1 | _BIT0);

            ulResult = ScalerGetByte(P7_D9_DCR_DATA_PORT);
            break;

        default:
            break;
    }

    return ulResult;
}
