#pragma once
#include <windows.h>

typedef enum {
    ONE,
    TWO,
} window_t;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
HWND CreateMainWindow(window_t type, HINSTANCE hInstance, int nCmdShow);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int UseActiveWindow(LPCSTR window_name);
