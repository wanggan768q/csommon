#include "OneVSOneTopV1Data.h"
#include "OneVSOneTopModule.h"


SyncDataOneVSOneTopV1::SyncDataOneVSOneTopV1()
{
	SetDataWraper( &m_syncDataOneVSOneDate );
}

SyncDataOneVSOneTopV1::~SyncDataOneVSOneTopV1()
{
}

void SyncDataOneVSOneTopV1::SendAllMembers(bool OnlyToClient)
{
	SendTopMesses(OnlyToClient);
	SendTime(OnlyToClient);

}



//排行榜数据
void SyncDataOneVSOneTopV1::SetTopMesses( const vector<TopMessWraper>& v )
{
	m_syncDataOneVSOneDate.SetTopMesses(v);
	OnDataChange();
	ModuleOneVSOneTop::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONETOP_TOPMESSES);
	SendTopMesses(false);
}
void SyncDataOneVSOneTopV1::SetTopMesses( int Index, const TopMessWraper& v )
{
	m_syncDataOneVSOneDate.SetTopMesses(Index,v);
	OnDataChange();
	ModuleOneVSOneTop::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONETOP_TOPMESSES,Index);
	SendTopMesses(Index,false);
}
vector<TopMessWraper> SyncDataOneVSOneTopV1::GetTopMesses()
{
	return m_syncDataOneVSOneDate.GetTopMesses();
}
TopMessWraper SyncDataOneVSOneTopV1::GetTopMesses( int Index )
{
	return m_syncDataOneVSOneDate.GetTopMesses(Index);
}
void SyncDataOneVSOneTopV1::SendTopMesses(bool OnlyToClient)
{
	SendTopMesses(-1,OnlyToClient);
	for(int i=0; i<m_syncDataOneVSOneDate.SizeTopMesses(); i++)
		SendTopMesses(i,OnlyToClient);
}
void SyncDataOneVSOneTopV1::SendTopMesses( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONETOP_TOPMESSES,Index,NULL,0);
		return;
	}
	const string v= GetTopMesses(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONETOP_TOPMESSES,Index,v.data(),v.size());
}
void SyncDataOneVSOneTopV1::AddTopMesses( const TopMessWraper& v )
{
	m_syncDataOneVSOneDate.AddTopMesses(v);
	OnDataChange();
	int Index = m_syncDataOneVSOneDate.SizeTopMesses()-1;
	ModuleOneVSOneTop::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONETOP_TOPMESSES,Index);
	SendTopMesses(Index,false);
}

//格林时间
void SyncDataOneVSOneTopV1::SetTime( const INT64& v )
{
	m_syncDataOneVSOneDate.SetTime(v);
	OnDataChange();
	ModuleOneVSOneTop::Instance().NotifySyncValueChanged(m_syncDataOneVSOneDate.GetKey(),SYNCID_ONEVSONETOP_TIME);
	SendTime(false);
}
INT64 SyncDataOneVSOneTopV1::GetTime()
{
	return m_syncDataOneVSOneDate.GetTime();
}
void SyncDataOneVSOneTopV1::SendTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONEVSONETOP_TIME,m_syncDataOneVSOneDate.GetTime());
}
