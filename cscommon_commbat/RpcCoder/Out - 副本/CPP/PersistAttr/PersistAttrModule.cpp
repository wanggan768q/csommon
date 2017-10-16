/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModulePersistAttr.cpp
* Author:       甘业清
* Description:  常驻内存属性模块类，包含以下内容
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

#include "PersistAttrModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModulePersistAttr);

//常驻内存属性模块实现类构造函数
ModulePersistAttr::ModulePersistAttr()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModulePersistAttr::RpcSyncData);


	
	m_mapSyncDataVersionName[1] = "SyncDataPersistAttrV1";
		
}

//常驻内存属性模块实现类析构函数
ModulePersistAttr::~ModulePersistAttr()
{

}


//获取模块ID
UINT8 ModulePersistAttr::GetModuleId()
{
	return MODULE_ID_PERSISTATTR;
}

//获取模块名字
TStr ModulePersistAttr::GetModuleName()
{
	return "PersistAttr";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModulePersistAttr::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModulePersistAttr::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}


//获取初始化顺序
int	ModulePersistAttr::GetInitializeOrder()
{
	return MODULE_ID_PERSISTATTR;
}

//获取结束退出顺序
int ModulePersistAttr::GetFinalizeOrder()
{
	return MODULE_ID_PERSISTATTR;
}

//初始化
bool ModulePersistAttr::Initialize()
{

	

	return true;
}

//结束退出
void ModulePersistAttr::Finalize()
{

}


//毫秒级Tick回调
void ModulePersistAttr::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModulePersistAttr::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModulePersistAttr::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModulePersistAttr::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModulePersistAttr::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModulePersistAttr::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModulePersistAttr::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModulePersistAttr::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModulePersistAttr::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModulePersistAttr::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

