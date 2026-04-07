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
// ID Code      : OsdFontLibraryRotation.c
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
void ScalerOsdFontLibraryRotation(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : None
// Input Value  : None
// Output Value :
//--------------------------------------------------
void ScalerOsdFontLibraryRotation(void)
{
    BYTE ucIdx = 0;

    for(ucIdx = 100; ucIdx > 0; ucIdx--)
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);

        if(ScalerGetBit(P3A_41_FRAME_CTRL_41, _BIT3) == 0x00)
        {
            break;
        }
    }
}
