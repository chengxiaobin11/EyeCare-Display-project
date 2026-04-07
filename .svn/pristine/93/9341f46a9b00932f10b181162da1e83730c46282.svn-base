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
// ID Code      : RL6492_Series_OsdFontRotateCtrl.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6492_Series_OSDLibInternalInclude.h"

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
void ScalerOsdFontRotateCtrl(EnumOsdRotateType enumRotType, BYTE ucFontDownloadRotEn, BYTE ucDispRotEn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Osd Font Rotation
// Input Value  : enumRotType
// Input Value  : ucFontDownloadRotEn
// Input Value  : ucDispRotEn
// Output Value :
//--------------------------------------------------
void ScalerOsdFontRotateCtrl(EnumOsdRotateType enumRotType, BYTE ucFontDownloadRotEn, BYTE ucDispRotEn)
{
    switch(enumRotType)
    {
        default:
        case _OSD_ROTATE_DEGREE_0:
            ScalerSetBit(P3A_0B_FRAME_CTRL_0B, ~(_BIT7 | _BIT6), 0x00);
            break;

        case _OSD_ROTATE_DEGREE_90:
            ScalerSetBit(P3A_0B_FRAME_CTRL_0B, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            break;

        case _OSD_ROTATE_DEGREE_270:
            ScalerSetBit(P3A_0B_FRAME_CTRL_0B, ~(_BIT7 | _BIT6), _BIT7);
            break;

        case _OSD_ROTATE_DEGREE_180:
            ScalerSetBit(P3A_0B_FRAME_CTRL_0B, ~(_BIT7 | _BIT6), _BIT6);
            break;
    }

    if(((bit)ucFontDownloadRotEn) == _ENABLE)
    {
        ScalerSetBit(P3A_0B_FRAME_CTRL_0B, ~_BIT2, _BIT2);
    }
    else
    {
        ScalerSetBit(P3A_0B_FRAME_CTRL_0B, ~_BIT2, 0x00);
    }

    if((enumRotType == _OSD_ROTATE_DEGREE_0) || (enumRotType == _OSD_ROTATE_DEGREE_180))
    {
        ScalerSetBit(P3A_0B_FRAME_CTRL_0B, ~_BIT0, 0x00);
    }
    else
    {
        ScalerSetBit(P3A_0B_FRAME_CTRL_0B, ~_BIT0, (bit)ucDispRotEn);
    }
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdFontRotateCtrl(_OSD_ROTATE_DEGREE_90, _ENABLE, _OSD_ROTATE_ROTATION);
*/


