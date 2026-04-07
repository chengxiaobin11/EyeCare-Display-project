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
// ID Code      : ScalerCommonTypeCPmicInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON) && (_TYPE_C_PMIC_TYPE != _PMIC_NONE))
//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definition of Default PMIC Portection Debounce
//--------------------------------------------------
#define _TYPE_C_PMIC_DEF_OVP_DEBOUNCE               0 // Unit: Judge_Time
#define _TYPE_C_PMIC_DEF_UVP_DEBOUNCE               0 // Unit: Judge_Time
#define _TYPE_C_PMIC_DEF_OCP_DEBOUNCE               0 // Unit: Judge_Time


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE b1PmicIICSetStart : 1;
    BYTE b1PmicIICMainLoop : 1;
    BYTE b1PmicIICExint0Loop : 1;
    BYTE b1PmicIICWdintLoop : 1;
    BYTE b1PmicIICExint0EverLoop : 1;
    BYTE b1PmicIICWdintEverLoop : 1;
} StructPmicControl;


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_TYPE_C_PMIC_HW_IIC_SUPPORT == _ON)
extern void ScalerTypeCPmicHwIICSetFreqDiv(EnumClkSel enumClock);
#endif
extern void ScalerTypeCPmicRx0Initial(void);
extern void ScalerTypeCPmicRx0Reset(void);
extern void ScalerTypeCPmicRx0Reset_EXINT0(void);
extern void ScalerTypeCPmicRx0Handler(void);
extern void ScalerTypeCPmicRx0TimerEventProc(EnumScalerTimerEventID enumEventID);
extern bit ScalerTypeCPmicRx0Setting(bit bAction, bit bPowerDirection, EnumPDPdoType enumPdoType, WORD usVoltage, WORD usCurrent, EnumPDPeakCurType enumPeakCurrent);
extern BYTE ScalerTypeCPmicRx0Setting_EXINT0(bit bAction, bit bPowerDirection, EnumPDPdoType enumPdoType, WORD usVoltage, WORD usCurrent, EnumPDPeakCurType enumPeakCurrent);
extern BYTE ScalerTypeCPmicRx0Setting_WDINT(bit bAction, bit bPowerDirection, EnumPDPdoType enumPdoType, WORD usVoltage, WORD usCurrent, EnumPDPeakCurType enumPeakCurrent);
extern bit ScalerTypeCPmicRx0VbusDischarge(bit bEn);
extern BYTE ScalerTypeCPmicRx0VbusDischarge_EXINT0(bit bEn);
extern BYTE ScalerTypeCPmicRx0VbusDischarge_WDINT(bit bEn);
#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
extern EnumTypeCPmicOperationMode ScalerTypeCPmicRx0ReadPpsOperationModeStatus_EXINT0(void);
#endif

#if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
void ScalerTypeCPmicRx0SetVbusProtectInfo(StructTypeCUserProtectInfo stTypeCVbusProtectInfo);
#endif // End of #if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)

#if(_TYPE_C_PMIC_CHECK_SUPPORT == _ON)
extern void ScalerTypeCPmicRx0ProtectStart(EnumTypeCPowerRole enumPowerRole);
extern void ScalerTypeCPmicRx0ProtectStart_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern void ScalerTypeCPmicRx0ProtectStart_WDINT(EnumTypeCPowerRole enumPowerRole);
#endif

#if(_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_SCALER_SARADC)
extern void ScalerTypeCPmicRx0FwOcpIntHandler_EXINT0(void);
extern void ScalerTypeCPmicRx0WDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID, BYTE *pucActiveWDID, BYTE *pucActiveWDTime);
#if(_TYPE_C_PMIC_SAFETY_PROTECT_SUPPORT == _ON)
extern void ScalerTypeCPmicRx0SafetyProtect(void);
#endif
#endif

#if(_TYPE_C_PMIC_FW_OVP_UVP_SUPPORT == _ON)
extern void ScalerTypeCPmicRx0OvpUvpIntHandler_EXINT0(void);
extern BYTE ScalerTypeCPmicRx0GetFwOvpUvpCheckFlag_EXINT0(void);
#endif

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
extern BYTE ScalerTypeCPmicRx0AttachProc(EnumTypeCPowerRole enumPowerRole);
extern BYTE ScalerTypeCPmicRx0AttachProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern void ScalerTypeCPmicRx0UnattachProc(bit bRole);
extern void ScalerTypeCPmicRx0UnattachProc_EXINT0(BYTE ucRole);
extern BYTE ScalerTypeCPmicRx0TransitionStartProc_EXINT0(WORD usVoltage, WORD usCurrent, WORD *pusSrcAdjustPowerTime);
extern BYTE ScalerTypeCPmicRx0TransitionReadyProc_WDINT(void);
extern BYTE ScalerTypeCPmicRx0PRSwapStartProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern BYTE ScalerTypeCPmicRx0PRSwapToSrcProc_WDINT(void);
extern void ScalerTypeCPmicRx0HardRstStartProc(EnumTypeCPowerRole enumPowerRole);
extern void ScalerTypeCPmicRx0HardRstStartProc_EXINT0(EnumTypeCPowerRole enumPowerRole);
extern void ScalerTypeCPmicRx0HardRstStartProc_WDINT(EnumTypeCPowerRole enumPowerRole);
extern BYTE ScalerTypeCPmicRx0HardRstVbusOffProc(void);
extern BYTE ScalerTypeCPmicRx0GetVbus5VCheckFlag_EXINT0(void);
extern void ScalerTypeCPmicRx0ClrVbus5VCheckFlag_EXINT0(void);
extern BYTE ScalerTypeCPmicRx0GetVbus0VCheckFlag_EXINT0(void);
extern void ScalerTypeCPmicRx0ClrVbus0VCheckFlag_EXINT0(void);
extern void ScalerTypeCPmicRx0VbusCheckProc_EXINT0(EnumTypeCVbusCheckType enumVbusCheckType);
extern EnumTypeCVbusCheckType ScalerTypeCPmicRx0Vbus5VReadyProc_EXINT0(BYTE ucRole);
extern BYTE ScalerTypeCPmicRx0Vbus0VReadyProc_EXINT0(BYTE ucRole);
#endif // End of #if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
#endif // End of #if((_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON) && (_TYPE_C_PMIC_TYPE != _PMIC_NONE))

