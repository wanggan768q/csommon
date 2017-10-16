
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperRpcPBZhanDou.cs
Author:
Description:
Version:      1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//zou请求封装类
[System.Serializable]
public class ZhanDouRpcMoveAskWraper
{

	//构造函数
	public ZhanDouRpcMoveAskWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ZhanDouRpcMoveAsk ToPB()
	{
		ZhanDouRpcMoveAsk v = new ZhanDouRpcMoveAsk();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ZhanDouRpcMoveAsk v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ZhanDouRpcMoveAsk>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ZhanDouRpcMoveAsk pb = ProtoBuf.Serializer.Deserialize<ZhanDouRpcMoveAsk>(protoMS);
		FromPB(pb);
		return true;
	}



};
//zou回应封装类
[System.Serializable]
public class ZhanDouRpcMoveReplyWraper
{

	//构造函数
	public ZhanDouRpcMoveReplyWraper()
	{
		 m_Result = -9999;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Result = -9999;

	}

 	//转化成Protobuffer类型函数
	public ZhanDouRpcMoveReply ToPB()
	{
		ZhanDouRpcMoveReply v = new ZhanDouRpcMoveReply();
		v.Result = m_Result;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ZhanDouRpcMoveReply v)
	{
        if (v == null)
            return;
		m_Result = v.Result;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ZhanDouRpcMoveReply>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ZhanDouRpcMoveReply pb = ProtoBuf.Serializer.Deserialize<ZhanDouRpcMoveReply>(protoMS);
		FromPB(pb);
		return true;
	}

	//返回结果
	public int m_Result;
	public int Result
	{
		get { return m_Result;}
		set { m_Result = value; }
	}


};
//聊天通知封装类
[System.Serializable]
public class ZhanDouRpcTalkNotifyWraper
{

	//构造函数
	public ZhanDouRpcTalkNotifyWraper()
	{

	}

	//重置函数
	public void ResetWraper()
	{

	}

 	//转化成Protobuffer类型函数
	public ZhanDouRpcTalkNotify ToPB()
	{
		ZhanDouRpcTalkNotify v = new ZhanDouRpcTalkNotify();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ZhanDouRpcTalkNotify v)
	{
        if (v == null)
            return;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ZhanDouRpcTalkNotify>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ZhanDouRpcTalkNotify pb = ProtoBuf.Serializer.Deserialize<ZhanDouRpcTalkNotify>(protoMS);
		FromPB(pb);
		return true;
	}



};
