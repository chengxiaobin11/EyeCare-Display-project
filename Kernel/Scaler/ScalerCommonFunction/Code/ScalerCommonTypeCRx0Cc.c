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
// ID Code      : ScalerCommonTypeCRx0Cc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _CC_FW_DEBUG                                            _OFF
#define _TYPE_C_CC_CONNECT_MODE                                 _TYPE_C_HW_MODE

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructTypeCEmbInfo g_stTpcInfo;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerTypeCRx0CcClkSel(BYTE ucClockSel);
void ScalerTypeCRx0CcInitial(void);
#if(_TYPE_C_POWER_SOURCE == _TYPE_C_VBUS_POWER_ONLY)
void ScalerTypeCRx0CcVbusPoweredSnkInitial(void);
void ScalerTypeCRx0CcVbusPoweredSnkAttachedProc_EXINT0(void);
#endif
void ScalerTypeCRx0CcHandler(void);
void ScalerTypeCRx0CcIntHandler_EXINT0(void);
BYTE ScalerTypeCRx0CcIntClrCheck_EXINT0(void);
void ScalerTypeCRx0CcTimerEventProc(EnumScalerTimerEventID enumEventID);
void ScalerTypeCRx0CcWDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID, BYTE *pucActiveWDID, BYTE *pucActiveWDTime);
void ScalerTypeCRx0CcSetDeglitch(EnumTypeCChannel enumTypeCChannel, BYTE ucTime, EnumDeglitchUnit enumUnit);
void ScalerTypeCRx0CcSetDebounce(bit bDbType, BYTE ucTime);
void ScalerTypeCRx0CcUnattachFlow_EXINT0(void);
void ScalerTypeCRx0CcUnattachReset(void);
void ScalerTypeCRx0CcUnattachReset_EXINT0(void);
void ScalerTypeCRx0CcConnectionSet(void);
void ScalerTypeCRx0CcConnectionSet_EXINT0(void);
bit ScalerTypeCRx0CcAttachedSetting(void);
bit ScalerTypeCRx0CcUnattachCheck(void);
void ScalerTypeCRx0CcVconnControl(bit bAction);
void ScalerTypeCRx0CcVconnControl_EXINT0(bit bAction);
void ScalerTypeCRx0CcVconnControl_WDINT(bit bAction);
void ScalerTypeCRx0CcSetBMC(bit bAction);
void ScalerTypeCRx0CcSetBMC_EXINT0(bit bAction);
void ScalerTypeCRx0CcVbusDetCtrl(bit bAction);
void ScalerTypeCRx0CcVbusDetCtrl_EXINT0(bit bAction);
void ScalerTypeCRx0CcVbusDetCtrl_WDINT(bit bAction);
BYTE ScalerTypeCRx0CcDetResistor(void);
#if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
#if(_TYPE_C_EMB_DP_ALT_MODE_SUPPORT == _ON)
BYTE ScalerTypeCRx0CcDetResistor_EXINT0(void);
BYTE ScalerTypeCRx0CcDetResistor_WDINT(void);
#endif
#endif
void ScalerTypeCRx0CcACOnDeviceDetect(void);
bit ScalerTypeCRx0CcGetACOnDeviceDetect(void);
void ScalerTypeCRx0CcSwitchPowerRole(BYTE ucTargetRole);
void ScalerTypeCRx0CcSwitchPowerRole_WDINT(BYTE ucTargetRole);
void ScalerTypeCRx0CcPowerSwitch(EnumPowerAction enumPowerAction);
void ScalerTypeCRx0CcFunctionControl(EnumTypeCCcFunction enumCcFunction);
void ScalerTypeCRx0CcSetFunctionSupport(EnumTypeCFunctionSupport enumFunctionSupport);
void ScalerTypeCRx0CcSetOperationMode(EnumTypeCOperationMode enumOperationMode);
void ScalerTypeCRx0CcFWModeSRCUnattached_EXINT0(void);
#if((_TYPE_C_EMB_CTS_FLOW == _ON) && (_HW_TYPE_C_FUNCTION_GEN == _TYPE_C_FUNCTION_GEN_1))
BYTE ScalerTypeCRx0CcGetChangeVbusOffThr_EXINT0(void);
#endif
BYTE ScalerTypeCRx0CcGetTryWaitSNKState_EXINT0(void);
void ScalerTypeCRx0CcFWModeTrySrcAttached_EXINT0(void);

#if(_TYPE_C_EMB_PD3_FRSWAP_SUPPORT == _ON)
void ScalerTypeCRx0CcFastRoleSwapControl(bit bAction);
void ScalerTypeCRx0CcFastRoleSwapControl_EXINT0(bit bAction);
#endif

#if(_TYPE_C_EMB_UNATTACH_HW_FORCE_VBUS_OFF == _OFF)
void ScalerTypeCRx0CcToolWarningUIControl(bit bAction);
void ScalerTypeCRx0CcToolWarningUIControl_EXINT0(bit bAction);
void ScalerTypeCRx0CcToolWarningUIControl_WDINT(bit bAction);
#endif

#endif  // End of #if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)

#if((_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED) || (_TYPE_C_GPIO_MODE_SUPPORT == _ON))
void ScalerTypeCRx0CcLoadTrimming(void);
#endif

#if(_TYPE_C_GPIO_MODE_SUPPORT == _ON)
void ScalerTypeCRx0CcGpioModeInitialSetting(void);
EnumTypeCCcDetectStatus ScalerTypeCRx0CcGetCcPinStatus(EnumTypeCChannel enumTypeCChannel);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)

//--------------------------------------------------
// Description  : Type C Rx0 CC Clk Setting (Always Use IOSC = 28MHz)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcClkSel(BYTE ucClockSel)
{
    if(ucClockSel == _IOSC_CLK)
    {
        // [0x6600] [5:4] Clk Sel = IOSC (b'10) / [0x6601] [3:0] sys_clk_div = b'0001
        ScalerSetBit(P66_00_GLOBAL_CTL, ~(_BIT5 | _BIT4), _BIT5);
        ScalerSetBit(P66_01_SYS_CLK_SRC_CFG, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);

        // [0x6602] clk_1m_div = 28 (b'0001_1100)
        ScalerSetByte(P66_02_1M_CLK_SRC_CFG, 0x1C);

        // [0x6603-04] clk_1k_div = 1000 (b'11_11101000)
        ScalerSetBit(P66_03_1K_CLK_SRC_CFG_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
        ScalerSetByte(P66_04_1K_CLK_SRC_CFG_1, 0xE8);
    }
}

//--------------------------------------------------
// Description  : Type C CC Logic AC_ON Initail
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcInitial(void)
{
    SET_TYPE_C_GLOBAL_IRQ_ENABLE(_ENABLE);
    // ------------------- Type C Initial Setting -------------------

    // global_cc_en = _ENABLE
    ScalerSetBit(P66_00_GLOBAL_CTL, ~_BIT7, _BIT7);

    // Setting Up CC1/2 De-glitch
    ScalerTypeCRx0CcSetDeglitch(_TYPE_C_CC1, 3, _TYPE_C_UNIT_100US);
    ScalerTypeCRx0CcSetDeglitch(_TYPE_C_CC2, 3, _TYPE_C_UNIT_100US);

#if(_TYPE_C_POWER_SOURCE == _TYPE_C_VBUS_POWER_ONLY)
    // [RL6828 TID] SinkWaitCapTimer
    // For Sink-Only, Powered from Vbus Products, Detect Vbus means Source Already in Attached.SRC
    // Reduce tCCDebounce (2 ms) to Enter Attached.SNK Faster
    if(GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_SNK_ONLY)
    {
        ScalerTypeCRx0CcSetDebounce(_TYPE_C_CC, 2);
    }
    else
    {
        ScalerTypeCRx0CcSetDebounce(_TYPE_C_CC, 110);
    }
#else
    // Set tCCDebounce (150 ms) & tPDDebounce (20 ms), Not Set VS-Debounce
    ScalerTypeCRx0CcSetDebounce(_TYPE_C_CC, 110);
#endif
    ScalerTypeCRx0CcSetDebounce(_TYPE_C_PD, 10);

    // Load Trimming Value From E-fuse and Set up AIF Registers
    ScalerTypeCRx0CcLoadTrimming();

    // Initial Flags & Status Setting
    CLR_CC_RX0_ATTACHED();
    SET_RX0_SRC_FRSWAP_STATUS(_DISABLE);
    SET_RX0_SNK_FRSWAP_STATUS(_DISABLE);
    SET_RX0_VCONN_STATUS(_OFF);
    CLR_TYPE_C_RX0_RESET_FLAG();

    // Enable CC
    SET_CC_RX0_CONNECT_EN();

    // ------------------- OCP Initial Setting -------------------

    // OCP Mode = HW Auto Mode
    ScalerSetBit(P66_0D_TPC_OCP_CTRL, ~_BIT6, 0x00);

    // ocp_deg_cc1/2 = _ENABLE, ocp_vref_sel_cc1/2 = b'100 (470mA)
    ScalerSetByte(P66_0E_TPC_OPC_CFG_0, 0xE4);

    // Escape Vltage = 4.5V, reg_opcadj_cc1 = 0
    ScalerSetBit(P66_0F_TPC_OPC_CFG_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

    // OCP HW Auto Mode Timing Setting
    ScalerSetByte(P66_73_VCONN_OCP_TIMER1, 0xBC);
    ScalerSetByte(P66_74_VCONN_OCP_TIMER2, 0xFC);
    ScalerSetByte(P66_75_VCONN_OCP_TIMER3, 0x41);
    ScalerSetByte(P66_76_VCONN_OCP_TIMER4, 0xBC);
    ScalerSetByte(P66_77_VCONN_OCP_TIMER5, 0xFC);

    // ----------------- HW Mode Initial Setting -----------------

#if(_TYPE_C_CC_CONNECT_MODE == _TYPE_C_HW_MODE)

    // HW Mode Type-C Version Setting [7] (0:_TYPE_C_1_1 / 1:_TYPE_C_1_2)
#if(_HW_TYPE_C_SUPPORT_VERSION == _TYPE_C_VERSION_1_1)
    ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~_BIT7, 0x00);
#else
    ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~_BIT7, _BIT7);
#endif

    // DRP Port Toggle Timing Setting (SRC/SNK/TrySRC/TrySNKWait)
    // [0x6638] drp_hw_src_time = 40 ms (0x28)
    ScalerSetByte(P66_38_CC_HW_DRP_SRC_TM, 0x28);

    // [0x6639] drp_hw_snk_time = 40 ms (0x28)
    ScalerSetByte(P66_39_CC_HW_DRP_SNK_TM, 0x28);

    // [0x663A] [4:3] Try.SRC = 75ms / [2:0] Try.Wait = 400ms
    ScalerSetBit(P66_3A_CC_HW_TRY_SRC_TM, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);

    // ---------- HW Mode Accessory Support Setting ----------

    // [2]   hw_debug_sup_en
#if((_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_DEBUG) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_DEBUG_POWER) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_DEBUG_AUDIO) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_ALL))
    ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~_BIT2, _BIT2);
#else
    ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~_BIT2, 0x00);
#endif

    // [1]   hw_audio_sup_en
#if((_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_AUDIO) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_AUDIO_POWER) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_DEBUG_AUDIO) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_ALL))
    ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~_BIT1, _BIT1);
#else
    ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~_BIT1, 0x00);
#endif

    // [0]   hw_pwr_sup_en
#if((_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_POWER) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_AUDIO_POWER) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_DEBUG_POWER) || (_TYPE_C_ACC_SUPPORT_TYPE == _TYPE_C_ACC_ALL))
    ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~_BIT0, _BIT0);
#else
    ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~_BIT0, 0x00);
#endif

    // ---------- HW Mode FSM & BMC De-Glitch Setting ----------

    // [0x663D] Enable Setup Hold / Debounce Time
    ScalerSetBit(P66_3D_HW_DGH_EN, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

    // [0x663E] Deglitch HW State Transition = 5ms
    ScalerSetByte(P66_3E_HW_DGH_TH, 0xCA);

    // [0x663F] Hold Time For HW Sync = 1 ms
    ScalerSetByte(P66_3F_STABLE_TIMER_TH, 0x8A);

#endif  // End of #if(_TYPE_C_CC_CONNECT_MODE == _TYPE_C_HW_MODE)

    // ----------------- Fast Role Swap Setting -----------------

#if(_TYPE_C_EMB_PD3_FRSWAP_SUPPORT == _ON)
    // Fast Role Swap CC Pin Select Mode = HW Mode
    ScalerSetBit(P66_60_FRS_CTRL, ~_BIT4, 0x00);

    // CC Pin Voltage < 490mV Signal Deglitch
    ScalerSetByte(P66_61_FRS_490MV_DGH, 0x41);

    // Vbus Voltage Drop Below Threshold Voltage Deglitch
    ScalerSetByte(P66_62_FRS_VBUS_DGH, 0x01);

    // Timing For SRC to Drive Low When Sending FR_SWAP Signal (90us)
    ScalerSetBit(P66_63_SRC_FRS_DRV_TM, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x09);

    // Timing For SNK to Recognize Drive Low Signal from SRC (CC Pin Vol. < 490mV for more than 50us)
    ScalerSetByte(P66_64_SNK_FRS_DET_TM, 0x20);

    // Configre For SNK to Start Supply Vbus
    ScalerSetByte(P66_65_SNK_FRS_VTH_MODE, _BIT6);

#endif  // End of #if(_TYPE_C_EMB_PD3_FRSWAP_SUPPORT == _ON)
}

#if(_TYPE_C_POWER_SOURCE == _TYPE_C_VBUS_POWER_ONLY)
//--------------------------------------------------
// Description  : Type C CC Vbus Powered Sink Initial Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcVbusPoweredSnkInitial(void)
{
    // CC FW Initial
    ScalerTypeCRx0CcInitial();
    ScalerTypeCRx0PdInitial();
    ScalerTypeCPowerAdcPortInitial();
#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
    ScalerTypeCPmicRx0Initial();
#endif

    // CC FW Unattach Reset
    // 1. Reset to Unattached State (Initial to Unattach / Error Recovery : PD => Power => CC)
    ScalerTypeCRx0PdReset();
    // FW Solution : Samsung S8 Clear Flag When CC Unattach (Not Cleared When PD Reset)
    ScalerTypeCRx0PdClrInteropS8Flag();
    ScalerTypeCPowerRx0UnattachReset();
    ScalerTypeCRx0CcUnattachReset();

    // 2. Setting For Connection
    ScalerTypeCRx0CcConnectionSet();

    // 3. Enable HW Connection
    ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~_BIT5, _BIT5);

    // 4. State Transition
    SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_CONNECTING);
}

//--------------------------------------------------
// Description  : Type C CC Vbus Powered Sink Attached Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcVbusPoweredSnkAttachedProc_EXINT0(void) using 1
{
    if(GET_RX0_REG_CC_STATE() == _ATTACHED_SNK)
    {
        ScalerTypeCRx0PdSetPowerRole_EXINT0(_PD_POWER_SNK);

        if(ScalerGetBit_EXINT(P66_33_CC_HW_FSM, (_BIT7)) == _BIT7)
        {   // Un-Flip : PD BMC Signal : CC1 / Vconn : CC2
            SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_UNFLIP);

            // [0x660C] Disconnect CC2 Detection and BMC Channel
            // [6] tpc_cc2_det_en  = _TYPE_C_DISCONNECT
            // [2] tpc_cc2_en      = _TYPE_C_DISCONNECT (Not Needed)
            ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT6 | _BIT4 | _BIT2), 0x00);
        }
        else
        {   // Flip : PD BMC Signal : CC2 / Vconn : CC1
            SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_FLIP);

            // [0x660C] Disconnect CC1 Detection and BMC Channel
            // [7] tpc_cc1_det_en  = _TYPE_C_DISCONNECT
            // [3] tpc_cc1_en      = _TYPE_C_DISCONNECT (Not Needed)
            ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT5 | _BIT3), 0x00);
        }

        // Adjust Unattch Vth to 3.67V
        ScalerTypeCPowerRx0UnattachVthAdjust_EXINT0(500);

#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
        // Disable Vbus Discharge
        ScalerTypeCPmicRx0VbusDischarge_EXINT0(_DISABLE);

        // Cancel WDTimerEvent (_UNATTACH_VBUS_DISCHARGE_TIMER)
        ScalerTimerWDCancelTimerEvent_EXINT0(_SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V);
#endif

        // Update Vbus Power Info to Support Sink OVP/UVP
        ScalerTypeCPowerRx0VbusControl_EXINT0(_ON, _PD_POWER_SNK, _PD_FIX_SUPPLY_PDO, 500, 0, _PD_PEAK_CUR_NONE);

#if((_TYPE_C_PMIC_TYPE != _PMIC_NONE) && (_TYPE_C_PMIC_CHECK_SUPPORT == _ON))
        // Start PMIC Protection
        ScalerTypeCPmicRx0ProtectStart_EXINT0(_TYPE_C_POWER_SNK);
#endif

#if((_TYPE_C_EMB_CTS_FLOW == _ON) && (_HW_TYPE_C_FUNCTION_GEN == _TYPE_C_FUNCTION_GEN_1))
        // Lecroy [TD.4.5.4] and [TD.4.7.2].
        // In Attached.SNK State, Clear Macro and Cancel WD Timer Event.
        CLR_TYPE_C_RX0_CHANGE_VBUS_OFF_THR();
        ScalerTimerWDCancelTimerEvent_EXINT0(_SCALER_WD_TIMER_EVENT_CC_RX0_CHANGE_VBUS_OFF_THRESHOLD);
#endif

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
        // [Eizo] SIC437A Customized Power Control : SRC/SNK Attach
        ScalerTypeCPmicRx0AttachProc_EXINT0(_TYPE_C_POWER_SNK);
#endif

        // Set Power Role for Detecting CC1/CC2 Resistor = SNK
        ScalerSetBit_EXINT(P66_2B_CC_DIG_DET_R, ~(_BIT7), _BIT7);

        // Enable CC1/ CC2 Change IRQ to Detect Open + Open
        ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        // Set PD to Initail State (Data Role, Vconn Role, Initial State (PE_SRC/SNK_STARTUP),...)
        ScalerTypeCRx0PdAttachedSetting_EXINT0();

        // BMC Related Setting
        ScalerTypeCRx0CcSetBMC_EXINT0(_ENABLE);

        // Turn On U3 & Hub Function
        ScalerDpRx0SetDpAltModeLaneMapping_EXINT0(_TYPE_C_PIN_ASSIGNMENT_NONE, GET_CC_RX0_ORIENTATION());

        SET_CC_RX0_ATTACHED();

        SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_ATTACHED);
    }
    else
    {
        // If Connect to Unexpected Attached State, Transit to UNATTACH State
        SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_UNATTACH);
    }
}
#endif

