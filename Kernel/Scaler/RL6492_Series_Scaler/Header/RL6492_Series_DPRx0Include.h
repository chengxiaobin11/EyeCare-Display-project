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
// ID Code      : RL6492_Series_DPRx0Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D0_DP_EXIST == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//----------------------------------------------------------------------------
// Macro of Dp Link Training Information
//----------------------------------------------------------------------------
#define GET_DP_RX0_FAKE_LINK_TRAINING()                         (g_bDpRx0FakeLT)
#define SET_DP_RX0_FAKE_LINK_TRAINING()                         (g_bDpRx0FakeLT = _TRUE)
#define CLR_DP_RX0_FAKE_LINK_TRAINING()                         (g_bDpRx0FakeLT = _FALSE)

#define GET_DP_RX0_VALID_VIDEO_CHECK()                          (g_bDpRx0ValidVideoCheck)
#define SET_DP_RX0_VALID_VIDEO_CHECK()                          (g_bDpRx0ValidVideoCheck = _TRUE)
#define CLR_DP_RX0_VALID_VIDEO_CHECK()                          {\
                                                                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_VALID_SIGNAL_DETECT_CHECK);\
                                                                    (g_bDpRx0ValidVideoCheck = _FALSE);\
                                                                }

#define GET_DP_RX0_CRC_CALCULATE()                              (g_bDpRx0CrcCalculate)
#define SET_DP_RX0_CRC_CALCULATE()                              (g_bDpRx0CrcCalculate = _TRUE)
#define CLR_DP_RX0_CRC_CALCULATE()                              (g_bDpRx0CrcCalculate = _FALSE)

#define CLR_DP_RX0_CRC_VALUE_EXINT0()                           {\
                                                                    ScalerDpRx0SetDpcdValue_EXINT0(0x00, 0x02, 0x40, 0x00);\
                                                                    ScalerDpRx0SetDpcdValue_EXINT0(0x00, 0x02, 0x41, 0x00);\
                                                                    ScalerDpRx0SetDpcdValue_EXINT0(0x00, 0x02, 0x42, 0x00);\
                                                                    ScalerDpRx0SetDpcdValue_EXINT0(0x00, 0x02, 0x43, 0x00);\
                                                                    ScalerDpRx0SetDpcdValue_EXINT0(0x00, 0x02, 0x44, 0x00);\
                                                                    ScalerDpRx0SetDpcdValue_EXINT0(0x00, 0x02, 0x45, 0x00);\
                                                                }

#define GET_DP_RX0_PS_AUX_TOGGLE()                              (g_bDpRx0PSAuxToggle)
#define SET_DP_RX0_PS_AUX_TOGGLE()                              (g_bDpRx0PSAuxToggle = _TRUE)
#define CLR_DP_RX0_PS_AUX_TOGGLE()                              (g_bDpRx0PSAuxToggle = _FALSE)

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
#define GET_DP_RX0_URGENT_LINK_LOSS()                           (g_bDpRx0UrgentLinkLossFlag)
#define SET_DP_RX0_URGENT_LINK_LOSS()                           (g_bDpRx0UrgentLinkLossFlag = _TRUE)
#define CLR_DP_RX0_URGENT_LINK_LOSS()                           (g_bDpRx0UrgentLinkLossFlag = _FALSE)
#endif

#define GET_DP_RX0_AUX_COMMAND_NO_REPLY()                       (g_bDpRx0AuxCommandNoReply)
#define SET_DP_RX0_AUX_COMMAND_NO_REPLY()                       (g_bDpRx0AuxCommandNoReply = _TRUE)
#define CLR_DP_RX0_AUX_COMMAND_NO_REPLY()                       (g_bDpRx0AuxCommandNoReply = _FALSE)

