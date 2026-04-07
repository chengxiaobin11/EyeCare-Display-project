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
// ID Code      : RL6851_Series_ScalerSDRAM.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_SDRAM__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definations of OESYNC
//--------------------------------------------------
#define OESYNC_OP_SEL(pi, usSelBit)                                ((((pi) & _BIT4) == _BIT4) ? (usSelBit) : 0x00)

#define GET_OESYNC_SETTING(stPI)                                   (OESYNC_OP_SEL(((stPI).ucCLK), _BIT0) | OESYNC_OP_SEL(((stPI).ucCMD), _BIT1))

//--------------------------------------------------
// Definitions of Memory Device PLL N.F code
//--------------------------------------------------
#if(_MEMORY_PLL_CLOCK == (_MEMORY_SPEED_200MHZ))
#define _MEMORYDEVICEPLL_N_CODE                                    (13 - 3)// Mhz
#define _MEMORYDEVICEPLL_F_CODE                                    (16095)
#elif(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_189MHZ)
#define _MEMORYDEVICEPLL_N_CODE                                    (13 - 3)// Mhz
#define _MEMORYDEVICEPLL_F_CODE                                    (3279)
#elif(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_216MHZ)
#define _MEMORYDEVICEPLL_N_CODE                                    (15 - 3)// Mhz
#define _MEMORYDEVICEPLL_F_CODE                                    (1407)
#elif(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_220MHZ)
#define _MEMORYDEVICEPLL_N_CODE                                    (15 - 3)// Mhz
#define _MEMORYDEVICEPLL_F_CODE                                    (5985)
#else
#define _MEMORYDEVICEPLL_N_CODE                                    (0)// Mhz
#define _MEMORYDEVICEPLL_F_CODE                                    (0)
#endif

#if(0)
//--------------------------------------------------
// SDRAM Boost Mode
//--------------------------------------------------
#if(_MEMORY_PLL_CLOCK == ¡¤)
#warning "NOTE: SDRAM is working at 220MHz for ultra high speed project."
#elif(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_216MHZ)
#warning "NOTE: SDRAM is working at 216MHz for ultra high speed project."
#endif
#endif

//--------------------------------------------------
// SDR PLL SSC Support
//--------------------------------------------------
#if((_SDRPLL_SSC_SUPPORT == _ON) && ((_MEMORY_PLL_CLOCK == _MEMORY_SPEED_189MHZ) || (_MEMORY_PLL_CLOCK == _MEMORY_SPEED_216MHZ)))
#warning "NOTE: _SDRPLL_SSC_SUPPORT is ON, Memory BW may be affected. Please check with SD!!!"
#endif


// Total num of actual PLL PI
#define _TOT_MEMORYDEVIC_PLL_PI_NUM                                32
#define _MCU_MEMORY_DMA_BUF_LEN                                    16
//--------------------------------------------------
// MEMORY Phase Calibration
//--------------------------------------------------
#define _MCU_DMA_POLLING_TIMEOUT                                   8
#define _BEGIN_THEO_PI                                             0
#define _LEFT_MOST_THEO_PI                                         16
#define _TOT_RDQS_EN_SEL_NUM                                       32
#define _TOT_RDQ_DLY_SEL_NUM                                       32
#define _TOT_WDQ_DLY_SEL_NUM                                       16
#define _PER_SET_DQ_NUM                                            16
#define _TOT_RX_FIFO_SEL_NUM                                       32
#define _TOTAL_THEO_DPI_PI_NUM                                     64
#define _THEO_PI_SCAN_BUF_LEN                                      (_TOTAL_THEO_DPI_PI_NUM / 8)
#define _RDQS_EN_SCAN_BUF_LEN                                      (_TOT_RDQS_EN_SEL_NUM / 8)
#define _RDQ_DLY_SCAN_BUF_LEN                                      (_TOT_RDQ_DLY_SEL_NUM / 8)
#define _WDQ_DLY_SCAN_BUF_LEN                                      (_TOT_WDQ_DLY_SEL_NUM / 8)
#define _RX_FIFO_SCAN_BUF_LEN                                      (_TOT_RX_FIFO_SEL_NUM / 8)

#define IS_VALID_THEO_PI(pi)                                       (((pi) >= 0) && ((pi) < _TOTAL_THEO_DPI_PI_NUM))

#define SET_BIT_RESULT(pucResBuf, ucIndex, bResult)                ((pucResBuf)[(ucIndex) / 8] = ((pucResBuf)[(ucIndex) / 8] & ~(_BIT0 << ((ucIndex) % 8))) | (((BYTE)(bResult)) << ((ucIndex) % 8)))

#define GET_BIT_RESULT(pucResBuf, ucIndex)                         (((pucResBuf)[(ucIndex) / 8] & (_BIT0 << ((ucIndex) % 8))) >> ((ucIndex) % 8))




//--------------------------------------------------
// SDRAM Phase Calibration - Debug Message
//--------------------------------------------------
#define _PHASE_CHK_DEBUG_MSG                                       _OFF
#define _PHASE_CHK_DEBUG_DETAIL_MSG                                _OFF

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _MCU_MEMORY_DMA_CMD_NOP = 0x00,
    _MCU_MEMORY_DMA_CMD_WRITE = 0x80,
    _MCU_MEMORY_DMA_CMD_READ = 0xA0,
} EnumMemoryDMACmd;

typedef struct
{
    BYTE ucCLK;
    BYTE ucCMD;
} StructMemoryPLLPI;

typedef struct
{
    StructMemoryPLLPI stPLL;
} StructMemoryPhaseInfo;

typedef enum
{
    _SCAN_RESULT_WR_PI,
    _SCAN_RESULT_RD_DLY_TAP,
    _SCAN_RESULT_RX_FIFO,
} EnumScanResultType;

typedef enum
{
    _CLK = 0,
    _CMD,
} EnumMemoryPLLClk;

typedef struct
{
    BYTE ucCLK;
    BYTE ucCMD;
} StructSDRAMPLLPI;

typedef struct
{
    BYTE ucCLK;
    BYTE ucCMD;
} StructMemoryDevicePLLPI;
//****************************************************************************
// CODE TABLES
//****************************************************************************
#if((_SDRAM_DPI_CRT_DLL_CAL == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_MCU_MODE))
BYTE code tMEMORY_PHASE_CHK_TEST_DATA_SEED[16] =
{
    0x7C, 0x4D,
    0x39, 0x27,
    0x54, 0x80,
    0xF3, 0xFA,
    0x05, 0xD3,
    0x66, 0x2E,
    0xBC, 0x19,
    0x02, 0x45,
};
#endif
//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if((_SDRAM_DPI_CRT_DLL_CAL == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_MCU_MODE))
bit g_bMemoryOfflinePhaseCalDone = _FALSE;

StructSDRAMPLLPI g_pstSdramPLLPHASE[] =
{
    // CLK,  CMD
    {0x20, 0x20},
};
#endif
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerSdramPowerControl(bit bOn);
void ScalerSdramDCPHYInitial(void);
void ScalerSdramPLLCtrl(bit bEnable);
void ScalerSdramPLLOutputCtrl(bit bEnable);
void ScalerSdramSetPLLFreq(DWORD ulFreq);

#if(_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM)
void ScalerSdramControlReset(void);

#if((_SDRAM_DPI_CRT_DLL_CAL == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_MCU_MODE))
void ScalerSdramDevicePLLSetPLLWritePhase(void);
void ScalerSdramOfflinePhaseCalMCUMode(void);
void ScalerSdramPhaseChkMCUModeGenTestData(BYTE pucTestData[_MCU_MEMORY_DMA_BUF_LEN]);
void ScalerSdramPhaseChkMCUModePrintDataBuf(BYTE pucDataBuf[_MCU_MEMORY_DMA_BUF_LEN]);
BYTE ScalerSdramPhaseCheckMCUMode(void);

void ScalerSdramOfflinePhaseCal(void);
bit ScalerSdramOfflinePhaseScanCLK(StructMemoryPhaseInfo pstPrevResult[1], StructMemoryPhaseInfo pstCurrResult[1]);

