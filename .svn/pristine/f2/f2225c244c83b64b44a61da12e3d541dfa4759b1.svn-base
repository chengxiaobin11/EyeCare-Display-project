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
// ID Code      : RL6851_Series_DPRx0.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6851_SERIES_DPRX0__

#include "ScalerFunctionInclude.h"

#if(_D0_DP_EXIST == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#define _DP_DE_ONLY_MODE_WITH_FULL_LAST_LINE_SUPPORT            _ON

//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
bit g_bDpRx0PSAuxToggle = _FALSE;

bit g_bDpRx0FakeLT = _FALSE;
bit g_bDpRx0ValidVideoCheck = _FALSE;
bit g_bDpRx0CrcCalculate = _FALSE;

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
bit g_bDpRx0UrgentLinkLossFlag = _FALSE;
#endif

BYTE g_ucDpRx0LinkStatus01;
BYTE g_ucDpRx0LinkStatus23;
BYTE g_ucDpRx0LinkRequest01;
BYTE g_ucDpRx0LinkRequest23;
BYTE g_ucDpRx0Temp;
BYTE g_pucDpRx0Backup[3];
bit g_bDpRx0AutoInc = _FALSE;
BYTE g_ucDpRx0LinkRate;
BYTE g_ucDpRx0LaneCount;
BYTE g_ucDpRx0TrainingPatternSet;

WORD g_usDpRx0ClockTargetCount;
WORD g_usDpRx0ClockMeasureCount;
BYTE g_pucDpRx0LEFineTune[4];

#if(_DP_WD_REBUILD_PHY_4PART_FOR_UCD400 == _ON)
WORD g_pusLevel0LEErrorCount[4];
WORD g_pusLevel1LEErrorCount[4];
WORD g_pusLevel2LEErrorCount[4];
WORD g_pusLevel3LEErrorCount[4];
#endif

BYTE g_ucRx0AuxTemp;
BYTE g_ucRx0AuxTemp_EXINT;
WORD g_usDpRx0Vfrontporch;

#if(_DP_RX_MI_DONGLE_SUPPORT == _ON)
BYTE g_ucDpRx0FakeLTLaneCount;
BYTE g_ucDpRx0FakeLTLaneCountBackUp;
#endif

StructDpAuxModeSetting g_stDpRxAuxModeSetting;
bit g_bDpHdcpRx0HdcpCpirqFlag = _FALSE;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerDpRx0AuxPowerOnInitial(void);
void ScalerDpRx0AuxModeSetting(void);
void ScalerDpRx0AuxIntInitial(void);
void ScalerDpRx0DpcdInitial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort, EnumFreeSyncSupport enumFreeSyncSupport);
void ScalerDpRx0MacInitial(void);
void ScalerDpRx0PhyInitial(void);
void ScalerDpRx0RebuildPhy(BYTE ucDpLinkRate, BYTE ucDpcdLane);
void ScalerDpRx0PassiveDFEFineTune(void);
void ScalerDpRx0AdjustLaneFLDBand(WORD usVCOBandDiff);
void ScalerDpRx0SetDFEInitial(EnumDpLinkRate enumDpLinkRate);
bit ScalerDpRx0CDRCheck(BYTE ucDpLinkRate, BYTE ucDpcdLane);
bit ScalerDpRx0MeasureLaneCDRClk(BYTE ucDpLinkRate, BYTE ucDpRx0LaneNumber);
void ScalerDpRx0SignalDetectInitial(BYTE ucDpLinkRate, BYTE ucDpLEQScanValue);
void ScalerDpRx0InterlaceReset(void);
WORD ScalerDpRx0SignalDetectMeasureCount(BYTE ucDpLaneSel, EnumDpMeasureTarget enumDpMeasureTarget, EnumDpMeasurePeriod enumDpMeasurePeriod);
bit ScalerDpRx0MeasureInfoCheck(StructDpInfo *pstDpInfo);
bit ScalerDpRx0GetMeasureLinkInfo(StructDpInfo *pstDpInfo);
void ScalerDpRx0SetBsToHsDelay(StructTimingInfo *pstDpTimingInfo);
void ScalerDpRx0SetBsToVsDelay(StructDpInfo *pstDpInfo);
bit ScalerDpRx0DisplayFormatSetting(StructDpInfo *pstDpInfo);

bit ScalerDpRx0StreamClkRegenerate(StructDpLinkInfo *pstDpLinkInfo);
bit ScalerDpRx0TrackingSetting(StructDpInfo *pstDpInfo);
bit ScalerDpRx0SetPLLInputClockSetting(EnumDpLinkRate enumLinkRate, DWORD *pulPllInputClockHz, DWORD ulLinkClockHz);
bit ScalerDpRx0SetPLLFreqNf(DWORD ulPllTargetClockHz, DWORD ulPllInputClockHz);
void ScalerDpRx0SetPLLNfOffProc(DWORD ulPllVcoClockHz, BYTE ucNcode, BYTE ucpllo, BYTE ucdivs);
bit ScalerDpRx0SetPLLNfOnProc(BYTE ucNcode, BYTE ucFcode_MSB4b, WORD usFcode_LSB16b, bit bPllVcoHighFreqStatus);
void ScalerDpRx0SetPLLPGainClampValue(BYTE ucPGainB3, BYTE ucPGainB2, BYTE ucPGainB1);

void ScalerDpRx0AdjustVsyncDelay(void);
bit ScalerDpRx0HdcpMeasureCheck(void);
void ScalerDpRx0PhyCtsTp1SetPhy(EnumDpNFCodeRef enumDpNFCodeRef);
void ScalerDpRx0PhyCtsTp2SetPhy(void);
bit ScalerDpRx0PhyCtsTp1Check(void);
void ScalerDpRx0PhyCTS(void);

bit ScalerDpRx0NormalPreDetect(void);
BYTE ScalerDpRx0ScanInputPort(void);
bit ScalerDpRx0StableDetect(void);

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
bit ScalerDpRx0LinkStatusLoss(void);
#endif

bit ScalerDpRx0TimerDelayXmsLinkCheck(WORD usNum);
bit ScalerDpRx0PollingFlagLinkCheck(WORD usTimeout, WORD usRegister, BYTE ucBit, bit bSuccess);
void ScalerDpRx0SetHotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
StructDpRxErrorCount ScalerDpRx0GetErrorCount(void);

#if(_AIO_MODERN_STANDBY_SUPPORT == _ON)
void ScalerDpRx0TimingInfoBackup(void);
#endif

#if(_DP_BS_MISS_DETECT_IRQ_WD_SUPPORT == _ON)
void ScalerDpRx0SetBsMissDetectIRQ(bit bEn);
void ScalerDpRx0SetBsMissDetectTrackingWD(bit bEn);
bit ScalerDpRx0CheckBsStatus(void);
#endif

#if(_DP_8B10B_DEC_ERROR_WD_SUPPORT == _ON)
void ScalerDpRx0Set8b10bDecErrorWD(bit bEn);
bit ScalerDpRx0Check8b10bDecErrorStatus(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initial Setting for DP Digital Aux, Analog Aux
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0AuxPowerOnInitial(void)
{
    BYTE ucConnectorType = ScalerSyncDpRxGetConnectorType(GET_DP_EMBEDDED_SWITCH_SELECT());

    if(ucConnectorType == _DP_CONNECTOR_EMBEDDED)
    {
        // Reset Aux Phy
        ScalerSetBit(PB7_65_AUX_5, ~_BIT7, 0x00);
    }

    // Get Aux Mode & Setting
    ScalerDpRx0AuxModeSetting();

    // Digital Aux Power On, DPCD REG Power On
    ScalerSetBit(PB7_C0_DPCD_CTRL, ~(_BIT7 | _BIT5 | _BIT1 | _BIT0), 0x00);

    // Average 8 cycles as Start Postion, Aux Clk Select to 27MHz, no Swap
    ScalerSetByte(PB7_72_AUX_DIG_PHY2, 0xC0);

#if(_DP_AUX_REPLY_CLK_SEL_FROM == _DP_AUX_REPLY_SEL_IOSC)
    // Aux Clk Select Manual Mode, Aux New Mode
    ScalerSetBit(PB7_73_AUX_DIG_PHY3, ~(_BIT7 | _BIT6), _BIT6);
#else
    // Aux Clk Select Source, Aux New Mode
    ScalerSetBit(PB7_73_AUX_DIG_PHY3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
#endif

    // HW Fake Link Training Disable.
    ScalerSetBit(PB7_C6_AUX_PHY_DIG2, ~_BIT4, 0x00);

    // Set Aux Precharge Number.
    ScalerSetBit(PB7_74_AUX_DIG_PHY4, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));

    // Aux Auto Mode, Using Default Average Number.
    ScalerSetByte(PB7_75_AUX_DIG_PHY5, 0x0D);

    // Aux Reply Timeout Setting
    ScalerSetByte(PB7_A2_AUX_TIMEOUT_TARGET, _DP_AUX_REPLY_TIMEOUT_USER_SETTING);

    // Enble Aux Channel.
    ScalerSetBit(PB7_D0_AUX_MODE_SET, ~(_BIT3 | _BIT2 | _BIT0), _BIT0);

    // Fast IIC Clock.
    ScalerSetBit(PB7_D1_DP_IIC_SET, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_DP_AUX_IIC_SCL_CLK_SETTING << 4));

    // Set aux mac clk use xclk
    ScalerSetBit(PB7_DA_AUX_FIFO_RST, ~(_BIT4 | _BIT3 | _BIT1 | _BIT0), _BIT3);

    // Not Reply when Aux Error.
    ScalerSetBit(PB7_DB_AUX_STATUS, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(PB7_76_AUX_DIG_PHY6, ~(_BIT7 | _BIT6), _BIT6);

    // Disable other DPCD, Aux Timeout, Receiving Aux INT.
    ScalerSetBit(PB7_DC_AUX_IRQ_STATUS, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

    // Disable Aux Phy Int
    ScalerSetBit(PB7_77_AUX_DIG_PHY7, ~(_BIT7 | _BIT6), 0x00);

    // Aux Ack Timer.
    ScalerSetBit(PB7_F0_AUX_TX_TIMER, ~(_BIT5 | _BIT2), (_BIT5 | _BIT2));

    // I2C timeout setting
    ScalerSetByte(PB7_F1_AUX_TX_TIMER_2, _DP_AUX_I2C_REPLY_TIMEOUT_SETTING);

    // Disable Reply IIC Defer Before Data Ready.
    ScalerSetBit(PB7_F4_MCUIIC, ~(_BIT6 | _BIT5), 0x00);

    // Enable Aux Error Handler.
    ScalerSetBit(PB7_78_AUX_DIG_PHY8, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4));

    if(ucConnectorType != _DP_CONNECTOR_EMBEDDED)
    {
        // Toggle Aux Auto K
        ScalerSetBit(PB7_65_AUX_5, ~_BIT7, 0x00);
        ScalerSetBit(PB7_65_AUX_5, ~_BIT7, _BIT7);
    }

    // Aux Mode Set (Diff Mode or Single-ended mode) && Aux RX0 Resistance Setting
    ScalerDpRx0AuxSet();

    // Set Aux Talk Mode ADJR
    ScalerSetByte(PB7_67_DIG_TX_03, 0x17);
    ScalerSetByte(PB7_6F_DIG_TX_02, 0x17);

    // RL6851 remove single ended mode
    // ScalerSetBit(PB7_60_DIG_TX_04, ~(_BIT1 | _BIT0), _BIT0);

    if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT)
    {
#if(_D0_AUX_DDC_CHANNEL == _D0_AUX_MAP_DDC0_PIN)
        // Enable Aux Channel 0, Disable Channel 1
        ScalerSetBit(PB7_60_DIG_TX_04, ~(_BIT7 | _BIT6), _BIT7);
        // Aux Mapping to DDC0
        ScalerSetBit(P6F_09_AUX_MAP_DDC, ~(_BIT1 | _BIT0), 0x00);
#elif(_D0_AUX_DDC_CHANNEL == _D0_AUX_MAP_DDC1_PIN)
        // Enable Aux Channel 1, Disable Channel 0
        ScalerSetBit(PB7_60_DIG_TX_04, ~(_BIT7 | _BIT6), _BIT6);
        // Aux Mapping to DDC1
        ScalerSetBit(P6F_09_AUX_MAP_DDC, ~(_BIT1 | _BIT0), _BIT0);
#endif
    }
    else if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
    {
#if(_D1_AUX_DDC_CHANNEL == _D1_AUX_MAP_DDC0_PIN)
        // Enable Aux Channel 0, Disable Channel 1
        ScalerSetBit(PB7_60_DIG_TX_04, ~(_BIT7 | _BIT6), _BIT7);
        // Aux Mapping to DDC0
        ScalerSetBit(P6F_09_AUX_MAP_DDC, ~(_BIT1 | _BIT0), 0x00);
#elif(_D1_AUX_DDC_CHANNEL == _D1_AUX_MAP_DDC1_PIN)
        // Enable Aux Channel 1, Disable Channel 0
        ScalerSetBit(PB7_60_DIG_TX_04, ~(_BIT7 | _BIT6), _BIT6);
        // Aux Mapping to DDC1
        ScalerSetBit(P6F_09_AUX_MAP_DDC, ~(_BIT1 | _BIT0), _BIT0);
#endif
    }

    // Delay 100ms for Aux Common Mode Voltage Stable, To Avoid Swing Couple to Aux Cabledetect
    ScalerTimerDelayXms(100);

    // Set Aux D_2 = ~D_1 for Aux Single Ended Mode
    ScalerSetBit(PB7_79_AUX_DIG_PHY9, ~_BIT7, _BIT7);

    // Clear the Clock Divider for AUX MAC and PHY
    ScalerSetBit(PB7_73_AUX_DIG_PHY3, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(PB7_B0_AUX_MAC_REF_CLK, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Aux ps clk from IOSC
    ScalerSetBit(P0_0B_POWER_CTRL, ~(_BIT5 | _BIT4), 0x00);

    // Set the Clock Divider = 1 for AUX MAC and PHY
    ScalerSetBit(PB7_73_AUX_DIG_PHY3, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
    ScalerSetBit(PB7_B0_AUX_MAC_REF_CLK, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
}

//--------------------------------------------------
// Description  : Setting Otp Value For Aux
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0AuxModeSetting(void)
{
    BYTE ucDpRxAuxModeSetting = 0;

    if(ScalerGlobalGetIDCode() == _RL6851_VER_A_ID_CODE)
    {
        g_stDpRxAuxModeSetting.enumDpAuxMode = _DP_AUX_RX1_MODE;

        g_stDpRxAuxModeSetting.enumDpAuxVth = _DP_AUX_VTH_25MV;

        g_stDpRxAuxModeSetting.b4DpAuxAdjr = 1;
    }
    else
    {
        // Get OTP Setting
        ScalerEfuseGetData(_OTPMEMORY_DP_AUX_RX_MODE, 1, &ucDpRxAuxModeSetting);

        g_stDpRxAuxModeSetting.enumDpAuxMode = _DP_AUX_RX2_MODE;

        // Set Vth
        switch(ucDpRxAuxModeSetting & (_BIT1 | _BIT0))
        {
            default:
            case (_BIT1 | _BIT0):
                g_stDpRxAuxModeSetting.enumDpAuxVth = _DP_AUX_VTH_75MV;
                break;

            case _BIT1:
                g_stDpRxAuxModeSetting.enumDpAuxVth = _DP_AUX_VTH_100MV;
                break;

            case _BIT0:
                g_stDpRxAuxModeSetting.enumDpAuxVth = _DP_AUX_VTH_25MV;
                break;

            case 0:
                g_stDpRxAuxModeSetting.enumDpAuxVth = _DP_AUX_VTH_50MV;
                break;
        }

        ucDpRxAuxModeSetting = ((ucDpRxAuxModeSetting) >> 4) & 0x0F;

        if(ucDpRxAuxModeSetting == 0x00)
        {
            // adjr cannot be 0
            g_stDpRxAuxModeSetting.b4DpAuxAdjr = 1;
        }
        else
        {
            g_stDpRxAuxModeSetting.b4DpAuxAdjr = ucDpRxAuxModeSetting;
        }
    }
}

//--------------------------------------------------
// Description  : Initial Setting for DP Aux INT
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0AuxIntInitial(void)
{
    // Enable 068xxx INT
    ScalerSetBit(PB7_DA_AUX_FIFO_RST, ~(_BIT4 | _BIT1 | _BIT0), _BIT1);
    ScalerSetBit(PB7_DA_AUX_FIFO_RST, ~(_BIT4 | _BIT2 | _BIT1 | _BIT0), _BIT2);

    // Clear flag for Write AKSV int
    ScalerSetBit(PB7_A5_AUX_HDCP_IRQ2, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);

    // Enable Write AKSV int
    ScalerSetBit(PB7_A5_AUX_HDCP_IRQ2, ~_BIT6, _BIT6);

    // Disable other DPCD, Aux Timeout, Receiving Aux INT.
    ScalerSetBit(PB7_DC_AUX_IRQ_STATUS, ~(_BIT5 | _BIT3 | _BIT2), 0x00);

    // Disable Aux Phy Int
    ScalerSetBit(PB7_77_AUX_DIG_PHY7, ~_BIT7, 0x00);

    // Enable DPCD INT
    ScalerSetByte(PB7_DE_AUX_DPCD_IRQ_EN, 0xE5);

    // I2c slave addr 50 Interrupt
    ScalerSetByte(PB7_F3_IIC_SLAVE_ADD, 0xA1);

    // Internal IRQ Enable (Global)
    ScalerGlobalIRQControl(_ENABLE);

    // Disable Wildcard IRQ for Error Counter
    ScalerSetBit(PB7_FB_DP0_MANUAL_DPCD_IRQ, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1 | _BIT0), 0x00);

    // Use Wildcard 0 to DPCD 0x022xxh, LSB 8 Bits Discarded
    ScalerSetByte(PB7_B4_AUX_IRQ_ADDR0_MSB, 0x30);
    ScalerSetByte(PB7_B5_AUX_IRQ_ADDR0_MSB1, 0x22);
    ScalerSetByte(PB7_B6_AUX_IRQ_ADDR0_LSB, 0x00);

    // Use Wildcard 3 to DPCD 0x0021xh, LSB 4 Bits Discarded
    ScalerSetByte(PB7_BD_AUX_IRQ_ADDR3_MSB, 0x10);
    ScalerSetByte(PB7_BE_AUX_IRQ_ADDR3_MSB1, 0x02);
    ScalerSetByte(PB7_BF_AUX_IRQ_ADDR3_LSB, 0x10);

    // Enable INT0
    EX0 = 1;
}

//--------------------------------------------------
// Description  : DPCD Table Initial
// Input Value  : _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0DpcdInitial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort, EnumFreeSyncSupport enumFreeSyncSupport)
{
    enumFreeSyncSupport = enumFreeSyncSupport;

    ScalerDpRx0SinkStatusSet(_DP_SINK_REVEICE_PORT0, _DP_SINK_OUT_OF_SYNC);
    ScalerDpRx0SinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_OUT_OF_SYNC);

    if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _D0_DP_LINK_CLK_RATE);
#endif
    }
    else if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
    {
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _D1_DP_LINK_CLK_RATE);
#endif
    }

    ScalerDpRx0ChangeDpcdVersion(enumDpVersion, enumDpRxMstPort);

    // Enhanced Framing Support(Bit7) and DP Lane Count(Bit[4:0])
    pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x02);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x02, ((pData[0] & ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) | _BIT7 | enumDpLaneCount));

#if(_DP_RX_MI_DONGLE_SUPPORT == _ON)
    g_ucDpRx0FakeLTLaneCount = (enumDpLaneCount & 0x1F);
    g_ucDpRx0FakeLTLaneCountBackUp = (enumDpLaneCount & 0x1F);
#endif

    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x03, 0x01);

#if(_AUDIO_SUPPORT == _ON)
    if(ScalerAudioDpGetCapabilityState(_D0_INPUT_PORT) == _AUDIO_DP_DPCD_SUPPORT)
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x04, 0x01);
    }
    else
#endif
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x04, 0x00);
    }

    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x05, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x06, 0x01);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x08, 0x02);

#if(_EIZO_CUSTOMIZED_VALUE_OF_DPCD_SUPPORT == _OFF)
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x09, 0x00);
#endif

#if(_AUDIO_SUPPORT == _ON)
    if(ScalerAudioDpGetCapabilityState(_D0_INPUT_PORT) == _AUDIO_DP_DPCD_SUPPORT)
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0A, 0x06);
    }
    else
#endif
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0A, 0x00);
    }

    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0B, 0x00);

    if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT)
    {
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DP_ASSR_MODE_SUPPORT == _ON))
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0D, 0x01);

        SET_DP_RX0_AUX_MANUAL_MODE();
        ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x0A, 0x00);
        SET_DP_RX0_AUX_AUTO_MODE();
#endif
    }
    else if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
    {
#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DP_ASSR_MODE_SUPPORT == _ON))
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0D, 0x01);

        SET_DP_RX0_AUX_MANUAL_MODE();
        ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x0A, 0x00);
        SET_DP_RX0_AUX_AUTO_MODE();
#endif
    }

    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x21, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x80, 0x00);

    // Coding Type Reset 8B10B
    SET_DP_RX0_AUX_MANUAL_MODE();
    ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x08, 0x01);
    SET_DP_RX0_AUX_AUTO_MODE();

    // DPCD Link Status Field Setting
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, 0x41);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x01, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x05, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x08, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x09, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x0A, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x0B, 0x00);

#if(_DP_CRC_TEST_VISUAL_CHECK == _ON)
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x46, 0x00);
#else
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x46, 0x20);
#endif

    // Initialize Reserved to 0
    ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x10, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x12, 0x00);

    // DPCD Initial Power Normal
    SET_DP_RX0_AUX_MANUAL_MODE();
    ScalerDpRx0SetDpcdBitValue(0x00, 0x06, 0x00, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
    SET_DP_RX0_AUX_AUTO_MODE();

    ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x28, 0x01);

#if(_DP_FREESYNC_SUPPORT == _ON)
    switch(GET_DP_EMBEDDED_SWITCH_SELECT())
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            SET_DP_RX0_FREESYNC_SUPPORT(enumFreeSyncSupport);

            if(GET_DP_RX0_FREESYNC_SUPPORT() == _FREESYNC_SUPPORT_ON)
            {
                ScalerDpRx0SetDpcdBitValue(0x00, 0x00, 0x07, ~_BIT6, _BIT6);
            }
            else
            {
                ScalerDpRx0SetDpcdBitValue(0x00, 0x00, 0x07, ~_BIT6, 0x00);
            }

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            SET_DP_RX1_FREESYNC_SUPPORT(enumFreeSyncSupport);

            if(GET_DP_RX1_FREESYNC_SUPPORT() == _FREESYNC_SUPPORT_ON)
            {
                ScalerDpRx0SetDpcdBitValue(0x00, 0x00, 0x07, ~_BIT6, _BIT6);
            }
            else
            {
                ScalerDpRx0SetDpcdBitValue(0x00, 0x00, 0x07, ~_BIT6, 0x00);
            }

            break;
#endif

        default:
            break;
    }
#endif

    // AAR Mode Reset 0
    SET_DP_RX0_AUX_MANUAL_MODE();
    ScalerDpRx0SetDpcdValue(0x0F, 0xFF, 0xFF, 0x00);
    SET_DP_RX0_AUX_AUTO_MODE();
}

//--------------------------------------------------
// Description  : Dp Mac Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0MacInitial(void)
{
    // Set Digital Phy to Normal
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

    // err_8b10b_ctrl_gate = 1'b1 --> Avoid 8b10b Error Decode to FS
    ScalerSetBit(PB_00_HD_DP_SEL, ~(_BIT1 | _BIT0), _BIT1);

    // DP RGB Output Enable
    ScalerSetBit(PB5_31_DP_OUTPUT_CTRL, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // DP CLK Output Enable
    ScalerSetBit(PB5_A2_PLL_OUT_CONTROL, ~_BIT7, _BIT7);

    // 0x00:disable error correction, 0xF4:enable all error correction
    ScalerSetBit(PB6_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), _BIT1);

#if(_DP_BS_MISS_DETECT_IRQ_WD_SUPPORT == _ON)
    // Disable DP BS Detect IRQ and Tracking WD
    ScalerDpRx0SetBsMissDetectTrackingWD(_DISABLE);
    ScalerDpRx0SetBsMissDetectIRQ(_DISABLE);
#endif

#if(_DP_8B10B_DEC_ERROR_WD_SUPPORT == _ON)
    // Disable DP 8b10b Dec Err WD
    ScalerDpRx0Set8b10bDecErrorWD(_DISABLE);
#endif

    // Disable DP Fifo Under/OverFlow Watch Dog
    ScalerDpRx0SetFifoWD(_DISABLE);

    // Disable DP Fifo Under/OverFlow IRQ
    ScalerDpRx0SetFifoIRQ(_DISABLE);

    // Disable DP No Video Stream IRQ
    ScalerDpRx0SetNoVideoStreamIRQ(_DISABLE);

    ScalerDpRx0SetInitialRSV0InfoType();

    CLR_DP_RX0_MSA_FAIL_MAC_RESET_COUNT();
}

//--------------------------------------------------
// Description  : DP Phy Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyInitial(void)
{
    // [7:6] CMU_SEL_CP = 2'b00 --> CMU LPF Cp = 0pF
    // [5] Always Set to 1 for PFD Deglitch Function Bug
    ScalerSetBit(PB_C5_CMU_03, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // [2:0] rate_sel = 3'b001 --> 1.5~3Gbps
    ScalerSetBit(PB_DC_TMDS_CONT_1, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

    // [1:0] SEL_DIV = 2'b00 --> 1.5~3Gbps
    ScalerSetBit(PB_C2_CCO, ~(_BIT1 | _BIT0), 0x00);

    // [6:4] sel_cdr_res = 3'b011 --> 1.6K Ohm
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));

    // [3:0] cdr_cp_in = 4'b1000 --> 27uA
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);
}