#define GET_DP_RX0_PHY_CTS_FLG()                                (((bit)ScalerGetBit(P1D_50_CDR_01, _BIT0)) && (ScalerGetBit(P1D_50_CDR_01, (_BIT2 | _BIT1)) == 0x00))
#define SET_DP_RX0_PHY_CTS_FLG()                                (ScalerSetBit(P1D_50_CDR_01, ~_BIT0, _BIT0))
#define CLR_DP_RX0_PHY_CTS_FLG()                                (ScalerSetBit(P1D_50_CDR_01, ~_BIT0, 0x00))

#define SET_DP_RX0_AUX_MANUAL_MODE_EXINT()                      {\
                                                                    BYTE ucLoopIndexInAuxMacro = 0;\
                                                                    if(ScalerGetBit_EXINT(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1)\
                                                                    {\
                                                                        do\
                                                                        {\
                                                                            DELAY_5US_EXINT();\
                                                                            ucLoopIndexInAuxMacro++;\
                                                                            if(ucLoopIndexInAuxMacro > 45)\
                                                                            {\
                                                                                break;\
                                                                            }\
                                                                        }while(ScalerGetBit_EXINT(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1);\
                                                                        DELAY_5US_EXINT();\
                                                                    }\
                                                                    ScalerSetBit_EXINT(PB7_D0_AUX_MODE_SET, ~_BIT1, 0x00);\
                                                                }
#define SET_DP_RX0_AUX_MANUAL_MODE()                            {\
                                                                    BYTE ucLoopIndexInAuxMacro = 0;\
                                                                    EX0 = 0;\
                                                                    if(ScalerGetBit(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1)\
                                                                    {\
                                                                        do\
                                                                        {\
                                                                            DELAY_5US();\
                                                                            ucLoopIndexInAuxMacro++;\
                                                                            if(ucLoopIndexInAuxMacro > 45)\
                                                                            {\
                                                                                break;\
                                                                            }\
                                                                        }while(ScalerGetBit(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1);\
                                                                        DELAY_5US();\
                                                                    }\
                                                                    ScalerSetBit(PB7_D0_AUX_MODE_SET, ~_BIT1, 0x00);\
                                                                    EX0 = 1;\
                                                                }
#define SET_DP_RX0_AUX_MANUAL_MODE_PHY_CTS()                    {\
                                                                    BYTE ucLoopIndexInAuxMacro = 0;\
                                                                    if(ScalerGetBit(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1)\
                                                                    {\
                                                                        do\
                                                                        {\
                                                                            DELAY_5US();\
                                                                            ucLoopIndexInAuxMacro++;\
                                                                            if(ucLoopIndexInAuxMacro > 45)\
                                                                            {\
                                                                                break;\
                                                                            }\
                                                                        }while(ScalerGetBit(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1);\
                                                                        DELAY_5US();\
                                                                    }\
                                                                    ScalerSetBit(PB7_D0_AUX_MODE_SET, ~_BIT1, 0x00);\
                                                                }
#define SET_DP_RX0_AUX_AUTO_MODE_EXINT()                        {\
                                                                    BYTE ucLoopIndexInAuxMacro = 0;\
                                                                    if(ScalerGetBit_EXINT(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1)\
                                                                    {\
                                                                        do\
                                                                        {\
                                                                            DELAY_5US_EXINT();\
                                                                            ucLoopIndexInAuxMacro++;\
                                                                            if(ucLoopIndexInAuxMacro > 45)\
                                                                            {\
                                                                                break;\
                                                                            }\
                                                                        }while(ScalerGetBit_EXINT(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1);\
                                                                        DELAY_5US_EXINT();\
                                                                    }\
                                                                    ScalerSetBit_EXINT(PB7_D0_AUX_MODE_SET, ~_BIT1, _BIT1);\
                                                                }
#define SET_DP_RX0_AUX_AUTO_MODE()                              {\
                                                                    BYTE ucLoopIndexInAuxMacro = 0;\
                                                                    EX0 = 0;\
                                                                    if(ScalerGetBit(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1)\
                                                                    {\
                                                                        do\
                                                                        {\
                                                                            DELAY_5US();\
                                                                            ucLoopIndexInAuxMacro++;\
                                                                            if(ucLoopIndexInAuxMacro > 45)\
                                                                            {\
                                                                                break;\
                                                                            }\
                                                                        }while(ScalerGetBit(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1);\
                                                                        DELAY_5US();\
                                                                    }\
                                                                    ScalerSetBit(PB7_D0_AUX_MODE_SET, ~_BIT1, _BIT1);\
                                                                    EX0 = 1;\
                                                                }
#define SET_DP_RX0_AUX_AUTO_MODE_PHY_CTS()                      {\
                                                                    BYTE ucLoopIndexInAuxMacro = 0;\
                                                                    if(ScalerGetBit(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1)\
                                                                    {\
                                                                        do\
                                                                        {\
                                                                            DELAY_5US();\
                                                                            ucLoopIndexInAuxMacro++;\
                                                                            if(ucLoopIndexInAuxMacro > 45)\
                                                                            {\
                                                                                break;\
                                                                            }\
                                                                        }while(ScalerGetBit(PB7_C7_TP1_OCCR, (_BIT2 | _BIT1 | _BIT0)) > _BIT1);\
                                                                        DELAY_5US();\
                                                                    }\
                                                                    ScalerSetBit(PB7_D0_AUX_MODE_SET, ~_BIT1, _BIT1);\
                                                                }

#define GET_DP_RX0_VFRONT_PORCH()                               (g_usDpRx0Vfrontporch)
#define SET_DP_RX0_VFRONT_PORCH(x)                              (g_usDpRx0Vfrontporch = (x))

#define SET_DP_RX0_PORCH_COLOR_RGB()                            {\
                                                                    ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x00);\
                                                                    ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                    ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x00);\
                                                                    ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                    ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x00);\
                                                                    ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                                }

#define SET_DP_RX0_PORCH_COLOR_YCC_LIMIT()                      {\
                                                                    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)\
                                                                    {\
                                                                        ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x01);\
                                                                        ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                        ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x01);\
                                                                        ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                        ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x08);\
                                                                        ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                                    }\
                                                                    else\
                                                                    {\
                                                                        ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x08);\
                                                                        ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                        ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x01);\
                                                                        ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                        ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x08);\
                                                                        ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                                    }\
                                                                }

