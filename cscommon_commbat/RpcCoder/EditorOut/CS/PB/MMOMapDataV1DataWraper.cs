
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperSyncPBMMOMapData.cs
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


//基础数据封装类
[System.Serializable]
public class MMOMapDataBaseDataWraperV1
{

	//构造函数
	public MMOMapDataBaseDataWraperV1()
	{
		 m_DataName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DataName = "";

	}

 	//转化成Protobuffer类型函数
	public MMOMapDataBaseDataV1 ToPB()
	{
		MMOMapDataBaseDataV1 v = new MMOMapDataBaseDataV1();
		v.DataName = m_DataName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MMOMapDataBaseDataV1 v)
	{
        if (v == null)
            return;
		m_DataName = v.DataName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MMOMapDataBaseDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MMOMapDataBaseDataV1 pb = ProtoBuf.Serializer.Deserialize<MMOMapDataBaseDataV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//地图文件名称
	public string m_DataName;
	public string DataName
	{
		get { return m_DataName;}
		set { m_DataName = value; }
	}


};
//出生点封装类
[System.Serializable]
public class MMOMapDataSpawnInfoWraperV1
{

	//构造函数
	public MMOMapDataSpawnInfoWraperV1()
	{
		 m_SpawnPos = new MMOMapDataMDVector3WraperV1();
		 m_SpawnRot = new MMOMapDataMDVector3WraperV1();
		 m_SpawnIndex = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SpawnPos = new MMOMapDataMDVector3WraperV1();
		 m_SpawnRot = new MMOMapDataMDVector3WraperV1();
		 m_SpawnIndex = 0;

	}

 	//转化成Protobuffer类型函数
	public MMOMapDataSpawnInfoV1 ToPB()
	{
		MMOMapDataSpawnInfoV1 v = new MMOMapDataSpawnInfoV1();
		v.SpawnPos = m_SpawnPos.ToPB();
		v.SpawnRot = m_SpawnRot.ToPB();
		v.SpawnIndex = m_SpawnIndex;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MMOMapDataSpawnInfoV1 v)
	{
        if (v == null)
            return;
		m_SpawnPos.FromPB(v.SpawnPos);
		m_SpawnRot.FromPB(v.SpawnRot);
		m_SpawnIndex = v.SpawnIndex;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MMOMapDataSpawnInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MMOMapDataSpawnInfoV1 pb = ProtoBuf.Serializer.Deserialize<MMOMapDataSpawnInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//出生点的位置
	public MMOMapDataMDVector3WraperV1 m_SpawnPos;
	public MMOMapDataMDVector3WraperV1 SpawnPos
	{
		get { return m_SpawnPos;}
		set { m_SpawnPos = value; }
	}
	//出生后的朝向
	public MMOMapDataMDVector3WraperV1 m_SpawnRot;
	public MMOMapDataMDVector3WraperV1 SpawnRot
	{
		get { return m_SpawnRot;}
		set { m_SpawnRot = value; }
	}
	//出生点编号
	public int m_SpawnIndex;
	public int SpawnIndex
	{
		get { return m_SpawnIndex;}
		set { m_SpawnIndex = value; }
	}


};
//MDVector3封装类
[System.Serializable]
public class MMOMapDataMDVector3WraperV1
{

	//构造函数
	public MMOMapDataMDVector3WraperV1()
	{
		 m_X = (float)0;
		 m_Y = (float)0;
		 m_Z = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X = (float)0;
		 m_Y = (float)0;
		 m_Z = (float)0;

	}

 	//转化成Protobuffer类型函数
	public MMOMapDataMDVector3V1 ToPB()
	{
		MMOMapDataMDVector3V1 v = new MMOMapDataMDVector3V1();
		v.X = m_X;
		v.Y = m_Y;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MMOMapDataMDVector3V1 v)
	{
        if (v == null)
            return;
		m_X = v.X;
		m_Y = v.Y;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MMOMapDataMDVector3V1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MMOMapDataMDVector3V1 pb = ProtoBuf.Serializer.Deserialize<MMOMapDataMDVector3V1>(protoMS);
		FromPB(pb);
		return true;
	}

	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Y
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}
	//Z
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//传送门信息封装类
[System.Serializable]
public class MMOMapDataPortalInfoWraperV1
{

