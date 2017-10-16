/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     SyncWraperPersistAttr.h
* Author:       甘业清
* Description:  常驻内存属性模块同步数据结构的类封装
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __SYNC_WRAPER_PERSISTATTR_H
#define __SYNC_WRAPER_PERSISTATTR_H

#include "BASE.h"
#include "PublicStructWraper.h"
#include "PersistAttrV1Data.pb.h"
#include "DataWraperInterface.h"
#include "ModuleDataClassFactory.h"
#include "ModuleDataInterface.h"



//Cache属性数据封装类
class PersistAttrPersistAttrWraperV1 : public DataWraperInterface , public ModuleDataInterface , public ModuleDataRegister<PersistAttrPersistAttrWraperV1>
{
public:
	//构造函数
	PersistAttrPersistAttrWraperV1()
	{
		SetDataWraper( this );

		m_UserName = "";
		m_UserId = -1;
		m_PlatName = "";
		m_AccountId = -1;
		m_Level = -1;
		m_Rank = -1;
		m_FightPower = -1;
		m_Sec = -1;
		m_Prof = -1;
		m_OnlineState = -1;
		m_TeamId = -1;
		m_ShopScore = -1;
		m_DungeonId = -1;
		m_SessionKey = "";
		m_GuildId = -1;

	}
	//赋值构造函数
	PersistAttrPersistAttrWraperV1(const PersistAttrPersistAttrV1& v){ Init(v); }
	//等号重载函数
	void operator = (const PersistAttrPersistAttrV1& v){ Init(v); }
 	//转化成Protobuffer类型函数
	PersistAttrPersistAttrV1 ToPB() const
	{
		PersistAttrPersistAttrV1 v;
		v.set_username( m_UserName );
		v.set_userid( m_UserId );
		v.set_platname( m_PlatName );
		v.set_accountid( m_AccountId );
		v.set_level( m_Level );
		v.set_rank( m_Rank );
		v.set_fightpower( m_FightPower );
		v.set_sec( m_Sec );
		v.set_prof( m_Prof );
		v.set_onlinestate( m_OnlineState );
		v.set_teamid( m_TeamId );
		v.set_shopscore( m_ShopScore );
		v.set_dungeonid( m_DungeonId );
		v.set_sessionkey( m_SessionKey );
		v.set_guildid( m_GuildId );

		return v;
	}
	//获取Protobuffer序列化后大小函数
	int ByteSize() const { return ToPB().ByteSize();}
	//Protobuffer序列化到缓冲区
	bool SerializeToArray( void* data, int size ) const
	{
		return ToPB().SerializeToArray(data,size);
	}
	//Protobuffer序列化到字符串
	string SerializeAsString() const
	{
		return ToPB().SerializeAsString();
	}
	//Protobuffer从字符串进行反序列化
	bool ParseFromString(const string& v)
	{
		return ParseFromArray(v.data(),v.size());
	}
	//Protobuffer从缓冲区进行反序列化
	bool ParseFromArray(const void* data, int size)
	{
		PersistAttrPersistAttrV1 pb;
		if(!pb.ParseFromArray(data,size)){return false;}
		Init(pb);
		return true;
	}

	string HtmlDescHeader()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		htmlBuff += "<li>UserName(战队名字) [string]</li>\r\n";
		htmlBuff += "<li>UserId(用户ID) [sint64]</li>\r\n";
		htmlBuff += "<li>PlatName(游戏中心账号名) [string]</li>\r\n";
		htmlBuff += "<li>AccountId(游戏中心账号ID) [sint64]</li>\r\n";
		htmlBuff += "<li>Level(战队等级) [sint32]</li>\r\n";
		htmlBuff += "<li>Rank(官阶) [sint32]</li>\r\n";
		htmlBuff += "<li>FightPower(战力) [sint32]</li>\r\n";
		htmlBuff += "<li>Sec(登录时间秒) [sint32]</li>\r\n";
		htmlBuff += "<li>Prof(职业) [sint32]</li>\r\n";
		htmlBuff += "<li>OnlineState(在线状态) [sint32]</li>\r\n";
		htmlBuff += "<li>TeamId(组队id) [sint32]</li>\r\n";
		htmlBuff += "<li>ShopScore(几分商城) [sint32]</li>\r\n";
		htmlBuff += "<li>DungeonId(当前场景Id) [sint32]</li>\r\n";
		htmlBuff += "<li>SessionKey(SessionKey) [string]</li>\r\n";
		htmlBuff += "<li>GuildId(帮会Id) [sint32]</li>\r\n";

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}

	string ToHtml()
	{
		string htmlBuff = "<div style=\"padding-left:30px\">\r\n";
		TStr tmpLine;
		htmlBuff += "<li>UserName：\""+m_UserName+"\"</li>\r\n";
		tmpLine.Fmt("<li>UserId：%lldL</li>\r\n",m_UserId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>PlatName：\""+m_PlatName+"\"</li>\r\n";
		tmpLine.Fmt("<li>AccountId：%lldL</li>\r\n",m_AccountId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Level：%di</li>\r\n",m_Level);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Rank：%di</li>\r\n",m_Rank);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>FightPower：%di</li>\r\n",m_FightPower);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Sec：%di</li>\r\n",m_Sec);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>Prof：%di</li>\r\n",m_Prof);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>OnlineState：%di</li>\r\n",m_OnlineState);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>TeamId：%di</li>\r\n",m_TeamId);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>ShopScore：%di</li>\r\n",m_ShopScore);
		htmlBuff += tmpLine;
		tmpLine.Fmt("<li>DungeonId：%di</li>\r\n",m_DungeonId);
		htmlBuff += tmpLine;
		htmlBuff += "<li>SessionKey：\""+m_SessionKey+"\"</li>\r\n";
		tmpLine.Fmt("<li>GuildId：%di</li>\r\n",m_GuildId);
		htmlBuff += tmpLine;

		
		htmlBuff += "</div>\r\n";
		return htmlBuff;
	}


