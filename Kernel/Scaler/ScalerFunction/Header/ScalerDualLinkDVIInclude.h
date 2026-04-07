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
// ID Code      : ScalerDualLinkDVIInclude.h No.0000
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
#if(_DUAL_DVI_SUPPORT == _ON)
extern bit ScalerDualLinkDVIGetDualDVIMode(EnumSourceSearchPort enumInputPort);
extern bit ScalerDualLinkDVIDoubleCheck(EnumSourceSearchPort enumSourceSearchPort, WORD usHwidth, WORD usVHeight);
extern void ScalerDualLinkDVIClockInvert(void);

#if(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT)
extern void ScalerDualLinkDVIRx2Switch(bit bEnable);
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT)
extern void ScalerDualLinkDVIRx3Switch(bit bEnable);
#endif

#if(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)
extern void ScalerDualLinkDVIRx4Switch(bit bEnable);
#endif

#endif // End of #if(_DUAL_DVI_SUPPORT == _ON)

