#include <iostream>

#include "ProcessUtil.h"
#include "SDK/Entity.h"

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
            LocalPlayer* localPlayer = new LocalPlayer(clientAddress);
            if (localPlayer->toEntity()->isValid() && localPlayer->toEntity()->isAlive())
            {
                if (GetAsyncKeyState(VK_SPACE) && localPlayer->toEntity()->isOnGround())
                    localPlayer->jump();
            }
        }
    }
    cout << "CSGO is running..." << endl;

    return EXIT_SUCCESS;
}
