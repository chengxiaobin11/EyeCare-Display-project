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
// ID Code      : OsdWindowGrayLevel.c
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
void ScalerOsdWindowGrayLevel(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ucPixelStep, BYTE ucDecimalPart);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set precise gradient level
// Input Value  : bEnable            -> _ENABLE or _DISABLE
//                enumOsdWindowsType -> _OSD_WINDOW_0, _OSD_WINDOW_5, _OSD_WINDOW_6, _OSD_WINDOW_7, _OSD_WINDOW_8, _OSD_WINDOW_9
//                ucPixelStep        -> Pixel Step for toggle/incremental, can not be 0 (1 ~ 255)
//                ucDecimalPart      -> Decimal part for Pixel-step (0~7)
// Output Value :
//--------------------------------------------------
void ScalerOsdWindowGrayLevel(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ucPixelStep, BYTE ucDecimalPart)
{
    WORD usTempWindowNumber = 0;
    BYTE ucTemp = 0;

    usTempWindowNumber = 0x177 + (enumOsdWindowsType * 7);

    ucTemp = ScalerOsdFrameControlByteGet(usTempWindowNumber, _OSD_BYTE0);
    ucTemp = ((ucTemp & ~_BIT1) | ((BYTE)bEnable << 1));

    ScalerOsdFrameControlAllByte(usTempWindowNumber, _OSD_WITHOUT_DB, ucTemp, ucPixelStep, ucDecimalPart);
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    SET_OSD_WINDOW_GRADIENT_ENABLE_R(_ENABLE);
    SET_OSD_WINDOW_GRADIENT_ENABLE(_ENABLE);
    SET_OSD_WINDOW_NUMBER(0);
    SET_OSD_WINDOW_COLOR(4);
    SET_OSD_WINDOW_ENABLE(_ENABLE);
    ScalerOsdDrawWindow(XSTART(50), YSTART(450), XEND(1450), YEND(650));
    ScalerOsdWindowGrayLevel(_ENABLE, _OSD_WINDOW_0, 5, 4);
*/
