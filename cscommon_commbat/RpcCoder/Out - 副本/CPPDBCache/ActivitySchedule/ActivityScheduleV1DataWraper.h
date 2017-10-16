/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperActivitySchedule.h
* Author:       甘业清
* Description:  活动日常同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ACTIVITYSCHEDULE_H
#define __SYNC_WRAPER_ACTIVITYSCHEDULE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "ActivityScheduleV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//活动数据信息封装类
class ActivityScheduleActiveValueWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleActiveValueWraperV1()
	{
		
		m_ID = 0;
		m_Num = 0;
		m_Vitality = 0;
		m_StartTime = -1;
		m_FinishTime = -1;
		m_ActivityMaxNum = -1;

	}
	//赋值构造函数
	ActivityScheduleActiveValueWraperV1(const ActivityScheduleActiveValueV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleActiveValueV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleActiveValueV1 ToPB() const
	{
		ActivityScheduleActiveValueV1 v;
		v.set_id( m_ID );
		v.set_num( m_Num );
		v.set_vitality( m_Vitality );
		v.set_starttime( m_StartTime );
		v.set_finishtime( m_FinishTime );
		v.set_activitymaxnum( m_ActivityMaxNum );

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
		ActivityScheduleActiveValueV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ID(id) [sint32]</li>\r\n";
		htmlBuff += "<li>Num(次数) [sint32]</li>\r\n";
		htmlBuff += "<li>Vitality(体力) [sint32]</li>\r\n";
		htmlBuff += "<li>StartTime(活动开始时间) [sint32]</li>\r\n";
		htmlBuff += "<li>FinishTime(结束时间) [sint32]</li>\r\n";
		htmlBuff += "<li>ActivityMaxNum(限时活动最大次数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ID：%di</li>\r\n",m_ID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Num：%di</li>\r\n",m_Num);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Vitality：%di</li>\r\n",m_Vitality);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>StartTime：%di</li>\r\n",m_StartTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FinishTime：%di</li>\r\n",m_FinishTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ActivityMaxNum：%di</li>\r\n",m_ActivityMaxNum);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleActiveValueV1& v)
	{
		m_ID = v.id();
		m_Num = v.num();
		m_Vitality = v.vitality();
		m_StartTime = v.starttime();
		m_FinishTime = v.finishtime();
		m_ActivityMaxNum = v.activitymaxnum();

	}

private:
	//id
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}
private:
	//次数
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}
private:
	//体力
	INT32 m_Vitality;
public:
	void SetVitality( INT32 v)
	{
		m_Vitality=v;
	}
	INT32 GetVitality()
	{
		return m_Vitality;
	}
	INT32 GetVitality() const
	{
		return m_Vitality;
	}
private:
	//活动开始时间
	INT32 m_StartTime;
public:
	void SetStartTime( INT32 v)
	{
		m_StartTime=v;
	}
	INT32 GetStartTime()
	{
		return m_StartTime;
	}
	INT32 GetStartTime() const
	{
		return m_StartTime;
	}
private:
	//结束时间
	INT32 m_FinishTime;
public:
	void SetFinishTime( INT32 v)
	{
		m_FinishTime=v;
	}
	INT32 GetFinishTime()
	{
		return m_FinishTime;
	}
	INT32 GetFinishTime() const
	{
		return m_FinishTime;
	}
private:
	//限时活动最大次数
	INT32 m_ActivityMaxNum;
public:
	void SetActivityMaxNum( INT32 v)
	{
		m_ActivityMaxNum=v;
	}
	INT32 GetActivityMaxNum()
	{
		return m_ActivityMaxNum;
	}
	INT32 GetActivityMaxNum() const
	{
		return m_ActivityMaxNum;
	}

};
//活动活力封装类
class ActivityScheduleActiveDateWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<ActivityScheduleActiveDateWraperV1>
{
public:
	//构造函数
	ActivityScheduleActiveDateWraperV1()
	{
		SetDataWraper( this );

		m_Time = -1;

	}
	//赋值构造函数
	ActivityScheduleActiveDateWraperV1(const ActivityScheduleActiveDateV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleActiveDateV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleActiveDateV1 ToPB() const
	{
		ActivityScheduleActiveDateV1 v;
		v.mutable_value()->Reserve(m_Value.size());
		for (int i=0; i<(int)m_Value.size(); i++)
		{
			*v.add_value() = m_Value[i].ToPB();
		}
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
		ActivityScheduleActiveDateV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Value(数据) [ActiveValue] Array</li>\r\n";
		htmlBuff += "<li>Time(时间（服务器专用）) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Value：</li>\r\n";
		if( m_Value.size()>0) htmlBuff += m_Value[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_Value.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_Value[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleActiveDateV1& v)
	{
		m_Value.clear();
		m_Value.reserve(v.value_size());
		for( int i=0; i<v.value_size(); i++)
			m_Value.push_back(v.value(i));
		m_Time = v.time();

	}

private:
	//数据
	vector<ActivityScheduleActiveValueWraperV1> m_Value;
public:
	int SizeValue()
	{
		return m_Value.size();
	}
	const vector<ActivityScheduleActiveValueWraperV1>& GetValue() const
	{
		return m_Value;
	}
	ActivityScheduleActiveValueWraperV1 GetValue(int Index) const
	{
		if(Index<0 || Index>=(int)m_Value.size())
		{
			assert(false);
			return ActivityScheduleActiveValueWraperV1();
		}
		return m_Value[Index];
	}
	void SetValue( const vector<ActivityScheduleActiveValueWraperV1>& v )
	{
		m_Value=v;
	}
	void ClearValue( )
	{
		m_Value.clear();
	}
	void SetValue( int Index, const ActivityScheduleActiveValueWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_Value.size())
		{
			assert(false);
			return;
		}
		m_Value[Index] = v;
	}
	void AddValue( const ActivityScheduleActiveValueWraperV1& v )
	{
		m_Value.push_back(v);
	}
private:
	//时间（服务器专用）
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

};

#endif
