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

//----------------------------------------------------------------------------------------
// Extern functions from FactoryFunction.c
//----------------------------------------------------------------------------------------
#ifndef __FACTORY_FUNCTION__

#if(_FACTORY_RTD_QC_SUPPORT == _ON)
extern void NoneFactoryQCFlow(BYTE ucInputPort);
extern bit NoneFactoryQCNextPort(BYTE ucInputPort);
#endif

#endif



