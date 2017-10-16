#include "OnlineDataV1Data.h"
#include "OnlineDataModule.h"


SyncDataOnlineDataV1::SyncDataOnlineDataV1()
{
	SetDataWraper( &m_syncDataOnlineData );
}

SyncDataOnlineDataV1::~SyncDataOnlineDataV1()
{
}

void SyncDataOnlineDataV1::SendAllMembers(bool OnlyToClient)
{
	SendBagRecycleBin(OnlyToClient);
	SendRoleAttr(OnlyToClient);
	SendRecommendFriendOffset(OnlyToClient);
	SendRecommendFriendFlushTime(OnlyToClient);
	SendRecommendFriendLastList(OnlyToClient);
	SendFollowmeUserId(OnlyToClient);
	SendFollowWho(OnlyToClient);
	SendThiefObjId(OnlyToClient);

}



//回收站
void SyncDataOnlineDataV1::SetBagRecycleBin( const vector<BagRecycleGridObjWraper>& v )
{
	m_syncDataOnlineData.SetBagRecycleBin(v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_BAGRECYCLEBIN);
	SendBagRecycleBin(false);
}
void SyncDataOnlineDataV1::SetBagRecycleBin( int Index, const BagRecycleGridObjWraper& v )
{
	m_syncDataOnlineData.SetBagRecycleBin(Index,v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_BAGRECYCLEBIN,Index);
	SendBagRecycleBin(Index,false);
}
vector<BagRecycleGridObjWraper> SyncDataOnlineDataV1::GetBagRecycleBin()
{
	return m_syncDataOnlineData.GetBagRecycleBin();
}
BagRecycleGridObjWraper SyncDataOnlineDataV1::GetBagRecycleBin( int Index )
{
	return m_syncDataOnlineData.GetBagRecycleBin(Index);
}
void SyncDataOnlineDataV1::SendBagRecycleBin(bool OnlyToClient)
{
	SendBagRecycleBin(-1,OnlyToClient);
	for(int i=0; i<m_syncDataOnlineData.SizeBagRecycleBin(); i++)
		SendBagRecycleBin(i,OnlyToClient);
}
void SyncDataOnlineDataV1::SendBagRecycleBin( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_BAGRECYCLEBIN,Index,NULL,0);
		if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_BAGRECYCLEBIN)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_BAGRECYCLEBIN,Index,NULL,0);
		return;
	}
	const string v= GetBagRecycleBin(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_BAGRECYCLEBIN,Index,v.data(),v.size());
	if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_BAGRECYCLEBIN)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_BAGRECYCLEBIN,Index,v.data(),v.size());
}
void SyncDataOnlineDataV1::AddBagRecycleBin( const BagRecycleGridObjWraper& v )
{
	m_syncDataOnlineData.AddBagRecycleBin(v);
	OnDataChange();
	int Index = m_syncDataOnlineData.SizeBagRecycleBin()-1;
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_BAGRECYCLEBIN,Index);
	SendBagRecycleBin(Index,false);
}

//角色属性
void SyncDataOnlineDataV1::SetRoleAttr( const vector<OnlineDataRoleAttrObjWraperV1>& v )
{
	m_syncDataOnlineData.SetRoleAttr(v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_ROLEATTR);
	SendRoleAttr(false);
}
void SyncDataOnlineDataV1::SetRoleAttr( int Index, const OnlineDataRoleAttrObjWraperV1& v )
{
	m_syncDataOnlineData.SetRoleAttr(Index,v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_ROLEATTR,Index);
	SendRoleAttr(Index,false);
}
vector<OnlineDataRoleAttrObjWraperV1> SyncDataOnlineDataV1::GetRoleAttr()
{
	return m_syncDataOnlineData.GetRoleAttr();
}
OnlineDataRoleAttrObjWraperV1 SyncDataOnlineDataV1::GetRoleAttr( int Index )
{
	return m_syncDataOnlineData.GetRoleAttr(Index);
}
void SyncDataOnlineDataV1::SendRoleAttr(bool OnlyToClient)
{
	SendRoleAttr(-1,OnlyToClient);
	for(int i=0; i<m_syncDataOnlineData.SizeRoleAttr(); i++)
		SendRoleAttr(i,OnlyToClient);
}
void SyncDataOnlineDataV1::SendRoleAttr( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_ROLEATTR,Index,NULL,0);
		if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_ROLEATTR)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_ROLEATTR,Index,NULL,0);
		return;
	}
	const string v= GetRoleAttr(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_ROLEATTR,Index,v.data(),v.size());
	if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_ROLEATTR)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_ROLEATTR,Index,v.data(),v.size());
}
void SyncDataOnlineDataV1::AddRoleAttr( const OnlineDataRoleAttrObjWraperV1& v )
{
	m_syncDataOnlineData.AddRoleAttr(v);
	OnDataChange();
	int Index = m_syncDataOnlineData.SizeRoleAttr()-1;
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_ROLEATTR,Index);
	SendRoleAttr(Index,false);
}

