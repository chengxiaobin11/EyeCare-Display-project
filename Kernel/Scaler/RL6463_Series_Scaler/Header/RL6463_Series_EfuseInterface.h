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
// ID Code      : RL6463_Series_EfuseInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#ifndef __RL6463_SERIES_EFUSE_H__
#define __RL6463_SERIES_EFUSE_H__
//--------------------------------------------------
// Enumerations of Efuse Data State
//--------------------------------------------------
typedef enum
{
    _EFUSE_NONE,
    _EFUSE_LC_TANK_CURRENT,
    _EFUSE_M2PLL_N_F_CODE,
    _EFUSE_THERMAL_SENSOR,
    _EFUSE_LVDS_DRIV,
    _EFUSE_LC_TANK_FREQ_FOR_APLL,
    _EFUSE_CP_WAFER_INFO,
} EnumEfuseDataState;

#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerEfuseGetData(EnumEfuseDataState enumEfuseDataState, BYTE ucEfuseLength, BYTE *pucEfuseData);

