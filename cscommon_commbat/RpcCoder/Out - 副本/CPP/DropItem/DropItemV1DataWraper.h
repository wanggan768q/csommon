/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperDropItem.h
* Author:       甘业清
* Description:  掉落物同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_DROPITEM_H
#define __SYNC_WRAPER_DROPITEM_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "DropItemV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//掉落物品数据封装类
class DropItemDropItemWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<DropItemDropItemWraperV1>
{
public:
	//构造函数
	DropItemDropItemWraperV1()
	{
		SetDataWraper( this );


	}
	//赋值构造函数
	DropItemDropItemWraperV1(const DropItemDropItemV1& v){ Init(v); }
	//等号重载函数
	void operator = (const DropItemDropItemV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	DropItemDropItemV1 ToPB() const
	{
		DropItemDropItemV1 v;
		v.mutable_dropitem()->Reserve(m_DropItem.size());
		for (int i=0; i<(int)m_DropItem.size(); i++)
		{
			*v.add_dropitem() = m_DropItem[i].ToPB();
		}
		v.mutable_equipalldata()->Reserve(m_EquipAllData.size());
		for (int i=0; i<(int)m_EquipAllData.size(); i++)
		{
			*v.add_equipalldata() = m_EquipAllData[i].ToPB();
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
		DropItemDropItemV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>DropItem(掉落的物品) [DropItemObj] Array</li>\r\n";
		htmlBuff += "<li>EquipAllData(装备全部数据) [BagEquipObj] Array</li>\r\n";

		
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
		htmlBuff += "<li>EquipAllData：</li>\r\n";
		if( m_EquipAllData.size()>0) htmlBuff += m_EquipAllData[0].HtmlDescHeader();
		htmlBuff +="<div style=\"padding-left:15px\"><table border=1>\r\n";
		for( int i=0; i<(int)m_EquipAllData.size(); i++){
			tmpLine.Fmt("%d",i);
			htmlBuff += "<tr><td>"+ tmpLine+"</td><td>"+m_EquipAllData[i].ToHtml().c_str() +"</td></tr>";
		}
		htmlBuff += "</table></div>";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const DropItemDropItemV1& v)
	{
		m_DropItem.clear();
		m_DropItem.reserve(v.dropitem_size());
		for( int i=0; i<v.dropitem_size(); i++)
			m_DropItem.push_back(v.dropitem(i));
		m_EquipAllData.clear();
		m_EquipAllData.reserve(v.equipalldata_size());
		for( int i=0; i<v.equipalldata_size(); i++)
			m_EquipAllData.push_back(v.equipalldata(i));

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
private:
	//装备全部数据
	vector<BagEquipObjWraper> m_EquipAllData;
public:
	int SizeEquipAllData()
	{
		return m_EquipAllData.size();
	}
	const vector<BagEquipObjWraper>& GetEquipAllData() const
	{
		return m_EquipAllData;
	}
	BagEquipObjWraper GetEquipAllData(int Index) const
	{
		if(Index<0 || Index>=(int)m_EquipAllData.size())
		{
			assert(false);
			return BagEquipObjWraper();
		}
		return m_EquipAllData[Index];
	}
	void SetEquipAllData( const vector<BagEquipObjWraper>& v )
	{
		m_EquipAllData=v;
	}
	void ClearEquipAllData( )
	{
		m_EquipAllData.clear();
	}
	void SetEquipAllData( int Index, const BagEquipObjWraper& v )
	{
		if(Index<0 || Index>=(int)m_EquipAllData.size())
		{
			assert(false);
			return;
		}
		m_EquipAllData[Index] = v;
	}
	void AddEquipAllData( const BagEquipObjWraper& v )
	{
		m_EquipAllData.push_back(v);
	}

};

#endif
