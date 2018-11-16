#include "startup.h"
#include "moho.h"

Moho::Moho(CScApp__vftable &vft)
{
	init_unk_sv(vft, "SupCom", "SupremeCommander");
	vft.unk1 = 0;
	vft.unk2 = 0;
	vft.unk3 = 0;
	vft.unk4 = 0;
	vft.unk5 = 0;
	vft.unk6 = 1;
	get_performance_count_ptr_stub(&vft.unk_perf_counter);
	vft.unk7 = 0;
	vft.unk8 = 0;

	this->game_name = "Supreme Commander Forged Alliance";
	this->dev_company = "Gas Powered Games";
	this->SCFA = "SCFA";

	dword_10A647C = dword_F8D68C;
	dword_10A6488 = dword_F8D698;
	dword_10A6480 = dword_F8D690;
	dword_10A6484 = dword_F8D694;
	/*
	  (int a2)
	  int result; // eax
	  int v3; // [esp-8h] [ebp-20h]
	  int *v4; // [esp+8h] [ebp-10h]
	  int v5; // [esp+14h] [ebp-4h]

	  v4 = &v3;
	  init_unk_sv(a2, "SupCom", "SupremeCommander");
	  v5 = 0;
	  *(_DWORD *)a2 = &CScApp::`vftable';
	  *(_DWORD *)(a2 + 68) = 0;
	  *(_BYTE *)(a2 + 72) = 0;
	  *(_BYTE *)(a2 + 73) = 0;
	  *(_DWORD *)(a2 + 76) = 0;
	  *(_DWORD *)(a2 + 80) = 0;
	  *(_BYTE *)(a2 + 84) = 1;
	  sub_9556D0((LARGE_INTEGER *)(a2 + 88));
	  *(_DWORD *)(a2 + 136) = 0;
	  *(_DWORD *)(a2 + 140) = 0;
	  LOBYTE(v5) = 1;
	  sub_4059E0((int)&unk_F5B9C0, "Gas Powered Games", strlen("Gas Powered Games"));
	  sub_4059E0((int)&unk_F5B9DC, "Supreme Commander Forged Alliance", strlen("Supreme Commander Forged Alliance"));
	  sub_4059E0((int)&unk_F5B9F8, "SCFA", strlen("SCFA"));
	  dword_10A647C = dword_F8D68C;
	  dword_10A6488 = dword_F8D698;
	  dword_10A6480 = dword_F8D690;
	  result = a2;
	  dword_10A6484 = dword_F8D694;
	  return result;	*/
}

int Moho::init_unk_sv(CScApp__vftable &vft, string s1, string s2)
{
	vft.unk10 = 15;
	vft.unk11 = 0;
	vft.unk12 = 0;
	vft.unk13 = 15;
	vft.unk14 = 0;
	vft.unk15 = 15;

	vft.unk_str1 = s1;
	vft.unk_str2 = s2;

	return 1;

	/*
	  (int a1, void *Src, void *a3)
	  int v3; // ecx
	  int v4; // ecx

	  v3 = a1 + 4;
	  *(_DWORD *)a1 = &off_E4F408;
	  *(_DWORD *)(v3 + 24) = 15;
	  *(_DWORD *)(v3 + 20) = 0;
	  *(_BYTE *)(v3 + 4) = 0;
	  sub_4059E0(a1 + 4, Src, strlen((const char *)Src));
	  v4 = a1 + 32;
	  *(_DWORD *)(v4 + 24) = 15;
	  *(_DWORD *)(v4 + 20) = 0;
	  *(_BYTE *)(v4 + 4) = 0;
	  sub_4059E0(a1 + 32, a3, strlen((const char *)a3));
	  *(_DWORD *)(a1 + 60) = 0;
	  return a1; */
}

LRESULT Moho::fn(int code, WPARAM wParam, LPARAM lParam)
{
	LRESULT result; // eax
	HHOOK hhk;
	if ( code
	        || !(*(unsigned __int8 (**)(void))(*(_DWORD *)dword_10A63BC + 24))()
	        || wParam < 0x100
	        || wParam > 0x101
	        || *(_DWORD *)lParam != 91 && *(_DWORD *)lParam != 92 )
	{
		result = CallNextHookEx(hhk, code, wParam, lParam);
	}
	else
	{
		result = 1;
	}
	return result;
}

