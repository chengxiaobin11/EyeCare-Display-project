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
// ID Code      : RL6851_Series_ScalerCommonDebugInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_SMBUS_BLOCK_READ_WRITE_COMMAND_SUPPORT == _ON)
#define _SMBUS_BLOCK_READ_WRITE_EXIT_TIMER_COUNT                 60000
#endif

// Switch to FwUpdae command Define
#if(_FW_UPDATE_PROCESS_SUPPORT == _ON)
#define _SCALER_FW_UPDATE_CMD                                    0x31
#endif

#if(_DUAL_BANK_DEBUG_SUPPORT == _ON)
// True : DDCCI  Swicth to Debug Mode; Ignore OSD Falg.
// FALSE :  Refer to OSD Flag
#define GET_DDCCI_SWITCH_STATE()                                 (g_bDdcciSwitchState)
#define SET_DDCCI_SWITCH_STATE()                                 (g_bDdcciSwitchState = _TRUE)
#define CLR_DDCCI_SWITCH_STATE()                                 (g_bDdcciSwitchState = _FALSE)
#endif

//--------------------------------------------------
// Macros of SMbus Block Read/Write
//--------------------------------------------------
#if(_SMBUS_BLOCK_READ_WRITE_COMMAND_SUPPORT == _ON)
#define SET_SMBUS_BLOCK_RW_STATUS(x)                             (g_stSmbusBlockRWCmd.b1SmbusEnable = (x))
#define GET_SMBUS_BLOCK_RW_STATUS()                              (g_stSmbusBlockRWCmd.b1SmbusEnable)
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_DUAL_BANK_DEBUG_SUPPORT == _ON)
extern bit g_bDdcciSwitchState;
#endif

#if(_SMBUS_BLOCK_READ_WRITE_COMMAND_SUPPORT == _ON)
extern StructSmbusBlockRWCmd g_stSmbusBlockRWCmd;
#endif


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDebugSelectDDCCIDebugMode(EnumDDCCIDebugMode enumMode);
extern EnumDDCCIDebugMode ScalerDebugGetDDCCIDebugMode(void);

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
extern bit ScalerDebugCheckDebugPort(BYTE ucInputPort);
#endif

extern void ScalerDebug(void);

#if((_DUAL_BANK_SUPPORT == _ON) || (_DIGITAL_SIGNATURE_SUPPORT == _ON))
extern void ScalerDebugDualBankSetDebugInfo(BYTE ucRevCmd, BYTE ucOpCode, BYTE ucSubOpCode);
extern BYTE ScalerDebugDualBankGetDebugInfo(BYTE *pucOpCode, BYTE *pucSubOpCode);
#endif


