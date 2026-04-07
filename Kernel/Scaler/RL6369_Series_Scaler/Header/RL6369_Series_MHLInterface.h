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
// ID Code      : RL6369_Series_MHLInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_MHL_SUPPORT == _ON)

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerMHLModeMHLSetting(BYTE ucInputPort);
extern void ScalerMHLModeHdmiSetting(BYTE ucInputPort);
extern void ScalerMHLInitialSettings(void);
extern void ScalerMHLCBUSPhySwitch(BYTE ucPortSelect, bit bSelect);
extern void ScalerMHLCBUSSwitchClk(EnumClkSel enumClockSel);
extern void ScalerMHLCBUSResetProc(BYTE ucInputPort);
extern void ScalerMHLIntHandler_EXINT0(void);
extern bit ScalerMHLMscSendCommand(BYTE ucInputPort, EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue);
extern void ScalerMHLMscCheckDeviceINT(BYTE ucInputPort);
extern bit ScalerMHLMscHandler(BYTE ucInputPort, BYTE ucActivePort, BYTE ucModeState);
extern bit ScalerMHLMscRAPHandler(BYTE ucInputPort);
extern bit ScalerMHLMscRCPGetCommand(BYTE ucInputPort, BYTE *pucKeyCode);

#if(_MHL_UCP_SUPPORT == _ON)
extern BYTE ScalerMHLMscUCPGetCommand(BYTE ucInputPort, BYTE *pucKeyCode);
#endif

extern bit ScalerMHLPSPreDetect(BYTE ucInputPort);
extern bit ScalerMHLNormalPreDetect(BYTE ucInputPort);

#endif  // End of #if(_MHL_SUPPORT == _ON)

