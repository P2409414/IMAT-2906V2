#include <Windows.h>
#pragma once
using namespace std;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
class Pickup
{
    private void OnTriggerEnter2D(Collider2D other)//!< On the player touching the object the gameobject is set to false and the player weapon is set to true.
    {
        this.gameObject.SetActive(false);
        other.gameObject.transform.Find("Weapons_0").gameObject.SetActive(true);
    }
};

