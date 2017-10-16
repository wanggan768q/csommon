/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTransport.cpp
* Author:       甘业清
* Description:  货运类，包含以下内容
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

#include "TransportModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleTransport);

//货运实现类构造函数
ModuleTransport::ModuleTransport()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleTransport::RpcSyncData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTransport::RpcFill);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTransport::RpcHelpOther);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTransport::RpcAskHelp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTransport::RpcSetSail);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTransport::RpcAddTransport);


	
	m_mapSyncDataVersionName[1] = "SyncDataTransportV1";
		
}

//货运实现类析构函数
ModuleTransport::~ModuleTransport()
{

}


//获取模块ID
UINT8 ModuleTransport::GetModuleId()
{
	return MODULE_ID_TRANSPORT;
}

//获取模块名字
TStr ModuleTransport::GetModuleName()
{
	return "Transport";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleTransport::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleTransport::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleTransport::GetInitializeOrder()
{
	return MODULE_ID_TRANSPORT;
}

//获取结束退出顺序
int ModuleTransport::GetFinalizeOrder()
{
	return MODULE_ID_TRANSPORT;
}

//初始化
bool ModuleTransport::Initialize()
{

	

	return true;
}

//结束退出
void ModuleTransport::Finalize()
{

}


//毫秒级Tick回调
void ModuleTransport::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleTransport::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleTransport::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleTransport::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleTransport::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleTransport::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleTransport::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleTransport::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleTransport::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleTransport::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

