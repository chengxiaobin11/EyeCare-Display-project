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
// ID Code      : RL6851_Series_ScalerCommonTimerFunctionInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern bit g_bNotifyTimer2Int;
extern volatile WORD data g_usTimerCounter;

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
extern volatile WORD data g_usMeasureCounter;
#endif

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern bit g_bWDTimer2Update;
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
extern BYTE data g_ucTimerQuarterCount;
#endif

#if(_INSTANT_TIMER_EVENT_0 == _ON)
extern BYTE g_ucTimerCountHByte0;
extern BYTE g_ucTimerCountLByte0;
extern WORD g_usTimerEventPeriod0;
extern WORD g_usTimerAxisCnt0;
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
extern BYTE g_ucTimerCountHByte1;
extern BYTE g_ucTimerCountLByte1;
extern WORD g_usTimerEventPeriod1;
extern WORD g_usTimerAxisCnt1;
#endif

#if(_UART_SUPPORT == _ON)
#if(_UART_LOW_BAUD_RATE_SUPPORT == _ON)
extern BYTE g_ucTimerCountHByte1_Uart;
extern BYTE g_ucTimerCountLByte1_Uart;
#endif
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_WD_TIMER_INT_SUPPORT == _ON)
extern void ScalerTimerWDEventProc_WDINT(void);
#endif

#if(_INSTANT_TIMER_EVENT_0 == _ON)
extern void ScalerTimer0SetTimerCount(WORD usTimerMs);
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
extern void ScalerTimer1SetTimerCount(WORD usTimerMs);
#endif

extern void ScalerTimerSetTimerCount(EnumScalerTimerOperationMode enumOperationMode);

#if(_SYSTEM_LOW_POWER_IDLE_SUPPORT == _ON)
extern void ScalerTimerAddTimerCounter(void);
#endif

extern void ScalerTimerEventProc(EnumScalerTimerEventID enumEventID);
extern WORD ScalerTimerGetEventTime(BYTE ucEventIndex);
extern void ScalerTimerClrEventValid(BYTE ucEventIndex);
extern bit ScalerTimerCheckEventValid(BYTE ucEventIndex);
extern void ScalerTimerActiveTimerEvent(WORD usTime, EnumScalerTimerEventID enumEventID);
extern void ScalerTimerReactiveTimerEvent(WORD usTime, EnumScalerTimerEventID enumEventID);
extern void ScalerTimerCancelTimerEvent(EnumScalerTimerEventID enumEventID);
extern WORD ScalerTimerGetEventRemainTime(EnumScalerTimerEventID enumEventID);
extern bit ScalerTimerSearchActiveTimerEvent(EnumScalerTimerEventID enumEventID);

#if(((_DDCCI_CODE_REDUCTION == _OFF) && (_DEBUG_MESSAGE_SUPPORT == _OFF) && (_DDCCI_AUTO_SWITCH_SUPPORT == _ON)) || (_SMBUS_BLOCK_READ_WRITE_COMMAND_SUPPORT == _ON))
extern void ScalerTimerCancelTimerEvent_EXINT1(EnumScalerTimerEventID enumEventID);
#endif

extern WORD ScalerTimerGetTimerCounter(void);
extern BYTE ScalerTimerGetEventID(BYTE ucEventIndex);
extern void ScalerTimerInitialTimerEvent(void);
extern void ScalerTimerDelayXms(WORD usNum);

#if((_HDCP_2_2_SUPPORT == _ON) || (_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON))
extern BYTE ScalerTimerPollingFlagProc_EXINT0(BYTE ucTimeout, WORD usRegister, BYTE ucBit, bit bSuccess);
#endif

extern void ScalerTimerWaitForActiveTimerEvent(EnumScalerTimerEventID enumEventID);

