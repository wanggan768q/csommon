/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMMOMapData.cpp
* Author:       甘业清
* Description:  45度MMO地图数据类，包含以下内容
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

#include "MMOMapDataModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleMMOMapData);

//45度MMO地图数据实现类构造函数
ModuleMMOMapData::ModuleMMOMapData()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataMMOMapDataV1";
		
}

//45度MMO地图数据实现类析构函数
ModuleMMOMapData::~ModuleMMOMapData()
{

}


//获取模块ID
UINT8 ModuleMMOMapData::GetModuleId()
{
	return MODULE_ID_MMOMAPDATA;
}

//获取模块名字
TStr ModuleMMOMapData::GetModuleName()
{
	return "MMOMapData";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleMMOMapData::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleMMOMapData::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleMMOMapData::GetInitializeOrder()
{
	return MODULE_ID_MMOMAPDATA;
}

//获取结束退出顺序
int ModuleMMOMapData::GetFinalizeOrder()
{
	return MODULE_ID_MMOMAPDATA;
}

//初始化
bool ModuleMMOMapData::Initialize()
{

	

	return true;
}

//结束退出
void ModuleMMOMapData::Finalize()
{

}


//毫秒级Tick回调
void ModuleMMOMapData::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleMMOMapData::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleMMOMapData::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleMMOMapData::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleMMOMapData::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleMMOMapData::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleMMOMapData::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleMMOMapData::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleMMOMapData::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleMMOMapData::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

