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

uint32_t ConvertReadInputsToBitArray(uint8_t button1,
                                     uint8_t button2,
                                     uint8_t button3,
                                     uint8_t button4,
                                     uint8_t button5,
                                     uint8_t button6,
                                     uint8_t button7,
                                     uint8_t button8);
