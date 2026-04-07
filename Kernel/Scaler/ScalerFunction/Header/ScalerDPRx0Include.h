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
// ID Code      : ScalerDPRx0Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_DP_HDCP14_REPEATER_BIT_DISABLE_FOR_TX_CLONE_OFF == _ON)
#define GET_DP_RX0_HDCP14_REPEATER_SUPPORT()            (g_bDpRx0HdcpRepeaterBit)
#define SET_DP_RX0_HDCP14_REPEATER_SUPPORT(x)           (g_bDpRx0HdcpRepeaterBit = (x))
#endif


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern BYTE g_ucDpRx0Tp1PermitSwingLevel0;

#if(_DP_LT_TP2_RETRY_FOR_S2P1_S3P0 == _ON)
extern BYTE g_pucDpRx0MaxSwing[4];
#endif

#if(_DP_HDCP14_REPEATER_BIT_DISABLE_FOR_TX_CLONE_OFF == _ON)
extern bit g_bDpRx0HdcpRepeaterBit;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D0_DP_EXIST == _ON)
extern void ScalerDpRx0AuxWaitRcv_EXINT0(void);
extern void ScalerDpRx0ErrorCounterUpdate_EXINT0(void);
extern void ScalerDpRx0ErrorCounterDisable_EXINT0(void);
extern void ScalerDpRx0ErrorCounterEnable_EXINT0(EnumDpLinkTrainingType enumDpLtType);
extern void ScalerDpRx0AVMute(void);
extern void ScalerDpRx0ScrambleSetting(void);

#if((_DP_ILLEGAL_IDLE_PATTERN_CHECK_SUPPORT == _ON) && (_HW_DP_LANE_VALID_CHECK_SUPPORT == _ON))
extern bit ScalerDpRx0LaneValidCheck(void);
#endif

extern void ScalerDpRx0CheckHdcpCpirqStatus(void);
extern void ScalerDpRx0CrcCalculate(void);

#if(_DP_DYNAMIC_ADJUST_LINK_RATE_SUPPORT == _ON)
extern void ScalerDpRx0CalculateLinkRate(EnumDpLaneCount enumDpLaneCount);
#endif

#if(_HW_HS_TRACKING_GEN_TYPE == _HS_TRACKING_GEN_2)
extern void ScalerDpRx0HSActiveTrackingMode(EnumDpHSTrackingType enumHSTrackingType);
#endif
extern BYTE ScalerDpRx0GetDpcdBitInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern BYTE ScalerDpRx0GetDpcdInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern bit ScalerDpRx0GetVideoStream(void);
extern bit ScalerDpRx0MSAActiveChange(void);
extern void ScalerDpRx0SecDataBlockReset(void);
extern void ScalerDpRx0SetDpcdBitValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
extern void ScalerDpRx0SetDpcdValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpRx0SetDpcdWrite1ClearValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpRx0DpcdGroupReset(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, WORD usLen);
extern void ScalerDpRx0DpcdLinkConfigReset(void);
extern void ScalerDpRx0DpcdSourceOUIReset(void);
extern void ScalerDpRx0SetSinkDeviceSpecificField(EnumDpVersionType enumDpVersion);

extern void ScalerDpRx0SinkStatusSet(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);
extern void ScalerDpRx0ChangeHdcpDpcdCapability(bit bEn);

#if(_DP_RX0_ASSR_MODE_SUPPORT == _ON)
extern void ScalerDpRx0ASSRModeSetting(void);
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
extern bit ScalerDpRx0GetFREESYNCStatusChange(void);
extern WORD ScalerDpRx0SetFREESYNCMsaForLut(WORD usDpHtotal);
#if(_FW_DP_RX_H_PORCH_ENLARGE_SUPPORT == _ON)
extern WORD ScalerDpRx0FreesyncHPorchEnlarge(WORD usDpHtotal);
#endif
#endif

#endif
