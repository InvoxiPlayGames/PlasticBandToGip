#include <iostream>
#include <Windows.h>
#include <Xinput.h>
#include "../converters.h"
#include "ToString.hpp"

// Quick 'n dirty playground for testing. Hack things up as needed.

int main()
{
    std::cout << "Hello World!\n";

    int lastPacketCount = 0;
    int errorCount = 0;
    BYTE gipBuffer[0xE] = { 0 };
    while (true)
    {
        Sleep(1);

        XINPUT_STATE state;
        if (XInputGetState(0, &state) != 0)
        {
            if (++errorCount >= 3)
                break;
            else
                continue;
        }

        if (state.dwPacketNumber == lastPacketCount)
            continue;
        lastPacketCount = state.dwPacketNumber;

        XInput_GuitarHero_ToGip((const BYTE*)&state.Gamepad, gipBuffer);

        std::cout << ToString::Hex((BYTE*)&state.Gamepad, sizeof(state.Gamepad)) << " -> "
            << ToString::Hex(gipBuffer, sizeof(gipBuffer)) << std::endl;
    }

    return 0;
}
