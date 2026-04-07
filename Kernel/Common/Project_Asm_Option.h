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
// ID Code      : Project_Asm_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//-------------------------------------------------
// Dual bank type
//-------------------------------------------------
#ifndef _DUAL_BANK_SUPPORT
#define _DUAL_BANK_SUPPORT                                   _OFF
#endif

#ifndef _DUAL_BANK_TYPE
#define _DUAL_BANK_TYPE                                      _DUAL_BANK_DIFF_BANK
#endif

#ifndef _DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL
#define _DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL             _DUAL_BANK_FLASH_PARTITION_BOOT
#endif

#ifndef _DUAL_BANK_COMPATIBLE_WITH_OLD_BOOT_SUPPORT
#define _DUAL_BANK_COMPATIBLE_WITH_OLD_BOOT_SUPPORT          _OFF
#endif

//-------------------------------------------------
// STARTUP.a51 init setting
//-------------------------------------------------
#ifndef _STARTUP_SPEED_UP_SUPPORT
#define _STARTUP_SPEED_UP_SUPPORT                            _OFF
#endif

//-------------------------------------------------
// L51 Total bank setting
//-------------------------------------------------
#ifndef _DUAL_BANK_FLASH_PARTITION_TOTAL_BANKS
#if(_DUAL_BANK_SUPPORT != _ON)
#define _DUAL_BANK_FLASH_PARTITION_TOTAL_BANKS               0x10
#else
#define _DUAL_BANK_FLASH_PARTITION_TOTAL_BANKS               0x20
#endif
#endif

//-------------------------------------------------
// Bank Switch Support(Using 30H)
// User Code Used in L51_bank.a51
//-------------------------------------------------
#define _BANK_SWITCH_SUPPORT                                 ((_DUAL_BANK_SUPPORT == _ON) &&\
                                                             ((_DUAL_BANK_TYPE == _DUAL_BANK_DIFF_BANK) ||\
                                                             (_DUAL_BANK_TYPE == _DUAL_BANK_COPY_BANK) ||\
                                                             (((_DUAL_BANK_TYPE == _DUAL_BANK_FLASH_PARTITION) ||\
                                                              (_DUAL_BANK_TYPE == _DUAL_BANK_FLASH_PARTITION_USER_FLAG_MODE)) &&\
                                                              (_DUAL_BANK_FLASH_PARTITION_BOOT_USER_SEL != _DUAL_BANK_FLASH_PARTITION_BOOT))))


