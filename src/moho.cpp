#include "startup.h"
#include "moho.h"

Moho::Moho(CScApp &vft)
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
}

int Moho::init_unk_sv(CScApp &vft, std::string s1, std::string s2)
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

void Moho::WIN_AppExecute(CScApp *vft)
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
		//CScApp* pApp = new CScApp();
		wxApp::SetInstance(vft);
		wxEntry((HINSTANCE)vft, 0, 0, 0);
		if (check_OS_compability())
		{
			v28 = 2;
			THREAD_SetAffinity(1);
			InitCommonControls();
			CoInitialize(0);
			PLAT_Init();
			//Moho::PLAT_CatchStructuredExceptions();
			/* 			gpg::time::Timer::Reset((gpg::time::Timer *)&unk_109BE230);
						if ( !(*(unsigned __int8 (__thiscall **)(Moho *))(*(_DWORD *)v1 + 12))(v1) )
						{
							v5 = GetCurrentProcess();
							TerminateProcess(v5, 1u);
						}
						*((_DWORD *)wxTheApp + 17) = 1;
						*((_BYTE *)wxTheApp + 92) = 1;
						controlfp(0x20000u, 0x30000u);
						v6 = 1;
						v26 = 1;
						v25 = 1;
						while ( 1 )
						{
							while ( 1 )
							{
								while ( 1 )
								{
									while ( v25 )
									{
										SleepEx(0, 1);
										v7 = (int *)Moho::WIN_GetBeforeEventsStage();
										sub_10009390(v7);
										v25 = 0;
									}
									if ( !(*(unsigned __int8 (**)(void))(*(_DWORD *)wxTheApp + 76))() )
										break;
									(*(void (**)(void))(*(_DWORD *)wxTheApp + 80))();
									v6 = 1;
									v26 = 1;
								}
								if ( !v6 )
									break;
								v6 = (*(int (**)(void))(*(_DWORD *)wxTheApp + 88))();
								v26 = v6;
							}
							if ( !*((_BYTE *)wxTheApp + 92) )
								break;
							(*(void (__thiscall **)(Moho *))(*(_DWORD *)v1 + 16))(v1);
							v6 = 1;
							v26 = 1;
							v25 = 1;
							v8 = (int *)Moho::WIN_GetBeforeWaitStage();
							sub_10009390(v8);
							v9 = flt_109BE23C - gpg::time::Timer::ElapsedMillisecondsAndReset((gpg::time::Timer *)&unk_109BE230);
							v24 = v9;
							if ( v9 >= 0.0 )
							{
								if ( v24 <= 4294967300.0 )
								{
									v16 = v9;
									v10 = sub_1000BC10(v16);
								}
								else
								{
									v10 = -1;
								}
							}
							else
							{
								v10 = 0;
							}
							LODWORD(flt_109BE23C) = dword_109BE210;
							v11 = v10;
							v12 = Moho::WIN_GetWaitHandleSet();
							Moho::CWaitHandleSet::MsgWaitEx(v12, v11, 0x4FFu, 6u);
						}
						v28 = -1;
						(*(void (__thiscall **)(Moho *))(*(_DWORD *)v1 + 20))(v1);
						Moho::WINX_Exit();
						Moho::PLAT_Exit();
						if ( wxTheApp )
						{
			LABEL_26:
							for ( i = 1; ; i = (*(int (**)(void))(v14 + 88))() )
							{
								if ( (*(unsigned __int8 (**)(void))(*(_DWORD *)wxTheApp + 76))() )
								{
									(*(void (**)(void))(*(_DWORD *)wxTheApp + 80))();
									goto LABEL_26;
								}
								v14 = *(_DWORD *)wxTheApp;
								if ( !i )
									break;
							}
							(*(void (**)(void))(v14 + 56))();
							wxApp::CleanUp();
						}
						if ( hhk )
							UnhookWindowsHookEx(hhk);
						Moho::RES_Exit();
						dword_109BA7A4 = 0;
					}
					else
					{
						std::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string<char,std::char_traits<char>,std::allocator<char>>(
						            &v18,
						            "Old OS Version");
						v28 = 0;
						std::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string<char,std::char_traits<char>,std::allocator<char>>(
						            &v21,
						            "This application requires Windows NT, 2000, XP, or newer, to operate.\n"
						            "Windows 95, 98, and ME are not supported.");
						LOBYTE(v28) = 1;
						v3 = v22;
						if ( v23 < 0x10 )
							v3 = (int *)&v22;
						v24 = COERCE_FLOAT(&v16);
						v16 = *(float *)&v3;
						v4 = v19;
						if ( v20 < 0x10 )
							v4 = (int *)&v19;
						v24 = COERCE_FLOAT(&v15);
						Moho::WIN_OkBox((int)v4, SLODWORD(v16));
						dword_109BA7A4 = 0;
						LOBYTE(v28) = 0;
						std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v21);
						v28 = -1;
						std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v18); */
		}
	}
}

