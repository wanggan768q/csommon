/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperGM.h
* Author:       甘业清
* Description:  GM指令RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_GM_H
#define __RPC_WRAPER_GM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "GMRpc.pb.h"



//GM指令类的枚举定义
enum ConstGME
{
	MODULE_ID_GM                                 = 17,	//GM指令模块ID
	RPC_CODE_GM_ACTION_REQUEST                   = 1751,	//GM指令-->指令动作-->请求


};


//指令动作回应封装类
class GMRpcActionReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	GMRpcActionReplyWraper()
	{
		
		m_Result = -9999;
		m_Value = "";

	}
	//赋值构造函数
	GMRpcActionReplyWraper(const GMRpcActionReply& v){ Init(v); }
	//等号重载函数
	void operator = (const GMRpcActionReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GMRpcActionReply ToPB() const
	{
		GMRpcActionReply v;
		v.set_result( m_Result );
		v.set_value( m_Value );

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
		GMRpcActionReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Value(指令内容) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		htmlBuff += "<li>Value：\""+m_Value+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GMRpcActionReply& v)
	{
		m_Result = v.result();
		m_Value = v.value();

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
	//指令内容
	string m_Value;
public:
	void SetValue( const string& v)
	{
		m_Value=v;
	}
	string GetValue()
	{
		return m_Value;
	}
	string GetValue() const
	{
		return m_Value;
	}

};
//指令动作请求封装类
class GMRpcActionAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	GMRpcActionAskWraper()
	{
		
		m_Value = "";

	}
	//赋值构造函数
	GMRpcActionAskWraper(const GMRpcActionAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const GMRpcActionAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	GMRpcActionAsk ToPB() const
	{
		GMRpcActionAsk v;
		v.set_value( m_Value );

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
		GMRpcActionAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Value(指令内容) [string]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>Value：\""+m_Value+"\"</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const GMRpcActionAsk& v)
	{
		m_Value = v.value();

	}

private:
	//指令内容
	string m_Value;
public:
	void SetValue( const string& v)
	{
		m_Value=v;
	}
	string GetValue()
	{
		return m_Value;
	}
	string GetValue() const
	{
		return m_Value;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<GMRpcActionAskWraper>{ enum{ID=RPC_CODE_GM_ACTION_REQUEST};};
template<> struct MessageIdT<GMRpcActionReplyWraper>{ enum{ID=RPC_CODE_GM_ACTION_REQUEST};};


#endif
