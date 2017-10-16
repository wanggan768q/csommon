#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class EquipmentRpcSyncDataAskWraperHelper
{
}
[System.Serializable]
public class EquipmentRpcWearAskWraperHelper
{
	public string EquipID;
	public int Pos;
}
[System.Serializable]
public class EquipmentRpcEnhanceAskWraperHelper
{
	public int Pos;
	public string EquipID;
	public int Type;
}
[System.Serializable]
public class EquipmentRpcUpgradeStarAskWraperHelper
{
	public int Pos;
	public string EquipID;
	public int Type;
	public int DiamondProtect;
}
[System.Serializable]
public class EquipmentRpcEquipEvolveAskWraperHelper
{
	public int Pos;
	public string EquipID;
}
[System.Serializable]
public class EquipmentRpcDecomposeAskWraperHelper
{
	public int Pos;
	public int Num;
	public string EquipID;
}
[System.Serializable]
public class EquipmentRpcEnhanceBreakAskWraperHelper
{
	public int Pos;
	public string EquipID;
}
[System.Serializable]
public class EquipmentRpcStarBreakAskWraperHelper
{
	public int Pos;
	public string EquipID;
}



public class EquipmentTestHelper : MonoBehaviour
{
	public EquipmentRpcSyncDataAskWraperHelper EquipmentRpcSyncDataAskWraperVar;
	public EquipmentRpcWearAskWraperHelper EquipmentRpcWearAskWraperVar;
	public EquipmentRpcEnhanceAskWraperHelper EquipmentRpcEnhanceAskWraperVar;
	public EquipmentRpcUpgradeStarAskWraperHelper EquipmentRpcUpgradeStarAskWraperVar;
	public EquipmentRpcEquipEvolveAskWraperHelper EquipmentRpcEquipEvolveAskWraperVar;
	public EquipmentRpcDecomposeAskWraperHelper EquipmentRpcDecomposeAskWraperVar;
	public EquipmentRpcEnhanceBreakAskWraperHelper EquipmentRpcEnhanceBreakAskWraperVar;
	public EquipmentRpcStarBreakAskWraperHelper EquipmentRpcStarBreakAskWraperVar;


	public void TestSyncData()
	{
		EquipmentRPC.Instance.SyncData(delegate(object obj){});
	}
	public void TestWear()
	{
		EquipmentRPC.Instance.Wear(EquipmentRpcWearAskWraperVar.EquipID,EquipmentRpcWearAskWraperVar.Pos,delegate(object obj){});
	}
	public void TestEnhance()
	{
		EquipmentRPC.Instance.Enhance(EquipmentRpcEnhanceAskWraperVar.Pos,EquipmentRpcEnhanceAskWraperVar.EquipID,EquipmentRpcEnhanceAskWraperVar.Type,delegate(object obj){});
	}
	public void TestUpgradeStar()
	{
		EquipmentRPC.Instance.UpgradeStar(EquipmentRpcUpgradeStarAskWraperVar.Pos,EquipmentRpcUpgradeStarAskWraperVar.EquipID,EquipmentRpcUpgradeStarAskWraperVar.Type,EquipmentRpcUpgradeStarAskWraperVar.DiamondProtect,delegate(object obj){});
	}
	public void TestEquipEvolve()
	{
		EquipmentRPC.Instance.EquipEvolve(EquipmentRpcEquipEvolveAskWraperVar.Pos,EquipmentRpcEquipEvolveAskWraperVar.EquipID,delegate(object obj){});
	}
	public void TestDecompose()
	{
		EquipmentRPC.Instance.Decompose(EquipmentRpcDecomposeAskWraperVar.Pos,EquipmentRpcDecomposeAskWraperVar.Num,EquipmentRpcDecomposeAskWraperVar.EquipID,delegate(object obj){});
	}
	public void TestEnhanceBreak()
	{
		EquipmentRPC.Instance.EnhanceBreak(EquipmentRpcEnhanceBreakAskWraperVar.Pos,EquipmentRpcEnhanceBreakAskWraperVar.EquipID,delegate(object obj){});
	}
	public void TestStarBreak()
	{
		EquipmentRPC.Instance.StarBreak(EquipmentRpcStarBreakAskWraperVar.Pos,EquipmentRpcStarBreakAskWraperVar.EquipID,delegate(object obj){});
	}


}

[CustomEditor(typeof(EquipmentTestHelper))]
public class EquipmentTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SyncData"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestSyncData();
		}
		if (GUILayout.Button("Wear"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestWear();
		}
		if (GUILayout.Button("Enhance"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEnhance();
		}
		if (GUILayout.Button("UpgradeStar"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestUpgradeStar();
		}
		if (GUILayout.Button("EquipEvolve"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipEvolve();
		}
		if (GUILayout.Button("Decompose"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestDecompose();
		}
		if (GUILayout.Button("EnhanceBreak"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEnhanceBreak();
		}
		if (GUILayout.Button("StarBreak"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestStarBreak();
		}


    }

}
#endif