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
// ID Code      : RL6851_Series_OTPInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//-------------------------------------------------
// OTP Mapping Data
//-------------------------------------------------

// OTPfuse Total Bank Number
#define _HW_OTPFUSE_TOTAL_BANK_NUM                     (1)

// OTPfuse IP Start Address
#define _HW_OTPFUSE_CHECK_EMPTY_STR                    (404)
#define _HW_OTPFUSE_HDCP14_RXKEYBKSV_STR               (0)
#define _HW_OTPFUSE_HDCP14_RXKEY_STR                   (5)
#define _HW_OTPFUSE_LVDS_IBHN_STR                      (428)
#define _HW_OTPFUSE_HVS_STR                            (429)
#define _HW_OTPFUSE_DP_AUX_RX_MODE_STR                 (430)
#define _HW_OTPFUSE_EDP_AUX_TX_MODE_STR                (431)
#define _HW_OTPFUSE_VCCK_LDO_STR                       (470)

// OTPfuse IP Length
#define _HW_OTPFUSE_CHECK_EMPTY_LEN                    (1)
#define _HW_OTPFUSE_HDCP14_RXKEY_LEN                   (320)
#define _HW_OTPFUSE_HDCP14_RXKEYBKSV_LEN               (5)
#define _HW_OTPFUSE_LVDS_IBHN_LEN                      (1)
#define _HW_OTPFUSE_HVS_LEN                            (1)
#define _HW_OTPFUSE_DP_AUX_RX_MODE_LEN                 (1)
#define _HW_OTPFUSE_EDP_AUX_TX_MODE_LEN                (1)
#define _HW_OTPFUSE_VCCK_LDO_LEN                       (1)


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
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

//--------------------------------------------------
// Enumerations of OTPfuse Data State
//--------------------------------------------------
typedef struct
{
    EnumOTPMemoryData enumDataId;
    WORD usAddress;
    WORD usLength;
} StructOTPMapping;

//-------------------------------------------------
// OTPfuse Bit Mode
//-------------------------------------------------
typedef enum
{
    _HW_OTPFUSE_16BIT = 0x00,
    _HW_OTPFUSE_8BIT = 0x01,
} EnumOTPfuseBitMode;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern bit ScalerOTPFuseReadData(EnumOTPMemoryData enumOTPMemoryData, BYTE *pucOTPfuseGetData);
