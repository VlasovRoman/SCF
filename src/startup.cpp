#include "startup.h"

_DWORD* get_performance_count_ptr_stub(_DWORD *_this)
{
	_DWORD *v1; // esi

	v1 = _this;
	*(LARGE_INTEGER *)_this = get_performance_count_ptr();
	return v1;
}

LARGE_INTEGER get_performance_count_ptr()
{
	__int64 v0; // kr00_8
	unsigned int v1; // ecx
	DWORD v2; // ebx
	LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h]

	QueryPerformanceCounter(&PerformanceCount);
	do
	{
		v0 = qword_F8ED68;
		v1 = PerformanceCount.u.HighPart;
		if ( PerformanceCount.u.HighPart > SHIDWORD(qword_F8ED68) )
		{
			v2 = PerformanceCount.u.LowPart;
		}
		else if ( PerformanceCount.u.HighPart < SHIDWORD(qword_F8ED68)
		          || (v2 = PerformanceCount.u.LowPart, PerformanceCount.u.LowPart < (unsigned int)qword_F8ED68) )
		{
			v1 = (unsigned __int64)(qword_F8ED68 + 1) >> 32;
			v2 = qword_F8ED68 + 1;
			PerformanceCount.QuadPart = qword_F8ED68 + 1;
		}
	}
	while ( _InterlockedCompareExchange64(&qword_F8ED68, __PAIR__(v1, v2), qword_F8ED68) != v0 );
	return PerformanceCount;
}

void debug_pause()
{
	cout<<"Press any key to continue..."<<endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	exit(1);
}

/* void __cdecl sub_8D1E50(char a1, char a2, char a3)
{
  unsigned int v3; // eax
  char *v4; // edi
  int *v5; // ecx
  char *v6; // eax
  int v7; // eax
  const void *v8; // eax
  bool v9; // zf
  char *v10; // [esp+Ch] [ebp-1B4h]
  unsigned int v11; // [esp+10h] [ebp-1B0h]
  DWORD Str; // [esp+14h] [ebp-1ACh]
  int v13; // [esp+18h] [ebp-1A8h]
  char v14; // [esp+1Ch] [ebp-1A4h]
  void *v15; // [esp+20h] [ebp-1A0h]
  int v16; // [esp+30h] [ebp-190h]
  unsigned int v17; // [esp+34h] [ebp-18Ch]
  char v18; // [esp+38h] [ebp-188h]
  char Args[4]; // [esp+40h] [ebp-180h]
  int v20; // [esp+50h] [ebp-170h]
  unsigned int v21; // [esp+54h] [ebp-16Ch]
  int v22; // [esp+58h] [ebp-168h]
  int *v23; // [esp+60h] [ebp-160h]
  int v24; // [esp+70h] [ebp-150h]
  unsigned int v25; // [esp+74h] [ebp-14Ch]
  int v26; // [esp+78h] [ebp-148h]
  int v27; // [esp+7Ch] [ebp-144h]
  LARGE_INTEGER PerformanceCount; // [esp+80h] [ebp-140h]
  int v29; // [esp+8Ch] [ebp-134h]
  int v30; // [esp+90h] [ebp-130h]
  int v31; // [esp+A0h] [ebp-120h]
  unsigned int v32; // [esp+A4h] [ebp-11Ch]
  char v33; // [esp+A8h] [ebp-118h]
  char v34; // [esp+B0h] [ebp-110h]
  int v35; // [esp+1BCh] [ebp-4h]

  EnterCriticalSection(&CriticalSection);
  if ( !byte_10A6490 )
  {
    byte_10A6490 = 1;
    Str = GetCurrentThreadId();
    fwrite(&Str, 4u, 1u, File);
    QueryPerformanceCounter(&PerformanceCount);
    fwrite(&PerformanceCount, 8u, 1u, File);
    fwrite(&a1, 4u, 1u, File);
    fwrite(&a2, 4u, 1u, File);
    fwrite(&a3, 4u, 1u, File);
    v3 = sub_4A22B0(0x40u, (int)&v34);
    if ( v3 > 0 )
    {
      v4 = &v34;
      v10 = &v34;
      v11 = v3;
      do
      {
        fwrite(v4, 4u, 1u, File);
        if ( *(_BYTE *)(sub_8D4C10((int)&v33, (unsigned int *)v4) + 4) )
        {
          v21 = 15;
          v20 = 0;
          Args[0] = 0;
          v25 = 15;
          v24 = 0;
          LOBYTE(v23) = 0;
          v35 = 0;
          v17 = 15;
          v16 = 0;
          LOBYTE(v15) = 0;
          LOBYTE(v35) = 1;
          if ( sub_4A2440(*(_DWORD *)v4, (DWORD *)&v18) )
          {
            v5 = v23;
            if ( v25 < 0x10 )
              v5 = (int *)&v23;
            v6 = *(char **)Args;
            if ( v21 < 0x10 )
              v6 = Args;
            v7 = sub_938F10((int)&v29, (int)"%s + %d bytes (%s(%d) + %d bytes)", v6, v22, v5, v26, v27);
            LOBYTE(v35) = 2;
            sub_4056B0((int)&v14, v7, 0, 0xFFFFFFFF);
            if ( v32 >= 0x10 )
              sub_957A60();
            v32 = 15;
            v31 = 0;
            LOBYTE(v30) = 0;
          }
          v8 = v15;
          if ( v17 < 0x10 )
            v8 = &v15;
          fwrite(v8, 1u, v16 + 1, File);
          if ( v17 >= 0x10 )
            sub_957A60();
          v35 = -1;
          v17 = 15;
          v16 = 0;
          LOBYTE(v15) = 0;
          if ( v25 >= 0x10 )
            sub_957A60();
          v25 = 15;
          v24 = 0;
          LOBYTE(v23) = 0;
          if ( v21 >= 0x10 )
            sub_957A60();
          v4 = v10;
          v21 = 15;
          v20 = 0;
          Args[0] = 0;
        }
        v4 += 4;
        v9 = v11-- == 1;
        v10 = v4;
      }
      while ( !v9 );
    }
    v13 = 0;
    fwrite(&v13, 4u, 1u, File);
    byte_10A6490 = 0;
  }
  LeaveCriticalSection(&CriticalSection);
} */

int sub_957EF0(int a1)
{
	int result; // eax

	result = a1;
	dword_F8F330 = (int (cdecl *)(_DWORD, _DWORD, _DWORD))a1;
	return result;
}

void close_criticalSection_file(void)
{
	sub_957EF0(0);
	fclose(File);
	File = 0;
	DeleteCriticalSection(&CriticalSection);
}

FILE set_PerformanceFrequency(const char *a1)
{
	FILE *result; // eax
	FILE *v2; // esi
	LARGE_INTEGER Frequency; // [esp+4h] [ebp-8h]

	result = fopen(a1, "wb");
	v2 = result;
	if ( result )
	{
		QueryPerformanceFrequency(&Frequency);
		fwrite(&Frequency, 8u, 1u, v2);
		InitializeCriticalSection(&CriticalSection);
		File = v2;
		atexit(close_criticalSection_file);
		// result = (FILE *)sub_957EF0((int)sub_8D1E50); //this function is big, leave for now...
	}
	//return result;
}
