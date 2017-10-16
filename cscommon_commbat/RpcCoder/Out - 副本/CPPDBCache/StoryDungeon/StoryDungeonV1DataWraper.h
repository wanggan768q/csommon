/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperStoryDungeon.h
* Author:       甘业清
* Description:  剧情副本同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_STORYDUNGEON_H
#define __SYNC_WRAPER_STORYDUNGEON_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "StoryDungeonV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//剧情副本对象封装类
class StoryDungeonStoryDungeonObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonStoryDungeonObjWraperV1()
	{
		
		m_Id = -1;
		m_IsLock = true;

	}
	//赋值构造函数
	StoryDungeonStoryDungeonObjWraperV1(const StoryDungeonStoryDungeonObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonStoryDungeonObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonStoryDungeonObjV1 ToPB() const
	{
		StoryDungeonStoryDungeonObjV1 v;
		v.set_id( m_Id );
		v.set_islock( m_IsLock );

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
		StoryDungeonStoryDungeonObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(Id) [sint32]</li>\r\n";
		htmlBuff += "<li>IsLock(副本锁定) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>IsLock：%di</li>\r\n",m_IsLock);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const StoryDungeonStoryDungeonObjV1& v)
	{
		m_Id = v.id();
		m_IsLock = v.islock();

	}

private:
	//Id
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
	//副本锁定
	bool m_IsLock;
public:
	void SetIsLock( bool v)
	{
		m_IsLock=v;
	}
	bool GetIsLock()
	{
		return m_IsLock;
	}
	bool GetIsLock() const
	{
		return m_IsLock;
	}

};
//剧情副本数据封装类
class StoryDungeonStoryDungeonWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<StoryDungeonStoryDungeonWraperV1>
{
public:
	//构造函数
	StoryDungeonStoryDungeonWraperV1()
	{
		SetDataWraper( this );

		m_ChallengeNum = 0;

	}
	//赋值构造函数
	StoryDungeonStoryDungeonWraperV1(const StoryDungeonStoryDungeonV1& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonStoryDungeonV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonStoryDungeonV1 ToPB() const
	{
		StoryDungeonStoryDungeonV1 v;
		v.mutable_storydungeon()->Reserve(m_StoryDungeon.size());
		for (int i=0; i<(int)m_StoryDungeon.size(); i++)
		{
			*v.add_storydungeon() = m_StoryDungeon[i].ToPB();
		}
		v.set_challengenum( m_ChallengeNum );

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
		StoryDungeonStoryDungeonV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>StoryDungeon(剧情副本数据) [StoryDungeonObj] Array</li>\r\n";
		htmlBuff += "<li>ChallengeNum(剩余挑战次数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>StoryDungeon：</li>\r\n";
		if( m_StoryDungeon.size()>0) htmlBuff += m_StoryDungeon[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_StoryDungeon.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_StoryDungeon[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>ChallengeNum：%di</li>\r\n",m_ChallengeNum);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const StoryDungeonStoryDungeonV1& v)
	{
		m_StoryDungeon.clear();
		m_StoryDungeon.reserve(v.storydungeon_size());
		for( int i=0; i<v.storydungeon_size(); i++)
			m_StoryDungeon.push_back(v.storydungeon(i));
		m_ChallengeNum = v.challengenum();

	}

private:
	//剧情副本数据
	vector<StoryDungeonStoryDungeonObjWraperV1> m_StoryDungeon;
public:
	int SizeStoryDungeon()
	{
		return m_StoryDungeon.size();
	}
	const vector<StoryDungeonStoryDungeonObjWraperV1>& GetStoryDungeon() const
	{
		return m_StoryDungeon;
	}
	StoryDungeonStoryDungeonObjWraperV1 GetStoryDungeon(int Index) const
	{
		if(Index<0 || Index>=(int)m_StoryDungeon.size())
		{
			assert(false);
			return StoryDungeonStoryDungeonObjWraperV1();
		}
		return m_StoryDungeon[Index];
	}
	void SetStoryDungeon( const vector<StoryDungeonStoryDungeonObjWraperV1>& v )
	{
		m_StoryDungeon=v;
	}
	void ClearStoryDungeon( )
	{
		m_StoryDungeon.clear();
	}
	void SetStoryDungeon( int Index, const StoryDungeonStoryDungeonObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_StoryDungeon.size())
		{
			assert(false);
			return;
		}
		m_StoryDungeon[Index] = v;
	}
	void AddStoryDungeon( const StoryDungeonStoryDungeonObjWraperV1& v )
	{
		m_StoryDungeon.push_back(v);
	}
private:
	//剩余挑战次数
	INT32 m_ChallengeNum;
public:
	void SetChallengeNum( INT32 v)
	{
		m_ChallengeNum=v;
	}
	INT32 GetChallengeNum()
	{
		return m_ChallengeNum;
	}
	INT32 GetChallengeNum() const
	{
		return m_ChallengeNum;
	}

};

#endif