//--------------------------------------------------
// Description  : Rebuilding DP PHY
// Input Value  : DPCD Bit Rate and Lane Count
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0RebuildPhy(BYTE ucDpLinkRate, BYTE ucDpcdLane)
{
    BYTE ucD0Z0Status = 0;
    BYTE ucD1Z0Status = 0;
    WORD usVCOBandDiff = 0;
    WORD usVCOBandScan = 0;
    WORD usVCOAutoBand = 0;
    BYTE ucIcp = (ScalerGetByte(PB_D2_ANA_CDR_03) & 0x0F);


    ////////////////////
    // Mode Select DP //
    ////////////////////

    // Backup Z0 Status
    ucD0Z0Status = ScalerGetBit(PB_B3_IMPEDANCE_00, (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    ucD1Z0Status = ScalerGetBit(PB_B4_IMPEDANCE_01, (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Disable Z0
    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // [5] dp_mode = 1'b1 --> Select DP Mode
    ScalerSetBit(PB_B1_PORT_SEL, ~_BIT5, _BIT5);

    // [0] hd_dp_sel = 1'b0 --> Select DP
    ScalerSetBit(PB_00_HD_DP_SEL, ~_BIT0, 0x00);

    // [3] PSM = 1'b0 --> Disable Clock Switch
    ScalerSetBit(PB_B0_CLK_DET, ~_BIT3, 0x00);

    // [6] reg_bypass_ok = 1'b0 --> Disable bypass ok
    ScalerSetBit(PB_C9_KOFFSET_02, ~_BIT6, 0x00);

    // Restore Z0 Status
    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucD0Z0Status);
    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucD1Z0Status);


    /////////////////////////////
    // MAC Lane Swap Selection //
    /////////////////////////////

    // DP Lane Swap Setting
    ScalerSetBit(PB_03_LANE_MUX, ~(_BIT7 | _BIT6), _D0_DP_LANE3 << 6);
    ScalerSetBit(PB_03_LANE_MUX, ~(_BIT5 | _BIT4), _D0_DP_LANE2 << 4);
    ScalerSetBit(PB_03_LANE_MUX, ~(_BIT3 | _BIT2), _D0_DP_LANE1 << 2);
    ScalerSetBit(PB_03_LANE_MUX, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

    // DP Lane PN Swap Setting
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~_BIT7, GET_DP_RX0_PCB_LANE3_PN_SWAP() << 7);
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~_BIT6, GET_DP_RX0_PCB_LANE2_PN_SWAP() << 6);
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~_BIT5, GET_DP_RX0_PCB_LANE1_PN_SWAP() << 5);
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~_BIT4, GET_DP_RX0_PCB_LANE0_PN_SWAP() << 4);


    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////

    // [2] cmu_en = 1'b0 --> Lane3 CMU Disable
    ScalerSetBit(PB_B0_CLK_DET, ~_BIT2, 0x00);

    // Disable RX_EN, CDR_EN
    ScalerSetByte(PB_B2_ENABLE, 0x00);

    // Enable RX_EN
    ScalerSetBit(PB_B2_ENABLE, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    switch(ucDpcdLane & 0x1F)
    {
        case _DP_ONE_LANE:

            // dp_bbpd_sel[5:4] --> ACDR BBPD UP/DN from MAC Lane0
            ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), GET_DP_RX0_PCB_LANE0_MAPPING() << 4);

            if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0)
            {
                // Enable Lane0 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT0, _BIT0);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1)
            {
                // Enable Lane1 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT1, _BIT1);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2)
            {
                // Enable Lane2 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT2, _BIT2);
            }

            // [4:3] DP MAC Select One Lane
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), _BIT3);

            break;

        case _DP_TWO_LANE:

            if((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3) || (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3))
            {
                // dp_bbpd_sel[5:4] = 2'b11 --> ACDR BBPD UP/DN from Lane3
                ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
            }
            else
            {
                // dp_bbpd_sel[5:4] --> ACDR BBPD UP/DN from MAC Lane0
                ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), GET_DP_RX0_PCB_LANE0_MAPPING() << 4);
            }

            if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0)
            {
                // Enable Lane0 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT0, _BIT0);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1)
            {
                // Enable Lane1 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT1, _BIT1);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2)
            {
                // Enable Lane2 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT2, _BIT2);
            }

            if(GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0)
            {
                // Enable Lane0 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT0, _BIT0);
            }
            else if(GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1)
            {
                // Enable Lane1 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT1, _BIT1);
            }
            else if(GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2)
            {
                // Enable Lane2 CDR_EN for DCDR
                ScalerSetBit(PB_B2_ENABLE, ~_BIT2, _BIT2);
            }

            // [4:3] DP MAC Select Two Lane
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), _BIT4);

            break;

        case _DP_FOUR_LANE:
        default:

            // dp_bbpd_sel[5:4] = 2'b11 --> ACDR BBPD UP/DN from Lane3
            ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

            // Enable Lane0/1/2 CDR_EN for DCDR
            ScalerSetBit(PB_B2_ENABLE, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
            ScalerSetBit(PB_B2_ENABLE, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
            ScalerSetBit(PB_B2_ENABLE, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // [4:3] DP MAC Select Four Lane
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

            break;
    }

    // Enable Lane3 CDR_EN for BBPD
    ScalerSetBit(PB_B2_ENABLE, ~_BIT3, _BIT3);

    // ln_clk_func_sel[1:0] --> MAC Clock from Analog CDR Lane
    ScalerSetBit(PB_96_LINK_CLOCK_SELECT, ~(_BIT1 | _BIT0), (ScalerGetBit(PB_D1_ANA_CDR_02, (_BIT5 | _BIT4)) >> 4));

    // Delay Time us [25,x]
    DELAY_25US();

    // Enable Analog CDR and FLD
    ScalerSetBit(PB_AF_ANA_CDR_TIMER, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

    // Enable CCO LDO
    ScalerSetBit(PB_C2_CCO, ~_BIT7, _BIT7);


    ///////////////////////
    // Frequency Setting //
    ///////////////////////

    // [7] xtal_en = 1'b1 --> FLD using xtal as reference clock
    ScalerSetBit(PB_D1_ANA_CDR_02, ~_BIT7, _BIT7);

#if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_200M) // GDI Clock = 28.6M
    switch(ucDpLinkRate)
    {
        // 26/492 = 5*(28.6M/2.7G)
        case _DP_LINK_HBR:

            g_usDpRx0ClockTargetCount = 0x1270; // ideal 2.7G

            // ref_conuter = 26
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x19);

            // cdr_counter = 491
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xEA);

            break;

        // 43/487 = 5*(28.6M/1.62G)
        case _DP_LINK_RBR:
        default:

            g_usDpRx0ClockTargetCount = 0xB10; // ideal 1.62G

            // ref_conuter = 43
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x2A);

            // cdr_counter = 499
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xE6);

            break;
    }
#elif((_M2PLL_FREQ_SEL == _M2PLL_FREQ_189M) || (_M2PLL_FREQ_SEL == _M2PLL_FREQ_216M)) // GDI Clock = 27M
    switch(ucDpLinkRate)
    {
        // 25/500 = 5*(27M/2.7G)
        case _DP_LINK_HBR:

            g_usDpRx0ClockTargetCount = 0x1388; // ideal 2.7G

            // ref_conuter = 25
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x18);

            // cdr_counter = 500
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xF4);

            break;

        // 40/480 = 5*(27M/1.62G)
        case _DP_LINK_RBR:
        default:

            g_usDpRx0ClockTargetCount = 0xBB8; // ideal 1.62G

            // ref_conuter = 40
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x27);

            // cdr_counter = 480
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xE0);

            break;
    }
#elif(_M2PLL_FREQ_SEL == _M2PLL_FREQ_220M) // GDI Clock = 27.5M
    switch(ucDpLinkRate)
    {
        // 25/491 = 5*(27.5M/2.7G)
        case _DP_LINK_HBR:

            g_usDpRx0ClockTargetCount = 0x132D; // ideal 2.7G

            // ref_conuter = 25
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x18);

            // cdr_counter = 491
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xEB);

            break;

        // 32/377 = 5*(27.5M/1.62G)
        case _DP_LINK_RBR:
        default:

            g_usDpRx0ClockTargetCount = 0xB81; // ideal 1.62G

            // ref_conuter = 32
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x1F);

            // cdr_counter = 377
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0x79);

            break;
    }
#endif

    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // Enable Comma Detection
    ScalerSetBit(PB_05_SAMPLE_EDGE, ~_BIT4, 0x00);

    if((ucDpcdLane & _BIT7) == _BIT7)
    {
        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, _BIT2);
    }
    else
    {
        // Disable Enhancement Control Mode --> MAC
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, 0x00);
    }

    if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x02) & _BIT5) == _BIT5)
    {
        // Disable Scrambling
        ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);
    }
    else
    {
        // Enable Scrambling
        ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, 0x00);
    }

    // [1] bypass_clk_rdy = 1'b1 --> Clk Rdy Signal in Manual Mode
    // [0] en_clkout_manual = 1'b1 --> Enable Clkout
    ScalerSetBit(PB_AB_SDM_04, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

    // [1] bypass_eqen_rdy = 1'b1 --> EQEN Rdy Signal in Manual Mode
    // [0] en_eqen_manual = 1'b1 --> Enable EQ
    ScalerSetBit(PB_AD_EQEN_TIMER, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

    // [1] bypass_data_rdy = 1'b1 --> Data Rdy Signal in Manual Mode
    // [0] en_data_manual = 1'b0 --> Disable Dataout
    ScalerSetBit(PB_AE_DATA_TIMER, ~(_BIT1 | _BIT0), _BIT1);

    // [3] reg_en_data_manual_l3 = 1'b0 --> Disable Data Ready
    // [2] reg_bypass_data_rdy_l3 = 1'b1 --> Data Ready Signal in Manual Mode
    // [1] reg_en_eqen_manual_l3 = 1'b1 --> Enable EQ
    // [0] reg_bypass_eqen_rdy_l3 = 1'b1 --> EQ Ready Signal in Manual Mode
    ScalerSetBit(PB_AF_ANA_CDR_TIMER, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // Digital Circuit Reset Toggle
    ScalerSetByte(PB_DA_TMDS_RESET, 0x00);

    switch(ucDpcdLane & 0x1F)
    {
        case _DP_ONE_LANE:

            if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0)
            {
                // Enable Lane0 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT7, _BIT7);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1)
            {
                // Enable Lane1 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT6, _BIT6);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2)
            {
                // Enable Lane2 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT5, _BIT5);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3)
            {
                // Enable Lane3 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT4, _BIT4);
            }

            break;

        case _DP_TWO_LANE:

            if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0)
            {
                // Enable Lane0 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT7, _BIT7);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1)
            {
                // Enable Lane1 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT6, _BIT6);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2)
            {
                // Enable Lane2 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT5, _BIT5);
            }
            else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3)
            {
                // Enable Lane3 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT4, _BIT4);
            }

            if(GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0)
            {
                // Enable Lane0 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT7, _BIT7);
            }
            else if(GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1)
            {
                // Enable Lane1 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT6, _BIT6);
            }
            else if(GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2)
            {
                // Enable Lane2 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT5, _BIT5);
            }
            else if(GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3)
            {
                // Enable Lane3 DPHY
                ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT4, _BIT4);
            }

            // [3] cdr_rst_n_lane0 = CDR_EN[0]
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT3, (ScalerGetBit(PB_B2_ENABLE, _BIT0) << 3));

            // [2] cdr_rst_n_lane1 = CDR_EN[1]
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT2, (ScalerGetBit(PB_B2_ENABLE, _BIT1) << 1));

            // [1] cdr_rst_n_lane2 = CDR_EN[2]
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT1, (ScalerGetBit(PB_B2_ENABLE, _BIT2) >> 1));

            if((GET_DP_RX0_PCB_LANE0_MAPPING() != _DP_SCALER_LANE3) && (GET_DP_RX0_PCB_LANE1_MAPPING() != _DP_SCALER_LANE3))
            {
                if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0)
                {
                    // [3] cdr_rst_n_lane0 = 0 --> Disable DCDR Lane0
                    ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT3, 0x00);
                }
                else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1)
                {
                    // [2] cdr_rst_n_lane1 = 0 --> Disable DCDR Lane1
                    ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT2, 0x00);
                }
                else if(GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2)
                {
                    // [1] cdr_rst_n_lane2 = 0 --> Disable DCDR Lane2
                    ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT1, 0x00);
                }
            }

            break;

        case _DP_FOUR_LANE:
        default:

            // [7:4] rst_n_lane0~3 = 4'b1111
            // [3:0] cdr_rst_n_lane0~3 = 4'b1110
            ScalerSetByte(PB_DA_TMDS_RESET, 0xFE);

            break;
    }


    /////////////////
    // CDR Setting //
    /////////////////

    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR:

            // [3:0] cdr_kvco = 4'b1010
            ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

            // Lane0~2 KP = 4
            ScalerSetByte(PB_F6_CDR_07, 0x10);
            ScalerSetByte(PB_F7_CDR_08, 0x10);
            ScalerSetByte(PB_F8_CDR_09, 0x10);

            // [6] en_cco_lp_mode = 0
            ScalerSetBit(PB_C2_CCO, ~_BIT6, 0x00);

            break;

        case _DP_LINK_RBR:
        default:

            // [3:0] cdr_kvco = 4'b1000 (Default)
            ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);

            // Lane0~2 KP = 8
            ScalerSetByte(PB_F6_CDR_07, 0x20);
            ScalerSetByte(PB_F7_CDR_08, 0x20);
            ScalerSetByte(PB_F8_CDR_09, 0x20);

            // [6] en_cco_lp_mode = 1
            ScalerSetBit(PB_C2_CCO, ~_BIT6, _BIT6);

            break;
    }


    ////////////////
    // EQ Setting //
    ////////////////

    // [4:0] reg_fore_off_adjr_Lane0~3 = 5'b10000
    ScalerSetBit(PB_CB_KOFFSET_04, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    ScalerSetBit(PB_CC_KOFFSET_05, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    ScalerSetBit(PB_CD_KOFFSET_06, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    ScalerSetBit(PB_CE_KOFFSET_07, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);

    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR:

            // [7:5] le_lowgain_highboost = 1'b1 --> Enable LE High-boost Mode
            ScalerSetBit(PB_CC_KOFFSET_05, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

            // [7:5] le_isel = 3'b010 --> LE Peaking = 1.7Gbps
            ScalerSetBit(PB_CD_KOFFSET_06, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

            // [7:5] le_rlsel = 3'b001 --> LE Peaking = 1.7Gbps
            ScalerSetBit(PB_CE_KOFFSET_07, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

            break;

        case _DP_LINK_RBR:
        default:

            // [7] le_lowgain_highboost = 1'b0 --> Disable LE High-boost Mode
            ScalerSetBit(PB_CC_KOFFSET_05, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

            // [7:5] le_isel = 3'b000 --> LE Peaking = 900Mbps
            ScalerSetBit(PB_CD_KOFFSET_06, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

            // [7:5] le_rlsel = 3'b011 --> LE Peaking = 900Mbps
            ScalerSetBit(PB_CE_KOFFSET_07, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));

            break;
    }

    // Set DFE Initial
    ScalerDpRx0SetDFEInitial(ucDpLinkRate);

    // [7] en_fore_offset = 1'b0 --> Disable EQ foreground Offset Calibration
    // [6] fore_off_autok = 1'b1 --> Enable EQ foreground Offset Calibration Auto Mode
    ScalerSetBit(PB_C8_KOFFSET_01, ~(_BIT7 | _BIT6), _BIT6);

    // Toggle en_fore_offset
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, 0x00);
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);

    // Delay Time ~ 50us
    for(pData[0] = 0; pData[0] <= 20; pData[0]++)
    {
        DELAY_5US();

        if(((ScalerGetBit(PB_DA_TMDS_RESET, _BIT7) == 0x00) || (ScalerGetBit(PB_C7_KOFFSET_00, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT6) == 0x00) || (ScalerGetBit(PB_C8_KOFFSET_01, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT5) == 0x00) || (ScalerGetBit(PB_C9_KOFFSET_02, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT4) == 0x00) || (ScalerGetBit(PB_CA_KOFFSET_03, _BIT5) == _BIT5)))
        {
            break;
        }
    }


    ///////////////////
    // FLD Auto Mode //
    ///////////////////

    // Set FLD Auto Mode
    ScalerSetBit(PB_CF_ANA_CDR_00, ~_BIT7, _BIT7);

    // [2] cp_en_manual = 1'b0 --> CDR Open Loop
    // [1] adp_en_manual = 1'b0 --> Disable CDR Clock
    ScalerSetBit(PB_D0_ANA_CDR_01, ~(_BIT2 | _BIT1), 0x00);

    // [7] rstb_fld --> Reset Timer of Analog CDR
    // [6] rstb_fsm --> FLD Reset
    ScalerSetBit(PB_D3_ANA_CDR_04, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit(PB_D3_ANA_CDR_04, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Delay Time ~300us for HBR
    for(pData[0] = 0; pData[0] <= 100; pData[0]++)
    {
        DELAY_5US();

        if(ScalerGetBit(PB_E6_ST_02, (_BIT2 | _BIT1 | _BIT0)) == 0x05)
        {
            break;
        }
    }


    /////////////////////
    // FLD Manual Mode //
    /////////////////////

    // Scan Auto FLD + 4
    usVCOAutoBand = ((WORD)ScalerGetBit(PB_D4_ANA_CDR_05, _BIT2) << 6) + ScalerGetByte(PB_D6_ANA_CDR_07);
    ScalerSetBit(PB_D4_ANA_CDR_05, ~_BIT3, HIBYTE((WORD)usVCOAutoBand + 4) << 3);
    ScalerSetByte(PB_D5_ANA_CDR_06, LOBYTE((WORD)usVCOAutoBand + 4));

    // [7] reg_auto_mode = 1'b0 --> FLD Manual Mode
    ScalerSetBit(PB_CF_ANA_CDR_00, ~_BIT7, 0x00);

    // [1] adp_en_manual = 1'b1 --> Enable CDR Clock Out
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT1, _BIT1);

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();


    //////////////////////////
    //  Scan FLD Band + 4   //
    //////////////////////////

    // [5] ln_ck_sel = 1'b1 -> CDR Clock
    // [0] DP_XTAL_CYCLE = 1'b0 -> XTAL Counter Cycles = 1000
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT0), _BIT5);

    // [1:0] freqdet_lane_sel = ACDR Lane
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), (ScalerGetBit(PB_D1_ANA_CDR_02, (_BIT5 | _BIT4)) >> 4));

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT Value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Delay Time us [5,150] Polling for Measure Done
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        DELAY_5US();

        if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
        {
            usVCOBandScan = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

            // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

            break;
        }
    }


    /////////////////////////
    // VCO Band Difference //
    /////////////////////////

    // Scan Auto FLD Band
    ScalerSetBit(PB_D4_ANA_CDR_05, ~_BIT3, HIBYTE((WORD)usVCOAutoBand) << 3);
    ScalerSetByte(PB_D5_ANA_CDR_06, LOBYTE((WORD)usVCOAutoBand));

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT Value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Delay Time us [5,150] Polling for Measure Done
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        DELAY_5US();

        if((usVCOBandScan == 0) || (ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6))
        {
            break;
        }
    }

    if((usVCOBandScan != 0) && (ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6))
    {
        g_usDpRx0ClockMeasureCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

        usVCOBandDiff = (abs(usVCOBandScan - g_usDpRx0ClockMeasureCount) >> 2);
    }
    else
    {
        usVCOBandDiff = 0;
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    if(usVCOBandDiff != 0)
    {
        // VCO Adjust
        ScalerDpRx0AdjustLaneFLDBand(usVCOBandDiff);
    }

    // [3:0] reg_cdr_cp_in --> Double Icp to Enlarge Locking Range
    if(ucIcp > 7)
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    }
    else
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucIcp << 1));
    }

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();


    ////////////////////
    // CDR Close Loop //
    ////////////////////

    // [2] reg_cp_en_manual = 1'b1 --> CDR Close Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, _BIT2);

    // Delay Time us [45,x]
    DELAY_45US();

    // [3:0] reg_cdr_cp_in --> Restore Icp to Original Setting
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucIcp);

    // Delay Time us [150,x] Wait MAC align comma --> idle pattern worse case every 8192 symbol insert bs (8192 x 1/162M x 2bs = 102us)
    DELAY_XUS(150);

    // [0] en_data_manual = 1'b1 --> Enable Dataout
    ScalerSetBit(PB_AE_DATA_TIMER, ~_BIT0, _BIT0);

    // [3] en_data_manual_l3 = 1'b1 --> Enable Dataout for Lane3
    ScalerSetBit(PB_AF_ANA_CDR_TIMER, ~_BIT3, _BIT3);

    // [6] xclk_sel = 1'b0 --> Keep Link Clock from Analog
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, 0x00);
}
//--------------------------------------------------
// Description  : DP DFE Finetune
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PassiveDFEFineTune(void)
{
    WORD pusLevel0LEErrorCount[4];
    WORD pusLevel1LEErrorCount[4];
    WORD pusLevel2LEErrorCount[4];
    WORD pusLevel3LEErrorCount[4];
    BYTE ucLELevel0 = 3;
    BYTE ucLELevel1 = 7;
    BYTE ucLELevel2 = 12;
    BYTE ucLELevel3 = 17;
    BYTE ucIcp = (ScalerGetByte(PB_D2_ANA_CDR_03) & 0x0F);
    BYTE ucLaneSelect = 0;
    BYTE ucTemp = 0;


    ////////////////////////////
    // LE = Default = Level 2 //
    ////////////////////////////

    // [2:0] rxbist_method = 3'b000 --> Clear 8b10b Error Count
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // [2:0] rxbist_method = 3'b010 --> Detect 8b10b + Disparity Correctness
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

    if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
    {
        // Delay for Checking 8b10b Error Count
        ScalerTimerDelayXms(5);
    }

    // [4:3] rxbist_lane_sel = 2'b00 --> Lane0
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE0 << 3);
    pusLevel2LEErrorCount[_D0_DP_LANE0] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

#if(_DP_RX0_PASSIVE_DFE_FINE_TUNE_TYPE == _FINE_TUNE_DFE_BY_4_LANE)

    // [4:3] rxbist_lane_sel = 2'b01 --> Lane1
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE1 << 3);
    pusLevel2LEErrorCount[_D0_DP_LANE1] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

    // [4:3] rxbist_lane_sel = 2'b10 --> Lane2
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE2 << 3);
    pusLevel2LEErrorCount[_D0_DP_LANE2] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

    // [4:3] rxbist_lane_sel = 2'b11 --> Lane3
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE3 << 3);
    pusLevel2LEErrorCount[_D0_DP_LANE3] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

#endif

    //////////////////
    // LE = Level 3 //
    //////////////////

    // LE Initial = 17
    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, ucLELevel3);
    ScalerSetByte(P1D_B2_L1_LIMIT_INIT, ucLELevel3);
    ScalerSetByte(P1D_C2_L2_LIMIT_INIT, ucLELevel3);
    ScalerSetByte(P1D_D2_L3_LIMIT_INIT, ucLELevel3);

    // Load Intial DFE Code
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

    // [2] reg_cp_en_manual = 1'b0 --> CDR Open Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, 0x00);

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [3:0] reg_cdr_cp_in --> Double Icp to Enlarge Locking Range
    if(ucIcp > 7)
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    }
    else
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucIcp << 1));
    }

    // [2] reg_cp_en_manual = 1'b1 --> CDR Close Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, _BIT2);

    // Delay Time us [45,x]
    DELAY_45US();

    // [3:0] reg_cdr_cp_in --> Restore Icp to Original Setting
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucIcp);

    // Delay Time us [150,x] Wait MAC align comma --> idle pattern worse case every 8192 symbol insert bs (8192 x 1/162M x 2bs = 102us)
    DELAY_XUS(150);

    // [2:0] rxbist_method = 3'b000 --> Clear 8b10b Error Count
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // [2:0] rxbist_method = 3'b010 --> Detect 8b10b + Disparity Correctness
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

    if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
    {
        // Delay for Checking 8b10b Error Count
        ScalerTimerDelayXms(5);
    }

    // [4:3] rxbist_lane_sel = 2'b00 --> Lane0
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE0 << 3);
    pusLevel3LEErrorCount[_D0_DP_LANE0] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

#if(_DP_RX0_PASSIVE_DFE_FINE_TUNE_TYPE == _FINE_TUNE_DFE_BY_4_LANE)

    // [4:3] rxbist_lane_sel = 2'b01 --> Lane1
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE1 << 3);
    pusLevel3LEErrorCount[_D0_DP_LANE1] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

    // [4:3] rxbist_lane_sel = 2'b10 --> Lane2
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE2 << 3);
    pusLevel3LEErrorCount[_D0_DP_LANE2] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

    // [4:3] rxbist_lane_sel = 2'b11 --> Lane3
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE3 << 3);
    pusLevel3LEErrorCount[_D0_DP_LANE3] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

#endif

    //////////////////
    // LE = Level 1 //
    //////////////////

    // LE Initial = 7
    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, ucLELevel1);
    ScalerSetByte(P1D_B2_L1_LIMIT_INIT, ucLELevel1);
    ScalerSetByte(P1D_C2_L2_LIMIT_INIT, ucLELevel1);
    ScalerSetByte(P1D_D2_L3_LIMIT_INIT, ucLELevel1);

    // Load Intial DFE Code
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

    // [2] reg_cp_en_manual = 1'b0 --> CDR Open Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, 0x00);

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [3:0] reg_cdr_cp_in --> Double Icp to Enlarge Locking Range
    if(ucIcp > 7)
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    }
    else
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucIcp << 1));
    }

    // [2] reg_cp_en_manual = 1'b1 --> CDR Close Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, _BIT2);

    // Delay Time us [45,x]
    DELAY_45US();

    // [3:0] reg_cdr_cp_in --> Restore Icp to Original Setting
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucIcp);

    // Delay Time us [150,x] Wait MAC align comma --> idle pattern worse case every 8192 symbol insert bs (8192 x 1/162M x 2bs = 102us)
    DELAY_XUS(150);

    // [2:0] rxbist_method = 3'b000 --> Clear 8b10b Error Count
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // [2:0] rxbist_method = 3'b010 --> Detect 8b10b + Disparity Correctness
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

    if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
    {
        // Delay for Checking 8b10b Error Count
        ScalerTimerDelayXms(5);
    }

    // [4:3] rxbist_lane_sel = 2'b00 --> Lane0
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE0 << 3);
    pusLevel1LEErrorCount[_D0_DP_LANE0] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

#if(_DP_RX0_PASSIVE_DFE_FINE_TUNE_TYPE == _FINE_TUNE_DFE_BY_4_LANE)

    // [4:3] rxbist_lane_sel = 2'b01 --> Lane1
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE1 << 3);
    pusLevel1LEErrorCount[_D0_DP_LANE1] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

    // [4:3] rxbist_lane_sel = 2'b10 --> Lane2
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE2 << 3);
    pusLevel1LEErrorCount[_D0_DP_LANE2] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

    // [4:3] rxbist_lane_sel = 2'b11 --> Lane3
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE3 << 3);
    pusLevel1LEErrorCount[_D0_DP_LANE3] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