bit ScalerSdramCalcTheoPhase(EnumMemoryPLLClk enumMainClk, BYTE ucMainClkPI, StructMemoryPLLPI *pstOrigPI, StructMemoryPLLPI *pstResultPI);
void ScalerSdramApplyNewPhase(void);
BYTE ScalerSdramPhaseCheck(void);
void ScalerSdramPrintScanResult(BYTE pucResult[], EnumScanResultType enumScanType, bit bDDRSel);
bit ScalerSdramFindPassRangeMidpoint(BYTE pucResult[], EnumScanResultType enumScanType, BYTE *pucMidpoint, bit bMsgEnable);
void ScalerSdramPrintPhaseCalResult(StructMemoryPhaseInfo pstResult[1]);
void ScalerSdramOfflineScanRx(void);
void ScalerSdramOfflineScanRxFIFO(void);
#endif // #if((_SDRAM_DPI_CRT_DLL_CAL == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_MCU_MODE))

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : DDR Power On/Off
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramPowerControl(bit bOn)
{
    if(bOn == _ON)
    {
        // Set Memory Device PLL CLK
        ScalerSdramSetPLLFreq((DWORD)_MEMORY_DATA_RATE_SPEED * 1000);

        //------------------------------
        // DC PHY Initial
        //------------------------------
        ScalerSdramDCPHYInitial();

#if((_SDRAM_DPI_CRT_DLL_CAL == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_MCU_MODE))
        ScalerSdramOfflinePhaseCalMCUMode();
#endif
    }
    else
    {
        // Disable CLK output, Reset PLL, Disable PLL
        ScalerSdramPLLOutputCtrl(_DISABLE);
        ScalerSdramPLLCtrl(_DISABLE);
    }
}
//--------------------------------------------------
// Description  : DC Phy initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramDCPHYInitial(void)
{
    //==============================
    // DLL Setting
    //==============================
    // One cycele command output delay, RDQS gen mode: PUPD3, enable 3-point cal, fw_set_mode = 'b10.
    ScalerSetDWord(P8F_7C_DPI_CTRL_0_7C, 0x00070406);

    // Enable CS Output One cycle Delay and Initial DQS/DQ Mux table
    ScalerSetDWord(P8E_28_WRLVL_CTRL_28, 0x00000000);

    // Vref PAD Mode
    // [6] vref_pdop, PDOP control for VREF PAD,  1: select for SDRAM;
    // [4] vref_sdram_mode, SDRAM mode control for VREF PAD, 1: select for SDRAM;
    ScalerSetDWord(P8F_70_PAD_BUS_0_70, 0x00000053); // pad_bus = 'b1(O1 for DQ Pad)
    ScalerSetDWord(P8E_14_PAD_IDDQ_14, 0x00000300); // 0x8E16[1:0](IDDQ[9:8]) = 'b11
    ScalerSetDWord(P8F_74_PAD_BUS_1_74, 0x00000003); // DQ0~DQ15:SMT

    //------------------------------
    // RDQS Enable
    //------------------------------
    // RDQS enable latency
    ScalerSetDWord(P8E_54_READ_CTRL_0_54, 0x00000004); // slice_0: DQS_0
    ScalerSetDWord(P8E_58_READ_CTRL_0_58, 0x00000004); // slice_1: DQS_1

    // Apply read delay setting
    ScalerSetDWord(P8F_80_DPI_CTRL_1_80, 0x0000000C);

    //------------------------------
    // Read DQ delay tap
    //------------------------------

    // RDQ delay tap - rising
    ScalerSetDWord(P8E_B8_DQS_IN_DLY_0_B8, 0x0A0A0A0A); // slice_0: DQ_03~DQ_00
    ScalerSetDWord(P8E_BC_DQS_IN_DLY_0_BC, 0x0A0A0A0A); // slice_1: DQ_11~DQ_08
    ScalerSetDWord(P8E_C8_DQS_IN_DLY_1_C8, 0x0A0A0A0A); // slice_0: DQ_07~DQ_04
    ScalerSetDWord(P8E_CC_DQS_IN_DLY_1_CC, 0x0A0A0A0A); // slice_1: DQ_15~DQ_12
    // RDQ delay tap - falling
    ScalerSetDWord(P8E_D8_DQS_IN_DLY_2_D8, 0x0A0A0A0A); // slice_0: DQ_03~DQ_00
    ScalerSetDWord(P8E_DC_DQS_IN_DLY_2_DC, 0x0A0A0A0A); // slice_1: DQ_11~DQ_08
    ScalerSetDWord(P8E_E8_DQS_IN_DLY_3_E8, 0x0A0A0A0A); // slice_0: DQ_07~DQ_04
    ScalerSetDWord(P8E_EC_DQS_IN_DLY_3_EC, 0x0A0A0A0A); // slice_1: DQ_15~DQ_12
    // Apply read delay setting

    ScalerSetDWord(P8F_80_DPI_CTRL_1_80, 0x0000000C);

    //------------------------------
    // Rx FIFO latency
    //------------------------------
    ScalerSetDWord(P8E_64_READ_CTRL_1_64, 0x00000005);
    // Apply read delay setting
    ScalerSetDWord(P8F_80_DPI_CTRL_1_80, 0x0000000C);
    //------------------------------
    // Controller IO pad driving/ODT
    //------------------------------
    // Set IO Pad Driving
    ScalerSetDWord(P8F_34_ODT_TTCP0_SET1_34, 0x00000000); // P-ODT = 0
    ScalerSetDWord(P8F_3C_ODT_TTCN0_SET1_3C, 0x00000000); // N-ODT = 0

    ScalerSetDWord(P8F_44_OCDP0_SET1_44, 0x08080808); // P-OCD
    ScalerSetDWord(P8F_4C_OCDN0_SET1_4C, 0x08080808); // N-OCD

    //For PUPD3, the signals are divided into groups//
    // ODT
    ScalerSetDWord(P90_60_DQ_ODT_SEL_60, 0x00000000); //
    ScalerSetDWord(P90_64_DQ_ODT_SEL_64, 0x00000000); //
    // OCD
    ScalerSetDWord(P90_68_DQ_OCD_SEL_68, 0x00000000); //
    ScalerSetDWord(P90_6C_DQ_OCD_SEL_6C, 0x00000000); //
    ScalerSetDWord(P8F_64_CKE_OCD_SEL_64, 0x00000000); // CKE OCD
    ScalerSetDWord(P8F_68_ADR_OCD_SEL_68, 0x00000000); // CS OCD
    ScalerSetDWord(P8F_6C_CK_OCD_SEL_6C, 0x00000000); // DCK & DCK# OCD

    // Set ODT enable interval
    ScalerSetDWord(P8E_68_READ_CTRL_2_68, 0x00000008);
    ScalerSetDWord(P8E_6C_READ_CTRL_2_6C, 0x00000008);

    ScalerSetDWord(P8E_8C_DPI_CTRL_2_8C, 0x00000000);

    // Apply read delay setting
    ScalerSetDWord(P8F_80_DPI_CTRL_1_80, 0x0000000C);

    // Set fw_set_mode = 'b01
    ScalerSetDWord(P8F_7C_DPI_CTRL_0_7C, 0x00070405);

    //==============================
    // SDRAM DCU Settig
    //==============================
    //------------------------------
    // DCU Start
    //------------------------------
    ScalerSetByte(P4_FC_EXTENDED_MODE_REGISTER0, 0x10); // 0xFC Mode Register
                                                        // bit 7    emr_first        = 0    0: EMR / 1: MR
                                                        // bit 6    mcurd_crc_en     = 0
                                                        // bit 5:4  emr_addr         = 01
                                                        // bit 3:0  emr_config[11:8] = 0
    ScalerSetByte(P4_FD_EXTENDED_MODE_REGISTER1, 0x00); // 0xFD Extended Mode Register  bit 7:0  emr_config[7:0]  = 00

    ScalerSetByte(P4_FE_RANDOM_GENERATOR, 0x00); // bit 7   rst_random_sel ( 0: dvs 1: ivs ) = 0
                                                 // bit 6   rst_crc_sel ( 0: dvs 1: ivs )    = 0
                                                 // bit 5   random_en                        = 0
                                                 // bit 4   crc_start ( 0: finish 1: start ) = 0
                                                 // bit 3:0 crc_adr_port                     = 0

    ScalerSetByte(P4_4F_DDR_DCU_WRITE_RECOVERY, 0x01); // bit 7:4 reserved
                                                       // bit 3   new cke mode  = 1 0: disable / 1: enable  (20190625 jjtsai)   TBD
                                                       // bit 2:0 DDR write recovery cycle  = 101   000: 0 cycle / 001: 1 cycle / 010: 2 cycle / 011: 3 cycle TBD
                                                       // 100: 4 cycle / 101: 5 cycle / 110: 6 cycle / 111: 7 cycle

    ScalerSetByte(P4_A1_SDR_CTRL0, 0x1B); // bit 7   rst_dll        = 0
                                          // bit 6   reserved
                                          // bit 5:3 sdr_rd_delay   = 011
                                          // bit 2:0 sdr_wr_delay   = 011

    ScalerSetByte(P4_A2_SDR_CTRL1, 0x64); // bit 7:5 sdr_cl                               = 011
                                          // bit 4   burst_type                           = 0
                                          // bit 3:1 burst length                         = 010 BL = 4
                                          // bit 0   mode register set ( 0: mrs 1: emrs ) = 0

    ScalerSetByte(P4_A3_SDR_AREF_TIME, 0x0D); // Auto Refresh Time

    ScalerSetByte(P4_A4_SDR_PRCG, 0x93); // bit 7   Precharge all bank by ( 0: A8 1: A10 ) = 1
                                         // bit 6   Force to precharge all bank            = 0
                                         // bit 5   Columns per bank ( 0: 256 1: 512 )     = 0  256 column
                                         // bit 4   SDR reset ( 0: normal 1: reset )       = 1
                                         // bit 3:0 precharge delay cycle                  = 03

    ScalerSetByte(P4_A5_SDR_MEM_TYPE, 0x23); // bit 7:6 sdr_mem_size ( 00: 1Mx16x1 01: 4Mx16x1 10: 4Mx16x2 ) = 00
                                             // bit 5   sdr_bank_sel ( 0: 4bank 1: 2bank )                   = 1    2 bank
                                             // bit 4   sdr_abr_status                                       = 0
                                             // bit 3   sdr_abr_rec_en                                       = 0
                                             // bit 2:0 sdr_cas_latn                                         = 011  (20190703 jjtsai)   TBD

    ScalerSetByte(P4_A6_SDR_SLEW_RATE, 0x84); // bit 7   is_sdram ( 0: DDR 1: SDR ) = 1
                                              // bit 6:3 reserved
                                              // bit 2   sdr_auto_gating            = 1
                                              // bit 1   sdr_cke_l                  = 0
                                              // bit 0   sdr_cke_h                  = 0

#if(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_189MHZ)
    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x03); // Refresh interval for -40C ~ 125C
