#include "RefreshDataV1Data.h"
#include "RefreshDataModule.h"


SyncDataRefreshDataV1::SyncDataRefreshDataV1()
{
	SetDataWraper( &m_syncDataRefreshData );
}

SyncDataRefreshDataV1::~SyncDataRefreshDataV1()
{
}

void SyncDataRefreshDataV1::SendAllMembers(bool OnlyToClient)
{
	SendLastRefreshTime(OnlyToClient);

}



//上次刷新
void SyncDataRefreshDataV1::SetLastRefreshTime( const INT32& v )
{
	m_syncDataRefreshData.SetLastRefreshTime(v);
	OnDataChange();
	ModuleRefreshData::Instance().NotifySyncValueChanged(m_syncDataRefreshData.GetKey(),SYNCID_REFRESHDATA_LASTREFRESHTIME);
	SendLastRefreshTime(false);
}
INT32 SyncDataRefreshDataV1::GetLastRefreshTime()
{
	return m_syncDataRefreshData.GetLastRefreshTime();
}
void SyncDataRefreshDataV1::SendLastRefreshTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_REFRESHDATA_LASTREFRESHTIME,m_syncDataRefreshData.GetLastRefreshTime());
	if(ModuleRefreshData::Instance().NotSyncToClient(SYNCID_REFRESHDATA_LASTREFRESHTIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_REFRESHDATA_LASTREFRESHTIME,m_syncDataRefreshData.GetLastRefreshTime());
}
