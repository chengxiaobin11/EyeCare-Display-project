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
// ID Code      : RL6851_Series_TMDS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6851_SERIES_TMDS__

#include "ScalerFunctionInclude.h"

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Measure Clk Source
//--------------------------------------------------
#define _CLK_SOURCE_RED                         0
#define _CLK_SOURCE_BLUE                        1
#define _CLK_SOURCE_GREEN                       2
#define _CLK_SOURCE_TMDS                        3

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructTMDSCtrlInfo g_stTMDSRx0CtrlInfo;
StructTMDSCtrlInfo g_stTMDSRx1CtrlInfo;
WORD g_usTMDSClkCount;
BYTE g_ucTMDSUnstableIrqFlag;

#if(_D0_TMDS_SUPPORT == _ON)
BYTE g_ucTMDSRx0Z0Status;
#endif
#if(_D1_TMDS_SUPPORT == _ON)
BYTE g_ucTMDSRx1Z0Status;
#endif
BYTE g_ucTMDSSlaveAddr;

#if(_HDCP_2_2_SUPPORT == _ON)
BYTE g_pucRxCaps[3];
#endif

#if((_HDMI21_VRR_SUPPORT == _ON) || (_HDMI21_FVA_SUPPORT == _ON))
volatile StructHdmi21EmpInfo g_stTMDSHdmi21EmpInfo;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerTMDSInitial(BYTE ucInputPort);
void ScalerTMDSInterruptInitial(BYTE ucInputPort);
void ScalerTMDSSetDeOnlyModeConfig(EnumSourceSearchPort enumSourceSearchPort, EnumDeOnlyConfig enumDeonlyConfig);
EnumDeOnlyConfig ScalerTMDSGetDeOnlyModeConfig(EnumSourceSearchPort enumSourceSearchPort);
void ScalerTMDSSetDFEInitial_EXINT0(void);
void ScalerTMDSSetPhy_EXINT0(void);
void ScalerTMDSIntHandler_EXINT0(void);
void ScalerTMDSPSIntHandler_EXINT0(void);
bit ScalerTMDSCheckCDRStable(BYTE ucInputPort, WORD usClkCount);
BYTE ScalerTMDSCheckCDRStable_EXINT0(WORD usClkCount);
WORD ScalerTMDSMeasureClk(BYTE ucInputPort, BYTE ucMeasureClk);
WORD ScalerTMDSMeasureClk_EXINT0(BYTE ucMeasureClk);
void ScalerTMDSRx0SetPorchColor(EnumColorSpace enumColorFormat);

#if(_HDMI_SUPPORT == _ON)
void ScalerTMDSHdmiAVMuteProc(void);
bit ScalerTMDSYUV420SupportCheck(BYTE ucInputPort);
#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))
void ScalerTMDSMacEmpDetectEvent(void);
void ScalerTMDSMacEmpPacketDetect(bit bWait);
WORD ScalerTMDSMacGetVtemInfo(EnumHdmi21VtemInfoContent enumContent);
#endif
#endif

#if(_TMDS_NO_CLK_TRIGGER_AV_WATCHDOG == _ON)
void ScalerTMDSNoClkWatchDogProc(void);
#endif

void ScalerTMDSMacDdcSwitchCtrl(BYTE ucInputPort);
void ScalerTMDSPowerSavingProc(BYTE ucPortSelect);
void ScalerTMDSPowerOffProc(void);
void ScalerTMDSFirstActiveProc(BYTE ucInputPort, BYTE ucSourceType);
bit ScalerTMDSPSPreDetect(BYTE ucInputPort);
bit ScalerTMDSNormalPreDetect(BYTE ucInputPort);
BYTE ScalerTMDSScanInputPort(BYTE ucInputPort, BYTE ucInputType);
BYTE ScalerTMDSFormatDetect(void);
bit ScalerTMDSHdcpEnabled(BYTE ucInputPort);
bit ScalerTMDSStableDetect(BYTE ucInputPort, BYTE ucSourceType);
void ScalerTMDSHotPlugEvent(BYTE ucPortSelect);
void ScalerTMDSSwitchHdcpSlaveAddr(BYTE ucPortSelect);
void ScalerTMDSBeforeHotPlugEventProc(BYTE ucPortSelect, bit bDisableZ0);
void ScalerTMDSAfterHotPlugEventProc(BYTE ucPortSelect, bit bRestoreZ0);
bit ScalerTMDSBEDCheck(void);
void ScalerTMDSHdcp1p4AksvClear(BYTE ucInputPort);

#if(_DVI_SUPPORT == _ON)
void ScalerTMDSRxHdcpVersionCapabilitySwitch(EnumSourceSearchPort enumInputPort, EnumTmdsHdcpType enumTmdsHdcpType);
void ScalerTMDSRxAllPortChangeHdcpCap(EnumTmdsHdcpType enumTmdsHdcpType);
#endif

#if(_TMDS_CLK_INTERRUPTION_CHECK == _ON)
bit ScalerTMDSClkInterruptionCheck(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initialize TMDS setting for search
// Input Value  : Current Search Port
// Output Value : None
//--------------------------------------------------
void ScalerTMDSInitial(BYTE ucInputPort)
{
    // Disable TMDS output
    ScalerSetBit(P2_A6_TMDS_OUTCTL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);

    // Set HS Width(DE only) and HDCP Reference VS
    ScalerSetBit(P2_AB_TMDS_ACC2, ~(_BIT7 | _BIT6), 0x00);

    // Disable C9/CA Port Auto-Inc
    ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, 0x00);

#if(_TMDS_NO_CLK_TRIGGER_AV_WATCHDOG == _ON)
    ScalerTMDSHdmiWatchDog(_TMDS_NO_CLK_WD, _DISABLE);
#endif

#if(_HDMI_SUPPORT == _ON)

    ScalerTMDSHdmiWatchDog((_HDMI_AVI_INFO_VARIATION_WD | _HDMI_AV_MUTE_WD), _DISABLE);

    // Deep Color Mode clock and detection auto
    ScalerSetBit(P2_B8_TMDS_DPC1, ~(_BIT3 | _BIT2), _BIT2);

    // Enable BCH Detection
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_02_PORT_PAGE2_HDMI_BCHCR, ~(_BIT6 | _BIT3 | _BIT2 | _BIT1), (_BIT6 | _BIT3 | _BIT2 | _BIT1));

    // DVI mode don't disable Audio Clk
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

    // Set Video Watch Dog New Mode
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_32_PORT_PAGE2_HDMI_WDCR1, ~_BIT5, _BIT5);

    // Specify Packet Detect Type
    ScalerSetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_43_PORT_PAGE2_HDMI_PTRSV0, _HDMI_AVI_INFO_TYPE);
    ScalerSetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_44_PORT_PAGE2_HDMI_PTRSV1, _HDMI_GENERAL_CONTROL_TYPE);

#if(_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON)
    memset(&g_stTmdsMacRx0SpdInfo, 0x00, sizeof(g_stTmdsMacRx0SpdInfo));
#endif

#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_IDENTIFY_GAME_SRC_SUPPORT == _ON))
    ScalerSetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_A4_PORT_PAGE2_HDMI_PTRSV_2, _SPD_INFO_TYPE);
#endif

#if((_EMBEDDED_DAC_SUPPORT == _ON) && (_DAC_AUDIO_TMDS_FLATLINE_CONTROL == _FLATLINE_TO_ZERO_LEVEL))
    ScalerSetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_A5_PORT_PAGE2_HDMI_PTRSV_3, _HDMI_AUDIO_SAMPLE_PACKET);
#endif

    // Packet Variation Detect Disable
    ScalerSetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_45_PORT_PAGE2_HDMI_PVGCR0, 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_46_PORT_PAGE2_HDMI_PVGCR1, 0x00);
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_47_PORT_PAGE2_HDMI_PVGCR2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_A9_PORT_PAGE2_HDMI_PVSR_4, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_AP, _P2_CA_PT_AA_PORT_PAGE2_HDMI_PVGCR3, 0x00);
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_AB_PORT_PAGE2_HDMI_PVGCR4, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
#endif

    // BED enable for Data Rate >= 700
    if(GET_INPUT_PIXEL_CLK() >= 700)
    {
        // BED counter period set 1 frame
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_B5_PORT_PAGE2_HDMI_BED_FUNC_6, ~(_BIT7 | _BIT6), 0x00);

        // Enable BED Double buffer and Valid Period Type by Frame(by Vsync)
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_AF_PORT_PAGE2_HDMI_BED_FUNC_0, ~(_BIT3 | _BIT1 | _BIT0), _BIT3);
    }

    // Set HDCP DDC Debounce, TMDS Function
    ScalerSetBit(P2_AC_TMDS_Z0CC2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

    // Set HDCP Address is 0x74
    ScalerSetDataPortBit(P2_C3_HDCP_AP, _P2_C4_PT_C2_PORT_PAGE2_HDCP_SLAVE_ADD, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x3A);

    // Set HDCP Feature
#if(_HDMI_SUPPORT == _ON)

#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_0)
    ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_40_PORT_PAGE2_BCAPS, 0x81);
#elif(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_1)
    ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_40_PORT_PAGE2_BCAPS, 0x83);
#else
    ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_40_PORT_PAGE2_BCAPS, 0x81);
#endif

#else // Else of #if(_HDMI_SUPPORT == _ON)

#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_0)
    ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_40_PORT_PAGE2_BCAPS, 0x01);
#elif(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_1_1)
    ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_40_PORT_PAGE2_BCAPS, 0x03);
#else
    ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_40_PORT_PAGE2_BCAPS, 0x01);
#endif

#endif // End of #if(_HDMI_SUPPORT == _ON)

    // MAC Select to HDMI
    ScalerSetBit(PB_00_HD_DP_SEL, ~_BIT0, _BIT0);

    // PHY Select to HDMI
    ScalerSetBit(PB_A5_DIG_05, ~_BIT7, _BIT7);

    // Analog Select to HDMI
    ScalerSetBit(PB_B1_PORT_SEL, ~_BIT5, 0x00);

    // Disable HDMI MAC Global Power Down
    ScalerSetBit(P2_AD_TMDS_CPS, ~_BIT1, 0x00);

    // Enable MAC Input
    ScalerSetBit(P2_A7_TMDS_PWDCTL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Set MAC Signal Swap
    ScalerSetBit(P2_A7_TMDS_PWDCTL, ~(_BIT6 | _BIT5), ((ucInputPort == _D0_INPUT_PORT) ? ((_D0_TMDS_BR_SWAP << 6) | (_D0_TMDS_PN_SWAP << 5)) : ((_D1_TMDS_BR_SWAP << 6) | (_D1_TMDS_PN_SWAP << 5))));

    // Auto switch to DVI when no signal
    ScalerSetBit(P2_AD_TMDS_CPS, ~_BIT2, _BIT2);

    if(ScalerGlobalGetIDCode() == _RL6851_VER_A_ID_CODE)
    {
        // Detect TMDS Format by Data Island Packet Preamble & Guard Band, Frame count: 30 frames
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, ~(_BIT7 | _BIT6 | _BIT4 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
    }
    else
    {
        // Detect TMDS Format by Data Island Packet Preamble & Guard Band
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, ~(_BIT7 | _BIT6 | _BIT4 | _BIT1), _BIT1);
    }

    // Enable TMDS MAC Error Correction
    ScalerSetBit(P2_B7_TMDS_UDC2, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));

    // Set HDMI/DVI switch to Auto Mode
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, ~(_BIT7 | _BIT6 | _BIT3), 0x00);
}

//--------------------------------------------------
// Description  : Initialize TMDS Interrupt Required Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSInterruptInitial(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    if(ScalerGetBit(P2_E6_HDMI_FREQDET_CTRL, _BIT1) == 0x00)
    {
        CLR_TMDS_PHY_SET();
    }

    // Enable Rx_En for Clk pair Z0
    ScalerSetBit(PB_B2_ENABLE, ~_BIT7, _BIT7);

    // Set Reg_bypass_ok=1 for solve P/N short(480p issue)
    ScalerSetBit(PB_C9_KOFFSET_02, ~_BIT6, _BIT6);

    // Choose Measure Clk to TMDS Clk
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), 0x00);

    // Settings for IRQ set PHY
    // Consider using table to fill all required initial settings
    // Set pre-set threshold (225MHz * 0.01 / 26.8KHz = 0x54)

    // Set TMDS Offset = 1/32
    ScalerSetBit(P2_E7_HDMI_FREQDET_OFFSET, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

#if(_TMDS_LOW_SPEED_PORT_SPEED_LIMIT == _OFF)
    // Set Upper Bound
    ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_HIGH_SPEED_UPPER_BOUND));
    ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_HIGH_SPEED_UPPER_BOUND));
#else
    ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOW_SPEED_UPPER_BOUND));
    ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOW_SPEED_UPPER_BOUND));
