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
// ID Code      : ScalerCommonFwCheckInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_ISP_FW_CHECK_PROJECT_ID_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _SCALER_FW_CHECK_CMD                                    0xCB
#define _SCALER_FW_CHECK_SUB_OP_GET_ADDR                        0x01
#define _SCALER_FW_CHECK_SUB_OP_VERIFY                          0x02

#define _ISP_FW_CHECK_COMMAND_BUF_LEN                           0x10

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
//--------------------------------------------------
// Enumerations of Project ID Verify Result
//--------------------------------------------------
typedef enum
{
    _ISP_FW_CHECK_VERIFY_FAIL = _FALSE,
    _ISP_FW_CHECK_VERIFY_SUCCESS = _TRUE,
} EnumProjectIDVerifyResult;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern EnumProjectIDVerifyResult ScalerFwCheckProjectIDVerify(BYTE *pucBuf);
extern void ScalerFwCheckGetProjectIDAddress(BYTE *pucArray);

#endif // End of #if(_ISP_FW_CHECK_PROJECT_ID_SUPPORT == _ON)

