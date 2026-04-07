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
// ID Code      : RL6851_Series_ScalerOSDLibInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerOSDLibInterface.h"

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _OSD_OFFSET_DRAW_WINDOW_H                               10
#define _OSD_OFFSET_DRAW_WINDOW_V                               0

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
//--------------------------------------------------
// Command
//--------------------------------------------------

//--------------------------------------------------
// Windows
//--------------------------------------------------

//--------------------------------------------------
// SRAM
//--------------------------------------------------
extern void ScalerOsdSramAddressSet(WORD usSramAddress, EnumOsdWriteType enumOsdWriteType);
extern void ScalerOsdFontLibraryRotation(void);

//--------------------------------------------------
// Function
//--------------------------------------------------
extern void ScalerOsdVerticalStartSelect(EnumOsdVsyncSelectType enumOsdVsyncSelectType);
extern void ScalerOsdCircuitActivated(bit bEnable);
extern void ScalerOsdFontWindowVericalAlignemnt(bit bOnOff);
extern bit ScalerOsdPositionCorrectSupport(void);