//推荐好友偏移
void SyncDataOnlineDataV1::SetRecommendFriendOffset( const INT32& v )
{
	m_syncDataOnlineData.SetRecommendFriendOffset(v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDOFFSET);
	SendRecommendFriendOffset(false);
}
INT32 SyncDataOnlineDataV1::GetRecommendFriendOffset()
{
	return m_syncDataOnlineData.GetRecommendFriendOffset();
}
void SyncDataOnlineDataV1::SendRecommendFriendOffset(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDOFFSET,m_syncDataOnlineData.GetRecommendFriendOffset());
	if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_RECOMMENDFRIENDOFFSET)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDOFFSET,m_syncDataOnlineData.GetRecommendFriendOffset());
}

//推荐好友刷新时间
void SyncDataOnlineDataV1::SetRecommendFriendFlushTime( const INT32& v )
{
	m_syncDataOnlineData.SetRecommendFriendFlushTime(v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDFLUSHTIME);
	SendRecommendFriendFlushTime(false);
}
INT32 SyncDataOnlineDataV1::GetRecommendFriendFlushTime()
{
	return m_syncDataOnlineData.GetRecommendFriendFlushTime();
}
void SyncDataOnlineDataV1::SendRecommendFriendFlushTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDFLUSHTIME,m_syncDataOnlineData.GetRecommendFriendFlushTime());
	if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_RECOMMENDFRIENDFLUSHTIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDFLUSHTIME,m_syncDataOnlineData.GetRecommendFriendFlushTime());
}

//上次推荐的好友
void SyncDataOnlineDataV1::SetRecommendFriendLastList( const vector<INT64>& v )
{
	m_syncDataOnlineData.SetRecommendFriendLastList(v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST);
	SendRecommendFriendLastList(false);
}
void SyncDataOnlineDataV1::SetRecommendFriendLastList( int Index, const INT64& v )
{
	m_syncDataOnlineData.SetRecommendFriendLastList(Index,v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST,Index);
	SendRecommendFriendLastList(Index,false);
}
vector<INT64> SyncDataOnlineDataV1::GetRecommendFriendLastList()
{
	return m_syncDataOnlineData.GetRecommendFriendLastList();
}
INT64 SyncDataOnlineDataV1::GetRecommendFriendLastList( int Index )
{
	return m_syncDataOnlineData.GetRecommendFriendLastList(Index);
}
void SyncDataOnlineDataV1::SendRecommendFriendLastList(bool OnlyToClient)
{
	SendRecommendFriendLastList(-1,OnlyToClient);
	for(int i=0; i<m_syncDataOnlineData.SizeRecommendFriendLastList(); i++)
		SendRecommendFriendLastList(i,OnlyToClient);
}
void SyncDataOnlineDataV1::SendRecommendFriendLastList( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST,Index,NULL,0);
		if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST,Index,NULL,0);
		return;
	}
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST,Index,m_syncDataOnlineData.GetRecommendFriendLastList(Index));
	if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST,Index,m_syncDataOnlineData.GetRecommendFriendLastList(Index));
}
void SyncDataOnlineDataV1::AddRecommendFriendLastList( INT64 v )
{
	m_syncDataOnlineData.AddRecommendFriendLastList(v);
	OnDataChange();
	int Index = m_syncDataOnlineData.SizeRecommendFriendLastList()-1;
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_RECOMMENDFRIENDLASTLIST,Index);
	SendRecommendFriendLastList(Index,false);
}

