#ifndef __SYNC_DATA_DROPITEM_V1_H
#define __SYNC_DATA_DROPITEM_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "DropItemV1DataWraper.h"


//同步数据相关枚举量定义
enum DropItemSyncDataItemIdE
{
 	SYNCID_DROPITEM_DROPITEM                    = 3501,  //掉落的物品
 	SYNCID_DROPITEM_EQUIPALLDATA                = 3504,  //装备全部数据

};


//主同步数据操作类
class SyncDataDropItemV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataDropItemV1>
{
public:
			SyncDataDropItemV1();
	virtual	~SyncDataDropItemV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataDropItem.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataDropItem.HtmlDescHeader(); }
public:
	//掉落的物品
	void SetDropItem( const vector<DropItemObjWraper>& v );
	void SetDropItem( int Index, const DropItemObjWraper& v );
	vector<DropItemObjWraper> GetDropItem();
	DropItemObjWraper GetDropItem( int Index );
	void AddDropItem( const DropItemObjWraper& v);
	void SendDropItem( int Index,bool OnlyToClient=true );
	void SendDropItem(bool OnlyToClient=true);
	int  SizeDropItem(){ return m_syncDataDropItem.SizeDropItem(); }
public:
	//装备全部数据
	void SetEquipAllData( const vector<BagEquipObjWraper>& v );
	void SetEquipAllData( int Index, const BagEquipObjWraper& v );
	vector<BagEquipObjWraper> GetEquipAllData();
	BagEquipObjWraper GetEquipAllData( int Index );
	void AddEquipAllData( const BagEquipObjWraper& v);
	void SendEquipAllData( int Index,bool OnlyToClient=true );
	void SendEquipAllData(bool OnlyToClient=true);
	int  SizeEquipAllData(){ return m_syncDataDropItem.SizeEquipAllData(); }


private:
	DropItemDropItemWraperV1 m_syncDataDropItem;

};



#endif
