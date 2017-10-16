/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperPersistAttr.h
* Author:       甘业清
* Description:  常驻内存属性模块RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_PERSISTATTR_H
#define __RPC_WRAPER_PERSISTATTR_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "PersistAttrRpc.pb.h"



//常驻内存属性模块类的枚举定义
enum ConstPersistAttrE
{
	MODULE_ID_PERSISTATTR                        = 10,	//常驻内存属性模块模块ID
	RPC_CODE_PERSISTATTR_SYNCDATA_REQUEST        = 1051,	//常驻内存属性模块-->同步背包数据-->请求


};


//同步背包数据回应封装类
class PersistAttrRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	PersistAttrRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	PersistAttrRpcSyncDataReplyWraper(const PersistAttrRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const PersistAttrRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PersistAttrRpcSyncDataReply ToPB() const
	{
		PersistAttrRpcSyncDataReply v;
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
		PersistAttrRpcSyncDataReply pb;
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
	void Init(const PersistAttrRpcSyncDataReply& v)
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
//同步背包数据请求封装类
class PersistAttrRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	PersistAttrRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	PersistAttrRpcSyncDataAskWraper(const PersistAttrRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const PersistAttrRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PersistAttrRpcSyncDataAsk ToPB() const
	{
		PersistAttrRpcSyncDataAsk v;

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
		PersistAttrRpcSyncDataAsk pb;
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
	void Init(const PersistAttrRpcSyncDataAsk& v)
	{

	}


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<PersistAttrRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_PERSISTATTR_SYNCDATA_REQUEST};};
template<> struct MessageIdT<PersistAttrRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_PERSISTATTR_SYNCDATA_REQUEST};};


#endif
