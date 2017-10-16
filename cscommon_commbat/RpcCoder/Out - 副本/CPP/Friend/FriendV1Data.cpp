#include "FriendV1Data.h"
#include "FriendModule.h"


SyncDataFriendV1::SyncDataFriendV1()
{
	SetDataWraper( &m_syncDataFriendData );
}

SyncDataFriendV1::~SyncDataFriendV1()
{
}

void SyncDataFriendV1::SendAllMembers(bool OnlyToClient)
{
	SendFriendList(OnlyToClient);
	SendBlackList(OnlyToClient);
	SendContactsList(OnlyToClient);
	SendStrangerFriendList(OnlyToClient);

}



//好友列表
void SyncDataFriendV1::SetFriendList( const vector<FriendFriendObjWraperV1>& v )
{
	m_syncDataFriendData.SetFriendList(v);
	OnDataChange();
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_FRIENDLIST);
	SendFriendList(false);
}
void SyncDataFriendV1::SetFriendList( int Index, const FriendFriendObjWraperV1& v )
{
	m_syncDataFriendData.SetFriendList(Index,v);
	OnDataChange();
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_FRIENDLIST,Index);
	SendFriendList(Index,false);
}
vector<FriendFriendObjWraperV1> SyncDataFriendV1::GetFriendList()
{
	return m_syncDataFriendData.GetFriendList();
}
FriendFriendObjWraperV1 SyncDataFriendV1::GetFriendList( int Index )
{
	return m_syncDataFriendData.GetFriendList(Index);
}
void SyncDataFriendV1::SendFriendList(bool OnlyToClient)
{
	SendFriendList(-1,OnlyToClient);
	for(int i=0; i<m_syncDataFriendData.SizeFriendList(); i++)
		SendFriendList(i,OnlyToClient);
}
void SyncDataFriendV1::SendFriendList( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_FRIEND_FRIENDLIST,Index,NULL,0);
		if(ModuleFriend::Instance().NotSyncToClient(SYNCID_FRIEND_FRIENDLIST)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_FRIEND_FRIENDLIST,Index,NULL,0);
		return;
	}
	const string v= GetFriendList(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_FRIEND_FRIENDLIST,Index,v.data(),v.size());
	if(ModuleFriend::Instance().NotSyncToClient(SYNCID_FRIEND_FRIENDLIST)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_FRIEND_FRIENDLIST,Index,v.data(),v.size());
}
void SyncDataFriendV1::AddFriendList( const FriendFriendObjWraperV1& v )
{
	m_syncDataFriendData.AddFriendList(v);
	OnDataChange();
	int Index = m_syncDataFriendData.SizeFriendList()-1;
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_FRIENDLIST,Index);
	SendFriendList(Index,false);
}

//黑名单
void SyncDataFriendV1::SetBlackList( const vector<FriendFriendObjWraperV1>& v )
{
	m_syncDataFriendData.SetBlackList(v);
	OnDataChange();
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_BLACKLIST);
	SendBlackList(false);
}
void SyncDataFriendV1::SetBlackList( int Index, const FriendFriendObjWraperV1& v )
{
	m_syncDataFriendData.SetBlackList(Index,v);
	OnDataChange();
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_BLACKLIST,Index);
	SendBlackList(Index,false);
}
vector<FriendFriendObjWraperV1> SyncDataFriendV1::GetBlackList()
{
	return m_syncDataFriendData.GetBlackList();
}
FriendFriendObjWraperV1 SyncDataFriendV1::GetBlackList( int Index )
{
	return m_syncDataFriendData.GetBlackList(Index);
}
void SyncDataFriendV1::SendBlackList(bool OnlyToClient)
{
	SendBlackList(-1,OnlyToClient);
	for(int i=0; i<m_syncDataFriendData.SizeBlackList(); i++)
		SendBlackList(i,OnlyToClient);
}
void SyncDataFriendV1::SendBlackList( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_FRIEND_BLACKLIST,Index,NULL,0);
		if(ModuleFriend::Instance().NotSyncToClient(SYNCID_FRIEND_BLACKLIST)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_FRIEND_BLACKLIST,Index,NULL,0);
		return;
	}
	const string v= GetBlackList(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_FRIEND_BLACKLIST,Index,v.data(),v.size());
	if(ModuleFriend::Instance().NotSyncToClient(SYNCID_FRIEND_BLACKLIST)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_FRIEND_BLACKLIST,Index,v.data(),v.size());
}
void SyncDataFriendV1::AddBlackList( const FriendFriendObjWraperV1& v )
{
	m_syncDataFriendData.AddBlackList(v);
	OnDataChange();
	int Index = m_syncDataFriendData.SizeBlackList()-1;
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_BLACKLIST,Index);
	SendBlackList(Index,false);
}

