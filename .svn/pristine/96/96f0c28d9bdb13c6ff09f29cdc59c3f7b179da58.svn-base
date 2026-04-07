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
// ID Code      : RL6432_Series_DisplayInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _LVDS_TXCD_OUTPUT_DATA_PORT_ADDR            (P39_03_LVDS_DISPLAY_CONV_CTRL2)

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
extern void ScalerDisplayLvdsPadPower(bit bOn);
extern void ScalerDisplaySetLvdsGpioInitial(void);

#if((_LVDS_PORT_SEL == _LVDS_1_PORT_A) || (_LVDS_PORT_SEL == _LVDS_1_PORT_B) || (_LVDS_PORT_SEL == _LVDS_2_PORT_AB) || (_LVDS_PORT_SEL == _LVDS_4_PORT_ABCD))
extern void ScalerDisplayLvdsSetVcoBand(BYTE ucVcoBand);
extern void ScalerDisplayLvdsSetPhaseBand(BYTE ucPhaseBand);
#endif

extern bit ScalerDisplayGetLvdsPowerStatus(void);
extern void ScalerDisplayLvdsPLL(bit bOn);

#elif(_PANEL_STYLE == _PANEL_DPTX)
extern void ScalerDisplayUseLvdsPadPower(bit bOn);
#endif

