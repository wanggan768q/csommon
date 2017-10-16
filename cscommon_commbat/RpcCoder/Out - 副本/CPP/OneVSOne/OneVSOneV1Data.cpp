#include "OneVSOneV1Data.h"
#include "OneVSOneModule.h"


SyncDataOneVSOneV1::SyncDataOneVSOneV1()
{
	SetDataWraper( &m_syncDataOneVSOneDate );
}

SyncDataOneVSOneV1::~SyncDataOneVSOneV1()
{
}

void SyncDataOneVSOneV1::SendAllMembers(bool OnlyToClient)
{
	SendSkillDate(OnlyToClient);
	SendLog(OnlyToClient);
	SendOneVSOneNum(OnlyToClient);
	SendSaveTime(OnlyToClient);
	SendRanking(OnlyToClient);
	SendRankingTimes(OnlyToClient);

}



//技能数据
void SyncDataOneVSOneV1::SetSkillDate( const vector<OneSDataWraper>& v )
{
	m_syncDataOneVSOneDate.SetSkillDate(v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_SKILLDATE);
	SendSkillDate(false);
}
void SyncDataOneVSOneV1::SetSkillDate( int Index, const OneSDataWraper& v )
{
	m_syncDataOneVSOneDate.SetSkillDate(Index,v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_SKILLDATE,Index);
	SendSkillDate(Index,false);
}
vector<OneSDataWraper> SyncDataOneVSOneV1::GetSkillDate()
{
	return m_syncDataOneVSOneDate.GetSkillDate();
}
OneSDataWraper SyncDataOneVSOneV1::GetSkillDate( int Index )
{
	return m_syncDataOneVSOneDate.GetSkillDate(Index);
}
void SyncDataOneVSOneV1::SendSkillDate(bool OnlyToClient)
{
	SendSkillDate(-1,OnlyToClient);
	for(int i=0; i<m_syncDataOneVSOneDate.SizeSkillDate(); i++)
		SendSkillDate(i,OnlyToClient);
}
void SyncDataOneVSOneV1::SendSkillDate( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_SKILLDATE,Index,NULL,0);
		return;
	}
	const string v= GetSkillDate(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_SKILLDATE,Index,v.data(),v.size());
}
void SyncDataOneVSOneV1::AddSkillDate( const OneSDataWraper& v )
{
	m_syncDataOneVSOneDate.AddSkillDate(v);
	OnDataChange();
	int Index = m_syncDataOneVSOneDate.SizeSkillDate()-1;
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_SKILLDATE,Index);
	SendSkillDate(Index,false);
}

//log日志
void SyncDataOneVSOneV1::SetLog( const vector<ActMessageWraper>& v )
{
	m_syncDataOneVSOneDate.SetLog(v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_LOG);
	SendLog(false);
}
void SyncDataOneVSOneV1::SetLog( int Index, const ActMessageWraper& v )
{
	m_syncDataOneVSOneDate.SetLog(Index,v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_LOG,Index);
	SendLog(Index,false);
}
vector<ActMessageWraper> SyncDataOneVSOneV1::GetLog()
{
	return m_syncDataOneVSOneDate.GetLog();
}
ActMessageWraper SyncDataOneVSOneV1::GetLog( int Index )
{
	return m_syncDataOneVSOneDate.GetLog(Index);
}
void SyncDataOneVSOneV1::SendLog(bool OnlyToClient)
{
	SendLog(-1,OnlyToClient);
	for(int i=0; i<m_syncDataOneVSOneDate.SizeLog(); i++)
		SendLog(i,OnlyToClient);
}
void SyncDataOneVSOneV1::SendLog( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_LOG,Index,NULL,0);
		return;
	}
	const string v= GetLog(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_LOG,Index,v.data(),v.size());
}
void SyncDataOneVSOneV1::AddLog( const ActMessageWraper& v )
{
	m_syncDataOneVSOneDate.AddLog(v);
	OnDataChange();
	int Index = m_syncDataOneVSOneDate.SizeLog()-1;
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_LOG,Index);
	SendLog(Index,false);
}

//一对一的剩余次数
void SyncDataOneVSOneV1::SetOneVSOneNum( const INT32& v )
{
	m_syncDataOneVSOneDate.SetOneVSOneNum(v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_ONEVSONENUM);
	SendOneVSOneNum(false);
}
INT32 SyncDataOneVSOneV1::GetOneVSOneNum()
{
	return m_syncDataOneVSOneDate.GetOneVSOneNum();
}
void SyncDataOneVSOneV1::SendOneVSOneNum(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_ONEVSONENUM,m_syncDataOneVSOneDate.GetOneVSOneNum());
}

//格林威治时间服务器用
void SyncDataOneVSOneV1::SetSaveTime( const INT64& v )
{
	m_syncDataOneVSOneDate.SetSaveTime(v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_SAVETIME);
	SendSaveTime(false);
}
INT64 SyncDataOneVSOneV1::GetSaveTime()
{
	return m_syncDataOneVSOneDate.GetSaveTime();
}
void SyncDataOneVSOneV1::SendSaveTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_SAVETIME,m_syncDataOneVSOneDate.GetSaveTime());
}

//排行名次
void SyncDataOneVSOneV1::SetRanking( const INT32& v )
{
	m_syncDataOneVSOneDate.SetRanking(v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_RANKING);
	SendRanking(false);
}
INT32 SyncDataOneVSOneV1::GetRanking()
{
	return m_syncDataOneVSOneDate.GetRanking();
}
void SyncDataOneVSOneV1::SendRanking(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_RANKING,m_syncDataOneVSOneDate.GetRanking());
}

//排行名次 时间段的
void SyncDataOneVSOneV1::SetRankingTimes( const vector<TimeTopWraper>& v )
{
	m_syncDataOneVSOneDate.SetRankingTimes(v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_RANKINGTIMES);
	SendRankingTimes(false);
}
void SyncDataOneVSOneV1::SetRankingTimes( int Index, const TimeTopWraper& v )
{
	m_syncDataOneVSOneDate.SetRankingTimes(Index,v);
	OnDataChange();
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_RANKINGTIMES,Index);
	SendRankingTimes(Index,false);
}
vector<TimeTopWraper> SyncDataOneVSOneV1::GetRankingTimes()
{
	return m_syncDataOneVSOneDate.GetRankingTimes();
}
TimeTopWraper SyncDataOneVSOneV1::GetRankingTimes( int Index )
{
	return m_syncDataOneVSOneDate.GetRankingTimes(Index);
}
void SyncDataOneVSOneV1::SendRankingTimes(bool OnlyToClient)
{
	SendRankingTimes(-1,OnlyToClient);
	for(int i=0; i<m_syncDataOneVSOneDate.SizeRankingTimes(); i++)
		SendRankingTimes(i,OnlyToClient);
}
void SyncDataOneVSOneV1::SendRankingTimes( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_RANKINGTIMES,Index,NULL,0);
		return;
	}
	const string v= GetRankingTimes(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONE_RANKINGTIMES,Index,v.data(),v.size());
}
void SyncDataOneVSOneV1::AddRankingTimes( const TimeTopWraper& v )
{
	m_syncDataOneVSOneDate.AddRankingTimes(v);
	OnDataChange();
	int Index = m_syncDataOneVSOneDate.SizeRankingTimes()-1;
	ModuleOneVSOne::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONE_RANKINGTIMES,Index);
	SendRankingTimes(Index,false);
}
