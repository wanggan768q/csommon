#include "TeamV1Data.h"
#include "TeamModule.h"


SyncDataTeamV1::SyncDataTeamV1()
{
	SetDataWraper( &m_syncDataTeamData );
}

SyncDataTeamV1::~SyncDataTeamV1()
{
}

void SyncDataTeamV1::SendAllMembers(bool OnlyToClient)
{
	SendTeamData(OnlyToClient);
	SendApplyList(OnlyToClient);

}



//组队数据
void SyncDataTeamV1::SetTeamData( const TeamObjWraper& v )
{
	m_syncDataTeamData.SetTeamData(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataTeamData.GetKey(),SYNCID_TEAM_TEAMDATA);
	SendTeamData(false);
}
TeamObjWraper SyncDataTeamV1::GetTeamData()
{
	return m_syncDataTeamData.GetTeamData();
}
void SyncDataTeamV1::SendTeamData(bool OnlyToClient)
{
	const string v=m_syncDataTeamData.GetTeamData().SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_TEAMDATA,v.data(),v.size());
}

//申请列表
void SyncDataTeamV1::SetApplyList( const vector<TeamApplyUserObjWraper>& v )
{
	m_syncDataTeamData.SetApplyList(v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataTeamData.GetKey(),SYNCID_TEAM_APPLYLIST);
	SendApplyList(false);
}
void SyncDataTeamV1::SetApplyList( int Index, const TeamApplyUserObjWraper& v )
{
	m_syncDataTeamData.SetApplyList(Index,v);
	OnDataChange();
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataTeamData.GetKey(),SYNCID_TEAM_APPLYLIST,Index);
	SendApplyList(Index,false);
}
vector<TeamApplyUserObjWraper> SyncDataTeamV1::GetApplyList()
{
	return m_syncDataTeamData.GetApplyList();
}
TeamApplyUserObjWraper SyncDataTeamV1::GetApplyList( int Index )
{
	return m_syncDataTeamData.GetApplyList(Index);
}
void SyncDataTeamV1::SendApplyList(bool OnlyToClient)
{
	SendApplyList(-1,OnlyToClient);
	for(int i=0; i<m_syncDataTeamData.SizeApplyList(); i++)
		SendApplyList(i,OnlyToClient);
}
void SyncDataTeamV1::SendApplyList( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_APPLYLIST,Index,NULL,0);
		return;
	}
	const string v= GetApplyList(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TEAM_APPLYLIST,Index,v.data(),v.size());
}
void SyncDataTeamV1::AddApplyList( const TeamApplyUserObjWraper& v )
{
	m_syncDataTeamData.AddApplyList(v);
	OnDataChange();
	int Index = m_syncDataTeamData.SizeApplyList()-1;
	ModuleTeam::Instance().NotifySyncValueChanged(m_syncDataTeamData.GetKey(),SYNCID_TEAM_APPLYLIST,Index);
	SendApplyList(Index,false);
}
