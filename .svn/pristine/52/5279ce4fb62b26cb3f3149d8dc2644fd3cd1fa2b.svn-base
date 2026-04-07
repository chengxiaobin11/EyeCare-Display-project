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
// ID Code      : RL6369_Series_PinshareInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerPinsharePowerOnReset(void);

#if(_HW_IIC_SUPPORT == _ON)
extern void ScalerPinshareHwIICPin(BYTE ucHwIICPinNum);
#endif

extern void ScalerPinshareGpioDdcPinSwitch(BYTE ucPinType);
extern void ScalerPinshareAdjustFlashDrive(EnumConfigSPIPinType enumConfigFlashDrive, EnumFlashDriveConfigType enumFlashDriveConfig);
extern void ScalerPinshareAdjustFlashSlewRate(void);

#if(_D0_DP_EXIST == _ON)
extern void ScalerPinshareRx0TypeCPinAssert(EnumTypeCPinCfgType enumTypeCPinCfgType, EnumTypeCOrientation enumTypeCOrientation);
#endif

