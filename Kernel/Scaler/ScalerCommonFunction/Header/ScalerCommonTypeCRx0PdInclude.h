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
// ID Code      : ScalerCommonTypeCRx0PdInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
// Definitions of SVID
#define _PD_SID                                 0xFF00
#define _DP_SID                                 0xFF01
#define _TBT3_SID                               0x8087
#define _LENOVO_VID                             0x17EF
#define _ACER_VID                               0x0502
#define _HP_VID                                 0x03F0
#define _DELL_VID                               0x413C

// POWER OPTION
#define _VCONN_1W                               0
#define _VCONN_1P5W                             1
#define _VCONN_2W                               2
#define _VCONN_3W                               3
#define _VCONN_4W                               4
#define _VCONN_5W                               5
#define _VCONN_6W                               6

#define _VCONN_REQUIRE                          _FALSE
#define _VCONN_POW                              _VCONN_1W

// POWER ROLE SWAP OPTIONS (If DRP Must Support One Kind Of Swap)
#define _SRC_ACCEPT_SWAP_TO_SNK                 _FALSE
#define _SRC_REQUEST_SWAP_TO_SNK                _FALSE
#define _SNK_ACCEPT_SWAP_TO_SRC                 _TRUE
#define _SNK_REQUEST_SWAP_TO_SRC                _TRUE

// DATA ROLE SWAP OPTIONS
#define _DFP_SWAP_TO_UFP                        _TRUE
#define _UFP_SWAP_TO_DFP                        _FALSE

// USB Related Capability
#define _USB_SUSPEND                            _FALSE

// ALT MODE SUPPORT OPTION
#define _ALT_MODE_SUPPORT_CNT                   ((_TYPE_C_EMB_DP_ALT_MODE_SUPPORT == _ON) + (_TYPE_C_VENDOR_ALT_MODE != _TYPE_C_VENDOR_ALT_MODE_NONE))
#define _PD_HW_VERSION                          0x00
#define _PD_FW_VERSION                          0x00

// The Revision and Version of PD Specification
#define _PD_SPEC_REVISION                       0x31
#define _PD_SPEC_VERSION                        0x15

// Refer to Port Partner Capability, e.g. DRP and DRD. This setting is for Compatibility.
#define _REFER_TO_PORT_PARTNER_CAP              _TRUE

// PD3.0 Related Capability
#define _MANUFACTURER_INFO_SUPPORT              _TRUE
#define _TYPE_C_CTS_SPEC_FOLLOW                 _TRUE

// Definitions of Specification Counters
#define _MAX_SRC_CAP_CNT                        60
#define _MAX_HW_NO_RETRY_FAIL_CNT               20      // Max FW Retry Fail Cnt When HW Don't Retry to Send Discover Id When No GoodCRC Received
#define _MAX_HW_RETRY_FAIL_CNT                  5       // Max FW Retry Fail Cnt When HW Retry to Send Discover Id When No GoodCRC Received
#define _MAX_HARD_RST_CNT                       2
#define _MAX_LENOVO_ATTN_CNT                    5
#define _MAX_VDM_NO_RESP_CNT                    3
#define _MAX_VDM_BUSY_CNT                       5

// Definitions of FW Usage Counters
#define _MAX_DATA_OBJ_CNT                       11
#define _HPD_QUEUE_DEPTH                        4

// Definitions of Specification Timer
#define _SRC_INIT_AMS_TIMER                     18      // 16 ~ 20ms (Source Wait After switch Rp to TxSinkNG)
#define _SWAP_SRC_START_TIMER                   20      // After PR_SWAP SRC should Wait At Least 20ms, After Power On, Cable Will Be Stable After 50ms
#define _PD2_SENDER_RESP_TIMER                  24      // PD2.0 : 24 ~ 30ms
#define _PD3_SENDER_RESP_TIMER                  27      // PD3.1 : 27 ~ 33ms
#define _SRC_ADJUST_POWER_TIMER                 30      // 25 ~ 35ms
#define _VDM_MODE_ENTRY_TIMER                   40      // 40 ~ 50ms
#define _VDM_MODE_EXIT_TIMER                    40      // 40 ~ 50ms
#define _VDM_BUSY_TIMER                         50      // At Least 50ms
#define _SINK_WAIT_CAP_TIMER                    500     // 310 ~ 620ms
#define _SRC_RECOVER_TIMER                      700     // 660 ~ 1000ms
#define _WAIT_TIMER                             100
#define _WAIT_VCONN_ON_TIMER                    100
#define _PS_TRANSITION_TIMER                    500     // 450 ~ 550ms
#define _PS_SRC_ON_TIMER                        400     // 390 ~ 480ms
#define _PS_SRC_OFF_TIMER                       750     // 750 ~ 920ms
#define _ATTENTION_SPACING_TIMER                10      // (ms) DP Alt Mode Standard 5.2.2 Gap Between Attention
#define _SRC_SEND_PS_RDY_FIX_VOLTAGE_TIMER      35      // 35ms, Depends on tSrcReady (SPR : 285ms) : 35ms * 8 (Check Vbus Count) <= 285ms
#define _SRC_SEND_PS_RDY_PPS_MODE_TIMER         3       // 3ms, Depends on tPpsSrcTransSmall (25ms) : 3ms * 8 (Check Vbus Count) <= 25ms
#define _SRC_SEND_PS_RDY_EPR_FIX_VOLTAGE_TIMER  90      // 90ms, Depends on tSrcReady (EPR : 720ms) : 90ms * 8 (Check Vbus Count) <= 720ms
#define _SRC_SEND_PS_RDY_EPR_AVS_MODE_TIMER     6       // 6ms, Depends on tAvsSrcTransSmall (50ms) : 6ms * 8 (Check Vbus Count) <= 50ms
#define _UNATTACH_VBUS_DISCHARGE_TIMER          10      // Same as tPDDebounce (min)
#define _SNK_HARD_RST_TIMER                     3000
#define _SRC_EPR_KEEP_ALIVE_TIMER               750     // 750 ~ 1000ms
#define _CHUNK_SENDER_REQ_TIMER                 24      // 24 ~ 30ms

// Definition of FW Usage Timer to Wait for Receiving Subsequent AMS, ex: Get_Status Msg., Timeout: Send Hard Reset.
#define _ALERT_WAIT_TIMER                       35      // (ms) Not Defined by Spec.

// Definitions of FW Usage Timer for Partner Support ALT Mode Detection
#define _PARTNER_ALT_SUPPORT_TIMER              2000    // Wait 2 Sec to Detect Whether Partner Support ALT Mode

// FW Solution For Lenovol T480, Wait 1s to Do Error Recovery
#define _T480_ERROR_RECOVERY_TIMER              1000    // Wait 1 Sec to Do Error Recovery

// Definitions of FW WD Timer Event Max Time
#define _MAX_WD_EVENT_TIME                      250     // (ms)

// Definitions of FW Usage Timer
#define _PD_SEND_MSG_TIMEOUT                    10

// Definitions of Other Default Value
#define _PD_DEFAULT_MAX_CUR                     300      // 300 * 10mA = 3.0A

// Definition of PD Capability
#define _SRC_CAP_NO_RETRY                       _FALSE   // [TEST.PD.PROT.SRC3.1] : All PD Message Should Implement 0.9~1.1ms Retry
#define _HIGHER_CAP                             _FALSE
#define _GIVE_BACK                              _FALSE
#define _UNCHUNK_SUPPORT                        _FALSE

// Definitions of PD Data(USB) DFP/UFP Role
#define _PD_DATA_UFP                            0x00
#define _PD_DATA_DFP                            0x01

// Definitions of PD Power SRC/SNK Role
#define _PD_POWER_SNK                           0x00
#define _PD_POWER_SRC                           0x01


// Definitions of PD Vconn SRC/SNK Role
#define _PD_VCONN_SRC                           0x00
#define _PD_VCONN_NOT_SRC                       0x01

// Definitions of PD DP Alt. Mode Tx/Rx Role
#define _PD_DP_TX                               0x00
#define _PD_DP_RX                               0x01

// Definitions of PD Cable Plug Role
#define _PD_DEVICE                              0x00
#define _PD_CABLE                               0x01

// Definitions of DP Alt Mode USB/DP Config
#define _PD_USB_CONFIG                          0x00
#define _PD_DP_CONFIG                           0x01

// Definition of Hp Alt Mode SysEvent Queue Size
#define _TYPE_C_PD_HP_SYS_EVENT_QUEUE_SIZE      6

// Definitions of PD SinkTxOK/NG
#define _PD_SINK_TX_NG                          _BIT6
#define _PD_SINK_TX_OK                          _BIT7

// Definitions of PD VDM Type
#define _PD_UNSTRUCTURED_VDM                    0x00
#define _PD_STRUCTURED_VDM                      0x01

// Definitions of Discover ID No Retry
#define _DISCOVER_ID_NO_RETRY                   _FALSE   // Fix Lecroy [COMMON.CHECK.PD.2 Check Message Header]

// PD Function Enable Macro
#define GET_PD_RX0_FUNCTION_EN()                (g_stPdRx0Status.b1PDFunctionEnable)
#define SET_PD_RX0_FUNCTION_EN()                (g_stPdRx0Status.b1PDFunctionEnable = _TRUE)
#define CLR_PD_RX0_FUNCTION_EN()                (g_stPdRx0Status.b1PDFunctionEnable = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
// Enumeration of Alt Mode Attention Type
typedef enum
{
    _PD_DP_ATTENTION = 0x00,
    _PD_LENOVO_ATTENTION = 0x01,
    _PD_HP_ATTENTION = 0x02,
    _PD_DELL_ATTENTION = 0x03,
}EnumPDAttnType;

