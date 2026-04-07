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
// ID Code      : ScalerMeasureCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_INPUT_TIMING_HWIDTH()                    (g_stInputTimingData.usHWidth)
#define GET_INPUT_TIMING_VHEIGHT()                   (g_stInputTimingData.usVHeight)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructTimingInfo g_stInputTimingData;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern bit ScalerMeasureTimingChange(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort enumSourceSearchPort);

