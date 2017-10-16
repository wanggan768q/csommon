#include "TaskV1Data.h"
#include "TaskModule.h"


SyncDataTaskV1::SyncDataTaskV1()
{
	SetDataWraper( &m_syncDataTaskData );
}

SyncDataTaskV1::~SyncDataTaskV1()
{
}

void SyncDataTaskV1::SendAllMembers(bool OnlyToClient)
{
	SendAllTaskArray(OnlyToClient);
	SendUnacceptedTaskArray(OnlyToClient);
	SendProfTaskId(OnlyToClient);
	SendProfTaskCompCount(OnlyToClient);
	SendOneDragonTaskId(OnlyToClient);
	SendOneDragonRingNum(OnlyToClient);
	SendOneDragonComplateCount(OnlyToClient);
	SendOneDragonDungeonId(OnlyToClient);
	SendGuildSpyComplateCount(OnlyToClient);

}



//全部任务数组
void SyncDataTaskV1::SetAllTaskArray( const vector<TaskTaskObjWraperV1>& v )
{
	m_syncDataTaskData.SetAllTaskArray(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ALLTASKARRAY);
	SendAllTaskArray(false);
}
void SyncDataTaskV1::SetAllTaskArray( int Index, const TaskTaskObjWraperV1& v )
{
	m_syncDataTaskData.SetAllTaskArray(Index,v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ALLTASKARRAY,Index);
	SendAllTaskArray(Index,false);
}
vector<TaskTaskObjWraperV1> SyncDataTaskV1::GetAllTaskArray()
{
	return m_syncDataTaskData.GetAllTaskArray();
}
TaskTaskObjWraperV1 SyncDataTaskV1::GetAllTaskArray( int Index )
{
	return m_syncDataTaskData.GetAllTaskArray(Index);
}
void SyncDataTaskV1::SendAllTaskArray(bool OnlyToClient)
{
	SendAllTaskArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataTaskData.SizeAllTaskArray(); i++)
		SendAllTaskArray(i,OnlyToClient);
}
void SyncDataTaskV1::SendAllTaskArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_ALLTASKARRAY,Index,NULL,0);
		if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_ALLTASKARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_ALLTASKARRAY,Index,NULL,0);
		return;
	}
	const string v= GetAllTaskArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_ALLTASKARRAY,Index,v.data(),v.size());
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_ALLTASKARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_ALLTASKARRAY,Index,v.data(),v.size());
}
void SyncDataTaskV1::AddAllTaskArray( const TaskTaskObjWraperV1& v )
{
	m_syncDataTaskData.AddAllTaskArray(v);
	OnDataChange();
	int Index = m_syncDataTaskData.SizeAllTaskArray()-1;
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ALLTASKARRAY,Index);
	SendAllTaskArray(Index,false);
}

//可接任务
void SyncDataTaskV1::SetUnacceptedTaskArray( const vector<TaskUnacceptedTaskObjWraperV1>& v )
{
	m_syncDataTaskData.SetUnacceptedTaskArray(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_UNACCEPTEDTASKARRAY);
	SendUnacceptedTaskArray(false);
}
void SyncDataTaskV1::SetUnacceptedTaskArray( int Index, const TaskUnacceptedTaskObjWraperV1& v )
{
	m_syncDataTaskData.SetUnacceptedTaskArray(Index,v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_UNACCEPTEDTASKARRAY,Index);
	SendUnacceptedTaskArray(Index,false);
}
vector<TaskUnacceptedTaskObjWraperV1> SyncDataTaskV1::GetUnacceptedTaskArray()
{
	return m_syncDataTaskData.GetUnacceptedTaskArray();
}
TaskUnacceptedTaskObjWraperV1 SyncDataTaskV1::GetUnacceptedTaskArray( int Index )
{
	return m_syncDataTaskData.GetUnacceptedTaskArray(Index);
}
void SyncDataTaskV1::SendUnacceptedTaskArray(bool OnlyToClient)
{
	SendUnacceptedTaskArray(-1,OnlyToClient);
	for(int i=0; i<m_syncDataTaskData.SizeUnacceptedTaskArray(); i++)
		SendUnacceptedTaskArray(i,OnlyToClient);
}
void SyncDataTaskV1::SendUnacceptedTaskArray( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_UNACCEPTEDTASKARRAY,Index,NULL,0);
		if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_UNACCEPTEDTASKARRAY)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_UNACCEPTEDTASKARRAY,Index,NULL,0);
		return;
	}
	const string v= GetUnacceptedTaskArray(Index).SerializeAsString();
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_UNACCEPTEDTASKARRAY,Index,v.data(),v.size());
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_UNACCEPTEDTASKARRAY)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_UNACCEPTEDTASKARRAY,Index,v.data(),v.size());
}
void SyncDataTaskV1::AddUnacceptedTaskArray( const TaskUnacceptedTaskObjWraperV1& v )
{
	m_syncDataTaskData.AddUnacceptedTaskArray(v);
	OnDataChange();
	int Index = m_syncDataTaskData.SizeUnacceptedTaskArray()-1;
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_UNACCEPTEDTASKARRAY,Index);
	SendUnacceptedTaskArray(Index,false);
}

