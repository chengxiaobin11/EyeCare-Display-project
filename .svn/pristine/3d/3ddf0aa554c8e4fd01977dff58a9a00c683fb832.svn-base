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
// ID Code      : RL6851_Series_MemoryInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define SET_IVS2DVS_DELAY_16ICLK1(usBackup)         {\
                                                        ScalerSetBit(P0_3F_DISPLAY_ALIGN_CONTROL, ~_BIT4, ((HIBYTE(usBackup) & 0x01) << 4));\
                                                        ScalerSetByte(P0_41_IVS2DVS_DLY_TUNE_ODD, LOBYTE(usBackup));\
                                                    }

#define SET_IVS2DVS_DELAY_16ICLK2(usBackup)         {\
                                                        ScalerSetBit(P0_3F_DISPLAY_ALIGN_CONTROL, ~_BIT0, (HIBYTE(usBackup) & 0x01));\
                                                        ScalerSetByte(P0_42_IVS2DVS_DLY_TUNE_EVEN, LOBYTE(usBackup));\
                                                    }

#define _VSU_INI_PHASE_LINES                        _VSU_4_LINE

//--------------------------------------------------
// Memory Efficiency
//--------------------------------------------------
#define _MEMORY_EFFICIENCY_INCREACE_ON_ONLY         ((_M2PLL_FREQ_SEL_BY_SDRAM_CLK == _M2PLL_FREQ_220M) ? 9 : ((_IMD_DOMAIN_ULTRA_HIGH_SPEED_SUPPORT == _ON) ? 4 : 0))
#define _MEMORY_EFFICIENCY                          (85)

#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
//--------------------------------------------------
// Define Total Bandwidth
//--------------------------------------------------
#define _MEMORY_TOTAL_BW                            ((DWORD)_MEMORY_DATA_RATE_SPEED * _MEMORY_EFFICIENCY / 10)
#define GET_MEMORY_TOTAL_BW()                       (_MEMORY_TOTAL_BW)

#endif // End of #if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
//--------------------------------------------------
// M domain Fifo bit
//--------------------------------------------------
#define _M_DOMAMAIN_FIFO_BIT                        (46848) // 488*96 bit

//--------------------------------------------------
// D Domain Request
//--------------------------------------------------
#define GET_D_DOMAIN_REQUEST()                      (_64_PIXELS_AFTER_DVS)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    DWORD ulLineStep;
    DWORD ulBlockStep;
} StructMemoryLineBlockStep;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMemorySetFifoCapture(WORD usHWidth, WORD usVHeight);
extern WORD ScalerMemoryGetFifoWidth(void);
extern void ScalerMemoryFrameSyncSetDt(BYTE ucNum);
extern DWORD ScalerMemoryGetIVS2DVSDelayPixel(void);
extern void ScalerMemorySetFIFOFreq(EnumScalerFIFOFreq enumFIFOFreq);
#if(_FRC_SUPPORT == _ON)
extern void ScalerMemoryCalculateLineStepAndBlockStep(DWORD ulHorSize, WORD usVerSize, StructMemoryLineBlockStep *pstMemoryLineBlockStep);
extern bit ScalerMemoryCheckScreenCoverStatus(void);
#endif

#if(_FREESYNC_SUPPORT == _ON)
extern void ScalerMemorySetShiftOneLine(bit bEnable);
#endif

#if(_DT_RANGE_TEST_SUPPORT == _ON)
extern void ScalerMemoryDtRangeTest(void);
#endif

