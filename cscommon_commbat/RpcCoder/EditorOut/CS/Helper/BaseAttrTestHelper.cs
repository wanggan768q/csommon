#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class BaseAttrRpcSyncDataAskWraperHelper
{
}
[System.Serializable]
public class BaseAttrRpcGetRankRewardAskWraperHelper
{
}
[System.Serializable]
public class BaseAttrRpcUpGradeRankAskWraperHelper
{
}



public class BaseAttrTestHelper : MonoBehaviour
{
	public BaseAttrRpcSyncDataAskWraperHelper BaseAttrRpcSyncDataAskWraperVar;
	public BaseAttrRpcGetRankRewardAskWraperHelper BaseAttrRpcGetRankRewardAskWraperVar;
	public BaseAttrRpcUpGradeRankAskWraperHelper BaseAttrRpcUpGradeRankAskWraperVar;


	public void TestSyncData()
	{
		BaseAttrRPC.Instance.SyncData(delegate(object obj){});
	}
	public void TestGetRankReward()
	{
		BaseAttrRPC.Instance.GetRankReward(delegate(object obj){});
	}
	public void TestUpGradeRank()
	{
		BaseAttrRPC.Instance.UpGradeRank(delegate(object obj){});
	}


}

[CustomEditor(typeof(BaseAttrTestHelper))]
public class BaseAttrTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SyncData"))
		{
			BaseAttrTestHelper rpc = target as BaseAttrTestHelper;
			if( rpc ) rpc.TestSyncData();
		}
		if (GUILayout.Button("GetRankReward"))
		{
			BaseAttrTestHelper rpc = target as BaseAttrTestHelper;
			if( rpc ) rpc.TestGetRankReward();
		}
		if (GUILayout.Button("UpGradeRank"))
		{
			BaseAttrTestHelper rpc = target as BaseAttrTestHelper;
			if( rpc ) rpc.TestUpGradeRank();
		}


    }

}
#endif