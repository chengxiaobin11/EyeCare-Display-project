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
// ID Code      : SysAutotest.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_AUTOTEST__

#include "SysInclude.h"

#if(_AUTO_TEST_SUPPORT == _ON)
#include "ATSysInclude.h"

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
void SysAutotestHandler(void);
void SysAutotestOSDSwitchCtrl(void);
void SysAutotestIntProc_EXINT1(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Auto Test Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAutotestHandler(void)
{
    ATUserCommonDdcciHandler();

    ATOSDKeyMessageScan();
}

//--------------------------------------------------
// Description  : Auto Test OSD Switch Control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAutotestOSDSwitchCtrl(void)
{
    ATOSDMenuKeyMessageClrFlg();
}

//--------------------------------------------------
// Description  : Auto Test Int Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysAutotestIntProc_EXINT1(void) using 2
{
    ATUserCommonInterfaceDdcciGetData_EXINT1();
}
#endif
