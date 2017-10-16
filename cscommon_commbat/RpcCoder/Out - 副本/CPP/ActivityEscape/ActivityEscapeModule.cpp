/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleActivityEscape.cpp
* Author:       甘业清
* Description:  活动 大逃杀类，包含以下内容
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

#include "ActivityEscapeModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleActivityEscape);

//活动 大逃杀实现类构造函数
ModuleActivityEscape::ModuleActivityEscape()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleActivityEscape::RpcSignUp);


	
	m_mapSyncDataVersionName[1] = "SyncDataActivityEscapeV1";
		
}

//活动 大逃杀实现类析构函数
ModuleActivityEscape::~ModuleActivityEscape()
{

}


//获取模块ID
UINT8 ModuleActivityEscape::GetModuleId()
{
	return MODULE_ID_ACTIVITYESCAPE;
}

//获取模块名字
TStr ModuleActivityEscape::GetModuleName()
{
	return "ActivityEscape";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleActivityEscape::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleActivityEscape::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleActivityEscape::GetInitializeOrder()
{
	return MODULE_ID_ACTIVITYESCAPE;
}

//获取结束退出顺序
int ModuleActivityEscape::GetFinalizeOrder()
{
	return MODULE_ID_ACTIVITYESCAPE;
}

//初始化
bool ModuleActivityEscape::Initialize()
{

	

	return true;
}

//结束退出
void ModuleActivityEscape::Finalize()
{

}


//毫秒级Tick回调
void ModuleActivityEscape::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleActivityEscape::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleActivityEscape::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleActivityEscape::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleActivityEscape::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleActivityEscape::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleActivityEscape::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleActivityEscape::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleActivityEscape::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleActivityEscape::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

