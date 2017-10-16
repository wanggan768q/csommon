/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperActivitySchedule.h
* Author:       甘业清
* Description:  活动日常RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ACTIVITYSCHEDULE_H
#define __RPC_WRAPER_ACTIVITYSCHEDULE_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ActivityScheduleRpc.pb.h"



//活动日常类的枚举定义
enum ConstActivityScheduleE
{
	MODULE_ID_ACTIVITYSCHEDULE                   = 32,	//活动日常模块ID
	RPC_CODE_ACTIVITYSCHEDULE_SYNCDATA_REQUEST   = 3251,	//活动日常-->活动日常数据-->请求
	RPC_CODE_ACTIVITYSCHEDULE_THIEFBEOPENED_NOTIFY= 3252,	//活动日常-->江洋大盗被开启通知-->通知
	RPC_CODE_ACTIVITYSCHEDULE_THIEFREFRESH_NOTIFY= 3253,	//活动日常-->江洋大盗刷新-->通知
	RPC_CODE_ACTIVITYSCHEDULE_THIEFOPENMONSTER_REQUEST= 3254,	//活动日常-->江洋大盗开怪-->请求
	RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERENTER_REQUEST= 3255,	//活动日常-->降妖进入副本-->请求
	RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERBEOPENED_NOTIFY= 3256,	//活动日常-->降妖被其他人开启-->通知
	RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERREFRESH_NOTIFY= 3257,	//活动日常-->降妖除魔刷新Npc-->通知
	RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSENTERDUNGEON_REQUEST= 3258,	//活动日常-->世界Boss进行副本-->请求
	RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSSYNCDATA_REQUEST= 3259,	//活动日常-->世界Boss,打开界面刷新数据-->请求


};


