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
// ID Code      : RL6410_Series_McuInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// MACRO for DDC Channel Select
//--------------------------------------------------
#define GET_DDC_CHANNEL()                               (MCU_FF22_IIC_CH_SEL & (_BIT2 | _BIT1 | _BIT0))

//--------------------------------------------------
// MACRO for VGADDC Channel SCL force low
//--------------------------------------------------
#define SET_VGADDC_SCL_FORCE_LOW()                      (MCU_FF1D_ADC_DDC_CONTROL_2 |= _BIT0)
#define CLR_VGADDC_SCL_FORCE_LOW()                      (MCU_FF1D_ADC_DDC_CONTROL_2 &= ~_BIT0)


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// Definitions of DDC Ram Address Layout
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
