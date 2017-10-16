#include "ActivityPlayV1Data.h"
#include "ActivityPlayModule.h"


SyncDataActivityPlayV1::SyncDataActivityPlayV1()
{
	SetDataWraper( &m_syncDataActivityData );
}

SyncDataActivityPlayV1::~SyncDataActivityPlayV1()
{
}

void SyncDataActivityPlayV1::SendAllMembers(bool OnlyToClient)
{
	SendThiefData(OnlyToClient);
	SendSubdueMonsterData(OnlyToClient);
	SendWorldBossData(OnlyToClient);
	SendWorldBossRank(OnlyToClient);

}



//江洋大盗数据
void SyncDataActivityPlayV1::SetThiefData( const vector<ActivityNpcDataWraper>& v )
{
	m_syncDataActivityData.SetThiefData(v);
	OnDataChange();
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_THIEFDATA);
	SendThiefData(false);
}
void SyncDataActivityPlayV1::SetThiefData( int Index, const ActivityNpcDataWraper& v )
{
	m_syncDataActivityData.SetThiefData(Index,v);
	OnDataChange();
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_THIEFDATA,Index);
	SendThiefData(Index,false);
}
vector<ActivityNpcDataWraper> SyncDataActivityPlayV1::GetThiefData()
{
	return m_syncDataActivityData.GetThiefData();
}
ActivityNpcDataWraper SyncDataActivityPlayV1::GetThiefData( int Index )
{
	return m_syncDataActivityData.GetThiefData(Index);
}
void SyncDataActivityPlayV1::SendThiefData(bool OnlyToClient)
{
	SendThiefData(-1,OnlyToClient);
	for(int i=0; i<m_syncDataActivityData.SizeThiefData(); i++)
		SendThiefData(i,OnlyToClient);
}
void SyncDataActivityPlayV1::SendThiefData( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYPLAY_THIEFDATA,Index,NULL,0);
		return;
	}
	const string v= GetThiefData(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYPLAY_THIEFDATA,Index,v.data(),v.size());
}
void SyncDataActivityPlayV1::AddThiefData( const ActivityNpcDataWraper& v )
{
	m_syncDataActivityData.AddThiefData(v);
	OnDataChange();
	int Index = m_syncDataActivityData.SizeThiefData()-1;
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_THIEFDATA,Index);
	SendThiefData(Index,false);
}

//降妖除魔数据
void SyncDataActivityPlayV1::SetSubdueMonsterData( const vector<ActivityNpcDataWraper>& v )
{
	m_syncDataActivityData.SetSubdueMonsterData(v);
	OnDataChange();
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_SUBDUEMONSTERDATA);
	SendSubdueMonsterData(false);
}
void SyncDataActivityPlayV1::SetSubdueMonsterData( int Index, const ActivityNpcDataWraper& v )
{
	m_syncDataActivityData.SetSubdueMonsterData(Index,v);
	OnDataChange();
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_SUBDUEMONSTERDATA,Index);
	SendSubdueMonsterData(Index,false);
}
vector<ActivityNpcDataWraper> SyncDataActivityPlayV1::GetSubdueMonsterData()
{
	return m_syncDataActivityData.GetSubdueMonsterData();
}
ActivityNpcDataWraper SyncDataActivityPlayV1::GetSubdueMonsterData( int Index )
{
	return m_syncDataActivityData.GetSubdueMonsterData(Index);
}
void SyncDataActivityPlayV1::SendSubdueMonsterData(bool OnlyToClient)
{
	SendSubdueMonsterData(-1,OnlyToClient);
	for(int i=0; i<m_syncDataActivityData.SizeSubdueMonsterData(); i++)
		SendSubdueMonsterData(i,OnlyToClient);
}
void SyncDataActivityPlayV1::SendSubdueMonsterData( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYPLAY_SUBDUEMONSTERDATA,Index,NULL,0);
		return;
	}
	const string v= GetSubdueMonsterData(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYPLAY_SUBDUEMONSTERDATA,Index,v.data(),v.size());
}
void SyncDataActivityPlayV1::AddSubdueMonsterData( const ActivityNpcDataWraper& v )
{
	m_syncDataActivityData.AddSubdueMonsterData(v);
	OnDataChange();
	int Index = m_syncDataActivityData.SizeSubdueMonsterData()-1;
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_SUBDUEMONSTERDATA,Index);
	SendSubdueMonsterData(Index,false);
}