	//构造函数
	public MMOMapDataPortalInfoWraperV1()
	{
		 m_SourcePos = new MMOMapDataMDVector3WraperV1();
		 m_TargetPos = new MMOMapDataMDVector3WraperV1();
		 m_TargetRot = new MMOMapDataMDVector3WraperV1();
		 m_TargetDungeonID = 0;
		 m_TargetSpawnIndex = 0;
		 m_PortalType = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SourcePos = new MMOMapDataMDVector3WraperV1();
		 m_TargetPos = new MMOMapDataMDVector3WraperV1();
		 m_TargetRot = new MMOMapDataMDVector3WraperV1();
		 m_TargetDungeonID = 0;
		 m_TargetSpawnIndex = 0;
		 m_PortalType = 0;

	}

 	//转化成Protobuffer类型函数
	public MMOMapDataPortalInfoV1 ToPB()
	{
		MMOMapDataPortalInfoV1 v = new MMOMapDataPortalInfoV1();
		v.SourcePos = m_SourcePos.ToPB();
		v.TargetPos = m_TargetPos.ToPB();
		v.TargetRot = m_TargetRot.ToPB();
		v.TargetDungeonID = m_TargetDungeonID;
		v.TargetSpawnIndex = m_TargetSpawnIndex;
		v.PortalType = m_PortalType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MMOMapDataPortalInfoV1 v)
	{
        if (v == null)
            return;
		m_SourcePos.FromPB(v.SourcePos);
		m_TargetPos.FromPB(v.TargetPos);
		m_TargetRot.FromPB(v.TargetRot);
		m_TargetDungeonID = v.TargetDungeonID;
		m_TargetSpawnIndex = v.TargetSpawnIndex;
		m_PortalType = v.PortalType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MMOMapDataPortalInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MMOMapDataPortalInfoV1 pb = ProtoBuf.Serializer.Deserialize<MMOMapDataPortalInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//起点位置
	public MMOMapDataMDVector3WraperV1 m_SourcePos;
	public MMOMapDataMDVector3WraperV1 SourcePos
	{
		get { return m_SourcePos;}
		set { m_SourcePos = value; }
	}
	//目标的位置
	public MMOMapDataMDVector3WraperV1 m_TargetPos;
	public MMOMapDataMDVector3WraperV1 TargetPos
	{
		get { return m_TargetPos;}
		set { m_TargetPos = value; }
	}
	//传送后的
	public MMOMapDataMDVector3WraperV1 m_TargetRot;
	public MMOMapDataMDVector3WraperV1 TargetRot
	{
		get { return m_TargetRot;}
		set { m_TargetRot = value; }
	}
	//目标场景ID
	public int m_TargetDungeonID;
	public int TargetDungeonID
	{
		get { return m_TargetDungeonID;}
		set { m_TargetDungeonID = value; }
	}
	//目标场景的出生点索引
	public int m_TargetSpawnIndex;
	public int TargetSpawnIndex
	{
		get { return m_TargetSpawnIndex;}
		set { m_TargetSpawnIndex = value; }
	}
	//传送类型
	public int m_PortalType;
	public int PortalType
	{
		get { return m_PortalType;}
		set { m_PortalType = value; }
	}


};
//节点信息封装类
[System.Serializable]
public class MMOMapDataNodeInfoWraperV1
{

	//构造函数
	public MMOMapDataNodeInfoWraperV1()
	{
		 m_RelevanceArea = 0;
		 m_PassKillEnemyID = 0;
		 m_PassKillEnemyNum = 0;
		 m_PassTime = 0;
		 m_PassUseItemID = 0;
		 m_PassUseItemNum = 0;
		 m_PassCollectItemID = 0;
		 m_PassCollectItemNum = 0;
		 m_PassConditionType = 0;
		 m_NodePos1 = new MMOMapDataMDVector3WraperV1();
		 m_NodePos2 = new MMOMapDataMDVector3WraperV1();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_RelevanceArea = 0;
		 m_PassKillEnemyID = 0;
		 m_PassKillEnemyNum = 0;
		 m_PassTime = 0;
		 m_PassUseItemID = 0;
		 m_PassUseItemNum = 0;
		 m_PassCollectItemID = 0;
		 m_PassCollectItemNum = 0;
		 m_PassConditionType = 0;
		 m_NodePos1 = new MMOMapDataMDVector3WraperV1();
		 m_NodePos2 = new MMOMapDataMDVector3WraperV1();

	}

