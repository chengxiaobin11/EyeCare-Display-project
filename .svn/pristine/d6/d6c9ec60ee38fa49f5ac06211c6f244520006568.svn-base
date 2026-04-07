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
// ID Code      : OsdRotationWindowSize.c
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
void ScalerOsdRotationWindowSize(EnumOsdMapType enumOsdMapType, WORD usLength, WORD usWidth);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window rotate reference size
// Input Value  : enumOsdMapType -> _OSD_A or _OSD_B
//                usLength       -> Horizontal max size
//                Width          -> Vertical max size
// Output Value :
//--------------------------------------------------
void ScalerOsdRotationWindowSize(EnumOsdMapType enumOsdMapType, WORD usLength, WORD usWidth)
{
    if(enumOsdMapType == _OSD_A)
    {
        // First OSD Width
        ScalerSetBit(P3A_38_FRAME_CTRL_38, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((usWidth & 0x0F00) >> 8));
        ScalerSetByte(P3A_3A_FRAME_CTRL_3A, (usWidth & 0xFF));

        // First OSD Length
        ScalerSetBit(P3A_38_FRAME_CTRL_38, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), ((usLength & 0x0F00) >> 4));
        ScalerSetByte(P3A_39_FRAME_CTRL_39, (usLength & 0xFF));
    }
    else
    {
        // Second OSD Width
        ScalerSetBit(P3A_3B_FRAME_CTRL_3B, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((usWidth & 0x0F00) >> 8));
        ScalerSetByte(P3A_3D_FRAME_CTRL_3D, (usWidth & 0xFF));

        // Second OSD Length
        ScalerSetBit(P3A_3B_FRAME_CTRL_3B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), ((usLength & 0x0F00) >> 4));
        ScalerSetByte(P3A_3C_FRAME_CTRL_3C, (usLength & 0xFF));
    }
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdRotationWindowSize(_OSD_A, XEND(400), YEND(500));
*/