#else
    ScalerSetByte(P4_A7_SDR_AREF_CNT, 0x0C); // Periodic refresh command interval time  (STD FW must set 0xC)
#endif

    ScalerSetByte(P4_A8_SDR_CLK_ALIGN, 0x00); // bit 7   DDR / SDR Clock Align MPLL Reset ( 0: Normal 1: Reset )
                                              // bit 6:0 reserved

    ScalerSetByte(P4_AA_SDR_RSC_AREF, 0xFF); // sdr_rsc_aref        TBD
    ScalerSetByte(P4_AB_SDR_RSC_MCU, 0xFF); // sdr_rsc_mcu      TBD
    ScalerSetByte(P4_AC_SDR_RSC_CAP1, 0xFF); // CAP         TBD
    ScalerSetByte(P4_AE_SDR_RSC_MAIN, 0x44); // DISP            TBD
    ScalerSetByte(P4_B0_SDR_RSC_RTC_RD, 0x11); // OD R          TBD
    ScalerSetByte(P4_B1_SDR_RSC_RTC_WR, 0xAA); // OD W          TBD
    ScalerSetByte(P4_B7_SDR_POWER_CTRL0, 0x00); // bit 7   enter precharge power down mode
                                                // bit 6   power down ready
                                                // bit 5:4 sdr_powdn_cmd ( 00: precharge power down 01: reserved 10: deep power down 11: self refresh )
                                                // bit 3   Force CKE pin of SDRAM High
                                                // bit 2:0 reserved

    ScalerSetByte(P4_A4_SDR_PRCG, 0x93); // Controller reset
    ScalerSetByte(P4_A4_SDR_PRCG, 0x83);
    ScalerTimerDelayXms(2);
    //------------------------------
    // DCU End
    //------------------------------
}



//--------------------------------------------------
// Description  : SDRAMPLL Function Control
// Input Value  : Enable/Disable
// Output Value : None
//--------------------------------------------------
void ScalerSdramPLLCtrl(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Enable SDRPLL LDO
        ScalerSetDWord(P88_34_CRT_RST_CTL_34, 0x00000001);

        DELAY_XUS(150);

        // De-assert both PLL reset and PLL ptr reset
        ScalerSetDWord(P88_34_CRT_RST_CTL_34, 0x0000000F);

        DELAY_XUS(85);
    }
    else // Disable
    {
        // Assert both PLL reset and PLL ptr reset
        ScalerMaskSetDWord(P88_34_CRT_RST_CTL_34, 0xFFFFFFF3, 0x00000000);

        DELAY_XUS(85);

        // Disable SDRPLL LDO
        ScalerMaskSetDWord(P88_34_CRT_RST_CTL_34, 0xFFFFFFFE, 0x00000000);

        DELAY_XUS(150);
    }
}

//--------------------------------------------------
// Description  : SDRAMPLL Output Control
// Input Value  : Enable/Disable
// Output Value : None
//--------------------------------------------------
void ScalerSdramPLLOutputCtrl(bit bEnable)
{
    bEnable = bEnable;

    // Add deep power down
    ScalerSetBit(P4_B7_SDR_POWER_CTRL0, ~(_BIT7 | _BIT5), 0xA0);

    DELAY_XUS(85);

    // dpi_mck_clk_en / dpi_mck_mc_en = 0
    ScalerSetDWord(P88_04_PLL_CTL0_04, 0x00001007);

    DELAY_XUS(85);

    // dpi_clk_oe = 0
    ScalerSetDWord(P88_08_PLL_CTL1_08, 0x00000000);

    DELAY_XUS(85);
}

//--------------------------------------------------
// Description  : Set SDRAMPLL Freq
// Input Value  : Target DDR Data Rate (KHz)
// Output Value : None
//--------------------------------------------------
void ScalerSdramSetPLLFreq(DWORD ulFreq)
{
    ulFreq = ulFreq;

    // PLL LDO enable : pll_ldo_rst_n = 1(CRT_RST_CTL, bit[0])
    ScalerSetDWord(P88_34_CRT_RST_CTL_34, 0x00000009);

    // PLL initial value setting
    ScalerMaskSetDWord(P88_04_PLL_CTL0_04, 0xFFFFEFFF, 0x00001000);
    ScalerSetDWord(P88_1C_PLL_CTL3_1C, 0x17D866D0);
    ScalerMaskSetDWord(P88_00_CRT_CTL_00, 0x77FFFFFF, 0x00000000);
    ScalerSetDWord(P88_44_PLL_CTL5_44, 0x00101701);
    ScalerSetDWord(P88_40_CRT_CTL_SDR_40, 0x00000000); // 0x8843[2]sdr_pos_dout_sel: Need Test

    // Set Ncode, Fcode
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF00FF, (((DWORD)_MEMORYDEVICEPLL_N_CODE) << 8));
    ScalerMaskSetDWord(P88_28_SSC2_28, 0x0000FFFF, (((DWORD)_MEMORYDEVICEPLL_F_CODE) << 16));

#if(_SDRPLL_SSC_SUPPORT == _ON)
#if(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_189MHZ)
#if(_SDRPLL_SSC_AMPLITUDE == _0_5_PERCENT)
    // frequency_t = 189.5MHz, frequency_ssc = 188.5MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000A0A);
    ScalerSetDWord(P88_28_SSC2_28, 0x0F0C0A93);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x000054D1);
#elif(_SDRPLL_SSC_AMPLITUDE == _1_PERCENT)
    // frequency_t = 190MHz, frequency_ssc = 188MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000A0A);
    ScalerSetDWord(P88_28_SSC2_28, 0x11420857);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x0000A98E);