 	//转化成Protobuffer类型函数
	public MMOMapDataNodeInfoV1 ToPB()
	{
		MMOMapDataNodeInfoV1 v = new MMOMapDataNodeInfoV1();
		v.RelevanceArea = m_RelevanceArea;
		v.PassKillEnemyID = m_PassKillEnemyID;
		v.PassKillEnemyNum = m_PassKillEnemyNum;
		v.PassTime = m_PassTime;
		v.PassUseItemID = m_PassUseItemID;
		v.PassUseItemNum = m_PassUseItemNum;
		v.PassCollectItemID = m_PassCollectItemID;
		v.PassCollectItemNum = m_PassCollectItemNum;
		v.PassConditionType = m_PassConditionType;
		v.NodePos1 = m_NodePos1.ToPB();
		v.NodePos2 = m_NodePos2.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MMOMapDataNodeInfoV1 v)
	{
        if (v == null)
            return;
		m_RelevanceArea = v.RelevanceArea;
		m_PassKillEnemyID = v.PassKillEnemyID;
		m_PassKillEnemyNum = v.PassKillEnemyNum;
		m_PassTime = v.PassTime;
		m_PassUseItemID = v.PassUseItemID;
		m_PassUseItemNum = v.PassUseItemNum;
		m_PassCollectItemID = v.PassCollectItemID;
		m_PassCollectItemNum = v.PassCollectItemNum;
		m_PassConditionType = v.PassConditionType;
		m_NodePos1.FromPB(v.NodePos1);
		m_NodePos2.FromPB(v.NodePos2);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MMOMapDataNodeInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MMOMapDataNodeInfoV1 pb = ProtoBuf.Serializer.Deserialize<MMOMapDataNodeInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//关联坑点区域
	public int m_RelevanceArea;
	public int RelevanceArea
	{
		get { return m_RelevanceArea;}
		set { m_RelevanceArea = value; }
	}
	//敌人ID
	public int m_PassKillEnemyID;
	public int PassKillEnemyID
	{
		get { return m_PassKillEnemyID;}
		set { m_PassKillEnemyID = value; }
	}
	//杀掉敌人数量
	public int m_PassKillEnemyNum;
	public int PassKillEnemyNum
	{
		get { return m_PassKillEnemyNum;}
		set { m_PassKillEnemyNum = value; }
	}
	//通过节点的时间
	public int m_PassTime;
	public int PassTime
	{
		get { return m_PassTime;}
		set { m_PassTime = value; }
	}
	//使用道具的ID
	public int m_PassUseItemID;
	public int PassUseItemID
	{
		get { return m_PassUseItemID;}
		set { m_PassUseItemID = value; }
	}
	//使用道具的数量
	public int m_PassUseItemNum;
	public int PassUseItemNum
	{
		get { return m_PassUseItemNum;}
		set { m_PassUseItemNum = value; }
	}
	//收集道具的ID
	public int m_PassCollectItemID;
	public int PassCollectItemID
	{
		get { return m_PassCollectItemID;}
		set { m_PassCollectItemID = value; }
	}
	//收集道具的数量
	public int m_PassCollectItemNum;
	public int PassCollectItemNum
	{
		get { return m_PassCollectItemNum;}
		set { m_PassCollectItemNum = value; }
	}
	//通过条件类型
	public int m_PassConditionType;
	public int PassConditionType
	{
		get { return m_PassConditionType;}
		set { m_PassConditionType = value; }
	}
	//节点位置1
	public MMOMapDataMDVector3WraperV1 m_NodePos1;
	public MMOMapDataMDVector3WraperV1 NodePos1
	{
		get { return m_NodePos1;}
		set { m_NodePos1 = value; }
	}
	//节点位置2
	public MMOMapDataMDVector3WraperV1 m_NodePos2;
	public MMOMapDataMDVector3WraperV1 NodePos2
	{
		get { return m_NodePos2;}
		set { m_NodePos2 = value; }
	}


};
//坑点信息封装类
[System.Serializable]
public class MMOMapDataPointInfoWraperV1
{

