#include "DropItemV1Data.h"
#include "DropItemModule.h"


SyncDataDropItemV1::SyncDataDropItemV1()
{
	SetDataWraper( &m_syncDataDropItem );
}

SyncDataDropItemV1::~SyncDataDropItemV1()
{
}

void SyncDataDropItemV1::SendAllMembers(bool OnlyToClient)
{
	SendDropItem(OnlyToClient);
	SendEquipAllData(OnlyToClient);

}



//掉落的物品
void SyncDataDropItemV1::SetDropItem( const vector<DropItemObjWraper>& v )
{
	m_syncDataDropItem.SetDropItem(v);
	OnDataChange();
	ModuleDropItem::Instance().NotifySyncValueChanged(m_syncDataDropItem.GetKey(),SYNCID_DROPITEM_DROPITEM);
	SendDropItem(false);
}
void SyncDataDropItemV1::SetDropItem( int Index, const DropItemObjWraper& v )
{
	m_syncDataDropItem.SetDropItem(Index,v);
	OnDataChange();
	ModuleDropItem::Instance().NotifySyncValueChanged(m_syncDataDropItem.GetKey(),SYNCID_DROPITEM_DROPITEM,Index);
	SendDropItem(Index,false);
}
vector<DropItemObjWraper> SyncDataDropItemV1::GetDropItem()
{
	return m_syncDataDropItem.GetDropItem();
}
DropItemObjWraper SyncDataDropItemV1::GetDropItem( int Index )
{
	return m_syncDataDropItem.GetDropItem(Index);
}
void SyncDataDropItemV1::SendDropItem(bool OnlyToClient)
{
	SendDropItem(-1,OnlyToClient);
	for(int i=0; i<m_syncDataDropItem.SizeDropItem(); i++)
		SendDropItem(i,OnlyToClient);
}
void SyncDataDropItemV1::SendDropItem( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DROPITEM_DROPITEM,Index,NULL,0);
		return;
	}
	const string v= GetDropItem(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DROPITEM_DROPITEM,Index,v.data(),v.size());
}
void SyncDataDropItemV1::AddDropItem( const DropItemObjWraper& v )
{
	m_syncDataDropItem.AddDropItem(v);
	OnDataChange();
	int Index = m_syncDataDropItem.SizeDropItem()-1;
	ModuleDropItem::Instance().NotifySyncValueChanged(m_syncDataDropItem.GetKey(),SYNCID_DROPITEM_DROPITEM,Index);
	SendDropItem(Index,false);
}

//装备全部数据
void SyncDataDropItemV1::SetEquipAllData( const vector<BagEquipObjWraper>& v )
{
	m_syncDataDropItem.SetEquipAllData(v);
	OnDataChange();
	ModuleDropItem::Instance().NotifySyncValueChanged(m_syncDataDropItem.GetKey(),SYNCID_DROPITEM_EQUIPALLDATA);
	SendEquipAllData(false);
}
void SyncDataDropItemV1::SetEquipAllData( int Index, const BagEquipObjWraper& v )
{
	m_syncDataDropItem.SetEquipAllData(Index,v);
	OnDataChange();
	ModuleDropItem::Instance().NotifySyncValueChanged(m_syncDataDropItem.GetKey(),SYNCID_DROPITEM_EQUIPALLDATA,Index);
	SendEquipAllData(Index,false);
}
vector<BagEquipObjWraper> SyncDataDropItemV1::GetEquipAllData()
{
	return m_syncDataDropItem.GetEquipAllData();
}
BagEquipObjWraper SyncDataDropItemV1::GetEquipAllData( int Index )
{
	return m_syncDataDropItem.GetEquipAllData(Index);
}
void SyncDataDropItemV1::SendEquipAllData(bool OnlyToClient)
{
	SendEquipAllData(-1,OnlyToClient);
	for(int i=0; i<m_syncDataDropItem.SizeEquipAllData(); i++)
		SendEquipAllData(i,OnlyToClient);
}
void SyncDataDropItemV1::SendEquipAllData( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DROPITEM_EQUIPALLDATA,Index,NULL,0);
		return;
	}
	const string v= GetEquipAllData(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DROPITEM_EQUIPALLDATA,Index,v.data(),v.size());
}
void SyncDataDropItemV1::AddEquipAllData( const BagEquipObjWraper& v )
{
	m_syncDataDropItem.AddEquipAllData(v);
	OnDataChange();
	int Index = m_syncDataDropItem.SizeEquipAllData()-1;
	ModuleDropItem::Instance().NotifySyncValueChanged(m_syncDataDropItem.GetKey(),SYNCID_DROPITEM_EQUIPALLDATA,Index);
	SendEquipAllData(Index,false);
}
