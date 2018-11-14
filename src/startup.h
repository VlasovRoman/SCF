#include "defs.h"
#include "temp_data.h"
#include "moho.h"
#include <shlobj.h>
#include <cstdio>
#include <windows.h>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
#include <tchar.h>
#include <string>
#include <Shlobj.h>

using namespace std;

//#define DEBUG

//--------------------------------

__attribute__((thiscall)) _DWORD* get_performance_count_ptr_stub(_DWORD *_this);
LARGE_INTEGER get_performance_count_ptr();
__attribute__((cdecl)) int sub_957EF0(int a1);
__attribute__((cdecl)) void sub_8D1E50(char a1, char a2, char a3);
void close_criticalSection_file(void);
FILE set_PerformanceFrequency(const char *a1);
void debug_pause();
//__attribute__((cdecl)) char sub_41B560(char *a1, int a2, char *Str2);

