/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleAchievement.cpp
* Author:       甘业清
* Description:  成就类，包含以下内容
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

#include "AchievementModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleAchievement);

//成就实现类构造函数
ModuleAchievement::ModuleAchievement()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleAchievement::RpcGetTheRewards);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleAchievement::RpcSyncData);


	
	m_mapSyncDataVersionName[1] = "SyncDataAchievementV1";
		
}

//成就实现类析构函数
ModuleAchievement::~ModuleAchievement()
{

}


//获取模块ID
UINT8 ModuleAchievement::GetModuleId()
{
	return MODULE_ID_ACHIEVEMENT;
}

//获取模块名字
TStr ModuleAchievement::GetModuleName()
{
	return "Achievement";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleAchievement::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleAchievement::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleAchievement::GetInitializeOrder()
{
	return MODULE_ID_ACHIEVEMENT;
}

//获取结束退出顺序
int ModuleAchievement::GetFinalizeOrder()
{
	return MODULE_ID_ACHIEVEMENT;
}

//初始化
bool ModuleAchievement::Initialize()
{

	

	return true;
}

//结束退出
void ModuleAchievement::Finalize()
{

}


//毫秒级Tick回调
void ModuleAchievement::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleAchievement::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleAchievement::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleAchievement::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleAchievement::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleAchievement::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleAchievement::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleAchievement::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleAchievement::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleAchievement::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