#endif


    //////////////////
    // LE = Level 0 //
    //////////////////

    // LE Initial = 3
    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, ucLELevel0);
    ScalerSetByte(P1D_B2_L1_LIMIT_INIT, ucLELevel0);
    ScalerSetByte(P1D_C2_L2_LIMIT_INIT, ucLELevel0);
    ScalerSetByte(P1D_D2_L3_LIMIT_INIT, ucLELevel0);

    // Load Intial DFE Code
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

    // [2] reg_cp_en_manual = 1'b0 --> CDR Open Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, 0x00);

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [3:0] reg_cdr_cp_in --> Double Icp to Enlarge Locking Range
    if(ucIcp > 7)
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    }
    else
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucIcp << 1));
    }

    // [2] reg_cp_en_manual = 1'b1 --> CDR Close Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, _BIT2);

    // Delay Time us [45,x]
    DELAY_45US();

    // [3:0] reg_cdr_cp_in --> Restore Icp to Original Setting
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucIcp);

    // Delay Time us [150,x] Wait MAC align comma --> idle pattern worse case every 8192 symbol insert bs (8192 x 1/162M x 2bs = 102us)
    DELAY_XUS(150);

    // [2:0] rxbist_method = 3'b000 --> Clear 8b10b Error Count
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // [2:0] rxbist_method = 3'b010 --> Detect 8b10b + Disparity Correctness
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

    if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
    {
        // Delay for Checking 8b10b Error Count
        ScalerTimerDelayXms(5);
    }

    // [4:3] rxbist_lane_sel = 2'b00 --> Lane0
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE0 << 3);
    pusLevel0LEErrorCount[_D0_DP_LANE0] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

#if(_DP_RX0_PASSIVE_DFE_FINE_TUNE_TYPE == _FINE_TUNE_DFE_BY_4_LANE)

    // [4:3] rxbist_lane_sel = 2'b01 --> Lane1
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE1 << 3);
    pusLevel0LEErrorCount[_D0_DP_LANE1] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

    // [4:3] rxbist_lane_sel = 2'b10 --> Lane2
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE2 << 3);
    pusLevel0LEErrorCount[_D0_DP_LANE2] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

    // [4:3] rxbist_lane_sel = 2'b11 --> Lane3
    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _D0_DP_LANE3 << 3);
    pusLevel0LEErrorCount[_D0_DP_LANE3] = (((WORD)(ScalerGetByte(PB_0B_BIST_PATTERN3) & 0x7F) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4));

#endif

    DebugMessageRx0("Level 3 LE ErrorCount[_D0_DP_LANE0]", pusLevel3LEErrorCount[_D0_DP_LANE0]);
    DebugMessageRx0("Level 2 LE ErrorCount[_D0_DP_LANE0]", pusLevel2LEErrorCount[_D0_DP_LANE0]);
    DebugMessageRx0("Level 1 LE ErrorCount[_D0_DP_LANE0]", pusLevel1LEErrorCount[_D0_DP_LANE0]);
    DebugMessageRx0("Level 0 LE ErrorCount[_D0_DP_LANE0]", pusLevel0LEErrorCount[_D0_DP_LANE0]);

#if(_DP_RX0_PASSIVE_DFE_FINE_TUNE_TYPE == _FINE_TUNE_DFE_BY_4_LANE)

    DebugMessageRx0("Level 3 LE ErrorCount[_D0_DP_LANE1]", pusLevel3LEErrorCount[_D0_DP_LANE1]);
    DebugMessageRx0("Level 2 LE ErrorCount[_D0_DP_LANE1]", pusLevel2LEErrorCount[_D0_DP_LANE1]);
    DebugMessageRx0("Level 1 LE ErrorCount[_D0_DP_LANE1]", pusLevel1LEErrorCount[_D0_DP_LANE1]);
    DebugMessageRx0("Level 0 LE ErrorCount[_D0_DP_LANE1]", pusLevel0LEErrorCount[_D0_DP_LANE1]);

    DebugMessageRx0("Level 3 LE ErrorCount[_D0_DP_LANE2]", pusLevel3LEErrorCount[_D0_DP_LANE2]);
    DebugMessageRx0("Level 2 LE ErrorCount[_D0_DP_LANE2]", pusLevel2LEErrorCount[_D0_DP_LANE2]);
    DebugMessageRx0("Level 1 LE ErrorCount[_D0_DP_LANE2]", pusLevel1LEErrorCount[_D0_DP_LANE2]);
    DebugMessageRx0("Level 0 LE ErrorCount[_D0_DP_LANE2]", pusLevel0LEErrorCount[_D0_DP_LANE2]);

    DebugMessageRx0("Level 3 LE ErrorCount[_D0_DP_LANE3]", pusLevel3LEErrorCount[_D0_DP_LANE3]);
    DebugMessageRx0("Level 2 LE ErrorCount[_D0_DP_LANE3]", pusLevel2LEErrorCount[_D0_DP_LANE3]);
    DebugMessageRx0("Level 1 LE ErrorCount[_D0_DP_LANE3]", pusLevel1LEErrorCount[_D0_DP_LANE3]);
    DebugMessageRx0("Level 0 LE ErrorCount[_D0_DP_LANE3]", pusLevel0LEErrorCount[_D0_DP_LANE3]);
#endif


    ///////////////////////////////////
    // Choose The Best DFE Parameter //
    ///////////////////////////////////

    SET_DP_RX0_AUX_MANUAL_MODE();

    if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
    {
        for(ucLaneSelect = 0; ucLaneSelect < 4; ucLaneSelect++)
        {
#if(_DP_RX0_PASSIVE_DFE_FINE_TUNE_TYPE == _FINE_TUNE_DFE_BY_1_LANE)

            ucTemp = _D0_DP_LANE0;

#elif(_DP_RX0_PASSIVE_DFE_FINE_TUNE_TYPE == _FINE_TUNE_DFE_BY_4_LANE)

            ucTemp = ucLaneSelect;
#endif
            if(pusLevel3LEErrorCount[ucTemp] > pusLevel0LEErrorCount[ucTemp])
            {
                if((pusLevel2LEErrorCount[ucTemp] > pusLevel0LEErrorCount[ucTemp]) && (pusLevel1LEErrorCount[ucTemp] >= pusLevel0LEErrorCount[ucTemp]))
                {
                    if(pusLevel1LEErrorCount[ucTemp] == pusLevel0LEErrorCount[ucTemp])
                    {
                        // LE Initial = 5
                        ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), (ucLELevel0 + ucLELevel1) >> 1);
                    }
                    else
                    {
                        // LE Initial = 3
                        ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), ucLELevel0);
                    }
                }
                else if((pusLevel0LEErrorCount[ucTemp] > pusLevel2LEErrorCount[ucTemp]) && (pusLevel1LEErrorCount[ucTemp] >= pusLevel2LEErrorCount[ucTemp]))
                {
                    if(pusLevel1LEErrorCount[ucTemp] == pusLevel2LEErrorCount[ucTemp])
                    {
                        // LE Initial = 9
                        ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), (ucLELevel1 + ucLELevel2) >> 1);
                    }
                    else
                    {
                        // LE Initial = 12
                        ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), ucLELevel2);
                    }
                }
                else
                {
                    // LE Initial = 7
                    ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), ucLELevel1);
                }
            }
            else if(pusLevel0LEErrorCount[ucTemp] > pusLevel3LEErrorCount[ucTemp])
            {
                if((pusLevel1LEErrorCount[ucTemp] > pusLevel3LEErrorCount[ucTemp]) && (pusLevel2LEErrorCount[ucTemp] >= pusLevel3LEErrorCount[ucTemp]))
                {
                    if(pusLevel2LEErrorCount[ucTemp] == pusLevel3LEErrorCount[ucTemp])
                    {
                        // LE Initial = 14
                        ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), (ucLELevel2 + ucLELevel3) >> 1);
                    }
                    else
                    {
                        // LE Initial = 17
                        ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), ucLELevel3);
                    }
                }
                else if((pusLevel3LEErrorCount[ucTemp] > pusLevel1LEErrorCount[ucTemp]) && (pusLevel2LEErrorCount[ucTemp] >= pusLevel1LEErrorCount[ucTemp]))
                {
                    if(pusLevel2LEErrorCount[ucTemp] == pusLevel1LEErrorCount[ucTemp])
                    {
                        // LE Initial = 9
                        ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), (ucLELevel1 + ucLELevel2) >> 1);
                    }
                    else
                    {
                        // LE Initial = 7
                        ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), ucLELevel1);
                    }
                }
                else
                {
                    // LE Initial = 12
                    ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), ucLELevel2);
                }
            }
            else
            {
                if((pusLevel0LEErrorCount[ucTemp] == 0) || (pusLevel1LEErrorCount[ucTemp] == pusLevel2LEErrorCount[ucTemp]))
                {
                    // LE Initial = 9
                    ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), (ucLELevel1 + ucLELevel2) >> 1);
                }
                else if(pusLevel1LEErrorCount[ucTemp] > pusLevel2LEErrorCount[ucTemp])
                {
                    // LE Initial = 12
                    ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), ucLELevel2);
                }
                else
                {
                    // LE Initial = 7
                    ScalerSetByte((P1D_A2_L0_LIMIT_INIT + (ucLaneSelect * 0x0010)), ucLELevel1);
                }
            }
        }
    }
    else if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS)
    {
        ScalerSetByte(P1D_A2_L0_LIMIT_INIT, g_pucDpRx0LEFineTune[0]);
        ScalerSetByte(P1D_B2_L1_LIMIT_INIT, g_pucDpRx0LEFineTune[1]);
        ScalerSetByte(P1D_C2_L2_LIMIT_INIT, g_pucDpRx0LEFineTune[2]);
        ScalerSetByte(P1D_D2_L3_LIMIT_INIT, g_pucDpRx0LEFineTune[3]);
    }
    else
    {
        ScalerSetByte(P1D_A2_L0_LIMIT_INIT, ucLELevel2);
        ScalerSetByte(P1D_B2_L1_LIMIT_INIT, ucLELevel2);
        ScalerSetByte(P1D_C2_L2_LIMIT_INIT, ucLELevel2);
        ScalerSetByte(P1D_D2_L3_LIMIT_INIT, ucLELevel2);
    }

    // HBR Reload Tap0 = 21
    if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR)
    {
        ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
        ScalerSetByte(P1D_B4_L1_INIT_2, 0x15);
        ScalerSetByte(P1D_C4_L2_INIT_2, 0x15);
        ScalerSetByte(P1D_D4_L3_INIT_2, 0x15);
    }

    // Load Intial DFE Code
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x81);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x81);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x81);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x81);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

    // Toggle en_fore_offset
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, 0x00);
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);

    // Delay Time ~ 50us
    for(pData[0] = 0; pData[0] <= 20; pData[0]++)
    {
        DELAY_5US();

        if(((ScalerGetBit(PB_DA_TMDS_RESET, _BIT7) == 0x00) || (ScalerGetBit(PB_C7_KOFFSET_00, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT6) == 0x00) || (ScalerGetBit(PB_C8_KOFFSET_01, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT5) == 0x00) || (ScalerGetBit(PB_C9_KOFFSET_02, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT4) == 0x00) || (ScalerGetBit(PB_CA_KOFFSET_03, _BIT5) == _BIT5)))
        {
            break;
        }
    }

    // [2] reg_cp_en_manual = 1'b0 --> CDR Open Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, 0x00);

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [3:0] reg_cdr_cp_in --> Double Icp to Enlarge Locking Range
    if(ucIcp > 7)
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    }
    else
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucIcp << 1));
    }

    // [2] reg_cp_en_manual = 1'b1 --> CDR Close Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, _BIT2);

    // Delay Time us [45,x]
    DELAY_45US();

    // [3:0] reg_cdr_cp_in --> Restore Icp to Original Setting
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucIcp);

    SET_DP_RX0_AUX_AUTO_MODE();
}
//--------------------------------------------------
// Description  : DP FLD Band Finetune
// Input Value  : LaneNumber
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0AdjustLaneFLDBand(WORD usVCOBandDiff)
{
    WORD usBestVCOBand = 0;
    WORD usAutoVCOBand = 0;

    usAutoVCOBand = ((WORD)ScalerGetBit(PB_D4_ANA_CDR_05, _BIT2) << 6) + ScalerGetByte(PB_D6_ANA_CDR_07);

    // [1:0] freqdet_lane_sel = ACDR Lane
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), (ScalerGetBit(PB_D1_ANA_CDR_02, (_BIT5 | _BIT4)) >> 4));

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Delay Time us [5,150] Polling for Measure Done
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        DELAY_5US();

        if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
        {
            break;
        }
    }

    if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
    {
        g_usDpRx0ClockMeasureCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

        if(g_usDpRx0ClockMeasureCount < g_usDpRx0ClockTargetCount)
        {
            usBestVCOBand = usAutoVCOBand + (((g_usDpRx0ClockTargetCount - g_usDpRx0ClockMeasureCount) / usVCOBandDiff) + 1);
        }
        else
        {
            usBestVCOBand = usAutoVCOBand - ((g_usDpRx0ClockMeasureCount - g_usDpRx0ClockTargetCount) / usVCOBandDiff);
        }
    }
    else
    {
        usBestVCOBand = usAutoVCOBand;
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    ScalerSetBit(PB_D4_ANA_CDR_05, ~_BIT3, HIBYTE((WORD)usBestVCOBand) << 3);
    ScalerSetByte(PB_D5_ANA_CDR_06, LOBYTE((WORD)usBestVCOBand));
}

//--------------------------------------------------
// Description  : DP PHY DFE Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetDFEInitial(EnumDpLinkRate enumDpLinkRate)
{
    if((ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, _BIT7) == _BIT7) || (GET_DP_RX0_PHY_CTS_FLG() == _TRUE))
    {
        if(enumDpLinkRate == _DP_LINK_RBR)
        {
            // LE Initial = 13
            ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x0D);
            ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x0D);
            ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x0D);
            ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x0D);
        }
        else
        {
            // LE Initial = 7
            ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x07);
            ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x07);
            ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x07);
            ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x07);
        }
    }
    else
    {
        // LE Initial = 12
        ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x0C);
        ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x0C);
        ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x0C);
        ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x0C);
    }

    // Tap0 Initial Value = 18
    ScalerSetByte(P1D_A4_L0_INIT_2, 0x12);
    ScalerSetByte(P1D_B4_L1_INIT_2, 0x12);
    ScalerSetByte(P1D_C4_L2_INIT_2, 0x12);
    ScalerSetByte(P1D_D4_L3_INIT_2, 0x12);

    // Tap1 Initial Value = 0
    ScalerSetByte(P1D_A5_L0_INIT_3, 0x00);
    ScalerSetByte(P1D_B5_L1_INIT_3, 0x00);
    ScalerSetByte(P1D_C5_L2_INIT_3, 0x00);
    ScalerSetByte(P1D_D5_L3_INIT_3, 0x00);

    // Tap2 Initial Value = 0
    ScalerSetByte(P1D_A6_L0_INIT_4, 0x00);
    ScalerSetByte(P1D_B6_L1_INIT_4, 0x00);
    ScalerSetByte(P1D_C6_L2_INIT_4, 0x00);
    ScalerSetByte(P1D_D6_L3_INIT_4, 0x00);

    // Load Intial DFE Code
    ScalerSetByte(P1D_AA_L0_INIT_8, 0xFF);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0xFF);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0xFF);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0xFF);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);
}

//--------------------------------------------------
// Description  : Check Valid Lane CDR
//                It can not use pData to avoid cross-function usage
// Input Value  : None
// Output Value : True --> CDR Lock
//--------------------------------------------------
bit ScalerDpRx0CDRCheck(BYTE ucDpLinkRate, BYTE ucDpcdLane)
{
#if(_HW_DP_GDI_RX0_DFE_TYPE == _PASSIVE_DFE)
    CLR_DP_RX0_SIGNALDETECT_INT_HAPPENED();
#endif

    switch(ucDpcdLane)
    {
        case _DP_ONE_LANE:

            if(ScalerDpRx0MeasureLaneCDRClk(ucDpLinkRate, _D0_DP_LANE0) == _TRUE)
            {
                return _TRUE;
            }
            break;

        case _DP_TWO_LANE:

            if(ScalerDpRx0MeasureLaneCDRClk(ucDpLinkRate, _D0_DP_LANE0) == _TRUE)
            {
                return _TRUE;
            }
            break;

        case _DP_FOUR_LANE:
        default:

            if(ScalerDpRx0MeasureLaneCDRClk(ucDpLinkRate, _D0_DP_LANE3) == _TRUE)
            {
                return _TRUE;
            }

            break;
    }

#if(_HW_DP_GDI_RX0_DFE_TYPE == _PASSIVE_DFE)
    if(GET_DP_RX0_SIGNALDETECT_INT_HAPPENED() == _TRUE)
    {
        return _TRUE;
    }
    else
#endif
    {
        DebugMessageRx0("7. wuzanne test : DP CDR Unlock", 0);

        return _FALSE;
    }
}

//--------------------------------------------------
// Description : check DP CDR locked or unlocked
//               It can not use pData to avoid cross-function usage
// Input Value  : DP Lane
// Output Value : True --> locked; False --> unlocked
//--------------------------------------------------
bit ScalerDpRx0MeasureLaneCDRClk(BYTE ucDpLinkRate, BYTE ucDpRx0LaneNumber)
{
    WORD usCDRClockCount = 0;
    BYTE ucCount = 0;

#if(_XTALESS_SUPPORT == _ON)
    return _TRUE;
#endif

#if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_200M) // GDI Clock = 28.6M
    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR:

            if((abs(g_usDpRx0ClockTargetCount - 0x1270)) > (0x1270 >> 4))
            {
                return _TRUE;
            }

            break;

        default:
        case _DP_LINK_RBR:

            if((abs(g_usDpRx0ClockTargetCount - 0xB10)) > (0xB10 >> 4))
            {
                return _TRUE;
            }

            break;
    }
#elif((_M2PLL_FREQ_SEL == _M2PLL_FREQ_189M) || (_M2PLL_FREQ_SEL == _M2PLL_FREQ_216M)) // GDI Clock = 27M
    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR:

            if((abs(g_usDpRx0ClockTargetCount - 0x1388)) > (0x1388 >> 4))
            {
                return _TRUE;
            }

            break;

        default:
        case _DP_LINK_RBR:

            if((abs(g_usDpRx0ClockTargetCount - 0xBB8)) > (0xBB8 >> 4))
            {
                return _TRUE;
            }

            break;
    }
#elif(_M2PLL_FREQ_SEL == _M2PLL_FREQ_220M) // GDI Clock = 27.5M
    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR:

            if((abs(g_usDpRx0ClockTargetCount - 0x132D)) > (0x132D >> 4))
            {
                return _TRUE;
            }

            break;

        default:
        case _DP_LINK_RBR:

            if((abs(g_usDpRx0ClockTargetCount - 0xB81)) > (0xB81 >> 4))
            {
                return _TRUE;
            }

            break;
    }
#endif

    // Select Measure CDR Clock & XTAL 27M Count 1000 Times
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT0), _BIT5);

    // Select CDR Lane
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), ucDpRx0LaneNumber);

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // Toggle Start Measure
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Delay Time us [5,150] Polling for Measure Done
    for(ucCount = 0; ucCount <= 30; ucCount++)
    {
        DELAY_5US();

        if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
        {
            break;
        }
    }

    if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == 0x00)
    {
        return _FALSE;
    }

    usCDRClockCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

    if(abs(g_usDpRx0ClockTargetCount - usCDRClockCount) > (g_usDpRx0ClockTargetCount >> 7))
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description : Initial Signal check
// Input Value  : DP Link Rate and DP Reload LEQ Scan Value
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SignalDetectInitial(BYTE ucDpLinkRate, BYTE ucDpLEQScanValue)
{
    BYTE ucD0Z0Status = 0;
    BYTE ucD1Z0Status = 0;


    ////////////////////
    // Mode Select DP //
    ////////////////////

    // Backup Z0 Status
    ucD0Z0Status = ScalerGetBit(PB_B3_IMPEDANCE_00, (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    ucD1Z0Status = ScalerGetBit(PB_B4_IMPEDANCE_01, (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Disable Z0
    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // [5] dp_mode = 1'b1 --> Select DP Mode
    ScalerSetBit(PB_B1_PORT_SEL, ~_BIT5, _BIT5);

    // [0] hd_dp_sel = 1'b0 --> Select DP
    ScalerSetBit(PB_00_HD_DP_SEL, ~_BIT0, 0x00);

    // [3] PSM = 1'b0 --> Disable Clock Switch
    ScalerSetBit(PB_B0_CLK_DET, ~_BIT3, 0x00);

    // [6] reg_bypass_ok = 1'b0 --> Disable bypass ok
    ScalerSetBit(PB_C9_KOFFSET_02, ~_BIT6, 0x00);

    // Restore Z0 Status
    ScalerSetBit(PB_B3_IMPEDANCE_00, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucD0Z0Status);
    ScalerSetBit(PB_B4_IMPEDANCE_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucD1Z0Status);

    // [5:4] reg_dp_bbpd_sel --> Default set ACDR to PCB Lane0
    ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), (GET_DP_RX0_PCB_LANE0_MAPPING() << 4));

    ///////////////
    // RX CMU EN //
    ///////////////

    // Disable RX_EN, CDR_EN
    ScalerSetByte(PB_B2_ENABLE, 0x00);

    // Enable RX_EN, CDR_EN
    ScalerSetByte(PB_B2_ENABLE, 0xFF);


    ////////////////
    // EQ Setting //
    ////////////////

    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR:

            // [7] le_lowgain_highboost = 1'b1 --> Enable LE High-boost Mode
            ScalerSetBit(PB_CC_KOFFSET_05, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

            // [7:5] le_isel = 3'b010 --> LE Peaking = 1.7Gbps
            ScalerSetBit(PB_CD_KOFFSET_06, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

            // [7:5] le_rlsel = 3'b001 --> LE Peaking = 1.7Gbps
            ScalerSetBit(PB_CE_KOFFSET_07, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

            switch(ucDpLEQScanValue)
            {
                case _DP_RELOAD_LEQ_DEFAULT:

                    // LE Initial = 12
                    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x0C);
                    ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x0C);
                    ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x0C);
                    ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x0C);

                    break;

                case _DP_RELOAD_LEQ_LARGE:
                default:

                    // LE Initial = 17
                    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x11);
                    ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x11);
                    ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x11);
                    ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x11);

                    break;
            }

            break;

        case _DP_LINK_RBR:
        default:

            // [7] le_lowgain_highboost = 1'b0 --> Disable LE High-boost Mode
            ScalerSetBit(PB_CC_KOFFSET_05, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

            // [7:5] le_isel = 3'b000 --> LE Peaking = 900Mbps
            ScalerSetBit(PB_CD_KOFFSET_06, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

            // [7:5] le_rlsel = 3'b011 --> LE Peaking = 900Mbps
            ScalerSetBit(PB_CE_KOFFSET_07, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));

            // LE Initial = 12
            ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x0C);
            ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x0C);
            ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x0C);
            ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x0C);

            break;
    }

    // Tap0 Initial Value = 18
    ScalerSetByte(P1D_A4_L0_INIT_2, 0x12);
    ScalerSetByte(P1D_B4_L1_INIT_2, 0x12);
    ScalerSetByte(P1D_C4_L2_INIT_2, 0x12);
    ScalerSetByte(P1D_D4_L3_INIT_2, 0x12);

    // Delay Time us [85,x]
    DELAY_XUS(85);

    // [7] en_fore_offset = 1'b0 --> Disable EQ foreground Offset Calibration
    // [6] fore_off_autok = 1'b1 --> Enable EQ foreground Offset Calibration Auto Mode
    ScalerSetBit(PB_C8_KOFFSET_01, ~(_BIT7 | _BIT6), _BIT6);

    // Toggle en_fore_offset
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, 0x00);
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);

    // Delay Time ~ 50us
    for(pData[0] = 0; pData[0] <= 20; pData[0]++)
    {
        DELAY_5US();

        if(((ScalerGetBit(PB_DA_TMDS_RESET, _BIT7) == 0x00) || (ScalerGetBit(PB_C7_KOFFSET_00, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT6) == 0x00) || (ScalerGetBit(PB_C8_KOFFSET_01, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT5) == 0x00) || (ScalerGetBit(PB_C9_KOFFSET_02, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT4) == 0x00) || (ScalerGetBit(PB_CA_KOFFSET_03, _BIT5) == _BIT5)))
        {
            break;
        }
    }
}

//--------------------------------------------------
// Description  : Reset Interlace Mode
// Input Value  : EnumHDCPType
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0InterlaceReset(void)
{
    // Interlace mode disable, refer to VBID[1], Field Inverse Disable, Clear Hwardware Detect Interlace Flag, Clear Fake Interlace Flag
    ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT0), (_BIT5 | _BIT0));

#if(_DP_RX_INTERLACE_NEW_MODE_SUPPORT == _ON)
    // Enable Field Sync by VBID
    ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~(_BIT6 | _BIT0), 0x00);

    // Set Vtt odd fw mode
    SET_DP_RX0_INTERLACE_VTT_FW_MODE(_ODD);
#endif
}