int sub_1009A910()
{
	int result; // eax

	result = 1;
	//if ( !(dword_109DCC04 & 1) )
	//{
	//	dword_109DCC04 |= 1u;
	//	sub_104D9E60(&unk_109DCBFC);
	//	result = atexit(sub_105BF010);
	//}
	//	PLAT_control_var = (int)&unk_109DCBFC;
	return result;
}

void Moho::PLAT_Init()
{
	int v0; // ecx
	int v1; // esi
	HANDLE v2; // eax

	v0 = PLAT_control_var;
	if ( !PLAT_control_var )
	{
		//startup.cpp
		swap_thread_objs((int)sub_1009A910, &dword_109BA774);
		v0 = PLAT_control_var;
	}
	v1 = v0;
	wait_thread_object(v0);
	if ( !byte_109BA76A )
	{
		byte_109BA76B = 0;
		SymSetOptions(0x216u);
		v2 = GetCurrentProcess();
		if ( SymInitialize(v2, 0, 1) )
			byte_109BA76B = 1;
		CreateMutexA(0, 0, "GPG_MohoEngine_Mutex");
		byte_109BA76A = 1;
	}
	wait_thread_object_destruc(v1);
}

void Moho::THREAD_SetAffinity(int a1)
{
	HANDLE v1; // eax
	unsigned int v2; // edx
	char v3; // si
	char v4; // cl
	DWORD v5; // ST08_4
	HANDLE v6; // eax
	DWORD ProcessAffinityMask; // [esp+Ch] [ebp-8h]
	DWORD SystemAffinityMask; // [esp+10h] [ebp-4h]

	v1 = GetCurrentProcess();
	GetProcessAffinityMask(v1, &ProcessAffinityMask, &SystemAffinityMask);
	v2 = 0;
	v3 = 31;
	while ( 1 )
	{
		v4 = v2;
		if ( a1 )
			v4 = v3;
		if ( (1 << v4) & ProcessAffinityMask )
			break;
		++v2;
		--v3;
		if ( v2 >= 0x20 )
			return;
	}
	v5 = 1 << v4;
	v6 = GetCurrentThread();
	SetThreadAffinityMask(v6, v5);
}

//Replace all strings of type in std::string.
//@@1 target string @@2 pattern string @@3 what to replace pattern with.
string Moho::replaceAll( const std::string& s, const std::string& f, const std::string& r )
{
	if ( s.empty() || f.empty() || f == r || s.find(f) == std::string::npos )
	{
		return s;
	}
	std::ostringstream build_it;
	size_t i = 0;
	for ( size_t pos; ( pos = s.find( f, i ) ) != std::string::npos; )
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
std::string Moho::USER_GetAppDataDir()
{
	std::string v1; // eax
	if (SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, NULL, Path) >=0)
	{
		v1 = std::string(Path);
		v1+="\\";
		v1+=dev_company;
		v1+="\\";
		v1+=game_name;
	}
	return v1;
}

//@@ return the string path to cache folder.
std::string Moho::USER_GetAppCacheDir()
{
	std::string AppDataDir;

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
	std::cout<<__func__<<" Cache dir is : \n";
	std::cout<<AppDataDir<<std::endl;
#endif
	return AppDataDir;
}

void Moho::USER_PurgeAppCacheDir()
{
	std::string path;
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