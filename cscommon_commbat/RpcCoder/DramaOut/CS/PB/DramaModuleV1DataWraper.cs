
/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:     WraperSyncPBDramaModule.cs
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


//剧情信息封装类
[System.Serializable]
public class DramaModuleDramaInfoWraperV1
{

	//构造函数
	public DramaModuleDramaInfoWraperV1()
	{
		 Name = "";
		TotalTime = (float)0;
		CommandList = new List<DramaModuleCommandInfoWraperV1>();

	}

	//重置函数
	public void ResetWraper()
	{
		 Name = "";
		TotalTime = (float)0;
		CommandList = new List<DramaModuleCommandInfoWraperV1>();

	}

 	//转化成Protobuffer类型函数
	public DramaModuleDramaInfoV1 ToPB()
	{
		DramaModuleDramaInfoV1 v = new DramaModuleDramaInfoV1();
		v.Name = Name;
		v.TotalTime = TotalTime;
		for (int i=0; i<(int)CommandList.Count; i++)
			v.CommandList.Add( CommandList[i].ToPB());

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DramaModuleDramaInfoV1 v)
	{
        if (v == null)
            return;
		Name = v.Name;
		TotalTime = v.TotalTime;
		CommandList.Clear();
		for( int i=0; i<v.CommandList.Count; i++)
			CommandList.Add( new DramaModuleCommandInfoWraperV1());
		for( int i=0; i<v.CommandList.Count; i++)
			CommandList[i].FromPB(v.CommandList[i]);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DramaModuleDramaInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DramaModuleDramaInfoV1 pb = ProtoBuf.Serializer.Deserialize<DramaModuleDramaInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//名字
	public string Name;
	//总时间
	public float TotalTime;
	//Actions
	public List<DramaModuleCommandInfoWraperV1> CommandList;


};
//ActionInfo封装类
[System.Serializable]
public class DramaModuleCommandInfoWraperV1
{

	//构造函数
	public DramaModuleCommandInfoWraperV1()
	{
		CommandType = -1;
		StartTime = (float)0;
		DurationTime = (float)0;
		CreateObjectType = 0;
		CreateNPCid = -1;
		 CreateNpcTransform = new DramaModuleTransformWraperV1();
		Trigger = false;
		SubtitleStyle = 0;
		SubtitleID = -1;
		SubtitleTargetType = 0;
		SubtitleTargetConfigId = -1;
		 TranslatePostion = new DramaModuleV3WraperV1();
		TranslateTime = (float)0;
		TranslateCurve = 0;
		TranslateTargetType = 0;
		TranslateTargetId = -1;
		SkillId = -1;
		SkllTargetId = -1;
		 SkillPostion = new DramaModuleV3WraperV1();
		SkillTargetType = 0;
		 MusicFileName = "";
		 SoundFileName = "";
		CameraPointType = 0;
		CameraPoints = new List<DramaModuleCameraPointWraperV1>();
		FreeType = 0;

	}

	//重置函数
	public void ResetWraper()
	{
		CommandType = -1;
		StartTime = (float)0;
		DurationTime = (float)0;
		CreateObjectType = 0;
		CreateNPCid = -1;
		 CreateNpcTransform = new DramaModuleTransformWraperV1();
		Trigger = false;
		SubtitleStyle = 0;
		SubtitleID = -1;
		SubtitleTargetType = 0;
		SubtitleTargetConfigId = -1;
		 TranslatePostion = new DramaModuleV3WraperV1();
		TranslateTime = (float)0;
		TranslateCurve = 0;
		TranslateTargetType = 0;
		TranslateTargetId = -1;
		SkillId = -1;
		SkllTargetId = -1;
		 SkillPostion = new DramaModuleV3WraperV1();
		SkillTargetType = 0;
		 MusicFileName = "";
		 SoundFileName = "";
		CameraPointType = 0;
		CameraPoints = new List<DramaModuleCameraPointWraperV1>();
		FreeType = 0;

	}

