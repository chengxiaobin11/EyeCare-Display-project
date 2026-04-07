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
// ID Code      : RL6492_Series_QCInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR1)
#define GET_DDR1_MEMORY_SIZE()                 (g_stDdr1MemorySizeInfo.b2Ddr1MemorySize)
#define SET_DDR1_MEMORY_SIZE(x)                (g_stDdr1MemorySizeInfo.b2Ddr1MemorySize = (x))
#endif

//****************************************************************************
// INTERFACE STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR1)
typedef struct
{
    BYTE b2Ddr1MemorySize : 2;
} StructDdr1MemorySizeInfo;
#endif

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG == _MEMORY_DDR1)
extern StructDdr1MemorySizeInfo g_stDdr1MemorySizeInfo;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_FACTORY_RTD_QC_SUPPORT == _ON)

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
extern BYTE ScalerQCA0PortTest(void);
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
extern BYTE ScalerQCD0PortTest(void);
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
extern WORD ScalerQCD1PortTest(void);
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
extern BYTE ScalerQCD2PortTest(void);
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
extern BYTE ScalerQCD3PortTest(void);
#endif

extern void ScalerQCAllDigitalFunctionDisable(void);

#endif
