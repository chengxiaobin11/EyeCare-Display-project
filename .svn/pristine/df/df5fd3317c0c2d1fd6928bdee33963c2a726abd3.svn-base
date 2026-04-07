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
// ID Code      : OsdReferenceDelay.c
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
void ScalerOsdReferenceDelay(EnumOsdMapType enumOsdMapType, EnumOsdReferenceType enumOsdReferenceType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set osd delay reference to which osd
// Input Value  : enumOsdMapType       -> _OSD_A or _OSD_B
//                enumOsdReferenceType -> _OSD_FIRST_DELAY or _OSD_SECOND_DELAY
// Output Value :
//--------------------------------------------------
void ScalerOsdReferenceDelay(EnumOsdMapType enumOsdMapType, EnumOsdReferenceType enumOsdReferenceType)
{
    if(enumOsdMapType == _OSD_A)
    {
        ScalerSetBit(P3A_18_FRAME_CTRL_18, ~_BIT2, (enumOsdReferenceType << 2));
    }
    else
    {
        ScalerSetBit(P3A_18_FRAME_CTRL_18, ~_BIT1, (enumOsdReferenceType << 1));
    }
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
*/



