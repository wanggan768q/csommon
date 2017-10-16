/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleActivitySchedule.cpp
* Author:       甘业清
* Description:  活动日常类，包含以下内容
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

#include "ActivityScheduleModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleActivitySchedule);

//活动日常实现类构造函数
ModuleActivitySchedule::ModuleActivitySchedule()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivitySchedule::RpcSyncData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivitySchedule::RpcThiefOpenMonster);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivitySchedule::RpcSubdueMonsterEnter);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivitySchedule::RpcWorldBossEnterDungeon);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivitySchedule::RpcWorldBossSyncData);


	
	m_mapSyncDataVersionName[1] = "SyncDataActivityScheduleV1";
		
}

//活动日常实现类析构函数
ModuleActivitySchedule::~ModuleActivitySchedule()
{

}


//获取模块ID
UINT8 ModuleActivitySchedule::GetModuleId()
{
	return MODULE_ID_ACTIVITYSCHEDULE;
}

//获取模块名字
TStr ModuleActivitySchedule::GetModuleName()
{
	return "ActivitySchedule";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleActivitySchedule::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleActivitySchedule::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleActivitySchedule::GetInitializeOrder()
{
	return MODULE_ID_ACTIVITYSCHEDULE;
}

//获取结束退出顺序
int ModuleActivitySchedule::GetFinalizeOrder()
{
	return MODULE_ID_ACTIVITYSCHEDULE;
}

//初始化
bool ModuleActivitySchedule::Initialize()
{

	

	return true;
}

//结束退出
void ModuleActivitySchedule::Finalize()
{

}


//毫秒级Tick回调
void ModuleActivitySchedule::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleActivitySchedule::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleActivitySchedule::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleActivitySchedule::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleActivitySchedule::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleActivitySchedule::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleActivitySchedule::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleActivitySchedule::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleActivitySchedule::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleActivitySchedule::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