// Enumeration of Hp Atten_type
typedef enum
{
    _PD_HP_ATTEN_NONE = 0x00,
    _PD_HP_ATTEN_VWIRE = 0x01,
    _PD_HP_ATTEN_CONFIG = 0x02,
    _PD_HP_ATTEN_DATA = 0x03,
    _PD_HP_ATTEN_DISCONNECT = 0x04,
}EnumTypeCPDHpAttenType;

// Enumeration of Hp Vwire Operation
typedef enum
{
    _PD_HP_VWIRE_OP_NONE = 0x00,
    _PD_HP_VWIRE_OP_DEASSERT = 0x01,
    _PD_HP_VWIRE_OP_ASSERT = 0x02,
    _PD_HP_VWIRE_OP_TOGGLE = 0x03,
    _PD_HP_VWIRE_OP_SAMPLE = 0x04,
    _PD_HP_VWIRE_OP_ONE_SHOT = 0x08,
}EnumTypeCPDHpVwireOperation;

// Enumeration of Cable Discover ID Info
typedef enum
{
    _PD_PRODUCT_TYPE_UNDEFINED = 0x00,
    _PD_PASSIVE_CABLE = 0x01,
    _PD_ACTIVE_CABLE = 0x02,
    _PD_VCONN_POWERED_USB_DEVICE = 0x03,
}EnumTypeCPDCableProductType;

typedef enum
{
    _PD_CABLE_CONNECTOR_TYPE_UNCONFIRMED = 0x00,
    _PD_CABLE_TYPEC_RECEPTACLE = 0x01,
    _PD_CABLE_TYPEC_PLUG = 0x02,
}EnumTypeCPDCableConnectorType;

typedef enum
{
    _PD_CBL_TERMINATION_TYPE_UNDEFINED = 0x00,
    _PD_CBL_ONE_ACTIVE_ONE_PASSIVE = 0x01,
    _PD_CBL_BOTH_END_ACTIVE = 0x02,
}EnumTypeCPDCableTerminationType;

typedef enum
{
    _PD_CBL_SBU_TYPE_UNDEFINED = 0x00,
    _PD_CBL_SBU_PASSIVE = 0x01,
    _PD_CBL_SBU_ACTIVE = 0x02,
}EnumTypeCPDCableSbuType;

typedef enum
{
    _PD_CBL_USB_LANES_SUPPORT_UNDEFINED = 0x00,
    _PD_CBL_ONE_LANE = 0x01,
    _PD_CBL_TWO_LANES = 0x02,
}EnumTypeCPDCableUsbLanesSupport;

// Enumeration of EPR Mode Action
typedef enum
{
    // EPR Mode Action
    _PD_EPR_MODE_RESERVED = 0x00,
    _PD_EPR_MODE_ENTER = 0x01,
    _PD_EPR_MODE_ENTER_ACK = 0x02,
    _PD_EPR_MODE_ENTER_SUCCESS = 0x03,
    _PD_EPR_MODE_ENTER_FAILED = 0x04,
    _PD_EPR_MODE_EXIT = 0x05,
}EnumTypeCPDEPRModeAction;

// Enumeration of EPR Mode Enter Failed Reason
typedef enum
{
    // EPR Mode Enter Failed Reason
    _PD_EPR_MODE_ENTER_FAILED_UNKNOWN = 0x00,
    _PD_EPR_MODE_ENTER_FAILED_CABLE_NOT_EPR_CAP = 0x01,
    _PD_EPR_MODE_ENTER_FAILED_NOT_VCONN_SOURCE = 0x02,
    _PD_EPR_MODE_ENTER_FAILED_SINK_NOT_EPR_CAP = 0x03,
    _PD_EPR_MODE_ENTER_FAILED_SOURCE_UNABLE_TO_ENTER_EPR = 0x04,
    _PD_EPR_MODE_ENTER_FAILED_SOURCE_NOT_EPR_CAP = 0x05,
}EnumTypeCPDEnterEPRFailedReason;

// Enumeration of Extended Conntrol Message Type
typedef enum
{
    _PD_EXT_CTRL_TYPE_RESERVED = 0x00,
    _PD_EXT_CTRL_TYPE_EPR_GET_SRC_CAP = 0x01,
    _PD_EXT_CTRL_TYPE_EPR_GET_SNK_CAP = 0x02,
    _PD_EXT_CTRL_TYPE_EPR_KEEP_ALIVE = 0x03,
    _PD_EXT_CTRL_TYPE_EPR_KEEP_ALIVE_ACK = 0x04,
}EnumTypeCPDExtCtrlType;

// Enumeration of PD SVDM Version From SVDM Header [14:13] Major, [12:11] Minor (Updated in Discover ID)
typedef enum
{
    _PD_SVDM_VER_2_0_EARLIER = _SVDM_VERSION_2_0_EARLIER,
    _PD_SVDM_VER_2_1 = _SVDM_VERSION_2_1,
}EnumTypeCPDSvdmVersion;

// DPAM v2.1: Enumeration of Vdo Version From Discover Mode Ack(SOP/SOP'/SOP'') or Dp Config(SOP)
typedef enum
{
    _PD_DPAM_VER_2_0_EARLIER = 0x00,
    _PD_DPAM_VER_2_1_HIGHER = 0x01,
}EnumTypeCPDDpamVersion;

typedef enum
{
    _PD_CBL_PIN_ASSIGNMENT_UNCONFIRMED = 0x00,
    _PD_CBL_PIN_ASSIGNMENT_C_AND_D = 0x01,
    _PD_CBL_PIN_ASSIGNMENT_E = 0x02,
}EnumTypeCPDCablePinAssignment;

typedef enum
{
    _PD_CBL_TBT3_PRODUCT_TYPE_UNCONFIRMED = 0x00,
    _PD_CBL_TBT3_ACTIVE_CABLE = 0x01,
    _PD_CBL_TBT3_PASSIVE_CABLE = 0x02,
}EnumTypeCPDCableTbt3ProductType;

typedef enum
{
    _PD_CBL_TBT3_DIRECTION_UNCONFIRMED = 0x00,
    _PD_CBL_TBT3_BIDIRECTION = 0x01,
    _PD_CBL_TBT3_UNIDIRECTION = 0x02,
}EnumTypeCPDCableTbt3Direction;

typedef enum
{
    _PD_CBL_TBT3_ROUNDED_SUPPORT_UNCONFIRMED = 0x00,
    _PD_CBL_TBT3_3RD_GEN_NON_ROUNDED = 0x01,
    _PD_CBL_TBT3_3RD_AND_4TH_GEN_ROUNDED = 0x02,
}EnumTypeCPDCableTbt3RoundedSupport;

typedef enum
{
    _PD_CBL_TBT3_SPEED_UNCONFIRMED = 0x00,
    _PD_CBL_TBT3_U3P1_GEN1 = 0x01,
    _PD_CBL_TBT3_10G = 0x02,
    _PD_CBL_TBT3_20G = 0x03,
}EnumTypeCPDCableTbt3Speed;

typedef enum
{
    _PD_CBL_USB_2_ONLY = 0x00,
    _PD_CBL_USB_3_GEN1 = 0x01,
    _PD_CBL_USB_3OR4_GEN2 = 0x02,
    _PD_CBL_USB_4_GEN3 = 0x03,
}EnumTypeCPDCableUsbHighestSpeed;

typedef enum
{
    _PD_CBL_U3_TO_U0_UNDEFINED = 0x00,
    _PD_CBL_U3_TO_U0_DIRECT = 0x01,
    _PD_CBL_U3_TO_U0_THROUGH_U3S = 0x02,
}EnumTypeCPDCableU3ToU0TransitionMode;

// PD Current Status Info
typedef struct
{
    BYTE ucPDState;
    // -----------------------------
    BYTE ucPDSubState;
    // -----------------------------
    BYTE b8PDDpAltState : 8;
    // -----------------------------
    BYTE b6PDLenovoAltState : 6;
    BYTE b1PDPowerContract : 1;
    BYTE b1UnconstrainedPower : 1;
    // -----------------------------
    BYTE b6SrcCapCnt : 6;
    BYTE b2HardRstCnt : 2;
    // -----------------------------
    BYTE b4CheckVbusCnt : 4;
    BYTE b4BistMode : 4;
    // -----------------------------
    BYTE b3PDNumOfSPRSrcCap : 3;
    BYTE b3PDNumOfEPRSrcCap : 3;
    BYTE b2SpecVersion : 2;
    // -----------------------------
    BYTE b3PDNumOfSPRSnkCap : 3;
    BYTE b3PDNumOfEPRSnkCap : 3;
    BYTE b1PDPowerRole : 1;
    BYTE b1PDDataRole : 1;
    // -----------------------------
    BYTE b2PDAmsStatus : 2;
    BYTE b1PDVconnRole : 1;
    BYTE b1HRST_Pwr_Off : 1;
    BYTE b1GetSnkCapWait : 1;
    BYTE b1PDVconnSwapReject : 1;
    BYTE b1RcvSnkCap : 1;
    BYTE b1RcvSrcCap : 1;
    // -----------------------------
    BYTE b1ReqWait : 1;
    BYTE b1PRSwapWait : 1;
    BYTE b1DRSwapWait : 1;
    BYTE b1VCSwapWait : 1;
    BYTE b1SrcCapSent : 1;
    BYTE b1SnkCapWait : 1;
    BYTE b2RcvBistMsgCnt : 2;
    // -----------------------------
    BYTE b1PRS_Processing : 1;
    BYTE b1InteropS8 : 1;
    BYTE b1AlertSent : 1;
    BYTE b1PDDRSwapReject : 1;
    BYTE b1PDPRSwapReject : 1;
    BYTE b1VdmBusy : 1;
    BYTE b1VdmMsgWait : 1;
    BYTE b1CblWait : 1;
    // -----------------------------
    EnumTypeCReqType enumReqType;
    // -----------------------------
    BYTE ucTargetVolRDO;
    // -----------------------------
    WORD b1PDFunctionEnable : 1;
    WORD b1PDHandlerOngoing : 1;
    WORD b1GetSrcCapSent : 1;
    WORD b1GetSnkCapSent : 1;
    WORD b10WDTimer : 10;
}StructPDStatus;