//--------------------------------------------------
// Description : DP Signal Detection Measure
//               It can not use pData to avoid cross-function usage
// Input Value  : DP Lane Select, Measure target, Measure Period
// Output Value : Measure Counter
//--------------------------------------------------
WORD ScalerDpRx0SignalDetectMeasureCount(BYTE ucDpLaneSel, EnumDpMeasureTarget enumDpMeasureTarget, EnumDpMeasurePeriod enumDpMeasurePeriod)
{
    WORD usDpMeasureCount = 0;
    BYTE ucCount = 0;

    if(enumDpMeasureTarget == _DP_MEASURE_TARGET_RAW_DATA)
    {
        // Enable Signal Detection
        ScalerSetBit(PB_C6_SIGDET, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    }

    // [1:0] freqdet_lane_sel
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), (ucDpLaneSel & (_BIT1 | _BIT0)));

    // [5] ln_ck_sel
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT5, enumDpMeasureTarget);

    switch(enumDpMeasurePeriod)
    {
        case _DP_MEASURE_PERIOD_1000_CYCLE:

            // [0] DP_XTAL_CYCLE = 0
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT0, 0x00);
            break;

        case _DP_MEASURE_PERIOD_2000_CYCLE:
        default:

            // [0] DP_XTAL_CYCLE = 1
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT0, _BIT0);
            break;
    }

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Delay Time us [5,150] Polling for Measure Done
    for(ucCount = 0; ucCount <= 30; ucCount++)
    {
        DELAY_5US();

        if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
        {
            usDpMeasureCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

            break;
        }
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    // Disable Signal Detection
    ScalerSetBit(PB_C6_SIGDET, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    return usDpMeasureCount;
}

//--------------------------------------------------
// Description  : Check DP Link Info from Measure Function
// Input Value  : StructDpInfo pointer
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerDpRx0MeasureInfoCheck(StructDpInfo *pstDpInfo)
{
    // Bs2Bs Count Check, CNT=0 => IDLE pattern
    if((pstDpInfo->stDpLinkInfo.usHBsToBsCount == 0) ||
       (pstDpInfo->stDpLinkInfo.ulVBsToBsCountN == 0) ||
       (pstDpInfo->stDpLinkInfo.ulVBsToBsCountN1 == 0))
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Get DP Link Info from Measure Function
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerDpRx0GetMeasureLinkInfo(StructDpInfo *pstDpInfo)
{
    WORD usTemp = 0;

    ///////////////////////
    // Get Measured Info //
    ///////////////////////

    // Reset Interlace mode
    ScalerDpRx0InterlaceReset();

    // Enable Measurement
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~(_BIT7 | _BIT5), 0x00);
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~(_BIT7 | _BIT5), _BIT7);

    if(ScalerDpRx0PollingFlagLinkCheck(_DP_MEASURE_POLLING_TIMEOUT, PB5_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Delay 1 frame time be used to wait time passed for upstream dptx generated different picture size of the firt frame and second frame
    // Pop up The Measured Result
    SET_DP_RX0_MEASURE_POP_UP();

    // Get BS To BS Count of Frame N
    pstDpInfo->stDpLinkInfo.ulVBsToBsCountN = TO_DWORD(0x00, ScalerGetBit(PB5_58_MN_MEAS_CTRL, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)), ScalerGetByte(PB5_59_MN_MEAS_VLN_M), ScalerGetByte(PB5_5A_MN_MEAS_VLN_L));

    // Delay 1 Frame Time, unit is ms
    if(ScalerDpRx0TimerDelayXmsLinkCheck((pstDpInfo->stDpLinkInfo.ulVBsToBsCountN / _GDI_CLK_KHZ) + 2) == _FALSE)
    {
        return _FALSE;
    }

    // Pop up The Measured Result
    SET_DP_RX0_MEASURE_POP_UP();

    // Get BS To BS Count of Frame N
    pstDpInfo->stDpLinkInfo.ulVBsToBsCountN = TO_DWORD(0x00, ScalerGetBit(PB5_58_MN_MEAS_CTRL, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)), ScalerGetByte(PB5_59_MN_MEAS_VLN_M), ScalerGetByte(PB5_5A_MN_MEAS_VLN_L));

    // Delay 2ms To Get VBID
    ScalerTimerDelayXms(2);

    // Get Interlace Field Flag VBID[1] of Frame N
    pstDpInfo->stDpLinkInfo.b1InterlaceFieldN = (bit)ScalerGetBit(PB6_01_DP_VBID, _BIT1);

    // Delay 1 Frame Time, unit is ms
    if(ScalerDpRx0TimerDelayXmsLinkCheck((pstDpInfo->stDpLinkInfo.ulVBsToBsCountN / _GDI_CLK_KHZ) + 2) == _FALSE)
    {
        return _FALSE;
    }

    // Pop up The Measured Result
    SET_DP_RX0_MEASURE_POP_UP();

    // Get BS To BS Count of Frame N+1
    pstDpInfo->stDpLinkInfo.ulVBsToBsCountN1 = TO_DWORD(0x00, ScalerGetBit(PB5_58_MN_MEAS_CTRL, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)), ScalerGetByte(PB5_59_MN_MEAS_VLN_M), ScalerGetByte(PB5_5A_MN_MEAS_VLN_L));

    // Get Interlace Field Flag VBID[1] of Frame N+1
    pstDpInfo->stDpLinkInfo.b1InterlaceFieldN1 = (bit)ScalerGetBit(PB6_01_DP_VBID, _BIT1);

    // Get Interlace HW Detect Result
    pstDpInfo->stDpLinkInfo.b1HwInterlaceDetect = (bit)ScalerGetBit(PB5_57_INTERLACE_MODE_CONFIG, _BIT5);
    pstDpInfo->stDpLinkInfo.b1HwFakeInterlaceDetect = (bit)ScalerGetBit(PB5_57_INTERLACE_MODE_CONFIG, _BIT0);

    // Disable Measurement
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~(_BIT7 | _BIT5), 0x00);

    // Get HBs2Bs Count By Link Clk / 2
    pstDpInfo->stDpLinkInfo.usHBsToBsCount = (((WORD)ScalerGetByte(PB5_5B_MN_MEAS_HLN_M)) << 8) | ((WORD)ScalerGetByte(PB5_5C_MN_MEAS_HLN_L));

    /////////////////////
    // Check the value //
    /////////////////////
    if(ScalerDpRx0MeasureInfoCheck(pstDpInfo) == _FALSE)
    {
        return _FALSE;
    }

    ////////////////////
    // Get Link Clock //
    ////////////////////

    usTemp = ScalerDpRx0SignalDetectMeasureCount(_D0_DP_LANE0, _DP_MEASURE_TARGET_CDR_CLOCK, _DP_MEASURE_PERIOD_2000_CYCLE);

    if(usTemp == 0)
    {
        switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00))
        {
            case _DP_LINK_HBR2:

                usTemp = _DP_VCO_TARGET_COUNT_2000_HBR2_SAVED;

                break;

            case _DP_LINK_HBR:

                usTemp = _DP_VCO_TARGET_COUNT_2000_HBR_SAVED;

                break;

            case _DP_LINK_RBR:
            default:

                usTemp = _DP_VCO_TARGET_COUNT_2000_RBR_SAVED;

                break;
        }
    }

    // Get Link Clock, Unit is Hz
    pstDpInfo->stDpLinkInfo.ulLinkClockHz = (((DWORD)usTemp) * _GDI_CLK_KHZ);


    //////////////////////
    // Get Stream Clock //
    //////////////////////

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        // Get IVfreq
        usTemp = ((DWORD)_GDI_CLK_KHZ * 1000 / (pstDpInfo->stDpLinkInfo.ulVBsToBsCountN / 10));

        // VTotal in line, Link Clk / 2 : (Link Rate * 27 / 2)
        pstDpInfo->stDpTimingInfo.usVTotal = ScalerComputeDwordMulDiv(pstDpInfo->stDpLinkInfo.ulVBsToBsCountN, (pstDpInfo->stDpLinkInfo.ulLinkClockHz / 1000 / 2), (DWORD)pstDpInfo->stDpLinkInfo.usHBsToBsCount) / _GDI_CLK_KHZ;

        // Calculate Stream Clock (Unit is Hz)
        pstDpInfo->stDpLinkInfo.ulStreamClockHz = pstDpInfo->stDpLinkInfo.ulMvid * (pstDpInfo->stDpLinkInfo.ulLinkClockHz / pstDpInfo->stDpLinkInfo.ulNvid);
        pstDpInfo->stDpLinkInfo.ulStreamClockHz += pstDpInfo->stDpLinkInfo.ulLinkClockHz % pstDpInfo->stDpLinkInfo.ulNvid * 100 / pstDpInfo->stDpLinkInfo.ulNvid * pstDpInfo->stDpLinkInfo.ulMvid / 100;

        // HTotal in Pixel Clk, Link Clk / 2 : (Link Rate * 27 / 2)
        pstDpInfo->stDpTimingInfo.usHTotal = ScalerComputeDwordMulDiv((DWORD)pstDpInfo->stDpLinkInfo.usHBsToBsCount, (pstDpInfo->stDpLinkInfo.ulStreamClockHz / 1000), pstDpInfo->stDpLinkInfo.ulLinkClockHz / 1000 / 2);

        ScalerDpRx0SetDrrMsaForLut(&pstDpInfo->stDpTimingInfo);

        // Initial Value Need to be Lower than the Target Value for Tracking (Margin is 0.07%)
        pstDpInfo->stDpLinkInfo.ulStreamClockHz = ScalerComputeDwordMulDiv(pstDpInfo->stDpLinkInfo.ulStreamClockHz, 9993, 10000);
    }
    else
#endif
    {
        // Calculate Stream Clock (Unit is Hz)
        pstDpInfo->stDpLinkInfo.ulStreamClockHz = ((((DWORD)pstDpInfo->stDpTimingInfo.usHTotal * ((DWORD)pstDpInfo->stDpTimingInfo.usVTotal) * 100) / pstDpInfo->stDpLinkInfo.ulVBsToBsCountN) *_GDI_CLK_KHZ * 10);

        // Initial Value Need to be Lower than the Target Value for Tracking (Margin is 0.07%)
        pstDpInfo->stDpLinkInfo.ulStreamClockHz = ScalerComputeDwordMulDiv(pstDpInfo->stDpLinkInfo.ulStreamClockHz, 9993, 10000);
    }

    // Recoed Input Pixel Clock (Unit is 0.1MHz)
    SET_INPUT_PIXEL_CLK(pstDpInfo->stDpLinkInfo.ulStreamClockHz / 100000);


    DebugMessageRx0("DP MAC RX0: VBs2Bs N", pstDpInfo->stDpLinkInfo.ulVBsToBsCountN);
    DebugMessageRx0("DP MAC RX0: VBs2Bs N+1", pstDpInfo->stDpLinkInfo.ulVBsToBsCountN1);
    DebugMessageRx0("DP MAC RX0: HBs2Bs", pstDpInfo->stDpLinkInfo.usHBsToBsCount);
    DebugMessageRx0("DP MAC RX0: Link Clock", pstDpInfo->stDpLinkInfo.ulLinkClockHz);
    DebugMessageRx0("DP MAC RX0: Mvid", pstDpInfo->stDpLinkInfo.ulMvid);
    DebugMessageRx0("DP MAC RX0: Nvid", pstDpInfo->stDpLinkInfo.ulNvid);
    DebugMessageRx0("DP MAC RX0: Stream Clock", pstDpInfo->stDpLinkInfo.ulStreamClockHz);

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP BS to HS Delay Calculation
// Input Value  : None
// Output Value : BS to VS Delay
//--------------------------------------------------
void ScalerDpRx0SetBsToHsDelay(StructTimingInfo *pstDpTimingInfo)
{
    WORD usFifoOffset = 0;
    WORD usBsToHsDelay = 0;

    // DP fifo size = 256 x 96bit
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        // FifoOffset = (1/2 * (256 * 96) / (2 * depth per color)), color format is YCbCr 4:2:2
        usFifoOffset = _HW_DP_RX_VIDEO_FIFO_SIZE / (4 * ((WORD)GET_COLOR_DEPTH()));
    }
    else
    {
        // FifoOffset = (1/2 * (256 * 96) / (3 * depth per color)), color format is RGB or YCbCr 4:4:4 or YCbCr 4:2:0 or others
        usFifoOffset = _HW_DP_RX_VIDEO_FIFO_SIZE / (6 * ((WORD)GET_COLOR_DEPTH()));
    }

    // De Only Mode HW constraint: BS2HS delay < Htotal => 1/2 FIFO < H Width, Enough Margin = 1/2 H Width
    if(usFifoOffset > (pstDpTimingInfo->usHWidth >> 1))
    {
        usFifoOffset = (pstDpTimingInfo->usHWidth >> 1);
    }

    // Get BS to HS delay according to (HBlanking + 1/2 FIFO - HStart), Unit is 2 pixel mode
    usBsToHsDelay = ((pstDpTimingInfo->usHTotal - pstDpTimingInfo->usHWidth) + usFifoOffset - pstDpTimingInfo->usHStart) >> 1;

    // Set BS to HS Delay
    ScalerSetByte(PB5_38_BS2HS_0, HIBYTE(usBsToHsDelay));
    ScalerSetByte(PB5_39_BS2HS_1, LOBYTE(usBsToHsDelay));
}

//--------------------------------------------------
// Description  : DP BS to VS Delay Calculation
// Input Value  : None
// Output Value : BS to VS Delay
//--------------------------------------------------
void ScalerDpRx0SetBsToVsDelay(StructDpInfo *pstDpInfo)
{
    DWORD ulVFrontPorch = 0;
    DWORD ulHFrontPorch = 0;
    DWORD ulBsToVsDelay = 0;
    WORD usFifoOffset = 0;

    // Get V Front Porch, unit is pixel clock
    ulVFrontPorch = ((DWORD)GET_DP_RX0_VFRONT_PORCH()) * pstDpInfo->stDpTimingInfo.usHTotal;

    // Get H Front Porch, unit is pixel clock
    ulHFrontPorch = (DWORD)(pstDpInfo->stDpTimingInfo.usHTotal - pstDpInfo->stDpTimingInfo.usHWidth - pstDpInfo->stDpTimingInfo.usHStart);

    // Get 1/2 Video FIFO Size, unit is pixel clock
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        // FifoOffset = (1/2 * Video FIFO Size / (2 * depth per color)), color format is YCbCr 4:2:2
        usFifoOffset = _HW_DP_RX_VIDEO_FIFO_SIZE / (4 * (WORD)GET_COLOR_DEPTH());
    }
    else
    {
        // FifoOffset = (1/2 * Video FIFO Size / (3 * depth per color)), color format is RGB or YCbCr 4:4:4 or others
        usFifoOffset = _HW_DP_RX_VIDEO_FIFO_SIZE / (6 * (WORD)GET_COLOR_DEPTH());
    }

    // Get BS to VS Delay, unit is 1/2 link clock
    ulBsToVsDelay = ScalerComputeDwordMulDiv((ulVFrontPorch + ulHFrontPorch + (DWORD)usFifoOffset), pstDpInfo->stDpLinkInfo.ulLinkClockHz / 2, pstDpInfo->stDpLinkInfo.ulStreamClockHz);

    // Set BS to VS Delay of Odd Field
    ScalerSetByte(PB5_35_OVBLK2VS_H, LOBYTE(HIWORD(ulBsToVsDelay)));
    ScalerSetByte(PB5_36_OVBLK2VS_M, HIBYTE(LOWORD(ulBsToVsDelay)));
    ScalerSetByte(PB5_37_OVBLK2VS_L, LOBYTE(LOWORD(ulBsToVsDelay)));

    if(pstDpInfo->stDpLinkInfo.b1InterlaceOddMode == _TRUE)
    {
        // BStoVSDelay = BStoVSDelay + 1 Line(Unit is 1/2 Link Clock)
        ulBsToVsDelay += ScalerComputeDwordMulDiv((DWORD)pstDpInfo->stDpTimingInfo.usHTotal, pstDpInfo->stDpLinkInfo.ulLinkClockHz / 2, pstDpInfo->stDpLinkInfo.ulStreamClockHz);

//        SET_DP_MAC_RX0_INTERLACE_VTOTAL_NUMBER(_ODD);
    }
    else
    {
//        SET_DP_MAC_RX0_INTERLACE_VTOTAL_NUMBER(_EVEN);
    }

    // Set BS to VS Delay of Even Field
    ScalerSetByte(PB5_32_EVBLK2VS_H, LOBYTE(HIWORD(ulBsToVsDelay)));
    ScalerSetByte(PB5_33_EVBLK2VS_M, HIBYTE(LOWORD(ulBsToVsDelay)));
    ScalerSetByte(PB5_34_EVBLK2VS_L, LOBYTE(LOWORD(ulBsToVsDelay)));
}

//--------------------------------------------------
// Description  : DP Display Format Generator Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerDpRx0DisplayFormatSetting(StructDpInfo *pstDpInfo)
{
    WORD pusTemp[2];
    bit bDeOnlyModeJudge = _FALSE;

    ////////////////////////////////////
    // Display Format Generator Reset //
    ////////////////////////////////////

    // Disable Generate Display Format
    ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT7, 0x00);

    // Display Format Generator Reset
    ScalerSetBit(PB5_00_MAC_DIG_RESET_CTRL, ~_BIT7, _BIT7);
    ScalerSetBit(PB5_00_MAC_DIG_RESET_CTRL, ~_BIT7, 0x00);


    //////////////////////////
    // Interlace Mode Check //
    //////////////////////////

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _FALSE)
#endif
    {
        if(ScalerDpRx0InterlaceCheck(pstDpInfo) == _TRUE)
        {
            DebugMessageRx0("7. DP MAC RX0: Interlace Mode - VTotal", pstDpInfo->stDpTimingInfo.usVTotal);
        }
        else
        {
            DebugMessageRx0("7. DP MAC RX0: Progressive Mode", 0);

            // Judge DE_Only Mode Use or not
            if(ScalerDpRx0DeOnlyJudge(pstDpInfo) == _TRUE)
            {
                bDeOnlyModeJudge = _TRUE;
            }
        }

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
        if(GET_DP_RX0_URGENT_LINK_LOSS() == _TRUE)
        {
            return _FALSE;
        }
#endif
    }

    ////////////////////////
    // Adjust Timing Info //
    ////////////////////////

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _FALSE)
#endif
    {
        // Check if MSA HSW is more than Hstart
        if(pstDpInfo->stDpTimingInfo.usHSWidth >= pstDpInfo->stDpTimingInfo.usHStart)
        {
            // Check if _DE_ONLY_MODE_HSW is more than Hstart
            if(_DE_ONLY_MODE_HSW >= pstDpInfo->stDpTimingInfo.usHStart)
            {
                // Adjust HSW = Hstart - 2
                pstDpInfo->stDpTimingInfo.usHSWidth = pstDpInfo->stDpTimingInfo.usHStart - 2;
            }
            else
            {
                // Adjust HSW = _DE_ONLY_MODE_HSW
                pstDpInfo->stDpTimingInfo.usHSWidth = _DE_ONLY_MODE_HSW;
            }
        }

        // Get HSW min by Measure clock
        pusTemp[0] = ((DWORD) _DP_HSYNC_WIDTH_MEASURE_COUNTER * GET_INPUT_PIXEL_CLK() * 100) / _MEASURE_CLK + 1;

        // Get Current H Blanking
        pusTemp[1] = pstDpInfo->stDpTimingInfo.usHTotal - pstDpInfo->stDpTimingInfo.usHWidth;

        // Check if HSW is less thane HSW min
        if(pstDpInfo->stDpTimingInfo.usHSWidth <= pusTemp[0])
        {
            // Check if H Blanking is more than HSW min
            if((pusTemp[1]) >= pusTemp[0])
            {
                // Adjust HSW = HSW min
                pstDpInfo->stDpTimingInfo.usHSWidth = pusTemp[0];
            }
            else
            {
                // Adjust HSW = Max H Porch
                pstDpInfo->stDpTimingInfo.usHSWidth = pusTemp[1];
            }
        }

        // Adjust VStart because V front porch must not be less than 2 line in scaling down block
        pstDpInfo->stDpTimingInfo.usVStart = pstDpInfo->stDpTimingInfo.usVTotal - pstDpInfo->stDpTimingInfo.usVHeight - GET_DP_RX0_VFRONT_PORCH();
    }


    ///////////////////////////////////
    // Display Format Timing Setting //
    ///////////////////////////////////

    // Set HTotal
    ScalerSetByte(PB5_41_MN_DPF_HTT_M, HIBYTE(pstDpInfo->stDpTimingInfo.usHTotal));
    ScalerSetByte(PB5_42_MN_DPF_HTT_L, LOBYTE(pstDpInfo->stDpTimingInfo.usHTotal));

    // Set HStart
    ScalerSetByte(PB5_43_MN_DPF_HST_M, HIBYTE(pstDpInfo->stDpTimingInfo.usHStart));
    ScalerSetByte(PB5_44_MN_DPF_HST_L, LOBYTE(pstDpInfo->stDpTimingInfo.usHStart));

    // Set HWidth
    ScalerSetByte(PB5_45_MN_DPF_HWD_M, HIBYTE(pstDpInfo->stDpTimingInfo.usHWidth));
    ScalerSetByte(PB5_46_MN_DPF_HWD_L, LOBYTE(pstDpInfo->stDpTimingInfo.usHWidth));

    // Set HSW
    ScalerSetByte(PB5_47_MN_DPF_HSW_M, HIBYTE(pstDpInfo->stDpTimingInfo.usHSWidth));
    ScalerSetByte(PB5_48_MN_DPF_HSW_L, LOBYTE(pstDpInfo->stDpTimingInfo.usHSWidth));

    // Set HSP = Positive
    ScalerSetBit(PB5_47_MN_DPF_HSW_M, ~_BIT7, ((BYTE)_SYNC_POLARITY_POSITIVE) << 7);

    // Set Vtotal
    ScalerSetByte(PB5_49_MN_DPF_VTT_M, HIBYTE(pstDpInfo->stDpTimingInfo.usVTotal));
    ScalerSetByte(PB5_4A_MN_DPF_VTT_L, LOBYTE(pstDpInfo->stDpTimingInfo.usVTotal));

    // Set VStart
    ScalerSetByte(PB5_4B_MN_DPF_VST_M, HIBYTE(pstDpInfo->stDpTimingInfo.usVStart));
    ScalerSetByte(PB5_4C_MN_DPF_VST_L, LOBYTE(pstDpInfo->stDpTimingInfo.usVStart));

    // Set VHeight
    ScalerSetByte(PB5_4D_MN_DPF_VHT_M, HIBYTE(pstDpInfo->stDpTimingInfo.usVHeight));
    ScalerSetByte(PB5_4E_MN_DPF_VHT_L, LOBYTE(pstDpInfo->stDpTimingInfo.usVHeight));

    // Set VSW
    ScalerSetByte(PB5_4F_MN_DPF_VSW_M, HIBYTE(pstDpInfo->stDpTimingInfo.usVSWidth));
    ScalerSetByte(PB5_50_MN_DPF_VSW_L, LOBYTE(pstDpInfo->stDpTimingInfo.usVSWidth));

    // Set VSP = Positive
    ScalerSetBit(PB5_4F_MN_DPF_VSW_M, ~_BIT7, ((BYTE)_SYNC_POLARITY_POSITIVE) << 7);

    // Set Color Format
    ScalerDpRx0VideoSetting();


    //////////////////////////////////////
    // Display Format Generator Setting //
    //////////////////////////////////////

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        //////////////////
        // DE Only Mode //
        //////////////////

        // Set Vsync Front Porch for DE Only Mode
        SET_DP_RX0_VFRONT_PORCH_REG(GET_DP_RX0_VFRONT_PORCH());

        // Set BS to HS Delay
        ScalerDpRx0SetBsToHsDelay(&(pstDpInfo->stDpTimingInfo));

        // Enable DP Freesync Mode(DRR Mode)
        ScalerSetBit(PB5_90_DP_RSV0, ~_BIT0, _BIT0);

        // Set DE Only Mode
        ScalerSetBit(PB5_30_DPF_CTRL_0, ~(_BIT5 | _BIT4), _BIT4);

        DebugMessageRx0("DP MAC RX0: Freesync Mode Enabled!!", ScalerGetByte(PB5_30_DPF_CTRL_0));
    }
    else
