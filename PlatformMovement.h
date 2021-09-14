#include <Windows.h>
#pragma once
using namespace std;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;
class PlatformMovement
{
    private Transform pointA; //!< Creation of the first point to travel to.
    private Transform pointB; //!< Creation of the second point to travel to.
    private int point; //!< Creation of an int to know which point is being travelled to by number instead of by position.
    private Vector3 currentTarget; //!< Creation of a vector3 to store the currenttarget position.
    private float speed; //!< Creation of a float for the speed the enemy will move at.
    private float allowedspeed; //!< Creation of a float for the maximum speed the enemy can move at.
    private float delayStart; //!< Creation of a float to have a set delay for movement after reaching a point.
    public float delayTimer; //!< Creation of a float to keep the current delay time.
    public:void FixedUpdate()
    {
        if (transform.position != currentTarget)
        {
            transform.position += ((currentTarget - transform.position) / (currentTarget - transform.position).magnitude) * speed * Time.deltaTime;
            if ((currentTarget - transform.position).magnitude < allowedspeed)
            {
                transform.position = currentTarget;
                delayStart = Time.time;
            }
        }
        else
        {
            if (Time.time - delayStart > delayTimer)
            {
                if (point == 1)
                {
                    point = 2;
                    currentTarget = pointA.position;
                }
                else
                {
                    point = 1;
                    currentTarget = pointB.position;
                }
            }
        }
    };

    private:void OnTriggerEnter2D(Collider2D other)
    {
        other.transform.parent = transform;
    };

    private:void OnTriggerExit2D(Collider2D other)
    {
        other.transform.parent = null;
    };
};

