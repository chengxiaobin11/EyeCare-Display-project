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
// ID Code      : ScalerDP_ComboPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
//  DP LEQ RELOAD Define
//--------------------------------------------------
#define _DP_RELOAD_LEQ_INITIAL                            0
#define _DP_RELOAD_LEQ_LARGE                              1
#define _DP_RELOAD_LEQ_DEFAULT                            2

#define GET_DP_RX0_MAIN_LINK_MARGINAL()                   (g_ucDpRx0MainLinkMarginal)
#define SET_DP_RX0_MAIN_LINK_MARGINAL()                   (g_ucDpRx0MainLinkMarginal = _TRUE)
#define CLR_DP_RX0_MAIN_LINK_MARGINAL()                   (g_ucDpRx0MainLinkMarginal = _FALSE)


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern BYTE g_ucDpRx0MainLinkMarginal;


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_DP_SUPPORT == _ON)
extern void ScalerDpFakeLinkTrainingSetting(BYTE ucInputPort);
extern void ScalerDpFirstActiveProc(BYTE ucInputPort);
extern bit ScalerDpHdcpCheckValid(BYTE ucInputPort);
extern void ScalerDpLaneCountSwitch(BYTE ucInputPort, EnumDpLaneCount enumDpLaneCount);
extern void ScalerDpLowPowerProc(void);
extern void ScalerDpResetProc(void);
#endif
