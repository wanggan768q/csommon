#include "BagV1Data.h"
#include "BagModule.h"


SyncDataBagV1::SyncDataBagV1()
{
	SetDataWraper( &m_syncDataPackageData );
}

SyncDataBagV1::~SyncDataBagV1()
{
}

void SyncDataBagV1::SendAllMembers(bool OnlyToClient)
{
	SendGridArray(OnlyToClient);
	SendEquipAllData(OnlyToClient);
	SendWearEquipContainer(OnlyToClient);
	SendStorageBagGrid(OnlyToClient);
	SendStorageBank(OnlyToClient);
	SendTalismanData(OnlyToClient);
	SendTalismanForeverAttr(OnlyToClient);
	SendAutoPickup(OnlyToClient);
	SendUseItemDay(OnlyToClient);
	SendUseItemWeek(OnlyToClient);

}



//背包格子数组
void SyncDataBagV1::SetGridArray( const vector<BagGridInfoWraperV1>& v )
{
	m_syncDataPackageData.SetGridArray(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_GRIDARRAY);
	SendGridArray(false);
}
void SyncDataBagV1::SetGridArray( int Index, const BagGridInfoWraperV1& v )
{
	m_syncDataPackageData.SetGridArray(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_GRIDARRAY,Index);
	SendGridArray(Index,false);
}
vector<BagGridInfoWraperV1> SyncDataBagV1::GetGridArray()
{
	return m_syncDataPackageData.GetGridArray();
}
BagGridInfoWraperV1 SyncDataBagV1::GetGridArray( int Index )
{
	return m_syncDataPackageData.GetGridArray(Index);
}
void SyncDataBagV1::SendGridArray(bool OnlyToClient)
{
	SendGridArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeGridArray(); i++)
		SendGridArray(i,OnlyToClient);
}
void SyncDataBagV1::SendGridArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_GRIDARRAY,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_GRIDARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_GRIDARRAY,Index,NULL,0);
		return;
	}
	const string v= GetGridArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_GRIDARRAY,Index,v.data(),v.size());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_GRIDARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_GRIDARRAY,Index,v.data(),v.size());
}
void SyncDataBagV1::AddGridArray( const BagGridInfoWraperV1& v )
{
	m_syncDataPackageData.AddGridArray(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeGridArray()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_GRIDARRAY,Index);
	SendGridArray(Index,false);
}

//装备全部数据
void SyncDataBagV1::SetEquipAllData( const vector<BagEquipObjWraper>& v )
{
	m_syncDataPackageData.SetEquipAllData(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_EQUIPALLDATA);
	SendEquipAllData(false);
}
void SyncDataBagV1::SetEquipAllData( int Index, const BagEquipObjWraper& v )
{
	m_syncDataPackageData.SetEquipAllData(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_EQUIPALLDATA,Index);
	SendEquipAllData(Index,false);
}
vector<BagEquipObjWraper> SyncDataBagV1::GetEquipAllData()
{
	return m_syncDataPackageData.GetEquipAllData();
}
BagEquipObjWraper SyncDataBagV1::GetEquipAllData( int Index )
{
	return m_syncDataPackageData.GetEquipAllData(Index);
}
void SyncDataBagV1::SendEquipAllData(bool OnlyToClient)
{
	SendEquipAllData(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeEquipAllData(); i++)
		SendEquipAllData(i,OnlyToClient);
}
void SyncDataBagV1::SendEquipAllData( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_EQUIPALLDATA,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_EQUIPALLDATA)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_EQUIPALLDATA,Index,NULL,0);
		return;
	}
	const string v= GetEquipAllData(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_EQUIPALLDATA,Index,v.data(),v.size());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_EQUIPALLDATA)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_EQUIPALLDATA,Index,v.data(),v.size());
}
void SyncDataBagV1::AddEquipAllData( const BagEquipObjWraper& v )
{
	m_syncDataPackageData.AddEquipAllData(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeEquipAllData()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_EQUIPALLDATA,Index);
	SendEquipAllData(Index,false);
}

