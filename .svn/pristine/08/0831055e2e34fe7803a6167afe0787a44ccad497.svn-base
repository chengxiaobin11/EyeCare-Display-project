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
// ID Code      : RL6449_Series_ColorDCCGetSceneChangeStatus.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6449_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Table Length
//--------------------------------------------------


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
bit ScalerColorDCCGetSceneChangeStatus(BYTE ucSceneChangeTHD);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Get Scene Change Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerColorDCCGetSceneChangeStatus(BYTE ucSceneChangeTHD)
{
    ScalerSetBit(P7_C7_DCC_CTRL_0, ~(_BIT1 | _BIT0), _PAGE0);
    ScalerSetByte(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_0D_PORT_PAGE0_SCG_DIFF);

    if(ScalerGetByte(P7_CA_DCC_DATA_PORT) > ucSceneChangeTHD)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}
