#include <iostream>

#include "ProcessUtil.h"

static MemoryRW* csgo;

using namespace std;

int main()
{
    SetConsoleTitle(L"Sakura");

    const auto process = ProcessUtil::getProcessID(L"csgo.exe");
    csgo = new MemoryRW(OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, process));

    if (!csgo)
        return EXIT_FAILURE;

    const auto clientAddress = ProcessUtil::getModuleBaseAddress(process, L"client.dll");

    if (clientAddress)
    {
        while (true)
        {
            const auto localPlayer = csgo->read<uintptr_t>(clientAddress + Offsets::LocalPlayer);
            if (localPlayer)
            {
                const auto health = csgo->read<uintptr_t>(localPlayer + Offsets::m_iHealth);
                cout << health << endl;
            }
        }
    }
    cout << "CSGO is running..." << endl;

    return EXIT_SUCCESS;
}
