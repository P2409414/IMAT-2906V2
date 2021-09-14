#include "Shoot.h"
#include <Windows.h>
#pragma once
using namespace std;

int main() {
	Shoot Object;
	while (true)
	{
		Sleep(1);
		if (GetKeyState(VK_SPACE))
		{
			Object.Shooting();
		}
	}
	return 0;
};