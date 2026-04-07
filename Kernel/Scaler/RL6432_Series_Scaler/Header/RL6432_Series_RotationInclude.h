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
// ID Code      : RL6432_Series_RotationInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
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
extern void ScalerRotationControl(const StructSDRAMDataInfo *pstFIFOSize);
extern void ScalerRotationReset(void);
extern void ScalerRotationSetRotInputSlowerFasterStyle(bit bInputFasterStatus);
extern void ScalerRotationSetEnable(bit bEn);
extern void ScalerRotationResetProc(void);
#endif
