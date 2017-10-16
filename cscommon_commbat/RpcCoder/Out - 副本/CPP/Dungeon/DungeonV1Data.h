#ifndef __SYNC_DATA_DUNGEON_V1_H
#define __SYNC_DATA_DUNGEON_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "DungeonV1DataWraper.h"


//同步数据相关枚举量定义
enum DungeonSyncDataItemIdE
{
 	SYNCID_DUNGEON_DUNGEONKEY                   = 1201,  //Key
 	SYNCID_DUNGEON_DUNGEONID                    = 1202,  //副本ID
 	SYNCID_DUNGEON_DUNGEONTYPE                  = 1203,  //副本类型
 	SYNCID_DUNGEON_KEYID                        = 1204,  //KeyId
 	SYNCID_DUNGEON_HOST                         = 1205,  //Host
 	SYNCID_DUNGEON_PORT                         = 1206,  //Port
 	SYNCID_DUNGEON_GUILD                        = 1207,  //帮派Id

};


//主同步数据操作类
class SyncDataDungeonV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataDungeonV1>
{
public:
			SyncDataDungeonV1();
	virtual	~SyncDataDungeonV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataDungeonInfo.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataDungeonInfo.HtmlDescHeader(); }
public:
	//Key
	void SetDungeonKey( const string& v );
	string GetDungeonKey();
	void SendDungeonKey(bool OnlyToClient=true);
public:
	//副本ID
	void SetDungeonId( const INT32& v );
	INT32 GetDungeonId();
	void SendDungeonId(bool OnlyToClient=true);
public:
	//副本类型
	void SetDungeonType( const INT32& v );
	INT32 GetDungeonType();
	void SendDungeonType(bool OnlyToClient=true);
public:
	//KeyId
	void SetKeyId( const INT32& v );
	INT32 GetKeyId();
	void SendKeyId(bool OnlyToClient=true);
public:
	//Host
	void SetHost( const string& v );
	string GetHost();
	void SendHost(bool OnlyToClient=true);
public:
	//Port
	void SetPort( const INT32& v );
	INT32 GetPort();
	void SendPort(bool OnlyToClient=true);
public:
	//帮派Id
	void SetGuild( const INT32& v );
	INT32 GetGuild();
	void SendGuild(bool OnlyToClient=true);


private:
	DungeonDungeonInfoWraperV1 m_syncDataDungeonInfo;

};



#endif
