#include "stdafx.h"
#include "Windows.h"

int main()
{
    int newValue = 1000;
    int read = 0;
    HWND hwnd = FindWindowA(NULL, "Application Name");
    if(hwnd == NULL) {
        printf("Error");
        Sleep(5000);
        exit(-1);
    }

    DWORD pID;
    GetWindowThreadProcessId(hwnd, &pID);
    HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
    if(handle == NULL) {
        printf("Error");
        Sleep(5000);
        exit(-1);
    }

    ReadProcessMemory(handle, (PBYTE*) 0x00000000, &read, sizeof(int), NULL);
    WriteProcessMemory(handle, (LPVOID) 0x00000000, &newValue, sizeof(int), NULL);
    Sleep(10000);

    return 0;
}

