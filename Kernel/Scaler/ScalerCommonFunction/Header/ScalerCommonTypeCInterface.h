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

#if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// ID Code      : ScalerCommonTypeCInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)
#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
#define GET_TYPE_C_5400_LENOVO_ALT_MODE_URGENT_EVENT()      (g_bTypeC5400LenovoAltModeUrgentEvent)
#define SET_TYPE_C_5400_LENOVO_ALT_MODE_URGENT_EVENT()      (g_bTypeC5400LenovoAltModeUrgentEvent = _TRUE)
#define CLR_TYPE_C_5400_LENOVO_ALT_MODE_URGENT_EVENT()      (g_bTypeC5400LenovoAltModeUrgentEvent = _FALSE)
#endif
#endif

//****************************************************************************
// INTERFACE STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)
#if((_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON) && (_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE))
extern bit g_bTypeC5400LenovoAltModeUrgentEvent;
#endif
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerTypeCSetAltModeReady(BYTE ucInputPort, EnumTypeCAltModeStatus enumAltModeStatus);
extern EnumTypeCAltModeStatus ScalerTypeCRxGetAltModeReady(BYTE ucInputPort);
extern void ScalerTypeCSetExplicitContract(BYTE ucInputPort, bit bGetExplicitContract);
extern bit ScalerTypeCRxGetExplicitContract(BYTE ucInputPort);
extern EnumTypeCPortCtrlType ScalerTypeCGetPortCtrlType(BYTE ucInputPort);

