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
// ID Code      : ScalerColorLibInternalInclude.h
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerFunctionCommonInclude.h"
#include "ScalerColorLibInterface.h"
#include "ScalerCommonRegLibInclude.h"
#include "ScalerCommonNVRamLibInclude.h"
#if(_SCALER_TYPE == _RL6369_SERIES)
#include "RL6369_Series_ColorLibInclude.h"
#elif(_SCALER_TYPE == _RL6410_SERIES)
#include "RL6410_Series_ColorLibInclude.h"
#elif(_SCALER_TYPE == _RL6432_SERIES)
#include "RL6432_Series_ColorLibInclude.h"
#elif(_SCALER_TYPE == _RL6449_SERIES)
#include "RL6449_Series_ColorLibInclude.h"
#elif(_SCALER_TYPE == _RL6463_SERIES)
#include "RL6463_Series_ColorLibInclude.h"
#elif(_SCALER_TYPE == _RL6492_SERIES)
#include "RL6492_Series_ColorLibInclude.h"
#endif


//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
// HLW Window Detection
extern void ScalerColorDCCSetMeasureRegion(EnumHLWType enumHLWType);

