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
// ID Code      : RL6369_Series_QCInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


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
extern BYTE ScalerQCD1PortTest(void);
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
extern BYTE ScalerQCD2PortTest(void);
#endif

extern void ScalerQCAllDigitalFunctionDisable(void);

#endif
