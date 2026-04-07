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
// ID Code      : RL6851_Series_ScalerODLibInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _OD_PIXEL_PER_COMP                                          4 // Number of pixels processed per compression
#define CEILING(x, y)                                               (((x) % (y)) ? ((((x) / (y)) + 1) * (y)) : (x))
#define CEILING_OF_INT_DIVISION(x, y)                               (((x) % (y)) ? (((x) / (y)) + 1) : ((x) / (y)))

#define GET_OD_BIT_RATE(x)                                          (((x) == _OD_PARAM_7_5_BPP) ? 75U :\
                                                                     (((x) == _OD_PARAM_6_0_BPP) ? 60U :\
                                                                     (((x) == _OD_PARAM_4_5_BPP) ? 45U : _OFF)))

#define GET_OD_USE_BIT()                                            (GET_OD_BIT_RATE(g_enumODParamIndex))
#define GET_OD_USE_PARAM()                                          (g_enumODParamIndex)
#define SET_OD_USE_PARAM(x)                                         (g_enumODParamIndex = (x))
#define CLR_OD_USE_PARAM()                                          (g_enumODParamIndex = _OD_PARAM_OFF)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _OD_PARAM_OFF,
    _OD_PARAM_4_5_BPP,
    _OD_PARAM_6_0_BPP,
    _OD_PARAM_7_5_BPP,
} EnumODParamIndex;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern EnumODParamIndex g_enumODParamIndex;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerODCompressionSetting(void);
