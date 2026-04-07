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
// ID Code      : OsdWindowGradientLevel.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerOSDLibInternalInclude.h"

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
void ScalerOsdWindowGradientLevel(EnumOsdWindowsType enumOsdWindowsType, BYTE ucLevelR, BYTE ucLevelG, BYTE ucLevelB);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window extension gradient level for R/G/B channel
// Input Value  : enumOsdWindowsType -> _OSD_WINDOW_0, _OSD_WINDOW_5, _OSD_WINDOW_6, _OSD_WINDOW_7, _OSD_WINDOW_8, _OSD_WINDOW_9
//                ucLevelR           -> window RED extension gradient level (0 ~ 255)
//                ucLevelG           -> window GRN extension gradient level (0 ~ 255)
//                ucLevelB           -> window BLU extension gradient level (0 ~ 255)
// Output Value :
//--------------------------------------------------
void ScalerOsdWindowGradientLevel(EnumOsdWindowsType enumOsdWindowsType, BYTE ucLevelR, BYTE ucLevelG, BYTE ucLevelB)
{
    WORD usTempWindowNumber = 0;

    usTempWindowNumber = 0x174 + (enumOsdWindowsType * 7);
    ScalerOsdWriteAllByte((_OSD_WIN_CONTROL), usTempWindowNumber, ucLevelR, ucLevelG, ucLevelB);
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    SET_OSD_WINDOW_GRADIENT_ENABLE_R(_ENABLE);
    SET_OSD_WINDOW_GRADIENT_ENABLE(_ENABLE);
    SET_OSD_WINDOW_GRADIENT_LEVEL_EXTENSION(_OSD_WINDOW_GRADIENT_LEVEL_EXTENSION_256);
    SET_OSD_WINDOW_NUMBER(5);
    SET_OSD_WINDOW_COLOR(4);
    SET_OSD_WINDOW_ENABLE(_ENABLE);
    ScalerOsdDrawWindow(XSTART(100), YSTART(200), XEND(300), YEND(400));
    ScalerOsdWindowGradientLevel(_OSD_WINDOW_0, 100, 100, 100);
*/

