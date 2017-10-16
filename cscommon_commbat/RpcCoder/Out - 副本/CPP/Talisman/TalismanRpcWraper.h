/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperTalisman.h
* Author:       甘业清
* Description:  法宝RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_TALISMAN_H
#define __RPC_WRAPER_TALISMAN_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "TalismanRpc.pb.h"



//法宝类的枚举定义
enum ConstTalismanE
{
	MODULE_ID_TALISMAN                           = 18,	//法宝模块ID
	RPC_CODE_TALISMAN_SYNCDATA_REQUEST           = 1851,	//法宝-->数据同步-->请求
	RPC_CODE_TALISMAN_ACTIVE_REQUEST             = 1852,	//法宝-->激活-->请求
	RPC_CODE_TALISMAN_UPGRADE_REQUEST            = 1853,	//法宝-->升级-->请求


};


//激活回应封装类
class TalismanRpcActiveReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TalismanRpcActiveReplyWraper()
	{
		
		m_Result = -9999;
		m_ID = -1;

	}
	//赋值构造函数
	TalismanRpcActiveReplyWraper(const TalismanRpcActiveReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TalismanRpcActiveReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalismanRpcActiveReply ToPB() const
	{
		TalismanRpcActiveReply v;
		v.set_result( m_Result );
		v.set_id( m_ID );

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
		TalismanRpcActiveReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ID(ID ) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ID：%di</li>\r\n",m_ID);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TalismanRpcActiveReply& v)
	{
		m_Result = v.result();
		m_ID = v.id();

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
	//ID 
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}

};
//激活请求封装类
class TalismanRpcActiveAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TalismanRpcActiveAskWraper()
	{
		
		m_ID = -1;

	}
	//赋值构造函数
	TalismanRpcActiveAskWraper(const TalismanRpcActiveAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TalismanRpcActiveAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalismanRpcActiveAsk ToPB() const
	{
		TalismanRpcActiveAsk v;
		v.set_id( m_ID );

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
		TalismanRpcActiveAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ID(ID ) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ID：%di</li>\r\n",m_ID);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TalismanRpcActiveAsk& v)
	{
		m_ID = v.id();

	}

private:
	//ID 
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}

};
//数据同步回应封装类
class TalismanRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TalismanRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TalismanRpcSyncDataReplyWraper(const TalismanRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TalismanRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalismanRpcSyncDataReply ToPB() const
	{
		TalismanRpcSyncDataReply v;
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
		TalismanRpcSyncDataReply pb;
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
	void Init(const TalismanRpcSyncDataReply& v)
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
//数据同步请求封装类
class TalismanRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TalismanRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	TalismanRpcSyncDataAskWraper(const TalismanRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TalismanRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalismanRpcSyncDataAsk ToPB() const
	{
		TalismanRpcSyncDataAsk v;

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
		TalismanRpcSyncDataAsk pb;
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
	void Init(const TalismanRpcSyncDataAsk& v)
	{

	}


};
//升级回应封装类
class TalismanRpcUpgradeReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TalismanRpcUpgradeReplyWraper()
	{
		
		m_Result = -9999;
		m_ID = -1;

	}
	//赋值构造函数
	TalismanRpcUpgradeReplyWraper(const TalismanRpcUpgradeReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TalismanRpcUpgradeReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalismanRpcUpgradeReply ToPB() const
	{
		TalismanRpcUpgradeReply v;
		v.set_result( m_Result );
		v.set_id( m_ID );

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
		TalismanRpcUpgradeReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ID(ID ) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ID：%di</li>\r\n",m_ID);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TalismanRpcUpgradeReply& v)
	{
		m_Result = v.result();
		m_ID = v.id();

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
	//ID 
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
	}

};
//升级请求封装类
class TalismanRpcUpgradeAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TalismanRpcUpgradeAskWraper()
	{
		
		m_ID = -1;
		m_Type = -1;

	}
	//赋值构造函数
	TalismanRpcUpgradeAskWraper(const TalismanRpcUpgradeAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TalismanRpcUpgradeAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TalismanRpcUpgradeAsk ToPB() const
	{
		TalismanRpcUpgradeAsk v;
		v.set_id( m_ID );
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
		TalismanRpcUpgradeAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ID(ID ) [sint32]</li>\r\n";
		htmlBuff += "<li>Type(类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ID：%di</li>\r\n",m_ID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Type：%di</li>\r\n",m_Type);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TalismanRpcUpgradeAsk& v)
	{
		m_ID = v.id();
		m_Type = v.type();

	}

private:
	//ID 
	INT32 m_ID;
public:
	void SetID( INT32 v)
	{
		m_ID=v;
	}
	INT32 GetID()
	{
		return m_ID;
	}
	INT32 GetID() const
	{
		return m_ID;
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

template<typename T> struct MessageIdT;
template<> struct MessageIdT<TalismanRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_TALISMAN_SYNCDATA_REQUEST};};
template<> struct MessageIdT<TalismanRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_TALISMAN_SYNCDATA_REQUEST};};
template<> struct MessageIdT<TalismanRpcActiveAskWraper>{ enum{ID=RPC_CODE_TALISMAN_ACTIVE_REQUEST};};
template<> struct MessageIdT<TalismanRpcActiveReplyWraper>{ enum{ID=RPC_CODE_TALISMAN_ACTIVE_REQUEST};};
template<> struct MessageIdT<TalismanRpcUpgradeAskWraper>{ enum{ID=RPC_CODE_TALISMAN_UPGRADE_REQUEST};};
template<> struct MessageIdT<TalismanRpcUpgradeReplyWraper>{ enum{ID=RPC_CODE_TALISMAN_UPGRADE_REQUEST};};


#endif