//穿戴装备容器
void SyncDataBagV1::SetWearEquipContainer( const vector<BagGridInfoWraperV1>& v )
{
	m_syncDataPackageData.SetWearEquipContainer(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_WEAREQUIPCONTAINER);
	SendWearEquipContainer(false);
}
void SyncDataBagV1::SetWearEquipContainer( int Index, const BagGridInfoWraperV1& v )
{
	m_syncDataPackageData.SetWearEquipContainer(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_WEAREQUIPCONTAINER,Index);
	SendWearEquipContainer(Index,false);
}
vector<BagGridInfoWraperV1> SyncDataBagV1::GetWearEquipContainer()
{
	return m_syncDataPackageData.GetWearEquipContainer();
}
BagGridInfoWraperV1 SyncDataBagV1::GetWearEquipContainer( int Index )
{
	return m_syncDataPackageData.GetWearEquipContainer(Index);
}
void SyncDataBagV1::SendWearEquipContainer(bool OnlyToClient)
{
	SendWearEquipContainer(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeWearEquipContainer(); i++)
		SendWearEquipContainer(i,OnlyToClient);
}
void SyncDataBagV1::SendWearEquipContainer( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_WEAREQUIPCONTAINER,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_WEAREQUIPCONTAINER)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_WEAREQUIPCONTAINER,Index,NULL,0);
		return;
	}
	const string v= GetWearEquipContainer(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_WEAREQUIPCONTAINER,Index,v.data(),v.size());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_WEAREQUIPCONTAINER)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_WEAREQUIPCONTAINER,Index,v.data(),v.size());
}
void SyncDataBagV1::AddWearEquipContainer( const BagGridInfoWraperV1& v )
{
	m_syncDataPackageData.AddWearEquipContainer(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeWearEquipContainer()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_WEAREQUIPCONTAINER,Index);
	SendWearEquipContainer(Index,false);
}

//仓库
void SyncDataBagV1::SetStorageBagGrid( const vector<BagGridInfoWraperV1>& v )
{
	m_syncDataPackageData.SetStorageBagGrid(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_STORAGEBAGGRID);
	SendStorageBagGrid(false);
}
void SyncDataBagV1::SetStorageBagGrid( int Index, const BagGridInfoWraperV1& v )
{
	m_syncDataPackageData.SetStorageBagGrid(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_STORAGEBAGGRID,Index);
	SendStorageBagGrid(Index,false);
}
vector<BagGridInfoWraperV1> SyncDataBagV1::GetStorageBagGrid()
{
	return m_syncDataPackageData.GetStorageBagGrid();
}
BagGridInfoWraperV1 SyncDataBagV1::GetStorageBagGrid( int Index )
{
	return m_syncDataPackageData.GetStorageBagGrid(Index);
}
void SyncDataBagV1::SendStorageBagGrid(bool OnlyToClient)
{
	SendStorageBagGrid(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeStorageBagGrid(); i++)
		SendStorageBagGrid(i,OnlyToClient);
}
void SyncDataBagV1::SendStorageBagGrid( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_STORAGEBAGGRID,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_STORAGEBAGGRID)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_STORAGEBAGGRID,Index,NULL,0);
		return;
	}
	const string v= GetStorageBagGrid(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_STORAGEBAGGRID,Index,v.data(),v.size());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_STORAGEBAGGRID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_STORAGEBAGGRID,Index,v.data(),v.size());
}
void SyncDataBagV1::AddStorageBagGrid( const BagGridInfoWraperV1& v )
{
	m_syncDataPackageData.AddStorageBagGrid(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeStorageBagGrid()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_STORAGEBAGGRID,Index);
	SendStorageBagGrid(Index,false);
}

//仓库金钱
void SyncDataBagV1::SetStorageBank( const INT32& v )
{
	m_syncDataPackageData.SetStorageBank(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_STORAGEBANK);
	SendStorageBank(false);
}
INT32 SyncDataBagV1::GetStorageBank()
{
	return m_syncDataPackageData.GetStorageBank();
}
void SyncDataBagV1::SendStorageBank(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_STORAGEBANK,m_syncDataPackageData.GetStorageBank());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_STORAGEBANK)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_STORAGEBANK,m_syncDataPackageData.GetStorageBank());
}

