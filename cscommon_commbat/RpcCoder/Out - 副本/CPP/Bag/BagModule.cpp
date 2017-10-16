/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBag.cpp
* Author:       甘业清
* Description:  背包类，包含以下内容
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

#include "BagModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleBag);

//背包实现类构造函数
ModuleBag::ModuleBag()
{

	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcSyncData);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcSell);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcDecompose);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcUse);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipWear);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipUndress);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipEnhance);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipPolished);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipPolishedReplace);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcBagTidy);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcBagRecycleSell);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcBagRecycleBuy);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcUnlockGrid);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcSplit);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipBaseAttrPlished);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipBaseAttrPolishedReplace);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipExAttrModify);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipInlayGem);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipGemSlotUnlock);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipEnhanceSwap);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcEquipGemRemove);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcBagPutInStorage);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcBagFetchFromStorage);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcBagStorageSaveMoney);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcBagStorageDrawMoney);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcStorageTidy);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcTalismanLvup);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcTalismanInherit);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcBagSetAutoPickup);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcTalismanRefindStar);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcTalismanUpSlotSkillLevel);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleBag::RpcTalismanGatherSprite);


	
	m_mapSyncDataVersionName[1] = "SyncDataBagV1";
		
}

//背包实现类析构函数
ModuleBag::~ModuleBag()
{

}


//获取模块ID
UINT8 ModuleBag::GetModuleId()
{
	return MODULE_ID_BAG;
}

//获取模块名字
TStr ModuleBag::GetModuleName()
{
	return "Bag";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleBag::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleBag::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleBag::GetInitializeOrder()
{
	return MODULE_ID_BAG;
}

//获取结束退出顺序
int ModuleBag::GetFinalizeOrder()
{
	return MODULE_ID_BAG;
}

//初始化
bool ModuleBag::Initialize()
{

	

	return true;
}

//结束退出
void ModuleBag::Finalize()
{

}


//毫秒级Tick回调
void ModuleBag::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleBag::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleBag::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleBag::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleBag::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleBag::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleBag::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleBag::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleBag::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleBag::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