#define SET_DP_RX0_PORCH_COLOR_YCC_FULL()                       {\
                                                                    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)\
                                                                    {\
                                                                        ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x01);\
                                                                        ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                        ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x01);\
                                                                        ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                        ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x08);\
                                                                        ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                                    }\
                                                                    else\
                                                                    {\
                                                                        ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x08);\
                                                                        ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                        ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x00);\
                                                                        ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                        ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x08);\
                                                                        ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                                    }\
                                                                }
#if(_DP_RX_INTERLACE_NEW_MODE_SUPPORT == _ON)
#define SET_DP_RX0_INTERLACE_VTT_FW_MODE(x)                     {\
                                                                    (((x) == _EVEN) ? (ScalerSetBit(PB5_F1_DP_RSV1, ~_BIT4, _BIT4)) : (ScalerSetBit(PB5_F1_DP_RSV1, ~_BIT4, 0x00)));\
                                                                }
#endif

#define _DP_RAWDATA_COUNT_D10P2_UPPER_BOUND_1000_RBR_EXINT0     (g_usDpRx0D10p2CountCriteriaUpperBoundRBR)
#define _DP_RAWDATA_COUNT_D10P2_UPPER_BOUND_1000_HBR_EXINT0     (g_usDpRx0D10p2CountCriteriaUpperBoundHBR)
#define _DP_RAWDATA_COUNT_D10P2_UPPER_BOUND_1000_HBR2_EXINT0    (g_usDpRx0D10p2CountCriteriaUpperBoundHBR2)