// PD Cable Status Info
typedef struct
{
    WORD b10CableMaxCur : 10;
    WORD b4CableState : 4;
    WORD b2CableSpecVer : 2;
    // -----------------------------
    WORD b10CableMaxVol : 10;   // Unit = 100mV
    WORD b5DiscoverIdRetryFailCnt : 5;
    WORD b1CableModalOperation : 1;
    // -----------------------------
    EnumTypeCCablePdCapability enumTypeCCablePdCap;
    EnumTypeCPDCableProductType enumTypeCCableProductType;
    EnumTypeCPDCableConnectorType enumTypeCCableConnectorType;
    EnumTypeCPDCableTerminationType enumTypeCCableTerminationType;
    EnumTypeCPDCableSbuType enumTypeCCableSbuType;
    EnumTypeCPDCableUsbLanesSupport enumTypeCCableUsbLanesSupport;
    EnumTypeCPDSvdmVersion enumTypeCCableSvdmVersion;
    EnumTypeCPDDpamVersion enumTypeCCableDpamVersion;
    EnumTypeCPDCablePinAssignment enumTypeCCablePinAssignment;
    EnumTypeCPDCableTbt3ProductType enumTypeCCableTbt3ProductType;
    EnumTypeCPDCableTbt3Direction enumTypeCCableTbt3Direction;
    EnumTypeCPDCableTbt3RoundedSupport enumTypeCCableTbt3RoundedSupport;
    EnumTypeCPDCableTbt3Speed enumTypeCCableTbt3Speed;
    EnumTypeCPDCableUsbHighestSpeed enumTypeCCableUsbHighestSpeed;
    EnumTypeCPDCableU3ToU0TransitionMode enumTypeCCableU3ToU0TransitionMode;
    BYTE b1CableVconnRequired : 1;
    BYTE b1CableVbusThrough : 1;
    BYTE b1CableSopPP : 1;
    BYTE b1CableUSB4 : 1;
    BYTE b1CableUSB3_2 : 1;
    BYTE b1ChargeThroughSupport : 1;
    BYTE b1CableSoftRstReq : 1;
    BYTE b1CableSbuSupport : 1;
    // -----------------------------
    BYTE b1CableDpEnterDpModeSupport : 1;
    BYTE b1CableSvidSearchFinish : 1;
    BYTE b1CableDpSvidSupport : 1;
    BYTE b1CableDpModeInfoReceived : 1;
    BYTE b1CableTbt3SvidSupport : 1;
    BYTE b1CableTbt3Retimer : 1;
    BYTE b1CableTbt3Optical : 1;
    BYTE b1CableEprModeCapable : 1;
}StructCableStatus;

// EPR Mode Info
typedef struct
{
    EnumTypeCPDEPRModeAction enumPDEPRModeAction;
    EnumTypeCPDEnterEPRFailedReason enumPDEnterEPRFailedReason;
    EnumTypeCPDExtCtrlType enumPDExtCtrlType;
    // -----------------------------
    BYTE ucPartnerEPRSinkPDP;
    // -----------------------------
    BYTE b1EnterEPRFlow : 1;
    BYTE b1EPRMode : 1;
    BYTE b1EPRSRCCapable : 1;
}StructTypeCEPRModeInfo;

// PD Alt. Mode Info
typedef struct
{
    BYTE ucRcvVdmMsg;
    // -----------------------------
    EnumTypeCPinCfgType enumDpRxPinAssignment;
    // -----------------------------
    BYTE ucPartnerPinAssignmentCap;
    // -----------------------------
    EnumTypeCPinCfgCapType enumPinAssignmentCap;
    // -----------------------------
    BYTE ucVdmSVID_H;
    // -----------------------------
    BYTE ucVdmSVID_L;
    // -----------------------------
    EnumTypeCUFPProductType enumUFPProductType;
    // -----------------------------
    EnumTypeCDFPProductType enumDFPProductType;
    // -----------------------------
    EnumTypeCLenovoDeviceType enumLenovoDeviceType;
    // -----------------------------
    BYTE ucLenovoDockingEvent;
    // -----------------------------
    BYTE ucLenovoSystemAcknowledge;
    // -----------------------------
    BYTE ucLenovoSystemEvent;
    // -----------------------------
    BYTE b3VdmObjPos : 3;
    BYTE b3DpObjPos : 3;
    BYTE b1AltModeFunc : 1;
    BYTE b1RcvVdmType : 1;
    // -----------------------------
    BYTE b3LenovoObjPos : 3;
    BYTE b3LenovoAttnCnt : 3;
    BYTE b1MultiFunctionBit : 1;
    BYTE b1DpSvidSearchFinish : 1;
    // -----------------------------
    EnumPDAttnType enumAttnType;
    // -----------------------------
    BYTE b1DpAltModeEnter : 1;
    BYTE b1DpAltModeConfig : 1;
    BYTE b1DpAltModeTargetConfig : 1;
    BYTE b1DpAltModeWaitConfig : 1;
    BYTE b1DpAltModeExit : 1;
    BYTE b1LenovoAttnSent : 1;
    BYTE b1LenovoAltModeEnter : 1;
    BYTE b1AttentionWait : 1;
    // -----------------------------
    BYTE b1PartnerInitAltMode : 1;
    BYTE b2PartnerVdmNoRespCnt : 2;
    BYTE b2CblVdmNoRespCnt : 2;
    BYTE b3VdmBusyCnt : 3;
    // -----------------------------
    BYTE b1MultiFunctionChange : 1;
    BYTE b1MultiFunctionChangeDone : 1;
    BYTE b1ForceHpdIrq : 1;
}StructAltModeInfo;

// PD Acer Alt Mode Info
typedef struct
{
    BYTE b6AcerAltModeState : 6;
    BYTE b1AcerAltModeEnter : 1;
}StructAcerAltModeInfo;

// PD Hp Alt Mode Info
typedef struct
{
    BYTE b1HpAltModeEnter : 1;
    BYTE b7HpI2cAddr : 7;
    // -----------------------------
    BYTE b6HpAltModeState : 6;
    BYTE b2HpOwnAmAddr_H : 2;
    // -----------------------------
    BYTE ucHpOwnAmAddr_L;
    // -----------------------------
    BYTE ucHpOwnAmAddr_M;
    // -----------------------------
    BYTE b3HpAttenCnt : 3;
    EnumTypeCPDHpVwireOperation enumHpVwireOp;
    EnumTypeCPDHpAttenType enumHpAttenType;
}StructTypeCHpAltModeInfo;

// Struct for Type-C Hp Alt Mode System Event Queue
typedef struct
{
    BYTE b3SysEventCnt : 3;
    BYTE b3SysEventHead : 3;
    BYTE b3SysEventTail : 3;
    StructTypeCHpSysEvent pstSysEvent[_TYPE_C_PD_HP_SYS_EVENT_QUEUE_SIZE];
}StructTypeCHpSysEventQueue;

// PD Dell Alt Mode Info
typedef struct
{
    BYTE b6DellAltModeState : 6;
    BYTE b1DellAltModeEnter : 1;
    BYTE b1DellAMTimeout : 1;
    // -----------------------------
    BYTE b3DellObjPos : 3;
    BYTE b3DellAttenCnt : 3;
    BYTE b1DellAttenWait : 1;
    BYTE b1DellInitComplete : 1;
}StructTypeCDellAltModeInfo;

// PD 3.0 Extended Message Header
typedef struct
{
    WORD b1Chunked : 1;
    WORD b4ChunkNum : 4;
    WORD b1ChunkRequest : 1;
    WORD b9DataSize : 9;
    WORD b1TxChunked : 1;
    // -----------------------------
    BYTE b4TxChunkNum : 4;
}StructExtMsgInfo;

// PD Message Transmit / Receive Info
typedef struct
{
    BYTE ucRcvMsg;
    // -----------------------------
    BYTE ucFifoRcvErrStatus;
    // -----------------------------
    BYTE b3RcvNodCnt : 3;
    BYTE b5TxResult : 5;
    // -----------------------------
    BYTE b5TxResult_EXINT : 5;
    BYTE b1IntOverWrite : 1;
    BYTE b1FifoClr : 1;
    BYTE b1BusIdle : 1;
}StructMsgInfo;

