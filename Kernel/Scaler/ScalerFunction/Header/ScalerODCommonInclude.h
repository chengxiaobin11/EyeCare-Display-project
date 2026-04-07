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
// ID Code      : ScalerODCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _OD_SUPERPIXEL1X2_75BIT_BIT_NUM     75 // Compression rate: 7.5 bit/pixel
#define _OD_SUPERPIXEL1X4_60BIT_BIT_NUM     60 // Compression rate: 6.0 bit/pixel

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _OD_CMP_PARAM_MODE_DEFAULT,
    _OD_CMP_PARAM_MODE_6_0_BIT_IMPROVE,
} EnumOdCmpParamMode;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern EnumOdCmpParamMode ScalerODGetCmpParamMode(void);