	//构造函数
	public MMOMapDataPointInfoWraperV1()
	{
		 m_SpriteType = 0;
		 m_SpriteID = 0;
		 m_Area = 0;
		 m_PointPos = new MMOMapDataMDVector3WraperV1();
		 m_PointRot = new MMOMapDataMDVector3WraperV1();
		 m_RefreshType = 0;
		 m_UnlockTime = 0;
		 m_EnemyID = 0;
		 m_EnemyNum = 0;
		 m_RebirthType = 0;
		 m_RebirthEnemyID = 0;
		 m_RebirthEnemyNum = 0;
		 m_AfterDeathTime = 0;
		 m_RebirthNum = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SpriteType = 0;
		 m_SpriteID = 0;
		 m_Area = 0;
		 m_PointPos = new MMOMapDataMDVector3WraperV1();
		 m_PointRot = new MMOMapDataMDVector3WraperV1();
		 m_RefreshType = 0;
		 m_UnlockTime = 0;
		 m_EnemyID = 0;
		 m_EnemyNum = 0;
		 m_RebirthType = 0;
		 m_RebirthEnemyID = 0;
		 m_RebirthEnemyNum = 0;
		 m_AfterDeathTime = 0;
		 m_RebirthNum = -1;

	}

 	//转化成Protobuffer类型函数
	public MMOMapDataPointInfoV1 ToPB()
	{
		MMOMapDataPointInfoV1 v = new MMOMapDataPointInfoV1();
		v.SpriteType = m_SpriteType;
		v.SpriteID = m_SpriteID;
		v.Area = m_Area;
		v.PointPos = m_PointPos.ToPB();
		v.PointRot = m_PointRot.ToPB();
		v.RefreshType = m_RefreshType;
		v.UnlockTime = m_UnlockTime;
		v.EnemyID = m_EnemyID;
		v.EnemyNum = m_EnemyNum;
		v.RebirthType = m_RebirthType;
		v.RebirthEnemyID = m_RebirthEnemyID;
		v.RebirthEnemyNum = m_RebirthEnemyNum;
		v.AfterDeathTime = m_AfterDeathTime;
		v.RebirthNum = m_RebirthNum;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MMOMapDataPointInfoV1 v)
	{
        if (v == null)
            return;
		m_SpriteType = v.SpriteType;
		m_SpriteID = v.SpriteID;
		m_Area = v.Area;
		m_PointPos.FromPB(v.PointPos);
		m_PointRot.FromPB(v.PointRot);
		m_RefreshType = v.RefreshType;
		m_UnlockTime = v.UnlockTime;
		m_EnemyID = v.EnemyID;
		m_EnemyNum = v.EnemyNum;
		m_RebirthType = v.RebirthType;
		m_RebirthEnemyID = v.RebirthEnemyID;
		m_RebirthEnemyNum = v.RebirthEnemyNum;
		m_AfterDeathTime = v.AfterDeathTime;
		m_RebirthNum = v.RebirthNum;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MMOMapDataPointInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MMOMapDataPointInfoV1 pb = ProtoBuf.Serializer.Deserialize<MMOMapDataPointInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//精灵类型
	public int m_SpriteType;
	public int SpriteType
	{
		get { return m_SpriteType;}
		set { m_SpriteType = value; }
	}
	//精灵ID
	public int m_SpriteID;
	public int SpriteID
	{
		get { return m_SpriteID;}
		set { m_SpriteID = value; }
	}
	//隶属区域
	public int m_Area;
	public int Area
	{
		get { return m_Area;}
		set { m_Area = value; }
	}
	//坑点位置
	public MMOMapDataMDVector3WraperV1 m_PointPos;
	public MMOMapDataMDVector3WraperV1 PointPos
	{
		get { return m_PointPos;}
		set { m_PointPos = value; }
	}
	//坑点朝向
	public MMOMapDataMDVector3WraperV1 m_PointRot;
	public MMOMapDataMDVector3WraperV1 PointRot
	{
		get { return m_PointRot;}
		set { m_PointRot = value; }
	}
	//刷新类型
	public int m_RefreshType;
	public int RefreshType
	{
		get { return m_RefreshType;}
		set { m_RefreshType = value; }
	}
	//开启时间
	public int m_UnlockTime;
	public int UnlockTime
	{
		get { return m_UnlockTime;}
		set { m_UnlockTime = value; }
	}
	//杀死敌人的ID
	public int m_EnemyID;
	public int EnemyID
	{
		get { return m_EnemyID;}
		set { m_EnemyID = value; }
	}
	//杀死敌人个数
	public int m_EnemyNum;
	public int EnemyNum
	{
		get { return m_EnemyNum;}
		set { m_EnemyNum = value; }
	}
	//重生类型
	public int m_RebirthType;
	public int RebirthType
	{
		get { return m_RebirthType;}
		set { m_RebirthType = value; }
	}
	//重生的敌人ID
	public int m_RebirthEnemyID;
	public int RebirthEnemyID
	{
		get { return m_RebirthEnemyID;}
		set { m_RebirthEnemyID = value; }
	}
	//重生的敌人数量
	public int m_RebirthEnemyNum;
	public int RebirthEnemyNum
	{
		get { return m_RebirthEnemyNum;}
		set { m_RebirthEnemyNum = value; }
	}
	//怪物死亡后的时间
	public int m_AfterDeathTime;
	public int AfterDeathTime
	{
		get { return m_AfterDeathTime;}
		set { m_AfterDeathTime = value; }
	}
	//重生次数
	public int m_RebirthNum;
	public int RebirthNum
	{
		get { return m_RebirthNum;}
		set { m_RebirthNum = value; }
	}


};
//信息封装类
[System.Serializable]
public class MMOMapDataInfoWraperV1
{