#endif
    {
        // Disable DP Freesync Mode(DRR mode)
        ScalerSetBit(PB5_90_DP_RSV0, ~_BIT0, 0x00);

        if(bDeOnlyModeJudge == _TRUE)
        {
            //////////////////
            // DE Only Mode //
            //////////////////

            // Set Vsync Front Porch for DE Only Mode
            SET_DP_RX0_VFRONT_PORCH_REG(GET_DP_RX0_VFRONT_PORCH());

            // Set BS to HS Delay
            ScalerDpRx0SetBsToHsDelay(&(pstDpInfo->stDpTimingInfo));

            // Set DE Only Mode
            ScalerSetBit(PB5_30_DPF_CTRL_0, ~(_BIT5 | _BIT4), _BIT4);

            DebugMessageRx0("DP MAC RX0: DE_Only Mode Enabled!!", ScalerGetByte(PB5_30_DPF_CTRL_0));
        }
        else
        {
            /////////////////////////
            // Full Last Line Mode //
            /////////////////////////

            // Set BS to VS Delay
            ScalerDpRx0SetBsToVsDelay(pstDpInfo);

            // Set Full Last Line Mode
            ScalerSetBit(PB5_30_DPF_CTRL_0, ~(_BIT5 | _BIT4), 0x00);

            DebugMessageRx0("DP MAC RX0: Full Last Line Mode Enable!!", ScalerGetByte(PB5_30_DPF_CTRL_0));
        }
    }

    // Choose VS Rising to Reset FIFO
    ScalerSetBit(PB5_20_PG_CTRL_0, ~_BIT5, 0x00);

    // Solve Abnormal Full Flag and Max. FIFO Level While Resetting by VSync
    ScalerSetBit(PB5_21_PG_CTRL_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0), _BIT7);

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Stream Clk PLL Setting
// Input Value  : None
// Output Value : True --> Stream CLK Regen. ok
//--------------------------------------------------
bit ScalerDpRx0StreamClkRegenerate(StructDpLinkInfo *pstDpLinkInfo)
{
    DWORD ulPllInputClockHz = 0;
    DWORD ulPllTargetClockHz = 0;
    DWORD ulDataPathSpeedLimit = (DWORD)(_DATA_PATH_SPEED_LIMIT * 100000);

    /////////////////////////////
    // PLL Input Clock Setting //
    /////////////////////////////

    // Set PLL Input Clock and Divider for Link Clock
    if(ScalerDpRx0SetPLLInputClockSetting(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), &ulPllInputClockHz, pstDpLinkInfo->ulLinkClockHz) == _FALSE)
    {
        return _FALSE;
    }

    DebugMessageRx0("DP MAC RX0: PLL In Clk", ulPllInputClockHz);


    //////////////////////////////
    // PLL Target Clock Setting //
    //////////////////////////////

    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)
    {
        // Enable YUV420 Output Clock
        ScalerSetBit(PB5_A2_PLL_OUT_CONTROL, ~_BIT6, _BIT6);

        // Set Pll Target Clock, Unit is Hz
        ulPllTargetClockHz = pstDpLinkInfo->ulStreamClockHz * 2;
    }
    else
    {
        // Disable YUV420 Output Clock
        ScalerSetBit(PB5_A2_PLL_OUT_CONTROL, ~_BIT6, 0x00);

        // Set Pll Target Clock, Unit is Hz
        ulPllTargetClockHz = pstDpLinkInfo->ulStreamClockHz;
    }

    DebugMessageRx0("DP MAC RX0: PLL Out Clk", ulPllTargetClockHz);


    ////////////////////////////////
    // PLL Output Divider Setting //
    ////////////////////////////////
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) &&
       (pstDpLinkInfo->ulStreamClockHz < ulDataPathSpeedLimit))
    {
        // sclk2x = sclk4x/2, sclk = sclk2x/2
        ScalerSetBit(PB5_A2_PLL_OUT_CONTROL, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
    }
    else
    {
        // sclk2x = sclk4x, sclk = sclk2x/2
        ScalerSetBit(PB5_A2_PLL_OUT_CONTROL, ~(_BIT5 | _BIT4 | _BIT3), _BIT4);
    }


    /////////////////////
    // PLL VCO Setting //
    /////////////////////

    if(ScalerDpRx0SetPLLFreqNf(ulPllTargetClockHz, ulPllInputClockHz) == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP NF PLL Tracking Enable
// Input Value  : StructDpMacRxInfo *pstDpInfo
// Output Value : True --> Tracking Stable
//--------------------------------------------------
bit ScalerDpRx0TrackingSetting(StructDpInfo *pstDpInfo)
{
    BYTE ucSscLineNumber = 0;
    WORD usHalfBSDelayCnt = 0;
    WORD usTemp = 0;
    WORD usFastLockTrakingFrames = 0;
    BYTE ucOneFrameTime = 0;

    // Disable Tracking
    ScalerSetBit(PB5_E0_VS_TRACK_EN, ~(_BIT7 | _BIT0), 0x00);

    // Set Tracking HTT
    ScalerSetByte(PB5_F2_DSC_HTT_0, HIBYTE(pstDpInfo->stDpTimingInfo.usHTotal >> 1));
    ScalerSetByte(PB5_F3_DSC_HTT_1, LOBYTE(pstDpInfo->stDpTimingInfo.usHTotal >> 1));

    // Set Tracking VTT
    ScalerSetByte(PB5_F4_DSC_VHT_0, HIBYTE(pstDpInfo->stDpTimingInfo.usVHeight));
    ScalerSetByte(PB5_F5_DSC_VHT_1, LOBYTE(pstDpInfo->stDpTimingInfo.usVHeight));

    //////////////////////////////////
    // HS Tracking Tracking Setting //
    //////////////////////////////////

    // Set HS Tracking
    ScalerSetBit(PB5_E1_VS_TRACK_MODE, ~_BIT7, _BIT7);

    // Avoid Too Large PE When Stream Clock is Smaller than 20MHz.
    if(pstDpInfo->stDpLinkInfo.ulStreamClockHz < 20000000)
    {
        // PE Clock = VCO Clock div 8
        ScalerSetByte(PB5_DA_MN_TRACKING_DIVS, 0x04);
    }
    else
    {
        // PE Clock = VCO Clock div 4
        ScalerSetByte(PB5_DA_MN_TRACKING_DIVS, 0x02);
    }

    // First Set Tracking Period with every line Tracking
    ScalerSetByte(PB5_E3_VS_TRACK1, 0x00);

    // DE Only Mode
    if(ScalerGetBit(PB5_30_DPF_CTRL_0, (_BIT5 | _BIT4)) == _BIT4)
    {
        // Get Half BS to BS delay (Counted by GDI_CLK) = HBs2BsCount / (1/2 * Link_clk) * GDI_clk / 2
        usHalfBSDelayCnt = ScalerComputeDwordMulDiv((DWORD)pstDpInfo->stDpLinkInfo.usHBsToBsCount, (DWORD)_GDI_CLK_KHZ, pstDpInfo->stDpLinkInfo.ulLinkClockHz / 1000);

#if(_DP_DE_ONLY_MODE_WITH_FULL_LAST_LINE_SUPPORT == _ON)
        // Enable Full Last Line mode for DE only mode
        ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT6, _BIT6);

        // Generate de_mod_de_window by cr_be (avoid BS lost case)
        ScalerSetBit(PB5_94_DP_RSV4, ~_BIT0, _BIT0);
#endif
    }
    else
    {
        // Get Half BS to BS delay (Counted by GDI_CLK) = HTotal / 2 * GDI_CLK(27MHz) / Stream Clock
        usHalfBSDelayCnt = ScalerComputeDwordMulDiv((DWORD)pstDpInfo->stDpTimingInfo.usHTotal, (DWORD)_GDI_CLK_KHZ, pstDpInfo->stDpLinkInfo.ulStreamClockHz / 500);
    }

    // Set Half BS to BS delay For Precision Mode
    ScalerSetBit(PB5_EA_HS_TRACKING_NEW_MODE1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usHalfBSDelayCnt));
    ScalerSetByte(PB5_EB_HS_TRACKING_NEW_MODE2, LOBYTE(usHalfBSDelayCnt));

    DebugMessageRx0("DP MAC RX0: Half BS2BS", usHalfBSDelayCnt);

    // Disable manual Htotal
    // ScalerSetBit(PB5_F2_DSC_HTT_0, ~_BIT7, 0x00);

    // Only Enable Tracking at Active Region
    ScalerDpRx0HSActiveTrackingMode(_DP_HS_TRACKING_FW_MODE);

    // Get 1 Frame Time, unit is ms
    ucOneFrameTime = pstDpInfo->stDpLinkInfo.ulVBsToBsCountN / _GDI_CLK_KHZ + 1;

    DebugMessageRx0("DP MAC RX0: Loop 1 Frame Time", ucOneFrameTime);

    /////////////////////////////////
    // 1st Tracking Fast Lock Mode //
    /////////////////////////////////

    // I Gain Clamp = 0x00 01 00 00

    // P Gain Clamp = 0x00 10 00 00
    ScalerDpRx0SetPLLPGainClampValue(0x00, 0x10, 0x00);

    // P Code = 0x0 00 FF FF
    ScalerSetBit(PB5_C9_MN_PI_CODE_1, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(PB5_CA_MN_PI_CODE_2, 0x00);
    ScalerSetByte(PB5_CB_MN_PI_CODE_3, 0xFF);
    ScalerSetByte(PB5_CC_MN_PI_CODE_4, 0xFF);

    // I Code = 0x08
    ScalerSetByte(PB5_C8_MN_PI_CODE_0, 0x08);

    // DE Only Mode
    if(ScalerGetBit(PB5_30_DPF_CTRL_0, (_BIT5 | _BIT4)) == _BIT4)
    {
        usFastLockTrakingFrames = 5;
    }
    else
    {
        usFastLockTrakingFrames = 3;
    }

    // Set PE Nonlock Threshold
    ScalerSetByte(PB5_E4_VS_TRACK2, 0x3F);

    // Set Fast Lock Mode
    ScalerSetBit(PB5_E1_VS_TRACK_MODE, ~(_BIT3 | _BIT2 | _BIT1), _BIT3);

    // Enable Tracking
    ScalerSetBit(PB5_E0_VS_TRACK_EN, ~(_BIT7 | _BIT0), _BIT7);

    usTemp = 0;

    // Waiting for Stream Clk Stable
    while(usTemp < 10)
    {
        // Clear PE Max Record
        ScalerSetByte(PB5_E5_VS_TRACK3, 0xFF);

        // Clear PE Flag
        ScalerSetBit(PB5_E0_VS_TRACK_EN, ~_BIT0, _BIT0);

        // Delay 1 Frame
        if(ScalerDpRx0TimerDelayXmsLinkCheck(ucOneFrameTime) == _FALSE)
        {
            return _FALSE;
        }

        usTemp++;

        // Fast lock mode tracking at least 2 Frames
        if((usTemp >= usFastLockTrakingFrames) && ((ScalerGetBit(PB5_E0_VS_TRACK_EN, _BIT0) == 0x00)))
        {
            break;
        }
    }

    DebugMessageRx0("DP MAC RX0: 1st PE Loop", usTemp);
    DebugMessageRx0("DP MAC RX0: 1st PE Max Record", ScalerGetByte(PB5_E5_VS_TRACK3));

    // Disable Tracking
    ScalerSetBit(PB5_E0_VS_TRACK_EN, ~(_BIT7 | _BIT0), 0x00);

    /////////////////////////////////
    // 2nd Tracking Presicion Mode //
    /////////////////////////////////

    // I Gain Clamp = 0x00 10 00 00

    // P Gain Clamp = 0x00 10 00 00
    ScalerDpRx0SetPLLPGainClampValue(0x00, 0x10, 0x00);

    // P Code = 0x0 00 FF FF
    ScalerSetBit(PB5_C9_MN_PI_CODE_1, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(PB5_CA_MN_PI_CODE_2, 0x00);
    ScalerSetByte(PB5_CB_MN_PI_CODE_3, 0xFF);
    ScalerSetByte(PB5_CC_MN_PI_CODE_4, 0xFF);

    // I Code = 0x04
    ScalerSetByte(PB5_C8_MN_PI_CODE_0, 0x04);

    // Set PE Nonlock Threshold
    ScalerSetByte(PB5_E4_VS_TRACK2, 0x1F);

    // Enable Precision Mode
    ScalerSetBit(PB5_E1_VS_TRACK_MODE, ~(_BIT3 | _BIT2 | _BIT1), _BIT2);

    // Enable Tracking
    ScalerSetBit(PB5_E0_VS_TRACK_EN, ~(_BIT7 | _BIT0), _BIT7);

    usTemp = 0;

    // Waiting for Stream Clk Stable
    do
    {
        // Clear PE Max Record
        ScalerSetByte(PB5_E5_VS_TRACK3, 0xFF);

        // Clear PE Flag
        ScalerSetBit(PB5_E0_VS_TRACK_EN, ~_BIT0, _BIT0);

        // Delay 1 Frame
        if(ScalerDpRx0TimerDelayXmsLinkCheck(ucOneFrameTime) == _FALSE)
        {
            return _FALSE;
        }

        usTemp++;
    }
    while((ScalerGetBit(PB5_E0_VS_TRACK_EN, _BIT0) == _BIT0) && (usTemp < 10));

    DebugMessageRx0("DP MAC RX0: 2nd PE Loop", usTemp);
    DebugMessageRx0("DP MAC RX0: 2nd PE Max Record", ScalerGetByte(PB5_E5_VS_TRACK3));

    // Get How Many Lines Per SSC Period
    // SSC(33khz)'s time to update.
    ucSscLineNumber = (BYTE)((pstDpInfo->stDpLinkInfo.ulStreamClockHz / pstDpInfo->stDpTimingInfo.usHTotal + 11500) / 33000);

    if(ucSscLineNumber > 0)
    {
        ucSscLineNumber--;
    }

    // Set Tracking Period
    ScalerSetByte(PB5_E3_VS_TRACK1, ucSscLineNumber);

    DebugMessageRx0("DP MAC RX0: Tracking Per Line", ScalerGetByte(PB5_E3_VS_TRACK1));

#if(_DP_DE_ONLY_MODE_WITH_FULL_LAST_LINE_SUPPORT == _OFF)
    // DE Only Mode
    if(ScalerGetBit(PB5_30_DPF_CTRL_0, (_BIT5 | _BIT4)) == _BIT4)
    {
        // Disable Tracking
        ScalerSetBit(PB5_E0_VS_TRACK_EN, ~(_BIT7 | _BIT0), 0x00);
    }
#endif

    /////////////////////////////////////
    // Display Format Generator Enable //
    /////////////////////////////////////

    // Start Generate Display Format
    ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT7, _BIT7);

    // Polling Vertical BS
    if(ScalerDpRx0PollingFlagLinkCheck(_DP_ONE_FRAME_TIME_MAX, PB6_01_DP_VBID, _BIT0, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Delay 1 Frame Time for PG Stable
    if(ScalerDpRx0TimerDelayXmsLinkCheck(ucOneFrameTime) == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP NF PLL Input Clock Setting
// Input Value  : Input Clock, Link Clock
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerDpRx0SetPLLInputClockSetting(EnumDpLinkRate enumLinkRate, DWORD *pulPllInputClockHz, DWORD ulLinkClockHz)
{
    BYTE ucprediv = 2;

    // [7:6] PLL Input Clock(Fin) : Link_Clk(27MHz),
    // [5] Enable DP14 Pixel Clock
    // [2] Video Select : 0(DP14), RL6851 not support DP20
    // [0] Tracking Sclk Clock : from local PLL

    ScalerSetBit(PB5_A3_PLL_IN_CONTROL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2 | _BIT0), (_BIT6 | _BIT5));

    // If Fin = Link CLock, Set Divdier for Link Clock
    if(ScalerGetBit(PB5_A3_PLL_IN_CONTROL, (_BIT7 | _BIT6)) == _BIT6)
    {
        switch(enumLinkRate)
        {
            case _DP_LINK_HBR3:

                // predivider = (1/2 link clk) / 27M
                ucprediv = _DP_LINK_HBR3 / 2;

                // Set Pll Input Clock, Unit is Hz
                *pulPllInputClockHz = ulLinkClockHz / _DP_LINK_HBR3;

                break;

            case _DP_LINK_HBR2:

                // predivider = (1/2 link clk) / 27M
                ucprediv = _DP_LINK_HBR2 / 2;

                // Set Pll Input Clock, Unit is Hz
                *pulPllInputClockHz = ulLinkClockHz / _DP_LINK_HBR2;

                break;

            case _DP_LINK_HBR:

                // predivider = (1/2 link clk) / 27M
                ucprediv = _DP_LINK_HBR / 2;

                // Set Pll Input Clock, Unit is Hz
                *pulPllInputClockHz = ulLinkClockHz / _DP_LINK_HBR;

                break;

            case _DP_LINK_RBR:

                // predivider = (1/2 link clk) / 27M
                ucprediv = _DP_LINK_RBR / 2;

                // Set Pll Input Clock, Unit is Hz
                *pulPllInputClockHz = ulLinkClockHz / _DP_LINK_RBR;

                break;

            default:

                return _FALSE;
        }
    }
    else
    {
        // Unit is Hz
        *pulPllInputClockHz = _GDI_CLK_KHZ * 1000;
    }

    ScalerSetByte(PB5_A4_M2PLL_DIVIDER0, (ucprediv - 2));

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP NF PLL Setting
// Input Value  : None
// Output Value : ulvcoFreq --> VCO Frequency Value
//--------------------------------------------------
bit ScalerDpRx0SetPLLFreqNf(DWORD ulPllTargetClockHz, DWORD ulPllInputClockHz)
{
    BYTE ucpllo = 0;
    BYTE ucdivs = 0;
    BYTE ucBuf = 0;
    BYTE ucdiv_pllo = 1;
    BYTE ucdiv_divs = 1;
    BYTE ucNcode = 0;
    BYTE ucFcode_MSB4b = 0;
    WORD usFcode_LSB16b = 0;
    DWORD ulPllVcoClockHz = 0;
    bit bPllVcoHighFreqStatus = _FALSE;

    if((ulPllTargetClockHz < 700000000) && (ulPllTargetClockHz >= 350000000))
    {
        // Total Div = 1
        ucpllo = 0;
        ucdivs = 0;
    }
    else if((ulPllTargetClockHz < 350000000) && (ulPllTargetClockHz >= 5468750))
    {
        if((ulPllTargetClockHz < 350000000) && (ulPllTargetClockHz >= 175000000))
        {
            // Total Div = 2
            ucpllo = 1;
            ucdivs = 0;
        }
        else if((ulPllTargetClockHz < 175000000) && (ulPllTargetClockHz >= 87500000))
        {
            // Total Div = 4
            ucpllo = 2;
            ucdivs = 0;
        }
        else if((ulPllTargetClockHz < 87500000) && (ulPllTargetClockHz >= 43750000))
        {
            // Total Div = 8
            ucpllo = 3;
            ucdivs = 0;
        }
        else if((ulPllTargetClockHz < 43750000) && (ulPllTargetClockHz >= 21875000))
        {
            // Total Div = 16
            ucpllo = 3;
            ucdivs = 1;
        }
        else if((ulPllTargetClockHz < 21875000) && (ulPllTargetClockHz >= 10937500))
        {
            // Total Div = 32
            ucpllo = 3;
            ucdivs = 3;
        }
        else
        {
            // Total Div = 64
            ucpllo = 3;
            ucdivs = 7;
        }
    }
    else
    {
        return _FALSE;
    }

    ucdiv_divs = ucdivs + 1;

    if(ucpllo != 0)
    {
        ucdiv_pllo = 1;

        for(ucBuf = 0; ucBuf < ucpllo; ucBuf++)
        {
            ucdiv_pllo = 2 * ucdiv_pllo;
        }
    }
    else
    {
        ucdiv_pllo = 1;
    }

    // Get PLL VCO Clock
    ulPllVcoClockHz = ulPllTargetClockHz * ucdiv_divs * ucdiv_pllo;

    // Get N Code
    ucNcode = ulPllVcoClockHz / ulPllInputClockHz;

    // Get F Code
    ucFcode_MSB4b = ((ulPllVcoClockHz - ulPllInputClockHz * ucNcode) << 4) / ulPllInputClockHz;
    usFcode_LSB16b = ScalerComputeDwordMulDiv((((ulPllVcoClockHz - ulPllInputClockHz * ucNcode) << 4) - ucFcode_MSB4b * ulPllInputClockHz), 1UL << 16, ulPllInputClockHz);

    ScalerDpRx0SetPLLNfOffProc(ulPllVcoClockHz, ucNcode, ucpllo, ucdivs);

    if(ScalerDpRx0SetPLLNfOnProc(ucNcode, ucFcode_MSB4b, usFcode_LSB16b, bPllVcoHighFreqStatus) == _FALSE)
    {
        return _FALSE;
    }

    DebugMessageRx0("DP MAC RX0: PLL Vco Clk", ulPllVcoClockHz);

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP NF PLL Setting for PLL Power Off Process
// Input Value  : ulvcoFreq --> VCO Frequency(Hz)
//              : ucNcode --> PLL N Code
//              : ucpllo --> divider o code
//              : ucdivs --> divider s code
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetPLLNfOffProc(DWORD ulPllVcoClockHz, BYTE ucNcode, BYTE ucpllo, BYTE ucdivs)
{
    // Power Off PLL
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~_BIT0, _BIT0);

    // Set Rs, Cs, Icp
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // Icp set 2.5uA, 5uA, 7.5uA, 10uA......                                                        //
    // Precise formula of Chrage Pump Current depends on DPM, resistor, and band.                   //
    // _ERROR_PRONE_CODE If VCO band = 'b00, Icp = (1400 * N* 2 * pi) /  (810  * 0xB5A6[7:5]).      //
    // _ERROR_PRONE_CODE If VCO band = 'b01, Icp = (1400 * N * 2 * pi) / (1418 * 0xB5A6[7:5]).      //
    // _ERROR_PRONE_CODE If VCO band = 'b10, Icp = (1400 * N * 2 * pi) / (1804 * 0xB5A6[7:5]).      //
    // _ERROR_PRONE_CODE If VCO band = 'b11, Icp = (1400 * N * 2 * pi) / (2063 * 0xB5A6[7:5]).      //
    // 700: DPLL max frequency design target is 700MHz; 778: Frequency curve in band00 is 778MHz.   //
    // Assume DPLL_M=0x13, DPM=0x13+2=21; DPN=2; reg_dpll_vcomd='b01; reg_dpll_rs[2:0]='b011;       //
    // Icp = (700 * 21 * 2 * 3.14) / (1340 * 13)                                                    //
    //////////////////////////////////////////////////////////////////////////////////////////////////

    // Kvco
    PDATA_DWORD(0) = 4000;

    // Icp = loopdivider / 4
    PDATA_DWORD(0) = (ucNcode * 20) / 4;
    pData[1] = (PDATA_DWORD(0) + 25) / 50;
    pData[1] -= (pData[1] == 0) ? 0 : 1;

    // Set Icp , RS:default 9K, RS:reserved, Icp = 2.5uA + 2.5uA*bit[0] + 5uA*bit[1] + 10uA*bit[2]
    pData[2] = (_BIT7 | _BIT4 | _BIT3 | (pData[1] & 0x07));
    ScalerSetByte(PB5_A6_M2PLL_0, pData[2]);

    // Set Vco Band11, Ipi
    if(ulPllVcoClockHz < 400000000)
    {
        pData[1] = 0;
    }
    else if(ulPllVcoClockHz < 500000000)
    {
        pData[1] = 1;
    }
    else if(ulPllVcoClockHz < 600000000)
    {
        pData[1] = 2;
    }
    else
    {
        pData[1] = 3;
    }

    // Set Ipi , VCO Band:11, Disable PI bypass
    ScalerSetBit(PB5_A7_M2PLL_1, ~(_BIT2 | _BIT1 | _BIT0), (pData[1] & 0x03));

    // Set CP Enable, close loop. Set Vc, Set LPF Enable
    ScalerSetBit(PB5_AA_M2PLL_DUMMY, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT0));

    // Set VCO Mode
    ScalerSetBit(PB5_A7_M2PLL_1, ~_BIT7, _BIT7);

    // Set preDiv byPass, Output Div
    ScalerSetBit(PB5_A5_M2PLL_DIVIDER1, ~(_BIT7 | _BIT1 | _BIT0), ucpllo);
    ScalerSetBit(PB5_A2_PLL_OUT_CONTROL, ~(_BIT2 | _BIT1 | _BIT0), ucdivs);
}

//--------------------------------------------------
// Description  : DP NF PLL Setting for PLL Power Off Process
// Input Value  : ucNcode --> PLL N Code
//              : ucFcode_MSB4b --> PLL F Code (MSB 4 bits)
//              : usFcode_LSB16b --> PLL F Code (LSB 16 bits)
// Output Value : None
//--------------------------------------------------
bit ScalerDpRx0SetPLLNfOnProc(BYTE ucNcode, BYTE ucFcode_MSB4b, WORD usFcode_LSB16b, bit bPllVcoHighFreqStatus)
{
    // PI Control Enable
    ScalerSetBit(PB5_C5_TRACKING_5, ~(_BIT7 | _BIT6), _BIT7);

    // Power On M2PLL
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~_BIT0, 0x00);

    // Delay 200us
    // Delay Time us [200,x]
    DELAY_XUS(200);

    // Enable VCO/4 & High VCO frequency
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~(_BIT7 | _BIT6), (_BIT7 | (((BYTE)bPllVcoHighFreqStatus) << 6)));

    // Check N code must set to >= 5
    ucNcode = ucNcode - 2;

    if(ucNcode < 5)
    {
        DebugMessageRx0("DP MAC RX0: PLL N Code is out of Spec", ucNcode);

        ucNcode = 5;

        return _FALSE;
    }

    // Set Limits Before NF Code Setting
    // Avoid HDMI change Limits
    ScalerSetByte(PB5_B1_N_F_MAX, 0x43);
    ScalerSetByte(PB5_B2_N_F_MIN, 0x07);

    // Set N[7:0]
    ScalerSetByte(PB5_AD_N_F_CODE_1, ucNcode);

    // Set F[19:16] Code
    ScalerSetByte(PB5_AE_N_F_CODE_2, (ucFcode_MSB4b & 0x0F));

    // Set F[15:8] Code
    ScalerSetByte(PB5_AF_N_F_CODE_3, ((usFcode_LSB16b & 0xFF00) >> 8));

    // Set F[7:0] Code
    ScalerSetByte(PB5_B0_N_F_CODE_4, (usFcode_LSB16b & 0x00FF));

    // Load N.F
    ScalerSetBit(PB5_AC_N_F_CODE_0, ~_BIT0, _BIT0);

    // Power Off M2PLL
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~_BIT0, _BIT0);

    // Power On M2PLL
    ScalerSetBit(PB5_A8_M2PLL_CONTROL, ~_BIT0, 0x00);

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP NF PLL P Gain Clamp Setting
// Input Value  : ucPGainB3 --> p_gain_clamp_value[26:24]
//              : ucPGainB2 --> p_gain_clamp_value[15:8]
//              : ucPGainB1 --> p_gain_clamp_value[7:0]
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetPLLPGainClampValue(BYTE ucPGainB3, BYTE ucPGainB2, BYTE ucPGainB1)
{
    // 1st tracking : 0x0 10 00 00
    // 2nd tracking : 0x0 01 00 00
    ScalerSetByte(PB5_D1_MN_PI_CODE_9, ucPGainB3);
    ScalerSetByte(PB5_D2_MN_PI_CODE_A, ucPGainB2);
    ScalerSetByte(PB5_D3_MN_PI_CODE_B, ucPGainB1);
    ScalerSetByte(PB5_D4_MN_PI_CODE_C, 0x00);
}

//--------------------------------------------------
// Description  : DP Adjust Vsync Delay
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0AdjustVsyncDelay(void)
{
    DWORD ulBStoVSDelayDeltaOverflow = 0;
    DWORD ulBStoVSDelayDeltaUnderflow = 0;

    if(ScalerGetBit(PB5_21_PG_CTRL_1, (_BIT1 | _BIT0)) == 0x00)// Fifo Ok
    {
        return;
    }
    else if(ScalerGetBit(PB5_21_PG_CTRL_1, _BIT0) == _BIT0) // Fifo Overflow
    {
        // Get Htotal
        ScalerRead(PB6_08_MSA_HTT_0, 2, &pData[0], _AUTOINC);

        // ((Link Clk * 256)/ Stream CLK) * Htotal / 256 --> 1 Line
        ulBStoVSDelayDeltaOverflow = (((DWORD)ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) * 270UL) * 256) / ((DWORD)GET_INPUT_PIXEL_CLK()) * ((DWORD)PDATA_WORD(0)) / 256;

        DebugMessageRx0("7. Fifo Overflow --> nVidia Case", ulBStoVSDelayDeltaOverflow);
    }
    else if(ScalerGetBit(PB5_21_PG_CTRL_1, _BIT1) == _BIT1) // Fifo Underflow
    {
        // Get Hactive
        ScalerRead(PB6_0C_MSA_HWD_0, 2, &pData[0], _AUTOINC);

        if(PDATA_WORD(0) != 1366)
        {
            return;
        }

        PDATA_WORD(0) = PDATA_WORD(0) - 2;

        // Set Hactive
        ScalerSetBit(PB5_45_MN_DPF_HWD_M, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(PDATA_WORD(0)));
        ScalerSetByte(PB5_46_MN_DPF_HWD_L, LOBYTE(PDATA_WORD(0)));

        // ((Link Clk * 2)/ Stream CLK) --> 2 pixels
        ulBStoVSDelayDeltaUnderflow = (((DWORD)ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) * 270) * 2) / ((DWORD)GET_INPUT_PIXEL_CLK());

        DebugMessageRx0("7. Fifo Underflow --> QD882 Case", ulBStoVSDelayDeltaUnderflow);
    }

    // For Initial Value Before Use PDATA_DWORD(0)
    pData[0] = 0;

    // Get BStoVSDelay Even
    ScalerRead(PB5_32_EVBLK2VS_H, 3, &pData[1], _AUTOINC);

    // For Initial Value Before Use PDATA_DWORD(1)
    pData[4] = 0;

    // Get BStoVSDelay Odd
    ScalerRead(PB5_35_OVBLK2VS_H, 3, &pData[5], _AUTOINC);

    // BStoVSDelay = BStoVSDelay + (Nvid * 256 / Mvid) * ((DWORD)Htotal) / 256;
    PDATA_DWORD(0) = PDATA_DWORD(0) - ((ulBStoVSDelayDeltaOverflow + ulBStoVSDelayDeltaUnderflow) / 2);

    // BStoVSDelay = BStoVSDelay + (Nvid * 256 / Mvid) * ((DWORD)Htotal) / 256;
    PDATA_DWORD(1) = PDATA_DWORD(1) - ((ulBStoVSDelayDeltaOverflow + ulBStoVSDelayDeltaUnderflow) / 2);

    // Set Even Field BS to VS Delay
    ScalerSetByte(PB5_32_EVBLK2VS_H, pData[1]);
    ScalerSetByte(PB5_33_EVBLK2VS_M, pData[2]);
    ScalerSetByte(PB5_34_EVBLK2VS_L, pData[3]);

    // Set Odd Field BS to VS Delay
    ScalerSetByte(PB5_35_OVBLK2VS_H, pData[5]);
    ScalerSetByte(PB5_36_OVBLK2VS_M, pData[6]);
    ScalerSetByte(PB5_37_OVBLK2VS_L, pData[7]);

    // Double Buffer to Apply Display Format Setting(RL6851 have no double buffer for Display FOrmat setting)
    // ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT6, _BIT6);

    // Reset Display Format Gen
    ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT7, 0x00);
    ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT7, _BIT7);

    // Polling Vertical BS
    if(ScalerDpRx0PollingFlagLinkCheck(50, PB6_01_DP_VBID, _BIT0, _TRUE) == _FALSE)
    {
        return;
    }

    // Delay for PG Stable
    if(ScalerDpRx0TimerDelayXmsLinkCheck(_DP_ONE_FRAME_TIME_MAX) == _FALSE)
    {
        return;
    }
}

