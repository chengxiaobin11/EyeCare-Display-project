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
// ID Code      : ScalerMbrAdvanceInclude.h No.0000
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
extern void ScalerMbrUpdateRtkAdvMbrStatus(WORD usInputVFreq, StructRtkAdvMbrPanelInfo *pstPanelInfo);
extern bit ScalerMbrGetAdvMbrStatus(void);
extern bit ScalerMbrCheckAdvMbrSequenceCtrl(void);
extern void ScalerMbrClearRtkAdvMbrMode(void);
extern void ScalerMbrSetRtkAdvMbrUserStatus(EnumRtkAdvMbrUserStatus enumRtkAdvMbrUserStatus);
extern void ScalerMbrUpdateRtkAdvMbrMemConfig(BYTE *pucMemConfig);
extern void ScalerMbrUpdateRtkAdvMbrMDomainInfo(DWORD *pulHSDSpace, StructMDomainInfo *pstMDomainInfo);
extern void ScalerMbrUpdateRtkAdvMbrDisplayInfo(DWORD *pulDclk, WORD *pusDVFreq, StructDisplayInfo *pstMDomainOutputData, StructRtkAdvMbrPanelInfo *pstPanelInfo);

