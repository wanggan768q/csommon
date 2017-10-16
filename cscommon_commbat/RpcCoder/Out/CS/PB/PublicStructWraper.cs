
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperPubPBCommon.cs
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


//背包回收格子封装类
[System.Serializable]
public class BagRecycleGridObjWraper
{

	//构造函数
	public BagRecycleGridObjWraper()
	{
		 m_ItemId = -1;
		 m_TemplateId = -1;
		 m_Num = -1;
		 m_ItemType = -1;
		 m_Pos = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemId = -1;
		 m_TemplateId = -1;
		 m_Num = -1;
		 m_ItemType = -1;
		 m_Pos = -1;

	}

 	//转化成Protobuffer类型函数
	public BagRecycleGridObj ToPB()
	{
		BagRecycleGridObj v = new BagRecycleGridObj();
		v.ItemId = m_ItemId;
		v.TemplateId = m_TemplateId;
		v.Num = m_Num;
		v.ItemType = m_ItemType;
		v.Pos = m_Pos;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagRecycleGridObj v)
	{
        if (v == null)
            return;
		m_ItemId = v.ItemId;
		m_TemplateId = v.TemplateId;
		m_Num = v.Num;
		m_ItemType = v.ItemType;
		m_Pos = v.Pos;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagRecycleGridObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagRecycleGridObj pb = ProtoBuf.Serializer.Deserialize<BagRecycleGridObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//道具id
	public long m_ItemId;
	public long ItemId
	{
		get { return m_ItemId;}
		set { m_ItemId = value; }
	}
	//模板id
	public int m_TemplateId;
	public int TemplateId
	{
		get { return m_TemplateId;}
		set { m_TemplateId = value; }
	}
	//数量
	public int m_Num;
	public int Num
	{
		get { return m_Num;}
		set { m_Num = value; }
	}
	//物品类型
	public int m_ItemType;
	public int ItemType
	{
		get { return m_ItemType;}
		set { m_ItemType = value; }
	}
	//位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}


};
//键值对封装类
[System.Serializable]
public class KeyValue2Wraper
{

	//构造函数
	public KeyValue2Wraper()
	{
		 m_Key = -1;
		 m_Value = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		 m_Value = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public KeyValue2 ToPB()
	{
		KeyValue2 v = new KeyValue2();
		v.Key = m_Key;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(KeyValue2 v)
	{
        if (v == null)
            return;
		m_Key = v.Key;
		m_Value = v.Value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<KeyValue2>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		KeyValue2 pb = ProtoBuf.Serializer.Deserialize<KeyValue2>(protoMS);
		FromPB(pb);
		return true;
	}

	//键
	public int m_Key;
	public int Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}
	//值
	public float m_Value;
	public float Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}


};
//背包格子对象封装类
[System.Serializable]
public class BagGridObjWraper
{

	//构造函数
	public BagGridObjWraper()
	{
		 m_TemplateID = -1;
		 m_Num = 0;
		 m_ItemType = -1;
		 m_Pos = -1;
		 m_Value = -1;
		 m_Index = -1;
		 m_Bind = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TemplateID = -1;
		 m_Num = 0;
		 m_ItemType = -1;
		 m_Pos = -1;
		 m_Value = -1;
		 m_Index = -1;
		 m_Bind = false;

	}

 	//转化成Protobuffer类型函数
	public BagGridObj ToPB()
	{
		BagGridObj v = new BagGridObj();
		v.TemplateID = m_TemplateID;
		v.Num = m_Num;
		v.ItemType = m_ItemType;
		v.Pos = m_Pos;
		v.Value = m_Value;
		v.Index = m_Index;
		v.Bind = m_Bind;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagGridObj v)
	{
        if (v == null)
            return;
		m_TemplateID = v.TemplateID;
		m_Num = v.Num;
		m_ItemType = v.ItemType;
		m_Pos = v.Pos;
		m_Value = v.Value;
		m_Index = v.Index;
		m_Bind = v.Bind;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagGridObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagGridObj pb = ProtoBuf.Serializer.Deserialize<BagGridObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品的配置Id
	public int m_TemplateID;
	public int TemplateID
	{
		get { return m_TemplateID;}
		set { m_TemplateID = value; }
	}
	//物品数量
	public int m_Num;
	public int Num
	{
		get { return m_Num;}
		set { m_Num = value; }
	}
	//物品类型
	public int m_ItemType;
	public int ItemType
	{
		get { return m_ItemType;}
		set { m_ItemType = value; }
	}
	//位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//客户端通用数据
	public int m_Value;
	public int Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}
	//ItemId，唯一id
	public long m_Index;
	public long Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//绑定
	public bool m_Bind;
	public bool Bind
	{
		get { return m_Bind;}
		set { m_Bind = value; }
	}


};
//背包装备对象封装类
[System.Serializable]
public class BagEquipObjWraper
{

