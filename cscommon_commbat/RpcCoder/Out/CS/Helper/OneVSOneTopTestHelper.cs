﻿#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class OneVSOneTopTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(OneVSOneTopTestHelper))]
public class OneVSOneTopTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif