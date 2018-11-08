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

/* char sub_41B560(char *a1, int a2, char *Str2)
{
  char *v3; // ebp
  char *v4; // edi
  signed int v5; // esi
  int v7; // ebp
  void *v8; // ecx
  const char *v9; // eax
  int v10; // [esp+10h] [ebp-28h]
  int v11; // [esp+14h] [ebp-24h]
  int v12; // [esp+24h] [ebp-14h]
  unsigned int v13; // [esp+28h] [ebp-10h]
  int v14; // [esp+34h] [ebp-4h]

  v3 = Str2;
  v4 = a1;
  if ( !Str2 )
    return 0;
  v5 = 1;
  if ( dword_FB7D64 - (signed int)a1 <= 1 )
    return 0;
  while ( _stricmp(*(const char **)(dword_FB7D68 + 4 * v5), v3) )
  {
    if ( ++v5 >= dword_FB7D64 - (signed int)v4 )
      return 0;
  }
  if ( a2 )
  {
    sub_41BBC0(&Str2, *(_DWORD *)(a2 + 4), *(_DWORD *)(a2 + 8));
    if ( v4 )
    {
      v7 = 4 * v5;
      Str2 = v4;
      do
      {
        v8 = *(void **)(dword_FB7D68 + v7 + 4);
        v9 = *(const char **)(dword_FB7D68 + v7 + 4);
        v13 = 15;
        v12 = 0;
        LOBYTE(v11) = 0;
        sub_4059E0((int)&v10, v8, strlen(v9));
        v14 = 0;
        sub_411C30(&v10);
        v14 = -1;
        if ( v13 >= 0x10 )
          sub_957A60(v11);
        v7 += 4;
        --Str2;
      }
      while ( Str2 );
    }
  }
  return 1;
} */