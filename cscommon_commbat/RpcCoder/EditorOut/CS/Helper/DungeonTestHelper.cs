#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class DungeonRpcEnterAskWraperHelper
{
	public int DungeonId;
	public List<int> HeroList;
	public int PVPType;
}
[System.Serializable]
public class DungeonRpcBeginPVEAskWraperHelper
{
	public int DungeonId;
}
[System.Serializable]
public class DungeonRpcOpenNotifyWraperHelper
{
	public string DungeonKey;
	public string Host;
	public int Port;
	public int RandSeed;
	public int Side;
	public List<int> LeftSideList;
	public List<int> RightSideList;
	public int PVPType;
}



public class DungeonTestHelper : MonoBehaviour
{
	public DungeonRpcEnterAskWraperHelper DungeonRpcEnterAskWraperVar;
	public DungeonRpcBeginPVEAskWraperHelper DungeonRpcBeginPVEAskWraperVar;
	public DungeonRpcOpenNotifyWraperHelper DungeonRpcOpenNotifyWraperVar;


	public void TestEnter()
	{
		DungeonRPC.Instance.Enter(DungeonRpcEnterAskWraperVar.DungeonId,DungeonRpcEnterAskWraperVar.HeroList,DungeonRpcEnterAskWraperVar.PVPType,delegate(object obj){});
	}
	public void TestBeginPVE()
	{
		DungeonRPC.Instance.BeginPVE(DungeonRpcBeginPVEAskWraperVar.DungeonId,delegate(object obj){});
	}


}

[CustomEditor(typeof(DungeonTestHelper))]
public class DungeonTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Enter"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestEnter();
		}
		if (GUILayout.Button("BeginPVE"))
		{
			DungeonTestHelper rpc = target as DungeonTestHelper;
			if( rpc ) rpc.TestBeginPVE();
		}


    }

}
#endif