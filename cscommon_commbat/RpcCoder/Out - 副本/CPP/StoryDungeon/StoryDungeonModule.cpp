/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleStoryDungeon.cpp
* Author:       甘业清
* Description:  剧情副本类，包含以下内容
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

#include "StoryDungeonModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleStoryDungeon);

//剧情副本实现类构造函数
ModuleStoryDungeon::ModuleStoryDungeon()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleStoryDungeon::RpcSyncData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleStoryDungeon::RpcChallenge);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleStoryDungeon::RpcConfirmEnter);


	
	m_mapSyncDataVersionName[1] = "SyncDataStoryDungeonV1";
		
}

//剧情副本实现类析构函数
ModuleStoryDungeon::~ModuleStoryDungeon()
{

}


//获取模块ID
UINT8 ModuleStoryDungeon::GetModuleId()
{
	return MODULE_ID_STORYDUNGEON;
}

//获取模块名字
TStr ModuleStoryDungeon::GetModuleName()
{
	return "StoryDungeon";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleStoryDungeon::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleStoryDungeon::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleStoryDungeon::GetInitializeOrder()
{
	return MODULE_ID_STORYDUNGEON;
}

//获取结束退出顺序
int ModuleStoryDungeon::GetFinalizeOrder()
{
	return MODULE_ID_STORYDUNGEON;
}

//初始化
bool ModuleStoryDungeon::Initialize()
{

	

	return true;
}

//结束退出
void ModuleStoryDungeon::Finalize()
{

}


//毫秒级Tick回调
void ModuleStoryDungeon::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleStoryDungeon::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleStoryDungeon::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleStoryDungeon::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleStoryDungeon::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleStoryDungeon::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleStoryDungeon::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleStoryDungeon::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleStoryDungeon::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleStoryDungeon::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

