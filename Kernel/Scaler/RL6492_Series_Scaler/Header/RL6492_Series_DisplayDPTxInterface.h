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
// ID Code      : RL6492_Series_DisplayDPTxInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PANEL_STYLE == _PANEL_DPTX)

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerDisplayDPTxPollingHotPlug(WORD usNum);
extern bit ScalerDisplayDPTxLinkSequence(void);
extern void ScalerDisplayDPTxStreamHanlder(bit bOutput);

#if(_PANEL_DPTX_FORCE_OUTPUT_SUPPORT == _ON)
extern void ScalerDisplayDPTxLinkSignalForceOutput(void);
#endif

extern void ScalerDisplayDPTxPowerSequenceProc(bit bLevel);
extern void ScalerDisplayDPTxPhyInitial(void);
extern void ScalerDisplayDPTxSSCSet(bit bSscEn);
#endif // End of #if(_PANEL_STYLE == _PANEL_DPTX)
