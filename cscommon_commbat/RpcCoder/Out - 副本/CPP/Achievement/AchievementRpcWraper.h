/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperAchievement.h
* Author:       甘业清
* Description:  成就RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ACHIEVEMENT_H
#define __RPC_WRAPER_ACHIEVEMENT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "AchievementRpc.pb.h"



//成就类的枚举定义
enum ConstAchievementE
{
	MODULE_ID_ACHIEVEMENT                        = 2,	//成就模块ID
	RPC_CODE_ACHIEVEMENT_GETTHEREWARDS_REQUEST   = 251,	//成就-->领取奖励-->请求
	RPC_CODE_ACHIEVEMENT_SYNCDATA_REQUEST        = 252,	//成就-->同步数据-->请求


};


//同步数据请求封装类
class AchievementRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AchievementRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	AchievementRpcSyncDataAskWraper(const AchievementRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AchievementRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AchievementRpcSyncDataAsk ToPB() const
	{
		AchievementRpcSyncDataAsk v;

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
		AchievementRpcSyncDataAsk pb;
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
	void Init(const AchievementRpcSyncDataAsk& v)
	{

	}


};
//同步数据回应封装类
class AchievementRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AchievementRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	AchievementRpcSyncDataReplyWraper(const AchievementRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AchievementRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AchievementRpcSyncDataReply ToPB() const
	{
		AchievementRpcSyncDataReply v;
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
		AchievementRpcSyncDataReply pb;
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
	void Init(const AchievementRpcSyncDataReply& v)
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
//领取奖励请求封装类
class AchievementRpcGetTheRewardsAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	AchievementRpcGetTheRewardsAskWraper()
	{
		
		m_GroupId = -1;

	}
	//赋值构造函数
	AchievementRpcGetTheRewardsAskWraper(const AchievementRpcGetTheRewardsAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const AchievementRpcGetTheRewardsAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AchievementRpcGetTheRewardsAsk ToPB() const
	{
		AchievementRpcGetTheRewardsAsk v;
		v.set_groupid( m_GroupId );

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
		AchievementRpcGetTheRewardsAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>GroupId(组id，使用解锁条件) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>GroupId：%di</li>\r\n",m_GroupId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const AchievementRpcGetTheRewardsAsk& v)
	{
		m_GroupId = v.groupid();

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

};
//领取奖励回应封装类
class AchievementRpcGetTheRewardsReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	AchievementRpcGetTheRewardsReplyWraper()
	{
		
		m_Result = -9999;
		m_GroupId = -1;

	}
	//赋值构造函数
	AchievementRpcGetTheRewardsReplyWraper(const AchievementRpcGetTheRewardsReply& v){ Init(v); }
	//等号重载函数
	void operator = (const AchievementRpcGetTheRewardsReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	AchievementRpcGetTheRewardsReply ToPB() const
	{
		AchievementRpcGetTheRewardsReply v;
		v.set_result( m_Result );
		v.set_groupid( m_GroupId );

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
		AchievementRpcGetTheRewardsReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>GroupId(组id，使用解锁条件) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>GroupId：%di</li>\r\n",m_GroupId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const AchievementRpcGetTheRewardsReply& v)
	{
		m_Result = v.result();
		m_GroupId = v.groupid();

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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<AchievementRpcGetTheRewardsAskWraper>{ enum{ID=RPC_CODE_ACHIEVEMENT_GETTHEREWARDS_REQUEST};};
template<> struct MessageIdT<AchievementRpcGetTheRewardsReplyWraper>{ enum{ID=RPC_CODE_ACHIEVEMENT_GETTHEREWARDS_REQUEST};};
template<> struct MessageIdT<AchievementRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_ACHIEVEMENT_SYNCDATA_REQUEST};};
template<> struct MessageIdT<AchievementRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_ACHIEVEMENT_SYNCDATA_REQUEST};};


#endif
