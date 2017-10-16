/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleActivityPlay.cpp
* Author:       甘业清
* Description:  活动玩法类，包含以下内容
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

#include "ActivityPlayModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleActivityPlay);

//活动玩法实现类构造函数
ModuleActivityPlay::ModuleActivityPlay()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataActivityPlayV1";
		
}

//活动玩法实现类析构函数
ModuleActivityPlay::~ModuleActivityPlay()
{

}


//获取模块ID
UINT8 ModuleActivityPlay::GetModuleId()
{
	return MODULE_ID_ACTIVITYPLAY;
}

//获取模块名字
TStr ModuleActivityPlay::GetModuleName()
{
	return "ActivityPlay";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleActivityPlay::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleActivityPlay::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}


//获取初始化顺序
int	ModuleActivityPlay::GetInitializeOrder()
{
	return MODULE_ID_ACTIVITYPLAY;
}

//获取结束退出顺序
int ModuleActivityPlay::GetFinalizeOrder()
{
	return MODULE_ID_ACTIVITYPLAY;
}

//初始化
bool ModuleActivityPlay::Initialize()
{

	

	return true;
}

//结束退出
void ModuleActivityPlay::Finalize()
{

}


//毫秒级Tick回调
void ModuleActivityPlay::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleActivityPlay::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleActivityPlay::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleActivityPlay::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleActivityPlay::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleActivityPlay::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleActivityPlay::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleActivityPlay::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleActivityPlay::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleActivityPlay::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

