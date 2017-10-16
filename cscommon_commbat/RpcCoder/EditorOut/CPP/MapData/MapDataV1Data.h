#ifndef __SYNC_DATA_MAPDATA_V1_H
#define __SYNC_DATA_MAPDATA_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "MapDataV1DataWraper.h"


//同步数据相关枚举量定义
enum MapDataSyncDataItemIdE
{
 	SYNCID_MAPDATA_X1                           = 2001,  //X1

};


//主同步数据操作类
class SyncDataMapDataV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataMapDataV1>
{
public:
			SyncDataMapDataV1();
	virtual	~SyncDataMapDataV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUseless.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUseless.HtmlDescHeader(); }
public:
	//X1
	void SetX1( const INT32& v );
	INT32 GetX1();
	void SendX1(bool OnlyToClient=true);


private:
	MapDataUselessWraperV1 m_syncDataUseless;

};



#endif