//--------------------------------------------------
// Description  : CC Logic Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcHandler(void)
{
    switch(GET_TYPE_C_RX0_ATTACH_STATUS())
    {
        case _EMB_TPC_INITAIL:

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
            DebugMessageTypeC("O Type C State : INITIAL", GET_TYPE_C_RX0_ATTACH_STATUS());
#endif
            ScalerTypeCRx0CcInitial();
            ScalerTypeCRx0PdInitial();
            ScalerTypeCPowerAdcPortInitial();
#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
            ScalerTypeCPmicRx0Initial();
#endif

            if((GET_TYPE_C_RX0_AC_ON_RECONNECT() == _TRUE) && (ScalerTypeCPowerGetLocPowExist() == _TYPE_C_LOCAL_POWER_EXIST))
            {
                ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, 0x00);
                ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, 0x00);
                ScalerSetByte(P66_30_CC_HW_MODE_CTRL, 0x00);

                ScalerTimerActiveTimerEvent(1000, _SCALER_TIMER_EVENT_CC_RX0_STATE_TO_UNATTACH);
            }
            else
            {
                ScalerTimerActiveTimerEvent(1, _SCALER_TIMER_EVENT_CC_RX0_STATE_TO_UNATTACH);
            }

#if(_TYPE_C_EMB_UNATTACH_HW_FORCE_VBUS_OFF == _OFF)
            // [MM1GENERAL-2282]
            // Tool Usage : [0x6666] [4] Used to Decide Whether Tool shall Show Warning UI when Disable Unattach HW Force Vbus Off Function, 0 = Not Show UI, 1 = Show UI
            // Tool Usage : [0x6666] [3] Unattach HW Force Vbus Off Enable Control, 0 = Disble, 1 = Enable
            // Tool Not Show Warning UI Initially
            ScalerSetBit(P66_66_SRC_FRS_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#endif

            break;

        case _EMB_TPC_UNATTACH:

            // Do Unattach Reset Only One Time When CC Function is Disable
            if(GET_TYPE_C_RX0_RESET_FLAG() == _FALSE)
            {
                SET_TYPE_C_RX0_RESET_FLAG();

                // 1. Reset to Unattached State (Initial to Unattach / Error Recovery : PD => Power => CC)
                ScalerTypeCRx0PdReset();
                // FW Solution : Samsung S8 Clear Flag When CC Unattach (Not Cleared When PD Reset)
                ScalerTypeCRx0PdClrInteropS8Flag();
                ScalerTypeCPowerRx0UnattachReset();
                ScalerTypeCRx0CcUnattachReset();
            }

            if(GET_CC_RX0_CONNECT_EN() == _TRUE)
            {
                CLR_TYPE_C_RX0_RESET_FLAG();

                // 2. Setting For Connection
                ScalerTypeCRx0CcConnectionSet();

                // 3. Enable HW Connection
                ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~_BIT5, _BIT5);

                // 4. State Transition
                SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_CONNECTING);

#if((_TYPE_C_EMB_CTS_FLOW == _ON) && (_HW_TYPE_C_FUNCTION_GEN == _TYPE_C_FUNCTION_GEN_1))
                // Lecroy [TD.4.5.4] and [TD.4.7.2], RL6561 FW Solution to Disable vSafe0V Check from Unattached.SRC to AttachWait.SRC
                // Set Macro and Enable [adc0_comp_vbus_off_en], then Active WD Timer Event to Dynamically Change Vbus_Off_Thr to vSafe0V when [adc0_comp_vbus_on] INT Triggered.
                // Note : Since _TYPE_C_FUNCTION_GEN_1 (RL6492) Do Not Have PD Timer Register, The FW Solution in S2_1P is Different from S3.
                SET_TYPE_C_RX0_CHANGE_VBUS_OFF_THR();
                ScalerTypeCPowerVbusCompIntControl(_TYPE_C_A0_UFP_VBUS, _OFF, _ENABLE);
#endif
            }
            break;

        case _EMB_TPC_CONNECTING:

            // FW Waiting for Attached When Connecting in HW_MODE
            // Can Use Debug Message to Monitor the Connecting Status
            //========================================================================
            // When "hw_done_irq" is Triggered, SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_CONNECTTED) @ SysInt
            // hw_done_irq     = 1;            [0x6630]
            // hw_done_irq_en  = _DISABLE;     [0x6630]
            // hw_unattach_irq = 1;            [0x6630]
            // hw_unattach_irq_en = _ENABLE;   [0x6630]
            //========================================================================

            // Check if Error Recovery is SET
            if(GET_TYPE_C_ERROR_RECOVERY() == _TRUE)
            {
                // Switch to FW Mode to Disconnect Both CC1 / CC2, and Wait 30ms (Should Be More Than tPDDebounce Max)
                ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, 0x00);
                ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, 0x00);
                ScalerSetByte(P66_30_CC_HW_MODE_CTRL, 0x00);
                ScalerTimerDelayXms(30);

                CLR_TYPE_C_ERROR_RECOVERY();
                SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_UNATTACH);
            }

            break;

        case _EMB_TPC_CONNECTTED:

            // 1. Detect CC Role, Orientation and Resistor on CC Pin
            // 2. If SRC, Check Vbus = vSafe0V before turnning on Vbus
            if(ScalerTypeCRx0CcAttachedSetting() == _TRUE)
            {
                if(ScalerTypeCRx0PdGetPowerRole() == _PD_POWER_SRC)
                {
                    if(ScalerTypeCPowerRx0CheckVbusSafe0V() == _FALSE)
                    {
                        return;
                    }

                    // For Type-C DRP (No Try.SRC/SNK) CTS Flow
                    // ScalerTimerDelayXms(150);

                    if(GET_CC_RX0_RA_EXIST() == _TRUE)
                    {   // If SRC and Ra Exist, Turn On Vconn
                        ScalerTypeCRx0CcVconnControl(_ON);
                    }

#if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
                    SET_RX0_OCP_CURRENT((WORD)(((DWORD)(GET_CC_RX0_DEF_CUR()) * (DWORD)(GET_RX0_OCP_RATIO(0))) / 100));
#else
                    SET_RX0_OCP_CURRENT((WORD)((DWORD)(GET_CC_RX0_DEF_CUR()) * _TYPE_C_DEF_OCP_RATIO / 100));
#endif

#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
                    // Disable Vbus Discharge
                    ScalerTypeCPmicRx0VbusDischarge(_DISABLE);

                    // Cancel WDTimerEvent (_UNATTACH_VBUS_DISCHARGE_TIMER)
                    ScalerTimerWDCancelTimerEvent(_SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V);
#endif

                    // If SRC, Turn On Vbus to vSafe5V (500 * 10mV) / Current = Default Current (10mA)
                    ScalerTypeCPowerRx0VbusControl(_ON, _PD_POWER_SRC, _PD_FIX_SUPPLY_PDO, 500, GET_RX0_OCP_CURRENT(), _PD_PEAK_CUR_NONE);

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
                    // [Eizo] SIC437A Customized Power Control : SRC/SNK Attach
                    ScalerTypeCPmicRx0AttachProc(_TYPE_C_POWER_SRC);
#endif

                    // Set Power Role for Detecting CC1/CC2 Resistor = SRC
                    ScalerSetBit(P66_2B_CC_DIG_DET_R, ~(_BIT7), 0x00);

                    // Enable CC1/ CC2 Change IRQ to Detect if SNK-Rd is Removed
                    ScalerSetBit(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                }
                else
                {   // Adjust Unattch Vth to 3.67V
                    ScalerTypeCPowerRx0UnattachVthAdjust();

#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
                    // Disable Vbus Discharge
                    ScalerTypeCPmicRx0VbusDischarge(_DISABLE);

                    // Cancel WDTimerEvent (_UNATTACH_VBUS_DISCHARGE_TIMER)
                    ScalerTimerWDCancelTimerEvent(_SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V);
#endif

                    // Update Vbus Power Info to Support Sink OVP/UVP
                    ScalerTypeCPowerRx0VbusControl(_ON, _PD_POWER_SNK, _PD_FIX_SUPPLY_PDO, 500, 0, _PD_PEAK_CUR_NONE);

#if((_TYPE_C_PMIC_TYPE != _PMIC_NONE) && (_TYPE_C_PMIC_CHECK_SUPPORT == _ON))
                    // Start PMIC Protection
                    ScalerTypeCPmicRx0ProtectStart(_TYPE_C_POWER_SNK);
#endif

#if((_TYPE_C_EMB_CTS_FLOW == _ON) && (_HW_TYPE_C_FUNCTION_GEN == _TYPE_C_FUNCTION_GEN_1))
                    // Lecroy [TD.4.5.4] and [TD.4.7.2].
                    // In Attached.SNK State, Clear Macro and Cancel WD Timer Event.
                    CLR_TYPE_C_RX0_CHANGE_VBUS_OFF_THR();
                    ScalerTimerWDCancelTimerEvent(_SCALER_WD_TIMER_EVENT_CC_RX0_CHANGE_VBUS_OFF_THRESHOLD);
#endif

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
                    // [Eizo] SIC437A Customized Power Control : SRC/SNK Attach
                    ScalerTypeCPmicRx0AttachProc(_TYPE_C_POWER_SNK);
#endif

                    // Set Power Role for Detecting CC1/CC2 Resistor = SNK
                    ScalerSetBit(P66_2B_CC_DIG_DET_R, ~(_BIT7), _BIT7);

                    // Enable CC1/ CC2 Change IRQ to Detect Open + Open
                    ScalerSetBit(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                }

                // Set PD to Initail State (Data Role, Vconn Role, Initial State (PE_SRC/SNK_STARTUP),...)
                ScalerTypeCRx0PdAttachedSetting();

                // BMC Related Setting
                ScalerTypeCRx0CcSetBMC(_ENABLE);

                // Turn On U3 & Hub Function
                ScalerDpRx0SetDpAltModeLaneMapping(_TYPE_C_PIN_ASSIGNMENT_NONE, GET_CC_RX0_ORIENTATION());

                SET_CC_RX0_ATTACHED();

                if(GET_TYPE_C_RX0_ATTACH_STATUS() == _EMB_TPC_CONNECTTED)
                {
                    SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_ATTACHED);
#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
                    DebugMessageTypeC("O Type C State : ATTACH SUCCESS!!!", GET_TYPE_C_RX0_ATTACH_STATUS());
                    DebugMessageTypeC("  ! ! ! CC ATTACHED ! ! !", GET_CC_RX0_ATTACHED());
#endif
                }
            }
            else
            {
                if((GET_RX0_REG_CC_STATE() == _AUDIO_ACCESSORY_SRC) || (GET_RX0_REG_CC_STATE() == _DEBUG_ACCESSORY_SRC))
                {
                    // [0x665A/5B] Setting FW Mode Rp Resistor (36K / 12K / 4.7K)
#if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)
                    ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT4);
                    ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT4);
#elif(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_1P5A)
                    ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT5);
                    ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT5);
#else
                    ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT3);
                    ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT3);
#endif  // End of #if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)

                    // [0x6630] Change to FW Mode, Clear (hw_done_irq) & (hw_unattach_irq), and Disable hw_unattach_irq_en
                    // [7] tpc_cc_mode_sel = 0
                    // [3] hw_done_irq     = 1
                    // [1] hw_unattach_irq = 1
                    // [0] hw_unattach_irq_en = _DISABLE
                    ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

                    // Set Power Role for Detecting CC1/CC2 Resistor = SRC
                    ScalerSetBit(P66_2B_CC_DIG_DET_R, ~(_BIT7), 0x00);

#if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)
                    // Set Vth
                    ScalerSetByte(P66_28_VTH_SEL, 0x55);
#elif(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_1P5A)
                    // Set Vth
                    ScalerSetByte(P66_28_VTH_SEL, 0x99);
#else
                    // Set Vth
                    ScalerSetByte(P66_28_VTH_SEL, 0xFF);
#endif  // End of #if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)

                    SET_CC_RX0_ACCESSORY_STATE();

                    // Enable CC1/ CC2 Change IRQ
                    ScalerSetBit(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                }
                else
                {
                    if(GET_CC_RX0_ACCESSORY_STATE() == _FALSE)
                    {
                        // If Connect to Unexpected Attached State, Transit to UNATTACH State
                        SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_UNATTACH);
                    }
                }
            }

            break;

        case _EMB_TPC_ATTACHED:

            //========================================================================
            // When "hw_unattach_irq" is Triggered,
            // Clear and Disable Unattach_irq, SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_UNATTACH) @ SysInt
            // Otherwise, Run PD Controller and Process Corresponding PD Events
            //========================================================================

            // 1. Run PD Handler if PD Function is Enabled and No Error Recovery Set
            if((GET_TYPE_C_ERROR_RECOVERY() == _FALSE) && (GET_PD_RX0_FUNCTION_EN() == _TRUE))
            {
                ScalerTypeCRx0PdHandler();
            }

            // 2. Check Whether CC FW Unattach Event is Triggered, Do Error Recovery
            if(ScalerTypeCRx0CcUnattachCheck() == _TRUE)
            {
                CLR_CC_RX0_ATTACHED();
                SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_UNATTACH);
            }

            // 3. Run PMIC Handler
#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
            ScalerTypeCPmicRx0Handler();
#endif

            break;

        default:

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
            DebugMessageTypeC("[WARNING] CC Enter Unexpected State", GET_TYPE_C_RX0_ATTACH_STATUS());
#endif
            // Error : Back to _EMB_TPC_UNATTACH State
            CLR_CC_RX0_ATTACHED();
            SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_UNATTACH);

            break;
    }
}

//--------------------------------------------------
// Description  : Interrupt Process For Type C
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcIntHandler_EXINT0(void) using 1
{
    if(ScalerGetBit_EXINT(P66_71_CC1_VCONN_OCP_INT, (_BIT5 | _BIT1)) == (_BIT5 | _BIT1))
    {   // (cc1_vconn_shutdown_irq == 1) && (cc1_vconn_shutdown_irq_en = _ENABLE)

        // Disable and Clear cc1_vconn_shutdown_irq
        ScalerSetBit_EXINT(P66_71_CC1_VCONN_OCP_INT, ~(_BIT5 | _BIT2 | _BIT1 | _BIT0), _BIT1);

        if(GET_CC_RX0_CONNECT_EN() == _TRUE)
        {
            // Turn Off Vconn (Should We Turn On Vconn Again Later?)
            ScalerTypeCRx0CcVconnControl_EXINT0(_OFF);

            ScalerTypeCRx0PdSetSystemEvent_EXINT0(_PD_SYS_EVENT_VCONN_OCP);
        }
    }

    if(ScalerGetBit_EXINT(P66_72_CC2_VCONN_OCP_INT, (_BIT5 | _BIT1)) == (_BIT5 | _BIT1))
    {   // (cc2_vconn_shutdown_irq == 1) && (cc2_vconn_shutdown_irq_en == _ENABLE)

        // Disable and Clear cc2_vconn_shutdown_irq
        ScalerSetBit_EXINT(P66_72_CC2_VCONN_OCP_INT, ~(_BIT5 | _BIT2 | _BIT1 | _BIT0), _BIT1);

        if(GET_CC_RX0_CONNECT_EN() == _TRUE)
        {
            // Turn Off Vconn (Should We Turn On Vconn Again Later?)
            ScalerTypeCRx0CcVconnControl_EXINT0(_OFF);

            ScalerTypeCRx0PdSetSystemEvent_EXINT0(_PD_SYS_EVENT_VCONN_OCP);
        }
    }

    if(ScalerGetBit_EXINT(P66_30_CC_HW_MODE_CTRL, (_BIT3 | _BIT2)) == (_BIT3 | _BIT2))
    {
        // (hw_done_irq == 1) && (hw_done_irq_en == Enable)
        // [0x6630] : [3] hw_done_irq, [2] hw_done_irq_en, [1] hw_unattach_irq, [0] hw_unattach_irq_en
        // [0] hw_unattach_irq_en = _ENABLE
        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

        if(GET_CC_RX0_CONNECT_EN() == _TRUE)
        {
            if((GET_RX0_REG_CC_STATE() == _AUDIO_ACCESSORY_SRC) || (GET_RX0_REG_CC_STATE() == _DEBUG_ACCESSORY_SRC))
            {
                // If CC State is in _AUDIO_ACCESSORY_SRC or _DEBUG_ACCESSORY_SRC, [0] hw_unattach_irq_en = _DISABLE
                ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));
            }
            else if((GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_DRP) && (GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC) && (GET_RX0_REG_CC_STATE() == _ATTACHED_SRC))
            {
                // DRP Try Src FW Solution : Disable hw_done_irq and hw_unattach_irq
                ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

                // Since hw_try_wait_snk_irq is Already Enable, Only Set Attached.SRC to TryWait.Snk Flag
                SET_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();
            }

#if(_TYPE_C_POWER_SOURCE == _TYPE_C_VBUS_POWER_ONLY)
            ScalerTypeCRx0CcVbusPoweredSnkAttachedProc_EXINT0();
#else
            SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_CONNECTTED);
#endif
        }
    }

    if(ScalerGetBit_EXINT(P66_30_CC_HW_MODE_CTRL, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
    {   // (hw_unattach_irq == 1) && (hw_unattach_irq_en == Enable)

        // [0x6630] : [3] hw_done_irq, [1] hw_unattach_irq, [0] hw_unattach_irq_en
        // Disable and Clear hw_unattach_irq
        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

        if(GET_CC_RX0_CONNECT_EN() == _TRUE)
        {
            // Do Type C Unattach Flow (ADC / PD / CC Reset), and Start HW CC Connection Detection (Enable hw_done_irq_en)
            ScalerTypeCRx0CcUnattachFlow_EXINT0();
        }
    }

    if((ScalerGetBit_EXINT(P66_2C_CC_R_CHG_INT, (_BIT7 | _BIT6)) == (_BIT7 | _BIT6)) || (ScalerGetBit_EXINT(P66_2C_CC_R_CHG_INT, (_BIT5 | _BIT4)) == (_BIT5 | _BIT4)))
    {   // ((cc1_r_chg_irq == 1) && (cc1_r_chg_irq_en == Enable)) || ((cc2_r_chg_irq == 1) && (cc2_r_chg_irq_en == Enable))

        // Disable and Clear CC1/ CC2 Change IRQ
        ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT5));

        if(GET_CC_RX0_CONNECT_EN() == _TRUE)
        {
            if(GET_CC_RX0_ACCESSORY_STATE() == _TRUE)
            {
                // Clear IRQ and Popup Digital Detect Result
                ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT5 | _BIT0), (_BIT7 | _BIT5 | _BIT0));

                // If CC is (Rd+Ra || Ra+Rd), Take Attached Flow
                if(((ScalerGetBit_EXINT(P66_2B_CC_DIG_DET_R, (_BIT5 | _BIT4 | _BIT3)) == (_BIT4)) && (ScalerGetBit_EXINT(P66_2B_CC_DIG_DET_R, (_BIT2 | _BIT1 | _BIT0)) == (_BIT0))) ||
                   ((ScalerGetBit_EXINT(P66_2B_CC_DIG_DET_R, (_BIT5 | _BIT4 | _BIT3)) == (_BIT3)) && (ScalerGetBit_EXINT(P66_2B_CC_DIG_DET_R, (_BIT2 | _BIT1 | _BIT0)) == (_BIT1))))
                {
                    ScalerTypeCRx0PdSetPowerRole_EXINT0(_PD_POWER_SRC);

                    if(ScalerGetBit_EXINT(P66_2B_CC_DIG_DET_R, (_BIT5 | _BIT4 | _BIT3)) == (_BIT4))
                    {
                        // Un-Flip : PD BMC Signal : CC1 / Vconn : CC2
                        SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_UNFLIP);

                        // [0x660C] Disconnect CC2 Detection Channel and CC2 Channel and BMC Channel
                        ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT6 | _BIT4 | _BIT2), 0x00);
                    }
                    else
                    {
                        // Flip : PD BMC Signal : CC2 / Vconn : CC1
                        SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_FLIP);

                        // [0x660C] Disconnect CC1 Detection Channel and CC1 Channel and BMC Channel
                        ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT5 | _BIT3), 0x00);
                    }

                    // Ra Exist, Turn On Vconn
                    ScalerTypeCRx0CcVconnControl_EXINT0(_ON);

