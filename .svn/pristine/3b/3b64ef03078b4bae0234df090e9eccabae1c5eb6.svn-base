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
// ID Code      : ScalerColorScaling.c
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
bit ScalerColorScalingByPassTableSel(void);
bit ScalerColorScalingGetScalingUpBypassStatus(void);
bit ScalerColorScalingGetScalingDownBypassStatus(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get Scaling By pass
// Input Value  : none
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerColorScalingByPassTableSel(void)
{
    if((ScalerColorScalingGetScalingUpBypassStatus() == _TRUE) && (ScalerColorScalingGetScalingDownBypassStatus() == _TRUE))
    {
        return _TRUE;
    }
    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Scaling By pass
// Input Value  : enumSelRegion
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerColorScalingGetScalingUpBypassStatus(void)
{
    ScalerGetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_03_VER_SCALE_FACTOR_H, 3, &pData[0], _AUTOINC);
    ScalerGetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_00_HOR_SCALE_FACTOR_H, 3, &pData[3], _AUTOINC);

    if(((pData[0] & 0x0F) == 0x0F) && (pData[1] == 0xFF) && (pData[2] == 0xFF) &&
       ((pData[3] & 0x0F) == 0x0F) && (pData[4] == 0xFF) && (pData[5] == 0xFF))
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Get Scale Down Bypass Status
// Input Value  : enumSelRegion
// Output Value : TRUE, FALSE
//--------------------------------------------------
bit ScalerColorScalingGetScalingDownBypassStatus(void)
{
    ScalerGetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_05_H_SD_FACTOR_H_M1, 3, &pData[0], _AUTOINC);
    ScalerGetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_01_V_SD_FACTOR_H_M1, 3, &pData[3], _AUTOINC);

    if((pData[0] != 0x10) || (pData[1] != 0x00) || (pData[2] != 0x00) ||
       (pData[3] != 0x02) || (pData[4] != 0x00) || (pData[5] != 0x00))
    {
        return _FALSE;
    }

#if(_SCALING_DOWN_VSD_TYPE == _SD_VSD_GEN_0)
    ScalerGetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_42_V_SD_FACTOR_L1_M1, 1, &pData[6], _AUTOINC);

    if((pData[6] & 0xE0) != 0x00)
    {
        return _FALSE;
    }
#endif

    return _TRUE;
}