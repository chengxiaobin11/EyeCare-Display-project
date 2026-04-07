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
// ID Code      : OsdWindowSaturatedColorSelect.c
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
void ScalerOsdWindowSaturatedColorSelect(EnumOsdWindowsType enumOsdWindowsType, BYTE ucColorR, BYTE ucColorG, BYTE ucColorB);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window gradient saturated color
// Input Value  : enumOsdWindowsType -> _OSD_WINDOW_0, _OSD_WINDOW_5, _OSD_WINDOW_6, _OSD_WINDOW_7, _OSD_WINDOW_8, _OSD_WINDOW_9
//                bversedGradient    -> _ENABLE or _DISABLE
//                ucColorR           -> window RED saturated color (0 ~ 255)
//                ucColorG           -> window GRN saturated color (0 ~ 255)
//                ucColorB           -> window BLU saturated color (0 ~ 255)
// Output Value :
//--------------------------------------------------
void ScalerOsdWindowSaturatedColorSelect(EnumOsdWindowsType enumOsdWindowsType, BYTE ucColorR, BYTE ucColorG, BYTE ucColorB)
{
    WORD usTempWindowNumber = 0;

    usTempWindowNumber = 0x150 + (enumOsdWindowsType * 2);
    ScalerOsdWriteAllByte((_OSD_WIN_CONTROL), usTempWindowNumber, ucColorR, ucColorG, ucColorB);
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    SET_OSD_WINDOW_GRADIENT_ENABLE_R(_ENABLE);
    SET_OSD_WINDOW_GRADIENT_SATURATED_COLOR_MODE(_ENABLE);
    SET_OSD_WINDOW_GRADIENT_REVERSED_COLOR_MODE(_DISABLE);
    SET_OSD_WINDOW_GRADIENT_ENABLE(_ENABLE);
    SET_OSD_WINDOW_NUMBER(5);
    SET_OSD_WINDOW_COLOR(4);
    SET_OSD_WINDOW_ENABLE(_ENABLE);
    ScalerOsdDrawWindow(XSTART(100), YSTART(200), XEND(300), YEND(400));
    ScalerOsdWindowSaturatedColorSelect(_OSD_WINDOW_5, 242, 242, 242);
*/
