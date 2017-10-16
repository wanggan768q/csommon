/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleFriend.cpp
* Author:       甘业清
* Description:  好友类，包含以下内容
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

#include "FriendModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleFriend);

//好友实现类构造函数
ModuleFriend::ModuleFriend()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcSyncFriendData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcAddFriend);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcDelFriend);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcAddBlackList);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcDelBlackList);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcAddContact);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcDelContact);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcSearchPlayer);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcRecommend);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFriend::RpcViewUserSimpleInfo);


	
	m_mapSyncDataVersionName[1] = "SyncDataFriendV1";
		
}

//好友实现类析构函数
ModuleFriend::~ModuleFriend()
{

}


//获取模块ID
UINT8 ModuleFriend::GetModuleId()
{
	return MODULE_ID_FRIEND;
}

//获取模块名字
TStr ModuleFriend::GetModuleName()
{
	return "Friend";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleFriend::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleFriend::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleFriend::GetInitializeOrder()
{
	return MODULE_ID_FRIEND;
}

//获取结束退出顺序
int ModuleFriend::GetFinalizeOrder()
{
	return MODULE_ID_FRIEND;
}

//初始化
bool ModuleFriend::Initialize()
{

	

	return true;
}

//结束退出
void ModuleFriend::Finalize()
{

}


//毫秒级Tick回调
void ModuleFriend::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleFriend::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleFriend::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleFriend::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleFriend::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleFriend::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleFriend::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleFriend::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleFriend::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleFriend::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

