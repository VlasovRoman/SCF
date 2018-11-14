#pragma once
#include "startup.h"
#include <windows.h>

static __int64 qword_F8ED68; // weak
static int dword_FB7D64; // weak
static int dword_FB7D68; // weak
static struct _RTL_CRITICAL_SECTION CriticalSection; // idb
static FILE *File;
static int (_cdecl *dword_F8F330)(_DWORD, _DWORD, _DWORD); // weak
static int dword_F8D68C = 4198675514; // weak
static int dword_F8D690 = 1332748053; // weak
static int dword_F8D694 = 2084474800; // weak
static int dword_F8D698 = 1757174530; // weak

static STICKYKEYS stickyKeys;
static TOGGLEKEYS toggleKeys;
static FILTERKEYS filterKeys;
