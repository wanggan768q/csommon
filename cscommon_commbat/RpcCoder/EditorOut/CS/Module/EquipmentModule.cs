/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleEquipment.cs
Author:
Description:
Version:	  1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


public class EquipmentRPC
{
	public const int ModuleId = 7;
	
	public const int RPC_CODE_EQUIPMENT_SYNCDATA_REQUEST = 751;
	public const int RPC_CODE_EQUIPMENT_WEAR_REQUEST = 752;
	public const int RPC_CODE_EQUIPMENT_ENHANCE_REQUEST = 753;
	public const int RPC_CODE_EQUIPMENT_UPGRADESTAR_REQUEST = 754;
	public const int RPC_CODE_EQUIPMENT_EQUIPEVOLVE_REQUEST = 755;
	public const int RPC_CODE_EQUIPMENT_DECOMPOSE_REQUEST = 756;
	public const int RPC_CODE_EQUIPMENT_ENHANCEBREAK_REQUEST = 757;
	public const int RPC_CODE_EQUIPMENT_STARBREAK_REQUEST = 758;

	
	private static EquipmentRPC m_Instance = null;
	public static EquipmentRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EquipmentRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, EquipmentData.Instance.UpdateField );
		


		return true;
	}


	/**
	*装备-->同步装备数据 RPC请求
	*/
	public void SyncData(ReplyHandler replyCB)
	{
		EquipmentRpcSyncDataAskWraper askPBWraper = new EquipmentRpcSyncDataAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_SYNCDATA_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcSyncDataReplyWraper replyPBWraper = new EquipmentRpcSyncDataReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->穿戴装备 RPC请求
	*/
	public void Wear(string EquipID, int Pos, ReplyHandler replyCB)
	{
		EquipmentRpcWearAskWraper askPBWraper = new EquipmentRpcWearAskWraper();
		askPBWraper.EquipID = EquipID;
		askPBWraper.Pos = Pos;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_WEAR_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcWearReplyWraper replyPBWraper = new EquipmentRpcWearReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->强化 RPC请求
	*/
	public void Enhance(int Pos, string EquipID, int Type, ReplyHandler replyCB)
	{
		EquipmentRpcEnhanceAskWraper askPBWraper = new EquipmentRpcEnhanceAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.EquipID = EquipID;
		askPBWraper.Type = Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_ENHANCE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEnhanceReplyWraper replyPBWraper = new EquipmentRpcEnhanceReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->装备升星 RPC请求
	*/
	public void UpgradeStar(int Pos, string EquipID, int Type, int DiamondProtect, ReplyHandler replyCB)
	{
		EquipmentRpcUpgradeStarAskWraper askPBWraper = new EquipmentRpcUpgradeStarAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.EquipID = EquipID;
		askPBWraper.Type = Type;
		askPBWraper.DiamondProtect = DiamondProtect;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_UPGRADESTAR_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcUpgradeStarReplyWraper replyPBWraper = new EquipmentRpcUpgradeStarReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->装备进化 RPC请求
	*/
	public void EquipEvolve(int Pos, string EquipID, ReplyHandler replyCB)
	{
		EquipmentRpcEquipEvolveAskWraper askPBWraper = new EquipmentRpcEquipEvolveAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.EquipID = EquipID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_EQUIPEVOLVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEquipEvolveReplyWraper replyPBWraper = new EquipmentRpcEquipEvolveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->分解 RPC请求
	*/
	public void Decompose(int Pos, int Num, string EquipID, ReplyHandler replyCB)
	{
		EquipmentRpcDecomposeAskWraper askPBWraper = new EquipmentRpcDecomposeAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.Num = Num;
		askPBWraper.EquipID = EquipID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_DECOMPOSE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcDecomposeReplyWraper replyPBWraper = new EquipmentRpcDecomposeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->强化突破 RPC请求
	*/
	public void EnhanceBreak(int Pos, string EquipID, ReplyHandler replyCB)
	{
		EquipmentRpcEnhanceBreakAskWraper askPBWraper = new EquipmentRpcEnhanceBreakAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.EquipID = EquipID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_ENHANCEBREAK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcEnhanceBreakReplyWraper replyPBWraper = new EquipmentRpcEnhanceBreakReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*装备-->星级突破 RPC请求
	*/
	public void StarBreak(int Pos, string EquipID, ReplyHandler replyCB)
	{
		EquipmentRpcStarBreakAskWraper askPBWraper = new EquipmentRpcStarBreakAskWraper();
		askPBWraper.Pos = Pos;
		askPBWraper.EquipID = EquipID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_EQUIPMENT_STARBREAK_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			EquipmentRpcStarBreakReplyWraper replyPBWraper = new EquipmentRpcStarBreakReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class EquipmentData
{
	public enum SyncIdE
	{
 		EQUIPARRAY                                 = 701,  //装备数组
 		WEAREQUIP                                  = 702,  //装备穿着
 		ENHANCERANK                                = 703,  //共鸣强化等阶
 		STARRANK                                   = 704,  //共鸣星阶

	}
	
	private static EquipmentData m_Instance = null;
	public static EquipmentData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EquipmentData();
			}
			return m_Instance;

		}
	}
	

	public void UpdateField(int Id, int Index, byte[] buff, int start, int len )
	{
		SyncIdE SyncId = (SyncIdE)Id;
		byte[]  updateBuffer = new byte[len];
		Array.Copy(buff, start, updateBuffer, 0, len);
		int  iValue = 0;
		long lValue = 0;

		switch (SyncId)
		{
			case SyncIdE.EQUIPARRAY:
				if(Index < 0){ m_Instance.ClearEquipArray(); break; }
				if (Index >= m_Instance.SizeEquipArray())
				{
					int Count = Index - m_Instance.SizeEquipArray() + 1;
					for (int i = 0; i < Count; i++)
						m_Instance.AddEquipArray(new EquipmentEquipInfoWraperV1());
				}
				m_Instance.GetEquipArray(Index).FromMemoryStream(new MemoryStream(updateBuffer));
				break;
			case SyncIdE.WEAREQUIP:
				if(Index < 0){ m_Instance.ClearWearEquip(); break; }
				if (Index >= m_Instance.SizeWearEquip())
				{
					int Count = Index - m_Instance.SizeWearEquip() + 1;
					for (int i = 0; i < Count; i++)
						m_Instance.AddWearEquip(new EquipmentEquipInfoWraperV1());
				}
				m_Instance.GetWearEquip(Index).FromMemoryStream(new MemoryStream(updateBuffer));
				break;
			case SyncIdE.ENHANCERANK:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.EnhanceRank = iValue;
				break;
			case SyncIdE.STARRANK:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.StarRank = iValue;
				break;

			default:
				break;
		}

		try
		{
			if (NotifySyncValueChanged!=null)
				NotifySyncValueChanged(Id, Index);
		}
		catch
		{
			Debug.Log("EquipmentData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  

	//构造函数
	public EquipmentData()
	{
		m_EquipArray = new List<EquipmentEquipInfoWraperV1>();
		m_WearEquip = new List<EquipmentEquipInfoWraperV1>();
		 m_EnhanceRank = 0;
		 m_StarRank = 0;

	}

 	//转化成Protobuffer类型函数
	public EquipmentEquipDataV1 ToPB()
	{
		EquipmentEquipDataV1 v = new EquipmentEquipDataV1();
		for (int i=0; i<(int)m_EquipArray.Count; i++)
			v.EquipArray.Add( m_EquipArray[i].ToPB());
		for (int i=0; i<(int)m_WearEquip.Count; i++)
			v.WearEquip.Add( m_WearEquip[i].ToPB());
		v.EnhanceRank = m_EnhanceRank;
		v.StarRank = m_StarRank;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(EquipmentEquipDataV1 v)
	{
		m_EquipArray.Clear();
		for( int i=0; i<v.EquipArray.Count; i++)
			m_EquipArray.Add( new EquipmentEquipInfoWraperV1());
		for( int i=0; i<v.EquipArray.Count; i++)
			m_EquipArray[i].FromPB(v.EquipArray[i]);
		m_WearEquip.Clear();
		for( int i=0; i<v.WearEquip.Count; i++)
			m_WearEquip.Add( new EquipmentEquipInfoWraperV1());
		for( int i=0; i<v.WearEquip.Count; i++)
			m_WearEquip[i].FromPB(v.WearEquip[i]);
		m_EnhanceRank = v.EnhanceRank;
		m_StarRank = v.StarRank;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<EquipmentEquipDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		EquipmentEquipDataV1 pb = ProtoBuf.Serializer.Deserialize<EquipmentEquipDataV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//装备数组
	public List<EquipmentEquipInfoWraperV1> m_EquipArray;
	public int SizeEquipArray()
	{
		return m_EquipArray.Count;
	}
	public List<EquipmentEquipInfoWraperV1> GetEquipArray()
	{
		return m_EquipArray;
	}
	public EquipmentEquipInfoWraperV1 GetEquipArray(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipArray.Count)
			return new EquipmentEquipInfoWraperV1();
		return m_EquipArray[Index];
	}
	public void SetEquipArray( List<EquipmentEquipInfoWraperV1> v )
	{
		m_EquipArray=v;
	}
	public void SetEquipArray( int Index, EquipmentEquipInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_EquipArray.Count)
			return;
		m_EquipArray[Index] = v;
	}
	public void AddEquipArray( EquipmentEquipInfoWraperV1 v )
	{
		m_EquipArray.Add(v);
	}
	public void ClearEquipArray( )
	{
		m_EquipArray.Clear();
	}
	//装备穿着
	public List<EquipmentEquipInfoWraperV1> m_WearEquip;
	public int SizeWearEquip()
	{
		return m_WearEquip.Count;
	}
	public List<EquipmentEquipInfoWraperV1> GetWearEquip()
	{
		return m_WearEquip;
	}
	public EquipmentEquipInfoWraperV1 GetWearEquip(int Index)
	{
		if(Index<0 || Index>=(int)m_WearEquip.Count)
			return new EquipmentEquipInfoWraperV1();
		return m_WearEquip[Index];
	}
	public void SetWearEquip( List<EquipmentEquipInfoWraperV1> v )
	{
		m_WearEquip=v;
	}
	public void SetWearEquip( int Index, EquipmentEquipInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_WearEquip.Count)
			return;
		m_WearEquip[Index] = v;
	}
	public void AddWearEquip( EquipmentEquipInfoWraperV1 v )
	{
		m_WearEquip.Add(v);
	}
	public void ClearWearEquip( )
	{
		m_WearEquip.Clear();
	}
	//共鸣强化等阶
	public int m_EnhanceRank;
	public int EnhanceRank
	{
		get { return m_EnhanceRank;}
		set { m_EnhanceRank = value; }
	}
	//共鸣星阶
	public int m_StarRank;
	public int StarRank
	{
		get { return m_StarRank;}
		set { m_StarRank = value; }
	}



}
