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
// ID Code      : RL6410_Series_FRCInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Deinfe FRC setting path
//--------------------------------------------------
#define _FRC_CAP_MAIN_1                                 (_BIT0)
#define _FRC_CAP_MAIN_2                                 (_BIT1)
#define _FRC_CAP_SUB_1                                  (_BIT2)
#define _FRC_CAP_SUB_2                                  (_BIT3)

#define _FRC_DISP_MAIN_1                                (_BIT4)
#define _FRC_DISP_MAIN_2                                (_BIT5)
#define _FRC_DISP_SUB_1                                 (_BIT6)
#define _FRC_DISP_SUB_2                                 (_BIT7) // Only for 4P Case / PBP_TB

#define _FRC_CAP_DISP_ALL                               (_FRC_CAP_MAIN_1 | _FRC_CAP_MAIN_2 | _FRC_CAP_SUB_1 | _FRC_CAP_SUB_2 | _FRC_DISP_MAIN_1 | _FRC_DISP_MAIN_2 | _FRC_DISP_SUB_1 | _FRC_DISP_SUB_2)

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_HW_FRC_TYPE != _FRC_GEN_NONE)
extern void ScalerFRCEn(BYTE ucSettingPath, bit bEn);
#endif

#if(_FRC_SUPPORT == _ON)
extern void ScalerFRCWaitWriteFrameBufFinish(void);

#if(_FREEZE_SUPPORT == _ON)
extern void ScalerFRCDisplayFreeze(bit bEn);
#endif
#endif

extern void ScalerFRCSetDDomainSourceSelect(EnumDDomainSourceSelect enumSourceSelect);
