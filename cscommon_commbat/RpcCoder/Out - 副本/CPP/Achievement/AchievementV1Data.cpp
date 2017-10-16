#include "AchievementV1Data.h"
#include "AchievementModule.h"


SyncDataAchievementV1::SyncDataAchievementV1()
{
	SetDataWraper( &m_syncDataAchiData );
}

SyncDataAchievementV1::~SyncDataAchievementV1()
{
}

void SyncDataAchievementV1::SendAllMembers(bool OnlyToClient)
{
	SendAchiData(OnlyToClient);

}



//成就数据
void SyncDataAchievementV1::SetAchiData( const vector<AchievementAchiObjWraperV1>& v )
{
	m_syncDataAchiData.SetAchiData(v);
	OnDataChange();
	ModuleAchievement::Instance().NotifySyncValueChanged(m_syncDataAchiData.GetKey(),SYNCID_ACHIEVEMENT_ACHIDATA);
	SendAchiData(false);
}
void SyncDataAchievementV1::SetAchiData( int Index, const AchievementAchiObjWraperV1& v )
{
	m_syncDataAchiData.SetAchiData(Index,v);
	OnDataChange();
	ModuleAchievement::Instance().NotifySyncValueChanged(m_syncDataAchiData.GetKey(),SYNCID_ACHIEVEMENT_ACHIDATA,Index);
	SendAchiData(Index,false);
}
vector<AchievementAchiObjWraperV1> SyncDataAchievementV1::GetAchiData()
{
	return m_syncDataAchiData.GetAchiData();
}
AchievementAchiObjWraperV1 SyncDataAchievementV1::GetAchiData( int Index )
{
	return m_syncDataAchiData.GetAchiData(Index);
}
void SyncDataAchievementV1::SendAchiData(bool OnlyToClient)
{
	SendAchiData(-1,OnlyToClient);
	for(int i=0; i<m_syncDataAchiData.SizeAchiData(); i++)
		SendAchiData(i,OnlyToClient);
}
void SyncDataAchievementV1::SendAchiData( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACHIEVEMENT_ACHIDATA,Index,NULL,0);
		if(ModuleAchievement::Instance().NotSyncToClient(SYNCID_ACHIEVEMENT_ACHIDATA)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ACHIEVEMENT_ACHIDATA,Index,NULL,0);
		return;
	}
	const string v= GetAchiData(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACHIEVEMENT_ACHIDATA,Index,v.data(),v.size());
	if(ModuleAchievement::Instance().NotSyncToClient(SYNCID_ACHIEVEMENT_ACHIDATA)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ACHIEVEMENT_ACHIDATA,Index,v.data(),v.size());
}
void SyncDataAchievementV1::AddAchiData( const AchievementAchiObjWraperV1& v )
{
	m_syncDataAchiData.AddAchiData(v);
	OnDataChange();
	int Index = m_syncDataAchiData.SizeAchiData()-1;
	ModuleAchievement::Instance().NotifySyncValueChanged(m_syncDataAchiData.GetKey(),SYNCID_ACHIEVEMENT_ACHIDATA,Index);
	SendAchiData(Index,false);
}
