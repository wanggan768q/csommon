/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperDramaModule.h
* Author:       甘业清
* Description:  剧情模块同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_DRAMAMODULE_H
#define __SYNC_WRAPER_DRAMAMODULE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DramaModuleV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//V3封装类
class DramaModuleV3WraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	DramaModuleV3WraperV1()
	{
		
		m_X = 0;
		m_Y = 0;
		m_Z = 0;

	}
	//赋值构造函数
	DramaModuleV3WraperV1(const DramaModuleV3V1& v){ Init(v); }
	//等号重载函数
	void operator = (const DramaModuleV3V1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DramaModuleV3V1 ToPB() const
	{
		DramaModuleV3V1 v;
		v.set_x( m_X );
		v.set_y( m_Y );
		v.set_z( m_Z );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		DramaModuleV3V1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>X(X) [float]</li>\r\n";
		htmlBuff += "<li>Y(Y) [float]</li>\r\n";
		htmlBuff += "<li>Z(Z) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>X：%.2ff</li>\r\n",m_X);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Y：%.2ff</li>\r\n",m_Y);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Z：%.2ff</li>\r\n",m_Z);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DramaModuleV3V1& v)
	{
		m_X = v.x();
		m_Y = v.y();
		m_Z = v.z();

	}

private:
	//X
	float m_X;
public:
	void SetX( float v)
	{
		m_X=v;
	}
	float GetX()
	{
		return m_X;
	}
	float GetX() const
	{
		return m_X;
	}
private:
	//Y
	float m_Y;
public:
	void SetY( float v)
	{
		m_Y=v;
	}
	float GetY()
	{
		return m_Y;
	}
	float GetY() const
	{
		return m_Y;
	}
private:
	//Z
	float m_Z;
