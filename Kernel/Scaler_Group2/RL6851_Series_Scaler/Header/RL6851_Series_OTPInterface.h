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
// ID Code      : RL6851_Series_OTPInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// OTPMemory type
//--------------------------------------------------
typedef enum
{
    _OTPMEMORY_CHECK_EMPTY = 0x00,
    _OTPMEMORY_HDCP14_RXKEY,
    _OTPMEMORY_HDCP14_RXKEYBKSV,
    _OTPMEMORY_LVDS_IBHN,
    _OTPMEMORY_HVS,
    _OTPMEMORY_DP_AUX_RX_MODE,
    _OTPMEMORY_EDP_AUX_TX_MODE,
    _OTPMEMORY_VCCK_LDO,
    _EFUSE_NONE = _OTPMEMORY_CHECK_EMPTY,
} EnumOTPMemoryData;

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************

