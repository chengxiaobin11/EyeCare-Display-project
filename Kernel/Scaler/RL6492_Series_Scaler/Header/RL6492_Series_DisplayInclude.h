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
// ID Code      : RL6492_Series_DisplayInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _LVDS_TXCD_OUTPUT_DATA_PORT_ADDR            (P39_02_LVDS_DISPLAY_CONV_CTRL1)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_PANEL_STYLE == _PANEL_LVDS)
extern void ScalerDisplayLvdsInitialTable(void);
extern void ScalerDisplayLvdsSetPhaseBand(BYTE ucPhaseBand);

extern bit ScalerDisplayGetLvdsPowerStatus(void);
extern void ScalerDisplayLvdsPLL(bit bOn);
extern void ScalerDisplayLvdsPadPower(bit bOn);
#endif

#if(_PANEL_STYLE == _PANEL_DPTX)
extern void ScalerDisplayUseLvdsPadPower(bit bOn);
#endif

