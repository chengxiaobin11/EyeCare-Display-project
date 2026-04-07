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
// ID Code      : RL6369_Series_MHLInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_MHL_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of MHL Port Valid
//--------------------------------------------------
#define _MHL_PORT_VALID                                 ((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) + (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT) + (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))

//--------------------------------------------------
// Macros of MHL Adopter ID
//--------------------------------------------------
#define GET_MHL_RX0_ADOPTER_ID_HBYTE()                  (g_ucMHLRx0AdopterIDH)
#define GET_MHL_RX0_ADOPTER_ID_LBYTE()                  (g_ucMHLRx0AdopterIDL)
#define CLR_MHL_RX0_ADOPTER_ID_HBYTE()                  (g_ucMHLRx0AdopterIDH = 0xFF)
#define CLR_MHL_RX0_ADOPTER_ID_LBYTE()                  (g_ucMHLRx0AdopterIDL = 0xFF)

#define GET_MHL_RX1_ADOPTER_ID_HBYTE()                  (g_ucMHLRx1AdopterIDH)
#define GET_MHL_RX1_ADOPTER_ID_LBYTE()                  (g_ucMHLRx1AdopterIDL)
#define CLR_MHL_RX1_ADOPTER_ID_HBYTE()                  (g_ucMHLRx1AdopterIDH = 0xFF)
#define CLR_MHL_RX1_ADOPTER_ID_LBYTE()                  (g_ucMHLRx1AdopterIDL = 0xFF)

#define GET_MHL_RX2_ADOPTER_ID_HBYTE()                  (g_ucMHLRx2AdopterIDH)
#define GET_MHL_RX2_ADOPTER_ID_LBYTE()                  (g_ucMHLRx2AdopterIDL)
#define CLR_MHL_RX2_ADOPTER_ID_HBYTE()                  (g_ucMHLRx2AdopterIDH = 0xFF)
#define CLR_MHL_RX2_ADOPTER_ID_LBYTE()                  (g_ucMHLRx2AdopterIDL = 0xFF)

#define GET_MHL_PROCESS_STATE(x)                        (g_pstMHLProcess[x].b4MHLProcessState)
#define SET_MHL_PROCESS_STATE(x, y)                     (g_pstMHLProcess[x].b4MHLProcessState = (y))

#define GET_MHL_READY_TO_TRANSMIT(x)                    (g_pstMHLProcess[x].b1MHLTransmitStatus)
#define SET_MHL_READY_TO_TRANSMIT(x, y)                 (g_pstMHLProcess[x].b1MHLTransmitStatus = (y))

#define GET_MHL_SWITCH_PORT_DISCOVERY_DONE(x)           (g_pstMHLProcess[x].b1MHLSwitchPortDiscoveryDoneStatus)
#define SET_MHL_SWITCH_PORT_DISCOVERY_DONE(x, y)        (g_pstMHLProcess[x].b1MHLSwitchPortDiscoveryDoneStatus = (y))

#define GET_MHL_PORT_ACTIVE()                           (g_ucMHLPortActive)
#define SET_MHL_PORT_ACTIVE(x)                          (g_ucMHLPortActive = (x))

#define _MHL_MSC_COMMAND_POLLING_MESSAGE                _OFF
//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
extern BYTE g_ucMHLRx0AdopterIDH;
extern BYTE g_ucMHLRx0AdopterIDL;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
extern BYTE g_ucMHLRx1AdopterIDH;
extern BYTE g_ucMHLRx1AdopterIDL;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
extern BYTE g_ucMHLRx2AdopterIDH;
extern BYTE g_ucMHLRx2AdopterIDL;
#endif

extern StructMHLProcessInfo g_pstMHLProcess[_MHL_PORT_VALID];
extern BYTE g_ucMHLPortActive;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerMHLCBUSPhySwitch(BYTE ucPortSelect, bit bSelect);
extern void ScalerMHLCBUSResetProc(BYTE ucInputPort);
extern void ScalerMHLPowerOffProc(BYTE ucInputPort);

extern bit ScalerMHLDetectClkMode(void);
extern BYTE ScalerMHLDetectClkMode_EXINT0(void);

extern bit ScalerMHLMscSendCommand(BYTE ucInputPort, EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue);
extern bit ScalerMHLMscSendWriteBurst(BYTE ucInputPort, BYTE ucOffset, BYTE ucDataLength, BYTE *pucData, EnumMHLWriteBurstMode enumMode);
extern void ScalerMHLSetDevCapReg(void);
extern void ScalerMHLTimerEventProc(EnumScalerTimerEventID enumEventID);

#endif // End of #if(_MHL_SUPPORT == _ON)
