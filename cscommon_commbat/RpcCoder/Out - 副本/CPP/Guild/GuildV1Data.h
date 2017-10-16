#ifndef __SYNC_DATA_GUILD_V1_H
#define __SYNC_DATA_GUILD_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "GuildV1DataWraper.h"


//同步数据相关枚举量定义
enum GuildSyncDataItemIdE
{
 	SYNCID_GUILD_GUILDDATA                      = 3401,  //帮会数据

};


//主同步数据操作类
class SyncDataGuildV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataGuildV1>
{
public:
			SyncDataGuildV1();
	virtual	~SyncDataGuildV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataGuildList.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataGuildList.HtmlDescHeader(); }
public:
	//帮会数据
	void SetGuildData( const GuildInfoObjWraper& v );
	GuildInfoObjWraper GetGuildData();
	void SendGuildData(bool OnlyToClient=true);


private:
	GuildGuildListWraperV1 m_syncDataGuildList;

};



#endif
