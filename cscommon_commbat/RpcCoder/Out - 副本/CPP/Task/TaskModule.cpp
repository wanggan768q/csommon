/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTask.cpp
* Author:       甘业清
* Description:  任务类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "TaskModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleTask);

//任务实现类构造函数
ModuleTask::ModuleTask()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleTask::RpcSyncData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTask::RpcCompleteTask);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTask::RpcSubmitTask);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTask::RpcAcceptTask);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTask::RpcStartProfTask);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTask::RpcStartOneDragon);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTask::RpcStartGuildSpy);


	
	m_mapSyncDataVersionName[1] = "SyncDataTaskV1";
		
}

//任务实现类析构函数
ModuleTask::~ModuleTask()
{

}


//获取模块ID
UINT8 ModuleTask::GetModuleId()
{
	return MODULE_ID_TASK;
}

//获取模块名字
TStr ModuleTask::GetModuleName()
{
	return "Task";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleTask::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleTask::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleTask::GetInitializeOrder()
{
	return MODULE_ID_TASK;
}

//获取结束退出顺序
int ModuleTask::GetFinalizeOrder()
{
	return MODULE_ID_TASK;
}

//初始化
bool ModuleTask::Initialize()
{

	

	return true;
}

//结束退出
void ModuleTask::Finalize()
{

}


//毫秒级Tick回调
void ModuleTask::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleTask::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleTask::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleTask::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleTask::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleTask::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleTask::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleTask::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleTask::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleTask::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

