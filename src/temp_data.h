#pragma once
#include "startup.h"
#include <windows.h>

static __int64 qword_F8ED68; // weak
static int dword_FB7D64; // weak
static int dword_FB7D68; // weak
static struct _RTL_CRITICAL_SECTION CriticalSection; // idb
static FILE *File;
static int (_cdecl *dword_F8F330)(_DWORD, _DWORD, _DWORD); // weak

static STICKYKEYS stickyKeys;
static TOGGLEKEYS toggleKeys;
static FILTERKEYS filterKeys;