#define _DP_RAWDATA_COUNT_D10P2_LOWER_BOUND_1000_RBR_EXINT0     (g_usDpRx0D10p2CountCriteriaLowerBoundRBR)
#define _DP_RAWDATA_COUNT_D10P2_LOWER_BOUND_1000_HBR_EXINT0     (g_usDpRx0D10p2CountCriteriaLowerBoundHBR)
#define _DP_RAWDATA_COUNT_D10P2_LOWER_BOUND_1000_HBR2_EXINT0    (g_usDpRx0D10p2CountCriteriaLowerBoundHBR2)

#if(_DP_ILLEGAL_IDLE_PATTERN_CHECK_SUPPORT == _ON)
//----------------------------------------------------------------------------
// Macro of Dp Lane Valid Check
//----------------------------------------------------------------------------
#define GET_DP_RX0_SOURCE_TYPE_JUDGE()                          (g_bDpRx0SourceTypeJudge)
#define SET_DP_RX0_SOURCE_TYPE_JUDGE()                          (g_bDpRx0SourceTypeJudge = _TRUE)
#define CLR_DP_RX0_SOURCE_TYPE_JUDGE()                          (g_bDpRx0SourceTypeJudge = _FALSE)
#endif

//--------------------------------------------------
// Macro of DP Lane Mapping
//--------------------------------------------------
#define GET_DP_RX0_PCB_LANE0_MAPPING()                          (g_stDpRx0LanesMapping.b2Lane0Mapping)
#define SET_DP_RX0_PCB_LANE0_MAPPING(x)                         (g_stDpRx0LanesMapping.b2Lane0Mapping = (x))

#define GET_DP_RX0_PCB_LANE1_MAPPING()                          (g_stDpRx0LanesMapping.b2Lane1Mapping)
#define SET_DP_RX0_PCB_LANE1_MAPPING(x)                         (g_stDpRx0LanesMapping.b2Lane1Mapping = (x))

#define GET_DP_RX0_PCB_LANE2_MAPPING()                          (g_stDpRx0LanesMapping.b2Lane2Mapping)
#define SET_DP_RX0_PCB_LANE2_MAPPING(x)                         (g_stDpRx0LanesMapping.b2Lane2Mapping = (x))

#define GET_DP_RX0_PCB_LANE3_MAPPING()                          (g_stDpRx0LanesMapping.b2Lane3Mapping)
#define SET_DP_RX0_PCB_LANE3_MAPPING(x)                         (g_stDpRx0LanesMapping.b2Lane3Mapping = (x))

#define GET_DP_RX0_PCB_LANE0_PN_SWAP()                          (g_stDpRx0LanesMapping.b1Lane0PNSwap)
#define SET_DP_RX0_PCB_LANE0_PN_SWAP(x)                         (g_stDpRx0LanesMapping.b1Lane0PNSwap = (x))

#define GET_DP_RX0_PCB_LANE1_PN_SWAP()                          (g_stDpRx0LanesMapping.b1Lane1PNSwap)
#define SET_DP_RX0_PCB_LANE1_PN_SWAP(x)                         (g_stDpRx0LanesMapping.b1Lane1PNSwap = (x))

#define GET_DP_RX0_PCB_LANE2_PN_SWAP()                          (g_stDpRx0LanesMapping.b1Lane2PNSwap)
#define SET_DP_RX0_PCB_LANE2_PN_SWAP(x)                         (g_stDpRx0LanesMapping.b1Lane2PNSwap = (x))

#define GET_DP_RX0_PCB_LANE3_PN_SWAP()                          (g_stDpRx0LanesMapping.b1Lane3PNSwap)
#define SET_DP_RX0_PCB_LANE3_PN_SWAP(x)                         (g_stDpRx0LanesMapping.b1Lane3PNSwap = (x))

//----------------------------------------------------------------------------
// Macro of HDCP Information
//----------------------------------------------------------------------------
#define GET_DP_RX0_HDCP_MODE_BACKUP()                           (g_enumDpRx0HdcpMode)
#define SET_DP_RX0_HDCP_MODE_BACKUP(x)                          (g_enumDpRx0HdcpMode = (x))