#if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
                    SET_RX0_OCP_CURRENT((WORD)(((DWORD)(GET_CC_RX0_DEF_CUR()) * (DWORD)(GET_RX0_OCP_RATIO(0))) / 100));
#else
                    SET_RX0_OCP_CURRENT((WORD)((DWORD)(GET_CC_RX0_DEF_CUR()) * _TYPE_C_DEF_OCP_RATIO / 100));
#endif

#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
                    // Disable Vbus Discharge
                    ScalerTypeCPmicRx0VbusDischarge_EXINT0(_DISABLE);

                    // Cancel WDTimerEvent (_UNATTACH_VBUS_DISCHARGE_TIMER)
                    ScalerTimerWDCancelTimerEvent_EXINT0(_SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V);
#endif
                    // If SRC, Turn On Vbus to vSafe5V (500 * 10mV) / Current = Default Current (10mA)
                    ScalerTypeCPowerRx0VbusControl_EXINT0(_ON, _PD_POWER_SRC, _PD_FIX_SUPPLY_PDO, 500, GET_RX0_OCP_CURRENT(), _PD_PEAK_CUR_NONE);

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
                    // [Eizo] SIC437A Customized Power Control : SRC/SNK Attach
                    ScalerTypeCPmicRx0AttachProc_EXINT0(_TYPE_C_POWER_SRC);
#endif

                    // Set PD to Initail State (Data Role, Vconn Role, Initial State (PE_SRC/SNK_STARTUP),...)
                    ScalerTypeCRx0PdAttachedSetting_EXINT0();

                    // BMC Related Setting
                    ScalerTypeCRx0CcSetBMC_EXINT0(_ENABLE);

                    // Turn On U3 & Hub Function
                    ScalerDpRx0SetDpAltModeLaneMapping_EXINT0(_TYPE_C_PIN_ASSIGNMENT_NONE, GET_CC_RX0_ORIENTATION());

                    SET_CC_RX0_ATTACHED();
                    SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_ATTACHED);

                    // [0x6635] Set HW State to Attached.SRC
                    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), 0x00);
                    ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));

                    // [0x6630] : [7] tpc_cc_mode_sel, [6] hw_mode_fsm_rst, [3] hw_done_irq, [2] hw_done_irq_en, [1] hw_unattach_irq, [0] hw_unattach_irq_en
                    if((GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_DRP) && (GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC))
                    {
                        // DRP Try Src FW Solution :
                        // Change Back to HW Mode, Clear (hw_done_irq) & (hw_unattach_irq), Disable hw_done_irq and hw_unattach_irq
                        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT6 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT6 | _BIT3 | _BIT1));

                        // Since hw_try_wait_snk_irq is Already Enable, Only Set Attached.SRC to TryWait.Snk Flag
                        SET_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();
                    }
                    else
                    {
                        // Change Back to HW Mode, Clear (hw_done_irq) & (hw_unattach_irq), Enable hw_unattach_irq_en
                        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT6 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT6 | _BIT3 | _BIT1 | _BIT0));
                    }

                    // Set Power Role for Detecting CC1/CC2 Resistor = SRC
                    ScalerSetBit_EXINT(P66_2B_CC_DIG_DET_R, ~(_BIT7), 0x00);

                    // Enable CC1/ CC2 Change IRQ to Detect if SNK-Rd is Removed
                    ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

                    // Set Vth to Defalut Value
                    ScalerSetByte_EXINT(P66_28_VTH_SEL, 0x11);

                    CLR_CC_RX0_ACCESSORY_STATE();
                }
                else if((ScalerGetByte_EXINT(P66_2B_CC_DIG_DET_R) & (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x00)
                {
                    // If CC1 and CC2 are Open, Take Unattach Flow

                    if(GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_SRC_ONLY)
                    {
                        // [0x6635] Set HW State to Unattached.SRC
                        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), 0x00);
                        ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
                    }
                    else
                    {
                        // [0x6635] Set HW State to Unattached.SNK
                        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), 0x00);
                        ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);
                    }

                    // [0x6630] Change Back to HW Mode, Clear (hw_done_irq) & (hw_unattach_irq), Disable hw_unattach_irq_en
                    // [7] tpc_cc_mode_sel = 1
                    // [6] hw_mode_fsm_rst = 1, Normal FSM Running
                    // [3] hw_done_irq     = 1
                    // [1] hw_unattach_irq = 1
                    // [0] hw_unattach_irq_en = _DISABLE
                    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT6 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT6 | _BIT3 | _BIT1));

                    // Do Type C Unattach Flow (ADC / PD / CC Reset), and Start HW CC Connection Detection (Enable hw_done_irq_en)
                    ScalerTypeCRx0CcUnattachFlow_EXINT0();

                    CLR_CC_RX0_ACCESSORY_STATE();
                }
                else
                {
                    // Enable CC1/ CC2 Change IRQ
                    ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                }
            }
            else if(GET_CC_RX0_ATTACHED() == _TRUE)
            {
                if((GET_RX0_REG_CC_STATE() == _ATTACHED_SRC) && (ScalerTypeCRx0PdGetPowerRoleSwapProcessing_EXINT0() == _FALSE))
                {   // For (SRC & Not in PR_Swap Flow) : Check if SRC-Rd is Removed, Do Unattach Flow

                    // Clear IRQ and Popup Digital Detect Result
                    ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT5 | _BIT0), (_BIT7 | _BIT5 | _BIT0));

                    // [0x662B] [5:3]: CC1 = OPEN or [2:0]: CC2 = OPEN, Take Unattach Flow
                    if(((ScalerGetByte_EXINT(P66_2B_CC_DIG_DET_R) & (_BIT5 | _BIT4 | _BIT3)) == 0x00) || ((ScalerGetByte_EXINT(P66_2B_CC_DIG_DET_R) & (_BIT2 | _BIT1 | _BIT0)) == 0x00))
                    {
                        if(GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_SRC_ONLY)
                        {
                            // [0x6635] Set HW State to Unattached.SRC
                            ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), 0x00);
                            ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
                        }
                        else
                        {
                            // [0x6635] Set HW State to Unattached.SNK
                            ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), 0x00);
                            ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);
                        }

                        // [0x6630] : [6] hw_mode_fsm_rst, [3] hw_done_irq, [1] hw_unattach_irq
                        // Change Back to Normal FSM Running, Clear (hw_done_irq) & (hw_unattach_irq)
                        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), (_BIT6 | _BIT3 | _BIT1));

                        // Do Type C Unattach Flow (ADC / PD / CC Reset), and Start HW CC Connection Detection (Enable hw_done_irq_en)
                        ScalerTypeCRx0CcUnattachFlow_EXINT0();
                    }
                    else
                    {
                        // Enable CC1/ CC2 Change IRQ
                        ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                    }
                }
                else if((GET_RX0_REG_CC_STATE() == _ATTACHED_SNK) && (ScalerTypeCRx0PdGetPowerRoleSwapProcessing_EXINT0() == _FALSE))
                {   // For (SNK & Not in PR_Swap Flow) : Check if SRC-Rp is Removed, Do Unattach Flow

                    // Clear IRQ and Popup Digital Detect Result
                    ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT5 | _BIT0), (_BIT7 | _BIT5 | _BIT0));

                    // [0x662B] [5:3]: CC1 = OPEN / [2:0]: CC2 = OPEN, Take Unattach Flow
                    if((ScalerGetByte_EXINT(P66_2B_CC_DIG_DET_R) & (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x00)
                    {
                        // [0x6635] Set HW State to Unattached.SNK
                        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), 0x00);
                        ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);

                        // [0x6630] : [6] hw_mode_fsm_rst, [3] hw_done_irq, [1] hw_unattach_irq
                        // Change Back to Normal FSM Running, Clear (hw_done_irq) & (hw_unattach_irq)
                        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), (_BIT6 | _BIT3 | _BIT1));

                        // Do Type C Unattach Flow (ADC / PD / CC Reset), and Start HW CC Connection Detection (Enable hw_done_irq_en)
                        ScalerTypeCRx0CcUnattachFlow_EXINT0();
                    }
                    else
                    {
                        // Enable CC1/ CC2 Change IRQ
                        ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                    }
                }
                else
                {
                    // Enable CC1/ CC2 Change IRQ
                    ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                }
            }
            else
            {
                ScalerSetBit_EXINT(P65_03_PD_TOP_RST, ~_BIT5, 0x00);
                ScalerSetBit_EXINT(P65_03_PD_TOP_RST, ~_BIT5, _BIT5);
                ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT5));
            }
        }
    }

    if(ScalerGetBit_EXINT(P66_58_DBCC_SNK_DET_COND, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
    {
        // DRP Try Src FW Solution : (hw_try_wait_snk_irq == 1) && (hw_try_wait_snk_irq_en == Enable)
        // [0x6658] : [1] hw_try_wait_snk_irq, [0] hw_try_wait_snk_irq_en
        // Clear and Disable hw_try_wait_snk_irq
        ScalerSetBit_EXINT(P66_58_DBCC_SNK_DET_COND, ~(_BIT3 | _BIT1 | _BIT0), _BIT1);

        if(GET_CC_RX0_CONNECT_EN() == _TRUE)
        {
            // [0x6630] : [3] hw_done_irq, [2] hw_done_irq_en, [1] hw_unattach_irq, [0] hw_unattach_irq_en
            // Disable hw_done_irq and hw_unattach_irq
            ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

            // Set TryWait.Snk to Attached.SNK Flag
            SET_TYPE_C_RX0_TRY_WAIT_SNK_STATE();

            // Do Unattach Flow When HW FSM Transition from Attached.SRC to TryWait.SNK
            if(GET_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK() == _TRUE)
            {
                // Clr Attached.SRC to TryWait.Snk Flag
                CLR_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();

                CLR_CC_RX0_ATTACHED();

                SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_CONNECTING);

                // Disable BMC Channel
                ScalerTypeCRx0CcSetBMC_EXINT0(_DISABLE);

                // Turn Off Vconn & Vbus Power
                ScalerTypeCRx0CcVconnControl_EXINT0(_OFF);
                ScalerTypeCPowerRx0VbusControl_EXINT0(_OFF, _PD_POWER_SNK, _PD_NONE_SETTING_PDO, 0, 0, _PD_PEAK_CUR_NONE);
#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
                // Turn On Vbus Discharge
                ScalerTypeCPmicRx0VbusDischarge_EXINT0(_ENABLE);

                // Active WD Timer Event To Detect if Vbus is Already Discharge to vSafe0V
                ScalerTimerWDActivateTimerEvent_EXINT0(_UNATTACH_VBUS_DISCHARGE_TIMER, _SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V);
#endif

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
                // [Eizo] SIC437A Customized Power Control : SRC/SNK Unattach
                ScalerTypeCPmicRx0UnattachProc_EXINT0(ScalerTypeCRx0PdGetPowerRole_EXINT0());
#endif
                // Reset PD
                ScalerTypeCRx0PdReset_EXINT0();

                // [0x660C] Connect CC1/2 Channel
                // [7] tpc_cc1_det_en = _TYPE_C_CONNECT
                // [6] tpc_cc2_det_en = _TYPE_C_CONNECT
                // [5] tpc_cc1_channel_en = _TYPE_C_CONNECT
                // [4] tpc_cc2_channel_en = _TYPE_C_CONNECT
                ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }

            // [0x665A/5B] Setting FW Mode Rd Resistor
            ScalerSetByte_EXINT(P66_5A_CC_FW_CC1_Z_CFG, _BIT7);
            ScalerSetByte_EXINT(P66_5B_CC_FW_CC2_Z_CFG, _BIT7);

            // [0x6630] Change to FW Mode to Detect Attach or Unattach
            // [7] tpc_cc_mode_sel = 0
            ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT3 | _BIT1), 0x00);

            // Set Power Role for Detecting CC1/CC2 Resistor = SNK
            ScalerSetBit_EXINT(P66_2B_CC_DIG_DET_R, ~_BIT7, _BIT7);

            // Set Vth2/Vth3 to 660mV/1230mV
            ScalerSetByte_EXINT(P66_28_VTH_SEL, 0x00);

            // Set Double CC as SNK Detect Open-Open Enable Bit
            ScalerSetBit_EXINT(P66_58_DBCC_SNK_DET_COND, ~(_BIT4 | _BIT3 | _BIT1), _BIT4);

            // Set De-Bounce Threshold For Open-Open ([1:0] tPDDebounce = b'01)
            ScalerSetBit_EXINT(P66_55_DBCC_SNK_DB_SEL, ~(_BIT1 | _BIT0), _BIT0);

            // Set Double CC De-glitch
            ScalerSetBit_EXINT(P66_50_DBCC_DGH_EN, ~_BIT0, _BIT0);
            ScalerSetByte_EXINT(P66_51_DBCC_DGH_TH, ScalerGetByte_EXINT(P66_05_CC1_DGH_LV));

            // [0x6641/42] Clear & Enable dbcc_det_irq
            ScalerSetBit_EXINT(P66_41_CC_FW_DET_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT7);
            ScalerSetBit_EXINT(P66_42_CC_FW_DET_INT_EN, ~_BIT7, _BIT7);

            // Unattach Condition : CC = Open + Open for tPDDebounce
            // Enable Both CC Detect Equal Condition
            ScalerSetBit_EXINT(P66_40_CC_FW_DET_CTRL, ~_BIT7, _BIT7);

            // Attach Condition : After tCCDebounce & Vbus Detected
            // Active WD Timer Event To Detect Vbus 5V After tCCDebounce
            ScalerTimerWDActivateTimerEvent_EXINT0(110, _SCALER_WD_TIMER_EVENT_CC_RX0_DETECT_VBUS);
        }
    }

    if((ScalerGetBit_EXINT(P66_41_CC_FW_DET_INT, _BIT7) == _BIT7) && (ScalerGetBit_EXINT(P66_42_CC_FW_DET_INT_EN, _BIT7) == _BIT7))
    {
        // DRP Try Src FW Solution : When Both CC Detect Open-Open for tPDDebounce, Set HW State to Unattached.SNK
        // [0x6641/42] Clear & Disable dbcc_det_irq
        ScalerSetBit_EXINT(P66_41_CC_FW_DET_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT7);
        ScalerSetBit_EXINT(P66_42_CC_FW_DET_INT_EN, ~_BIT7, 0x00);

        if(GET_CC_RX0_CONNECT_EN() == _TRUE)
        {
            // Cancel WDTimerEvent
            ScalerTimerWDCancelTimerEvent_EXINT0(_SCALER_WD_TIMER_EVENT_CC_RX0_DETECT_VBUS);

            // Disable [adc0_comp_vbus_on_en]
            ScalerTypeCPowerVbusCompIntControl_EXINT0(_TYPE_C_A0_UFP_VBUS, _ON, _DISABLE);

            // Clear TryWait.Snk to Attached.SNK Flag
            CLR_TYPE_C_RX0_TRY_WAIT_SNK_STATE();

            // [0x6635] Set HW State to Unattached.SNK
            ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), 0x00);
            ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);

            // [0x6630] : [7] tpc_cc_mode_sel, [6] hw_mode_fsm_rst, [3] hw_done_irq, [1] hw_unattach_irq
            // Change Back to HW Mode, Clear (hw_done_irq) & (hw_unattach_irq)
            ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT6 | _BIT3 | _BIT1), (_BIT7 | _BIT6 | _BIT3 | _BIT1));

            // Do Type C Unattach Flow (ADC / PD / CC Reset), and Start HW CC Connection Detection (Enable hw_done_irq_en)
            ScalerTypeCRx0CcUnattachFlow_EXINT0();
        }
    }
}

//--------------------------------------------------
// Description  : Check If All CC Enabled IRQ is Clear Or Not
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
BYTE ScalerTypeCRx0CcIntClrCheck_EXINT0(void) using 1
{
    // Return False, if Any of IRQs is Enabled and Has Not Been Processed
    if((ScalerGetBit_EXINT(P66_71_CC1_VCONN_OCP_INT, (_BIT5 | _BIT1)) == (_BIT5 | _BIT1)) ||
       (ScalerGetBit_EXINT(P66_72_CC2_VCONN_OCP_INT, (_BIT5 | _BIT1)) == (_BIT5 | _BIT1)) ||
       (ScalerGetBit_EXINT(P66_30_CC_HW_MODE_CTRL, (_BIT3 | _BIT2)) == (_BIT3 | _BIT2)) ||
       (ScalerGetBit_EXINT(P66_30_CC_HW_MODE_CTRL, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0)) ||
       (ScalerGetBit_EXINT(P66_2C_CC_R_CHG_INT, (_BIT5 | _BIT4)) == (_BIT5 | _BIT4)))
    {
        return _FALSE;
    }
    else
    {
        return _TRUE;
    }
}

