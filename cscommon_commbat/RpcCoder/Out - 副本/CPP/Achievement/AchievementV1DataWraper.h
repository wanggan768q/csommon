/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperAchievement.h
* Author:       甘业清
* Description:  成就同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_ACHIEVEMENT_H
#define __SYNC_WRAPER_ACHIEVEMENT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "AchievementV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//成就对象封装类
class AchievementAchiObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	AchievementAchiObjWraperV1()
	{
		
		m_GroupId = -1;
		m_Star = -1;
		m_Status = -1;
		m_Id = -1;
		m_Type = -1;

	}
	//赋值构造函数
	AchievementAchiObjWraperV1(const AchievementAchiObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const AchievementAchiObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AchievementAchiObjV1 ToPB() const
	{
		AchievementAchiObjV1 v;
		v.set_groupid( m_GroupId );
		v.set_star( m_Star );
		v.set_status( m_Status );
		v.set_id( m_Id );
		v.set_type( m_Type );

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
		AchievementAchiObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GroupId(组id，使用解锁条件) [sint32]</li>\r\n";
		htmlBuff += "<li>Star(星级) [sint32]</li>\r\n";
		htmlBuff += "<li>Status(完成状态(0未完成,1完成未领奖，2已领奖）) [sint32]</li>\r\n";
		htmlBuff += "<li>Id(成就Id) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(成长，活动，社交) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>GroupId：%di</li>\r\n",m_GroupId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Star：%di</li>\r\n",m_Star);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Status：%di</li>\r\n",m_Status);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const AchievementAchiObjV1& v)
	{
		m_GroupId = v.groupid();
		m_Star = v.star();
		m_Status = v.status();
		m_Id = v.id();
		m_Type = v.type();

	}

private:
	//组id，使用解锁条件
	INT32 m_GroupId;
public:
	void SetGroupId( INT32 v)
	{
		m_GroupId=v;
	}
	INT32 GetGroupId()
	{
		return m_GroupId;
	}
	INT32 GetGroupId() const
	{
		return m_GroupId;
	}
private:
	//星级
	INT32 m_Star;
public:
	void SetStar( INT32 v)
	{
		m_Star=v;
	}
	INT32 GetStar()
	{
		return m_Star;
	}
	INT32 GetStar() const
	{
		return m_Star;
	}
private:
	//完成状态(0未完成,1完成未领奖，2已领奖）
	INT32 m_Status;
public:
	void SetStatus( INT32 v)
	{
		m_Status=v;
	}
	INT32 GetStatus()
	{
		return m_Status;
	}
	INT32 GetStatus() const
	{
		return m_Status;
	}
private:
	//成就Id
	INT32 m_Id;
public:
	void SetId( INT32 v)
	{
		m_Id=v;
	}
	INT32 GetId()
	{
		return m_Id;
	}
	INT32 GetId() const
	{
		return m_Id;
	}
private:
	//成长，活动，社交
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

};
//成就数据封装类
class AchievementAchiDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<AchievementAchiDataWraperV1>
{
public:
	//构造函数
	AchievementAchiDataWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	AchievementAchiDataWraperV1(const AchievementAchiDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const AchievementAchiDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AchievementAchiDataV1 ToPB() const
	{
		AchievementAchiDataV1 v;
		v.mutable_achidata()->Reserve(m_AchiData.size());
		for (int i=0; i<(int)m_AchiData.size(); i++)
		{
			*v.add_achidata() = m_AchiData[i].ToPB();
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
		AchievementAchiDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>AchiData(成就数据) [AchiObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>AchiData：</li>\r\n";
		if( m_AchiData.size()>0) htmlBuff += m_AchiData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_AchiData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_AchiData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const AchievementAchiDataV1& v)
	{
		m_AchiData.clear();
		m_AchiData.reserve(v.achidata_size());
		for( int i=0; i<v.achidata_size(); i++)
			m_AchiData.push_back(v.achidata(i));

	}

private:
	//成就数据
	vector<AchievementAchiObjWraperV1> m_AchiData;
public:
	int SizeAchiData()
	{
		return m_AchiData.size();
	}
	const vector<AchievementAchiObjWraperV1>& GetAchiData() const
	{
		return m_AchiData;
	}
	AchievementAchiObjWraperV1 GetAchiData(int Index) const
	{
		if(Index<0 || Index>=(int)m_AchiData.size())
		{
			assert(false);
			return AchievementAchiObjWraperV1();
		}
		return m_AchiData[Index];
	}
	void SetAchiData( const vector<AchievementAchiObjWraperV1>& v )
	{
		m_AchiData=v;
	}
	void ClearAchiData( )
	{
		m_AchiData.clear();
	}
	void SetAchiData( int Index, const AchievementAchiObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_AchiData.size())
		{
			assert(false);
			return;
		}
		m_AchiData[Index] = v;
	}
	void AddAchiData( const AchievementAchiObjWraperV1& v )
	{
		m_AchiData.push_back(v);
	}

};

#endif