//--------------------------------------------------
// Description  : DP HDCP Measure Check
// Input Value  : None
// Output Value : FALSE => Measure Check Fail
//--------------------------------------------------
bit ScalerDpRx0HdcpMeasureCheck(void)
{
    DWORD ulLinkClk = 0;
    WORD usHTotalCount = 0;

    // Pop up Main Stream Attributes
    ScalerSetBit(PB6_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT3));

    // Get Vtotal
    ScalerRead(PB6_10_MSA_VTTE_0, 2, &pData[10], _AUTOINC);

    if(PDATA_WORD(5) == 0)
    {
        return _FALSE;
    }

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        return _FALSE;
    }
#endif

    // [5] ln_ck_sel = 1'b1 -> CDR Clock
    // [4:0] DP_XTAL_CYCLE = 5'b00100 -> XTAL Counter Cycles = 2000
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT0), (_BIT5 | _BIT0));

    // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Waiting for Measure Done
    ScalerTimerDelayXms(2);

    if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
    {
        PDATA_WORD(0) = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));
    }
    else
    {
        // For RL6851,GDI_CLK is 28.6MHz
        if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2)
        {
            PDATA_WORD(0) = 0x49C1;
        }
        else if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR)
        {
            PDATA_WORD(0) = 0x24E1;
        }
        else // Both Default && _DP_LINK_RBR Case
        {
            PDATA_WORD(0) = 0x1620;
        }
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    PDATA_DWORD(0) = (((DWORD)PDATA_WORD(0)) * _GDI_CLK_KHZ);

    // Link Clk in KHz
    ulLinkClk = (PDATA_DWORD(0) / 1000);

    DebugMessageRx0("Current Link Clk", ulLinkClk);

    // Start to Measure Vertical BS to BS Counter by GDI Clock
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

    if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PB5_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Pop up The result
    SET_DP_RX0_MEASURE_POP_UP();

    // Get Measure Result
    ScalerRead(PB5_58_MN_MEAS_CTRL, 3, &pData[1], _AUTOINC);

    // Get Measure Htotal Counts
    ScalerRead(PB5_5B_MN_MEAS_HLN_M, 2, &pData[6], _AUTOINC);

    // Disable Measure Block
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);

    // Convert HTotal Count from 1/2 Link Clk to GDI Clk
    usHTotalCount = ((DWORD)PDATA_WORD(3) * _GDI_CLK_KHZ * 2 + (ulLinkClk >> 1)) / ulLinkClk;

    PDATA_DWORD(0) = (PDATA_DWORD(0) & 0x001FFFFF);
    PDATA_DWORD(1) = ((DWORD)usHTotalCount & 0x0000FFFF);

    PDATA_WORD(2) = PDATA_DWORD(0) / PDATA_DWORD(1);

    // 2% Tolerance
    if((ABSDWORD(PDATA_WORD(2), PDATA_WORD(5))) > (PDATA_WORD(5) * 2 / 100))
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Phy Setting in TP1 for PHY CTS
// Input Value  : FLD Reference Clock
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyCtsTp1SetPhy(EnumDpNFCodeRef enumDpNFCodeRef)
{
    BYTE ucIcp = (ScalerGetByte(PB_D2_ANA_CDR_03) & 0x0F);
    WORD usVCOAutoBand = 0;


    ////////////////////
    // Mode Select DP //
    ////////////////////

    // [5] dp_mode = 1'b1 --> Select DP Mode
    ScalerSetBit(PB_B1_PORT_SEL, ~_BIT5, _BIT5);

    // [0] hd_dp_sel = 1'b0 --> Select DP
    ScalerSetBit(PB_00_HD_DP_SEL, ~_BIT0, 0x00);

    // [3] PSM = 1'b0 --> Disable Clock Switch
    ScalerSetBit(PB_B0_CLK_DET, ~_BIT3, 0x00);

    // [6] reg_bypass_ok = 1'b0 --> Disable bypass ok
    ScalerSetBit(PB_C9_KOFFSET_02, ~_BIT6, 0x00);


    /////////////////////////////
    // MAC Lane Swap Selection //
    /////////////////////////////

    // DP Lane Swap Setting
    ScalerSetBit(PB_03_LANE_MUX, ~(_BIT7 | _BIT6), _D0_DP_LANE3 << 6);
    ScalerSetBit(PB_03_LANE_MUX, ~(_BIT5 | _BIT4), _D0_DP_LANE2 << 4);
    ScalerSetBit(PB_03_LANE_MUX, ~(_BIT3 | _BIT2), _D0_DP_LANE1 << 2);
    ScalerSetBit(PB_03_LANE_MUX, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

    // DP Lane PN Swap Setting
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~_BIT7, GET_DP_RX0_PCB_LANE3_PN_SWAP() << 7);
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~_BIT6, GET_DP_RX0_PCB_LANE2_PN_SWAP() << 6);
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~_BIT5, GET_DP_RX0_PCB_LANE1_PN_SWAP() << 5);
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~_BIT4, GET_DP_RX0_PCB_LANE0_PN_SWAP() << 4);


    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////

    // [2] cmu_en = 1'b0 --> Lane3 CMU Disable
    ScalerSetBit(PB_B0_CLK_DET, ~_BIT2, 0x00);

    // Disable RX_EN, CDR_EN
    ScalerSetByte(PB_B2_ENABLE, 0x00);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        case 0x10:

            // dp_bbpd_sel[5:4] = 2'b01 --> ACDR BBPD UP/DN from Lane1
            ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), _BIT4);

            // ln_clk_func_sel[1:0] = 2'b01 --> MAC Clock from Analog Lane1
            ScalerSetBit(PB_96_LINK_CLOCK_SELECT, ~(_BIT1 | _BIT0), _BIT0);

            // Lane1 Test, Enable RX_EN/CDR_EN for Lane1/3
            ScalerSetByte(PB_B2_ENABLE, 0xAA);

            break;

        case 0x20:

            // dp_bbpd_sel[5:4] = 2'b10 --> ACDR BBPD UP/DN from Lane2
            ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), _BIT5);

            // ln_clk_func_sel[1:0] = 2'b10 --> MAC Clock from Analog Lane2
            ScalerSetBit(PB_96_LINK_CLOCK_SELECT, ~(_BIT1 | _BIT0), _BIT1);

            // Lane2 Test, Enable RX_EN/CDR_EN for Lane2/3
            ScalerSetByte(PB_B2_ENABLE, 0xCC);

            break;

        case 0x30:

            // dp_bbpd_sel[5:4] = 2'b11 --> ACDR BBPD UP/DN from Lane3
            ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

            // ln_clk_func_sel[1:0] = 2'b11 --> MAC Clock from Analog Lane3
            ScalerSetBit(PB_96_LINK_CLOCK_SELECT, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Lane3 Test, Enable RX_EN/CDR_EN for Lane3
            ScalerSetByte(PB_B2_ENABLE, 0x88);

            break;

        default:
        case 0x00:

            // dp_bbpd_sel[5:4] = 2'b00 --> ACDR BBPD UP/DN from Lane0
            ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT5 | _BIT4), 0x00);

            // ln_clk_func_sel[1:0] = 2'b00 --> MAC Clock from Analog Lane0
            ScalerSetBit(PB_96_LINK_CLOCK_SELECT, ~(_BIT1 | _BIT0), 0x00);

            // Lane0 Test, Enable RX_EN/CDR_EN for Lane0/3
            ScalerSetByte(PB_B2_ENABLE, 0x99);

            break;
    }

    // Delay Time us [25,x]
    DELAY_25US();

    // Enable Analog CDR and FLD
    ScalerSetBit(PB_AF_ANA_CDR_TIMER, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

    // Enable CCO LDO
    ScalerSetBit(PB_C2_CCO, ~_BIT7, _BIT7);

    // [4:3] One Lane Test
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), _BIT3);


    ///////////////////////
    // Frequency Setting //
    ///////////////////////

    if(enumDpNFCodeRef == _DP_NF_REF_XTAL)
    {
        // [7] xtal_en = 1'b1 --> FLD using xtal as reference clock
        ScalerSetBit(PB_D1_ANA_CDR_02, ~_BIT7, _BIT7);

#if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_200M) // GDI Clock = 28.6M
        if((g_ucDpRx0PhyCtsCtrl & 0xC0) == 0x00)   // RBR = 43/487 = 5*(28.6M/1.62G)
        {
            // ref_conuter = 43
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x2A);

            // cdr_counter = 487
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xE6);
        }
        else  // HBR = 26/492 = 5*(28.6M/2.7G)
        {
            // ref_conuter = 26
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x19);

            // cdr_counter = 491
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xEA);
        }
#elif((_M2PLL_FREQ_SEL == _M2PLL_FREQ_189M) || (_M2PLL_FREQ_SEL == _M2PLL_FREQ_216M)) // GDI Clock = 27M
        if((g_ucDpRx0PhyCtsCtrl & 0xC0) == 0x00)   // RBR = 40/480 = 5*(27M/1.62G)
        {
            // ref_conuter = 40
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x27);

            // cdr_counter = 480
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xE0);
        }
        else  // HBR = 25/500 = 5*(27M/2.7G)
        {
            // ref_conuter = 25
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x18);

            // cdr_counter = 500
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xF4);
        }
#elif(_M2PLL_FREQ_SEL == _M2PLL_FREQ_220M) // GDI Clock = 27.5M
        if((g_ucDpRx0PhyCtsCtrl & 0xC0) == 0x00)   // RBR = 32/377 = 5*(27.5M/1.62G)
        {
            // ref_conuter = 32
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x1F);

            // cdr_counter = 377
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0x79);
        }
        else  // HBR = 25/491 = 5*(27.5M/2.7G)
        {
            // ref_conuter = 25
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
            ScalerSetByte(PB_D8_ANA_CDR_09, 0x18);

            // cdr_counter = 491
            ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
            ScalerSetByte(PB_D9_ANA_CDR_10, 0xEB);
        }
#endif
    }
    else
    {
        // [7] xtal_en = 1'b1 --> D10.2 clock
        ScalerSetBit(PB_D1_ANA_CDR_02, ~_BIT7, 0x00);

        // ref_conuter = 250
        ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT7, 0x00);
        ScalerSetByte(PB_D8_ANA_CDR_09, 0xF9);

        // cdr_counter = 500
        ScalerSetBit(PB_D7_ANA_CDR_08, ~_BIT6, _BIT6);
        ScalerSetByte(PB_D9_ANA_CDR_10, 0xEB);
    }


    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // [4] Disable Comma Detection
    ScalerSetBit(PB_05_SAMPLE_EDGE, ~_BIT4, _BIT4);

    // [5] Disable De-Scrambling
    ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);

    // [2] Enable Enhancement Control Mode
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, _BIT2);

    // [1] bypass_clk_rdy = 1'b1 --> Clk Rdy Signal in Manual Mode
    // [0] en_clkout_manual = 1'b1 --> Enable Clkout
    ScalerSetBit(PB_AB_SDM_04, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

    // [1] bypass_eqen_rdy = 1'b1 --> EQEN Rdy Signal in Manual Mode
    // [0] en_eqen_manual = 1'b1 --> Enable EQ
    ScalerSetBit(PB_AD_EQEN_TIMER, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

    // [1] bypass_data_rdy = 1'b1 --> Data Rdy Signal in Manual Mode
    // [0] en_data_manual = 1'b0 --> Disable Dataout
    ScalerSetBit(PB_AE_DATA_TIMER, ~(_BIT1 | _BIT0), _BIT1);

    // [3] reg_en_data_manual_l3 = 1'b0 --> Disable Data Ready
    // [2] reg_bypass_data_rdy_l3 = 1'b1 --> Data Ready Signal in Manual Mode
    // [1] reg_en_eqen_manual_l3 = 1'b1 --> Enable EQ
    // [0] reg_bypass_eqen_rdy_l3 = 1'b1 --> EQ Ready Signal in Manual Mode
    ScalerSetBit(PB_AF_ANA_CDR_TIMER, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // Digital Circuit Reset Toggle
    ScalerSetByte(PB_DA_TMDS_RESET, 0x00);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        case 0x10:

            // Enable Lane1 DPHY
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT6, _BIT6);

            break;

        case 0x20:

            // Enable Lane2 DPHY
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT5, _BIT5);

            break;

        case 0x30:

            // Enable Lane3 DPHY
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT4, _BIT4);

            break;

        default:
        case 0x00:

            // Enable Lane0 DPHY
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT7, _BIT7);

            break;
    }


    ////////////////
    // EQ Setting //
    ////////////////

    // [4:0] reg_fore_off_adjr_Lane0~3 = 5'b10000
    ScalerSetBit(PB_CB_KOFFSET_04, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    ScalerSetBit(PB_CC_KOFFSET_05, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    ScalerSetBit(PB_CD_KOFFSET_06, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    ScalerSetBit(PB_CE_KOFFSET_07, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);

    if((g_ucDpRx0PhyCtsCtrl & 0xC0) == 0x00)   // RBR
    {
        // [3:0] cdr_kvco = 4'b1000 (Default)
        ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);

        // [7] le_lowgain_highboost = 1'b0 --> Disable LE High-boost Mode
        ScalerSetBit(PB_CC_KOFFSET_05, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

        // [7:5] le_isel = 3'b000 --> LE Peaking = 900Mbps
        ScalerSetBit(PB_CD_KOFFSET_06, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

        // [7:5] le_rlsel = 3'b011 --> LE Peaking = 900Mbps
        ScalerSetBit(PB_CE_KOFFSET_07, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));

        // Set DFE Initial
        ScalerDpRx0SetDFEInitial(_DP_LINK_RBR);

        // [6] en_cco_lp_mode = 1
        ScalerSetBit(PB_C2_CCO, ~_BIT6, _BIT6);
    }
    else
    {
        // [3:0] cdr_kvco = 4'b1010
        ScalerSetBit(PB_D1_ANA_CDR_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));

        // [7] le_lowgain_highboost = 1'b1 --> Enable LE High-boost Mode
        ScalerSetBit(PB_CC_KOFFSET_05, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

        // [7:5] le_isel = 3'b010 --> LE Peaking = 1.7Gbps
        ScalerSetBit(PB_CD_KOFFSET_06, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

        // [7:5] le_rlsel = 3'b001 --> LE Peaking = 1.7Gbps
        ScalerSetBit(PB_CE_KOFFSET_07, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

        // Set DFE Initial
        ScalerDpRx0SetDFEInitial(_DP_LINK_HBR);

        // [6] en_cco_lp_mode = 0
        ScalerSetBit(PB_C2_CCO, ~_BIT6, 0x00);
    }

    // [7] en_fore_offset = 1'b0 --> Disable EQ foreground Offset Calibration
    // [6] fore_off_autok = 1'b1 --> Enable EQ foreground Offset Calibration Auto Mode
    ScalerSetBit(PB_C8_KOFFSET_01, ~(_BIT7 | _BIT6), _BIT6);

    // Toggle en_fore_offset
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, 0x00);
    ScalerSetBit(PB_C8_KOFFSET_01, ~_BIT7, _BIT7);

    // Delay Time ~ 50us
    for(pData[0] = 0; pData[0] <= 20; pData[0]++)
    {
        DELAY_5US();

        if(((ScalerGetBit(PB_DA_TMDS_RESET, _BIT7) == 0x00) || (ScalerGetBit(PB_C7_KOFFSET_00, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT6) == 0x00) || (ScalerGetBit(PB_C8_KOFFSET_01, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT5) == 0x00) || (ScalerGetBit(PB_C9_KOFFSET_02, _BIT5) == _BIT5)) &&
           ((ScalerGetBit(PB_DA_TMDS_RESET, _BIT4) == 0x00) || (ScalerGetBit(PB_CA_KOFFSET_03, _BIT5) == _BIT5)))
        {
            break;
        }
    }


    ///////////////////
    // FLD Auto Mode //
    ///////////////////

    // Set FLD Auto Mode
    ScalerSetBit(PB_CF_ANA_CDR_00, ~_BIT7, _BIT7);

    // [2] cp_en_manual = 1'b0 --> CDR Open Loop
    // [1] adp_en_manual = 1'b0 --> Disable CDR Clock
    ScalerSetBit(PB_D0_ANA_CDR_01, ~(_BIT2 | _BIT1), 0x00);

    // [7] rstb_fld --> Reset Timer of Analog CDR
    // [6] rstb_fsm --> FLD Reset
    ScalerSetBit(PB_D3_ANA_CDR_04, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit(PB_D3_ANA_CDR_04, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Delay Time ~300us for HBR
    for(pData[0] = 0; pData[0] <= 100; pData[0]++)
    {
        DELAY_5US();

        if(ScalerGetBit(PB_E6_ST_02, (_BIT2 | _BIT1 | _BIT0)) == 0x05)
        {
            break;
        }
    }


    /////////////////////
    // FLD Manual Mode //
    /////////////////////

    // Scan Lane3 Auto FLD
    usVCOAutoBand = ((WORD)ScalerGetBit(PB_D4_ANA_CDR_05, _BIT2) << 6) + ScalerGetByte(PB_D6_ANA_CDR_07);
    ScalerSetBit(PB_D4_ANA_CDR_05, ~_BIT3, HIBYTE((WORD)usVCOAutoBand) << 3);
    ScalerSetByte(PB_D5_ANA_CDR_06, LOBYTE((WORD)usVCOAutoBand));

    // [7] reg_auto_mode = 1'b0 --> FLD Manual Mode
    ScalerSetBit(PB_CF_ANA_CDR_00, ~_BIT7, 0x00);

    // [3:0] reg_cdr_cp_in --> Double Icp to Enlarge Locking Range
    if(ucIcp > 7)
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    }
    else
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucIcp << 1));
    }

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [2] reg_cp_en_manual = 1'b1 --> CDR Close Loop
    // [1] adp_en_manual = 1'b1 --> Enable CDR Clock
    ScalerSetBit(PB_D0_ANA_CDR_01, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

    // Delay Time us [45,x] Waiting for VCO Stable
    DELAY_45US();

    // [3:0] reg_cdr_cp_in --> Restore Icp to Original Setting
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucIcp);

    // Delay Time us [45,x] Waiting for VCO Stable
    DELAY_45US();

    // [0] en_data_manual = 1'b1 --> Enable Dataout
    ScalerSetBit(PB_AE_DATA_TIMER, ~_BIT0, _BIT0);

    // [3] en_data_manual_l3 = 1'b1 --> Enable Dataout for Lane3
    ScalerSetBit(PB_AF_ANA_CDR_TIMER, ~_BIT3, _BIT3);

    // [6] xclk_sel = 1'b0 --> Keep Link Clock from Analog
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, 0x00);

    // [1] dig_reset Toggle
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);
}

//--------------------------------------------------
// Description  : DP Phy Setting in TP2 for PHY CTS
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyCtsTp2SetPhy(void)
{
    WORD usBestVCOBand = 0;
    WORD usVCOBandDiff = 0;
    WORD usVCOAutoBandAdd4 = 0;
    WORD usVCOAutoBand = 0;
    BYTE ucIcp = (ScalerGetByte(PB_D2_ANA_CDR_03) & 0x0F);


    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // Enable Comma Detection
    ScalerSetBit(PB_05_SAMPLE_EDGE, ~_BIT4, 0x00);

    // Disable Enhancement Control Mode --> MAC
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, 0x00);

    // [0] en_data_manual = 1'b0 --> Disable Dataout
    ScalerSetBit(PB_AE_DATA_TIMER, ~_BIT0, 0x00);

    // [3] en_data_manual_l3 = 1'b0 --> Disable Dataout for Lane3
    ScalerSetBit(PB_AF_ANA_CDR_TIMER, ~_BIT3, 0x00);

    // Digital Circuit Reset Toggle
    ScalerSetByte(PB_DA_TMDS_RESET, 0x00);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        case 0x10:

            // Enable Lane1 DPHY
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT6, _BIT6);

            break;

        case 0x20:

            // Enable Lane2 DPHY
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT5, _BIT5);

            break;

        case 0x30:

            // Enable Lane3 DPHY
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT4, _BIT4);

            break;

        default:
        case 0x00:

            // Enable Lane0 DPHY
            ScalerSetBit(PB_DA_TMDS_RESET, ~_BIT7, _BIT7);

            break;
    }


    ////////////////////////
    //  FLD Band Finetune //
    ////////////////////////

    // Target Freq.
#if(_M2PLL_FREQ_SEL == _M2PLL_FREQ_200M) // GDI Clock = 28.6M
    if((g_ucDpRx0PhyCtsCtrl & 0xC0) == 0x00)
    {
        g_usDpRx0ClockTargetCount = 0xB10; // ideal 1.62G
    }
    else
    {
        g_usDpRx0ClockTargetCount = 0x1270; // ideal 2.7G
    }
#elif((_M2PLL_FREQ_SEL == _M2PLL_FREQ_189M) || (_M2PLL_FREQ_SEL == _M2PLL_FREQ_216M)) // GDI Clock = 27M
    if((g_ucDpRx0PhyCtsCtrl & 0xC0) == 0x00)
    {
        g_usDpRx0ClockTargetCount = 0xBB8; // ideal 1.62G
    }
    else
    {
        g_usDpRx0ClockTargetCount = 0x1388; // ideal 2.7G
    }
#elif(_M2PLL_FREQ_SEL == _M2PLL_FREQ_220M) // GDI Clock = 27.5M
    if((g_ucDpRx0PhyCtsCtrl & 0xC0) == 0x00)
    {
        g_usDpRx0ClockTargetCount = 0xB81; // ideal 1.62G
    }
    else
    {
        g_usDpRx0ClockTargetCount = 0x132D; // ideal 2.7G
    }
