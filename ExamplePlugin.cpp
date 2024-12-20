#include "ExamplePlugin.h"

// DLLのモジュールの取得
BOOL APIENTRY DllMain(HANDLE hModuleFunc, DWORD , LPVOID) {
    hModule = hModuleFunc;
    return TRUE;
}

class ExamplePlugin : public MMDPluginDLL3 {
    private:
        IDirect3DDevice9* device;
        HMODULE classModule;

    public:
		ExamplePlugin(IDirect3DDevice9* d) : classModule((HMODULE)hModule), device(d) {
            iniPath = getIniPath(L"config", L"ini");

            // iniファイルの存在確認
            if (!PathFileExists(iniPath)) {
                // iniファイルを保存
                WritePrivateProfileString(L"string", L"HogeHoge", L"Hello, World!", iniPath);
            }

            createMenu();
        }

		void createMenu() {
            //MMDのHWNDを取得
            HWND hWnd = getHWND();

            // MMDのメニューを取得
            HMENU menu = GetMenu(hWnd);

            // ポップメニューを作成
            HMENU subMenu = CreatePopupMenu();

            // メニューの作成
            MENUITEMINFOW mii;
            mii.cbSize = sizeof(MENUITEMINFOW);
            mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_SUBMENU;
            mii.fType = MFT_STRING;
            mii.wID = MAIN_MENU;
            mii.hSubMenu = subMenu;
            mii.dwTypeData = L"Example";
            InsertMenuItemW(menu, mii.wID, FALSE, &mii);

            mii.fMask = MIIM_ID | MIIM_TYPE;
            mii.fType = MFT_STRING;
            mii.wID = SUB_MENU1;
            mii.dwTypeData = L"SubMenu1";
            InsertMenuItemW(subMenu, mii.wID, FALSE, &mii);

            mii.fMask = MIIM_ID | MIIM_TYPE;
            mii.fType = MFT_STRING;
            mii.wID = SUB_MENU2;
            mii.dwTypeData = L"SubMenu2";
            InsertMenuItemW(subMenu, mii.wID, FALSE, &mii);

            mii.fMask = MIIM_ID | MIIM_TYPE;
            mii.fType = MFT_STRING;
            mii.wID = CHECK_MENU;
            mii.dwTypeData = L"CheckMenu";
            InsertMenuItemW(subMenu, mii.wID, FALSE, &mii);

            mii.fMask = MIIM_ID | MIIM_TYPE;
            mii.fType = MFT_STRING;
            mii.wID = ABOUT_MENU;
            mii.dwTypeData = L"About the plugin";
            InsertMenuItemW(subMenu, mii.wID, FALSE, &mii);

            // メニューを再描画
            DrawMenuBar(hWnd);
		}

		// wndProc
        void WndProc(const CWPSTRUCT* param) override {
            HWND hWnd = (HWND)param->lParam;

            switch (param->message) {
                case WM_LBUTTONUP:
                    WORD menuId = LOWORD(param->wParam);
                        
                    if (menuId == CHECK_MENU) {
                        HMENU menu = GetMenu(hWnd);
                        UINT state = GetMenuState(menu, CHECK_MENU, MF_BYCOMMAND);

                        if (state & MFS_CHECKED) {
                            CheckMenuItem(menu, CHECK_MENU, MF_BYCOMMAND | MFS_UNCHECKED);
                        } else {
                            CheckMenuItem(menu, CHECK_MENU, MF_BYCOMMAND | MFS_CHECKED);
                        }
                    } 
                    
                    if (menuId == ABOUT_MENU) {
                        MessageBox(hWnd, L"This plugin is Example.", L"About the plugin", MB_OK);
                    }
                    break;
                
                default:
                    break;
            }
        };

        WCHAR* getIniPath(WCHAR* fileName, WCHAR* fileExtension) {
            // 初期化
            WCHAR resPath[MAX_PATH];
            WCHAR dllPath[MAX_PATH];
            WCHAR drive[_MAX_DRIVE];
            WCHAR folder[_MAX_DIR];
            WCHAR file[_MAX_FNAME];
            WCHAR extension[_MAX_EXT];

            // DLLのパスを取得
            GetModuleFileName((HMODULE)hModule, dllPath, MAX_PATH);

            // DLLのパスを分割
            _tsplitpath_s(dllPath, drive, _MAX_DRIVE, folder, _MAX_DIR, file, _MAX_FNAME, extension, _MAX_EXT);

            // iniのパスを生成
            _tmakepath_s(resPath, MAX_PATH, drive, folder, fileName, fileExtension);

            // パスを返す
            return resPath;
        }

        // プラグイン名を返す
        const char* getPluginTitle() const override {
            return "Example Plugin";
        }
};

MMD_PLUGIN_API int version() {
    return 1;
}

MMD_PLUGIN_API MMDPluginDLL3* create3(IDirect3DDevice9* d) {
    return new ExamplePlugin(d);
}

MMD_PLUGIN_API void destroy3(MMDPluginDLL3* p) {
    delete p;
}