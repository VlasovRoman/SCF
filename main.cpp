#include "src/startup.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	char v4; // al
	int * v5; // edi
	int v6; // eax
	HANDLE currentProcess; // eax
	int v8; // eax
	HANDLE v9; // eax
	void * v10; // ecx
	int v11; // esi
	DWORD v13; // [esp-4h] [ebp-14Ch]
	int v14; // [esp+0h] [ebp-148h]
	int v15; // [esp+A8h] [ebp-A0h]
	int v16; // [esp+E4h] [ebp-64h]
	char v17; // [esp+108h] [ebp-40h]
	int * v18; // [esp+138h] [ebp-10h]
	int v19; // [esp+144h] [ebp-4h]
	char v20; // [esp+154h] [ebp+Ch]
	int * v21; // [esp+158h] [ebp+10h]
	int * v22; // [esp+15Ch] [ebp+14h]
	int v23; // [esp+160h] [ebp+18h]
	_DWORD v24; // [esp+164h] [ebp+1Ch]
	DWORD ProcessAffinityMask; // [esp+16Ch] [ebp+24h]
	DWORD SystemAffinityMask; // [esp+170h] [ebp+28h]

	v18 = & v14;
	get_performance_count_ptr_stub( & v24);
	*(float * ) &ProcessAffinityMask = *reinterpret_cast <float*> (&v13);
	if (lstrcmp(lpCmdLine, "/waitfordebugger") == 0)
	{
		MessageBoxW(0, L"...", L"trap to debugger", 0);
	}
	*(float * ) &ProcessAffinityMask = *reinterpret_cast <float*> (&v13);
	if (lstrcmp(lpCmdLine, "/aqtime") == 0)
	{
		//sub_9071C0(0); //set some byte variable to 0
	}
	v21 = 0;
	v22 = 0;
	v23 = 0;
	v19 = 0;
	SystemAffinityMask = (DWORD) & v13;
	v4 = lstrcmp(lpCmdLine, "/alloclog");
	v5 = v21;
	if (v4==0)
	{
		if ( * (_DWORD * )(v21 + 24) < 0x10u)
			v6 = (int)v21 + 4;
		else
			v6 = (int)&v21 + 4;
		set_PerformanceFrequency((char*)v6); //write the performance frequency to log to a file.
	}
	//sub_938FE0((int)sub_4F1500); //validate cmd line args, if not throw an error
	SystemAffinityMask = (DWORD)&v13;
	//FIX
	if( lstrcmp(lpCmdLine, "/singleproc")==0)
	{
		currentProcess = GetCurrentProcess();
		//GetProcessAffinityMask(currentProcess, (PDWORD_PTR)&ProcessAffinityMask, (PDWORD_PTR)&SystemAffinityMask);
		//_BitScanForward(&affinityMaskIndex, (DWORD)&ProcessAffinityMask);
		//currentProcessAffinityMask = 1 << affinityMaskIndex;
		//SetProcessAffinityMask(currentProcess, readyProcessAffinityMask);
	}

	stickyKeys = { sizeof(STICKYKEYS), 0 };
	toggleKeys = { sizeof(TOGGLEKEYS), 0 };
	filterKeys = { sizeof(FILTERKEYS), 0 };

	SystemParametersInfoW(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &stickyKeys, 0);
	SystemParametersInfoW(SPI_GETTOGGLEKEYS, sizeof(TOGGLEKEYS), &toggleKeys, 0);
	SystemParametersInfoW(SPI_GETFILTERKEYS, sizeof(FILTERKEYS), &filterKeys, 0);

	//checkSystemInfo(0); //more system info checks and sets the values
	CScApp__vftable vft;
	Moho obj(vft); //strings as the name of the game, pobably an entry into engine's class constructor.

	if (lstrcmp(lpCmdLine, "/purgecache") == 0)
	{
		obj.USER_PurgeAppCacheDir(); //delete the cache files if those are present, maybe logs too
	}
	
	obj.WIN_AppExecute(&vft);

	//LOBYTE(v19) = 2;
	//sub_4F20B0(&v15); //this checks operating system version / compatibility / WINDOW IS CREATED HERE.
	//v18 = 1;
	//*(float * ) &ProcessAffinityMask = sub_4A3560( &v23); //this goes into the get_performance_count_ptr_stub
	/* 	SystemAffinityMask = (signed int) * (float *) &ProcessAffinityMask;
		v12 = (signed int) SystemAffinityMask % 60;
		sub_937CB0(
			(int)
			"Run time: %dh%02dm%02ds",
			(signed int) SystemAffinityMask / 3600,
			(signed int) SystemAffinityMask % 3600 / 60,
			v12);
		sub_8D4320(1);
		sub_8D4410();
		v10 = v15;
		sub_8D5280( & v16);
		sub_8CD400( & v14);
		if (v5) {
			v12 = SystemAffinityMask;
			sub_40D540(v5, v21);
			sub_957A60(v5);
		}
		return v10;	 */

	debug_pause();
}