#endif

    // Set Lower Bound
    ScalerSetByte(P2_EA_HDMI_FREQDET_LOWER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));
    ScalerSetByte(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));

    // Disable Freq. Unstable IRQ
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT1, 0x00);

    // Enable Freq. Stable IRQ
    ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Set Stable Time (0x3F = about 5ms)
    ScalerSetByte(P2_EC_HDMI_FREQDET_STABLE, 0x3F);

    // Clear IRQ Pending Flag
    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_60_PORT_PAGE2_HDMI_INTCR, ~_BIT7, _BIT7);

    // Internal IRQ Enable (Global)
    ScalerGlobalIRQControl(_ENABLE);

    EX0 = 1;

    // Start Freq. Detection
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Set Config of TMDS Mac Deonly mode
// Input Value  : None
// Output Value : enumInputPort, enumDeonlyConfig
//--------------------------------------------------
void ScalerTMDSSetDeOnlyModeConfig(EnumSourceSearchPort enumSourceSearchPort, EnumDeOnlyConfig enumDeonlyConfig)
{
    enumSourceSearchPort = enumSourceSearchPort;

    // De only enable?
    if((enumDeonlyConfig & _DE_ONLY_DISABLE) == _DE_ONLY_DISABLE)
    {
        ScalerSetBit(P2_A7_TMDS_PWDCTL, ~_BIT7, 0x00);
    }
    else if((enumDeonlyConfig & _DE_ONLY_ENABLE) == _DE_ONLY_ENABLE)
    {
        ScalerSetBit(P2_A7_TMDS_PWDCTL, ~_BIT7, _BIT7);
    }

    // Set HS
    if((enumDeonlyConfig & _DE_ONLY_HS_8T) == _DE_ONLY_HS_8T)
    {
        ScalerSetBit(P2_AB_TMDS_ACC2, ~_BIT7, _BIT7);
    }
    else if((enumDeonlyConfig & _DE_ONLY_HS_72T) == _DE_ONLY_HS_72T)
    {
        ScalerSetBit(P2_AB_TMDS_ACC2, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set Config of TMDS Mac Deonly mode
// Input Value  : None
// Output Value : enumInputPort, enumDeonlyConfig
//--------------------------------------------------
EnumDeOnlyConfig ScalerTMDSGetDeOnlyModeConfig(EnumSourceSearchPort enumSourceSearchPort)
{
    EnumDeOnlyConfig enumDeConfig = _DE_NO_INDICATED;

    enumSourceSearchPort = enumSourceSearchPort;

    if(ScalerGetBit(P2_A7_TMDS_PWDCTL, _BIT7) == _BIT7)
    {
        enumDeConfig = _DE_ONLY_ENABLE;
    }
    else
    {
        enumDeConfig = _DE_ONLY_DISABLE;
    }

    if(ScalerGetBit(P2_AB_TMDS_ACC2, _BIT7) == _BIT7)
    {
        enumDeConfig |= _DE_ONLY_HS_8T;
    }
    else
    {
        enumDeConfig |= _DE_ONLY_HS_72T;
    }

    return enumDeConfig;
}

//--------------------------------------------------
// Description  : TMDS DFE Initial Setting (EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSSetDFEInitial_EXINT0(void) using 1
{
    /////////////////////////
    // DFE Code Initialize //
    /////////////////////////

    // Initial DFE Code
    if(GET_INPUT_PIXEL_CLK() < 375)
    {
        // LE  Initial = 4
        ScalerSetByte_EXINT(P1D_A2_L0_LIMIT_INIT, 0x04);
        ScalerSetByte_EXINT(P1D_B2_L1_LIMIT_INIT, 0x04);
        ScalerSetByte_EXINT(P1D_C2_L2_LIMIT_INIT, 0x04);
    }
    else if(GET_INPUT_PIXEL_CLK() < 700)
    {
        // LE  Initial = 6
        ScalerSetByte_EXINT(P1D_A2_L0_LIMIT_INIT, 0x06);
        ScalerSetByte_EXINT(P1D_B2_L1_LIMIT_INIT, 0x06);
        ScalerSetByte_EXINT(P1D_C2_L2_LIMIT_INIT, 0x06);
    }
    else if(GET_INPUT_PIXEL_CLK() < 1000)
    {
        // LE Initial = 11
        ScalerSetByte_EXINT(P1D_A2_L0_LIMIT_INIT, 0x0B);
        ScalerSetByte_EXINT(P1D_B2_L1_LIMIT_INIT, 0x0B);
        ScalerSetByte_EXINT(P1D_C2_L2_LIMIT_INIT, 0x0B);
    }
    else if(GET_INPUT_PIXEL_CLK() < 2000)
    {
        // LE Initial = 12
        ScalerSetByte_EXINT(P1D_A2_L0_LIMIT_INIT, 0x0C);
        ScalerSetByte_EXINT(P1D_B2_L1_LIMIT_INIT, 0x0C);
        ScalerSetByte_EXINT(P1D_C2_L2_LIMIT_INIT, 0x0C);
    }
    else
    {
#if(_TMDS_HIGH_LE_ENABLE == _ON) // Default off
        // LE Initial = 12
        ScalerSetByte_EXINT(P1D_A2_L0_LIMIT_INIT, 0x0C);
        ScalerSetByte_EXINT(P1D_B2_L1_LIMIT_INIT, 0x0C);
        ScalerSetByte_EXINT(P1D_C2_L2_LIMIT_INIT, 0x0C);
#else
        // Using low LE to prevent over EQ
        // Side effect: >11M cable may not use
        // LE Initial = 9
        ScalerSetByte_EXINT(P1D_A2_L0_LIMIT_INIT, 0x09);
        ScalerSetByte_EXINT(P1D_B2_L1_LIMIT_INIT, 0x09);
        ScalerSetByte_EXINT(P1D_C2_L2_LIMIT_INIT, 0x09);
#endif
    }

    // Tap0 Initial Value = 15
    ScalerSetByte_EXINT(P1D_A4_L0_INIT_2, 0x0F);
    ScalerSetByte_EXINT(P1D_B4_L1_INIT_2, 0x0F);
    ScalerSetByte_EXINT(P1D_C4_L2_INIT_2, 0x0F);

    // Tap1 Initial Value = 0
    ScalerSetByte_EXINT(P1D_A5_L0_INIT_3, 0x00);
    ScalerSetByte_EXINT(P1D_B5_L1_INIT_3, 0x00);
    ScalerSetByte_EXINT(P1D_C5_L2_INIT_3, 0x00);

    // Tap2 Initial Value = 0
    ScalerSetByte_EXINT(P1D_A6_L0_INIT_4, 0x00);
    ScalerSetByte_EXINT(P1D_B6_L1_INIT_4, 0x00);
    ScalerSetByte_EXINT(P1D_C6_L2_INIT_4, 0x00);

    // Load Intial DFE Code
    ScalerSetByte_EXINT(P1D_AA_L0_INIT_8, 0x17);
    ScalerSetByte_EXINT(P1D_BA_L1_INIT_8, 0x17);
    ScalerSetByte_EXINT(P1D_CA_L2_INIT_8, 0x17);

    ScalerSetByte_EXINT(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte_EXINT(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte_EXINT(P1D_CA_L2_INIT_8, 0x00);
}

//-------------------------------------------------------------------
// Description  : TMDS Set PHY Function for HDMI+MHL2.0 (EXINT0 Only)
// Input Value  : None
// Output Value : None
//-------------------------------------------------------------------
void ScalerTMDSSetPhy_EXINT0(void) using 1
{
    BYTE ucDelayCount = 0;


    ///////////////
    // RX CMU EN //
    ///////////////

    // [2] cmu_en = 0 --> Disable CMU PLL
    ScalerSetBit_EXINT(PB_B0_CLK_DET, ~_BIT2, 0x00);

    // [3:0] cdr_en = 4'b0000 --> Disable CDREN
    ScalerSetBit_EXINT(PB_B2_ENABLE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // [7:4] rx_en = 4'b1111 --> Enable RXEN
    ScalerSetBit_EXINT(PB_B2_ENABLE, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    // [3] sel_iblpf = 1 --> Enable Local Bias LPF
    ScalerSetBit_EXINT(PB_E8_ST_04, ~_BIT3, _BIT3);

    DELAY_45US_EXINT();

    // [3:0] cdr_en = 4'b0001 ~ 4'b0011 ~ 4'b0111 ~ 4'b1111
    ScalerSetBit_EXINT(PB_B2_ENABLE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
    ScalerSetBit_EXINT(PB_B2_ENABLE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
    ScalerSetBit_EXINT(PB_B2_ENABLE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
    ScalerSetBit_EXINT(PB_B2_ENABLE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Recover Reg_bypass_ok=0 before koffset and after cdr_en=1
    // for solve P/N short(480p issue)
    ScalerSetBit_EXINT(PB_C9_KOFFSET_02, ~_BIT6, 0x00);

    // Enable CCO LDO
    ScalerSetBit_EXINT(PB_C2_CCO, ~_BIT7, _BIT7);


    /////////////////
    // CMU Setting //
    /////////////////

    // [0] PLL_WD_EN = 1'b0 --> Disable WD
    ScalerSetBit_EXINT(PB_AC_WD, ~_BIT0, 0x00);

    // [7:6] CMU_SEL_CP = 2'b10 --> CMU LPF Cp = 2pF
    // [5] en_largers_forcmu = 1 --> CMU Rs increase 20K
    // [2:0] CMU_SEL_R1 = 3'b110 --> CMU LPF Rs = 4K + 20K
    ScalerSetBit_EXINT(PB_C5_CMU_03, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT5 | _BIT2 | _BIT1));

    // [3:0] cdr_cp_in = 4'b0100 --> Icp = 15uA
    ScalerSetBit_EXINT(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);

    if((GET_INPUT_PIXEL_CLK() >= 187) && (GET_INPUT_PIXEL_CLK() < 375))
    {
        // Analog CDR Auto FLD Counter
        // ref_conuter = 30
        // cdr_counter = 480
        // 30/480 = 1/16 = 5*(1/80 clock rate)
        ScalerSetBit_EXINT(PB_D7_ANA_CDR_08, ~(_BIT7 | _BIT6), _BIT6);
        ScalerSetByte_EXINT(PB_D8_ANA_CDR_09, 0x1D);
        ScalerSetByte_EXINT(PB_D9_ANA_CDR_10, 0xDF);

        // [2:0] rate_sel = 3'b100 --> 187.5MHz ~ 375MHz
        ScalerSetBit_EXINT(PB_DC_TMDS_CONT_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);

        // [1:0] SEL_DIV = 2'b11 --> 187.5MHz ~ 375MHz
        ScalerSetBit_EXINT(PB_C2_CCO, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // [5:4] CMU_SELPREDIV = 2'b00 --> /1
        ScalerSetBit_EXINT(PB_C4_CMU_02, ~(_BIT5 | _BIT4), 0x00);

        // [7:0] N_CODE = 0x4C --> 76 + 4 = 80
        ScalerSetByte_EXINT(PB_C3_CMU_01, 0x4C);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 375) && (GET_INPUT_PIXEL_CLK() < 750))
    {
        // Analog CDR Auto FLD Counter
        // ref_conuter = 50
        // cdr_counter = 400
        // 50/400 = 1/8 = 5*(1/40 clock rate)
        ScalerSetBit_EXINT(PB_D7_ANA_CDR_08, ~(_BIT7 | _BIT6), _BIT6);
        ScalerSetByte_EXINT(PB_D8_ANA_CDR_09, 0x31);
        ScalerSetByte_EXINT(PB_D9_ANA_CDR_10, 0x8F);

        // [2:0] rate_sel = 3'b011 --> 375MHz ~ 750MHz
        ScalerSetBit_EXINT(PB_DC_TMDS_CONT_1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

        // [1:0] SEL_DIV = 2'b10 --> 375MHz ~ 750MHz
        ScalerSetBit_EXINT(PB_C2_CCO, ~(_BIT1 | _BIT0), _BIT1);

        // [5:4] CMU_SELPREDIV = 2'b01 --> /1
        ScalerSetBit_EXINT(PB_C4_CMU_02, ~(_BIT5 | _BIT4), 0x00);

        // [7:0] N_CODE = 0x4C --> 36 + 4 = 40
        ScalerSetByte_EXINT(PB_C3_CMU_01, 0x24);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 750) && (GET_INPUT_PIXEL_CLK() < 1500))
    {
        // Analog CDR Auto FLD Counter
        // ref_conuter = 125
        // cdr_counter = 500
        // 125/500 = 1/4 = 5*(1/20 clock rate)
        ScalerSetBit_EXINT(PB_D7_ANA_CDR_08, ~(_BIT7 | _BIT6), _BIT6);
        ScalerSetByte_EXINT(PB_D8_ANA_CDR_09, 0x7C);
        ScalerSetByte_EXINT(PB_D9_ANA_CDR_10, 0xF3);

        // [2:0] rate_sel = 3'b010 --> 750MHz ~ 1500MHz
        ScalerSetBit_EXINT(PB_DC_TMDS_CONT_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

        // [1:0] SEL_DIV = 2'b01 --> 750MHz ~ 1500MHz
        ScalerSetBit_EXINT(PB_C2_CCO, ~(_BIT1 | _BIT0), _BIT0);

        // [5:4] CMU_SELPREDIV = 2'b01 --> /1
        ScalerSetBit_EXINT(PB_C4_CMU_02, ~(_BIT5 | _BIT4), 0x00);

        // [7:0] N_CODE = 0x4C --> 16 + 4 = 20
        ScalerSetByte_EXINT(PB_C3_CMU_01, 0x10);
    }
    else if((GET_INPUT_PIXEL_CLK() >= 1500) && (GET_INPUT_PIXEL_CLK() < 3000))
    {
        // Analog CDR Auto FLD Counter
        // ref_conuter = 250
        // cdr_counter = 500
        // 250/500 = 1/2 = 5*(1/10 clock rate)
        ScalerSetBit_EXINT(PB_D7_ANA_CDR_08, ~(_BIT7 | _BIT6), _BIT6);
        ScalerSetByte_EXINT(PB_D8_ANA_CDR_09, 0xF9);
        ScalerSetByte_EXINT(PB_D9_ANA_CDR_10, 0xF3);

        // [2:0] rate_sel = 3'b001 --> 1500MHz ~ 3000MHz
        ScalerSetBit_EXINT(PB_DC_TMDS_CONT_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

        // [1:0] SEL_DIV = 2'b00 --> 1500MHz ~ 3000MHz
        ScalerSetBit_EXINT(PB_C2_CCO, ~(_BIT1 | _BIT0), 0x00);

        // [5:4] CMU_SELPREDIV = 2'b01 --> /2
        ScalerSetBit_EXINT(PB_C4_CMU_02, ~(_BIT5 | _BIT4), _BIT4);

        // [7:0] N_CODE = 0x4C --> 16 + 4 = 20
        ScalerSetByte_EXINT(PB_C3_CMU_01, 0x10);
    }


    /////////////////
    // CDR Setting //
    /////////////////

    if(GET_INPUT_PIXEL_CLK() < 1500)
    {
        // KP_L0 = 8
        // KP_L1 = 8
        // KP_L2 = 8
        ScalerSetByte_EXINT(PB_F6_CDR_07, 0x20);
        ScalerSetByte_EXINT(PB_F7_CDR_08, 0x20);
        ScalerSetByte_EXINT(PB_F8_CDR_09, 0x20);
    }
    else
    {
        // KP_L0 = 5
        // KP_L1 = 5
        // KP_L2 = 5
        ScalerSetByte_EXINT(PB_F6_CDR_07, 0x14);
        ScalerSetByte_EXINT(PB_F7_CDR_08, 0x14);
        ScalerSetByte_EXINT(PB_F8_CDR_09, 0x14);
    }

    if((GET_INPUT_PIXEL_CLK() << (ScalerGetBit_EXINT(PB_C2_CCO, (_BIT1 | _BIT0)))) >= 2250)
    {
        // [5:4] en_pi_cap_loading = 2'b10 --> 20 fF
        ScalerSetBit_EXINT(PB_B6_REG_RESERVED_APHY_2, ~(_BIT5 | _BIT4), _BIT5);

        // [6] en_cco_lp_mode = 0
        ScalerSetBit_EXINT(PB_C2_CCO, ~_BIT6, 0x00);
    }
    else
    {
        // [5:4] en_pi_cap_loading = 2'b00 --> 60 fF (Default)
        ScalerSetBit_EXINT(PB_B6_REG_RESERVED_APHY_2, ~(_BIT5 | _BIT4), 0x00);

        // [6] en_cco_lp_mode = 1
        ScalerSetBit_EXINT(PB_C2_CCO, ~_BIT6, _BIT6);
    }


    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // [1] bypass_clk_rdy = 1 --> manual mode
    // [0] en_clkout_manual = 0 --> Disable Clkout
    ScalerSetBit_EXINT(PB_AB_SDM_04, ~(_BIT1 | _BIT0), _BIT1);

    // [1] bypass_eqen_rdy = 1 --> manual mode
    // [0] en_eqen_manual = 0 --> Disable Clkout
    ScalerSetBit_EXINT(PB_AD_EQEN_TIMER, ~(_BIT1 | _BIT0), _BIT1);

    // [1] bypass_data_rdy = 1 --> manual mode
    // [0] en_data_manual = 0 --> Disable Dataout
    ScalerSetBit_EXINT(PB_AE_DATA_TIMER, ~(_BIT1 | _BIT0), _BIT1);

    // [4] Disable Lane0 ACDR
    ScalerSetBit_EXINT(PB_AF_ANA_CDR_TIMER, ~_BIT4, 0x00);

    // [7:4] RST_N = 4'b0000 --> Digital Circuit Reset
    ScalerSetBit_EXINT(PB_DA_TMDS_RESET, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // [7:4] RST_N = 4'b1111 --> Digital Circuit Normal
    ScalerSetBit_EXINT(PB_DA_TMDS_RESET, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));


    /////////////////
    // DFE Setting //
    /////////////////

    // Load DFE Initial Code
    ScalerTMDSSetDFEInitial_EXINT0();

    // [7:5] LE_lowgain_highboost = 1 --> LE LowGain HighBoost Mode
    ScalerSetBit_EXINT(PB_CC_KOFFSET_05, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

    if(GET_INPUT_PIXEL_CLK() < 2000)
    {
        // [7] SEL_DFE_DELAY = 1'b1 --> Increase DFE Delay
        ScalerSetBit_EXINT(PB_C6_SIGDET, ~_BIT7, _BIT7);
    }
    else
    {
        // [7] SEL_DFE_DELAY = 1'b0 --> Normal DFE Delay
        ScalerSetBit_EXINT(PB_C6_SIGDET, ~_BIT7, 0x00);
    }

    if(GET_INPUT_PIXEL_CLK() < 2000)
    {
        // [7:5] LE_ISEL = 3'b000
        ScalerSetBit_EXINT(PB_CD_KOFFSET_06, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

        // [7:5] LE_RLSEL = 3'b011
        ScalerSetBit_EXINT(PB_CE_KOFFSET_07, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));
    }
    else
    {
        // [7:5] LE_ISEL = 3'b010
        ScalerSetBit_EXINT(PB_CD_KOFFSET_06, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

        // [7:5] LE_RLSEL = 3'b001
        ScalerSetBit_EXINT(PB_CE_KOFFSET_07, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);
    }


    //////////////
    // K Offset //
    //////////////

    // [6] Enable Foreground Calibration Auto Mode
    ScalerSetBit_EXINT(PB_C8_KOFFSET_01, ~_BIT6, _BIT6);

    // [7] Toggle Foreground Calibration
    ScalerSetBit_EXINT(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);
    ScalerSetBit_EXINT(PB_C8_KOFFSET_01, ~_BIT7, 0x00);
    ScalerSetBit_EXINT(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);

    // Delay Time ~50us
    for(ucDelayCount = 0; ucDelayCount <= 20; ucDelayCount++)
    {
        DELAY_5US_EXINT();

        if(((ScalerGetBit_EXINT(PB_DA_TMDS_RESET, _BIT7) == 0x00) || (ScalerGetBit_EXINT(PB_C7_KOFFSET_00, _BIT5) == _BIT5)) &&
           ((ScalerGetBit_EXINT(PB_DA_TMDS_RESET, _BIT6) == 0x00) || (ScalerGetBit_EXINT(PB_C8_KOFFSET_01, _BIT5) == _BIT5)) &&
           ((ScalerGetBit_EXINT(PB_DA_TMDS_RESET, _BIT5) == 0x00) || (ScalerGetBit_EXINT(PB_C9_KOFFSET_02, _BIT5) == _BIT5)))
        {
            break;
        }
    }

    // Reset Digital CDR
    ScalerSetBit_EXINT(PB_DA_TMDS_RESET, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit_EXINT(PB_DA_TMDS_RESET, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));


    ///////////////////
    // FLD Lock Band //
    ///////////////////

    // [3] reg_adp_eq_off = 1'b0 --> Enable Analog CDR DFE Adaptation
    // [2] reg_cp_en_manual = 1'b0 -->  Disable cp_en_manual
    // [1] reg_ac_en_manual = 0 --> Disable adp_en_manual
    ScalerSetBit_EXINT(PB_D0_ANA_CDR_01, ~(_BIT3 | _BIT2 | _BIT1), 0x00);

    // [5] lane_en = 1 --> Enable FLD
    ScalerSetBit_EXINT(PB_AF_ANA_CDR_TIMER, ~_BIT5, _BIT5);

    // [7] reg_auto_mode = 1'b1 --> FLD Select Auto Mode
    // [3] reg_cp_adj_en = 1'b1 --> Enable Adjust Icp When Tracking
    ScalerSetBit_EXINT(PB_CF_ANA_CDR_00, ~(_BIT7 | _BIT3), (_BIT7 | _BIT3));

    // [7] xtal_en = 0 --> FLD Reference Input Clock
    ScalerSetBit_EXINT(PB_D1_ANA_CDR_02, ~_BIT7, 0x00);

    // [7] reg_rstb_fsm --> Toggle for FLD reset
    // [6] reg_rstb_fld --> Toggle for FLD reset
    ScalerSetBit_EXINT(PB_D3_ANA_CDR_04, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit_EXINT(PB_D3_ANA_CDR_04, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Delay Time ~300us for HBR
    for(ucDelayCount = 0; ucDelayCount <= 100; ucDelayCount++)
    {
        DELAY_5US_EXINT();

        if(ScalerGetBit_EXINT(PB_E6_ST_02, (_BIT2 | _BIT1 | _BIT0)) == 0x05)
        {
            break;
        }
    }

    // [2] cmu_en = 1'b1 --> Enable CMU PLL
    ScalerSetBit_EXINT(PB_B0_CLK_DET, ~_BIT2, _BIT2);

    // Waiting for CMU PLL Stable
    DELAY_XUS_EXINT(150);

    // [0] en_clkout_manual = 1 --> Enable Clkout
    ScalerSetBit_EXINT(PB_AB_SDM_04, ~_BIT0, _BIT0);

    // [0] en_eqen_manual = 1 --> Enable Adaptation
    ScalerSetBit_EXINT(PB_AD_EQEN_TIMER, ~_BIT0, _BIT0);

    // Waiting for the Adaptation
    DELAY_XUS_EXINT(290);

    // [0] en_eqen_manual = 0 --> Disable Adaptation
    ScalerSetBit_EXINT(PB_AD_EQEN_TIMER, ~_BIT0, 0x00);

    // [0] en_data_manual = 1 --> Enable Dataout
    ScalerSetBit_EXINT(PB_AE_DATA_TIMER, ~_BIT0, _BIT0);

    // Reset PHY -> MAC Interface
    ScalerSetBit_EXINT(P2_A7_TMDS_PWDCTL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit_EXINT(P2_A7_TMDS_PWDCTL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Reset HDMI 3 Channel FIFO
    ScalerSetBit_EXINT(P2_B0_TMDS_CHANNEL_FIFO, ~_BIT6, _BIT6);

    // HDMI 3 Channel FIFO Global Enable
    ScalerSetBit_EXINT(P2_B0_TMDS_CHANNEL_FIFO, ~(_BIT7 | _BIT6), _BIT7);

    // Clear RGB Data Detection Flags
    ScalerSetBit_EXINT(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5));
}

//--------------------------------------------------
// Description  : TMDS Interrupt Process (EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSIntHandler_EXINT0(void) using 1
{
    BYTE pucBackUp[4];
    WORD usCount = 0;
    WORD usErrorThreshold_1 = 0;
    WORD usErrorThreshold_2 = 0;

    pucBackUp[0] = ScalerGetByte_EXINT(P2_C9_HDMI_AP);
    pucBackUp[1] = (ScalerGetByte_EXINT(P2_C8_HDMI_APC) & 0x01);

    // Set CA Port non-auto increase
    ScalerSetBit_EXINT(P2_C8_HDMI_APC, ~_BIT0, 0x00);

    pucBackUp[2] = ScalerGetByte_EXINT(P2_C3_HDCP_AP);
    pucBackUp[3] = (ScalerGetByte_EXINT(P2_C2_HDCP_PCR) & 0x01);

    // Set C4 Port non-auto increase
    ScalerSetBit_EXINT(P2_C2_HDCP_PCR, ~(_BIT4 | _BIT0), _BIT0);

    // Freq. Stable Into IRQ
    if((ScalerGetByte_EXINT(P2_EF_HDMI_ERROR_TH) & 0xC0) == 0xC0)
    {
        // Disable Freq Stable IRQ
        ScalerSetBit_EXINT(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6), _BIT6);

#if(_TMDS_NO_CLK_TRIGGER_AV_WATCHDOG == _ON)
        // Disable NO CLK WD
        ScalerSetBit_EXINT(P2_B2_TMDS_DBB2, ~(_BIT5 | _BIT4), 0x00);
#endif

        // Enable Freq unstable IRQ
        ScalerSetBit_EXINT(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

        // Pop up Counter Value
        ScalerSetBit_EXINT(P2_EC_HDMI_FREQDET_STABLE, ~_BIT7, _BIT7);

        usCount = (WORD)(((ScalerGetByte_EXINT(P2_ED_HDMI_FREQDET_RESULT_M) & 0x7F) << 8) | ScalerGetByte_EXINT(P2_EE_HDMI_FREQDET_RESULT_L));

        // TMDS_FREQ(MHz) = GDI_CLK(MHz) * CLK_COUNT * _TMDS_MEASURE_CLOCK_DIVIDER / _TMDS_MEASURE_CLOCK_COUNTER
        SET_INPUT_PIXEL_CLK((((DWORD)_GDI_CLK_KHZ * usCount + 50000) / 100000));

        if(GET_INPUT_PIXEL_CLK() > 3000)
        {
            // Set Input Clock Measure Divider = /2
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
            ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT6, _BIT6);
        }
        else
        {
            // Set Input Clock Measure Divider = /1
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
            ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT6, 0x00);
        }

        if((GET_TMDS_PHY_SET() == _FALSE) || ((bit)ScalerTMDSCheckCDRStable_EXINT0(g_usTMDSClkCount) == _FALSE))
        {
            g_usTMDSClkCount = ScalerTMDSMeasureClk_EXINT0(_CLK_SOURCE_TMDS);

            // If Measure Divider = /2 then CLK x 2
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
            if(ScalerGetBit_EXINT(P2_CA_HDMI_DP, _BIT6) == _BIT6)
            {
                // TMDS_OFFLine Measure FREQ(MHz) = GDI_CLK(MHz) * 1024 * 2 / g_usTMDSClkCount
                SET_TMDS_OFFLINE_MEASURE_CLK(((DWORD)(_GDI_CLK_KHZ * 1024) * 2 / 100) / g_usTMDSClkCount);
            }
            else
            {
                // TMDS_OFFLine Measure FREQ(MHz) = GDI_CLK(MHz) * 1024 / g_usTMDSClkCount
                SET_TMDS_OFFLINE_MEASURE_CLK(((DWORD)(_GDI_CLK_KHZ * 1024) / 100) / g_usTMDSClkCount);
            }

            ScalerTMDSSetPhy_EXINT0();
        }

        // Set Upper Bound (allow 1/64 freq shift)
        ScalerSetByte_EXINT(P2_E8_HDMI_FREQDET_UPPER_M, (HIBYTE(usCount + (usCount >> 6)) & 0x7F));
        ScalerSetByte_EXINT(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(usCount + (usCount >> 6)));

        // Set Lower bound
        ScalerSetByte_EXINT(P2_EA_HDMI_FREQDET_LOWER_M, (HIBYTE(usCount - (usCount >> 6)) & 0x7F));
        ScalerSetByte_EXINT(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(usCount - (usCount >> 6)));

        // Reset Color Depth to 8 Bits
        SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);
        SET_TMDS_PHY_SET();
    }

    // Freq. Unstable Into IRQ
    if((ScalerGetByte_EXINT(P2_E6_HDMI_FREQDET_CTRL) & 0x06) == 0x06)
    {
        g_ucTMDSUnstableIrqFlag = _TRUE;
        // Clear Unstable IRQ Flag
        ScalerSetBit_EXINT(P2_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);

#if(_SDRPLL_SSC_AMPLITUDE > _1_PERCENT)
        usErrorThreshold_1 = (g_usTMDSClkCount >> 5);
        usErrorThreshold_2 = (GET_INPUT_PIXEL_CLK() >> 5);
#else
        usErrorThreshold_1 = (g_usTMDSClkCount >> 6);
        usErrorThreshold_2 = (GET_INPUT_PIXEL_CLK() >> 6);
#endif

        // Ensure Freq really unstable
        if((abs(g_usTMDSClkCount - ScalerTMDSMeasureClk_EXINT0(_CLK_SOURCE_TMDS)) > usErrorThreshold_1) ||
           (abs(GET_INPUT_PIXEL_CLK() - ((GET_TMDS_OFFLINE_MEASURE_CLK() << 3) / ((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) ? _COLOR_DEPTH_8_BITS : GET_COLOR_DEPTH()))) > usErrorThreshold_2))
        {
            // Set Display M1 output force to background color and free run mode
            ScalerSetBit_EXINT(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT5 | _BIT3), _BIT5);

            // Disable RGB/clock Output to avoid garbage
            ScalerSetBit_EXINT(P2_A6_TMDS_OUTCTL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), 0x00);

            // Disable Freq. Unstable IRQ
            ScalerSetBit_EXINT(P2_E6_HDMI_FREQDET_CTRL, ~_BIT1, 0x00);

#if(_TMDS_LOW_SPEED_PORT_SPEED_LIMIT == _OFF)
            // Set Upper Bound
            ScalerSetByte_EXINT(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_HIGH_SPEED_UPPER_BOUND));
            ScalerSetByte_EXINT(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_HIGH_SPEED_UPPER_BOUND));
#else
            ScalerSetByte_EXINT(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOW_SPEED_UPPER_BOUND));
            ScalerSetByte_EXINT(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOW_SPEED_UPPER_BOUND));
#endif
            // Set Lower bound
            ScalerSetByte_EXINT(P2_EA_HDMI_FREQDET_LOWER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));
            ScalerSetByte_EXINT(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));

            // Reset Freq. Detect Counter(Toggle)
            ScalerSetBit_EXINT(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);
            ScalerSetBit_EXINT(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);

            // Enable Freq. Stable IRQ
            ScalerSetBit_EXINT(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            CLR_TMDS_PHY_SET();
        }
    }

    // HDCP 1.4 Write Aksv IRQ have been Received
    if((ScalerGetBit_EXINT(P2_A9_TMDS_ABC0, _BIT7) == _BIT7) && (ScalerGetBit_EXINT(P2_AA_TMDS_ABC1, _BIT4) == _BIT4))
    {
        // clear AKSV & Ri flag
        ScalerSetBit_EXINT(P2_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2), (_BIT7 | _BIT6));

        // SET KEY ready bit 1
        ScalerSetBit_EXINT(P2_AE_TMDS_RPS, ~_BIT1, _BIT1);
    }

#if(_AUDIO_SUPPORT == _ON)
    // Detect if Auido Sampling is Changed
    ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_8A_PORT_PAGE2_AUDIO_FREQDET);
    if(ScalerGetBit_EXINT(P2_CA_HDMI_DP, (_BIT3 | _BIT1)) == (_BIT3 | _BIT1))
    {
        // Clear Auido Sampling Change Flag
        ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_8A_PORT_PAGE2_AUDIO_FREQDET);
        ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT1, _BIT1);

#if(_LINE_IN_SUPPORT == _ON)
        if(ScalerAudioGetInputSource_EXINT0() == _DIGITAL_AUDIO)
#endif
        {
            // Disable FIFO Boundary Tracking, Disable Trend Tracking
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_15_PORT_PAGE2_HDMI_PSCR);
            ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~(_BIT3 | _BIT2), 0x00);

            // Set Double Buffer bit
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D0_PORT_PAGE2_HDMI_CMCR);
            ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT7, _BIT7);

#if(_HDMI_AUDIO_SPREAD_PCODE_SUPPORT == _ON)
            // Disable P Code Spread
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_E2_PORT_PAGE2_P_SPREAD_0);
            ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT7, 0x00);
