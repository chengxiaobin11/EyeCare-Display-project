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
// ID Code      : RL6410_Series_RotationInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
// Define Block Mode blk_w
#define _ROTATION_FRC_CAP_BLK_W                         (0x60)
#define _ROTATION_FRC_DISP_BLK_W                        (0x04)

// Define Memory Access Length
#define _ROTATION_WRITE_LENGTH_CW180                    (0x50)
#define _ROTATION_READ_LENGTH_CW180                     (0x50)
#define _ROTATION_BLK_LENGTH                            (_ROTATION_FRC_CAP_BLK_W)


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
extern void ScalerRotationSetEnable(bit bEn);
extern void ScalerRotationDisplayCtrlCW180(StructMemoryLineBlockStep stStep, WORD usVerSize);
extern void ScalerRotationResetProc(void);
#endif

