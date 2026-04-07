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
// ID Code      : ScalerCommonTypeCRx0CcInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#define SET_TYPE_C_ERROR_RECOVERY()             (g_stTpcInfo.b1Error = _TRUE)

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
extern StructTypeCEmbInfo g_stTpcInfo;
#endif  // End of #if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
extern void ScalerTypeCRx0CcACOnDeviceDetect(void);
extern bit ScalerTypeCRx0CcGetACOnDeviceDetect(void);
#endif  // End of #if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)