// Struct for Type-C Source/Sink Capability PDO Content
typedef struct
{
    EnumPDPdoType enumPdoType;
    // -----------------------------
    WORD usMaxVoltage;    // Unit = 10mV
    WORD usMinVoltage;    // Unit = 10mV
    // -----------------------------
    WORD b2PeakCurrent : 2;
    WORD b10MaxCurrent : 10;
}StructTypeCPDO;

// USB-C PD SNK Request Normal RDO Struct
typedef struct
{
    WORD usVoltage;
    // -----------------------------
    WORD b4ObjPos : 4;
    WORD b10OpCurrent : 10;
    WORD b1CapMis : 1;
    WORD b1GiveBack : 1;
    // -----------------------------
    WORD b1PPSSmallStep : 1;
    WORD b1AVSSmallStep : 1;
    WORD b10MaxCurrent : 10;
}StructSnkRDO;

// PD Power Contract Negotiated Status
typedef struct
{
    WORD usVoltage;
    WORD usCurrent;
    // -----------------------------
    BYTE b4ObjPos : 4;
}StructPdoStatus;

// PD Info From Port Partner Src/Snk Capability
typedef struct
{
    EnumTypeCPDSvdmVersion enumSvdmVersion;
    EnumTypeCPDDpamVersion enumDpamVersion;
    BYTE b3NumOfSrcCap : 3;
    BYTE b3NumOfSnkCap : 3;
    BYTE b2FrsCurrent : 2;
    // -----------------------------
    BYTE b1DualRolePower : 1;
    BYTE b1DualRoleData : 1;
    BYTE b1SuspendSupport : 1;
    BYTE b1ExtPower : 1;
    BYTE b1UsbCapable : 1;
    BYTE b1UnchkSupport : 1;
    BYTE b1PartnerEPRCapable : 1;
    BYTE b1HigherCap : 1;
    // -----------------------------
    BYTE b1ALTSupport : 1;
}StructPdPartnerInfo;

// Power Delivery Alt. Mode HPD Queue
typedef struct
{
    BYTE b1HpdStatus : 1;
    BYTE b3HpdCnt : 3;
    BYTE b2HpdWptr : 2;
    BYTE b2HpdRptr : 2;
    // -----------------------------
    EnumPDHpdType penumHpdType[_HPD_QUEUE_DEPTH];
    WORD pusHpdSpace[_HPD_QUEUE_DEPTH];
}StructHpdQueue;

// Power Delivery Alt. Mode HPD Queue
typedef struct
{
    BYTE b1Valid : 1;
    BYTE b1CancelSrcEprKeepAlive : 1;
    EnumScalerTimerEventID enumEventID;
    WORD usEventTime;
}StructPdTimerEvent;

// Power Delivery Event
typedef struct
{
    EnumPDSysEvent enumSystemEvent; // Power Delivery System Request Event
    EnumPDPortCtrlEvent enumPortCtrlEvent; // Power Delivery Port Controller Inform System / User of Events Occurred
}StructPdEvent;

// Enumeration of PD State
typedef enum
{
    _PD_SRC_START_UP = 0x01,
    _PD_SRC_SEND_CAP = 0x02,
    _PD_SRC_INT_WAIT_REQ = 0x03,
    _PD_SRC_INT_SEND_ACCEPT_REQ = 0x04,
    _PD_SRC_INT_SEND_REJECT_REQ = 0x05,
    _PD_SRC_INT_SEND_WAIT_REQ = 0x06,
    _PD_SRC_INT_TRANSIT_POWER = 0x07,
    _PD_SRC_INT_SEND_PSRDY = 0x08,
    _PD_SRC_READY = 0x09,
    _PD_SNK_START_UP = 0x11,
    _PD_SNK_INT_WAIT_SRC_CAP = 0x12,
    _PD_SNK_INT_SEND_REQUEST = 0x13,
    _PD_SNK_INT_WAIT_REQ_RESP = 0x14,
    _PD_SNK_INT_WAIT_PS_RDY = 0x15,
    _PD_SNK_READY = 0x16,
    _PD_SEND_CBL_DISCOVER_ID = 0x20,
    _PD_INT_WAIT_CBL_DISCOVER_ID_RESP = 0x21,
    _PD_SEND_CBL_SOFT_RESET = 0x22,
    _PD_INT_WAIT_CBL_SOFT_RESET_RESP = 0x23,

    // FW STATE FOR EPR MODE
    _PD_SRC_INT_WAIT_EPR_REQ = 0x30,

    _PD_INT_SEND_SOFTRESET = 0xF0,
    _PD_INT_WAIT_SOFTRESET_RESP = 0xF1,
    _PD_INT_SEND_SOFTRESET_RESP = 0xF2,
    _PD_HARDRESET = 0xFE,
    _PD_NO_RESPONSE = 0xFF,
}EnumPDState;

// Enumeration of PD Sub-State (Running Under _PE_SRC_READY/_PE_SNK_READY)
typedef enum
{
    _PD_SUB_STATE_NONE = 0x00,
    _PD_SUB_SNK_READY = 0x01,
    _PD_SUB_SRC_READY = 0x10,
    _PD_SUB_CABLE_PROC = 0x20,
    _PD_SUB_SEND_GET_SNK_CAP = 0x31,
    _PD_SUB_INT_WAIT_SNK_CAP = 0x32,
    _PD_SUB_SEND_GET_SRC_CAP = 0x33,
    _PD_SUB_INT_WAIT_SRC_CAP = 0x34,
    _PD_SUB_INT_SEND_SRC_CAP = 0x35,
    _PD_SUB_INT_SEND_SNK_CAP = 0x36,
    _PD_SUB_SEND_SRC_CAP = 0x37,

    // PR_SWAP States
    _PD_SUB_SEND_PR_SWAP = 0x40,
    _PD_SUB_INT_WAIT_PRS_RESP = 0x41,
    _PD_SUB_INT_SEND_ACCEPT_PRS = 0x42,
    _PD_SUB_INT_WAIT_SRC_ON = 0x43,
    _PD_SUB_INT_WAIT_SRC_OFF = 0x44,
    _PD_SUB_INT_SEND_SRC_ON_PSRDY = 0x45,
    _PD_SUB_PRS_SRC_OFF = 0x46,

    // DR_SWAP States
    _PD_SUB_SEND_DR_SWAP = 0x47,
    _PD_SUB_INT_WAIT_DRS_RESP = 0x48,
    _PD_SUB_INT_SEND_ACCEPT_DRS = 0x49,

    // VCONN_SWAP States
    _PD_SUB_SEND_VCONN_SWAP = 0x4A,
    _PD_SUB_INT_WAIT_VCS_RESP = 0x4B,
    _PD_SUB_INT_SEND_ACCEPT_VCS = 0x4C,
    _PD_SUB_INT_WAIT_VCONN_ON = 0x4D,
    _PD_SUB_INT_SEND_VCONN_ON_PSRDY = 0x4E,

    // PD 3.0 DATA / EXTENDED MSG States
    _PD_SUB_INT_SEND_SRC_CAP_EXT = 0x60,
    _PD_SUB_INT_SEND_STATUS = 0x61,
    _PD_SUB_INT_SEND_MFC_INFO = 0x62,
    _PD_SUB_INT_SEND_CHK_TEST_REQ = 0x63,
    _PD_SUB_INT_WAIT_CHK_TEST_RESP = 0x64,
    _PD_SUB_INT_WAIT_STATUS = 0x65,
    _PD_SUB_INT_SEND_GET_BAT_STATUS = 0x66,
    _PD_SUB_INT_WAIT_BAT_STATUS = 0x67,
    _PD_SUB_INT_SEND_PPS_STATUS = 0x68,
    _PD_SUB_SEND_GET_STATUS = 0x69,
    _PD_SUB_SEND_ALERT = 0x6A,
    _PD_SUB_INT_SEND_REVISION = 0x6B,
    _PD_SUB_INT_SEND_SNK_CAP_EXT = 0x6C,

    // SUB STATE FOR EPR MODE
    _PD_SUB_INT_SEND_EPR_ENTER_ACK = 0x70,
    _PD_SUB_INT_SEND_EPR_ENTER_FAILED = 0x71,
    _PD_SUB_INT_SEND_EPR_ENTER_SUCCESSFUL = 0x72,
    _PD_SUB_WDINT_DISCOVER_CABLE = 0x73,
    _PD_SUB_WDINT_SEND_VCONN_SWAP = 0x74,
    _PD_SUB_INT_SEND_VCONN_SWAP = 0x75,
    _PD_SUB_SEND_EPR_SRC_CAP = 0x76,
    _PD_SUB_INT_WAIT_EPR_SRC_CAP_CHUNK_REQ = 0x77,
    _PD_SUB_INT_SEND_EPR_SRC_CAP = 0x78,
    _PD_SUB_INT_SEND_EPR_KEEP_ALIVE_ACK = 0x79,
    _PD_SUB_WDINT_SEND_EPR_SRC_CAP = 0x7A,

    // SUB STATE FOR ALT MODE
    _PD_SUB_SEND_DP_VDM_REQ = 0xA1,
    _PD_SUB_INT_SEND_VDM_RESP = 0xA2,
    _PD_SUB_INT_WAIT_VDM_RESP = 0xA3,
    _PD_SUB_BIST_MODE = 0xB0,
    _PD_SUB_INT_SEND_REJECT = 0xF0,
    _PD_SUB_INT_SEND_WAIT = 0xF1,
    _PD_SUB_INT_SEND_NOT_SUPPORT = 0xF2,
}EnumPDSubState;

