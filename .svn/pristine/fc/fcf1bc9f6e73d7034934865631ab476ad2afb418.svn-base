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
// ID Code      : OsdSramDataValue2Byte.c
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
void ScalerOsdSramDataValue2Byte(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucValue1, BYTE ucValue2, EnumOsdWriteType enumOsdWriteType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SRAM address value and which byte
// Input Value  : ucRow. ucCol.    -> Just that !!
//                enumOsdWriteType -> _OSD_BYTE0 or _OSD_BYTE1 or _OSD_BYTE2
// Output Value :
//--------------------------------------------------
void ScalerOsdSramDataValue2Byte(BYTE ucRow, BYTE ucCol, BYTE ucLength, BYTE ucValue1, BYTE ucValue2, EnumOsdWriteType enumOsdWriteType)
{
    BYTE ucTemp = 0;

    ScalerOsdSramAddressCount(ucRow, ucCol, enumOsdWriteType);

    for(ucTemp = 0; ucTemp < ucLength; ucTemp++)
    {
        ScalerOsdDataPort(ucValue1);
        ScalerOsdDataPort(ucValue2);
    }
}