#elif(_SDRPLL_SSC_AMPLITUDE == _1_5_PERCENT)
    // frequency_t = 190.5MHz, frequency_ssc = 187.5MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000A0A);
    ScalerSetDWord(P88_28_SSC2_28, 0x1384061B);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x0000FE4C);
#elif(_SDRPLL_SSC_AMPLITUDE == _2_PERCENT)
    // frequency_t = 191MHz, frequency_ssc = 187MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000A0A);
    ScalerSetDWord(P88_28_SSC2_28, 0x15C003DF);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x00015309);
#endif
#elif(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_200MHZ)
#if(_SDRPLL_SSC_AMPLITUDE == _0_5_PERCENT)
    // frequency_t = 200.7MHz, frequency_ssc = 199.7MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000B0A);
    ScalerSetDWord(P88_28_SSC2_28, 0x011C3CA3);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x000054D1);
#elif(_SDRPLL_SSC_AMPLITUDE == _1_PERCENT)
    // frequency_t = 201.2MHz, frequency_ssc = 199.2MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000B0A);
    ScalerSetDWord(P88_28_SSC2_28, 0x03583A67);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x0000A98E);
#elif(_SDRPLL_SSC_AMPLITUDE == _1_5_PERCENT)
    // frequency_t = 201.7MHz, frequency_ssc = 198.7MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000B0A);
    ScalerSetDWord(P88_28_SSC2_28, 0x0594382B);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x0000FE4C);
#elif(_SDRPLL_SSC_AMPLITUDE == _2_PERCENT)
    // frequency_t = 202.2MHz, frequency_ssc = 198.2MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000B0A);
    ScalerSetDWord(P88_28_SSC2_28, 0x07D035EF);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x00015309);
#endif
#elif(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_216MHZ)
#if(_SDRPLL_SSC_AMPLITUDE == _0_5_PERCENT)
    // frequency_t = 216.54MHz, frequency_ssc = 215.46MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000C0C);
    ScalerSetDWord(P88_28_SSC2_28, 0x07E90316);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x00005B7B);
#elif(_SDRPLL_SSC_AMPLITUDE == _1_PERCENT)
    // frequency_t = 217.08MHz, frequency_ssc = 214.92MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000C0C);
    ScalerSetDWord(P88_28_SSC2_28, 0x0A5300AC);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x0000B709);
#elif(_SDRPLL_SSC_AMPLITUDE == _1_5_PERCENT)
    // frequency_t = 217.62MHz, frequency_ssc = 214.38MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000C0B);
    ScalerSetDWord(P88_28_SSC2_28, 0x0CBD3E42);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x00011298);
#elif(_SDRPLL_SSC_AMPLITUDE == _2_PERCENT)
    // frequency_t = 218.16MHz, frequency_ssc = 213.84MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000C0B);
    ScalerSetDWord(P88_28_SSC2_28, 0x0F273DB8);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x00016E26);
#endif
#elif(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_220MHZ)
#if(_SDRPLL_SSC_AMPLITUDE == _0_5_PERCENT)
    // frequency_t = 219.45MHz, frequency_ssc = 220.55MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000C0C);
    ScalerSetDWord(P88_28_SSC2_28, 0x19D614EB);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x00005D42);
#elif(_SDRPLL_SSC_AMPLITUDE == _1_PERCENT)
    // frequency_t = 218.9MHz, frequency_ssc = 221.1MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000C0C);
    ScalerSetDWord(P88_28_SSC2_28, 0x1C4B1276);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x0000BA72);
#elif(_SDRPLL_SSC_AMPLITUDE == _1_5_PERCENT)
    // frequency_t = 218.35MHz, frequency_ssc = 221.65MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000C0C);
    ScalerSetDWord(P88_28_SSC2_28, 0x1EC11001);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x000117B4);
#elif(_SDRPLL_SSC_AMPLITUDE == _2_PERCENT)
    // frequency_t = 217.8MHz, frequency_ssc = 222.2MHz, SSC Frequency = 66K
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xFFFF0000, 0x00000C0C);
    ScalerSetDWord(P88_28_SSC2_28, 0x21360D8B);
    ScalerMaskSetDWord(P88_24_SSC1_24, 0xFFF80000, 0x000174F7);
#endif
#endif // End if #if(_MEMORY_PLL_CLOCK == _MEMORY_SPEED_189MHZ))
#endif // End of #if(_SDRPLL_SSC_SUPPORT == _ON)

    // Release SSC NFCODE sync_reset : pll_ssc_dig_rst_n = 0x1 (CRT_RST_CTL, bit[1])
    ScalerSetDWord(P88_34_CRT_RST_CTL_34, 0x0000000B);

    // Enable pow_ldo_vco and external DVDD
    ScalerSetDWord(P88_0C_PLL_CTL2_0C, 0x03C00000);

    // De-assert DPI reset
    // ptr_rst_n = 0(CRT_RST_CTL,  bit[3])
    ScalerSetDWord(P88_34_CRT_RST_CTL_34, 0x00000003);
    // rst_n = 1(CRT_RST_CTL,  bit[2])
    ScalerSetDWord(P88_34_CRT_RST_CTL_34, 0x00000007);
    // ptr_rst_n = 1(CRT_RST_CTL,  bit[3])
    ScalerSetDWord(P88_34_CRT_RST_CTL_34, 0x0000000F);

    // SSC NFCODE fetch : OC_EN toggle :
    // step1. dpi_oc_en = 0x1 (SSC3,  bit[28])
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xEFFFFFFF, 0x10000000);
    // step2. dpi_oc_en = 0x0 (SSC3,  bit[28])
    ScalerMaskSetDWord(P88_48_SSC3_48, 0xEFFFFFFF, 0x00000000);
    // Initial SSC : dpi_ssc_flag_init = 0x1 (SSC0,  bit[31])
    ScalerMaskSetDWord(P88_20_SSC0_20, 0x7FFFFFFF, 0x80000000);

#if((_SDRPLL_SSC_SUPPORT == _ON) && ((_MEMORY_PLL_CLOCK == _MEMORY_SPEED_189MHZ) || (_MEMORY_PLL_CLOCK == _MEMORY_SPEED_216MHZ) || (_MEMORY_PLL_CLOCK == _MEMORY_SPEED_220MHZ)))
    // Initial SSC : dpi_ssc_flag_init = 0x1 and dpi_en_ssc =0x1
    ScalerMaskSetDWord(P88_20_SSC0_20, 0x7FFFFFFD, 0x80000002);
#endif

    // Turn on clock flow
    // step1. dpi_mck_clk_en / dpi_mck_mc_en = 1
    ScalerSetDWord(P88_04_PLL_CTL0_04, 0x80031007);

#if((_SDRAM_DPI_CRT_DLL_CAL == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_MCU_MODE))

    // Set phase control
    ScalerSdramDevicePLLSetPLLWritePhase();
#else
    // step2. dpi_oesync_op_sel (crt_spec) = 0x? (if value of dpi_post_pi* > 15, set oesync_op_sel[*] = 1)
    ScalerSetDWord(P88_10_PLL_PI0_10, 0x00000000);
    ScalerSetDWord(P88_14_PLL_PI1_14, 0x00000000);
    ScalerMaskSetDWord(P88_08_PLL_CTL1_08, 0xFFFFFFFC, 0x00000000);
#endif

    // step3. dpi_clk_oe (crt_spec) = 1
    ScalerMaskSetDWord(P88_08_PLL_CTL1_08, 0xFFFCFFFF, 0x00030000);

    // Disable CKE manual mode : CRT_CTL force_rstn* / force_cke* (CRT_CTL, bit[23][21]) = 0x0
    ScalerMaskSetDWord(P88_00_CRT_CTL_00, 0xFF5FFFFF, 0x00000000);

    // Debug
    DebugMessageDigital("6. Memory Devive PLL *** fvco=189M, N=0x0A, F=0x0CCF ***", 0);
    DebugMessageDigital("6. Memory Devive PLL Ncode =", (ScalerGetDWord(P88_48_SSC3_48) & 0x0000FF00));
    DebugMessageDigital("6. Memory Devive PLL Fcode[12:0] =", (ScalerGetDWord(P88_28_SSC2_28) & 0x1FFF0000));
    DebugMessageDigital("6. Memory Devive PLL ~Freq(Mhz) ~=Xtal*Ncode=", ((DWORD)14318 * ((((ScalerGetDWord(P88_48_SSC3_48)) & 0x0000FF00) >> 8) + 3 + ((ScalerGetDWord(P88_28_SSC2_28) & 0xFFFF0000) >> 16) / 16384) / 1000));
    DebugMessageDigital("6. Memory Devive PLL **********************", 0);
}

