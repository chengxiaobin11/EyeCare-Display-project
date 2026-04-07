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
// ID Code      : RL6449_Series_ColorDCRLocalDimmingReadResult.c
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
void ScalerColorDCRLocalDimmingReadResult(BYTE *pucResult);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Read DCR Local Dimming Information Result
// Input Value  : Pointor of Local Dimming Information Result
// Output Value : none
//--------------------------------------------------
void ScalerColorDCRLocalDimmingReadResult(BYTE *pucResult)
{
    if(ScalerGetDataPortBit(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_27_CTS_BRI_SET, _BIT1) == 0x00)
    {
        memcpy(pucResult, g_stDCRStoreInfo.pucWinMaxRGB, 8);
    }
    else
    {
        memcpy(pucResult, g_stDCRStoreInfo.pucWinMaxRGB, 16);
    }
}
