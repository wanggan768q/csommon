/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTalisman.cpp
* Author:       甘业清
* Description:  法宝类，包含以下内容
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

#include "TalismanModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleTalisman);

//法宝实现类构造函数
ModuleTalisman::ModuleTalisman()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleTalisman::RpcSyncData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTalisman::RpcActive);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTalisman::RpcUpgrade);


	
	m_mapSyncDataVersionName[1] = "SyncDataTalismanV1";
		
}

//法宝实现类析构函数
ModuleTalisman::~ModuleTalisman()
{

}


//获取模块ID
UINT8 ModuleTalisman::GetModuleId()
{
	return MODULE_ID_TALISMAN;
}

//获取模块名字
TStr ModuleTalisman::GetModuleName()
{
	return "Talisman";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleTalisman::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleTalisman::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleTalisman::GetInitializeOrder()
{
	return MODULE_ID_TALISMAN;
}

//获取结束退出顺序
int ModuleTalisman::GetFinalizeOrder()
{
	return MODULE_ID_TALISMAN;
}

//初始化
bool ModuleTalisman::Initialize()
{

	

	return true;
}

//结束退出
void ModuleTalisman::Finalize()
{

}


//毫秒级Tick回调
void ModuleTalisman::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleTalisman::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleTalisman::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleTalisman::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleTalisman::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleTalisman::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleTalisman::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleTalisman::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleTalisman::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleTalisman::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