//--------------------------------------------------
// Description  : Timer Event Proc of CC RX0
// Input Value  : enumEventID
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcTimerEventProc(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
        case _SCALER_TIMER_EVENT_CC_RX0_STATE_TO_UNATTACH:

            SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_UNATTACH);

            break;

        case _SCALER_TIMER_EVENT_CC_RX0_CLEAR_AC_ON_DEVICE_DETECT:

            SET_TYPE_C_RX0_AC_ON_DEVICE_DETECT(_FALSE);

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : WD Timer Event Proc of CC RX0
// Input Value  : enumEventID, pucActiveWDID, pucActiveWDTime
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcWDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID, BYTE *pucActiveWDID, BYTE *pucActiveWDTime) using 3
{
    pucActiveWDID = pucActiveWDID;
    pucActiveWDTime = pucActiveWDTime;

    switch(enumEventID)
    {
        case _SCALER_WD_TIMER_EVENT_CC_RX0_DETECT_VBUS:

            // Set Vbus On/Off Detection Threshold to vSafe5V(4.6V) to Detect Vbus On
            ScalerTypeCPowerVbusCompThrSetting_WDINT(_TYPE_C_A0_UFP_VBUS, _ON, GET_TYPE_C_5V_LOW_BND());
            ScalerTypeCPowerVbusCompThrSetting_WDINT(_TYPE_C_A0_UFP_VBUS, _OFF, GET_TYPE_C_5V_LOW_BND());

            // Enable [adc0_comp_vbus_on_en], and Wait ADC VbusSafe5V [adc0_comp_vbus_on] INT Triggered, then Set HW FSM to Attached.SNK
            ScalerTypeCPowerVbusCompIntControl_WDINT(_TYPE_C_A0_UFP_VBUS, _ON, _ENABLE);

            break;

#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
        case _SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V:

            if(ScalerTypeCPowerRx0CheckVbusSafe0V_WDINT() == _TRUE)
            {
                ScalerTypeCPmicRx0VbusDischarge_WDINT(_DISABLE);
            }
            else
            {
                *pucActiveWDID = _SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V;
                *pucActiveWDTime = _UNATTACH_VBUS_DISCHARGE_TIMER;
            }

            break;
#endif

#if((_TYPE_C_EMB_CTS_FLOW == _ON) && (_HW_TYPE_C_FUNCTION_GEN == _TYPE_C_FUNCTION_GEN_1))
        case _SCALER_WD_TIMER_EVENT_CC_RX0_CHANGE_VBUS_OFF_THRESHOLD:

            // Lecroy [TD.4.5.4] and [TD.4.7.2], RL6561 FW Solution to Disable vSafe0V Check from Unattached.SRC to AttachWait.SRC
            // Check if CC HW FSM have already Entered AttachWait.SRC
            if(GET_RX0_REG_CC_STATE() == _ATTACHWAIT_SRC)
            {
                // Set Vbus_Off_Thr to vSafe0V to Normally Operate CC HW FSM from AttachWait.SRC to Try.SNK or to Attached.SRC
                ScalerTypeCPowerVbusCompThrSetting_WDINT(_TYPE_C_A0_UFP_VBUS, _ON, GET_TYPE_C_0V_UP_BND());
                ScalerTypeCPowerVbusCompThrSetting_WDINT(_TYPE_C_A0_UFP_VBUS, _OFF, GET_TYPE_C_0V_UP_BND());

                CLR_TYPE_C_RX0_CHANGE_VBUS_OFF_THR();
            }
            else
            {
                // CC HW FSM haven't Entered AttachWait.SRC yet. Active another WD Timer Event until Entering AttachWait.SRC.
                *pucActiveWDID = _SCALER_WD_TIMER_EVENT_CC_RX0_CHANGE_VBUS_OFF_THRESHOLD;
                *pucActiveWDTime = 80;
            }

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : CC De-Glitch          [0x6605 / 0x6606]
// Input Value  : enumTypeCChannel  : _TYPE_C_CC1(0) / _TYPE_C_CC2(1)
//                ucTime    : 0-63
//                enumUnit  : _TYPE_C_UNIT_1US / _TYPE_C_UNIT_10US / _TYPE_C_UNIT_100US / _TYPE_C_UNIT_1MS
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcSetDeglitch(EnumTypeCChannel enumTypeCChannel, BYTE ucTime, EnumDeglitchUnit enumUnit)
{
    // [0x6605] Setting CC1 De-glitch Time Value
    // [0x6606] Setting CC2 De-glitch Time Value
    if(ucTime < 64)
    {
        // [5:0] tpc_cc1_dgh_lv / tpc_cc2_dgh_lv = ucTime
        ScalerSetByte(P66_05_CC1_DGH_LV + enumTypeCChannel, ucTime);

        switch(enumUnit)
        {   // Setting De-glitch Level For Valid Input

            case _TYPE_C_UNIT_1US:
                // [7:6] tpc_cc1_dgh_lv / tpc_cc2_dgh_lv = b'00
                ScalerSetBit(P66_05_CC1_DGH_LV + enumTypeCChannel, ~(_BIT7 | _BIT6), 0x00);
                break;
            case _TYPE_C_UNIT_10US:
                // [7:6] : tpc_cc1_dgh_lv / tpc_cc2_dgh_lv = b'01
                ScalerSetBit(P66_05_CC1_DGH_LV + enumTypeCChannel, ~(_BIT7 | _BIT6), _BIT6);
                break;
            case _TYPE_C_UNIT_100US:
                // [7:6] : tpc_cc1_dgh_lv / tpc_cc2_dgh_lv = b'10
                ScalerSetBit(P66_05_CC1_DGH_LV + enumTypeCChannel, ~(_BIT7 | _BIT6), _BIT7);
                break;
            case _TYPE_C_UNIT_1MS:
            default:
                // [7:6] : tpc_cc1_dgh_lv / tpc_cc2_dgh_lv = b'11
                ScalerSetBit(P66_05_CC1_DGH_LV + enumTypeCChannel, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
                break;
        }
    }
    else
    {   // Setting De-glitch Level to Default Value (1us) For Invalid Input
        ScalerSetByte(P66_05_CC1_DGH_LV + enumTypeCChannel, 0x01);
    }   // End of if(ucTime < 64)
}

//--------------------------------------------------
// Description  : Set tCCDeBounce / tPDDebounce [0x6607 / 0x6608]
// Input Value  : bDbType   : _TYPE_C_CC / _TYPE_C_PD
//                ucTime    : 0-255
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcSetDebounce(bit bDbType, BYTE ucTime)
{
    if(bDbType == _TYPE_C_CC)
    {   // [0x6607] tCCDebounce = 100-200ms
        // tpc_db_time_tcc = ucTime
        ScalerSetByte(P66_07_TPC_TCC_DB_TIME, ucTime);
    }
    else
    {   // [0x6608] tPDDebounce = 10-20ms
        if((ucTime >= 10) && (ucTime <= 20))
        {   // tpc_db_time_tpd = ucTime
            ScalerSetByte(P66_08_TPC_TPD_DB_TIME, ucTime);
        }
        else
        {   // tpc_db_time_tpd = 15 ms
            ScalerSetByte(P66_08_TPC_TPD_DB_TIME, 20);
        }
    }
}

//--------------------------------------------------
// Description  : Type C Unattach Flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcUnattachFlow_EXINT0(void) using 1
{
    // Turn Off Vconn & Vbus Power
    ScalerTypeCRx0CcVconnControl_EXINT0(_OFF);
    ScalerTypeCPowerRx0VbusControl_EXINT0(_OFF, _PD_POWER_SNK, _PD_NONE_SETTING_PDO, 0, 0, _PD_PEAK_CUR_NONE);
#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
    // Turn On Vbus Discharge
    ScalerTypeCPmicRx0VbusDischarge_EXINT0(_ENABLE);

    // Active WD Timer Event To Detect if Vbus is Already Discharge to vSafe0V
    ScalerTimerWDActivateTimerEvent_EXINT0(_UNATTACH_VBUS_DISCHARGE_TIMER, _SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V);
#endif

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
    // [Eizo] SIC437A Customized Power Control : SRC/SNK Unattach
    ScalerTypeCPmicRx0UnattachProc_EXINT0(ScalerTypeCRx0PdGetPowerRole_EXINT0());
#endif

    // Cancel AC_ON_CABLE_DETECT Timer Event & Clear AC_ON_DEVICE_DETECT flag when HW Unattach Event Triggered to update & maintain AC_ON_DEVICE_DETECT flag _False
    ScalerTimerCancelTimerEvent_EXINT0(_SCALER_TIMER_EVENT_CC_RX0_CLEAR_AC_ON_DEVICE_DETECT);
    SET_TYPE_C_RX0_AC_ON_DEVICE_DETECT(_FALSE);

    // 1. Reset to Unattached State (From Attached Back to Unattach : PD => Power => CC)
    ScalerTypeCRx0PdReset_EXINT0();
    // FW Solution : Samsung S8 Clear Flag When CC Unattach (Not Cleared When PD Reset)
    ScalerTypeCRx0PdClrInteropS8Flag_EXINT0();
    ScalerTypeCPowerRx0UnattachReset_EXINT0();
    ScalerTypeCRx0CcUnattachReset_EXINT0();

    // 2. Setting For Connection
    ScalerTypeCRx0CcConnectionSet_EXINT0();

    // 3. State Transition
    SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_CONNECTING);

#if((_TYPE_C_EMB_CTS_FLOW == _ON) && (_HW_TYPE_C_FUNCTION_GEN == _TYPE_C_FUNCTION_GEN_1))
    // Lecroy [TD.4.5.4] and [TD.4.7.2], RL6561 FW Solution to Disable vSafe0V Check from Unattached.SRC to AttachWait.SRC
    // Set Macro and Enable [adc0_comp_vbus_off_en], then Active WD Timer Event to Dynamically Change Vbus_Off_Thr to vSafe0V when [adc0_comp_vbus_on] INT Triggered.
    // Note : Since _TYPE_C_FUNCTION_GEN_1 (RL6492) Do Not Have PD Timer Register, The FW Solution in S2_1P is Different from S3.
    SET_TYPE_C_RX0_CHANGE_VBUS_OFF_THR();
    ScalerTypeCPowerVbusCompIntControl_EXINT0(_TYPE_C_A0_UFP_VBUS, _OFF, _ENABLE);
#endif
}

//--------------------------------------------------
// Description  : Type C Unattach (Turn Off Power / Disconnect Channel / Clear IRQs)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcUnattachReset(void)
{
    // Turn Off Vbus / Vconn, if they are turned on when attached
    ScalerTypeCRx0CcVconnControl(_OFF);

    // Only Initial to Unattach & Error Recovery Will Use Mainloop's Unattach Reset, so It's Allowed Some Delay Times When Vbus Discharge
#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
    // Enable Vbus Discharge For Source to Discharge 5V
    ScalerTypeCPmicRx0VbusDischarge(_ENABLE);

    {
        BYTE ucVbusDischargeCnt = 0;

        // Polling Until Vbus Discharge to 0V For At Most 5 times
        while((ucVbusDischargeCnt < 5) && (ScalerTypeCPowerRx0CheckVbusSafe0V() == _FALSE))
        {
            ucVbusDischargeCnt += 1;
            ScalerTimerDelayXms(1);
        }
    }

    // Disable Vbus Discharge
    ScalerTypeCPmicRx0VbusDischarge(_DISABLE);
#endif

// =============================== Control By Power Delivery ??? ===============================
#if(_TYPE_C_EMB_PD3_FRSWAP_SUPPORT == _ON)
    // Disable FR_SWAP and FR_SWAP Bypass, if it is turned on when attached
    if((GET_RX0_SRC_FRSWAP_STATUS() == _ENABLE) || (GET_RX0_SNK_FRSWAP_STATUS() == _ENABLE))
    {
        ScalerTypeCRx0CcFastRoleSwapControl(_DISABLE);
        SET_RX0_SRC_FRSWAP_STATUS(_DISABLE);
        SET_RX0_SNK_FRSWAP_STATUS(_DISABLE);
    }
#endif
// =============================================================================================

    // [0x6630] Reset CC HW FSM
    // [6] hw_mode_fsm_rst = 0, [2] hw_done_irq_en = _DISABLE, [0] hw_unattach_irq_en = _DISABLE
    if(GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_SRC_ONLY)
    {
        // CTS FW Solution to Transit to Unattached.SRC (hw_mode_fsm_rst = 1 (Normal FSM Running))
        ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~(_BIT2 | _BIT0), 0x00);
    }
    else
    {
        ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT2 | _BIT0), 0x00);
    }

    // [0x660C] Disconnect CC1/2 Channel, Detect Circuit
    // [7] tpc_cc1_det_en     = _TYPE_C_DISCONNECT
    // [6] tpc_cc2_det_en     = _TYPE_C_DISCONNECT
    // [5] tpc_cc1_channel_en = _TYPE_C_DISCONNECT
    // [4] tpc_cc2_channel_en = _TYPE_C_DISCONNECT
    ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Disable CC1/2 to BMC and Disable BMC Tx/Rx
    ScalerTypeCRx0CcSetBMC(_DISABLE);

    // Clear and Disable CC1/2_R_CHG_INT     [0x662C] = b'1010_0000
    ScalerSetBit(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));

    // CC Flags Reset
    CLR_CC_RX0_ATTACHED();
    CLR_CC_RX0_RA_EXIST();
    CLR_TYPE_C_ERROR_RECOVERY();
    CLR_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();
    CLR_TYPE_C_RX0_TRY_WAIT_SNK_STATE();
#if(_TYPE_C_EMB_UNATTACH_HW_FORCE_VBUS_OFF == _OFF)
    // Tool Not Show Warning UI when CC Unattach
    ScalerTypeCRx0CcToolWarningUIControl(_DISABLE);
#endif

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
    DebugMessageTypeC("O Type C State : UNATTACH", GET_TYPE_C_RX0_ATTACH_STATUS());
    DebugMessageTypeC("    [CC/RST] Vbus Status : ", GET_RX0_VBUS_STATUS());
    DebugMessageTypeC("    [CC/RST] Attach Status : ", GET_CC_RX0_ATTACHED());
#endif
}

//--------------------------------------------------
// Description  : Type C Unattach Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcUnattachReset_EXINT0(void) using 1
{
// =============================== Control By Power Delivery ??? ===============================
#if(_TYPE_C_EMB_PD3_FRSWAP_SUPPORT == _ON)
    // Disable FR_SWAP and FR_SWAP Bypass, if it is turned on when attached
    if((GET_RX0_SRC_FRSWAP_STATUS() == _ENABLE) || (GET_RX0_SNK_FRSWAP_STATUS() == _ENABLE))
    {
        ScalerTypeCRx0CcFastRoleSwapControl_EXINT0(_DISABLE);
        SET_RX0_SRC_FRSWAP_STATUS(_DISABLE);
        SET_RX0_SNK_FRSWAP_STATUS(_DISABLE);
    }
#endif
// =============================================================================================

    // If Source Only, Do FW Mode Unattach, and Set HW FSM to Unattached.SRC
    if(GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_SRC_ONLY)
    {
        ScalerTypeCRx0CcFWModeSRCUnattached_EXINT0();
    }

    // Disable CC1/2 to BMC and Disable BMC Tx/Rx
    ScalerTypeCRx0CcSetBMC_EXINT0(_DISABLE);

    // Clear and Disable CC1/2_R_CHG_INT     [0x662C] = b'1010_0000
    ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));

    // CC Flags Reset
    CLR_CC_RX0_ATTACHED();
    CLR_CC_RX0_RA_EXIST();
    CLR_TYPE_C_ERROR_RECOVERY();
    CLR_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();
    CLR_TYPE_C_RX0_TRY_WAIT_SNK_STATE();
#if(_TYPE_C_EMB_UNATTACH_HW_FORCE_VBUS_OFF == _OFF)
    // Tool Not Show Warning UI when CC Unattach
    ScalerTypeCRx0CcToolWarningUIControl_EXINT0(_DISABLE);
#endif
}

//--------------------------------------------------
// Description  : Type C Setting For Connection (Select Resistor / Initial State / Connect Channels)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcConnectionSet(void)
{
// ===================================== DRP / SRC Switch =====================================
    // [0x6631] [6:5] HW Mode Type-C Port Role Setting (00:SRC-Only / 01:SNK-Only / 11:DRP)
    // [0x6635] [7:4] Set Initail State (0000: Unattach.SRC / 0001 : Unattach.SNK)
    if(GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_SRC_ONLY)
    {
        // [6:5] Source-Only Port ([4:3] Not Support Try.SRC/SNK)
        ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);
        ScalerSetBit(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    }
    else if(GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_SNK_ONLY)
    {
        // [6:5] Sink-Only Port ([4:3] Not Support Try.SRC/SNK)
        ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT5);
        ScalerSetBit(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);
    }
    else
    {
        // ======================= DRP Mode =======================
        // [6:5] Dual Role Port ([4:3] Support Try.SRC/SNK)
        ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));
        ScalerSetBit(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);

        // Try.SRC/SNK Setting [4] Try.SRC [3] Try.SNK
        if(GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SNK)
        {
            ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~(_BIT4 | _BIT3), _BIT3);
        }
        else if(GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC)
        {
            ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~(_BIT4 | _BIT3), _BIT4);
        }
        else
        {
            ScalerSetBit(P66_31_CC_HW_MODE_CFG, ~(_BIT4 | _BIT3), 0x00);
        }
    }
// ===========================================================================================

#if(_TYPE_C_CC_CONNECT_MODE == _TYPE_C_HW_MODE)

    // [0x6637][7:6] Setting SRC Rp Resistor (36K / 12K / 4.7K)
#if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)
    ScalerSetBit(P66_37_CC_HW_Z_CFG, ~(_BIT7 | _BIT6), (_SET_RP_DEF << 6));
    SET_CC_RX0_DEF_CUR(90);  // 90 * 10mA = 900mA
#elif(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_1P5A)
    ScalerSetBit(P66_37_CC_HW_Z_CFG, ~(_BIT7 | _BIT6), (_SET_RP_1P5A << 6));
    SET_CC_RX0_DEF_CUR(150); // 150 * 10mA = 1.5A
#else
    ScalerSetBit(P66_37_CC_HW_Z_CFG, ~(_BIT7 | _BIT6), (_SET_RP_3P0A << 6));
    SET_CC_RX0_DEF_CUR(300); // 300 * 10mA = 3.0A
#endif  // End of #if(_TYPE_C_EMB_SRC_DEF_CUR == _SRC_DEF_USB)

    // [5:4] Setting SNK CC1 Resistor
    ScalerSetBit(P66_37_CC_HW_Z_CFG, ~(_BIT5 | _BIT4), (_SET_RD << 4));
    // [3:2] Setting SNK CC2 Resistor
    ScalerSetBit(P66_37_CC_HW_Z_CFG, ~(_BIT3 | _BIT2), (_SET_RD << 2));

#endif  // End of #if(_TYPE_C_CC_CONNECT_MODE == _TYPE_C_HW_MODE)

    // [0x660C] Connect CC1/2 Channel
    // [7] tpc_cc1_det_en = _TYPE_C_CONNECT
    // [6] tpc_cc2_det_en = _TYPE_C_CONNECT
    // [5] tpc_cc1_channel_en = _TYPE_C_CONNECT
    // [4] tpc_cc2_channel_en = _TYPE_C_CONNECT
    ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