#define GET_DP_RX0_HDCP_CPIRQ()                                 (g_bDpHdcpRx0HdcpCpirqFlag)
#define SET_DP_RX0_HDCP_CPIRQ()                                 (g_bDpHdcpRx0HdcpCpirqFlag = _TRUE)
#define CLR_DP_RX0_HDCP_CPIRQ()                                 (g_bDpHdcpRx0HdcpCpirqFlag = _FALSE)

#define GET_DP_RX0_HDCP_MODE()                                  ((ScalerGetBit(PB_1A_HDCP_IRQ, _BIT1) == _BIT1) ? _HDCP_22 : _HDCP_14)

// HDCP mode register at power off region, set register and backup variable must at the same time.
#define SET_DP_RX0_HDCP_MODE(x)                                 {\
                                                                    if((x) == _HDCP_22)\
                                                                    {\
                                                                        ScalerSetBit(PB_1A_HDCP_IRQ, ~_BIT1, _BIT1);\
                                                                        SET_DP_RX0_HDCP_MODE_BACKUP(_HDCP_22);\
                                                                    }\
                                                                    else\
                                                                    {\
                                                                        ScalerSetBit(PB_1A_HDCP_IRQ, ~_BIT1, 0x00);\
                                                                        SET_DP_RX0_HDCP_MODE_BACKUP(_HDCP_14);\
                                                                    }\
                                                                }

#define GET_DP_RX0_HDCP_MODE_EXINT()                            ((ScalerGetBit_EXINT(PB_1A_HDCP_IRQ, _BIT1) == _BIT1) ? _HDCP_22 : _HDCP_14)

// HDCP mode register at power off region, set register and backup variable must at the same time.
#define SET_DP_RX0_HDCP_MODE_EXINT(x)                           {\
                                                                    if((x) == _HDCP_22)\
                                                                    {\
                                                                        ScalerSetBit_EXINT(PB_1A_HDCP_IRQ, ~_BIT1, _BIT1);\
                                                                        SET_DP_RX0_HDCP_MODE_BACKUP(_HDCP_22);\
                                                                    }\
                                                                    else\
                                                                    {\
                                                                        ScalerSetBit_EXINT(PB_1A_HDCP_IRQ, ~_BIT1, 0x00);\
                                                                        SET_DP_RX0_HDCP_MODE_BACKUP(_HDCP_14);\
                                                                    }\
                                                                }

//--------------------------------------------------
// Definitions of DP Lane Setting Ralation to Actual Lane Mapping
//--------------------------------------------------
#define _D0_DP_LANE0                                            (GET_DP_RX0_PCB_LANE0_MAPPING())
#define _D0_DP_LANE1                                            (GET_DP_RX0_PCB_LANE1_MAPPING())
#define _D0_DP_LANE2                                            (GET_DP_RX0_PCB_LANE2_MAPPING())
#define _D0_DP_LANE3                                            (GET_DP_RX0_PCB_LANE3_MAPPING())

//--------------------------------------------------
// Macro of DP AUX PN Swap for Type-C reverse plug
//--------------------------------------------------
#define GET_DP_RX0_AUX_PN_SWAP()                                ((ScalerGetBit(PB7_66_AUX_6, _BIT7) == _BIT7) ? _TRUE : _FALSE)
#define SET_DP_RX0_AUX_PN_SWAP()                                (ScalerSetBit(PB7_66_AUX_6, ~_BIT7, _BIT7))
#define CLR_DP_RX0_AUX_PN_SWAP()                                (ScalerSetBit(PB7_66_AUX_6, ~_BIT7, 0x00))


//--------------------------------------------------
// Macro of Dp Measure Pop Up Action
//--------------------------------------------------
// Delay 5us for Wait Hw Update Period to Prevent MCU Get wrong value, Update Period is 3T, T = 1/14.318M or 1/27M
#define SET_DP_RX0_MEASURE_POP_UP()                             {\
                                                                    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);\
                                                                    DELAY_5US();\
                                                                }

