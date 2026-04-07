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
// ID Code      : ScalerCommonNVRamInterface.h No.0000
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
extern bit ScalerFlashErasePage(BYTE ucBank, BYTE ucPage);

#if(_FLASH_WR_PROTECT == _ON)
extern void ScalerFlashWRProtect(void);
#endif

#if(_FW_UPDATE_FOREGROUND_SUPPORT == _ON)
extern bit ScalerFlashEraseBank(BYTE ucBank);
extern bit ScalerFlashWritePageProgram(BYTE ucBank, WORD usAddr, WORD usLength, bit bEnFlashSR, bit bDisFlashSR);
#endif

#if(_FLASH_WRITE_FUNCTION_SUPPORT == _ON)
void ScalerFlashWREN(BYTE ucBank, BYTE ucPage);
void ScalerFlashWRDis(void);
#endif