 	//转化成Protobuffer类型函数
	public DramaModuleCommandInfoV1 ToPB()
	{
		DramaModuleCommandInfoV1 v = new DramaModuleCommandInfoV1();
		v.CommandType = CommandType;
		v.StartTime = StartTime;
		v.DurationTime = DurationTime;
		v.CreateObjectType = CreateObjectType;
		v.CreateNPCid = CreateNPCid;
		v.CreateNpcTransform = CreateNpcTransform.ToPB();
		v.Trigger = Trigger;
		v.SubtitleStyle = SubtitleStyle;
		v.SubtitleID = SubtitleID;
		v.SubtitleTargetType = SubtitleTargetType;
		v.SubtitleTargetConfigId = SubtitleTargetConfigId;
		v.TranslatePostion = TranslatePostion.ToPB();
		v.TranslateTime = TranslateTime;
		v.TranslateCurve = TranslateCurve;
		v.TranslateTargetType = TranslateTargetType;
		v.TranslateTargetId = TranslateTargetId;
		v.SkillId = SkillId;
		v.SkllTargetId = SkllTargetId;
		v.SkillPostion = SkillPostion.ToPB();
		v.SkillTargetType = SkillTargetType;
		v.MusicFileName = MusicFileName;
		v.SoundFileName = SoundFileName;
		v.CameraPointType = CameraPointType;
		for (int i=0; i<(int)CameraPoints.Count; i++)
			v.CameraPoints.Add( CameraPoints[i].ToPB());
		v.FreeType = FreeType;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DramaModuleCommandInfoV1 v)
	{
        if (v == null)
            return;
		CommandType = v.CommandType;
		StartTime = v.StartTime;
		DurationTime = v.DurationTime;
		CreateObjectType = v.CreateObjectType;
		CreateNPCid = v.CreateNPCid;
		CreateNpcTransform.FromPB(v.CreateNpcTransform);
		Trigger = v.Trigger;
		SubtitleStyle = v.SubtitleStyle;
		SubtitleID = v.SubtitleID;
		SubtitleTargetType = v.SubtitleTargetType;
		SubtitleTargetConfigId = v.SubtitleTargetConfigId;
		TranslatePostion.FromPB(v.TranslatePostion);
		TranslateTime = v.TranslateTime;
		TranslateCurve = v.TranslateCurve;
		TranslateTargetType = v.TranslateTargetType;
		TranslateTargetId = v.TranslateTargetId;
		SkillId = v.SkillId;
		SkllTargetId = v.SkllTargetId;
		SkillPostion.FromPB(v.SkillPostion);
		SkillTargetType = v.SkillTargetType;
		MusicFileName = v.MusicFileName;
		SoundFileName = v.SoundFileName;
		CameraPointType = v.CameraPointType;
		CameraPoints.Clear();
		for( int i=0; i<v.CameraPoints.Count; i++)
			CameraPoints.Add( new DramaModuleCameraPointWraperV1());
		for( int i=0; i<v.CameraPoints.Count; i++)
			CameraPoints[i].FromPB(v.CameraPoints[i]);
		FreeType = v.FreeType;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DramaModuleCommandInfoV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DramaModuleCommandInfoV1 pb = ProtoBuf.Serializer.Deserialize<DramaModuleCommandInfoV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//Action类型
	public int CommandType;
	//开始时间
	public float StartTime;
	//持续时间
	public float DurationTime;
	//创建资源类型
	public int CreateObjectType;
	//创建NPC
	public int CreateNPCid;
	//CreateNpcTransform
	public DramaModuleTransformWraperV1 CreateNpcTransform;
	//是否触发
	public bool Trigger;
	//字幕类型
	public int SubtitleStyle;
	//字幕id
	public int SubtitleID;
	//字幕目标类型
	public int SubtitleTargetType;
	//目标配置id
	public int SubtitleTargetConfigId;
	//最终位置
	public DramaModuleV3WraperV1 TranslatePostion;
	//位移的时间
	public float TranslateTime;
	//曲线
	public int TranslateCurve;
	//位移目标类型
	public int TranslateTargetType;
	//TranslateTargetId
	public int TranslateTargetId;
	//技能id
	public int SkillId;
	//释放技能者id
	public int SkllTargetId;
	//技能释放位置
	public DramaModuleV3WraperV1 SkillPostion;
	//释放技能
	public int SkillTargetType;
	//音乐
	public string MusicFileName;
	//音效
	public string SoundFileName;
	//摄像机点类型
	public int CameraPointType;
	//视点
	public List<DramaModuleCameraPointWraperV1> CameraPoints;
	//释放类型
	public int FreeType;


};
//V3封装类
[System.Serializable]
public class DramaModuleV3WraperV1
{

