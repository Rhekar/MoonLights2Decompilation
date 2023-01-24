#ifndef UNICODE
#define UNICODE
#endif
#include "main.h"

#include <windows.h>
#include <strsafe.h>
#include <commctrl.h>
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"gdi32.lib")

#define ML2 L"Moon Lights 2"
#define ML2VER L"Moon Lights 2 Ver.1.07"
extern char* NO_USE;
extern char* JOYSTICK1;
extern char* JOYSTICK2;

HWND HWND_00688518;
window_t window_type;






int UseActiveWindow(LPCSTR window_name) {
    HWND hWnd;
    WINDOWPLACEMENT window_placement;

    hWnd = FindWindowExA((HWND)0, (HWND)0, window_name, (LPCSTR)0);
    if (hWnd == (HWND)0) {
        return 0;
    }
    window_placement.length = 0x2c;
    if (GetWindowPlacement(hWnd, &window_placement) == 0) {
        return -1;
    }
    if (window_placement.showCmd == 2) {
        window_placement.showCmd = 1;
        if (SetWindowPlacement(hWnd,&window_placement) == 0) {
            return -1;
        }
    }
    SetActiveWindow(hWnd);
    SetForegroundWindow(hWnd);
    return -1;
}

void lollmao(){
      int msgboxID = MessageBoxA(
      NULL,
      (LPCSTR)ML2,
      (LPCSTR)"Lol. Lmao",
      MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
      );
}

// yes this should be normal winmain but shift-JIS is a curse upon this land
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    int iVar1;
    int* IVar2;
    int* puVar3;

    InitCommonControls();
    iVar1 = UseActiveWindow((LPCSTR)ML2);
    if (iVar1 == -1) {
        return -1;
    }

    /*
    int msgboxID = MessageBoxA(
                               NULL,
                               (LPCSTR)ML2,
                               (LPCSTR)ML2,
                               MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
                               );
    */

    /*
    puVar3 = &DAT_00687860;
    for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
    }
    iVar1 = findCDDrive@FUN_0042b5c0();
    if (iVar1 != -1) {
    DAT_00687860._1_1_ = ':';
    DAT_00687860._2_1_ = '\\';
    DAT_00687860._3_1_ = 0;
    DAT_00687860._0_1_ = (char)iVar1 + 'A';
    }
    DAT_004c15f4 = param_1;
    FUN_0042a3f0();
    FUN_00429fe0();
    IVar2 = DialogBoxParamA(DAT_004c15f4,s_IDD_BOOT_004398d4,(HWND)0x0,FUN_00406850,0);
    if (IVar2 == -1) {
    return 0xffffffff;
    }
    FUN_0042a270();
    if (DAT_00439864 == 1) {
    DAT_00439860 = DAT_00439860 | 2;
    }
    iVar1 = findActiveWindow@FUN_00406a90(s_Moon_Lights_2_00439890);
    if (iVar1 == -1) {
    return 0xffffffff;
    }
    _DAT_0068a3a8 = 1;
    */
    window_type = 0;
    HWND_00688518 = CreateMainWindow(window_type, hInstance, nCmdShow);
    if (HWND_00688518 == NULL) {
        LPVOID lpMsgBuf;
        LPVOID lpDisplayBuf;
        LPTSTR lpszFunction = "AA";
        DWORD dw = GetLastError(); 
        FormatMessage(
                      FORMAT_MESSAGE_ALLOCATE_BUFFER | 
                      FORMAT_MESSAGE_FROM_SYSTEM |
                      FORMAT_MESSAGE_IGNORE_INSERTS,
                      NULL,
                      dw,
                      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                      (LPTSTR) &lpMsgBuf,
                      0, NULL );

        // Display the error message and exit the process

        lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
                                          (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR)); 
        StringCchPrintf((LPTSTR)lpDisplayBuf, 
                        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
                        TEXT("%s failed with error %d: %s"), 
                        lpszFunction, dw, lpMsgBuf); 
        MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK); 
 
        return 0;
    }
    /* Sound Stuff
    if (DAT_00439868 == 0) {
        _DAT_006b2fd0 = 0xffffffff;
    }
    else {
        _DAT_006b2fd0 = soundrelated?@FUN_0042ac40(HWND@DAT_00688518);
    }
    soundorstringrelated@FUN_00410c50(s_13.ZMD_004398cc);
    */
    /* Registry Scores
    registryManage@FUN_0042a790();
    registryStuff2@FUN_0042a920();
    regsitryTimeAttack@FUN_0042aab0();
    */
    //_DAT_006b2e68 = 0;
    //init?@FUN_00413eb0();
    //DestroyWindow(HWND@DAT_00688518);
    lollmao();
    return 0;
}

