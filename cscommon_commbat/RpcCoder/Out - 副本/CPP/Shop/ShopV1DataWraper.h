/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperShop.h
* Author:       甘业清
* Description:  商城同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_SHOP_H
#define __SYNC_WRAPER_SHOP_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "ShopV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//道具对象封装类
class ShopItemObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ShopItemObjWraperV1()
	{
		
		m_ItemId = -1;
		m_Count = -1;
		m_Pos = -1;

	}
	//赋值构造函数
	ShopItemObjWraperV1(const ShopItemObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopItemObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopItemObjV1 ToPB() const
	{
		ShopItemObjV1 v;
		v.set_itemid( m_ItemId );
		v.set_count( m_Count );
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
		ShopItemObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ItemId(道具id) [sint32]</li>\r\n";
		htmlBuff += "<li>Count(数量) [sint32]</li>\r\n";
		htmlBuff += "<li>Pos(道具位置) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ItemId：%di</li>\r\n",m_ItemId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Count：%di</li>\r\n",m_Count);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Pos：%di</li>\r\n",m_Pos);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ShopItemObjV1& v)
	{
		m_ItemId = v.itemid();
		m_Count = v.count();
		m_Pos = v.pos();

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
	//数量
	INT32 m_Count;
public:
	void SetCount( INT32 v)
	{
		m_Count=v;
	}
	INT32 GetCount()
	{
		return m_Count;
	}
	INT32 GetCount() const
	{
		return m_Count;
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
//商店对象封装类
class ShopShopObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	ShopShopObjWraperV1()
	{
		
		m_ShopType = -1;
		m_LastRefreshTime = -1;
		m_RefreshTimes = -1;

	}
	//赋值构造函数
	ShopShopObjWraperV1(const ShopShopObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopShopObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopShopObjV1 ToPB() const
	{
		ShopShopObjV1 v;
		v.set_shoptype( m_ShopType );
		v.mutable_itemarray()->Reserve(m_ItemArray.size());
		for (int i=0; i<(int)m_ItemArray.size(); i++)
		{
			*v.add_itemarray() = m_ItemArray[i].ToPB();
		}
		v.set_lastrefreshtime( m_LastRefreshTime );
		v.set_refreshtimes( m_RefreshTimes );

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
		ShopShopObjV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ShopType(商店类型) [sint32]</li>\r\n";
		htmlBuff += "<li>ItemArray(道具) [ItemObj] Array</li>\r\n";
		htmlBuff += "<li>LastRefreshTime(上次刷新时间) [sint64]</li>\r\n";
		htmlBuff += "<li>RefreshTimes(刷新次数) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		tmpLine.Fmt("<li>ShopType：%di</li>\r\n",m_ShopType);
		htmlBuff += tmpLine;
		htmlBuff += "<li>ItemArray：</li>\r\n";
		if( m_ItemArray.size()>0) htmlBuff += m_ItemArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ItemArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ItemArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";
		tmpLine.Fmt("<li>LastRefreshTime：%lldL</li>\r\n",m_LastRefreshTime);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>RefreshTimes：%di</li>\r\n",m_RefreshTimes);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ShopShopObjV1& v)
	{
		m_ShopType = v.shoptype();
		m_ItemArray.clear();
		m_ItemArray.reserve(v.itemarray_size());
		for( int i=0; i<v.itemarray_size(); i++)
			m_ItemArray.push_back(v.itemarray(i));
		m_LastRefreshTime = v.lastrefreshtime();
		m_RefreshTimes = v.refreshtimes();

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
	//道具
	vector<ShopItemObjWraperV1> m_ItemArray;
public:
	int SizeItemArray()
	{
		return m_ItemArray.size();
	}
	const vector<ShopItemObjWraperV1>& GetItemArray() const
	{
		return m_ItemArray;
	}
	ShopItemObjWraperV1 GetItemArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_ItemArray.size())
		{
			assert(false);
			return ShopItemObjWraperV1();
		}
		return m_ItemArray[Index];
	}
	void SetItemArray( const vector<ShopItemObjWraperV1>& v )
	{
		m_ItemArray=v;
	}
	void ClearItemArray( )
	{
		m_ItemArray.clear();
	}
	void SetItemArray( int Index, const ShopItemObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_ItemArray.size())
		{
			assert(false);
			return;
		}
		m_ItemArray[Index] = v;
	}
	void AddItemArray( const ShopItemObjWraperV1& v )
	{
		m_ItemArray.push_back(v);
	}
private:
	//上次刷新时间
	INT64 m_LastRefreshTime;
public:
	void SetLastRefreshTime( INT64 v)
	{
		m_LastRefreshTime=v;
	}
	INT64 GetLastRefreshTime()
	{
		return m_LastRefreshTime;
	}
	INT64 GetLastRefreshTime() const
	{
		return m_LastRefreshTime;
	}
private:
	//刷新次数
	INT32 m_RefreshTimes;
public:
	void SetRefreshTimes( INT32 v)
	{
		m_RefreshTimes=v;
	}
	INT32 GetRefreshTimes()
	{
		return m_RefreshTimes;
	}
	INT32 GetRefreshTimes() const
	{
		return m_RefreshTimes;
	}

};
//商店数据封装类
class ShopShopDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<ShopShopDataWraperV1>
{
public:
	//构造函数
	ShopShopDataWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	ShopShopDataWraperV1(const ShopShopDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const ShopShopDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	ShopShopDataV1 ToPB() const
	{
		ShopShopDataV1 v;
		v.mutable_shoparray()->Reserve(m_ShopArray.size());
		for (int i=0; i<(int)m_ShopArray.size(); i++)
		{
			*v.add_shoparray() = m_ShopArray[i].ToPB();
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
		ShopShopDataV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>ShopArray(商店) [ShopObj] Array</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>ShopArray：</li>\r\n";
		if( m_ShopArray.size()>0) htmlBuff += m_ShopArray[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_ShopArray.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_ShopArray[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const ShopShopDataV1& v)
	{
		m_ShopArray.clear();
		m_ShopArray.reserve(v.shoparray_size());
		for( int i=0; i<v.shoparray_size(); i++)
			m_ShopArray.push_back(v.shoparray(i));

	}

private:
	//商店
	vector<ShopShopObjWraperV1> m_ShopArray;
public:
	int SizeShopArray()
	{
		return m_ShopArray.size();
	}
	const vector<ShopShopObjWraperV1>& GetShopArray() const
	{
		return m_ShopArray;
	}
	ShopShopObjWraperV1 GetShopArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_ShopArray.size())
		{
			assert(false);
			return ShopShopObjWraperV1();
		}
		return m_ShopArray[Index];
	}
	void SetShopArray( const vector<ShopShopObjWraperV1>& v )
	{
		m_ShopArray=v;
	}
	void ClearShopArray( )
	{
		m_ShopArray.clear();
	}
	void SetShopArray( int Index, const ShopShopObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_ShopArray.size())
		{
			assert(false);
			return;
		}
		m_ShopArray[Index] = v;
	}
	void AddShopArray( const ShopShopObjWraperV1& v )
	{
		m_ShopArray.push_back(v);
	}

};

#endif
