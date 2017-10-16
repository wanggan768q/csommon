#ifndef __SYNC_DATA_TASK_V1_H
#define __SYNC_DATA_TASK_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "TaskV1DataWraper.h"


//同步数据相关枚举量定义
enum TaskSyncDataItemIdE
{
 	SYNCID_TASK_ALLTASKARRAY                    = 2402,  //全部任务数组
 	SYNCID_TASK_UNACCEPTEDTASKARRAY             = 2403,  //可接任务
 	SYNCID_TASK_PROFTASKID                      = 2404,  //师门任务环数
 	SYNCID_TASK_PROFTASKCOMPCOUNT               = 2405,  //师门任务完成次数
 	SYNCID_TASK_ONEDRAGONTASKID                 = 2406,  //使用过的一条龙任务Id
 	SYNCID_TASK_ONEDRAGONRINGNUM                = 2407,  //一条龙环数
 	SYNCID_TASK_ONEDRAGONCOMPLATECOUNT          = 2408,  //一条龙完成次数
 	SYNCID_TASK_ONEDRAGONDUNGEONID              = 2409,  //一条龙副本Id
 	SYNCID_TASK_GUILDSPYCOMPLATECOUNT           = 2410,  //帮会刺探完成次数

};


//主同步数据操作类
class SyncDataTaskV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataTaskV1>
{
public:
			SyncDataTaskV1();
	virtual	~SyncDataTaskV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataTaskData.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataTaskData.HtmlDescHeader(); }
public:
	//全部任务数组
	void SetAllTaskArray( const vector<TaskTaskObjWraperV1>& v );
	void SetAllTaskArray( int Index, const TaskTaskObjWraperV1& v );
	vector<TaskTaskObjWraperV1> GetAllTaskArray();
	TaskTaskObjWraperV1 GetAllTaskArray( int Index );
	void AddAllTaskArray( const TaskTaskObjWraperV1& v);
	void SendAllTaskArray( int Index,bool OnlyToClient=true );
	void SendAllTaskArray(bool OnlyToClient=true);
	int  SizeAllTaskArray(){ return m_syncDataTaskData.SizeAllTaskArray(); }
public:
	//可接任务
	void SetUnacceptedTaskArray( const vector<TaskUnacceptedTaskObjWraperV1>& v );
	void SetUnacceptedTaskArray( int Index, const TaskUnacceptedTaskObjWraperV1& v );
	vector<TaskUnacceptedTaskObjWraperV1> GetUnacceptedTaskArray();
	TaskUnacceptedTaskObjWraperV1 GetUnacceptedTaskArray( int Index );
	void AddUnacceptedTaskArray( const TaskUnacceptedTaskObjWraperV1& v);
	void SendUnacceptedTaskArray( int Index,bool OnlyToClient=true );
	void SendUnacceptedTaskArray(bool OnlyToClient=true);
	int  SizeUnacceptedTaskArray(){ return m_syncDataTaskData.SizeUnacceptedTaskArray(); }
public:
	//师门任务环数
	void SetProfTaskId( const INT32& v );
	INT32 GetProfTaskId();
	void SendProfTaskId(bool OnlyToClient=true);
public:
	//师门任务完成次数
	void SetProfTaskCompCount( const INT32& v );
	INT32 GetProfTaskCompCount();
	void SendProfTaskCompCount(bool OnlyToClient=true);
public:
	//使用过的一条龙任务Id
	void SetOneDragonTaskId( const vector<INT32>& v );
	void SetOneDragonTaskId( int Index, const INT32& v );
	vector<INT32> GetOneDragonTaskId();
	INT32 GetOneDragonTaskId( int Index );
	void AddOneDragonTaskId( INT32 v=-1 );
	void SendOneDragonTaskId( int Index,bool OnlyToClient=true );
	void SendOneDragonTaskId(bool OnlyToClient=true);
	int  SizeOneDragonTaskId(){ return m_syncDataTaskData.SizeOneDragonTaskId(); }
public:
	//一条龙环数
	void SetOneDragonRingNum( const INT32& v );
	INT32 GetOneDragonRingNum();
	void SendOneDragonRingNum(bool OnlyToClient=true);
public:
	//一条龙完成次数
	void SetOneDragonComplateCount( const INT32& v );
	INT32 GetOneDragonComplateCount();
	void SendOneDragonComplateCount(bool OnlyToClient=true);
public:
	//一条龙副本Id
	void SetOneDragonDungeonId( const INT32& v );
	INT32 GetOneDragonDungeonId();
	void SendOneDragonDungeonId(bool OnlyToClient=true);
public:
	//帮会刺探完成次数
	void SetGuildSpyComplateCount( const INT32& v );
	INT32 GetGuildSpyComplateCount();
	void SendGuildSpyComplateCount(bool OnlyToClient=true);


private:
	TaskTaskDataWraperV1 m_syncDataTaskData;

};



#endif
