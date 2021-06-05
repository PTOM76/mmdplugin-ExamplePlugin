// ヘッダーファイルのinclude
#include "ExamplePlugin.h"
// ----

// DLLのモジュールの取得
BOOL APIENTRY DllMain(HANDLE hModuleFunc, DWORD , LPVOID)
{
    hModule = hModuleFunc;
    return TRUE;
}
//----

// WndProc
static LRESULT CALLBACK pluginWndProc(HWND hWnd, UINT msg, WPARAM wp,
    LPARAM lp) {
    switch (msg) {
        case WM_COMMAND: {
            WORD menuId = LOWORD(wp);
            if (menuId == (WORD)CheckMenu) {
                HMENU menu = GetMenu(hWnd);
                UINT state = GetMenuState(menu, CheckMenu, MF_BYCOMMAND);
                if (state & MFS_CHECKED) {
                    CheckMenuItem(menu, CheckMenu, MF_BYCOMMAND | MFS_UNCHECKED);
                }
                else {
                    CheckMenuItem(menu, CheckMenu, MF_BYCOMMAND | MFS_CHECKED);
                }
                break;
            }
            else if (menuId == (WORD)AboutMenu) {
                MessageBox(hWnd, L"This plugin is Example.", L"About the plugin", MB_OK);
                break;
            }
        }
        default:
            break;
    }
    return CallWindowProc((WNDPROC)originWndProc, hWnd, msg, wp, lp);
};
// ----

WCHAR *getIniPath(WCHAR *fileName, WCHAR *fileExtension) {
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

// DLLが読み込まれたら実行する関数
void init()
{
    // dllの入っている場所を取得してconfig.iniのパスを設定
    iniPath = getIniPath(L"config", L"ini");

    // iniファイルの存在確認
    if (!PathFileExists(iniPath)) {
        // iniファイルを保存
        WritePrivateProfileString(L"string", L"HogeHoge", L"Hello, World!", iniPath);
    }
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
    mii.wID = MainMenu;
    mii.hSubMenu = subMenu;
    mii.dwTypeData = L"Example";
    InsertMenuItemW(menu, mii.wID, FALSE, &mii);

    mii.fMask = MIIM_ID | MIIM_TYPE;
    mii.fType = MFT_STRING;
    mii.wID = SubMenu1;
    mii.dwTypeData = L"SubMenu1";
    InsertMenuItemW(subMenu, mii.wID, FALSE, &mii);

    mii.fMask = MIIM_ID | MIIM_TYPE;
    mii.fType = MFT_STRING;
    mii.wID = SubMenu2;
    mii.dwTypeData = L"SubMenu2";
    InsertMenuItemW(subMenu, mii.wID, FALSE, &mii);

    mii.fMask = MIIM_ID | MIIM_TYPE;
    mii.fType = MFT_STRING;
    mii.wID = CheckMenu;
    mii.dwTypeData = L"CheckMenu";
    InsertMenuItemW(subMenu, mii.wID, FALSE, &mii);

    mii.fMask = MIIM_ID | MIIM_TYPE;
    mii.fType = MFT_STRING;
    mii.wID = AboutMenu;
    mii.dwTypeData = L"About the plugin";
    InsertMenuItemW(subMenu, mii.wID, FALSE, &mii);

    // メニューを再描画
    DrawMenuBar(hWnd);

    // MMDのWndProcを取得
    originWndProc = GetWindowLongPtr(hWnd, GWLP_WNDPROC);

    // WndProcをpluginWndProcに置換
    SetWindowLongPtr(hWnd, GWLP_WNDPROC, (_LONG_PTR)pluginWndProc);
}
// ----

// MMDPlugin
class ExamplePlugin : public MMDPluginDLL1 {
    private:
        HMODULE classModule;

    public:
        ExamplePlugin() : classModule((HMODULE)hModule)
        {
            // init()を呼び出す。
            init(); 
        }
};

// バージョン情報
MMD_PLUGIN_API int version() { return 1; }

MMD_PLUGIN_API MMDPluginDLL1* create1(IDirect3DDevice9*) {
    return new ExamplePlugin;
}

MMD_PLUGIN_API void destroy1(MMDPluginDLL1* p) { delete p; }