//跟随我的人
void SyncDataOnlineDataV1::SetFollowmeUserId( const vector<INT64>& v )
{
	m_syncDataOnlineData.SetFollowmeUserId(v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_FOLLOWMEUSERID);
	SendFollowmeUserId(false);
}
void SyncDataOnlineDataV1::SetFollowmeUserId( int Index, const INT64& v )
{
	m_syncDataOnlineData.SetFollowmeUserId(Index,v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_FOLLOWMEUSERID,Index);
	SendFollowmeUserId(Index,false);
}
vector<INT64> SyncDataOnlineDataV1::GetFollowmeUserId()
{
	return m_syncDataOnlineData.GetFollowmeUserId();
}
INT64 SyncDataOnlineDataV1::GetFollowmeUserId( int Index )
{
	return m_syncDataOnlineData.GetFollowmeUserId(Index);
}
void SyncDataOnlineDataV1::SendFollowmeUserId(bool OnlyToClient)
{
	SendFollowmeUserId(-1,OnlyToClient);
	for(int i=0; i<m_syncDataOnlineData.SizeFollowmeUserId(); i++)
		SendFollowmeUserId(i,OnlyToClient);
}
void SyncDataOnlineDataV1::SendFollowmeUserId( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_FOLLOWMEUSERID,Index,NULL,0);
		if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_FOLLOWMEUSERID)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_FOLLOWMEUSERID,Index,NULL,0);
		return;
	}
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_FOLLOWMEUSERID,Index,m_syncDataOnlineData.GetFollowmeUserId(Index));
	if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_FOLLOWMEUSERID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_FOLLOWMEUSERID,Index,m_syncDataOnlineData.GetFollowmeUserId(Index));
}
void SyncDataOnlineDataV1::AddFollowmeUserId( INT64 v )
{
	m_syncDataOnlineData.AddFollowmeUserId(v);
	OnDataChange();
	int Index = m_syncDataOnlineData.SizeFollowmeUserId()-1;
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_FOLLOWMEUSERID,Index);
	SendFollowmeUserId(Index,false);
}

//跟随谁
void SyncDataOnlineDataV1::SetFollowWho( const INT64& v )
{
	m_syncDataOnlineData.SetFollowWho(v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_FOLLOWWHO);
	SendFollowWho(false);
}
INT64 SyncDataOnlineDataV1::GetFollowWho()
{
	return m_syncDataOnlineData.GetFollowWho();
}
void SyncDataOnlineDataV1::SendFollowWho(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_FOLLOWWHO,m_syncDataOnlineData.GetFollowWho());
	if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_FOLLOWWHO)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_FOLLOWWHO,m_syncDataOnlineData.GetFollowWho());
}

//江洋大盗
void SyncDataOnlineDataV1::SetThiefObjId( const INT64& v )
{
	m_syncDataOnlineData.SetThiefObjId(v);
	OnDataChange();
	ModuleOnlineData::Instance().NotifySyncValueChanged(m_syncDataOnlineData.GetKey(),SYNCID_ONLINEDATA_THIEFOBJID);
	SendThiefObjId(false);
}
INT64 SyncDataOnlineDataV1::GetThiefObjId()
{
	return m_syncDataOnlineData.GetThiefObjId();
}
void SyncDataOnlineDataV1::SendThiefObjId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_ONLINEDATA_THIEFOBJID,m_syncDataOnlineData.GetThiefObjId());
	if(ModuleOnlineData::Instance().NotSyncToClient(SYNCID_ONLINEDATA_THIEFOBJID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_ONLINEDATA_THIEFOBJID,m_syncDataOnlineData.GetThiefObjId());
}