//最近联系人
void SyncDataFriendV1::SetContactsList( const vector<FriendFriendObjWraperV1>& v )
{
	m_syncDataFriendData.SetContactsList(v);
	OnDataChange();
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_CONTACTSLIST);
	SendContactsList(false);
}
void SyncDataFriendV1::SetContactsList( int Index, const FriendFriendObjWraperV1& v )
{
	m_syncDataFriendData.SetContactsList(Index,v);
	OnDataChange();
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_CONTACTSLIST,Index);
	SendContactsList(Index,false);
}
vector<FriendFriendObjWraperV1> SyncDataFriendV1::GetContactsList()
{
	return m_syncDataFriendData.GetContactsList();
}
FriendFriendObjWraperV1 SyncDataFriendV1::GetContactsList( int Index )
{
	return m_syncDataFriendData.GetContactsList(Index);
}
void SyncDataFriendV1::SendContactsList(bool OnlyToClient)
{
	SendContactsList(-1,OnlyToClient);
	for(int i=0; i<m_syncDataFriendData.SizeContactsList(); i++)
		SendContactsList(i,OnlyToClient);
}
void SyncDataFriendV1::SendContactsList( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_FRIEND_CONTACTSLIST,Index,NULL,0);
		if(ModuleFriend::Instance().NotSyncToClient(SYNCID_FRIEND_CONTACTSLIST)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_FRIEND_CONTACTSLIST,Index,NULL,0);
		return;
	}
	const string v= GetContactsList(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_FRIEND_CONTACTSLIST,Index,v.data(),v.size());
	if(ModuleFriend::Instance().NotSyncToClient(SYNCID_FRIEND_CONTACTSLIST)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_FRIEND_CONTACTSLIST,Index,v.data(),v.size());
}
void SyncDataFriendV1::AddContactsList( const FriendFriendObjWraperV1& v )
{
	m_syncDataFriendData.AddContactsList(v);
	OnDataChange();
	int Index = m_syncDataFriendData.SizeContactsList()-1;
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_CONTACTSLIST,Index);
	SendContactsList(Index,false);
}

//加过我的人
void SyncDataFriendV1::SetStrangerFriendList( const vector<INT64>& v )
{
	m_syncDataFriendData.SetStrangerFriendList(v);
	OnDataChange();
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_STRANGERFRIENDLIST);
	SendStrangerFriendList(false);
}
void SyncDataFriendV1::SetStrangerFriendList( int Index, const INT64& v )
{
	m_syncDataFriendData.SetStrangerFriendList(Index,v);
	OnDataChange();
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_STRANGERFRIENDLIST,Index);
	SendStrangerFriendList(Index,false);
}
vector<INT64> SyncDataFriendV1::GetStrangerFriendList()
{
	return m_syncDataFriendData.GetStrangerFriendList();
}
INT64 SyncDataFriendV1::GetStrangerFriendList( int Index )
{
	return m_syncDataFriendData.GetStrangerFriendList(Index);
}
void SyncDataFriendV1::SendStrangerFriendList(bool OnlyToClient)
{
	SendStrangerFriendList(-1,OnlyToClient);
	for(int i=0; i<m_syncDataFriendData.SizeStrangerFriendList(); i++)
		SendStrangerFriendList(i,OnlyToClient);
}
void SyncDataFriendV1::SendStrangerFriendList( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_FRIEND_STRANGERFRIENDLIST,Index,NULL,0);
		if(ModuleFriend::Instance().NotSyncToClient(SYNCID_FRIEND_STRANGERFRIENDLIST)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_FRIEND_STRANGERFRIENDLIST,Index,NULL,0);
		return;
	}
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_FRIEND_STRANGERFRIENDLIST,Index,m_syncDataFriendData.GetStrangerFriendList(Index));
	if(ModuleFriend::Instance().NotSyncToClient(SYNCID_FRIEND_STRANGERFRIENDLIST)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_FRIEND_STRANGERFRIENDLIST,Index,m_syncDataFriendData.GetStrangerFriendList(Index));
}
void SyncDataFriendV1::AddStrangerFriendList( INT64 v )
{
	m_syncDataFriendData.AddStrangerFriendList(v);
	OnDataChange();
	int Index = m_syncDataFriendData.SizeStrangerFriendList()-1;
	ModuleFriend::Instance().NotifySyncValueChanged(m_syncDataFriendData.GetKey(),SYNCID_FRIEND_STRANGERFRIENDLIST,Index);
	SendStrangerFriendList(Index,false);
}
