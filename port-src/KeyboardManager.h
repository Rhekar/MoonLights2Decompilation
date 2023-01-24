#pragma once

#include <windows.h>

typedef struct
{
    
} KeyboardManager;

// Sets HWND and clears out keyboard fields
void SetupKeyboard(HWND hWnd);

// Clears out keyboard state
void ClearKeyboard();

int ReadKeyboard(int* mystery);

uint32_t ConvertReadInputsToBitArray(char b1,
                                 char b2,
                                 char b3,
                                 char b4,
                                 char b5,
                                 char b6,
                                 char b7,
                                 char b8,
                                 );
