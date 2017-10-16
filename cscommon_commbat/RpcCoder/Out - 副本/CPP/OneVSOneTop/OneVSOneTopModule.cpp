/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleOneVSOneTop.cpp
* Author:       甘业清
* Description:  排行榜类，包含以下内容
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

#include "OneVSOneTopModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleOneVSOneTop);

//排行榜实现类构造函数
ModuleOneVSOneTop::ModuleOneVSOneTop()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataOneVSOneTopV1";
		
}

//排行榜实现类析构函数
ModuleOneVSOneTop::~ModuleOneVSOneTop()
{

}


//获取模块ID
UINT8 ModuleOneVSOneTop::GetModuleId()
{
	return MODULE_ID_ONEVSONETOP;
}

//获取模块名字
TStr ModuleOneVSOneTop::GetModuleName()
{
	return "OneVSOneTop";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleOneVSOneTop::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleOneVSOneTop::GetSavedDataType()
{
	return SAVE_MODULE_DATA;
}


//获取初始化顺序
int	ModuleOneVSOneTop::GetInitializeOrder()
{
	return MODULE_ID_ONEVSONETOP;
}

//获取结束退出顺序
int ModuleOneVSOneTop::GetFinalizeOrder()
{
	return MODULE_ID_ONEVSONETOP;
}

//初始化
bool ModuleOneVSOneTop::Initialize()
{

	

	return true;
}

//结束退出
void ModuleOneVSOneTop::Finalize()
{

}


//毫秒级Tick回调
void ModuleOneVSOneTop::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleOneVSOneTop::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleOneVSOneTop::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleOneVSOneTop::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleOneVSOneTop::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleOneVSOneTop::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleOneVSOneTop::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleOneVSOneTop::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleOneVSOneTop::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleOneVSOneTop::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

