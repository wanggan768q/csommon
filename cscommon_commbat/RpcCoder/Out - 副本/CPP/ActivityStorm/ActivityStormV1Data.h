#ifndef __SYNC_DATA_ACTIVITYSTORM_V1_H
#define __SYNC_DATA_ACTIVITYSTORM_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "ActivityStormV1DataWraper.h"


//同步数据相关枚举量定义
enum ActivityStormSyncDataItemIdE
{
 	SYNCID_ACTIVITYSTORM_TYPE                   = 3001,  //类型
 	SYNCID_ACTIVITYSTORM_TIME                   = 3002,  //倒计时时间
 	SYNCID_ACTIVITYSTORM_ACTID                  = 3003,  //战斗id 需要确认时候带回
 	SYNCID_ACTIVITYSTORM_LVD                    = 3004,  //等级段

};


//主同步数据操作类
class SyncDataActivityStormV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataActivityStormV1>
{
public:
			SyncDataActivityStormV1();
	virtual	~SyncDataActivityStormV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataActivityStorm.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataActivityStorm.HtmlDescHeader(); }
public:
	//类型
	void SetType( const INT32& v );
	INT32 GetType();
	void SendType(bool OnlyToClient=true);
public:
	//倒计时时间
	void SetTime( const INT32& v );
	INT32 GetTime();
	void SendTime(bool OnlyToClient=true);
public:
	//战斗id 需要确认时候带回
	void SetActID( const INT32& v );
	INT32 GetActID();
	void SendActID(bool OnlyToClient=true);
public:
	//等级段
	void SetLvD( const INT32& v );
	INT32 GetLvD();
	void SendLvD(bool OnlyToClient=true);


private:
	ActivityStormActivityStormWraperV1 m_syncDataActivityStorm;

};



#endif
