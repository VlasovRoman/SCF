#include "defs.h"
#include "temp_data.h"
#include "moho.h"
#include "supportCode.h"
#include "checkSystemInfo.h"
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
#include <dbghelp.h>

// WXWINDGETS-------
#include <wx/app.h>
#include <wx/wxprec.h>
#include "CScApp.h"


//------------------

using namespace std;

//#define DEBUG

//--------------------------------

/* Common forgedalliance.exe symbols and addresses:

sub_4059E0 = std::basic_string<>() ctor
sub_405130 = std::exception () ctor
sub_938F10 = exception
sub_9556D0 = get_performance_count_ptr_stub()



*/
//--------------------------------

__attribute__((thiscall)) _DWORD* get_performance_count_ptr_stub(_DWORD *_this);
LARGE_INTEGER get_performance_count_ptr();
__attribute__((cdecl)) int sub_957EF0(int a1);
__attribute__((cdecl)) void sub_8D1E50(char a1, char a2, char a3);
void close_criticalSection_file(void);
FILE set_PerformanceFrequency(const char *a1);
void debug_pause();
void wait_thread_object(int _this);
void wait_thread_object_destruc(int _this);
unsigned long swap_thread_objs(int a1, unsigned long *Destination);
//__attribute__((cdecl)) char sub_41B560(char *a1, int a2, char *Str2);

