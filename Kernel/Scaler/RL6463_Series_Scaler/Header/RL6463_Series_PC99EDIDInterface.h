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
// ID Code      : RL6463_Series_PC99EDIDInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_HW_PC99_SUPPORT == _ON)
//--------------------------------------------------
// Definitions of PC99 EDID start address (at bank 0)
//--------------------------------------------------
#define _HW_PC99_WRITE_EDID_COMMAND_BANK_INDEX                  (0)
#define _HW_PC99_WRITE_EDID_COMMAND_ADDR_START                  (0xFD70)
#define _HW_PC99_A0_EDID_FLASH_ADDR_START                       (0xFD80)
#define _HW_PC99_D0_EDID_FLASH_ADDR_START                       (0xFE00)
#define _HW_PC99_D1_EDID_FLASH_ADDR_START                       (0xFF00)
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_HW_PC99_SUPPORT == _ON)
extern void ScalerPC99EDIDInitialControl(void);
#endif
