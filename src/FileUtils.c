#include "FileUtils.h"

#include <stdio.h>
#include <windows.h>

int FindCDDrive() {
    // this is going to be -1 alsmot all the time these days
    UINT offset;
    char buf[256];

    for (offset = 0; offset < 0x1a; ++offset) {
        sprintf(buf, "%c:\\", (char)(offset + 'A'));
        int drive_type = GetDriveTypeA(buf);
        if (drive_type == 5) {
            return offset;
        }
    }
    return -1;
}
