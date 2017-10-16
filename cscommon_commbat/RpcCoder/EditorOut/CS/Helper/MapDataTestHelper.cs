#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class MapDataTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(MapDataTestHelper))]
public class MapDataTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif