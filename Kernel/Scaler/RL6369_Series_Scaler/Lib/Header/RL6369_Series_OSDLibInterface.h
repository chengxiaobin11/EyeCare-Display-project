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
// ID Code      : RL6369_Series_OSDLibInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifndef __RL6369_SERIES_OSD_LIB_INTERFACE__
#define __RL6369_SERIES_OSD_LIB_INTERFACE__

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#define _OSD_POSITION_OFFSET_H                                  0x28
#define _OSD_POSITION_OFFSET_V                                  0x04

#define _OSD_DOUBLE_POSITION_OFFSET_H                           0x0C
#define _OSD_DOUBLE_POSITION_OFFSET_V                           0x01

#define _OSD_ROTATE_NO_SWAP                                     0x00
#define _OSD_ROTATE_CCW                                         (_BIT7)
#define _OSD_ROTATE_CW                                          (_BIT7 | _BIT6)

#define GET_OSD_POSITION_V_OFFSET_CORRECT_COMPENSATION()        (g_ucOSDPositionVOffsetCorrectCompensation)

//****************************************************************************
// INTERFACE STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
extern BYTE g_ucOSDPositionVOffsetCorrectCompensation;


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
//--------------------------------------------------
// SRAM
//--------------------------------------------------
extern void ScalerOsdFontRotateCtrl(EnumOsdRotateType enumRotType, BYTE ucFontDownloadRotEn, BYTE ucDispRotEn);
extern void ScalerOsdHardwareCompression(BYTE *pucArray, WORD usVLCTableSize, BYTE ucBankNum, WORD usOffset, WORD usFontTableStart, EnumOsdRotateType enumOsdRotateType, bit bTableLocation);
extern void ScalerOsdHardwareVLC(BYTE *pucArray, WORD usVLCTableSize, BYTE ucBankNum, WORD usOffset, WORD usFontTableStart, EnumOsdRotateType enumOsdRotateType);
extern void ScalerOsdSramBaseAddressSet(EnumOsdMapType enumOsdMapType, BYTE ucRowCommandStart, WORD usCharactorCommandStart, WORD usFontStart);

//--------------------------------------------------
// Function
//--------------------------------------------------
extern void ScalerOsdSetTransparency(BYTE ucTransparency);
extern void ScalerOsdSetTransparency_EXINT(BYTE ucTransparency);
extern void ScalerOsdPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY);
extern void ScalerOsdPositionOffsetCorrection(void);
extern void ScalerOsdVerticalBoundary(bit bEnable);

#endif