#endif

            // Reload NF code
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D0_PORT_PAGE2_HDMI_CMCR);
            ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT5, _BIT5);
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D0_PORT_PAGE2_HDMI_CMCR);
            ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT5, 0x00);

            // Set FW tracking reset
#if(_HDMI_AUDIO_FW_TRACKING_MODE_SUPPORT == _ON)
            if(GET_AUDIO_D0_SAMPLING_FREQ() <= _AUDIO_FREQ_48K)
            {
                SET_AUDIO_D0_FW_TRACKING_RESET();
            }
#endif
#if(_AUDIO_MANUAL_SAMPLING_FREQ_SUPPORT == _OFF)
            // No Audio Detect Set User Define Frequency When No Audio
            ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_8B_PORT_PAGE2_AUDIO_FREQ_RESULT);
            if(ScalerGetBit_EXINT(P2_CA_HDMI_DP, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x00)
            {
                // Disable Auto Load S Code
                ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D0_PORT_PAGE2_HDMI_CMCR);
                ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~(_BIT6 | _BIT5), 0x00);

                // Set S code User Define
                ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D5_PORT_PAGE2_HDMI_SCAPR);
                ScalerSetByte_EXINT(P2_CA_HDMI_DP, ScalerAudioGetUserSamplingFreqSCode_EXINT0(_PORT_HDMI, GET_D0_SAMPLING_FREQ_USER_DEFINE()));

                // Set N code User Define
                ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D2_PORT_PAGE2_HDMI_DNF_CODE_1);
                ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), LOBYTE(HIWORD(ScalerAudioGetUserSamplingFreqNFCode_EXINT0(_PORT_HDMI, GET_D0_SAMPLING_FREQ_USER_DEFINE()))));

                // Set F code User Define
                ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D3_PORT_PAGE2_HDMI_DNF_CODE_2);
                ScalerSetByte_EXINT(P2_CA_HDMI_DP, HIBYTE(LOWORD(ScalerAudioGetUserSamplingFreqNFCode_EXINT0(_PORT_HDMI, GET_D0_SAMPLING_FREQ_USER_DEFINE()))));
                ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D4_PORT_PAGE2_HDMI_DNF_CODE_3);
                ScalerSetByte_EXINT(P2_CA_HDMI_DP, LOBYTE(LOWORD(ScalerAudioGetUserSamplingFreqNFCode_EXINT0(_PORT_HDMI, GET_D0_SAMPLING_FREQ_USER_DEFINE()))));

                // Set Double Buffer bit
                ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D0_PORT_PAGE2_HDMI_CMCR);
                ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT7, _BIT7);

                // Load NF code
                ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D0_PORT_PAGE2_HDMI_CMCR);
                ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT5, _BIT5);
                ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_D0_PORT_PAGE2_HDMI_CMCR);
                ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT5, 0x00);

                // CLR PLL Autoload Status Flag
                CLR_AUDIO_D0_AUTO_LOAD_FREQ();
            }
