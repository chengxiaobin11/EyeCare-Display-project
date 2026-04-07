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
// ID Code      : RL6463_Series_TMDSInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
#define CHECK_TMDS_DPHY_SWITCH(port)                (\
                                                        (((port) == _D0_INPUT_PORT) && (ScalerGetBit_EXINT(PB_B6_BANDGAP_02, (_BIT7)) == 0x00)) ||\
                                                        (((port) == _D1_INPUT_PORT) && (ScalerGetBit_EXINT(PB_B6_BANDGAP_02, (_BIT7)) == _BIT7))\
                                                    )
//--------------------------------------------------
// Macro of PHY Set Flag
//--------------------------------------------------
#define GET_TMDS_PHY_SET()                          (g_stTMDSRx0CtrlInfo.b1TMDSPhySet)
#define SET_TMDS_PHY_SET()                          (g_stTMDSRx0CtrlInfo.b1TMDSPhySet = _TRUE)
#define CLR_TMDS_PHY_SET()                          (g_stTMDSRx0CtrlInfo.b1TMDSPhySet = _FALSE)

//--------------------------------------------------
// Macro of TMDS Video Detecting Flag
//--------------------------------------------------
#define GET_TMDS_RGBHV_DETECTING()                  (g_stTMDSRx0CtrlInfo.b1RGBHVDetecting)
#define SET_TMDS_RGBHV_DETECTING()                  (g_stTMDSRx0CtrlInfo.b1RGBHVDetecting = _TRUE)
#define CLR_TMDS_RGBHV_DETECTING()                  (g_stTMDSRx0CtrlInfo.b1RGBHVDetecting = _FALSE)

//--------------------------------------------------
// Macro of Packet Detecting Flag
//--------------------------------------------------
#define GET_HDMI_PACKET_DETECTING()                 (g_stTMDSRx0CtrlInfo.b1PacketDetecting)
#define SET_HDMI_PACKET_DETECTING()                 (g_stTMDSRx0CtrlInfo.b1PacketDetecting = _TRUE)
#define CLR_HDMI_PACKET_DETECTING()                 (g_stTMDSRx0CtrlInfo.b1PacketDetecting = _FALSE)

//--------------------------------------------------
// Macro of AVI Info Frame Received Flag
//--------------------------------------------------
#define GET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED()      (g_stTMDSRx0CtrlInfo.b1AVIInfoFrameReceived)
#define SET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED()      (g_stTMDSRx0CtrlInfo.b1AVIInfoFrameReceived = _TRUE)
#define CLR_HDMI_RX0_AVI_INFO_FRAME_RECEIVED()      (g_stTMDSRx0CtrlInfo.b1AVIInfoFrameReceived = _FALSE)

//--------------------------------------------------
// Macro of GCP Received Flag
//--------------------------------------------------
#define GET_HDMI_GCP_RECEIVED()                     (g_stTMDSRx0CtrlInfo.b1GCPReceived)
#define SET_HDMI_GCP_RECEIVED()                     (g_stTMDSRx0CtrlInfo.b1GCPReceived = _TRUE)
#define CLR_HDMI_GCP_RECEIVED()                     (g_stTMDSRx0CtrlInfo.b1GCPReceived = _FALSE)

//--------------------------------------------------
// Macro of the Fiset Time of Z0 Asserted
//--------------------------------------------------
#define GET_TMDS_Z0_ASSERTED()                      (g_stTMDSRx0CtrlInfo.b1Z0Asserted)
#define SET_TMDS_Z0_ASSERTED()                      (g_stTMDSRx0CtrlInfo.b1Z0Asserted = _TRUE)
#define CLR_TMDS_Z0_ASSERTED()                      (g_stTMDSRx0CtrlInfo.b1Z0Asserted = _FALSE)

//--------------------------------------------------
// Macro of HPD Evnet Trigger
//--------------------------------------------------
#define GET_TMDS_RX0_HPD_TRIGGER_EVENT()            (g_stTMDSRx0CtrlInfo.b3HPDTriggerEvent)
#define SET_TMDS_RX0_HPD_TRIGGER_EVENT(x)           (g_stTMDSRx0CtrlInfo.b3HPDTriggerEvent = (x))
#define CLR_TMDS_RX0_HPD_TRIGGER_EVENT()            (g_stTMDSRx0CtrlInfo.b3HPDTriggerEvent = _TMDS_HPD_NONE)

#define GET_TMDS_RX1_HPD_TRIGGER_EVENT()            (g_stTMDSRx1CtrlInfo.b3HPDTriggerEvent)
#define SET_TMDS_RX1_HPD_TRIGGER_EVENT(x)           (g_stTMDSRx1CtrlInfo.b3HPDTriggerEvent = (x))
#define CLR_TMDS_RX1_HPD_TRIGGER_EVENT()            (g_stTMDSRx1CtrlInfo.b3HPDTriggerEvent = _TMDS_HPD_NONE)

