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

// 変数の初期化
#ifdef _WIN64
#define _LONG_PTR LONG_PTR
#else
#define _LONG_PTR LONG
#endif
HANDLE hModule;
WCHAR* iniPath;

// メニューのIDを生成
UINT MAIN_MENU = createWM_APP_ID();
UINT SUB_MENU1 = createWM_APP_ID();
UINT SUB_MENU2 = createWM_APP_ID();
UINT CHECK_MENU = createWM_APP_ID();
UINT ABOUT_MENU = createWM_APP_ID();