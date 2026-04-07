
#include "UserCommonInclude.h"

//****************************************************************************
// CODE TABLES
//****************************************************************************

//--------------------------------------------------
// Font Body Table
//--------------------------------------------------
#include "./TextTableBody/Rtd2014OsdTextTableBody_0.h"//europe
/*
#if(_DEF_TCHINESE_TEXT)
#include "./TextTableBody/Rtd2014OsdTextTableBody_ChineseT.h"
#endif
#if(_DEF_SCHINESE_TEXT)
#include "./TextTableBody/Rtd2014OsdTextTableBody_ChineseS.h"
#endif
#if(_DEF_JAPANESE_TEXT)
#include "./TextTableBody/Rtd2014OsdTextTableBody_Japanese.h"
#endif
#if(_DEF_KOREAN_TEXT)
#include "./TextTableBody/Rtd2014OsdTextTableBody_Korean.h"
#endif
#if(_DEF_Vietnam_TEXT)
#include "./TextTableBody/Rtd2014OsdTextTableBody_Vietnam.h"
#endif
*/

#include "./TextTableBody/Rtd2014OsdTextTableBody_FontTableDefine.h"

extern BYTE OsdPutStringPropFontTable(BYTE ucLanguage, WORD ucFontPoint);