//--------------------------------------------------
// Macro of Dp Rx Mac Assigned
//--------------------------------------------------
#define GET_REG_DP_RX0_MAC_ASSIGNED()                           ((ScalerGetBit(PB_00_HD_DP_SEL, (_BIT1 | _BIT0)) == 0x00) ? _TRUE : _FALSE)
#define GET_REG_DP_RX0_MAC_ASSIGNED_EXINT()                     ((ScalerGetBit_EXINT(PB_00_HD_DP_SEL, (_BIT1 | _BIT0)) == 0x00) ? _TRUE : _FALSE)

#if((_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED))
//--------------------------------------------------
// Macro of AUX Reset Flag
//--------------------------------------------------
#define GET_DP_RX0_HPD_LOW_AUX_RESET_FLAG()                     (g_bDpRx0HpdLowAuxResetFlag)
#define SET_DP_RX0_HPD_LOW_AUX_RESET_FLAG()                     (g_bDpRx0HpdLowAuxResetFlag = _TRUE)
#define CLR_DP_RX0_HPD_LOW_AUX_RESET_FLAG()                     (g_bDpRx0HpdLowAuxResetFlag = _FALSE)
#endif

#define GET_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE()             (g_stDpRx0MiscInfo.b1DpCheckAuxChNoPowerDebounce)
#define SET_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE()             (g_stDpRx0MiscInfo.b1DpCheckAuxChNoPowerDebounce = _TRUE)
#define CLR_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE()             (g_stDpRx0MiscInfo.b1DpCheckAuxChNoPowerDebounce = _FALSE)

#define GET_DP_RX0_CHECK_AUX_CH_POWER_STATUS()                  (g_stDpRx0MiscInfo.b2DpCheckAuxChPowerStatus)
#define SET_DP_RX0_CHECK_AUX_CH_POWER_STATUS(x)                 (g_stDpRx0MiscInfo.b2DpCheckAuxChPowerStatus = (x))
#define CLR_DP_RX0_CHECK_AUX_CH_POWER_STATUS()                  (g_stDpRx0MiscInfo.b2DpCheckAuxChPowerStatus = _DP_RX_AUX_POWER_STATUS_NONE)

#define GET_DP_RX0_AUX_CH_POWER_ON_WAKE_UP()                    (g_stDpRx0MiscInfo.b1DpAuxChPowerOnWakeUp)
#define SET_DP_RX0_AUX_CH_POWER_ON_WAKE_UP()                    (g_stDpRx0MiscInfo.b1DpAuxChPowerOnWakeUp = _TRUE)
#define CLR_DP_RX0_AUX_CH_POWER_ON_WAKE_UP()                    (g_stDpRx0MiscInfo.b1DpAuxChPowerOnWakeUp = _FALSE)

#define GET_DP_RX0_SOURCE_FIRST_POWER_ON()                      (g_stDpRx0MiscInfo.b1DpSourceFirstPowerOn)
#define SET_DP_RX0_SOURCE_FIRST_POWER_ON()                      (g_stDpRx0MiscInfo.b1DpSourceFirstPowerOn = _TRUE)
#define CLR_DP_RX0_SOURCE_FIRST_POWER_ON()                      (g_stDpRx0MiscInfo.b1DpSourceFirstPowerOn = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern bit g_bDpRx0PSAuxToggle;

extern bit g_bDpRx0AuxCommandNoReply;

extern bit g_bDpRx0FakeLT;
extern bit g_bDpRx0ValidVideoCheck;
extern bit g_bDpRx0CrcCalculate;

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
extern bit g_bDpRx0UrgentLinkLossFlag;
#endif

extern BYTE g_ucDpRx0LinkStatus01;
extern BYTE g_ucDpRx0LinkStatus23;
extern BYTE g_ucDpRx0LinkRequest01;
extern BYTE g_ucDpRx0LinkRequest23;
extern BYTE g_ucDpRx0Temp;
extern BYTE g_pucDpRx0Backup[3];
extern bit g_bDpRx0AutoInc;
extern BYTE g_ucDpRx0LinkRate;
extern BYTE g_ucDpRx0LaneCount;
extern BYTE g_ucDpRx0TrainingPatternSet;

