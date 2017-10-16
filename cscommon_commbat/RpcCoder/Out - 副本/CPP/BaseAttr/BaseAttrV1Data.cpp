#include "BaseAttrV1Data.h"
#include "BaseAttrModule.h"


SyncDataBaseAttrV1::SyncDataBaseAttrV1()
{
	SetDataWraper( &m_syncDataUserData );
}

SyncDataBaseAttrV1::~SyncDataBaseAttrV1()
{
}

void SyncDataBaseAttrV1::SendAllMembers(bool OnlyToClient)
{
	SendHeadID(OnlyToClient);
	SendExp(OnlyToClient);
	SendCreateTime(OnlyToClient);
	SendLastLoginTime(OnlyToClient);
	SendLast2LoginDate(OnlyToClient);
	SendLastLogoutTime(OnlyToClient);
	SendMoney(OnlyToClient);
	SendDiamond(OnlyToClient);
	SendStrength(OnlyToClient);
	SendFeats(OnlyToClient);
	SendGotRankRewardTime(OnlyToClient);
	SendMaxMilitary(OnlyToClient);
	SendMasterAttrs(OnlyToClient);
	SendCurMilitary(OnlyToClient);
	SendUserName(OnlyToClient);
	SendUserId(OnlyToClient);
	SendPlatName(OnlyToClient);
	SendAccountId(OnlyToClient);
	SendLevel(OnlyToClient);
	SendRank(OnlyToClient);
	SendFightPower(OnlyToClient);
	SendSec(OnlyToClient);
	SendMilitary(OnlyToClient);
	SendTeamId(OnlyToClient);
	SendProf(OnlyToClient);
	SendDungeonRemainCount(OnlyToClient);
	SendMapId(OnlyToClient);
	SendPosX(OnlyToClient);
	SendPosY(OnlyToClient);
	SendPosZ(OnlyToClient);
	SendRy(OnlyToClient);
	SendSkillCdArr(OnlyToClient);
	SendBuffCdArr(OnlyToClient);
	SendCurrentScene(OnlyToClient);
	SendGuildId(OnlyToClient);
	SendExitGuildTime(OnlyToClient);
	SendApplyGuildId(OnlyToClient);
	SendCurGuildContribution(OnlyToClient);
	SendMaxGuildContribution(OnlyToClient);
	SendBindMoney(OnlyToClient);
	SendGem(OnlyToClient);
	SendServerTime(OnlyToClient);
	SendNewbieGuide(OnlyToClient);
	SendThiefRewardNum(OnlyToClient);
	SendSubdueMonsterRewardNum(OnlyToClient);
	SendWorldBossRemainTimes(OnlyToClient);
	SendWorldBossHurt(OnlyToClient);
	SendFunctionOpenList(OnlyToClient);
	SendTotalEnergyValue(OnlyToClient);
	SendEnergyArray(OnlyToClient);
	SendPKState(OnlyToClient);
	SendPKProtect(OnlyToClient);
	SendGuildScienArray(OnlyToClient);
	SendScienceTotalMoney(OnlyToClient);

}



//头像id
void SyncDataBaseAttrV1::SetHeadID( const INT32& v )
{
	m_syncDataUserData.SetHeadID(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_HEADID);
	SendHeadID(false);
}
INT32 SyncDataBaseAttrV1::GetHeadID()
{
	return m_syncDataUserData.GetHeadID();
}
void SyncDataBaseAttrV1::SendHeadID(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_HEADID,m_syncDataUserData.GetHeadID());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_HEADID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_HEADID,m_syncDataUserData.GetHeadID());
}

//经验
void SyncDataBaseAttrV1::SetExp( const INT32& v )
{
	m_syncDataUserData.SetExp(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_EXP);
	SendExp(false);
}
INT32 SyncDataBaseAttrV1::GetExp()
{
	return m_syncDataUserData.GetExp();
}
void SyncDataBaseAttrV1::SendExp(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_EXP,m_syncDataUserData.GetExp());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_EXP)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_EXP,m_syncDataUserData.GetExp());
}

//创建时间
void SyncDataBaseAttrV1::SetCreateTime( const INT32& v )
{
	m_syncDataUserData.SetCreateTime(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_CREATETIME);
	SendCreateTime(false);
}
INT32 SyncDataBaseAttrV1::GetCreateTime()
{
	return m_syncDataUserData.GetCreateTime();
}
void SyncDataBaseAttrV1::SendCreateTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_CREATETIME,m_syncDataUserData.GetCreateTime());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_CREATETIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_CREATETIME,m_syncDataUserData.GetCreateTime());
}

//最后登录时间
void SyncDataBaseAttrV1::SetLastLoginTime( const INT32& v )
{
	m_syncDataUserData.SetLastLoginTime(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_LASTLOGINTIME);
	SendLastLoginTime(false);
}
INT32 SyncDataBaseAttrV1::GetLastLoginTime()
{
	return m_syncDataUserData.GetLastLoginTime();
}
void SyncDataBaseAttrV1::SendLastLoginTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_LASTLOGINTIME,m_syncDataUserData.GetLastLoginTime());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_LASTLOGINTIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_LASTLOGINTIME,m_syncDataUserData.GetLastLoginTime());
}

//倒数第二登录日期
void SyncDataBaseAttrV1::SetLast2LoginDate( const INT32& v )
{
	m_syncDataUserData.SetLast2LoginDate(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_LAST2LOGINDATE);
	SendLast2LoginDate(false);
}
INT32 SyncDataBaseAttrV1::GetLast2LoginDate()
{
	return m_syncDataUserData.GetLast2LoginDate();
}
void SyncDataBaseAttrV1::SendLast2LoginDate(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_LAST2LOGINDATE,m_syncDataUserData.GetLast2LoginDate());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_LAST2LOGINDATE)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_LAST2LOGINDATE,m_syncDataUserData.GetLast2LoginDate());
}