//师门任务环数
void SyncDataTaskV1::SetProfTaskId( const INT32& v )
{
	m_syncDataTaskData.SetProfTaskId(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_PROFTASKID);
	SendProfTaskId(false);
}
INT32 SyncDataTaskV1::GetProfTaskId()
{
	return m_syncDataTaskData.GetProfTaskId();
}
void SyncDataTaskV1::SendProfTaskId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_PROFTASKID,m_syncDataTaskData.GetProfTaskId());
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_PROFTASKID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_PROFTASKID,m_syncDataTaskData.GetProfTaskId());
}

//师门任务完成次数
void SyncDataTaskV1::SetProfTaskCompCount( const INT32& v )
{
	m_syncDataTaskData.SetProfTaskCompCount(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_PROFTASKCOMPCOUNT);
	SendProfTaskCompCount(false);
}
INT32 SyncDataTaskV1::GetProfTaskCompCount()
{
	return m_syncDataTaskData.GetProfTaskCompCount();
}
void SyncDataTaskV1::SendProfTaskCompCount(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_PROFTASKCOMPCOUNT,m_syncDataTaskData.GetProfTaskCompCount());
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_PROFTASKCOMPCOUNT)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_PROFTASKCOMPCOUNT,m_syncDataTaskData.GetProfTaskCompCount());
}

//使用过的一条龙任务Id
void SyncDataTaskV1::SetOneDragonTaskId( const vector<INT32>& v )
{
	m_syncDataTaskData.SetOneDragonTaskId(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ONEDRAGONTASKID);
	SendOneDragonTaskId(false);
}
void SyncDataTaskV1::SetOneDragonTaskId( int Index, const INT32& v )
{
	m_syncDataTaskData.SetOneDragonTaskId(Index,v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ONEDRAGONTASKID,Index);
	SendOneDragonTaskId(Index,false);
}
vector<INT32> SyncDataTaskV1::GetOneDragonTaskId()
{
	return m_syncDataTaskData.GetOneDragonTaskId();
}
INT32 SyncDataTaskV1::GetOneDragonTaskId( int Index )
{
	return m_syncDataTaskData.GetOneDragonTaskId(Index);
}
void SyncDataTaskV1::SendOneDragonTaskId(bool OnlyToClient)
{
	SendOneDragonTaskId(-1,OnlyToClient);
	for(int i=0; i<m_syncDataTaskData.SizeOneDragonTaskId(); i++)
		SendOneDragonTaskId(i,OnlyToClient);
}
void SyncDataTaskV1::SendOneDragonTaskId( int Index, bool OnlyToClient )
{
	if( Index<0 )
	{
		if( !OnlyToClient )
			MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_ONEDRAGONTASKID,Index,NULL,0);
		if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_ONEDRAGONTASKID)||GetKey()==0) return;
		MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_ONEDRAGONTASKID,Index,NULL,0);
		return;
	}
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_ONEDRAGONTASKID,Index,m_syncDataTaskData.GetOneDragonTaskId(Index));
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_ONEDRAGONTASKID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_ONEDRAGONTASKID,Index,m_syncDataTaskData.GetOneDragonTaskId(Index));
}
void SyncDataTaskV1::AddOneDragonTaskId( INT32 v )
{
	m_syncDataTaskData.AddOneDragonTaskId(v);
	OnDataChange();
	int Index = m_syncDataTaskData.SizeOneDragonTaskId()-1;
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ONEDRAGONTASKID,Index);
	SendOneDragonTaskId(Index,false);
}

