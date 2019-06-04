#include "../src/read_write_memory.h"

using namespace Memory;

int main()
{
    read_write_memory instance;
    int newValue = 1000;
    int process = instance.getProcessID("Application Name");
    printf("%d", instance.readMemory(process, 0x00000000));
    printf("%d", instance.writeMemory(process, 0x00000000, 1000));
    Sleep(10000);

    return 0;
}
