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
// ID Code      : RL6851_Series_ScalerImgCmpLibInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _IMG_CMP_GEN1_BPP_SHIFT                         4

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE ucSteamPeriodEnc;
    BYTE ucSteamPeriodDec;
    BYTE b4BitPerComponent : 4;
    BYTE b4LineBufDepth : 4;
    BYTE b1YCCModeEn : 1;
    WORD b10BitPerPixel : 10;
    WORD usWidth;
    WORD usHeight;
} StructImgCmpGen1Param;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerImgCmpEncEn(BYTE ucRegPage, bit bEn);
extern void ScalerImgCmpDecEn(BYTE ucRegPage, bit bEn);
extern void ScalerImgCmpGen1CommonCtrl(BYTE ucCmpRegPage, BYTE ucDecmpRegPage, StructImgCmpGen1Param *pstImgCmpGen1Param);
