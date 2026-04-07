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
// ID Code      : ScalerCommonMcuCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _CKCON_MOVX_2_CYCLE                     (0)
#define _CKCON_MOVX_3_CYCLE                     (1)
#define _CKCON_MOVX_4_CYCLE                     (2)
#define _CKCON_MOVX_5_CYCLE                     (3)
#define _CKCON_MOVX_6_CYCLE                     (4)
#define _CKCON_MOVX_7_CYCLE                     (5)
#define _CKCON_MOVX_8_CYCLE                     (6)
#define _CKCON_MOVX_9_CYCLE                     (7)

#define _CKCON_MOVX_DEFAULT_CYCLE               _CKCON_MOVX_2_CYCLE

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#define MCU_SET_BIT_WITH_CKCON(addr, bitAnd,\
                            bitOr, ckcon)       {\
                                                    if((ckcon) == _CKCON_MOVX_DEFAULT_CYCLE)\
                                                    {\
                                                        (addr) = ((addr) & (bitAnd) | (bitOr));\
                                                    }\
                                                    else\
                                                    {\
                                                        CKCON = ((CKCON & ~(_BIT2 | _BIT1 | _BIT0)) | (ckcon));\
                                                        (addr) = ((addr) & (bitAnd) | (bitOr));\
                                                        CKCON = ((CKCON & ~(_BIT2 | _BIT1 | _BIT0)) | _CKCON_MOVX_DEFAULT_CYCLE);\
                                                    }\
                                                }

#define MCU_SET_BYTE_WITH_CKCON(addr,\
                                  x, ckcon)     {\
                                                    if((ckcon) == _CKCON_MOVX_DEFAULT_CYCLE)\
                                                    {\
                                                        (addr) = (x);\
                                                    }\
                                                    else\
                                                    {\
                                                        CKCON = ((CKCON & ~(_BIT2 | _BIT1 | _BIT0)) | (ckcon));\
                                                        (addr) = (x);\
                                                        CKCON = ((CKCON & ~(_BIT2 | _BIT1 | _BIT0)) | _CKCON_MOVX_DEFAULT_CYCLE);\
                                                    }\
                                                }

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

