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
// ID Code      : RL6851_Series_ColorUltraVividAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6851_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Table Length
//--------------------------------------------------
#define _ULTRAVIVID_TABLE_SIZE                  91


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
void ScalerColorUltraVividAdjust(BYTE code *pucUltraVividSetting, BYTE ucBankNum);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : UltraVivid Adjust
// Input Value  : UltraVivid Table and ucBankNum
// Output Value : None
//--------------------------------------------------
void ScalerColorUltraVividAdjust(BYTE code *pucUltraVividSetting, BYTE ucBankNum)
{
    if(GET_V_SCALE_UP() == _TRUE)
    {
        ScalerGetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_03_VER_SCALE_FACTOR_H, 2, pData, _AUTOINC);
        pData[0] = ((pData[0] << 4) | (pData[1] >> 4));

        if(pData[0] < 85)  // IVHeight/DVHeight <= 1/4
        {
            ScalerBurstWrite(pucUltraVividSetting, _ULTRAVIVID_TABLE_SIZE, ucBankNum, P11_B9_SCALER_LSR_HLW, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }
        else if(pData[0] < 170)  // IVHeight/DVHeight < 2/3
        {
            ScalerBurstWrite(pucUltraVividSetting + _ULTRAVIVID_TABLE_SIZE, _ULTRAVIVID_TABLE_SIZE, ucBankNum, P11_B9_SCALER_LSR_HLW, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }
        else  // IVHeight/DVHeight <= 1
        {
            ScalerBurstWrite(pucUltraVividSetting + _ULTRAVIVID_TABLE_SIZE * 2, _ULTRAVIVID_TABLE_SIZE, ucBankNum, P11_B9_SCALER_LSR_HLW, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
        }
    }
    else if(GET_V_SCALE_DOWN() == _TRUE)
    {
        ScalerBurstWrite(pucUltraVividSetting + _ULTRAVIVID_TABLE_SIZE * 3, _ULTRAVIVID_TABLE_SIZE, ucBankNum, P11_B9_SCALER_LSR_HLW, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    }
    else // by pass
    {
        ScalerBurstWrite(pucUltraVividSetting + _ULTRAVIVID_TABLE_SIZE * 4, _ULTRAVIVID_TABLE_SIZE, ucBankNum, P11_B9_SCALER_LSR_HLW, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    }

    // Wait for Event
    ScalerGlobalIDDomainDBApply(_DB_APPLY_NONE);
}