// Enumeration of PD Cable State
typedef enum
{
    _PD_CBL_STATE_NONE = 0x00,
    _PD_CBL_SEND_DISCOVER_ID = 0x01,
    _PD_CBL_INT_SEND_DISCOVER_ID = 0x02,
    _PD_CBL_INT_WAIT_DISCOVER_ID_RESP = 0x03,
    _PD_CBL_SEND_SOFT_RST = 0x04,
    _PD_CBL_INT_SEND_SOFT_RST = 0x05,
    _PD_CBL_INT_WAIT_SOFT_RST_RESP = 0x06,
    _PD_CBL_SEND_CBL_RST = 0x0A,
    _PD_CBL_NO_RESPONSE = 0x0F,
}EnumPDCableState;

// Enumeration of DP Alt. Mode State Machine
typedef enum
{
    _PD_ALT_MODE_NONE = 0x00,
    _PD_ALT_MODE_SEND_DISCOVER_ID = 0x01,
    _PD_ALT_MODE_INT_WAIT_DISCOVER_ID_RESP = 0x02,
    _PD_ALT_MODE_INT_SEND_DISCOVER_ID_ACK = 0x03,
    _PD_ALT_MODE_INT_SEND_DISCOVER_ID_NAK = 0x04,
    _PD_ALT_MODE_SEND_DISCOVER_SVID = 0x05,
    _PD_ALT_MODE_INT_WAIT_DISCOVER_SVID_RESP = 0x06,
    _PD_ALT_MODE_INT_SEND_DISCOVER_SVID_ACK = 0x07,
    _PD_ALT_MODE_INT_SEND_DISCOVER_SVID_NAK = 0x08,
    _PD_ALT_MODE_SEND_DISCOVER_MODE = 0x09,
    _PD_ALT_MODE_INT_WAIT_DISCOVER_MODE_RESP = 0x0A,
    _PD_ALT_MODE_INT_SEND_DISCOVER_MODE_ACK = 0x0B,
    _PD_ALT_MODE_INT_SEND_DISCOVER_MODE_NAK = 0x0C,
    _PD_ALT_MODE_SEND_ENTER_MODE = 0x0D,
    _PD_ALT_MODE_INT_WAIT_ENTER_MODE_RESP = 0x0E,
    _PD_ALT_MODE_INT_SEND_ENTER_MODE_ACK = 0x0F,
    _PD_ALT_MODE_INT_SEND_ENTER_MODE_NAK = 0x10,
    _PD_ALT_MODE_SEND_EXIT_MODE = 0x11,
    _PD_ALT_MODE_INT_WAIT_EXIT_MODE_RESP = 0x12,
    _PD_ALT_MODE_INT_SEND_EXIT_MODE_ACK = 0x13,
    _PD_ALT_MODE_INT_SEND_EXIT_MODE_NAK = 0x14,
    _PD_ALT_MODE_SEND_DP_STATUS = 0x15,
    _PD_ALT_MODE_INT_WAIT_DP_STATUS_RESP = 0x16,
    _PD_ALT_MODE_INT_SEND_DP_STATUS_ACK = 0x17,
    _PD_ALT_MODE_INT_SEND_DP_STATUS_NAK = 0x18,
    _PD_ALT_MODE_SEND_DP_CONFIG = 0x19,
    _PD_ALT_MODE_INT_WAIT_DP_CONFIG_RESP = 0x1A,
    _PD_ALT_MODE_INT_SEND_DP_CONFIG_ACK = 0x1B,
    _PD_ALT_MODE_INT_SEND_DP_CONFIG_NAK = 0x1C,
    _PD_ALT_MODE_SEND_LENOVO_GET_STATUS = 0x1D,
    _PD_ALT_MODE_INT_WAIT_LENOVO_GET_STATUS_RESP = 0x1E,
    _PD_ALT_MODE_INT_SEND_LENOVO_GET_STATUS_ACK = 0x1F,
    _PD_ALT_MODE_INT_SEND_LENOVO_GET_STATUS_NAK = 0x20,
    _PD_ALT_MODE_INT_SEND_HP_SET_CONFIG_ACK = 0x21,
    _PD_ALT_MODE_SEND_HP_SET_VWIRE_SAMPLE_ACK = 0x22,
    _PD_ALT_MODE_SEND_HP_ATTEN_CONFIG = 0x23,
    _PD_ALT_MODE_SEND_HP_ATTEN_VWIRE = 0x24,
    _PD_ALT_MODE_SEND_HP_ATTEN_DATA = 0x25,
    _PD_ALT_MODE_INT_SEND_DELL_0X12_ACK = 0x26,
    _PD_ALT_MODE_SEND_DELL_ATTEN = 0x27,
    _PD_ALT_MODE_INT_WAIT_DELL_0X13 = 0x28,
    _PD_ALT_MODE_SEND_ATTENTION = 0x29,
    _PD_ALT_MODE_INT_WAIT_ATTENTION = 0x2A,
    _PD_ALT_MODE_SEND_DISCOVER_ID_SOP_P = 0x2B,
    _PD_ALT_MODE_INT_WAIT_DISCOVER_ID_RESP_SOP_P = 0x2C,
    _PD_ALT_MODE_SEND_DISCOVER_SVID_SOP_P = 0x2D,
    _PD_ALT_MODE_INT_WAIT_DISCOVER_SVID_RESP_SOP_P = 0x2E,
    _PD_ALT_MODE_SEND_DP_DISCOVER_MODE_SOP_P = 0x2F,
    _PD_ALT_MODE_INT_WAIT_DP_DISCOVER_MODE_RESP_SOP_P = 0x30,
    _PD_ALT_MODE_SEND_TBT3_DISCOVER_MODE_SOP_P = 0x31,
    _PD_ALT_MODE_INT_WAIT_TBT3_DISCOVER_MODE_RESP_SOP_P = 0x32,
    _PD_ALT_MODE_SEND_ENTER_MODE_SOP_P = 0x33,
    _PD_ALT_MODE_INT_WAIT_ENTER_MODE_RESP_SOP_P = 0x34,
    _PD_ALT_MODE_SEND_ENTER_MODE_SOP_PP = 0x35,
    _PD_ALT_MODE_INT_WAIT_ENTER_MODE_RESP_SOP_PP = 0x36,
    _PD_ALT_MODE_SEND_DP_CONFIG_SOP_P = 0x37,
    _PD_ALT_MODE_INT_WAIT_DP_CONFIG_RESP_SOP_P = 0x38,
    _PD_ALT_MODE_SEND_DP_CONFIG_SOP_PP = 0x39,
    _PD_ALT_MODE_INT_WAIT_DP_CONFIG_RESP_SOP_PP = 0x3A,
    _PD_ALT_MODE_SEND_EXIT_MODE_SOP_P = 0x3B,
    _PD_ALT_MODE_INT_WAIT_EXIT_MODE_RESP_SOP_P = 0x3C,
    _PD_ALT_MODE_SEND_EXIT_MODE_SOP_PP = 0x3D,
    _PD_ALT_MODE_INT_WAIT_EXIT_MODE_RESP_SOP_PP = 0x3E,
    _PD_ALT_MODE_READY = 0x3F,
    _PD_ALT_MODE_ERROR = 0x40,
}EnumPDAltModeState;

// Enumeration of PD Atomic Message Sequence Status
typedef enum
{
    _PD_AMS_NONE = 0x00,
    _PD_AMS_INTERRUPTIBLE = 0x01,
    _PD_AMS_NON_INTERRUPTIBLE = 0x02,
    _PD_AMS_POWER_TRANSITION = 0x03,
}EnumPDAmsState;

// Enumeration of PD Packet Type
typedef enum
{
    _PD_SOP_PKT = 0x00,
    _PD_SOP_P_PKT = 0x01,
    _PD_SOP_PP_PKT = 0x02,
    _PD_HARD_RESET_PKT = 0x03,
    _PD_CABLE_RESET_PKT = 0x04,
    _PD_VS1_SOP_PKT = 0x05,
    _PD_VS2_SOP_PKT = 0x06,
    _PD_VS3_SOP_PKT = 0x07,
}EnumPDPacketType;

// Enumeration of PD Tx Check Result
typedef enum
{
    _PD_TX_NOT_AVAILABLE = 0x00,
    _PD_TX_AVAILABLE = 0x01,
    _PD_TX_WAIT_SRC_INIT_AMS_TIMER = 0x02,
}EnumTypeCTxCheckResult;

// Enumeration of PD Tx Transmission Result
typedef enum
{
    _PD_SENT_CONFLICT = _BIT4,
    _PD_SENT_SUCCESS = _BIT3,
    _PD_SENT_RETRY_FAIL = _BIT2,
    _PD_SENT_DISCARDED = _BIT1,
    _PD_SENT_HARD_RST = _BIT0,
}EnumTxSentResult;

// Enumeration of PD Rx FIFO
typedef enum
{
    _PD_RX_FIFO_0 = 0x00,
    _PD_RX_FIFO_1 = 0x01,
    _PD_RX_FIFO_2 = 0x02,
    _PD_RX_FIFO_RSV = 0x03,
}EnumRxFifoIndex;

// Enumeration of PD Message Command Type
typedef enum
{
    _PD_CMD_TYPE_CTRL = 0x00,
    _PD_CMD_TYPE_DATA = _BIT6,
    _PD_CMD_TYPE_EXT = _BIT7,
}EnumPDCmdType;

