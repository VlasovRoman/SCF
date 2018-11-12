#include "startup.h"
#include "moho.h"

int* sub_1048D030(int *a1, int *a2, int a3, int *a4, int a5, int *a6)
{
  int *result; // eax

  for ( result = a4; result != a6; ++result )
  {
    if ( *result == *a1 )
      *result = *a2;
  }
  return result;
}

string Moho::USER_GetAppDataDir(string a1)
{
  string v1; // eax
  LPSTR pszPath; // [esp+28h] [ebp-214h]
  int v5; // [esp+238h] [ebp-4h]

  v5 = 0;
  if ( SHGetFolderPathA(0, 28, 0, 0, pszPath) >= 0 )
  {
    v1 = gpg::STR_WideToUtf8(pszPath);
	v1.append(dev_company);
	v1.append("\\");
	v1.append(game_name);
	v1.append("\\");
  }
  return v1;
}

string Moho::USER_GetAppCacheDir(string a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax
  const CHAR *v4; // eax
  char v6; // [esp+16h] [ebp-42h]
  char v7; // [esp+17h] [ebp-41h]
  int v8; // [esp+18h] [ebp-40h]
  char v9; // [esp+1Ch] [ebp-3Ch]
  char v10; // [esp+24h] [ebp-34h]
  char v11; // [esp+2Ch] [ebp-2Ch]
  int v12; // [esp+54h] [ebp-4h]

  USER_GetAppDataDir(a1);
 /*  v12 = 0;
  v8 = 1;
  v6 = 47;
  v7 = 92;
  v1 = std::basic_string<char,std::char_traits<char>,std::allocator<char>>::end(a1, &v9);
  v2 = std::basic_string<char,std::char_traits<char>,std::allocator<char>>::begin(a1, &v10);
  sub_1048D030(&v7, &v6, *(_DWORD *)v2, *(int **)(v2 + 4), *(_DWORD *)v1, *(int **)(v1 + 4));
  v3 = std::operator+<char,std::char_traits<char>,std::allocator<char>>(&v11, a1, "cache");
  v12 = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(v3);
  LOBYTE(v12) = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v11);
  if ( *((_DWORD *)a1 + 6) < 0x10u )
    v4 = a1 + 4;
  else
    v4 = (const CHAR *)*((_DWORD *)a1 + 1);
  CreateDirectoryA(v4, 0);
  return a1; */
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

  v0 = USER_GetAppCacheDir(v11);
/*   v13 = 0;
  std::operator+<char,std::char_traits<char>,std::allocator<char>>(&v8, v0, "/*");
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
   // gpg::Warnf((gpg *)"unable to purge cache directory", v3);
  v13 = -1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string<char,std::char_traits<char>,std::allocator<char>>(&v8); */
}