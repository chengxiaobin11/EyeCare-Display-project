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
// ID Code      : RL6851_Series_ScalerGlobalInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of System Clock Frequency
//--------------------------------------------------
#define _GDI_CLK_DIV                                (ScalerGetBit(P80_06_GDI_CLK_DIVIDER, (_BIT3 | _BIT2 | _BIT1 | _BIT0))) // GDI Clock Divider
//#define _SYS_CLK_DIV                                (ScalerGetBit(P40_06_SYNCPROC_CLK_DIVIDER, (_BIT3 | _BIT2 | _BIT1 | _BIT0))) // System Clock Divider
//#define _SYS_CLK_KHZ                                (DWORD)((bit)ScalerGetBit(P40_06_SYNCPROC_CLK_DIVIDER, _BIT4) ? ((DWORD)_M2PLL_CLK_KHZ / _SYS_CLK_DIV) : (_SYS_USE_ISO_CLK ? _INTERNAL_OSC_XTAL : _EXT_XTAL))

#if(_WD_TIMER_INT_SUPPORT == _ON)
//--------------------------------------------------
// Definition of Global Xtal Clk Switch
//--------------------------------------------------
#define SET_GLOBAL_XTAL_CLK_SWITCH(x)               (g_enumGlobalXtalClkSelect = (x))
#define GET_GLOBAL_XTAL_CLK_SWITCH()                (g_enumGlobalXtalClkSelect)
#endif

#if(_FORCE_D_DOMAIN_DB_APPLY == _ON)
#if((_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_II) || (_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_III))
#define GET_FORCE_D_DOMAIN_DB()                     (g_stGlobalForceDDomainDB.b1ForceDDomainDB)
#define SET_FORCE_D_DOMAIN_DB(x)                    (g_stGlobalForceDDomainDB.b1ForceDDomainDB = (x))

#if(_LOCAL_DIMMING_SUPPORT == _ON)
#define GET_D_DOMAIN_DB_STATUS()                    (g_stGlobalForceDDomainDB.b1DDomainDBStatus)
#define SET_D_DOMAIN_DB_STATUS(x)                   (g_stGlobalForceDDomainDB.b1DDomainDBStatus = (x))
#endif
#endif
#endif


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if(_WD_TIMER_INT_SUPPORT == _ON)
//--------------------------------------------------
// Enumerations of Global Xtal Clk Switch
//--------------------------------------------------
typedef enum
{
    _GLOBAL_XTAL_CLK_SEL_UNCHANGE = 0x00,
    _GLOBAL_XTAL_CLK_SEL_TO_EXTERNAL,
    _GLOBAL_XTAL_CLK_SEL_TO_INTERNAL,
} EnumGlobalXtalClkSelect;
#endif

#if(_FORCE_D_DOMAIN_DB_APPLY == _ON)
#if((_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_II) || (_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_III))
typedef struct
{
    BYTE b1ForceDDomainDB : 1;
    BYTE b1IMDDBStatus : 1;
#if(_LOCAL_DIMMING_SUPPORT == _ON)
    BYTE b1DDomainDBStatus : 1;
#endif
} StructGlobalForceDDomainDB;
#endif
#endif

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_WD_TIMER_INT_SUPPORT == _ON)
extern EnumGlobalXtalClkSelect g_enumGlobalXtalClkSelect;
#endif

#if(_FORCE_D_DOMAIN_DB_APPLY == _ON)
#if((_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_II) || (_HW_GLOBAL_DB_TYPE == _GLOBAL_DB_GEN_III))
extern StructGlobalForceDDomainDB g_stGlobalForceDDomainDB;
#endif
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerGlobalIRQControl(bit bEn);
extern void ScalerGlobalOsdInitial(void);

#if(((_OD_SUPPORT == _ON) && (_FRC_SUPPORT == _ON)) || (_XTALESS_SUPPORT == _ON))
extern void ScalerGlobalSetInterrupt(EnumIRQ enumIRQType, BYTE ucEn);
#endif

