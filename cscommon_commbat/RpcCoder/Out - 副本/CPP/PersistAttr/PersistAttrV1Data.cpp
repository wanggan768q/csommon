#include "PersistAttrV1Data.h"
#include "PersistAttrModule.h"


SyncDataPersistAttrV1::SyncDataPersistAttrV1()
{
	SetDataWraper( &m_syncDataPersistAttr );
}

SyncDataPersistAttrV1::~SyncDataPersistAttrV1()
{
}

void SyncDataPersistAttrV1::SendAllMembers(bool OnlyToClient)
{
	SendUserName(OnlyToClient);
	SendUserId(OnlyToClient);
	SendPlatName(OnlyToClient);
	SendAccountId(OnlyToClient);
	SendLevel(OnlyToClient);
	SendRank(OnlyToClient);
	SendFightPower(OnlyToClient);
	SendSec(OnlyToClient);
	SendProf(OnlyToClient);
	SendOnlineState(OnlyToClient);
	SendTeamId(OnlyToClient);
	SendShopScore(OnlyToClient);
	SendDungeonId(OnlyToClient);
	SendSessionKey(OnlyToClient);
	SendGuildId(OnlyToClient);

}



//战队名字
void SyncDataPersistAttrV1::SetUserName( const string& v )
{
	m_syncDataPersistAttr.SetUserName(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_USERNAME);
	SendUserName(false);
}
string SyncDataPersistAttrV1::GetUserName()
{
	return m_syncDataPersistAttr.GetUserName();
}
void SyncDataPersistAttrV1::SendUserName(bool OnlyToClient)
{
	const string v=m_syncDataPersistAttr.GetUserName();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_USERNAME,v.data(),v.size());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_USERNAME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_USERNAME,v.data(),v.size());
}

//用户ID
void SyncDataPersistAttrV1::SetUserId( const INT64& v )
{
	m_syncDataPersistAttr.SetUserId(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_USERID);
	SendUserId(false);
}
INT64 SyncDataPersistAttrV1::GetUserId()
{
	return m_syncDataPersistAttr.GetUserId();
}
void SyncDataPersistAttrV1::SendUserId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_USERID,m_syncDataPersistAttr.GetUserId());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_USERID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_USERID,m_syncDataPersistAttr.GetUserId());
}

//游戏中心账号名
void SyncDataPersistAttrV1::SetPlatName( const string& v )
{
	m_syncDataPersistAttr.SetPlatName(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_PLATNAME);
	SendPlatName(false);
}
string SyncDataPersistAttrV1::GetPlatName()
{
	return m_syncDataPersistAttr.GetPlatName();
}
void SyncDataPersistAttrV1::SendPlatName(bool OnlyToClient)
{
	const string v=m_syncDataPersistAttr.GetPlatName();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_PLATNAME,v.data(),v.size());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_PLATNAME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_PLATNAME,v.data(),v.size());
}

//游戏中心账号ID
void SyncDataPersistAttrV1::SetAccountId( const INT64& v )
{
	m_syncDataPersistAttr.SetAccountId(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_ACCOUNTID);
	SendAccountId(false);
}
INT64 SyncDataPersistAttrV1::GetAccountId()
{
	return m_syncDataPersistAttr.GetAccountId();
}
void SyncDataPersistAttrV1::SendAccountId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_ACCOUNTID,m_syncDataPersistAttr.GetAccountId());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_ACCOUNTID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_ACCOUNTID,m_syncDataPersistAttr.GetAccountId());
}

//战队等级
void SyncDataPersistAttrV1::SetLevel( const INT32& v )
{
	m_syncDataPersistAttr.SetLevel(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_LEVEL);
	SendLevel(false);
}
INT32 SyncDataPersistAttrV1::GetLevel()
{
	return m_syncDataPersistAttr.GetLevel();
}
void SyncDataPersistAttrV1::SendLevel(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_LEVEL,m_syncDataPersistAttr.GetLevel());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_LEVEL)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_LEVEL,m_syncDataPersistAttr.GetLevel());
}

//官阶
void SyncDataPersistAttrV1::SetRank( const INT32& v )
{
	m_syncDataPersistAttr.SetRank(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_RANK);
	SendRank(false);
}
INT32 SyncDataPersistAttrV1::GetRank()
{
	return m_syncDataPersistAttr.GetRank();
}
void SyncDataPersistAttrV1::SendRank(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_RANK,m_syncDataPersistAttr.GetRank());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_RANK)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_RANK,m_syncDataPersistAttr.GetRank());
}

//战力
void SyncDataPersistAttrV1::SetFightPower( const INT32& v )
{
	m_syncDataPersistAttr.SetFightPower(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_FIGHTPOWER);
	SendFightPower(false);
}
INT32 SyncDataPersistAttrV1::GetFightPower()
{
	return m_syncDataPersistAttr.GetFightPower();
}
void SyncDataPersistAttrV1::SendFightPower(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_FIGHTPOWER,m_syncDataPersistAttr.GetFightPower());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_FIGHTPOWER)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_FIGHTPOWER,m_syncDataPersistAttr.GetFightPower());
}

