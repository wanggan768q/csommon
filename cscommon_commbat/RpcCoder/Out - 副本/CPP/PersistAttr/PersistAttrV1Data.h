#ifndef __SYNC_DATA_PERSISTATTR_V1_H
#define __SYNC_DATA_PERSISTATTR_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "PersistAttrV1DataWraper.h"


//同步数据相关枚举量定义
enum PersistAttrSyncDataItemIdE
{
 	SYNCID_PERSISTATTR_USERNAME                 = 1001,  //战队名字
 	SYNCID_PERSISTATTR_USERID                   = 1003,  //用户ID
 	SYNCID_PERSISTATTR_PLATNAME                 = 1004,  //游戏中心账号名
 	SYNCID_PERSISTATTR_ACCOUNTID                = 1021,  //游戏中心账号ID
 	SYNCID_PERSISTATTR_LEVEL                    = 1030,  //战队等级
 	SYNCID_PERSISTATTR_RANK                     = 1031,  //官阶
 	SYNCID_PERSISTATTR_FIGHTPOWER               = 1032,  //战力
 	SYNCID_PERSISTATTR_SEC                      = 1033,  //登录时间秒
 	SYNCID_PERSISTATTR_PROF                     = 1035,  //职业
 	SYNCID_PERSISTATTR_ONLINESTATE              = 1036,  //在线状态
 	SYNCID_PERSISTATTR_TEAMID                   = 1037,  //组队id
 	SYNCID_PERSISTATTR_SHOPSCORE                = 1039,  //几分商城
 	SYNCID_PERSISTATTR_DUNGEONID                = 1042,  //当前场景Id
 	SYNCID_PERSISTATTR_SESSIONKEY               = 1043,  //SessionKey
 	SYNCID_PERSISTATTR_GUILDID                  = 1044,  //帮会Id

};


//主同步数据操作类
class SyncDataPersistAttrV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataPersistAttrV1>
{
public:
			SyncDataPersistAttrV1();
	virtual	~SyncDataPersistAttrV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataPersistAttr.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataPersistAttr.HtmlDescHeader(); }
public:
	//战队名字
	void SetUserName( const string& v );
	string GetUserName();
	void SendUserName(bool OnlyToClient=true);
public:
	//用户ID
	void SetUserId( const INT64& v );
	INT64 GetUserId();
	void SendUserId(bool OnlyToClient=true);
public:
	//游戏中心账号名
	void SetPlatName( const string& v );
	string GetPlatName();
	void SendPlatName(bool OnlyToClient=true);
public:
	//游戏中心账号ID
	void SetAccountId( const INT64& v );
	INT64 GetAccountId();
	void SendAccountId(bool OnlyToClient=true);
public:
	//战队等级
	void SetLevel( const INT32& v );
	INT32 GetLevel();
	void SendLevel(bool OnlyToClient=true);
public:
	//官阶
	void SetRank( const INT32& v );
	INT32 GetRank();
	void SendRank(bool OnlyToClient=true);
public:
	//战力
	void SetFightPower( const INT32& v );
	INT32 GetFightPower();
	void SendFightPower(bool OnlyToClient=true);
public:
	//登录时间秒
	void SetSec( const INT32& v );
	INT32 GetSec();
	void SendSec(bool OnlyToClient=true);
public:
	//职业
	void SetProf( const INT32& v );
	INT32 GetProf();
	void SendProf(bool OnlyToClient=true);
public:
	//在线状态
	void SetOnlineState( const INT32& v );
	INT32 GetOnlineState();
	void SendOnlineState(bool OnlyToClient=true);
public:
	//组队id
	void SetTeamId( const INT32& v );
	INT32 GetTeamId();
	void SendTeamId(bool OnlyToClient=true);
public:
	//几分商城
	void SetShopScore( const INT32& v );
	INT32 GetShopScore();
	void SendShopScore(bool OnlyToClient=true);
public:
	//当前场景Id
	void SetDungeonId( const INT32& v );
	INT32 GetDungeonId();
	void SendDungeonId(bool OnlyToClient=true);
public:
	//SessionKey
	void SetSessionKey( const string& v );
	string GetSessionKey();
	void SendSessionKey(bool OnlyToClient=true);
public:
	//帮会Id
	void SetGuildId( const INT32& v );
	INT32 GetGuildId();
	void SendGuildId(bool OnlyToClient=true);


private:
	PersistAttrPersistAttrWraperV1 m_syncDataPersistAttr;

};



#endif
