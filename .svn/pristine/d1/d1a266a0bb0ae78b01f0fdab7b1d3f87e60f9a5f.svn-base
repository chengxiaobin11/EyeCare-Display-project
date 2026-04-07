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
// ID Code      : ScalerRotationInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#define GET_ROT_TYPE()                                  (g_stRotationStatus.enumRotationType)
#define SET_ROT_TYPE(x)                                 (g_stRotationStatus.enumRotationType = (x))

#define GET_ROT_DISP_SIZE()                             (g_stRotationStatus.enumRotationDispSize)
#define SET_ROT_DISP_SIZE(x)                            (g_stRotationStatus.enumRotationDispSize = (x))

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
extern StructRotationStatus g_stRotationStatus;

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern bit ScalerRotationCheckStatus(void);

#if(_DISPLAY_ROTATION_TYPE == _DISPLAY_ROTATION_GEN_I)
extern void ScalerRotationSetDDomainSourceSelect(EnumDDomainSourceSelect enumSourceSelect);
extern void ScalerRotationSetFRCEn(EnumFRCOnOff enumCapDispOnOff, bit bEn);
#endif

#endif

