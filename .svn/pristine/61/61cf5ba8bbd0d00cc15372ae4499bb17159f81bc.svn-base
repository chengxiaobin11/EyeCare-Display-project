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
// ID Code      : RL6432_Series_ScalingInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_VER_FILTER_COEF_INI(ulBackup)           {\
                                                        BYTE pucVerCoefIniBackup[3];\
                                                        memset(pucVerCoefIniBackup, 0, sizeof(pucVerCoefIniBackup));\
                                                        ScalerGetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_11_VER_FILTER_COEF_INI, 1, &pucVerCoefIniBackup[0], _NON_AUTOINC);\
                                                        ScalerGetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_16_VER_FILTER_COEF_INI_M, 1, &pucVerCoefIniBackup[1], _NON_AUTOINC);\
                                                        ScalerGetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_17_VER_FILTER_COEF_INI_L, 1, &pucVerCoefIniBackup[2], _NON_AUTOINC);\
                                                        (ulBackup) = (((((DWORD)pucVerCoefIniBackup[0] << 12) & 0xFF000) | (((DWORD)pucVerCoefIniBackup[1] << 4) & 0x00FF0) | ((pucVerCoefIniBackup[2] >> 4) & 0x0000F)) & 0x000FFFFF);\
                                                        (ulBackup) = ((ulBackup) >> 13);\
                                                    }

#define _VSD_FACTOR_BIT                             (20)

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

