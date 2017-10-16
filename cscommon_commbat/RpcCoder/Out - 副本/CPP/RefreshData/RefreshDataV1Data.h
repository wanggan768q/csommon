#ifndef __SYNC_DATA_REFRESHDATA_V1_H
#define __SYNC_DATA_REFRESHDATA_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "RefreshDataV1DataWraper.h"


//同步数据相关枚举量定义
enum RefreshDataSyncDataItemIdE
{
 	SYNCID_REFRESHDATA_LASTREFRESHTIME          = 3901,  //上次刷新

};


//主同步数据操作类
class SyncDataRefreshDataV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataRefreshDataV1>
{
public:
			SyncDataRefreshDataV1();
	virtual	~SyncDataRefreshDataV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataRefreshData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataRefreshData.HtmlDescHeader(); }
public:
	//上次刷新
	void SetLastRefreshTime( const INT32& v );
	INT32 GetLastRefreshTime();
	void SendLastRefreshTime(bool OnlyToClient=true);


private:
	RefreshDataRefreshDataWraperV1 m_syncDataRefreshData;

};



#endif
