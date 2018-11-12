#pragma once
#include "moho.h"

using namespace std;

namespace gpg
{

/* gpg *__cdecl STR_EncodeUtf8Char(gpg *this, char *a2, int a3)
{
	gpg *result; // eax

	result = this;
	if ( (unsigned __int16)a2 >= 0x80u )
	{
		if ( (unsigned __int16)a2 >= 0x800u )
		{
			if ( !a3 || (unsigned int)this + 3 <= a3 )
			{
				*(_BYTE *)this = ((unsigned __int16)a2 >> 12) | 0xE0;
				*((_BYTE *)this + 1) = ((unsigned int)a2 >> 6) & 0x3F | 0x80;
				*((_BYTE *)this + 2) = (unsigned __int8)a2 & 0x3F | 0x80;
				result = (gpg *)((char *)this + 3);
			}
		}
		else if ( !a3 || (unsigned int)this + 2 <= a3 )
		{
			*(_BYTE *)this = ((unsigned int)a2 >> 6) | 0xC0;
			*((_BYTE *)this + 1) = (unsigned __int8)a2 & 0x3F | 0x80;
			result = (gpg *)((char *)this + 2);
		}
	}
	else if ( !a3 || (unsigned int)this + 1 <= a3 )
	{
		*(_BYTE *)this = (_BYTE)a2;
		result = (gpg *)((char *)this + 1);
	}
	return result;
} */

static string STR_WideToUtf8(string utf8, LPWSTR str)
{
	LPWSTR v3; // esi
	char *i; // eax
	char *v5; // eax
	const char *v7; // [esp+0h] [ebp-18h]

// std::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string<char,std::char_traits<char>,std::allocator<char>>(a1);
	v3 = str;
	if ( str )
	{
		//for ( i = (char *)*str; (_WORD)i; ++v3 )
		//{
			//v5 = gpg::STR_EncodeUtf8Char((gpg *)&str, i, (unsigned int)&a3, v7);
			//std::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(a1, &str, v5 - (char *)&str);
			//i = (char *)v3[1];
		//}
	}
	return utf8;
}


};//namespace gpg