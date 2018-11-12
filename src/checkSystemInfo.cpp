#include "checkSystemInfo.h"

/* int checkSystemInfo(bool a1) {
  int result; // eax
  int STICKYKEYS_Str_exem; // [esp+8h] [ebp-28h]
  unsigned int v3; // [esp+Ch] [ebp-24h]
  int v4; // [esp+10h] [ebp-20h]
  unsigned int v5; // [esp+14h] [ebp-1Ch]
  int v6; // [esp+18h] [ebp-18h]
  unsigned int v7; // [esp+1Ch] [ebp-14h]
  int v8; // [esp+20h] [ebp-10h]
  int v9; // [esp+24h] [ebp-Ch]
  int v10; // [esp+28h] [ebp-8h]
  int v11; // [esp+2Ch] [ebp-4h]

  if ( a1 )
  {
  	SystemParametersInfoW(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &stickyKeys, 0);
  	SystemParametersInfoW(SPI_GETTOGGLEKEYS, sizeof(TOGGLEKEYS), &toggleKeys, 0);
  	SystemParametersInfoW(SPI_GETFILTERKEYS, sizeof(FILTERKEYS), &filterKeys, 0);
  }
  else
  {
    STICKYKEYS_Str_exem = STICKYKEYS_Structure;
    v3 = dword_F5788C;
    if ( !(dword_F5788C & 1) )
    {
      v3 = dword_F5788C & 0xFFFFFFF3;
      SystemParametersInfoW(SPI_GETSTICKYKEYS, 8u, &STICKYKEYS_Str_exem, 0);
    }
    v4 = TOOGLEKEYS_Structure;
    v5 = dword_F57894;
    if ( !(dword_F57894 & 1) )
    {
      v5 = dword_F57894 & 0xFFFFFFF3;
      SystemParametersInfoW(SPI_GETTOGGLEKEYS, 8u, &v4, 0);
    }
    result = dword_F5789C;
    v6 = FILTERKEYS_Structure;
    v8 = dword_F578A0;
    v9 = dword_F578A4;
    v10 = dword_F578A8;
    v11 = dword_F578AC;
    if ( !(dword_F5789C & 1) )
    {
      v7 = dword_F5789C & 0xFFFFFFF3;
      result = SystemParametersInfoW(SPI_GETFILTERKEYS, 0x18u, &v6, 0);
    }
  }
  return result;
}
} */
