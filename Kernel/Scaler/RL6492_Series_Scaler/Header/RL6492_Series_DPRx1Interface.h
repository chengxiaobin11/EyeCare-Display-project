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
// ID Code      : RL6492_Series_DPRx1Interface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D1_DP_EXIST == _ON)
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_DP_RX_MI_DONGLE_SUPPORT == _ON)
extern BYTE g_ucDpRx0FakeLTLaneCount;
extern BYTE g_ucDpRx0FakeLTLaneCountBackUp;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerDpRx1HDCPBlockReset(void);
extern void ScalerDpRx1AuxSet(void);
extern void ScalerDpRx1SetDpLaneMapping(EnumTypeCPinCfgType enumPinAssignment, EnumTypeCOrientation enumOrientation);
extern void ScalerDpRx1HpdIrqAssert(void);

#endif // End of #if(_D1_DP_EXIST == _ON)
