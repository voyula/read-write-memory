#include "stdafx.h"
#include "Windows.h"

int main()
{
    int newValue = 1000;
    int process = getProcessID("Application Name");
    printf("%d", readMemory(process, 0x00000000));
    printf("%d", writeMemory(process, 0x00000000, 1000));
    Sleep(10000);

    return 0;
}

int getProcess(string processName)
{
    HWND hwnd = FindWindowA(NULL, processName);
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

    return handle;
}

int readMemory(int handle, LPVOID lpBaseAddress)
{
    int read = 0;
    ReadProcessMemory(handle, lpBaseAddress, read, sizeof(int), NULL);

    return read;
}

bool writeMemory(int handle, LPVOID lpBaseAddress, int write)
{
    return WriteProcessMemory(handle, lpBaseAddress, write, sizeof(int), NULL);
}
