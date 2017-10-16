
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperSyncPBZhanDou.cs
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


//行走数据封装类
[System.Serializable]
public class ZhanDouMoveDataWraperV1
{

	//构造函数
	public ZhanDouMoveDataWraperV1()
	{
		 m_Dir = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Dir = -1;

	}

 	//转化成Protobuffer类型函数
	public ZhanDouMoveDataV1 ToPB()
	{
		ZhanDouMoveDataV1 v = new ZhanDouMoveDataV1();
		v.Dir = m_Dir;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(ZhanDouMoveDataV1 v)
	{
        if (v == null)
            return;
		m_Dir = v.Dir;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<ZhanDouMoveDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		ZhanDouMoveDataV1 pb = ProtoBuf.Serializer.Deserialize<ZhanDouMoveDataV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//方向
	public int m_Dir;
	public int Dir
	{
		get { return m_Dir;}
		set { m_Dir = value; }
	}


};