	//构造函数
	public DramaModuleV3WraperV1()
	{
		X = (float)0;
		Y = (float)0;
		Z = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		X = (float)0;
		Y = (float)0;
		Z = (float)0;

	}

 	//转化成Protobuffer类型函数
	public DramaModuleV3V1 ToPB()
	{
		DramaModuleV3V1 v = new DramaModuleV3V1();
		v.X = X;
		v.Y = Y;
		v.Z = Z;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DramaModuleV3V1 v)
	{
        if (v == null)
            return;
		X = v.X;
		Y = v.Y;
		Z = v.Z;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DramaModuleV3V1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DramaModuleV3V1 pb = ProtoBuf.Serializer.Deserialize<DramaModuleV3V1>(protoMS);
		FromPB(pb);
		return true;
	}

	//X
	public float X;
	//Y
	public float Y;
	//Z
	public float Z;


};
//Transform封装类
[System.Serializable]
public class DramaModuleTransformWraperV1
{

	//构造函数
	public DramaModuleTransformWraperV1()
	{
		 Postion = new DramaModuleV3WraperV1();
		 Rotation = new DramaModuleV3WraperV1();
		 Scale = new DramaModuleV3WraperV1();

	}

	//重置函数
	public void ResetWraper()
	{
		 Postion = new DramaModuleV3WraperV1();
		 Rotation = new DramaModuleV3WraperV1();
		 Scale = new DramaModuleV3WraperV1();

	}

 	//转化成Protobuffer类型函数
	public DramaModuleTransformV1 ToPB()
	{
		DramaModuleTransformV1 v = new DramaModuleTransformV1();
		v.Postion = Postion.ToPB();
		v.Rotation = Rotation.ToPB();
		v.Scale = Scale.ToPB();

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DramaModuleTransformV1 v)
	{
        if (v == null)
            return;
		Postion.FromPB(v.Postion);
		Rotation.FromPB(v.Rotation);
		Scale.FromPB(v.Scale);

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DramaModuleTransformV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DramaModuleTransformV1 pb = ProtoBuf.Serializer.Deserialize<DramaModuleTransformV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//Postion
	public DramaModuleV3WraperV1 Postion;
	//rotation
	public DramaModuleV3WraperV1 Rotation;
	//Scale
	public DramaModuleV3WraperV1 Scale;


};
//摄像机点封装类
[System.Serializable]
public class DramaModuleCameraPointWraperV1
{

	//构造函数
	public DramaModuleCameraPointWraperV1()
	{
		 Pos = new DramaModuleV3WraperV1();
		 Angle = new DramaModuleV3WraperV1();
		Time = (float)0;

	}

	//重置函数
	public void ResetWraper()
	{
		 Pos = new DramaModuleV3WraperV1();
		 Angle = new DramaModuleV3WraperV1();
		Time = (float)0;

	}

 	//转化成Protobuffer类型函数
	public DramaModuleCameraPointV1 ToPB()
	{
		DramaModuleCameraPointV1 v = new DramaModuleCameraPointV1();
		v.Pos = Pos.ToPB();
		v.Angle = Angle.ToPB();
		v.Time = Time;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(DramaModuleCameraPointV1 v)
	{
        if (v == null)
            return;
		Pos.FromPB(v.Pos);
		Angle.FromPB(v.Angle);
		Time = v.Time;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<DramaModuleCameraPointV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		DramaModuleCameraPointV1 pb = ProtoBuf.Serializer.Deserialize<DramaModuleCameraPointV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//位置
	public DramaModuleV3WraperV1 Pos;
	//角度
	public DramaModuleV3WraperV1 Angle;
	//时间
	public float Time;


};
