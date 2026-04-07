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
// ID Code      : RL6492_Series_PinshareInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerPinshareInitial(void);
extern void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType);
extern void ScalerPinshareAdjustConfig(EnumConfigPin enumConfigPin, EnumPinConfigType enumConfigType);
extern void ScalerPinshareAdjustFlashDrive(EnumConfigSPIPinType enumConfigFlashDrive, EnumFlashDriveConfigType enumFlashDriveConfig);
extern void ScalerPinshareCBUSPinInitialReset(void);

#if(_10_BIT_ADC_FOR_NONE_TYPE_C_SUPPORT == _ON)
extern void ScalerPinshareTypeCAdcInitial(void);
extern WORD ScalerPinshareTypeCAdcGetAdcIdealData(EnumTypeCAdcChannel enumChannel);
#endif