void Moho::WIN_AppExecute(CScApp__vftable *vft)
{
	//CScApp__vftable *v1; // esi
	HMODULE v2; // eax
	int *v3; // ecx
	int *v4; // ecx
	HANDLE v5; // eax
	char v6; // bl
	int *v7; // eax
	int *v8; // eax
	double v9; // st7
	int v10; // eax
	DWORD v11; // ST08_4
	//Moho::CWaitHandleSet *v12; // eax
	char i; // bl
	int v14; // edx
	int v15; // [esp-4h] [ebp-6Ch]
	float v16; // [esp+0h] [ebp-68h]
	int v17; // [esp+4h] [ebp-64h]
	char v18; // [esp+10h] [ebp-58h]
	int *v19; // [esp+14h] [ebp-54h]
	unsigned int v20; // [esp+28h] [ebp-40h]
	char v21; // [esp+2Ch] [ebp-3Ch]
	int *v22; // [esp+30h] [ebp-38h]
	unsigned int v23; // [esp+44h] [ebp-24h]
	float v24; // [esp+50h] [ebp-18h]
	char v25; // [esp+56h] [ebp-12h]
	char v26; // [esp+57h] [ebp-11h]
	int *v27; // [esp+58h] [ebp-10h]
	int v28; // [esp+64h] [ebp-4h]
	static HHOOK hhookSysMsg; 

	v27 = &v17;
	if (vft!=nullptr)
	{
		dword_10A63BC = (int)vft;
		v2 = GetModuleHandleW(0);
		hhookSysMsg = SetWindowsHookExW(WH_KEYBOARD_LL, (HOOKPROC)&fn, v2, 0);
		wstring foo = towstring(fn);
		GetModuleHandleExW(6u, &foo[0], (HMODULE *)&vft);
		//wxEntry((HINSTANCE)this, 0, 0, 0, 0);
/* 		if ( sub_4F2000() )
		{
			v32 = 2;
			sub_4141A0(1);
			InitCommonControls();
			CoInitialize(0);
			sub_4A2150();
			sub_4A2D30();
			sub_9556F0((LARGE_INTEGER *)&unk_10A9B78);
			if ( !(*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v2 + 12))(v2) )
			{
				v6 = GetCurrentProcess();
				TerminateProcess(v6, 1u);
			}
			v7 = dword_F8F80C;
			*(_DWORD *)(dword_F8F80C + 68) = 1;
			*(_BYTE *)(v7 + 92) = 1;
			_controlfp(0x20000u, 0x30000u);
			v8 = 1;
			v30 = 1;
			v29 = 1;
			while ( 1 )
			{
				while ( 1 )
				{
					while ( 1 )
					{
						while ( v29 )
						{
							SleepEx(0, 1);
							v9 = (int *)sub_4F2480();
							sub_409AC0(v9);
							v29 = 0;
						}
						if ( !(*(unsigned __int8 (**)(void))(*(_DWORD *)dword_F8F80C + 76))() )
							break;
						(*(void (**)(void))(*(_DWORD *)dword_F8F80C + 80))();
						v8 = 1;
						v30 = 1;
					}
					if ( !v8 )
						break;
					v8 = (*(int (**)(void))(*(_DWORD *)dword_F8F80C + 88))();
					v30 = v8;
				}
				if ( !*(_BYTE *)(dword_F8F80C + 92) )
					break;
				(*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 16))(v2);
				v8 = 1;
				v30 = 1;
				v29 = 1;
				v10 = (int *)sub_4F24F0();
				sub_409AC0(v10);
				sub_4F1540();
				a2 = flt_10A9B84 - a2;
				v27 = a2;
				if ( a2 >= 0.0 )
				{
					if ( v27 <= 4294967300.0 )
					{
						v17 = a2;
						*(float *)&v11 = COERCE_FLOAT(sub_40D820(v17));
					}
					else
					{
						*(float *)&v11 = -6.8056469e38;
					}
				}
				else
				{
					*(float *)&v11 = 0.0;
				}
				LODWORD(flt_10A9B84) = dword_10A9B58;
				v17 = *(float *)&v11;
				v12 = sub_4F2420();
				sub_4145E0((int)v12, LODWORD(v17));
			}
			v32 = -1;
			(*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 20))(v2);
			sub_4F3A60();
			sub_4A2210();
			if ( dword_F8F80C )
			{
LABEL_30:
				for ( i = 1; ; i = (*(int (**)(void))(v15 + 88))() )
				{
					v14 = (*(int (**)(void))(*(_DWORD *)dword_F8F80C + 76))();
					v15 = *(_DWORD *)dword_F8F80C;
					if ( v14 )
					{
						(*(void (**)(void))(v15 + 80))();
						goto LABEL_30;
					}
					if ( !i )
						break;
				}
				(*(void (**)(void))(v15 + 56))();
				sub_992E10();
			}
			if ( hhk )
				UnhookWindowsHookEx(hhk);
			sub_4ABEB0();
			dword_10A63BC = 0;
		}
		else
		{
			sub_405550((int)&v19, "Old OS Version");
			v32 = 0;
			sub_405550(
			    (int)&v23,
			    "This application requires Windows NT, 2000, XP, or newer, to operate.\n"
			    "Windows 95, 98, and ME are not supported.");
			LOBYTE(v32) = 1;
			*(float *)&v4 = v24;
			if ( v26 < 0x10 )
				*(float *)&v4 = COERCE_FLOAT(&v24);
			v27 = COERCE_FLOAT(&v17);
			v17 = *(float *)&v4;
			v5 = (char *)LODWORD(v20);
			if ( v22 < 0x10 )
				v5 = (char *)&v20;
			v27 = COERCE_FLOAT(&v16);
			sub_4F2800(v5, (char *)LODWORD(v17));
			dword_10A63BC = 0;
			LOBYTE(v32) = 0;
			if ( v26 >= 0x10 )
			{
				v17 = v24;
				sub_957A60();
			}
			v26 = 15;
			v25 = 0;
			LOBYTE(v24) = 0;
			v32 = -1;
			if ( v22 >= 0x10 )
			{
				v17 = v20;
				sub_957A60();
			}
			v22 = 15;
			v21 = 0;
			LOBYTE(v20) = 0;
		}*/
	}	 
}

