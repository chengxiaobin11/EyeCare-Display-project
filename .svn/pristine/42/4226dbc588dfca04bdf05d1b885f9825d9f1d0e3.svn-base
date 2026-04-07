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
// ID Code      : ScalerColorDCRDataRefreshControl.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerColorLibInternalInclude.h"

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
void ScalerColorDCRDataRefreshControl(bit bEnable);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Control DCR Data Reflash
// Input Value  : bMode ->
//                   _ENABLE : Enable reflash DCR Measure result
//                   _DISABLE : Disable reflash DCR Measure result
// Output Value : None
//--------------------------------------------------
void ScalerColorDCRDataRefreshControl(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, _BIT0);
    }
    else
    {
        ScalerSetByte(P7_D8_DCR_ADDRESS_PORT, _BIT1 | _BIT0);
    }
}
