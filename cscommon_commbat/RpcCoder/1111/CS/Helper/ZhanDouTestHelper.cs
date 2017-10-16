#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class ZhanDouRpcMoveAskWraperHelper
{
}
[System.Serializable]
public class ZhanDouRpcTalkNotifyWraperHelper
{
}



public class ZhanDouTestHelper : MonoBehaviour
{
	public ZhanDouRpcMoveAskWraperHelper ZhanDouRpcMoveAskWraperVar;
	public ZhanDouRpcTalkNotifyWraperHelper ZhanDouRpcTalkNotifyWraperVar;


	public void TestMove()
	{
		ZhanDouRPC.Instance.Move(delegate(object obj){});
	}


}

[CustomEditor(typeof(ZhanDouTestHelper))]
public class ZhanDouTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Move"))
		{
			ZhanDouTestHelper rpc = target as ZhanDouTestHelper;
			if( rpc ) rpc.TestMove();
		}


    }

}
#endif