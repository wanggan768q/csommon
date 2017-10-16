/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleZhanDou.cpp
* Author:       甘业清
* Description:  战斗类，包含以下内容
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

#include "ZhanDouModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleZhanDou);

//战斗实现类构造函数
ModuleZhanDou::ModuleZhanDou()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleZhanDou::RpcMove);


	
	m_mapSyncDataVersionName[1] = "SyncDataZhanDouV1";
		
}

//战斗实现类析构函数
ModuleZhanDou::~ModuleZhanDou()
{

}


//获取模块ID
UINT8 ModuleZhanDou::GetModuleId()
{
	return MODULE_ID_ZHANDOU;
}

//获取模块名字
TStr ModuleZhanDou::GetModuleName()
{
	return "ZhanDou";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleZhanDou::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleZhanDou::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleZhanDou::GetInitializeOrder()
{
	return MODULE_ID_ZHANDOU;
}

//获取结束退出顺序
int ModuleZhanDou::GetFinalizeOrder()
{
	return MODULE_ID_ZHANDOU;
}

//初始化
bool ModuleZhanDou::Initialize()
{

	

	return true;
}

//结束退出
void ModuleZhanDou::Finalize()
{

}


//毫秒级Tick回调
void ModuleZhanDou::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleZhanDou::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleZhanDou::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleZhanDou::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleZhanDou::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleZhanDou::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleZhanDou::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleZhanDou::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleZhanDou::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleZhanDou::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

