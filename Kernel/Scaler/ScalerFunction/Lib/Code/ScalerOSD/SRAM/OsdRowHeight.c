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
// ID Code      : OsdRowHeight.c
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
void ScalerOsdRowHeight(BYTE ucRow, BYTE ucHeight, BYTE ucLength);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : ucRow -> ROW_MAPA(x), ROW_MAPB(x)
//                ucHeight -> 1 ~ 64
//                ucLength -> number of row to be changed
// Output Value :
//--------------------------------------------------
void ScalerOsdRowHeight(BYTE ucRow, BYTE ucHeight, BYTE ucLength)
{
    BYTE ucIdx = 0;

    if(ucHeight > 64)
    {
        ucHeight = 64;
    }

    ucHeight--;

    if(ScalerGetBit(P3A_18_FRAME_CTRL_18, _BIT3) == _BIT3) // OSD 2 font function
    {
        if(ucRow >= _OSD_MAP_B_ROW_OFFSET)
        {
            ScalerOsdSramAddressSet((ScalerGetByte(P3A_1A_FRAME_CTRL_1A) + (ucRow - _OSD_MAP_B_ROW_OFFSET)), _OSD_BYTE1);
        }
        else
        {
            ScalerOsdSramAddressSet((ScalerGetByte(P3A_19_FRAME_CTRL_19) + ucRow), _OSD_BYTE1);
        }
    }
    else
    {
        ScalerOsdSramAddressSet((0 + ucRow), _OSD_BYTE1);
    }

    for(ucIdx = 0; ucIdx < ucLength; ucIdx++)
    {
        ScalerOsdDataPort(ucHeight);
    }
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdRowHeight(ROW_MAPA(0), HEIGHT(31), LENGTH(3));
*/

