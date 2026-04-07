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
// ID Code      : RL6449_Series_OsdScaleUpOnOff.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_OSDLibInternalInclude.h"

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
void ScalerOsdScaleUpOnOff(bit bOnOff);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OSD Font Scale Up (only valid when even-odd mode is applied)
// Input Value  : bOnOff
// Output Value :
//--------------------------------------------------
void ScalerOsdScaleUpOnOff(bit bOnOff)
{
    BYTE ucOSDOffsetCorrect = _DISABLE;

    if(((bit)ScalerGetBit(P3A_C0_OSD_SU_CRTL, _BIT7) != bOnOff) && (ScalerOsdPositionCorrectSupport() == _ON))
    {
        ucOSDOffsetCorrect = _ENABLE;
    }

    ScalerSetBit(P3A_C0_OSD_SU_CRTL, ~(_BIT7), ((BYTE)bOnOff << 7));

    if(ucOSDOffsetCorrect == _ENABLE)
    {
        ScalerOsdPositionOffsetCorrection();
    }

    if(ScalerGlobalGetIDCode() == _RL6449_VER_A_ID_CODE)
    {
        // Read value effective not immediately
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }
}