#if(_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM)
//--------------------------------------------------
// Description  : Sdram Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramControlReset(void)
{
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, _BIT4);
    ScalerSetBit(P4_A4_SDR_PRCG, ~_BIT4, 0x00);

    // Delay Time us [300,x] Waiting for SDRAM Control Reset
    DELAY_XUS(300);

    // Set Mclk Gen Reset Align MPLL
    // Set Mclk Gen Local Reset
    ScalerSetBit(P4_A8_SDR_CLK_ALIGN, ~_BIT7, _BIT7);

    // Delay Time us [300,x] Waiting for SDRAM Mclk Reset
    DELAY_XUS(300);

    // Set Mclk Gen Local Reset
    ScalerSetBit(P4_A8_SDR_CLK_ALIGN, ~_BIT7, 0x00);
}

#if((_SDRAM_DPI_CRT_DLL_CAL == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_MCU_MODE))
//--------------------------------------------------
// Description  : Set Memory Device PLL Write Phase
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramDevicePLLSetPLLWritePhase(void)
{
    StructMemoryDevicePLLPI stPI;

    // Set phase control
    stPI.ucCLK = g_pstSdramPLLPHASE[0].ucCLK;
    stPI.ucCMD = g_pstSdramPLLPHASE[0].ucCMD;

    stPI.ucCLK = stPI.ucCLK % _TOT_MEMORYDEVIC_PLL_PI_NUM;
    stPI.ucCMD = stPI.ucCMD % _TOT_MEMORYDEVIC_PLL_PI_NUM;

    // CLK/CMD/
    PDATA_DWORD(0) = (((DWORD)stPI.ucCMD << 8) | (DWORD)stPI.ucCLK);
    ScalerSetDWord(P88_10_PLL_PI0_10, PDATA_DWORD(0));

    // Set dpi_oesync_op_sel
    ScalerMaskSetDWord(P88_08_PLL_CTL1_08, 0xFFFFFFFC, GET_OESYNC_SETTING(stPI));
}
//--------------------------------------------------
// Description  : DDR2/DDR1/SDRAM offline phase calibration - MCU mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramOfflinePhaseCalMCUMode(void)
{
    if(g_bMemoryOfflinePhaseCalDone)
    {
        return;
    }
    //=================================
    // Phase calibration
    //=================================
    ScalerSdramOfflinePhaseCal();

    // DDR2 Offlie phase cal. done, update flag
    g_bMemoryOfflinePhaseCalDone = _TRUE;
}
//--------------------------------------------------
// Description  : Generate test data for phase check functions
// Input Value  : test data array(output array)
// Output Value : None
//--------------------------------------------------
void ScalerSdramPhaseChkMCUModeGenTestData(BYTE pucTestData[_MCU_MEMORY_DMA_BUF_LEN])
{
    static bit sbTestDataReset = _TRUE;
    static BYTE sucShiftFactor = 0;
    BYTE ucBufOffset = 0;
    static BYTE spucRawData[(_MCU_MEMORY_DMA_BUF_LEN + 1)];
    BYTE ucPrimeNum = 23;


    if(sbTestDataReset == _TRUE)
    {
        memcpy(spucRawData, tMEMORY_PHASE_CHK_TEST_DATA_SEED, _MCU_MEMORY_DMA_BUF_LEN);

        sbTestDataReset = _FALSE;
    }
    else
    {
        // Equivalently right circular shift one byte of data in the raw data buffer
        // when calculate next R/W testing data
        spucRawData[_MCU_MEMORY_DMA_BUF_LEN] = spucRawData[0];

        for(ucBufOffset = 0; ucBufOffset < _MCU_MEMORY_DMA_BUF_LEN; ucBufOffset++)
        {
            spucRawData[ucBufOffset] = ((((WORD)spucRawData[ucBufOffset + 1] * (WORD)tMEMORY_PHASE_CHK_TEST_DATA_SEED[ucBufOffset] + ucPrimeNum * sucShiftFactor) %
                                         (((WORD)tMEMORY_PHASE_CHK_TEST_DATA_SEED[(ucBufOffset + sucShiftFactor) % _MCU_MEMORY_DMA_BUF_LEN] << 1) + 1)) & 0xFF);
        }
    }

    memcpy(pucTestData, spucRawData, _MCU_MEMORY_DMA_BUF_LEN);

    sucShiftFactor = (sucShiftFactor + 1) % 4;
}
//--------------------------------------------------
// Description  : Print data buffer of phase check MCU mode
// Input Value  : data buffer array
// Output Value : None
//--------------------------------------------------
void ScalerSdramPhaseChkMCUModePrintDataBuf(BYTE pucDataBuf[_MCU_MEMORY_DMA_BUF_LEN])
{
    BYTE ucBufOffset = 0;

    for(ucBufOffset = 0; ucBufOffset < _MCU_MEMORY_DMA_BUF_LEN; ucBufOffset++)
    {
        pData[ucBufOffset % 4] = pucDataBuf[ucBufOffset];

        switch(ucBufOffset)
        {
            case 3:
                DebugMessageMemoryPhaseCal("00~03", PDATA_DWORD(0));
                break;

            case 7:
                DebugMessageMemoryPhaseCal("04~07", PDATA_DWORD(0));
                break;

            case 11:
                DebugMessageMemoryPhaseCal("08~11", PDATA_DWORD(0));
                break;

            case 15:
                DebugMessageMemoryPhaseCal("12~15", PDATA_DWORD(0));
                break;

            default:
                break;
        }
    }
}
//--------------------------------------------------
// Description  : Check DDR R/W correctness with MCU DDR DMA
// Input Value  : None
// Output Value : Result byte
//--------------------------------------------------
BYTE ScalerSdramPhaseCheckMCUMode(void)
{
    static WORD susMemAddrRow = 0;
    const WORD usADDR_ROW_STEP = 8; // Row step: 8 rows
    const WORD usADDR_BANK_AND_COL = 0x01A8; // Aribitraily chosen: DDR bank_3, column_160
    BYTE ucDDRSel = 0;
    BYTE ucResByte = 0;
    BYTE pucWrData[_MCU_MEMORY_DMA_BUF_LEN];
    BYTE pucRdData[_MCU_MEMORY_DMA_BUF_LEN];


    //====================================
    // Preparation
    //====================================
    ScalerSetByte(P33_A7_DCU_01, 0x01);

    ScalerSetByte(P37_01_MCU_DC_LEN, 0x02);

    // Set DMA memory address
    ScalerSetDWord(P37_04_MCU_DC_ADDR_H, (((DWORD)susMemAddrRow << 9) + usADDR_BANK_AND_COL));
    susMemAddrRow = (susMemAddrRow + usADDR_ROW_STEP) % _MEMORY_ROW;

    // Prepare data for write test
    ScalerSdramPhaseChkMCUModeGenTestData(pucWrData);

    //====================================
    // Write data
    //====================================
    // Write data to DMA write buffer registers
    ScalerWrite(P37_10_MCU_DC_DATABUF_W_00, _MCU_MEMORY_DMA_BUF_LEN, pucWrData, _AUTOINC);

    // Send write request
    ScalerSetByte(P37_00_MCU_DC_CMD, _MCU_MEMORY_DMA_CMD_WRITE);
    // Send NOP request
    ScalerSetByte(P37_00_MCU_DC_CMD, _MCU_MEMORY_DMA_CMD_NOP);

    // Polling qack of write request
    if(ScalerTimerPollingFlagProc(_MCU_DMA_POLLING_TIMEOUT, P37_00_MCU_DC_CMD, (_BIT7 | _BIT6 | _BIT5), _FALSE) == _FALSE)
    {
        DebugMessageMemoryPhaseCal("DDR DMA Write Timeout", 0);
    }

    // Delay 2 ms to ensure that write process is finished
    ScalerTimerDelayXms(2);

    //====================================
    // Read data
    //====================================
    // Read data buffer to clear uncleared ready-to-read flag (if it exists).
    ScalerRead(P37_20_MCU_DC_DATABUF_R_00, _MCU_MEMORY_DMA_BUF_LEN, pucRdData, _AUTOINC);

    // Send DDR read request
    ScalerSetByte(P37_00_MCU_DC_CMD, _MCU_MEMORY_DMA_CMD_READ);
    // Send NOP request
    ScalerSetByte(P37_00_MCU_DC_CMD, _MCU_MEMORY_DMA_CMD_NOP);

    // Delay 2 ms to ensure that read process is finished
    ScalerTimerDelayXms(5);

    // Read data from DMA read buffer registers
    // SDR and DDR1 need to read twice!!
    ScalerRead(P37_20_MCU_DC_DATABUF_R_00, _MCU_MEMORY_DMA_BUF_LEN, pucRdData, _AUTOINC);
    ScalerRead(P37_20_MCU_DC_DATABUF_R_00, _MCU_MEMORY_DMA_BUF_LEN, pucRdData, _AUTOINC); // Test

    //====================================
    // Compare read data with wrote data
    //====================================
    SET_BIT_RESULT(&ucResByte, ucDDRSel, ((memcmp(pucRdData, pucWrData, _MCU_MEMORY_DMA_BUF_LEN) == 0) ? _SUCCESS : _FAIL));

    //====================================
    // Print debug message if needed
    //====================================
#if(_PHASE_CHK_DEBUG_MSG == _ON)
#if(_PHASE_CHK_DEBUG_DETAIL_MSG == _ON)

    if(GET_BIT_RESULT(&ucResByte, ucDDRSel) != _SUCCESS)
    {
        // Print write data
        DebugMessageMemoryPhaseCal("Memory Write:", 0);
        ScalerSdramPhaseChkMCUModePrintDataBuf(pucWrData);
        // Print read data
        DebugMessageMemoryPhaseCal("Memory Read:", 0);
        ScalerSdramPhaseChkMCUModePrintDataBuf(pucRdData);
    }
    else
    {
        DebugMessageMemoryPhaseCal("Memory Passed", 1);
    }
#endif // End of #if(_PHASE_CHK_DEBUG_DETAIL_MSG == _ON)
#endif // End of #if(_PHASE_CHK_DEBUG_MSG == _ON)

#if(_PHASE_CHK_DEBUG_MSG == _ON)
    DebugMessageMemoryPhaseCal("** MCU Phase Chk Result.", ucResByte);
#endif

    ScalerSetByte(P33_A7_DCU_01, 0x00);

    return ucResByte;
}
//--------------------------------------------------
// Description  : DDR2/DDR1/SDRAM offline phase calibration
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramOfflinePhaseCal(void)
{
    StructMemoryPhaseInfo pstPrevFoundPhase[1];
    StructMemoryPhaseInfo pstCurrFoundPhase[1];

    //===========================================
    // Set initial phase
    //===========================================
    DebugMessageMemoryPhaseCal("===================", 0);
    DebugMessageMemoryPhaseCal("_____MCU_Mode_____", 0);
    DebugMessageMemoryPhaseCal("___________Version:", 20221012);
    DebugMessageMemoryPhaseCal("===================", 0);

    // Reset global varIABLE TO ZERO
    memset(&g_pstSdramPLLPHASE, 0x00, sizeof(g_pstSdramPLLPHASE));

    // SDR
    memset(&pstPrevFoundPhase, 0x00, sizeof(pstPrevFoundPhase));
    memset(&pstCurrFoundPhase, 0x00, sizeof(pstCurrFoundPhase));

    //===========================================
    // Phase Scan - CLK
    //===========================================
    DebugMessageMemoryPhaseCal("====ScanPhase CLK====", 0);
    if(ScalerSdramOfflinePhaseScanCLK(pstPrevFoundPhase, pstCurrFoundPhase) == _FAIL)
    {
        pstCurrFoundPhase[0] = pstPrevFoundPhase[0];
    }
    //===========================================
    // Phase Scan - RDQ Dly Tap
    //===========================================
    DebugMessageMemoryPhaseCal("==ScanPhase Rx ==", 0);
    ScalerSdramOfflineScanRx();

    //===========================================
    // Phase Scan - Rx FIFO
    //===========================================
    DebugMessageMemoryPhaseCal("==ScanPhase RX_FIFO ==", 0);
    ScalerSdramOfflineScanRxFIFO();

    // Print Result
    ScalerSdramPrintPhaseCalResult(pstCurrFoundPhase);
    pstPrevFoundPhase[0] = pstCurrFoundPhase[0];
}
//--------------------------------------------------
// Description  : DDR2/DDR1/SDRAM offline phase calibration - scan CLK
// Input Value  : Previous phase cal result, current phase cal result
// Output Value : Pass range found      -> _SUCCESS
//                Pass range not found  -> _FAIL
//--------------------------------------------------
bit ScalerSdramOfflinePhaseScanCLK(StructMemoryPhaseInfo pstPrevResult[1], StructMemoryPhaseInfo pstCurrResult[1])
{
    BYTE ucPIIndex = 0;
    BYTE ucChkResByte = 0;
    StructMemoryPLLPI pstPI[1];
    BYTE ucPIValidity = 0;
    BYTE ucPassRangeFound = 0;
    BYTE ucTargetPllClk = 0;
    BYTE pucScanResult[_THEO_PI_SCAN_BUF_LEN] = {0};
    BYTE *ppucScanResult[] = {pucScanResult};

    //===============================================
    // Copy previous result
    //===============================================
    // Copy the fixed PI(CMD) from previous result
    pstPI[0] = pstPrevResult[0].stPLL;

    //===============================================
    //===============================================
    // Scan for CLK pass region - post 1T
    for(ucPIIndex = _BEGIN_THEO_PI; ucPIIndex < _TOTAL_THEO_DPI_PI_NUM; ucPIIndex++)
    {
        // Update PIs of CLK
        SET_BIT_RESULT(&ucPIValidity, 0, ScalerSdramCalcTheoPhase(_CLK, ucPIIndex, &(pstPrevResult[0].stPLL), &pstPI[0]));
        if(GET_BIT_RESULT(&ucPIValidity, 0))
        {
            // global variables are set to the new phase
            g_pstSdramPLLPHASE[0] = pstPI[0];
        }
        // Apply New Phase
        ScalerSdramApplyNewPhase();

        // Phase check
        ucChkResByte = ScalerSdramPhaseCheck();

        // Save check result to result buffer
        SET_BIT_RESULT(ppucScanResult[0], ucPIIndex, (GET_BIT_RESULT(&ucPIValidity, 0) ? GET_BIT_RESULT(&ucChkResByte, 0) : _FALSE));
    }

    //===============================================
    // Process scanned result
    //===============================================
    // Print pass range
    ScalerSdramPrintScanResult(ppucScanResult[0], _SCAN_RESULT_WR_PI, 0);
    DebugMessageMemoryPhaseCal(("*** Memory CLK ***"), 0);

    // Markup the target PLL clk
    SET_BIT_RESULT(&ucTargetPllClk, 0, _TRUE);
    // Update the best PI of CLK to current result
    SET_BIT_RESULT(&ucPassRangeFound, 0, ScalerSdramFindPassRangeMidpoint(ppucScanResult[0], _SCAN_RESULT_WR_PI, &(pstCurrResult[0].stPLL.ucCLK), _ENABLE));
    // TODO: error handling

    // Update whole current PLL result accroding to above result
    pstCurrResult[0].stPLL.ucCMD = pstPrevResult[0].stPLL.ucCMD;
    ScalerSdramCalcTheoPhase(_CLK, pstCurrResult[0].stPLL.ucCLK, &(pstPrevResult[0].stPLL), &(pstCurrResult[0].stPLL));

    // Update global vaiable of DDRPLL phase according to current result
    g_pstSdramPLLPHASE[0] = pstCurrResult[0].stPLL;
    ScalerSdramApplyNewPhase();

    // Return _SUCCESS if all target PLL clks' pass range have been found
    return ((ucPassRangeFound == ucTargetPllClk) ? _SUCCESS : _FAIL);
}