	//构造函数
	public MMOMapDataInfoWraperV1()
	{
		 m_BaseInfo = new MMOMapDataBaseDataWraperV1();
		m_SpawnArr = new List<MMOMapDataSpawnInfoWraperV1>();
		m_PortalArr = new List<MMOMapDataPortalInfoWraperV1>();
		 m_DefeatInfo = new MMOMapDataDefeatInfoWraperV1();
		m_NodeArr = new List<MMOMapDataNodeInfoWraperV1>();
		m_PointArr = new List<MMOMapDataPointInfoWraperV1>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_BaseInfo = new MMOMapDataBaseDataWraperV1();
		m_SpawnArr = new List<MMOMapDataSpawnInfoWraperV1>();
		m_PortalArr = new List<MMOMapDataPortalInfoWraperV1>();
		 m_DefeatInfo = new MMOMapDataDefeatInfoWraperV1();
		m_NodeArr = new List<MMOMapDataNodeInfoWraperV1>();
		m_PointArr = new List<MMOMapDataPointInfoWraperV1>();

	}

 	//转化成Protobuffer类型函数
	public MMOMapDataInfoV1 ToPB()
	{
		MMOMapDataInfoV1 v = new MMOMapDataInfoV1();
		v.BaseInfo = m_BaseInfo.ToPB();
		for (int i=0; i<(int)m_SpawnArr.Count; i++)
			v.SpawnArr.Add( m_SpawnArr[i].ToPB());
		for (int i=0; i<(int)m_PortalArr.Count; i++)
			v.PortalArr.Add( m_PortalArr[i].ToPB());
		v.DefeatInfo = m_DefeatInfo.ToPB();
		for (int i=0; i<(int)m_NodeArr.Count; i++)
			v.NodeArr.Add( m_NodeArr[i].ToPB());
		for (int i=0; i<(int)m_PointArr.Count; i++)
			v.PointArr.Add( m_PointArr[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MMOMapDataInfoV1 v)
	{
        if (v == null)
            return;
		m_BaseInfo.FromPB(v.BaseInfo);
		m_SpawnArr.Clear();
		for( int i=0; i<v.SpawnArr.Count; i++)
			m_SpawnArr.Add( new MMOMapDataSpawnInfoWraperV1());
		for( int i=0; i<v.SpawnArr.Count; i++)
			m_SpawnArr[i].FromPB(v.SpawnArr[i]);
		m_PortalArr.Clear();
		for( int i=0; i<v.PortalArr.Count; i++)
			m_PortalArr.Add( new MMOMapDataPortalInfoWraperV1());
		for( int i=0; i<v.PortalArr.Count; i++)
			m_PortalArr[i].FromPB(v.PortalArr[i]);
		m_DefeatInfo.FromPB(v.DefeatInfo);
		m_NodeArr.Clear();
		for( int i=0; i<v.NodeArr.Count; i++)
			m_NodeArr.Add( new MMOMapDataNodeInfoWraperV1());
		for( int i=0; i<v.NodeArr.Count; i++)
			m_NodeArr[i].FromPB(v.NodeArr[i]);
		m_PointArr.Clear();
		for( int i=0; i<v.PointArr.Count; i++)
			m_PointArr.Add( new MMOMapDataPointInfoWraperV1());
		for( int i=0; i<v.PointArr.Count; i++)
			m_PointArr[i].FromPB(v.PointArr[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MMOMapDataInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MMOMapDataInfoV1 pb = ProtoBuf.Serializer.Deserialize<MMOMapDataInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//基础信息
	public MMOMapDataBaseDataWraperV1 m_BaseInfo;
	public MMOMapDataBaseDataWraperV1 BaseInfo
	{
		get { return m_BaseInfo;}
		set { m_BaseInfo = value; }
	}
	//出生点信息
	public List<MMOMapDataSpawnInfoWraperV1> m_SpawnArr;
	public int SizeSpawnArr()
	{
		return m_SpawnArr.Count;
	}
	public List<MMOMapDataSpawnInfoWraperV1> GetSpawnArr()
	{
		return m_SpawnArr;
	}
	public MMOMapDataSpawnInfoWraperV1 GetSpawnArr(int Index)
	{
		if(Index<0 || Index>=(int)m_SpawnArr.Count)
			return new MMOMapDataSpawnInfoWraperV1();
		return m_SpawnArr[Index];
	}
	public void SetSpawnArr( List<MMOMapDataSpawnInfoWraperV1> v )
	{
		m_SpawnArr=v;
	}
	public void SetSpawnArr( int Index, MMOMapDataSpawnInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_SpawnArr.Count)
			return;
		m_SpawnArr[Index] = v;
	}
	public void AddSpawnArr( MMOMapDataSpawnInfoWraperV1 v )
	{
		m_SpawnArr.Add(v);
	}
	public void ClearSpawnArr( )
	{
		m_SpawnArr.Clear();
	}
	//传送信息
	public List<MMOMapDataPortalInfoWraperV1> m_PortalArr;
	public int SizePortalArr()
	{
		return m_PortalArr.Count;
	}
	public List<MMOMapDataPortalInfoWraperV1> GetPortalArr()
	{
		return m_PortalArr;
	}
	public MMOMapDataPortalInfoWraperV1 GetPortalArr(int Index)
	{
		if(Index<0 || Index>=(int)m_PortalArr.Count)
			return new MMOMapDataPortalInfoWraperV1();
		return m_PortalArr[Index];
	}
	public void SetPortalArr( List<MMOMapDataPortalInfoWraperV1> v )
	{
		m_PortalArr=v;
	}
	public void SetPortalArr( int Index, MMOMapDataPortalInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_PortalArr.Count)
			return;
		m_PortalArr[Index] = v;
	}
	public void AddPortalArr( MMOMapDataPortalInfoWraperV1 v )
	{
		m_PortalArr.Add(v);
	}
	public void ClearPortalArr( )
	{
		m_PortalArr.Clear();
	}
	//失败条件
	public MMOMapDataDefeatInfoWraperV1 m_DefeatInfo;
	public MMOMapDataDefeatInfoWraperV1 DefeatInfo
	{
		get { return m_DefeatInfo;}
		set { m_DefeatInfo = value; }
	}
	//节点信息
	public List<MMOMapDataNodeInfoWraperV1> m_NodeArr;
	public int SizeNodeArr()
	{
		return m_NodeArr.Count;
	}
	public List<MMOMapDataNodeInfoWraperV1> GetNodeArr()
	{
		return m_NodeArr;
	}
	public MMOMapDataNodeInfoWraperV1 GetNodeArr(int Index)
	{
		if(Index<0 || Index>=(int)m_NodeArr.Count)
			return new MMOMapDataNodeInfoWraperV1();
		return m_NodeArr[Index];
	}
	public void SetNodeArr( List<MMOMapDataNodeInfoWraperV1> v )
	{
		m_NodeArr=v;
	}
	public void SetNodeArr( int Index, MMOMapDataNodeInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_NodeArr.Count)
			return;
		m_NodeArr[Index] = v;
	}
	public void AddNodeArr( MMOMapDataNodeInfoWraperV1 v )
	{
		m_NodeArr.Add(v);
	}
	public void ClearNodeArr( )
	{
		m_NodeArr.Clear();
	}
	//坑点信息
	public List<MMOMapDataPointInfoWraperV1> m_PointArr;
	public int SizePointArr()
	{
		return m_PointArr.Count;
	}
	public List<MMOMapDataPointInfoWraperV1> GetPointArr()
	{
		return m_PointArr;
	}
	public MMOMapDataPointInfoWraperV1 GetPointArr(int Index)
	{
		if(Index<0 || Index>=(int)m_PointArr.Count)
			return new MMOMapDataPointInfoWraperV1();
		return m_PointArr[Index];
	}
	public void SetPointArr( List<MMOMapDataPointInfoWraperV1> v )
	{
		m_PointArr=v;
	}
	public void SetPointArr( int Index, MMOMapDataPointInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_PointArr.Count)
			return;
		m_PointArr[Index] = v;
	}
	public void AddPointArr( MMOMapDataPointInfoWraperV1 v )
	{
		m_PointArr.Add(v);
	}
	public void ClearPointArr( )
	{
		m_PointArr.Clear();
	}


};
//失败信息封装类
[System.Serializable]
public class MMOMapDataDefeatInfoWraperV1
{

