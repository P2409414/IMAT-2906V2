
#include "Bullets.h"
#include <Windows.h>
#include <stdlib.h>
#pragma once
using namespace std;

int main() {
    Bullets Object;
    Object.rb = GetComponent<Rigidbody2D>(); //!< Finding the rigidbody from the gameObject.

    while (true) {
        Sleep(1);
        Object.FixedUpdate();
    }
};
