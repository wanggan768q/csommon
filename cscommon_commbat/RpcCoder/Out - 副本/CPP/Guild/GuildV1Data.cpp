#include "GuildV1Data.h"
#include "GuildModule.h"


SyncDataGuildV1::SyncDataGuildV1()
{
	SetDataWraper( &m_syncDataGuildList );
}

SyncDataGuildV1::~SyncDataGuildV1()
{
}

void SyncDataGuildV1::SendAllMembers(bool OnlyToClient)
{
	SendGuildData(OnlyToClient);

}



//帮会数据
void SyncDataGuildV1::SetGuildData( const GuildInfoObjWraper& v )
{
	m_syncDataGuildList.SetGuildData(v);
	OnDataChange();
	ModuleGuild::Instance().NotifySyncValueChanged(m_syncDataGuildList.GetKey(),SYNCID_GUILD_GUILDDATA);
	SendGuildData(false);
}
GuildInfoObjWraper SyncDataGuildV1::GetGuildData()
{
	return m_syncDataGuildList.GetGuildData();
}
void SyncDataGuildV1::SendGuildData(bool OnlyToClient)
{
	const string v=m_syncDataGuildList.GetGuildData().SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_GUILD_GUILDDATA,v.data(),v.size());
}
