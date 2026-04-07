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
// ID Code      : UserCommonFwUpdatePassword.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_FW_UPDATE_PASSWORD_TABLE__

#include "UserCommonInclude.h"

#if(_FW_UPDATE_FOREGROUND_SUPPORT == _ON)
#if(_FW_UPDATE_CHECK_TYPE == _FW_UPDATE_CHECK_PASSWORD)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
BYTE code tFwPassword[] =
{
    _FW_UPDATE_PASSWORD_DATA,
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit UserCommonFwUpdatePasswordVerify(BYTE ucBank, WORD usAddr);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Fw Update Password Verify
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserCommonFwUpdatePasswordVerify(BYTE ucBank, WORD usAddr)
{
    BYTE pucPasswordTable[sizeof(tFwPassword)];

    // Read BootTable data from Flash
    UserCommonFlashRead(ucBank, usAddr, sizeof(tFwPassword), pucPasswordTable);

    // Check user-defined user/boot code id
    if(memcmp(tFwPassword, pucPasswordTable, sizeof(tFwPassword)) == 0)
    {
        // Check success; return user bank address
        return _TRUE;
    }
    return _FALSE;
}

#endif // End #if(_FW_UPDATE_CHECK_TYPE == _FW_UPDATE_CHECK_PASSWORD)

#endif  // End #if(_FW_UPDATE_PROCESS_SUPPORT == _ON)