private:
	//从Protobuffer类型初始化
	void Init(const PersistAttrPersistAttrV1& v)
	{
		m_UserName = v.username();
		m_UserId = v.userid();
		m_PlatName = v.platname();
		m_AccountId = v.accountid();
		m_Level = v.level();
		m_Rank = v.rank();
		m_FightPower = v.fightpower();
		m_Sec = v.sec();
		m_Prof = v.prof();
		m_OnlineState = v.onlinestate();
		m_TeamId = v.teamid();
		m_ShopScore = v.shopscore();
		m_DungeonId = v.dungeonid();
		m_SessionKey = v.sessionkey();
		m_GuildId = v.guildid();

	}

private:
	//战队名字
	string m_UserName;
public:
	void SetUserName( const string& v)
	{
		m_UserName=v;
	}
	string GetUserName()
	{
		return m_UserName;
	}
	string GetUserName() const
	{
		return m_UserName;
	}
private:
	//用户ID
	INT64 m_UserId;
public:
	void SetUserId( INT64 v)
	{
		m_UserId=v;
	}
	INT64 GetUserId()
	{
		return m_UserId;
	}
	INT64 GetUserId() const
	{
		return m_UserId;
	}
private:
	//游戏中心账号名
	string m_PlatName;
public:
	void SetPlatName( const string& v)
	{
		m_PlatName=v;
	}
	string GetPlatName()
	{
		return m_PlatName;
	}
	string GetPlatName() const
	{
		return m_PlatName;
	}
private:
	//游戏中心账号ID
	INT64 m_AccountId;
public:
	void SetAccountId( INT64 v)
	{
		m_AccountId=v;
	}
	INT64 GetAccountId()
	{
		return m_AccountId;
	}
	INT64 GetAccountId() const
	{
		return m_AccountId;
	}
private:
	//战队等级
	INT32 m_Level;
public:
	void SetLevel( INT32 v)
	{
		m_Level=v;
	}
	INT32 GetLevel()
	{
		return m_Level;
	}
	INT32 GetLevel() const
	{
		return m_Level;
	}
private:
	//官阶
	INT32 m_Rank;
public:
	void SetRank( INT32 v)
	{
		m_Rank=v;
	}
	INT32 GetRank()
	{
		return m_Rank;
	}
	INT32 GetRank() const
	{
		return m_Rank;
	}
private:
	//战力
	INT32 m_FightPower;
public:
	void SetFightPower( INT32 v)
	{
		m_FightPower=v;
	}
	INT32 GetFightPower()
	{
		return m_FightPower;
	}
	INT32 GetFightPower() const
	{
		return m_FightPower;
	}
private:
	//登录时间秒
	INT32 m_Sec;
public:
	void SetSec( INT32 v)
	{
		m_Sec=v;
	}
	INT32 GetSec()
	{
		return m_Sec;
	}
	INT32 GetSec() const
	{
		return m_Sec;
	}
private:
	//职业
	INT32 m_Prof;
public:
	void SetProf( INT32 v)
	{
		m_Prof=v;
	}
	INT32 GetProf()
	{
		return m_Prof;
	}
	INT32 GetProf() const
	{
		return m_Prof;
	}
private:
	//在线状态
	INT32 m_OnlineState;
public:
	void SetOnlineState( INT32 v)
	{
		m_OnlineState=v;
	}
	INT32 GetOnlineState()
	{
		return m_OnlineState;
	}
	INT32 GetOnlineState() const
	{
		return m_OnlineState;
	}
private:
	//组队id
	INT32 m_TeamId;
public:
	void SetTeamId( INT32 v)
	{
		m_TeamId=v;
	}
	INT32 GetTeamId()
	{
		return m_TeamId;
	}
	INT32 GetTeamId() const
	{
		return m_TeamId;
	}
private:
	//几分商城
	INT32 m_ShopScore;
public:
	void SetShopScore( INT32 v)
	{
		m_ShopScore=v;
	}
	INT32 GetShopScore()
	{
		return m_ShopScore;
	}
	INT32 GetShopScore() const
	{
		return m_ShopScore;
	}
private:
	//当前场景Id
	INT32 m_DungeonId;
public:
	void SetDungeonId( INT32 v)
	{
		m_DungeonId=v;
	}
	INT32 GetDungeonId()
	{
		return m_DungeonId;
	}
	INT32 GetDungeonId() const
	{
		return m_DungeonId;
	}
private:
	//SessionKey
	string m_SessionKey;
public:
	void SetSessionKey( const string& v)
	{
		m_SessionKey=v;
	}
	string GetSessionKey()
	{
		return m_SessionKey;
	}
	string GetSessionKey() const
	{
		return m_SessionKey;
	}
private:
	//帮会Id
	INT32 m_GuildId;
public:
	void SetGuildId( INT32 v)
	{
		m_GuildId=v;
	}
	INT32 GetGuildId()
	{
		return m_GuildId;
	}
	INT32 GetGuildId() const
	{
		return m_GuildId;
	}

};

#endif