//法宝数据
void SyncDataBagV1::SetTalismanData( const vector<BagTalismanObjWraperV1>& v )
{
	m_syncDataPackageData.SetTalismanData(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_TALISMANDATA);
	SendTalismanData(false);
}
void SyncDataBagV1::SetTalismanData( int Index, const BagTalismanObjWraperV1& v )
{
	m_syncDataPackageData.SetTalismanData(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_TALISMANDATA,Index);
	SendTalismanData(Index,false);
}
vector<BagTalismanObjWraperV1> SyncDataBagV1::GetTalismanData()
{
	return m_syncDataPackageData.GetTalismanData();
}
BagTalismanObjWraperV1 SyncDataBagV1::GetTalismanData( int Index )
{
	return m_syncDataPackageData.GetTalismanData(Index);
}
void SyncDataBagV1::SendTalismanData(bool OnlyToClient)
{
	SendTalismanData(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeTalismanData(); i++)
		SendTalismanData(i,OnlyToClient);
}
void SyncDataBagV1::SendTalismanData( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_TALISMANDATA,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_TALISMANDATA)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_TALISMANDATA,Index,NULL,0);
		return;
	}
	const string v= GetTalismanData(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_TALISMANDATA,Index,v.data(),v.size());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_TALISMANDATA)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_TALISMANDATA,Index,v.data(),v.size());
}
void SyncDataBagV1::AddTalismanData( const BagTalismanObjWraperV1& v )
{
	m_syncDataPackageData.AddTalismanData(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeTalismanData()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_TALISMANDATA,Index);
	SendTalismanData(Index,false);
}

//装备过的法宝，可获得永久属性加成
void SyncDataBagV1::SetTalismanForeverAttr( const vector<INT32>& v )
{
	m_syncDataPackageData.SetTalismanForeverAttr(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_TALISMANFOREVERATTR);
	SendTalismanForeverAttr(false);
}
void SyncDataBagV1::SetTalismanForeverAttr( int Index, const INT32& v )
{
	m_syncDataPackageData.SetTalismanForeverAttr(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_TALISMANFOREVERATTR,Index);
	SendTalismanForeverAttr(Index,false);
}
vector<INT32> SyncDataBagV1::GetTalismanForeverAttr()
{
	return m_syncDataPackageData.GetTalismanForeverAttr();
}
INT32 SyncDataBagV1::GetTalismanForeverAttr( int Index )
{
	return m_syncDataPackageData.GetTalismanForeverAttr(Index);
}
void SyncDataBagV1::SendTalismanForeverAttr(bool OnlyToClient)
{
	SendTalismanForeverAttr(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeTalismanForeverAttr(); i++)
		SendTalismanForeverAttr(i,OnlyToClient);
}
void SyncDataBagV1::SendTalismanForeverAttr( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_TALISMANFOREVERATTR,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_TALISMANFOREVERATTR)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_TALISMANFOREVERATTR,Index,NULL,0);
		return;
	}
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_TALISMANFOREVERATTR,Index,m_syncDataPackageData.GetTalismanForeverAttr(Index));
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_TALISMANFOREVERATTR)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_TALISMANFOREVERATTR,Index,m_syncDataPackageData.GetTalismanForeverAttr(Index));
}
void SyncDataBagV1::AddTalismanForeverAttr( INT32 v )
{
	m_syncDataPackageData.AddTalismanForeverAttr(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeTalismanForeverAttr()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_TALISMANFOREVERATTR,Index);
	SendTalismanForeverAttr(Index,false);
}

//自动拾取设置
void SyncDataBagV1::SetAutoPickup( const vector<KeyValue2IntBoolWraper>& v )
{
	m_syncDataPackageData.SetAutoPickup(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_AUTOPICKUP);
	SendAutoPickup(false);
}
void SyncDataBagV1::SetAutoPickup( int Index, const KeyValue2IntBoolWraper& v )
{
	m_syncDataPackageData.SetAutoPickup(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_AUTOPICKUP,Index);
	SendAutoPickup(Index,false);
}
vector<KeyValue2IntBoolWraper> SyncDataBagV1::GetAutoPickup()
{
	return m_syncDataPackageData.GetAutoPickup();
}
KeyValue2IntBoolWraper SyncDataBagV1::GetAutoPickup( int Index )
{
	return m_syncDataPackageData.GetAutoPickup(Index);
}
void SyncDataBagV1::SendAutoPickup(bool OnlyToClient)
{
	SendAutoPickup(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeAutoPickup(); i++)
		SendAutoPickup(i,OnlyToClient);
}
void SyncDataBagV1::SendAutoPickup( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_AUTOPICKUP,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_AUTOPICKUP)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_AUTOPICKUP,Index,NULL,0);
		return;
	}
	const string v= GetAutoPickup(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_AUTOPICKUP,Index,v.data(),v.size());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_AUTOPICKUP)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_AUTOPICKUP,Index,v.data(),v.size());
}
void SyncDataBagV1::AddAutoPickup( const KeyValue2IntBoolWraper& v )
{
	m_syncDataPackageData.AddAutoPickup(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeAutoPickup()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_AUTOPICKUP,Index);
	SendAutoPickup(Index,false);
}

