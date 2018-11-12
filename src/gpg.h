#pragma once
#include "defs.h"
#include "temp_data.h"
#include "moho.h"
#include <cstdio>
#include <windows.h>
#include <iostream>

using namespace std;

namespace gpg
{
	string STR_WideToUtf8(LPSTR a2);
	
	string STR_WideToUtf8(LPSTR str)
	{
		return string(str);
	}
	

};