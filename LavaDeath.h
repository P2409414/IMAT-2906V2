#include <Windows.h>
#pragma once
using namespace std;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;
class LavaDeath
{
    public GameObject StartPos;
    public GameObject Blackout;
    public Text Lives;
    public GameObject CameraEnd;
    private int LivesValue = 3;
    private void OnTriggerEnter2D(Collider2D other)  //!< On the player touching the lava the repawn coroutine is started or if player is out of lives player is destroyed and game is ended.
    {
        if (LivesValue != 1)
        {
            StartCoroutine(Respawn(other.gameObject));
        }
        else
        {
            CameraEnd.SetActive(true);
            Destroy(other.gameObject);
        }
    }

    IEnumerator Respawn(GameObject rb) //!< IEnumerator used to allow for a timer to be used for fading the screen and moving the character as well as freezing until screen returns.
    {
        rb.GetComponent<Rigidbody2D>().constraints = RigidbodyConstraints2D.FreezeAll;
        for (int i = 0; i < 10; i++)
        {
            Blackout.GetComponent<SpriteRenderer>().color = Blackout.GetComponent<SpriteRenderer>().color + new Color(0, 0, 0, 0.1f);
            yield return new WaitForSeconds(0.1f);
        }
        rb.transform.position = StartPos.transform.position;
        for (int i = 0; i < 10; i++)
        {
            Blackout.GetComponent<SpriteRenderer>().color = Blackout.GetComponent<SpriteRenderer>().color - new Color(0, 0, 0, 0.1f);
            yield return new WaitForSeconds(0.1f);
        }
        rb.GetComponent<Rigidbody2D>().constraints = RigidbodyConstraints2D.FreezeRotation;
        LivesValue = LivesValue - 1;
        Lives.text = "Lives: " + LivesValue;
    }

    private void OnTriggerExit2D(Collider2D other)
    {
        other.transform.parent = null;
    }
}
};