#endif

    // [2] reg_cp_en_manual = 1'b0 --> CDR Open Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, 0x00);

    // [5] ln_ck_sel = 1'b1 -> CDR Clock
    // [0] DP_XTAL_CYCLE = 1'b0 -> XTAL Counter Cycles = 1000
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT0), _BIT5);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        default:
        case 0x00: // Lane0 VCO Adjust

            // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), 0x00);

            break;

        case 0x10: // Lane1 VCO Adjust

            // [1:0] freqdet_lane_sel = 2'b01 -> Lane1
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _BIT0);

            break;

        case 0x20: // Lane2 VCO Adjust

            // [1:0] freqdet_lane_sel = 2'b10 -> Lane2
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _BIT1);

            break;

        case 0x30: // Lane3 VCO Adjust

            // [1:0] freqdet_lane_sel = 2'b11 -> Lane3
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            break;
    }

    // Scan Auto FLD + 4
    usVCOAutoBand = ((WORD)ScalerGetBit(PB_D4_ANA_CDR_05, _BIT2) << 6) + ScalerGetByte(PB_D6_ANA_CDR_07);
    ScalerSetBit(PB_D4_ANA_CDR_05, ~_BIT3, HIBYTE((WORD)usVCOAutoBand + 4) << 3);
    ScalerSetByte(PB_D5_ANA_CDR_06, LOBYTE((WORD)usVCOAutoBand + 4));

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT Value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Delay Time us [5,150] Polling for Measure Done
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        DELAY_5US();

        // FLD + 4 Measure Done
        if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
        {
            usVCOAutoBandAdd4 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

            // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

            break;
        }
    }


    /////////////////////////
    // VCO Band Difference //
    /////////////////////////

    // Scan Auto FLD
    ScalerSetBit(PB_D4_ANA_CDR_05, ~_BIT3, HIBYTE((WORD)usVCOAutoBand) << 3);
    ScalerSetByte(PB_D5_ANA_CDR_06, LOBYTE((WORD)usVCOAutoBand));

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT Value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Delay Time us [5,150] Polling for Measure Done
    for(pData[0] = 0; pData[0] <= 30; pData[0]++)
    {
        DELAY_5US();

        // FLD + 4 Measure Fail or Measure Done
        if((usVCOAutoBandAdd4 == 0) || (ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6))
        {
            break;
        }
    }

    // Measure Done
    if((ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6) && (usVCOAutoBandAdd4 != 0))
    {
        g_usDpRx0ClockMeasureCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

        usVCOBandDiff = (abs(usVCOAutoBandAdd4 - g_usDpRx0ClockMeasureCount) >> 2);

        if(g_usDpRx0ClockMeasureCount < g_usDpRx0ClockTargetCount)
        {
            // VCO Adjust
            usBestVCOBand = usVCOAutoBand + (((g_usDpRx0ClockTargetCount - g_usDpRx0ClockMeasureCount) / usVCOBandDiff) + 1);
        }
        else
        {
            // VCO Adjust
            usBestVCOBand = usVCOAutoBand - ((g_usDpRx0ClockMeasureCount - g_usDpRx0ClockTargetCount) / usVCOBandDiff);
        }
    }
    else
    {
        // Measure Fail -> Use Auto FLD Band
        usBestVCOBand = usVCOAutoBand;
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    // Manually Reload FLD Band
    ScalerSetBit(PB_D4_ANA_CDR_05, ~_BIT3, HIBYTE((WORD)usBestVCOBand) << 3);
    ScalerSetByte(PB_D5_ANA_CDR_06, LOBYTE((WORD)usBestVCOBand));

    // [3:0] reg_cdr_cp_in --> Double Icp to Enlarge Locking Range
    if(ucIcp > 7)
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    }
    else
    {
        ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ucIcp << 1));
    }

    // Delay Time us [25,x] Waiting for VCO Stable
    DELAY_25US();

    // [2] reg_cp_en_manual = 1'b1 --> CDR Close Loop
    ScalerSetBit(PB_D0_ANA_CDR_01, ~_BIT2, _BIT2);

    // Delay Time us [45,x] Waiting for VCO Stable
    DELAY_45US();

    // [3:0] reg_cdr_cp_in --> Restore Icp to Original Setting
    ScalerSetBit(PB_D2_ANA_CDR_03, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ucIcp);

    // Delay Time us [45,x] Waiting for VCO Stable
    DELAY_45US();

    // [0] en_data_manual = 1'b1 --> Enable Dataout
    ScalerSetBit(PB_AE_DATA_TIMER, ~_BIT0, _BIT0);

    // [3] en_data_manual_l3 = 1'b1 --> Enable Dataout for Lane3
    ScalerSetBit(PB_AF_ANA_CDR_TIMER, ~_BIT3, _BIT3);

    // [6] xclk_sel = 1'b0 --> Keep Link Clock from Analog
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, 0x00);

    // [1] dig_reset Toggle
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);
}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 1 for PHY CTS
// Input Value  : None
// Output Value : TRUE --> TP1 Pass
//--------------------------------------------------
bit ScalerDpRx0PhyCtsTp1Check(void)
{
    // Wait for 10ms
    ScalerTimerDelayXms(10);

    // Clear 8B/10B Decode Error Flags
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Wait for 2ms
    ScalerTimerDelayXms(2);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test

            // EQ auto K,Check lane0 CRC
            pData[0] = 0x10;
            pData[1] = 0x01;

            break;

        case 0x10: // Lane1 Test

            // EQ auto K,Check lane1 CRC
            pData[0] = 0x20;
            pData[1] = 0x02;

            break;

        case 0x20: // Lane2 Test

            // EQ auto K,Check lane2 CRC
            pData[0] = 0x40;
            pData[1] = 0x04;

            break;

        case 0x30: // Lane3 Test

            // EQ auto K,Check lane3 CRC
            pData[0] = 0x80;
            pData[1] = 0x08;

            break;

        default:

            pData[0] = 0x00;
            pData[1] = 0x00;

            break;
    }

    if(((ScalerGetByte(PB_06_DECODE_10B8B_ERROR) & pData[1]) == 0x00) &&
       ((ScalerGetByte(PB_14_EQ_CRC_3) & pData[0]) != 0x00))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP PHY CTS Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyCTS(void)
{
    // _ERROR_PRONE_CODE
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[3] = 0 --> PHY CTS Enable Start
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[2:0]) = 0x01 --> CDR
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[2:0]) = 0x02 --> EQ CRC
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[2:0]) = 0x03 --> PRBS7 Error Counter Reset and Counter Start
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[2:0]) = 0x04 --> PRBS7 Error Counter Read
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[2:0]) = 0x05 --> PHY CTS Disable
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[5:4]) = 00 --> lane0
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[5:4]) = 01 --> lane1
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[5:4]) = 10 --> lane2
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[5:4]) = 11 --> lane3
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[7:6]) = 00 --> RBR
    // g_ucDpRx0PhyCtsCtrl(Page0x0B B7[7:6]) = 01 --> HBR

    // ucPhyCtsAutoMode = 0x00 --> PHY CTS Manual Mode
    // ucPhyCtsAutoMode = 0xFF --> PHY CTS Auto Mode Enable
    // ucPhyCtsAutoMode = 0x01 --> PHY CTS TP1 Setphy
    // ucPhyCtsAutoMode = 0x11 --> PHY CTS TP1 Pass
    // ucPhyCtsAutoMode = 0xF1 --> PHY CTS TP1 Fail
    // ucPhyCtsAutoMode = 0x02 --> PHY CTS TP2 Setphy
    // ucPhyCtsAutoMode = 0x12 --> PHY CTS TP2 Pass
    // ucPhyCtsAutoMode = 0xF2 --> PHY CTS TP2 Fail
    // ucPhyCtsAutoMode = 0x03 --> PHY CTS Error Count Enable
    // ucPhyCtsAutoMode = 0x04 --> PHY CTS Error Count Lock
    // ucPhyCtsAutoMode = 0x05 --> PHY CTS Error Count Report

    WORD usErrorCount = 0;
    BYTE ucPhyCtsAutoMode = 0;

    g_ucDpRx0PhyCtsCtrl = 0x00;

    EX0 = 0;

    if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, _BIT7) == _BIT7)
    {
        ucPhyCtsAutoMode = 0xFF;

        while(ucPhyCtsAutoMode != 0x00)
        {
            ScalerDebug();

            if(ucPhyCtsAutoMode == 0x11)
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x11);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x11);
            }
            else if(ucPhyCtsAutoMode == 0x12)
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x77);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x77);
            }

            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x06, 0x22);
            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x07, 0x22);

            switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x02) & (_BIT1 | _BIT0))
            {
                case 0x01: // CDR Lock Check

                    if(ucPhyCtsAutoMode != 0x11)
                    {
                        // Link Rate
                        switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00))
                        {
                            case 0x0A:

                                g_ucDpRx0PhyCtsCtrl = ((g_ucDpRx0PhyCtsCtrl & 0x3F) | (_BIT6));

                                break;

                            default:
                            case 0x06:

                                g_ucDpRx0PhyCtsCtrl = (g_ucDpRx0PhyCtsCtrl & 0x3F);

                                break;
                        }

                        // Lane Select
                        switch(ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, (_BIT5 | _BIT4)))
                        {
                            default:
                            case 0x00: // Source Lane0

                                g_ucDpRx0PhyCtsCtrl = ((g_ucDpRx0PhyCtsCtrl & 0xCF) | (_D0_DP_LANE0 << 4));

                                break;

                            case 0x10: // Source Lane1

                                g_ucDpRx0PhyCtsCtrl = ((g_ucDpRx0PhyCtsCtrl & 0xCF) | (_D0_DP_LANE1 << 4));

                                break;

                            case 0x20: // Source Lane2

                                g_ucDpRx0PhyCtsCtrl = ((g_ucDpRx0PhyCtsCtrl & 0xCF) | (_D0_DP_LANE2 << 4));

                                break;

                            case 0x30: // Source Lane3

                                g_ucDpRx0PhyCtsCtrl = ((g_ucDpRx0PhyCtsCtrl & 0xCF) | (_D0_DP_LANE3 << 4));

                                break;
                        }

                        SET_DP_RX0_AUX_MANUAL_MODE_PHY_CTS();

                        ScalerDpRx0PhyCtsTp1SetPhy(_DP_NF_REF_XTAL);

                        ucPhyCtsAutoMode = 0x01;
                    }

                    if(ucPhyCtsAutoMode == 0x01)
                    {
                        if(ScalerDpRx0PhyCtsTp1Check() == _TRUE)
                        {
                            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x11);
                            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x11);

                            ucPhyCtsAutoMode = 0x11;
                        }
                        else
                        {
                            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x00);
                            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x00);

                            ucPhyCtsAutoMode = 0xF1;
                        }

                        SET_DP_RX0_AUX_AUTO_MODE_PHY_CTS();
                    }

                    break;

                case 0x02: // Symbol Lock Check by TPS2
                case 0x03: // Symbol Lock Check by TPS3
                case 0x07: // Symbol Lock Check by TPS4

                    if((ucPhyCtsAutoMode == 0x11) || (ucPhyCtsAutoMode == 0xF2))
                    {
                        SET_DP_RX0_AUX_MANUAL_MODE_PHY_CTS();

                        ScalerDpRx0PhyCtsTp2SetPhy();

                        ucPhyCtsAutoMode = 0x02;
                    }

                    if(ucPhyCtsAutoMode == 0x02)
                    {
                        if(ScalerDpRx0PhyCtsTp2Check() == _TRUE)
                        {
                            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x77);
                            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x77);

                            ucPhyCtsAutoMode = 0x12;
                        }
                        else
                        {
                            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x11);
                            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x11);

                            ucPhyCtsAutoMode = 0xF2;
                        }
                    }

                    SET_DP_RX0_AUX_AUTO_MODE_PHY_CTS();

                    if(ucPhyCtsAutoMode == 0x12)
                    {
                        // Mac Use Xtal Clk
                        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, _BIT6);

                        // Error Count Lane Select
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), (g_ucDpRx0PhyCtsCtrl & (_BIT5 | _BIT4)) >> 1);

                        // Disable Error Detection
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                        // Reverse PRBS7 Pattern Gen
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~_BIT6, _BIT6);

                        // Disable Scramble
                        ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);

                        // Reset DPCD Error Count
                        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x10, 0x00);
                        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x11, 0x00);
                        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x12, 0x00);
                        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x13, 0x00);
                        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x14, 0x00);
                        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x15, 0x00);
                        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x16, 0x00);
                        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x17, 0x00);

                        switch(ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, (_BIT5 | _BIT4)))
                        {
                            case (_BIT5 | _BIT4):

                                ScalerDpRx0SetDpcdBitValue(0x00, 0x02, 0x17, ~_BIT7, _BIT7);

                                break;

                            case (_BIT5):

                                ScalerDpRx0SetDpcdBitValue(0x00, 0x02, 0x15, ~_BIT7, _BIT7);

                                break;

                            case (_BIT4):

                                ScalerDpRx0SetDpcdBitValue(0x00, 0x02, 0x13, ~_BIT7, _BIT7);

                                break;

                            default:
                            case 0x00:

                                ScalerDpRx0SetDpcdBitValue(0x00, 0x02, 0x11, ~_BIT7, _BIT7);

                                break;
                        }
                    }

                    break;

                case 0x00:

                    if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, (0x0B + ((ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, (_BIT5 | _BIT4))) >> 4))) != 0x00)
                    {
                        if(ucPhyCtsAutoMode != 0x05) // Error Count Enable
                        {
                            // Error Count Enable
                            ucPhyCtsAutoMode = 0x03;

                            switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, (0x0B + ((ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, (_BIT5 | _BIT4))) >> 4))))
                            {
                                case 0x03: // PRBS7 Pattern

                                    // PRBS7 Pattern for RBR/HBR
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

                                    ScalerTimerDelayXms(2);

                                    // Error Count Lock
                                    ucPhyCtsAutoMode = 0x05;

                                    // Disable Wildcard IRQ for Error Counter
                                    ScalerSetBit(PB7_FB_DP0_MANUAL_DPCD_IRQ, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1 | _BIT0), 0x00);

                                    // Enable Read Error Counter IRQ, Clear IRQ Flag
                                    ScalerSetBit(PB7_FB_DP0_MANUAL_DPCD_IRQ, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

                                    break;

                                default:

                                    break;
                            }
                        }

                        while(ucPhyCtsAutoMode == 0x05) // Error Count Report
                        {
                            ScalerDebug();

                            usErrorCount = (((WORD)ScalerGetByte(PB_0B_BIST_PATTERN3)) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4);

                            ScalerTimerDelayXms(2);

                            switch(ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, (_BIT5 | _BIT4)))
                            {
                                case (_BIT5 | _BIT4):

                                    // Store Lane3 Error
                                    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x16, LOBYTE(usErrorCount));
                                    ScalerDpRx0SetDpcdBitValue(0x00, 0x02, 0x17, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usErrorCount));

                                    break;

                                case (_BIT5):

                                    // Store Lane2 Error
                                    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x14, LOBYTE(usErrorCount));
                                    ScalerDpRx0SetDpcdBitValue(0x00, 0x02, 0x15, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usErrorCount));

                                    break;

                                case (_BIT4):

                                    // Store Lane1 Error
                                    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x12, LOBYTE(usErrorCount));
                                    ScalerDpRx0SetDpcdBitValue(0x00, 0x02, 0x13, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usErrorCount));

                                    break;

                                default:
                                case 0x00:

                                    // Store Lane0 Error
                                    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x10, LOBYTE(usErrorCount));
                                    ScalerDpRx0SetDpcdBitValue(0x00, 0x02, 0x11, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(usErrorCount));

                                    break;
                            }

                            // If DPCD 0x0021xh Hit
                            if(ScalerGetBit(PB7_FB_DP0_MANUAL_DPCD_IRQ, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
                            {
                                // Clear IRQ Flag
                                ScalerSetBit(PB7_FB_DP0_MANUAL_DPCD_IRQ, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), _BIT1);

                                // Reset 8B/10B Error Counter
                                ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                                ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                            }
                            else if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, (0x0B + ((ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, (_BIT5 | _BIT4))) >> 4))) == 0x00)
                            {
                                ucPhyCtsAutoMode = 0xFF;
                            }
                        }
                    }
                    else if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, _BIT7) == 0x00)
                    {
                        ucPhyCtsAutoMode = 0x00;
                    }

                    break;

                default:

                    break;
            }
        }
    }
    else
    {
        while(GET_DP_RX0_PHY_CTS_FLG() == _TRUE)
        {
            ScalerDebug();

            DebugMessageRx0("7. PHY CTS Loop", ScalerGetByte(PB_B7_REG_RESERVED_FW_1));

            switch(ScalerGetByte(PB_B7_REG_RESERVED_FW_1) & 0x30)
            {
                default:
                case 0x00: // Source Lane0

                    ScalerSetBit(PB_B7_REG_RESERVED_FW_1, ~(_BIT5 | _BIT4), _D0_DP_LANE0 << 4);

                    break;

                case 0x10: // Source Lane1

                    ScalerSetBit(PB_B7_REG_RESERVED_FW_1, ~(_BIT5 | _BIT4), _D0_DP_LANE1 << 4);

                    break;

                case 0x20: // Source Lane2

                    ScalerSetBit(PB_B7_REG_RESERVED_FW_1, ~(_BIT5 | _BIT4), _D0_DP_LANE2 << 4);

                    break;

                case 0x30: // Source Lane3

                    ScalerSetBit(PB_B7_REG_RESERVED_FW_1, ~(_BIT5 | _BIT4), _D0_DP_LANE3 << 4);

                    break;
            }

            ScalerRead(PB_B7_REG_RESERVED_FW_1, 1, &g_ucDpRx0PhyCtsCtrl, _NON_AUTOINC);

            DebugMessageRx0("7. PHY CTS Loop", g_ucDpRx0PhyCtsCtrl);

            switch(g_ucDpRx0PhyCtsCtrl & 0x07)
            {
                case 0x01: // CDR Lock Check

                    ScalerSetByte(PB_B7_REG_RESERVED_FW_1, (g_ucDpRx0PhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0))); // Clear DP PHY CTS Phase Info

                    ScalerDpRx0PhyCtsTp1SetPhy(_DP_NF_REF_XTAL);

                    if(ScalerDpRx0PhyCtsTp1Check() == _TRUE)
                    {
                        ScalerSetByte(PB_B8_REG_RESERVED_FW_2, 0x01);
                    }
                    else
                    {
                        ScalerSetByte(PB_B8_REG_RESERVED_FW_2, 0xFF);
                    }

                    break;

                case 0x02: // Symbol Lock Check

                    ScalerSetByte(PB_B7_REG_RESERVED_FW_1, (g_ucDpRx0PhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0)));

                    ScalerDpRx0PhyCtsTp2SetPhy();

                    if(ScalerDpRx0PhyCtsTp2Check() == _TRUE)
                    {
                        ScalerSetByte(PB_B8_REG_RESERVED_FW_2, 0x02);
                    }
                    else
                    {
                        ScalerSetByte(PB_B8_REG_RESERVED_FW_2, 0xFF);
                    }

                    break;

                case 0x03:

                    ScalerSetByte(PB_B7_REG_RESERVED_FW_1, (g_ucDpRx0PhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0)));

                    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
                    {
                        case 0x00: // Lane0 Test

                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), 0x00);

                            break;

                        case 0x10: // Lane1 Test

                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _BIT3);

                            break;

                        case 0x20: // Lane2 Test

                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _BIT4);

                            break;

                        case 0x30: // Lane3 Test

                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

                            break;

                        default:
                            break;
                    }

                    // Disable Scramble
                    ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);

                    // Reverse PRBS7 Pattern Gen
                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~_BIT6, _BIT6);

                    // Disable PRBS7 Error Detection
                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                    // Waiting for PHY Stable
                    ScalerTimerDelayXms(10);

                    // PRBS7 Pattern for RBR/HBR
                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

                    break;

                case 0x05:

                    // Disable PRBS7 Error Detection
                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                    // Clear DP PHY CTS Control Register
                    ScalerSetByte(PB_B7_REG_RESERVED_FW_1, 0x00);

                    // Clear DP PHY CTS Result
                    ScalerSetByte(PB_B8_REG_RESERVED_FW_2, 0x00);

                    CLR_DP_RX0_PHY_CTS_FLG();

                    break;

                default:

                    break;
            }

            if((g_ucDpRx0PhyCtsCtrl & 0x07) != 0x05)
            {
                if(((ScalerGetByte(PB_B7_REG_RESERVED_FW_1) & 0x30) >> 4) == _D0_DP_LANE0) // Source Lane0
                {
                    ScalerSetBit(PB_B7_REG_RESERVED_FW_1, ~(_BIT5 | _BIT4), _DP_SCALER_LANE0 << 4);
                }
                else if(((ScalerGetByte(PB_B7_REG_RESERVED_FW_1) & 0x30) >> 4) == _D0_DP_LANE1) // Source Lane1
                {
                    ScalerSetBit(PB_B7_REG_RESERVED_FW_1, ~(_BIT5 | _BIT4), _DP_SCALER_LANE1 << 4);
                }
                else if(((ScalerGetByte(PB_B7_REG_RESERVED_FW_1) & 0x30) >> 4) == _D0_DP_LANE2) // Source Lane2
                {
                    ScalerSetBit(PB_B7_REG_RESERVED_FW_1, ~(_BIT5 | _BIT4), _DP_SCALER_LANE2 << 4);
                }
                else if(((ScalerGetByte(PB_B7_REG_RESERVED_FW_1) & 0x30) >> 4) == _D0_DP_LANE3) // Source Lane3
                {
                    ScalerSetBit(PB_B7_REG_RESERVED_FW_1, ~(_BIT5 | _BIT4), _DP_SCALER_LANE3 << 4);
                }

                DebugMessageRx0("7. PHY CTS Loop (Swap Back)", ScalerGetByte(PB_B7_REG_RESERVED_FW_1));
            }
            else
            {
                g_ucDpRx0PhyCtsCtrl = 0x00;
            }
        }
    }
}

//--------------------------------------------------
// Description  : Signal PreDetection for DP(Power Normal)
// Input Value  : None
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerDpRx0NormalPreDetect(void)
{
    // For Dp PHY CTS Test
    if((GET_DP_RX0_PHY_CTS_FLG() == _TRUE) || (ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x70, _BIT7) == _BIT7))
    {
        ScalerDpRx0PhyCTS();

        return _FALSE;
    }

    if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT)
    {
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DP_ASSR_MODE_SUPPORT == _ON))
        // ASSR Mode Setting
        ScalerDpRx0ASSRModeSetting();
#endif
    }
    else if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
    {
#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DP_ASSR_MODE_SUPPORT == _ON))
        // ASSR Mode Setting
        ScalerDpRx0ASSRModeSetting();
#endif
    }

#if(_DP_ILLEGAL_IDLE_PATTERN_CHECK_SUPPORT == _ON)
    CLR_DP_RX0_SOURCE_TYPE_JUDGE();
#endif

    switch(GET_DP_RX0_LINK_TRAINING_STATUS())
    {
        case _DP_NORMAL_LINK_TRAINING_PASS:
        case _DP_LINK_STATUS_FAIL:

            CLR_DP_RX0_VALID_VIDEO_CHECK();

            if((ScalerDpRx0CDRCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
               (ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
               (ScalerDpRx0MarginLinkCheck() == _TRUE) &&
               (ScalerDpRx0AlignCheck() == _TRUE) &&
               (ScalerDpRx0DecodeCheck() == _TRUE))
            {
                /*
                DebugMessageRx0("9. Lane0 LE Diff", (g_pucDpRx0LEMaxTemp[0] - g_pucDpRx0LEMinTemp[0]));
                DebugMessageRx0("9. Lane1 LE Diff", (g_pucDpRx0LEMaxTemp[1] - g_pucDpRx0LEMinTemp[1]));
                DebugMessageRx0("9. Lane2 LE Diff", (g_pucDpRx0LEMaxTemp[2] - g_pucDpRx0LEMinTemp[2]));
                DebugMessageRx0("9. Lane3 LE Diff", (g_pucDpRx0LEMaxTemp[3] - g_pucDpRx0LEMinTemp[3]));
                DebugMessageRx0("9. Lane0 LE Min", g_pucDpRx0LEMinTemp[0]);
                DebugMessageRx0("9. Lane1 LE Min", g_pucDpRx0LEMinTemp[1]);
                DebugMessageRx0("9. Lane2 LE Min", g_pucDpRx0LEMinTemp[2]);
                DebugMessageRx0("9. Lane3 LE Min", g_pucDpRx0LEMinTemp[3]);
                DebugMessageRx0("9. Lane0 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[0] - g_pucDpRx0Tap0MinTemp[0]));
                DebugMessageRx0("9. Lane1 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[1] - g_pucDpRx0Tap0MinTemp[1]));
                DebugMessageRx0("9. Lane2 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[2] - g_pucDpRx0Tap0MinTemp[2]));
                DebugMessageRx0("9. Lane3 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[3] - g_pucDpRx0Tap0MinTemp[3]));
                DebugMessageRx0("9. Lane0 Tap0 Max", g_pucDpRx0Tap0MaxTemp[0]);
                DebugMessageRx0("9. Lane1 Tap0 Max", g_pucDpRx0Tap0MaxTemp[1]);
                DebugMessageRx0("9. Lane2 Tap0 Max", g_pucDpRx0Tap0MaxTemp[2]);
                DebugMessageRx0("9. Lane3 Tap0 Max", g_pucDpRx0Tap0MaxTemp[3]);
                DebugMessageRx0("9. FLD Band", ScalerGetByte(PB_BF_LANE0_A_CDR_02));
                DebugMessageRx0("9. Best FLD Band", ScalerGetByte(PB_BE_LANE0_A_CDR_01));
                DebugMessageRx0("9. Lane0 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[0] - g_pucDpRx0Tap0MinTemp2[0]));
                DebugMessageRx0("9. Lane1 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[1] - g_pucDpRx0Tap0MinTemp2[1]));
                DebugMessageRx0("9. Lane2 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[2] - g_pucDpRx0Tap0MinTemp2[2]));
                DebugMessageRx0("9. Lane3 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[3] - g_pucDpRx0Tap0MinTemp2[3]));
                DebugMessageRx0("9. Lane0 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[0]);
                DebugMessageRx0("9. Lane1 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[1]);
                DebugMessageRx0("9. Lane2 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[2]);
                DebugMessageRx0("9. Lane3 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[3]);
                DebugMessageRx0("9. TP2 Check Result", g_ucDpRx0EQCRC);
                */

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_LINK_STATUS_IRQ);
#endif

                if(GET_DP_RX0_NORMAL_LINK_TRAINING_SETPHY_FINISH() == _TRUE)
                {
#if(_AIO_MODERN_STANDBY_SUPPORT == _ON)
                    if(GET_AIO_MODERN_STANDBY_MODE() == _FALSE)
#endif
                    {
                        ScalerTimerDelayXms(_DP_ONE_FRAME_TIME_MAX);
                    }

                    CLR_DP_RX0_NORMAL_LINK_TRAINING_SETPHY_FINISH();
                }

                SET_DP_RX0_AUX_MANUAL_MODE();

                if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL)
                {
                    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);

                    ScalerDpRx0ScrambleSetting();
                }

                SET_DP_RX0_AUX_AUTO_MODE();

                if((ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1) ||
                   (ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0)))
                {
                    return _FALSE;
                }

                return _TRUE;
            }
            else
            {
                DebugMessageRx0("7. Link Status Fail IRQ", 0);

                SET_DP_RX0_AUX_MANUAL_MODE();

                if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
                {
                    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_LINK_STATUS_FAIL);

                    ScalerDpRx0ActiveLinkStatusIRQ();
                }

                SET_DP_RX0_AUX_AUTO_MODE();
            }

            break;

        case _DP_LINK_TRAINING_FAIL:

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_LINK_STATUS_IRQ);
#endif

            ScalerDpRx0LinkStatusIRQ();

            break;

        case _DP_FAKE_LINK_TRAINING_PASS:
        case _DP_FAKE_LINK_TRAINING_PASS_VBIOS:

            CLR_DP_RX0_VALID_VIDEO_CHECK();

#if(_AIO_MODERN_STANDBY_SUPPORT == _ON)
            if(GET_AIO_MODERN_STANDBY_MODE() == _FALSE)
