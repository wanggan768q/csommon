#ifndef __SYNC_DATA_BAG_V1_H
#define __SYNC_DATA_BAG_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "BagV1DataWraper.h"


//同步数据相关枚举量定义
enum BagSyncDataItemIdE
{
 	SYNCID_BAG_GRIDARRAY                        = 1401,  //背包格子数组
 	SYNCID_BAG_EQUIPALLDATA                     = 1404,  //装备全部数据
 	SYNCID_BAG_WEAREQUIPCONTAINER               = 1405,  //穿戴装备容器
 	SYNCID_BAG_STORAGEBAGGRID                   = 1407,  //仓库
 	SYNCID_BAG_STORAGEBANK                      = 1408,  //仓库金钱
 	SYNCID_BAG_TALISMANDATA                     = 1409,  //法宝数据
 	SYNCID_BAG_TALISMANFOREVERATTR              = 1410,  //装备过的法宝，可获得永久属性加成
 	SYNCID_BAG_AUTOPICKUP                       = 1411,  //自动拾取设置
 	SYNCID_BAG_USEITEMDAY                       = 1415,  //每天使用的道具
 	SYNCID_BAG_USEITEMWEEK                      = 1416,  //每周使用的道具

};


//主同步数据操作类
class SyncDataBagV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataBagV1>
{
public:
			SyncDataBagV1();
	virtual	~SyncDataBagV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataPackageData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataPackageData.HtmlDescHeader(); }
public:
	//背包格子数组
	void SetGridArray( const vector<BagGridInfoWraperV1>& v );
	void SetGridArray( int Index, const BagGridInfoWraperV1& v );
	vector<BagGridInfoWraperV1> GetGridArray();
	BagGridInfoWraperV1 GetGridArray( int Index );
	void AddGridArray( const BagGridInfoWraperV1& v);
	void SendGridArray( int Index,bool OnlyToClient=true );
	void SendGridArray(bool OnlyToClient=true);
	int  SizeGridArray(){ return m_syncDataPackageData.SizeGridArray(); }
public:
	//装备全部数据
	void SetEquipAllData( const vector<BagEquipObjWraper>& v );
	void SetEquipAllData( int Index, const BagEquipObjWraper& v );
	vector<BagEquipObjWraper> GetEquipAllData();
	BagEquipObjWraper GetEquipAllData( int Index );
	void AddEquipAllData( const BagEquipObjWraper& v);
	void SendEquipAllData( int Index,bool OnlyToClient=true );
	void SendEquipAllData(bool OnlyToClient=true);
	int  SizeEquipAllData(){ return m_syncDataPackageData.SizeEquipAllData(); }
public:
	//穿戴装备容器
	void SetWearEquipContainer( const vector<BagGridInfoWraperV1>& v );
	void SetWearEquipContainer( int Index, const BagGridInfoWraperV1& v );
	vector<BagGridInfoWraperV1> GetWearEquipContainer();
	BagGridInfoWraperV1 GetWearEquipContainer( int Index );
	void AddWearEquipContainer( const BagGridInfoWraperV1& v);
	void SendWearEquipContainer( int Index,bool OnlyToClient=true );
	void SendWearEquipContainer(bool OnlyToClient=true);
	int  SizeWearEquipContainer(){ return m_syncDataPackageData.SizeWearEquipContainer(); }
public:
	//仓库
	void SetStorageBagGrid( const vector<BagGridInfoWraperV1>& v );
	void SetStorageBagGrid( int Index, const BagGridInfoWraperV1& v );
	vector<BagGridInfoWraperV1> GetStorageBagGrid();
	BagGridInfoWraperV1 GetStorageBagGrid( int Index );
	void AddStorageBagGrid( const BagGridInfoWraperV1& v);
	void SendStorageBagGrid( int Index,bool OnlyToClient=true );
	void SendStorageBagGrid(bool OnlyToClient=true);
	int  SizeStorageBagGrid(){ return m_syncDataPackageData.SizeStorageBagGrid(); }
public:
	//仓库金钱
	void SetStorageBank( const INT32& v );
	INT32 GetStorageBank();
	void SendStorageBank(bool OnlyToClient=true);
public:
	//法宝数据
	void SetTalismanData( const vector<BagTalismanObjWraperV1>& v );
	void SetTalismanData( int Index, const BagTalismanObjWraperV1& v );
	vector<BagTalismanObjWraperV1> GetTalismanData();
	BagTalismanObjWraperV1 GetTalismanData( int Index );
	void AddTalismanData( const BagTalismanObjWraperV1& v);
	void SendTalismanData( int Index,bool OnlyToClient=true );
	void SendTalismanData(bool OnlyToClient=true);
	int  SizeTalismanData(){ return m_syncDataPackageData.SizeTalismanData(); }
public:
	//装备过的法宝，可获得永久属性加成
	void SetTalismanForeverAttr( const vector<INT32>& v );
	void SetTalismanForeverAttr( int Index, const INT32& v );
	vector<INT32> GetTalismanForeverAttr();
	INT32 GetTalismanForeverAttr( int Index );
	void AddTalismanForeverAttr( INT32 v=-1 );
	void SendTalismanForeverAttr( int Index,bool OnlyToClient=true );
	void SendTalismanForeverAttr(bool OnlyToClient=true);
	int  SizeTalismanForeverAttr(){ return m_syncDataPackageData.SizeTalismanForeverAttr(); }
public:
	//自动拾取设置
	void SetAutoPickup( const vector<KeyValue2IntBoolWraper>& v );
	void SetAutoPickup( int Index, const KeyValue2IntBoolWraper& v );
	vector<KeyValue2IntBoolWraper> GetAutoPickup();
	KeyValue2IntBoolWraper GetAutoPickup( int Index );
	void AddAutoPickup( const KeyValue2IntBoolWraper& v);
	void SendAutoPickup( int Index,bool OnlyToClient=true );
	void SendAutoPickup(bool OnlyToClient=true);
	int  SizeAutoPickup(){ return m_syncDataPackageData.SizeAutoPickup(); }
public:
	//每天使用的道具
	void SetUseItemDay( const vector<KeyValue2IntIntWraper>& v );
	void SetUseItemDay( int Index, const KeyValue2IntIntWraper& v );
	vector<KeyValue2IntIntWraper> GetUseItemDay();
	KeyValue2IntIntWraper GetUseItemDay( int Index );
	void AddUseItemDay( const KeyValue2IntIntWraper& v);
	void SendUseItemDay( int Index,bool OnlyToClient=true );
	void SendUseItemDay(bool OnlyToClient=true);
	int  SizeUseItemDay(){ return m_syncDataPackageData.SizeUseItemDay(); }
public:
	//每周使用的道具
	void SetUseItemWeek( const vector<KeyValue2IntIntWraper>& v );
	void SetUseItemWeek( int Index, const KeyValue2IntIntWraper& v );
	vector<KeyValue2IntIntWraper> GetUseItemWeek();
	KeyValue2IntIntWraper GetUseItemWeek( int Index );
	void AddUseItemWeek( const KeyValue2IntIntWraper& v);
	void SendUseItemWeek( int Index,bool OnlyToClient=true );
	void SendUseItemWeek(bool OnlyToClient=true);
	int  SizeUseItemWeek(){ return m_syncDataPackageData.SizeUseItemWeek(); }


private:
	BagPackageDataWraperV1 m_syncDataPackageData;

};



#endif
