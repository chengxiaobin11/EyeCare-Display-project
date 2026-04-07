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
// ID Code      : UserCommonFwUpdateSignatureTable.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_FW_UPDATE_SIGNATURE_TABLE__

#include "UserCommonInclude.h"

#if(_FW_UPDATE_FOREGROUND_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_FW_UPDATE_CHECK_TYPE == _FW_UPDATE_CHECK_RTK_RSA2048)
// 4K byte is reserved for RSA2048 Signature Info
BYTE code tFW_UPDATE_SIGNATURE_TABLE[] =
{
#include <UserCommonDualBankUser1KTable.h>
#include <UserCommonDualBankUser1KTable.h>
#include <UserCommonDualBankUser1KTable.h>
#include <UserCommonDualBankUser1KTable.h>
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


#endif

