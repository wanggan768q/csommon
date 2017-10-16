/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperActivityStorm.h
* Author:       甘业清
* Description:  活动 风暴同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ACTIVITYSTORM_H
#define __SYNC_WRAPER_ACTIVITYSTORM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "ActivityStormV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//五行旗数据封装类
class ActivityStormActivityStormWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<ActivityStormActivityStormWraperV1>
{
public:
	//构造函数
	ActivityStormActivityStormWraperV1()
	{
		SetDataWraper( this );

		m_Type = -1;
		m_Time = -1;
		m_ActID = -1;
		m_LvD = -1;

	}
	//赋值构造函数
	ActivityStormActivityStormWraperV1(const ActivityStormActivityStormV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormActivityStormV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormActivityStormV1 ToPB() const
	{
		ActivityStormActivityStormV1 v;
		v.set_type( m_Type );
		v.set_time( m_Time );
		v.set_actid( m_ActID );
		v.set_lvd( m_LvD );

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
		ActivityStormActivityStormV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(倒计时时间) [sint32]</li>\r\n";
		htmlBuff += "<li>ActID(战斗id 需要确认时候带回) [sint32]</li>\r\n";
		htmlBuff += "<li>LvD(等级段) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ActID：%di</li>\r\n",m_ActID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>LvD：%di</li>\r\n",m_LvD);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityStormActivityStormV1& v)
	{
		m_Type = v.type();
		m_Time = v.time();
		m_ActID = v.actid();
		m_LvD = v.lvd();

	}

private:
	//类型
	INT32 m_Type;
public:
	void SetType( INT32 v)
	{
		m_Type=v;
	}
	INT32 GetType()
	{
		return m_Type;
	}
	INT32 GetType() const
	{
		return m_Type;
	}
private:
	//倒计时时间
	INT32 m_Time;
public:
	void SetTime( INT32 v)
	{
		m_Time=v;
	}
	INT32 GetTime()
	{
		return m_Time;
	}
	INT32 GetTime() const
	{
		return m_Time;
	}
private:
	//战斗id 需要确认时候带回
	INT32 m_ActID;
public:
	void SetActID( INT32 v)
	{
		m_ActID=v;
	}
	INT32 GetActID()
	{
		return m_ActID;
	}
	INT32 GetActID() const
	{
		return m_ActID;
	}
private:
	//等级段
	INT32 m_LvD;
public:
	void SetLvD( INT32 v)
	{
		m_LvD=v;
	}
	INT32 GetLvD()
	{
		return m_LvD;
	}
	INT32 GetLvD() const
	{
		return m_LvD;
	}

};

#endif
