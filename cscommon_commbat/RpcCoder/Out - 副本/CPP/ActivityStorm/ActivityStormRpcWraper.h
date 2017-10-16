/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperActivityStorm.h
* Author:       甘业清
* Description:  活动 风暴RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ACTIVITYSTORM_H
#define __RPC_WRAPER_ACTIVITYSTORM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ActivityStormRpc.pb.h"



//活动 风暴类的枚举定义
enum ConstActivityStormE
{
	MODULE_ID_ACTIVITYSTORM                      = 30,	//活动 风暴模块ID
	RPC_CODE_ACTIVITYSTORM_SIGNUP_REQUEST        = 3051,	//活动 风暴-->报名-->请求
	RPC_CODE_ACTIVITYSTORM_CANCELSIGNUP_REQUEST  = 3052,	//活动 风暴-->取消报名-->请求
	RPC_CODE_ACTIVITYSTORM_INSERTBATTLEFIELD_REQUEST= 3053,	//活动 风暴-->进入战场-->请求
	RPC_CODE_ACTIVITYSTORM_BATTLEFIELDMESSAGE_NOTIFY= 3054,	//活动 风暴-->战场信息-->通知
	RPC_CODE_ACTIVITYSTORM_TIMEOUTMESSAGE_NOTIFY = 3055,	//活动 风暴-->超时消息主推-->通知
	RPC_CODE_ACTIVITYSTORM_SYNCDATA_REQUEST      = 3056,	//活动 风暴-->同步数据-->请求
	RPC_CODE_ACTIVITYSTORM_JOINLEVEVNOTIFY_NOTIFY= 3057,	//活动 风暴-->加入离开notify-->通知
	RPC_CODE_ACTIVITYSTORM_CANCEINSERTBATTLE_REQUEST= 3058,	//活动 风暴-->取消进入战场-->请求
	RPC_CODE_ACTIVITYSTORM_RESETSIGNUPNOTIFY_NOTIFY= 3059,	//活动 风暴-->重置报名-->通知


};


