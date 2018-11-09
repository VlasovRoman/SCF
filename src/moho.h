#include "defs.h"
#include "temp_data.h"
#include <cstdio>
#include <windows.h>
#include <iostream>

_BYTE* sub_1048D030(_BYTE *a1, _BYTE *a2, int a3, _BYTE *a4, int a5, _BYTE *a6);

class Moho
{
	public:
	
	Moho(){};
	
	__attribute__((cdecl)) CHAR* Moho::USER_GetAppCacheDir(CHAR *a1);
	void Moho::USER_PurgeAppCacheDir();
	__attribute__((cdecl)) void* Moho::USER_GetAppDataDir(void *a1);
	
	
	
	
	private:
}