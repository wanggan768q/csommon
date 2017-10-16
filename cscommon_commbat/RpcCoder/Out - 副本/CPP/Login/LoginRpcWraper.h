/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperLogin.h
* Author:       甘业清
* Description:  登录模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_LOGIN_H
#define __RPC_WRAPER_LOGIN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "LoginRpc.pb.h"



//登录模块类的枚举定义
enum ConstLoginE
{
	MODULE_ID_LOGIN                              = 5,	//登录模块模块ID
	RPC_CODE_LOGIN_KEYAUTH_REQUEST               = 551,	//登录模块-->密钥认证-->请求
	RPC_CODE_LOGIN_KICKOFF_NOTIFY                = 552,	//登录模块-->被踢下线-->通知


};


//被踢下线通知封装类
class LoginRpcKickOffNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcKickOffNotifyWraper()
	{
		

	}
	//赋值构造函数
	LoginRpcKickOffNotifyWraper(const LoginRpcKickOffNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcKickOffNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcKickOffNotify ToPB() const
	{
		LoginRpcKickOffNotify v;

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
		LoginRpcKickOffNotify pb;
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
	void Init(const LoginRpcKickOffNotify& v)
	{

	}


};
//密钥认证回应封装类
class LoginRpcKeyAuthReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcKeyAuthReplyWraper()
	{
		
		m_Result = -9999;
		m_UserId = -1;
		m_PlatName = "";

	}
	//赋值构造函数
	LoginRpcKeyAuthReplyWraper(const LoginRpcKeyAuthReply& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcKeyAuthReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcKeyAuthReply ToPB() const
	{
		LoginRpcKeyAuthReply v;
		v.set_result( m_Result );
		v.set_userid( m_UserId );
		v.set_platname( m_PlatName );

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
		LoginRpcKeyAuthReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>PlatName(平台账号名) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PlatName：\""+m_PlatName+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcKeyAuthReply& v)
	{
		m_Result = v.result();
		m_UserId = v.userid();
		m_PlatName = v.platname();

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
	//平台账号名
	string m_PlatName;
public:
	void SetPlatName( const string& v)
	{
		m_PlatName=v;
	}
	string GetPlatName()
	{
		return m_PlatName;
	}
	string GetPlatName() const
	{
		return m_PlatName;
	}

};
//密钥认证请求封装类
class LoginRpcKeyAuthAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	LoginRpcKeyAuthAskWraper()
	{
		
		m_DistId = -1;
		m_RsaData = "";

	}
	//赋值构造函数
	LoginRpcKeyAuthAskWraper(const LoginRpcKeyAuthAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const LoginRpcKeyAuthAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	LoginRpcKeyAuthAsk ToPB() const
	{
		LoginRpcKeyAuthAsk v;
		v.set_distid( m_DistId );
		v.set_rsadata( m_RsaData );

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
		LoginRpcKeyAuthAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DistId(区ID) [sint32]</li>\r\n";
		htmlBuff += "<li>RsaData(加密数据) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>DistId：%di</li>\r\n",m_DistId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>RsaData：\""+m_RsaData+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const LoginRpcKeyAuthAsk& v)
	{
		m_DistId = v.distid();
		m_RsaData = v.rsadata();

	}

private:
	//区ID
	INT32 m_DistId;
public:
	void SetDistId( INT32 v)
	{
		m_DistId=v;
	}
	INT32 GetDistId()
	{
		return m_DistId;
	}
	INT32 GetDistId() const
	{
		return m_DistId;
	}
private:
	//加密数据
	string m_RsaData;
public:
	void SetRsaData( const string& v)
	{
		m_RsaData=v;
	}
	string GetRsaData()
	{
		return m_RsaData;
	}
	string GetRsaData() const
	{
		return m_RsaData;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<LoginRpcKeyAuthAskWraper>{ enum{ID=RPC_CODE_LOGIN_KEYAUTH_REQUEST};};
template<> struct MessageIdT<LoginRpcKeyAuthReplyWraper>{ enum{ID=RPC_CODE_LOGIN_KEYAUTH_REQUEST};};
template<> struct MessageIdT<LoginRpcKickOffNotifyWraper>{ enum{ID=RPC_CODE_LOGIN_KICKOFF_NOTIFY};};


#endif
