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
// ID Code      : Scaler_Test_Function.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//////////
// DDR3 //
//////////

//--------------------------------------------------
// DDR3 Phase Calibration or Phase Check (_ON : For All DDR3 Project)
//--------------------------------------------------
#define _DDR3_PHASE_CALIBRATION                                 _OFF
#define _DDR3_PHASE_CHECK                                       _OFF
#define _DDR_BURN_IN_TEST                                       _OFF

#if((_MEMORY_TYPE_CONFIG == _MEMORY_DDR3) && ((_DDR3_PHASE_CALIBRATION == _ON) || (_DDR3_PHASE_CHECK == _ON)))
#undef _MEMORY_PHASE_CALIBRATION_MODE
#define _MEMORY_PHASE_CALIBRATION_MODE                          _MEMORY_PHASE_CALIBRATION_FRC_MODE
#endif

#define _DDR3_PHASE_CAL_FRC_MODE_INTERNAL_PG                    _OFF

//*******************************************************//
//******DQS01_CLK3, PADCLK_CLK2, DQ01_CLK1, REFCMD_CLK0**//
//******OESync, Fix00, DQ23_CLK5, DQS23_CLK4*************//
//******RXDelay Tap**************************************//
//*******************************************************//
#define _DDR3_PHASE_CAL_INIT_PHASE_CLK0                         0x00
#define _DDR3_PHASE_CAL_INIT_PHASE_CLK1                         0x2A
#define _DDR3_PHASE_CAL_INIT_PHASE_CLK2                         0x06
#define _DDR3_PHASE_CAL_INIT_PHASE_CLK3                         0x1C
#define _DDR3_PHASE_CAL_INIT_PHASE_CLK4                         0x1C
#define _DDR3_PHASE_CAL_INIT_PHASE_CLK5                         0x2A
#define _DDR3_PHASE_CAL_INIT_RDQ_DELAY_TAP                      0x20

#if(((_DDR3_PHASE_CALIBRATION == _ON) || (_DDR3_PHASE_CHECK == _ON)) &&\
    (_MEMORY_PHASE_CALIBRATION_MODE == _MEMORY_PHASE_CALIBRATION_FRC_MODE))

#if(_FORMAT_CONVERSION_FORCE_EO_MODE == _OFF)
#undef _FORMAT_CONVERSION_FORCE_EO_MODE
#define _FORMAT_CONVERSION_FORCE_EO_MODE                        _ON
#endif

#if(_FRAME_SYNC_LINE_BUFFER_SUPPORT == _ON)
#warning "_FRAME_SYNC_LINE_BUFFER_SUPPORT Should Be _OFF!!!"
#endif

#endif

#if(_DDR3_PHASE_CALIBRATION == _ON)
#warning "_DDR3_PHASE_CALIBRATION is _ON!!!"
#endif

#if(_DDR3_PHASE_CHECK == _ON)
#warning "_DDR3_PHASE_CHECK is _ON!!!"
#endif

#if(_DDR_BURN_IN_TEST == _ON)
#if(_FRAME_SYNC_LINE_BUFFER_SUPPORT == _ON)
#warning "_FRAME_SYNC_LINE_BUFFER_SUPPORT Should Be _OFF!!!"
#endif
#warning "_DDR_BURN_IN_TEST is _ON!!!"
#endif

//--------------------------------------------------
// SDRAM DPIDLL Calibration (_ON : Only For RL6851 Project)
//--------------------------------------------------
#define _SDRAM_DPI_CRT_DLL_CAL                                  _OFF

#if((_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM) && (_SDRAM_DPI_CRT_DLL_CAL == _ON))
#undef _MEMORY_PHASE_CALIBRATION_MODE
#define _MEMORY_PHASE_CALIBRATION_MODE                          _MEMORY_PHASE_CALIBRATION_MCU_MODE
#endif