#endif
        }

#if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
        // Turn-off FIFO Tracking
        // Todo!!!

        // Set FW Mannual Mode
        // Todo!!!

        // Set TTS Play Error Flag
        SET_TTS_PLAYBACK_ERROR();
#endif // End of #if(_AUDIO_TTS_SUPPORT_TYPE == _AUDIO_TTS_EMBEDDED_TYPE)
    }
#endif

    // Clear IRQ Pending Flag
    ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_60_PORT_PAGE2_HDMI_INTCR);
    ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT7, _BIT7);

    ScalerSetBit_EXINT(P2_C8_HDMI_APC, ~_BIT0, pucBackUp[1]);
    ScalerSetByte_EXINT(P2_C9_HDMI_AP, pucBackUp[0]);

    ScalerSetBit_EXINT(P2_C2_HDCP_PCR, ~(_BIT4 | _BIT0), pucBackUp[3]);
    ScalerSetByte_EXINT(P2_C3_HDCP_AP, pucBackUp[2]);
}

//--------------------------------------------------
// Description  : TMDS Interrupt Process In PS/PD State(EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSPSIntHandler_EXINT0(void) using 1
{
    BYTE pucBackUp[4];

    pucBackUp[0] = ScalerGetByte_EXINT(P2_C9_HDMI_AP);
    pucBackUp[1] = (ScalerGetByte_EXINT(P2_C8_HDMI_APC) & 0x01);

    // Set CA Port non-auto increase
    ScalerSetBit_EXINT(P2_C8_HDMI_APC, ~_BIT0, 0x00);

    pucBackUp[2] = ScalerGetByte_EXINT(P2_C3_HDCP_AP);
    pucBackUp[3] = (ScalerGetByte_EXINT(P2_C2_HDCP_PCR) & 0x01);

    // Set C4 Port non-auto increase
    ScalerSetBit_EXINT(P2_C2_HDCP_PCR, ~(_BIT4 | _BIT0), _BIT0);

    // HDCP 1.4 Write Aksv IRQ have been Received
    if((ScalerGetBit_EXINT(P2_A9_TMDS_ABC0, _BIT7) == _BIT7) && (ScalerGetBit_EXINT(P2_AA_TMDS_ABC1, _BIT4) == _BIT4))
    {
        // clear AKSV & Ri flag
        ScalerSetBit_EXINT(P2_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2), (_BIT7 | _BIT6));

        // SET KEY ready bit 1
        ScalerSetBit_EXINT(P2_AE_TMDS_RPS, ~_BIT1, _BIT1);
    }

    // Clear IRQ Pending Flag
    ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_60_PORT_PAGE2_HDMI_INTCR);
    ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~_BIT7, _BIT7);

    ScalerSetBit_EXINT(P2_C8_HDMI_APC, ~_BIT0, pucBackUp[1]);
    ScalerSetByte_EXINT(P2_C9_HDMI_AP, pucBackUp[0]);

    ScalerSetBit_EXINT(P2_C2_HDCP_PCR, ~(_BIT4 | _BIT0), pucBackUp[3]);
    ScalerSetByte_EXINT(P2_C3_HDCP_AP, pucBackUp[2]);
}

//--------------------------------------------------
// Description  : Check CDR Locked
// Input Value  : Measured Clk Count to be compared
// Output Value : _TRUE => Stable
//--------------------------------------------------
bit ScalerTMDSCheckCDRStable(BYTE ucInputPort, WORD usClkCount)
{
    BYTE ucStableIrq = 0;
    BYTE ucUnstableIrq = 0;

#if(_SDRPLL_SSC_AMPLITUDE > _1_PERCENT)
    WORD usErrorThreshold = (usClkCount >> 5);
#else
    WORD usErrorThreshold = (usClkCount >> 6);
#endif

    // Backup Stable IRQ && Unstable IRQ enable bit status
    ucStableIrq = ScalerGetByte(P2_EF_HDMI_ERROR_TH);
    ucUnstableIrq = ScalerGetByte(P2_E6_HDMI_FREQDET_CTRL);

    // Disable INT Clock Check
    ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT6 | _BIT2 | _BIT1), 0x00);

    // Check Current Measured Freq. is the same as previously locked
    if(abs(usClkCount - ScalerTMDSMeasureClk(ucInputPort, _CLK_SOURCE_RED)) > usErrorThreshold)
    {
        // Restore INT Clock Check
        ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6 | _BIT5), (ucStableIrq & _BIT7));
        ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT6 | _BIT2 | _BIT1), (ucUnstableIrq & _BIT1));

        return _FALSE;
    }

    if(abs(usClkCount - ScalerTMDSMeasureClk(ucInputPort, _CLK_SOURCE_BLUE)) > usErrorThreshold)
    {
        // Restore INT Clock Check
        ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6 | _BIT5), (ucStableIrq & _BIT7));
        ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT6 | _BIT2 | _BIT1), (ucUnstableIrq & _BIT1));

        return _FALSE;
    }

    if(abs(usClkCount - ScalerTMDSMeasureClk(ucInputPort, _CLK_SOURCE_GREEN)) > usErrorThreshold)
    {
        // Restore INT Clock Check
        ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6 | _BIT5), (ucStableIrq & _BIT7));
        ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT6 | _BIT2 | _BIT1), (ucUnstableIrq & _BIT1));

        return _FALSE;
    }

    // Restore INT Clock Check
    ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6 | _BIT5), (ucStableIrq & _BIT7));
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT6 | _BIT2 | _BIT1), (ucUnstableIrq & _BIT1));

    return _TRUE;
}

//--------------------------------------------------
// Description  : Check CDR Locked (EXINT0 Only)
// Input Value  : Measured Clk Count to be compared
// Output Value : _TRUE => Stable
//--------------------------------------------------
BYTE ScalerTMDSCheckCDRStable_EXINT0(WORD usClkCount) using 1
{
#if(_SDRPLL_SSC_AMPLITUDE > _1_PERCENT)
    WORD usErrorThreshold = (usClkCount >> 5);
#else
    WORD usErrorThreshold = (usClkCount >> 6);
#endif

    // Check Current Measured Freq. is the same as previously locked
    if(abs(usClkCount - ScalerTMDSMeasureClk_EXINT0(_CLK_SOURCE_TMDS)) > usErrorThreshold)
    {
        return _FALSE;
    }

    if(abs(usClkCount - ScalerTMDSMeasureClk_EXINT0(_CLK_SOURCE_RED)) > usErrorThreshold)
    {
        return _FALSE;
    }

    if(abs(usClkCount - ScalerTMDSMeasureClk_EXINT0(_CLK_SOURCE_BLUE)) > usErrorThreshold)
    {
        return _FALSE;
    }

    if(abs(usClkCount - ScalerTMDSMeasureClk_EXINT0(_CLK_SOURCE_GREEN)) > usErrorThreshold)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Measure Clk
// Input Value  : Clk Source to be measured
// Output Value : Measured Clk Count
//--------------------------------------------------
WORD ScalerTMDSMeasureClk(BYTE ucInputPort, BYTE ucMeasureClk)
{
    BYTE ucDelayCount = 0;

    ucInputPort = ucInputPort;

    // Enable CMU_EN(Lane0,1,2) and Rx_EN(Lane0,1,2,3)
    ScalerSetByte(PB_B2_ENABLE, 0xFF);

    // Disable Measure for Reset Measure Window
    ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
    ScalerSetBit(P2_CA_HDMI_DP, ~(_BIT5 | _BIT4 | _BIT3), 0x00);

    // Select reference clk to Xtal Clk and measure clk
    ScalerSetBit(P2_AD_TMDS_CPS, ~(_BIT6 | _BIT5 | _BIT4), ((ucMeasureClk << 5) | _BIT4));

    // Start Measure
    ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
    ScalerSetBit(P2_CA_HDMI_DP, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);

    // Delay at least 40us at Xtal = 27MHz
    for(ucDelayCount = 0; ucDelayCount <= 8; ucDelayCount++)
    {
        DELAY_5US();

        ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
        if(ScalerGetBit(P2_CA_HDMI_DP, _BIT3) == 0x00)
        {
            break;
        }
    }

    ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
    pData[0] = ScalerGetByte(P2_CA_HDMI_DP);

    ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_29_PORT_PAGE2_HDMI_NTX1024TR1);
    pData[1] = ScalerGetByte(P2_CA_HDMI_DP);

    return ((WORD)(pData[0] & 0x07) << 8) | pData[1];
}

//--------------------------------------------------
// Description  : Measure Clk (EXINT0 Only)
// Input Value  : Clk Source to be measured
// Output Value : Measured Clk Count
//--------------------------------------------------
WORD ScalerTMDSMeasureClk_EXINT0(BYTE ucMeasureClk) using 1
{
    BYTE ucDelayCount = 0;
    WORD usClkCount = 0;
    BYTE ucBackUp = 0;

    // Enable CMU_EN(Lane0,1,2) and Rx_EN(Lane0,1,2,3)
    ScalerSetByte_EXINT(PB_B2_ENABLE, 0xFF);

    // Disable Measure for Reset Measure Window
    ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
    ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~(_BIT5 | _BIT4 | _BIT3), 0x00);

    // Select reference clk to Xtal Clk and measure clk
    ScalerSetBit_EXINT(P2_AD_TMDS_CPS, ~(_BIT6 | _BIT5 | _BIT4), ((ucMeasureClk << 5) | _BIT4));

    ucBackUp = (ScalerGetByte_EXINT(P2_C8_HDMI_APC) & 0x01);

    // Set CA Port non-auto increase
    ScalerSetBit_EXINT(P2_C8_HDMI_APC, ~_BIT0, 0x00);

    // Start Measure
    ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
    ScalerSetBit_EXINT(P2_CA_HDMI_DP, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);

    // Delay at least 40us at Xtal = 27MHz
    for(ucDelayCount = 0; ucDelayCount <= 8; ucDelayCount++)
    {
        DELAY_5US_EXINT();

        if((ScalerGetBit_EXINT(P2_CA_HDMI_DP, _BIT3)) == 0x00)
        {
            break;
        }
    }

    ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
    usClkCount = ((WORD)(ScalerGetByte_EXINT(P2_CA_HDMI_DP) & 0x07) << 8);

    ScalerSetByte_EXINT(P2_C9_HDMI_AP, _P2_CA_PT_29_PORT_PAGE2_HDMI_NTX1024TR1);
    usClkCount = usClkCount | ScalerGetByte_EXINT(P2_CA_HDMI_DP);

    ScalerSetBit_EXINT(P2_C8_HDMI_APC, ~_BIT0, ucBackUp);

    return usClkCount;
}

//--------------------------------------------------
// Description  : Set Back Ground Color
// Input Value  : InputPort and Current Color Space
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx0SetPorchColor(EnumColorSpace enumColorFormat)
{
    // Manual Set Background Color Enable
    ScalerSetBit(P2_B9_TMDS_OUT_CTRL, ~_BIT7, 0x00);

    if((enumColorFormat == _COLOR_SPACE_YPBPR) ||
       (enumColorFormat == _COLOR_SPACE_YCBCR444) ||
       (enumColorFormat == _COLOR_SPACE_YCBCR422) ||
       (enumColorFormat == _COLOR_SPACE_YCBCR420))
    {
        ScalerSetBit(P2_B9_TMDS_OUT_CTRL, ~_BIT6, _BIT6);
    }
    else
    {
        ScalerSetBit(P2_B9_TMDS_OUT_CTRL, ~_BIT6, 0x00);
    }
    //////////////////////////////////////////////////////////////////
}

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Hdmi Handle AVMute Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiAVMuteProc(void)
{
    // if AVMute Has been triggered
    if((ScalerGetBit(P2_CB_HDMI_SR, _BIT6) == 0x00) && (ScalerGetBit(P2_A6_TMDS_OUTCTL, (_BIT6 | _BIT5 | _BIT4)) == 0x00))
    {
        // Clear AVMute Flag
        ScalerSetBit(P2_CB_HDMI_SR, ~_BIT7, _BIT7);

        // Disable AVMute Watch Dog
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_31_PORT_PAGE2_HDMI_WDCR0, ~_BIT7, 0x00);

        // Enable Video/Audio Output
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_30_PORT_PAGE2_HDMI_AVMCR, ~(_BIT6 | _BIT5 | _BIT3), (_BIT6 | _BIT5 | _BIT3));

        // Enable RGB Output
        ScalerSetBit(P2_A6_TMDS_OUTCTL, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

        // Enable AVMute Watch Dog
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_31_PORT_PAGE2_HDMI_WDCR0, ~_BIT7, _BIT7);
    }
}

//--------------------------------------------------
// Description  : TMDS 420 Color Space Support Check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerTMDSYUV420SupportCheck(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            // Check YCbCr 420 format; only support 8 bit
            if(ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420)
            {
                return _FALSE;
            }

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            // Check YCbCr 420 format; only support 8 bit
            if(ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420)
            {
                return _FALSE;
            }

            break;
#endif

        default:
            break;
    }

    return _TRUE;
}

#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))
//--------------------------------------------------
// Description  : HDMI2.1 EMP Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSMacEmpDetectEvent(void)
{
    CLR_TMDS_EMP_DETECTING();
}

