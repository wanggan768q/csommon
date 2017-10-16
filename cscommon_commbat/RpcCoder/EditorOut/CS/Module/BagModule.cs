/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleBag.cs
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


public class BagRPC
{
	public const int ModuleId = 14;
	
	public const int RPC_CODE_BAG_SYNCDATA_REQUEST = 1451;
	public const int RPC_CODE_BAG_SELL_REQUEST = 1452;
	public const int RPC_CODE_BAG_DECOMPOSE_REQUEST = 1453;
	public const int RPC_CODE_BAG_USE_REQUEST = 1454;

	
	private static BagRPC m_Instance = null;
	public static BagRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BagRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, BagData.Instance.UpdateField );
		


		return true;
	}


	/**
	*背包-->同步背包数据 RPC请求
	*/
	public void SyncData(ReplyHandler replyCB)
	{
		BagRpcSyncDataAskWraper askPBWraper = new BagRpcSyncDataAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_SYNCDATA_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcSyncDataReplyWraper replyPBWraper = new BagRpcSyncDataReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*背包-->出售 RPC请求
	*/
	public void Sell(int ItemID, int Pos, int Num, ReplyHandler replyCB)
	{
		BagRpcSellAskWraper askPBWraper = new BagRpcSellAskWraper();
		askPBWraper.ItemID = ItemID;
		askPBWraper.Pos = Pos;
		askPBWraper.Num = Num;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_SELL_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcSellReplyWraper replyPBWraper = new BagRpcSellReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*背包-->分解 RPC请求
	*/
	public void Decompose(int ItemID, int Pos, int Num, ReplyHandler replyCB)
	{
		BagRpcDecomposeAskWraper askPBWraper = new BagRpcDecomposeAskWraper();
		askPBWraper.ItemID = ItemID;
		askPBWraper.Pos = Pos;
		askPBWraper.Num = Num;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_DECOMPOSE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcDecomposeReplyWraper replyPBWraper = new BagRpcDecomposeReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}

	/**
	*背包-->物品使用 RPC请求
	*/
	public void Use(int ItemID, int Pos, ReplyHandler replyCB)
	{
		BagRpcUseAskWraper askPBWraper = new BagRpcUseAskWraper();
		askPBWraper.ItemID = ItemID;
		askPBWraper.Pos = Pos;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BAG_USE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BagRpcUseReplyWraper replyPBWraper = new BagRpcUseReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}





}

public class BagData
{
	public enum SyncIdE
	{
 		GRIDARRAY                                  = 1401,  //格子数组

	}
	
	private static BagData m_Instance = null;
	public static BagData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BagData();
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
			case SyncIdE.GRIDARRAY:
				if(Index < 0){ m_Instance.ClearGridArray(); break; }
				if (Index >= m_Instance.SizeGridArray())
				{
					int Count = Index - m_Instance.SizeGridArray() + 1;
					for (int i = 0; i < Count; i++)
						m_Instance.AddGridArray(new BagGridInfoWraperV1());
				}
				m_Instance.GetGridArray(Index).FromMemoryStream(new MemoryStream(updateBuffer));
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
			Debug.Log("BagData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  

	//构造函数
	public BagData()
	{
		m_GridArray = new List<BagGridInfoWraperV1>();

	}

 	//转化成Protobuffer类型函数
	public BagPackageDataV1 ToPB()
	{
		BagPackageDataV1 v = new BagPackageDataV1();
		for (int i=0; i<(int)m_GridArray.Count; i++)
			v.GridArray.Add( m_GridArray[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagPackageDataV1 v)
	{
		m_GridArray.Clear();
		for( int i=0; i<v.GridArray.Count; i++)
			m_GridArray.Add( new BagGridInfoWraperV1());
		for( int i=0; i<v.GridArray.Count; i++)
			m_GridArray[i].FromPB(v.GridArray[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagPackageDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagPackageDataV1 pb = ProtoBuf.Serializer.Deserialize<BagPackageDataV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//格子数组
	public List<BagGridInfoWraperV1> m_GridArray;
	public int SizeGridArray()
	{
		return m_GridArray.Count;
	}
	public List<BagGridInfoWraperV1> GetGridArray()
	{
		return m_GridArray;
	}
	public BagGridInfoWraperV1 GetGridArray(int Index)
	{
		if(Index<0 || Index>=(int)m_GridArray.Count)
			return new BagGridInfoWraperV1();
		return m_GridArray[Index];
	}
	public void SetGridArray( List<BagGridInfoWraperV1> v )
	{
		m_GridArray=v;
	}
	public void SetGridArray( int Index, BagGridInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_GridArray.Count)
			return;
		m_GridArray[Index] = v;
	}
	public void AddGridArray( BagGridInfoWraperV1 v )
	{
		m_GridArray.Add(v);
	}
	public void ClearGridArray( )
	{
		m_GridArray.Clear();
	}



}
