/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleMapData.cs
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


public class MapDataRPC
{
	public const int ModuleId = 20;
	

	
	private static MapDataRPC m_Instance = null;
	public static MapDataRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MapDataRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, MapDataData.Instance.UpdateField );
		


		return true;
	}






}

public class MapDataData
{
	public enum SyncIdE
	{
 		X1                                         = 2001,  //X1

	}
	
	private static MapDataData m_Instance = null;
	public static MapDataData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MapDataData();
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
			case SyncIdE.X1:
				GameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);
				m_Instance.X1 = iValue;
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
			Ex.Logger.Log("MapDataData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  

	//构造函数
	public MapDataData()
	{
		 m_X1 = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_X1 = -1;

	}

 	//转化成Protobuffer类型函数
	public MapDataUselessV1 ToPB()
	{
		MapDataUselessV1 v = new MapDataUselessV1();
		v.X1 = m_X1;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(MapDataUselessV1 v)
	{
        if (v == null)
            return;
		m_X1 = v.X1;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MapDataUselessV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		MapDataUselessV1 pb = ProtoBuf.Serializer.Deserialize<MapDataUselessV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//X1
	public int m_X1;
	public int X1
	{
		get { return m_X1;}
		set { m_X1 = value; }
	}



}