	//构造函数
	public BagEquipObjWraper()
	{
		 m_ItemID = -1;
		m_BaseAttr = new List<BagAttrIntObjWraper>();
		m_ExtraAttr = new List<BagExtraAttrObjWraper>();
		m_EnhanceLv = new List<int>();
		m_EquipPolishedResult = new List<BagExtraAttrObjWraper>();
		 m_PolishedScore = 0;
		 m_Index = -1;
		m_InitBaseAttr = new List<BagAttrIntObjWraper>();
		 m_BagContainerType = -1;
		 m_GridIndex = -1;
		m_PlishedAttrId = new List<BagExtraAttrIdObjWraper>();
		m_GemArray = new List<BagGemObjWraper>();
		m_PolishedBaseAttrResult = new List<BagAttrIntObjWraper>();
		 m_TemplateId = -1;
		 m_GemSuitId = -1;
		 m_EquipScore = 0;
		 m_PolishedEquipScore = 0;
		m_BaseAttrPolishedInitAttr = new List<BagAttrIntObjWraper>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_ItemID = -1;
		m_BaseAttr = new List<BagAttrIntObjWraper>();
		m_ExtraAttr = new List<BagExtraAttrObjWraper>();
		m_EnhanceLv = new List<int>();
		m_EquipPolishedResult = new List<BagExtraAttrObjWraper>();
		 m_PolishedScore = 0;
		 m_Index = -1;
		m_InitBaseAttr = new List<BagAttrIntObjWraper>();
		 m_BagContainerType = -1;
		 m_GridIndex = -1;
		m_PlishedAttrId = new List<BagExtraAttrIdObjWraper>();
		m_GemArray = new List<BagGemObjWraper>();
		m_PolishedBaseAttrResult = new List<BagAttrIntObjWraper>();
		 m_TemplateId = -1;
		 m_GemSuitId = -1;
		 m_EquipScore = 0;
		 m_PolishedEquipScore = 0;
		m_BaseAttrPolishedInitAttr = new List<BagAttrIntObjWraper>();

	}

