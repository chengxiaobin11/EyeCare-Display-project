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
// ID Code      : UserCommonDualBankUserTable.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_DUAL_BANK_USER_TABLE__

#include "UserCommonInclude.h"

#if((_DUAL_BANK_FLASH_PARTITION_SUPPORT == _ON) &&\
    (_DUAL_BANK_TYPE == _DUAL_BANK_FLASH_PARTITION_USER_FLAG_MODE) &&\
    (_DUAL_BANK_USER_FLAG_LOCATION_AREA != _DUAL_BANK_FLAG_LOCATION_IN_NONE_FW))
#warning "NOTE: Please check _DUAL_BANK_FLASH_PARTITION_DEFAULT_CODE_TABLE should be all 0xFF or equal _DUAL_BANK_FLASH_PARTITION_USER_FLAG_DATA!!"
#endif

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_DUAL_BANK_FP_USER_FLAG_TABLE_SUPPORT == _ON)
BYTE code tDUALBANKUSERFLAGTABLE[] =
{
    _DUAL_BANK_FLASH_PARTITION_DEFAULT_CODE_TABLE
};
#endif

#if(_DUAL_BANK_USER_DATA_TABLE_SUPPORT == _ON)
BYTE code tDUALBANK_FILLHEX[_DUALBANK_FILL_LENGTH * 1024] =
{
#if(_DUALBANK_FILL_LENGTH >= 1)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 2)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 3)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 4)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 5)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 6)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 7)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 8)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 9)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 10)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 11)
#include <UserCommonDualBankUser1KTable.h>
#endif
#if(_DUALBANK_FILL_LENGTH >= 12)
#include <UserCommonDualBankUser1KTable.h>
#endif
};
#endif


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

