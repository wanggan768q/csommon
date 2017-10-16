/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleActivityStorm.cpp
* Author:       甘业清
* Description:  活动 风暴类，包含以下内容
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

#include "ActivityStormModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleActivityStorm);

//活动 风暴实现类构造函数
ModuleActivityStorm::ModuleActivityStorm()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivityStorm::RpcSignUp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivityStorm::RpcCancelSignUp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivityStorm::RpcInsertBattlefield);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivityStorm::RpcSyncData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivityStorm::RpcCanceInsertBattle);


	
	m_mapSyncDataVersionName[1] = "SyncDataActivityStormV1";
		
}

//活动 风暴实现类析构函数
ModuleActivityStorm::~ModuleActivityStorm()
{

}


//获取模块ID
UINT8 ModuleActivityStorm::GetModuleId()
{
	return MODULE_ID_ACTIVITYSTORM;
}

//获取模块名字
TStr ModuleActivityStorm::GetModuleName()
{
	return "ActivityStorm";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleActivityStorm::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleActivityStorm::GetSavedDataType()
{
	return SAVE_MODULE_DATA;
}


//获取初始化顺序
int	ModuleActivityStorm::GetInitializeOrder()
{
	return MODULE_ID_ACTIVITYSTORM;
}

//获取结束退出顺序
int ModuleActivityStorm::GetFinalizeOrder()
{
	return MODULE_ID_ACTIVITYSTORM;
}

//初始化
bool ModuleActivityStorm::Initialize()
{

	

	return true;
}

//结束退出
void ModuleActivityStorm::Finalize()
{

}


//毫秒级Tick回调
void ModuleActivityStorm::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleActivityStorm::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleActivityStorm::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleActivityStorm::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleActivityStorm::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleActivityStorm::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleActivityStorm::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleActivityStorm::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleActivityStorm::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleActivityStorm::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

