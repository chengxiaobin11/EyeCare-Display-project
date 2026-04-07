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
// ID Code      : ScalerCommonColor.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_COLOR__

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
StructColorInfo g_pstColorInfo[_COLOR_INFO_NUM];
StructColorInfo *g_pstColorInfoPointer = &g_pstColorInfo[0];
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
void ScalerColorSwitchColorInfoArray(EnumColorInfo enumColorInfo);
void ScalerColorSwitchColorInfoArray_EXINT0(EnumColorInfo enumColorInfo);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************


#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Change ColorInfoPointer
// Input Value  : EnumColorInfo _COLOR_INFO_SYSTEM or COLOR_INFO_BG_DETECT
// Output Value : None
//--------------------------------------------------
void ScalerColorSwitchColorInfoArray(EnumColorInfo enumColorInfo)
{
    g_pstColorInfoPointer = &g_pstColorInfo[enumColorInfo % _COLOR_INFO_NUM];
}

//--------------------------------------------------
// Description  : Change ColorInfoPointer
// Input Value  : EnumColorInfo _COLOR_INFO_SYSTEM or COLOR_INFO_BG_DETECT
// Output Value : None
//--------------------------------------------------
void ScalerColorSwitchColorInfoArray_EXINT0(EnumColorInfo enumColorInfo) using 1
{
    g_pstColorInfoPointer = &g_pstColorInfo[enumColorInfo];
}

#endif