	//构造函数
	public MMOMapDataDefeatInfoWraperV1()
	{
		 m_DefeatConditionSpared = false;
		 m_DefeatConditionTimeOver = false;
		 m_DefeatConditionHP = false;
		 m_DefeatTime = 0;
		 m_DefeatID = 0;
		 m_DefeatHP = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_DefeatConditionSpared = false;
		 m_DefeatConditionTimeOver = false;
		 m_DefeatConditionHP = false;
		 m_DefeatTime = 0;
		 m_DefeatID = 0;
		 m_DefeatHP = 0;

	}

 	//转化成Protobuffer类型函数
	public MMOMapDataDefeatInfoV1 ToPB()
	{
		MMOMapDataDefeatInfoV1 v = new MMOMapDataDefeatInfoV1();
		v.DefeatConditionSpared = m_DefeatConditionSpared;
		v.DefeatConditionTimeOver = m_DefeatConditionTimeOver;
		v.DefeatConditionHP = m_DefeatConditionHP;
		v.DefeatTime = m_DefeatTime;
		v.DefeatID = m_DefeatID;
		v.DefeatHP = m_DefeatHP;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MMOMapDataDefeatInfoV1 v)
	{
        if (v == null)
            return;
		m_DefeatConditionSpared = v.DefeatConditionSpared;
		m_DefeatConditionTimeOver = v.DefeatConditionTimeOver;
		m_DefeatConditionHP = v.DefeatConditionHP;
		m_DefeatTime = v.DefeatTime;
		m_DefeatID = v.DefeatID;
		m_DefeatHP = v.DefeatHP;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MMOMapDataDefeatInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MMOMapDataDefeatInfoV1 pb = ProtoBuf.Serializer.Deserialize<MMOMapDataDefeatInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//所有角色死亡
	public bool m_DefeatConditionSpared;
	public bool DefeatConditionSpared
	{
		get { return m_DefeatConditionSpared;}
		set { m_DefeatConditionSpared = value; }
	}
	//失败条件到时
	public bool m_DefeatConditionTimeOver;
	public bool DefeatConditionTimeOver
	{
		get { return m_DefeatConditionTimeOver;}
		set { m_DefeatConditionTimeOver = value; }
	}
	//失败条件血量
	public bool m_DefeatConditionHP;
	public bool DefeatConditionHP
	{
		get { return m_DefeatConditionHP;}
		set { m_DefeatConditionHP = value; }
	}
	//失败条件时间
	public int m_DefeatTime;
	public int DefeatTime
	{
		get { return m_DefeatTime;}
		set { m_DefeatTime = value; }
	}
	//失败条件ID
	public int m_DefeatID;
	public int DefeatID
	{
		get { return m_DefeatID;}
		set { m_DefeatID = value; }
	}
	//失败条件血量
	public int m_DefeatHP;
	public int DefeatHP
	{
		get { return m_DefeatHP;}
		set { m_DefeatHP = value; }
	}


};
