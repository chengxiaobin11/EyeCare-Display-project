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
// ID Code      : RL6432_Series_SyncInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern WORD ScalerSyncGetInputPixelClk(void);

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern void ScalerSyncHdcpEnableDownLoadKey(bit bEnable);
extern void ScalerSyncHdcpDownLoadBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
extern void ScalerSyncHdcpDownLoadKey(WORD usLength, BYTE *pucReadArray);
#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_EFUSE)
void ScalerSyncGetEfuseHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void ScalerSyncGetEfuseHDCPKeyBKsv(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#endif

#endif