#if(_MEMORY_TYPE_CONFIG == _NO_MEMORY)
#if(_SDRAM_PHASE_CALIBRATION == _ON)
#warning "_SDRAM_PHASE_CALIBRATION Can Not Be Supported With No Memory!!!"
#endif

#if(_DDR1_PHASE_CALIBRATION == _ON)
#warning "_DDR1_PHASE_CALIBRATION Can Not Be Supported With No Memory!!!"
#endif

#if(_DDR3_PHASE_CALIBRATION == _ON)
#warning "_DDR3_PHASE_CALIBRATION Can Not Be Supported With No Memory!!!"
#endif

#if(_DDR3_PHASE_CHECK == _ON)
#warning "_DDR3_PHASE_CHECK Can Not Be Supported With No Memory!!!"
#endif

#if(_SDRAM_DPI_CRT_DLL_CAL == _ON)
#warning "_SDRAM_DPI_CRT_DLL_CAL Can Not Be Supported With No Memory!!!"
#endif
#endif // End of #if(_MEMORY_TYPE_CONFIG == _NO_MEMORY)


/////////////////
// FreeSync OD //
/////////////////

//--------------------------------------------------
// FreeSync Mode Measure OD Table (_ON : For FreeSync OD Measure)
//--------------------------------------------------
#define _FREESYNC_OD_MEASURE                                    _OFF

#if(_FREESYNC_OD_MEASURE == _ON)
#warning "_FREESYNC_OD_MEASURE is _ON!!!"

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
#warning "_DEBUG_MESSAGE_SUPPORT should be _ON!!!"
#endif
#endif


///////////////
// TMDS Test //
///////////////

//--------------------------------------------------
// Debug Option For TMDS Low Speed Port (_ON : 340MHz ; _OFF : 600MHz)
//--------------------------------------------------
#define _TMDS_LOW_SPEED_PORT_SPEED_LIMIT                        _ON


///////////////////
// HDMI VRR Test //
///////////////////

//--------------------------------------------------
// HDMI Force VRR Support
//--------------------------------------------------
#define _HDMI_FORCE_VRR_SUPPORT                                 _OFF


#if(_HDMI_FORCE_VRR_SUPPORT == _ON)
#if(_HDMI21_VRR_SUPPORT == _OFF)
#warning "_HDMI21_VRR_SUPPORT Should Be _ON When _HDMI_FORCE_VRR_SUPPORT _ON"
#endif
#endif


//////////////
// MHL Test //
//////////////

//--------------------------------------------------
// Debug Option For MHL (_ON : No CBUS Handshake ; _OFF : Need CBUS Handshake)
//--------------------------------------------------
#define _MHL_DEBUG_WITHOUT_CBUS_MODE                            _OFF

///////////////
// MCRC Test //
///////////////

//--------------------------------------------------
// Verify Option For MCRC (_ON : FOR CRC check; _OFF : NO CRC check)
//--------------------------------------------------
#define _MCRC_STABILITY_CHECK_SUPPORT                           _OFF

//////////////////////
// DP Freesync Test //
//////////////////////

//--------------------------------------------------
// DP Force Freesync Support
//--------------------------------------------------
#define _DP_FORCE_FREESYNC_SUPPORT                              _OFF


#if(_DP_FORCE_FREESYNC_SUPPORT == _ON)
#if(_DP_FREESYNC_SUPPORT == _OFF)
#warning "_DP_FREESYNC_SUPPORT Should Be _ON When _DP_FORCE_FREESYNC_SUPPORT _ON"
#endif
#endif


//////////////////////
// Dt Range Test    //
//////////////////////

//--------------------------------------------------
// Dt Range Test
//--------------------------------------------------
#ifndef _DT_RANGE_TEST_SUPPORT
#define _DT_RANGE_TEST_SUPPORT                                  _OFF
#endif

#if(_DT_RANGE_TEST_SUPPORT == _ON)
#if(_DEBUG_MESSAGE_AUTOTEST == _OFF)
#warning "_DEBUG_MESSAGE_AUTOTEST should be _ON!!!"
#endif
#endif
