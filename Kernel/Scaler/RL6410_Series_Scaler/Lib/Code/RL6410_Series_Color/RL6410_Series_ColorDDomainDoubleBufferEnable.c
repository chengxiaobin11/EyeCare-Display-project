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
// ID Code      : RL6410_Series_ColorDDomainDoubleBufferEnable.c
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
void ScalerColorDDomainDBEnable(bit bEn);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Enable/Disable double buffer
// Input Value  : bEn --> _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerColorDDomainDBEnable(bit bEn)
{
    if(ScalerGlobalGetIDCode() >= _RL6410_VER_E_ID_CODE)
    {
        if(bEn == _ENABLE)
        {
            // D Domain Double Buffer Enable
            ScalerSetBit(P31_B0_D_DB_CTRL0, ~(_BIT7 | _BIT6), _BIT7);
        }
        else
        {
            // D Domain Double Buffer Disable
            ScalerSetBit(P31_B0_D_DB_CTRL0, ~(_BIT7 | _BIT6), 0x00);
        }
    }
}