 	//转化成Protobuffer类型函数
	public BagEquipObj ToPB()
	{
		BagEquipObj v = new BagEquipObj();
		v.ItemID = m_ItemID;
		for (int i=0; i<(int)m_BaseAttr.Count; i++)
			v.BaseAttr.Add( m_BaseAttr[i].ToPB());
		for (int i=0; i<(int)m_ExtraAttr.Count; i++)
			v.ExtraAttr.Add( m_ExtraAttr[i].ToPB());
		for (int i=0; i<(int)m_EnhanceLv.Count; i++)
			v.EnhanceLv.Add( m_EnhanceLv[i]);
		for (int i=0; i<(int)m_EquipPolishedResult.Count; i++)
			v.EquipPolishedResult.Add( m_EquipPolishedResult[i].ToPB());
		v.PolishedScore = m_PolishedScore;
		v.Index = m_Index;
		for (int i=0; i<(int)m_InitBaseAttr.Count; i++)
			v.InitBaseAttr.Add( m_InitBaseAttr[i].ToPB());
		v.BagContainerType = m_BagContainerType;
		v.GridIndex = m_GridIndex;
		for (int i=0; i<(int)m_PlishedAttrId.Count; i++)
			v.PlishedAttrId.Add( m_PlishedAttrId[i].ToPB());
		for (int i=0; i<(int)m_GemArray.Count; i++)
			v.GemArray.Add( m_GemArray[i].ToPB());
		for (int i=0; i<(int)m_PolishedBaseAttrResult.Count; i++)
			v.PolishedBaseAttrResult.Add( m_PolishedBaseAttrResult[i].ToPB());
		v.TemplateId = m_TemplateId;
		v.GemSuitId = m_GemSuitId;
		v.EquipScore = m_EquipScore;
		v.PolishedEquipScore = m_PolishedEquipScore;
		for (int i=0; i<(int)m_BaseAttrPolishedInitAttr.Count; i++)
			v.BaseAttrPolishedInitAttr.Add( m_BaseAttrPolishedInitAttr[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagEquipObj v)
	{
        if (v == null)
            return;
		m_ItemID = v.ItemID;
		m_BaseAttr.Clear();
		for( int i=0; i<v.BaseAttr.Count; i++)
			m_BaseAttr.Add( new BagAttrIntObjWraper());
		for( int i=0; i<v.BaseAttr.Count; i++)
			m_BaseAttr[i].FromPB(v.BaseAttr[i]);
		m_ExtraAttr.Clear();
		for( int i=0; i<v.ExtraAttr.Count; i++)
			m_ExtraAttr.Add( new BagExtraAttrObjWraper());
		for( int i=0; i<v.ExtraAttr.Count; i++)
			m_ExtraAttr[i].FromPB(v.ExtraAttr[i]);
		m_EnhanceLv.Clear();
		for( int i=0; i<v.EnhanceLv.Count; i++)
			m_EnhanceLv.Add(v.EnhanceLv[i]);
		m_EquipPolishedResult.Clear();
		for( int i=0; i<v.EquipPolishedResult.Count; i++)
			m_EquipPolishedResult.Add( new BagExtraAttrObjWraper());
		for( int i=0; i<v.EquipPolishedResult.Count; i++)
			m_EquipPolishedResult[i].FromPB(v.EquipPolishedResult[i]);
		m_PolishedScore = v.PolishedScore;
		m_Index = v.Index;
		m_InitBaseAttr.Clear();
		for( int i=0; i<v.InitBaseAttr.Count; i++)
			m_InitBaseAttr.Add( new BagAttrIntObjWraper());
		for( int i=0; i<v.InitBaseAttr.Count; i++)
			m_InitBaseAttr[i].FromPB(v.InitBaseAttr[i]);
		m_BagContainerType = v.BagContainerType;
		m_GridIndex = v.GridIndex;
		m_PlishedAttrId.Clear();
		for( int i=0; i<v.PlishedAttrId.Count; i++)
			m_PlishedAttrId.Add( new BagExtraAttrIdObjWraper());
		for( int i=0; i<v.PlishedAttrId.Count; i++)
			m_PlishedAttrId[i].FromPB(v.PlishedAttrId[i]);
		m_GemArray.Clear();
		for( int i=0; i<v.GemArray.Count; i++)
			m_GemArray.Add( new BagGemObjWraper());
		for( int i=0; i<v.GemArray.Count; i++)
			m_GemArray[i].FromPB(v.GemArray[i]);
		m_PolishedBaseAttrResult.Clear();
		for( int i=0; i<v.PolishedBaseAttrResult.Count; i++)
			m_PolishedBaseAttrResult.Add( new BagAttrIntObjWraper());
		for( int i=0; i<v.PolishedBaseAttrResult.Count; i++)
			m_PolishedBaseAttrResult[i].FromPB(v.PolishedBaseAttrResult[i]);
		m_TemplateId = v.TemplateId;
		m_GemSuitId = v.GemSuitId;
		m_EquipScore = v.EquipScore;
		m_PolishedEquipScore = v.PolishedEquipScore;
		m_BaseAttrPolishedInitAttr.Clear();
		for( int i=0; i<v.BaseAttrPolishedInitAttr.Count; i++)
			m_BaseAttrPolishedInitAttr.Add( new BagAttrIntObjWraper());
		for( int i=0; i<v.BaseAttrPolishedInitAttr.Count; i++)
			m_BaseAttrPolishedInitAttr[i].FromPB(v.BaseAttrPolishedInitAttr[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagEquipObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagEquipObj pb = ProtoBuf.Serializer.Deserialize<BagEquipObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//物品实例id, 唯一id
	public long m_ItemID;
	public long ItemID
	{
		get { return m_ItemID;}
		set { m_ItemID = value; }
	}
	//基础属性值(包括附加的加成)
	public List<BagAttrIntObjWraper> m_BaseAttr;
	public int SizeBaseAttr()
	{
		return m_BaseAttr.Count;
	}
	public List<BagAttrIntObjWraper> GetBaseAttr()
	{
		return m_BaseAttr;
	}
	public BagAttrIntObjWraper GetBaseAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_BaseAttr.Count)
			return new BagAttrIntObjWraper();
		return m_BaseAttr[Index];
	}
	public void SetBaseAttr( List<BagAttrIntObjWraper> v )
	{
		m_BaseAttr=v;
	}
	public void SetBaseAttr( int Index, BagAttrIntObjWraper v )
	{
		if(Index<0 || Index>=(int)m_BaseAttr.Count)
			return;
		m_BaseAttr[Index] = v;
	}
	public void AddBaseAttr( BagAttrIntObjWraper v )
	{
		m_BaseAttr.Add(v);
	}
	public void ClearBaseAttr( )
	{
		m_BaseAttr.Clear();
	}
	//额外属性
	public List<BagExtraAttrObjWraper> m_ExtraAttr;
	public int SizeExtraAttr()
	{
		return m_ExtraAttr.Count;
	}
	public List<BagExtraAttrObjWraper> GetExtraAttr()
	{
		return m_ExtraAttr;
	}
	public BagExtraAttrObjWraper GetExtraAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.Count)
			return new BagExtraAttrObjWraper();
		return m_ExtraAttr[Index];
	}
	public void SetExtraAttr( List<BagExtraAttrObjWraper> v )
	{
		m_ExtraAttr=v;
	}
	public void SetExtraAttr( int Index, BagExtraAttrObjWraper v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.Count)
			return;
		m_ExtraAttr[Index] = v;
	}
	public void AddExtraAttr( BagExtraAttrObjWraper v )
	{
		m_ExtraAttr.Add(v);
	}
	public void ClearExtraAttr( )
	{
		m_ExtraAttr.Clear();
	}
	//强化等级
	public List<int> m_EnhanceLv;
	public int SizeEnhanceLv()
	{
		return m_EnhanceLv.Count;
	}
	public List<int> GetEnhanceLv()
	{
		return m_EnhanceLv;
	}
	public int GetEnhanceLv(int Index)
	{
		if(Index<0 || Index>=(int)m_EnhanceLv.Count)
			return -1;
		return m_EnhanceLv[Index];
	}
	public void SetEnhanceLv( List<int> v )
	{
		m_EnhanceLv=v;
	}
	public void SetEnhanceLv( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_EnhanceLv.Count)
			return;
		m_EnhanceLv[Index] = v;
	}
	public void AddEnhanceLv( int v=-1 )
	{
		m_EnhanceLv.Add(v);
	}
	public void ClearEnhanceLv( )
	{
		m_EnhanceLv.Clear();
	}
	//装备洗炼结果
	public List<BagExtraAttrObjWraper> m_EquipPolishedResult;
	public int SizeEquipPolishedResult()
	{
		return m_EquipPolishedResult.Count;
	}
	public List<BagExtraAttrObjWraper> GetEquipPolishedResult()
	{
		return m_EquipPolishedResult;
	}
	public BagExtraAttrObjWraper GetEquipPolishedResult(int Index)
	{
		if(Index<0 || Index>=(int)m_EquipPolishedResult.Count)
			return new BagExtraAttrObjWraper();
		return m_EquipPolishedResult[Index];
	}
	public void SetEquipPolishedResult( List<BagExtraAttrObjWraper> v )
	{
		m_EquipPolishedResult=v;
	}
	public void SetEquipPolishedResult( int Index, BagExtraAttrObjWraper v )
	{
		if(Index<0 || Index>=(int)m_EquipPolishedResult.Count)
			return;
		m_EquipPolishedResult[Index] = v;
	}
	public void AddEquipPolishedResult( BagExtraAttrObjWraper v )
	{
		m_EquipPolishedResult.Add(v);
	}
	public void ClearEquipPolishedResult( )
	{
		m_EquipPolishedResult.Clear();
	}
	//洗炼积分
	public int m_PolishedScore;
	public int PolishedScore
	{
		get { return m_PolishedScore;}
		set { m_PolishedScore = value; }
	}
	//用于索引道具具体数据
	public long m_Index;
	public long Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}
	//初始基础属性
	public List<BagAttrIntObjWraper> m_InitBaseAttr;
	public int SizeInitBaseAttr()
	{
		return m_InitBaseAttr.Count;
	}
	public List<BagAttrIntObjWraper> GetInitBaseAttr()
	{
		return m_InitBaseAttr;
	}
	public BagAttrIntObjWraper GetInitBaseAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_InitBaseAttr.Count)
			return new BagAttrIntObjWraper();
		return m_InitBaseAttr[Index];
	}
	public void SetInitBaseAttr( List<BagAttrIntObjWraper> v )
	{
		m_InitBaseAttr=v;
	}
	public void SetInitBaseAttr( int Index, BagAttrIntObjWraper v )
	{
		if(Index<0 || Index>=(int)m_InitBaseAttr.Count)
			return;
		m_InitBaseAttr[Index] = v;
	}
	public void AddInitBaseAttr( BagAttrIntObjWraper v )
	{
		m_InitBaseAttr.Add(v);
	}
	public void ClearInitBaseAttr( )
	{
		m_InitBaseAttr.Clear();
	}
	//物品容器类型
	public int m_BagContainerType;
	public int BagContainerType
	{
		get { return m_BagContainerType;}
		set { m_BagContainerType = value; }
	}
	//装备格子的索引
	public int m_GridIndex;
	public int GridIndex
	{
		get { return m_GridIndex;}
		set { m_GridIndex = value; }
	}
	//洗炼属性id
	public List<BagExtraAttrIdObjWraper> m_PlishedAttrId;
	public int SizePlishedAttrId()
	{
		return m_PlishedAttrId.Count;
	}
	public List<BagExtraAttrIdObjWraper> GetPlishedAttrId()
	{
		return m_PlishedAttrId;
	}
	public BagExtraAttrIdObjWraper GetPlishedAttrId(int Index)
	{
		if(Index<0 || Index>=(int)m_PlishedAttrId.Count)
			return new BagExtraAttrIdObjWraper();
		return m_PlishedAttrId[Index];
	}
	public void SetPlishedAttrId( List<BagExtraAttrIdObjWraper> v )
	{
		m_PlishedAttrId=v;
	}
	public void SetPlishedAttrId( int Index, BagExtraAttrIdObjWraper v )
	{
		if(Index<0 || Index>=(int)m_PlishedAttrId.Count)
			return;
		m_PlishedAttrId[Index] = v;
	}
	public void AddPlishedAttrId( BagExtraAttrIdObjWraper v )
	{
		m_PlishedAttrId.Add(v);
	}
	public void ClearPlishedAttrId( )
	{
		m_PlishedAttrId.Clear();
	}
	//宝石数组
	public List<BagGemObjWraper> m_GemArray;
	public int SizeGemArray()
	{
		return m_GemArray.Count;
	}
	public List<BagGemObjWraper> GetGemArray()
	{
		return m_GemArray;
	}
	public BagGemObjWraper GetGemArray(int Index)
	{
		if(Index<0 || Index>=(int)m_GemArray.Count)
			return new BagGemObjWraper();
		return m_GemArray[Index];
	}
	public void SetGemArray( List<BagGemObjWraper> v )
	{
		m_GemArray=v;
	}
	public void SetGemArray( int Index, BagGemObjWraper v )
	{
		if(Index<0 || Index>=(int)m_GemArray.Count)
			return;
		m_GemArray[Index] = v;
	}
	public void AddGemArray( BagGemObjWraper v )
	{
		m_GemArray.Add(v);
	}
	public void ClearGemArray( )
	{
		m_GemArray.Clear();
	}
	//基础属性洗炼结果
	public List<BagAttrIntObjWraper> m_PolishedBaseAttrResult;
	public int SizePolishedBaseAttrResult()
	{
		return m_PolishedBaseAttrResult.Count;
	}
	public List<BagAttrIntObjWraper> GetPolishedBaseAttrResult()
	{
		return m_PolishedBaseAttrResult;
	}
	public BagAttrIntObjWraper GetPolishedBaseAttrResult(int Index)
	{
		if(Index<0 || Index>=(int)m_PolishedBaseAttrResult.Count)
			return new BagAttrIntObjWraper();
		return m_PolishedBaseAttrResult[Index];
	}
	public void SetPolishedBaseAttrResult( List<BagAttrIntObjWraper> v )
	{
		m_PolishedBaseAttrResult=v;
	}
	public void SetPolishedBaseAttrResult( int Index, BagAttrIntObjWraper v )
	{
		if(Index<0 || Index>=(int)m_PolishedBaseAttrResult.Count)
			return;
		m_PolishedBaseAttrResult[Index] = v;
	}
	public void AddPolishedBaseAttrResult( BagAttrIntObjWraper v )
	{
		m_PolishedBaseAttrResult.Add(v);
	}
	public void ClearPolishedBaseAttrResult( )
	{
		m_PolishedBaseAttrResult.Clear();
	}
	//模板id
	public int m_TemplateId;
	public int TemplateId
	{
		get { return m_TemplateId;}
		set { m_TemplateId = value; }
	}
	//宝石组合id
	public int m_GemSuitId;
	public int GemSuitId
	{
		get { return m_GemSuitId;}
		set { m_GemSuitId = value; }
	}
	//装备评分
	public int m_EquipScore;
	public int EquipScore
	{
		get { return m_EquipScore;}
		set { m_EquipScore = value; }
	}
	//洗炼装备评分
	public int m_PolishedEquipScore;
	public int PolishedEquipScore
	{
		get { return m_PolishedEquipScore;}
		set { m_PolishedEquipScore = value; }
	}
	//基础属性洗炼初始属性
	public List<BagAttrIntObjWraper> m_BaseAttrPolishedInitAttr;
	public int SizeBaseAttrPolishedInitAttr()
	{
		return m_BaseAttrPolishedInitAttr.Count;
	}
	public List<BagAttrIntObjWraper> GetBaseAttrPolishedInitAttr()
	{
		return m_BaseAttrPolishedInitAttr;
	}
	public BagAttrIntObjWraper GetBaseAttrPolishedInitAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_BaseAttrPolishedInitAttr.Count)
			return new BagAttrIntObjWraper();
		return m_BaseAttrPolishedInitAttr[Index];
	}
	public void SetBaseAttrPolishedInitAttr( List<BagAttrIntObjWraper> v )
	{
		m_BaseAttrPolishedInitAttr=v;
	}
	public void SetBaseAttrPolishedInitAttr( int Index, BagAttrIntObjWraper v )
	{
		if(Index<0 || Index>=(int)m_BaseAttrPolishedInitAttr.Count)
			return;
		m_BaseAttrPolishedInitAttr[Index] = v;
	}
	public void AddBaseAttrPolishedInitAttr( BagAttrIntObjWraper v )
	{
		m_BaseAttrPolishedInitAttr.Add(v);
	}
	public void ClearBaseAttrPolishedInitAttr( )
	{
		m_BaseAttrPolishedInitAttr.Clear();
	}


};
//装备属性封装类
[System.Serializable]
public class BagAttrIntObjWraper
{