#endif
            {
                ScalerTimerDelayXms(30);
            }

            DebugMessageRx0("7. DP Rebuild PHY", GET_DP_RX0_LINK_TRAINING_STATUS());

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_LINK_STATUS_IRQ);
#endif

            SET_DP_RX0_AUX_MANUAL_MODE();

            if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
            {
                ScalerDpRx0RebuildPhy(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01));

                SET_DP_RX0_AUX_AUTO_MODE();

                // Mac Reset After Link Clock Stable
                ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
                ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

                // Delay Time us [150,x] Delay for Lane Alignment after Mac Reset
                DELAY_XUS(150);

                ScalerDpRx0PassiveDFEFineTune();
            }

            SET_DP_RX0_AUX_AUTO_MODE();

            // De-Skew Circuit Reset
            ScalerSetBit(PB_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetBit(PB_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), _BIT6);

            // Mac Reset After Link Clock Stable
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

            // Delay for Lane Alignment after Mac Reset
            ScalerTimerDelayXms(2);

            if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS)
            {
                ScalerDpRx0DecodeErrorCountReset();
            }

            if((ScalerDpRx0CDRCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
               (ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
               (ScalerDpRx0MarginLinkCheck() == _TRUE) &&
               (ScalerDpRx0AlignCheck() == _TRUE) &&
               (ScalerDpRx0DecodeCheck() == _TRUE))
            {
                DebugMessageRx0("7. Rebuild Phy Pass", 0);

                /*
                DebugMessageRx0("9. Lane0 LE Diff", (g_pucDpRx0LEMaxTemp[0] - g_pucDpRx0LEMinTemp[0]));
                DebugMessageRx0("9. Lane1 LE Diff", (g_pucDpRx0LEMaxTemp[1] - g_pucDpRx0LEMinTemp[1]));
                DebugMessageRx0("9. Lane2 LE Diff", (g_pucDpRx0LEMaxTemp[2] - g_pucDpRx0LEMinTemp[2]));
                DebugMessageRx0("9. Lane3 LE Diff", (g_pucDpRx0LEMaxTemp[3] - g_pucDpRx0LEMinTemp[3]));
                DebugMessageRx0("9. Lane0 LE Min", g_pucDpRx0LEMinTemp[0]);
                DebugMessageRx0("9. Lane1 LE Min", g_pucDpRx0LEMinTemp[1]);
                DebugMessageRx0("9. Lane2 LE Min", g_pucDpRx0LEMinTemp[2]);
                DebugMessageRx0("9. Lane3 LE Min", g_pucDpRx0LEMinTemp[3]);
                DebugMessageRx0("9. Lane0 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[0] - g_pucDpRx0Tap0MinTemp[0]));
                DebugMessageRx0("9. Lane1 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[1] - g_pucDpRx0Tap0MinTemp[1]));
                DebugMessageRx0("9. Lane2 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[2] - g_pucDpRx0Tap0MinTemp[2]));
                DebugMessageRx0("9. Lane3 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[3] - g_pucDpRx0Tap0MinTemp[3]));
                DebugMessageRx0("9. Lane0 Tap0 Max", g_pucDpRx0Tap0MaxTemp[0]);
                DebugMessageRx0("9. Lane1 Tap0 Max", g_pucDpRx0Tap0MaxTemp[1]);
                DebugMessageRx0("9. Lane2 Tap0 Max", g_pucDpRx0Tap0MaxTemp[2]);
                DebugMessageRx0("9. Lane3 Tap0 Max", g_pucDpRx0Tap0MaxTemp[3]);
                DebugMessageRx0("9. FLD Band", ScalerGetByte(PB_BF_LANE0_A_CDR_02));
                DebugMessageRx0("9. Best FLD Band", ScalerGetByte(PB_BE_LANE0_A_CDR_01));
                DebugMessageRx0("9. D10.2 Counter", g_usDpRx0ClockCount);
                DebugMessageRx0("9. D10.2 Counter1", g_usDpRx0ClockCount1);
                DebugMessageRx0("9. Lane0 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[0] - g_pucDpRx0Tap0MinTemp2[0]));
                DebugMessageRx0("9. Lane1 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[1] - g_pucDpRx0Tap0MinTemp2[1]));
                DebugMessageRx0("9. Lane2 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[2] - g_pucDpRx0Tap0MinTemp2[2]));
                DebugMessageRx0("9. Lane3 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[3] - g_pucDpRx0Tap0MinTemp2[3]));
                DebugMessageRx0("9. Lane0 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[0]);
                DebugMessageRx0("9. Lane1 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[1]);
                DebugMessageRx0("9. Lane2 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[2]);
                DebugMessageRx0("9. Lane3 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[3]);
                DebugMessageRx0("9. Best FLD Band", ScalerGetByte(PB_BE_LANE0_A_CDR_01));
                DebugMessageRx0("9. TP2 Check Result", g_ucDpRx0EQCRC);
                DebugMessageRx0("9. DP Requeset", ScalerDpRx0GetDpcdInfo(0x00, 0x02, 0x06));
                DebugMessageRx0("9. DP Requeset", ScalerDpRx0GetDpcdInfo(0x00, 0x02, 0x07));
                DebugMessageRx0("9. Lane0 Tap1 Max", ScalerGetByte(P1D_A5_L0_INIT_3));
                DebugMessageRx0("9. Lane1 Tap1 Max", ScalerGetByte(P1D_B5_L1_INIT_3));
                DebugMessageRx0("9. Lane2 Tap1 Max", ScalerGetByte(P1D_C5_L2_INIT_3));
                DebugMessageRx0("9. Lane3 Tap1 Max", ScalerGetByte(P1D_D5_L3_INIT_3));
                */

                SET_DP_RX0_AUX_MANUAL_MODE();

                if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
                {
                    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);
                    CLR_DP_RX0_NORMAL_LINK_TRAINING_SETPHY_FINISH();

                    ScalerDpRx0ScrambleSetting();
                }

                SET_DP_RX0_AUX_AUTO_MODE();

#if(_AIO_MODERN_STANDBY_SUPPORT == _ON)
                if(GET_AIO_MODERN_STANDBY_MODE() == _FALSE)
#endif
                {
                    ScalerTimerDelayXms(_DP_ONE_FRAME_TIME_MAX);
                }

                if((ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1) ||
                   (ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0)))
                {
                    return _FALSE;
                }

                return _TRUE;
            }
            else
            {
                DebugMessageRx0("7. DP Rebuild PHY Fail", 0);

                SET_DP_RX0_AUX_MANUAL_MODE();

                if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS)
                {
                    ScalerDpRx0DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_INITIAL);

                    ScalerDpRx0HDCPBlockReset();
                }
                else if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS)
                {
                    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_LINK_STATUS_FAIL);

                    SET_DP_RX0_AUX_AUTO_MODE();

                    return _TRUE;
                }

                SET_DP_RX0_AUX_AUTO_MODE();
            }

            break;

        case _DP_LINK_TRAINING_NONE:

            if(GET_DP_RX0_VALID_VIDEO_CHECK() == _TRUE)
            {
                ScalerDpRx0ValidSignalDetection();

                DebugMessageRx0("7. VBIOS Check !!!!!!!", GET_DP_RX0_FAKE_LINK_TRAINING());
            }

            break;

        default:

            break;
    }

    if(GET_DP_RX0_VALID_VIDEO_CHECK() == _TRUE)
    {
        CLR_DP_RX0_VALID_VIDEO_CHECK();
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP Port Source/Sync Scanning and Setting
// Input Value  : None
// Output Value : Source DP --> DP Sync Stable
//                Source None --> No Stable Sync
//--------------------------------------------------
BYTE ScalerDpRx0ScanInputPort(void)
{
    StructDpInfo stDpInfo;
    memset(&stDpInfo, 0, sizeof(StructDpInfo));

    if(GET_DP_RX0_LINK_TRAINING_STATUS() != _DP_NORMAL_LINK_TRAINING_PASS)
    {
        return _SOURCE_NONE;
    }

    // 2nd Scramble Setting Sync
    ScalerDpRx0ScrambleSetting();

    if(ScalerDpRx0HdcpCheck() == _FALSE)
    {
        DebugMessageRx0("7. DP HDCP Check Fail", 0);

        ScalerDpRx0CpIRQ(_DP_HDCP_BSTATUS_LINK_INTEGRITY_FAIL);

        SET_DP_RX0_HDCP_CPIRQ();

#if(_DP_LONG_HPD_AFTER_CPIRQ_SUPPORT == _ON)
        if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT)
        {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            ScalerTimerReactiveTimerEvent(SEC(1), _SCALER_TIMER_EVENT_DP_RX0_HDCP_LONG_HOTPLUG_EVENT);
#endif
        }
        else if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
        {
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            ScalerTimerReactiveTimerEvent(SEC(1), _SCALER_TIMER_EVENT_DP_RX1_HDCP_LONG_HOTPLUG_EVENT);
#endif
        }
#endif

        return _SOURCE_NONE;
    }

    if(ScalerDpRx0GetVideoStream() == _FALSE)
    {
        DebugMessageRx0("7. DP Video Stream Fail", 0);

        return _SOURCE_NONE;
    }

#if(_DP_FREESYNC_SUPPORT == _ON)
    if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x07) & _BIT7) == _BIT7)
    {
        SET_DP_FREESYNC_ENABLED();
    }
    else
    {
        CLR_FREESYNC_ENABLED();
    }

#if(_DP_FORCE_FREESYNC_SUPPORT == _ON)
    SET_DP_FREESYNC_ENABLED();
#endif

#endif

    if(ScalerDpRx0GetMsaTimingInfo(&stDpInfo) == _FALSE)
    {
        DebugMessageRx0("7. DP MSA Fail", 0);

        return _SOURCE_NONE;
    }

    if(ScalerDpRx0GetVideoInfo() == _FALSE)
    {
        DebugMessageRx0("7. DP Get Video Info Fail", 0);

        return _SOURCE_NONE;
    }
    else
    {
        ScalerDpRx0SetColorInfo();
    }

    if(ScalerDpRx0GetMeasureLinkInfo(&stDpInfo) == _FALSE)
    {
        DebugMessageRx0("7. DP MAC RX0: Get Measure Info Fail", 0);

        return _SOURCE_NONE;
    }

    if(ScalerDpRx0DisplayFormatSetting(&stDpInfo) == _FALSE)
    {
        DebugMessageRx0("7. DP MAC RX0: Display Format Fail", 0);

        return _SOURCE_NONE;
    }

    if(ScalerDpRx0StreamClkRegenerate(&(stDpInfo.stDpLinkInfo)) == _FALSE)
    {
        DebugMessageRx0("7. DP MAC RX0: Stream Clk Fail", 0);

        return _SOURCE_NONE;
    }

    if(ScalerDpRx0TrackingSetting(&stDpInfo) == _FALSE)
    {
        DebugMessageRx0("7. DP MAC RX0: Tracking Fail", 0);

        return _SOURCE_NONE;
    }

    if(ScalerDpRx0FifoCheck(_DP_FIFO_DELAY_CHECK) == _FALSE)
    {
#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
        if(GET_DP_RX0_URGENT_LINK_LOSS() == _TRUE)
        {
            return _SOURCE_NONE;
        }
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
        if(GET_FREESYNC_ENABLED() == _TRUE)
        {
            return _SOURCE_NONE;
        }
        else
#endif
        {
            ScalerDpRx0AdjustVsyncDelay();

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
            if(GET_DP_RX0_URGENT_LINK_LOSS() == _TRUE)
            {
                return _SOURCE_NONE;
            }
#endif
            if(ScalerDpRx0FifoCheck(_DP_FIFO_DELAY_CHECK) == _FALSE)
            {
#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
                if(GET_DP_RX0_URGENT_LINK_LOSS() == _TRUE)
                {
                    return _SOURCE_NONE;
                }
#endif
                ScalerDpRx0AdjustVsyncDelay();

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
                if(GET_DP_RX0_URGENT_LINK_LOSS() == _TRUE)
                {
                    return _SOURCE_NONE;
                }
#endif
                if(ScalerDpRx0FifoCheck(_DP_FIFO_DELAY_CHECK) == _FALSE)
                {
                    DebugMessageRx0("7. DP Fifo Fail", 0);

                    return _SOURCE_NONE;
                }
            }
        }
    }

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HDCP_LONG_HOTPLUG_EVENT);
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_LONG_HOTPLUG_EVENT);
#endif

    CLR_DP_RX0_HDCP_CPIRQ();

#if(_DP_FREESYNC_SUPPORT == _ON)
    // Measurement Enable for On-Line VFreq check
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);
#endif

    ScalerSetBit(PB5_31_DP_OUTPUT_CTRL, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

#if(_AUDIO_SUPPORT == _ON)
    // Enable Audio Channel
    ScalerAudioDpAudioEnable(_ENABLE, _D0_INPUT_PORT);
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
    ScalerFreeSyncDpRx0GetSPDVfreqMaxMin();
#endif

#if(_AIO_MODERN_STANDBY_SUPPORT == _ON)
    ScalerDpRx0TimingInfoBackup();
#endif

#if(_DP_ILLEGAL_IDLE_PATTERN_CHECK_SUPPORT == _ON)
    SET_DP_RX0_SOURCE_TYPE_JUDGE();
#endif

    return _SOURCE_DP;
}

//--------------------------------------------------
// Description  : On Line Check DP stability
// Input Value  : None
// Output Value : True --> DP Stable
//                False --> DP Unstable
//--------------------------------------------------
bit ScalerDpRx0StableDetect(void)
{
#if(_DP_POWER_MANAGEMENT_FOR_FAST_DISPLAY_RECOVER == _ON)
    if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1)
#else
    if((ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1) ||
       (ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0)))
#endif
    {
        DebugMessageRx0("7. DP Power Down", 0);

        return _FALSE;
    }

    if((ScalerDpRx0CDRCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _FALSE) ||
       (ScalerDpRx0AlignCheck() == _FALSE) ||
       (ScalerDpRx0DecodeCheck() == _FALSE) ||
       (ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _FALSE))
    {
        DebugMessageRx0("7. DP Link Fail", 0);

        return _FALSE;
    }

#if(_DP_8B10B_DEC_ERROR_WD_SUPPORT == _ON)
    if(ScalerDpRx0Check8b10bDecErrorStatus() == _FAIL)
    {
        DebugMessageRx0("7. DP 8b10b Acc Dec Err", 0);
        return _FALSE;
    }
#endif

#if(_DP_BS_MISS_DETECT_IRQ_WD_SUPPORT == _ON)
    if(ScalerDpRx0CheckBsStatus() == _UNSTABLE)
    {
        DebugMessageRx0("7. DP BS Unstable", 0);

        return _FALSE;
    }
#endif

    if(ScalerDpRx0GetVideoStream() == _FALSE)
    {
        DebugMessageRx0("7. DP Video Stream Fail", 0);

        return _FALSE;
    }

    if(ScalerDpRx0MiscCheck() == _FALSE)
    {
        DebugMessageRx0("7. DP Misc Change", 0);

        return _FALSE;
    }

    if(ScalerDpRx0FifoCheck(_DP_FIFO_POLLING_CHECK) == _FALSE)
    {
        DebugMessageRx0("7. Fifo Under/Overflow", 0);

        return _FALSE;
    }

    if(ScalerDpRx0MSAActiveChange() == _TRUE)
    {
        DebugMessageRx0("7. MSA Timing Change", 0);

        return _FALSE;
    }

#if(_DP_FORCE_FREESYNC_SUPPORT == _OFF)
#if(_DP_FREESYNC_SUPPORT == _ON)
    if(ScalerDpRx0GetFREESYNCStatusChange() == _TRUE)
    {
        return _FALSE;
    }
#endif
#endif

    // Clear CPIRQ Flag
    ScalerDpRx0CheckHdcpCpirqStatus();

    ScalerDpRx0CrcCalculate();

    return _TRUE;
}

#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check DP Phy Link Loss
// Input Value  : None
// Output Value : True --> DP Link Loss
//                False --> DP Link Stable
//--------------------------------------------------
bit ScalerDpRx0LinkStatusLoss(void)
{
    if((ScalerDpRx0CDRCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
       (ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
       (ScalerDpRx0DecodeCheck() == _TRUE))
    {
        CLR_DP_RX0_URGENT_LINK_LOSS();

        return _FALSE;
    }

    SET_DP_RX0_URGENT_LINK_LOSS();

    return _TRUE;
}
#endif

//--------------------------------------------------
// Description  : Divide the time to check for Link Loss checker
// Input Value  : usNum --> Delay in ms
// Output Value : True --> DP Stable
//                False --> DP Unstable
//--------------------------------------------------
bit ScalerDpRx0TimerDelayXmsLinkCheck(WORD usNum)
{
    while(usNum >= _DP_RX_LINK_LOSS_CHECK_INTERVAL)
    {
#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
        if(ScalerDpRx0LinkStatusLoss() == _TRUE)
        {
            return _FALSE;
        }
#endif
        ScalerTimerDelayXms(_DP_RX_LINK_LOSS_CHECK_INTERVAL);

        usNum -= _DP_RX_LINK_LOSS_CHECK_INTERVAL;
    }

    if(usNum > 0)
    {
#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
        if(ScalerDpRx0LinkStatusLoss() == _TRUE)
        {
            return _FALSE;
        }
#endif
        // If usNum = 1ms, it will delay 2ms (Cause 1ms is inaccurate)
        ScalerTimerDelayXms((usNum == 1) ? 2 : usNum);
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Divide the time of Polling func to check for Link Loss checker
// Input Value  : usTimeout --> Timeout number (Max: 65,535 ms)
//                usRegister--> Current Register
//                ucBit     --> Polling Bit
//                bSuccess  --> 1 or 0 when finished for Polling Bit
// Output Value : Return _TRUE while polling success, _FALSE for timeout or Link loss
//--------------------------------------------------
bit ScalerDpRx0PollingFlagLinkCheck(WORD usTimeout, WORD usRegister, BYTE ucBit, bit bSuccess)
{
    while(usTimeout >= _DP_RX_LINK_LOSS_CHECK_INTERVAL)
    {
#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
        if(ScalerDpRx0LinkStatusLoss() == _TRUE)
        {
            return _FALSE;
        }
#endif
        if(ScalerTimerPollingFlagProc(_DP_RX_LINK_LOSS_CHECK_INTERVAL, usRegister, ucBit, bSuccess) == _TRUE)
        {
            return _TRUE;
        }

        usTimeout -= _DP_RX_LINK_LOSS_CHECK_INTERVAL;
    }

    if(usTimeout > 0)
    {
#if(_DP_LINK_INTERVAL_CHECK_SUPPORT == _ON)
        if(ScalerDpRx0LinkStatusLoss() == _TRUE)
        {
            return _FALSE;
        }
#endif
        if(ScalerTimerPollingFlagProc(usTimeout, usRegister, ucBit, bSuccess) == _TRUE)
        {
            return _TRUE;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Set Dp HotPlug Event
// Input Value  : Hot Plug Type
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetHotPlugEvent(EnumDpHotPlugAssertType enumHpdType)
{
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    if((ScalerDebugCheckDebugPort(GET_DP_EMBEDDED_SWITCH_SELECT()) == _TRUE) && (ScalerSyncDpCableStatus(GET_DP_EMBEDDED_SWITCH_SELECT()) == _TRUE))
    {
        if(ScalerSyncDpGetHotPlugStatus(GET_DP_EMBEDDED_SWITCH_SELECT()) == _HIGH)
        {
            return;
        }
    }
#endif

    if((enumHpdType > _DP_HPD_LOW) && (ScalerSyncDpCableStatus(GET_DP_EMBEDDED_SWITCH_SELECT()) == _FALSE))
    {
        return;
    }

#if(_DP_LONG_HPD_ALLOWED_BY_USER_SUPPORT == _ON)
    if(ScalerSyncDpLongHpdGetAllowed(GET_DP_EMBEDDED_SWITCH_SELECT()) == _FALSE)
    {
        if(ScalerSyncDpGetHotPlugStatus(GET_DP_EMBEDDED_SWITCH_SELECT()) == _HIGH)
        {
            if((enumHpdType > _DP_HPD_LOW) && (enumHpdType < _DP_HPD_ASSERTED))
            {
                return;
            }
        }
    }
#endif

    // If the priority of enumHpdType is higher
    if(enumHpdType < GET_DP_RX0_HOTPLUG_ASSERT_TYPE())
    {
        SET_DP_RX0_HOTPLUG_ASSERT_TYPE(enumHpdType);
    }
}

//--------------------------------------------------
// Description  : Read DP Rx Error Count
// Input Value  : DP Input Port
// Output Value : DP 4 Lane Error Count & Valid Flag
//--------------------------------------------------
StructDpRxErrorCount ScalerDpRx0GetErrorCount(void)
{
    StructDpRxErrorCount stDpRxErrorCount;

    if(ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _FALSE)
    {
        DebugMessageSystem("Rx Fail to Report Valid Error Counter", 0x00);

        switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)
        {
            case _DP_ONE_LANE:

                stDpRxErrorCount.usDpRxLane0ErrorCount = 0x7FFF;
                stDpRxErrorCount.usDpRxLane1ErrorCount = 0;
                stDpRxErrorCount.usDpRxLane2ErrorCount = 0;
                stDpRxErrorCount.usDpRxLane3ErrorCount = 0;

                break;

            case _DP_TWO_LANE:

                stDpRxErrorCount.usDpRxLane0ErrorCount = 0x7FFF;
                stDpRxErrorCount.usDpRxLane1ErrorCount = 0x7FFF;
                stDpRxErrorCount.usDpRxLane2ErrorCount = 0;
                stDpRxErrorCount.usDpRxLane3ErrorCount = 0;

                break;

            default:
            case _DP_FOUR_LANE:

                stDpRxErrorCount.usDpRxLane0ErrorCount = 0x7FFF;
                stDpRxErrorCount.usDpRxLane1ErrorCount = 0x7FFF;
                stDpRxErrorCount.usDpRxLane2ErrorCount = 0x7FFF;
                stDpRxErrorCount.usDpRxLane3ErrorCount = 0x7FFF;

                break;
        }
    }
    else
    {
        switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)
        {
            case _DP_ONE_LANE:

                stDpRxErrorCount.usDpRxLane0ErrorCount = ScalerDpRx0GetDecodeErrorCount(_D0_DP_LANE0);
                stDpRxErrorCount.usDpRxLane1ErrorCount = 0;
                stDpRxErrorCount.usDpRxLane2ErrorCount = 0;
                stDpRxErrorCount.usDpRxLane3ErrorCount = 0;

                break;

            case _DP_TWO_LANE:

                stDpRxErrorCount.usDpRxLane0ErrorCount = ScalerDpRx0GetDecodeErrorCount(_D0_DP_LANE0);
                stDpRxErrorCount.usDpRxLane1ErrorCount = ScalerDpRx0GetDecodeErrorCount(_D0_DP_LANE1);
                stDpRxErrorCount.usDpRxLane2ErrorCount = 0;
                stDpRxErrorCount.usDpRxLane3ErrorCount = 0;

                break;

            default:
            case _DP_FOUR_LANE:

                stDpRxErrorCount.usDpRxLane0ErrorCount = ScalerDpRx0GetDecodeErrorCount(_D0_DP_LANE0);
                stDpRxErrorCount.usDpRxLane1ErrorCount = ScalerDpRx0GetDecodeErrorCount(_D0_DP_LANE1);
                stDpRxErrorCount.usDpRxLane2ErrorCount = ScalerDpRx0GetDecodeErrorCount(_D0_DP_LANE2);
                stDpRxErrorCount.usDpRxLane3ErrorCount = ScalerDpRx0GetDecodeErrorCount(_D0_DP_LANE3);

                break;
        }
    }

    // Reset Error Counter
    ScalerDpRx0DecodeErrorCountReset();

    return stDpRxErrorCount;
}
#if(_AIO_MODERN_STANDBY_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Backup Timing Info for Modern Standby
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0TimingInfoBackup(void)
{
    // Backup Offset Value of Stream Clock
    g_stDpRx0LinkInfo.lStreamClockOffset = ((((SDWORD)ScalerGetBit(PB5_BA_MN_SCLKG_SDM_SUMC_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0))) << 16) |
                                            (((WORD)ScalerGetByte(PB5_BB_MN_SCLKG_SDM_SUMC_M)) << 8) |
                                            (ScalerGetByte(PB5_BC_MN_SCLKG_SDM_SUMC_L))) >> 1;

    // Backup VBs2Bs Delay of Even Field
    g_stDpRx0LinkInfo.ulVBsToBsDelayEven = (((DWORD)ScalerGetBit(PB5_32_EVBLK2VS_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0))) << 16) |
                                           (((WORD)ScalerGetByte(PB5_33_EVBLK2VS_M)) << 8) |
                                           (ScalerGetByte(PB5_34_EVBLK2VS_L));

    // Backup VBs2Bs Delay of Odd Field
    g_stDpRx0LinkInfo.ulVBsToBsDelayOdd = (((DWORD)ScalerGetBit(PB5_35_OVBLK2VS_H, (_BIT3 | _BIT2 | _BIT1 | _BIT0))) << 16) |
                                          (((WORD)ScalerGetByte(PB5_36_OVBLK2VS_M)) << 8) |
                                          (ScalerGetByte(PB5_37_OVBLK2VS_L));
}
#endif

#if(_DP_BS_MISS_DETECT_IRQ_WD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable DP BS Miss Detect IRQ
// Input Value  : _ENABLE/ DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetBsMissDetectIRQ(bit bEn)
{
    // Clear BS Miss Detect Flag
    ScalerSetBit(PB5_B8_PLL_DUMMY_0, ~_BIT6, _BIT6);

    // BS Miss Detect IRQ Setting
    ScalerSetBit(PB5_B8_PLL_DUMMY_0, ~(_BIT7 | _BIT6), ((bEn == _ENABLE) ? _BIT7 : 0x00));
}

//--------------------------------------------------
// Description  : Enable DP BS Miss Detect Tracing WD
// Input Value  : _ENABLE/ DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetBsMissDetectTrackingWD(bit bEn)
{
    // Clear BS Miss Detect Flag
    ScalerSetBit(PB5_B8_PLL_DUMMY_0, ~_BIT6, _BIT6);

    // BS Miss Detect Tracking WD Setting
    if(bEn == _ENABLE)
    {
        ScalerSetBit(PB5_B8_PLL_DUMMY_0, ~_BIT5, _BIT5);
        ScalerSetBit(PB5_C5_TRACKING_5, ~_BIT2, _BIT2);
    }
    else
    {
        ScalerSetBit(PB5_C5_TRACKING_5, ~_BIT2, 0x00);
        ScalerSetBit(PB5_B8_PLL_DUMMY_0, ~_BIT5, 0x00);
    }
}
//--------------------------------------------------
// Description  : Check Dp BS Status
// Input Value  : None
// Output Value : Stable --> BS Exist
//--------------------------------------------------
bit ScalerDpRx0CheckBsStatus(void)
{
    return ((ScalerGetBit(PB5_B8_PLL_DUMMY_0, _BIT6) == _BIT6) ? _UNSTABLE : _STABLE);
}
#endif

#if(_DP_8B10B_DEC_ERROR_WD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable Dp 8b10b Decoder Error WD
// Input Value  : _ENABLE/ DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0Set8b10bDecErrorWD(bit bEn)
{
    // 8b10b Decoder Error WD Setting
    // _BIT3 set to 0 == Clear Flag 0x0B4A[7:4]
    ScalerSetBit(PB_10_DUMMY1, ~(_BIT5 | _BIT3), ((bEn == _ENABLE) ? (_BIT5 | _BIT3) : 0x00));
}

//--------------------------------------------------
// Description  : Check Dp 8b10b Dec Err Status
// Input Value  : None
// Output Value : _SUCCESS --> No Dec Err
//                _FAIL    --> Dec Err Occur
//--------------------------------------------------
bit ScalerDpRx0Check8b10bDecErrorStatus(void)
{
    return ((ScalerGetBit(PB_4A_DP_LANEX_ACCUMLATED_ERR_COUNT, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00) ? _SUCCESS : _FAIL);
}
#endif

#endif // End of #if(_D0_DP_EXIST == _ON)
