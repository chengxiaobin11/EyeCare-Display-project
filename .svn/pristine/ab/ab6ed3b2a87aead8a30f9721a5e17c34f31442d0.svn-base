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
// ID Code      : RL6851_Series_OsdWriteProtection.c
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
void ScalerOsdWriteProtection(bit bEnable, EnumOsdWriteType enumOsdWriteType, BYTE ucBitSelect);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set write protection for SRAM when OSD is on
// Input Value  : bEnable          -> _ENABLE or _DISABLE
//                enumOsdWriteType -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2
//                ucBitSelect      -> (_BIT7 | _BIT6 | _BIT5 |_BIT4 | _BIT3 |_BIT2 | _BIT1 | _BIT0)
// Output Value :
//--------------------------------------------------
void ScalerOsdWriteProtection(bit bEnable, EnumOsdWriteType enumOsdWriteType, BYTE ucBitSelect)
{
    BYTE ucTemp = 0;

    // Set OSD Circuit Enable for Write-Protection Function effective in OSD enable.
    if((bEnable == _ENABLE) && (ScalerGetBit(P3A_02_FRAME_CTRL_02, _BIT0) == 0x00))
    {
        if(ScalerOsdGetOsdEnable() == _TRUE)
        {
            ScalerOsdDisableOsd();
        }

        ScalerOsdCircuitActivated(_ENABLE);
    }

    ScalerTimerWaitForEvent(_EVENT_DVS);

    if(enumOsdWriteType == _OSD_BYTE1)
    {
        ucTemp |= _BIT1;
    }
    else if(enumOsdWriteType == _OSD_BYTE2)
    {
        ucTemp |= _BIT2;
    }

    ScalerSetBit(P3A_33_FRAME_CTRL_33, ~(_BIT2 | _BIT1 | _BIT0), (ucTemp | (BYTE)bEnable));
    ScalerSetByte(P3A_34_FRAME_CTRL_34, ucBitSelect);
}
