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
// ID Code      : RL6851_Series_OsdBurstWriteDataPort.c
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
void ScalerOsdBurstWriteDataPort(BYTE *pucAddress, WORD usWriteLength, BYTE ucBankNum, BYTE ucTableType, bit bTableLocation);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Osd Burst Write to CM_92_OSD_DATA_PORT
// Input Value  : Burst Write Pointer, Length, Bank, Table Type, Location
// Output Value : None
//--------------------------------------------------
void ScalerOsdBurstWriteDataPort(BYTE *pucAddress, WORD usWriteLength, BYTE ucBankNum, BYTE ucTableType, bit bTableLocation)
{
    ScalerBurstWrite(pucAddress, usWriteLength, ucBankNum, P0_92_OSD_DATA_PORT, ucTableType, bTableLocation);
}

