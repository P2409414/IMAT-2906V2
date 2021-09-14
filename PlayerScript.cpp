#include "PlayerScript.h"
#include <Windows.h>
#include <stdlib.h>
#pragma once
using namespace std;

int main() {
    PlayerScript Object;
    Object.rb = GetComponent<Rigidbody2D>();
    Object.ac = GetComponent<Animator>();
    Object.ground = LayerMask.GetMask("Ground");

    while (true) {
        Sleep(1);
        if (GetKeyState(VK_LEFT)) {
            Object.UporDown = -1;
        }
        else if (GetKeyState(VK_RIGHT)) {
            Object.UporDown = +1;
        }
        else if (GetKeyState(VK_DOWN)) {
            Object.DirectionMove = -1;
        }
        else if (GetKeyState(VK_UP)) {
            Object.DirectionMove = +1;
        }
        Object.FixedUpdate();
    }
};