//一条龙环数
void SyncDataTaskV1::SetOneDragonRingNum( const INT32& v )
{
	m_syncDataTaskData.SetOneDragonRingNum(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ONEDRAGONRINGNUM);
	SendOneDragonRingNum(false);
}
INT32 SyncDataTaskV1::GetOneDragonRingNum()
{
	return m_syncDataTaskData.GetOneDragonRingNum();
}
void SyncDataTaskV1::SendOneDragonRingNum(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_ONEDRAGONRINGNUM,m_syncDataTaskData.GetOneDragonRingNum());
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_ONEDRAGONRINGNUM)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_ONEDRAGONRINGNUM,m_syncDataTaskData.GetOneDragonRingNum());
}

//一条龙完成次数
void SyncDataTaskV1::SetOneDragonComplateCount( const INT32& v )
{
	m_syncDataTaskData.SetOneDragonComplateCount(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ONEDRAGONCOMPLATECOUNT);
	SendOneDragonComplateCount(false);
}
INT32 SyncDataTaskV1::GetOneDragonComplateCount()
{
	return m_syncDataTaskData.GetOneDragonComplateCount();
}
void SyncDataTaskV1::SendOneDragonComplateCount(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_ONEDRAGONCOMPLATECOUNT,m_syncDataTaskData.GetOneDragonComplateCount());
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_ONEDRAGONCOMPLATECOUNT)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_ONEDRAGONCOMPLATECOUNT,m_syncDataTaskData.GetOneDragonComplateCount());
}

//一条龙副本Id
void SyncDataTaskV1::SetOneDragonDungeonId( const INT32& v )
{
	m_syncDataTaskData.SetOneDragonDungeonId(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_ONEDRAGONDUNGEONID);
	SendOneDragonDungeonId(false);
}
INT32 SyncDataTaskV1::GetOneDragonDungeonId()
{
	return m_syncDataTaskData.GetOneDragonDungeonId();
}
void SyncDataTaskV1::SendOneDragonDungeonId(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_ONEDRAGONDUNGEONID,m_syncDataTaskData.GetOneDragonDungeonId());
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_ONEDRAGONDUNGEONID)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_ONEDRAGONDUNGEONID,m_syncDataTaskData.GetOneDragonDungeonId());
}

//帮会刺探完成次数
void SyncDataTaskV1::SetGuildSpyComplateCount( const INT32& v )
{
	m_syncDataTaskData.SetGuildSpyComplateCount(v);
	OnDataChange();
	ModuleTask::Instance().NotifySyncValueChanged(m_syncDataTaskData.GetKey(),SYNCID_TASK_GUILDSPYCOMPLATECOUNT);
	SendGuildSpyComplateCount(false);
}
INT32 SyncDataTaskV1::GetGuildSpyComplateCount()
{
	return m_syncDataTaskData.GetGuildSpyComplateCount();
}
void SyncDataTaskV1::SendGuildSpyComplateCount(bool OnlyToClient)
{
	if( !OnlyToClient )
		MsgStreamMgr::Instance().IncrementCache(GetKey(),SYNCID_TASK_GUILDSPYCOMPLATECOUNT,m_syncDataTaskData.GetGuildSpyComplateCount());
	if(ModuleTask::Instance().NotSyncToClient(SYNCID_TASK_GUILDSPYCOMPLATECOUNT)||GetKey()==0) return;
	MsgStreamMgr::Instance().SendSync(GetKey(),SYNCID_TASK_GUILDSPYCOMPLATECOUNT,m_syncDataTaskData.GetGuildSpyComplateCount());
}
