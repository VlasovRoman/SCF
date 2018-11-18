#pragma once
#include "startup.h"
#include "gpg.h"

class CScApp;

class Moho
{
public:

	Moho() {};
	Moho(CScApp &vft);
	void WIN_AppExecute(CScApp *vft);
	int init_unk_sv(CScApp &vft, std::string s1, std::string s2);
	LRESULT fn(int code, WPARAM wParam, LPARAM lParam);
	void THREAD_SetAffinity(int a1);
	void PLAT_Init();

	__attribute__((cdecl)) std::string USER_GetAppCacheDir();
	void USER_PurgeAppCacheDir();
	__attribute__((cdecl)) std::string USER_GetAppDataDir();
	std::string replaceAll( const std::string& s, const std::string& f, const std::string& r );

private:
	LPTSTR Path;
	std::string game_name;
	std::string dev_company;
	std::string SCFA;
	std::string leftslash = "\\";
	std::string rightslash = "/";
	std::string double_left_slash = "\\\\";
	DWORD dword_10A647C;
	DWORD dword_10A6488;
	DWORD dword_10A6480;
	DWORD dword_10A6484;
	DWORD dword_10A63BC;
	int PLAT_control_var = 0;
	unsigned long dword_109BA774;
	char byte_109BA76A;
	char byte_109BA76B;
};