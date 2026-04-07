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
// ID Code      : ScalerColorHLWBorderEnable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerColorLibInternalInclude.h"

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
void ScalerColorHLWBorderEnable(bit bTopBorderEn, bit bBottomBorderEn, bit bLeftBorderEn, bit bRightBorderEn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust HLW Border Enable
// Input Value  : bTopBorderEn, bBottomBorderEn, bLeftBorderEn, bRightBorderEn, enumDBApply
// Output Value : none
//--------------------------------------------------
void ScalerColorHLWBorderEnable(bit bTopBorderEn, bit bBottomBorderEn, bit bLeftBorderEn, bit bRightBorderEn)
{
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), ((BYTE)(~bLeftBorderEn) << 7) | ((BYTE)(~bRightBorderEn) << 6) | ((BYTE)(~bTopBorderEn) << 5) | ((BYTE)(~bBottomBorderEn) << 4));

    ScalerGlobalDDomainDBApply(_DB_APPLY_NO_POLLING);
}

