/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleGM.cpp
* Author:       甘业清
* Description:  GM指令类，包含以下内容
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

#include "GMModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleGM);

//GM指令实现类构造函数
ModuleGM::ModuleGM()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleGM::RpcAction);


	
	m_mapSyncDataVersionName[1] = "SyncDataGMV1";
		
}

//GM指令实现类析构函数
ModuleGM::~ModuleGM()
{

}


//获取模块ID
UINT8 ModuleGM::GetModuleId()
{
	return MODULE_ID_GM;
}

//获取模块名字
TStr ModuleGM::GetModuleName()
{
	return "GM";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleGM::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleGM::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleGM::GetInitializeOrder()
{
	return MODULE_ID_GM;
}

//获取结束退出顺序
int ModuleGM::GetFinalizeOrder()
{
	return MODULE_ID_GM;
}

//初始化
bool ModuleGM::Initialize()
{

	

	return true;
}

//结束退出
void ModuleGM::Finalize()
{

}


//毫秒级Tick回调
void ModuleGM::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleGM::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleGM::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleGM::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleGM::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleGM::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleGM::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleGM::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleGM::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleGM::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

