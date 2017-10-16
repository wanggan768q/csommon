/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperZhanDou.h
* Author:       甘业清
* Description:  战斗RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_ZHANDOU_H
#define __RPC_WRAPER_ZHANDOU_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ZhanDouRpc.pb.h"



//战斗类的枚举定义
enum ConstZhanDouE
{
	MODULE_ID_ZHANDOU                            = 1,	//战斗模块ID
	RPC_CODE_ZHANDOU_MOVE_REQUEST                = 151,	//战斗-->zou-->请求
	RPC_CODE_ZHANDOU_TALK_NOTIFY                 = 152,	//战斗-->聊天-->通知


};


//聊天通知封装类
class ZhanDouRpcTalkNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ZhanDouRpcTalkNotifyWraper()
	{
		

	}
	//赋值构造函数
	ZhanDouRpcTalkNotifyWraper(const ZhanDouRpcTalkNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const ZhanDouRpcTalkNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ZhanDouRpcTalkNotify ToPB() const
	{
		ZhanDouRpcTalkNotify v;

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
		ZhanDouRpcTalkNotify pb;
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
	void Init(const ZhanDouRpcTalkNotify& v)
	{

	}


};
//zou回应封装类
class ZhanDouRpcMoveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ZhanDouRpcMoveReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ZhanDouRpcMoveReplyWraper(const ZhanDouRpcMoveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ZhanDouRpcMoveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ZhanDouRpcMoveReply ToPB() const
	{
		ZhanDouRpcMoveReply v;
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
		ZhanDouRpcMoveReply pb;
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
	void Init(const ZhanDouRpcMoveReply& v)
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
//zou请求封装类
class ZhanDouRpcMoveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ZhanDouRpcMoveAskWraper()
	{
		

	}
	//赋值构造函数
	ZhanDouRpcMoveAskWraper(const ZhanDouRpcMoveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ZhanDouRpcMoveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ZhanDouRpcMoveAsk ToPB() const
	{
		ZhanDouRpcMoveAsk v;

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
		ZhanDouRpcMoveAsk pb;
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
	void Init(const ZhanDouRpcMoveAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ZhanDouRpcMoveAskWraper>{ enum{ID=RPC_CODE_ZHANDOU_MOVE_REQUEST};};
template<> struct MessageIdT<ZhanDouRpcMoveReplyWraper>{ enum{ID=RPC_CODE_ZHANDOU_MOVE_REQUEST};};
template<> struct MessageIdT<ZhanDouRpcTalkNotifyWraper>{ enum{ID=RPC_CODE_ZHANDOU_TALK_NOTIFY};};


#endif
