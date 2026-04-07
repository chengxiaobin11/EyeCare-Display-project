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
// ID Code      : RL6851_Series_McuInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// MACRO for DDC Channel Select
//--------------------------------------------------
#define GET_DDC_CHANNEL()                               (MCU_FF22_IIC_CH_SEL & (_BIT3 | _BIT2 | _BIT1 | _BIT0))


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMcuDdcDebounceSel(EnumClkSel enumClock);
extern void ScalerMcuDdcciSwitchPort(EnumDDCCIDebugMode enumMode, BYTE ucInputPort);
extern void ScalerMcuGpioInitial(void);
extern void ScalerMcuDdcInitial(void);
#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
extern void ScalerMcuDdcciEnable(bit bEn, BYTE ucInputPort);
#endif
extern void ScalerMcuDdcRamEnable(void);
extern void ScalerMcuDdcciInitial(void);

#if((_DEBUG_MESSAGE_SUPPORT == _OFF) && ((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON)))
extern void ScalerMcuDdcciHoldScl_EXINT1(void);
#endif

extern void ScalerMcuSetISPChannel(WORD usISPChannel);
