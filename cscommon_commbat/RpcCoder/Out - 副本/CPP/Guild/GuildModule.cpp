/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleGuild.cpp
* Author:       甘业清
* Description:  帮派类，包含以下内容
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

#include "GuildModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleGuild);

//帮派实现类构造函数
ModuleGuild::ModuleGuild()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcSyncData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcCreateGuild);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcApplyGuild);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcQuickApply);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcChangeGuildName);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcChangeAnnouncement);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcReqGuildList);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcAppointDuty);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcKickout);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcExitGuild);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcBreakUp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcInviteToJoin);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcBeInvitedHandle);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcResignDuty);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcHallLvUp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcHouseLvUp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcStoreroomLvUp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcKongfuHallLvUp);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcApplyGuildHandle);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcCreateGuildDungeon);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcEnterGuildDungeon);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcCreateGuildWar);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcEnterGuildWar);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcOpenScienceAttr);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleGuild::RpcGuildScienceLvUp);


	
	m_mapSyncDataVersionName[1] = "SyncDataGuildV1";
		
}

//帮派实现类析构函数
ModuleGuild::~ModuleGuild()
{

}


//获取模块ID
UINT8 ModuleGuild::GetModuleId()
{
	return MODULE_ID_GUILD;
}

//获取模块名字
TStr ModuleGuild::GetModuleName()
{
	return "Guild";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleGuild::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleGuild::GetSavedDataType()
{
	return SAVE_CACHE_DATA;
}


//获取初始化顺序
int	ModuleGuild::GetInitializeOrder()
{
	return MODULE_ID_GUILD;
}

//获取结束退出顺序
int ModuleGuild::GetFinalizeOrder()
{
	return MODULE_ID_GUILD;
}

//初始化
bool ModuleGuild::Initialize()
{

	

	return true;
}

//结束退出
void ModuleGuild::Finalize()
{

}


//毫秒级Tick回调
void ModuleGuild::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleGuild::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleGuild::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleGuild::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleGuild::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleGuild::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleGuild::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleGuild::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleGuild::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleGuild::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

