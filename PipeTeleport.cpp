#include "PipeTeleport.h"
#include <Windows.h>
#include <stdlib.h>
#pragma once
using namespace std;

int main() {
    PipeTeleport Object;

    while (true) {
        Sleep(1);
        if (GetKeyState(VK_DOWN)) {
            Object.UporDown = -1;
        }
        else if (GetKeyState(VK_UP)) {
            Object.UporDown = +1;
        }
    }
};