//--------------------------------------------------
// Description  : Detect HDMI2.1 EMP
// Input Value  : bWait => Whether to wait then read
// Output Value : None
//--------------------------------------------------
void ScalerTMDSMacEmpPacketDetect(bit bWait)
{
    if(bWait == _WAIT)
    {
#if((_HDMI21_VRR_SUPPORT == _ON) || (_HDMI21_FVA_SUPPORT == _ON))
#if(_HDMI21_VRR_SUPPORT == _ON)
        // Clear VRR flag
        CLR_TMDS_HDMI21_VRR_EN();
        CLR_TMDS_HDMI21_QMS_EN();
#endif
#if(_HDMI21_FVA_SUPPORT == _ON)
        SET_TMDS_HDMI21_FVA_FACTOR(1);
#endif
        // CLR_TMDS_MAC_RX3_HDMI21_VTEM_RECEIVED();
#if(_HDMI21_VRR_SUPPORT == _ON)
        CLR_TMDS_HDMI21_VRR_RECEIVE_CHG();
        CLR_TMDS_HDMI21_QMS_RECEIVE_CHG();
#endif

        // Wait at least 2 frames for HW auto update VTEM flag and Length not 0
        if((ScalerTimerPollingFlagProc(90, P2_54_PAGE2_EMP_CTRL_0, _BIT6, _TRUE) == _TRUE) && ((ScalerGetByte(P2_5B_PAGE2_HDMI_EMP_6) != 0x00) || (ScalerGetByte(P2_5C_PAGE2_HDMI_EMP_7) != 0x00)))
        {
            SET_TMDS_HDMI21_VTEM_RECEIVED();
        }
        else
        {
            CLR_TMDS_HDMI21_VTEM_RECEIVED();
        }
#endif
        CLR_TMDS_EMP_DETECTING();
    }
    else
    {
#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))
        if((ScalerGetBit(P2_54_PAGE2_EMP_CTRL_0, _BIT6) == _BIT6) && ((ScalerGetByte(P2_5B_PAGE2_HDMI_EMP_6) != 0x00) || (ScalerGetByte(P2_5C_PAGE2_HDMI_EMP_7) != 0x00)))
        {
            SET_TMDS_HDMI21_VTEM_RECEIVED();

            // Clear VTEM flag
            ScalerSetBit(P2_54_PAGE2_EMP_CTRL_0, ~(_BIT6 | _BIT5 | _BIT4), _BIT6);

#if(_HDMI21_VRR_SUPPORT == _ON)
            if((((bit)ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_VRR_EN)) == _ENABLE) && (GET_TMDS_HDMI21_VRR_EN() != _ENABLE))
            {
                DebugMessageRx0("TMDS Rx0: VRR_EN from 0 -> 1", 0x00);
                SET_TMDS_HDMI21_VRR_RECEIVE_CHG();
                SET_TMDS_HDMI21_VRR_EN();
            }
            else if((((bit)ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_VRR_EN)) == _DISABLE) && (GET_TMDS_HDMI21_VRR_EN() != _DISABLE))
            {
                DebugMessageRx0("TMDS Rx0: VRR_EN from 1 -> 0", 0x00);
                SET_TMDS_HDMI21_VRR_RECEIVE_CHG();
                CLR_TMDS_HDMI21_VRR_EN();
            }

            if((((bit)ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_QMS_EN)) == _ENABLE) && (GET_TMDS_HDMI21_QMS_EN() != _ENABLE))
            {
                DebugMessageRx0("TMDS Rx0: QMS_EN from 0 -> 1", 0x00);
                SET_TMDS_HDMI21_QMS_RECEIVE_CHG();
                SET_TMDS_HDMI21_QMS_EN();
            }
            else if((((bit)ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_QMS_EN)) == _DISABLE) && (GET_TMDS_HDMI21_QMS_EN() != _DISABLE))
            {
                DebugMessageRx0("TMDS Rx0: QMS_EN from 1 -> 0", 0x00);
                SET_TMDS_HDMI21_QMS_RECEIVE_CHG();
                CLR_TMDS_HDMI21_QMS_EN();
            }
#endif
        }
        else
        {
            // Received VTEM -> No Received / MLDS
            if(GET_TMDS_HDMI21_VTEM_RECEIVED() == _TRUE)
            {
#if(_HDMI21_VRR_SUPPORT == _ON)
                if(GET_TMDS_HDMI21_VRR_EN() == _TRUE)
                {
                    DebugMessageRx0("VTEM->No Received(VRR_EN from 1->0)", 0x00);
                    SET_TMDS_HDMI21_VRR_RECEIVE_CHG();
                    CLR_TMDS_HDMI21_VRR_EN();
                }

                if(GET_TMDS_HDMI21_QMS_EN() == _TRUE)
                {
                    DebugMessageRx0("VTEM->No Received(QMS_EN from 1->0)", 0x00);
                    SET_TMDS_HDMI21_QMS_RECEIVE_CHG();
                    CLR_TMDS_HDMI21_QMS_EN();
                }
#endif

#if(_HDMI21_FVA_SUPPORT == _ON)
                SET_TMDS_HDMI21_FVA_FACTOR(1);
#endif
            }

            CLR_TMDS_HDMI21_VTEM_RECEIVED();
        }
#endif
        SET_TMDS_EMP_DETECTING();

        // Activate EMP Detection Event 12 frames = 45ms * 12
        ScalerTimerActiveTimerEvent(540, _SCALER_TIMER_EVENT_TMDS_EMP_DETECT);
    }
}

#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get HDMI21 VTEM Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
WORD ScalerTMDSMacGetVtemInfo(EnumHdmi21VtemInfoContent enumContent)
{
    if(GET_TMDS_HDMI21_VTEM_RECEIVED() == _TRUE)
    {
        switch(enumContent)
        {
            case _HDMI21_VTEM_INFO_VRR_EN:

                return (((ScalerGetByte(P2_5D_PAGE2_HDMI_EMP_8) & _BIT0) == _BIT0) ? _ON : _OFF);

            case _HDMI21_VTEM_INFO_M_CONST:

                return (((ScalerGetByte(P2_5D_PAGE2_HDMI_EMP_8) & _BIT1) == _BIT1) ? _ON : _OFF);

            case _HDMI21_VTEM_INFO_FVA_FACTOR_M1:

                return ((ScalerGetByte(P2_5D_PAGE2_HDMI_EMP_8) & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4);

            case _HDMI21_VTEM_INFO_BASE_VFRONT:

                return (ScalerGetByte(P2_5E_PAGE2_HDMI_EMP_9));


            case _HDMI21_VTEM_INFO_BASE_REFRESH_RATE:

                return (((WORD)(ScalerGetByte(P2_5F_PAGE2_HDMI_EMP_A) & 0x03) << 8) | (WORD)(ScalerGetByte(P2_60_PAGE2_HDMI_EMP_B)));

            case _HDMI21_VTEM_INFO_QMS_EN:

                return (((ScalerGetByte(P2_5D_PAGE2_HDMI_EMP_8) & _BIT2) == _BIT2) ? _ON : _OFF);

            case _HDMI21_VTEM_NEXT_TFR:

                return ((ScalerGetByte(P2_5F_PAGE2_HDMI_EMP_A) & (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3)) >> 3);

            default:

                break;
        }
    }

    return 0x00;
}
#endif
#endif
#endif // End of #if(_HDMI_SUPPORT == _ON)

#if(_TMDS_NO_CLK_TRIGGER_AV_WATCHDOG == _ON)
//--------------------------------------------------
// Description  : TMDS handle WD when no clk
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSNoClkWatchDogProc(void)
{
    if((ScalerGetBit(P2_B6_TMDS_UDC1, _BIT3) == _BIT3) && (ScalerGetBit(P2_EF_HDMI_ERROR_TH, _BIT6) == _BIT6))
    {
        // clr Freq Stable Flag
        ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~_BIT6, _BIT6);

        ScalerTimerDelayXms(5);

        if(ScalerGetBit(P2_EF_HDMI_ERROR_TH, _BIT6) == _BIT6)
        {
            // clr NO CLK Flag
            ScalerSetBit(P2_B6_TMDS_UDC1, ~_BIT3, _BIT3);

            // Disable NO CLK WD
            ScalerSetBit(P2_B2_TMDS_DBB2, ~(_BIT5 | _BIT4), 0x00);

            // Enable Video/Audio Output
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_30_PORT_PAGE2_HDMI_AVMCR, ~(_BIT6 | _BIT5 | _BIT3), (_BIT6 | _BIT5 | _BIT3));

            // Enable RGB Output
            ScalerSetBit(P2_A6_TMDS_OUTCTL, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

            // Enable NO CLK WD
            ScalerSetBit(P2_B2_TMDS_DBB2, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
        }
    }
}
#endif

//--------------------------------------------------
// Description  : TMDS Port DDC Selection
// Input Value  : Input Port
// Output Value : None
//--------------------------------------------------
void ScalerTMDSMacDdcSwitchCtrl(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT:
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
            ScalerSetBit(P2_C2_HDCP_PCR, ~(_BIT2 | _BIT1), 0x00);
#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
            ScalerSetBit(P2_C2_HDCP_PCR, ~(_BIT2 | _BIT1), _BIT1);
#endif
            break;
#endif // End of #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
            ScalerSetBit(P2_C2_HDCP_PCR, ~(_BIT2 | _BIT1), 0x00);
#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
            ScalerSetBit(P2_C2_HDCP_PCR, ~(_BIT2 | _BIT1), _BIT1);
#endif
            break;
#endif // End of #if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : TMDS Power Saving Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSPowerSavingProc(BYTE ucPortSelect)
{
    ucPortSelect = ucPortSelect;

    ScalerTMDSFreqDetectDisable();

    // Switch TMDS Input/Output to Auto
    ScalerSetBit(P2_A6_TMDS_OUTCTL, ~_BIT7, _BIT7);
    ScalerSetBit(P2_A7_TMDS_PWDCTL, ~_BIT4, _BIT4);

    // Set Freq. Stable Time: 5 times
    ScalerSetByte(P2_EC_HDMI_FREQDET_STABLE, 0x05);

    // Set Freq. Shift Offset to Max
    ScalerSetBit(P2_E7_HDMI_FREQDET_OFFSET, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

#if(_TMDS_LOW_SPEED_PORT_SPEED_LIMIT == _OFF)
    // Set Upper Bound
    ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_PS_HIGH_SPEED_UPPER_BOUND));
    ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_PS_HIGH_SPEED_UPPER_BOUND));
#else
    ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_PS_LOW_SPEED_UPPER_BOUND));
    ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_PS_LOW_SPEED_UPPER_BOUND));
#endif


    // Set Counter Lower Bound
    ScalerSetByte(P2_EA_HDMI_FREQDET_LOWER_M, HIBYTE(_TMDS_FREQ_PS_LOWER_BOUND));
    ScalerSetByte(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(_TMDS_FREQ_PS_LOWER_BOUND));
}

//--------------------------------------------------
// Description  : TMDS Power Off Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSPowerOffProc(void)
{
    // Disable EDID read/ SCL toggle IRQ
    MCU_FFE4_DDC0_EDID_IRQ = ((MCU_FFE4_DDC0_EDID_IRQ & ~(_BIT3 | _BIT1)) | (_BIT2 | _BIT0));
    MCU_FFE5_DDC1_EDID_IRQ = ((MCU_FFE5_DDC1_EDID_IRQ & ~(_BIT3 | _BIT1)) | (_BIT2 | _BIT0));

    ScalerTMDSFreqDetectDisable();
}

//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerTMDSFirstActiveProc(BYTE ucInputPort, BYTE ucSourceType)
{
    ucInputPort = ucInputPort;
    ucSourceType = ucSourceType;

#if(_TMDS_NO_CLK_TRIGGER_AV_WATCHDOG == _ON)
    // Enable NO CLK WD
    ScalerTMDSHdmiWatchDog(_TMDS_NO_CLK_WD, _ENABLE);
#endif
}