//最后登出时间
void SyncDataBaseAttrV1::SetLastLogoutTime( const INT32& v )
{
	m_syncDataUserData.SetLastLogoutTime(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_LASTLOGOUTTIME);
	SendLastLogoutTime(false);
}
INT32 SyncDataBaseAttrV1::GetLastLogoutTime()
{
	return m_syncDataUserData.GetLastLogoutTime();
}
void SyncDataBaseAttrV1::SendLastLogoutTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_LASTLOGOUTTIME,m_syncDataUserData.GetLastLogoutTime());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_LASTLOGOUTTIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_LASTLOGOUTTIME,m_syncDataUserData.GetLastLogoutTime());
}

//游戏币
void SyncDataBaseAttrV1::SetMoney( const INT32& v )
{
	m_syncDataUserData.SetMoney(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_MONEY);
	SendMoney(false);
}
INT32 SyncDataBaseAttrV1::GetMoney()
{
	return m_syncDataUserData.GetMoney();
}
void SyncDataBaseAttrV1::SendMoney(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_MONEY,m_syncDataUserData.GetMoney());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_MONEY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_MONEY,m_syncDataUserData.GetMoney());
}

//钻石
void SyncDataBaseAttrV1::SetDiamond( const INT32& v )
{
	m_syncDataUserData.SetDiamond(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_DIAMOND);
	SendDiamond(false);
}
INT32 SyncDataBaseAttrV1::GetDiamond()
{
	return m_syncDataUserData.GetDiamond();
}
void SyncDataBaseAttrV1::SendDiamond(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_DIAMOND,m_syncDataUserData.GetDiamond());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_DIAMOND)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_DIAMOND,m_syncDataUserData.GetDiamond());
}

//体力
void SyncDataBaseAttrV1::SetStrength( const INT32& v )
{
	m_syncDataUserData.SetStrength(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_STRENGTH);
	SendStrength(false);
}
INT32 SyncDataBaseAttrV1::GetStrength()
{
	return m_syncDataUserData.GetStrength();
}
void SyncDataBaseAttrV1::SendStrength(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_STRENGTH,m_syncDataUserData.GetStrength());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_STRENGTH)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_STRENGTH,m_syncDataUserData.GetStrength());
}

//功勋
void SyncDataBaseAttrV1::SetFeats( const INT32& v )
{
	m_syncDataUserData.SetFeats(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_FEATS);
	SendFeats(false);
}
INT32 SyncDataBaseAttrV1::GetFeats()
{
	return m_syncDataUserData.GetFeats();
}
void SyncDataBaseAttrV1::SendFeats(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_FEATS,m_syncDataUserData.GetFeats());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_FEATS)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_FEATS,m_syncDataUserData.GetFeats());
}

//领取官阶奖励时间
void SyncDataBaseAttrV1::SetGotRankRewardTime( const INT32& v )
{
	m_syncDataUserData.SetGotRankRewardTime(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_GOTRANKREWARDTIME);
	SendGotRankRewardTime(false);
}
INT32 SyncDataBaseAttrV1::GetGotRankRewardTime()
{
	return m_syncDataUserData.GetGotRankRewardTime();
}
void SyncDataBaseAttrV1::SendGotRankRewardTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_GOTRANKREWARDTIME,m_syncDataUserData.GetGotRankRewardTime());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_GOTRANKREWARDTIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_GOTRANKREWARDTIME,m_syncDataUserData.GetGotRankRewardTime());
}

//历史最大战力
void SyncDataBaseAttrV1::SetMaxMilitary( const INT32& v )
{
	m_syncDataUserData.SetMaxMilitary(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_MAXMILITARY);
	SendMaxMilitary(false);
}
INT32 SyncDataBaseAttrV1::GetMaxMilitary()
{
	return m_syncDataUserData.GetMaxMilitary();
}
void SyncDataBaseAttrV1::SendMaxMilitary(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_MAXMILITARY,m_syncDataUserData.GetMaxMilitary());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_MAXMILITARY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_MAXMILITARY,m_syncDataUserData.GetMaxMilitary());
}

//主公基础属性
void SyncDataBaseAttrV1::SetMasterAttrs( const vector<INT32>& v )
{
	m_syncDataUserData.SetMasterAttrs(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_MASTERATTRS);
	SendMasterAttrs(false);
}
void SyncDataBaseAttrV1::SetMasterAttrs( int Index, const INT32& v )
{
	m_syncDataUserData.SetMasterAttrs(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_MASTERATTRS,Index);
	SendMasterAttrs(Index,false);
}
vector<INT32> SyncDataBaseAttrV1::GetMasterAttrs()
{
	return m_syncDataUserData.GetMasterAttrs();
}
INT32 SyncDataBaseAttrV1::GetMasterAttrs( int Index )
{
	return m_syncDataUserData.GetMasterAttrs(Index);
}
void SyncDataBaseAttrV1::SendMasterAttrs(bool OnlyToClient)
{
	SendMasterAttrs(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizeMasterAttrs(); i++)
		SendMasterAttrs(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendMasterAttrs( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_MASTERATTRS,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_MASTERATTRS)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_MASTERATTRS,Index,NULL,0);
		return;
	}
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_MASTERATTRS,Index,m_syncDataUserData.GetMasterAttrs(Index));
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_MASTERATTRS)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_MASTERATTRS,Index,m_syncDataUserData.GetMasterAttrs(Index));
}
void SyncDataBaseAttrV1::AddMasterAttrs( INT32 v )
{
	m_syncDataUserData.AddMasterAttrs(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizeMasterAttrs()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_MASTERATTRS,Index);
	SendMasterAttrs(Index,false);
}

