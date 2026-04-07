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
// ID Code      : RL6432_Series_ColorDCRGetMaxRGB.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6432_Series_ColorLibInternalInclude.h"

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
WORD ScalerColorDCRGetMaxRGB(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get DCR Max RGB
// Input Value  : None
// Output Value : Max RGB
//--------------------------------------------------
WORD ScalerColorDCRGetMaxRGB(void)
{
    WORD usResult = 0;

    if(GET_DCR_READY_STATUS() == _FALSE)
    {
        return 0;
    }

    ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_14_DCR_HIGH_LV_VAL_R_1 << 2) | _BIT1 | _BIT0);
    ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
    ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_2C_DCR_HIGH_LV_VAL_R_0 << 2) | _BIT1 | _BIT0);
    ScalerRead(P7_D9_DCR_DATA_PORT, 1, &pData[1], _NON_AUTOINC);
    usResult = PDATA_WORD(0) >> 6;

    ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_1A_DCR_HIGH_LV_VAL_G_1 << 2) | _BIT1 | _BIT0);
    ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
    ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_2E_DCR_HIGH_LV_VAL_G_0 << 2) | _BIT1 | _BIT0);
    ScalerRead(P7_D9_DCR_DATA_PORT, 1, &pData[1], _NON_AUTOINC);
    if(usResult < (PDATA_WORD(0) >> 6))
    {
        usResult = PDATA_WORD(0) >> 6;
    }

    ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_20_DCR_HIGH_LV_VAL_B_1 << 2) | _BIT1 | _BIT0);
    ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
    ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, (_P7_D9_PT_30_DCR_HIGH_LV_VAL_B_0 << 2) | _BIT1 | _BIT0);
    ScalerRead(P7_D9_DCR_DATA_PORT, 1, &pData[1], _NON_AUTOINC);
    if(usResult < (PDATA_WORD(0) >> 6))
    {
        usResult = PDATA_WORD(0) >> 6;
    }
    return usResult;
}
