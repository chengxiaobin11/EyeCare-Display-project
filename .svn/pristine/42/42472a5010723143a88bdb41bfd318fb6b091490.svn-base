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
// ID Code      : RL6851_Series_ScalerImgCmpInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
#define _IMG_CMP_MEM_RW_UNIT                            (128)
#define _IMG_CMP_BLK_WIDTH                              (1)
#define _IMG_CMP_STREAM_END_DUMMY_LEN                   (0)
#define _IMC_LATENCY                                    (2) // IMC = IMC encode + IMC decode = 570 pixel + 1 line
#define _M_DOMAIN_IMG_CMP_6_BPP_SUPPORT                 _OFF // have performance issue, fix to _OFF
#endif

#define GET_IMG_CMP_ENABLE(x)                           (g_pstImgCmpParam[(x)].b1Enable)
#define GET_IMG_CMP_PARAM_DATA_DEPTH(x)                 (g_pstImgCmpParam[(x)].b5ColorDepth)
#define GET_IMG_CMP_PARAM_LLB(x)                        (g_pstImgCmpParam[(x)].ucLineLimitBit)

#define _IMG_CMP_MIN_INPUT_WIDTH                        (800)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE b1Enable : 1;
    BYTE b5ColorDepth : 5;
    BYTE ucLineLimitBit;
} StructImgCmpParam;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructImgCmpParam g_pstImgCmpParam[];

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_M_DOMAIN_IMG_CMP_SUPPORT == _ON)
extern void ScalerImgCmpCtrl(WORD usHWidth, WORD usVHeight, EnumImgCmpParamIndex enumCmpParamIndex);
extern void ScalerImgCmpEn(EnumFRCOnOff enumCapDispOnOff, bit bEn);
extern void ScalerImgCmpDecmpPowerControl(bit bPowerOn);
#endif
