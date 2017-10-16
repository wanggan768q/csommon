
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperSyncPBMapData.cs
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


//层数据封装类
[System.Serializable]
public class MapDataLayerInfoWraperV1
{

	//构造函数
	public MapDataLayerInfoWraperV1()
	{
		m_WalkArea = new List<MapDataVector2WraperV1>();
		m_LostArea = new List<MapDataVector2WraperV1>();
		 m_ClientHight = (float)0;
		 m_X = (float)0;
		 m_Z = (float)0;
		 m_Y = (float)0;
		 m_MinHeightLimit = (float)0;
		 m_MaxHeightLimit = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		m_WalkArea = new List<MapDataVector2WraperV1>();
		m_LostArea = new List<MapDataVector2WraperV1>();
		 m_ClientHight = (float)0;
		 m_X = (float)0;
		 m_Z = (float)0;
		 m_Y = (float)0;
		 m_MinHeightLimit = (float)0;
		 m_MaxHeightLimit = (float)0;

	}

 	//转化成Protobuffer类型函数
	public MapDataLayerInfoV1 ToPB()
	{
		MapDataLayerInfoV1 v = new MapDataLayerInfoV1();
		for (int i=0; i<(int)m_WalkArea.Count; i++)
			v.WalkArea.Add( m_WalkArea[i].ToPB());
		for (int i=0; i<(int)m_LostArea.Count; i++)
			v.LostArea.Add( m_LostArea[i].ToPB());
		v.ClientHight = m_ClientHight;
		v.X = m_X;
		v.Z = m_Z;
		v.Y = m_Y;
		v.MinHeightLimit = m_MinHeightLimit;
		v.MaxHeightLimit = m_MaxHeightLimit;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataLayerInfoV1 v)
	{
        if (v == null)
            return;
		m_WalkArea.Clear();
		for( int i=0; i<v.WalkArea.Count; i++)
			m_WalkArea.Add( new MapDataVector2WraperV1());
		for( int i=0; i<v.WalkArea.Count; i++)
			m_WalkArea[i].FromPB(v.WalkArea[i]);
		m_LostArea.Clear();
		for( int i=0; i<v.LostArea.Count; i++)
			m_LostArea.Add( new MapDataVector2WraperV1());
		for( int i=0; i<v.LostArea.Count; i++)
			m_LostArea[i].FromPB(v.LostArea[i]);
		m_ClientHight = v.ClientHight;
		m_X = v.X;
		m_Z = v.Z;
		m_Y = v.Y;
		m_MinHeightLimit = v.MinHeightLimit;
		m_MaxHeightLimit = v.MaxHeightLimit;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataLayerInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataLayerInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataLayerInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//可行走区
	public List<MapDataVector2WraperV1> m_WalkArea;
	public int SizeWalkArea()
	{
		return m_WalkArea.Count;
	}
	public List<MapDataVector2WraperV1> GetWalkArea()
	{
		return m_WalkArea;
	}
	public MapDataVector2WraperV1 GetWalkArea(int Index)
	{
		if(Index<0 || Index>=(int)m_WalkArea.Count)
			return new MapDataVector2WraperV1();
		return m_WalkArea[Index];
	}
	public void SetWalkArea( List<MapDataVector2WraperV1> v )
	{
		m_WalkArea=v;
	}
	public void SetWalkArea( int Index, MapDataVector2WraperV1 v )
	{
		if(Index<0 || Index>=(int)m_WalkArea.Count)
			return;
		m_WalkArea[Index] = v;
	}
	public void AddWalkArea( MapDataVector2WraperV1 v )
	{
		m_WalkArea.Add(v);
	}
	public void ClearWalkArea( )
	{
		m_WalkArea.Clear();
	}
	//可掉落区
	public List<MapDataVector2WraperV1> m_LostArea;
	public int SizeLostArea()
	{
		return m_LostArea.Count;
	}
	public List<MapDataVector2WraperV1> GetLostArea()
	{
		return m_LostArea;
	}
	public MapDataVector2WraperV1 GetLostArea(int Index)
	{
		if(Index<0 || Index>=(int)m_LostArea.Count)
			return new MapDataVector2WraperV1();
		return m_LostArea[Index];
	}
	public void SetLostArea( List<MapDataVector2WraperV1> v )
	{
		m_LostArea=v;
	}
	public void SetLostArea( int Index, MapDataVector2WraperV1 v )
	{
		if(Index<0 || Index>=(int)m_LostArea.Count)
			return;
		m_LostArea[Index] = v;
	}
	public void AddLostArea( MapDataVector2WraperV1 v )
	{
		m_LostArea.Add(v);
	}
	public void ClearLostArea( )
	{
		m_LostArea.Clear();
	}
	//ClientHight
	public float m_ClientHight;
	public float ClientHight
	{
		get { return m_ClientHight;}
		set { m_ClientHight = value; }
	}
	//X轴
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Z轴
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//Y轴
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}
	//最小高度限制
	public float m_MinHeightLimit;
	public float MinHeightLimit
	{
		get { return m_MinHeightLimit;}
		set { m_MinHeightLimit = value; }
	}
	//最大高度限制
	public float m_MaxHeightLimit;
	public float MaxHeightLimit
	{
		get { return m_MaxHeightLimit;}
		set { m_MaxHeightLimit = value; }
	}


};
//场景信息封装类
[System.Serializable]
public class MapDataInfoWraperV1
{

	//构造函数
	public MapDataInfoWraperV1()
	{
		m_LayerArr = new List<MapDataLayerInfoWraperV1>();
		m_SpawnArr = new List<MapDataSpawnInfoWraperV1>();
		 m_Defeat = new MapDataDefeatInfoWraperV1();
		m_PerfectArr = new List<MapDataPerfectInfoWraperV1>();
		m_PortalArr = new List<MapDataPortalInfoWraperV1>();
		m_TrapArr = new List<MapDataTrapInfoWraperV1>();
		m_NpcArr = new List<MapDataNpcInfoWraperV1>();
		m_NodeArr = new List<MapDataNodeInfoWraperV1>();
		 m_Name = "";
		m_StormBaseArr = new List<MapDataTerritorialInfoWraperV1>();
		 m_StormFlag = new MapDataTerritorialInfoWraperV1();
		 m_BaseConfig = new MapDataBaseConfigWraperV1();
		m_GatherArr = new List<MapDataGatherInfoWraperV1>();
		m_EventArr = new List<MapDataEventInfoWraperV1>();

	}

	//重置函数
	public void ResetWraper()
	{
		m_LayerArr = new List<MapDataLayerInfoWraperV1>();
		m_SpawnArr = new List<MapDataSpawnInfoWraperV1>();
		 m_Defeat = new MapDataDefeatInfoWraperV1();
		m_PerfectArr = new List<MapDataPerfectInfoWraperV1>();
		m_PortalArr = new List<MapDataPortalInfoWraperV1>();
		m_TrapArr = new List<MapDataTrapInfoWraperV1>();
		m_NpcArr = new List<MapDataNpcInfoWraperV1>();
		m_NodeArr = new List<MapDataNodeInfoWraperV1>();
		 m_Name = "";
		m_StormBaseArr = new List<MapDataTerritorialInfoWraperV1>();
		 m_StormFlag = new MapDataTerritorialInfoWraperV1();
		 m_BaseConfig = new MapDataBaseConfigWraperV1();
		m_GatherArr = new List<MapDataGatherInfoWraperV1>();
		m_EventArr = new List<MapDataEventInfoWraperV1>();

	}