//--------------------------------------------------
// Description  : Signal Detection for TMDS(Power Saving)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSPSPreDetect(BYTE ucInputPort)
{
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if(ScalerDebugCheckDebugPort(ucInputPort) == _FALSE)
#endif
    {
        if((ucInputPort == _D0_INPUT_PORT) && (GET_TMDS_RX0_DDC_DETECTED() == _TRUE))
        {
            // DDC handshake Detected
            DebugMessageDigital("7. wuzanne test : Normal D0 DDC", 0);

            CLR_TMDS_RX0_DDC_DETECTED();

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
            SET_TMDS_RX0_TOGGLE_Z0();
#endif
            return _TRUE;
        }
    }

    if(ucInputPort == _D0_INPUT_PORT)
    {
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
        if(((MCU_FFE4_DDC0_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX0_DDC_DETECTED() != _TRUE))
        {
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT3;

            CLR_TMDS_RX0_DDC_DETECTED();
        }
#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
        if(((MCU_FFE5_DDC1_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX0_DDC_DETECTED() != _TRUE))
        {
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT3;

            CLR_TMDS_RX0_DDC_DETECTED();
        }
#endif // End of #if(_D0_DDC_CHANNEL_SEL == _DDC0)
    }
#endif // End of #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if(ScalerDebugCheckDebugPort(ucInputPort) == _FALSE)
#endif
    {
        if((ucInputPort == _D1_INPUT_PORT) && (GET_TMDS_RX1_DDC_DETECTED() == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : Normal D1 DDC", 0);

            CLR_TMDS_RX1_DDC_DETECTED();

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
            SET_TMDS_RX1_TOGGLE_Z0();
#endif
            return _TRUE;
        }
    }

    if(ucInputPort == _D1_INPUT_PORT)
    {
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
        if(((MCU_FFE4_DDC0_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX1_DDC_DETECTED() != _TRUE))
        {
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT3;

            CLR_TMDS_RX1_DDC_DETECTED();
        }
#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
        if(((MCU_FFE5_DDC1_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX1_DDC_DETECTED() != _TRUE))
        {
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT3;

            CLR_TMDS_RX1_DDC_DETECTED();
        }
#endif // End of #if(_D1_DDC_CHANNEL_SEL == _DDC0)
    }
#endif // End of #if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)


    // Reset Freq. Detect Counter(Toggle) & Choose Measure Clk to TMDS Clk
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), 0x00);
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);


    // Clear Freq. Stable Flag
    ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~_BIT6, _BIT6);

    // Clear Unstable Flag
    ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);

    // Delay enough time for freq. measure (calculated for measure 5 times)
    ScalerTimerDelayXms(5);

    // Detect Freq. Measure Stable
    if((ScalerGetBit(P2_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P2_EF_HDMI_ERROR_TH, _BIT6) == _BIT6))
    {
#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
        if(ucInputPort == _D0_INPUT_PORT)
        {
            SET_TMDS_RX0_TOGGLE_Z0();
        }
        else if(ucInputPort == _D1_INPUT_PORT)
        {
            SET_TMDS_RX1_TOGGLE_Z0();
        }
#endif
        return _TRUE;
    }
    else
    {
        // Disable Freq. Detection
        ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);

        return _FALSE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Signal PreDetection for TMDS(Power Normal)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSNormalPreDetect(BYTE ucInputPort)
{
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if(ScalerDebugCheckDebugPort(ucInputPort) == _FALSE)
#endif
    {
        // DDC handshake Detected
        if((ucInputPort == _D0_INPUT_PORT) && (GET_TMDS_RX0_DDC_DETECTED() == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : Normal D0 DDC", 0);

            CLR_TMDS_RX0_DDC_DETECTED();

            return _TRUE;
        }
    }

    if(ucInputPort == _D0_INPUT_PORT)
    {
        // Enable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
        if(((MCU_FFE4_DDC0_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX0_DDC_DETECTED() != _TRUE))
        {
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT3;

            CLR_TMDS_RX0_DDC_DETECTED();
        }
#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
        if(((MCU_FFE5_DDC1_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX0_DDC_DETECTED() != _TRUE))
        {
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT3;

            CLR_TMDS_RX0_DDC_DETECTED();
        }
#endif // End of #if(_D0_DDC_CHANNEL_SEL == _DDC0)
    }
#endif // End of #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if(ScalerDebugCheckDebugPort(ucInputPort) == _FALSE)
#endif
    {
        if((ucInputPort == _D1_INPUT_PORT) && (GET_TMDS_RX1_DDC_DETECTED() == _TRUE))
        {
            DebugMessageDigital("7. wuzanne test : Normal D1 DDC", 0);

            CLR_TMDS_RX1_DDC_DETECTED();

            return _TRUE;
        }
    }

    if(ucInputPort == _D1_INPUT_PORT)
    {
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
        if(((MCU_FFE4_DDC0_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX1_DDC_DETECTED() != _TRUE))
        {
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT3;

            CLR_TMDS_RX1_DDC_DETECTED();
        }
#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
        if(((MCU_FFE5_DDC1_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX1_DDC_DETECTED() != _TRUE))
        {
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT3;

            CLR_TMDS_RX1_DDC_DETECTED();
        }
#endif
    }
#endif // End of #if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

    ScalerTimerDelayXms(6);

    if(GET_TMDS_PHY_SET() == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : TMDS Port Source/Sync Scanning and Setting
// Input Value  : Input Port
// Output Value : Source DVI --> DVI Format
//                Source HDMI --> HDMI Format
//                Source None --> No Stable Sync
//--------------------------------------------------
BYTE ScalerTMDSScanInputPort(BYTE ucInputPort, BYTE ucInputType)
{
    BYTE ucTMDSType = _SOURCE_NONE;
    BYTE ucTMDSVideoDataType = _TMDS_VIDEO_DATA_NONE;

#if(_HDMI_SUPPORT == _ON)
    WORD usInputPixelClk = 0;
#endif

    ucInputType = ucInputType;

    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
            {
                return _SOURCE_NONE;
            }

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
            {
                return _SOURCE_NONE;
            }

            break;
#endif

        default:

            break;
    }

    if(GET_TMDS_PHY_SET() == _TRUE)
    {
        // Delay for PHY Stable
        ScalerTimerDelayXms(2);


        if((ScalerTMDSCheckCDRStable(ucInputPort, g_usTMDSClkCount) == _FALSE) || (ScalerTMDSBEDCheck() == _FALSE))
        {
#if(_TMDS_LOW_SPEED_PORT_SPEED_LIMIT == _OFF)
            // Set Upper Bound
            ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_HIGH_SPEED_UPPER_BOUND));
            ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_HIGH_SPEED_UPPER_BOUND));
#else
            ScalerSetByte(P2_E8_HDMI_FREQDET_UPPER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOW_SPEED_UPPER_BOUND));
            ScalerSetByte(P2_E9_HDMI_FREQDET_UPPER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOW_SPEED_UPPER_BOUND));
#endif
            // Set Lower bound
            ScalerSetByte(P2_EA_HDMI_FREQDET_LOWER_M, HIBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));
            ScalerSetByte(P2_EB_HDMI_FREQDET_LOWER_L, LOBYTE(_TMDS_FREQ_NORMAL_LOWER_BOUND));


            // Set Stable Time (0x3F = about 5ms)
            ScalerSetByte(P2_EC_HDMI_FREQDET_STABLE, 0x3F);

            CLR_TMDS_PHY_SET();

            // Disable Freq. Unstable IRQ
            ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT1, 0x00);

            // Reset Freq. Detect Counter(Toggle)
            ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);
            ScalerSetBit(P2_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);

            // Enable Freq. Stable IRQ
            ScalerSetBit(P2_EF_HDMI_ERROR_TH, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            DebugMessageDigital("Scan Input Port Clk UnStable", 0x00);

            return _SOURCE_NONE;
        }

        // Clear RGBHV Flag
        ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

        // Clear Info Packet SRAM
        ScalerSetBit(P2_AD_TMDS_CPS, ~_BIT3, _BIT3);
        ScalerSetBit(P2_AD_TMDS_CPS, ~_BIT3, 0x00);

        // Clear AVI infoframe & GCP packet Detection Flag
        ScalerSetBit(P2_CC_HDMI_GPVS, ~_BIT6, _BIT6);
        ScalerSetBit(P2_CC_HDMI_GPVS, ~_BIT5, _BIT5);

        // Clear VTEM flag
        ScalerSetBit(P2_54_PAGE2_EMP_CTRL_0, ~(_BIT6 | _BIT5 | _BIT4), _BIT6);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
        // Clear DRR flag
        CLR_FREESYNC_ENABLED();
#endif

#if((_HDMI_FREESYNC_SUPPORT == _ON) || (_HDMI_FREESYNC_II_SUPPORT == _ON))
        // Clear SPD infoframe
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_00_PORT_PAGE2_HDMI_SCR, ~(_BIT7 | _BIT6), _BIT7);
#endif

        DebugMessageRx0("9. Freq Check Pass => Pixel Clock", GET_INPUT_PIXEL_CLK());

        if(ScalerTMDSFormatDetect() == _SOURCE_HDMI)
        {
            DebugMessageDigital("Format Detect HDMI", 0x00);

#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_BY_INPUT)
            ScalerSetDataPortBit(P2_C3_HDCP_AP, _P2_C4_PT_40_PORT_PAGE2_BCAPS, ~_BIT1, _BIT1);
#endif

#if(_HDMI_FROM_DVI_CONNECT == _OFF)
            if(GET_PORT_TYPE(ucInputType) == _PORT_DVI)
            {
                return _SOURCE_NONE;
            }
#endif
            ucTMDSType = _SOURCE_HDMI;
        }
        else
        {
#if(_TMDS_HDCP_FEATURE == _HDCP_FEATURE_BY_INPUT)
            ScalerSetDataPortBit(P2_C3_HDCP_AP, _P2_C4_PT_40_PORT_PAGE2_BCAPS, ~_BIT1, 0x00);
#endif

            ucTMDSType = _SOURCE_DVI;
        }

        ucTMDSVideoDataType = ScalerTMDSVideoDetect(_WAIT);

        if(ucTMDSVideoDataType == _TMDS_VIDEO_DATA_DE_ONLY)
        {
            DebugMessageDigital("DE Only Mode", 0x00);

#if(_DVI_DE_ONLY_SUPPORT == _ON)
            if(ucTMDSType == _SOURCE_DVI)
            {
                // Enable DE Only Mode
                ScalerSetBit(P2_A7_TMDS_PWDCTL, ~_BIT7, _BIT7);
            }
            else
            {
                return _SOURCE_NONE;
            }
#else
            return _SOURCE_NONE;
#endif
        }
        else if(ucTMDSVideoDataType == _TMDS_VIDEO_DATA_RGBHV)
        {
            // Enable DE Only Mode
            ScalerSetBit(P2_A7_TMDS_PWDCTL, ~_BIT7, _BIT7);
        }
        else
        {
            return _SOURCE_NONE;
        }

#if(_HDMI_SUPPORT == _ON)
        if(ucTMDSType == _SOURCE_HDMI)
        {
            // HDMI packet detect --> AVI infoframe & GCP packet
            ScalerTMDSHdmiPacketDetect(_WAIT);

#if((_HDMI21_VRR_SUPPORT == _ON) || (_HDMI21_FVA_SUPPORT == _ON))
            // Get EMP packet
            ScalerTMDSMacEmpPacketDetect(_WAIT);
#endif

            ScalerSyncTMDSRx0HdmiVideoSetting();

            SET_COLOR_DEPTH(ScalerTMDSHdmiGetColorDepth());

            if((GET_COLOR_DEPTH() != _COLOR_DEPTH_8_BITS) && (GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR422))
            {
                DebugMessageDigital("Deep Color Mode Detected", GET_COLOR_DEPTH());

                // Backup Input Pixel clk
                usInputPixelClk = GET_INPUT_PIXEL_CLK();

                SET_INPUT_PIXEL_CLK((GET_INPUT_PIXEL_CLK() << 3) / GET_COLOR_DEPTH());

                if(ScalerTMDSHdmiDeepColorProc(g_usTMDSClkCount) == _FALSE)
                {
                    // Restore Input Pixel clk
                    SET_INPUT_PIXEL_CLK(usInputPixelClk);

                    return _SOURCE_NONE;
                }

                // Turn On Deep Color Block
                ScalerSetBit(P2_B5_TMDS_UDC0, ~_BIT7, _BIT7);
            }
            else
            {
                // Turn off Deep Color Block
                ScalerSetBit(P2_B5_TMDS_UDC0, ~_BIT7, 0x00);

                // Disable Set clk for deep color
                ScalerSetBit(PB5_A2_PLL_OUT_CONTROL, ~_BIT6, 0x00);
            }

#if(_HDMI_FREESYNC_SUPPORT == _ON)
            if(GET_HDMIRX0_AMD_SPD_INFO(_SPD_INFO_FREESYNC_SUPPORT) == _ENABLE)
            {
                SET_HDMI_FREESYNC_ENABLED();

                // Get SPD Free Sync Vfreq Max
                g_usFREESYNCVFreq_max = (WORD)GET_HDMIRX0_AMD_SPD_INFO(_SPD_INFO_FREESYNC_MAX_VFREQ) * 10;
                g_usFREESYNCVFreq_min = (WORD)GET_HDMIRX0_AMD_SPD_INFO(_SPD_INFO_FREESYNC_MIN_VFREQ) * 10;

                // Disable DE Only Mode
                ScalerSetBit(P2_A7_TMDS_PWDCTL, ~_BIT7, 0x00);
            }
            else
#endif
            {
#if((_HDMI21_FVA_SUPPORT == _ON) || (_HDMI21_VRR_SUPPORT == _ON))
                if(GET_TMDS_HDMI21_VTEM_RECEIVED() == _TRUE)
                {
#if(_HDMI21_VRR_SUPPORT == _ON)
                    WORD usSourceBrr = 0x00;

                    // Get Base Frame Rate from SRC
                    if((GET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED() == _TRUE) && (ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_VIC) != 0x00))
                    {
                        usSourceBrr = ((WORD)ScalerTMDSGetVicVfreqParameter(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_VIC)) * 10);
                        DebugMessageRx0("VRR BRR (AVI IF)", usSourceBrr);
                    }
                    else if(ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_BASE_REFRESH_RATE) != 0x00)
                    {
                        usSourceBrr = ((WORD)ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_BASE_REFRESH_RATE) * 10);
                        DebugMessageRx0("VRR BRR (VTEM)", usSourceBrr);
                    }
                    else
                    {
                        DebugMessageRx0("VRR BRR Error!!", 0x00);
                    }

                    // Get Max VFmax from SRC BRR
                    SET_DRR_VFREQ_MAX(usSourceBrr);

                    if(((bit)ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_VRR_EN)) == _ENABLE)
                    {
                        SET_TMDS_HDMI21_VRR_EN();
                        DebugMessageRx0("VRR_EN", 0x00);
                    }
                    else
                    {
                        CLR_TMDS_HDMI21_VRR_EN();
                        DebugMessageRx0("VRR_DIS", 0x00);
                    }

                    if(((bit)ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_QMS_EN)) == _ENABLE)
                    {
                        SET_TMDS_HDMI21_QMS_EN();
                        DebugMessageRx0("QMS_EN", 0x00);
                    }
                    else
                    {
                        CLR_TMDS_HDMI21_QMS_EN();
                        DebugMessageRx0("QMS_DIS", 0x00);
                    }

#if(_HDMI_FORCE_VRR_SUPPORT == _ON)
                    // Get SPD Free Sync Vfreq Max
                    SET_DRR_VFREQ_MAX(0);
                    SET_DRR_VFREQ_MIN(0);
#endif
#endif

#if(_HDMI21_FVA_SUPPORT == _ON)
                    SET_TMDS_HDMI21_FVA_FACTOR(ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_FVA_FACTOR_M1) + 1);
#endif
                    // Disable DE Only Mode
                    ScalerSetBit(P2_A7_TMDS_PWDCTL, ~_BIT7, 0x00);
                }
#endif
            }
        }
        else
        {
            CLR_HDMI_RX0_AVI_INFO_FRAME_RECEIVED();

            CLR_HDMI_GCP_RECEIVED();

            // Disable All WD when DVI
            ScalerTMDSHdmiWatchDog((_HDMI_AVI_INFO_VARIATION_WD | _HDMI_AV_MUTE_WD), _DISABLE);

            ScalerTMDSDviVideoSetting(ucInputPort);

            SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);

            // Turn off Deep Color Block
            ScalerSetBit(P2_B5_TMDS_UDC0, ~_BIT7, 0x00);
        }
#else

        ScalerTMDSDviVideoSetting(ucInputPort);

        SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);

        // Turn off Deep Color Block
        ScalerSetBit(P2_B5_TMDS_UDC0, ~_BIT7, 0x00);
#endif

        // Enable Video Output
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_30_PORT_PAGE2_HDMI_AVMCR, ~_BIT3, _BIT3);
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_80_PORT_PAGE2_HDMI_DPC_SET0, ~_BIT7, _BIT7);

        // Enable RGB Clk Output
        ScalerSetBit(P2_A6_TMDS_OUTCTL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5 | _BIT4 | _BIT3));

        return ucTMDSType;
    }

    return _SOURCE_NONE;
}

//--------------------------------------------------
// Description  : Detect TMDS Format
// Input Value  : None
// Output Value : Return DVI or HDMI format
//--------------------------------------------------
BYTE ScalerTMDSFormatDetect(void)
{
    // Polling at least 3 frame for HW auto detect TMDS format
    if(ScalerTimerPollingFlagProc(130, P2_CB_HDMI_SR, _BIT0, _TRUE) == _TRUE)
    {
        ScalerSetBit(P2_AF_TMDS_WDC, ~_BIT0, 0x00);

        return _SOURCE_HDMI;
    }
    else
    {
        ScalerSetBit(P2_AF_TMDS_WDC, ~_BIT0, _BIT0);
        return _SOURCE_DVI;
    }
}

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : None
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
bit ScalerTMDSHdcpEnabled(BYTE ucInputPort)
{
    BYTE pucHDCPFrameCount[2];
    memset(pucHDCPFrameCount, 0, sizeof(pucHDCPFrameCount));

    ucInputPort = ucInputPort;

    ScalerGetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_C0_PORT_PAGE2_HDCP_FCR, 1, &pucHDCPFrameCount[0], _NON_AUTOINC);

    // Wait 2Vsync to make sure frame counter changing, and timeout 45ms (margin + 1/24 frame+rate)
    ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);
    ScalerTimerPollingFlagProc(45, P2_A4_TMDS_CTRL, _BIT3, _TRUE);
    ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);
    ScalerTimerPollingFlagProc(45, P2_A4_TMDS_CTRL, _BIT3, _TRUE);


    ScalerGetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_C0_PORT_PAGE2_HDCP_FCR, 1, &pucHDCPFrameCount[1], _NON_AUTOINC);

    if(pucHDCPFrameCount[0] != pucHDCPFrameCount[1])
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : On Line Check TMDS stability
// Input Value  : ucSourceType --> Source Type
// Output Value : True --> TMDS Stable
//                False --> TMDS Unstable
//--------------------------------------------------
bit ScalerTMDSStableDetect(BYTE ucInputPort, BYTE ucSourceType)
{
    ucInputPort = ucInputPort;

    // CLR SCL/SDA Toggle Flag
    CLR_TMDS_RX0_DDC_DETECTED();
    CLR_TMDS_RX1_DDC_DETECTED();

#if(_TMDS_CLK_INTERRUPTION_CHECK == _ON)
    if(ScalerTMDSClkInterruptionCheck() == _FALSE)
    {
        return _FALSE;
    }
#endif

    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
            {
                DebugMessageRx0("Rx HPD Toggle!!", 0);
                return _FALSE;
            }

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)

            if(GET_TMDS_RX0_TOGGLE_Z0() == _TRUE)
            {
                SET_TMDS_RX0_TOGGLE_Z0_EVENT();

                return _FALSE;
            }