#if(_TYPE_C_CC_CONNECT_MODE == _TYPE_C_HW_MODE)
    // [0x6630] Enable HW Mode, Release Reset : Enable connect_en and Clear IRQs
    // [6] hw_mode_fsm_rst = 0
    // [5] hw_connect_en = _DISABLE
    // [3] hw_done_irq  = 1
    // [2] hw_done_irq_en = _DISABLE
    // [1] hw_unattach_irq = 1
    // [0] hw_unattach_irq_en = _DISABLE
    ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT6 | _BIT3 | _BIT2 | _BIT1));

    if((GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_DRP) && (GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC))
    {
        // DRP Try Src FW Solution
        // [0x6658] : [1] hw_try_wait_snk_irq, [0] hw_try_wait_snk_irq_en
        // Clear and Enable hw_try_wait_snk_irq
        ScalerSetBit(P66_58_DBCC_SNK_DET_COND, ~(_BIT3 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
    }
#else
    // FW_MODE Reset
    ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));
#endif

    // Active Timer Event to clear AC_ON_CABLE_DETECT flag if Not Attached in 500 ms
    ScalerTimerActiveTimerEvent(500, _SCALER_TIMER_EVENT_CC_RX0_CLEAR_AC_ON_DEVICE_DETECT);

    // Enable CC1/CC2 and Vbus Detect
    ScalerTypeCRx0CcVbusDetCtrl(_ENABLE);
    ScalerSetBit(P66_2B_CC_DIG_DET_R, ~_BIT6, _BIT6);

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
    DebugMessageTypeC("O Type C State : CONNECTING...", GET_TYPE_C_RX0_ATTACH_STATUS());
    DebugMessageTypeC("    [CC/Connect Set] Default Current : ", GET_CC_RX0_DEF_CUR());
#endif
}

//--------------------------------------------------
// Description  : Type C Setting For Connection (Connect Channels)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcConnectionSet_EXINT0(void) using 1
{
#if(_TYPE_C_CC_CONNECT_MODE == _TYPE_C_HW_MODE)

    // [0x6637][7:6] Setting SRC Rp Resistor (36K / 12K / 4.7K)
#if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)
    ScalerSetBit_EXINT(P66_37_CC_HW_Z_CFG, ~(_BIT7 | _BIT6), (_SET_RP_DEF << 6));
    SET_CC_RX0_DEF_CUR(90);  // 90 * 10mA = 900mA
#elif(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_1P5A)
    ScalerSetBit_EXINT(P66_37_CC_HW_Z_CFG, ~(_BIT7 | _BIT6), (_SET_RP_1P5A << 6));
    SET_CC_RX0_DEF_CUR(150); // 150 * 10mA = 1.5A
#else
    ScalerSetBit_EXINT(P66_37_CC_HW_Z_CFG, ~(_BIT7 | _BIT6), (_SET_RP_3P0A << 6));
    SET_CC_RX0_DEF_CUR(300); // 300 * 10mA = 3.0A
#endif  // End of #if(_TYPE_C_EMB_SRC_DEF_CUR == _SRC_DEF_USB)

#endif  // End of #if(_TYPE_C_CC_CONNECT_MODE == _TYPE_C_HW_MODE)

    // [0x660C] Connect CC1/2 Channel
    // [7] tpc_cc1_det_en = _TYPE_C_CONNECT
    // [6] tpc_cc2_det_en = _TYPE_C_CONNECT
    // [5] tpc_cc1_channel_en = _TYPE_C_CONNECT
    // [4] tpc_cc2_channel_en = _TYPE_C_CONNECT
    ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

#if(_TYPE_C_CC_CONNECT_MODE == _TYPE_C_HW_MODE)
    // [0x6630] : [3] hw_done_irq, [2] hw_done_irq_en, [1] hw_unattach_irq, [0] hw_unattach_irq_en
    // Enable hw_done_irq, Disable hw_unattach_irq and Clear IRQs
    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1));

    if((GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_DRP) && (GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC))
    {
        // DRP Try Src FW Solution
        // [0x6658] : [1] hw_try_wait_snk_irq, [0] hw_try_wait_snk_irq_en
        // Clear and Enable hw_try_wait_snk_irq
        ScalerSetBit_EXINT(P66_58_DBCC_SNK_DET_COND, ~(_BIT3 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
    }
#else
    // FW_MODE Reset
    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));
#endif

    // Enable CC1/CC2 and Vbus Detect
    ScalerTypeCRx0CcVbusDetCtrl_EXINT0(_ENABLE);
    ScalerSetBit_EXINT(P66_2B_CC_DIG_DET_R, ~_BIT6, _BIT6);
}

//--------------------------------------------------
// Description  : Set Attached Role, Resistors on CC and Orientation
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerTypeCRx0CcAttachedSetting(void)
{
    bit bPass = _FALSE;

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
    DebugMessageTypeC("O Type C State : CONNECTED!!!", GET_TYPE_C_RX0_ATTACH_STATUS());
#endif

    switch(GET_RX0_REG_CC_STATE())
    {
        case _ATTACHED_SRC:

            ScalerTypeCRx0PdSetPowerRole(_PD_POWER_SRC);

            if(ScalerGetBit(P66_33_CC_HW_FSM, (_BIT7)) == _BIT7)
            {   // Un-Flip : PD BMC Signal : CC1 / Vconn : CC2
                SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_UNFLIP);

                // Get [0x662A][3:0], Check if Ra is Presented on CC2
                if(ScalerGetBit(P66_2A_CC_ANA_DET_R, (_BIT3 | _BIT2)) == 0x00)
                {
                    SET_CC_RX0_RA_EXIST();
                }

                // [0x660C] Disconnect CC2 Detection and BMC Channel
                // [6] tpc_cc2_det_en  = _TYPE_C_DISCONNECT
                // [2] tpc_cc2_en      = _TYPE_C_DISCONNECT (Not Needed)
                ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT6 | _BIT4 | _BIT2), 0x00);

                bPass = _TRUE;
            }
            else
            {   // Flip : PD BMC Signal : CC2 / Vconn : CC1
                SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_FLIP);

                // Check if Ra is Presented on CC2
                if(ScalerGetBit(P66_2A_CC_ANA_DET_R, (_BIT7 | _BIT6)) == 0x00)
                {
                    SET_CC_RX0_RA_EXIST();
                }

                // [0x660C] Disconnect CC1 Detection and BMC Channel
                // [7] tpc_cc1_det_en  = _TYPE_C_DISCONNECT
                // [3] tpc_cc1_en      = _TYPE_C_DISCONNECT (Not Needed)
                ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT5 | _BIT3), 0x00);

                bPass = _TRUE;
            }

            break;

        case _ATTACHED_SNK:

            ScalerTypeCRx0PdSetPowerRole(_PD_POWER_SNK);

            if(ScalerGetBit(P66_33_CC_HW_FSM, (_BIT7)) == _BIT7)
            {   // Un-Flip : PD BMC Signal : CC1 / Vconn : CC2
                SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_UNFLIP);

                // [0x660C] Disconnect CC2 Detection and BMC Channel
                // [6] tpc_cc2_det_en  = _TYPE_C_DISCONNECT
                // [2] tpc_cc2_en      = _TYPE_C_DISCONNECT (Not Needed)
                ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT6 | _BIT4 | _BIT2), 0x00);

                bPass = _TRUE;
            }
            else
            {   // Flip : PD BMC Signal : CC2 / Vconn : CC1
                SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_FLIP);

                // [0x660C] Disconnect CC1 Detection and BMC Channel
                // [7] tpc_cc1_det_en  = _TYPE_C_DISCONNECT
                // [3] tpc_cc1_en      = _TYPE_C_DISCONNECT (Not Needed)
                ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT5 | _BIT3), 0x00);

                bPass = _TRUE;
            }

            break;

        case _IDLE:
        case _UNATTACHED_SNK:
        case _ATTACHWAIT_SNK:
        case _UNATTACHED_SRC:
        case _ATTACHWAIT_SRC:
        case _TRY_SRC:
        case _TRY_WAIT_SNK:
        case _TRY_SNK:
        case _TRY_WAIT_SRC:
        case _UNATTACHED_ACCESSORY:
        case _ATTACH_WAIT_ACCESSORY:
        case _POWER_ACCESSORY:
        case _UNSUPORTED_ACCESSORY:
        case _DEBUG_ACCESSORY_SNK:
        case _AUDIO_ACCESSORY:
        case _AUDIO_ACCESSORY_SRC:
        case _DEBUG_ACCESSORY_SRC:
        default:
            // Not SRC nor SNK : ERROR !!!
            bPass = _FALSE;

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
            DebugMessageTypeC("  [Error] Type C Attach Check : State FAIL!!!", GET_RX0_REG_CC_STATE());
#endif

            break;
    }

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
    if(bPass == _TRUE)
    {
        DebugMessageTypeC("    [CC/Attach Chk] : Pass ! ! ! ", GET_RX0_REG_CC_STATE());
        DebugMessageTypeC("    ----> Attach Role : SNK(0)/SRC(1)", ScalerTypeCRx0PdGetPowerRole());
        // DebugMessageTypeC("    ----> CC1 : Open/Ra/Rd/Rp-Def/Rp1.5/Rp3.0", GET_RX0_CC1_R());
        // DebugMessageTypeC("    ----> CC2 : Open/Ra/Rd/Rp-Def/Rp1.5/Rp3.0", GET_RX0_CC2_R());
        DebugMessageTypeC("    ----> Orientation : Unflip(1)/Flip(2)", GET_CC_RX0_ORIENTATION());
        DebugMessageTypeC("    ----> Ra Exist : ", GET_CC_RX0_RA_EXIST());
    }
#endif

    return bPass;
}

//--------------------------------------------------
// Description  : CC Check if Unattach Event is Triggered
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerTypeCRx0CcUnattachCheck(void)
{
    bit bUnattach = _FALSE;
    BYTE ucUnattachWaitPhyIdleCnt = 0;

    // 1. Check if Error Recovery is SET
    if(GET_TYPE_C_ERROR_RECOVERY() == _TRUE)
    {
        // [0x6630] : [3] hw_done_irq, [1] hw_unattach_irq, [0] hw_unattach_irq_en
        // Disable hw_unattach_irq to Prevent IRQ Triggered during Error Recovery
        ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

        // Polling 1ms * 5 to Check PHY Idle, Don't Do Error Recovery When BMC Is Not Idle
        while((ucUnattachWaitPhyIdleCnt < 5) && (ScalerGetBit(P65_05_PD_PHY_IDLE_INT, _BIT2) == 0x00))
        {
            ucUnattachWaitPhyIdleCnt += 1;
            ScalerTimerDelayXms(1);
        }

        if(ScalerTypeCRx0PdGetPowerRole() == _PD_POWER_SRC)
        {
#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
            // Enable Vbus Discharge For Source to Discharge 5V
            ScalerTypeCPmicRx0VbusDischarge(_ENABLE);
#endif

            // Turn Off Vbus / Vconn, if they are turned on when attached
            ScalerTypeCRx0CcVconnControl(_OFF);
            ScalerTypeCPowerRx0VbusControl(_OFF, _PD_POWER_SNK, _PD_NONE_SETTING_PDO, 0, 0, _PD_PEAK_CUR_NONE);
        }

        // Switch to FW Mode to Disconnect Both CC1 / CC2, and Wait 30ms (Should Be More Than tPDDebounce Max)
        ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, 0x00);
        ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, 0x00);
        ScalerSetByte(P66_30_CC_HW_MODE_CTRL, 0x00);
        ScalerTimerDelayXms(30);

        // Any Fatal Error Happens in PD, and Need to Unattach Type C Function
        bUnattach = _TRUE;
        CLR_TYPE_C_ERROR_RECOVERY();
    }

    if(bUnattach == _TRUE)
    {
        // Cancel AC_ON_CABLE_DETECT Timer Event & Clear AC_ON_DEVICE_DETECT flag when FW Unattach Event Triggered to update & maintain AC_ON_DEVICE_DETECT flag _False
        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_CC_RX0_CLEAR_AC_ON_DEVICE_DETECT);
        SET_TYPE_C_RX0_AC_ON_DEVICE_DETECT(_FALSE);

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
        // [Eizo] SIC437A Customized Power Control : SRC/SNK Unattach
        ScalerTypeCPmicRx0UnattachProc(ScalerTypeCRx0PdGetPowerRole());
#endif
    }

    return bUnattach;
}

//--------------------------------------------------
// Description  : Enable / Disable Vconn Power
// Input Value  : bAction : _ON / _OFF
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcVconnControl(bit bAction)
{
    if(bAction == _ENABLE)
    {
        if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
        {
            // [0x6672] Reset and Enable CC2 OCP IRQs
            // [2]cc2_vconn_prot_irq      = 1
            // [1]cc2_vconn_shutdown_irq  = 1
            // [0]cc2_vconn_on_irq        = 1
            ScalerSetBit(P66_72_CC2_VCONN_OCP_INT, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // [6] cc2_vconn_prot_irq_en    = _DISABLE
            // [5] cc2_vconn_shutdown_irq_en= _ENABLE
            // [4] cc2_vconn_on_irq_en      = _DISABLE
            ScalerSetBit(P66_72_CC2_VCONN_OCP_INT, ~(_BIT6 | _BIT5 | _BIT4), _BIT5);

            // [0x660D] Turn On CC2 Vconn Switch : [2]tpc_cc2_vconn_en= _ENABLE
            ScalerSetBit(P66_0D_TPC_OCP_CTRL, ~_BIT2, _BIT2);

            SET_RX0_VCONN_STATUS(_ON);

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
            DebugMessageTypeC("    [CC/Vconn] Vconn on CC2 : ", _TYPE_C_CC2);
            DebugMessageTypeC("    [CC/Vconn] Turn On Vconn : ", GET_RX0_VCONN_STATUS());
#endif
        }
        else if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_FLIP)
        {
            // [0x6671] Reset and Enable CC1 OCP IRQs
            // [2] cc1_vconn_prot_irq      = 1
            // [1] cc1_vconn_shutdown_irq  = 1
            // [0] cc1_vconn_on_irq        = 1
            ScalerSetBit(P66_71_CC1_VCONN_OCP_INT, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // [6] cc1_vconn_prot_irq_en    = _DISABLE
            // [5] cc1_vconn_shutdown_irq_en= _ENABLE
            // [4] cc1_vconn_on_irq_en      = _DISABLE
            ScalerSetBit(P66_71_CC1_VCONN_OCP_INT, ~(_BIT6 | _BIT5 | _BIT4), _BIT5);

            // [0x660D] Turn On CC1 Vconn Switch : [3] tpc_cc1_vconn_en= _ENABLE
            ScalerSetBit(P66_0D_TPC_OCP_CTRL, ~_BIT3, _BIT3);

            SET_RX0_VCONN_STATUS(_ON);

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
            DebugMessageTypeC("    [CC/Vconn] Vconn on CC1 : ", _TYPE_C_CC1);
            DebugMessageTypeC("    [CC/Vconn] Turn On Vconn : ", GET_RX0_VCONN_STATUS());
#endif
        }
    }
    else
    {
        // Disable CC1/CC2 Vconn IRQs
        ScalerSetByte(P66_71_CC1_VCONN_OCP_INT, 0x00);
        ScalerSetByte(P66_72_CC2_VCONN_OCP_INT, 0x00);

        // [0x660D] Turn Off Both CC1/2 Vconn Switch : [3:2] tpc_cc1/2_vconn_en= _DISABLE
        ScalerSetBit(P66_0D_TPC_OCP_CTRL, ~(_BIT3 | _BIT2), 0x00); // [0x660D] <3:2> : tpc_cc1/2_vconn_en = _DISABLE
        SET_RX0_VCONN_STATUS(_OFF);

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
        DebugMessageTypeC("    [CC/Vconn] Turn Off Vconn : ", GET_RX0_VCONN_STATUS());
#endif
    }
}

//--------------------------------------------------
// Description  : Enable / Disable Vconn Power in Interrupt
// Input Value  : bAction : _ON / _OFF
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcVconnControl_EXINT0(bit bAction) using 1
{
    if(bAction == _ENABLE)
    {
        if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
        {
            // [0x6672] Reset and Enable CC2 OCP IRQs
            // [2]cc2_vconn_prot_irq      = 1
            // [1]cc2_vconn_shutdown_irq  = 1
            // [0]cc2_vconn_on_irq        = 1
            ScalerSetBit_EXINT(P66_72_CC2_VCONN_OCP_INT, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // [6] cc2_vconn_prot_irq_en    = _DISABLE
            // [5] cc2_vconn_shutdown_irq_en= _ENABLE
            // [4] cc2_vconn_on_irq_en      = _DISABLE
            ScalerSetBit_EXINT(P66_72_CC2_VCONN_OCP_INT, ~(_BIT6 | _BIT5 | _BIT4), _BIT5);

            // [0x660D] Turn On CC2 Vconn Switch : [2]tpc_cc2_vconn_en= _ENABLE
            ScalerSetBit_EXINT(P66_0D_TPC_OCP_CTRL, ~_BIT2, _BIT2);

            SET_RX0_VCONN_STATUS(_ON);
        }
        else if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_FLIP)
        {
            // [0x6671] Reset and Enable CC1 OCP IRQs
            // [2] cc1_vconn_prot_irq      = 1
            // [1] cc1_vconn_shutdown_irq  = 1
            // [0] cc1_vconn_on_irq        = 1
            ScalerSetBit_EXINT(P66_71_CC1_VCONN_OCP_INT, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // [6] cc1_vconn_prot_irq_en    = _DISABLE
            // [5] cc1_vconn_shutdown_irq_en= _ENABLE
            // [4] cc1_vconn_on_irq_en      = _DISABLE
            ScalerSetBit_EXINT(P66_71_CC1_VCONN_OCP_INT, ~(_BIT6 | _BIT5 | _BIT4), _BIT5);

            // [0x660D] Turn On CC1 Vconn Switch : [3] tpc_cc1_vconn_en= _ENABLE
            ScalerSetBit_EXINT(P66_0D_TPC_OCP_CTRL, ~_BIT3, _BIT3);

            SET_RX0_VCONN_STATUS(_ON);
        }
    }
    else
    {
        // Disable CC1/CC2 Vconn IRQs
        ScalerSetByte_EXINT(P66_71_CC1_VCONN_OCP_INT, 0x00);
        ScalerSetByte_EXINT(P66_72_CC2_VCONN_OCP_INT, 0x00);

        // [0x660D] Turn Off Both CC1/2 Vconn Switch : [3:2] tpc_cc1/2_vconn_en= _DISABLE
        ScalerSetBit_EXINT(P66_0D_TPC_OCP_CTRL, ~(_BIT3 | _BIT2), 0x00); // [0x660D] <3:2> : tpc_cc1/2_vconn_en = _DISABLE
        SET_RX0_VCONN_STATUS(_OFF);
    }
}

//--------------------------------------------------
// Description  : Enable / Disable Vconn Power in Interrupt
// Input Value  : bAction : _ON / _OFF
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcVconnControl_WDINT(bit bAction) using 3
{
    if(bAction == _ENABLE)
    {
        if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
        {
            // [0x6672] Reset and Enable CC2 OCP IRQs
            // [2]cc2_vconn_prot_irq      = 1
            // [1]cc2_vconn_shutdown_irq  = 1
            // [0]cc2_vconn_on_irq        = 1
            ScalerSetBit_EXINT(P66_72_CC2_VCONN_OCP_INT, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // [6] cc2_vconn_prot_irq_en    = _DISABLE
            // [5] cc2_vconn_shutdown_irq_en= _ENABLE
            // [4] cc2_vconn_on_irq_en      = _DISABLE
            ScalerSetBit_EXINT(P66_72_CC2_VCONN_OCP_INT, ~(_BIT6 | _BIT5 | _BIT4), _BIT5);

            // [0x660D] Turn On CC2 Vconn Switch : [2]tpc_cc2_vconn_en= _ENABLE
            ScalerSetBit_EXINT(P66_0D_TPC_OCP_CTRL, ~_BIT2, _BIT2);

            SET_RX0_VCONN_STATUS(_ON);
        }
        else if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_FLIP)
        {
            // [0x6671] Reset and Enable CC1 OCP IRQs
            // [2] cc1_vconn_prot_irq      = 1
            // [1] cc1_vconn_shutdown_irq  = 1
            // [0] cc1_vconn_on_irq        = 1
            ScalerSetBit_EXINT(P66_71_CC1_VCONN_OCP_INT, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // [6] cc1_vconn_prot_irq_en    = _DISABLE
            // [5] cc1_vconn_shutdown_irq_en= _ENABLE
            // [4] cc1_vconn_on_irq_en      = _DISABLE
            ScalerSetBit_EXINT(P66_71_CC1_VCONN_OCP_INT, ~(_BIT6 | _BIT5 | _BIT4), _BIT5);

            // [0x660D] Turn On CC1 Vconn Switch : [3] tpc_cc1_vconn_en= _ENABLE
            ScalerSetBit_EXINT(P66_0D_TPC_OCP_CTRL, ~_BIT3, _BIT3);

            SET_RX0_VCONN_STATUS(_ON);
        }
    }
    else
    {
        // Disable CC1/CC2 Vconn IRQs
        ScalerSetByte_EXINT(P66_71_CC1_VCONN_OCP_INT, 0x00);
        ScalerSetByte_EXINT(P66_72_CC2_VCONN_OCP_INT, 0x00);

        // [0x660D] Turn Off Both CC1/2 Vconn Switch : [3:2] tpc_cc1/2_vconn_en= _DISABLE
        ScalerSetBit_EXINT(P66_0D_TPC_OCP_CTRL, ~(_BIT3 | _BIT2), 0x00); // [0x660D] <3:2> : tpc_cc1/2_vconn_en = _DISABLE
        SET_RX0_VCONN_STATUS(_OFF);
    }
}

//--------------------------------------------------
// Description  : Enable / Disable BMC Channel in CC Logic
// Input Value  : Event : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcSetBMC(bit bAction)
{
    if(bAction == _ENABLE)
    {
        // 1. [0x6625] Set SRC/SNK BMC Vth_H/L and Enable BMC Rx ([3] Tx Controlled By HW)
        if(ScalerTypeCRx0PdGetPowerRole() == _PD_POWER_SRC)
        {   // [7:6] bmc_rx/tx_en = b'10 (Enable Rx, [3] Tx Control By HW)
            // [5:4] cc_bmc_rx_th_sel = 'b00
            ScalerSetBit(P66_25_BMC_TX_RX_CFG, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT3));
        }
        else
        {   // [7:6] bmc_rx/tx_en = b'10 (Enable Rx, Tx Control By HW)
            // [5:4] cc_bmc_rx_th_sel = 'b11
            ScalerSetBit(P66_25_BMC_TX_RX_CFG, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT5 | _BIT4 | _BIT3));
        }

        // 2. [0x660C] Connect CC1 or CC2 to BMC Channel
        if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
        {
            // [3] tpc_cc1_en = _TYPE_C_CONNECT
            // [2] tpc_cc2_en = _TYPE_C_DISCONNECT (Not Needed)
            ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT3 | _BIT2), _BIT3);
        }
        else
        {
            // [3] tpc_cc1_en = _TYPE_C_DISCONNECT  (Not Needed)
            // [2] tpc_cc2_en = _TYPE_C_CONNECT
            ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT3 | _BIT2), _BIT2);
        }

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
        if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
        {
            DebugMessageTypeC("    [CC/BMC] BMC Connected to CC1", bAction);
        }
        else
        {
            DebugMessageTypeC("    [CC/BMC] BMC Connected to CC2", bAction);
        }
