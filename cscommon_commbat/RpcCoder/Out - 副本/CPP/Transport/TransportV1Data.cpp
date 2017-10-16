#include "TransportV1Data.h"
#include "TransportModule.h"


SyncDataTransportV1::SyncDataTransportV1()
{
	SetDataWraper( &m_syncDataGoodsData );
}

SyncDataTransportV1::~SyncDataTransportV1()
{
}

void SyncDataTransportV1::SendAllMembers(bool OnlyToClient)
{
	SendGoodsArray(OnlyToClient);
	SendAskNum(OnlyToClient);
	SendHelpNum(OnlyToClient);
	SendRewardArry(OnlyToClient);
	SendRewardFlag(OnlyToClient);
	SendPickTaskFlag(OnlyToClient);

}



//货物容器
void SyncDataTransportV1::SetGoodsArray( const vector<TransportGoodsObjWraperV1>& v )
{
	m_syncDataGoodsData.SetGoodsArray(v);
	OnDataChange();
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_GOODSARRAY);
	SendGoodsArray(false);
}
void SyncDataTransportV1::SetGoodsArray( int Index, const TransportGoodsObjWraperV1& v )
{
	m_syncDataGoodsData.SetGoodsArray(Index,v);
	OnDataChange();
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_GOODSARRAY,Index);
	SendGoodsArray(Index,false);
}
vector<TransportGoodsObjWraperV1> SyncDataTransportV1::GetGoodsArray()
{
	return m_syncDataGoodsData.GetGoodsArray();
}
TransportGoodsObjWraperV1 SyncDataTransportV1::GetGoodsArray( int Index )
{
	return m_syncDataGoodsData.GetGoodsArray(Index);
}
void SyncDataTransportV1::SendGoodsArray(bool OnlyToClient)
{
	SendGoodsArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataGoodsData.SizeGoodsArray(); i++)
		SendGoodsArray(i,OnlyToClient);
}
void SyncDataTransportV1::SendGoodsArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TRANSPORT_GOODSARRAY,Index,NULL,0);
		if(ModuleTransport::Instance().NotSyncToClient(SYNCID_TRANSPORT_GOODSARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TRANSPORT_GOODSARRAY,Index,NULL,0);
		return;
	}
	const string v= GetGoodsArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TRANSPORT_GOODSARRAY,Index,v.data(),v.size());
	if(ModuleTransport::Instance().NotSyncToClient(SYNCID_TRANSPORT_GOODSARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TRANSPORT_GOODSARRAY,Index,v.data(),v.size());
}
void SyncDataTransportV1::AddGoodsArray( const TransportGoodsObjWraperV1& v )
{
	m_syncDataGoodsData.AddGoodsArray(v);
	OnDataChange();
	int Index = m_syncDataGoodsData.SizeGoodsArray()-1;
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_GOODSARRAY,Index);
	SendGoodsArray(Index,false);
}

//请求数量
void SyncDataTransportV1::SetAskNum( const INT32& v )
{
	m_syncDataGoodsData.SetAskNum(v);
	OnDataChange();
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_ASKNUM);
	SendAskNum(false);
}
INT32 SyncDataTransportV1::GetAskNum()
{
	return m_syncDataGoodsData.GetAskNum();
}
void SyncDataTransportV1::SendAskNum(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TRANSPORT_ASKNUM,m_syncDataGoodsData.GetAskNum());
	if(ModuleTransport::Instance().NotSyncToClient(SYNCID_TRANSPORT_ASKNUM)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TRANSPORT_ASKNUM,m_syncDataGoodsData.GetAskNum());
}

//帮助次数
void SyncDataTransportV1::SetHelpNum( const INT32& v )
{
	m_syncDataGoodsData.SetHelpNum(v);
	OnDataChange();
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_HELPNUM);
	SendHelpNum(false);
}
INT32 SyncDataTransportV1::GetHelpNum()
{
	return m_syncDataGoodsData.GetHelpNum();
}
void SyncDataTransportV1::SendHelpNum(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TRANSPORT_HELPNUM,m_syncDataGoodsData.GetHelpNum());
	if(ModuleTransport::Instance().NotSyncToClient(SYNCID_TRANSPORT_HELPNUM)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TRANSPORT_HELPNUM,m_syncDataGoodsData.GetHelpNum());
}

