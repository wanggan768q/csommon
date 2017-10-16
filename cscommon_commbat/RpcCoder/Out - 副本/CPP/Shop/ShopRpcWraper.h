/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperShop.h
* Author:       甘业清
* Description:  商城RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_SHOP_H
#define __RPC_WRAPER_SHOP_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "ShopRpc.pb.h"



//商城类的枚举定义
enum ConstShopE
{
	MODULE_ID_SHOP                               = 22,	//商城模块ID
	RPC_CODE_SHOP_SYNCDATA_REQUEST               = 2251,	//商城-->数据同步-->请求
	RPC_CODE_SHOP_BUY_REQUEST                    = 2252,	//商城-->购买-->请求
	RPC_CODE_SHOP_REFRESHITEM_REQUEST            = 2253,	//商城-->刷新道具-->请求


};


//刷新道具回应封装类
class ShopRpcRefreshItemReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcRefreshItemReplyWraper()
	{
		
		m_Result = -9999;
		m_ShopType = -1;

	}
	//赋值构造函数
	ShopRpcRefreshItemReplyWraper(const ShopRpcRefreshItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcRefreshItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcRefreshItemReply ToPB() const
	{
		ShopRpcRefreshItemReply v;
		v.set_result( m_Result );
		v.set_shoptype( m_ShopType );

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
		ShopRpcRefreshItemReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ShopType(商店类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ShopType：%di</li>\r\n",m_ShopType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ShopRpcRefreshItemReply& v)
	{
		m_Result = v.result();
		m_ShopType = v.shoptype();

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
	//商店类型
	INT32 m_ShopType;
public:
	void SetShopType( INT32 v)
	{
		m_ShopType=v;
	}
	INT32 GetShopType()
	{
		return m_ShopType;
	}
	INT32 GetShopType() const
	{
		return m_ShopType;
	}

};
//数据同步请求封装类
class ShopRpcSyncDataAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcSyncDataAskWraper()
	{
		

	}
	//赋值构造函数
	ShopRpcSyncDataAskWraper(const ShopRpcSyncDataAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcSyncDataAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcSyncDataAsk ToPB() const
	{
		ShopRpcSyncDataAsk v;

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
		ShopRpcSyncDataAsk pb;
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
	void Init(const ShopRpcSyncDataAsk& v)
	{

	}


};
//购买请求封装类
class ShopRpcBuyAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcBuyAskWraper()
	{
		
		m_ShopType = -1;
		m_ItemId = -1;
		m_Pos = -1;

	}
	//赋值构造函数
	ShopRpcBuyAskWraper(const ShopRpcBuyAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcBuyAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcBuyAsk ToPB() const
	{
		ShopRpcBuyAsk v;
		v.set_shoptype( m_ShopType );
		v.set_itemid( m_ItemId );
		v.set_pos( m_Pos );

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
		ShopRpcBuyAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ShopType(商店类型) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemId(道具id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ShopType：%di</li>\r\n",m_ShopType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ShopRpcBuyAsk& v)
	{
		m_ShopType = v.shoptype();
		m_ItemId = v.itemid();
		m_Pos = v.pos();

	}

private:
	//商店类型
	INT32 m_ShopType;
public:
	void SetShopType( INT32 v)
	{
		m_ShopType=v;
	}
	INT32 GetShopType()
	{
		return m_ShopType;
	}
	INT32 GetShopType() const
	{
		return m_ShopType;
	}
private:
	//道具id
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}

};
//数据同步回应封装类
class ShopRpcSyncDataReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcSyncDataReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	ShopRpcSyncDataReplyWraper(const ShopRpcSyncDataReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcSyncDataReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcSyncDataReply ToPB() const
	{
		ShopRpcSyncDataReply v;
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
		ShopRpcSyncDataReply pb;
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
	void Init(const ShopRpcSyncDataReply& v)
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
//刷新道具请求封装类
class ShopRpcRefreshItemAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcRefreshItemAskWraper()
	{
		
		m_ShopType = -1;

	}
	//赋值构造函数
	ShopRpcRefreshItemAskWraper(const ShopRpcRefreshItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcRefreshItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcRefreshItemAsk ToPB() const
	{
		ShopRpcRefreshItemAsk v;
		v.set_shoptype( m_ShopType );

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
		ShopRpcRefreshItemAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ShopType(商店类型) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ShopType：%di</li>\r\n",m_ShopType);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ShopRpcRefreshItemAsk& v)
	{
		m_ShopType = v.shoptype();

	}

private:
	//商店类型
	INT32 m_ShopType;
public:
	void SetShopType( INT32 v)
	{
		m_ShopType=v;
	}
	INT32 GetShopType()
	{
		return m_ShopType;
	}
	INT32 GetShopType() const
	{
		return m_ShopType;
	}

};
//购买回应封装类
class ShopRpcBuyReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	ShopRpcBuyReplyWraper()
	{
		
		m_Result = -9999;
		m_ShopType = -1;
		m_ItemId = -1;
		m_Pos = -1;

	}
	//赋值构造函数
	ShopRpcBuyReplyWraper(const ShopRpcBuyReply& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopRpcBuyReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopRpcBuyReply ToPB() const
	{
		ShopRpcBuyReply v;
		v.set_result( m_Result );
		v.set_shoptype( m_ShopType );
		v.set_itemid( m_ItemId );
		v.set_pos( m_Pos );

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
		ShopRpcBuyReply pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>Result(返回结果) [sint32]</li>\r\n";
		htmlBuff += "<li>ShopType(商店类型) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemId(道具id) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>Result：%di</li>\r\n",m_Result);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ShopType：%di</li>\r\n",m_ShopType);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ShopRpcBuyReply& v)
	{
		m_Result = v.result();
		m_ShopType = v.shoptype();
		m_ItemId = v.itemid();
		m_Pos = v.pos();

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
	//商店类型
	INT32 m_ShopType;
public:
	void SetShopType( INT32 v)
	{
		m_ShopType=v;
	}
	INT32 GetShopType()
	{
		return m_ShopType;
	}
	INT32 GetShopType() const
	{
		return m_ShopType;
	}
private:
	//道具id
	INT32 m_ItemId;
public:
	void SetItemId( INT32 v)
	{
		m_ItemId=v;
	}
	INT32 GetItemId()
	{
		return m_ItemId;
	}
	INT32 GetItemId() const
	{
		return m_ItemId;
	}
private:
	//道具位置
	INT32 m_Pos;
public:
	void SetPos( INT32 v)
	{
		m_Pos=v;
	}
	INT32 GetPos()
	{
		return m_Pos;
	}
	INT32 GetPos() const
	{
		return m_Pos;
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<ShopRpcSyncDataAskWraper>{ enum{ID=RPC_CODE_SHOP_SYNCDATA_REQUEST};};
template<> struct MessageIdT<ShopRpcSyncDataReplyWraper>{ enum{ID=RPC_CODE_SHOP_SYNCDATA_REQUEST};};
template<> struct MessageIdT<ShopRpcBuyAskWraper>{ enum{ID=RPC_CODE_SHOP_BUY_REQUEST};};
template<> struct MessageIdT<ShopRpcBuyReplyWraper>{ enum{ID=RPC_CODE_SHOP_BUY_REQUEST};};
template<> struct MessageIdT<ShopRpcRefreshItemAskWraper>{ enum{ID=RPC_CODE_SHOP_REFRESHITEM_REQUEST};};
template<> struct MessageIdT<ShopRpcRefreshItemReplyWraper>{ enum{ID=RPC_CODE_SHOP_REFRESHITEM_REQUEST};};


#endif
