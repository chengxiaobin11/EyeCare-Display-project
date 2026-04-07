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
// ID Code      : ScalerCommonFunctionInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_SCALER_TYPE == _RL6410_SERIES)
#include "RL6410_Series_Common_FunctionInterface.h"
#elif(_SCALER_TYPE == _RL6432_SERIES)
#include "RL6432_Series_Common_FunctionInterface.h"
#elif(_SCALER_TYPE == _RL6449_SERIES)
#include "RL6449_Series_Common_FunctionInterface.h"
#elif(_SCALER_TYPE == _RL6492_SERIES)
#include "RL6492_Series_Common_FunctionInterface.h"
#endif

#include "ScalerCommonRegInterface.h"
#include "ScalerCommonDebugInterface.h"
#include "ScalerCommonPowerInterface.h"
#include "ScalerCommonIOSCInterface.h"
#include "ScalerCommonMcuInterface.h"
#include "ScalerCommonTimerFunctionInterface.h"
#include "ScalerCommonSyncInterface.h"
#include "ScalerCommonMeasureInterface.h"
#include "ScalerCommonPLLInterface.h"
#include "ScalerCommonColorInterface.h"
#include "ScalerCommonFunctionLibInterface.h"
#include "ScalerCommonDPRx0Interface.h"
#include "ScalerCommonDPRx1Interface.h"
#include "ScalerCommonDPRxMSTInterface.h"
#include "ScalerCommonDPTxInterface.h"
#include "ScalerCommonDPTxMSTInterface.h"
#include "ScalerCommonDPTxAuxInterface.h"
#include "ScalerCommonNVRamInterface.h"
#include "ScalerCommonHDCP2Interface.h"
#include "ScalerCommonTMDSInterface.h"
#include "ScalerCommonDPRx0HDCP2Interface.h"
#include "ScalerCommonDPRx1HDCP2Interface.h"
#include "ScalerCommonDPTxHDCP2Interface.h"
#include "ScalerCommonFreeSyncInterface.h"
#include "ScalerCommonDpAdaptiveSyncInterface.h"
#include "ScalerCommonFwInfoInterface.h"
#include "ScalerCommonFwCheckInterface.h"
#include "ScalerCommonFwUpdateInterface.h"
#include "ScalerCommonFwUpdateBackgroundInterface.h"
#include "ScalerCommonFwUpdateForegroundInterface.h"

