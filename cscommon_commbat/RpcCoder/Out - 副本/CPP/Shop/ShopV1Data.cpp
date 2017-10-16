#include "ShopV1Data.h"
#include "ShopModule.h"


SyncDataShopV1::SyncDataShopV1()
{
	SetDataWraper( &m_syncDataShopData );
}

SyncDataShopV1::~SyncDataShopV1()
{
}

void SyncDataShopV1::SendAllMembers(bool OnlyToClient)
{
	SendShopArray(OnlyToClient);

}



//商店
void SyncDataShopV1::SetShopArray( const vector<ShopShopObjWraperV1>& v )
{
	m_syncDataShopData.SetShopArray(v);
	OnDataChange();
	ModuleShop::Instance().NotifySyncValueChanged(m_syncDataShopData.GetKey(),SYNCID_SHOP_SHOPARRAY);
	SendShopArray(false);
}
void SyncDataShopV1::SetShopArray( int Index, const ShopShopObjWraperV1& v )
{
	m_syncDataShopData.SetShopArray(Index,v);
	OnDataChange();
	ModuleShop::Instance().NotifySyncValueChanged(m_syncDataShopData.GetKey(),SYNCID_SHOP_SHOPARRAY,Index);
	SendShopArray(Index,false);
}
vector<ShopShopObjWraperV1> SyncDataShopV1::GetShopArray()
{
	return m_syncDataShopData.GetShopArray();
}
ShopShopObjWraperV1 SyncDataShopV1::GetShopArray( int Index )
{
	return m_syncDataShopData.GetShopArray(Index);
}
void SyncDataShopV1::SendShopArray(bool OnlyToClient)
{
	SendShopArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataShopData.SizeShopArray(); i++)
		SendShopArray(i,OnlyToClient);
}
void SyncDataShopV1::SendShopArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SHOP_SHOPARRAY,Index,NULL,0);
		if(ModuleShop::Instance().NotSyncToClient(SYNCID_SHOP_SHOPARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SHOP_SHOPARRAY,Index,NULL,0);
		return;
	}
	const string v= GetShopArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_SHOP_SHOPARRAY,Index,v.data(),v.size());
	if(ModuleShop::Instance().NotSyncToClient(SYNCID_SHOP_SHOPARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_SHOP_SHOPARRAY,Index,v.data(),v.size());
}
void SyncDataShopV1::AddShopArray( const ShopShopObjWraperV1& v )
{
	m_syncDataShopData.AddShopArray(v);
	OnDataChange();
	int Index = m_syncDataShopData.SizeShopArray()-1;
	ModuleShop::Instance().NotifySyncValueChanged(m_syncDataShopData.GetKey(),SYNCID_SHOP_SHOPARRAY,Index);
	SendShopArray(Index,false);
}