public:
	void SetZ( float v)
	{
		m_Z=v;
	}
	float GetZ()
	{
		return m_Z;
	}
	float GetZ() const
	{
		return m_Z;
	}

};
//Transform封装类
class DramaModuleTransformWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	DramaModuleTransformWraperV1()
	{
		
		m_Postion = DramaModuleV3WraperV1();
		m_Rotation = DramaModuleV3WraperV1();
		m_Scale = DramaModuleV3WraperV1();

	}
	//赋值构造函数
	DramaModuleTransformWraperV1(const DramaModuleTransformV1& v){ Init(v); }
	//等号重载函数
	void operator = (const DramaModuleTransformV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DramaModuleTransformV1 ToPB() const
	{
		DramaModuleTransformV1 v;
		*v.mutable_postion()= m_Postion.ToPB();
		*v.mutable_rotation()= m_Rotation.ToPB();
		*v.mutable_scale()= m_Scale.ToPB();

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		DramaModuleTransformV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Postion(Postion) [V3]</li>\r\n";
		htmlBuff += "<li>Rotation(rotation) [V3]</li>\r\n";
		htmlBuff += "<li>Scale(Scale) [V3]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Postion：</li>\r\n";
		htmlBuff += m_Postion.HtmlDescHeader();
		htmlBuff += m_Postion.ToHtml();
		htmlBuff += "<li>Rotation：</li>\r\n";
		htmlBuff += m_Rotation.HtmlDescHeader();
		htmlBuff += m_Rotation.ToHtml();
		htmlBuff += "<li>Scale：</li>\r\n";
		htmlBuff += m_Scale.HtmlDescHeader();
		htmlBuff += m_Scale.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DramaModuleTransformV1& v)
	{
		m_Postion = v.postion();
		m_Rotation = v.rotation();
		m_Scale = v.scale();

	}

private:
	//Postion
	DramaModuleV3WraperV1 m_Postion;
public:
	void SetPostion( const DramaModuleV3WraperV1& v)
	{
		m_Postion=v;
	}
	DramaModuleV3WraperV1 GetPostion()
	{
		return m_Postion;
	}
	DramaModuleV3WraperV1 GetPostion() const
	{
		return m_Postion;
	}
private:
	//rotation
	DramaModuleV3WraperV1 m_Rotation;
public:
	void SetRotation( const DramaModuleV3WraperV1& v)
	{
		m_Rotation=v;
	}
	DramaModuleV3WraperV1 GetRotation()
	{
		return m_Rotation;
	}
	DramaModuleV3WraperV1 GetRotation() const
	{
		return m_Rotation;
	}
private:
	//Scale
	DramaModuleV3WraperV1 m_Scale;
public:
	void SetScale( const DramaModuleV3WraperV1& v)
	{
		m_Scale=v;
	}
	DramaModuleV3WraperV1 GetScale()
	{
		return m_Scale;
	}
	DramaModuleV3WraperV1 GetScale() const
	{
		return m_Scale;
	}

};
//摄像机点封装类
class DramaModuleCameraPointWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	DramaModuleCameraPointWraperV1()
	{
		
		m_Pos = DramaModuleV3WraperV1();
		m_Angle = DramaModuleV3WraperV1();
		m_Time = 0;

	}
	//赋值构造函数
	DramaModuleCameraPointWraperV1(const DramaModuleCameraPointV1& v){ Init(v); }
	//等号重载函数
	void operator = (const DramaModuleCameraPointV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DramaModuleCameraPointV1 ToPB() const
	{
		DramaModuleCameraPointV1 v;
		*v.mutable_pos()= m_Pos.ToPB();
		*v.mutable_angle()= m_Angle.ToPB();
		v.set_time( m_Time );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		DramaModuleCameraPointV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Pos(位置) [V3]</li>\r\n";
		htmlBuff += "<li>Angle(角度) [V3]</li>\r\n";
		htmlBuff += "<li>Time(时间) [float]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Pos：</li>\r\n";
		htmlBuff += m_Pos.HtmlDescHeader();
		htmlBuff += m_Pos.ToHtml();
		htmlBuff += "<li>Angle：</li>\r\n";
		htmlBuff += m_Angle.HtmlDescHeader();
		htmlBuff += m_Angle.ToHtml();
		tmpLine.Fmt("<li>Time：%.2ff</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DramaModuleCameraPointV1& v)
	{
		m_Pos = v.pos();
		m_Angle = v.angle();
		m_Time = v.time();

	}

private:
	//位置
	DramaModuleV3WraperV1 m_Pos;
public:
	void SetPos( const DramaModuleV3WraperV1& v)
	{
		m_Pos=v;
	}
	DramaModuleV3WraperV1 GetPos()
	{
		return m_Pos;
	}
	DramaModuleV3WraperV1 GetPos() const
	{
		return m_Pos;
	}
private:
	//角度
	DramaModuleV3WraperV1 m_Angle;
public:
	void SetAngle( const DramaModuleV3WraperV1& v)
	{
		m_Angle=v;
	}
	DramaModuleV3WraperV1 GetAngle()
	{
		return m_Angle;
	}
	DramaModuleV3WraperV1 GetAngle() const
	{
		return m_Angle;
	}
private:
	//时间
	float m_Time;
public:
	void SetTime( float v)
	{
		m_Time=v;
	}
	float GetTime()
	{
		return m_Time;
	}
	float GetTime() const
	{
		return m_Time;
	}

};
//ActionInfo封装类
class DramaModuleCommandInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	DramaModuleCommandInfoWraperV1()
	{
		
		m_CommandType = -1;
		m_StartTime = 0;
		m_DurationTime = 0;
		m_CreateObjectType = 0;
		m_CreateNPCid = -1;
		m_CreateNpcTransform = DramaModuleTransformWraperV1();
		m_Trigger = false;
		m_SubtitleStyle = 0;
		m_SubtitleID = -1;
		m_SubtitleTargetType = 0;
		m_SubtitleTargetConfigId = -1;
		m_TranslatePostion = DramaModuleV3WraperV1();
		m_TranslateTime = 0;
		m_TranslateCurve = 0;
		m_TranslateTargetType = 0;
		m_TranslateTargetId = -1;
		m_SkillId = -1;
		m_SkllTargetId = -1;
		m_SkillPostion = DramaModuleV3WraperV1();
		m_SkillTargetType = 0;
		m_MusicFileName = "";
		m_SoundFileName = "";
		m_CameraPointType = 0;
		m_FreeType = 0;

	}
	//赋值构造函数
	DramaModuleCommandInfoWraperV1(const DramaModuleCommandInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const DramaModuleCommandInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DramaModuleCommandInfoV1 ToPB() const
	{
		DramaModuleCommandInfoV1 v;
		v.set_commandtype( m_CommandType );
		v.set_starttime( m_StartTime );
		v.set_durationtime( m_DurationTime );
		v.set_createobjecttype( m_CreateObjectType );
		v.set_createnpcid( m_CreateNPCid );
		*v.mutable_createnpctransform()= m_CreateNpcTransform.ToPB();
		v.set_trigger( m_Trigger );
		v.set_subtitlestyle( m_SubtitleStyle );
		v.set_subtitleid( m_SubtitleID );
		v.set_subtitletargettype( m_SubtitleTargetType );
		v.set_subtitletargetconfigid( m_SubtitleTargetConfigId );
		*v.mutable_translatepostion()= m_TranslatePostion.ToPB();
		v.set_translatetime( m_TranslateTime );
		v.set_translatecurve( m_TranslateCurve );
		v.set_translatetargettype( m_TranslateTargetType );
		v.set_translatetargetid( m_TranslateTargetId );
		v.set_skillid( m_SkillId );
		v.set_sklltargetid( m_SkllTargetId );
		*v.mutable_skillpostion()= m_SkillPostion.ToPB();
		v.set_skilltargettype( m_SkillTargetType );
		v.set_musicfilename( m_MusicFileName );
		v.set_soundfilename( m_SoundFileName );
		v.set_camerapointtype( m_CameraPointType );
		v.mutable_camerapoints()->Reserve(m_CameraPoints.size());
		for (int i=0; i<(int)m_CameraPoints.size(); i++)
		{
			*v.add_camerapoints() = m_CameraPoints[i].ToPB();
		}
		v.set_freetype( m_FreeType );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		DramaModuleCommandInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>CommandType(Action类型) [sint32]</li>\r\n";
		htmlBuff += "<li>StartTime(开始时间) [float]</li>\r\n";
		htmlBuff += "<li>DurationTime(持续时间) [float]</li>\r\n";
		htmlBuff += "<li>CreateObjectType(创建资源类型) [sint32]</li>\r\n";
		htmlBuff += "<li>CreateNPCid(创建NPC) [sint32]</li>\r\n";
		htmlBuff += "<li>CreateNpcTransform(CreateNpcTransform) [Transform]</li>\r\n";
		htmlBuff += "<li>Trigger(是否触发) [bool]</li>\r\n";
		htmlBuff += "<li>SubtitleStyle(字幕类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SubtitleID(字幕id) [sint32]</li>\r\n";
		htmlBuff += "<li>SubtitleTargetType(字幕目标类型) [sint32]</li>\r\n";
		htmlBuff += "<li>SubtitleTargetConfigId(目标配置id) [sint32]</li>\r\n";
		htmlBuff += "<li>TranslatePostion(最终位置) [V3]</li>\r\n";
		htmlBuff += "<li>TranslateTime(位移的时间) [float]</li>\r\n";
		htmlBuff += "<li>TranslateCurve(曲线) [sint32]</li>\r\n";
		htmlBuff += "<li>TranslateTargetType(位移目标类型) [sint32]</li>\r\n";
		htmlBuff += "<li>TranslateTargetId(TranslateTargetId) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillId(技能id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkllTargetId(释放技能者id) [sint32]</li>\r\n";
		htmlBuff += "<li>SkillPostion(技能释放位置) [V3]</li>\r\n";
		htmlBuff += "<li>SkillTargetType(释放技能) [sint32]</li>\r\n";
		htmlBuff += "<li>MusicFileName(音乐) [string]</li>\r\n";
		htmlBuff += "<li>SoundFileName(音效) [string]</li>\r\n";
		htmlBuff += "<li>CameraPointType(摄像机点类型) [sint32]</li>\r\n";
		htmlBuff += "<li>CameraPoints(视点) [CameraPoint] Array</li>\r\n";
		htmlBuff += "<li>FreeType(释放类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>CommandType：%di</li>\r\n",m_CommandType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>StartTime：%.2ff</li>\r\n",m_StartTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DurationTime：%.2ff</li>\r\n",m_DurationTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CreateObjectType：%di</li>\r\n",m_CreateObjectType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>CreateNPCid：%di</li>\r\n",m_CreateNPCid);
		htmlBuff += tmpLine;
		htmlBuff += "<li>CreateNpcTransform：</li>\r\n";
		htmlBuff += m_CreateNpcTransform.HtmlDescHeader();
		htmlBuff += m_CreateNpcTransform.ToHtml();
		tmpLine.Fmt("<li>Trigger：%di</li>\r\n",m_Trigger);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SubtitleStyle：%di</li>\r\n",m_SubtitleStyle);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SubtitleID：%di</li>\r\n",m_SubtitleID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SubtitleTargetType：%di</li>\r\n",m_SubtitleTargetType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SubtitleTargetConfigId：%di</li>\r\n",m_SubtitleTargetConfigId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>TranslatePostion：</li>\r\n";
		htmlBuff += m_TranslatePostion.HtmlDescHeader();
		htmlBuff += m_TranslatePostion.ToHtml();
		tmpLine.Fmt("<li>TranslateTime：%.2ff</li>\r\n",m_TranslateTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TranslateCurve：%di</li>\r\n",m_TranslateCurve);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TranslateTargetType：%di</li>\r\n",m_TranslateTargetType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TranslateTargetId：%di</li>\r\n",m_TranslateTargetId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkillId：%di</li>\r\n",m_SkillId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>SkllTargetId：%di</li>\r\n",m_SkllTargetId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>SkillPostion：</li>\r\n";
		htmlBuff += m_SkillPostion.HtmlDescHeader();
		htmlBuff += m_SkillPostion.ToHtml();
		tmpLine.Fmt("<li>SkillTargetType：%di</li>\r\n",m_SkillTargetType);
		htmlBuff += tmpLine;
		htmlBuff += "<li>MusicFileName：\""+m_MusicFileName+"\"</li>\r\n";
		htmlBuff += "<li>SoundFileName：\""+m_SoundFileName+"\"</li>\r\n";
		tmpLine.Fmt("<li>CameraPointType：%di</li>\r\n",m_CameraPointType);
		htmlBuff += tmpLine;
		htmlBuff += "<li>CameraPoints：</li>\r\n";
		if( m_CameraPoints.size()>0) htmlBuff += m_CameraPoints[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_CameraPoints.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_CameraPoints[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>FreeType：%di</li>\r\n",m_FreeType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DramaModuleCommandInfoV1& v)
	{
		m_CommandType = v.commandtype();
		m_StartTime = v.starttime();
		m_DurationTime = v.durationtime();
		m_CreateObjectType = v.createobjecttype();
		m_CreateNPCid = v.createnpcid();
		m_CreateNpcTransform = v.createnpctransform();
		m_Trigger = v.trigger();
		m_SubtitleStyle = v.subtitlestyle();
		m_SubtitleID = v.subtitleid();
		m_SubtitleTargetType = v.subtitletargettype();
		m_SubtitleTargetConfigId = v.subtitletargetconfigid();
		m_TranslatePostion = v.translatepostion();
		m_TranslateTime = v.translatetime();
		m_TranslateCurve = v.translatecurve();
		m_TranslateTargetType = v.translatetargettype();
		m_TranslateTargetId = v.translatetargetid();
		m_SkillId = v.skillid();
		m_SkllTargetId = v.sklltargetid();
		m_SkillPostion = v.skillpostion();
		m_SkillTargetType = v.skilltargettype();
		m_MusicFileName = v.musicfilename();
		m_SoundFileName = v.soundfilename();
		m_CameraPointType = v.camerapointtype();
		m_CameraPoints.clear();
		m_CameraPoints.reserve(v.camerapoints_size());
		for( int i=0; i<v.camerapoints_size(); i++)
			m_CameraPoints.push_back(v.camerapoints(i));
		m_FreeType = v.freetype();

	}

private:
	//Action类型
	INT32 m_CommandType;
public:
	void SetCommandType( INT32 v)
	{
		m_CommandType=v;
	}
	INT32 GetCommandType()
	{
		return m_CommandType;
	}
	INT32 GetCommandType() const
	{
		return m_CommandType;
	}
private:
	//开始时间
	float m_StartTime;
public:
	void SetStartTime( float v)
	{
		m_StartTime=v;
	}
	float GetStartTime()
	{
		return m_StartTime;
	}
	float GetStartTime() const
	{
		return m_StartTime;
	}
private:
	//持续时间
	float m_DurationTime;
public:
	void SetDurationTime( float v)
	{
		m_DurationTime=v;
	}
	float GetDurationTime()
	{
		return m_DurationTime;
	}
	float GetDurationTime() const
	{
		return m_DurationTime;
	}
private:
	//创建资源类型
	INT32 m_CreateObjectType;
public:
	void SetCreateObjectType( INT32 v)
	{
		m_CreateObjectType=v;
	}
	INT32 GetCreateObjectType()
	{
		return m_CreateObjectType;
	}
	INT32 GetCreateObjectType() const
	{
		return m_CreateObjectType;
	}
private:
	//创建NPC
	INT32 m_CreateNPCid;
public:
	void SetCreateNPCid( INT32 v)
	{
		m_CreateNPCid=v;
	}
	INT32 GetCreateNPCid()
	{
		return m_CreateNPCid;
	}
	INT32 GetCreateNPCid() const
	{
		return m_CreateNPCid;
	}
private:
	//CreateNpcTransform
	DramaModuleTransformWraperV1 m_CreateNpcTransform;
public:
	void SetCreateNpcTransform( const DramaModuleTransformWraperV1& v)
	{
		m_CreateNpcTransform=v;
	}
	DramaModuleTransformWraperV1 GetCreateNpcTransform()
	{
		return m_CreateNpcTransform;
	}
	DramaModuleTransformWraperV1 GetCreateNpcTransform() const
	{
		return m_CreateNpcTransform;
	}
private:
	//是否触发
	bool m_Trigger;
public:
	void SetTrigger( bool v)
	{
		m_Trigger=v;
	}
	bool GetTrigger()
	{
		return m_Trigger;
	}
	bool GetTrigger() const
	{
		return m_Trigger;
	}
private:
	//字幕类型
	INT32 m_SubtitleStyle;
public:
	void SetSubtitleStyle( INT32 v)
	{
		m_SubtitleStyle=v;
	}
	INT32 GetSubtitleStyle()
	{
		return m_SubtitleStyle;
	}
	INT32 GetSubtitleStyle() const
	{
		return m_SubtitleStyle;
	}
private:
	//字幕id
	INT32 m_SubtitleID;
public:
	void SetSubtitleID( INT32 v)
	{
		m_SubtitleID=v;
	}
	INT32 GetSubtitleID()
	{
		return m_SubtitleID;
	}
	INT32 GetSubtitleID() const
	{
		return m_SubtitleID;
	}
private:
	//字幕目标类型
	INT32 m_SubtitleTargetType;
public:
	void SetSubtitleTargetType( INT32 v)
	{
		m_SubtitleTargetType=v;
	}
	INT32 GetSubtitleTargetType()
	{
		return m_SubtitleTargetType;
	}
	INT32 GetSubtitleTargetType() const
	{
		return m_SubtitleTargetType;
	}
private:
	//目标配置id
	INT32 m_SubtitleTargetConfigId;
public:
	void SetSubtitleTargetConfigId( INT32 v)
	{
		m_SubtitleTargetConfigId=v;
	}
	INT32 GetSubtitleTargetConfigId()
	{
		return m_SubtitleTargetConfigId;
	}
	INT32 GetSubtitleTargetConfigId() const
	{
		return m_SubtitleTargetConfigId;
	}
private:
	//最终位置
	DramaModuleV3WraperV1 m_TranslatePostion;
public:
	void SetTranslatePostion( const DramaModuleV3WraperV1& v)
	{
		m_TranslatePostion=v;
	}
	DramaModuleV3WraperV1 GetTranslatePostion()
	{
		return m_TranslatePostion;
	}
	DramaModuleV3WraperV1 GetTranslatePostion() const
	{
		return m_TranslatePostion;
	}
private:
	//位移的时间
	float m_TranslateTime;
public:
	void SetTranslateTime( float v)
	{
		m_TranslateTime=v;
	}
	float GetTranslateTime()
	{
		return m_TranslateTime;
	}
	float GetTranslateTime() const
	{
		return m_TranslateTime;
	}
private:
	//曲线
	INT32 m_TranslateCurve;
public:
	void SetTranslateCurve( INT32 v)
	{
		m_TranslateCurve=v;
	}
	INT32 GetTranslateCurve()
	{
		return m_TranslateCurve;
	}
	INT32 GetTranslateCurve() const
	{
		return m_TranslateCurve;
	}
private:
	//位移目标类型
	INT32 m_TranslateTargetType;
public:
	void SetTranslateTargetType( INT32 v)
	{
		m_TranslateTargetType=v;
	}
	INT32 GetTranslateTargetType()
	{
		return m_TranslateTargetType;
	}
	INT32 GetTranslateTargetType() const
	{
		return m_TranslateTargetType;
	}
private:
	//TranslateTargetId
	INT32 m_TranslateTargetId;
public:
	void SetTranslateTargetId( INT32 v)
	{
		m_TranslateTargetId=v;
	}
	INT32 GetTranslateTargetId()
	{
		return m_TranslateTargetId;
	}
	INT32 GetTranslateTargetId() const
	{
		return m_TranslateTargetId;
	}
private:
	//技能id
	INT32 m_SkillId;
public:
	void SetSkillId( INT32 v)
	{
		m_SkillId=v;
	}
	INT32 GetSkillId()
	{
		return m_SkillId;
	}
	INT32 GetSkillId() const
	{
		return m_SkillId;
	}
private:
	//释放技能者id
	INT32 m_SkllTargetId;
public:
	void SetSkllTargetId( INT32 v)
	{
		m_SkllTargetId=v;
	}
	INT32 GetSkllTargetId()
	{
		return m_SkllTargetId;
	}
	INT32 GetSkllTargetId() const
	{
		return m_SkllTargetId;
	}
private:
	//技能释放位置
	DramaModuleV3WraperV1 m_SkillPostion;
public:
	void SetSkillPostion( const DramaModuleV3WraperV1& v)
	{
		m_SkillPostion=v;
	}
	DramaModuleV3WraperV1 GetSkillPostion()
	{
		return m_SkillPostion;
	}
	DramaModuleV3WraperV1 GetSkillPostion() const
	{
		return m_SkillPostion;
	}
private:
	//释放技能
	INT32 m_SkillTargetType;
public:
	void SetSkillTargetType( INT32 v)
	{
		m_SkillTargetType=v;
	}
	INT32 GetSkillTargetType()
	{
		return m_SkillTargetType;
	}
	INT32 GetSkillTargetType() const
	{
		return m_SkillTargetType;
	}
private:
	//音乐
	string m_MusicFileName;
public:
	void SetMusicFileName( const string& v)
	{
		m_MusicFileName=v;
	}
	string GetMusicFileName()
	{
		return m_MusicFileName;
	}
	string GetMusicFileName() const
	{
		return m_MusicFileName;
	}
private:
	//音效
	string m_SoundFileName;
public:
	void SetSoundFileName( const string& v)
	{
		m_SoundFileName=v;
	}
	string GetSoundFileName()
	{
		return m_SoundFileName;
	}
	string GetSoundFileName() const
	{
		return m_SoundFileName;
	}
private:
	//摄像机点类型
	INT32 m_CameraPointType;
public:
	void SetCameraPointType( INT32 v)
	{
		m_CameraPointType=v;
	}
	INT32 GetCameraPointType()
	{
		return m_CameraPointType;
	}
	INT32 GetCameraPointType() const
	{
		return m_CameraPointType;
	}
private:
	//视点
	vector<DramaModuleCameraPointWraperV1> m_CameraPoints;
public:
	int SizeCameraPoints()
	{
		return m_CameraPoints.size();
	}
	const vector<DramaModuleCameraPointWraperV1>& GetCameraPoints() const
	{
		return m_CameraPoints;
	}
	DramaModuleCameraPointWraperV1 GetCameraPoints(int Index) const
	{
		if(Index<0 || Index>=(int)m_CameraPoints.size())
		{
			assert(false);
			return DramaModuleCameraPointWraperV1();
		}
		return m_CameraPoints[Index];
	}
	void SetCameraPoints( const vector<DramaModuleCameraPointWraperV1>& v )
	{
		m_CameraPoints=v;
	}
	void ClearCameraPoints( )
	{
		m_CameraPoints.clear();
	}
	void SetCameraPoints( int Index, const DramaModuleCameraPointWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_CameraPoints.size())
		{
			assert(false);
			return;
		}
		m_CameraPoints[Index] = v;
	}
	void AddCameraPoints( const DramaModuleCameraPointWraperV1& v )
	{
		m_CameraPoints.push_back(v);
	}
private:
	//释放类型
	INT32 m_FreeType;
public:
	void SetFreeType( INT32 v)
	{
		m_FreeType=v;
	}
	INT32 GetFreeType()
	{
		return m_FreeType;
	}
	INT32 GetFreeType() const
	{
		return m_FreeType;
	}

};
//剧情信息封装类
class DramaModuleDramaInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	DramaModuleDramaInfoWraperV1()
	{
		
		m_Name = "";
		m_TotalTime = 0;

	}
	//赋值构造函数
	DramaModuleDramaInfoWraperV1(const DramaModuleDramaInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const DramaModuleDramaInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DramaModuleDramaInfoV1 ToPB() const
	{
		DramaModuleDramaInfoV1 v;
		v.set_name( m_Name );
		v.set_totaltime( m_TotalTime );
		v.mutable_commandlist()->Reserve(m_CommandList.size());
		for (int i=0; i<(int)m_CommandList.size(); i++)
		{
			*v.add_commandlist() = m_CommandList[i].ToPB();
		}

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		DramaModuleDramaInfoV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Name(名字) [string]</li>\r\n";
		htmlBuff += "<li>TotalTime(总时间) [float]</li>\r\n";
		htmlBuff += "<li>CommandList(Actions) [CommandInfo] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Name：\""+m_Name+"\"</li>\r\n";
		tmpLine.Fmt("<li>TotalTime：%.2ff</li>\r\n",m_TotalTime);
		htmlBuff += tmpLine;
		htmlBuff += "<li>CommandList：</li>\r\n";
		if( m_CommandList.size()>0) htmlBuff += m_CommandList[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_CommandList.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_CommandList[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DramaModuleDramaInfoV1& v)
	{
		m_Name = v.name();
		m_TotalTime = v.totaltime();
		m_CommandList.clear();
		m_CommandList.reserve(v.commandlist_size());
		for( int i=0; i<v.commandlist_size(); i++)
			m_CommandList.push_back(v.commandlist(i));

	}

private:
	//名字
	string m_Name;
public:
	void SetName( const string& v)
	{
		m_Name=v;
	}
	string GetName()
	{
		return m_Name;
	}
	string GetName() const
	{
		return m_Name;
	}
private:
	//总时间
	float m_TotalTime;
public:
	void SetTotalTime( float v)
	{
		m_TotalTime=v;
	}
	float GetTotalTime()
	{
		return m_TotalTime;
	}
	float GetTotalTime() const
	{
		return m_TotalTime;
	}
private:
	//Actions
	vector<DramaModuleCommandInfoWraperV1> m_CommandList;
public:
	int SizeCommandList()
	{
		return m_CommandList.size();
	}
	const vector<DramaModuleCommandInfoWraperV1>& GetCommandList() const
	{
		return m_CommandList;
	}
	DramaModuleCommandInfoWraperV1 GetCommandList(int Index) const
	{
		if(Index<0 || Index>=(int)m_CommandList.size())
		{
			assert(false);
			return DramaModuleCommandInfoWraperV1();
		}
		return m_CommandList[Index];
	}
	void SetCommandList( const vector<DramaModuleCommandInfoWraperV1>& v )
	{
		m_CommandList=v;
	}
	void ClearCommandList( )
	{
		m_CommandList.clear();
	}
	void SetCommandList( int Index, const DramaModuleCommandInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_CommandList.size())
		{
			assert(false);
			return;
		}
		m_CommandList[Index] = v;
	}
	void AddCommandList( const DramaModuleCommandInfoWraperV1& v )
	{
		m_CommandList.push_back(v);
	}

};
//UseLess封装类
class DramaModuleUseLessWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<DramaModuleUseLessWraperV1>
{
public:
	//构造函数
	DramaModuleUseLessWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	DramaModuleUseLessWraperV1(const DramaModuleUseLessV1& v){ Init(v); }
	//等号重载函数
	void operator = (const DramaModuleUseLessV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DramaModuleUseLessV1 ToPB() const
	{
		DramaModuleUseLessV1 v;

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		DramaModuleUseLessV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DramaModuleUseLessV1& v)
	{

	}


};

#endif
