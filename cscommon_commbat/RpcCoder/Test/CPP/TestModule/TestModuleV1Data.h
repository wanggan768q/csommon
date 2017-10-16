#ifndef __SYNC_DATA_TESTMODULE_V1_H
#define __SYNC_DATA_TESTMODULE_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "TestModuleV1DataWraper.h"


//同步数据相关枚举量定义
enum TestModuleSyncDataItemIdE
{

};


//主同步数据操作类
class SyncDataTestModuleV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataTestModuleV1>
{
public:
			SyncDataTestModuleV1();
	virtual	~SyncDataTestModuleV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUseless.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUseless.HtmlDescHeader(); }


private:
	TestModuleUselessWraperV1 m_syncDataUseless;

};



#endif
