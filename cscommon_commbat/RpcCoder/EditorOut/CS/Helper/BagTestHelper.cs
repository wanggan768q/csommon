#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class BagRpcSyncDataAskWraperHelper
{
}
[System.Serializable]
public class BagRpcSellAskWraperHelper
{
	public int ItemID;
	public int Pos;
	public int Num;
}
[System.Serializable]
public class BagRpcDecomposeAskWraperHelper
{
	public int ItemID;
	public int Pos;
	public int Num;
}
[System.Serializable]
public class BagRpcUseAskWraperHelper
{
	public int ItemID;
	public int Pos;
}



public class BagTestHelper : MonoBehaviour
{
	public BagRpcSyncDataAskWraperHelper BagRpcSyncDataAskWraperVar;
	public BagRpcSellAskWraperHelper BagRpcSellAskWraperVar;
	public BagRpcDecomposeAskWraperHelper BagRpcDecomposeAskWraperVar;
	public BagRpcUseAskWraperHelper BagRpcUseAskWraperVar;


	public void TestSyncData()
	{
		BagRPC.Instance.SyncData(delegate(object obj){});
	}
	public void TestSell()
	{
		BagRPC.Instance.Sell(BagRpcSellAskWraperVar.ItemID,BagRpcSellAskWraperVar.Pos,BagRpcSellAskWraperVar.Num,delegate(object obj){});
	}
	public void TestDecompose()
	{
		BagRPC.Instance.Decompose(BagRpcDecomposeAskWraperVar.ItemID,BagRpcDecomposeAskWraperVar.Pos,BagRpcDecomposeAskWraperVar.Num,delegate(object obj){});
	}
	public void TestUse()
	{
		BagRPC.Instance.Use(BagRpcUseAskWraperVar.ItemID,BagRpcUseAskWraperVar.Pos,delegate(object obj){});
	}


}

[CustomEditor(typeof(BagTestHelper))]
public class BagTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SyncData"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestSyncData();
		}
		if (GUILayout.Button("Sell"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestSell();
		}
		if (GUILayout.Button("Decompose"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestDecompose();
		}
		if (GUILayout.Button("Use"))
		{
			BagTestHelper rpc = target as BagTestHelper;
			if( rpc ) rpc.TestUse();
		}


    }

}
#endif