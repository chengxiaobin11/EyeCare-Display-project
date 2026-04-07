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
// ID Code      : RL6410_Series_ColorDCRLocalDimmingReadTHDResult.c
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
DWORD ScalerColorDCRLocalDimmingReadTHDResult(EnumDCRLDAdjOption enumDCRLDReadOption);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Read Local Dimming DCR Above THD1/2 Value and Number Result
// Input Value  : DCR Histogram Information Option
// Output Value : DCR Histogram Information
// Note         : When get _DCR_ABOVE_TH_VAL(8bit or 10bit), should get _DCR_ABOVE_TH_VAL_HIGH first
//              : then get _DCR_ABOVE_TH_VAL
//--------------------------------------------------
DWORD ScalerColorDCRLocalDimmingReadTHDResult(EnumDCRLDAdjOption enumDCRLDReadOption)
{
    DWORD ulResult = 0;

    if((GET_DCR_READY_STATUS() == _FALSE) || (ScalerGetDataPortBit(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_27_CTS_BRI_SET, _BIT0) == 0x00))
    {
        return 0;
    }

    switch(enumDCRLDReadOption)
    {
        case _DCR_LD_ABOVE_TH1_NUM:
            ulResult = g_stDCRStoreInfo.ulDCR_LD_ABOVE_TH1_NUM;
            break;

        case _DCR_LD_ABOVE_TH2_NUM:
            ulResult = g_stDCRStoreInfo.ulDCR_LD_ABOVE_TH2_NUM;
            break;

        default:
            break;
    }

    return ulResult;
}
