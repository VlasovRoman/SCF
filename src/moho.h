#pragma once
#include "defs.h"
#include "temp_data.h"
#include "gpg.h"
#include <shlobj.h>
#include <cstdio>
#include <windows.h>
#include <iostream>

using namespace std;

int* sub_1048D030(int *a1, int *a2, int a3, int *a4, int a5, int *a6);

class Moho
{
	public:
	
	Moho(){};
	
	__attribute__((cdecl)) string USER_GetAppCacheDir(string a1);
	void USER_PurgeAppCacheDir();
	__attribute__((cdecl)) string USER_GetAppDataDir(string a1);
	
	private:
	string game_name = "Supreme Commander Forged Alliance";
	string dev_company = "Gas Powered Games";
};