//当前玩家战力
void SyncDataBaseAttrV1::SetCurMilitary( const INT32& v )
{
	m_syncDataUserData.SetCurMilitary(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_CURMILITARY);
	SendCurMilitary(false);
}
INT32 SyncDataBaseAttrV1::GetCurMilitary()
{
	return m_syncDataUserData.GetCurMilitary();
}
void SyncDataBaseAttrV1::SendCurMilitary(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_CURMILITARY,m_syncDataUserData.GetCurMilitary());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_CURMILITARY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_CURMILITARY,m_syncDataUserData.GetCurMilitary());
}

//玩家名字
void SyncDataBaseAttrV1::SetUserName( const string& v )
{
	m_syncDataUserData.SetUserName(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_USERNAME);
	SendUserName(false);
}
string SyncDataBaseAttrV1::GetUserName()
{
	return m_syncDataUserData.GetUserName();
}
void SyncDataBaseAttrV1::SendUserName(bool OnlyToClient)
{
	const string v=m_syncDataUserData.GetUserName();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_USERNAME,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_USERNAME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_USERNAME,v.data(),v.size());
}

//用户ID
void SyncDataBaseAttrV1::SetUserId( const INT64& v )
{
	m_syncDataUserData.SetUserId(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_USERID);
	SendUserId(false);
}
INT64 SyncDataBaseAttrV1::GetUserId()
{
	return m_syncDataUserData.GetUserId();
}
void SyncDataBaseAttrV1::SendUserId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_USERID,m_syncDataUserData.GetUserId());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_USERID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_USERID,m_syncDataUserData.GetUserId());
}

//游戏中心账号名
void SyncDataBaseAttrV1::SetPlatName( const string& v )
{
	m_syncDataUserData.SetPlatName(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_PLATNAME);
	SendPlatName(false);
}
string SyncDataBaseAttrV1::GetPlatName()
{
	return m_syncDataUserData.GetPlatName();
}
void SyncDataBaseAttrV1::SendPlatName(bool OnlyToClient)
{
	const string v=m_syncDataUserData.GetPlatName();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_PLATNAME,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_PLATNAME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_PLATNAME,v.data(),v.size());
}

//游戏中心账号ID
void SyncDataBaseAttrV1::SetAccountId( const INT64& v )
{
	m_syncDataUserData.SetAccountId(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_ACCOUNTID);
	SendAccountId(false);
}
INT64 SyncDataBaseAttrV1::GetAccountId()
{
	return m_syncDataUserData.GetAccountId();
}
void SyncDataBaseAttrV1::SendAccountId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_ACCOUNTID,m_syncDataUserData.GetAccountId());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_ACCOUNTID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_ACCOUNTID,m_syncDataUserData.GetAccountId());
}

//玩家等级
void SyncDataBaseAttrV1::SetLevel( const INT32& v )
{
	m_syncDataUserData.SetLevel(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_LEVEL);
	SendLevel(false);
}
INT32 SyncDataBaseAttrV1::GetLevel()
{
	return m_syncDataUserData.GetLevel();
}
void SyncDataBaseAttrV1::SendLevel(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_LEVEL,m_syncDataUserData.GetLevel());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_LEVEL)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_LEVEL,m_syncDataUserData.GetLevel());
}

//官阶
void SyncDataBaseAttrV1::SetRank( const INT32& v )
{
	m_syncDataUserData.SetRank(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_RANK);
	SendRank(false);
}
INT32 SyncDataBaseAttrV1::GetRank()
{
	return m_syncDataUserData.GetRank();
}
void SyncDataBaseAttrV1::SendRank(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_RANK,m_syncDataUserData.GetRank());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_RANK)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_RANK,m_syncDataUserData.GetRank());
}

//战力
void SyncDataBaseAttrV1::SetFightPower( const INT32& v )
{
	m_syncDataUserData.SetFightPower(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_FIGHTPOWER);
	SendFightPower(false);
}
INT32 SyncDataBaseAttrV1::GetFightPower()
{
	return m_syncDataUserData.GetFightPower();
}
void SyncDataBaseAttrV1::SendFightPower(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_FIGHTPOWER,m_syncDataUserData.GetFightPower());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_FIGHTPOWER)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_FIGHTPOWER,m_syncDataUserData.GetFightPower());
}

//用户累加的数据
void SyncDataBaseAttrV1::SetSec( const INT32& v )
{
	m_syncDataUserData.SetSec(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_SEC);
	SendSec(false);
}
INT32 SyncDataBaseAttrV1::GetSec()
{
	return m_syncDataUserData.GetSec();
}
void SyncDataBaseAttrV1::SendSec(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_SEC,m_syncDataUserData.GetSec());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_SEC)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_SEC,m_syncDataUserData.GetSec());
}

//当前战力
void SyncDataBaseAttrV1::SetMilitary( const INT32& v )
{
	m_syncDataUserData.SetMilitary(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_MILITARY);
	SendMilitary(false);
}
INT32 SyncDataBaseAttrV1::GetMilitary()
{
	return m_syncDataUserData.GetMilitary();
}
void SyncDataBaseAttrV1::SendMilitary(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_MILITARY,m_syncDataUserData.GetMilitary());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_MILITARY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_MILITARY,m_syncDataUserData.GetMilitary());
}