HWND CreateMainWindow(window_t type, HINSTANCE hInstance, int nCmdShow) {
    ATOM atom;
    HDC info_context;
    int iVar1;
    int iVar2;
    HMENU hmenu;
    HWND hwnd;
    LPVOID lpParam;
    WNDCLASS wnd_class_ex = {
        .hInstance = hInstance,
        .lpszClassName = ML2,
        .lpfnWndProc = WindowProc,
    };
 
    switch(type) {
    case 0:
        /*
        WNDCLASS wnd_class_ex = {
            .hInstance = hInstance,
            .lpszClassName = ML2,
            .lpfnWndProc = WindowProc,
            //.style = 0,
            //.cbSize = 0x30,
            //.hIcon = LoadIconA(hInstance, "ICON"),
            //.hIconSm = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f05),
            //.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00),
            //.lpszMenuName = (LPCSTR)0x0,
            //.cbClsExtra = 0,
            //.cbWndExtra = 0,
            //.hbrBackground = (HBRUSH)GetStockObject(0),
        };
        */
        /*
        wnd_class_ex_a.hInstance = hInstance;
        wnd_class_ex_a.lpszClassName = ML2;
        wnd_class_ex_a.lpfnWndProc = WindowProc;
        wnd_class_ex_a.style = 0;
        wnd_class_ex_a.cbSize = 0x30;
        wnd_class_ex_a.hIcon = LoadIconA(hInstance, "ICON");
        wnd_class_ex_a.hIconSm = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f05);
        wnd_class_ex_a.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
        wnd_class_ex_a.lpszMenuName = (LPCSTR)0x0;
        wnd_class_ex_a.cbClsExtra = 0;
        wnd_class_ex_a.cbWndExtra = 0;
        wnd_class_ex_a.hbrBackground = (HBRUSH)GetStockObject(0);
            */
        atom = RegisterClass(&wnd_class_ex);
        if (atom == 0) {
            lollmao();
            return (HWND)0x0;
        }
        hwnd = CreateWindowEx(0, ML2, ML2VER, 0xcf0000,
                               //-0x80000000, -0x80000000, 0x180, 0x140,
                               CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                               (HWND)0x0, (HMENU)0x0, hInstance, (LPVOID)0x0);
        if (hwnd != (HWND)0x0) {
            info_context = CreateICA("Display",(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
            iVar1 = GetDeviceCaps(info_context,0xc);
            DeleteDC(info_context);
            // This bit checks for 8bpp. As a modern machine has truecolor this has been changed from != to <
            // A value of 1 indicates greater than 8 color depth. Seems to be 32 for truecolor.
            if (iVar1 < 8 && iVar1 != 1) {
                return (HWND)0x0;
            }
            ShowWindow(hwnd,nCmdShow);
            UpdateWindow(hwnd);
            return hwnd;
        }
        break;
    case 1:
        break;
    case 2:
        break;
    /*
    case 1:
        iVar1 = FUN_0042b890(&DAT_004c1560);
        if (iVar1 == -1) {
            return (HWND)0x0;
        }
        FUN_0042b900(8,0x280,0x1e0);
        WNDCLASSA wnd_class_a;
        wnd_class_a.cbClsExtra = 0;
        wnd_class_a.cbWndExtra = 0;
        wnd_class_a.hInstance = hInstance;
        wnd_class_a.style = 3;
        wnd_class_a.lpfnWndProc = WindowProc;
        wnd_class_a.hIcon = LoadIconA(hInstance,(LPCSTR)0x7f00);
        wnd_class_a.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
        wnd_class_a.hbrBackground = (HBRUSH)0x0;
        wnd_class_a.lpszMenuName = s_Moon_Lights_2_Ver.1.07_004398a0;
        wnd_class_a.lpszClassName = s_Moon_Lights_2_00439890;
        RegisterClassA(&wnd_class_a);
        lpParam = (LPVOID)0x0;
        hmenu = (HMENU)0x0;
        hwnd = (HWND)0x0;
        iVar1 = GetSystemMetrics(1);
        iVar2 = GetSystemMetrics(0);
        hwnd = CreateWindowExA(8,s_Moon_Lights_2_00439890,s_Moon_Lights_2_Ver.1.07_004398a0,0x80000000,0
                               ,0,iVar2,iVar1,hwnd,hmenu,hInstance,lpParam);
        if (hwnd != (HWND)0x0) {
            info_context = CreateICA("Display",(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
            iVar1 = GetDeviceCaps(info_context,0xc);
            DeleteDC(info_context);
            if (iVar1 != 8) {
                MessageBoxA(hwnd,&DAT_0043998c,s_Moon_Lights_2_Ver.1.07_004398a0,0);
                return (HWND)0x0;
            }
            ShowWindow(hwnd,nCmdShow);
            UpdateWindow(hwnd);
            SetFocus(hwnd);
            ShowCursor(0);
            return hwnd;
        }
        break;
    case 2:
        WNDCLASSA wnd_class_a;
        wnd_class_a.cbClsExtra = 0;
        wnd_class_a.cbWndExtra = 0;
        wnd_class_a.hInstance = hInstance;
        wnd_class_a.style = 3;
        wnd_class_a.lpfnWndProc = WindowProc;
        wnd_class_a.hIcon = LoadIconA(hInstance,(LPCSTR)0x7f00);
        wnd_class_a.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
        wnd_class_a.hbrBackground = (HBRUSH)0x0;
        wnd_class_a.lpszMenuName = s_Moon_Lights_2_Ver.1.07_004398a0;
        wnd_class_a.lpszClassName = s_Moon_Lights_2_00439890;
        RegisterClassA(&wnd_class_a);
        hwnd = CreateWindowExA(0,s_Moon_Lights_2_00439890,s_Moon_Lights_2_Ver.1.07_004398a0,0xca0000,
                               -0x80000000,-0x80000000,0x106,0x118,(HWND)0x0,(HMENU)0x0,hInstance,
                               (LPVOID)0x0);
        if (hwnd != (HWND)0x0) {
            info_context = CreateICA("Display",(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
            iVar1 = GetDeviceCaps(info_context,0xc);
            DeleteDC(info_context);
            if (iVar1 != 8) {
                MessageBoxA(hwnd,&DAT_0043998c,s_Moon_Lights_2_Ver.1.07_004398a0,0);
                return (HWND)0x0;
            }
            ShowWindow(hwnd,nCmdShow);
            UpdateWindow(hwnd);
            iVar1 = FUN_00406580(0,hwnd);
            if (iVar1 == 0) {
                MessageBoxA(hwnd,&DAT_00439938,s_Moon_Lights_2_Ver.1.07_004398a0,0);
                DestroyWindow(hwnd);
                return (HWND)0x0;
            }
        }
        break;
    case 3:
        wnd_class_a.cbClsExtra = 0;
        wnd_class_a.cbWndExtra = 0;
        wnd_class_a.hInstance = hInstance;
        wnd_class_a.style = 3;
        wnd_class_a.lpfnWndProc = WindowProc;
        wnd_class_a.hIcon = LoadIconA(hInstance,(LPCSTR)0x7f00);
        wnd_class_a.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
        wnd_class_a.hbrBackground = (HBRUSH)0x0;
        wnd_class_a.lpszMenuName = s_Moon_Lights_2_Ver.1.07_004398a0;
        wnd_class_a.lpszClassName = s_Moon_Lights_2_00439890;
        RegisterClassA(&wnd_class_a);
        lpParam = (LPVOID)0x0;
        hmenu = (HMENU)0x0;
        hwnd = (HWND)0x0;
        iVar1 = GetSystemMetrics(1);
        iVar2 = GetSystemMetrics(0);
        hwnd = CreateWindowExA(8,s_Moon_Lights_2_00439890,s_Moon_Lights_2_Ver.1.07_004398a0,0x80000000,0
                               ,0,iVar2,iVar1,hwnd,hmenu,hInstance,lpParam);
        if (hwnd != (HWND)0x0) {
            ShowWindow(hwnd,nCmdShow);
            UpdateWindow(hwnd);
            SetFocus(hwnd);
            ShowCursor(0);
            iVar1 = FUN_00406580(1,hwnd);
            if (iVar1 == 0) {
                MessageBoxA(hwnd,&DAT_004398e0,s_Moon_Lights_2_Ver.1.07_004398a0,0);
                DestroyWindow(hwnd);
                return (HWND)0x0;
            }
        }
    */
    }
    return hwnd;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
