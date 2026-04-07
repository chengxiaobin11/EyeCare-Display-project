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
// ID Code      : ScalerCommonColorInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
typedef enum
{
    _COLOR_INFO_SYSTEM = 0x00,
#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
    _COLOR_INFO_BG_DETECT,
#endif
    _COLOR_INFO_NUM,
} EnumColorInfo;

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_SOURCE_BACKGROUND_DETECT_SUPPORT == _ON)
extern void ScalerColorSwitchColorInfoArray(EnumColorInfo enumColorInfo);
#endif

