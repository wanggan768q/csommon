#include "TalismanV1Data.h"
#include "TalismanModule.h"


SyncDataTalismanV1::SyncDataTalismanV1()
{
	SetDataWraper( &m_syncDataDataFabao );
}

SyncDataTalismanV1::~SyncDataTalismanV1()
{
}

void SyncDataTalismanV1::SendAllMembers(bool OnlyToClient)
{
	SendFabaoArr(OnlyToClient);

}



//法宝列表
void SyncDataTalismanV1::SetFabaoArr( const vector<TalismanFabaoInfoWraperV1>& v )
{
	m_syncDataDataFabao.SetFabaoArr(v);
	OnDataChange();
	ModuleTalisman::Instance().NotifySyncValueChanged(m_syncDataDataFabao.GetKey(),SYNCID_TALISMAN_FABAOARR);
	SendFabaoArr(false);
}
void SyncDataTalismanV1::SetFabaoArr( int Index, const TalismanFabaoInfoWraperV1& v )
{
	m_syncDataDataFabao.SetFabaoArr(Index,v);
	OnDataChange();
	ModuleTalisman::Instance().NotifySyncValueChanged(m_syncDataDataFabao.GetKey(),SYNCID_TALISMAN_FABAOARR,Index);
	SendFabaoArr(Index,false);
}
vector<TalismanFabaoInfoWraperV1> SyncDataTalismanV1::GetFabaoArr()
{
	return m_syncDataDataFabao.GetFabaoArr();
}
TalismanFabaoInfoWraperV1 SyncDataTalismanV1::GetFabaoArr( int Index )
{
	return m_syncDataDataFabao.GetFabaoArr(Index);
}
void SyncDataTalismanV1::SendFabaoArr(bool OnlyToClient)
{
	SendFabaoArr(-1,OnlyToClient);
	for(int i=0; i<m_syncDataDataFabao.SizeFabaoArr(); i++)
		SendFabaoArr(i,OnlyToClient);
}
void SyncDataTalismanV1::SendFabaoArr( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TALISMAN_FABAOARR,Index,NULL,0);
		if(ModuleTalisman::Instance().NotSyncToClient(SYNCID_TALISMAN_FABAOARR)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TALISMAN_FABAOARR,Index,NULL,0);
		return;
	}
	const string v= GetFabaoArr(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TALISMAN_FABAOARR,Index,v.data(),v.size());
	if(ModuleTalisman::Instance().NotSyncToClient(SYNCID_TALISMAN_FABAOARR)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TALISMAN_FABAOARR,Index,v.data(),v.size());
}
void SyncDataTalismanV1::AddFabaoArr( const TalismanFabaoInfoWraperV1& v )
{
	m_syncDataDataFabao.AddFabaoArr(v);
	OnDataChange();
	int Index = m_syncDataDataFabao.SizeFabaoArr()-1;
	ModuleTalisman::Instance().NotifySyncValueChanged(m_syncDataDataFabao.GetKey(),SYNCID_TALISMAN_FABAOARR,Index);
	SendFabaoArr(Index,false);
}