//登录时间秒
void SyncDataPersistAttrV1::SetSec( const INT32& v )
{
	m_syncDataPersistAttr.SetSec(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_SEC);
	SendSec(false);
}
INT32 SyncDataPersistAttrV1::GetSec()
{
	return m_syncDataPersistAttr.GetSec();
}
void SyncDataPersistAttrV1::SendSec(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_SEC,m_syncDataPersistAttr.GetSec());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_SEC)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_SEC,m_syncDataPersistAttr.GetSec());
}

//职业
void SyncDataPersistAttrV1::SetProf( const INT32& v )
{
	m_syncDataPersistAttr.SetProf(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_PROF);
	SendProf(false);
}
INT32 SyncDataPersistAttrV1::GetProf()
{
	return m_syncDataPersistAttr.GetProf();
}
void SyncDataPersistAttrV1::SendProf(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_PROF,m_syncDataPersistAttr.GetProf());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_PROF)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_PROF,m_syncDataPersistAttr.GetProf());
}

//在线状态
void SyncDataPersistAttrV1::SetOnlineState( const INT32& v )
{
	m_syncDataPersistAttr.SetOnlineState(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_ONLINESTATE);
	SendOnlineState(false);
}
INT32 SyncDataPersistAttrV1::GetOnlineState()
{
	return m_syncDataPersistAttr.GetOnlineState();
}
void SyncDataPersistAttrV1::SendOnlineState(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_ONLINESTATE,m_syncDataPersistAttr.GetOnlineState());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_ONLINESTATE)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_ONLINESTATE,m_syncDataPersistAttr.GetOnlineState());
}

//组队id
void SyncDataPersistAttrV1::SetTeamId( const INT32& v )
{
	m_syncDataPersistAttr.SetTeamId(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_TEAMID);
	SendTeamId(false);
}
INT32 SyncDataPersistAttrV1::GetTeamId()
{
	return m_syncDataPersistAttr.GetTeamId();
}
void SyncDataPersistAttrV1::SendTeamId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_TEAMID,m_syncDataPersistAttr.GetTeamId());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_TEAMID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_TEAMID,m_syncDataPersistAttr.GetTeamId());
}

//几分商城
void SyncDataPersistAttrV1::SetShopScore( const INT32& v )
{
	m_syncDataPersistAttr.SetShopScore(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_SHOPSCORE);
	SendShopScore(false);
}
INT32 SyncDataPersistAttrV1::GetShopScore()
{
	return m_syncDataPersistAttr.GetShopScore();
}
void SyncDataPersistAttrV1::SendShopScore(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_SHOPSCORE,m_syncDataPersistAttr.GetShopScore());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_SHOPSCORE)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_SHOPSCORE,m_syncDataPersistAttr.GetShopScore());
}

//当前场景Id
void SyncDataPersistAttrV1::SetDungeonId( const INT32& v )
{
	m_syncDataPersistAttr.SetDungeonId(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_DUNGEONID);
	SendDungeonId(false);
}
INT32 SyncDataPersistAttrV1::GetDungeonId()
{
	return m_syncDataPersistAttr.GetDungeonId();
}
void SyncDataPersistAttrV1::SendDungeonId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_DUNGEONID,m_syncDataPersistAttr.GetDungeonId());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_DUNGEONID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_DUNGEONID,m_syncDataPersistAttr.GetDungeonId());
}

//SessionKey
void SyncDataPersistAttrV1::SetSessionKey( const string& v )
{
	m_syncDataPersistAttr.SetSessionKey(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_SESSIONKEY);
	SendSessionKey(false);
}
string SyncDataPersistAttrV1::GetSessionKey()
{
	return m_syncDataPersistAttr.GetSessionKey();
}
void SyncDataPersistAttrV1::SendSessionKey(bool OnlyToClient)
{
	const string v=m_syncDataPersistAttr.GetSessionKey();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_SESSIONKEY,v.data(),v.size());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_SESSIONKEY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_SESSIONKEY,v.data(),v.size());
}

//帮会Id
void SyncDataPersistAttrV1::SetGuildId( const INT32& v )
{
	m_syncDataPersistAttr.SetGuildId(v);
	OnDataChange();
	ModulePersistAttr::Instance().NotifySyncValueChanged(m_syncDataPersistAttr.GetKey(),SYNCID_PERSISTATTR_GUILDID);
	SendGuildId(false);
}
INT32 SyncDataPersistAttrV1::GetGuildId()
{
	return m_syncDataPersistAttr.GetGuildId();
}
void SyncDataPersistAttrV1::SendGuildId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_PERSISTATTR_GUILDID,m_syncDataPersistAttr.GetGuildId());
	if(ModulePersistAttr::Instance().NotSyncToClient(SYNCID_PERSISTATTR_GUILDID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_PERSISTATTR_GUILDID,m_syncDataPersistAttr.GetGuildId());
}