//同步数据回应封装类
class ActivityStormRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	ActivityStormRpcSyncDataReplyWraper(const ActivityStormRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcSyncDataReply ToPB() const
	{
		ActivityStormRpcSyncDataReply v;
		v.set_result( m_Result );
		v.set_type( m_Type );
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
		ActivityStormRpcSyncDataReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(倒计时时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityStormRpcSyncDataReply& v)
	{
		m_Result = v.result();
		m_Type = v.type();
		m_Time = v.time();

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

};
//同步数据请求封装类
class ActivityStormRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityStormRpcSyncDataAskWraper(const ActivityStormRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcSyncDataAsk ToPB() const
	{
		ActivityStormRpcSyncDataAsk v;

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
		ActivityStormRpcSyncDataAsk pb;
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
	void Init(const ActivityStormRpcSyncDataAsk& v)
	{

	}


};
//加入离开notify通知封装类
class ActivityStormRpcJoinLevevNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcJoinLevevNotifyNotifyWraper()
	{
		
		m_UserID = -1;
		m_NickName = "";
		m_Type = -1;

	}
	//赋值构造函数
	ActivityStormRpcJoinLevevNotifyNotifyWraper(const ActivityStormRpcJoinLevevNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcJoinLevevNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcJoinLevevNotifyNotify ToPB() const
	{
		ActivityStormRpcJoinLevevNotifyNotify v;
		v.set_userid( m_UserID );
		v.set_nickname( m_NickName );
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
		ActivityStormRpcJoinLevevNotifyNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserID(USERID) [sint64]</li>\r\n";
		htmlBuff += "<li>NickName(昵称) [string]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UserID：%lldL</li>\r\n",m_UserID);
		htmlBuff += tmpLine;
		htmlBuff += "<li>NickName：\""+m_NickName+"\"</li>\r\n";
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityStormRpcJoinLevevNotifyNotify& v)
	{
		m_UserID = v.userid();
		m_NickName = v.nickname();
		m_Type = v.type();

	}

private:
	//USERID
	INT64 m_UserID;
public:
	void SetUserID( INT64 v)
	{
		m_UserID=v;
	}
	INT64 GetUserID()
	{
		return m_UserID;
	}
	INT64 GetUserID() const
	{
		return m_UserID;
	}
private:
	//昵称
	string m_NickName;
public:
	void SetNickName( const string& v)
	{
		m_NickName=v;
	}
	string GetNickName()
	{
		return m_NickName;
	}
	string GetNickName() const
	{
		return m_NickName;
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

};
//重置报名通知封装类
class ActivityStormRpcResetSignUpNotifyNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcResetSignUpNotifyNotifyWraper()
	{
		
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	ActivityStormRpcResetSignUpNotifyNotifyWraper(const ActivityStormRpcResetSignUpNotifyNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcResetSignUpNotifyNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcResetSignUpNotifyNotify ToPB() const
	{
		ActivityStormRpcResetSignUpNotifyNotify v;
		v.set_type( m_Type );
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
		ActivityStormRpcResetSignUpNotifyNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(倒计时时间) [sint32]</li>\r\n";

		
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

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityStormRpcResetSignUpNotifyNotify& v)
	{
		m_Type = v.type();
		m_Time = v.time();

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

};
//取消进入战场回应封装类
class ActivityStormRpcCanceInsertBattleReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcCanceInsertBattleReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ActivityStormRpcCanceInsertBattleReplyWraper(const ActivityStormRpcCanceInsertBattleReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcCanceInsertBattleReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcCanceInsertBattleReply ToPB() const
	{
		ActivityStormRpcCanceInsertBattleReply v;
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
		ActivityStormRpcCanceInsertBattleReply pb;
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
	void Init(const ActivityStormRpcCanceInsertBattleReply& v)
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
//取消进入战场请求封装类
class ActivityStormRpcCanceInsertBattleAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcCanceInsertBattleAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityStormRpcCanceInsertBattleAskWraper(const ActivityStormRpcCanceInsertBattleAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcCanceInsertBattleAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcCanceInsertBattleAsk ToPB() const
	{
		ActivityStormRpcCanceInsertBattleAsk v;

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
		ActivityStormRpcCanceInsertBattleAsk pb;
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
	void Init(const ActivityStormRpcCanceInsertBattleAsk& v)
	{

	}


};
//超时消息主推通知封装类
class ActivityStormRpcTimeOutMessageNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcTimeOutMessageNotifyWraper()
	{
		

	}
	//赋值构造函数
	ActivityStormRpcTimeOutMessageNotifyWraper(const ActivityStormRpcTimeOutMessageNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcTimeOutMessageNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcTimeOutMessageNotify ToPB() const
	{
		ActivityStormRpcTimeOutMessageNotify v;

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
		ActivityStormRpcTimeOutMessageNotify pb;
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
	void Init(const ActivityStormRpcTimeOutMessageNotify& v)
	{

	}


};
//取消报名请求封装类
class ActivityStormRpcCancelSignUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcCancelSignUpAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityStormRpcCancelSignUpAskWraper(const ActivityStormRpcCancelSignUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcCancelSignUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcCancelSignUpAsk ToPB() const
	{
		ActivityStormRpcCancelSignUpAsk v;

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
		ActivityStormRpcCancelSignUpAsk pb;
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
	void Init(const ActivityStormRpcCancelSignUpAsk& v)
	{

	}


};
//报名回应封装类
class ActivityStormRpcSignUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcSignUpReplyWraper()
	{
		
		m_Result = -9999;
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	ActivityStormRpcSignUpReplyWraper(const ActivityStormRpcSignUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcSignUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcSignUpReply ToPB() const
	{
		ActivityStormRpcSignUpReply v;
		v.set_result( m_Result );
		v.set_type( m_Type );
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
		ActivityStormRpcSignUpReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(倒计时时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityStormRpcSignUpReply& v)
	{
		m_Result = v.result();
		m_Type = v.type();
		m_Time = v.time();

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

};
//报名请求封装类
class ActivityStormRpcSignUpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcSignUpAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityStormRpcSignUpAskWraper(const ActivityStormRpcSignUpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcSignUpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcSignUpAsk ToPB() const
	{
		ActivityStormRpcSignUpAsk v;

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
		ActivityStormRpcSignUpAsk pb;
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
	void Init(const ActivityStormRpcSignUpAsk& v)
	{

	}


};
//取消报名回应封装类
class ActivityStormRpcCancelSignUpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcCancelSignUpReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ActivityStormRpcCancelSignUpReplyWraper(const ActivityStormRpcCancelSignUpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcCancelSignUpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcCancelSignUpReply ToPB() const
	{
		ActivityStormRpcCancelSignUpReply v;
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
		ActivityStormRpcCancelSignUpReply pb;
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
	void Init(const ActivityStormRpcCancelSignUpReply& v)
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
//战场信息通知封装类
class ActivityStormRpcBattlefieldMessageNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcBattlefieldMessageNotifyWraper()
	{
		
		m_Time = -1;

	}
	//赋值构造函数
	ActivityStormRpcBattlefieldMessageNotifyWraper(const ActivityStormRpcBattlefieldMessageNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcBattlefieldMessageNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcBattlefieldMessageNotify ToPB() const
	{
		ActivityStormRpcBattlefieldMessageNotify v;
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
		ActivityStormRpcBattlefieldMessageNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Time(倒计时时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityStormRpcBattlefieldMessageNotify& v)
	{
		m_Time = v.time();

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

};
//进入战场回应封装类
class ActivityStormRpcInsertBattlefieldReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcInsertBattlefieldReplyWraper()
	{
		
		m_Result = -9999;
		m_Type = -1;
		m_Time = -1;

	}
	//赋值构造函数
	ActivityStormRpcInsertBattlefieldReplyWraper(const ActivityStormRpcInsertBattlefieldReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcInsertBattlefieldReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcInsertBattlefieldReply ToPB() const
	{
		ActivityStormRpcInsertBattlefieldReply v;
		v.set_result( m_Result );
		v.set_type( m_Type );
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
		ActivityStormRpcInsertBattlefieldReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";
		htmlBuff += "<li>Time(倒计时时间) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Time：%di</li>\r\n",m_Time);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ActivityStormRpcInsertBattlefieldReply& v)
	{
		m_Result = v.result();
		m_Type = v.type();
		m_Time = v.time();

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

};
//进入战场请求封装类
class ActivityStormRpcInsertBattlefieldAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ActivityStormRpcInsertBattlefieldAskWraper()
	{
		

	}
	//赋值构造函数
	ActivityStormRpcInsertBattlefieldAskWraper(const ActivityStormRpcInsertBattlefieldAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ActivityStormRpcInsertBattlefieldAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ActivityStormRpcInsertBattlefieldAsk ToPB() const
	{
		ActivityStormRpcInsertBattlefieldAsk v;

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
		ActivityStormRpcInsertBattlefieldAsk pb;
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
	void Init(const ActivityStormRpcInsertBattlefieldAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ActivityStormRpcSignUpAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_SIGNUP_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcSignUpReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_SIGNUP_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcCancelSignUpAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_CANCELSIGNUP_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcCancelSignUpReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_CANCELSIGNUP_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcInsertBattlefieldAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_INSERTBATTLEFIELD_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcInsertBattlefieldReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_INSERTBATTLEFIELD_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcBattlefieldMessageNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_BATTLEFIELDMESSAGE_NOTIFY};};
template<> struct MessageIdT<ActivityStormRpcTimeOutMessageNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_TIMEOUTMESSAGE_NOTIFY};};
template<> struct MessageIdT<ActivityStormRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_SYNCDATA_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_SYNCDATA_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcJoinLevevNotifyNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_JOINLEVEVNOTIFY_NOTIFY};};
template<> struct MessageIdT<ActivityStormRpcCanceInsertBattleAskWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_CANCEINSERTBATTLE_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcCanceInsertBattleReplyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_CANCEINSERTBATTLE_REQUEST};};
template<> struct MessageIdT<ActivityStormRpcResetSignUpNotifyNotifyWraper>{ enum{ID=RPC_CODE_ACTIVITYSTORM_RESETSIGNUPNOTIFY_NOTIFY};};


#endif