//每天使用的道具
void SyncDataBagV1::SetUseItemDay( const vector<KeyValue2IntIntWraper>& v )
{
	m_syncDataPackageData.SetUseItemDay(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_USEITEMDAY);
	SendUseItemDay(false);
}
void SyncDataBagV1::SetUseItemDay( int Index, const KeyValue2IntIntWraper& v )
{
	m_syncDataPackageData.SetUseItemDay(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_USEITEMDAY,Index);
	SendUseItemDay(Index,false);
}
vector<KeyValue2IntIntWraper> SyncDataBagV1::GetUseItemDay()
{
	return m_syncDataPackageData.GetUseItemDay();
}
KeyValue2IntIntWraper SyncDataBagV1::GetUseItemDay( int Index )
{
	return m_syncDataPackageData.GetUseItemDay(Index);
}
void SyncDataBagV1::SendUseItemDay(bool OnlyToClient)
{
	SendUseItemDay(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeUseItemDay(); i++)
		SendUseItemDay(i,OnlyToClient);
}
void SyncDataBagV1::SendUseItemDay( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_USEITEMDAY,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_USEITEMDAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_USEITEMDAY,Index,NULL,0);
		return;
	}
	const string v= GetUseItemDay(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_USEITEMDAY,Index,v.data(),v.size());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_USEITEMDAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_USEITEMDAY,Index,v.data(),v.size());
}
void SyncDataBagV1::AddUseItemDay( const KeyValue2IntIntWraper& v )
{
	m_syncDataPackageData.AddUseItemDay(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeUseItemDay()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_USEITEMDAY,Index);
	SendUseItemDay(Index,false);
}

//每周使用的道具
void SyncDataBagV1::SetUseItemWeek( const vector<KeyValue2IntIntWraper>& v )
{
	m_syncDataPackageData.SetUseItemWeek(v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_USEITEMWEEK);
	SendUseItemWeek(false);
}
void SyncDataBagV1::SetUseItemWeek( int Index, const KeyValue2IntIntWraper& v )
{
	m_syncDataPackageData.SetUseItemWeek(Index,v);
	OnDataChange();
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_USEITEMWEEK,Index);
	SendUseItemWeek(Index,false);
}
vector<KeyValue2IntIntWraper> SyncDataBagV1::GetUseItemWeek()
{
	return m_syncDataPackageData.GetUseItemWeek();
}
KeyValue2IntIntWraper SyncDataBagV1::GetUseItemWeek( int Index )
{
	return m_syncDataPackageData.GetUseItemWeek(Index);
}
void SyncDataBagV1::SendUseItemWeek(bool OnlyToClient)
{
	SendUseItemWeek(-1,OnlyToClient);
	for(int i=0; i<m_syncDataPackageData.SizeUseItemWeek(); i++)
		SendUseItemWeek(i,OnlyToClient);
}
void SyncDataBagV1::SendUseItemWeek( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_USEITEMWEEK,Index,NULL,0);
		if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_USEITEMWEEK)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_USEITEMWEEK,Index,NULL,0);
		return;
	}
	const string v= GetUseItemWeek(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BAG_USEITEMWEEK,Index,v.data(),v.size());
	if(ModuleBag::Instance().NotSyncToClient(SYNCID_BAG_USEITEMWEEK)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BAG_USEITEMWEEK,Index,v.data(),v.size());
}
void SyncDataBagV1::AddUseItemWeek( const KeyValue2IntIntWraper& v )
{
	m_syncDataPackageData.AddUseItemWeek(v);
	OnDataChange();
	int Index = m_syncDataPackageData.SizeUseItemWeek()-1;
	ModuleBag::Instance().NotifySyncValueChanged(m_syncDataPackageData.GetKey(),SYNCID_BAG_USEITEMWEEK,Index);
	SendUseItemWeek(Index,false);
}
