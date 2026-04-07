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
// ID Code      : RL6432_Series_DPInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DP_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_DP_FREESYNC_SUPPORT == _ON)
#define _DP_FREESYNC_IVSTART                            1
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDpSecDataReset(BYTE ucInputPort);
extern bit ScalerDpHdcpCheckValid(BYTE ucInputPort);
extern void ScalerDpFirstActiveProc(BYTE ucInputPort);
extern void ScalerDpPowerSwitch(EnumPowerAction enumPowerAction);

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
extern bit ScalerDpRxLinkStatusLoss(void);
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)

#if(_DP_TX_SUPPORT == _ON)
extern void ScalerDpTxSSTSetAmdSpdInfo(bit bPlayback);
#endif
#endif

#endif