#endif
            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
            {
                return _FALSE;
            }

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)

            if(GET_TMDS_RX1_TOGGLE_Z0() == _TRUE)
            {
                SET_TMDS_RX1_TOGGLE_Z0_EVENT();

                return _FALSE;
            }

#endif
            break;
#endif

        default:

            break;
    }

#if(_TMDS_CLK_INTERRUPTION_CHECK == _OFF)
    if(ScalerTMDSCheckCDRStable(ucInputPort, g_usTMDSClkCount) == _FALSE)
    {
        DebugMessageRx0("CDR Unstable!!", ucSourceType);
        return _FALSE;
    }
#endif

    // Check TMDS Clock Output Disable
    if(ScalerGetBit(P2_A6_TMDS_OUTCTL, _BIT3) == 0x00)
    {
        DebugMessageRx0("TMDS Clock Output has been disable", ucSourceType);
        return _FALSE;
    }


    // Check TMDS Format Changed

    if(ucSourceType == _SOURCE_HDMI)
    {
        if(ScalerGetBit(P2_CB_HDMI_SR, _BIT0) == 0x00)
        {
            DebugMessageRx0("TMDS Format Changed", ucSourceType);
            return _FALSE;
        }
    }
    else
    {
        if(ScalerGetBit(P2_CB_HDMI_SR, _BIT0) == _BIT0)
        {
            DebugMessageRx0("TMDS Format Changed", ucSourceType);
            return _FALSE;
        }
    }

    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            if(GET_TMDS_Z0_ASSERTED() == _TRUE)
            {
                // Hdcp1.4 normal check
                if(ScalerGetBit(P2_C0_HDCP_CR, _BIT0) == _BIT0)
                {
                    if((ScalerGetBit(P2_A9_TMDS_ABC0, _BIT6) == _BIT6) && (!((ScalerGetBit(P2_AE_TMDS_RPS, _BIT1) == _BIT1) && (ScalerGetBit(P2_A9_TMDS_ABC0, _BIT5) == _BIT5))))
                    {
                        SET_TMDS_RX0_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);

                        CLR_TMDS_Z0_ASSERTED();

                        DebugMessageRx0("7. HDCP Abnormal !!!!!", 0);

                        return _FALSE;
                    }
                    else if(((ScalerGetBit(P2_A9_TMDS_ABC0, _BIT7) == (_BIT7)) || (ScalerGetBit(P2_AE_TMDS_RPS, _BIT1) == (_BIT1))) && (ScalerGetBit(P2_A9_TMDS_ABC0, _BIT5) == (_BIT5)))
                    {
                        CLR_TMDS_Z0_ASSERTED();

                        DebugMessageRx0("7. HDCP Normal", 0);
                    }
                }
            }

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            if(GET_TMDS_Z0_ASSERTED() == _TRUE)
            {
                // Hdcp1.4 normal check
                if(ScalerGetBit(P2_C0_HDCP_CR, _BIT0) == _BIT0)
                {
                    if((ScalerGetBit(P2_A9_TMDS_ABC0, _BIT6) == _BIT6) && (!((ScalerGetBit(P2_AE_TMDS_RPS, _BIT1) == _BIT1) && (ScalerGetBit(P2_A9_TMDS_ABC0, _BIT5) == _BIT5))))
                    {
                        SET_TMDS_RX1_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);

                        CLR_TMDS_Z0_ASSERTED();

                        DebugMessageRx0("7. HDCP Abnormal !!!!!", 0);

                        return _FALSE;
                    }
                    else if(((ScalerGetBit(P2_A9_TMDS_ABC0, _BIT7) == (_BIT7)) || (ScalerGetBit(P2_AE_TMDS_RPS, _BIT1) == (_BIT1))) && (ScalerGetBit(P2_A9_TMDS_ABC0, _BIT5) == (_BIT5)))
                    {
                        CLR_TMDS_Z0_ASSERTED();

                        DebugMessageRx0("7. HDCP Normal", 0);
                    }
                }
            }

            break;
#endif

        default:

            break;
    }

    if(ucSourceType == _SOURCE_DVI)
    {
        if(GET_TMDS_RGBHV_DETECTING() == _FALSE)
        {
            // TMDS Video Detected
#if(_DVI_DE_ONLY_SUPPORT == _OFF)
            if(ScalerTMDSVideoDetect(_NOT_WAIT) != _TMDS_VIDEO_DATA_RGBHV)
#else
            if(ScalerTMDSVideoDetect(_NOT_WAIT) == _TMDS_VIDEO_DATA_NONE)
#endif
            {
                DebugMessageRx0("TMDS Video format changed", ucSourceType);

                return _FALSE;
            }
        }
    }

#if(_HDMI_SUPPORT == _ON)

    if(ucSourceType == _SOURCE_HDMI)
    {
        if(GET_HDMI_PACKET_DETECTING() == _FALSE)
        {
            // HDMI Packet Detected
            ScalerTMDSHdmiPacketDetect(_NOT_WAIT);

            if(GET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED() == _TRUE)
            {
                if(ScalerSyncTMDSRx0HdmiColorInfoChanged() == _TRUE)
                {
                    DebugMessageRx0("Color Info Changed", ucSourceType);
                    return _FALSE;
                }

                if(ScalerTMDSHdmiAviPixelRepInfoChanged() == _TRUE)
                {
                    DebugMessageRx0("Pixel Repetition Info Changed", ucSourceType);
                    return _FALSE;
                }
            }
            else
            {
                if(GET_COLOR_SPACE() != _COLOR_SPACE_RGB)
                {
                    DebugMessageRx0("HDMI Info Frame Not Received and not RGB", ucSourceType);
                    return _FALSE;
                }

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
                if(GET_COLOR_RGB_QUANTIZATION_RANGE() != _RGB_QUANTIZATION_RESERVED)
                {
                    DebugMessageRx0("No Quantization Range Specified", ucSourceType);
                    return _FALSE;
                }
#endif

                if(GET_TMDS_RX0_AVI_PIXEL_REPETITION() != _AVI_PIXEL_REPETITION_0)
                {
                    DebugMessageRx0("Pixel Repetition Not Received and not Pixel repetition 0", ucSourceType);
                    return _FALSE;
                }
            }

            if((ScalerGetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_41_PORT_PAGE2_HDMI_VWDSR, _BIT0) == _BIT0) && (ScalerGetBit(P2_CC_HDMI_GPVS, _BIT0) == _BIT0))
            {
                DebugMessageRx0("HDMI AVI info frame has changed", ucSourceType);
                return _FALSE;
            }

            if(GET_HDMI_GCP_RECEIVED() == _TRUE)
            {
                if((GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR422) && (ScalerTMDSHdmiGetColorDepth() != GET_COLOR_DEPTH()))
                {
                    DebugMessageRx0("Color Depth Has Changed", GET_COLOR_DEPTH());
                    return _FALSE;
                }
            }
            else
            {
                if((GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR422) && (GET_COLOR_DEPTH() != _COLOR_DEPTH_8_BITS))
                {
                    DebugMessageRx0("HDMI GCP PACKET Not Received and not 8 bit", ucSourceType);
                    return _FALSE;
                }
            }

#if(_HDMI_FREESYNC_SUPPORT == _ON)
            if(GET_TMDS_RX0_SPD_INFO_FRAME_RECEIVED() == _TRUE)
            {
                if((bit)GET_HDMIRX0_AMD_SPD_INFO(_SPD_INFO_FREESYNC_SUPPORT) != GET_HDMI_FREESYNC_ENABLED())
                {
                    DebugMessageRx0("HDMI Freesync Status Change", GET_HDMI_FREESYNC_ENABLED());
                    return _FALSE;
                }
            }
            else
            {
                if(GET_HDMI_FREESYNC_ENABLED() == _TRUE)
                {
                    DebugMessageRx0("HDMI Freesync Status Change", GET_HDMI_FREESYNC_ENABLED());
                    return _FALSE;
                }
            }
#endif
        }

#if(_HDMI_FORCE_VRR_SUPPORT == _OFF)
#if((_HDMI21_VRR_SUPPORT == _ON) || (_HDMI21_FVA_SUPPORT == _ON))
        if(GET_TMDS_EMP_DETECTING() == _FALSE)
        {
            // EMP Packet Detect
            ScalerTMDSMacEmpPacketDetect(_NOT_WAIT);

#if(_HDMI21_VRR_SUPPORT == _ON)
            if((GET_TMDS_HDMI21_VTEM_RECEIVE_CHG() == _TRUE) && (GET_TMDS_HDMI21_VTEM_RECEIVED() == _TRUE))
            {
                DebugMessageRx0("Tmds Rx0: VTEM from NA(or MLDS) to received", 0x00);
                CLR_TMDS_HDMI21_VTEM_RECEIVE_CHG();

                return _FALSE;
            }
#endif

#if(_HDMI21_FVA_SUPPORT == _ON)
            if(GET_TMDS_HDMI21_VTEM_RECEIVED() == _TRUE)
            {
                // FVA factor change
                if(GET_TMDS_HDMI21_FVA_FACTOR() != (ScalerTMDSMacGetVtemInfo(_HDMI21_VTEM_INFO_FVA_FACTOR_M1) + 1))
                {
                    return _FALSE;
                }
            }
#endif
        }
#endif
#endif
    }

#endif

    return _TRUE;
}

//--------------------------------------------------
// Description  : TMDS Hot Plug Event
// Input Value  : None
// Output Value :
//--------------------------------------------------
void ScalerTMDSHotPlugEvent(BYTE ucPortSelect)
{
    switch(ucPortSelect)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            if(GET_HDMI_Z0_HPD_TYPE() == _HDMI_HPD_Z0_TOGGLE_AT_SAME_TIME)
            {
                ScalerTMDSBeforeHotPlugEventProc(_D0_INPUT_PORT, _TRUE);
            }
            else
            {
                ScalerTMDSBeforeHotPlugEventProc(_D0_INPUT_PORT, _FALSE);
            }

            // ACER mode and DVI port will only toggle Z0 130ms
#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
            if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() == _TMDS_HPD_ACER)
            {
                if(GET_D0_CABLE_STATUS() == _TRUE)
                {
                    ScalerTimerDelayXms(_TMDS_ACER_HPD_TIME);
                }
            }
            else
#endif
            {
                if(GET_HDMI_Z0_HPD_TYPE() == _HDMI_Z0_TOGGLE_BEFORE_HPD_TOGGLE)
                {
                    // wait Z0 / HPD Interval
                    ScalerTimerDelayXms(GET_HDMI_Z0_HPD_INTERVAL());
                }

                // HPD Low
                ScalerTMDSHotPlugLowProc(_D0_INPUT_PORT);

                // wait
                if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() == _TMDS_HPD_NORMAL)
                {
                    ScalerTMDSHotPlugHighProc(_D0_INPUT_PORT, GET_HDMI_HOTPLUG_TIME());
                }
                else if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() == _TMDS_HPD_HDCP_2_2)
                {
                    ScalerTMDSHotPlugHighProc(_D0_INPUT_PORT, _TMDS_HDCP_2_2_HPD_TIME);
                }
                else if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() == _TMDS_HPD_ACER)
                {
                    ScalerTMDSHotPlugHighProc(_D0_INPUT_PORT, _TMDS_ACER_HPD_TIME);
                }
                else if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() == _TMDS_HPD_EDID_SWITCH)
                {
                    ScalerTMDSHotPlugHighProc(_D0_INPUT_PORT, _TMDS_EDID_SWITCH_HPD_TIME);
                }
                else
                {
                    ScalerTMDSHotPlugHighProc(_D0_INPUT_PORT, GET_HDMI_HOTPLUG_TIME());
                }
            }

            if(GET_HDMI_Z0_HPD_TYPE() == _HDMI_HPD_Z0_TOGGLE_AT_SAME_TIME)
            {
                // Restore Slave Address and Z0 Status
                ScalerTMDSAfterHotPlugEventProc(_D0_INPUT_PORT, _TRUE);
            }
            else
            {
                // Restore Slave Address
                ScalerTMDSAfterHotPlugEventProc(_D0_INPUT_PORT, _FALSE);
            }

            if(GET_HDMI_Z0_HPD_TYPE() == _HDMI_HPD_TOGGLE_BEFORE_Z0_TOGGLE)
            {
                // wait HPD / Z0 Interval
                ScalerTimerDelayXms(GET_HDMI_Z0_HPD_INTERVAL());

                // Disable Z0
                ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // wait Z0 Low Period
                ScalerTimerDelayXms(GET_HDMI_Z0_LOW_PERIOD());
            }

            DebugMessageRx0("Rx0 HPD Toggle!!", 0);

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
            if(GET_TMDS_RX0_TOGGLE_Z0_EVENT() == _TRUE)
            {
                CLR_TMDS_RX0_TOGGLE_Z0();
                CLR_TMDS_RX0_TOGGLE_Z0_EVENT();
            }
#endif

            CLR_TMDS_RX0_HPD_TRIGGER_EVENT();

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            if(GET_HDMI_Z0_HPD_TYPE() == _HDMI_HPD_Z0_TOGGLE_AT_SAME_TIME)
            {
                ScalerTMDSBeforeHotPlugEventProc(_D1_INPUT_PORT, _TRUE);
            }
            else
            {
                ScalerTMDSBeforeHotPlugEventProc(_D1_INPUT_PORT, _FALSE);
            }

            // ACER mode and DVI port will only toggle Z0 130ms
#if((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
            if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() == _TMDS_HPD_ACER)
            {
                if(GET_D1_CABLE_STATUS() == _TRUE)
                {
                    ScalerTimerDelayXms(_TMDS_ACER_HPD_TIME);
                }
            }
            else
#endif
            {
                if(GET_HDMI_Z0_HPD_TYPE() == _HDMI_Z0_TOGGLE_BEFORE_HPD_TOGGLE)
                {
                    // wait Z0 / HPD Interval
                    ScalerTimerDelayXms(GET_HDMI_Z0_HPD_INTERVAL());
                }

                // HPD Low
                ScalerTMDSHotPlugLowProc(_D1_INPUT_PORT);

                // wait
                if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() == _TMDS_HPD_NORMAL)
                {
                    ScalerTMDSHotPlugHighProc(_D1_INPUT_PORT, GET_HDMI_HOTPLUG_TIME());
                }
                else if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() == _TMDS_HPD_HDCP_2_2)
                {
                    ScalerTMDSHotPlugHighProc(_D1_INPUT_PORT, _TMDS_HDCP_2_2_HPD_TIME);
                }
                else if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() == _TMDS_HPD_ACER)
                {
                    ScalerTMDSHotPlugHighProc(_D1_INPUT_PORT, _TMDS_ACER_HPD_TIME);
                }
                else if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() == _TMDS_HPD_EDID_SWITCH)
                {
                    ScalerTMDSHotPlugHighProc(_D1_INPUT_PORT, _TMDS_EDID_SWITCH_HPD_TIME);
                }
                else
                {
                    ScalerTMDSHotPlugHighProc(_D1_INPUT_PORT, GET_HDMI_HOTPLUG_TIME());
                }
            }

            if(GET_HDMI_Z0_HPD_TYPE() == _HDMI_HPD_Z0_TOGGLE_AT_SAME_TIME)
            {
                // Restore Slave Address and Z0 Status
                ScalerTMDSAfterHotPlugEventProc(_D1_INPUT_PORT, _TRUE);
            }
            else
            {
                // Restore Slave Address
                ScalerTMDSAfterHotPlugEventProc(_D1_INPUT_PORT, _FALSE);
            }

            if(GET_HDMI_Z0_HPD_TYPE() == _HDMI_HPD_TOGGLE_BEFORE_Z0_TOGGLE)
            {
                // wait HPD / Z0 Interval
                ScalerTimerDelayXms(GET_HDMI_Z0_HPD_INTERVAL());

                // Disable Z0
                ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // wait Z0 Low Period
                ScalerTimerDelayXms(GET_HDMI_Z0_LOW_PERIOD());
            }

            DebugMessageRx1("Rx1 HPD Toggle!!", 0);

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
            if(GET_TMDS_RX1_TOGGLE_Z0_EVENT() == _TRUE)
            {
                CLR_TMDS_RX1_TOGGLE_Z0();
                CLR_TMDS_RX1_TOGGLE_Z0_EVENT();
            }
