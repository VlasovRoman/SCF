#pragma once
#include "startup.h"


class CScApp : public wxApp
{
public:
	virtual bool OnInit();

	int unk1;// (a2 + 68)
	int unk2;//(a2 + 72)
	bool unk3;//(a2 + 73)
	int unk4;//(a2 + 76)
	int unk5;//
	int unk6;//
	int unk7;//
	int unk8;//(a2 + 136)
	int unk9;//(a2 + 140)

	_DWORD unk_perf_counter;

	int unk10;
	int unk11;
	int unk12;
	int unk13;
	int unk14;
	int unk15;
	int unk16;
	std::string unk_str1;
	std::string unk_str2;
};