// Enumeration of PD Message Command
// Control Msg 0x01 - 1F / Data Msg. 0x40 - 5F / Ext Msg. 0x80 - 9F
typedef enum
{
    _PD_CMD_RSV = 0x00,
    _PD_CMD_GOODCRC = 0x01,
    _PD_CMD_GOTOMIN = 0x02,
    _PD_CMD_ACCEPT = 0x03,
    _PD_CMD_REJECT = 0x04,
    _PD_CMD_PING = 0x05,
    _PD_CMD_PS_RDY = 0x06,
    _PD_CMD_GET_SRC_CAP = 0x07,
    _PD_CMD_GET_SNK_CAP = 0x08,
    _PD_CMD_DR_SWAP = 0x09,
    _PD_CMD_PR_SWAP = 0x0A,
    _PD_CMD_VCONN_SWAP = 0x0B,
    _PD_CMD_WAIT = 0x0C,
    _PD_CMD_SOFT_RESET = 0x0D,
    _PD_CMD_NOT_SUPPORT = 0x10,
    _PD_CMD_GET_SRC_CAP_EXT = 0x11,
    _PD_CMD_GET_STATUS = 0x12,
    _PD_CMD_FR_SWAP = 0x13,
    _PD_CMD_GET_PPS_STATUS = 0x14,
    _PD_CMD_GET_COUNTRY_CODES = 0x15,
    _PD_CMD_GET_SNK_CAP_EXT = 0x16,
    _PD_CMD_GET_REVISION = 0x18,

    _PD_CMD_SRC_CAP = 0x41,
    _PD_CMD_REQUEST = 0x42,
    _PD_CMD_BIST = 0x43,
    _PD_CMD_SNK_CAP = 0x44,
    _PD_CMD_BAT_STATUS = 0x45,
    _PD_CMD_ALERT = 0x46,
    _PD_CMD_GET_COUNTRY_INFO = 0x47,
    _PD_CMD_EPR_REQUEST = 0x49,
    _PD_CMD_EPR_MODE = 0x4A,
    _PD_CMD_REVISION = 0x4C,
    _PD_CMD_VDM = 0x4F,

    _PD_CMD_SRC_CAP_EXT = 0x81,
    _PD_CMD_STATUS = 0x82,
    _PD_CMD_GET_BAT_CAP = 0x83,
    _PD_CMD_GET_BAT_STATUS = 0x84,
    _PD_CMD_BAT_CAP = 0x85,
    _PD_CMD_GET_MFC_INFO = 0x86,
    _PD_CMD_MFC_INFO = 0x87,
    _PD_CMD_SEC_REQ = 0x88,
    _PD_CMD_SEC_RESP = 0x89,
    _PD_CMD_FW_UPDATE_REQ = 0x8A,
    _PD_CMD_FW_UPDATE_RESP = 0x8B,
    _PD_CMD_PPS_STATUS = 0x8C,
    _PD_CMD_COUNTRY_INFO = 0x8D,
    _PD_CMD_COUNTRY_CODES = 0x8E,
    _PD_CMD_SNK_CAP_EXT = 0x8F,
    _PD_CMD_EXTENDED_CONTROL = 0x90,
    _PD_CMD_EPR_SRC_CAP = 0x91,
    _PD_CMD_CHUNK_TEST = 0x9F,

    _PD_CMD_UNDEFINED = 0xFF,
}EnumPDCmd;

// Enumeration of VDM Message Command Type
typedef enum
{
    _PD_VDM_CMD_TYPE_REQ = 0x00,
    _PD_VDM_CMD_TYPE_ACK = _BIT6,
    _PD_VDM_CMD_TYPE_NAK = _BIT7,
    _PD_VDM_CMD_TYPE_BUSY = (_BIT7 | _BIT6),
}EnumPDVdmCmdType;

// Enumeration of PD VDM Message Command Type
typedef enum
{
    _PD_VDM_CMD_RESERVED = 0x00,
    _PD_VDM_CMD_DISCOVER_ID_REQ = 0x01,
    _PD_VDM_CMD_DISCOVER_SVID_REQ = 0x02,
    _PD_VDM_CMD_DISCOVER_MODE_REQ = 0x03,
    _PD_VDM_CMD_ENTER_MODE_REQ = 0x04,
    _PD_VDM_CMD_EXIT_MODE_REQ = 0x05,
    _PD_VDM_CMD_ATTENTION_REQ = 0x06,
    _PD_VDM_CMD_10 = 0x10,  // DP, Lenovo Status Req
    _PD_VDM_CMD_11 = 0x11,  // DP Config Req
    _PD_VDM_CMD_15 = 0x15,  // Acer Attention
    _PD_VDM_CMD_DISCOVER_ID_ACK = 0x41,
    _PD_VDM_CMD_DISCOVER_SVID_ACK = 0x42,
    _PD_VDM_CMD_DISCOVER_MODE_ACK = 0x43,
    _PD_VDM_CMD_ENTER_MODE_ACK = 0x44,
    _PD_VDM_CMD_EXIT_MODE_ACK = 0x45,
    _PD_VDM_CMD_50 = 0x50,
    _PD_VDM_CMD_51 = 0x51,
    _PD_VDM_CMD_52 = 0x52,  // HP Set_vwire Sample ACK
    _PD_VDM_CMD_DISCOVER_ID_NAK = 0x81,
    _PD_VDM_CMD_DISCOVER_SVID_NAK = 0x82,
    _PD_VDM_CMD_DISCOVER_MODE_NAK = 0x83,
    _PD_VDM_CMD_ENTER_MODE_NAK = 0x84,
    _PD_VDM_CMD_EXIT_MODE_NAK = 0x85,
    _PD_VDM_CMD_90 = 0x90,
    _PD_VDM_CMD_91 = 0x91,
    _PD_VDM_CMD_DISCOVER_ID_BUSY = 0xC1,
    _PD_VDM_CMD_DISCOVER_SVID_BUSY = 0xC2,
    _PD_VDM_CMD_DISCOVER_MODE_BUSY = 0xC3,
    _PD_VDM_CMD_ENTER_MODE_BUSY = 0xC4,
    _PD_VDM_CMD_EXIT_MODE_BUSY = 0xC5,
    _PD_VDM_CMD_D0 = 0xD0,
    _PD_VDM_CMD_D1 = 0xD1,
}EnumVdmCmd;

// Enumeration of Dp VDM Message Command Type
typedef enum
{
    _PD_VDM_DP_CMD_RESERVED = 0x00,
    _PD_VDM_DP_CMD_DISCOVER_MODE_REQ = 0x03,
    _PD_VDM_DP_CMD_ENTER_MODE_REQ = 0x04,
    _PD_VDM_DP_CMD_EXIT_MODE_REQ = 0x05,
    _PD_VDM_DP_CMD_ATTENTION_REQ = 0x06,
    _PD_VDM_DP_CMD_DP_STATUS_REQ = 0x10,
    _PD_VDM_DP_CMD_DP_CONFIG_REQ = 0x11,
    _PD_VDM_DP_CMD_DISCOVER_MODE_ACK = 0x43,
    _PD_VDM_DP_CMD_ENTER_MODE_ACK = 0x44,
    _PD_VDM_DP_CMD_EXIT_MODE_ACK = 0x45,
    _PD_VDM_DP_CMD_DP_STATUS_ACK = 0x50,
    _PD_VDM_DP_CMD_DP_CONFIG_ACK = 0x51,
    _PD_VDM_DP_CMD_DISCOVER_MODE_NAK = 0x83,
    _PD_VDM_DP_CMD_ENTER_MODE_NAK = 0x84,
    _PD_VDM_DP_CMD_EXIT_MODE_NAK = 0x85,
    _PD_VDM_DP_CMD_DP_STATUS_NAK = 0x90,
    _PD_VDM_DP_CMD_DP_CONFIG_NAK = 0x91,
    _PD_VDM_DP_CMD_DISCOVER_MODE_BUSY = 0xC3,
    _PD_VDM_DP_CMD_ENTER_MODE_BUSY = 0xC4,
    _PD_VDM_DP_CMD_EXIT_MODE_BUSY = 0xC5,
    _PD_VDM_DP_CMD_DP_STATUS_BUSY = 0xD0,
    _PD_VDM_DP_CMD_DP_CONFIG_BUSY = 0xD1,
}EnumVdmDpCmd;

// Enumeration of Lenovo VDM Message Command Type
typedef enum
{
    _PD_VDM_LENOVO_CMD_RESERVED = 0x00,
    _PD_VDM_LENOVO_CMD_DISCOVER_MODE_REQ = 0x03,
    _PD_VDM_LENOVO_CMD_ENTER_MODE_REQ = 0x04,
    _PD_VDM_LENOVO_CMD_EXIT_MODE_REQ = 0x05,
    _PD_VDM_LENOVO_CMD_ATTENTION_REQ = 0x06,
    _PD_VDM_LENOVO_CMD_GET_STATUS_REQ = 0x10,
    _PD_VDM_LENOVO_CMD_LENOVO_DEVICE_ID_REQ = 0x11,
    _PD_VDM_LENOVO_CMD_DISCOVER_MODE_ACK = 0x43,
    _PD_VDM_LENOVO_CMD_ENTER_MODE_ACK = 0x44,
    _PD_VDM_LENOVO_CMD_EXIT_MODE_ACK = 0x45,
    _PD_VDM_LENOVO_CMD_GET_STATUS_ACK = 0x50,
    _PD_VDM_LENOVO_CMD_LENOVO_DEVICE_ID_ACK = 0x51,
    _PD_VDM_LENOVO_CMD_DISCOVER_MODE_NAK = 0x83,
    _PD_VDM_LENOVO_CMD_ENTER_MODE_NAK = 0x84,
    _PD_VDM_LENOVO_CMD_EXIT_MODE_NAK = 0x85,
    _PD_VDM_LENOVO_CMD_GET_STATUS_NAK = 0x90,
    _PD_VDM_LENOVO_CMD_LENOVO_DEVICE_ID_NAK = 0x91,
}EnumVdmLenovoCmd;

