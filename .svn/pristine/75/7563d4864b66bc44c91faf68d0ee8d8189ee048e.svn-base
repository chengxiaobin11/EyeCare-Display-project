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
// ID Code      : UserCommonFwUpdateBackgroundInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_FW_UPDATE_BACKGROUND_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _BACKGROUND_FW_UPDATE_SLAVE_ADDRESS                     0x3A
// Sub Address
#define _BACKGROUND_FW_UPDATE_CMD_SUB_ADDREESS                  0x31
#define _BACKGROUND_FW_UPDATE_ISP_DATA_SUB_ADDRESS              0x32
/// Op Code
#define _BACKGROUND_FW_UPDATE_OPCODE_START_REQ                  0x01
#define _BACKGROUND_FW_UPDATE_OPCODE_FINISH_REQ                 0x02
#define _BACKGROUND_FW_UPDATE_OPCODE_GET_ACFWVER_REQ            0x03
#define _BACKGROUND_FW_UPDATE_OPCODE_EXIT_REQ                   0x04
#define _BACKGROUND_FW_UPDATE_OPCODE_GET_PROJECT_ID_ADDR_REQ    0x05
#define _BACKGROUND_FW_UPDATE_OPCODE_VERIFY_PROJECT_ID_REQ      0x06
#define _BACKGROUND_FW_UPDATE_OPCODE_SET_DATA_LEN_REQ           0x07

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _FW_UPDATE_START = 0x00,
    _FW_UPDATE_END
} EnumBackgroundFwUpdateStatus;


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern bit UserCommonFwUpdateBackgroundHandler(void);

#endif

