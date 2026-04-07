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
// ID Code      : RL6492_Series_EfuseInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#ifndef __RL6492_SERIES_EFUSE_H__
#define __RL6492_SERIES_EFUSE_H__
//--------------------------------------------------
// Enumerations of Efuse Data State
//--------------------------------------------------

typedef enum
{
    _EFUSE_NONE,
    _EFUSE_LVDS_DRIV,
    _EFUSE_TYPE_C_1M_OHM_RESISTOR,
    _EFUSE_CP_WAFER_INFO,
    _EFUSE_CC_RESISTANCE,
    _EFUSE_CC_ATTACH_VOLTAGE,
    _EFUSE_CC_BMC_TX_RX_VOLTAGE,
    _EFUSE_ADC_SLOP_OFFSET,
    _EFUSE_VBUS_COMPARATOR,
    _EFUSE_CHECK_BIT,
} EnumEfuseDataState;

#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerEfuseGetData(EnumEfuseDataState enumEfuseDataState, BYTE ucEfuseLength, BYTE *pucEfuseData);

