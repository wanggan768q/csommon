
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperSyncPBTestModule.cs
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


//NewDataStruct封装类
[System.Serializable]
public class TestModuleDataWraperV1
{

	//构造函数
	public TestModuleDataWraperV1()
	{
		 m_Field = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Field = -1;

	}

 	//转化成Protobuffer类型函数
	public TestModuleDataV1 ToPB()
	{
		TestModuleDataV1 v = new TestModuleDataV1();
		v.Field = m_Field;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(TestModuleDataV1 v)
	{
        if (v == null)
            return;
		m_Field = v.Field;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TestModuleDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		TestModuleDataV1 pb = ProtoBuf.Serializer.Deserialize<TestModuleDataV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//Field
	public int m_Field;
	public int Field
	{
		get { return m_Field;}
		set { m_Field = value; }
	}


};
