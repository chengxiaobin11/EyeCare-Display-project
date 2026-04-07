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
// ID Code      : RL6851_Series_ScalerCommonRegLibInclude.h No.0000
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

extern void ScalerWrite(WORD usAddr, WORD usLength, BYTE *pucArray, bit bAutoInc);
extern void ScalerRead(WORD usAddr, WORD usLength, BYTE *pucArray, bit bAutoInc);

extern void ScalerSetDataPortByte(WORD usAddr, BYTE ucValue1, BYTE ucValue2);
extern void ScalerSetDataPortByte_EXINT0(WORD usAddr, BYTE ucValue1, BYTE ucValue2);
extern void ScalerGetDataPortByte(WORD usAddr, BYTE ucValue, WORD usLength, BYTE *pucArray, bit bAutoInc);
extern void ScalerSetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd, BYTE ucOr);
extern void ScalerSetDataPortBit_EXINT0(WORD usAddr, BYTE ucValue, BYTE ucAnd, BYTE ucOr);
extern BYTE ScalerGetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd);

extern BYTE ScalerGetDataPortSingleByte(WORD usAddr, BYTE ucValue);
extern void ScalerSetDataPortWord(WORD usAddr, BYTE ucValue1, WORD usValue2);
extern WORD ScalerGetDataPortWord(WORD usAddr, BYTE ucValue, bit bAutoInc);
extern void ScalerSetDataPortDword(WORD usAddr, BYTE ucValue1, DWORD ulValue2);
extern DWORD ScalerGetDataPortDword(WORD usAddr, BYTE ucValue, bit bAutoInc);

extern void ScalerBurstWrite(BYTE *pucAddress, WORD usWriteLength, BYTE ucBankNum, WORD usHostAddr, BYTE ucTableType, bit bTableLocation);

extern BYTE ScalerGlobalGetIDCode(void);
extern BYTE ScalerGlobalGetIDCode_EXINT0(void);
extern BYTE ScalerGlobalGetIDCode_WDINT(void);

