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
// ID Code      : ScalerCommonDPRxMSTInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DP_MST_SUPPORT == _ON)
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerDpRxMstPowerOnInitial(void);
extern void ScalerDpRxMstInitial(EnumDPMSTPort enumRxMstPort);

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _OFF)
extern void ScalerDpRxMstRx0Rx1switch(EnumDPMSTPort enumMstCapablePort);
#endif

extern void ScalerDpRxMstInfoBackup(BYTE ucInputPort, EnumDpMstBackup enumDpMstBackup);
extern void ScalerDpRxMstHandler(void);
extern void ScalerDpRxMstStreamsHandler(void);

#if(_DP_TX_SUPPORT == _ON)
extern bit ScalerDpRxMstCheckMsgTransition(void);
#endif

extern void ScalerDpRxMstCableUnplugReset(BYTE ucInputPort);
extern void ScalerDpRxMstStreamMuxChangeHandler(void);
extern EnumDPMSTPort ScalerDpRxMstGetCapablePort(void);
extern bit ScalerDpRxMstGetSrcMsgEnable(EnumSourceSearchPort enumInputPort);
extern bit ScalerDpRxMstGetMstCapability(EnumSourceSearchPort enumInputPort);
extern EnumSourceSearchPort ScalerDpRxMstGetInputPort(EnumDPMSTPort enumMstPort);

#if(_DP_MST_AUTO_SEARCH_SUPPORT == _ON)
extern void ScalerDpRxMstCapabilitySwitch(EnumSourceSearchPort enumInputPort, bit bEn);
#endif

#endif

