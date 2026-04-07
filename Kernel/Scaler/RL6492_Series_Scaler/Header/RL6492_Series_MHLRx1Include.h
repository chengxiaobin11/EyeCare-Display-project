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
// ID Code      : RL6492_Series_MHLRx1Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Macros of MHL Adopter ID
//--------------------------------------------------
#define GET_MHL_RX1_ADOPTER_ID_HBYTE()                  (g_ucMHLRx1AdopterIDH)
#define GET_MHL_RX1_ADOPTER_ID_LBYTE()                  (g_ucMHLRx1AdopterIDL)
#define CLR_MHL_RX1_ADOPTER_ID_HBYTE()                  (g_ucMHLRx1AdopterIDH = 0xFF)
#define CLR_MHL_RX1_ADOPTER_ID_LBYTE()                  (g_ucMHLRx1AdopterIDL = 0xFF)

#define GET_MHL_RX1_PROCESS_STATE()                     (g_stMHLRx1Process.b4MHLProcessState)
#define SET_MHL_RX1_PROCESS_STATE(x)                    (g_stMHLRx1Process.b4MHLProcessState = (x))

#define GET_MHL_RX1_READY_TO_TRANSMIT()                 (g_stMHLRx1Process.b1MHLTransmitStatus)
#define SET_MHL_RX1_READY_TO_TRANSMIT()                 (g_stMHLRx1Process.b1MHLTransmitStatus = _TRUE)
#define CLR_MHL_RX1_READY_TO_TRANSMIT()                 (g_stMHLRx1Process.b1MHLTransmitStatus = _FALSE)

#define GET_MHL_RX1_READY_TO_RESEND()                   (g_stMHLRx1Process.b1MHLResendStatus)
#define SET_MHL_RX1_READY_TO_RESEND()                   (g_stMHLRx1Process.b1MHLResendStatus = _TRUE)
#define CLR_MHL_RX1_READY_TO_RESEND()                   (g_stMHLRx1Process.b1MHLResendStatus = _FALSE)

#define GET_MHL_RX1_SWITCH_PORT_DISCOVERY_DONE()        (g_stMHLRx1Process.b1MHLSwitchPortDiscoveryDoneStatus)
#define SET_MHL_RX1_SWITCH_PORT_DISCOVERY_DONE()        (g_stMHLRx1Process.b1MHLSwitchPortDiscoveryDoneStatus = _TRUE)
#define CLR_MHL_RX1_SWITCH_PORT_DISCOVERY_DONE()        (g_stMHLRx1Process.b1MHLSwitchPortDiscoveryDoneStatus = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern BYTE g_ucMHLRx1AdopterIDH;
extern BYTE g_ucMHLRx1AdopterIDL;
extern StructMHLProcessInfo g_stMHLRx1Process;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMHLRx1ModeMHLSetting(void);
extern void ScalerMHLRx1ModeHdmiSetting(void);
extern void ScalerMHLRx1InitialSettings(void);
extern void ScalerMHLRx1CBUSPhySwitch(bit bSelect);
extern void ScalerMHLRx1CBUSSwitchClk(EnumClkSel enumClockSel);
extern void ScalerMHLRx1CBUSResetProc(void);
extern void ScalerMHLRx1PowerOffProc(void);
extern bit ScalerMHLRx1DetectClkMode(void);
extern BYTE ScalerMHLRx1DetectClkMode_EXINT0(void);
extern void ScalerMHLRx1IntHandler_EXINT0(void);
extern bit ScalerMHLRx1MscSendCommand(EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue);
extern bit ScalerMHLRx1MscSendWriteBurst(BYTE ucOffset, BYTE ucDataLength, BYTE *pucData, EnumMHLWriteBurstMode enumMode);
extern void ScalerMHLRx1MscCheckDeviceINT(void);

extern void ScalerMHLRx1SetDevCapReg(void);
extern bit ScalerMHLRx1MscHandler(BYTE ucActivePort, BYTE ucModeState);
extern bit ScalerMHLRx1MscRAPHandler(void);
extern bit ScalerMHLRx1MscRCPGetCommand(BYTE *pucKeyCode);

#if(_MHL_UCP_SUPPORT == _ON)
extern BYTE ScalerMHLRx1MscUCPGetCommand(BYTE *pucKeyCode);
#endif

extern bit ScalerMHLRx1PSPreDetect(void);
extern bit ScalerMHLRx1NormalPreDetect(void);
extern void ScalerMHLRx1TimerEventProc(EnumScalerTimerEventID enumEventID);

#endif  // End of #if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