//世界Boss数据
void SyncDataActivityPlayV1::SetWorldBossData( const vector<WorldBossObjWraper>& v )
{
	m_syncDataActivityData.SetWorldBossData(v);
	OnDataChange();
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSDATA);
	SendWorldBossData(false);
}
void SyncDataActivityPlayV1::SetWorldBossData( int Index, const WorldBossObjWraper& v )
{
	m_syncDataActivityData.SetWorldBossData(Index,v);
	OnDataChange();
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSDATA,Index);
	SendWorldBossData(Index,false);
}
vector<WorldBossObjWraper> SyncDataActivityPlayV1::GetWorldBossData()
{
	return m_syncDataActivityData.GetWorldBossData();
}
WorldBossObjWraper SyncDataActivityPlayV1::GetWorldBossData( int Index )
{
	return m_syncDataActivityData.GetWorldBossData(Index);
}
void SyncDataActivityPlayV1::SendWorldBossData(bool OnlyToClient)
{
	SendWorldBossData(-1,OnlyToClient);
	for(int i=0; i<m_syncDataActivityData.SizeWorldBossData(); i++)
		SendWorldBossData(i,OnlyToClient);
}
void SyncDataActivityPlayV1::SendWorldBossData( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSDATA,Index,NULL,0);
		return;
	}
	const string v= GetWorldBossData(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSDATA,Index,v.data(),v.size());
}
void SyncDataActivityPlayV1::AddWorldBossData( const WorldBossObjWraper& v )
{
	m_syncDataActivityData.AddWorldBossData(v);
	OnDataChange();
	int Index = m_syncDataActivityData.SizeWorldBossData()-1;
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSDATA,Index);
	SendWorldBossData(Index,false);
}

//世界Boss排名
void SyncDataActivityPlayV1::SetWorldBossRank( const vector<WorldBossRankObjWraper>& v )
{
	m_syncDataActivityData.SetWorldBossRank(v);
	OnDataChange();
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSRANK);
	SendWorldBossRank(false);
}
void SyncDataActivityPlayV1::SetWorldBossRank( int Index, const WorldBossRankObjWraper& v )
{
	m_syncDataActivityData.SetWorldBossRank(Index,v);
	OnDataChange();
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSRANK,Index);
	SendWorldBossRank(Index,false);
}
vector<WorldBossRankObjWraper> SyncDataActivityPlayV1::GetWorldBossRank()
{
	return m_syncDataActivityData.GetWorldBossRank();
}
WorldBossRankObjWraper SyncDataActivityPlayV1::GetWorldBossRank( int Index )
{
	return m_syncDataActivityData.GetWorldBossRank(Index);
}
void SyncDataActivityPlayV1::SendWorldBossRank(bool OnlyToClient)
{
	SendWorldBossRank(-1,OnlyToClient);
	for(int i=0; i<m_syncDataActivityData.SizeWorldBossRank(); i++)
		SendWorldBossRank(i,OnlyToClient);
}
void SyncDataActivityPlayV1::SendWorldBossRank( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSRANK,Index,NULL,0);
		return;
	}
	const string v= GetWorldBossRank(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSRANK,Index,v.data(),v.size());
}
void SyncDataActivityPlayV1::AddWorldBossRank( const WorldBossRankObjWraper& v )
{
	m_syncDataActivityData.AddWorldBossRank(v);
	OnDataChange();
	int Index = m_syncDataActivityData.SizeWorldBossRank()-1;
	ModuleActivityPlay::Instance().NotifySyncValueChanged(m_syncDataActivityData.GetKey(),SYNCID_ACTIVITYPLAY_WORLDBOSSRANK,Index);
	SendWorldBossRank(Index,false);
}
