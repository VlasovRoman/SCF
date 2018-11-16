#pragma once
#include "startup.h"
#include "gpg.h"

using namespace std;

//@@virtual table from constructor
struct CScApp__vftable
{
	int unk1;// (a2 + 68)
	int unk2;//(a2 + 72)
	bool unk3;//(a2 + 73)
	int unk4;//(a2 + 76)
	int unk5;//
	int unk6;//
	int unk7;//
	int unk8;//(a2 + 136)
	int unk9;//(a2 + 140)

	_DWORD unk_perf_counter;

	int unk10;
	int unk11;
	int unk12;
	int unk13;
	int unk14;
	int unk15;
	int unk16;
	string unk_str1;
	string unk_str2;
};

class Moho
{
public:

	Moho(){};
	Moho(CScApp__vftable &vft);
	void WIN_AppExecute(CScApp__vftable *vft);
	int init_unk_sv(CScApp__vftable &vft, string s1, string s2);
	LRESULT fn(int code, WPARAM wParam, LPARAM lParam);

	__attribute__((cdecl)) string USER_GetAppCacheDir();
	void USER_PurgeAppCacheDir();
	__attribute__((cdecl)) string USER_GetAppDataDir();
	string replaceAll( const string& s, const string& f, const string& r );

private:
	LPTSTR Path;
	string game_name;
	string dev_company;
	string SCFA;
	string leftslash = "\\";
	string rightslash = "/";
	string double_left_slash = "\\\\";
	DWORD dword_10A647C;
	DWORD dword_10A6488;
	DWORD dword_10A6480;
	DWORD dword_10A6484;
	DWORD dword_10A63BC;
};