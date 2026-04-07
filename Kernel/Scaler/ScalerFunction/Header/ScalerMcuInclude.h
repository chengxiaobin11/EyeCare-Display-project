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
// ID Code      : ScalerMcuInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// MACRO for MCU Clock Setting
//--------------------------------------------------
#define GET_REG_MCU_CLK_SEL()                   (((MCU_FFED_MCU_CONTROL & _BIT1) == 0x00) ? GET_REG_XTAL_CLK_SEL() : _M2PLL_CLK)
#define GET_REG_MCU_CLK_DIV_STAGE_1ST()         ((MCU_FFED_MCU_CONTROL >> 2) & 0x0F)


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
extern BYTE ScalerMcuGetDdcChannelFromInputPort(BYTE ucInputPort);
#endif
extern void ScalerMcuFlashClockGroupSetting(EnumClkSel enumClock);
extern void ScalerMcuCacheInitial(void);

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
extern void ScalerMcuDdcRamEDIDAddrSelect(EnumD0D1DDCRAMSelect enumDdcRamSel, EnumDDCAddrType enumDdcAddr);
#endif