//队伍Id
void SyncDataBaseAttrV1::SetTeamId( const INT32& v )
{
	m_syncDataUserData.SetTeamId(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_TEAMID);
	SendTeamId(false);
}
INT32 SyncDataBaseAttrV1::GetTeamId()
{
	return m_syncDataUserData.GetTeamId();
}
void SyncDataBaseAttrV1::SendTeamId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_TEAMID,m_syncDataUserData.GetTeamId());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_TEAMID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_TEAMID,m_syncDataUserData.GetTeamId());
}

//职业
void SyncDataBaseAttrV1::SetProf( const INT32& v )
{
	m_syncDataUserData.SetProf(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_PROF);
	SendProf(false);
}
INT32 SyncDataBaseAttrV1::GetProf()
{
	return m_syncDataUserData.GetProf();
}
void SyncDataBaseAttrV1::SendProf(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_PROF,m_syncDataUserData.GetProf());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_PROF)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_PROF,m_syncDataUserData.GetProf());
}

//副本剩余次数
void SyncDataBaseAttrV1::SetDungeonRemainCount( const INT32& v )
{
	m_syncDataUserData.SetDungeonRemainCount(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_DUNGEONREMAINCOUNT);
	SendDungeonRemainCount(false);
}
INT32 SyncDataBaseAttrV1::GetDungeonRemainCount()
{
	return m_syncDataUserData.GetDungeonRemainCount();
}
void SyncDataBaseAttrV1::SendDungeonRemainCount(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_DUNGEONREMAINCOUNT,m_syncDataUserData.GetDungeonRemainCount());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_DUNGEONREMAINCOUNT)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_DUNGEONREMAINCOUNT,m_syncDataUserData.GetDungeonRemainCount());
}

//地图Id
void SyncDataBaseAttrV1::SetMapId( const INT32& v )
{
	m_syncDataUserData.SetMapId(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_MAPID);
	SendMapId(false);
}
INT32 SyncDataBaseAttrV1::GetMapId()
{
	return m_syncDataUserData.GetMapId();
}
void SyncDataBaseAttrV1::SendMapId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_MAPID,m_syncDataUserData.GetMapId());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_MAPID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_MAPID,m_syncDataUserData.GetMapId());
}

//X坐标
void SyncDataBaseAttrV1::SetPosX( const float& v )
{
	m_syncDataUserData.SetPosX(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_POSX);
	SendPosX(false);
}
float SyncDataBaseAttrV1::GetPosX()
{
	return m_syncDataUserData.GetPosX();
}
void SyncDataBaseAttrV1::SendPosX(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCacheF(GetKey(),SYNCID_BASEATTR_POSX,m_syncDataUserData.GetPosX());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_POSX)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSyncF(GetKey(),SYNCID_BASEATTR_POSX,m_syncDataUserData.GetPosX());
}

//Y坐标
void SyncDataBaseAttrV1::SetPosY( const float& v )
{
	m_syncDataUserData.SetPosY(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_POSY);
	SendPosY(false);
}
float SyncDataBaseAttrV1::GetPosY()
{
	return m_syncDataUserData.GetPosY();
}
void SyncDataBaseAttrV1::SendPosY(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCacheF(GetKey(),SYNCID_BASEATTR_POSY,m_syncDataUserData.GetPosY());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_POSY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSyncF(GetKey(),SYNCID_BASEATTR_POSY,m_syncDataUserData.GetPosY());
}

//Z坐标
void SyncDataBaseAttrV1::SetPosZ( const float& v )
{
	m_syncDataUserData.SetPosZ(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_POSZ);
	SendPosZ(false);
}
float SyncDataBaseAttrV1::GetPosZ()
{
	return m_syncDataUserData.GetPosZ();
}
void SyncDataBaseAttrV1::SendPosZ(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCacheF(GetKey(),SYNCID_BASEATTR_POSZ,m_syncDataUserData.GetPosZ());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_POSZ)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSyncF(GetKey(),SYNCID_BASEATTR_POSZ,m_syncDataUserData.GetPosZ());
}

//位置方向
void SyncDataBaseAttrV1::SetRy( const INT32& v )
{
	m_syncDataUserData.SetRy(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_RY);
	SendRy(false);
}
INT32 SyncDataBaseAttrV1::GetRy()
{
	return m_syncDataUserData.GetRy();
}
void SyncDataBaseAttrV1::SendRy(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_RY,m_syncDataUserData.GetRy());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_RY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_RY,m_syncDataUserData.GetRy());
}

//技能CD列表
void SyncDataBaseAttrV1::SetSkillCdArr( const vector<BaseAttrSkillCdInfoWraperV1>& v )
{
	m_syncDataUserData.SetSkillCdArr(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_SKILLCDARR);
	SendSkillCdArr(false);
}
void SyncDataBaseAttrV1::SetSkillCdArr( int Index, const BaseAttrSkillCdInfoWraperV1& v )
{
	m_syncDataUserData.SetSkillCdArr(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_SKILLCDARR,Index);
	SendSkillCdArr(Index,false);
}
vector<BaseAttrSkillCdInfoWraperV1> SyncDataBaseAttrV1::GetSkillCdArr()
{
	return m_syncDataUserData.GetSkillCdArr();
}
BaseAttrSkillCdInfoWraperV1 SyncDataBaseAttrV1::GetSkillCdArr( int Index )
{
	return m_syncDataUserData.GetSkillCdArr(Index);
}
void SyncDataBaseAttrV1::SendSkillCdArr(bool OnlyToClient)
{
	SendSkillCdArr(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizeSkillCdArr(); i++)
		SendSkillCdArr(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendSkillCdArr( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_SKILLCDARR,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_SKILLCDARR)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_SKILLCDARR,Index,NULL,0);
		return;
	}
	const string v= GetSkillCdArr(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_SKILLCDARR,Index,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_SKILLCDARR)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_SKILLCDARR,Index,v.data(),v.size());
}
void SyncDataBaseAttrV1::AddSkillCdArr( const BaseAttrSkillCdInfoWraperV1& v )
{
	m_syncDataUserData.AddSkillCdArr(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizeSkillCdArr()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_SKILLCDARR,Index);
	SendSkillCdArr(Index,false);
}

