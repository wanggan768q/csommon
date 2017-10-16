/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleDramaModule.cpp
* Author:       甘业清
* Description:  剧情模块类，包含以下内容
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

#include "DramaModuleModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleDramaModule);

//剧情模块实现类构造函数
ModuleDramaModule::ModuleDramaModule()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataDramaModuleV1";
		
}

//剧情模块实现类析构函数
ModuleDramaModule::~ModuleDramaModule()
{

}


//获取模块ID
UINT8 ModuleDramaModule::GetModuleId()
{
	return MODULE_ID_DRAMAMODULE;
}

//获取模块名字
TStr ModuleDramaModule::GetModuleName()
{
	return "DramaModule";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleDramaModule::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleDramaModule::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleDramaModule::GetInitializeOrder()
{
	return MODULE_ID_DRAMAMODULE;
}

//获取结束退出顺序
int ModuleDramaModule::GetFinalizeOrder()
{
	return MODULE_ID_DRAMAMODULE;
}

//初始化
bool ModuleDramaModule::Initialize()
{

	

	return true;
}

//结束退出
void ModuleDramaModule::Finalize()
{

}


//毫秒级Tick回调
void ModuleDramaModule::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleDramaModule::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleDramaModule::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleDramaModule::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleDramaModule::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleDramaModule::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleDramaModule::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleDramaModule::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleDramaModule::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleDramaModule::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