extern BYTE g_ucDpRx0EQCRC;
extern WORD g_pusDpRx0ClockCount[4];
extern WORD g_pusDpRx0ClockCount1[4];

extern WORD g_usDpRx0D10p2CountCriteriaUpperBoundRBR;
extern WORD g_usDpRx0D10p2CountCriteriaUpperBoundHBR;
extern WORD g_usDpRx0D10p2CountCriteriaUpperBoundHBR2;

extern WORD g_usDpRx0D10p2CountCriteriaLowerBoundRBR;
extern WORD g_usDpRx0D10p2CountCriteriaLowerBoundHBR;
extern WORD g_usDpRx0D10p2CountCriteriaLowerBoundHBR2;

#if(_DP_ILLEGAL_IDLE_PATTERN_CHECK_SUPPORT == _ON)
extern bit g_bDpRx0SourceTypeJudge;
#endif

extern BYTE g_ucRx0AuxTemp;
extern BYTE g_ucRx0AuxTemp_EXINT;
extern WORD g_usDpRx0Vfrontporch;

#if(_DP_RX_MI_DONGLE_SUPPORT == _ON)
extern BYTE g_ucDpRx0FakeLTLaneCount;
extern BYTE g_ucDpRx0FakeLTLaneCountBackUp;
#endif

extern BYTE g_ucDpRx0PhyCtsCtrl;
extern EnumHDCPType g_enumDpRx0HdcpMode;
extern bit g_bDpHdcpRx0HdcpCpirqFlag;
extern StructDpLanesMapping g_stDpRx0LanesMapping;
extern StructDPRxMiscInfo g_stDpRx0MiscInfo;

#if(_DP_HDCP_2_2_SUPPORT == _ON)
extern BYTE g_pucDPRx0Caps[3];
#endif

#if((_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED))
extern bit g_bDpRx0HpdLowAuxResetFlag;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDpRx0AuxPowerOnInitial(void);
extern void ScalerDpRx0AuxIntInitial(void);
extern void ScalerDpRx0DpcdInitial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort, EnumFreeSyncSupport enumFreeSyncSupport);
extern void ScalerDpRx0ChangeDpcdVersion(EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);
extern EnumDpHotPlugTime ScalerDpRx0BeforeHpdToggleProc(EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpRx0DisconnectReset(void);
extern void ScalerDpRx0AfterHpdToggleProc(void);
extern void ScalerDpRx0HpdIrqAssert(void);
#if(_DP_HDCP_2_2_SUPPORT == _ON)
extern void ScalerDpRx0CpIRQ_EXINT0(EnumDpRxBStatusType enumBStatusType);
#if(_WD_TIMER_INT_SUPPORT == _ON)
extern void ScalerDpRx0CpIRQ_WDINT(EnumDpRxBStatusType enumBStatusType);
#endif
#endif
extern void ScalerDpRx0MacInitial(void);
extern void ScalerDpRx0PhyInitial(void);
extern void ScalerDpRx0RebuildPhy(BYTE ucDpLinkRate, BYTE ucDpcdLane);
extern bit ScalerDpRx0AlignCheck(void);
extern bit ScalerDpRx0DecodeCheck(void);
extern bit ScalerDpRx0DFECheck(void);
extern void ScalerDpRx0SignalDetectInitial(BYTE ucDpLinkRate, BYTE ucDpLEQScanValue);
extern WORD ScalerDpRx0GetVtotalbyMeasure(WORD usHBs2BsCount, DWORD ulVBs2BsCount);
extern bit ScalerDpRx0DeOnlyTimngCheck(DWORD ulVBs2BsCount);
extern bit ScalerDpRx0DeOnlyJudge(WORD *pusDpVtotal, WORD usHBs2BsCount, DWORD ulVBs2BsCount);
extern bit ScalerDpRx0DisplayFormatSetting(void);
extern bit ScalerDpRx0StreamClkRegenerate(void);
extern bit ScalerDpRx0FifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition);
extern void ScalerDpRx0HDCPBlockReset(void);
extern bit ScalerDpRx0HdcpCheck(void);
extern bit ScalerDpRx0HdcpReAuthStatusCheck(void);
extern void ScalerDpRx0CpIRQ(EnumDpRxBStatusType enumBStatusType);
extern bit ScalerDpRx0HdcpCheckValid(void);
extern bit ScalerDpRx0HdcpCheckEnabled(void);
extern void ScalerDpRx0PhyCTS(void);
extern void ScalerDpRx0SetFifoWD(bit bEn);
extern void ScalerDpRx0SetFifoIRQ(bit bEn);
extern bit ScalerDpRx0NormalPreDetect(void);
extern bit ScalerDpRx0ChangeSrambleSeed(void);
#if(_DP_RX0_ASSR_MODE_SUPPORT == _ON)
extern bit ScalerDpRx0VbiosAssrCheck(bit bMSACheckResult);
#endif
extern BYTE ScalerDpRx0ScanInputPort(void);
extern bit ScalerDpRx0StableDetect(void);
extern void ScalerDpRx0SetHotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpRx0AdjustVsyncDelay(void);

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
extern bit ScalerDpRx0LinkStatusLoss(void);
#endif

