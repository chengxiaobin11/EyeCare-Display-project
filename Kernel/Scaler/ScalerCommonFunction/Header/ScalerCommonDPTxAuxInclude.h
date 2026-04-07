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
// ID Code      : ScalerCommonDPTxAuxInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _DP_AUX_TX_RETRY_LIMIT                                  10

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
//extern BYTE data g_ucEDIDPreferTiming[18];

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

#if(_DP_TX_SUPPORT == _ON)
extern bit ScalerDpTxAuxNativeWrite(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL, BYTE ucLength, BYTE *pucWriteArray);
extern bit ScalerDpTxAuxNativeRead(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL, BYTE ucLength, BYTE *pucReadArray);
extern bit ScalerDpTxAuxI2CoverWrite(BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray, bit bMOT);
extern bit ScalerDpTxAuxI2CoverRead(BYTE ucSlaveAddress, BYTE ucLength, BYTE *pucDataArray, bit bMOT);
extern BYTE ScalerDpTxAuxNativeRead_EXINT0(BYTE ucAddrH, BYTE ucAddrM, BYTE ucAddrL, BYTE ucLength, BYTE *pucReadArray);
#endif

