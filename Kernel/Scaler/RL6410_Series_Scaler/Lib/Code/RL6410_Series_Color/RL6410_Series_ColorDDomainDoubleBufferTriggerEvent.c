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
// ID Code      : RL6410_Series_ColorDDomainDoubleBufferTriggerEvent.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6410_Series_ColorLibInternalInclude.h"

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
void ScalerColorDDomainDBTriggerEvent(EnumDBTriggerEvent enumDBTriggerEvent);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Set D domain double buffer trigger event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDDomainDBTriggerEvent(EnumDBTriggerEvent enumDBTriggerEvent)
{
    if(ScalerGlobalGetIDCode() >= _RL6410_VER_E_ID_CODE)
    {
        if(enumDBTriggerEvent == _DB_VS_TRIGGER)
        {
            // Set D-domain DB trigger source: DVS
            ScalerSetBit(P31_B0_D_DB_CTRL0, ~_BIT5, 0x00);
        }
        else
        {
            // Set D-domain DB trigger source: DENA STOP
            ScalerSetBit(P31_B0_D_DB_CTRL0, ~_BIT5, _BIT5);
        }
    }
}