//BuffCD列表
void SyncDataBaseAttrV1::SetBuffCdArr( const vector<BaseAttrBuffCdInfoWraperV1>& v )
{
	m_syncDataUserData.SetBuffCdArr(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_BUFFCDARR);
	SendBuffCdArr(false);
}
void SyncDataBaseAttrV1::SetBuffCdArr( int Index, const BaseAttrBuffCdInfoWraperV1& v )
{
	m_syncDataUserData.SetBuffCdArr(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_BUFFCDARR,Index);
	SendBuffCdArr(Index,false);
}
vector<BaseAttrBuffCdInfoWraperV1> SyncDataBaseAttrV1::GetBuffCdArr()
{
	return m_syncDataUserData.GetBuffCdArr();
}
BaseAttrBuffCdInfoWraperV1 SyncDataBaseAttrV1::GetBuffCdArr( int Index )
{
	return m_syncDataUserData.GetBuffCdArr(Index);
}
void SyncDataBaseAttrV1::SendBuffCdArr(bool OnlyToClient)
{
	SendBuffCdArr(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizeBuffCdArr(); i++)
		SendBuffCdArr(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendBuffCdArr( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_BUFFCDARR,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_BUFFCDARR)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_BUFFCDARR,Index,NULL,0);
		return;
	}
	const string v= GetBuffCdArr(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_BUFFCDARR,Index,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_BUFFCDARR)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_BUFFCDARR,Index,v.data(),v.size());
}
void SyncDataBaseAttrV1::AddBuffCdArr( const BaseAttrBuffCdInfoWraperV1& v )
{
	m_syncDataUserData.AddBuffCdArr(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizeBuffCdArr()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_BUFFCDARR,Index);
	SendBuffCdArr(Index,false);
}

//当前所在场景
void SyncDataBaseAttrV1::SetCurrentScene( const BaseAttrSceneInfoWraperV1& v )
{
	m_syncDataUserData.SetCurrentScene(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_CURRENTSCENE);
	SendCurrentScene(false);
}
BaseAttrSceneInfoWraperV1 SyncDataBaseAttrV1::GetCurrentScene()
{
	return m_syncDataUserData.GetCurrentScene();
}
void SyncDataBaseAttrV1::SendCurrentScene(bool OnlyToClient)
{
	const string v=m_syncDataUserData.GetCurrentScene().SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_CURRENTSCENE,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_CURRENTSCENE)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_CURRENTSCENE,v.data(),v.size());
}

//帮会Id
void SyncDataBaseAttrV1::SetGuildId( const INT32& v )
{
	m_syncDataUserData.SetGuildId(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_GUILDID);
	SendGuildId(false);
}
INT32 SyncDataBaseAttrV1::GetGuildId()
{
	return m_syncDataUserData.GetGuildId();
}
void SyncDataBaseAttrV1::SendGuildId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_GUILDID,m_syncDataUserData.GetGuildId());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_GUILDID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_GUILDID,m_syncDataUserData.GetGuildId());
}

//退出帮会时间
void SyncDataBaseAttrV1::SetExitGuildTime( const INT32& v )
{
	m_syncDataUserData.SetExitGuildTime(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_EXITGUILDTIME);
	SendExitGuildTime(false);
}
INT32 SyncDataBaseAttrV1::GetExitGuildTime()
{
	return m_syncDataUserData.GetExitGuildTime();
}
void SyncDataBaseAttrV1::SendExitGuildTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_EXITGUILDTIME,m_syncDataUserData.GetExitGuildTime());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_EXITGUILDTIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_EXITGUILDTIME,m_syncDataUserData.GetExitGuildTime());
}

//申请过的帮会
void SyncDataBaseAttrV1::SetApplyGuildId( const vector<INT32>& v )
{
	m_syncDataUserData.SetApplyGuildId(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_APPLYGUILDID);
	SendApplyGuildId(false);
}
void SyncDataBaseAttrV1::SetApplyGuildId( int Index, const INT32& v )
{
	m_syncDataUserData.SetApplyGuildId(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_APPLYGUILDID,Index);
	SendApplyGuildId(Index,false);
}
vector<INT32> SyncDataBaseAttrV1::GetApplyGuildId()
{
	return m_syncDataUserData.GetApplyGuildId();
}
INT32 SyncDataBaseAttrV1::GetApplyGuildId( int Index )
{
	return m_syncDataUserData.GetApplyGuildId(Index);
}
void SyncDataBaseAttrV1::SendApplyGuildId(bool OnlyToClient)
{
	SendApplyGuildId(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizeApplyGuildId(); i++)
		SendApplyGuildId(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendApplyGuildId( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_APPLYGUILDID,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_APPLYGUILDID)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_APPLYGUILDID,Index,NULL,0);
		return;
	}
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_APPLYGUILDID,Index,m_syncDataUserData.GetApplyGuildId(Index));
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_APPLYGUILDID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_APPLYGUILDID,Index,m_syncDataUserData.GetApplyGuildId(Index));
}
void SyncDataBaseAttrV1::AddApplyGuildId( INT32 v )
{
	m_syncDataUserData.AddApplyGuildId(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizeApplyGuildId()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_APPLYGUILDID,Index);
	SendApplyGuildId(Index,false);
}

