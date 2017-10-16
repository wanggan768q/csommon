/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleAction.cpp
* Author:       甘业清
* Description:  Action类，包含以下内容
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

#include "ActionModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleAction);

//Action实现类构造函数
ModuleAction::ModuleAction()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataActionV1";
		
}

//Action实现类析构函数
ModuleAction::~ModuleAction()
{

}


//获取模块ID
UINT8 ModuleAction::GetModuleId()
{
	return MODULE_ID_ACTION;
}

//获取模块名字
TStr ModuleAction::GetModuleName()
{
	return "Action";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleAction::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleAction::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleAction::GetInitializeOrder()
{
	return MODULE_ID_ACTION;
}

//获取结束退出顺序
int ModuleAction::GetFinalizeOrder()
{
	return MODULE_ID_ACTION;
}

//初始化
bool ModuleAction::Initialize()
{

	

	return true;
}

//结束退出
void ModuleAction::Finalize()
{

}


//毫秒级Tick回调
void ModuleAction::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleAction::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleAction::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleAction::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleAction::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleAction::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleAction::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleAction::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleAction::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleAction::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