	//构造函数
	public BagAttrIntObjWraper()
	{
		 m_AttrId = -1;
		 m_AttrValue = -1;
		 m_MaxAttrValue = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AttrId = -1;
		 m_AttrValue = -1;
		 m_MaxAttrValue = -1;

	}

 	//转化成Protobuffer类型函数
	public BagAttrIntObj ToPB()
	{
		BagAttrIntObj v = new BagAttrIntObj();
		v.AttrId = m_AttrId;
		v.AttrValue = m_AttrValue;
		v.MaxAttrValue = m_MaxAttrValue;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagAttrIntObj v)
	{
        if (v == null)
            return;
		m_AttrId = v.AttrId;
		m_AttrValue = v.AttrValue;
		m_MaxAttrValue = v.MaxAttrValue;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagAttrIntObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagAttrIntObj pb = ProtoBuf.Serializer.Deserialize<BagAttrIntObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//属性Id
	public int m_AttrId;
	public int AttrId
	{
		get { return m_AttrId;}
		set { m_AttrId = value; }
	}
	//属性值
	public int m_AttrValue;
	public int AttrValue
	{
		get { return m_AttrValue;}
		set { m_AttrValue = value; }
	}
	//最大属性值
	public int m_MaxAttrValue;
	public int MaxAttrValue
	{
		get { return m_MaxAttrValue;}
		set { m_MaxAttrValue = value; }
	}


};
//装备属性对象封装类
[System.Serializable]
public class BagAttrFloatObjWraper
{

