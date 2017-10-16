#ifndef __SYNC_DATA_ZHANDOU_V1_H
#define __SYNC_DATA_ZHANDOU_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "ZhanDouV1DataWraper.h"


//同步数据相关枚举量定义
enum ZhanDouSyncDataItemIdE
{

};


//主同步数据操作类
class SyncDataZhanDouV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataZhanDouV1>
{
public:
			SyncDataZhanDouV1();
	virtual	~SyncDataZhanDouV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUserData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUserData.HtmlDescHeader(); }


private:
	ZhanDouUserDataWraperV1 m_syncDataUserData;

};



#endif