// Enumeration of Acer VDM Message Command Type
typedef enum
{
    _PD_VDM_ACER_CMD_RESERVED = 0x00,
    _PD_VDM_ACER_CMD_DISCOVER_MODE_REQ = 0x03,
    _PD_VDM_ACER_CMD_ENTER_MODE_REQ = 0x04,
    _PD_VDM_ACER_CMD_EXIT_MODE_REQ = 0x05,
    _PD_VDM_ACER_CMD_ATTENTION_REQ = 0x15,
    _PD_VDM_ACER_CMD_GET_STATUS_REQ = 0x16,
    _PD_VDM_ACER_CMD_DISCOVER_MODE_ACK = 0x43,
    _PD_VDM_ACER_CMD_ENTER_MODE_ACK = 0x44,
    _PD_VDM_ACER_CMD_EXIT_MODE_ACK = 0x45,
    _PD_VDM_ACER_CMD_GET_STATUS_ACK = 0x56,
    _PD_VDM_ACER_CMD_DISCOVER_MODE_NAK = 0x83,
    _PD_VDM_ACER_CMD_ENTER_MODE_NAK = 0x84,
    _PD_VDM_ACER_CMD_EXIT_MODE_NAK = 0x85,
    _PD_VDM_ACER_CMD_GET_STATUS_NAK = 0x96,
}EnumVdmAcerCmd;

// Enumeration of Hp VDM Message Command Type
typedef enum
{
    _PD_VDM_HP_CMD_RESERVED = 0x00,
    _PD_VDM_HP_CMD_DISCOVER_MODE_REQ = 0x03,
    _PD_VDM_HP_CMD_ENTER_MODE_REQ = 0x04,
    _PD_VDM_HP_CMD_EXIT_MODE_REQ = 0x05,
    _PD_VDM_HP_CMD_ATTENTION_REQ = 0x06,
    _PD_VDM_HP_CMD_SET_CONFIG_REQ = 0x10,
    _PD_VDM_HP_CMD_GET_CONFIG_REQ = 0x11,
    _PD_VDM_HP_CMD_SET_VWIRE_REQ = 0x12,
    _PD_VDM_HP_CMD_GET_VWIRE_REQ = 0x13,
    _PD_VDM_HP_CMD_SET_DATA_REQ = 0x14,
    _PD_VDM_HP_CMD_GET_DATA_REQ = 0x15,
    _PD_VDM_HP_CMD_CMD_REQ = 0x16,
    _PD_VDM_HP_CMD_DISCOVER_MODE_ACK = 0x43,
    _PD_VDM_HP_CMD_ENTER_MODE_ACK = 0x44,
    _PD_VDM_HP_CMD_EXIT_MODE_ACK = 0x45,
    _PD_VDM_HP_CMD_SET_CONFIG_ACK = 0x50,
    _PD_VDM_HP_CMD_GET_CONFIG_ACK = 0x51,
    _PD_VDM_HP_CMD_SET_VWIRE_ACK = 0x52,
    _PD_VDM_HP_CMD_GET_VWIRE_ACK = 0x53,
    _PD_VDM_HP_CMD_SET_DATA_ACK = 0x54,
    _PD_VDM_HP_CMD_GET_DATA_ACK = 0x55,
    _PD_VDM_HP_CMD_DISCOVER_MODE_NAK = 0x83,
    _PD_VDM_HP_CMD_ENTER_MODE_NAK = 0x84,
    _PD_VDM_HP_CMD_EXIT_MODE_NAK = 0x85,
}EnumTypeCVdmHpCmd;

// Enumeration of Dell VDM Message Command Type
typedef enum
{
    _PD_VDM_DELL_CMD_RESERVED = 0x00,
    _PD_VDM_DELL_CMD_DISCOVER_MODE_REQ = 0x03,
    _PD_VDM_DELL_CMD_ENTER_MODE_REQ = 0x04,
    _PD_VDM_DELL_CMD_EXIT_MODE_REQ = 0x05,
    _PD_VDM_DELL_CMD_ATTENTION_REQ = 0x06,
    _PD_VDM_DELL_CMD_0X12_REQ = 0x12,
    _PD_VDM_DELL_CMD_0X13_REQ = 0x13,
    _PD_VDM_DELL_CMD_DISCOVER_MODE_ACK = 0x43,
    _PD_VDM_DELL_CMD_ENTER_MODE_ACK = 0x44,
    _PD_VDM_DELL_CMD_EXIT_MODE_ACK = 0x45,
    _PD_VDM_DELL_CMD_0X12_ACK = 0x52,
    _PD_VDM_DELL_CMD_DISCOVER_MODE_NAK = 0x83,
    _PD_VDM_DELL_CMD_ENTER_MODE_NAK = 0x84,
    _PD_VDM_DELL_CMD_EXIT_MODE_NAK = 0x85,
}EnumTypeCVdmDellCmd;

// Enumeration of PD Rx FIFO Receive Error Status
typedef enum
{
    _PD_RX_MSG_CORRECT = 0x00,
    _PD_RX_MSG_NOD_MIS = _BIT0,
    _PD_RX_MSG_SEPC_VER_MIS = _BIT3,
    _PD_RX_MSG_DR_MIS = _BIT4,
    _PD_RX_MSG_CP_MIS = _BIT5,
    _PD_RX_MSG_PR_MIS = _BIT6,
}EnumRxFifoErrStatus;

// Enumeration of Check Rebuild Power Contract
typedef enum
{
    _PD_REBUILD_NOT_REQUIRED = 0x00,
    _PD_REBUILD_REQUIRED = 0x01,
}EnumTypeCPDRebuildPowerContract;

// Enumeration of Check PD Request Check
typedef enum
{
    _PD_REQUEST_INVALID_CURRENT = 0x00,
    _PD_REQUEST_INVALID_COPY_PDO = 0x01,
    _PD_REQUEST_VALID = 0x02,
}EnumTypeCPDRequestValid;

// Enumeration of Check DP Status Result
typedef enum
{
    _PD_CONFIG_NOT_REQUIRED = 0x00,
    _PD_CONFIG_REQUIRED = 0x01,
}EnumDpStatusCheckResult;

// Enumeration of Alt Mode Urgent Status
typedef enum
{
    _PD_ALT_MODE_NOT_URGENT = 0x00,
    _PD_ALT_MODE_URGENT = 0x01,
}EnumTypeCPDAltModeUrgentStatus;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructPDStatus g_stPdRx0Status;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerTypeCRx0PdClkSel(BYTE ucClockSel);
extern void ScalerTypeCRx0PdInitial(void);
extern void ScalerTypeCRx0PdSetPdoByKernel(EnumTypeCPowerRole enumPowerRole);
extern void ScalerTypeCRx0PdReset(void);
extern void ScalerTypeCRx0PdReset_EXINT0(void);
extern void ScalerTypeCRx0PdAttachedSetting(void);
extern void ScalerTypeCRx0PdAttachedSetting_EXINT0(void);
extern void ScalerTypeCRx0PdHandler(void);
extern void ScalerTypeCRx0PdIntHandler_EXINT0(void);
extern BYTE ScalerTypeCRx0PdIntClrCheck_EXINT0(void);
extern void ScalerTypeCRx0PdTimerEventProc(EnumScalerTimerEventID enumEventID);
extern void ScalerTypeCRx0PdWDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID, BYTE *pucActiveWDID, BYTE *pucActiveWDTime);
extern void ScalerTypeCRx0PdPowerSwitch(EnumPowerAction enumPowerAction);
extern void ScalerTypeCRx0PdSetFixPdo(EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex, WORD usVoltage, WORD usMaxCur, EnumPDPeakCurType enumPeakCur);
#if(_TYPE_C_EMB_PD3_PPS_SUPPORT == _ON)
extern void ScalerTypeCRx0PdSetArgumentedPdo(EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex, WORD usMinVol, WORD usMaxVol, BYTE ucMaxCur);
#endif
extern void ScalerTypeCRx0PdSetAdjustablePdo(EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex, WORD usMinVol, WORD usMaxVol, EnumPDPeakCurType enumPeakCur);
extern void ScalerTypeCRx0PdSetInitRdo(StructTypeCUserInitRDO stTypeCUserInitRdo);
extern void ScalerTypeCRx0PdSetRdo(StructTypeCUserRDO stTypeCUserRdo);
#if(_TYPE_C_EMB_VBUS_PROTECT_MODE == _VBUS_PROTECT_BY_USER)
extern void ScalerTypeCRx0PdSetProtectInfo(BYTE ucPdoIndex, StructTypeCUserProtectInfo stTypeCUserProtectInfo);
#endif
extern EnumTypeCUFPProductType ScalerTypeCRx0PdGetUFPProductType(void);
extern EnumTypeCDFPProductType ScalerTypeCRx0PdGetDFPProductType(void);
extern void ScalerTypeCRx0PdSetUnconstrainedPow(EnumTypeCUnconstrainPowerExist enumTypeCUnconstrainPowerExist);
extern bit ScalerTypeCRx0PdGetAltModeReady(void);
extern EnumTypeCPinCfgType ScalerTypeCRx0PdGetPinAssignment(void);
extern EnumTypeCPinCfgType ScalerTypeCRx0PdGetPinAssignment_EXINT0(void);

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern EnumTypeCPinCfgType ScalerTypeCRx0PdGetPinAssignment_WDINT(void);
#endif