#endif
    }
    else
    {   // [0x6625] Disable BMC Channel
        // [7] bmc_rx_en = _DISABLE
        // [6] bmc_tx_en = _DISABLE
        ScalerSetBit(P66_25_BMC_TX_RX_CFG, ~(_BIT7 | _BIT6), 0x00);

        // [0x660C] CC1/CC2 Disconnect to BMC Channel
        // [3] tpc_cc1_en = _TYPE_C_DISCONNECT
        // [2] tpc_cc2_en = _TYPE_C_DISCONNECT
        ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT3 | _BIT2), 0x00);

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
        DebugMessageTypeC("    [CC/BMC] BMC Disconnected", bAction);
#endif
    }
}

//--------------------------------------------------
// Description  : Enable / Disable BMC Channel in CC Logic
// Input Value  : Event : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcSetBMC_EXINT0(bit bAction) using 1
{
    if(bAction == _ENABLE)
    {
        // 1. [0x6625] Set SRC/SNK BMC Vth_H/L and Enable BMC Rx ([3] Tx Controlled By HW)
        if(ScalerTypeCRx0PdGetPowerRole_EXINT0() == _PD_POWER_SRC)
        {   // [7:6] bmc_rx/tx_en = b'10 (Enable Rx, [3] Tx Control By HW)
            // [5:4] cc_bmc_rx_th_sel = 'b00
            ScalerSetBit_EXINT(P66_25_BMC_TX_RX_CFG, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT3));
        }
        else
        {   // [7:6] bmc_rx/tx_en = b'10 (Enable Rx, Tx Control By HW)
            // [5:4] cc_bmc_rx_th_sel = 'b11
            ScalerSetBit_EXINT(P66_25_BMC_TX_RX_CFG, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT5 | _BIT4 | _BIT3));
        }

        // 2. [0x660C] Connect CC1 or CC2 to BMC Channel
        if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
        {
            // [3] tpc_cc1_en = _TYPE_C_CONNECT
            // [2] tpc_cc2_en = _TYPE_C_DISCONNECT (Not Needed)
            ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT3 | _BIT2), _BIT3);
        }
        else
        {
            // [3] tpc_cc1_en = _TYPE_C_DISCONNECT  (Not Needed)
            // [2] tpc_cc2_en = _TYPE_C_CONNECT
            ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT3 | _BIT2), _BIT2);
        }
    }
    else
    {   // [0x6625] Disable BMC Channel
        // [7] bmc_rx_en = _DISABLE
        // [6] bmc_tx_en = _DISABLE
        ScalerSetBit_EXINT(P66_25_BMC_TX_RX_CFG, ~(_BIT7 | _BIT6), 0x00);

        // [0x660C] CC1/CC2 Disconnect to BMC Channel
        // [3] tpc_cc1_en = _TYPE_C_DISCONNECT
        // [2] tpc_cc2_en = _TYPE_C_DISCONNECT
        ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT3 | _BIT2), 0x00);
    }
}

//--------------------------------------------------
// Description  : Enable/Disable Detect Vbus On/Off to transit State
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcVbusDetCtrl(bit bAction)
{
    // [0x6634] [7] vbus_det_dis
    if(bAction == _ENABLE)
    {   // Enable Vbus Detection : vbus_det_dis = _DISABLE
        ScalerSetBit(P66_34_CC_HW_STATE_CTRL, ~_BIT7, 0x00);

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
        DebugMessageTypeC("    [CC/Det Vbus] Start Vbus Detect", bAction);
#endif
    }
    else
    {   // Enable Vbus Detection : vbus_det_dis = _ENABLE
        ScalerSetBit(P66_34_CC_HW_STATE_CTRL, ~_BIT7, _BIT7);

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
        DebugMessageTypeC("    [CC/Det Vbus] Stop Vbus Detect", bAction);
#endif
    }
}

//--------------------------------------------------
// Description  : Enable/Disable Detect Vbus On/Off to transit State
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcVbusDetCtrl_EXINT0(bit bAction) using 1
{
    // [0x6634] Enable Vbus Detection
    // [7] vbus_det_dis    = _ENABLE
    if(bAction == _ENABLE)
    {
        ScalerSetBit_EXINT(P66_34_CC_HW_STATE_CTRL, ~_BIT7, 0x00);
    }
    else
    {
        ScalerSetBit_EXINT(P66_34_CC_HW_STATE_CTRL, ~_BIT7, _BIT7);
    }
}

//--------------------------------------------------
// Description  : Enable/Disable Detect Vbus On/Off to transit State
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcVbusDetCtrl_WDINT(bit bAction) using 3
{
    // [0x6634] Enable Vbus Detection
    // [7] vbus_det_dis    = _ENABLE
    if(bAction == _ENABLE)
    {
        ScalerSetBit_EXINT(P66_34_CC_HW_STATE_CTRL, ~_BIT7, 0x00);
    }
    else
    {
        ScalerSetBit_EXINT(P66_34_CC_HW_STATE_CTRL, ~_BIT7, _BIT7);
    }
}

//--------------------------------------------------
// Description  : Update & Return CC Pin Resistor (Only For CC Pin, Not Vconn Pin)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerTypeCRx0CcDetResistor(void)
{
    // Only Update Resistor of CC Pin, Not Vconn Pin (Flip : [7:4] CC1, Un-Flip : [3:0] CC2)
    if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
    {
        if(ScalerGetBit(P66_2A_CC_ANA_DET_R, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0xF0)
        {
            SET_RX0_CC1_R(_DET_RP_3P0A);
        }
        else
        {
            // Setting Default Result = SinkTxNG (Rp 1.5A)
            SET_RX0_CC1_R(_DET_RP_1P5A);
        }

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
        DebugMessageTypeC("[CC]  Resistor Detect CC1", GET_CC_RX0_ORIENTATION());
        DebugMessageTypeC("[CC]  Resistor Detect Result", GET_RX0_CC1_R());
#endif
        return GET_RX0_CC1_R();
    }
    else
    {
        if(ScalerGetBit(P66_2A_CC_ANA_DET_R, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x0F)
        {
            SET_RX0_CC2_R(_DET_RP_3P0A);
        }
        else
        {
            // Setting Default Result = SinkTxNG (Rp 1.5A)
            SET_RX0_CC2_R(_DET_RP_1P5A);
        }

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
        DebugMessageTypeC("[CC]  Resistor Detect CC2", GET_CC_RX0_ORIENTATION());
        DebugMessageTypeC("[CC]  Resistor Detect Result", GET_RX0_CC2_R());
#endif
        return GET_RX0_CC2_R();
    }
}

#if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
#if(_TYPE_C_EMB_DP_ALT_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Update & Return CC Pin Resistor (Only For CC Pin, Not Vconn Pin)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerTypeCRx0CcDetResistor_EXINT0(void) using 1
{
    // Only Update Resistor of CC Pin, Not Vconn Pin (Flip : [7:4] CC1, Un-Flip : [3:0] CC2)
    if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
    {
        if(ScalerGetBit_EXINT(P66_2A_CC_ANA_DET_R, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0xF0)
        {
            SET_RX0_CC1_R(_DET_RP_3P0A);
        }
        else
        {
            // Setting Default Result = SinkTxNG (Rp 1.5A)
            SET_RX0_CC1_R(_DET_RP_1P5A);
        }

        return GET_RX0_CC1_R();
    }
    else
    {
        if(ScalerGetBit_EXINT(P66_2A_CC_ANA_DET_R, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x0F)
        {
            SET_RX0_CC2_R(_DET_RP_3P0A);
        }
        else
        {
            // Setting Default Result = SinkTxNG (Rp 1.5A)
            SET_RX0_CC2_R(_DET_RP_1P5A);
        }

        return GET_RX0_CC2_R();
    }
}

//--------------------------------------------------
// Description  : Update & Return CC Pin Resistor (Only For CC Pin, Not Vconn Pin)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerTypeCRx0CcDetResistor_WDINT(void) using 3
{
    // Only Update Resistor of CC Pin, Not Vconn Pin (Flip : [7:4] CC1, Un-Flip : [3:0] CC2)
    if(GET_CC_RX0_ORIENTATION() == _TYPE_C_ORIENTATION_UNFLIP)
    {
        if(ScalerGetBit_EXINT(P66_2A_CC_ANA_DET_R, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0xF0)
        {
            SET_RX0_CC1_R(_DET_RP_3P0A);
        }
        else
        {
            // Setting Default Result = SinkTxNG (Rp 1.5A)
            SET_RX0_CC1_R(_DET_RP_1P5A);
        }

        return GET_RX0_CC1_R();
    }
    else
    {
        if(ScalerGetBit_EXINT(P66_2A_CC_ANA_DET_R, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x0F)
        {
            SET_RX0_CC2_R(_DET_RP_3P0A);
        }
        else
        {
            // Setting Default Result = SinkTxNG (Rp 1.5A)
            SET_RX0_CC2_R(_DET_RP_1P5A);
        }

        return GET_RX0_CC2_R();
    }
}
#endif // End of #if(_TYPE_C_EMB_DP_ALT_MODE_SUPPORT == _ON)
#endif // End of #if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)

//--------------------------------------------------
// Description  : TypeC Device Detect For initial setting port-searching time
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
void ScalerTypeCRx0CcACOnDeviceDetect(void)
{
    // Notice: For extreme case: tDRP = 50ms & dcSRC.DRP = 70 %, usResistor_hold_time shall be smaller than 15ms.
    // Notice: To avoid consistency issue between devices, usResistor_hold_time should be smaller than tPDDebounce(10ms).
    WORD usResistor_hold_time = 1;
    bit bACOnDeviceDetect = _FALSE;

    // 1. global_cc_en = _ENABLE, to enable CC register to be active
    ScalerSetBit(P66_00_GLOBAL_CTL, ~_BIT7, _BIT7);

    // 2. Switch to FW Mode
    ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~_BIT7, 0x00);

    // 3. Start storing CC attach voltage result to P66_2A_CC_ANA_DET_R
    // [0x660C] Connect CC1/2 Channel
    // [7] tpc_cc1_det_en = _TYPE_C_CONNECT
    // [6] tpc_cc2_det_en = _TYPE_C_CONNECT
    // [5] tpc_cc1_channel_en = _TYPE_C_CONNECT
    // [4] tpc_cc2_channel_en = _TYPE_C_CONNECT
    ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    // 4. FW Mode Resistor Asserted to detect TypeC device
    // 1st :
    // (1.) Set FW Mode Rd Resistor (5.1K)
    ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT7);
    ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT7);

    // (2.) Set CC1/CC2 FW Mode Vth (660mV / 1230mV)
    ScalerSetByte(P66_28_VTH_SEL, 0x00);

    // (3.) Assert Resistor for usResistor_hold_time ms, and judge whether CC1/CC2 vRd is in attached voltage range (vRd>0.2V)
    ScalerTimerDelayXms(usResistor_hold_time);
    if(((ScalerGetByte(P66_2A_CC_ANA_DET_R) & (_BIT4)) == _BIT4) || ((ScalerGetByte(P66_2A_CC_ANA_DET_R) & (_BIT0)) == _BIT0))
    {
        bACOnDeviceDetect = _TRUE;
    }
    else
    {
        // 2nd :
        // (1.) Set FW Mode Rp-3A @5V Resistor (4.7K)
        ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT3);
        ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT3);

        // (2.) Set CC1/CC2 FW Mode Vth (800mV / 2600mV)
        ScalerSetByte(P66_28_VTH_SEL, 0xFF);

        // (3.) Assert Resistor for usResistor_hold_time ms, and judge whether CC1/CC2 Rp-3A @5V is in attached voltage range (2600mV>vRd>800mV)
        ScalerTimerDelayXms(usResistor_hold_time);
        if(((ScalerGetByte(P66_2A_CC_ANA_DET_R) & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x70) || ((ScalerGetByte(P66_2A_CC_ANA_DET_R) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x07))
        {
            bACOnDeviceDetect = _TRUE;
        }
        else
        {
            // 3rd :
            // (1.) Set FW Mode Rd Resistor (5.1K)
            ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT7);
            ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT7);

            // (2.) Set CC1/CC2 FW Mode Vth (660mV / 1230mV)
            ScalerSetByte(P66_28_VTH_SEL, 0x00);

            // (3.) Assert Resistor for usResistor_hold_time ms, and judge whether CC1/CC2 vRd is in attached voltage range (vRd>0.2V)
            ScalerTimerDelayXms(usResistor_hold_time);
            if(((ScalerGetByte(P66_2A_CC_ANA_DET_R) & (_BIT4)) == _BIT4) || ((ScalerGetByte(P66_2A_CC_ANA_DET_R) & (_BIT0)) == _BIT0))
            {
                bACOnDeviceDetect = _TRUE;
            }
        }
    }
    SET_TYPE_C_RX0_AC_ON_DEVICE_DETECT(bACOnDeviceDetect);
}

//--------------------------------------------------
// Description  : Return Port Controller CC Device Detect result to SysTypeC
// Input Value  : None
// Output Value : CC Device Detect result (_TRUE / _FALSE)
//--------------------------------------------------
bit ScalerTypeCRx0CcGetACOnDeviceDetect(void)
{
    return GET_TYPE_C_RX0_AC_ON_DEVICE_DETECT();
}

//--------------------------------------------------
// Description  : Process For Change Between SRC and SNK w/o Unattach
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcSwitchPowerRole(BYTE ucTargetRole)
{
    if(ucTargetRole == _PD_POWER_SRC)
    {   // Switch Type-C HW State From SNK to SRC (FW Solution)

        // 1. [0x665A/5B] Setting FW Mode Rp Resistor (36K / 12K / 4.7K)
#if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)
        ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT4);
        ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT4);

        // Set FW Mode Vth (200mV / 1600mV)
        ScalerSetByte(P66_28_VTH_SEL, 0x55);

#elif(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_1P5A)
        ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT5);
        ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT5);

        // Set FW Mode Vth (400mV / 1600mV)
        ScalerSetByte(P66_28_VTH_SEL, 0x99);

#else
        ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, _BIT3);
        ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, _BIT3);

        // Set FW Mode Vth (800mV / 2600mV)
        ScalerSetByte(P66_28_VTH_SEL, 0xFF);

