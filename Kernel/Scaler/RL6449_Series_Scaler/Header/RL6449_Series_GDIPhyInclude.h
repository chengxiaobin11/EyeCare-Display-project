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
// ID Code      : RL6449_Series_GDIPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of GDI Clk Freq. (in kHz)
//--------------------------------------------------
#define _GDI_CLK_KHZ                                (DWORD)((bit)ScalerGetBit(P80_06_GDI_CLK_DIVIDER, _BIT4) ? (((DWORD)1000 * _M2PLL_CLK_MHZ) / _GDI_CLK_DIV) : (_SYS_USE_ISO_CLK ? _INTERNAL_OSC_XTAL : _EXT_XTAL))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerGDIPhyBandgap(bit bSelect);

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect);
extern void ScalerGDIPhyPowerProc(BYTE ucPortSelect, EnumPowerAction enumPowerAction);
extern void ScalerGDIPhyDigitalPhySwitch(BYTE ucInputPort);
#endif

