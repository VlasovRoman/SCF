#include "startup.h"
#include "moho.h"

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
	LPWSTR pszPath; // [esp+28h] [ebp-214h]

	if ( SHGetFolderPathW(0, 28, 0, 0, pszPath) >= 0 )
	{
		//v1 = gpg::STR_WideToUtf8(pszPath);
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

	bool isDirCreated = CreateDirectoryA(AppDataDir.c_str(), nullptr);
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
	string v0; // eax
	int v1; // esi
	int v2; // eax
	const char *v3; // [esp+0h] [ebp-88h]
	char v4; // [esp+Eh] [ebp-7Ah]
	char v5; // [esp+Fh] [ebp-79h]
	char v6; // [esp+10h] [ebp-78h]
	char v7; // [esp+18h] [ebp-70h]
	char v8; // [esp+20h] [ebp-68h]
	const CHAR *v9; // [esp+24h] [ebp-64h]
	unsigned int v10; // [esp+38h] [ebp-50h]
	string v11; // [esp+3Ch] [ebp-4Ch]
	struct _SHFILEOPSTRUCTA FileOp; // [esp+58h] [ebp-30h]
	int v13; // [esp+84h] [ebp-4h]

	v0 = USER_GetAppCacheDir();
// v11==v0.append("/*");
// v13 = 0;

// v11 = replaceAll( v11, rightslash, double_left_slash);

// cout<<v11<<endl;

	/*   std::operator+<char,std::char_traits<char>,std::allocator<char>>(&v8, v0, "/*");
	  LOBYTE(v13) = 2;
	  std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v11);
	  v4 = 92;
	  v5 = 47;
	  v1 = std::basic_string<char,std::char_traits<char>,std::allocator<char>>::end(&v8, &v6);
	  v2 = std::basic_string<char,std::char_traits<char>,std::allocator<char>>::begin(&v8, &v7);
	  sub_1048D030(&v5, &v4, *(_DWORD *)v2, *(int **)(v2 + 4), *(_DWORD *)v1, *(int **)(v1 + 4));
	  std::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(&v8, 0);
	  FileOp.hwnd = 0;
	  FileOp.pFrom = 0;
	  FileOp.pTo = 0;
	  *(_QWORD *)&FileOp.fFlags = 0i64;
	  *(LPVOID *)((char *)&FileOp.hNameMappings + 2) = 0;
	  HIWORD(FileOp.lpszProgressTitle) = 0;
	  FileOp.wFunc = 3;
	  if ( v10 < 0x10 )
	    FileOp.pFrom = (LPCSTR)&v9;
	  else
	    FileOp.pFrom = v9;
	  FileOp.fFlags = 1044;
	  if ( SHFileOperationA(&FileOp) )
	   // gpg::Warnf((gpg *)"unable to purge cache directory", v3); */
// v13 = -1;
// std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v8);
}