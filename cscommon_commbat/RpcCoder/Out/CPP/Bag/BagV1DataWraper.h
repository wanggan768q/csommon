/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperBag.h
* Author:       甘业清
* Description:  背包同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_BAG_H
#define __SYNC_WRAPER_BAG_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "BagV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//槽位信息封装类
class BagSlotInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BagSlotInfoWraperV1()
	{
		
		m_SlotId = -1;
		m_SlotType = -1;
		m_SlotSkillId = -1;

	}
	//赋值构造函数
	BagSlotInfoWraperV1(const BagSlotInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BagSlotInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagSlotInfoV1 ToPB() const
	{
		BagSlotInfoV1 v;
		v.set_slotid( m_SlotId );
		v.set_slottype( m_SlotType );
		v.set_slotskillid( m_SlotSkillId );

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
		BagSlotInfoV1 pb;
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
	void Init(const BagSlotInfoV1& v)
	{
		m_SlotId = v.slotid();
		m_SlotType = v.slottype();
		m_SlotSkillId = v.slotskillid();

	}

private:
	//槽位Id
	INT32 m_SlotId;
public:
	void SetSlotId( INT32 v)
	{
		m_SlotId=v;
	}
	INT32 GetSlotId()
	{
		return m_SlotId;
	}
	INT32 GetSlotId() const
	{
		return m_SlotId;
	}
private:
	//槽位类别(0上古，1其他)
	INT32 m_SlotType;
public:
	void SetSlotType( INT32 v)
	{
		m_SlotType=v;
	}
	INT32 GetSlotType()
	{
		return m_SlotType;
	}
	INT32 GetSlotType() const
	{
		return m_SlotType;
	}
private:
	//聚灵技能ID
	INT32 m_SlotSkillId;
public:
	void SetSlotSkillId( INT32 v)
	{
		m_SlotSkillId=v;
	}
	INT32 GetSlotSkillId()
	{
		return m_SlotSkillId;
	}
	INT32 GetSlotSkillId() const
	{
		return m_SlotSkillId;
	}

};
//格子信息封装类
class BagGridInfoWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BagGridInfoWraperV1()
	{
		
		m_TemplateID = -1;
		m_Num = 0;
		m_ItemType = -1;
		m_Pos = -1;
		m_Value = -1;
		m_Index = -1;
		m_Bind = false;

	}
	//赋值构造函数
	BagGridInfoWraperV1(const BagGridInfoV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BagGridInfoV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagGridInfoV1 ToPB() const
	{
		BagGridInfoV1 v;
		v.set_templateid( m_TemplateID );
		v.set_num( m_Num );
		v.set_itemtype( m_ItemType );
		v.set_pos( m_Pos );
		v.set_value( m_Value );
		v.set_index( m_Index );
		v.set_bind( m_Bind );

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
		BagGridInfoV1 pb;
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
	void Init(const BagGridInfoV1& v)
	{
		m_TemplateID = v.templateid();
		m_Num = v.num();
		m_ItemType = v.itemtype();
		m_Pos = v.pos();
		m_Value = v.value();
		m_Index = v.index();
		m_Bind = v.bind();

	}

private:
	//物品的配置Id
	INT32 m_TemplateID;
public:
	void SetTemplateID( INT32 v)
	{
		m_TemplateID=v;
	}
	INT32 GetTemplateID()
	{
		return m_TemplateID;
	}
	INT32 GetTemplateID() const
	{
		return m_TemplateID;
	}
private:
	//物品数量
	INT32 m_Num;
public:
	void SetNum( INT32 v)
	{
		m_Num=v;
	}
	INT32 GetNum()
	{
		return m_Num;
	}
	INT32 GetNum() const
	{
		return m_Num;
	}
private:
	//物品类型
	INT32 m_ItemType;
public:
	void SetItemType( INT32 v)
	{
		m_ItemType=v;
	}
	INT32 GetItemType()
	{
		return m_ItemType;
	}
	INT32 GetItemType() const
	{
		return m_ItemType;
	}
private:
	//位置
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
private:
	//客户端通用数据
	INT32 m_Value;
public:
	void SetValue( INT32 v)
	{
		m_Value=v;
	}
	INT32 GetValue()
	{
		return m_Value;
	}
	INT32 GetValue() const
	{
		return m_Value;
	}
private:
	//实例id，唯一id
	INT64 m_Index;
public:
	void SetIndex( INT64 v)
	{
		m_Index=v;
	}
	INT64 GetIndex()
	{
		return m_Index;
	}
	INT64 GetIndex() const
	{
		return m_Index;
	}
private:
	//绑定
	bool m_Bind;
public:
	void SetBind( bool v)
	{
		m_Bind=v;
	}
	bool GetBind()
	{
		return m_Bind;
	}
	bool GetBind() const
	{
		return m_Bind;
	}

};
//法宝对象封装类
class BagTalismanObjWraperV1 : public DataWraperInterface 
{
public:
	//构造函数
	BagTalismanObjWraperV1()
	{
		
		m_ItemID = -1;
		m_TemplateId = -1;
		m_CurExp = 0;
		m_EquipScore = 0;
		m_StarLevel = 0;
		m_TailsManLevel = -1;

	}
	//赋值构造函数
	BagTalismanObjWraperV1(const BagTalismanObjV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BagTalismanObjV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagTalismanObjV1 ToPB() const
	{
		BagTalismanObjV1 v;
		v.set_itemid( m_ItemID );
		v.set_templateid( m_TemplateId );
		v.set_curexp( m_CurExp );
		v.set_equipscore( m_EquipScore );
		v.set_starlevel( m_StarLevel );
		v.mutable_gatherspriteslot()->Reserve(m_GatherSpriteSlot.size());
		for (int i=0; i<(int)m_GatherSpriteSlot.size(); i++)
		{
			*v.add_gatherspriteslot() = m_GatherSpriteSlot[i].ToPB();
		}
		v.set_tailsmanlevel( m_TailsManLevel );
		v.mutable_talismanattr()->Reserve(m_TalismanAttr.size());
		for (int i=0; i<(int)m_TalismanAttr.size(); i++)
		{
			v.add_talismanattr(m_TalismanAttr[i]);
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
		BagTalismanObjV1 pb;
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
	void Init(const BagTalismanObjV1& v)
	{
		m_ItemID = v.itemid();
		m_TemplateId = v.templateid();
		m_CurExp = v.curexp();
		m_EquipScore = v.equipscore();
		m_StarLevel = v.starlevel();
		m_GatherSpriteSlot.clear();
		m_GatherSpriteSlot.reserve(v.gatherspriteslot_size());
		for( int i=0; i<v.gatherspriteslot_size(); i++)
			m_GatherSpriteSlot.push_back(v.gatherspriteslot(i));
		m_TailsManLevel = v.tailsmanlevel();
		m_TalismanAttr.clear();
		m_TalismanAttr.reserve(v.talismanattr_size());
		for( int i=0; i<v.talismanattr_size(); i++)
			m_TalismanAttr.push_back(v.talismanattr(i));

	}

private:
	//物品实例id, 唯一id
	INT64 m_ItemID;
public:
	void SetItemID( INT64 v)
	{
		m_ItemID=v;
	}
	INT64 GetItemID()
	{
		return m_ItemID;
	}
	INT64 GetItemID() const
	{
		return m_ItemID;
	}
private:
	//模板id
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
private:
	//当前经验
	INT32 m_CurExp;
public:
	void SetCurExp( INT32 v)
	{
		m_CurExp=v;
	}
	INT32 GetCurExp()
	{
		return m_CurExp;
	}
	INT32 GetCurExp() const
	{
		return m_CurExp;
	}
private:
	//装备评分
	INT32 m_EquipScore;
public:
	void SetEquipScore( INT32 v)
	{
		m_EquipScore=v;
	}
	INT32 GetEquipScore()
	{
		return m_EquipScore;
	}
	INT32 GetEquipScore() const
	{
		return m_EquipScore;
	}
private:
	//星级
	INT32 m_StarLevel;
public:
	void SetStarLevel( INT32 v)
	{
		m_StarLevel=v;
	}
	INT32 GetStarLevel()
	{
		return m_StarLevel;
	}
	INT32 GetStarLevel() const
	{
		return m_StarLevel;
	}
private:
	//聚灵槽位
	vector<BagSlotInfoWraperV1> m_GatherSpriteSlot;
public:
	int SizeGatherSpriteSlot()
	{
		return m_GatherSpriteSlot.size();
	}
	const vector<BagSlotInfoWraperV1>& GetGatherSpriteSlot() const
	{
		return m_GatherSpriteSlot;
	}
	BagSlotInfoWraperV1 GetGatherSpriteSlot(int Index) const
	{
		if(Index<0 || Index>=(int)m_GatherSpriteSlot.size())
		{
			assert(false);
			return BagSlotInfoWraperV1();
		}
		return m_GatherSpriteSlot[Index];
	}
	void SetGatherSpriteSlot( const vector<BagSlotInfoWraperV1>& v )
	{
		m_GatherSpriteSlot=v;
	}
	void ClearGatherSpriteSlot( )
	{
		m_GatherSpriteSlot.clear();
	}
	void SetGatherSpriteSlot( int Index, const BagSlotInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_GatherSpriteSlot.size())
		{
			assert(false);
			return;
		}
		m_GatherSpriteSlot[Index] = v;
	}
	void AddGatherSpriteSlot( const BagSlotInfoWraperV1& v )
	{
		m_GatherSpriteSlot.push_back(v);
	}
private:
	//法宝等级
	INT32 m_TailsManLevel;
public:
	void SetTailsManLevel( INT32 v)
	{
		m_TailsManLevel=v;
	}
	INT32 GetTailsManLevel()
	{
		return m_TailsManLevel;
	}
	INT32 GetTailsManLevel() const
	{
		return m_TailsManLevel;
	}
private:
	//法宝属性
	vector<INT32> m_TalismanAttr;
public:
	int SizeTalismanAttr()
	{
		return m_TalismanAttr.size();
	}
	const vector<INT32>& GetTalismanAttr() const
	{
		return m_TalismanAttr;
	}
	INT32 GetTalismanAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_TalismanAttr.size())
		{
			assert(false);
			return INT32();
		}
		return m_TalismanAttr[Index];
	}
	void SetTalismanAttr( const vector<INT32>& v )
	{
		m_TalismanAttr=v;
	}
	void ClearTalismanAttr( )
	{
		m_TalismanAttr.clear();
	}
	void SetTalismanAttr( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_TalismanAttr.size())
		{
			assert(false);
			return;
		}
		m_TalismanAttr[Index] = v;
	}
	void AddTalismanAttr( INT32 v = -1 )
	{
		m_TalismanAttr.push_back(v);
	}

};
//背包数据封装类
class BagPackageDataWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<BagPackageDataWraperV1>
{
public:
	//构造函数
	BagPackageDataWraperV1()
	{
		SetDataWraper( this );

		m_StorageBank = 0;

	}
	//赋值构造函数
	BagPackageDataWraperV1(const BagPackageDataV1& v){ Init(v); }
	//等号重载函数
	void operator = (const BagPackageDataV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	BagPackageDataV1 ToPB() const
	{
		BagPackageDataV1 v;
		v.mutable_gridarray()->Reserve(m_GridArray.size());
		for (int i=0; i<(int)m_GridArray.size(); i++)
		{
			*v.add_gridarray() = m_GridArray[i].ToPB();
		}
		v.mutable_equipalldata()->Reserve(m_EquipAllData.size());
		for (int i=0; i<(int)m_EquipAllData.size(); i++)
		{
			*v.add_equipalldata() = m_EquipAllData[i].ToPB();
		}
		v.mutable_wearequipcontainer()->Reserve(m_WearEquipContainer.size());
		for (int i=0; i<(int)m_WearEquipContainer.size(); i++)
		{
			*v.add_wearequipcontainer() = m_WearEquipContainer[i].ToPB();
		}
		v.mutable_storagebaggrid()->Reserve(m_StorageBagGrid.size());
		for (int i=0; i<(int)m_StorageBagGrid.size(); i++)
		{
			*v.add_storagebaggrid() = m_StorageBagGrid[i].ToPB();
		}
		v.set_storagebank( m_StorageBank );
		v.mutable_talismandata()->Reserve(m_TalismanData.size());
		for (int i=0; i<(int)m_TalismanData.size(); i++)
		{
			*v.add_talismandata() = m_TalismanData[i].ToPB();
		}
		v.mutable_talismanforeverattr()->Reserve(m_TalismanForeverAttr.size());
		for (int i=0; i<(int)m_TalismanForeverAttr.size(); i++)
		{
			v.add_talismanforeverattr(m_TalismanForeverAttr[i]);
		}
		v.mutable_autopickup()->Reserve(m_AutoPickup.size());
		for (int i=0; i<(int)m_AutoPickup.size(); i++)
		{
			*v.add_autopickup() = m_AutoPickup[i].ToPB();
		}
		v.mutable_useitemday()->Reserve(m_UseItemDay.size());
		for (int i=0; i<(int)m_UseItemDay.size(); i++)
		{
			*v.add_useitemday() = m_UseItemDay[i].ToPB();
		}
		v.mutable_useitemweek()->Reserve(m_UseItemWeek.size());
		for (int i=0; i<(int)m_UseItemWeek.size(); i++)
		{
			*v.add_useitemweek() = m_UseItemWeek[i].ToPB();
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
		BagPackageDataV1 pb;
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
	void Init(const BagPackageDataV1& v)
	{
		m_GridArray.clear();
		m_GridArray.reserve(v.gridarray_size());
		for( int i=0; i<v.gridarray_size(); i++)
			m_GridArray.push_back(v.gridarray(i));
		m_EquipAllData.clear();
		m_EquipAllData.reserve(v.equipalldata_size());
		for( int i=0; i<v.equipalldata_size(); i++)
			m_EquipAllData.push_back(v.equipalldata(i));
		m_WearEquipContainer.clear();
		m_WearEquipContainer.reserve(v.wearequipcontainer_size());
		for( int i=0; i<v.wearequipcontainer_size(); i++)
			m_WearEquipContainer.push_back(v.wearequipcontainer(i));
		m_StorageBagGrid.clear();
		m_StorageBagGrid.reserve(v.storagebaggrid_size());
		for( int i=0; i<v.storagebaggrid_size(); i++)
			m_StorageBagGrid.push_back(v.storagebaggrid(i));
		m_StorageBank = v.storagebank();
		m_TalismanData.clear();
		m_TalismanData.reserve(v.talismandata_size());
		for( int i=0; i<v.talismandata_size(); i++)
			m_TalismanData.push_back(v.talismandata(i));
		m_TalismanForeverAttr.clear();
		m_TalismanForeverAttr.reserve(v.talismanforeverattr_size());
		for( int i=0; i<v.talismanforeverattr_size(); i++)
			m_TalismanForeverAttr.push_back(v.talismanforeverattr(i));
		m_AutoPickup.clear();
		m_AutoPickup.reserve(v.autopickup_size());
		for( int i=0; i<v.autopickup_size(); i++)
			m_AutoPickup.push_back(v.autopickup(i));
		m_UseItemDay.clear();
		m_UseItemDay.reserve(v.useitemday_size());
		for( int i=0; i<v.useitemday_size(); i++)
			m_UseItemDay.push_back(v.useitemday(i));
		m_UseItemWeek.clear();
		m_UseItemWeek.reserve(v.useitemweek_size());
		for( int i=0; i<v.useitemweek_size(); i++)
			m_UseItemWeek.push_back(v.useitemweek(i));

	}

private:
	//背包格子数组
	vector<BagGridInfoWraperV1> m_GridArray;
public:
	int SizeGridArray()
	{
		return m_GridArray.size();
	}
	const vector<BagGridInfoWraperV1>& GetGridArray() const
	{
		return m_GridArray;
	}
	BagGridInfoWraperV1 GetGridArray(int Index) const
	{
		if(Index<0 || Index>=(int)m_GridArray.size())
		{
			assert(false);
			return BagGridInfoWraperV1();
		}
		return m_GridArray[Index];
	}
	void SetGridArray( const vector<BagGridInfoWraperV1>& v )
	{
		m_GridArray=v;
	}
	void ClearGridArray( )
	{
		m_GridArray.clear();
	}
	void SetGridArray( int Index, const BagGridInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_GridArray.size())
		{
			assert(false);
			return;
		}
		m_GridArray[Index] = v;
	}
	void AddGridArray( const BagGridInfoWraperV1& v )
	{
		m_GridArray.push_back(v);
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
private:
	//穿戴装备容器
	vector<BagGridInfoWraperV1> m_WearEquipContainer;
public:
	int SizeWearEquipContainer()
	{
		return m_WearEquipContainer.size();
	}
	const vector<BagGridInfoWraperV1>& GetWearEquipContainer() const
	{
		return m_WearEquipContainer;
	}
	BagGridInfoWraperV1 GetWearEquipContainer(int Index) const
	{
		if(Index<0 || Index>=(int)m_WearEquipContainer.size())
		{
			assert(false);
			return BagGridInfoWraperV1();
		}
		return m_WearEquipContainer[Index];
	}
	void SetWearEquipContainer( const vector<BagGridInfoWraperV1>& v )
	{
		m_WearEquipContainer=v;
	}
	void ClearWearEquipContainer( )
	{
		m_WearEquipContainer.clear();
	}
	void SetWearEquipContainer( int Index, const BagGridInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_WearEquipContainer.size())
		{
			assert(false);
			return;
		}
		m_WearEquipContainer[Index] = v;
	}
	void AddWearEquipContainer( const BagGridInfoWraperV1& v )
	{
		m_WearEquipContainer.push_back(v);
	}
private:
	//仓库
	vector<BagGridInfoWraperV1> m_StorageBagGrid;
public:
	int SizeStorageBagGrid()
	{
		return m_StorageBagGrid.size();
	}
	const vector<BagGridInfoWraperV1>& GetStorageBagGrid() const
	{
		return m_StorageBagGrid;
	}
	BagGridInfoWraperV1 GetStorageBagGrid(int Index) const
	{
		if(Index<0 || Index>=(int)m_StorageBagGrid.size())
		{
			assert(false);
			return BagGridInfoWraperV1();
		}
		return m_StorageBagGrid[Index];
	}
	void SetStorageBagGrid( const vector<BagGridInfoWraperV1>& v )
	{
		m_StorageBagGrid=v;
	}
	void ClearStorageBagGrid( )
	{
		m_StorageBagGrid.clear();
	}
	void SetStorageBagGrid( int Index, const BagGridInfoWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_StorageBagGrid.size())
		{
			assert(false);
			return;
		}
		m_StorageBagGrid[Index] = v;
	}
	void AddStorageBagGrid( const BagGridInfoWraperV1& v )
	{
		m_StorageBagGrid.push_back(v);
	}
private:
	//仓库金钱
	INT32 m_StorageBank;
public:
	void SetStorageBank( INT32 v)
	{
		m_StorageBank=v;
	}
	INT32 GetStorageBank()
	{
		return m_StorageBank;
	}
	INT32 GetStorageBank() const
	{
		return m_StorageBank;
	}
private:
	//法宝数据
	vector<BagTalismanObjWraperV1> m_TalismanData;
public:
	int SizeTalismanData()
	{
		return m_TalismanData.size();
	}
	const vector<BagTalismanObjWraperV1>& GetTalismanData() const
	{
		return m_TalismanData;
	}
	BagTalismanObjWraperV1 GetTalismanData(int Index) const
	{
		if(Index<0 || Index>=(int)m_TalismanData.size())
		{
			assert(false);
			return BagTalismanObjWraperV1();
		}
		return m_TalismanData[Index];
	}
	void SetTalismanData( const vector<BagTalismanObjWraperV1>& v )
	{
		m_TalismanData=v;
	}
	void ClearTalismanData( )
	{
		m_TalismanData.clear();
	}
	void SetTalismanData( int Index, const BagTalismanObjWraperV1& v )
	{
		if(Index<0 || Index>=(int)m_TalismanData.size())
		{
			assert(false);
			return;
		}
		m_TalismanData[Index] = v;
	}
	void AddTalismanData( const BagTalismanObjWraperV1& v )
	{
		m_TalismanData.push_back(v);
	}
private:
	//装备过的法宝，可获得永久属性加成
	vector<INT32> m_TalismanForeverAttr;
public:
	int SizeTalismanForeverAttr()
	{
		return m_TalismanForeverAttr.size();
	}
	const vector<INT32>& GetTalismanForeverAttr() const
	{
		return m_TalismanForeverAttr;
	}
	INT32 GetTalismanForeverAttr(int Index) const
	{
		if(Index<0 || Index>=(int)m_TalismanForeverAttr.size())
		{
			assert(false);
			return INT32();
		}
		return m_TalismanForeverAttr[Index];
	}
	void SetTalismanForeverAttr( const vector<INT32>& v )
	{
		m_TalismanForeverAttr=v;
	}
	void ClearTalismanForeverAttr( )
	{
		m_TalismanForeverAttr.clear();
	}
	void SetTalismanForeverAttr( int Index, INT32 v )
	{
		if(Index<0 || Index>=(int)m_TalismanForeverAttr.size())
		{
			assert(false);
			return;
		}
		m_TalismanForeverAttr[Index] = v;
	}
	void AddTalismanForeverAttr( INT32 v = -1 )
	{
		m_TalismanForeverAttr.push_back(v);
	}
private:
	//自动拾取设置
	vector<KeyValue2IntBoolWraper> m_AutoPickup;
public:
	int SizeAutoPickup()
	{
		return m_AutoPickup.size();
	}
	const vector<KeyValue2IntBoolWraper>& GetAutoPickup() const
	{
		return m_AutoPickup;
	}
	KeyValue2IntBoolWraper GetAutoPickup(int Index) const
	{
		if(Index<0 || Index>=(int)m_AutoPickup.size())
		{
			assert(false);
			return KeyValue2IntBoolWraper();
		}
		return m_AutoPickup[Index];
	}
	void SetAutoPickup( const vector<KeyValue2IntBoolWraper>& v )
	{
		m_AutoPickup=v;
	}
	void ClearAutoPickup( )
	{
		m_AutoPickup.clear();
	}
	void SetAutoPickup( int Index, const KeyValue2IntBoolWraper& v )
	{
		if(Index<0 || Index>=(int)m_AutoPickup.size())
		{
			assert(false);
			return;
		}
		m_AutoPickup[Index] = v;
	}
	void AddAutoPickup( const KeyValue2IntBoolWraper& v )
	{
		m_AutoPickup.push_back(v);
	}
private:
	//每天使用的道具
	vector<KeyValue2IntIntWraper> m_UseItemDay;
public:
	int SizeUseItemDay()
	{
		return m_UseItemDay.size();
	}
	const vector<KeyValue2IntIntWraper>& GetUseItemDay() const
	{
		return m_UseItemDay;
	}
	KeyValue2IntIntWraper GetUseItemDay(int Index) const
	{
		if(Index<0 || Index>=(int)m_UseItemDay.size())
		{
			assert(false);
			return KeyValue2IntIntWraper();
		}
		return m_UseItemDay[Index];
	}
	void SetUseItemDay( const vector<KeyValue2IntIntWraper>& v )
	{
		m_UseItemDay=v;
	}
	void ClearUseItemDay( )
	{
		m_UseItemDay.clear();
	}
	void SetUseItemDay( int Index, const KeyValue2IntIntWraper& v )
	{
		if(Index<0 || Index>=(int)m_UseItemDay.size())
		{
			assert(false);
			return;
		}
		m_UseItemDay[Index] = v;
	}
	void AddUseItemDay( const KeyValue2IntIntWraper& v )
	{
		m_UseItemDay.push_back(v);
	}
private:
	//每周使用的道具
	vector<KeyValue2IntIntWraper> m_UseItemWeek;
public:
	int SizeUseItemWeek()
	{
		return m_UseItemWeek.size();
	}
	const vector<KeyValue2IntIntWraper>& GetUseItemWeek() const
	{
		return m_UseItemWeek;
	}
	KeyValue2IntIntWraper GetUseItemWeek(int Index) const
	{
		if(Index<0 || Index>=(int)m_UseItemWeek.size())
		{
			assert(false);
			return KeyValue2IntIntWraper();
		}
		return m_UseItemWeek[Index];
	}
	void SetUseItemWeek( const vector<KeyValue2IntIntWraper>& v )
	{
		m_UseItemWeek=v;
	}
	void ClearUseItemWeek( )
	{
		m_UseItemWeek.clear();
	}
	void SetUseItemWeek( int Index, const KeyValue2IntIntWraper& v )
	{
		if(Index<0 || Index>=(int)m_UseItemWeek.size())
		{
			assert(false);
			return;
		}
		m_UseItemWeek[Index] = v;
	}
	void AddUseItemWeek( const KeyValue2IntIntWraper& v )
	{
		m_UseItemWeek.push_back(v);
	}

};

#endif