//当前帮贡
void SyncDataBaseAttrV1::SetCurGuildContribution( const INT32& v )
{
	m_syncDataUserData.SetCurGuildContribution(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_CURGUILDCONTRIBUTION);
	SendCurGuildContribution(false);
}
INT32 SyncDataBaseAttrV1::GetCurGuildContribution()
{
	return m_syncDataUserData.GetCurGuildContribution();
}
void SyncDataBaseAttrV1::SendCurGuildContribution(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_CURGUILDCONTRIBUTION,m_syncDataUserData.GetCurGuildContribution());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_CURGUILDCONTRIBUTION)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_CURGUILDCONTRIBUTION,m_syncDataUserData.GetCurGuildContribution());
}

//最大帮贡
void SyncDataBaseAttrV1::SetMaxGuildContribution( const INT32& v )
{
	m_syncDataUserData.SetMaxGuildContribution(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_MAXGUILDCONTRIBUTION);
	SendMaxGuildContribution(false);
}
INT32 SyncDataBaseAttrV1::GetMaxGuildContribution()
{
	return m_syncDataUserData.GetMaxGuildContribution();
}
void SyncDataBaseAttrV1::SendMaxGuildContribution(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_MAXGUILDCONTRIBUTION,m_syncDataUserData.GetMaxGuildContribution());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_MAXGUILDCONTRIBUTION)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_MAXGUILDCONTRIBUTION,m_syncDataUserData.GetMaxGuildContribution());
}

//绑银
void SyncDataBaseAttrV1::SetBindMoney( const INT32& v )
{
	m_syncDataUserData.SetBindMoney(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_BINDMONEY);
	SendBindMoney(false);
}
INT32 SyncDataBaseAttrV1::GetBindMoney()
{
	return m_syncDataUserData.GetBindMoney();
}
void SyncDataBaseAttrV1::SendBindMoney(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_BINDMONEY,m_syncDataUserData.GetBindMoney());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_BINDMONEY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_BINDMONEY,m_syncDataUserData.GetBindMoney());
}

//宝石
void SyncDataBaseAttrV1::SetGem( const INT32& v )
{
	m_syncDataUserData.SetGem(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_GEM);
	SendGem(false);
}
INT32 SyncDataBaseAttrV1::GetGem()
{
	return m_syncDataUserData.GetGem();
}
void SyncDataBaseAttrV1::SendGem(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_GEM,m_syncDataUserData.GetGem());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_GEM)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_GEM,m_syncDataUserData.GetGem());
}

//服务器时间
void SyncDataBaseAttrV1::SetServerTime( const INT32& v )
{
	m_syncDataUserData.SetServerTime(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_SERVERTIME);
	SendServerTime(false);
}
INT32 SyncDataBaseAttrV1::GetServerTime()
{
	return m_syncDataUserData.GetServerTime();
}
void SyncDataBaseAttrV1::SendServerTime(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_SERVERTIME,m_syncDataUserData.GetServerTime());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_SERVERTIME)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_SERVERTIME,m_syncDataUserData.GetServerTime());
}

//新手引导
void SyncDataBaseAttrV1::SetNewbieGuide( const vector<KeyValue2IntIntWraper>& v )
{
	m_syncDataUserData.SetNewbieGuide(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_NEWBIEGUIDE);
	SendNewbieGuide(false);
}
void SyncDataBaseAttrV1::SetNewbieGuide( int Index, const KeyValue2IntIntWraper& v )
{
	m_syncDataUserData.SetNewbieGuide(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_NEWBIEGUIDE,Index);
	SendNewbieGuide(Index,false);
}
vector<KeyValue2IntIntWraper> SyncDataBaseAttrV1::GetNewbieGuide()
{
	return m_syncDataUserData.GetNewbieGuide();
}
KeyValue2IntIntWraper SyncDataBaseAttrV1::GetNewbieGuide( int Index )
{
	return m_syncDataUserData.GetNewbieGuide(Index);
}
void SyncDataBaseAttrV1::SendNewbieGuide(bool OnlyToClient)
{
	SendNewbieGuide(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizeNewbieGuide(); i++)
		SendNewbieGuide(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendNewbieGuide( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_NEWBIEGUIDE,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_NEWBIEGUIDE)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_NEWBIEGUIDE,Index,NULL,0);
		return;
	}
	const string v= GetNewbieGuide(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_NEWBIEGUIDE,Index,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_NEWBIEGUIDE)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_NEWBIEGUIDE,Index,v.data(),v.size());
}
void SyncDataBaseAttrV1::AddNewbieGuide( const KeyValue2IntIntWraper& v )
{
	m_syncDataUserData.AddNewbieGuide(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizeNewbieGuide()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_NEWBIEGUIDE,Index);
	SendNewbieGuide(Index,false);
}

//江洋大盗奖励次数
void SyncDataBaseAttrV1::SetThiefRewardNum( const INT32& v )
{
	m_syncDataUserData.SetThiefRewardNum(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_THIEFREWARDNUM);
	SendThiefRewardNum(false);
}
INT32 SyncDataBaseAttrV1::GetThiefRewardNum()
{
	return m_syncDataUserData.GetThiefRewardNum();
}
void SyncDataBaseAttrV1::SendThiefRewardNum(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_THIEFREWARDNUM,m_syncDataUserData.GetThiefRewardNum());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_THIEFREWARDNUM)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_THIEFREWARDNUM,m_syncDataUserData.GetThiefRewardNum());
}

