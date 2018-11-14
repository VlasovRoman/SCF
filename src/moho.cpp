#include "startup.h"
#include "moho.h"

Moho::Moho(int a2)
{
	CScApp__vftable vft;
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