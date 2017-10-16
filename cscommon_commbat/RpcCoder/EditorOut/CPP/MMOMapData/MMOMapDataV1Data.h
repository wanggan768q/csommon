#ifndef __SYNC_DATA_MMOMAPDATA_V1_H
#define __SYNC_DATA_MMOMAPDATA_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "MMOMapDataV1DataWraper.h"


//同步数据相关枚举量定义
enum MMOMapDataSyncDataItemIdE
{

};


//主同步数据操作类
class SyncDataMMOMapDataV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataMMOMapDataV1>
{
public:
			SyncDataMMOMapDataV1();
	virtual	~SyncDataMMOMapDataV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUseless.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUseless.HtmlDescHeader(); }


private:
	MMOMapDataUselessWraperV1 m_syncDataUseless;

};



#endif