#endif  // End of #if(_TYPE_C_EMB_SRC_DEF_CUR == _SRC_DEF_USB)

        // 2. Switch to FW Mode with Rp Aeesrted
        ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~_BIT7, 0x00);

        // 3. Set HW Mode FSM to Attached.SRC (!!! Warning : Flow or Delay Change May Cause Orientation Error)
        ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~_BIT6, 0x00);
        ScalerSetBit(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));
        ScalerTimerDelayXms(2);
        ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~_BIT6, _BIT6);

        // 4. Adjust BMC Rx Vth to SRC_H / SRC_L
        ScalerSetBit(P66_25_BMC_TX_RX_CFG, ~(_BIT5 | _BIT4), 0x00);

        // 5. Switch Back to HW Mode with FSM Already in Attached.SRC
        ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~_BIT7, _BIT7);

        if((GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_DRP) && (GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC))
        {
            // DRP Try Src FW Solution
            // [0x6630] : [3] hw_done_irq, [2] hw_done_irq_en, [1] hw_unattach_irq, [0] hw_unattach_irq_en
            // Disable hw_done_irq and hw_unattach_irq
            ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

            // [0x6658] : [1] hw_try_wait_snk_irq, [0] hw_try_wait_snk_irq_en
            // Clear and Enable hw_try_wait_snk_irq
            ScalerSetBit(P66_58_DBCC_SNK_DET_COND, ~(_BIT3 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Set Attached.SRC to TryWait.Snk Flag
            SET_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();
        }

        // Set Power Role for Detecting CC1/CC2 Resistor = SRC
        ScalerSetBit(P66_2B_CC_DIG_DET_R, ~(_BIT7), 0x00);

        // Enable CC1/ CC2 Change IRQ to Detect if SNK-Rd is Removed
        ScalerSetBit(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
    }
    else
    {   // Switch Type-C HW State From SRC to SNK
        ScalerSetBit(P66_34_CC_HW_STATE_CTRL, ~_BIT5, _BIT5);

        if((GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_DRP) && (GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC))
        {
            // DRP Try Src FW Solution
            // [0x6630] : [3] hw_done_irq, [2] hw_done_irq_en, [1] hw_unattach_irq, [0] hw_unattach_irq_en
            // Disable hw_done_irq and Enable hw_unattach_irq
            ScalerSetBit(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

            // [0x6658] : [1] hw_try_wait_snk_irq, [0] hw_try_wait_snk_irq_en
            // Clear and Disable hw_try_wait_snk_irq
            ScalerSetBit(P66_58_DBCC_SNK_DET_COND, ~(_BIT3 | _BIT1 | _BIT0), _BIT1);

            // Clear Attached.SRC to TryWait.Snk Flag
            CLR_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();
        }

        // Set Power Role for Detecting CC1/CC2 Resistor = SNK
        ScalerSetBit(P66_2B_CC_DIG_DET_R, ~(_BIT7), _BIT7);

        // Enable CC1/ CC2 Change IRQ to Detect Open + Open
        ScalerSetBit(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
    }

#if((_DEBUG_MESSAGE_TYPE_C == _ON) && (_CC_FW_DEBUG == _ON))
    DebugMessageTypeC("    [CC/Resistor] Switch to SNK(0) / SRC(1): ", ucTargetRole);
#endif
}

//--------------------------------------------------
// Description  : Process For Change Between SRC and SNK w/o Unattach
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcSwitchPowerRole_WDINT(BYTE ucTargetRole) using 3
{
    if(ucTargetRole == _PD_POWER_SRC)
    {
        // Switch Type-C HW State From SNK to SRC (FW Solution)

        // 1. [0x665A/5B] Setting FW Mode Rp Resistor (36K / 12K / 4.7K)
#if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)
        ScalerSetByte_EXINT(P66_5A_CC_FW_CC1_Z_CFG, _BIT4);
        ScalerSetByte_EXINT(P66_5B_CC_FW_CC2_Z_CFG, _BIT4);

        // Set FW Mode Vth (200mV / 1600mV)
        ScalerSetByte_EXINT(P66_28_VTH_SEL, 0x55);

#elif(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_1P5A)
        ScalerSetByte_EXINT(P66_5A_CC_FW_CC1_Z_CFG, _BIT5);
        ScalerSetByte_EXINT(P66_5B_CC_FW_CC2_Z_CFG, _BIT5);

        // Set FW Mode Vth (400mV / 1600mV)
        ScalerSetByte_EXINT(P66_28_VTH_SEL, 0x99);

#else
        ScalerSetByte_EXINT(P66_5A_CC_FW_CC1_Z_CFG, _BIT3);
        ScalerSetByte_EXINT(P66_5B_CC_FW_CC2_Z_CFG, _BIT3);

        // Set FW Mode Vth (800mV / 2600mV)
        ScalerSetByte_EXINT(P66_28_VTH_SEL, 0xFF);
#endif  // End of #if(_TYPE_C_EMB_SRC_DEF_CUR == _SRC_DEF_USB)

        // 2. Switch to FW Mode with Rp Aeesrted
        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~_BIT7, 0x00);

        // 3. Set HW Mode FSM to Attached.SRC (!!! Warning : Flow or Delay Change May Cause Orientation Error)
        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~_BIT6, 0x00);
        ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));

        for(pData_EXINT[0] = 0; pData_EXINT[0] < 50; pData_EXINT[0] ++)
        {
            DELAY_40US_EXINT();
        }

        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~_BIT6, _BIT6);

        // 4. Adjust BMC Rx Vth to SRC_H / SRC_L
        ScalerSetBit_EXINT(P66_25_BMC_TX_RX_CFG, ~(_BIT5 | _BIT4), 0x00);

        // 5. Switch Back to HW Mode with FSM Already in Attached.SRC
        ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~_BIT7, _BIT7);

        if((GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_DRP) && (GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC))
        {
            // DRP Try Src FW Solution
            // [0x6630] : [3] hw_done_irq, [2] hw_done_irq_en, [1] hw_unattach_irq, [0] hw_unattach_irq_en
            // Disable hw_done_irq and hw_unattach_irq
            ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

            // [0x6658] : [1] hw_try_wait_snk_irq, [0] hw_try_wait_snk_irq_en
            // Clear and Enable hw_try_wait_snk_irq
            ScalerSetBit_EXINT(P66_58_DBCC_SNK_DET_COND, ~(_BIT3 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Set Attached.SRC to TryWait.Snk Flag
            SET_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();
        }

        // Set Power Role for Detecting CC1/CC2 Resistor = SRC
        ScalerSetBit_EXINT(P66_2B_CC_DIG_DET_R, ~(_BIT7), 0x00);

        // Enable CC1/ CC2 Change IRQ to Detect if SNK-Rd is Removed
        ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
    }
    else
    {   // Switch Type-C HW State From SRC to SNK
        ScalerSetBit_EXINT(P66_34_CC_HW_STATE_CTRL, ~_BIT5, _BIT5);

        if((GET_TYPE_C_RX0_PORT_ROLE() == _TYPE_C_PORT_DRP) && (GET_TYPE_C_RX0_DRP_PREFER() == _TYPE_C_DRP_TRY_SRC))
        {
            // DRP Try Src FW Solution
            // [0x6630] : [3] hw_done_irq, [2] hw_done_irq_en, [1] hw_unattach_irq, [0] hw_unattach_irq_en
            // Disable hw_done_irq and Enable hw_unattach_irq
            ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

            // [0x6658] : [1] hw_try_wait_snk_irq, [0] hw_try_wait_snk_irq_en
            // Clear and Disable hw_try_wait_snk_irq
            ScalerSetBit_EXINT(P66_58_DBCC_SNK_DET_COND, ~(_BIT3 | _BIT1 | _BIT0), _BIT1);

            // Clear Attached.SRC to TryWait.Snk Flag
            CLR_TYPE_C_RX0_ATTACHED_SRC_TO_TRY_WAIT_SNK();
        }

        // Set Power Role for Detecting CC1/CC2 Resistor = SNK
        ScalerSetBit_EXINT(P66_2B_CC_DIG_DET_R, ~(_BIT7), _BIT7);

        // Enable CC1/ CC2 Change IRQ to Detect Open + Open
        ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
    }
}

//--------------------------------------------------
// Description  : Rx0 Cc Power Switch Proc
// Input Value  : enumPowerAction : Power Switch Enum
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcPowerSwitch(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_AC_ON_TO_OFF:

#if(_TYPE_C_POWER_SOURCE != _TYPE_C_VBUS_POWER_ONLY)
#if(_TYPE_C_CC_AC_ON_RECONNECT == _TRUE)
            SET_TYPE_C_RX0_AC_ON_RECONNECT();
#else
            CLR_TYPE_C_RX0_AC_ON_RECONNECT();
#endif

            // Cancel Switch Mode Timer Event if Successfully Attached
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_CC_RX0_STATE_TO_UNATTACH);

            // AC On Start From INITIAL State
            SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_INITAIL);
#endif
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Rx0 Cc Function Control
// Input Value  : enumCcFunction : _TYPE_C_CC_FUNCTION_DISABLE/ENABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcFunctionControl(EnumTypeCCcFunction enumCcFunction)
{
    if(enumCcFunction == _TYPE_C_CC_FUNCTION_DISABLE)
    {
        CLR_CC_RX0_CONNECT_EN();
        SET_TYPE_C_ERROR_RECOVERY();
    }
    else if(enumCcFunction == _TYPE_C_CC_FUNCTION_ENABLE)
    {
        SET_CC_RX0_CONNECT_EN();
    }
}

//--------------------------------------------------
// Description  : Set CC Function Support Option
// Input Value  : enumFunctionSupport
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcSetFunctionSupport(EnumTypeCFunctionSupport enumFunctionSupport)
{
    if(enumFunctionSupport == _TYPE_C_SUPPORT_NO_FUNCTION)
    {
        CLR_CC_RX0_CONNECT_EN();
    }
    else
    {
        SET_CC_RX0_CONNECT_EN();
    }
}

//--------------------------------------------------
// Description  : Set Type-C Operation Mode
// Input Value  : enumOperationMode
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcSetOperationMode(EnumTypeCOperationMode enumOperationMode)
{
    switch(enumOperationMode)
    {
        case _TYPE_C_SRC_ONLY_MODE:

            SET_TYPE_C_RX0_PORT_ROLE(_TYPE_C_PORT_SRC_ONLY);
            SET_TYPE_C_RX0_DRP_PREFER(_TYPE_C_DRP_NO_PREFERENCE);

            break;

        case _TYPE_C_SNK_ONLY_MODE:

            SET_TYPE_C_RX0_PORT_ROLE(_TYPE_C_PORT_SNK_ONLY);
            SET_TYPE_C_RX0_DRP_PREFER(_TYPE_C_DRP_NO_PREFERENCE);

            break;

        case _TYPE_C_DRP_NO_PREFERENCE_MODE:

            SET_TYPE_C_RX0_PORT_ROLE(_TYPE_C_PORT_DRP);
            SET_TYPE_C_RX0_DRP_PREFER(_TYPE_C_DRP_NO_PREFERENCE);

            break;

        case _TYPE_C_DRP_TRY_SNK_MODE:

            SET_TYPE_C_RX0_PORT_ROLE(_TYPE_C_PORT_DRP);
            SET_TYPE_C_RX0_DRP_PREFER(_TYPE_C_DRP_TRY_SNK);

            break;

        case _TYPE_C_DRP_TRY_SRC_MODE:

            SET_TYPE_C_RX0_PORT_ROLE(_TYPE_C_PORT_DRP);
            SET_TYPE_C_RX0_DRP_PREFER(_TYPE_C_DRP_TRY_SRC);

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : FW Mode to Unattached.SRC
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcFWModeSRCUnattached_EXINT0(void) using 1
{
    // 1. [0x665A/5B] Setting FW Mode Rp Resistor (36K / 12K / 4.7K)
#if(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_USB)
    ScalerSetByte_EXINT(P66_5A_CC_FW_CC1_Z_CFG, _BIT4);
    ScalerSetByte_EXINT(P66_5B_CC_FW_CC2_Z_CFG, _BIT4);

#elif(_TYPE_C_EMB_SRC_DEF_CUR == _TYPE_C_SRC_DEF_1P5A)
    ScalerSetByte_EXINT(P66_5A_CC_FW_CC1_Z_CFG, _BIT5);
    ScalerSetByte_EXINT(P66_5B_CC_FW_CC2_Z_CFG, _BIT5);

#else
    ScalerSetByte_EXINT(P66_5A_CC_FW_CC1_Z_CFG, _BIT3);
    ScalerSetByte_EXINT(P66_5B_CC_FW_CC2_Z_CFG, _BIT3);

#endif  // End of #if(_TYPE_C_EMB_SRC_DEF_CUR == _SRC_DEF_USB)

    // 2. Switch to FW Mode with Rp Aeesrted
    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~_BIT7, 0x00);

    // 3. Set HW Mode FSM to Unattached.SRC
    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~_BIT6, 0x00);
    ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~_BIT6, _BIT6);

    // 5. Switch Back to HW Mode with FSM Already in Unattached.SRC
    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~_BIT7, _BIT7);
}

#if((_TYPE_C_EMB_CTS_FLOW == _ON) && (_HW_TYPE_C_FUNCTION_GEN == _TYPE_C_FUNCTION_GEN_1))
//--------------------------------------------------
// Description  : Get TypeC Rx0 Change Vbus_Off_Thr.
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
BYTE ScalerTypeCRx0CcGetChangeVbusOffThr_EXINT0(void) using 1
{
    return GET_TYPE_C_RX0_CHANGE_VBUS_OFF_THR();
}
#endif

//--------------------------------------------------
// Description  : Get TypeC Rx0 is in TryWait.SNK State
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
BYTE ScalerTypeCRx0CcGetTryWaitSNKState_EXINT0(void) using 1
{
    return GET_TYPE_C_RX0_TRY_WAIT_SNK_STATE();
}

//--------------------------------------------------
// Description  : FW Mode TryWait.SNK to Attached.SNK
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcFWModeTrySrcAttached_EXINT0(void) using 1
{
    // Clr TryWait.Snk to Attached.SNK Flag
    CLR_TYPE_C_RX0_TRY_WAIT_SNK_STATE();

    ScalerTypeCRx0PdSetPowerRole_EXINT0(_PD_POWER_SNK);

    // Disable Double CC as SNK Detect Open-Open Enable Bit
    ScalerSetBit_EXINT(P66_58_DBCC_SNK_DET_COND, ~(_BIT4 | _BIT3 | _BIT1), 0x00);

    // Disable Both CC Detect Equal Condition
    ScalerSetBit_EXINT(P66_40_CC_FW_DET_CTRL, ~_BIT7, 0x00);

    // Popup Digital Detect Result
    ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT5 | _BIT0), _BIT0);

    // [0x662B] [5:3]: CC1 = Rp
    if((ScalerGetByte_EXINT(P66_2B_CC_DIG_DET_R) & (_BIT5 | _BIT4 | _BIT3)) >= (_BIT4 | _BIT3))
    {
        // Un-Flip : PD BMC Signal : CC1 / Vconn : CC2
        SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_UNFLIP);

        // [0x660C] Disconnect CC2 Detection Channel and CC2 Channel and BMC Channel
        // [6] tpc_cc2_det_en     = _TYPE_C_DISCONNECT
        // [4] tpc_cc2_channel_en = _TYPE_C_DISCONNECT
        // [2] tpc_cc2_en         = _TYPE_C_DISCONNECT (Not Needed)
        ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT6 | _BIT4 | _BIT2), 0x00);
    }
    else
    {
        // Flip : PD BMC Signal : CC2 / Vconn : CC1
        SET_CC_RX0_ORIENTATION(_TYPE_C_ORIENTATION_FLIP);

        // [0x660C] Disconnect CC1 Detection Channel and CC1 Channel and BMC Channel
        // [7] tpc_cc1_det_en     = _TYPE_C_DISCONNECT
        // [5] tpc_cc1_channel_en = _TYPE_C_DISCONNECT
        // [3] tpc_cc1_en         = _TYPE_C_DISCONNECT (Not Needed)
        ScalerSetBit_EXINT(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT5 | _BIT3), 0x00);
    }

    // Adjust Unattch Vth to 3.67V
    ScalerTypeCPowerRx0UnattachVthAdjust_EXINT0(500);

#if(_TYPE_C_PMIC_TYPE != _PMIC_NONE)
    // Disable Vbus Discharge
    ScalerTypeCPmicRx0VbusDischarge_EXINT0(_DISABLE);

    // Cancel WDTimerEvent (_UNATTACH_VBUS_DISCHARGE_TIMER)
    ScalerTimerWDCancelTimerEvent_EXINT0(_SCALER_WD_TIMER_EVENT_CC_RX0_CHECK_VBUS_0V);
#endif

    // Update Vbus Power Info to Support Sink OVP/UVP
    ScalerTypeCPowerRx0VbusControl_EXINT0(_ON, _PD_POWER_SNK, _PD_FIX_SUPPLY_PDO, 500, 0, _PD_PEAK_CUR_NONE);

#if((_TYPE_C_PMIC_TYPE != _PMIC_NONE) && (_TYPE_C_PMIC_CHECK_SUPPORT == _ON))
    // Start PMIC Protection
    ScalerTypeCPmicRx0ProtectStart_EXINT0(_TYPE_C_POWER_SNK);
#endif

#if((_TYPE_C_EMB_CTS_FLOW == _ON) && (_HW_TYPE_C_FUNCTION_GEN == _TYPE_C_FUNCTION_GEN_1))
    // Lecroy [TD.4.5.4] and [TD.4.7.2].
    // In Attached.SNK State, Clear Macro and Cancel WD Timer Event.
    CLR_TYPE_C_RX0_CHANGE_VBUS_OFF_THR();
    ScalerTimerWDCancelTimerEvent_EXINT0(_SCALER_WD_TIMER_EVENT_CC_RX0_CHANGE_VBUS_OFF_THRESHOLD);
#endif

#if(_TYPE_C_EIZO_CUSTOMIZED_PMIC_SIC437A_SUPPORT == _ON)
    // [Eizo] SIC437A Customized Power Control : SRC/SNK Attach
    ScalerTypeCPmicRx0AttachProc_EXINT0(_TYPE_C_POWER_SNK);