	//构造函数
	public BagAttrFloatObjWraper()
	{
		 m_AttrId = -1;
		 m_AttrValue = (float)-1;
		 m_Index = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_AttrId = -1;
		 m_AttrValue = (float)-1;
		 m_Index = -1;

	}

 	//转化成Protobuffer类型函数
	public BagAttrFloatObj ToPB()
	{
		BagAttrFloatObj v = new BagAttrFloatObj();
		v.AttrId = m_AttrId;
		v.AttrValue = m_AttrValue;
		v.Index = m_Index;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagAttrFloatObj v)
	{
        if (v == null)
            return;
		m_AttrId = v.AttrId;
		m_AttrValue = v.AttrValue;
		m_Index = v.Index;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagAttrFloatObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagAttrFloatObj pb = ProtoBuf.Serializer.Deserialize<BagAttrFloatObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//属性Id
	public int m_AttrId;
	public int AttrId
	{
		get { return m_AttrId;}
		set { m_AttrId = value; }
	}
	//属性值
	public float m_AttrValue;
	public float AttrValue
	{
		get { return m_AttrValue;}
		set { m_AttrValue = value; }
	}
	//索引
	public int m_Index;
	public int Index
	{
		get { return m_Index;}
		set { m_Index = value; }
	}


};
//装备宝石对象封装类
[System.Serializable]
public class BagGemObjWraper
{

