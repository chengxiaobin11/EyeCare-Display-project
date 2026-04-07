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
// ID Code      : RL6851_Series_ScalerMDomainCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_INTERLACED_MODE()                           (g_stMDomainInputData.b1Interlace)

#define GET_H_SCALE_UP()                                (g_stMDomainInfo.b1HSU)
#define SET_H_SCALE_UP()                                (g_stMDomainInfo.b1HSU = _TRUE)
#define CLR_H_SCALE_UP()                                (g_stMDomainInfo.b1HSU = _FALSE)

#define GET_H_SCALE_DOWN()                              (g_stMDomainInfo.b1HSD)
#define SET_H_SCALE_DOWN()                              (g_stMDomainInfo.b1HSD = _TRUE)
#define CLR_H_SCALE_DOWN()                              (g_stMDomainInfo.b1HSD = _FALSE)

#define GET_V_SCALE_UP()                                (g_stMDomainInfo.b1VSU)
#define SET_V_SCALE_UP()                                (g_stMDomainInfo.b1VSU = _TRUE)
#define CLR_V_SCALE_UP()                                (g_stMDomainInfo.b1VSU = _FALSE)

#define GET_V_SCALE_DOWN()                              (g_stMDomainInfo.b1VSD)
#define SET_V_SCALE_DOWN()                              (g_stMDomainInfo.b1VSD = _TRUE)
#define CLR_V_SCALE_DOWN()                              (g_stMDomainInfo.b1VSD = _FALSE)

//--------------------------------------------------
// Macros of Input Info.
//--------------------------------------------------
#define GET_MEMORY_SELECT()                             (g_stMDomainInfo.b3MemorySelect)
#define SET_MEMORY_SELECT(x)                            (g_stMDomainInfo.b3MemorySelect = (x))
#define CLR_MEMORY_SELECT()                             (g_stMDomainInfo.b3MemorySelect = 0)

//--------------------------------------------------
// Define Memory Frame Buffer
//--------------------------------------------------
#define _MEMORY_1_FRAME_BUFFER                          0
#define _MEMORY_1_5_FRAME_BUFFER                        1
#define _MEMORY_2_FRAME_BUFFER                          2
#define _MEMORY_3_FRAME_BUFFER                          3

//--------------------------------------------------
// Macros of Memory Frame buffer
//--------------------------------------------------
#define GET_MEMORY_FRAME_BUFFER()                       (g_stMDomainInfo.b2MemoryFrameBuf)
#define SET_MEMORY_FRAME_BUFFER(x)                      (g_stMDomainInfo.b2MemoryFrameBuf = (x))
#define CLR_MEMORY_FRAME_BUFFER()                       (g_stMDomainInfo.b2MemoryFrameBuf = 0)

//--------------------------------------------------
// Macros of DVF
//--------------------------------------------------
#define GET_MEMORY_DVF_SELECT()                         (g_stMDomainInfo.b3DVFSelect)
#define SET_MEMORY_DVF_SELECT(x)                        (g_stMDomainInfo.b3DVFSelect = (x))
#define CLR_MEMORY_DVF_SELECT()                         (g_stMDomainInfo.b3DVFSelect = 0)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructMDomainInfo g_stMDomainInfo;
extern StructTimingInfo g_stMDomainInputData;
extern StructDisplayInfo g_stMDomainOutputData;
extern StructFRCFIFOInfo g_stMDomainFRCFIFOData;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern BYTE ScalerMDomainGetColorDepth(void);
