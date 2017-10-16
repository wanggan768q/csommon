/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperStoryDungeon.h
* Author:       甘业清
* Description:  剧情副本RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_STORYDUNGEON_H
#define __RPC_WRAPER_STORYDUNGEON_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "StoryDungeonRpc.pb.h"



//剧情副本类的枚举定义
enum ConstStoryDungeonE
{
	MODULE_ID_STORYDUNGEON                       = 43,	//剧情副本模块ID
	RPC_CODE_STORYDUNGEON_SYNCDATA_REQUEST       = 4351,	//剧情副本-->SyncData-->请求
	RPC_CODE_STORYDUNGEON_CHALLENGE_REQUEST      = 4352,	//剧情副本-->挑战副本-->请求
	RPC_CODE_STORYDUNGEON_WAITFORCONFIRMATION_NOTIFY= 4353,	//剧情副本-->等待玩家确认是否选择进入-->通知
	RPC_CODE_STORYDUNGEON_CONFIRMENTER_REQUEST   = 4354,	//剧情副本-->确认是否进入-->请求
	RPC_CODE_STORYDUNGEON_PLAYERCONFIRMRESULT_NOTIFY= 4355,	//剧情副本-->玩家确认或拒绝进入-->通知


};


//确认是否进入请求封装类
class StoryDungeonRpcConfirmEnterAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonRpcConfirmEnterAskWraper()
	{
		
		m_IsAgree = false;

	}
	//赋值构造函数
	StoryDungeonRpcConfirmEnterAskWraper(const StoryDungeonRpcConfirmEnterAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonRpcConfirmEnterAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonRpcConfirmEnterAsk ToPB() const
	{
		StoryDungeonRpcConfirmEnterAsk v;
		v.set_isagree( m_IsAgree );

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
		StoryDungeonRpcConfirmEnterAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>IsAgree(同意进入) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>IsAgree：%di</li>\r\n",m_IsAgree);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const StoryDungeonRpcConfirmEnterAsk& v)
	{
		m_IsAgree = v.isagree();

	}

private:
	//同意进入
	bool m_IsAgree;
public:
	void SetIsAgree( bool v)
	{
		m_IsAgree=v;
	}
	bool GetIsAgree()
	{
		return m_IsAgree;
	}
	bool GetIsAgree() const
	{
		return m_IsAgree;
	}

};
//等待玩家确认是否选择进入通知封装类
class StoryDungeonRpcWaitForConfirmationNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonRpcWaitForConfirmationNotifyWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	StoryDungeonRpcWaitForConfirmationNotifyWraper(const StoryDungeonRpcWaitForConfirmationNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonRpcWaitForConfirmationNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonRpcWaitForConfirmationNotify ToPB() const
	{
		StoryDungeonRpcWaitForConfirmationNotify v;
		v.set_id( m_Id );

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
		StoryDungeonRpcWaitForConfirmationNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const StoryDungeonRpcWaitForConfirmationNotify& v)
	{
		m_Id = v.id();

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

};
//确认是否进入回应封装类
class StoryDungeonRpcConfirmEnterReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonRpcConfirmEnterReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	StoryDungeonRpcConfirmEnterReplyWraper(const StoryDungeonRpcConfirmEnterReply& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonRpcConfirmEnterReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonRpcConfirmEnterReply ToPB() const
	{
		StoryDungeonRpcConfirmEnterReply v;
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
		StoryDungeonRpcConfirmEnterReply pb;
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
	void Init(const StoryDungeonRpcConfirmEnterReply& v)
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
//玩家确认或拒绝进入通知封装类
class StoryDungeonRpcPlayerConfirmResultNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonRpcPlayerConfirmResultNotifyWraper()
	{
		
		m_UserId = -1;
		m_UserName = "";
		m_IsAgree = false;

	}
	//赋值构造函数
	StoryDungeonRpcPlayerConfirmResultNotifyWraper(const StoryDungeonRpcPlayerConfirmResultNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonRpcPlayerConfirmResultNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonRpcPlayerConfirmResultNotify ToPB() const
	{
		StoryDungeonRpcPlayerConfirmResultNotify v;
		v.set_userid( m_UserId );
		v.set_username( m_UserName );
		v.set_isagree( m_IsAgree );

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
		StoryDungeonRpcPlayerConfirmResultNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>UserName(玩家名字) [string]</li>\r\n";
		htmlBuff += "<li>IsAgree(同意进入) [bool]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>IsAgree：%di</li>\r\n",m_IsAgree);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const StoryDungeonRpcPlayerConfirmResultNotify& v)
	{
		m_UserId = v.userid();
		m_UserName = v.username();
		m_IsAgree = v.isagree();

	}

private:
	//用户ID
	INT64 m_UserId;
public:
	void SetUserId( INT64 v)
	{
		m_UserId=v;
	}
	INT64 GetUserId()
	{
		return m_UserId;
	}
	INT64 GetUserId() const
	{
		return m_UserId;
	}
private:
	//玩家名字
	string m_UserName;
public:
	void SetUserName( const string& v)
	{
		m_UserName=v;
	}
	string GetUserName()
	{
		return m_UserName;
	}
	string GetUserName() const
	{
		return m_UserName;
	}
private:
	//同意进入
	bool m_IsAgree;
public:
	void SetIsAgree( bool v)
	{
		m_IsAgree=v;
	}
	bool GetIsAgree()
	{
		return m_IsAgree;
	}
	bool GetIsAgree() const
	{
		return m_IsAgree;
	}

};
//SyncData请求封装类
class StoryDungeonRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	StoryDungeonRpcSyncDataAskWraper(const StoryDungeonRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonRpcSyncDataAsk ToPB() const
	{
		StoryDungeonRpcSyncDataAsk v;

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
		StoryDungeonRpcSyncDataAsk pb;
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
	void Init(const StoryDungeonRpcSyncDataAsk& v)
	{

	}


};
//SyncData回应封装类
class StoryDungeonRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	StoryDungeonRpcSyncDataReplyWraper(const StoryDungeonRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonRpcSyncDataReply ToPB() const
	{
		StoryDungeonRpcSyncDataReply v;
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
		StoryDungeonRpcSyncDataReply pb;
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
	void Init(const StoryDungeonRpcSyncDataReply& v)
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
//挑战副本回应封装类
class StoryDungeonRpcChallengeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonRpcChallengeReplyWraper()
	{
		
		m_Result = -9999;
		m_ErrorUserName = "";

	}
	//赋值构造函数
	StoryDungeonRpcChallengeReplyWraper(const StoryDungeonRpcChallengeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonRpcChallengeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonRpcChallengeReply ToPB() const
	{
		StoryDungeonRpcChallengeReply v;
		v.set_result( m_Result );
		v.set_errorusername( m_ErrorUserName );

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
		StoryDungeonRpcChallengeReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ErrorUserName(玩家名字) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ErrorUserName：\""+m_ErrorUserName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const StoryDungeonRpcChallengeReply& v)
	{
		m_Result = v.result();
		m_ErrorUserName = v.errorusername();

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
	//玩家名字
	string m_ErrorUserName;
public:
	void SetErrorUserName( const string& v)
	{
		m_ErrorUserName=v;
	}
	string GetErrorUserName()
	{
		return m_ErrorUserName;
	}
	string GetErrorUserName() const
	{
		return m_ErrorUserName;
	}

};
//挑战副本请求封装类
class StoryDungeonRpcChallengeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	StoryDungeonRpcChallengeAskWraper()
	{
		
		m_Id = -1;

	}
	//赋值构造函数
	StoryDungeonRpcChallengeAskWraper(const StoryDungeonRpcChallengeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const StoryDungeonRpcChallengeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	StoryDungeonRpcChallengeAsk ToPB() const
	{
		StoryDungeonRpcChallengeAsk v;
		v.set_id( m_Id );

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
		StoryDungeonRpcChallengeAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Id(Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Id：%di</li>\r\n",m_Id);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const StoryDungeonRpcChallengeAsk& v)
	{
		m_Id = v.id();

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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<StoryDungeonRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_STORYDUNGEON_SYNCDATA_REQUEST};};
template<> struct MessageIdT<StoryDungeonRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_STORYDUNGEON_SYNCDATA_REQUEST};};
template<> struct MessageIdT<StoryDungeonRpcChallengeAskWraper>{ enum{ID=RPC_CODE_STORYDUNGEON_CHALLENGE_REQUEST};};
template<> struct MessageIdT<StoryDungeonRpcChallengeReplyWraper>{ enum{ID=RPC_CODE_STORYDUNGEON_CHALLENGE_REQUEST};};
template<> struct MessageIdT<StoryDungeonRpcWaitForConfirmationNotifyWraper>{ enum{ID=RPC_CODE_STORYDUNGEON_WAITFORCONFIRMATION_NOTIFY};};
template<> struct MessageIdT<StoryDungeonRpcConfirmEnterAskWraper>{ enum{ID=RPC_CODE_STORYDUNGEON_CONFIRMENTER_REQUEST};};
template<> struct MessageIdT<StoryDungeonRpcConfirmEnterReplyWraper>{ enum{ID=RPC_CODE_STORYDUNGEON_CONFIRMENTER_REQUEST};};
template<> struct MessageIdT<StoryDungeonRpcPlayerConfirmResultNotifyWraper>{ enum{ID=RPC_CODE_STORYDUNGEON_PLAYERCONFIRMRESULT_NOTIFY};};


#endif