extern bit ScalerDpRx0TimerDelayXmsLinkCheck(WORD usNum);
extern bit ScalerDpRx0PollingFlagLinkCheck(WORD usTimeout, WORD usRegister, BYTE ucBit, bit bSuccess);

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
extern bit ScalerDpRx0CheckVgipVsBypass(void);
#endif

extern void ScalerDpRx0SetNoVideoStreamIRQ(bit bEn);
extern void ScalerDpRx0DpcdLinkStatusReset(EnumDpResetStatus enumDpResetStatus);
extern DWORD ScalerDpRx0GetBStoVSDelay(void);
extern void ScalerDpRx0Initial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort, EnumFreeSyncSupport enumFreeSyncSupport, EnumAudioDpDpcdSupport enumAudioSupport);
extern bit ScalerDpRx0MarginLinkCheck(void);
extern void ScalerDpRx0LinkStatusIRQ(void);
extern void ScalerDpRx0ActiveLinkStatusIRQ(void);
extern void ScalerDpRx0AuxSet(void);
extern bit ScalerDpRx0PSPreDetect(void);

#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED)
extern void ScalerDpRx0SetDpAltModeLaneMapping(EnumTypeCPinCfgType enumPinAssignment, EnumTypeCOrientation enumOrientation);
#else
extern void ScalerDpRx0SetDpLaneMapping(EnumTypeCPinCfgType enumPinAssignment, EnumTypeCOrientation enumOrientation);
#endif

#if(_DP_HDCP_ARBITER_SUPPORT == _ON)
extern bit ScalerDpRx0CheckHdcpCapability(void);
extern void ScalerDpRx0HdcpHandshakeMonitorEnable(void);
extern void ScalerDpRx0HdcpHandshakeMonitorDisable(void);
extern void ScalerDpRx0HdcpHandshakeMonitorDisable_EXINT0(void);
#endif
extern StructDpRxErrorCount ScalerDpRx0GetErrorCount(void);

#if((_D0_DP_TYPE_C_PORT_CTRL_SUPPORT == _ON) && (_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTROLLER_EMBEDDED))
extern void ScalerDpRx0HpdToggleAuxPhyResetProc(bit bHpdHighLow);
#endif
extern bit ScalerDpRx0AuxChSourcePowerCheck(void);
extern void ScalerDpRx0AuxChPowerStatusCheck(bit bCableStatus);

#endif // End of #if(_D0_DP_EXIST == _ON)
