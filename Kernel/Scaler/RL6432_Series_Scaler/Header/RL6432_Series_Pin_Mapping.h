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
// ID Code      : RL6432_Series_Pin_Mapping.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifdef _76PIN_PIN_16
#include "RL6432_Series_Pin76_Mapping.h"
#endif

#ifdef _156PIN_PIN_121

#include "RL6432_Series_Pin156MST_Mapping.h"

#else

#ifdef _156PIN_PIN_82
#include "RL6432_Series_Pin156_Mapping.h"
#endif

#endif