 	//转化成Protobuffer类型函数
	public MapDataInfoV1 ToPB()
	{
		MapDataInfoV1 v = new MapDataInfoV1();
		for (int i=0; i<(int)m_LayerArr.Count; i++)
			v.LayerArr.Add( m_LayerArr[i].ToPB());
		for (int i=0; i<(int)m_SpawnArr.Count; i++)
			v.SpawnArr.Add( m_SpawnArr[i].ToPB());
		v.Defeat = m_Defeat.ToPB();
		for (int i=0; i<(int)m_PerfectArr.Count; i++)
			v.PerfectArr.Add( m_PerfectArr[i].ToPB());
		for (int i=0; i<(int)m_PortalArr.Count; i++)
			v.PortalArr.Add( m_PortalArr[i].ToPB());
		for (int i=0; i<(int)m_TrapArr.Count; i++)
			v.TrapArr.Add( m_TrapArr[i].ToPB());
		for (int i=0; i<(int)m_NpcArr.Count; i++)
			v.NpcArr.Add( m_NpcArr[i].ToPB());
		for (int i=0; i<(int)m_NodeArr.Count; i++)
			v.NodeArr.Add( m_NodeArr[i].ToPB());
		v.Name = m_Name;
		for (int i=0; i<(int)m_StormBaseArr.Count; i++)
			v.StormBaseArr.Add( m_StormBaseArr[i].ToPB());
		v.StormFlag = m_StormFlag.ToPB();
		v.BaseConfig = m_BaseConfig.ToPB();
		for (int i=0; i<(int)m_GatherArr.Count; i++)
			v.GatherArr.Add( m_GatherArr[i].ToPB());
		for (int i=0; i<(int)m_EventArr.Count; i++)
			v.EventArr.Add( m_EventArr[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataInfoV1 v)
	{
        if (v == null)
            return;
		m_LayerArr.Clear();
		for( int i=0; i<v.LayerArr.Count; i++)
			m_LayerArr.Add( new MapDataLayerInfoWraperV1());
		for( int i=0; i<v.LayerArr.Count; i++)
			m_LayerArr[i].FromPB(v.LayerArr[i]);
		m_SpawnArr.Clear();
		for( int i=0; i<v.SpawnArr.Count; i++)
			m_SpawnArr.Add( new MapDataSpawnInfoWraperV1());
		for( int i=0; i<v.SpawnArr.Count; i++)
			m_SpawnArr[i].FromPB(v.SpawnArr[i]);
		m_Defeat.FromPB(v.Defeat);
		m_PerfectArr.Clear();
		for( int i=0; i<v.PerfectArr.Count; i++)
			m_PerfectArr.Add( new MapDataPerfectInfoWraperV1());
		for( int i=0; i<v.PerfectArr.Count; i++)
			m_PerfectArr[i].FromPB(v.PerfectArr[i]);
		m_PortalArr.Clear();
		for( int i=0; i<v.PortalArr.Count; i++)
			m_PortalArr.Add( new MapDataPortalInfoWraperV1());
		for( int i=0; i<v.PortalArr.Count; i++)
			m_PortalArr[i].FromPB(v.PortalArr[i]);
		m_TrapArr.Clear();
		for( int i=0; i<v.TrapArr.Count; i++)
			m_TrapArr.Add( new MapDataTrapInfoWraperV1());
		for( int i=0; i<v.TrapArr.Count; i++)
			m_TrapArr[i].FromPB(v.TrapArr[i]);
		m_NpcArr.Clear();
		for( int i=0; i<v.NpcArr.Count; i++)
			m_NpcArr.Add( new MapDataNpcInfoWraperV1());
		for( int i=0; i<v.NpcArr.Count; i++)
			m_NpcArr[i].FromPB(v.NpcArr[i]);
		m_NodeArr.Clear();
		for( int i=0; i<v.NodeArr.Count; i++)
			m_NodeArr.Add( new MapDataNodeInfoWraperV1());
		for( int i=0; i<v.NodeArr.Count; i++)
			m_NodeArr[i].FromPB(v.NodeArr[i]);
		m_Name = v.Name;
		m_StormBaseArr.Clear();
		for( int i=0; i<v.StormBaseArr.Count; i++)
			m_StormBaseArr.Add( new MapDataTerritorialInfoWraperV1());
		for( int i=0; i<v.StormBaseArr.Count; i++)
			m_StormBaseArr[i].FromPB(v.StormBaseArr[i]);
		m_StormFlag.FromPB(v.StormFlag);
		m_BaseConfig.FromPB(v.BaseConfig);
		m_GatherArr.Clear();
		for( int i=0; i<v.GatherArr.Count; i++)
			m_GatherArr.Add( new MapDataGatherInfoWraperV1());
		for( int i=0; i<v.GatherArr.Count; i++)
			m_GatherArr[i].FromPB(v.GatherArr[i]);
		m_EventArr.Clear();
		for( int i=0; i<v.EventArr.Count; i++)
			m_EventArr.Add( new MapDataEventInfoWraperV1());
		for( int i=0; i<v.EventArr.Count; i++)
			m_EventArr[i].FromPB(v.EventArr[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//层
	public List<MapDataLayerInfoWraperV1> m_LayerArr;
	public int SizeLayerArr()
	{
		return m_LayerArr.Count;
	}
	public List<MapDataLayerInfoWraperV1> GetLayerArr()
	{
		return m_LayerArr;
	}
	public MapDataLayerInfoWraperV1 GetLayerArr(int Index)
	{
		if(Index<0 || Index>=(int)m_LayerArr.Count)
			return new MapDataLayerInfoWraperV1();
		return m_LayerArr[Index];
	}
	public void SetLayerArr( List<MapDataLayerInfoWraperV1> v )
	{
		m_LayerArr=v;
	}
	public void SetLayerArr( int Index, MapDataLayerInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_LayerArr.Count)
			return;
		m_LayerArr[Index] = v;
	}
	public void AddLayerArr( MapDataLayerInfoWraperV1 v )
	{
		m_LayerArr.Add(v);
	}
	public void ClearLayerArr( )
	{
		m_LayerArr.Clear();
	}
	//SpawnArr
	public List<MapDataSpawnInfoWraperV1> m_SpawnArr;
	public int SizeSpawnArr()
	{
		return m_SpawnArr.Count;
	}
	public List<MapDataSpawnInfoWraperV1> GetSpawnArr()
	{
		return m_SpawnArr;
	}
	public MapDataSpawnInfoWraperV1 GetSpawnArr(int Index)
	{
		if(Index<0 || Index>=(int)m_SpawnArr.Count)
			return new MapDataSpawnInfoWraperV1();
		return m_SpawnArr[Index];
	}
	public void SetSpawnArr( List<MapDataSpawnInfoWraperV1> v )
	{
		m_SpawnArr=v;
	}
	public void SetSpawnArr( int Index, MapDataSpawnInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_SpawnArr.Count)
			return;
		m_SpawnArr[Index] = v;
	}
	public void AddSpawnArr( MapDataSpawnInfoWraperV1 v )
	{
		m_SpawnArr.Add(v);
	}
	public void ClearSpawnArr( )
	{
		m_SpawnArr.Clear();
	}
	//Defeat
	public MapDataDefeatInfoWraperV1 m_Defeat;
	public MapDataDefeatInfoWraperV1 Defeat
	{
		get { return m_Defeat;}
		set { m_Defeat = value; }
	}
	//PerfectArr
	public List<MapDataPerfectInfoWraperV1> m_PerfectArr;
	public int SizePerfectArr()
	{
		return m_PerfectArr.Count;
	}
	public List<MapDataPerfectInfoWraperV1> GetPerfectArr()
	{
		return m_PerfectArr;
	}
	public MapDataPerfectInfoWraperV1 GetPerfectArr(int Index)
	{
		if(Index<0 || Index>=(int)m_PerfectArr.Count)
			return new MapDataPerfectInfoWraperV1();
		return m_PerfectArr[Index];
	}
	public void SetPerfectArr( List<MapDataPerfectInfoWraperV1> v )
	{
		m_PerfectArr=v;
	}
	public void SetPerfectArr( int Index, MapDataPerfectInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_PerfectArr.Count)
			return;
		m_PerfectArr[Index] = v;
	}
	public void AddPerfectArr( MapDataPerfectInfoWraperV1 v )
	{
		m_PerfectArr.Add(v);
	}
	public void ClearPerfectArr( )
	{
		m_PerfectArr.Clear();
	}
	//PortalArr
	public List<MapDataPortalInfoWraperV1> m_PortalArr;
	public int SizePortalArr()
	{
		return m_PortalArr.Count;
	}
	public List<MapDataPortalInfoWraperV1> GetPortalArr()
	{
		return m_PortalArr;
	}
	public MapDataPortalInfoWraperV1 GetPortalArr(int Index)
	{
		if(Index<0 || Index>=(int)m_PortalArr.Count)
			return new MapDataPortalInfoWraperV1();
		return m_PortalArr[Index];
	}
	public void SetPortalArr( List<MapDataPortalInfoWraperV1> v )
	{
		m_PortalArr=v;
	}
	public void SetPortalArr( int Index, MapDataPortalInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_PortalArr.Count)
			return;
		m_PortalArr[Index] = v;
	}
	public void AddPortalArr( MapDataPortalInfoWraperV1 v )
	{
		m_PortalArr.Add(v);
	}
	public void ClearPortalArr( )
	{
		m_PortalArr.Clear();
	}
	//TrapArr
	public List<MapDataTrapInfoWraperV1> m_TrapArr;
	public int SizeTrapArr()
	{
		return m_TrapArr.Count;
	}
	public List<MapDataTrapInfoWraperV1> GetTrapArr()
	{
		return m_TrapArr;
	}
	public MapDataTrapInfoWraperV1 GetTrapArr(int Index)
	{
		if(Index<0 || Index>=(int)m_TrapArr.Count)
			return new MapDataTrapInfoWraperV1();
		return m_TrapArr[Index];
	}
	public void SetTrapArr( List<MapDataTrapInfoWraperV1> v )
	{
		m_TrapArr=v;
	}
	public void SetTrapArr( int Index, MapDataTrapInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_TrapArr.Count)
			return;
		m_TrapArr[Index] = v;
	}
	public void AddTrapArr( MapDataTrapInfoWraperV1 v )
	{
		m_TrapArr.Add(v);
	}
	public void ClearTrapArr( )
	{
		m_TrapArr.Clear();
	}
	//NpcArr
	public List<MapDataNpcInfoWraperV1> m_NpcArr;
	public int SizeNpcArr()
	{
		return m_NpcArr.Count;
	}
	public List<MapDataNpcInfoWraperV1> GetNpcArr()
	{
		return m_NpcArr;
	}
	public MapDataNpcInfoWraperV1 GetNpcArr(int Index)
	{
		if(Index<0 || Index>=(int)m_NpcArr.Count)
			return new MapDataNpcInfoWraperV1();
		return m_NpcArr[Index];
	}
	public void SetNpcArr( List<MapDataNpcInfoWraperV1> v )
	{
		m_NpcArr=v;
	}
	public void SetNpcArr( int Index, MapDataNpcInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_NpcArr.Count)
			return;
		m_NpcArr[Index] = v;
	}
	public void AddNpcArr( MapDataNpcInfoWraperV1 v )
	{
		m_NpcArr.Add(v);
	}
	public void ClearNpcArr( )
	{
		m_NpcArr.Clear();
	}
	//NodeArr
	public List<MapDataNodeInfoWraperV1> m_NodeArr;
	public int SizeNodeArr()
	{
		return m_NodeArr.Count;
	}
	public List<MapDataNodeInfoWraperV1> GetNodeArr()
	{
		return m_NodeArr;
	}
	public MapDataNodeInfoWraperV1 GetNodeArr(int Index)
	{
		if(Index<0 || Index>=(int)m_NodeArr.Count)
			return new MapDataNodeInfoWraperV1();
		return m_NodeArr[Index];
	}
	public void SetNodeArr( List<MapDataNodeInfoWraperV1> v )
	{
		m_NodeArr=v;
	}
	public void SetNodeArr( int Index, MapDataNodeInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_NodeArr.Count)
			return;
		m_NodeArr[Index] = v;
	}
	public void AddNodeArr( MapDataNodeInfoWraperV1 v )
	{
		m_NodeArr.Add(v);
	}
	public void ClearNodeArr( )
	{
		m_NodeArr.Clear();
	}
	//Name
	public string m_Name;
	public string Name
	{
		get { return m_Name;}
		set { m_Name = value; }
	}
	//领地
	public List<MapDataTerritorialInfoWraperV1> m_StormBaseArr;
	public int SizeStormBaseArr()
	{
		return m_StormBaseArr.Count;
	}
	public List<MapDataTerritorialInfoWraperV1> GetStormBaseArr()
	{
		return m_StormBaseArr;
	}
	public MapDataTerritorialInfoWraperV1 GetStormBaseArr(int Index)
	{
		if(Index<0 || Index>=(int)m_StormBaseArr.Count)
			return new MapDataTerritorialInfoWraperV1();
		return m_StormBaseArr[Index];
	}
	public void SetStormBaseArr( List<MapDataTerritorialInfoWraperV1> v )
	{
		m_StormBaseArr=v;
	}
	public void SetStormBaseArr( int Index, MapDataTerritorialInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_StormBaseArr.Count)
			return;
		m_StormBaseArr[Index] = v;
	}
	public void AddStormBaseArr( MapDataTerritorialInfoWraperV1 v )
	{
		m_StormBaseArr.Add(v);
	}
	public void ClearStormBaseArr( )
	{
		m_StormBaseArr.Clear();
	}
	//旗子
	public MapDataTerritorialInfoWraperV1 m_StormFlag;
	public MapDataTerritorialInfoWraperV1 StormFlag
	{
		get { return m_StormFlag;}
		set { m_StormFlag = value; }
	}
	//基础配置
	public MapDataBaseConfigWraperV1 m_BaseConfig;
	public MapDataBaseConfigWraperV1 BaseConfig
	{
		get { return m_BaseConfig;}
		set { m_BaseConfig = value; }
	}
	//采集物数据
	public List<MapDataGatherInfoWraperV1> m_GatherArr;
	public int SizeGatherArr()
	{
		return m_GatherArr.Count;
	}
	public List<MapDataGatherInfoWraperV1> GetGatherArr()
	{
		return m_GatherArr;
	}
	public MapDataGatherInfoWraperV1 GetGatherArr(int Index)
	{
		if(Index<0 || Index>=(int)m_GatherArr.Count)
			return new MapDataGatherInfoWraperV1();
		return m_GatherArr[Index];
	}
	public void SetGatherArr( List<MapDataGatherInfoWraperV1> v )
	{
		m_GatherArr=v;
	}
	public void SetGatherArr( int Index, MapDataGatherInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_GatherArr.Count)
			return;
		m_GatherArr[Index] = v;
	}
	public void AddGatherArr( MapDataGatherInfoWraperV1 v )
	{
		m_GatherArr.Add(v);
	}
	public void ClearGatherArr( )
	{
		m_GatherArr.Clear();
	}
	//事件信息
	public List<MapDataEventInfoWraperV1> m_EventArr;
	public int SizeEventArr()
	{
		return m_EventArr.Count;
	}
	public List<MapDataEventInfoWraperV1> GetEventArr()
	{
		return m_EventArr;
	}
	public MapDataEventInfoWraperV1 GetEventArr(int Index)
	{
		if(Index<0 || Index>=(int)m_EventArr.Count)
			return new MapDataEventInfoWraperV1();
		return m_EventArr[Index];
	}
	public void SetEventArr( List<MapDataEventInfoWraperV1> v )
	{
		m_EventArr=v;
	}
	public void SetEventArr( int Index, MapDataEventInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_EventArr.Count)
			return;
		m_EventArr[Index] = v;
	}
	public void AddEventArr( MapDataEventInfoWraperV1 v )
	{
		m_EventArr.Add(v);
	}
	public void ClearEventArr( )
	{
		m_EventArr.Clear();
	}


};
//Vector2封装类
[System.Serializable]
public class MapDataVector2WraperV1
{