//Replace all strings of type in std::string.
//@@1 target string @@2 pattern string @@3 what to replace pattern with.
string Moho::replaceAll( const string& s, const string& f, const string& r )
{
	if ( s.empty() || f.empty() || f == r || s.find(f) == string::npos )
	{
		return s;
	}
	ostringstream build_it;
	size_t i = 0;
	for ( size_t pos; ( pos = s.find( f, i ) ) != string::npos; )
	{
		build_it.write( &s[i], pos - i );
		build_it << r;
		i = pos + f.size();
	}
	if ( i != s.size() )
	{
		build_it.write( &s[i], s.size() - i );
	}
	return build_it.str();
}

//@@ return the string path to Appdata on windows.
string Moho::USER_GetAppDataDir()
{
	string v1; // eax
	if (SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, NULL, Path) >=0)
	{
		v1 = string(Path);
		v1+="\\";
		v1+=dev_company;
		v1+="\\";
		v1+=game_name;
	}
	return v1;
}

//@@ return the string path to cache folder.
string Moho::USER_GetAppCacheDir()
{
	string AppDataDir;

	AppDataDir = USER_GetAppDataDir();
	AppDataDir = replaceAll( AppDataDir, &leftslash[0],rightslash);
	AppDataDir+="/cache";

	bool isDirCreated = CreateDirectoryA(&AppDataDir[0], nullptr);
	DWORD dw = ::GetLastError();
	if (!isDirCreated)
	{
		printf("CreateDirectory() %s Failed with (%d)", AppDataDir.c_str(), dw);
		//debug_pause();
	}

#ifdef DEBUG
	cout<<__func__<<" Cache dir is : \n";
	cout<<AppDataDir<<endl;
#endif
	return AppDataDir;
}

void Moho::USER_PurgeAppCacheDir()
{
	string path;
	int err;

	path = USER_GetAppCacheDir();
	path+="/*";
	path = replaceAll( path, rightslash, leftslash);
	path+="\\0";

	SHFILEOPSTRUCT FileOp;
	FileOp.hwnd = NULL;
	FileOp.wFunc=FO_DELETE;
	FileOp.pFrom= path.c_str();
	FileOp.pTo = NULL;
	FileOp.fFlags=FOF_ALLOWUNDO|FOF_NOCONFIRMATION;
	FileOp.hNameMappings=NULL;

	if ( err = SHFileOperationA(&FileOp) )
	{
		cout<<"Unable to purge cache directory "<<err<<endl;
	}
}