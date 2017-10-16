#include "ActivityStormV1Data.h"
#include "ActivityStormModule.h"


SyncDataActivityStormV1::SyncDataActivityStormV1()
{
	SetDataWraper( &m_syncDataActivityStorm );
}

SyncDataActivityStormV1::~SyncDataActivityStormV1()
{
}

void SyncDataActivityStormV1::SendAllMembers(bool OnlyToClient)
{
	SendType(OnlyToClient);
	SendTime(OnlyToClient);
	SendActID(OnlyToClient);
	SendLvD(OnlyToClient);

}



//类型
void SyncDataActivityStormV1::SetType( const INT32& v )
{
	m_syncDataActivityStorm.SetType(v);
	OnDataChange();
	ModuleActivityStorm::Instance().NotifySyncValueChanged(m_syncDataActivityStorm.GetKey(),SYNCID_ACTIVITYSTORM_TYPE);
	SendType(false);
}
INT32 SyncDataActivityStormV1::GetType()
{
	return m_syncDataActivityStorm.GetType();
}
void SyncDataActivityStormV1::SendType(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYSTORM_TYPE,m_syncDataActivityStorm.GetType());
}

//倒计时时间
void SyncDataActivityStormV1::SetTime( const INT32& v )
{
	m_syncDataActivityStorm.SetTime(v);
	OnDataChange();
	ModuleActivityStorm::Instance().NotifySyncValueChanged(m_syncDataActivityStorm.GetKey(),SYNCID_ACTIVITYSTORM_TIME);
	SendTime(false);
}
INT32 SyncDataActivityStormV1::GetTime()
{
	return m_syncDataActivityStorm.GetTime();
}
void SyncDataActivityStormV1::SendTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYSTORM_TIME,m_syncDataActivityStorm.GetTime());
}

//战斗id 需要确认时候带回
void SyncDataActivityStormV1::SetActID( const INT32& v )
{
	m_syncDataActivityStorm.SetActID(v);
	OnDataChange();
	ModuleActivityStorm::Instance().NotifySyncValueChanged(m_syncDataActivityStorm.GetKey(),SYNCID_ACTIVITYSTORM_ACTID);
	SendActID(false);
}
INT32 SyncDataActivityStormV1::GetActID()
{
	return m_syncDataActivityStorm.GetActID();
}
void SyncDataActivityStormV1::SendActID(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYSTORM_ACTID,m_syncDataActivityStorm.GetActID());
}

//等级段
void SyncDataActivityStormV1::SetLvD( const INT32& v )
{
	m_syncDataActivityStorm.SetLvD(v);
	OnDataChange();
	ModuleActivityStorm::Instance().NotifySyncValueChanged(m_syncDataActivityStorm.GetKey(),SYNCID_ACTIVITYSTORM_LVD);
	SendLvD(false);
}
INT32 SyncDataActivityStormV1::GetLvD()
{
	return m_syncDataActivityStorm.GetLvD();
}
void SyncDataActivityStormV1::SendLvD(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ACTIVITYSTORM_LVD,m_syncDataActivityStorm.GetLvD());
}
