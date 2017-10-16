#ifndef __SYNC_DATA_DRAMAMODULE_V1_H
#define __SYNC_DATA_DRAMAMODULE_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "DramaModuleV1DataWraper.h"


//同步数据相关枚举量定义
enum DramaModuleSyncDataItemIdE
{

};


//主同步数据操作类
class SyncDataDramaModuleV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataDramaModuleV1>
{
public:
			SyncDataDramaModuleV1();
	virtual	~SyncDataDramaModuleV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUseLess.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUseLess.HtmlDescHeader(); }


private:
	DramaModuleUseLessWraperV1 m_syncDataUseLess;

};



#endif
