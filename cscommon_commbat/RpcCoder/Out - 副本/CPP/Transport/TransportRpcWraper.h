/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperTransport.h
* Author:       甘业清
* Description:  货运RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_TRANSPORT_H
#define __RPC_WRAPER_TRANSPORT_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "TransportRpc.pb.h"



//货运类的枚举定义
enum ConstTransportE
{
	MODULE_ID_TRANSPORT                          = 40,	//货运模块ID
	RPC_CODE_TRANSPORT_SYNCDATA_REQUEST          = 4051,	//货运-->数据同步-->请求
	RPC_CODE_TRANSPORT_FILL_REQUEST              = 4052,	//货运-->填充-->请求
	RPC_CODE_TRANSPORT_HELPOTHER_REQUEST         = 4053,	//货运-->帮助请求-->请求
	RPC_CODE_TRANSPORT_ASKHELP_REQUEST           = 4054,	//货运-->请求帮助-->请求
	RPC_CODE_TRANSPORT_SETSAIL_REQUEST           = 4055,	//货运-->起航请求-->请求
	RPC_CODE_TRANSPORT_ADDTRANSPORT_REQUEST      = 4056,	//货运-->添加货物-->请求
	RPC_CODE_TRANSPORT_ISHELPED_NOTIFY           = 4057,	//货运-->自己被帮助通知-->通知


};


