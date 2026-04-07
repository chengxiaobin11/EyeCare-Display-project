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
// ID Code      : RL6492_Series_FormatConversionInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _FC_SOURCE_ADC = _BIT1,
    _FC_SOURCE_D0 = (_BIT1 | _BIT0),
    _FC_SOURCE_D1 = _BIT2,
    _FC_SOURCE_D2 = (_BIT2 | _BIT0),
    _FC_SOURCE_NONE = 0xFF,
} EnumFormatConversionSourceType;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerFmtCnvInitialSetting(EnumSourceSearchPort enumSourceSearchPort);
extern EnumFormatConversionSourceType ScalerFmtCnvGetSourceType(void);
