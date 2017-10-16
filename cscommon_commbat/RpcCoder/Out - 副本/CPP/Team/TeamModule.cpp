/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTeam.cpp
* Author:       甘业清
* Description:  组队类，包含以下内容
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

#include "TeamModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleTeam);

//组队实现类构造函数
ModuleTeam::ModuleTeam()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcCreateTeam);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcApplyForTeam);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcQuitTeam);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcBreakUp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcInviteToTeam);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcChangeTeamTarget);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcBeInviteHandle);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcNearbyTeam);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcApplyHandleAgree);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcReqMyTeamData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcAppointCaptain);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcNearbyRoleList);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcKickRole);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcCaptainAutoMatch);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcNormalAutoMatch);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcFollow);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::RpcClearApplyList);


	
	m_mapSyncDataVersionName[1] = "SyncDataTeamV1";
		
}

//组队实现类析构函数
ModuleTeam::~ModuleTeam()
{

}


//获取模块ID
UINT8 ModuleTeam::GetModuleId()
{
	return MODULE_ID_TEAM;
}

//获取模块名字
TStr ModuleTeam::GetModuleName()
{
	return "Team";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleTeam::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleTeam::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}


//获取初始化顺序
int	ModuleTeam::GetInitializeOrder()
{
	return MODULE_ID_TEAM;
}

//获取结束退出顺序
int ModuleTeam::GetFinalizeOrder()
{
	return MODULE_ID_TEAM;
}

//初始化
bool ModuleTeam::Initialize()
{

	

	return true;
}

//结束退出
void ModuleTeam::Finalize()
{

}


//毫秒级Tick回调
void ModuleTeam::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleTeam::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleTeam::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleTeam::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleTeam::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleTeam::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleTeam::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleTeam::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleTeam::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleTeam::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

