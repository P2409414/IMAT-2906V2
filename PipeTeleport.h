#include <Windows.h>
#pragma once
using namespace std;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;
class PipeTeleport
{
    public GameObject TeleportPos;
    public:float UporDown = 0f;
    private void OnTriggerStay2D(Collider2D other) //!< If the player is on the pipe and presses down it will activate this and change their position to just above another pipe.
    {
        if (UporDown < 0)
        {
            other.transform.position = TeleportPos.transform.position;
        }
    }
};

