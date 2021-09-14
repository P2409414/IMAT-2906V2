
#include "EnemyScript.h"
#include <Windows.h>
#include <stdlib.h>
#pragma once
using namespace std;

int main() {
    EnemyScript Object;
    Object.pointA = this.transform.parent.Find("PointA").transform; //!< Finding the position of the first point
    Object.pointB = this.transform.parent.Find("PointB").transform; //!< Finding the position of the second point
    Object.point = 1; //!< Setting the value of point to 1 to know which is being travelled to
    Object.speed = 6f; //!< Setting the speed of the enemy
    Object.allowedspeed = speed * Time.deltaTime; //!< Setting the allowed speed depending on the deltatime
    Object.currentTarget = pointB.position; //!< Setting the current point that is being moved to
    Object.delayTimer = 2f; //!< Setting the delay between reaching a point and moving to the next
    Object.rb = GetComponent<Rigidbody2D>(); //!< Finding the rigidbody attached to the gameObject

    while (true) {
        Sleep(1);
        Object.FixedUpdate();
    }
};

