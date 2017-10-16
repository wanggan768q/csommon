/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleOneVSOne.cpp
* Author:       甘业清
* Description:  一v一类，包含以下内容
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

#include "OneVSOneModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleOneVSOne);

//一v一实现类构造函数
ModuleOneVSOne::ModuleOneVSOne()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleOneVSOne::RpcFlush);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleOneVSOne::RpcAct);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleOneVSOne::RpcReplyAct);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleOneVSOne::RpcGetTop);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleOneVSOne::RpcAdjustmentSkill);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleOneVSOne::RpcGetSkill);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleOneVSOne::RpcGetActMessage);


	
	m_mapSyncDataVersionName[1] = "SyncDataOneVSOneV1";
		
}

//一v一实现类析构函数
ModuleOneVSOne::~ModuleOneVSOne()
{

}


//获取模块ID
UINT8 ModuleOneVSOne::GetModuleId()
{
	return MODULE_ID_ONEVSONE;
}

//获取模块名字
TStr ModuleOneVSOne::GetModuleName()
{
	return "OneVSOne";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleOneVSOne::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleOneVSOne::GetSavedDataType()
{
	return SAVE_MODULE_DATA;
}


//获取初始化顺序
int	ModuleOneVSOne::GetInitializeOrder()
{
	return MODULE_ID_ONEVSONE;
}

//获取结束退出顺序
int ModuleOneVSOne::GetFinalizeOrder()
{
	return MODULE_ID_ONEVSONE;
}

//初始化
bool ModuleOneVSOne::Initialize()
{

	

	return true;
}

//结束退出
void ModuleOneVSOne::Finalize()
{

}


//毫秒级Tick回调
void ModuleOneVSOne::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleOneVSOne::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleOneVSOne::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleOneVSOne::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleOneVSOne::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleOneVSOne::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleOneVSOne::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleOneVSOne::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleOneVSOne::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleOneVSOne::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