//--------------------------------------------------
// Description  : Calculate correspoding theoretical
//                PLL PI for phase calibration process
// Input Value  : Main PLL clk, main PLL clk PI,
//                origin PI of each PLL clk,
//                result PI of each PLL clk(i.e. the output struct)
// Output Value : Valid phase   -> _TRUE
//                Invalid phase -> _FALSE
//--------------------------------------------------
bit ScalerSdramCalcTheoPhase(EnumMemoryPLLClk enumMainClk, BYTE ucMainClkPI, StructMemoryPLLPI *pstOrigPI, StructMemoryPLLPI *pstResultPI)
{
    SWORD shMainPIOffset = 0;
    BYTE ucInvRecord = 0x00; // Invalid record

    switch(enumMainClk)
    {
        case _CLK:
            //===========================================================
            // Update PIs of DQS0, DQS1, DQ0, DQ1 according to PI of CLK
            //===========================================================
            shMainPIOffset = (SWORD)ucMainClkPI - pstOrigPI->ucCLK;

            // If valid, calculate PI of each PLL clk
            if(ucInvRecord == 0x00)
            {
                pstResultPI->ucCLK = ucMainClkPI; // Main clk
                // pstResultPI->ucCMD is left unchanged
            }
            break;

        default:
            ucInvRecord = 0xFF;
            break;
    }

    return ((ucInvRecord == 0x00) ? _TRUE : _FALSE);
}
//--------------------------------------------------
// Description  : Reset memory related blocks
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramApplyNewPhase(void)
{
    //------------------------------
    // Reset DC PHY
    //------------------------------
    // Disable CLK output, Reset PLL, Disable PLL
    ScalerSdramPLLOutputCtrl(_DISABLE);
    ScalerSdramPLLCtrl(_DISABLE);

    ScalerSetBit(P33_90_M_DOMAIN_MCLK_SET_A, ~_BIT2, 0x00);
    ScalerTimerDelayXms(2);
    ScalerSetBit(P33_90_M_DOMAIN_MCLK_SET_A, ~_BIT2, _BIT2);

    ScalerTimerDelayXms(2);
    // Set DDR PLL CLK
    ScalerSdramSetPLLFreq((DWORD)_MEMORY_DATA_RATE_SPEED * 1000);
    // Init DC PHY
    ScalerSdramDCPHYInitial();
    ScalerTimerDelayXms(2);
}