//起航奖励
void SyncDataTransportV1::SetRewardArry( const vector<TransportRewardObjWraperV1>& v )
{
	m_syncDataGoodsData.SetRewardArry(v);
	OnDataChange();
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_REWARDARRY);
	SendRewardArry(false);
}
void SyncDataTransportV1::SetRewardArry( int Index, const TransportRewardObjWraperV1& v )
{
	m_syncDataGoodsData.SetRewardArry(Index,v);
	OnDataChange();
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_REWARDARRY,Index);
	SendRewardArry(Index,false);
}
vector<TransportRewardObjWraperV1> SyncDataTransportV1::GetRewardArry()
{
	return m_syncDataGoodsData.GetRewardArry();
}
TransportRewardObjWraperV1 SyncDataTransportV1::GetRewardArry( int Index )
{
	return m_syncDataGoodsData.GetRewardArry(Index);
}
void SyncDataTransportV1::SendRewardArry(bool OnlyToClient)
{
	SendRewardArry(-1,OnlyToClient);
	for(int i=0; i<m_syncDataGoodsData.SizeRewardArry(); i++)
		SendRewardArry(i,OnlyToClient);
}
void SyncDataTransportV1::SendRewardArry( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TRANSPORT_REWARDARRY,Index,NULL,0);
		if(ModuleTransport::Instance().NotSyncToClient(SYNCID_TRANSPORT_REWARDARRY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TRANSPORT_REWARDARRY,Index,NULL,0);
		return;
	}
	const string v= GetRewardArry(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TRANSPORT_REWARDARRY,Index,v.data(),v.size());
	if(ModuleTransport::Instance().NotSyncToClient(SYNCID_TRANSPORT_REWARDARRY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TRANSPORT_REWARDARRY,Index,v.data(),v.size());
}
void SyncDataTransportV1::AddRewardArry( const TransportRewardObjWraperV1& v )
{
	m_syncDataGoodsData.AddRewardArry(v);
	OnDataChange();
	int Index = m_syncDataGoodsData.SizeRewardArry()-1;
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_REWARDARRY,Index);
	SendRewardArry(Index,false);
}

//奖励是否领取标识
void SyncDataTransportV1::SetRewardFlag( const bool& v )
{
	m_syncDataGoodsData.SetRewardFlag(v);
	OnDataChange();
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_REWARDFLAG);
	SendRewardFlag(false);
}
bool SyncDataTransportV1::GetRewardFlag()
{
	return m_syncDataGoodsData.GetRewardFlag();
}
void SyncDataTransportV1::SendRewardFlag(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TRANSPORT_REWARDFLAG,m_syncDataGoodsData.GetRewardFlag());
	if(ModuleTransport::Instance().NotSyncToClient(SYNCID_TRANSPORT_REWARDFLAG)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TRANSPORT_REWARDFLAG,m_syncDataGoodsData.GetRewardFlag());
}

//是否接取任务
void SyncDataTransportV1::SetPickTaskFlag( const bool& v )
{
	m_syncDataGoodsData.SetPickTaskFlag(v);
	OnDataChange();
	ModuleTransport::Instance().NotifySyncValueChanged(m_syncDataGoodsData.GetKey(),SYNCID_TRANSPORT_PICKTASKFLAG);
	SendPickTaskFlag(false);
}
bool SyncDataTransportV1::GetPickTaskFlag()
{
	return m_syncDataGoodsData.GetPickTaskFlag();
}
void SyncDataTransportV1::SendPickTaskFlag(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TRANSPORT_PICKTASKFLAG,m_syncDataGoodsData.GetPickTaskFlag());
	if(ModuleTransport::Instance().NotSyncToClient(SYNCID_TRANSPORT_PICKTASKFLAG)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TRANSPORT_PICKTASKFLAG,m_syncDataGoodsData.GetPickTaskFlag());
}
