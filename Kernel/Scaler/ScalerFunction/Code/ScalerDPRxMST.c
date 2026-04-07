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
// ID Code      : ScalerDPRxMST.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_DPRXMST__

#include "ScalerFunctionInclude.h"

#if((_DP_SUPPORT == _ON) && (_DP_MST_SUPPORT == _ON))

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_DP_TX_SUPPORT == _ON)
bit ScalerDpRxMstToSstTxMeasureTimingChange(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : On-line check for DPTX SST D0
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerDpRxMstToSstTxMeasureTimingChange(void)
{
    bit bTimingChangeStatus = _FALSE;
    StructMeasureSyncData stMeasureSyncHV;
    memset(&stMeasureSyncHV, 0, sizeof(StructMeasureSyncData));

    // Measure timeout or overflow
    if(ScalerGetBit(P16_43_DPTX_MEAS_ERROR_FLG0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) != 0x00)
    {
        return _TRUE;
    }

    // Pop up if on-line measure complete
    if(ScalerDpTxMeasureGetMeasureResult(&stMeasureSyncHV) == _FALSE)
    {
        return _TRUE;
    }

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_DP_MST_FREESYNC_ENABLED() == _TRUE)
    {
        // Check on-line measure result
        bTimingChangeStatus = ((stMeasureSyncHV.b1HSP != g_stDPTxInputTimingInfo.b1HSP) ||
                               (stMeasureSyncHV.b1VSP != g_stDPTxInputTimingInfo.b1VSP) ||
                               (abs(stMeasureSyncHV.usVHeight - g_stDPTxInputTimingInfo.usVHeight) > 2) ||
                               (abs(stMeasureSyncHV.usHWidth - g_stDPTxInputTimingInfo.usHWidth) > 2));
    }
    else
#endif
    {
        // Check on-line measure result
        bTimingChangeStatus = ((stMeasureSyncHV.b1HSP != g_stDPTxInputTimingInfo.b1HSP) ||
                               (stMeasureSyncHV.b1VSP != g_stDPTxInputTimingInfo.b1VSP) ||
                               (abs(stMeasureSyncHV.usVSPeriod - g_stDPTxInputTimingInfo.usVTotal) > 2) ||
                               (abs(stMeasureSyncHV.usHTotal - g_stDPTxInputTimingInfo.usHTotal) > 2) ||
                               (abs(stMeasureSyncHV.usVHeight - g_stDPTxInputTimingInfo.usVHeight) > 2) ||
                               (abs(stMeasureSyncHV.usHWidth - g_stDPTxInputTimingInfo.usHWidth) > 2));
    }

    return bTimingChangeStatus;
}
#endif

#endif // End of #if((_DP_SUPPORT == _ON) && (_DP_MST_SUPPORT == _ON))