//--------------------------------------------------
// Description  : Check DDR R/W correctness of specific phase set
// Input Value  : None
// Output Value : Phase check result byte
//--------------------------------------------------
BYTE ScalerSdramPhaseCheck(void)
{
    return ScalerSdramPhaseCheckMCUMode();
}
//--------------------------------------------------
// Description  : Print scan result of phase calibration process
// Input Value  : Array of scan result, scan type, bDDRSel
// Output Value : None
//--------------------------------------------------
void ScalerSdramPrintScanResult(BYTE pucResult[], EnumScanResultType enumScanType, bit bDDRSel)
{
    BYTE ucBufIndex = 0;

    bDDRSel = bDDRSel;

    DebugMessageMemoryPhaseCal("==Memory Scan Result==", 0);

    switch(enumScanType)
    {
        case _SCAN_RESULT_WR_PI:
            DebugMessageMemoryPhaseCal("63~32", (((DWORD)pucResult[7] << 24) | ((DWORD)pucResult[6] << 16) | ((DWORD)pucResult[5] << 8) | pucResult[4]));
            DebugMessageMemoryPhaseCal("31~00", (((DWORD)pucResult[3] << 24) | ((DWORD)pucResult[2] << 16) | ((DWORD)pucResult[1] << 8) | pucResult[0]));

            break;

        case _SCAN_RESULT_RD_DLY_TAP:
            for(ucBufIndex = 0; ucBufIndex < _RDQ_DLY_SCAN_BUF_LEN; ucBufIndex++)
            {
                pData[ucBufIndex % 4] = pucResult[(_RDQ_DLY_SCAN_BUF_LEN - 1) - ucBufIndex];

                if(ucBufIndex == 3)
                {
                    DebugMessageMemoryPhaseCal("031~000", PDATA_DWORD(0));
                }
            }
            break;

        case _SCAN_RESULT_RX_FIFO:
            for(ucBufIndex = 0; ucBufIndex < _RX_FIFO_SCAN_BUF_LEN; ucBufIndex++)
            {
                pData[ucBufIndex % 4] = pucResult[(_RX_FIFO_SCAN_BUF_LEN - 1) - ucBufIndex];

                if(ucBufIndex == 3)
                {
                    DebugMessageMemoryPhaseCal("031~000", PDATA_DWORD(0));
                }
            }
            break;

        default:
            break;
    }
}
//--------------------------------------------------
// Description  : Find midpoint of longest pass range according to scan result
// Input Value  : Array of scan result, scan result type, pointer to output midpoint value
// Output Value : Whether the minpoint is found: _SUCCESS/_FAIL
//--------------------------------------------------
bit ScalerSdramFindPassRangeMidpoint(BYTE pucResult[], EnumScanResultType enumScanType, BYTE *pucMidpoint, bit bMsgEnable)
{
    BYTE ucLongestPassIntvlStart = 0;
    BYTE ucLongestPassIntvlEnd = 0;
    BYTE ucLongestPassIntvlLength = 0;
    BYTE ucLongestPassIntvlForbidPICount = 0;
    // Forbidden PI: 15/31/47/63/79/95/111/127
    BYTE ucMidpoint = 0;
    BYTE ucPassIntvlStart = 0;
    BYTE ucPassIntvlEnd = 0;
    BYTE ucPassIntvlLength = 0;
    BYTE ucPassIntvlForbidPICount = 0;

    bit bPassRangeExist = _FALSE;
    BYTE ucBufIndex = 0;

    if(enumScanType == _SCAN_RESULT_WR_PI)
    {
        if(GET_BIT_RESULT(pucResult, 0) == _SUCCESS)
        {
            ucPassIntvlStart = 0;
            bPassRangeExist = _TRUE;
        }

        for(ucBufIndex = 0; ucBufIndex < _TOTAL_THEO_DPI_PI_NUM; ucBufIndex++)
        {
            // Ignore the frobidden PIs if it is included in pass range
            // PPP_PP...
            // ---^Don't care
            if(((ucBufIndex < (_TOTAL_THEO_DPI_PI_NUM - 1)) && ((ucBufIndex & 0x0F) == 0x0F)) &&
               (GET_BIT_RESULT(pucResult, (ucBufIndex - 1)) == _SUCCESS) && (GET_BIT_RESULT(pucResult, (ucBufIndex + 1)) == _SUCCESS))
            {
                ucPassIntvlForbidPICount++;
                continue;
            }


            if((GET_BIT_RESULT(pucResult, ucBufIndex) == _SUCCESS) && (GET_BIT_RESULT(pucResult, (ucBufIndex - 1)) == _FAIL))
            {
                if((((ucBufIndex - 1) & 0x0F) == 0x0F) && (GET_BIT_RESULT(pucResult, (ucBufIndex - 2)) == _SUCCESS))
                {
                    // Avoid misjudgement of start point
                    continue;
                }

                // From "fail" to "pass": FFFPP...
                // --------------------------^Start
                ucPassIntvlStart = ucBufIndex;
                bPassRangeExist = _TRUE;
            }
            else if((GET_BIT_RESULT(pucResult, ucBufIndex) == _FAIL) && (GET_BIT_RESULT(pucResult, (ucBufIndex - 1)) == _SUCCESS))
            {
                // From "pass" to "fail": PPPFF...
                // -------------------------^End
                ucPassIntvlEnd = ucBufIndex - 1;
                ucPassIntvlLength = ucPassIntvlEnd - ucPassIntvlStart + 1;

                if(ucPassIntvlLength > ucLongestPassIntvlLength)
                {
                    ucLongestPassIntvlLength = ucPassIntvlLength;
                    ucLongestPassIntvlStart = ucPassIntvlStart;
                    ucLongestPassIntvlEnd = ucPassIntvlEnd;
                    ucLongestPassIntvlForbidPICount = ucPassIntvlForbidPICount;
                }
                // Clear forbidden PI count
                ucPassIntvlForbidPICount = 0;
            }
        } // End of for(ucBufIndex = 0; ucBufIndex < _TOTAL_THEO_DPI_PI_NUM; ucBufIndex++)

        if(bPassRangeExist == _FALSE)
        {
            if(bMsgEnable)
            {
                DebugMessageMemoryPhaseCal("Pass Range Not Found!", 0);
            }
            return _FAIL;
        }

        if((ucLongestPassIntvlStart == ucLongestPassIntvlEnd) && ((ucLongestPassIntvlStart & 0x0F) == 0x0F))
        {
            if(bMsgEnable)
            {
                DebugMessageMemoryPhaseCal("Valid Midpoint Not Found!", 0);
            }
            return _FAIL;
        }

        ucMidpoint = (ucLongestPassIntvlStart + ucLongestPassIntvlEnd) / 2;
        if((ucMidpoint & 0x0F) == 0x0F)
        {
            ucMidpoint += 1;
        }

        if(bMsgEnable)
        {
            DebugMessageMemoryPhaseCal("Pass Intvl Start:", ucLongestPassIntvlStart);
            DebugMessageMemoryPhaseCal("Pass Intvl End:", ucLongestPassIntvlEnd);
            DebugMessageMemoryPhaseCal("Best PI:", ucMidpoint);
        }

        *pucMidpoint = ucMidpoint;

        return _SUCCESS;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Print phase calibration result
// Input Value  : Array of phase calibration result
// Output Value : None
//--------------------------------------------------
void ScalerSdramPrintPhaseCalResult(StructMemoryPhaseInfo pstResult[1])
{
    pstResult = pstResult;
    DebugMessageMemoryPhaseCal("*******************", 0);
    DebugMessageMemoryPhaseCal("***Cal. Result****", 0);
    DebugMessageMemoryPhaseCal("***** Memory *****", 0);
    DebugMessageMemoryPhaseCal("*****  CLK Phase = ", pstResult[0].stPLL.ucCLK);
    DebugMessageMemoryPhaseCal("*****  CMD Phase = ", pstResult[0].stPLL.ucCMD);
    DebugMessageMemoryPhaseCal("*******************", 0);
}
//--------------------------------------------------
// Description  : Rx tm_dqs_en[4:1] & sdr_pos_dout_sel Scan
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSdramOfflineScanRx(void)
{
    BYTE ucDQSEnNum = 0;
    BYTE ucChkResByte = 0;
    BYTE pucScanResult[4] = {0};
    BYTE *ppucScanResult[] = {pucScanResult};

    // Right Case I, tm_dqs_en[4:1]=N & sdr_pos_dout_sel = 1 (postive sample)

    DebugMessageMemoryPhaseCal("====Right Case I Start====", 0x01);
    ScalerMaskSetDWord(P88_40_CRT_CTL_SDR_40, 0xFFFFFFFD, 0x00000002);

    for(ucDQSEnNum = 0; ucDQSEnNum < 32; ucDQSEnNum++)
    {
        ScalerSetDWord(P8E_54_READ_CTRL_0_54, (DWORD)ucDQSEnNum); // slice_0: DQS_0
        ScalerSetDWord(P8E_58_READ_CTRL_0_58, (DWORD)ucDQSEnNum); // slice_1: DQS_1

        // Phase check
        ucChkResByte = ScalerSdramPhaseCheck();

        // Save check result to result buffer
        SET_BIT_RESULT(ppucScanResult[0], ucDQSEnNum, ucChkResByte);
    }

    DebugMessageMemoryPhaseCal("====31~00====", (((DWORD)pucScanResult[3] << 24) | ((DWORD)pucScanResult[2] << 16) | ((DWORD)pucScanResult[1] << 8) | pucScanResult[0]));
    DebugMessageMemoryPhaseCal("====Right Case I End====", 0x01);

    // Right Case II, tm_dqs_en[4:1]=N & sdr_pos_dout_sel = 0 (negative sample)
    DebugMessageMemoryPhaseCal("====Right Case II Start====", 0x02);
    ScalerMaskSetDWord(P88_40_CRT_CTL_SDR_40, 0xFFFFFFFD, 0x00000000);

    for(ucDQSEnNum = 0; ucDQSEnNum < 32; ucDQSEnNum++)
    {
        ScalerSetDWord(P8E_54_READ_CTRL_0_54, (DWORD)ucDQSEnNum); // slice_0: DQS_0
        ScalerSetDWord(P8E_58_READ_CTRL_0_58, (DWORD)ucDQSEnNum); // slice_1: DQS_1
        // Phase check
        ucChkResByte = ScalerSdramPhaseCheck();

        // Save check result to result buffer
        SET_BIT_RESULT(ppucScanResult[0], ucDQSEnNum, ucChkResByte);
    }
    DebugMessageMemoryPhaseCal("====31~00====", (((DWORD)pucScanResult[3] << 24) | ((DWORD)pucScanResult[2] << 16) | ((DWORD)pucScanResult[1] << 8) | pucScanResult[0]));
    DebugMessageMemoryPhaseCal("====Right Case II End====", 0x02);

    ScalerMaskSetDWord(P88_40_CRT_CTL_SDR_40, 0xFFFFFFFD, 0x00000000);
    // RDQS enable latency
    ScalerSetDWord(P8E_54_READ_CTRL_0_54, 0x00000004); // slice_0: DQS_0
    ScalerSetDWord(P8E_58_READ_CTRL_0_58, 0x00000004); // slice_1: DQS_1
}
//--------------------------------------------------
// Description  : DDR2/DDR1/SDR offline phase calibration - scan Rx FIFO
// Input Value  : Previous phase cal result, current phase cal result
// Output Value : Pass range found      -> _SUCCESS
//                Pass range not found  -> _FAIL
//--------------------------------------------------
void ScalerSdramOfflineScanRxFIFO(void)
{
    BYTE ucRxFIFOIndex = 0;
    BYTE ucDDRSel = 0;
    BYTE ucChkResByte = 0;
    BYTE pucScanResultA[_RX_FIFO_SCAN_BUF_LEN] = {0};
    BYTE *ppucScanResult[1] = {pucScanResultA};

    //===========================================================================
    // DPI setting
    //===========================================================================
    // FW set mode = 'b10 (immediately)
    ScalerMaskSetDWord(P8F_7C_DPI_CTRL_0_7C, 0xFFFFFFFC, 0x00000002);

    //===========================================================================
    // Scan Rx FIFO
    //===========================================================================
    for(ucRxFIFOIndex = 0; ucRxFIFOIndex < _TOT_RX_FIFO_SEL_NUM; ucRxFIFOIndex++)
    {
        // Set Rx FIFO
        ScalerMaskSetDWord(P8E_64_READ_CTRL_1_64, 0xFFFFFFE0, ucRxFIFOIndex);

        // fw_set_rd_dly
        ScalerMaskSetDWord(P8F_80_DPI_CTRL_1_80, 0xFFFFFFF3, 0x0000000C);

        // Phase check
        ucChkResByte = ScalerSdramPhaseCheck();

        // Save check result to result buffer
        SET_BIT_RESULT(ppucScanResult[ucDDRSel], ucRxFIFOIndex, GET_BIT_RESULT(&ucChkResByte, ucDDRSel));
    }
    // TODO: resume Rx FIFO setting to default value

    // Set Rx FIFO
    ScalerMaskSetDWord(P8E_64_READ_CTRL_1_64, 0xFFFFFFE0, 0x00000005);
    // fw_set_rd_dly
    ScalerMaskSetDWord(P8F_80_DPI_CTRL_1_80, 0xFFFFFFF3, 0x0000000C);

    // Print scan result
    DebugMessageMemoryPhaseCal("=== Rx FIFO ===", 0);

    ScalerSdramPrintScanResult(ppucScanResult[0], _SCAN_RESULT_RX_FIFO, 0);
}
#endif // #if((_SDRAM_DPI_CRT_DLL_CAL == _ON) && (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_MCU_MODE))

#endif // if(_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM)


