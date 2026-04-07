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
// ID Code      : ScalerColorPCMInputGammaLoadTable.c
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
void ScalerColorPCMInputGammaLoadTable(BYTE ucSelect);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust Input gamma
// Input Value  : 0-sRGB, 1-Adobe, 2-UserDefine, 3-SoftProof
// Output Value : None
//--------------------------------------------------
void ScalerColorPCMInputGammaLoadTable(BYTE ucSelect)
{
    EnumPCMType enumPCMMode = ucSelect;
    ScalerColorPCMInputGammaAdjust((BYTE *)ScalerColorPCMGetTableAddress(enumPCMMode), ScalerColorPCMGetTableBank());
}