#if(_HDMI_HPD_TOGGLE_BY_Z0_OFF_DDC_TOGGLE == _ON)
#define GET_TMDS_RX0_AC_ON_HPD_TOGGLE_EVENT()       (g_stTMDSRx0CtrlInfo.b1HdmiAcOnHpdToggleEvent)
#define SET_TMDS_RX0_AC_ON_HPD_TOGGLE_EVENT()       (g_stTMDSRx0CtrlInfo.b1HdmiAcOnHpdToggleEvent = _TRUE)
#define CLR_TMDS_RX0_AC_ON_HPD_TOGGLE_EVENT()       (g_stTMDSRx0CtrlInfo.b1HdmiAcOnHpdToggleEvent = _FALSE)

#define GET_TMDS_RX1_AC_ON_HPD_TOGGLE_EVENT()       (g_stTMDSRx1CtrlInfo.b1HdmiAcOnHpdToggleEvent)
#define SET_TMDS_RX1_AC_ON_HPD_TOGGLE_EVENT()       (g_stTMDSRx1CtrlInfo.b1HdmiAcOnHpdToggleEvent = _TRUE)
#define CLR_TMDS_RX1_AC_ON_HPD_TOGGLE_EVENT()       (g_stTMDSRx1CtrlInfo.b1HdmiAcOnHpdToggleEvent = _FALSE)
#endif

#define GET_TMDS_RX0_DDC_DETECTED()                 (g_stTMDSRx0CtrlInfo.b1TMDSDdcDetected)
#define SET_TMDS_RX0_DDC_DETECTED()                 (g_stTMDSRx0CtrlInfo.b1TMDSDdcDetected = _TRUE)
#define CLR_TMDS_RX0_DDC_DETECTED()                 (g_stTMDSRx0CtrlInfo.b1TMDSDdcDetected = _FALSE)

#define GET_TMDS_RX1_DDC_DETECTED()                 (g_stTMDSRx1CtrlInfo.b1TMDSDdcDetected)
#define SET_TMDS_RX1_DDC_DETECTED()                 (g_stTMDSRx1CtrlInfo.b1TMDSDdcDetected = _TRUE)
#define CLR_TMDS_RX1_DDC_DETECTED()                 (g_stTMDSRx1CtrlInfo.b1TMDSDdcDetected = _FALSE)

#if(_MHL_SUPPORT == _ON)
#define GET_TMDS_RX0_CLK_MODE()                     (g_ucTMDSClkMode)
#define SET_TMDS_RX0_CLK_MODE(x)                    (g_ucTMDSClkMode = (x))
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructTMDSCtrlInfo g_stTMDSRx0CtrlInfo;
extern StructTMDSCtrlInfo g_stTMDSRx1CtrlInfo;
extern WORD g_usTMDSClkCount;

#if(_D0_TMDS_SUPPORT == _ON)
extern BYTE g_ucTMDSRx0Z0Status;
#endif
#if(_D1_TMDS_SUPPORT == _ON)
extern BYTE g_ucTMDSRx1Z0Status;
#endif

#if(_MHL_SUPPORT == _ON)
extern BYTE g_ucTMDSClkMode;
#endif

#if(_HDCP_2_2_SUPPORT == _ON)
extern BYTE g_pucRxCaps[3];
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerTMDSInitial(BYTE ucInputPort);
extern void ScalerTMDSInterruptInitial(BYTE ucInputPort);
extern void ScalerTMDSSetDeOnlyModeConfig(EnumSourceSearchPort enumSourceSearchPort, EnumDeOnlyConfig enumDeonlyConfig);
extern EnumDeOnlyConfig ScalerTMDSGetDeOnlyModeConfig(EnumSourceSearchPort enumSourceSearchPort);
extern void ScalerTMDSRx0SetPorchColor(EnumColorSpace enumColorFormat);

#if(_HDMI_SUPPORT == _ON)
extern void ScalerTMDSHdmiAVMuteProc(void);
#endif

extern void ScalerTMDSMacDdcSwitchCtrl(BYTE ucInputPort);
extern void ScalerTMDSPowerSavingProc(BYTE ucPortSelect);
extern void ScalerTMDSPowerOffProc(void);
extern void ScalerTMDSFirstActiveProc(BYTE ucInputPort, BYTE ucSourceType);
extern bit ScalerTMDSHdcpEnabled(BYTE ucInputPort);
extern void ScalerTMDSHotPlugEvent(BYTE ucPortSelect);
extern void ScalerTMDSSwitchHdcpSlaveAddr(BYTE ucPortSelect);
extern void ScalerTMDSBeforeHotPlugEventProc(BYTE ucPortSelect, bit bDisableZ0);
extern void ScalerTMDSAfterHotPlugEventProc(BYTE ucPortSelect, bit bRestoreZ0);

#if(_TMDS_CLK_INTERRUPTION_CHECK == _ON)
extern bit ScalerTMDSClkInterruptionCheck(void);
#endif

#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
