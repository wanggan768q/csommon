#ifndef __SYNC_DATA_ACTIVITYSCHEDULE_V1_H
#define __SYNC_DATA_ACTIVITYSCHEDULE_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "ActivityScheduleV1DataWraper.h"


//同步数据相关枚举量定义
enum ActivityScheduleSyncDataItemIdE
{
 	SYNCID_ACTIVITYSCHEDULE_VALUE               = 3201,  //数据
 	SYNCID_ACTIVITYSCHEDULE_TIME                = 3202,  //时间（服务器专用）

};


//主同步数据操作类
class SyncDataActivityScheduleV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataActivityScheduleV1>
{
public:
			SyncDataActivityScheduleV1();
	virtual	~SyncDataActivityScheduleV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataActiveDate.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataActiveDate.HtmlDescHeader(); }
public:
	//数据
	void SetValue( const vector<ActivityScheduleActiveValueWraperV1>& v );
	void SetValue( int Index, const ActivityScheduleActiveValueWraperV1& v );
	vector<ActivityScheduleActiveValueWraperV1> GetValue();
	ActivityScheduleActiveValueWraperV1 GetValue( int Index );
	void AddValue( const ActivityScheduleActiveValueWraperV1& v);
	void SendValue( int Index,bool OnlyToClient=true );
	void SendValue(bool OnlyToClient=true);
	int  SizeValue(){ return m_syncDataActiveDate.SizeValue(); }
public:
	//时间（服务器专用）
	void SetTime( const INT32& v );
	INT32 GetTime();
	void SendTime(bool OnlyToClient=true);


private:
	ActivityScheduleActiveDateWraperV1 m_syncDataActiveDate;

};



#endif
