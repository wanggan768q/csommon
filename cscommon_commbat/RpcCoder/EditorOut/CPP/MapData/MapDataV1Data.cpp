#include "MapDataV1Data.h"
#include "MapDataModule.h"


SyncDataMapDataV1::SyncDataMapDataV1()
{
	SetDataWraper( &m_syncDataUseless );
}

SyncDataMapDataV1::~SyncDataMapDataV1()
{
}

void SyncDataMapDataV1::SendAllMembers(bool OnlyToClient)
{
	SendX1(OnlyToClient);

}



//X1
void SyncDataMapDataV1::SetX1( const INT32& v )
{
	m_syncDataUseless.SetX1(v);
	OnDataChange();
	ModuleMapData::Instance().NotifySyncValueChanged(m_syncDataUseless.GetKey(),SYNCID_MAPDATA_X1);
	SendX1(false);
}
INT32 SyncDataMapDataV1::GetX1()
{
	return m_syncDataUseless.GetX1();
}
void SyncDataMapDataV1::SendX1(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_MAPDATA_X1,m_syncDataUseless.GetX1());
	if(ModuleMapData::Instance().NotSyncToClient(SYNCID_MAPDATA_X1)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_MAPDATA_X1,m_syncDataUseless.GetX1());
}
