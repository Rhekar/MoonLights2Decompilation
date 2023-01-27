#pragma once
#include <windows.h>

typedef enum {
    DEFAULT,
    FULLSCREEN,
    DDRAW,
    DDRAWFULLSCREEN,
} window_t;

typedef struct {
    window_t window_type;
    UINT v1;
    UINT directsound_enable;
    UINT vc;
    UINT frameskip;
    UINT imagesize;
    // Greyed out? Desc is HW image optimization
    UINT v18;
    // 0 for 320, 1 for 640
    UINT resolution;
    // How fast the combat is
    UINT speed;
    UINT bgm;
    UINT sound_effects;
    // Unused?
    UINT v2c;
} Settings;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
HWND CreateMainWindow(window_t type, HINSTANCE hInstance, int nCmdShow);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int InitDirectDraw(int mode, HWND hwnd);
int DirectDrawSurfaceFunc();

LRESULT MainDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int UseActiveWindow(LPCWSTR window_name);

// Originally below keyconfig in the original but moved here for clarity
void DDrawSomething();

LRESULT KeyConfigDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT OptionsDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT DirectSoundDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT GameSpeedDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT DXDisplayDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT SpeedDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT SoundDialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
