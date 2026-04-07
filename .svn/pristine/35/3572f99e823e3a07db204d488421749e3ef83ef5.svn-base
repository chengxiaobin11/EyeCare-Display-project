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
// ID Code      : RL6851_Series_ScalerOsdInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_OSD_POSITION_OFFSET_CORRECTION == _OFF)
#define GET_OSD_POSITION_GOLOBAL_OFFSET_H()                     (g_ucOsdPositionGlobalOffsetH)
#define SET_OSD_POSITION_GOLOBAL_OFFSET_H(x)                    (g_ucOsdPositionGlobalOffsetH = (x))

#define GET_OSD_POSITION_GOLOBAL_OFFSET_V()                     (g_ucOsdPositionGlobalOffsetV)
#define SET_OSD_POSITION_GOLOBAL_OFFSET_V(x)                    (g_ucOsdPositionGlobalOffsetV = (x))
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_OSD_POSITION_OFFSET_CORRECTION == _OFF)
extern BYTE g_ucOsdPositionGlobalOffsetH;
extern BYTE g_ucOsdPositionGlobalOffsetV;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerOsdPositionOffset(EnumOsdPositionOffsetType enumOsdPositionOffsetType, BYTE ucHOffset, BYTE ucVOffset);
extern void ScalerOsdReset(void);
