#include "stdafx.h"
#include "Windows.h"
#include "read-write-memory.h" // header in local directory
#include <iostream> // header in standard library

using namespace Memory;
using namespace std;

int read_write_memory::getProcess(string processName)
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

int read_write_memory::readMemory(int handle, LPVOID lpBaseAddress)
{
    int read = 0;
    ReadProcessMemory(handle, lpBaseAddress, read, sizeof(int), NULL);

    return read;
}

bool read_write_memory::writeMemory(int handle, LPVOID lpBaseAddress, int write)
{
    return WriteProcessMemory(handle, lpBaseAddress, write, sizeof(int), NULL);
}
