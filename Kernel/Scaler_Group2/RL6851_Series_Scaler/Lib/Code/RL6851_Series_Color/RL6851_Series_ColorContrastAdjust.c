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
// ID Code      : RL6851_Series_ColorContrastAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ColorLibInternalInclude.h"

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
void ScalerColorContrastAdjust(EnumBriConCoefType enumBriConCoefType, WORD *pusData);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust Contrast
// Input Value  : EnumBriConCoefType, Coefficient
//                12 bit input, old 8 bit contrast input value must left shift 4 bit
//                0 (00h) ~ 1(800h) ~  2(FFFh)
// Output Value : void
//--------------------------------------------------
void ScalerColorContrastAdjust(EnumBriConCoefType enumBriConCoefType, WORD *pusData)
{
    switch(enumBriConCoefType)
    {
        case _CONTRAST_COEF_A:
            ScalerSetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_03_CTS_RED_COE_SETA_H, pusData[0] & 0x00FF);
            ScalerSetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_04_CTS_GRN_COE_SETA_H, pusData[1] & 0x00FF);
            ScalerSetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_05_CTS_BLU_COE_SETA_H, pusData[2] & 0x00FF);
            break;

        case _CONTRAST_COEF_B:
            ScalerSetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_09_CTS_RED_COE_SETB_H, pusData[0] & 0x00FF);
            ScalerSetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_0A_CTS_GRN_COE_SETB_H, pusData[1] & 0x00FF);
            ScalerSetDataPortByte(P0_64_CTS_BRI_PORT_ADD, _P0_65_PT_0B_CTS_BLU_COE_SETB_H, pusData[2] & 0x00FF);
            break;

        default:
            break;
    }
}
