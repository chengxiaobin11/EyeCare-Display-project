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
// ID Code      : RL6851_Series_OsdWindowChessboard.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ScalerOSDLibInternalInclude.h"

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
void ScalerOsdWindowChessboard(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ucChessBoardColor1, BYTE ucChessBoardColor2);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set window 6 Special function
// Input Value  : bEnable            -> _ENABLE or _DISABLE
//                enumOsdWindowsType -> _OSD_WINDOW_8   or _OSD_WINDOW_9   or _OSD_WINDOW_4_1 or _OSD_WINDOW_4_2 or _OSD_WINDOW_4_3 or
//                                      _OSD_WINDOW_4_4 or _OSD_WINDOW_4_5 or _OSD_WINDOW_4_6 or _OSD_WINDOW_4_7 or _OSD_WINDOW_4_8
//                ChessBoardColor1   -> Color (0 ~ 63)
//                ChessBoardColor2   -> Color (0 ~ 63)
// Output Value :
//--------------------------------------------------
void ScalerOsdWindowChessboard(bit bEnable, EnumOsdWindowsType enumOsdWindowsType, BYTE ucChessBoardColor1, BYTE ucChessBoardColor2)
{
    WORD usTemp = 0;

    if((enumOsdWindowsType >= _OSD_WINDOW_4_1) && (enumOsdWindowsType <= _OSD_WINDOW_4_8))
    {
        // _OSD_WINDOW_4_1 ~ _OSD_WINDOW_4_8
        usTemp = 0x164 + (enumOsdWindowsType - _OSD_WINDOW_4_1) * 2;
    }
#if(_OSD_WINDOW_CHESSBORAD_WIN8_WIND9_SUPPORT == _ON)
    else if((enumOsdWindowsType == _OSD_WINDOW_8) || (enumOsdWindowsType == _OSD_WINDOW_9))
    {
        usTemp = 0x161 + (enumOsdWindowsType - _OSD_WINDOW_8) * 2;
    }
#endif
#if(_OSD_WINDOW_5_1_5_8_SUPPORT == _ON)
    else if((enumOsdWindowsType >= _OSD_WINDOW_5_1) && (enumOsdWindowsType <= _OSD_WINDOW_5_8))
    {
        // _OSD_WINDOW_5_1 ~ _OSD_WINDOW_5_8
        usTemp = 0x2A0 + (enumOsdWindowsType - _OSD_WINDOW_5_1) * 10;
    }
#endif

    ScalerOsdWriteAllByte((_OSD_WIN_CONTROL), usTemp, (BYTE)bEnable << 7, (ucChessBoardColor1 & 0x3F), (ucChessBoardColor2 & 0x3F));
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdWindowChessboard(_ENABLE, _OSD_WINDOW_4_1, 0, 8);
*/
