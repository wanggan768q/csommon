/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RpcWraperDropItem.h
* Author:       甘业清
* Description:  掉落物RPC通信参数的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __RPC_WRAPER_DROPITEM_H
#define __RPC_WRAPER_DROPITEM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DataWraperInterface.h"
#include "DropItemRpc.pb.h"



//掉落物类的枚举定义
enum ConstDropItemE
{
	MODULE_ID_DROPITEM                           = 35,	//掉落物模块ID
	RPC_CODE_DROPITEM_DROPITEMNOTICE_NOTIFY      = 3551,	//掉落物-->物品掉落通知-->通知
	RPC_CODE_DROPITEM_PICKUPITEM_REQUEST         = 3552,	//掉落物-->捡物品-->请求
	RPC_CODE_DROPITEM_DELDROPITEM_NOTIFY         = 3553,	//掉落物-->删除掉落-->通知


};


//捡物品回应封装类
class DropItemRpcPickupItemReplyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DropItemRpcPickupItemReplyWraper()
	{
		
		m_Result = -9999;

	}
	//赋值构造函数
	DropItemRpcPickupItemReplyWraper(const DropItemRpcPickupItemReply& v){ Init(v); }
	//等号重载函数
	void operator = (const DropItemRpcPickupItemReply& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DropItemRpcPickupItemReply ToPB() const
	{
		DropItemRpcPickupItemReply v;
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
		DropItemRpcPickupItemReply pb;
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
	void Init(const DropItemRpcPickupItemReply& v)
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
//删除掉落通知封装类
class DropItemRpcDelDropItemNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DropItemRpcDelDropItemNotifyWraper()
	{
		
		m_UId = -1;

	}
	//赋值构造函数
	DropItemRpcDelDropItemNotifyWraper(const DropItemRpcDelDropItemNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DropItemRpcDelDropItemNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DropItemRpcDelDropItemNotify ToPB() const
	{
		DropItemRpcDelDropItemNotify v;
		v.set_uid( m_UId );

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
		DropItemRpcDelDropItemNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UId(下标) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UId：%di</li>\r\n",m_UId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DropItemRpcDelDropItemNotify& v)
	{
		m_UId = v.uid();

	}

private:
	//下标
	INT32 m_UId;
public:
	void SetUId( INT32 v)
	{
		m_UId=v;
	}
	INT32 GetUId()
	{
		return m_UId;
	}
	INT32 GetUId() const
	{
		return m_UId;
	}

};
//捡物品请求封装类
class DropItemRpcPickupItemAskWraper : public DataWraperInterface 
{
public:
	//构造函数
	DropItemRpcPickupItemAskWraper()
	{
		
		m_UId = -1;

	}
	//赋值构造函数
	DropItemRpcPickupItemAskWraper(const DropItemRpcPickupItemAsk& v){ Init(v); }
	//等号重载函数
	void operator = (const DropItemRpcPickupItemAsk& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DropItemRpcPickupItemAsk ToPB() const
	{
		DropItemRpcPickupItemAsk v;
		v.set_uid( m_UId );

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
		DropItemRpcPickupItemAsk pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UId(下标) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>UId：%di</li>\r\n",m_UId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DropItemRpcPickupItemAsk& v)
	{
		m_UId = v.uid();

	}

private:
	//下标
	INT32 m_UId;
public:
	void SetUId( INT32 v)
	{
		m_UId=v;
	}
	INT32 GetUId()
	{
		return m_UId;
	}
	INT32 GetUId() const
	{
		return m_UId;
	}

};
//物品掉落通知通知封装类
class DropItemRpcDropItemNoticeNotifyWraper : public DataWraperInterface 
{
public:
	//构造函数
	DropItemRpcDropItemNoticeNotifyWraper()
	{
		

	}
	//赋值构造函数
	DropItemRpcDropItemNoticeNotifyWraper(const DropItemRpcDropItemNoticeNotify& v){ Init(v); }
	//等号重载函数
	void operator = (const DropItemRpcDropItemNoticeNotify& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DropItemRpcDropItemNoticeNotify ToPB() const
	{
		DropItemRpcDropItemNoticeNotify v;
		v.mutable_dropitem()->Reserve(m_DropItem.size());
		for (int i=0; i<(int)m_DropItem.size(); i++)
		{
			*v.add_dropitem() = m_DropItem[i].ToPB();
		}

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
		DropItemRpcDropItemNoticeNotify pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DropItem(掉落的物品) [DropItemObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>DropItem：</li>\r\n";
		if( m_DropItem.size()>0) htmlBuff += m_DropItem[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_DropItem.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_DropItem[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DropItemRpcDropItemNoticeNotify& v)
	{
		m_DropItem.clear();
		m_DropItem.reserve(v.dropitem_size());
		for( int i=0; i<v.dropitem_size(); i++)
			m_DropItem.push_back(v.dropitem(i));

	}

private:
	//掉落的物品
	vector<DropItemObjWraper> m_DropItem;
public:
	int SizeDropItem()
	{
		return m_DropItem.size();
	}
	const vector<DropItemObjWraper>& GetDropItem() const
	{
		return m_DropItem;
	}
	DropItemObjWraper GetDropItem(int Index) const
	{
		if(Index<0 || Index>=(int)m_DropItem.size())
		{
			assert(false);
			return DropItemObjWraper();
		}
		return m_DropItem[Index];
	}
	void SetDropItem( const vector<DropItemObjWraper>& v )
	{
		m_DropItem=v;
	}
	void ClearDropItem( )
	{
		m_DropItem.clear();
	}
	void SetDropItem( int Index, const DropItemObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_DropItem.size())
		{
			assert(false);
			return;
		}
		m_DropItem[Index] = v;
	}
	void AddDropItem( const DropItemObjWraper& v )
	{
		m_DropItem.push_back(v);
	}

};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<DropItemRpcDropItemNoticeNotifyWraper>{ enum{ID=RPC_CODE_DROPITEM_DROPITEMNOTICE_NOTIFY};};
template<> struct MessageIdT<DropItemRpcPickupItemAskWraper>{ enum{ID=RPC_CODE_DROPITEM_PICKUPITEM_REQUEST};};
template<> struct MessageIdT<DropItemRpcPickupItemReplyWraper>{ enum{ID=RPC_CODE_DROPITEM_PICKUPITEM_REQUEST};};
template<> struct MessageIdT<DropItemRpcDelDropItemNotifyWraper>{ enum{ID=RPC_CODE_DROPITEM_DELDROPITEM_NOTIFY};};


#endif
