#include "PlatformMovement.h"
#include <Windows.h>
#include <stdlib.h>
#pragma once
using namespace std;

int main() {
    PlatformMovement Object;
    while (true) {
        Sleep(1);
        Object.FixedUpdate();
    }
};
