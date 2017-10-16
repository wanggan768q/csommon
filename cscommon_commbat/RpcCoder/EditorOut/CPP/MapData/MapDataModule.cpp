/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMapData.cpp
* Author:       甘业清
* Description:  场景数据类，包含以下内容
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

#include "MapDataModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleMapData);

//场景数据实现类构造函数
ModuleMapData::ModuleMapData()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataMapDataV1";
		
}

//场景数据实现类析构函数
ModuleMapData::~ModuleMapData()
{

}


//获取模块ID
UINT8 ModuleMapData::GetModuleId()
{
	return MODULE_ID_MAPDATA;
}

//获取模块名字
TStr ModuleMapData::GetModuleName()
{
	return "MapData";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleMapData::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleMapData::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleMapData::GetInitializeOrder()
{
	return MODULE_ID_MAPDATA;
}

//获取结束退出顺序
int ModuleMapData::GetFinalizeOrder()
{
	return MODULE_ID_MAPDATA;
}

//初始化
bool ModuleMapData::Initialize()
{

	

	return true;
}

//结束退出
void ModuleMapData::Finalize()
{

}


//毫秒级Tick回调
void ModuleMapData::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleMapData::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleMapData::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleMapData::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleMapData::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleMapData::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleMapData::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleMapData::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleMapData::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleMapData::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