//起航请求请求封装类
class TransportRpcSetSailAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcSetSailAskWraper()
	{
		

	}
	//赋值构造函数
	TransportRpcSetSailAskWraper(const TransportRpcSetSailAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcSetSailAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcSetSailAsk ToPB() const
	{
		TransportRpcSetSailAsk v;

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
		TransportRpcSetSailAsk pb;
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
	void Init(const TransportRpcSetSailAsk& v)
	{

	}


};
//起航请求回应封装类
class TransportRpcSetSailReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcSetSailReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TransportRpcSetSailReplyWraper(const TransportRpcSetSailReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcSetSailReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcSetSailReply ToPB() const
	{
		TransportRpcSetSailReply v;
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
		TransportRpcSetSailReply pb;
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
	void Init(const TransportRpcSetSailReply& v)
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
//添加货物回应封装类
class TransportRpcAddTransportReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcAddTransportReplyWraper()
	{
		
		m_Result = -9999;
		m_Lv = -1;

	}
	//赋值构造函数
	TransportRpcAddTransportReplyWraper(const TransportRpcAddTransportReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcAddTransportReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcAddTransportReply ToPB() const
	{
		TransportRpcAddTransportReply v;
		v.set_result( m_Result );
		v.set_lv( m_Lv );

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
		TransportRpcAddTransportReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>Lv(玩家等级) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcAddTransportReply& v)
	{
		m_Result = v.result();
		m_Lv = v.lv();

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
	//玩家等级
	INT32 m_Lv;
public:
	void SetLv( INT32 v)
	{
		m_Lv=v;
	}
	INT32 GetLv()
	{
		return m_Lv;
	}
	INT32 GetLv() const
	{
		return m_Lv;
	}

};
//自己被帮助通知通知封装类
class TransportRpcIsHelpedNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcIsHelpedNotifyWraper()
	{
		
		m_TemplateId = -1;

	}
	//赋值构造函数
	TransportRpcIsHelpedNotifyWraper(const TransportRpcIsHelpedNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcIsHelpedNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcIsHelpedNotify ToPB() const
	{
		TransportRpcIsHelpedNotify v;
		v.set_templateid( m_TemplateId );

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
		TransportRpcIsHelpedNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>TemplateId(被帮助物品ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>TemplateId：%di</li>\r\n",m_TemplateId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcIsHelpedNotify& v)
	{
		m_TemplateId = v.templateid();

	}

private:
	//被帮助物品ID
	INT32 m_TemplateId;
public:
	void SetTemplateId( INT32 v)
	{
		m_TemplateId=v;
	}
	INT32 GetTemplateId()
	{
		return m_TemplateId;
	}
	INT32 GetTemplateId() const
	{
		return m_TemplateId;
	}

};
//添加货物请求封装类
class TransportRpcAddTransportAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcAddTransportAskWraper()
	{
		
		m_Lv = -1;

	}
	//赋值构造函数
	TransportRpcAddTransportAskWraper(const TransportRpcAddTransportAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcAddTransportAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcAddTransportAsk ToPB() const
	{
		TransportRpcAddTransportAsk v;
		v.set_lv( m_Lv );

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
		TransportRpcAddTransportAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Lv(玩家等级) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Lv：%di</li>\r\n",m_Lv);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcAddTransportAsk& v)
	{
		m_Lv = v.lv();

	}

private:
	//玩家等级
	INT32 m_Lv;
public:
	void SetLv( INT32 v)
	{
		m_Lv=v;
	}
	INT32 GetLv()
	{
		return m_Lv;
	}
	INT32 GetLv() const
	{
		return m_Lv;
	}

};
//填充请求封装类
class TransportRpcFillAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcFillAskWraper()
	{
		
		m_FillID = -1;

	}
	//赋值构造函数
	TransportRpcFillAskWraper(const TransportRpcFillAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcFillAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcFillAsk ToPB() const
	{
		TransportRpcFillAsk v;
		v.set_fillid( m_FillID );

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
		TransportRpcFillAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>FillID(物品ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>FillID：%di</li>\r\n",m_FillID);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcFillAsk& v)
	{
		m_FillID = v.fillid();

	}

private:
	//物品ID
	INT32 m_FillID;
public:
	void SetFillID( INT32 v)
	{
		m_FillID=v;
	}
	INT32 GetFillID()
	{
		return m_FillID;
	}
	INT32 GetFillID() const
	{
		return m_FillID;
	}

};
//填充回应封装类
class TransportRpcFillReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcFillReplyWraper()
	{
		
		m_Result = -9999;
		m_FillID = -1;

	}
	//赋值构造函数
	TransportRpcFillReplyWraper(const TransportRpcFillReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcFillReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcFillReply ToPB() const
	{
		TransportRpcFillReply v;
		v.set_result( m_Result );
		v.set_fillid( m_FillID );

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
		TransportRpcFillReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>FillID(物品ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FillID：%di</li>\r\n",m_FillID);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcFillReply& v)
	{
		m_Result = v.result();
		m_FillID = v.fillid();

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
	//物品ID
	INT32 m_FillID;
public:
	void SetFillID( INT32 v)
	{
		m_FillID=v;
	}
	INT32 GetFillID()
	{
		return m_FillID;
	}
	INT32 GetFillID() const
	{
		return m_FillID;
	}

};
//数据同步请求封装类
class TransportRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	TransportRpcSyncDataAskWraper(const TransportRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcSyncDataAsk ToPB() const
	{
		TransportRpcSyncDataAsk v;

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
		TransportRpcSyncDataAsk pb;
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
	void Init(const TransportRpcSyncDataAsk& v)
	{

	}


};
//数据同步回应封装类
class TransportRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	TransportRpcSyncDataReplyWraper(const TransportRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcSyncDataReply ToPB() const
	{
		TransportRpcSyncDataReply v;
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
		TransportRpcSyncDataReply pb;
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
	void Init(const TransportRpcSyncDataReply& v)
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
//请求帮助请求封装类
class TransportRpcAskHelpAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcAskHelpAskWraper()
	{
		
		m_ItemID = -1;

	}
	//赋值构造函数
	TransportRpcAskHelpAskWraper(const TransportRpcAskHelpAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcAskHelpAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcAskHelpAsk ToPB() const
	{
		TransportRpcAskHelpAsk v;
		v.set_itemid( m_ItemID );

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
		TransportRpcAskHelpAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemID(物品ID) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcAskHelpAsk& v)
	{
		m_ItemID = v.itemid();

	}

private:
	//物品ID
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}

};
//请求帮助回应封装类
class TransportRpcAskHelpReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcAskHelpReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemID = -1;

	}
	//赋值构造函数
	TransportRpcAskHelpReplyWraper(const TransportRpcAskHelpReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcAskHelpReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcAskHelpReply ToPB() const
	{
		TransportRpcAskHelpReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemID );

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
		TransportRpcAskHelpReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemID(物品id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcAskHelpReply& v)
	{
		m_Result = v.result();
		m_ItemID = v.itemid();

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
	//物品id
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}

};
//帮助请求请求封装类
class TransportRpcHelpOtherAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcHelpOtherAskWraper()
	{
		
		m_ItemID = -1;
		m_UserId = -1;

	}
	//赋值构造函数
	TransportRpcHelpOtherAskWraper(const TransportRpcHelpOtherAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcHelpOtherAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcHelpOtherAsk ToPB() const
	{
		TransportRpcHelpOtherAsk v;
		v.set_itemid( m_ItemID );
		v.set_userid( m_UserId );

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
		TransportRpcHelpOtherAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemID(物品ID) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(发起请求的用户ID) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcHelpOtherAsk& v)
	{
		m_ItemID = v.itemid();
		m_UserId = v.userid();

	}

private:
	//物品ID
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//发起请求的用户ID
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

};
//帮助请求回应封装类
class TransportRpcHelpOtherReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	TransportRpcHelpOtherReplyWraper()
	{
		
		m_Result = -9999;
		m_ItemID = -1;
		m_UserId = -1;

	}
	//赋值构造函数
	TransportRpcHelpOtherReplyWraper(const TransportRpcHelpOtherReply& v){ Init(v); }
	//等号重载函数
	void operator = (const TransportRpcHelpOtherReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	TransportRpcHelpOtherReply ToPB() const
	{
		TransportRpcHelpOtherReply v;
		v.set_result( m_Result );
		v.set_itemid( m_ItemID );
		v.set_userid( m_UserId );

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
		TransportRpcHelpOtherReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemID(物品ID) [sint32]</li>\r\n";
		htmlBuff += "<li>UserId(发起请求的用户ID) [sint64]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemID：%di</li>\r\n",m_ItemID);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const TransportRpcHelpOtherReply& v)
	{
		m_Result = v.result();
		m_ItemID = v.itemid();
		m_UserId = v.userid();

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
	//物品ID
	INT32 m_ItemID;
public:
	void SetItemID( INT32 v)
	{
		m_ItemID=v;
	}
	INT32 GetItemID()
	{
		return m_ItemID;
	}
	INT32 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//发起请求的用户ID
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

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<TransportRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_TRANSPORT_SYNCDATA_REQUEST};};
template<> struct MessageIdT<TransportRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_TRANSPORT_SYNCDATA_REQUEST};};
template<> struct MessageIdT<TransportRpcFillAskWraper>{ enum{ID=RPC_CODE_TRANSPORT_FILL_REQUEST};};
template<> struct MessageIdT<TransportRpcFillReplyWraper>{ enum{ID=RPC_CODE_TRANSPORT_FILL_REQUEST};};
template<> struct MessageIdT<TransportRpcHelpOtherAskWraper>{ enum{ID=RPC_CODE_TRANSPORT_HELPOTHER_REQUEST};};
template<> struct MessageIdT<TransportRpcHelpOtherReplyWraper>{ enum{ID=RPC_CODE_TRANSPORT_HELPOTHER_REQUEST};};
template<> struct MessageIdT<TransportRpcAskHelpAskWraper>{ enum{ID=RPC_CODE_TRANSPORT_ASKHELP_REQUEST};};
template<> struct MessageIdT<TransportRpcAskHelpReplyWraper>{ enum{ID=RPC_CODE_TRANSPORT_ASKHELP_REQUEST};};
template<> struct MessageIdT<TransportRpcSetSailAskWraper>{ enum{ID=RPC_CODE_TRANSPORT_SETSAIL_REQUEST};};
template<> struct MessageIdT<TransportRpcSetSailReplyWraper>{ enum{ID=RPC_CODE_TRANSPORT_SETSAIL_REQUEST};};
template<> struct MessageIdT<TransportRpcAddTransportAskWraper>{ enum{ID=RPC_CODE_TRANSPORT_ADDTRANSPORT_REQUEST};};
template<> struct MessageIdT<TransportRpcAddTransportReplyWraper>{ enum{ID=RPC_CODE_TRANSPORT_ADDTRANSPORT_REQUEST};};
template<> struct MessageIdT<TransportRpcIsHelpedNotifyWraper>{ enum{ID=RPC_CODE_TRANSPORT_ISHELPED_NOTIFY};};


#endif
