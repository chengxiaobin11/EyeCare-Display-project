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
// ID Code      : RL6369_Series_DPRx0Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//----------------------------------------------------------------------------
// Macro of Dp Link Training Information
//----------------------------------------------------------------------------
#define GET_DP_RX0_PHY_CTS_FLG()                        ((bit)ScalerGetBit(PB_B8_IMPEDANCE_01, _BIT7))
#define SET_DP_RX0_PHY_CTS_FLG()                        (ScalerSetBit(PB_B8_IMPEDANCE_01, ~_BIT7, _BIT7))
#define CLR_DP_RX0_PHY_CTS_FLG()                        (ScalerSetBit(PB_B8_IMPEDANCE_01, ~_BIT7, 0x00))

#define SET_DP_RX0_AUX_MANUAL_MODE_EXINT()              {\
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
#define SET_DP_RX0_AUX_MANUAL_MODE()                    {\
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
#define SET_DP_RX0_AUX_MANUAL_MODE_PHY_CTS()            {\
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
#define SET_DP_RX0_AUX_AUTO_MODE_EXINT()                {\
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
#define SET_DP_RX0_AUX_AUTO_MODE()                      {\
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
#define SET_DP_RX0_AUX_AUTO_MODE_PHY_CTS()              {\
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

#define GET_DP_RX0_VFRONT_PORCH()                       (g_usDpRx0Vfrontporch)
#define SET_DP_RX0_VFRONT_PORCH(x)                      (g_usDpRx0Vfrontporch = (x))

#define SET_DP_RX0_PORCH_COLOR_RGB()                    {\
                                                            ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x00);\
                                                            ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                            ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x00);\
                                                            ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                            ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x00);\
                                                            ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                        }

#define SET_DP_RX0_PORCH_COLOR_YCC_LIMIT()              {\
                                                            if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)\
                                                            {\
                                                                ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x10);\
                                                                ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x10);\
                                                                ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x80);\
                                                                ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                            }\
                                                            else\
                                                            {\
                                                                ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x80);\
                                                                ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x10);\
                                                                ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x80);\
                                                                ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                            }\
                                                        }

#define SET_DP_RX0_PORCH_COLOR_YCC_FULL()               {\
                                                            if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)\
                                                            {\
                                                                ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x10);\
                                                                ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x10);\
                                                                ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x80);\
                                                                ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                            }\
                                                            else\
                                                            {\
                                                                ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x80);\
                                                                ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x00);\
                                                                ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x80);\
                                                                ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                            }\
                                                        }

#if(_DP_RX_INTERLACE_NEW_MODE_SUPPORT == _ON)
#define SET_DP_RX0_INTERLACE_VTT_FW_MODE(x)             {\
                                                        }
#endif

#define GET_DP_RX0_HDCP_CPIRQ()                         (g_bDpHdcpRx0HdcpCpirqFlag)
#define SET_DP_RX0_HDCP_CPIRQ()                         (g_bDpHdcpRx0HdcpCpirqFlag = _TRUE)
#define CLR_DP_RX0_HDCP_CPIRQ()                         (g_bDpHdcpRx0HdcpCpirqFlag = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern bit g_bDpRx0PSAuxToggle;

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
extern BYTE g_ucRx0AuxTemp;
extern BYTE g_ucRx0AuxTemp_EXINT;
extern WORD g_usDpRx0Vfrontporch;

#if(_DP_RX_MI_DONGLE_SUPPORT == _ON)
extern BYTE g_ucDpRx0FakeLTLaneCount;
extern BYTE g_ucDpRx0FakeLTLaneCountBackUp;
#endif

extern bit g_bDpHdcpRx0HdcpCpirqFlag;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDpRx0AuxPowerOnInitial(void);
extern void ScalerDpRx0AuxIntInitial(void);
extern void ScalerDpRx0DpcdInitial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort, EnumFreeSyncSupport enumFreeSyncSupport);
extern void ScalerDpRx0MacInitial(void);
extern void ScalerDpRx0PhyInitial(void);
extern void ScalerDpRx0RebuildPhy(BYTE ucDpLinkRate, BYTE ucDpcdLane);
extern void ScalerDpRx0SignalDetectInitial(BYTE ucDpLinkRate, BYTE ucDpLEQScanValue);
extern bit ScalerDpRx0DisplayFormatSetting(void);

extern bit ScalerDpRx0StreamClkRegenerate(void);
extern void ScalerDpRx0AdjustVsyncDelay(void);
extern bit ScalerDpRx0HdcpMeasureCheck(void);
extern void ScalerDpRx0PhyCTS(void);
extern bit ScalerDpRx0NormalPreDetect(void);
extern BYTE ScalerDpRx0ScanInputPort(void);
extern bit ScalerDpRx0StableDetect(void);
extern void ScalerDpRx0SetHotPlugEvent(EnumDpHotPlugAssertType enumHpdType);

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
extern bit ScalerDpRx0LinkStatusLoss(void);
#endif

extern bit ScalerDpRx0TimerDelayXmsLinkCheck(WORD usNum);
extern bit ScalerDpRx0PollingFlagLinkCheck(WORD usTimeout, WORD usRegister, BYTE ucBit, bit bSuccess);

#if(_DP_RX_ACTIVE_REDUCE_LANE_COUNT_SUPPORT == _ON)
extern void ScalerDpRx0MainLinkQualityManagement(BYTE ucInputPort);
#endif

extern StructDpRxErrorCount ScalerDpRx0GetErrorCount(void);