	//构造函数
	public BagGemObjWraper()
	{
		 m_GemId = -1;
		 m_Pos = -1;
		 m_IsLock = false;
		 m_Level = -1;
		 m_Type = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GemId = -1;
		 m_Pos = -1;
		 m_IsLock = false;
		 m_Level = -1;
		 m_Type = -1;

	}

 	//转化成Protobuffer类型函数
	public BagGemObj ToPB()
	{
		BagGemObj v = new BagGemObj();
		v.GemId = m_GemId;
		v.Pos = m_Pos;
		v.IsLock = m_IsLock;
		v.Level = m_Level;
		v.Type = m_Type;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagGemObj v)
	{
        if (v == null)
            return;
		m_GemId = v.GemId;
		m_Pos = v.Pos;
		m_IsLock = v.IsLock;
		m_Level = v.Level;
		m_Type = v.Type;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagGemObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagGemObj pb = ProtoBuf.Serializer.Deserialize<BagGemObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//宝石id
	public int m_GemId;
	public int GemId
	{
		get { return m_GemId;}
		set { m_GemId = value; }
	}
	//位置
	public int m_Pos;
	public int Pos
	{
		get { return m_Pos;}
		set { m_Pos = value; }
	}
	//锁着， 未打孔
	public bool m_IsLock;
	public bool IsLock
	{
		get { return m_IsLock;}
		set { m_IsLock = value; }
	}
	//宝石等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//配置的type
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}


};
//键值对封装类
[System.Serializable]
public class KeyValue2IntIntWraper
{

