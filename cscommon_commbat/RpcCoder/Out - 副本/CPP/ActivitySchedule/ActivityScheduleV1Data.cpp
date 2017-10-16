#include "ActivityScheduleV1Data.h"
#include "ActivityScheduleModule.h"


SyncDataActivityScheduleV1::SyncDataActivityScheduleV1()
{
	SetDataWraper( &m_syncDataActiveDate );
}

SyncDataActivityScheduleV1::~SyncDataActivityScheduleV1()
{
}

void SyncDataActivityScheduleV1::SendAllMembers(bool OnlyToClient)
{
	SendValue(OnlyToClient);
	SendTime(OnlyToClient);

}



//数据
void SyncDataActivityScheduleV1::SetValue( const vector<ActivityScheduleActiveValueWraperV1>& v )
{
	m_syncDataActiveDate.SetValue(v);
	OnDataChange();
	ModuleActivitySchedule::Instance().NotifySyncValueChanged(m_syncDataActiveDate.GetKey(),SYNCID_ACTIVITYSCHEDULE_VALUE);
	SendValue(false);
}
void SyncDataActivityScheduleV1::SetValue( int Index, const ActivityScheduleActiveValueWraperV1& v )
{
	m_syncDataActiveDate.SetValue(Index,v);
	OnDataChange();
	ModuleActivitySchedule::Instance().NotifySyncValueChanged(m_syncDataActiveDate.GetKey(),SYNCID_ACTIVITYSCHEDULE_VALUE,Index);
	SendValue(Index,false);
}
vector<ActivityScheduleActiveValueWraperV1> SyncDataActivityScheduleV1::GetValue()
{
	return m_syncDataActiveDate.GetValue();
}
ActivityScheduleActiveValueWraperV1 SyncDataActivityScheduleV1::GetValue( int Index )
{
	return m_syncDataActiveDate.GetValue(Index);
}
void SyncDataActivityScheduleV1::SendValue(bool OnlyToClient)
{
	SendValue(-1,OnlyToClient);
	for(int i=0; i<m_syncDataActiveDate.SizeValue(); i++)
		SendValue(i,OnlyToClient);
}
void SyncDataActivityScheduleV1::SendValue( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYSCHEDULE_VALUE,Index,NULL,0);
		if(ModuleActivitySchedule::Instance().NotSyncToClient(SYNCID_ACTIVITYSCHEDULE_VALUE)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ACTIVITYSCHEDULE_VALUE,Index,NULL,0);
		return;
	}
	const string v= GetValue(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYSCHEDULE_VALUE,Index,v.data(),v.size());
	if(ModuleActivitySchedule::Instance().NotSyncToClient(SYNCID_ACTIVITYSCHEDULE_VALUE)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ACTIVITYSCHEDULE_VALUE,Index,v.data(),v.size());
}
void SyncDataActivityScheduleV1::AddValue( const ActivityScheduleActiveValueWraperV1& v )
{
	m_syncDataActiveDate.AddValue(v);
	OnDataChange();
	int Index = m_syncDataActiveDate.SizeValue()-1;
	ModuleActivitySchedule::Instance().NotifySyncValueChanged(m_syncDataActiveDate.GetKey(),SYNCID_ACTIVITYSCHEDULE_VALUE,Index);
	SendValue(Index,false);
}

//时间（服务器专用）
void SyncDataActivityScheduleV1::SetTime( const INT32& v )
{
	m_syncDataActiveDate.SetTime(v);
	OnDataChange();
	ModuleActivitySchedule::Instance().NotifySyncValueChanged(m_syncDataActiveDate.GetKey(),SYNCID_ACTIVITYSCHEDULE_TIME);
	SendTime(false);
}
INT32 SyncDataActivityScheduleV1::GetTime()
{
	return m_syncDataActiveDate.GetTime();
}
void SyncDataActivityScheduleV1::SendTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYSCHEDULE_TIME,m_syncDataActiveDate.GetTime());
	if(ModuleActivitySchedule::Instance().NotSyncToClient(SYNCID_ACTIVITYSCHEDULE_TIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ACTIVITYSCHEDULE_TIME,m_syncDataActiveDate.GetTime());
}