//降妖奖励次数
void SyncDataBaseAttrV1::SetSubdueMonsterRewardNum( const INT32& v )
{
	m_syncDataUserData.SetSubdueMonsterRewardNum(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_SUBDUEMONSTERREWARDNUM);
	SendSubdueMonsterRewardNum(false);
}
INT32 SyncDataBaseAttrV1::GetSubdueMonsterRewardNum()
{
	return m_syncDataUserData.GetSubdueMonsterRewardNum();
}
void SyncDataBaseAttrV1::SendSubdueMonsterRewardNum(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_SUBDUEMONSTERREWARDNUM,m_syncDataUserData.GetSubdueMonsterRewardNum());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_SUBDUEMONSTERREWARDNUM)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_SUBDUEMONSTERREWARDNUM,m_syncDataUserData.GetSubdueMonsterRewardNum());
}

//世界Boss剩余次数
void SyncDataBaseAttrV1::SetWorldBossRemainTimes( const INT32& v )
{
	m_syncDataUserData.SetWorldBossRemainTimes(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_WORLDBOSSREMAINTIMES);
	SendWorldBossRemainTimes(false);
}
INT32 SyncDataBaseAttrV1::GetWorldBossRemainTimes()
{
	return m_syncDataUserData.GetWorldBossRemainTimes();
}
void SyncDataBaseAttrV1::SendWorldBossRemainTimes(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_WORLDBOSSREMAINTIMES,m_syncDataUserData.GetWorldBossRemainTimes());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_WORLDBOSSREMAINTIMES)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_WORLDBOSSREMAINTIMES,m_syncDataUserData.GetWorldBossRemainTimes());
}

//世界Boss伤害
void SyncDataBaseAttrV1::SetWorldBossHurt( const INT32& v )
{
	m_syncDataUserData.SetWorldBossHurt(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_WORLDBOSSHURT);
	SendWorldBossHurt(false);
}
INT32 SyncDataBaseAttrV1::GetWorldBossHurt()
{
	return m_syncDataUserData.GetWorldBossHurt();
}
void SyncDataBaseAttrV1::SendWorldBossHurt(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_WORLDBOSSHURT,m_syncDataUserData.GetWorldBossHurt());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_WORLDBOSSHURT)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_WORLDBOSSHURT,m_syncDataUserData.GetWorldBossHurt());
}

//功能开启列表
void SyncDataBaseAttrV1::SetFunctionOpenList( const vector<BaseAttrIconOpenInfoWraperV1>& v )
{
	m_syncDataUserData.SetFunctionOpenList(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_FUNCTIONOPENLIST);
	SendFunctionOpenList(false);
}
void SyncDataBaseAttrV1::SetFunctionOpenList( int Index, const BaseAttrIconOpenInfoWraperV1& v )
{
	m_syncDataUserData.SetFunctionOpenList(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_FUNCTIONOPENLIST,Index);
	SendFunctionOpenList(Index,false);
}
vector<BaseAttrIconOpenInfoWraperV1> SyncDataBaseAttrV1::GetFunctionOpenList()
{
	return m_syncDataUserData.GetFunctionOpenList();
}
BaseAttrIconOpenInfoWraperV1 SyncDataBaseAttrV1::GetFunctionOpenList( int Index )
{
	return m_syncDataUserData.GetFunctionOpenList(Index);
}
void SyncDataBaseAttrV1::SendFunctionOpenList(bool OnlyToClient)
{
	SendFunctionOpenList(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizeFunctionOpenList(); i++)
		SendFunctionOpenList(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendFunctionOpenList( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_FUNCTIONOPENLIST,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_FUNCTIONOPENLIST)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_FUNCTIONOPENLIST,Index,NULL,0);
		return;
	}
	const string v= GetFunctionOpenList(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_FUNCTIONOPENLIST,Index,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_FUNCTIONOPENLIST)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_FUNCTIONOPENLIST,Index,v.data(),v.size());
}
void SyncDataBaseAttrV1::AddFunctionOpenList( const BaseAttrIconOpenInfoWraperV1& v )
{
	m_syncDataUserData.AddFunctionOpenList(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizeFunctionOpenList()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_FUNCTIONOPENLIST,Index);
	SendFunctionOpenList(Index,false);
}

//总活力值
void SyncDataBaseAttrV1::SetTotalEnergyValue( const INT32& v )
{
	m_syncDataUserData.SetTotalEnergyValue(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_TOTALENERGYVALUE);
	SendTotalEnergyValue(false);
}
INT32 SyncDataBaseAttrV1::GetTotalEnergyValue()
{
	return m_syncDataUserData.GetTotalEnergyValue();
}
void SyncDataBaseAttrV1::SendTotalEnergyValue(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_TOTALENERGYVALUE,m_syncDataUserData.GetTotalEnergyValue());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_TOTALENERGYVALUE)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_TOTALENERGYVALUE,m_syncDataUserData.GetTotalEnergyValue());
}

//活力值信息容器
void SyncDataBaseAttrV1::SetEnergyArray( const vector<BaseAttrEnergyInfoWraperV1>& v )
{
	m_syncDataUserData.SetEnergyArray(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_ENERGYARRAY);
	SendEnergyArray(false);
}
void SyncDataBaseAttrV1::SetEnergyArray( int Index, const BaseAttrEnergyInfoWraperV1& v )
{
	m_syncDataUserData.SetEnergyArray(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_ENERGYARRAY,Index);
	SendEnergyArray(Index,false);
}
vector<BaseAttrEnergyInfoWraperV1> SyncDataBaseAttrV1::GetEnergyArray()
{
	return m_syncDataUserData.GetEnergyArray();
}
BaseAttrEnergyInfoWraperV1 SyncDataBaseAttrV1::GetEnergyArray( int Index )
{
	return m_syncDataUserData.GetEnergyArray(Index);
}
void SyncDataBaseAttrV1::SendEnergyArray(bool OnlyToClient)
{
	SendEnergyArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizeEnergyArray(); i++)
		SendEnergyArray(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendEnergyArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_ENERGYARRAY,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_ENERGYARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_ENERGYARRAY,Index,NULL,0);
		return;
	}
	const string v= GetEnergyArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_ENERGYARRAY,Index,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_ENERGYARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_ENERGYARRAY,Index,v.data(),v.size());
}
void SyncDataBaseAttrV1::AddEnergyArray( const BaseAttrEnergyInfoWraperV1& v )
{
	m_syncDataUserData.AddEnergyArray(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizeEnergyArray()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_ENERGYARRAY,Index);
	SendEnergyArray(Index,false);
}