	//构造函数
	public KeyValue2IntIntWraper()
	{
		 m_Key = -1;
		 m_Value = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		 m_Value = -1;

	}

 	//转化成Protobuffer类型函数
	public KeyValue2IntInt ToPB()
	{
		KeyValue2IntInt v = new KeyValue2IntInt();
		v.Key = m_Key;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(KeyValue2IntInt v)
	{
        if (v == null)
            return;
		m_Key = v.Key;
		m_Value = v.Value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<KeyValue2IntInt>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		KeyValue2IntInt pb = ProtoBuf.Serializer.Deserialize<KeyValue2IntInt>(protoMS);
		FromPB(pb);
		return true;
	}

	//键
	public int m_Key;
	public int Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}
	//值
	public int m_Value;
	public int Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}


};
//键值对封装类
[System.Serializable]
public class KeyValue2IntBoolWraper
{

	//构造函数
	public KeyValue2IntBoolWraper()
	{
		 m_Key = -1;
		 m_Value = false;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Key = -1;
		 m_Value = false;

	}

 	//转化成Protobuffer类型函数
	public KeyValue2IntBool ToPB()
	{
		KeyValue2IntBool v = new KeyValue2IntBool();
		v.Key = m_Key;
		v.Value = m_Value;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(KeyValue2IntBool v)
	{
        if (v == null)
            return;
		m_Key = v.Key;
		m_Value = v.Value;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<KeyValue2IntBool>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		KeyValue2IntBool pb = ProtoBuf.Serializer.Deserialize<KeyValue2IntBool>(protoMS);
		FromPB(pb);
		return true;
	}

	//键
	public int m_Key;
	public int Key
	{
		get { return m_Key;}
		set { m_Key = value; }
	}
	//值
	public bool m_Value;
	public bool Value
	{
		get { return m_Value;}
		set { m_Value = value; }
	}


};
//背包装备附加属性封装类
[System.Serializable]
public class BagExtraAttrObjWraper
{

