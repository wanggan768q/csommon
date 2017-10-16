#ifndef __SYNC_DATA_ACTION_V1_H
#define __SYNC_DATA_ACTION_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "ActionV1DataWraper.h"


//同步数据相关枚举量定义
enum ActionSyncDataItemIdE
{

};


//主同步数据操作类
class SyncDataActionV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataActionV1>
{
public:
			SyncDataActionV1();
	virtual	~SyncDataActionV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUseless.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUseless.HtmlDescHeader(); }


private:
	ActionUselessWraperV1 m_syncDataUseless;

};



#endif
