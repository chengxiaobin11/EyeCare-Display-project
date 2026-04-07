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
// ID Code      : SysTMDS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_TMDS__

#include "SysInclude.h"

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

#if(_INPUTCLOCK_RANG_HDMI <= 3400)
#if(_INPUTCLOCK_RANG_DVI != _INPUTCLOCK_RANG_HDMI)
#warning "NOTE: _INPUTCLOCK_RANG_DVI should be same as _INPUTCLOCK_RANG_HDMI!!!"
#endif
#else
#if(_INPUTCLOCK_RANG_DVI != 3400)
#warning "NOTE: _INPUTCLOCK_RANG_DVI should be set 3400!!!"
#endif

#if(_HDMI_2_0_SUPPORT == _ON)
#if((_HDMI_SINK_RTK_ID_STRING_H == 0x00) && (_HDMI_SINK_RTK_ID_STRING_L == 0x00))
#warning "NOTE: _HDMI_SINK_RTK_ID_STRING_H/_HDMI_SINK_RTK_ID_STRING_H Should Be Defined as RTD Number When VID = Realtek"
#endif
#endif
#endif

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
void SysTMDSRxHandler(void);
#if(_HDMI_SUPPORT == _ON)
void SysTMDSRxSetPsWakeupHpdToggle(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : TMDS Handler Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysTMDSRxHandler(void)
{
    ScalerSyncTMDSHPDToggleProc();
}

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Scan & Set the relatived PS Wakeup HPD Toggle flag
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysTMDSRxSetPsWakeupHpdToggle(void)
{
    if((GET_SOURCE_TYPE(g_ucSearchIndex) == _SOURCE_HDMI) || (GET_SOURCE_TYPE(g_ucSearchIndex) == _SOURCE_DVI) || (GET_SOURCE_TYPE(g_ucSearchIndex) == _SOURCE_NONE))
    {
        ScalerTMDSSetPsWakeupHpdToggle(SysSourceGetInputPort());
    }
}
#endif


#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
