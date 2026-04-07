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
// ID Code      : OsdWindowSpecialColorMask.c
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
void ScalerOsdWindowSpecialColorMask(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, EnumOsdSpecialColorMaskOperation enumOsdSpecialColorMaskOperation);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window special color mask
// Input Value  : bEnable            -> _ENABLE or _DISABLE
//                enumOsdWindowsType -> _OSD_WINDOW_0, _OSD_WINDOW_5, _OSD_WINDOW_6, _OSD_WINDOW_7, _OSD_WINDOW_8, _OSD_WINDOW_9
//                EnumOsdSpecialColorMaskOperation  -> _OSD_SPECIAL_COLOR_MASK_AND_OPERATION or _OSD_SPECIAL_COLOR_MASK_OR_OPERATION
// Output Value :
//--------------------------------------------------
void ScalerOsdWindowSpecialColorMask(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, EnumOsdSpecialColorMaskOperation enumOsdSpecialColorMaskOperation)
{
    BYTE ucTemp = 0;
    WORD usTempWindowNumber = 0;

    usTempWindowNumber = 0x177 + (enumOsdWindowsType * 7);
    ucTemp = ScalerOsdFrameControlByteGet(usTempWindowNumber, _OSD_BYTE0);
    ucTemp = ((ucTemp & ~(_BIT3 | _BIT2)) | (((BYTE)enumOsdSpecialColorMaskOperation << 3) | ((BYTE)bEnable << 2)));

    ScalerOsdFrameControlByte(usTempWindowNumber, _OSD_BYTE0, ucTemp);
}



/*
//--------------------------------------------------
// example
//--------------------------------------------------
    SET_OSD_WINDOW_NUMBER(0);
    SET_OSD_WINDOW_ENABLE(_ENABLE);
    SET_OSD_WINDOW_COLOR(4);
    ScalerOsdDrawWindow(XSTART(100), YSTART(200), XEND(300), YEND(400));
    ScalerOsdWindowSpecialColorMask(_ENABLE, _OSD_WINDOW_0, _OSD_SPECIAL_COLOR_MASK_AND_OPERATION);
*/