extern StructTypeCCableInfoForDpcd ScalerTypeCRx0PdGetCableInfoForDpcd(void);
extern void ScalerTypeCRx0PdSetPinAssignmentCapability(EnumTypeCPinCfgCapType enumPinAssignmentCap);
extern void ScalerTypeCRx0PdSetMultiFunctionBit(EnumTypeCMultiFuncStatus enumMultiFunc);
extern bit ScalerTypeCRx0PdGetMultiFunctionChangeDone(void);
extern void ScalerTypeCRx0PdWaitDpConfig(void);
extern void ScalerTypeCRx0PdPushHpd(EnumPDHpdType enumHpdType, WORD usHpdSpaceTime);
extern void ScalerTypeCRx0PdPushHpd_EXINT0(EnumPDHpdType enumHpdType, WORD usHpdSpaceTime);
extern void ScalerTypeCRx0PdPushHpd_WDINT(EnumPDHpdType enumHpdType, WORD usHpdSpaceTime);

extern void ScalerTypeCRx0PdSendHardRst(void);
extern void ScalerTypeCRx0PdSendHardRst_EXINT0(void);
extern void ScalerTypeCRx0PdSendHardRst_WDINT(BYTE *pucActiveWDID, BYTE *pucActiveWDTime);

extern void ScalerTypeCRx0PdSetMaxPower(WORD usMaxPower);
extern void ScalerTypeCRx0PdSetSnkInfo(StructTypeCSnkInfo stTypeCSnkInfo);
extern void ScalerTypeCRx0PdSetStatusEvent(StructTypeCStatusEvent stTypeCStatusEvent);
extern void ScalerTypeCRx0PdSetAlertEvent(StructTypeCAlertEvent stTypeCAlertEvent);
extern void ScalerTypeCRx0PdSetSPRPdoCnt(EnumTypeCPowerRole enumPowerRole, BYTE ucPdoCnt);
extern BYTE ScalerTypeCRx0PdGetSPRPdoCnt(EnumTypeCPowerRole enumPowerRole);
#if(_TYPE_C_EMB_PD3_1_EPR_SUPPORT == _ON)
extern void ScalerTypeCRx0PdSetEPRPdoCnt(EnumTypeCPowerRole enumPowerRole, BYTE ucPdoCnt);
extern BYTE ScalerTypeCRx0PdGetEPRPdoCnt(EnumTypeCPowerRole enumPowerRole);
#endif
extern StructTypeCUserPDO ScalerTypeCRx0PdGetPdo(EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex);
extern BYTE ScalerTypeCRx0PdGetPartnerPdoCnt(EnumTypeCPowerRole enumPowerRole);
extern StructTypeCUserPDO ScalerTypeCRx0PdGetPartnerPdo(EnumTypeCPowerRole enumPowerRole, BYTE ucPdoIndex);
extern StructTypeCStatusEvent ScalerTypeCRx0PdGetPartnerStatusInfo(void);
extern StructTypeCAlertEvent ScalerTypeCRx0PdGetPartnerAlertInfo(void);
extern void ScalerTypeCRx0PdGetPdoStatus(WORD *pusVoltage, WORD *pusCurrent);
extern StructTypeCUserPDO ScalerTypeCRx0PdGetRequestedSrcPdo(void);
extern void ScalerTypeCRx0PdSetSystemEvent(EnumPDSysEvent enumPdSysEvent);
extern void ScalerTypeCRx0PdSetSystemEvent_EXINT0(EnumPDSysEvent enumPdSysEvent);
#if((_TYPE_C_PMIC_FW_OCP_PROTECT_METHOD == _TYPE_C_PMIC_FW_OCP_BY_SCALER_SARADC) && (_TYPE_C_PMIC_TYPE != _PMIC_NONE))
extern void ScalerTypeCRx0PdSetSystemEvent_WDINT(EnumPDSysEvent enumPdSysEvent);
#endif
extern EnumPDPortCtrlEvent ScalerTypeCRx0PdGetPortCtrlEvent(void);
extern void ScalerTypeCRx0PdClrPortCtrlEvent(EnumPDPortCtrlEvent enumPdPortCtrlEvent);
extern void ScalerTypeCRx0PdSetFunctionSupport(EnumTypeCFunctionSupport enumFunctionSupport);
extern StructTypeCDpStatusInfo ScalerTypeCRx0PdGetDpStatusInfo(void);
#if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
#if(_TYPE_C_EMB_DP_ALT_MODE_SUPPORT == _ON)
extern void ScalerTypeCRx0PdDpCTSForceHpdIrq(void);
extern void ScalerTypeCRx0PdDpCTSForceHpdIrq_EXINT0(void);
extern void ScalerTypeCRx0PdDpCTSForceHpdIrq_WDINT(BYTE *pucActiveWDID, BYTE *pucActiveWDTime);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_LENOVO_ALT_MODE)
extern bit ScalerTypeCRx0PdGetLenovoAltModeReady(void);
extern EnumTypeCLenovoDeviceType ScalerTypeCRx0PdGetLenovoDeviceType(void);
extern StructTypeCLenovoSysEvent ScalerTypeCRx0PdGetLenovoSystemEvent(void);
extern void ScalerTypeCRx0PdSetLenovoDockingEvent(StructTypeCLenovoDockEvent stLenovoDockEvent);
extern bit ScalerTypeCRx0PdCheckLenovoDockingEventBusy(void);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_ACER_ALT_MODE)
extern bit ScalerTypeCRx0PdGetAcerAltModeReady(void);
extern StructTypeCAcerSysEvent ScalerTypeCRx0PdGetAcerSystemEvent(void);
extern void ScalerTypeCRx0PdSetAcerUserEvent(StructTypeCAcerUserEvent stAcerUserEvent);
extern EnumTypeCAcerBusyStatus ScalerTypeCRx0PdCheckAcerUserEventBusy(void);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_HP_ALT_MODE)
extern bit ScalerTypeCRx0PdGetHpAltModeReady(void);
extern StructTypeCHpSysEvent ScalerTypeCRx0PdGetHpSystemEvent(void);
extern void ScalerTypeCRx0PdSetHpUserEvent(StructTypeCHpUserEvent stHpUserEvent);
extern EnumTypeCHpBusyStatus ScalerTypeCRx0PdCheckHpUserEventBusy(void);
#endif
#if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_DELL_ALT_MODE)
extern bit ScalerTypeCRx0PdGetDellAltModeReady(void);
extern StructTypeCDellSysEvent ScalerTypeCRx0PdGetDellSystemEvent(void);
extern void ScalerTypeCRx0PdSetDellUserEvent(StructTypeCDellUserEvent stDellUserEvent);
extern void ScalerTypeCRx0PdSetDellAltModeInitComplete(EnumTypeCDellInitCompleteStatus enumDellInitCompleteStatus);
extern EnumTypeCDellBusyStatus ScalerTypeCRx0PdCheckDellUserEventBusy(void);
extern EnumTypeCEnterDellAltModeTimeOut ScalerTypeCRx0PdGetEnterDellAltModeTimeOut(void);
#endif  // End of #if(_TYPE_C_VENDOR_ALT_MODE == _TYPE_C_DELL_ALT_MODE)
#if(_BILLBOARD_SCALER_SUPPORT == _ON)
extern void ScalerTypeCRx0PdGetAltModeBillboardInfo(BYTE *pucBillboardAltModeInfo);
#endif  // End of #if(_BILLBOARD_SCALER_SUPPORT == _ON)
#endif  // End of #if(_TYPE_C_PORT_CTRL_MODAL_OPERATION_SUPPORT == _ON)
extern bit ScalerTypeCRx0PdGetDataRole(void);
extern bit ScalerTypeCRx0PdGetPowerRole(void);
extern BYTE ScalerTypeCRx0PdGetPowerRole_EXINT0(void);
extern void ScalerTypeCRx0PdSetPowerRole(bit bRole);
extern void ScalerTypeCRx0PdSetPowerRole_EXINT0(bit bRole);
extern bit ScalerTypeCRx0PdGetExplicitContract(void);
extern bit ScalerTypeCRx0PdGetPowerRoleSwapProcessing(void);
extern BYTE ScalerTypeCRx0PdGetPowerRoleSwapProcessing_EXINT0(void);
extern void ScalerTypeCRx0PdClrInteropS8Flag(void);
extern void ScalerTypeCRx0PdClrInteropS8Flag_EXINT0(void);
extern EnumPDHpdType ScalerTypeCRx0PdGetHPDQueue(BYTE ucIndex);
extern BYTE ScalerTypeCRx0PdGetHPDQueReadPointer(void);
extern bit ScalerTypeCRx0PdGetSRCCapSentStatus(void);
extern bit ScalerTypeCRx0PdGetHPDStatus(void);
#endif  // End of #if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)

