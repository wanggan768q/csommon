#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class MMOMapDataTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(MMOMapDataTestHelper))]
public class MMOMapDataTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif