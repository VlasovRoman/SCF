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