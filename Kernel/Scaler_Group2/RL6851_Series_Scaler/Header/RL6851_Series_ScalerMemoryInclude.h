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
// ID Code      : RL6851_Series_ScalerMemoryInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Memory Speed
//--------------------------------------------------
#define _MEMORY_PLL_CLOCK                           _M2PLL_CLK_MHZ
#define _MEMORY_DATA_RATE_SPEED                     _MEMORY_PLL_CLOCK

//--------------------------------------------------
// Memory Size
//--------------------------------------------------
#if(_MEMORY_TYPE_CONFIG == _NO_MEMORY)
#define _MEMORY_BUS_WIDTH                           0
#define _MEMORY_SIZE                                0
#define _MEMORY_BIT_NUM                             0
#define _MEMORY_BANK                                0
#define _MEMORY_COL_PER_BANK                        256
#define _MEMORY_ROW                                 2048
#elif(_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM)

#if(_MEMORY_SIZE_CONFIG == _1M_16BIT_SDRAM)
#define _MEMORY_BUS_WIDTH                           16
#define _MEMORY_SIZE                                _MEMORY_16MB
#define _MEMORY_BIT_NUM                             16
#define _MEMORY_BANK                                2
#define _MEMORY_COL_PER_BANK                        256
#define _MEMORY_ROW                                 2048
#endif

#elif(_MEMORY_TYPE_CONFIG == _MEMORY_DDR1)

#if(_MEMORY_SIZE_CONFIG == _4M_16BIT_DDR1_1PC)
#define _MEMORY_BUS_WIDTH                           16
#define _MEMORY_SIZE                                _MEMORY_64MB
#define _MEMORY_BIT_NUM                             16
#define _MEMORY_BANK                                4
#define _MEMORY_COL_PER_BANK                        256
#define _MEMORY_ROW                                 4096
#elif(_MEMORY_SIZE_CONFIG == _4M_16BIT_DDR1_2PCS)
#define _MEMORY_BUS_WIDTH                           32
#define _MEMORY_SIZE                                _MEMORY_128MB
#define _MEMORY_BIT_NUM                             32
#define _MEMORY_BANK                                4
#define _MEMORY_COL_PER_BANK                        256
#define _MEMORY_ROW                                 4096
#endif

#elif(_MEMORY_TYPE_CONFIG == _MEMORY_DDR2)

#if(_MEMORY_SIZE_CONFIG == _16M_16BIT_DDR2_1PC)
#define _MEMORY_BUS_WIDTH                           16
#define _MEMORY_SIZE                                _MEMORY_256MB
#define _MEMORY_BIT_NUM                             16
#define _MEMORY_BANK                                4
#define _MEMORY_COL_PER_BANK                        512
#define _MEMORY_ROW                                 8192
#elif(_MEMORY_SIZE_CONFIG == _16M_16BIT_DDR2_2PCS)
#define _MEMORY_BUS_WIDTH                           32
#define _MEMORY_SIZE                                _MEMORY_512MB
#define _MEMORY_BIT_NUM                             32
#define _MEMORY_BANK                                4
#define _MEMORY_COL_PER_BANK                        512
#define _MEMORY_ROW                                 8192
#endif

#elif(_MEMORY_TYPE_CONFIG == _MEMORY_DDR3)

#if(_MEMORY_SIZE_CONFIG == _1G_16BIT_DDR3_1PC)
#define _MEMORY_BUS_WIDTH                           (16)
#define _MEMORY_SIZE                                (_MEMORY_1GB)
#define _MEMORY_BIT_NUM                             (16)
#define _MEMORY_BANK                                8
#define _MEMORY_COL_PER_BANK                        1024
#define _MEMORY_ROW                                 8192
#elif(_MEMORY_SIZE_CONFIG == _1G_16BIT_DDR3_2PCS)
#define _MEMORY_BUS_WIDTH                           (16 * 2)
#define _MEMORY_SIZE                                (_MEMORY_1GB * 2)
#define _MEMORY_BIT_NUM                             (16 * 2)
#define _MEMORY_BANK                                8
#define _MEMORY_COL_PER_BANK                        1024
#define _MEMORY_ROW                                 8192
#elif(_MEMORY_SIZE_CONFIG == _2G_16BIT_GDDR3_1PC)
#define _MEMORY_BUS_WIDTH                           (16)
#define _MEMORY_SIZE                                (_MEMORY_2GB)
#define _MEMORY_BIT_NUM                             (16)
#define _MEMORY_BANK                                8
#define _MEMORY_COL_PER_BANK                        1024
#define _MEMORY_ROW                                 16384
#elif(_MEMORY_SIZE_CONFIG == _2G_16BIT_GDDR3_2PCS)
#define _MEMORY_BUS_WIDTH                           (16 * 2)
#define _MEMORY_SIZE                                (_MEMORY_2GB * 2)
#define _MEMORY_BIT_NUM                             (16 * 2)
#define _MEMORY_BANK                                8
#define _MEMORY_COL_PER_BANK                        1024
#define _MEMORY_ROW                                 16384
#elif(_MEMORY_SIZE_CONFIG == _4G_16BIT_GDDR3_1PC)
#define _MEMORY_BUS_WIDTH                           (16)
#define _MEMORY_SIZE                                (_MEMORY_4GB)
#define _MEMORY_BIT_NUM                             (16)
#define _MEMORY_BANK                                8
#define _MEMORY_COL_PER_BANK                        1024
#define _MEMORY_ROW                                 32768
#elif(_MEMORY_SIZE_CONFIG == _4G_16BIT_GDDR3_2PCS)
#define _MEMORY_BUS_WIDTH                           (16 * 2)
#define _MEMORY_SIZE                                (_MEMORY_4GB * 2)
#define _MEMORY_BIT_NUM                             (16 * 2)
#define _MEMORY_BANK                                8
#define _MEMORY_COL_PER_BANK                        1024
#define _MEMORY_ROW                                 32768
#endif

#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMemoryInitial(void);

#if(_LAST_LINE_FINETUNE_ENABLE == _ENABLE)
extern void ScalerMemoryCompensateDtForLastLine(DWORD ulTargetLastLine, DWORD ulCurrentLastLine);
#endif

extern void ScalerMemoryUpdateIVS2DVSLineDelay(DWORD ulCompsIVS2DVSpixel);
extern void ScalerMemorySetIVS2DVSLineDelay(WORD usIVS2DVSDelay);
extern void ScalerMemoryFineTuneIVS2DVSDelay(WORD usOldIVS2DVSDelay, WORD usNewIVS2DVSDelay, WORD usIVS2DVSChgLimit);
extern WORD ScalerMemoryGetScaleUpDt(void);

#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
extern void ScalerMemoryReset(void);
#endif

#if(_FRC_SUPPORT == _ON)
extern void ScalerMemorySetFrameTrackingEnable(bit bEn);
extern bit ScalerMemoryGetFrameTrackingEnable(void);
extern void ScalerMemoryFrameTracking(void);
extern WORD ScalerMemoryGetMNRatio(void);
#endif

#if(_OD_SUPPORT == _ON)
#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
extern void ScalerMemorySetODThreeBlockAddress(void);
#endif
#endif
