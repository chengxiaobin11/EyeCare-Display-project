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
// ID Code      : ScalerDisplayInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
extern StructDisplayCustomizedData g_stDisplayCustomizedData;

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_PANEL_STYLE == _PANEL_VBO)
extern void ScalerDisplayVboAnalogPhyConrol(bit bEnable);
extern void ScalerDisplayVboHtpdnSetFwControl(bit bEnable);

#if(_PANEL_VBO_CHANGE_CLK_RESET_TYPE == _VBO_CHANGE_CLK_RESET_BY_RE_LINK_TRAIN)
extern void ScalerDisplayVboForceLinkTraining(bit bEnable);
#endif

extern void ScalerDisplayVboForceVideoOutput(bit bEnable);
extern void ScalerDisplayVboPollingHotPlug(WORD usNum);
extern void ScalerDisplayVboHtpdnHandler(void);
extern void ScalerDisplayVboLocknHandler(void);
extern void ScalerDisplayVboPanelSetFastOff(bit bEnable);
extern bit ScalerDisplayVboPanelFastOffCheck(void);
extern void ScalerDisplayVboPanelBacklightReTurnOn(void);
extern void ScalerDisplayVboIntHandler_EXINT0(void);
#endif

extern BYTE ScalerDisplaySelectDVFMode(void);

