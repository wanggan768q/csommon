/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleZhanDou.cs
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


public class ZhanDouRPC
{
	public const int ModuleId = 1;
	
	public const int RPC_CODE_ZHANDOU_MOVE_REQUEST = 151;
	public const int RPC_CODE_ZHANDOU_TALK_NOTIFY = 152;

	
	private static ZhanDouRPC m_Instance = null;
	public static ZhanDouRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ZhanDouRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, ZhanDouData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_ZHANDOU_TALK_NOTIFY, TalkCB);


		return true;
	}


	/**
	*战斗-->zou RPC请求
	*/
	public void Move(ReplyHandler replyCB)
	{
		ZhanDouRpcMoveAskWraper askPBWraper = new ZhanDouRpcMoveAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_ZHANDOU_MOVE_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			ZhanDouRpcMoveReplyWraper replyPBWraper = new ZhanDouRpcMoveReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*战斗-->聊天 服务器通知回调
	*/
	public static void TalkCB( ModMessage notifyMsg )
	{
		ZhanDouRpcTalkNotifyWraper notifyPBWraper = new ZhanDouRpcTalkNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( TalkCBDelegate != null )
			TalkCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback TalkCBDelegate = null;



}

public class ZhanDouData
{
	public enum SyncIdE
	{

	}
	
	private static ZhanDouData m_Instance = null;
	public static ZhanDouData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new ZhanDouData();
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
			Ex.Logger.Log("ZhanDouData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  

	//构造函数
	public ZhanDouData()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ZhanDouUserDataV1 ToPB()
	{
		ZhanDouUserDataV1 v = new ZhanDouUserDataV1();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ZhanDouUserDataV1 v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ZhanDouUserDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ZhanDouUserDataV1 pb = ProtoBuf.Serializer.Deserialize<ZhanDouUserDataV1>(protoMS);
		FromPB(pb);
		return true;
	}




}
