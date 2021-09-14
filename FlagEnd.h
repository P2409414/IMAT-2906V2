#include <Windows.h>
#pragma once
using namespace std;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;
class FlagEnd
{
    public GameObject CameraEnd;
    private void OnTriggerEnter2D(Collider2D other)
    {
        CameraEnd.SetActive(true); //!< Changes active camera and destroys player
        Destroy(other.gameObject);
    }

    private void OnTriggerExit2D(Collider2D other)
    {
        other.transform.parent = null;
    }
};