#if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
#if(_TYPE_C_POWER_SOURCE == _TYPE_C_VBUS_POWER_ONLY)
extern void ScalerTypeCVbusPoweredSnkInitial(BYTE ucInputPort);
#endif
extern void ScalerTypeCHandler(BYTE ucInputPort);
extern EnumTypeCAttachStatus ScalerTypeCGetCcAttach(BYTE ucInputPort);
#if(_USB3_RETIMER_SUPPORT == _ON)
extern EnumTypeCAttachStatus ScalerTypeCSearchCcAttach(void);
#endif
extern EnumTypeCAltModeStatus ScalerTypeCGetAltModeReady(BYTE ucInputPort);
extern EnumTypeCOrientation ScalerTypeCGetOrientation(BYTE ucInputPort);
extern bit ScalerTypeCGetPinAssignment(BYTE ucInputPort, EnumTypeCPinCfgType *penumPinAssignment);
extern bit ScalerTypeCGetMultiFunctionChangeDone(BYTE ucInputPort);
extern StructTypeCCableInfoForDpcd ScalerTypeCGetCableInfoForDpcd(BYTE ucInputPort);
extern EnumTypeCDataRole ScalerTypeCGetDataRole(BYTE ucInputPort);
extern EnumTypeCPowerRole ScalerTypeCGetPowerRole(BYTE ucInputPort);
extern bit ScalerTypeCGetExplicitContract(BYTE ucInputPort);
extern bit ScalerTypeCReconnect(BYTE ucInputPort);
extern void ScalerTypeCWaitDpConfigUpdate(BYTE ucInputPort);
extern bit ScalerTypeCUpdateConfig(BYTE ucInputPort, EnumTypeCMultiFuncStatus enumMultiFunc, EnumTypeCPinCfgCapType enumPinAssignmentCap);
extern void ScalerTypeCIntHandler_EXINT0(void);
extern void ScalerTypeCPowerSwitch(EnumPowerAction enumPowerAction);
extern void ScalerTypeCSetPdoByKernel(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole);
extern void ScalerTypeCSetMaxPower(BYTE ucInputPort, WORD usMaxPower);
extern void ScalerTypeCSetSnkInfo(BYTE ucInputPort, StructTypeCSnkInfo stTypeCSnkInfo);
extern void ScalerTypeCSetStatusEvent(BYTE ucInputPort, StructTypeCStatusEvent stTypeCStatusEvent);
extern void ScalerTypeCSetAlertEvent(BYTE ucInputPort, StructTypeCAlertEvent stTypeCAlertEvent);
extern void ScalerTypeCSetPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucSPRPdoCnt, BYTE ucEPRPdoCnt);
extern BYTE ScalerTypeCGetPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE *pucSPRPdoCnt, BYTE *pucEPRPdoCnt);
extern StructTypeCUserPDO ScalerTypeCGetPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex);
extern BYTE ScalerTypeCGetPartnerPdoCnt(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole);
extern StructTypeCUserPDO ScalerTypeCGetPartnerPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex);
extern StructTypeCStatusEvent ScalerTypeCGetPartnerStatusInfo(BYTE ucInputPort);
extern StructTypeCAlertEvent ScalerTypeCGetPartnerAlertInfo(BYTE ucInputPort);
extern void ScalerTypeCGetPdoStatus(BYTE ucInputPort, WORD *pusVoltage, WORD *pusCurrent);
extern StructTypeCUserPDO ScalerTypeCGetRequestedSrcPdo(BYTE ucInputPort);
extern void ScalerTypeCSetFixPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex, WORD usVoltage, WORD usMaxCur, EnumPDPeakCurType enumPeakCur);
#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
extern void ScalerTypeCSetPpsPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex, WORD usMinVol, WORD usMaxVol, BYTE ucMaxCur);
#endif
extern void ScalerTypeCSetAvsPdo(BYTE ucInputPort, EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex, WORD usMinVol, WORD usMaxVol, EnumPDPeakCurType enumPeakCur);
extern void ScalerTypeCSetInitRdo(BYTE ucInputPort, StructTypeCUserInitRDO stTypeCUserInitRdo);
extern void ScalerTypeCSetRdo(BYTE ucInputPort, StructTypeCUserRDO stTypeCUserRdo);
extern void ScalerTypeCSetUnconstrainedPow(BYTE ucInputPort, EnumTypeCUnconstrainPowerExist enumTypeCUnconstrainPowerExist);
#if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
extern void ScalerTypeCSetProtectInfo(BYTE ucInputPort, BYTE ucPdoIndex, StructTypeCUserProtectInfo stTypeCUserProtectInfo);
#endif
extern EnumTypeCUFPProductType ScalerTypeCGetUFPProductType(BYTE ucInputPort);
extern EnumTypeCDFPProductType ScalerTypeCGetDFPProductType(BYTE ucInputPort);
extern void ScalerTypeCSetPdSystemEvent(BYTE ucInputPort, EnumPDSysEvent enumPdSysEvent);
extern EnumPDPortCtrlEvent ScalerTypeCGetPortCtrlEvent(BYTE ucInputPort);
extern void ScalerTypeCClrPortCtrlEvent(BYTE ucInputPort, EnumPDPortCtrlEvent enumPdPortCtrlEvent);
extern bit ScalerTypeCPowerControl(BYTE ucInputPort, EnumTypeCPowerControlStatus enumPowerControlStatus);
extern void ScalerTypeCCcFunctionControl(BYTE ucInputPort, EnumTypeCCcFunction enumCcFunction);
extern void ScalerTypeCSetFunctionSupport(BYTE ucInputPort, EnumTypeCFunctionSupport enumFunctionSupport);
extern void ScalerTypeCSetOperationMode(BYTE ucInputPort, EnumTypeCOperationMode enumOperationMode);
extern StructTypeCDpStatusInfo ScalerTypeCGetDpStatusInfo(BYTE ucInputPort);
#if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE)
extern EnumTypeCLenovoAltModeStatus ScalerTypeCGetLenovoAltModeReady(BYTE ucInputPort);
extern EnumTypeCLenovoDeviceType ScalerTypeCGetLenovoDeviceType(BYTE ucInputPort);
extern StructTypeCLenovoSysEvent ScalerTypeCGetLenovoSystemEvent(BYTE ucInputPort);
extern void ScalerTypeCSetLenovoDockingEvent(BYTE ucInputPort, StructTypeCLenovoDockEvent stLenovoDockEvent);
extern bit ScalerTypeCCheckLenovoDockingEventBusy(BYTE ucInputPort);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_ACER_ALT_MODE)
extern EnumTypeCAcerAltModeStatus ScalerTypeCGetAcerAltModeReady(BYTE ucInputPort);
extern StructTypeCAcerSysEvent ScalerTypeCGetAcerSystemEvent(BYTE ucInputPort);
extern void ScalerTypeCSetAcerUserEvent(BYTE ucInputPort, StructTypeCAcerUserEvent stAcerUserEvent);
extern EnumTypeCAcerBusyStatus ScalerTypeCCheckAcerUserEventBusy(BYTE ucInputPort);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_HP_ALT_MODE)
extern EnumTypeCHpAltModeStatus ScalerTypeCGetHpAltModeReady(BYTE ucInputPort);
extern StructTypeCHpSysEvent ScalerTypeCGetHpSystemEvent(BYTE ucInputPort);
extern void ScalerTypeCSetHpUserEvent(BYTE ucInputPort, StructTypeCHpUserEvent stHpUserEvent);
extern EnumTypeCHpBusyStatus ScalerTypeCCheckHpUserEventBusy(BYTE ucInputPort);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_DELL_ALT_MODE)
extern EnumTypeCDellAltModeStatus ScalerTypeCGetDellAltModeReady(BYTE ucInputPort);
extern StructTypeCDellSysEvent ScalerTypeCGetDellSystemEvent(BYTE ucInputPort);
extern void ScalerTypeCSetDellUserEvent(BYTE ucInputPort, StructTypeCDellUserEvent stDellUserEvent);
extern void ScalerTypeCSetDellAltModeInitComplete(BYTE ucInputPort, EnumTypeCDellInitCompleteStatus enumDellInitCompleteStatus);
extern EnumTypeCDellBusyStatus ScalerTypeCCheckDellUserEventBusy(BYTE ucInputPort);
extern EnumTypeCEnterDellAltModeTimeOut ScalerTypeCGetEnterDellAltModeTimeOut(BYTE ucInputPort);
#endif
#endif // End of #if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
#endif // End of #if(_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON)

#if(_TYPE_C_GPIO_MODE_SUPPORT == _ON)
extern void ScalerTypeCGpioModeInitialSetting(void);
extern EnumTypeCCcDetectStatus ScalerTypeCGetCcPinStatus(EnumTypeCChannel enumTypeCChannel);
#endif  // End of #if(_TYPE_C_GPIO_MODE_SUPPORT == _ON)