#endif

    // Set Power Role for Detecting CC1/CC2 Resistor = SNK
    ScalerSetBit_EXINT(P66_2B_CC_DIG_DET_R, ~(_BIT7), _BIT7);

    // Enable CC1/ CC2 Change IRQ to Detect Open + Open
    ScalerSetBit_EXINT(P66_2C_CC_R_CHG_INT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    // Set PD to Initail State (Data Role, Vconn Role, Initial State (PE_SRC/SNK_STARTUP),...)
    ScalerTypeCRx0PdAttachedSetting_EXINT0();

    // BMC Related Setting
    ScalerTypeCRx0CcSetBMC_EXINT0(_ENABLE);

    // Turn On U3 & Hub Function
    ScalerDpRx0SetDpAltModeLaneMapping_EXINT0(_TYPE_C_PIN_ASSIGNMENT_NONE, GET_CC_RX0_ORIENTATION());

    SET_CC_RX0_ATTACHED();
    SET_TYPE_C_RX0_ATTACH_STATUS(_EMB_TPC_ATTACHED);

    // [0x6635] Set HW State to Attached.SNK
    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT6 | _BIT3 | _BIT1), 0x00);
    ScalerSetBit_EXINT(P66_35_CC_HW_STATE_TRANSIT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT6);

    // [0x6630] : [7] tpc_cc_mode_sel, [6] hw_mode_fsm_rst, [3] hw_done_irq, [1] hw_unattach_irq, [0] hw_unattach_irq_en
    // Change Back to HW Mode, Clear (hw_done_irq) & (hw_unattach_irq), Enable hw_unattach_irq_en
    ScalerSetBit_EXINT(P66_30_CC_HW_MODE_CTRL, ~(_BIT7 | _BIT6 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT6 | _BIT3 | _BIT1 | _BIT0));
}

#if(_TYPE_C_EMB_PD3_FRSWAP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable / Disable Fast Role Swap
// Input Value  : bAction : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcFastRoleSwapControl(bit bAction)
{
    if(bAction == _ENABLE)
    {
        if(ScalerTypeCRx0PdGetPowerRole() == _PD_POWER_SRC)
        {
            // [0x6666] Clear and Enable SRC FR_SWAP INT
            // [7] src_frs_done_int    = 1
            // [6] src_frs_done_int_en = _ENABLE
            ScalerSetBit(P66_66_SRC_FRS_INT, ~_BIT7, _BIT7);
            ScalerSetBit(P66_66_SRC_FRS_INT, ~_BIT6, _BIT6);

            // [0x6660] Turn On Source-Side FR_SWAP
            // [7] src_frs_en = _ENABLE
            ScalerSetBit(P66_60_FRS_CTRL, ~_BIT7, _BIT7);

            SET_RX0_SRC_FRSWAP_STATUS(_ENABLE);
        }
        else
        {
            // [0x6667] Clear and Enable SNK FR_SWAP INT
            // [7] snk_frs_done_int    = 1
            // [6] snk_frs_done_int_en = _ENABLE
            // [3] snk_frs_tri_int     = 1
            // [2] snk_frs_tri_int_en  = _ENABLE
            ScalerSetBit(P66_67_SNK_FRS_INT, ~_BIT7, _BIT7);
            ScalerSetBit(P66_67_SNK_FRS_INT, ~_BIT6, _BIT6);
            ScalerSetBit(P66_67_SNK_FRS_INT, ~_BIT3, _BIT3);
            ScalerSetBit(P66_67_SNK_FRS_INT, ~_BIT2, _BIT2);

            // [0x6660] Turn On Sink-Side FR_SWAP
            // [6] snk_frs_en = _ENABLE
            ScalerSetBit(P66_60_FRS_CTRL, ~_BIT6, _BIT6);

            SET_RX0_SNK_FRSWAP_STATUS(_ENABLE);
        }   // End of if(GET_PD_RX0_POWER_ROLE() == _PD_POWER_SRC)
    }
    else
    {   // [0x6666] Disable SRC FR_SWAP INT
        // [6] src_frs_done_int_en = _DISABLE
        ScalerSetBit(P66_66_SRC_FRS_INT, ~_BIT6, 0x00);

        // [0x6667] Disable SNK FR_SWAP INT
        // [6] snk_frs_done_int_en = _DISABLE
        // [2] snk_frs_tri_int_en  = _DISABLE
        ScalerSetBit(P66_67_SNK_FRS_INT, ~(_BIT6 | _BIT2), 0x00);

        // [0x6660] Turn Off Source/Sink-Side FR_SWAP
        // [7] src_frs_en = _DISABLE
        // [6] snk_frs_en = _DISABLE
        ScalerSetBit(P66_60_FRS_CTRL, ~(_BIT7 | _BIT6), 0x00);

        // [0x6668] Turn Off Fast-Role Swap
        ScalerSetBit(P66_68_FRS_BYPASS_MODE, ~_BIT7, 0x00);

        SET_RX0_SRC_FRSWAP_STATUS(_DISABLE);
        SET_RX0_SNK_FRSWAP_STATUS(_DISABLE);
    }
}

//--------------------------------------------------
// Description  : Enable / Disable Fast Role Swap
// Input Value  : bAction : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcFastRoleSwapControl_EXINT0(bit bAction) using 1
{
    if(bAction == _ENABLE)
    {
        if(ScalerTypeCRx0PdGetPowerRole_EXINT0() == _PD_POWER_SRC)
        {
            // [0x6666] Clear and Enable SRC FR_SWAP INT
            // [7] src_frs_done_int    = 1
            // [6] src_frs_done_int_en = _ENABLE
            ScalerSetBit_EXINT(P66_66_SRC_FRS_INT, ~_BIT7, _BIT7);
            ScalerSetBit_EXINT(P66_66_SRC_FRS_INT, ~_BIT6, _BIT6);

            // [0x6660] Turn On Source-Side FR_SWAP
            // [7] src_frs_en = _ENABLE
            ScalerSetBit_EXINT(P66_60_FRS_CTRL, ~_BIT7, _BIT7);

            SET_RX0_SRC_FRSWAP_STATUS(_ENABLE);
        }
        else
        {
            // [0x6667] Clear and Enable SNK FR_SWAP INT
            // [7] snk_frs_done_int    = 1
            // [6] snk_frs_done_int_en = _ENABLE
            // [3] snk_frs_tri_int     = 1
            // [2] snk_frs_tri_int_en  = _ENABLE
            ScalerSetBit_EXINT(P66_67_SNK_FRS_INT, ~_BIT7, _BIT7);
            ScalerSetBit_EXINT(P66_67_SNK_FRS_INT, ~_BIT6, _BIT6);
            ScalerSetBit_EXINT(P66_67_SNK_FRS_INT, ~_BIT3, _BIT3);
            ScalerSetBit_EXINT(P66_67_SNK_FRS_INT, ~_BIT2, _BIT2);

            // [0x6660] Turn On Sink-Side FR_SWAP
            // [6] snk_frs_en = _ENABLE
            ScalerSetBit_EXINT(P66_60_FRS_CTRL, ~_BIT6, _BIT6);

            SET_RX0_SNK_FRSWAP_STATUS(_ENABLE);
        }   // End of if(GET_PD_RX0_POWER_ROLE() == _PD_POWER_SRC)
    }
    else
    {   // [0x6666] Disable SRC FR_SWAP INT
        // [6] src_frs_done_int_en = _DISABLE
        ScalerSetBit_EXINT(P66_66_SRC_FRS_INT, ~_BIT6, 0x00);

        // [0x6667] Disable SNK FR_SWAP INT
        // [6] snk_frs_done_int_en = _DISABLE
        // [2] snk_frs_tri_int_en  = _DISABLE
        ScalerSetBit_EXINT(P66_67_SNK_FRS_INT, ~(_BIT6 | _BIT2), 0x00);

        // [0x6660] Turn Off Source/Sink-Side FR_SWAP
        // [7] src_frs_en = _DISABLE
        // [6] snk_frs_en = _DISABLE
        ScalerSetBit_EXINT(P66_60_FRS_CTRL, ~(_BIT7 | _BIT6), 0x00);

        // [0x6668] Turn Off Fast-Role Swap
        ScalerSetBit_EXINT(P66_68_FRS_BYPASS_MODE, ~_BIT7, 0x00);

        SET_RX0_SRC_FRSWAP_STATUS(_DISABLE);
        SET_RX0_SNK_FRSWAP_STATUS(_DISABLE);
    }
}
#endif  // End of #if(_TYPE_C_EMB_PD3_FRSWAP_SUPPORT == _ON)

#if(_TYPE_C_EMB_UNATTACH_HW_FORCE_VBUS_OFF == _OFF)
//--------------------------------------------------
// Description  : Enable Tool to Show Warning UI when We Provide Vbus > 5V
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcToolWarningUIControl(bit bAction)
{
    // Tool Usage : [0x6666] [4] Used to Decide Whether Tool shall Show Warning UI when Disable Unattach HW Force Vbus Off Function([3]=0), 0 = Not Show UI, 1 = Show UI
    if(bAction == _ENABLE)
    {
        ScalerSetBit(P66_66_SRC_FRS_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    }
    else
    {
        ScalerSetBit(P66_66_SRC_FRS_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    }
}

//--------------------------------------------------
// Description  : Enable Tool to Show Warning UI when We Provide Vbus > 5V
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcToolWarningUIControl_EXINT0(bit bAction) using 1
{
    // Tool Usage : [0x6666] [4] Used to Decide Whether Tool shall Show Warning UI when Disable Unattach HW Force Vbus Off Function([3]=0), 0 = Not Show UI, 1 = Show UI
    if(bAction == _ENABLE)
    {
        ScalerSetBit_EXINT(P66_66_SRC_FRS_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    }
    else
    {
        ScalerSetBit_EXINT(P66_66_SRC_FRS_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    }
}

//--------------------------------------------------
// Description  : Enable Tool to Show Warning UI when We Provide Vbus > 5V
// Input Value  : _ENABLE / _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcToolWarningUIControl_WDINT(bit bAction) using 3
{
    // Tool Usage : [0x6666] [4] Used to Decide Whether Tool shall Show Warning UI when Disable Unattach HW Force Vbus Off Function([3]=0), 0 = Not Show UI, 1 = Show UI
    if(bAction == _ENABLE)
    {
        ScalerSetBit_EXINT(P66_66_SRC_FRS_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    }
    else
    {
        ScalerSetBit_EXINT(P66_66_SRC_FRS_INT, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    }
}
#endif  // End of #if(_TYPE_C_EMB_UNATTACH_HW_FORCE_VBUS_OFF == _OFF)

#endif  // End of #if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED))

#if((_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED) || (_TYPE_C_GPIO_MODE_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Load Trimming Value From E-Fuse
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcLoadTrimming(void)
{
    BYTE pucEfuseValueTemp[8] = {0};

    // Read Check Bit
    ScalerEfuseGetData(_EFUSE_CHECK_BIT, 1, &pucEfuseValueTemp[0]);

    if((pucEfuseValueTemp[0] & 0xE0) != 0x00)
    {
        // Read CC Resistance
        ScalerEfuseGetData(_EFUSE_CC_RESISTANCE, 8, &pucEfuseValueTemp[0]);

        // CC1/CC2 Rp 12k
        ScalerSetByte(P66_1A_TPC_CC1_RP12K_CFG, (pucEfuseValueTemp[0] & 0x1F));
        ScalerSetByte(P66_1E_TPC_CC2_RP12K_CFG, (pucEfuseValueTemp[1] & 0x1F));

        // CC1/CC2 Rp 36k
        ScalerSetByte(P66_1B_TPC_CC1_RP36K_CFG, (pucEfuseValueTemp[2] & 0x1F));
        ScalerSetByte(P66_1F_TPC_CC2_RP36K_CFG, (pucEfuseValueTemp[3] & 0x1F));

        // CC1/CC2 Rp 4.7k
        ScalerSetByte(P66_19_TPC_CC1_RP4P7K_CFG, (pucEfuseValueTemp[4] & 0x1F));
        ScalerSetByte(P66_1D_TPC_CC2_RP4P7K_CFG, (pucEfuseValueTemp[5] & 0x1F));

        // CC1/CC2 Rp 5.1k
        ScalerSetByte(P66_18_TPC_CC1_RD_CFG, (pucEfuseValueTemp[6] & 0x1F));
        ScalerSetByte(P66_1C_TPC_CC2_RD_CFG, (pucEfuseValueTemp[7] & 0x1F));

        // Read CC Resistance
        ScalerEfuseGetData(_EFUSE_CC_ATTACH_VOLTAGE, 8, &pucEfuseValueTemp[0]);

        // CC1 Attach Thershold
        ScalerSetByte(P66_10_CC1_VTH_CFG_0, pucEfuseValueTemp[0]);
        ScalerSetByte(P66_11_CC1_VTH_CFG_1, pucEfuseValueTemp[1]);
        ScalerSetByte(P66_12_CC1_VTH_CFG_2, pucEfuseValueTemp[2]);
        ScalerSetByte(P66_13_CC1_VTH_CFG_3, pucEfuseValueTemp[3]);

        // CC2 Attach Thershold
        ScalerSetByte(P66_14_CC2_VTH_CFG_0, pucEfuseValueTemp[4]);
        ScalerSetByte(P66_15_CC2_VTH_CFG_1, pucEfuseValueTemp[5]);
        ScalerSetByte(P66_16_CC2_VTH_CFG_2, pucEfuseValueTemp[6]);
        ScalerSetByte(P66_17_CC2_VTH_CFG_3, pucEfuseValueTemp[7]);

        // BMC RX Voltage Thershold
        ScalerEfuseGetData(_EFUSE_CC_BMC_TX_RX_VOLTAGE, 4, &pucEfuseValueTemp[0]);
        ScalerSetByte(P66_20_BMC_RX_SNK_VTH, pucEfuseValueTemp[0]);
        ScalerSetByte(P66_21_BMC_RX_SRC_VTH, pucEfuseValueTemp[1]);

        // BMC TX Swing Voltage
        ScalerSetBit(P66_22_BMC_TX_CFG, ~(_BIT2 | _BIT1 | _BIT0), (pucEfuseValueTemp[3] & 0x07));
    }
    else
    {
        // Setting Voltage Triming Value : CC1/2 200/400/660/800/1230/1600/2600/490 mV
        ScalerSetByte(P66_10_CC1_VTH_CFG_0, 0x88);  // 200 / 400 mV
        ScalerSetByte(P66_11_CC1_VTH_CFG_1, 0x77);  // 660 / 800 mV
        ScalerSetByte(P66_12_CC1_VTH_CFG_2, 0x67);  // 1230 / 1600 mV
        ScalerSetByte(P66_13_CC1_VTH_CFG_3, 0x55);  // 2600 / 490 mV

        ScalerSetByte(P66_14_CC2_VTH_CFG_0, 0x88);  // 200 / 400 mV
        ScalerSetByte(P66_15_CC2_VTH_CFG_1, 0x77);  // 660 / 800 mV
        ScalerSetByte(P66_16_CC2_VTH_CFG_2, 0x67);  // 1230 / 1600 mV
        ScalerSetByte(P66_17_CC2_VTH_CFG_3, 0x55);  // 2600 / 490 mV

        // Setting Resistor Triming Value : CC1/2 Rd/Rp-4.7K/Rp-12K/Rp-36K
        ScalerSetBit(P66_18_TPC_CC1_RD_CFG, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);
        ScalerSetBit(P66_19_TPC_CC1_RP4P7K_CFG, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);
        ScalerSetBit(P66_1A_TPC_CC1_RP12K_CFG, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);
        ScalerSetBit(P66_1B_TPC_CC1_RP36K_CFG, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);

        ScalerSetBit(P66_1C_TPC_CC2_RD_CFG, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);
        ScalerSetBit(P66_1D_TPC_CC2_RP4P7K_CFG, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);
        ScalerSetBit(P66_1E_TPC_CC2_RP12K_CFG, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);
        ScalerSetBit(P66_1F_TPC_CC2_RP36K_CFG, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);

        // Setting SRC/SNK VTH
        // ScalerSetByte(P66_20_BMC_RX_SNK_VTH, 0x38);
        ScalerSetByte(P66_20_BMC_RX_SNK_VTH, 0x37);
        ScalerSetByte(P66_21_BMC_RX_SRC_VTH, 0x57);

        // Setting Tx Term [7:4] = 4'b1000 (50) / Vswing [2:0] = 3'b010 (1.0V) MQP Test A Liittle Bit Higher
        ScalerSetByte(P66_22_BMC_TX_CFG, 0x82);
    }

    // Setting Rising / Falling Time
    ScalerSetByte(P66_23_BMC_TX_DRV_TM, 0x88);

    // Setting LPF
    ScalerSetBit(P66_24_BMC_LPF, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x08);
}
#endif  // End of #if((_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED) || (_TYPE_C_GPIO_MODE_SUPPORT == _ON))

#if(_TYPE_C_GPIO_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TypeC0 GPIO Mode Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTypeCRx0CcGpioModeInitialSetting(void)
{
    // Set cc1_det_vth3 / cc2_det_vth3 to 2.6V
    ScalerSetBit(P66_28_VTH_SEL, ~(_BIT5 | _BIT4 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT1 | _BIT0));

    // CC1/2 Not Connect Rp/Rd
    ScalerSetByte(P66_5A_CC_FW_CC1_Z_CFG, 0x00);
    ScalerSetByte(P66_5B_CC_FW_CC2_Z_CFG, 0x00);

    // Switch to FW Mode
    ScalerSetByte(P66_30_CC_HW_MODE_CTRL, 0x00);

    // Enable cc1_channel_en and cc1_det_en / cc2_channel_en and cc2_det_en
    ScalerSetBit(P66_0C_TPC_CC_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
}

//--------------------------------------------------
// Description  : Get TypeC0 CC Pin Status
// Input Value  : enumTypeCChannel (_TYPE_C_CC1, _TYPE_C_CC2)
// Output Value : EnumTypeCCcDetectStatus : _TYPE_C_CC_DETECT_HIGH (if CC Voltage >= 2.6V) / _TYPE_C_CC_DETECT_LOW (if CC Voltage < 2.6V)
//--------------------------------------------------
EnumTypeCCcDetectStatus ScalerTypeCRx0CcGetCcPinStatus(EnumTypeCChannel enumTypeCChannel)
{
    EnumTypeCCcDetectStatus enumTypeCCcDetectStatus = _TYPE_C_CC_DETECT_LOW;

    if(enumTypeCChannel == _TYPE_C_CC1)
    {
        // Check whether CC1 > 2.6V
        if((ScalerGetBit(P66_2A_CC_ANA_DET_R, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) & _BIT7) == _BIT7)
        {
            enumTypeCCcDetectStatus = _TYPE_C_CC_DETECT_HIGH;
        }
    }
    else if(enumTypeCChannel == _TYPE_C_CC2)
    {
        // Check whether CC2 > 2.6V
        if((ScalerGetBit(P66_2A_CC_ANA_DET_R, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) & _BIT3) == _BIT3)
        {
            enumTypeCCcDetectStatus = _TYPE_C_CC_DETECT_HIGH;
        }
    }

    return enumTypeCCcDetectStatus;
}
#endif  // End of #if(_TYPE_C_GPIO_MODE_SUPPORT == _ON)