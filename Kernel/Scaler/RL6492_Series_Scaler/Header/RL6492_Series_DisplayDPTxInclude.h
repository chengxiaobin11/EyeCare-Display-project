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
// ID Code      : RL6492_Series_DisplayDPTxInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_PANEL_STYLE == _PANEL_DPTX)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#define SET_DISPLAY_DP_TX1_MVID_FW_MODE()                   (ScalerSetBit(P9C_F3_DPTX_TOP_RSV6, ~_BIT1, 0x00))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDisplayDPTxSSCSet(bit bSscEn);
extern void ScalerDisplayDPTxPhy(bit bOn);
extern void ScalerDisplayDPTxPLL(bit bOn);
extern void ScalerDisplayDPTxPower(bit bOn);
extern void ScalerDisplayDPTxSetLinkRate(void);

#if(_DISPLAY_DP_TX_PORT_1 == _ON)
extern void ScalerDisplayDPTx1AuxPHYSet(BYTE ucMode);
extern void ScalerDisplayDPTx1SetSignalLevel(EnumDisplayDPTxLane enumLaneX, BYTE ucVoltageSwing, BYTE ucPreEmphasis);
extern void ScalerDisplayDPTx1SignalInitialSetting(void);
extern EnumDisplayDPTxTrainPattern ScalerDisplayDPTx1SetTp2PatternType(void);
#endif

#endif // End of #if(_PANEL_STYLE == _PANEL_DPTX)
