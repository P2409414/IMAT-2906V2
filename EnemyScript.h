#include <Windows.h>
#pragma once
using namespace std;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;
class EnemyScript
{
    public Transform pointA; //!< Creation of the first point to travel to.
    public Transform pointB; //!< Creation of the second point to travel to.
    public Rigidbody2D rb; //!< Creation of the rigidbody variable.
    public int point; //!< Creation of an int to know which point is being travelled to by number instead of by position.
    public Vector3 currentTarget; //!< Creation of a vector3 to store the currenttarget position.
    public float speed; //!< Creation of a float for the speed the enemy will move at.
    public float allowedspeed; //!< Creation of a float for the maximum speed the enemy can move at.
    public float delayStart; //!< Creation of a float to have a set delay for movement after reaching a point.
    public float delayTimer; //!< Creation of a float to keep the current delay time.
public:void FixedUpdate()
{
    Collider2D[] colliders = Physics2D.OverlapCircleAll(rb.position, 5f, LayerMask.GetMask("Character")); //!< Creating an array that looks for gameobjects within the Character layer
    if (colliders.Length == 0)
    {
        if (currentTarget == pointA.position && transform.localScale.x == 1)
        {
            Vector3 theScale = transform.localScale;
            theScale.x = -1;
            transform.localScale = theScale;  //!< Changes the localscale of the enemy to flip it
        }
        if (currentTarget == pointB.position && transform.localScale.x == -1)
        {
            Vector3 theScale = transform.localScale;
            theScale.x = 1;
            transform.localScale = theScale;  //!< Changes the localscale of the enemy to flip it
        }
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
                else if (point == 2)
                {
                    point = 1;
                    currentTarget = pointB.position;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < colliders.Length; i++)
        {
            if (colliders[i].gameObject != gameObject && colliders[i].gameObject.name == "Soldier")
            {
                print("Shooting at Player");
            }
            else
            {
                print("Enemy Hit");
            }
        }
    }
}
};

