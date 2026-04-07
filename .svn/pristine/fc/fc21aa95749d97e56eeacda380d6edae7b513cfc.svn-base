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
// ID Code      : RL6463_Series_FRCInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _FRC_ACCESS_WRITE_LENGTH                        (0x40)

#if(_MEMORY_SIZE_CONFIG == _1M_16BIT_SDRAM)
#define _FRC_ACCESS_READ_LENGTH                         (0x7C)
#else
#define _FRC_ACCESS_READ_LENGTH                         (0x80)
#endif

//--------------------------------------------------
// Deinfe FRC setting path
//--------------------------------------------------
#define _FRC_CAP_MAIN_1                                 (_BIT0)
#define _FRC_DISP_MAIN_1                                (_BIT4)

#define _FRC_CAP_DISP_ALL                               (_FRC_CAP_MAIN_1 | _FRC_DISP_MAIN_1)

//--------------------------------------------------
// Deinfe for FRC auto 3 block toggle
//--------------------------------------------------
#define _FRC_R_1ST_BLOCK_STA_ADDR_H                     (0x00) // 0 row
#define _FRC_R_1ST_BLOCK_STA_ADDR_M                     (0x00)

//--------------------------------------------------
// Deinfe for one-frame FRC
//--------------------------------------------------
#define _LINE_MARGIN                                    (5)

#define _FRC_START_ADDRESS_M1                           (_FRC_R_1ST_BLOCK_STA_ADDR_H)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_HW_FRC_TYPE != _FRC_GEN_NONE)
extern void ScalerFRCInitial(void);
extern void ScalerFRCEn(BYTE ucSettingPath, bit bEn);
#endif

#if(_FRC_SUPPORT == _ON)
extern WORD ScalerFRCSetOneFrameDVTotal(void);
extern void ScalerFRCControl(const StructSDRAMDataInfo *pstFIFOSize);
#endif

extern void ScalerFRCSetDDomainSourceSelect(EnumDDomainSourceSelect enumSourceSelect);

