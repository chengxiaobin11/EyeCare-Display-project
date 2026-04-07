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
// ID Code      : UserCommonDualBankUserInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_DUAL_BANK_DEBUG_SUPPORT == _ON)

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _DUAL_BANK_STATE_NONE = 0,
    _DUAL_BANK_STATE_RUN,
    _DUAL_BANK_STATE_VERIFY,
    _DUAL_BANK_STATE_WAIT_SWITCH,
    _DUAL_BANK_STATE_SWITCH,
    _DUAL_BANK_STATE_COPY,
}EnumDualBankState;


typedef enum
{
    _USER_ILLEGAL = 0,
    _USER_VALID,
    _USER_INVALID,
    _USER_VERIFY,
    _USER_WAIT_SWITCH,
    _USER_SWITCH,
    _USER_COPY,
}EnumDualBankUserStatus;

typedef enum
{
    _VERIFY_RESULT_PASS = 0,
    _VERIFY_RESULT_FAIL,
}EnumDualBankVerifyResult;

typedef enum
{
    _COPY_RESULT_PASS = 0,
    _COPY_RESULT_FAIL,
}EnumDualBankCopyResult;

typedef enum
{
    _REGION_NONE = 0,
    _REGION_BOOT,
    _REGION_USER_I,
    _REGION_USER_II,
}EnumDualBankCodeRegion;

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************


//****************************************************************************
// INTERFACE  FUNCTION EXTERN
//****************************************************************************
extern void UserCommonDualBankUserDebug(void);

#if(_ISP_CHANNEL_PROTECT_SUPPORT == _ON)
extern void UserCommonDualBankUserSetISPChannel(WORD usISPChannel);
extern void UserCommonDualBankUserSetISPSlaveAddr(EnumIspSlaveAddrState enumISPStatus);
#endif

#endif
