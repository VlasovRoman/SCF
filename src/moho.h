#pragma once
#include "startup.h"
#include "gpg.h"

using namespace std;

class Moho
{
public:

	Moho() {};

	__attribute__((cdecl)) string USER_GetAppCacheDir();
	void USER_PurgeAppCacheDir();
	__attribute__((cdecl)) string USER_GetAppDataDir();
	string replaceAll( const string& s, const string& f, const string& r );

private:
	string game_name = "Supreme Commander Forged Alliance";
	string dev_company = "Gas Powered Games";
	string leftslash = "\\";
	string rightslash = "/";
	string double_left_slash = "\\";
};