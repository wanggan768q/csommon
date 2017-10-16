#include "DungeonV1Data.h"
#include "DungeonModule.h"


SyncDataDungeonV1::SyncDataDungeonV1()
{
	SetDataWraper( &m_syncDataDungeonInfo );
}

SyncDataDungeonV1::~SyncDataDungeonV1()
{
}

void SyncDataDungeonV1::SendAllMembers(bool OnlyToClient)
{
	SendDungeonKey(OnlyToClient);
	SendDungeonId(OnlyToClient);
	SendDungeonType(OnlyToClient);
	SendKeyId(OnlyToClient);
	SendHost(OnlyToClient);
	SendPort(OnlyToClient);
	SendGuild(OnlyToClient);

}



//Key
void SyncDataDungeonV1::SetDungeonKey( const string& v )
{
	m_syncDataDungeonInfo.SetDungeonKey(v);
	OnDataChange();
	ModuleDungeon::Instance().NotifySyncValueChanged(m_syncDataDungeonInfo.GetKey(),SYNCID_DUNGEON_DUNGEONKEY);
	SendDungeonKey(false);
}
string SyncDataDungeonV1::GetDungeonKey()
{
	return m_syncDataDungeonInfo.GetDungeonKey();
}
void SyncDataDungeonV1::SendDungeonKey(bool OnlyToClient)
{
	const string v=m_syncDataDungeonInfo.GetDungeonKey();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DUNGEON_DUNGEONKEY,v.data(),v.size());
}

//副本ID
void SyncDataDungeonV1::SetDungeonId( const INT32& v )
{
	m_syncDataDungeonInfo.SetDungeonId(v);
	OnDataChange();
	ModuleDungeon::Instance().NotifySyncValueChanged(m_syncDataDungeonInfo.GetKey(),SYNCID_DUNGEON_DUNGEONID);
	SendDungeonId(false);
}
INT32 SyncDataDungeonV1::GetDungeonId()
{
	return m_syncDataDungeonInfo.GetDungeonId();
}
void SyncDataDungeonV1::SendDungeonId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DUNGEON_DUNGEONID,m_syncDataDungeonInfo.GetDungeonId());
}

//副本类型
void SyncDataDungeonV1::SetDungeonType( const INT32& v )
{
	m_syncDataDungeonInfo.SetDungeonType(v);
	OnDataChange();
	ModuleDungeon::Instance().NotifySyncValueChanged(m_syncDataDungeonInfo.GetKey(),SYNCID_DUNGEON_DUNGEONTYPE);
	SendDungeonType(false);
}
INT32 SyncDataDungeonV1::GetDungeonType()
{
	return m_syncDataDungeonInfo.GetDungeonType();
}
void SyncDataDungeonV1::SendDungeonType(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DUNGEON_DUNGEONTYPE,m_syncDataDungeonInfo.GetDungeonType());
}

//KeyId
void SyncDataDungeonV1::SetKeyId( const INT32& v )
{
	m_syncDataDungeonInfo.SetKeyId(v);
	OnDataChange();
	ModuleDungeon::Instance().NotifySyncValueChanged(m_syncDataDungeonInfo.GetKey(),SYNCID_DUNGEON_KEYID);
	SendKeyId(false);
}
INT32 SyncDataDungeonV1::GetKeyId()
{
	return m_syncDataDungeonInfo.GetKeyId();
}
void SyncDataDungeonV1::SendKeyId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DUNGEON_KEYID,m_syncDataDungeonInfo.GetKeyId());
}

//Host
void SyncDataDungeonV1::SetHost( const string& v )
{
	m_syncDataDungeonInfo.SetHost(v);
	OnDataChange();
	ModuleDungeon::Instance().NotifySyncValueChanged(m_syncDataDungeonInfo.GetKey(),SYNCID_DUNGEON_HOST);
	SendHost(false);
}
string SyncDataDungeonV1::GetHost()
{
	return m_syncDataDungeonInfo.GetHost();
}
void SyncDataDungeonV1::SendHost(bool OnlyToClient)
{
	const string v=m_syncDataDungeonInfo.GetHost();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DUNGEON_HOST,v.data(),v.size());
}

//Port
void SyncDataDungeonV1::SetPort( const INT32& v )
{
	m_syncDataDungeonInfo.SetPort(v);
	OnDataChange();
	ModuleDungeon::Instance().NotifySyncValueChanged(m_syncDataDungeonInfo.GetKey(),SYNCID_DUNGEON_PORT);
	SendPort(false);
}
INT32 SyncDataDungeonV1::GetPort()
{
	return m_syncDataDungeonInfo.GetPort();
}
void SyncDataDungeonV1::SendPort(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DUNGEON_PORT,m_syncDataDungeonInfo.GetPort());
}

//帮派Id
void SyncDataDungeonV1::SetGuild( const INT32& v )
{
	m_syncDataDungeonInfo.SetGuild(v);
	OnDataChange();
	ModuleDungeon::Instance().NotifySyncValueChanged(m_syncDataDungeonInfo.GetKey(),SYNCID_DUNGEON_GUILD);
	SendGuild(false);
}
INT32 SyncDataDungeonV1::GetGuild()
{
	return m_syncDataDungeonInfo.GetGuild();
}
void SyncDataDungeonV1::SendGuild(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_DUNGEON_GUILD,m_syncDataDungeonInfo.GetGuild());
}