#endif

            CLR_TMDS_RX1_HPD_TRIGGER_EVENT();

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : TMDS Switch Slave Address
// Input Value  : ucPortSelect
// Output Value :
//--------------------------------------------------
void ScalerTMDSSwitchHdcpSlaveAddr(BYTE ucPortSelect)
{
    ucPortSelect = ucPortSelect;

    // Switch Slave Address to unknow State (Prohibit any handshake on DDC Channel During HPD Low)
    ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_C2_PORT_PAGE2_HDCP_SLAVE_ADD, 0x7F);
}
//--------------------------------------------------
// Description  : TMDS Before Hot Plug Event Process
// Input Value  : ucPortSelect, bDisableZ0
// Output Value :
//--------------------------------------------------
void ScalerTMDSBeforeHotPlugEventProc(BYTE ucPortSelect, bit bDisableZ0)
{
    switch(ucPortSelect)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            if(GET_D0_CABLE_STATUS() == _TRUE)
            {
                // Save Z0 Status
                g_ucTMDSRx0Z0Status = ScalerGetBit(PB_B3_IMPEDANCE_00, (_BIT3 | _BIT2 | _BIT1 | _BIT0));

                // Backup Slave Address
                ScalerGetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_C2_PORT_PAGE2_HDCP_SLAVE_ADD, 1, &g_ucTMDSSlaveAddr, _NON_AUTOINC);

                if(bDisableZ0 == _TRUE)
                {
                    // Disable Z0
                    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                }
            }
            else if(GET_D0_CABLE_STATUS() == _FALSE)
            {
                // DDC reset
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
                MCU_FF1F_DDC0_DDC_CONTROL_1 |= _BIT1;
#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
                MCU_FF2D_DDC1_DDC_CONTROL_1 |= _BIT1;
#endif
            }

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            if(GET_D1_CABLE_STATUS() == _TRUE)
            {
                // Save Z0 Status
                g_ucTMDSRx1Z0Status = ScalerGetBit(PB_B4_IMPEDANCE_01, (_BIT3 | _BIT2 | _BIT1 | _BIT0));

                // Backup Slave Address
                ScalerGetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_C2_PORT_PAGE2_HDCP_SLAVE_ADD, 1, &g_ucTMDSSlaveAddr, _NON_AUTOINC);

                if(bDisableZ0 == _TRUE)
                {
                    // Disable Z0
                    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
                }
            }
            else if(GET_D1_CABLE_STATUS() == _FALSE)
            {
                // DDC reset
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
                MCU_FF1F_DDC0_DDC_CONTROL_1 |= _BIT1;
#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
                MCU_FF2D_DDC1_DDC_CONTROL_1 |= _BIT1;
#endif
            }

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : TMDS After Hot Plug Event Process
// Input Value  : ucPortSelect, bRestoreZ0
// Output Value :
//--------------------------------------------------
void ScalerTMDSAfterHotPlugEventProc(BYTE ucPortSelect, bit bRestoreZ0)
{
    switch(ucPortSelect)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            if(GET_D0_CABLE_STATUS() == _TRUE)
            {
                // Restore Slave Address
                ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_C2_PORT_PAGE2_HDCP_SLAVE_ADD, g_ucTMDSSlaveAddr);

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
                if(g_ucTmdsD0DdcramNackStatus == _FALSE)
                {
                    // DDCRAM Force Nack off
                    ScalerSyncSetDdcForceNack(_D0_INPUT_PORT, _OFF);
                }

                // Restore DDCCI Slave Address
                ScalerMcuDdcciEnable(_ENABLE, _D0_INPUT_PORT);
#endif

                if(bRestoreZ0 == _TRUE)
                {
                    // Restore Z0 Status
                    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), g_ucTMDSRx0Z0Status);
                }
            }
            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            if(GET_D1_CABLE_STATUS() == _TRUE)
            {
                // Restore Slave Address
                ScalerSetDataPortByte(P2_C3_HDCP_AP, _P2_C4_PT_C2_PORT_PAGE2_HDCP_SLAVE_ADD, g_ucTMDSSlaveAddr);

#if(_DELL_HDMI_HPD_DDC_STYLE_SUPPORT == _ON)
                if(g_ucTmdsD1DdcramNackStatus == _FALSE)
                {
                    // DDCRAM Force Nack off
                    ScalerSyncSetDdcForceNack(_D1_INPUT_PORT, _OFF);
                }

                // Restore DDCCI Slave Address
                ScalerMcuDdcciEnable(_ENABLE, _D1_INPUT_PORT);
#endif

                if(bRestoreZ0 == _TRUE)
                {
                    // Restore Z0 Status
                    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), g_ucTMDSRx1Z0Status);
                }
            }
            break;
#endif

        default:

            break;
    }
}

//-------------------------------------------------
// Description  : TMDS Bit Error Detection
// Input Value  : None
// Output Value : _FALSE=>Reset PHY
//--------------------------------------------------
bit ScalerTMDSBEDCheck(void)
{
    BYTE ucLEL0 = 0;
    BYTE ucLEL1 = 0;
    BYTE ucLEL2 = 0;
    BYTE ucBEDErrorCountDefault = 0;
    BYTE ucBEDErrorCountLE3 = 0;
    BYTE ucBEDErrorCountLE6 = 0;
    BYTE ucTMDSBEDCycle = 0;

    g_ucTMDSUnstableIrqFlag = _FALSE;

    if(GET_TMDS_PHY_SET() == _FALSE)
    {
        return _FALSE;
    }
    if(GET_INPUT_PIXEL_CLK() <= 1250)
    {
        return _TRUE;
    }

    // check 12 frames, XBOX worst case is 10 frames.
    for(ucTMDSBEDCycle = 0; ucTMDSBEDCycle < 12; ucTMDSBEDCycle++)
    {
        if(g_ucTMDSUnstableIrqFlag == _TRUE)
        {
            break;
        }
        // Clear Vsync
        ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);

        // Wait Vsync
        if(ScalerTimerPollingFlagProc(50, P2_A4_TMDS_CTRL, _BIT3, _TRUE) == _TRUE)
        {
            // Read Bit Error enable
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_AF_PORT_PAGE2_HDMI_BED_FUNC_0, ~_BIT5, _BIT5);

            // pop up Bit Error Counter
            ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_B6_PORT_PAGE2_HDMI_BED_FUNC_7);
            ucBEDErrorCountDefault = ScalerGetByte(P2_CA_HDMI_DP);

            if(ucBEDErrorCountDefault > 0)
            {
                ucLEL0 = ScalerGetBit(P1D_A2_L0_LIMIT_INIT, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
                ucLEL1 = ScalerGetBit(P1D_B2_L1_LIMIT_INIT, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
                ucLEL2 = ScalerGetBit(P1D_C2_L2_LIMIT_INIT, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

                // change to LEQ = 6
                ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x06);
                ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x06);
                ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x06);

                DELAY_45US();

                // Clear Vsync
                ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);

                // Wait Vsync
                if(ScalerTimerPollingFlagProc(50, P2_A4_TMDS_CTRL, _BIT3, _TRUE) == _TRUE)
                {
                    // Read Bit Error enable
                    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_AF_PORT_PAGE2_HDMI_BED_FUNC_0, ~_BIT5, _BIT5);

                    // pop up Bit Error Counter
                    ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_B6_PORT_PAGE2_HDMI_BED_FUNC_7);
                    ucBEDErrorCountLE6 = ScalerGetByte(P2_CA_HDMI_DP);
                }
                else
                {
                    ucBEDErrorCountLE6 = 0xFF;
                }

                // change to LEQ = 3
                ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x03);
                ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x03);
                ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x03);

                DELAY_45US();

                // Clear Vsync
                ScalerSetBit(P2_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT3);

                // Wait Vsync
                if(ScalerTimerPollingFlagProc(50, P2_A4_TMDS_CTRL, _BIT3, _TRUE) == _TRUE)
                {
                    // Read Bit Error enable
                    ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_AF_PORT_PAGE2_HDMI_BED_FUNC_0, ~_BIT5, _BIT5);

                    // pop up Bit Error Counter
                    ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_B6_PORT_PAGE2_HDMI_BED_FUNC_7);
                    ucBEDErrorCountLE3 = ScalerGetByte(P2_CA_HDMI_DP);
                }
                else
                {
                    ucBEDErrorCountLE3 = 0xFF;
                }

                if((ucBEDErrorCountDefault > ucBEDErrorCountLE6) && (ucBEDErrorCountLE3 >= ucBEDErrorCountLE6))
                {
                    // Restore to LEQ to 6
                    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x06);
                    ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x06);
                    ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x06);
                }
                else if((ucBEDErrorCountDefault > ucBEDErrorCountLE3) && (ucBEDErrorCountLE6 >= ucBEDErrorCountLE3))
                {
                    if(ucBEDErrorCountLE6 == ucBEDErrorCountLE3)
                    {
                        // Restore to LEQ to 6
                        ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x06);
                        ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x06);
                        ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x06);
                    }
                }
                else
                {
                    // Restore to LEQ to Default
                    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, ucLEL0);
                    ScalerSetByte(P1D_B2_L1_LIMIT_INIT, ucLEL1);
                    ScalerSetByte(P1D_C2_L2_LIMIT_INIT, ucLEL2);
                }

                break;
            }
        }
        // no Vsync, DE only mode keep LEQ default
        else
        {
            break;
        }
    }

    if(g_ucTMDSUnstableIrqFlag == _TRUE)
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : ScalerTMDSHdcp1p4AksvClear
// Input Value  : None
// Output Value :
//--------------------------------------------------
void ScalerTMDSHdcp1p4AksvClear(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            if(CHECK_TMDS_DPHY_SWITCH(_D0_INPUT_PORT) == _TRUE)
            {
                ScalerSetBit(P2_AE_TMDS_RPS, ~(_BIT1), 0x00);
            }
            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            if(CHECK_TMDS_DPHY_SWITCH(_D1_INPUT_PORT) == _TRUE)
            {
                // SET KEY ready bit 1
                ScalerSetBit(P2_AE_TMDS_RPS, ~(_BIT1), 0x00);
            }
            break;
#endif

        default:

            break;
    }
}

#if(_DVI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Switch HDCP Version Capbility
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRxHdcpVersionCapabilitySwitch(EnumSourceSearchPort enumInputPort, EnumTmdsHdcpType enumTmdsHdcpType)
{
    enumTmdsHdcpType = enumTmdsHdcpType;

    switch(enumInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            if(enumTmdsHdcpType == _TMDS_HDCP_NONE)
            {
                ScalerTMDSSwitchHdcpSlaveAddr(_D0_INPUT_PORT);
            }

            SET_TMDS_RX0_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            if(enumTmdsHdcpType == _TMDS_HDCP_NONE)
            {
                ScalerTMDSSwitchHdcpSlaveAddr(_D1_INPUT_PORT);
            }

            SET_TMDS_RX1_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Change HDCP Cap
// Input Value  : HDCP Type
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRxAllPortChangeHdcpCap(EnumTmdsHdcpType enumTmdsHdcpType)
{
    switch(enumTmdsHdcpType)
    {
        case _HDCP_BY_PROJECT_DEFINE:

            break;

        case _TMDS_HDCP_14:

            break;

        case _TMDS_HDCP_NONE:

#if(_D0_TMDS_SUPPORT == _ON)
            ScalerTMDSSwitchHdcpSlaveAddr(_D0_INPUT_PORT);
#endif

#if(_D1_TMDS_SUPPORT == _ON)
            ScalerTMDSSwitchHdcpSlaveAddr(_D1_INPUT_PORT);
#endif
            break;

        default:

            break;
    }
}
#endif

#if(_TMDS_CLK_INTERRUPTION_CHECK == _ON)
//--------------------------------------------------
// Description  : ScalerTMDSClkInterruptionCheck
// Input Value  : None
// Output Value : TRUE/FALSE
//--------------------------------------------------
bit ScalerTMDSClkInterruptionCheck(void)
{
    BYTE ucBackup = 0x00;
    WORD usTmdsClockCounter = 0x00;
    WORD usLoopCounter = 0x00;

    // backup HDMI access port Auto Inc Function
    ucBackup = (ScalerGetByte(P2_C8_HDMI_APC) & 0x01);

    if(ScalerGetBit(P0_0C_WATCH_DOG_CTRL0, _BIT3) == _BIT3)
    {
        if(GET_MDOMAIN_V_SCALING_BYPASS_TIMING() == _TRUE)
        {
            EX0 = 0;

            // select TMDS clk to measure
            ScalerSetBit(P2_AD_TMDS_CPS, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

            // disable HDMI access port(CA) Auto Inc Function
            ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, 0x00);

            // expected main loop time ~ 35ms
            while(usLoopCounter < 1500)
            {
                usLoopCounter++;

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT_FW_POLLING)
                if(ScalerGetBit(P0_02_STATUS0, (_BIT6 | _BIT5 | _BIT1 | _BIT0)) != 0x00)
                {
#if(_PANEL_OLED_BACKLIGHT_AC_DET_CONTROL_TYPE == _PANEL_OLED_AC_DET_CTRL_WITHOUT_SEQ)
                    PCB_BACKLIGHT_POWER_PIN(_LIGHT_CONTROL_OFF);
#endif

                    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT5 | _BIT3), (_BIT5));

                    EX0 = 1;

                    ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, ucBackup);

                    return _FALSE;
                }
#endif
                ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_28_PORT_PAGE2_HDMI_NTX1024TR0);
                ScalerSetBit(P2_CA_HDMI_DP, ~_BIT3, _BIT3);

                DELAY_10US();   // for 148.5MHz

                if((ScalerGetByte(P2_CA_HDMI_DP) & _BIT3) == _BIT3)
                {
                    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT5 | _BIT3), (_BIT5));

                    EX0 = 1;

                    ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, ucBackup);

                    return _FALSE;
                }
                else
                {
                    ScalerSetByte(P2_C9_HDMI_AP, _P2_CA_PT_29_PORT_PAGE2_HDMI_NTX1024TR1);
                    usTmdsClockCounter = ScalerGetByte(P2_CA_HDMI_DP);

                    if(abs(usTmdsClockCounter - (BYTE)g_usTMDSClkCount) > 3)
                    {
                        ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT5 | _BIT3), (_BIT5));

                        EX0 = 1;

                        ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, ucBackup);

                        return _FALSE;
                    }
                }
            }

            EX0 = 1;
        }
    }

    ScalerSetBit(P2_C8_HDMI_APC, ~_BIT0, ucBackup);

    return _TRUE;
}
#endif
#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