	//构造函数
	public BagExtraAttrObjWraper()
	{
		m_ExtraAttr = new List<BagAttrFloatObjWraper>();
		 m_Id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_ExtraAttr = new List<BagAttrFloatObjWraper>();
		 m_Id = -1;

	}

 	//转化成Protobuffer类型函数
	public BagExtraAttrObj ToPB()
	{
		BagExtraAttrObj v = new BagExtraAttrObj();
		for (int i=0; i<(int)m_ExtraAttr.Count; i++)
			v.ExtraAttr.Add( m_ExtraAttr[i].ToPB());
		v.Id = m_Id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagExtraAttrObj v)
	{
        if (v == null)
            return;
		m_ExtraAttr.Clear();
		for( int i=0; i<v.ExtraAttr.Count; i++)
			m_ExtraAttr.Add( new BagAttrFloatObjWraper());
		for( int i=0; i<v.ExtraAttr.Count; i++)
			m_ExtraAttr[i].FromPB(v.ExtraAttr[i]);
		m_Id = v.Id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagExtraAttrObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagExtraAttrObj pb = ProtoBuf.Serializer.Deserialize<BagExtraAttrObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//附加属性
	public List<BagAttrFloatObjWraper> m_ExtraAttr;
	public int SizeExtraAttr()
	{
		return m_ExtraAttr.Count;
	}
	public List<BagAttrFloatObjWraper> GetExtraAttr()
	{
		return m_ExtraAttr;
	}
	public BagAttrFloatObjWraper GetExtraAttr(int Index)
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.Count)
			return new BagAttrFloatObjWraper();
		return m_ExtraAttr[Index];
	}
	public void SetExtraAttr( List<BagAttrFloatObjWraper> v )
	{
		m_ExtraAttr=v;
	}
	public void SetExtraAttr( int Index, BagAttrFloatObjWraper v )
	{
		if(Index<0 || Index>=(int)m_ExtraAttr.Count)
			return;
		m_ExtraAttr[Index] = v;
	}
	public void AddExtraAttr( BagAttrFloatObjWraper v )
	{
		m_ExtraAttr.Add(v);
	}
	public void ClearExtraAttr( )
	{
		m_ExtraAttr.Clear();
	}
	//词条Id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}


};
//附加属性Id封装类
[System.Serializable]
public class BagExtraAttrIdObjWraper
{

	//构造函数
	public BagExtraAttrIdObjWraper()
	{
		m_AttrId = new List<int>();
		 m_Id = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		m_AttrId = new List<int>();
		 m_Id = -1;

	}

 	//转化成Protobuffer类型函数
	public BagExtraAttrIdObj ToPB()
	{
		BagExtraAttrIdObj v = new BagExtraAttrIdObj();
		for (int i=0; i<(int)m_AttrId.Count; i++)
			v.AttrId.Add( m_AttrId[i]);
		v.Id = m_Id;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BagExtraAttrIdObj v)
	{
        if (v == null)
            return;
		m_AttrId.Clear();
		for( int i=0; i<v.AttrId.Count; i++)
			m_AttrId.Add(v.AttrId[i]);
		m_Id = v.Id;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BagExtraAttrIdObj>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BagExtraAttrIdObj pb = ProtoBuf.Serializer.Deserialize<BagExtraAttrIdObj>(protoMS);
		FromPB(pb);
		return true;
	}

	//属性Id
	public List<int> m_AttrId;
	public int SizeAttrId()
	{
		return m_AttrId.Count;
	}
	public List<int> GetAttrId()
	{
		return m_AttrId;
	}
	public int GetAttrId(int Index)
	{
		if(Index<0 || Index>=(int)m_AttrId.Count)
			return -1;
		return m_AttrId[Index];
	}
	public void SetAttrId( List<int> v )
	{
		m_AttrId=v;
	}
	public void SetAttrId( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_AttrId.Count)
			return;
		m_AttrId[Index] = v;
	}
	public void AddAttrId( int v=-1 )
	{
		m_AttrId.Add(v);
	}
	public void ClearAttrId( )
	{
		m_AttrId.Clear();
	}
	//词条Id
	public int m_Id;
	public int Id
	{
		get { return m_Id;}
		set { m_Id = value; }
	}


};