	//构造函数
	public MapDataVector2WraperV1()
	{
		 m_X1 = (float)0;
		 m_X2 = (float)0;
		 m_Z1 = (float)0;
		 m_Z2 = (float)0;
		 m_OrgAngle = (float)0;
		 m_FinAngle = (float)0;
		 m_Radius = (float)0;
		m_ContourLineArr = new List<MapDataContourLineInfoWraperV1>();

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X1 = (float)0;
		 m_X2 = (float)0;
		 m_Z1 = (float)0;
		 m_Z2 = (float)0;
		 m_OrgAngle = (float)0;
		 m_FinAngle = (float)0;
		 m_Radius = (float)0;
		m_ContourLineArr = new List<MapDataContourLineInfoWraperV1>();

	}

 	//转化成Protobuffer类型函数
	public MapDataVector2V1 ToPB()
	{
		MapDataVector2V1 v = new MapDataVector2V1();
		v.X1 = m_X1;
		v.X2 = m_X2;
		v.Z1 = m_Z1;
		v.Z2 = m_Z2;
		v.OrgAngle = m_OrgAngle;
		v.FinAngle = m_FinAngle;
		v.Radius = m_Radius;
		for (int i=0; i<(int)m_ContourLineArr.Count; i++)
			v.ContourLineArr.Add( m_ContourLineArr[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataVector2V1 v)
	{
        if (v == null)
            return;
		m_X1 = v.X1;
		m_X2 = v.X2;
		m_Z1 = v.Z1;
		m_Z2 = v.Z2;
		m_OrgAngle = v.OrgAngle;
		m_FinAngle = v.FinAngle;
		m_Radius = v.Radius;
		m_ContourLineArr.Clear();
		for( int i=0; i<v.ContourLineArr.Count; i++)
			m_ContourLineArr.Add( new MapDataContourLineInfoWraperV1());
		for( int i=0; i<v.ContourLineArr.Count; i++)
			m_ContourLineArr[i].FromPB(v.ContourLineArr[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataVector2V1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataVector2V1 pb = ProtoBuf.Serializer.Deserialize<MapDataVector2V1>(protoMS);
		FromPB(pb);
		return true;
	}

	//X1
	public float m_X1;
	public float X1
	{
		get { return m_X1;}
		set { m_X1 = value; }
	}
	//X2
	public float m_X2;
	public float X2
	{
		get { return m_X2;}
		set { m_X2 = value; }
	}
	//Z1
	public float m_Z1;
	public float Z1
	{
		get { return m_Z1;}
		set { m_Z1 = value; }
	}
	//Z2
	public float m_Z2;
	public float Z2
	{
		get { return m_Z2;}
		set { m_Z2 = value; }
	}
	//起始角度
	public float m_OrgAngle;
	public float OrgAngle
	{
		get { return m_OrgAngle;}
		set { m_OrgAngle = value; }
	}
	//终点角度
	public float m_FinAngle;
	public float FinAngle
	{
		get { return m_FinAngle;}
		set { m_FinAngle = value; }
	}
	//半径
	public float m_Radius;
	public float Radius
	{
		get { return m_Radius;}
		set { m_Radius = value; }
	}
	//等高线信息
	public List<MapDataContourLineInfoWraperV1> m_ContourLineArr;
	public int SizeContourLineArr()
	{
		return m_ContourLineArr.Count;
	}
	public List<MapDataContourLineInfoWraperV1> GetContourLineArr()
	{
		return m_ContourLineArr;
	}
	public MapDataContourLineInfoWraperV1 GetContourLineArr(int Index)
	{
		if(Index<0 || Index>=(int)m_ContourLineArr.Count)
			return new MapDataContourLineInfoWraperV1();
		return m_ContourLineArr[Index];
	}
	public void SetContourLineArr( List<MapDataContourLineInfoWraperV1> v )
	{
		m_ContourLineArr=v;
	}
	public void SetContourLineArr( int Index, MapDataContourLineInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_ContourLineArr.Count)
			return;
		m_ContourLineArr[Index] = v;
	}
	public void AddContourLineArr( MapDataContourLineInfoWraperV1 v )
	{
		m_ContourLineArr.Add(v);
	}
	public void ClearContourLineArr( )
	{
		m_ContourLineArr.Clear();
	}


};
//SpawnInfo封装类
[System.Serializable]
public class MapDataSpawnInfoWraperV1
{

	//构造函数
	public MapDataSpawnInfoWraperV1()
	{
		 m_X = (float)0;
		 m_Layer = 0;
		 m_SpawnDirection = 1;
		 m_Z = (float)0;
		 m_Radius = (float)0;
		 m_Angle = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X = (float)0;
		 m_Layer = 0;
		 m_SpawnDirection = 1;
		 m_Z = (float)0;
		 m_Radius = (float)0;
		 m_Angle = (float)0;

	}

 	//转化成Protobuffer类型函数
	public MapDataSpawnInfoV1 ToPB()
	{
		MapDataSpawnInfoV1 v = new MapDataSpawnInfoV1();
		v.X = m_X;
		v.Layer = m_Layer;
		v.SpawnDirection = m_SpawnDirection;
		v.Z = m_Z;
		v.Radius = m_Radius;
		v.Angle = m_Angle;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataSpawnInfoV1 v)
	{
        if (v == null)
            return;
		m_X = v.X;
		m_Layer = v.Layer;
		m_SpawnDirection = v.SpawnDirection;
		m_Z = v.Z;
		m_Radius = v.Radius;
		m_Angle = v.Angle;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataSpawnInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataSpawnInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataSpawnInfoV1>(protoMS);
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
	//Layer
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}
	//出生时的朝向
	public int m_SpawnDirection;
	public int SpawnDirection
	{
		get { return m_SpawnDirection;}
		set { m_SpawnDirection = value; }
	}
	//Z轴
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//半径
	public float m_Radius;
	public float Radius
	{
		get { return m_Radius;}
		set { m_Radius = value; }
	}
	//角度
	public float m_Angle;
	public float Angle
	{
		get { return m_Angle;}
		set { m_Angle = value; }
	}


};
//DefeatInfo封装类
[System.Serializable]
public class MapDataDefeatInfoWraperV1
{

	//构造函数
	public MapDataDefeatInfoWraperV1()
	{
		 m_Condition = 0;
		 m_TimeLimit = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Condition = 0;
		 m_TimeLimit = (float)0;

	}

 	//转化成Protobuffer类型函数
	public MapDataDefeatInfoV1 ToPB()
	{
		MapDataDefeatInfoV1 v = new MapDataDefeatInfoV1();
		v.Condition = m_Condition;
		v.TimeLimit = m_TimeLimit;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataDefeatInfoV1 v)
	{
        if (v == null)
            return;
		m_Condition = v.Condition;
		m_TimeLimit = v.TimeLimit;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataDefeatInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataDefeatInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataDefeatInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//Condition
	public int m_Condition;
	public int Condition
	{
		get { return m_Condition;}
		set { m_Condition = value; }
	}
	//TimeLimit
	public float m_TimeLimit;
	public float TimeLimit
	{
		get { return m_TimeLimit;}
		set { m_TimeLimit = value; }
	}


};
//PerfectInfo封装类
[System.Serializable]
public class MapDataPerfectInfoWraperV1
{

	//构造函数
	public MapDataPerfectInfoWraperV1()
	{
		 m_Condition = -1;
		 m_DeathCountNum = 0;
		 m_KillEnemyID = 0;
		 m_KillEnemyCount = 0;
		 m_HpPercent = 0;
		 m_TimeLimit = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Condition = -1;
		 m_DeathCountNum = 0;
		 m_KillEnemyID = 0;
		 m_KillEnemyCount = 0;
		 m_HpPercent = 0;
		 m_TimeLimit = (float)0;

	}

 	//转化成Protobuffer类型函数
	public MapDataPerfectInfoV1 ToPB()
	{
		MapDataPerfectInfoV1 v = new MapDataPerfectInfoV1();
		v.Condition = m_Condition;
		v.DeathCountNum = m_DeathCountNum;
		v.KillEnemyID = m_KillEnemyID;
		v.KillEnemyCount = m_KillEnemyCount;
		v.HpPercent = m_HpPercent;
		v.TimeLimit = m_TimeLimit;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataPerfectInfoV1 v)
	{
        if (v == null)
            return;
		m_Condition = v.Condition;
		m_DeathCountNum = v.DeathCountNum;
		m_KillEnemyID = v.KillEnemyID;
		m_KillEnemyCount = v.KillEnemyCount;
		m_HpPercent = v.HpPercent;
		m_TimeLimit = v.TimeLimit;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataPerfectInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataPerfectInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataPerfectInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//Condition
	public int m_Condition;
	public int Condition
	{
		get { return m_Condition;}
		set { m_Condition = value; }
	}
	//DeathCountNum
	public int m_DeathCountNum;
	public int DeathCountNum
	{
		get { return m_DeathCountNum;}
		set { m_DeathCountNum = value; }
	}
	//KillEnemyID
	public int m_KillEnemyID;
	public int KillEnemyID
	{
		get { return m_KillEnemyID;}
		set { m_KillEnemyID = value; }
	}
	//KillEnemyCount
	public int m_KillEnemyCount;
	public int KillEnemyCount
	{
		get { return m_KillEnemyCount;}
		set { m_KillEnemyCount = value; }
	}
	//HpPercent
	public int m_HpPercent;
	public int HpPercent
	{
		get { return m_HpPercent;}
		set { m_HpPercent = value; }
	}
	//TimeLimit
	public float m_TimeLimit;
	public float TimeLimit
	{
		get { return m_TimeLimit;}
		set { m_TimeLimit = value; }
	}


};
//PortalInfo封装类
[System.Serializable]
public class MapDataPortalInfoWraperV1
{

	//构造函数
	public MapDataPortalInfoWraperV1()
	{
		 m_SourceX = (float)0;
		 m_SourceLayer = 0;
		 m_TargetX = (float)-1;
		 m_TargetLayer = -1;
		 m_UseCount = 1;
		 m_Channel = false;
		 m_PortalType = 0;
		 m_TargetDungeonId = 0;
		 m_TargetSpawnIndex = 0;
		 m_TargetDirection = 0;
		 m_SourceZ = (float)0;
		 m_TargetZ = (float)0;
		 m_SourceAngle = (float)0;
		 m_TargetAngle = (float)0;
		 m_SourceRadius = (float)0;
		 m_TargetRadius = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_SourceX = (float)0;
		 m_SourceLayer = 0;
		 m_TargetX = (float)-1;
		 m_TargetLayer = -1;
		 m_UseCount = 1;
		 m_Channel = false;
		 m_PortalType = 0;
		 m_TargetDungeonId = 0;
		 m_TargetSpawnIndex = 0;
		 m_TargetDirection = 0;
		 m_SourceZ = (float)0;
		 m_TargetZ = (float)0;
		 m_SourceAngle = (float)0;
		 m_TargetAngle = (float)0;
		 m_SourceRadius = (float)0;
		 m_TargetRadius = (float)0;

	}

 	//转化成Protobuffer类型函数
	public MapDataPortalInfoV1 ToPB()
	{
		MapDataPortalInfoV1 v = new MapDataPortalInfoV1();
		v.SourceX = m_SourceX;
		v.SourceLayer = m_SourceLayer;
		v.TargetX = m_TargetX;
		v.TargetLayer = m_TargetLayer;
		v.UseCount = m_UseCount;
		v.Channel = m_Channel;
		v.PortalType = m_PortalType;
		v.TargetDungeonId = m_TargetDungeonId;
		v.TargetSpawnIndex = m_TargetSpawnIndex;
		v.TargetDirection = m_TargetDirection;
		v.SourceZ = m_SourceZ;
		v.TargetZ = m_TargetZ;
		v.SourceAngle = m_SourceAngle;
		v.TargetAngle = m_TargetAngle;
		v.SourceRadius = m_SourceRadius;
		v.TargetRadius = m_TargetRadius;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataPortalInfoV1 v)
	{
        if (v == null)
            return;
		m_SourceX = v.SourceX;
		m_SourceLayer = v.SourceLayer;
		m_TargetX = v.TargetX;
		m_TargetLayer = v.TargetLayer;
		m_UseCount = v.UseCount;
		m_Channel = v.Channel;
		m_PortalType = v.PortalType;
		m_TargetDungeonId = v.TargetDungeonId;
		m_TargetSpawnIndex = v.TargetSpawnIndex;
		m_TargetDirection = v.TargetDirection;
		m_SourceZ = v.SourceZ;
		m_TargetZ = v.TargetZ;
		m_SourceAngle = v.SourceAngle;
		m_TargetAngle = v.TargetAngle;
		m_SourceRadius = v.SourceRadius;
		m_TargetRadius = v.TargetRadius;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataPortalInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataPortalInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataPortalInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//SourceX
	public float m_SourceX;
	public float SourceX
	{
		get { return m_SourceX;}
		set { m_SourceX = value; }
	}
	//SourceLayer
	public int m_SourceLayer;
	public int SourceLayer
	{
		get { return m_SourceLayer;}
		set { m_SourceLayer = value; }
	}
	//TargetX
	public float m_TargetX;
	public float TargetX
	{
		get { return m_TargetX;}
		set { m_TargetX = value; }
	}
	//TargetLayer
	public int m_TargetLayer;
	public int TargetLayer
	{
		get { return m_TargetLayer;}
		set { m_TargetLayer = value; }
	}
	//UseCount
	public int m_UseCount;
	public int UseCount
	{
		get { return m_UseCount;}
		set { m_UseCount = value; }
	}
	//Channel
	public bool m_Channel;
	public bool Channel
	{
		get { return m_Channel;}
		set { m_Channel = value; }
	}
	//PortalType
	public int m_PortalType;
	public int PortalType
	{
		get { return m_PortalType;}
		set { m_PortalType = value; }
	}
	//目标副本id
	public int m_TargetDungeonId;
	public int TargetDungeonId
	{
		get { return m_TargetDungeonId;}
		set { m_TargetDungeonId = value; }
	}
	//目标出生点索引
	public int m_TargetSpawnIndex;
	public int TargetSpawnIndex
	{
		get { return m_TargetSpawnIndex;}
		set { m_TargetSpawnIndex = value; }
	}
	//传送目标点朝向
	public int m_TargetDirection;
	public int TargetDirection
	{
		get { return m_TargetDirection;}
		set { m_TargetDirection = value; }
	}
	//源Z轴
	public float m_SourceZ;
	public float SourceZ
	{
		get { return m_SourceZ;}
		set { m_SourceZ = value; }
	}
	//目标Z轴
	public float m_TargetZ;
	public float TargetZ
	{
		get { return m_TargetZ;}
		set { m_TargetZ = value; }
	}
	//源角度
	public float m_SourceAngle;
	public float SourceAngle
	{
		get { return m_SourceAngle;}
		set { m_SourceAngle = value; }
	}
	//目标角度
	public float m_TargetAngle;
	public float TargetAngle
	{
		get { return m_TargetAngle;}
		set { m_TargetAngle = value; }
	}
	//源半径
	public float m_SourceRadius;
	public float SourceRadius
	{
		get { return m_SourceRadius;}
		set { m_SourceRadius = value; }
	}
	//目标半径
	public float m_TargetRadius;
	public float TargetRadius
	{
		get { return m_TargetRadius;}
		set { m_TargetRadius = value; }
	}


};
//TrapInfo封装类
[System.Serializable]
public class MapDataTrapInfoWraperV1
{

	//构造函数
	public MapDataTrapInfoWraperV1()
	{
		 m_TrapID = 0;
		 m_X = (float)0;
		 m_Y = (float)0;
		 m_Direction = 1;
		 m_Z = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_TrapID = 0;
		 m_X = (float)0;
		 m_Y = (float)0;
		 m_Direction = 1;
		 m_Z = (float)0;

	}

 	//转化成Protobuffer类型函数
	public MapDataTrapInfoV1 ToPB()
	{
		MapDataTrapInfoV1 v = new MapDataTrapInfoV1();
		v.TrapID = m_TrapID;
		v.X = m_X;
		v.Y = m_Y;
		v.Direction = m_Direction;
		v.Z = m_Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataTrapInfoV1 v)
	{
        if (v == null)
            return;
		m_TrapID = v.TrapID;
		m_X = v.X;
		m_Y = v.Y;
		m_Direction = v.Direction;
		m_Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataTrapInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataTrapInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataTrapInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//TrapID
	public int m_TrapID;
	public int TrapID
	{
		get { return m_TrapID;}
		set { m_TrapID = value; }
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
	//朝向
	public int m_Direction;
	public int Direction
	{
		get { return m_Direction;}
		set { m_Direction = value; }
	}
	//Z轴
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}


};
//NpcInfo封装类
[System.Serializable]
public class MapDataNpcInfoWraperV1
{

	//构造函数
	public MapDataNpcInfoWraperV1()
	{
		 m_NpcID = 0;
		 m_X = (float)0;
		 m_Layer = 0;
		 m_Z = (float)0;
		 m_Direction = 1;
		 m_Angle = (float)0;
		 m_Radius = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_NpcID = 0;
		 m_X = (float)0;
		 m_Layer = 0;
		 m_Z = (float)0;
		 m_Direction = 1;
		 m_Angle = (float)0;
		 m_Radius = (float)0;

	}

 	//转化成Protobuffer类型函数
	public MapDataNpcInfoV1 ToPB()
	{
		MapDataNpcInfoV1 v = new MapDataNpcInfoV1();
		v.NpcID = m_NpcID;
		v.X = m_X;
		v.Layer = m_Layer;
		v.Z = m_Z;
		v.Direction = m_Direction;
		v.Angle = m_Angle;
		v.Radius = m_Radius;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataNpcInfoV1 v)
	{
        if (v == null)
            return;
		m_NpcID = v.NpcID;
		m_X = v.X;
		m_Layer = v.Layer;
		m_Z = v.Z;
		m_Direction = v.Direction;
		m_Angle = v.Angle;
		m_Radius = v.Radius;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataNpcInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataNpcInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataNpcInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//NpcID
	public int m_NpcID;
	public int NpcID
	{
		get { return m_NpcID;}
		set { m_NpcID = value; }
	}
	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Layer
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}
	//Z轴
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//朝向
	public int m_Direction;
	public int Direction
	{
		get { return m_Direction;}
		set { m_Direction = value; }
	}
	//角度
	public float m_Angle;
	public float Angle
	{
		get { return m_Angle;}
		set { m_Angle = value; }
	}
	//半径
	public float m_Radius;
	public float Radius
	{
		get { return m_Radius;}
		set { m_Radius = value; }
	}


};
//MonsterInfo封装类
[System.Serializable]
public class MapDataMonsterInfoWraperV1
{

	//构造函数
	public MapDataMonsterInfoWraperV1()
	{
		 m_MonsterID = 0;
		 m_X = (float)0;
		 m_Layer = 0;
		 m_RepeatCount = 1;
		 m_SpawmTriggerType = 0;
		 m_RespawmTriggerType = 0;
		 m_PatrolX1 = (float)-1;
		 m_PatrolX2 = (float)-1;
		 m_SpawnNodeTime = (float)0;
		 m_SpawnKillEnemyID = 0;
		 m_SpawnKillEnemyCount = 0;
		 m_SpawnAfterDeathTime = (float)0;
		 m_RespawnNodeTime = (float)0;
		 m_RespawnKillEnemyID = 0;
		 m_RespawnKillEnemyCount = 0;
		 m_RespawnAfterDeathTime = (float)0;
		 m_CreateMonsterType = 0;
		m_NodeMonsterInfoArr = new List<MapDataNodeMonsterInfoWraperV1>();
		 m_Z = (float)0;
		 m_Direction = 1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MonsterID = 0;
		 m_X = (float)0;
		 m_Layer = 0;
		 m_RepeatCount = 1;
		 m_SpawmTriggerType = 0;
		 m_RespawmTriggerType = 0;
		 m_PatrolX1 = (float)-1;
		 m_PatrolX2 = (float)-1;
		 m_SpawnNodeTime = (float)0;
		 m_SpawnKillEnemyID = 0;
		 m_SpawnKillEnemyCount = 0;
		 m_SpawnAfterDeathTime = (float)0;
		 m_RespawnNodeTime = (float)0;
		 m_RespawnKillEnemyID = 0;
		 m_RespawnKillEnemyCount = 0;
		 m_RespawnAfterDeathTime = (float)0;
		 m_CreateMonsterType = 0;
		m_NodeMonsterInfoArr = new List<MapDataNodeMonsterInfoWraperV1>();
		 m_Z = (float)0;
		 m_Direction = 1;

	}

 	//转化成Protobuffer类型函数
	public MapDataMonsterInfoV1 ToPB()
	{
		MapDataMonsterInfoV1 v = new MapDataMonsterInfoV1();
		v.MonsterID = m_MonsterID;
		v.X = m_X;
		v.Layer = m_Layer;
		v.RepeatCount = m_RepeatCount;
		v.SpawmTriggerType = m_SpawmTriggerType;
		v.RespawmTriggerType = m_RespawmTriggerType;
		v.PatrolX1 = m_PatrolX1;
		v.PatrolX2 = m_PatrolX2;
		v.SpawnNodeTime = m_SpawnNodeTime;
		v.SpawnKillEnemyID = m_SpawnKillEnemyID;
		v.SpawnKillEnemyCount = m_SpawnKillEnemyCount;
		v.SpawnAfterDeathTime = m_SpawnAfterDeathTime;
		v.RespawnNodeTime = m_RespawnNodeTime;
		v.RespawnKillEnemyID = m_RespawnKillEnemyID;
		v.RespawnKillEnemyCount = m_RespawnKillEnemyCount;
		v.RespawnAfterDeathTime = m_RespawnAfterDeathTime;
		v.CreateMonsterType = m_CreateMonsterType;
		for (int i=0; i<(int)m_NodeMonsterInfoArr.Count; i++)
			v.NodeMonsterInfoArr.Add( m_NodeMonsterInfoArr[i].ToPB());
		v.Z = m_Z;
		v.Direction = m_Direction;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataMonsterInfoV1 v)
	{
        if (v == null)
            return;
		m_MonsterID = v.MonsterID;
		m_X = v.X;
		m_Layer = v.Layer;
		m_RepeatCount = v.RepeatCount;
		m_SpawmTriggerType = v.SpawmTriggerType;
		m_RespawmTriggerType = v.RespawmTriggerType;
		m_PatrolX1 = v.PatrolX1;
		m_PatrolX2 = v.PatrolX2;
		m_SpawnNodeTime = v.SpawnNodeTime;
		m_SpawnKillEnemyID = v.SpawnKillEnemyID;
		m_SpawnKillEnemyCount = v.SpawnKillEnemyCount;
		m_SpawnAfterDeathTime = v.SpawnAfterDeathTime;
		m_RespawnNodeTime = v.RespawnNodeTime;
		m_RespawnKillEnemyID = v.RespawnKillEnemyID;
		m_RespawnKillEnemyCount = v.RespawnKillEnemyCount;
		m_RespawnAfterDeathTime = v.RespawnAfterDeathTime;
		m_CreateMonsterType = v.CreateMonsterType;
		m_NodeMonsterInfoArr.Clear();
		for( int i=0; i<v.NodeMonsterInfoArr.Count; i++)
			m_NodeMonsterInfoArr.Add( new MapDataNodeMonsterInfoWraperV1());
		for( int i=0; i<v.NodeMonsterInfoArr.Count; i++)
			m_NodeMonsterInfoArr[i].FromPB(v.NodeMonsterInfoArr[i]);
		m_Z = v.Z;
		m_Direction = v.Direction;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataMonsterInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataMonsterInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataMonsterInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//MonsterID
	public int m_MonsterID;
	public int MonsterID
	{
		get { return m_MonsterID;}
		set { m_MonsterID = value; }
	}
	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//Layer
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}
	//RepeatCount
	public int m_RepeatCount;
	public int RepeatCount
	{
		get { return m_RepeatCount;}
		set { m_RepeatCount = value; }
	}
	//SpawmTriggerType
	public int m_SpawmTriggerType;
	public int SpawmTriggerType
	{
		get { return m_SpawmTriggerType;}
		set { m_SpawmTriggerType = value; }
	}
	//RespawmTriggerType
	public int m_RespawmTriggerType;
	public int RespawmTriggerType
	{
		get { return m_RespawmTriggerType;}
		set { m_RespawmTriggerType = value; }
	}
	//PatrolX1
	public float m_PatrolX1;
	public float PatrolX1
	{
		get { return m_PatrolX1;}
		set { m_PatrolX1 = value; }
	}
	//PatrolX2
	public float m_PatrolX2;
	public float PatrolX2
	{
		get { return m_PatrolX2;}
		set { m_PatrolX2 = value; }
	}
	//SpawnNodeTime
	public float m_SpawnNodeTime;
	public float SpawnNodeTime
	{
		get { return m_SpawnNodeTime;}
		set { m_SpawnNodeTime = value; }
	}
	//SpawnKillEnemyID
	public int m_SpawnKillEnemyID;
	public int SpawnKillEnemyID
	{
		get { return m_SpawnKillEnemyID;}
		set { m_SpawnKillEnemyID = value; }
	}
	//SpawnKillEnemyCount
	public int m_SpawnKillEnemyCount;
	public int SpawnKillEnemyCount
	{
		get { return m_SpawnKillEnemyCount;}
		set { m_SpawnKillEnemyCount = value; }
	}
	//SpawnAfterDeathTime
	public float m_SpawnAfterDeathTime;
	public float SpawnAfterDeathTime
	{
		get { return m_SpawnAfterDeathTime;}
		set { m_SpawnAfterDeathTime = value; }
	}
	//RespawnNodeTime
	public float m_RespawnNodeTime;
	public float RespawnNodeTime
	{
		get { return m_RespawnNodeTime;}
		set { m_RespawnNodeTime = value; }
	}
	//RespawnKillEnemyID
	public int m_RespawnKillEnemyID;
	public int RespawnKillEnemyID
	{
		get { return m_RespawnKillEnemyID;}
		set { m_RespawnKillEnemyID = value; }
	}
	//RespawnKillEnemyCount
	public int m_RespawnKillEnemyCount;
	public int RespawnKillEnemyCount
	{
		get { return m_RespawnKillEnemyCount;}
		set { m_RespawnKillEnemyCount = value; }
	}
	//RespawnAfterDeathTime
	public float m_RespawnAfterDeathTime;
	public float RespawnAfterDeathTime
	{
		get { return m_RespawnAfterDeathTime;}
		set { m_RespawnAfterDeathTime = value; }
	}
	//出怪类型
	public int m_CreateMonsterType;
	public int CreateMonsterType
	{
		get { return m_CreateMonsterType;}
		set { m_CreateMonsterType = value; }
	}
	//坑点中怪物节点列表
	public List<MapDataNodeMonsterInfoWraperV1> m_NodeMonsterInfoArr;
	public int SizeNodeMonsterInfoArr()
	{
		return m_NodeMonsterInfoArr.Count;
	}
	public List<MapDataNodeMonsterInfoWraperV1> GetNodeMonsterInfoArr()
	{
		return m_NodeMonsterInfoArr;
	}
	public MapDataNodeMonsterInfoWraperV1 GetNodeMonsterInfoArr(int Index)
	{
		if(Index<0 || Index>=(int)m_NodeMonsterInfoArr.Count)
			return new MapDataNodeMonsterInfoWraperV1();
		return m_NodeMonsterInfoArr[Index];
	}
	public void SetNodeMonsterInfoArr( List<MapDataNodeMonsterInfoWraperV1> v )
	{
		m_NodeMonsterInfoArr=v;
	}
	public void SetNodeMonsterInfoArr( int Index, MapDataNodeMonsterInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_NodeMonsterInfoArr.Count)
			return;
		m_NodeMonsterInfoArr[Index] = v;
	}
	public void AddNodeMonsterInfoArr( MapDataNodeMonsterInfoWraperV1 v )
	{
		m_NodeMonsterInfoArr.Add(v);
	}
	public void ClearNodeMonsterInfoArr( )
	{
		m_NodeMonsterInfoArr.Clear();
	}
	//Z轴
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//朝向
	public int m_Direction;
	public int Direction
	{
		get { return m_Direction;}
		set { m_Direction = value; }
	}


};
//NodeInfo封装类
[System.Serializable]
public class MapDataNodeInfoWraperV1
{

	//构造函数
	public MapDataNodeInfoWraperV1()
	{
		 m_X = (float)0;
		 m_Layer = 0;
		 m_PassCondition = 0;
		 m_KillEnemyID = 0;
		 m_KillEnemyCount = 0;
		m_MonsterArr = new List<MapDataMonsterInfoWraperV1>();
		 m_TimeLimit = (float)0;
		 m_NodeType = 0;
		 m_NodeArrowDisplayType = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X = (float)0;
		 m_Layer = 0;
		 m_PassCondition = 0;
		 m_KillEnemyID = 0;
		 m_KillEnemyCount = 0;
		m_MonsterArr = new List<MapDataMonsterInfoWraperV1>();
		 m_TimeLimit = (float)0;
		 m_NodeType = 0;
		 m_NodeArrowDisplayType = 0;

	}

 	//转化成Protobuffer类型函数
	public MapDataNodeInfoV1 ToPB()
	{
		MapDataNodeInfoV1 v = new MapDataNodeInfoV1();
		v.X = m_X;
		v.Layer = m_Layer;
		v.PassCondition = m_PassCondition;
		v.KillEnemyID = m_KillEnemyID;
		v.KillEnemyCount = m_KillEnemyCount;
		for (int i=0; i<(int)m_MonsterArr.Count; i++)
			v.MonsterArr.Add( m_MonsterArr[i].ToPB());
		v.TimeLimit = m_TimeLimit;
		v.NodeType = m_NodeType;
		v.NodeArrowDisplayType = m_NodeArrowDisplayType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataNodeInfoV1 v)
	{
        if (v == null)
            return;
		m_X = v.X;
		m_Layer = v.Layer;
		m_PassCondition = v.PassCondition;
		m_KillEnemyID = v.KillEnemyID;
		m_KillEnemyCount = v.KillEnemyCount;
		m_MonsterArr.Clear();
		for( int i=0; i<v.MonsterArr.Count; i++)
			m_MonsterArr.Add( new MapDataMonsterInfoWraperV1());
		for( int i=0; i<v.MonsterArr.Count; i++)
			m_MonsterArr[i].FromPB(v.MonsterArr[i]);
		m_TimeLimit = v.TimeLimit;
		m_NodeType = v.NodeType;
		m_NodeArrowDisplayType = v.NodeArrowDisplayType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataNodeInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataNodeInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataNodeInfoV1>(protoMS);
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
	//Layer
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}
	//PassCondition
	public int m_PassCondition;
	public int PassCondition
	{
		get { return m_PassCondition;}
		set { m_PassCondition = value; }
	}
	//KillEnemyID
	public int m_KillEnemyID;
	public int KillEnemyID
	{
		get { return m_KillEnemyID;}
		set { m_KillEnemyID = value; }
	}
	//KillEnemyCount
	public int m_KillEnemyCount;
	public int KillEnemyCount
	{
		get { return m_KillEnemyCount;}
		set { m_KillEnemyCount = value; }
	}
	//MonsterArr
	public List<MapDataMonsterInfoWraperV1> m_MonsterArr;
	public int SizeMonsterArr()
	{
		return m_MonsterArr.Count;
	}
	public List<MapDataMonsterInfoWraperV1> GetMonsterArr()
	{
		return m_MonsterArr;
	}
	public MapDataMonsterInfoWraperV1 GetMonsterArr(int Index)
	{
		if(Index<0 || Index>=(int)m_MonsterArr.Count)
			return new MapDataMonsterInfoWraperV1();
		return m_MonsterArr[Index];
	}
	public void SetMonsterArr( List<MapDataMonsterInfoWraperV1> v )
	{
		m_MonsterArr=v;
	}
	public void SetMonsterArr( int Index, MapDataMonsterInfoWraperV1 v )
	{
		if(Index<0 || Index>=(int)m_MonsterArr.Count)
			return;
		m_MonsterArr[Index] = v;
	}
	public void AddMonsterArr( MapDataMonsterInfoWraperV1 v )
	{
		m_MonsterArr.Add(v);
	}
	public void ClearMonsterArr( )
	{
		m_MonsterArr.Clear();
	}
	//TimeLimit
	public float m_TimeLimit;
	public float TimeLimit
	{
		get { return m_TimeLimit;}
		set { m_TimeLimit = value; }
	}
	//NodeType
	public int m_NodeType;
	public int NodeType
	{
		get { return m_NodeType;}
		set { m_NodeType = value; }
	}
	//节点箭头显示模式
	public int m_NodeArrowDisplayType;
	public int NodeArrowDisplayType
	{
		get { return m_NodeArrowDisplayType;}
		set { m_NodeArrowDisplayType = value; }
	}


};
//领地封装类
[System.Serializable]
public class MapDataTerritorialInfoWraperV1
{

	//构造函数
	public MapDataTerritorialInfoWraperV1()
	{
		 m_Layer = 0;
		 m_Area = new MapDataVector2WraperV1();
		 m_X = (float)0;
		 m_ID = 0;
		 m_ModelName = "";

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Layer = 0;
		 m_Area = new MapDataVector2WraperV1();
		 m_X = (float)0;
		 m_ID = 0;
		 m_ModelName = "";

	}

 	//转化成Protobuffer类型函数
	public MapDataTerritorialInfoV1 ToPB()
	{
		MapDataTerritorialInfoV1 v = new MapDataTerritorialInfoV1();
		v.Layer = m_Layer;
		v.Area = m_Area.ToPB();
		v.X = m_X;
		v.ID = m_ID;
		v.ModelName = m_ModelName;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataTerritorialInfoV1 v)
	{
        if (v == null)
            return;
		m_Layer = v.Layer;
		m_Area.FromPB(v.Area);
		m_X = v.X;
		m_ID = v.ID;
		m_ModelName = v.ModelName;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataTerritorialInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataTerritorialInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataTerritorialInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//层
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}
	//区域
	public MapDataVector2WraperV1 m_Area;
	public MapDataVector2WraperV1 Area
	{
		get { return m_Area;}
		set { m_Area = value; }
	}
	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//ID
	public int m_ID;
	public int ID
	{
		get { return m_ID;}
		set { m_ID = value; }
	}
	//ModelName
	public string m_ModelName;
	public string ModelName
	{
		get { return m_ModelName;}
		set { m_ModelName = value; }
	}


};
//怪物坑点数据封装类
[System.Serializable]
public class MapDataNodeMonsterInfoWraperV1
{

	//构造函数
	public MapDataNodeMonsterInfoWraperV1()
	{
		 m_MonsterId = -1;
		 m_RandomWeight = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MonsterId = -1;
		 m_RandomWeight = -1;

	}

 	//转化成Protobuffer类型函数
	public MapDataNodeMonsterInfoV1 ToPB()
	{
		MapDataNodeMonsterInfoV1 v = new MapDataNodeMonsterInfoV1();
		v.MonsterId = m_MonsterId;
		v.RandomWeight = m_RandomWeight;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataNodeMonsterInfoV1 v)
	{
        if (v == null)
            return;
		m_MonsterId = v.MonsterId;
		m_RandomWeight = v.RandomWeight;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataNodeMonsterInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataNodeMonsterInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataNodeMonsterInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//怪物ID
	public int m_MonsterId;
	public int MonsterId
	{
		get { return m_MonsterId;}
		set { m_MonsterId = value; }
	}
	//怪物随机权重
	public int m_RandomWeight;
	public int RandomWeight
	{
		get { return m_RandomWeight;}
		set { m_RandomWeight = value; }
	}


};
//基础配置封装类
[System.Serializable]
public class MapDataBaseConfigWraperV1
{

	//构造函数
	public MapDataBaseConfigWraperV1()
	{
		 m_MapType = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_MapType = 0;

	}

 	//转化成Protobuffer类型函数
	public MapDataBaseConfigV1 ToPB()
	{
		MapDataBaseConfigV1 v = new MapDataBaseConfigV1();
		v.MapType = m_MapType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataBaseConfigV1 v)
	{
        if (v == null)
            return;
		m_MapType = v.MapType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataBaseConfigV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataBaseConfigV1 pb = ProtoBuf.Serializer.Deserialize<MapDataBaseConfigV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//地图类型
	public int m_MapType;
	public int MapType
	{
		get { return m_MapType;}
		set { m_MapType = value; }
	}


};
//采集物封装类
[System.Serializable]
public class MapDataGatherInfoWraperV1
{

	//构造函数
	public MapDataGatherInfoWraperV1()
	{
		 m_GatherId = 0;
		 m_X = (float)0;
		 m_Layer = 0;
		 m_Z = (float)0;
		 m_Direction = 1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_GatherId = 0;
		 m_X = (float)0;
		 m_Layer = 0;
		 m_Z = (float)0;
		 m_Direction = 1;

	}

 	//转化成Protobuffer类型函数
	public MapDataGatherInfoV1 ToPB()
	{
		MapDataGatherInfoV1 v = new MapDataGatherInfoV1();
		v.GatherId = m_GatherId;
		v.X = m_X;
		v.Layer = m_Layer;
		v.Z = m_Z;
		v.Direction = m_Direction;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataGatherInfoV1 v)
	{
        if (v == null)
            return;
		m_GatherId = v.GatherId;
		m_X = v.X;
		m_Layer = v.Layer;
		m_Z = v.Z;
		m_Direction = v.Direction;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataGatherInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataGatherInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataGatherInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//采集物ID
	public int m_GatherId;
	public int GatherId
	{
		get { return m_GatherId;}
		set { m_GatherId = value; }
	}
	//X
	public float m_X;
	public float X
	{
		get { return m_X;}
		set { m_X = value; }
	}
	//层
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}
	//Z
	public float m_Z;
	public float Z
	{
		get { return m_Z;}
		set { m_Z = value; }
	}
	//朝向
	public int m_Direction;
	public int Direction
	{
		get { return m_Direction;}
		set { m_Direction = value; }
	}


};
//等高线信息封装类
[System.Serializable]
public class MapDataContourLineInfoWraperV1
{

	//构造函数
	public MapDataContourLineInfoWraperV1()
	{
		 m_Y = (float)-1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Y = (float)-1;

	}

 	//转化成Protobuffer类型函数
	public MapDataContourLineInfoV1 ToPB()
	{
		MapDataContourLineInfoV1 v = new MapDataContourLineInfoV1();
		v.Y = m_Y;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataContourLineInfoV1 v)
	{
        if (v == null)
            return;
		m_Y = v.Y;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataContourLineInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataContourLineInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataContourLineInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//Y
	public float m_Y;
	public float Y
	{
		get { return m_Y;}
		set { m_Y = value; }
	}


};
//事件信息封装类
[System.Serializable]
public class MapDataEventInfoWraperV1
{

	//构造函数
	public MapDataEventInfoWraperV1()
	{
		 m_X1 = (float)0;
		 m_Z1 = (float)0;
		 m_X2 = (float)0;
		 m_Z2 = (float)0;
		 m_Type = 0;
		 m_EventId = 0;
		 m_Layer = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X1 = (float)0;
		 m_Z1 = (float)0;
		 m_X2 = (float)0;
		 m_Z2 = (float)0;
		 m_Type = 0;
		 m_EventId = 0;
		 m_Layer = 0;

	}

 	//转化成Protobuffer类型函数
	public MapDataEventInfoV1 ToPB()
	{
		MapDataEventInfoV1 v = new MapDataEventInfoV1();
		v.X1 = m_X1;
		v.Z1 = m_Z1;
		v.X2 = m_X2;
		v.Z2 = m_Z2;
		v.Type = m_Type;
		v.EventId = m_EventId;
		v.Layer = m_Layer;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataEventInfoV1 v)
	{
        if (v == null)
            return;
		m_X1 = v.X1;
		m_Z1 = v.Z1;
		m_X2 = v.X2;
		m_Z2 = v.Z2;
		m_Type = v.Type;
		m_EventId = v.EventId;
		m_Layer = v.Layer;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataEventInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataEventInfoV1 pb = ProtoBuf.Serializer.Deserialize<MapDataEventInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//X1坐标
	public float m_X1;
	public float X1
	{
		get { return m_X1;}
		set { m_X1 = value; }
	}
	//Z1坐标
	public float m_Z1;
	public float Z1
	{
		get { return m_Z1;}
		set { m_Z1 = value; }
	}
	//X2坐标
	public float m_X2;
	public float X2
	{
		get { return m_X2;}
		set { m_X2 = value; }
	}
	//Z2坐标
	public float m_Z2;
	public float Z2
	{
		get { return m_Z2;}
		set { m_Z2 = value; }
	}
	//类型
	public int m_Type;
	public int Type
	{
		get { return m_Type;}
		set { m_Type = value; }
	}
	//事件Id
	public int m_EventId;
	public int EventId
	{
		get { return m_EventId;}
		set { m_EventId = value; }
	}
	//层信息
	public int m_Layer;
	public int Layer
	{
		get { return m_Layer;}
		set { m_Layer = value; }
	}


};