//降妖被其他人开启通知封装类
class ActivityScheduleRpcSubdueMonsterBeOpenedNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcSubdueMonsterBeOpenedNotifyWraper()
	{
		
		m_SubdueMonsterData = ActivityNpcDataWraper();

	}
	//赋值构造函数
	ActivityScheduleRpcSubdueMonsterBeOpenedNotifyWraper(const ActivityScheduleRpcSubdueMonsterBeOpenedNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcSubdueMonsterBeOpenedNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcSubdueMonsterBeOpenedNotify ToPB() const
	{
		ActivityScheduleRpcSubdueMonsterBeOpenedNotify v;
		*v.mutable_subduemonsterdata()= m_SubdueMonsterData.ToPB();

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
		ActivityScheduleRpcSubdueMonsterBeOpenedNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SubdueMonsterData(降妖活动数据) [ActivityNpcData]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SubdueMonsterData：</li>\r\n";
		htmlBuff += m_SubdueMonsterData.HtmlDescHeader();
		htmlBuff += m_SubdueMonsterData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcSubdueMonsterBeOpenedNotify& v)
	{
		m_SubdueMonsterData = v.subduemonsterdata();

	}

private:
	//降妖活动数据
	ActivityNpcDataWraper m_SubdueMonsterData;
public:
	void SetSubdueMonsterData( const ActivityNpcDataWraper& v)
	{
		m_SubdueMonsterData=v;
	}
	ActivityNpcDataWraper GetSubdueMonsterData()
	{
		return m_SubdueMonsterData;
	}
	ActivityNpcDataWraper GetSubdueMonsterData() const
	{
		return m_SubdueMonsterData;
	}

};
//降妖除魔刷新Npc通知封装类
class ActivityScheduleRpcSubdueMonsterRefreshNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcSubdueMonsterRefreshNotifyWraper()
	{
		

	}
	//赋值构造函数
	ActivityScheduleRpcSubdueMonsterRefreshNotifyWraper(const ActivityScheduleRpcSubdueMonsterRefreshNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcSubdueMonsterRefreshNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcSubdueMonsterRefreshNotify ToPB() const
	{
		ActivityScheduleRpcSubdueMonsterRefreshNotify v;
		v.mutable_subduemonsterdata()->Reserve(m_SubdueMonsterData.size());
		for (int i=0; i<(int)m_SubdueMonsterData.size(); i++)
		{
			*v.add_subduemonsterdata() = m_SubdueMonsterData[i].ToPB();
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
		ActivityScheduleRpcSubdueMonsterRefreshNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SubdueMonsterData(降妖活动数据) [ActivityNpcData] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SubdueMonsterData：</li>\r\n";
		if( m_SubdueMonsterData.size()>0) htmlBuff += m_SubdueMonsterData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SubdueMonsterData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SubdueMonsterData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcSubdueMonsterRefreshNotify& v)
	{
		m_SubdueMonsterData.clear();
		m_SubdueMonsterData.reserve(v.subduemonsterdata_size());
		for( int i=0; i<v.subduemonsterdata_size(); i++)
			m_SubdueMonsterData.push_back(v.subduemonsterdata(i));

	}

private:
	//降妖活动数据
	vector<ActivityNpcDataWraper> m_SubdueMonsterData;
public:
	int SizeSubdueMonsterData()
	{
		return m_SubdueMonsterData.size();
	}
	const vector<ActivityNpcDataWraper>& GetSubdueMonsterData() const
	{
		return m_SubdueMonsterData;
	}
	ActivityNpcDataWraper GetSubdueMonsterData(int Index) const
	{
		if(Index<0 || Index>=(int)m_SubdueMonsterData.size())
		{
			assert(false);
			return ActivityNpcDataWraper();
		}
		return m_SubdueMonsterData[Index];
	}
	void SetSubdueMonsterData( const vector<ActivityNpcDataWraper>& v )
	{
		m_SubdueMonsterData=v;
	}
	void ClearSubdueMonsterData( )
	{
		m_SubdueMonsterData.clear();
	}
	void SetSubdueMonsterData( int Index, const ActivityNpcDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_SubdueMonsterData.size())
		{
			assert(false);
			return;
		}
		m_SubdueMonsterData[Index] = v;
	}
	void AddSubdueMonsterData( const ActivityNpcDataWraper& v )
	{
		m_SubdueMonsterData.push_back(v);
	}

};
//降妖进入副本请求封装类
class ActivityScheduleRpcSubdueMonsterEnterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcSubdueMonsterEnterAskWraper()
	{
		
		m_SubdueMonsterData = ActivityNpcDataWraper();

	}
	//赋值构造函数
	ActivityScheduleRpcSubdueMonsterEnterAskWraper(const ActivityScheduleRpcSubdueMonsterEnterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcSubdueMonsterEnterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcSubdueMonsterEnterAsk ToPB() const
	{
		ActivityScheduleRpcSubdueMonsterEnterAsk v;
		*v.mutable_subduemonsterdata()= m_SubdueMonsterData.ToPB();

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
		ActivityScheduleRpcSubdueMonsterEnterAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>SubdueMonsterData(降妖活动数据) [ActivityNpcData]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>SubdueMonsterData：</li>\r\n";
		htmlBuff += m_SubdueMonsterData.HtmlDescHeader();
		htmlBuff += m_SubdueMonsterData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcSubdueMonsterEnterAsk& v)
	{
		m_SubdueMonsterData = v.subduemonsterdata();

	}

private:
	//降妖活动数据
	ActivityNpcDataWraper m_SubdueMonsterData;
public:
	void SetSubdueMonsterData( const ActivityNpcDataWraper& v)
	{
		m_SubdueMonsterData=v;
	}
	ActivityNpcDataWraper GetSubdueMonsterData()
	{
		return m_SubdueMonsterData;
	}
	ActivityNpcDataWraper GetSubdueMonsterData() const
	{
		return m_SubdueMonsterData;
	}

};
//降妖进入副本回应封装类
class ActivityScheduleRpcSubdueMonsterEnterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcSubdueMonsterEnterReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ActivityScheduleRpcSubdueMonsterEnterReplyWraper(const ActivityScheduleRpcSubdueMonsterEnterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcSubdueMonsterEnterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcSubdueMonsterEnterReply ToPB() const
	{
		ActivityScheduleRpcSubdueMonsterEnterReply v;
		v.set_result( m_Result );

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
		ActivityScheduleRpcSubdueMonsterEnterReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcSubdueMonsterEnterReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//世界Boss,打开界面刷新数据请求封装类
class ActivityScheduleRpcWorldBossSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcWorldBossSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityScheduleRpcWorldBossSyncDataAskWraper(const ActivityScheduleRpcWorldBossSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcWorldBossSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcWorldBossSyncDataAsk ToPB() const
	{
		ActivityScheduleRpcWorldBossSyncDataAsk v;

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
		ActivityScheduleRpcWorldBossSyncDataAsk pb;
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
	void Init(const ActivityScheduleRpcWorldBossSyncDataAsk& v)
	{

	}


};
//世界Boss,打开界面刷新数据回应封装类
class ActivityScheduleRpcWorldBossSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcWorldBossSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ActivityScheduleRpcWorldBossSyncDataReplyWraper(const ActivityScheduleRpcWorldBossSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcWorldBossSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcWorldBossSyncDataReply ToPB() const
	{
		ActivityScheduleRpcWorldBossSyncDataReply v;
		v.set_result( m_Result );
		v.mutable_worldbossdata()->Reserve(m_WorldBossData.size());
		for (int i=0; i<(int)m_WorldBossData.size(); i++)
		{
			*v.add_worldbossdata() = m_WorldBossData[i].ToPB();
		}
		v.mutable_worldbossrank()->Reserve(m_WorldBossRank.size());
		for (int i=0; i<(int)m_WorldBossRank.size(); i++)
		{
			*v.add_worldbossrank() = m_WorldBossRank[i].ToPB();
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
		ActivityScheduleRpcWorldBossSyncDataReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>WorldBossData(世界Boss数据) [WorldBossObj] Array</li>\r\n";
		htmlBuff += "<li>WorldBossRank(世界Boss排名) [WorldBossRankObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>WorldBossData：</li>\r\n";
		if( m_WorldBossData.size()>0) htmlBuff += m_WorldBossData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_WorldBossData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_WorldBossData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>WorldBossRank：</li>\r\n";
		if( m_WorldBossRank.size()>0) htmlBuff += m_WorldBossRank[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_WorldBossRank.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_WorldBossRank[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcWorldBossSyncDataReply& v)
	{
		m_Result = v.result();
		m_WorldBossData.clear();
		m_WorldBossData.reserve(v.worldbossdata_size());
		for( int i=0; i<v.worldbossdata_size(); i++)
			m_WorldBossData.push_back(v.worldbossdata(i));
		m_WorldBossRank.clear();
		m_WorldBossRank.reserve(v.worldbossrank_size());
		for( int i=0; i<v.worldbossrank_size(); i++)
			m_WorldBossRank.push_back(v.worldbossrank(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//世界Boss数据
	vector<WorldBossObjWraper> m_WorldBossData;
public:
	int SizeWorldBossData()
	{
		return m_WorldBossData.size();
	}
	const vector<WorldBossObjWraper>& GetWorldBossData() const
	{
		return m_WorldBossData;
	}
	WorldBossObjWraper GetWorldBossData(int Index) const
	{
		if(Index<0 || Index>=(int)m_WorldBossData.size())
		{
			assert(false);
			return WorldBossObjWraper();
		}
		return m_WorldBossData[Index];
	}
	void SetWorldBossData( const vector<WorldBossObjWraper>& v )
	{
		m_WorldBossData=v;
	}
	void ClearWorldBossData( )
	{
		m_WorldBossData.clear();
	}
	void SetWorldBossData( int Index, const WorldBossObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_WorldBossData.size())
		{
			assert(false);
			return;
		}
		m_WorldBossData[Index] = v;
	}
	void AddWorldBossData( const WorldBossObjWraper& v )
	{
		m_WorldBossData.push_back(v);
	}
private:
	//世界Boss排名
	vector<WorldBossRankObjWraper> m_WorldBossRank;
public:
	int SizeWorldBossRank()
	{
		return m_WorldBossRank.size();
	}
	const vector<WorldBossRankObjWraper>& GetWorldBossRank() const
	{
		return m_WorldBossRank;
	}
	WorldBossRankObjWraper GetWorldBossRank(int Index) const
	{
		if(Index<0 || Index>=(int)m_WorldBossRank.size())
		{
			assert(false);
			return WorldBossRankObjWraper();
		}
		return m_WorldBossRank[Index];
	}
	void SetWorldBossRank( const vector<WorldBossRankObjWraper>& v )
	{
		m_WorldBossRank=v;
	}
	void ClearWorldBossRank( )
	{
		m_WorldBossRank.clear();
	}
	void SetWorldBossRank( int Index, const WorldBossRankObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_WorldBossRank.size())
		{
			assert(false);
			return;
		}
		m_WorldBossRank[Index] = v;
	}
	void AddWorldBossRank( const WorldBossRankObjWraper& v )
	{
		m_WorldBossRank.push_back(v);
	}

};
//世界Boss进行副本请求封装类
class ActivityScheduleRpcWorldBossEnterDungeonAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcWorldBossEnterDungeonAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityScheduleRpcWorldBossEnterDungeonAskWraper(const ActivityScheduleRpcWorldBossEnterDungeonAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcWorldBossEnterDungeonAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcWorldBossEnterDungeonAsk ToPB() const
	{
		ActivityScheduleRpcWorldBossEnterDungeonAsk v;

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
		ActivityScheduleRpcWorldBossEnterDungeonAsk pb;
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
	void Init(const ActivityScheduleRpcWorldBossEnterDungeonAsk& v)
	{

	}


};
//世界Boss进行副本回应封装类
class ActivityScheduleRpcWorldBossEnterDungeonReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcWorldBossEnterDungeonReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ActivityScheduleRpcWorldBossEnterDungeonReplyWraper(const ActivityScheduleRpcWorldBossEnterDungeonReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcWorldBossEnterDungeonReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcWorldBossEnterDungeonReply ToPB() const
	{
		ActivityScheduleRpcWorldBossEnterDungeonReply v;
		v.set_result( m_Result );

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
		ActivityScheduleRpcWorldBossEnterDungeonReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcWorldBossEnterDungeonReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//活动日常数据请求封装类
class ActivityScheduleRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityScheduleRpcSyncDataAskWraper(const ActivityScheduleRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcSyncDataAsk ToPB() const
	{
		ActivityScheduleRpcSyncDataAsk v;

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
		ActivityScheduleRpcSyncDataAsk pb;
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
	void Init(const ActivityScheduleRpcSyncDataAsk& v)
	{

	}


};
//活动日常数据回应封装类
class ActivityScheduleRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ActivityScheduleRpcSyncDataReplyWraper(const ActivityScheduleRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcSyncDataReply ToPB() const
	{
		ActivityScheduleRpcSyncDataReply v;
		v.set_result( m_Result );
		v.mutable_thiefdata()->Reserve(m_ThiefData.size());
		for (int i=0; i<(int)m_ThiefData.size(); i++)
		{
			*v.add_thiefdata() = m_ThiefData[i].ToPB();
		}
		v.mutable_subduemonsterdata()->Reserve(m_SubdueMonsterData.size());
		for (int i=0; i<(int)m_SubdueMonsterData.size(); i++)
		{
			*v.add_subduemonsterdata() = m_SubdueMonsterData[i].ToPB();
		}
		v.mutable_worldbossdata()->Reserve(m_WorldBossData.size());
		for (int i=0; i<(int)m_WorldBossData.size(); i++)
		{
			*v.add_worldbossdata() = m_WorldBossData[i].ToPB();
		}
		v.mutable_worldbossrank()->Reserve(m_WorldBossRank.size());
		for (int i=0; i<(int)m_WorldBossRank.size(); i++)
		{
			*v.add_worldbossrank() = m_WorldBossRank[i].ToPB();
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
		ActivityScheduleRpcSyncDataReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ThiefData(当前有哪些江洋大盗) [ActivityNpcData] Array</li>\r\n";
		htmlBuff += "<li>SubdueMonsterData(降妖活动数据) [ActivityNpcData] Array</li>\r\n";
		htmlBuff += "<li>WorldBossData(世界Boss数据) [WorldBossObj] Array</li>\r\n";
		htmlBuff += "<li>WorldBossRank(世界Boss排名) [WorldBossRankObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ThiefData：</li>\r\n";
		if( m_ThiefData.size()>0) htmlBuff += m_ThiefData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ThiefData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ThiefData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>SubdueMonsterData：</li>\r\n";
		if( m_SubdueMonsterData.size()>0) htmlBuff += m_SubdueMonsterData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_SubdueMonsterData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_SubdueMonsterData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>WorldBossData：</li>\r\n";
		if( m_WorldBossData.size()>0) htmlBuff += m_WorldBossData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_WorldBossData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_WorldBossData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		htmlBuff += "<li>WorldBossRank：</li>\r\n";
		if( m_WorldBossRank.size()>0) htmlBuff += m_WorldBossRank[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_WorldBossRank.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_WorldBossRank[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcSyncDataReply& v)
	{
		m_Result = v.result();
		m_ThiefData.clear();
		m_ThiefData.reserve(v.thiefdata_size());
		for( int i=0; i<v.thiefdata_size(); i++)
			m_ThiefData.push_back(v.thiefdata(i));
		m_SubdueMonsterData.clear();
		m_SubdueMonsterData.reserve(v.subduemonsterdata_size());
		for( int i=0; i<v.subduemonsterdata_size(); i++)
			m_SubdueMonsterData.push_back(v.subduemonsterdata(i));
		m_WorldBossData.clear();
		m_WorldBossData.reserve(v.worldbossdata_size());
		for( int i=0; i<v.worldbossdata_size(); i++)
			m_WorldBossData.push_back(v.worldbossdata(i));
		m_WorldBossRank.clear();
		m_WorldBossRank.reserve(v.worldbossrank_size());
		for( int i=0; i<v.worldbossrank_size(); i++)
			m_WorldBossRank.push_back(v.worldbossrank(i));

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}
private:
	//当前有哪些江洋大盗
	vector<ActivityNpcDataWraper> m_ThiefData;
public:
	int SizeThiefData()
	{
		return m_ThiefData.size();
	}
	const vector<ActivityNpcDataWraper>& GetThiefData() const
	{
		return m_ThiefData;
	}
	ActivityNpcDataWraper GetThiefData(int Index) const
	{
		if(Index<0 || Index>=(int)m_ThiefData.size())
		{
			assert(false);
			return ActivityNpcDataWraper();
		}
		return m_ThiefData[Index];
	}
	void SetThiefData( const vector<ActivityNpcDataWraper>& v )
	{
		m_ThiefData=v;
	}
	void ClearThiefData( )
	{
		m_ThiefData.clear();
	}
	void SetThiefData( int Index, const ActivityNpcDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ThiefData.size())
		{
			assert(false);
			return;
		}
		m_ThiefData[Index] = v;
	}
	void AddThiefData( const ActivityNpcDataWraper& v )
	{
		m_ThiefData.push_back(v);
	}
private:
	//降妖活动数据
	vector<ActivityNpcDataWraper> m_SubdueMonsterData;
public:
	int SizeSubdueMonsterData()
	{
		return m_SubdueMonsterData.size();
	}
	const vector<ActivityNpcDataWraper>& GetSubdueMonsterData() const
	{
		return m_SubdueMonsterData;
	}
	ActivityNpcDataWraper GetSubdueMonsterData(int Index) const
	{
		if(Index<0 || Index>=(int)m_SubdueMonsterData.size())
		{
			assert(false);
			return ActivityNpcDataWraper();
		}
		return m_SubdueMonsterData[Index];
	}
	void SetSubdueMonsterData( const vector<ActivityNpcDataWraper>& v )
	{
		m_SubdueMonsterData=v;
	}
	void ClearSubdueMonsterData( )
	{
		m_SubdueMonsterData.clear();
	}
	void SetSubdueMonsterData( int Index, const ActivityNpcDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_SubdueMonsterData.size())
		{
			assert(false);
			return;
		}
		m_SubdueMonsterData[Index] = v;
	}
	void AddSubdueMonsterData( const ActivityNpcDataWraper& v )
	{
		m_SubdueMonsterData.push_back(v);
	}
private:
	//世界Boss数据
	vector<WorldBossObjWraper> m_WorldBossData;
public:
	int SizeWorldBossData()
	{
		return m_WorldBossData.size();
	}
	const vector<WorldBossObjWraper>& GetWorldBossData() const
	{
		return m_WorldBossData;
	}
	WorldBossObjWraper GetWorldBossData(int Index) const
	{
		if(Index<0 || Index>=(int)m_WorldBossData.size())
		{
			assert(false);
			return WorldBossObjWraper();
		}
		return m_WorldBossData[Index];
	}
	void SetWorldBossData( const vector<WorldBossObjWraper>& v )
	{
		m_WorldBossData=v;
	}
	void ClearWorldBossData( )
	{
		m_WorldBossData.clear();
	}
	void SetWorldBossData( int Index, const WorldBossObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_WorldBossData.size())
		{
			assert(false);
			return;
		}
		m_WorldBossData[Index] = v;
	}
	void AddWorldBossData( const WorldBossObjWraper& v )
	{
		m_WorldBossData.push_back(v);
	}
private:
	//世界Boss排名
	vector<WorldBossRankObjWraper> m_WorldBossRank;
public:
	int SizeWorldBossRank()
	{
		return m_WorldBossRank.size();
	}
	const vector<WorldBossRankObjWraper>& GetWorldBossRank() const
	{
		return m_WorldBossRank;
	}
	WorldBossRankObjWraper GetWorldBossRank(int Index) const
	{
		if(Index<0 || Index>=(int)m_WorldBossRank.size())
		{
			assert(false);
			return WorldBossRankObjWraper();
		}
		return m_WorldBossRank[Index];
	}
	void SetWorldBossRank( const vector<WorldBossRankObjWraper>& v )
	{
		m_WorldBossRank=v;
	}
	void ClearWorldBossRank( )
	{
		m_WorldBossRank.clear();
	}
	void SetWorldBossRank( int Index, const WorldBossRankObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_WorldBossRank.size())
		{
			assert(false);
			return;
		}
		m_WorldBossRank[Index] = v;
	}
	void AddWorldBossRank( const WorldBossRankObjWraper& v )
	{
		m_WorldBossRank.push_back(v);
	}

};
//江洋大盗开怪请求封装类
class ActivityScheduleRpcThiefOpenMonsterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcThiefOpenMonsterAskWraper()
	{
		
		m_ThiefData = ActivityNpcDataWraper();

	}
	//赋值构造函数
	ActivityScheduleRpcThiefOpenMonsterAskWraper(const ActivityScheduleRpcThiefOpenMonsterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcThiefOpenMonsterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcThiefOpenMonsterAsk ToPB() const
	{
		ActivityScheduleRpcThiefOpenMonsterAsk v;
		*v.mutable_thiefdata()= m_ThiefData.ToPB();

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
		ActivityScheduleRpcThiefOpenMonsterAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ThiefData(需要开启的江洋大盗) [ActivityNpcData]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ThiefData：</li>\r\n";
		htmlBuff += m_ThiefData.HtmlDescHeader();
		htmlBuff += m_ThiefData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcThiefOpenMonsterAsk& v)
	{
		m_ThiefData = v.thiefdata();

	}

private:
	//需要开启的江洋大盗
	ActivityNpcDataWraper m_ThiefData;
public:
	void SetThiefData( const ActivityNpcDataWraper& v)
	{
		m_ThiefData=v;
	}
	ActivityNpcDataWraper GetThiefData()
	{
		return m_ThiefData;
	}
	ActivityNpcDataWraper GetThiefData() const
	{
		return m_ThiefData;
	}

};
//江洋大盗开怪回应封装类
class ActivityScheduleRpcThiefOpenMonsterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcThiefOpenMonsterReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ActivityScheduleRpcThiefOpenMonsterReplyWraper(const ActivityScheduleRpcThiefOpenMonsterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcThiefOpenMonsterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcThiefOpenMonsterReply ToPB() const
	{
		ActivityScheduleRpcThiefOpenMonsterReply v;
		v.set_result( m_Result );

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
		ActivityScheduleRpcThiefOpenMonsterReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcThiefOpenMonsterReply& v)
	{
		m_Result = v.result();

	}

private:
	//返回结果
	INT32 m_Result;
public:
	void SetResult( INT32 v)
	{
		m_Result=v;
	}
	INT32 GetResult()
	{
		return m_Result;
	}
	INT32 GetResult() const
	{
		return m_Result;
	}

};
//江洋大盗被开启通知通知封装类
class ActivityScheduleRpcThiefBeOpenedNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcThiefBeOpenedNotifyWraper()
	{
		
		m_ThiefData = ActivityNpcDataWraper();

	}
	//赋值构造函数
	ActivityScheduleRpcThiefBeOpenedNotifyWraper(const ActivityScheduleRpcThiefBeOpenedNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcThiefBeOpenedNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcThiefBeOpenedNotify ToPB() const
	{
		ActivityScheduleRpcThiefBeOpenedNotify v;
		*v.mutable_thiefdata()= m_ThiefData.ToPB();

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
		ActivityScheduleRpcThiefBeOpenedNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ThiefData(被开启的江洋大盗) [ActivityNpcData]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ThiefData：</li>\r\n";
		htmlBuff += m_ThiefData.HtmlDescHeader();
		htmlBuff += m_ThiefData.ToHtml();

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcThiefBeOpenedNotify& v)
	{
		m_ThiefData = v.thiefdata();

	}

private:
	//被开启的江洋大盗
	ActivityNpcDataWraper m_ThiefData;
public:
	void SetThiefData( const ActivityNpcDataWraper& v)
	{
		m_ThiefData=v;
	}
	ActivityNpcDataWraper GetThiefData()
	{
		return m_ThiefData;
	}
	ActivityNpcDataWraper GetThiefData() const
	{
		return m_ThiefData;
	}

};
//江洋大盗刷新通知封装类
class ActivityScheduleRpcThiefRefreshNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityScheduleRpcThiefRefreshNotifyWraper()
	{
		

	}
	//赋值构造函数
	ActivityScheduleRpcThiefRefreshNotifyWraper(const ActivityScheduleRpcThiefRefreshNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityScheduleRpcThiefRefreshNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityScheduleRpcThiefRefreshNotify ToPB() const
	{
		ActivityScheduleRpcThiefRefreshNotify v;
		v.mutable_thiefdata()->Reserve(m_ThiefData.size());
		for (int i=0; i<(int)m_ThiefData.size(); i++)
		{
			*v.add_thiefdata() = m_ThiefData[i].ToPB();
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
		ActivityScheduleRpcThiefRefreshNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ThiefData(当前有哪些江洋大盗) [ActivityNpcData] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ThiefData：</li>\r\n";
		if( m_ThiefData.size()>0) htmlBuff += m_ThiefData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ThiefData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ThiefData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityScheduleRpcThiefRefreshNotify& v)
	{
		m_ThiefData.clear();
		m_ThiefData.reserve(v.thiefdata_size());
		for( int i=0; i<v.thiefdata_size(); i++)
			m_ThiefData.push_back(v.thiefdata(i));

	}

private:
	//当前有哪些江洋大盗
	vector<ActivityNpcDataWraper> m_ThiefData;
public:
	int SizeThiefData()
	{
		return m_ThiefData.size();
	}
	const vector<ActivityNpcDataWraper>& GetThiefData() const
	{
		return m_ThiefData;
	}
	ActivityNpcDataWraper GetThiefData(int Index) const
	{
		if(Index<0 || Index>=(int)m_ThiefData.size())
		{
			assert(false);
			return ActivityNpcDataWraper();
		}
		return m_ThiefData[Index];
	}
	void SetThiefData( const vector<ActivityNpcDataWraper>& v )
	{
		m_ThiefData=v;
	}
	void ClearThiefData( )
	{
		m_ThiefData.clear();
	}
	void SetThiefData( int Index, const ActivityNpcDataWraper& v )
	{
		if(Index<0 || Index>=(int)m_ThiefData.size())
		{
			assert(false);
			return;
		}
		m_ThiefData[Index] = v;
	}
	void AddThiefData( const ActivityNpcDataWraper& v )
	{
		m_ThiefData.push_back(v);
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ActivityScheduleRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_SYNCDATA_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_SYNCDATA_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcThiefBeOpenedNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_THIEFBEOPENED_NOTIFY};};
template<> struct MessageIdT<ActivityScheduleRpcThiefRefreshNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_THIEFREFRESH_NOTIFY};};
template<> struct MessageIdT<ActivityScheduleRpcThiefOpenMonsterAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_THIEFOPENMONSTER_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcThiefOpenMonsterReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_THIEFOPENMONSTER_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcSubdueMonsterEnterAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERENTER_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcSubdueMonsterEnterReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERENTER_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcSubdueMonsterBeOpenedNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERBEOPENED_NOTIFY};};
template<> struct MessageIdT<ActivityScheduleRpcSubdueMonsterRefreshNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERREFRESH_NOTIFY};};
template<> struct MessageIdT<ActivityScheduleRpcWorldBossEnterDungeonAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSENTERDUNGEON_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcWorldBossEnterDungeonReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSENTERDUNGEON_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcWorldBossSyncDataAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSSYNCDATA_REQUEST};};
template<> struct MessageIdT<ActivityScheduleRpcWorldBossSyncDataReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSSYNCDATA_REQUEST};};


#endif
