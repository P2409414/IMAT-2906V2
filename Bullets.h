#include <Windows.h>
#pragma once
using namespace std;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;
class Bullets
{
	public Rigidbody2D rb; //!< Creation of rigidbody variable
    public:void FixedUpdate()
    {
    Collider2D[] colliders = Physics2D.OverlapCircleAll(rb.position, 0.2f, ~0); //!< Creating an array of colliders that are nearby
    for (int i = 0; i < colliders.Length; i++)
    {
        if (colliders[i].gameObject != gameObject)
        {
            Destroy(gameObject);  //!< Destroy the bullet
        }
    }
    }
};

