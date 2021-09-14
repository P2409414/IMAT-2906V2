#include <Windows.h>
#pragma once
using namespace std;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;

class Shoot {
public:
    GameObject Bullet;  //!< Creation of variables used to instantiate the bullets
    GameObject BulletSpawn;
    Transform MainScene;
private:
    GameObject Bullets;

public:void Shooting() {
    if (gameObject.transform.parent.transform.localScale.x == 1)
    {
        Bullets = Instantiate(Bullet, BulletSpawn.transform.position, new Quaternion(0, 0, 0, 0), MainScene);  //!< If the player is facing right the bullet will move right
        Bullets.GetComponent<Rigidbody2D>().velocity = new Vector2(40, 0);
    }
    else
    {
        Bullets = Instantiate(Bullet, BulletSpawn.transform.position, new Quaternion(0, 0, 0, 0), MainScene);  //!< If the player is facing left the bullet will move left.
        Bullets.GetComponent<Rigidbody2D>().velocity = new Vector2(-40, 0);
    }
};
};