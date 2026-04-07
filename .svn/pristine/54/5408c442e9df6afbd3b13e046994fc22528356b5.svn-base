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
// ID Code      : RL6463_Series_ScalingInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_VER_FILTER_COEF_INI(ulBackup)           {\
                                                        BYTE pucVerCoefIniBackup[1];\
                                                        memset(pucVerCoefIniBackup, 0, sizeof(pucVerCoefIniBackup));\
                                                        ScalerGetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_11_VER_FILTER_COEF_INI, 1, &pucVerCoefIniBackup[0], _NON_AUTOINC);\
                                                        (ulBackup) = (pucVerCoefIniBackup[0] & 0x000000FF);\
                                                        (ulBackup) = ((ulBackup) >> 1);\
                                                    }

#define _VSD_FACTOR_BIT                             (17)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerScalingSetScalingUp(const StructSDRAMDataInfo *pstFIFOScaling);
extern void ScalerScalingSetScalingDown(const StructSDRAMDataInfo *pstFIFOScaling);

extern void ScalerScalingGetFIFOScalingSize(StructSDRAMDataInfo *pstData);

