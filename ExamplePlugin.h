#pragma once
#include "lib/mmd_plugin.h"
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#pragma comment(lib, "shlwapi.lib")
#include <Shlwapi.h>
#include <tchar.h>
using namespace mmp;
using namespace std;

// 変数の初期化など
LONG_PTR originWndProc = NULL;
#ifdef _WIN64
#define _LONG_PTR LONG_PTR
#else
#define _LONG_PTR LONG
#endif
HANDLE hModule;
WCHAR* iniPath;

// メニューのIDを生成
UINT MainMenu = createWM_APP_ID();
UINT SubMenu1 = createWM_APP_ID();
UINT SubMenu2 = createWM_APP_ID();
UINT CheckMenu = createWM_APP_ID();
UINT AboutMenu = createWM_APP_ID();
// ----