//PK状态
void SyncDataBaseAttrV1::SetPKState( const INT32& v )
{
	m_syncDataUserData.SetPKState(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_PKSTATE);
	SendPKState(false);
}
INT32 SyncDataBaseAttrV1::GetPKState()
{
	return m_syncDataUserData.GetPKState();
}
void SyncDataBaseAttrV1::SendPKState(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_PKSTATE,m_syncDataUserData.GetPKState());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_PKSTATE)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_PKSTATE,m_syncDataUserData.GetPKState());
}

//PK保护列表
void SyncDataBaseAttrV1::SetPKProtect( const vector<KeyValue2IntBoolWraper>& v )
{
	m_syncDataUserData.SetPKProtect(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_PKPROTECT);
	SendPKProtect(false);
}
void SyncDataBaseAttrV1::SetPKProtect( int Index, const KeyValue2IntBoolWraper& v )
{
	m_syncDataUserData.SetPKProtect(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_PKPROTECT,Index);
	SendPKProtect(Index,false);
}
vector<KeyValue2IntBoolWraper> SyncDataBaseAttrV1::GetPKProtect()
{
	return m_syncDataUserData.GetPKProtect();
}
KeyValue2IntBoolWraper SyncDataBaseAttrV1::GetPKProtect( int Index )
{
	return m_syncDataUserData.GetPKProtect(Index);
}
void SyncDataBaseAttrV1::SendPKProtect(bool OnlyToClient)
{
	SendPKProtect(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizePKProtect(); i++)
		SendPKProtect(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendPKProtect( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_PKPROTECT,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_PKPROTECT)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_PKPROTECT,Index,NULL,0);
		return;
	}
	const string v= GetPKProtect(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_PKPROTECT,Index,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_PKPROTECT)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_PKPROTECT,Index,v.data(),v.size());
}
void SyncDataBaseAttrV1::AddPKProtect( const KeyValue2IntBoolWraper& v )
{
	m_syncDataUserData.AddPKProtect(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizePKProtect()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_PKPROTECT,Index);
	SendPKProtect(Index,false);
}

//帮会修炼
void SyncDataBaseAttrV1::SetGuildScienArray( const vector<BaseAttrScienceInfoWraperV1>& v )
{
	m_syncDataUserData.SetGuildScienArray(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_GUILDSCIENARRAY);
	SendGuildScienArray(false);
}
void SyncDataBaseAttrV1::SetGuildScienArray( int Index, const BaseAttrScienceInfoWraperV1& v )
{
	m_syncDataUserData.SetGuildScienArray(Index,v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_GUILDSCIENARRAY,Index);
	SendGuildScienArray(Index,false);
}
vector<BaseAttrScienceInfoWraperV1> SyncDataBaseAttrV1::GetGuildScienArray()
{
	return m_syncDataUserData.GetGuildScienArray();
}
BaseAttrScienceInfoWraperV1 SyncDataBaseAttrV1::GetGuildScienArray( int Index )
{
	return m_syncDataUserData.GetGuildScienArray(Index);
}
void SyncDataBaseAttrV1::SendGuildScienArray(bool OnlyToClient)
{
	SendGuildScienArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataUserData.SizeGuildScienArray(); i++)
		SendGuildScienArray(i,OnlyToClient);
}
void SyncDataBaseAttrV1::SendGuildScienArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_GUILDSCIENARRAY,Index,NULL,0);
		if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_GUILDSCIENARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_GUILDSCIENARRAY,Index,NULL,0);
		return;
	}
	const string v= GetGuildScienArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_GUILDSCIENARRAY,Index,v.data(),v.size());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_GUILDSCIENARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_GUILDSCIENARRAY,Index,v.data(),v.size());
}
void SyncDataBaseAttrV1::AddGuildScienArray( const BaseAttrScienceInfoWraperV1& v )
{
	m_syncDataUserData.AddGuildScienArray(v);
	OnDataChange();
	int Index = m_syncDataUserData.SizeGuildScienArray()-1;
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_GUILDSCIENARRAY,Index);
	SendGuildScienArray(Index,false);
}

//修炼升级消耗总金币
void SyncDataBaseAttrV1::SetScienceTotalMoney( const INT32& v )
{
	m_syncDataUserData.SetScienceTotalMoney(v);
	OnDataChange();
	ModuleBaseAttr::Instance().NotifySyncValueChanged(m_syncDataUserData.GetKey(),SYNCID_BASEATTR_SCIENCETOTALMONEY);
	SendScienceTotalMoney(false);
}
INT32 SyncDataBaseAttrV1::GetScienceTotalMoney()
{
	return m_syncDataUserData.GetScienceTotalMoney();
}
void SyncDataBaseAttrV1::SendScienceTotalMoney(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_BASEATTR_SCIENCETOTALMONEY,m_syncDataUserData.GetScienceTotalMoney());
	if(ModuleBaseAttr::Instance().NotSyncToClient(SYNCID_BASEATTR_SCIENCETOTALMONEY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_BASEATTR_SCIENCETOTALMONEY,m_syncDataUserData.GetScienceTotalMoney());
}
