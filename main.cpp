#include <string>

#include <iostream>

#include <limits>

#include <fstream>

#include <vector>

#include <windows.h>

#include <tchar.h>

#include <cstdio>

//----------------------

#include "src/startup.h"

using namespace std;

const char g_szClassName[] = "myWindowClass";

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	/*     WNDCLASSEX wc;
	    HWND hwnd;
	    MSG Msg;

	    //Step 1: Registering the Window Class
	    wc.cbSize        = sizeof(WNDCLASSEX);
	    wc.style         = 0;
	    wc.lpfnWndProc   = WndProc;
	    wc.cbClsExtra    = 0;
	    wc.cbWndExtra    = 0;
	    wc.hInstance     = hInstance;
	    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	    wc.lpszMenuName  = NULL;
	    wc.lpszClassName = g_szClassName;
	    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

		if(!RegisterClassEx(&wc))
	    {
	        MessageBox(NULL, "Window Registration Failed!", "Error!",
	            MB_ICONEXCLAMATION | MB_OK);
	        return 0;
	    }

			MessageBox(NULL, lpCmdLine, "WinMain Demo", 0);

	    // Step 2: Creating the Window
	    hwnd = CreateWindowEx(
	        WS_EX_CLIENTEDGE,
	        g_szClassName,
	        "ForgedAlliance",
	        WS_OVERLAPPEDWINDOW,
	        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
	        NULL, NULL, hInstance, NULL);

	    if(hwnd == NULL)
	    {
	        MessageBox(NULL, "Window Creation Failed!", "Error!",
	            MB_ICONEXCLAMATION | MB_OK);
	        return 0;
	    }

	    ShowWindow(hwnd, nCmdShow);
	    UpdateWindow(hwnd);

	    // Step 3: The Message Loop
	    while(GetMessage(&Msg, NULL, 0, 0) > 0)
	    {
	        TranslateMessage(&Msg);
	        DispatchMessage(&Msg);
	    }
	    return Msg.wParam; */

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
	if (lstrcmp(lpCmdLine, "/waitfordebugger") == 0) {
		MessageBoxW(0, L"...", L"trap to debugger", 0);
	}
	*(float * ) &ProcessAffinityMask = *reinterpret_cast <float*> (&v13);
	if (lstrcmp(lpCmdLine, "/aqtime") == 0) {
		//sub_9071C0(0); //set some byte variable to 0
	}
	v21 = 0;
	v22 = 0;
	v23 = 0;
	v19 = 0;
	SystemAffinityMask = (DWORD) & v13;
	v4 = lstrcmp(lpCmdLine, "/alloclog");
	v5 = v21;
	if (v4) {
		if ( * (_DWORD * )(v21 + 24) < 0x10u)
			v6 = (int)v21 + 4;
		else
			v6 = (int)&v21 + 4;
		set_PerformanceFrequency((char*)v6); //write the performance frequency to log to a file.
	}
	//sub_938FE0((int)sub_4F1500); //validate cmd line args, if not throw an error
	SystemAffinityMask = (DWORD)&v13;
	//FIX
	if( lstrcmp(lpCmdLine, "/singleproc") ) {
		currentProcess = GetCurrentProcess();
		GetProcessAffinityMask(currentProcess, (PDWORD_PTR)&ProcessAffinityMask, (PDWORD_PTR)&SystemAffinityMask);
		_BitScanForward(&affinityMaskIndex, (DWORD)&ProcessAffinityMask);
		currentProcessAffinityMask = 1 << affinityMaskIndex;
		SetProcessAffinityMask(currentProcess, readyProcessAffinityMask);
	}

	if (lstrcmp(lpCmdLine, "/purgecache") == 0)
	{
		//sub_8CA070(); //delete the cache files if those are present, maybe logs too
	}

	STICKYKEYS stickyKeys = { sizeof(STICKYKEYS), 0 };
	TOGGLEKEYS toggleKeys = { sizeof(TOGGLEKEYS), 0 };
	FILTERKEYS filterKeys = { sizeof(FILTERKEYS), 0 };

	SystemParametersInfoW(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &stickyKeys, 0);
	SystemParametersInfoW(SPI_GETTOGGLEKEYS, sizeof(TOGGLEKEYS), &toggleKeys, 0);
	SystemParametersInfoW(SPI_GETFILTERKEYS, sizeof(FILTERKEYS), &filterKeys, 0);

	//sub_8D4320(0); //more system info checks and sets the values
	//sub_8CE0A0(v10, (int)&v15); //strings as the name of the game, pobably an entry into engine's class constructor.
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

}
