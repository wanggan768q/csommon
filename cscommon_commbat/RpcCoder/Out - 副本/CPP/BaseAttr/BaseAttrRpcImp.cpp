/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcBaseAttrImp.cpp
* Author:       甘业清
* Description:  战队基础数据类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "BaseAttrModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    战队基础数据-->同步玩家数据同步调用操作函数
* Input:          BaseAttrRpcSyncDataAskWraper& Ask 同步玩家数据请求
* Output:         BaseAttrRpcSyncDataReplyWraper& Reply 同步玩家数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcSyncData( INT64 UserId, BaseAttrRpcSyncDataAskWraper& Ask, BaseAttrRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetRankReward
* Description:    战队基础数据-->领取官阶奖励同步调用操作函数
* Input:          BaseAttrRpcGetRankRewardAskWraper& Ask 领取官阶奖励请求
* Output:         BaseAttrRpcGetRankRewardReplyWraper& Reply 领取官阶奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcGetRankReward( INT64 UserId, BaseAttrRpcGetRankRewardAskWraper& Ask, BaseAttrRpcGetRankRewardReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUpGradeRank
* Description:    战队基础数据-->提升官阶同步调用操作函数
* Input:          BaseAttrRpcUpGradeRankAskWraper& Ask 提升官阶请求
* Output:         BaseAttrRpcUpGradeRankReplyWraper& Reply 提升官阶回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcUpGradeRank( INT64 UserId, BaseAttrRpcUpGradeRankAskWraper& Ask, BaseAttrRpcUpGradeRankReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChooseRole
* Description:    战队基础数据-->选人同步调用操作函数
* Input:          BaseAttrRpcChooseRoleAskWraper& Ask 选人请求
* Output:         BaseAttrRpcChooseRoleReplyWraper& Reply 选人回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcChooseRole( INT64 UserId, BaseAttrRpcChooseRoleAskWraper& Ask, BaseAttrRpcChooseRoleReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLevelUp
* Description:    战队基础数据-->升级同步调用操作函数
* Input:          BaseAttrRpcLevelUpAskWraper& Ask 升级请求
* Output:         BaseAttrRpcLevelUpReplyWraper& Reply 升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcLevelUp( INT64 UserId, BaseAttrRpcLevelUpAskWraper& Ask, BaseAttrRpcLevelUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetTimer
* Description:    战队基础数据-->获取时间同步调用操作函数
* Input:          BaseAttrRpcGetTimerAskWraper& Ask 获取时间请求
* Output:         BaseAttrRpcGetTimerReplyWraper& Reply 获取时间回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcGetTimer( INT64 UserId, BaseAttrRpcGetTimerAskWraper& Ask, BaseAttrRpcGetTimerReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRevive
* Description:    战队基础数据-->复活同步调用操作函数
* Input:          BaseAttrRpcReviveAskWraper& Ask 复活请求
* Output:         BaseAttrRpcReviveReplyWraper& Reply 复活回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcRevive( INT64 UserId, BaseAttrRpcReviveAskWraper& Ask, BaseAttrRpcReviveReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcQueryEquip
* Description:    战队基础数据-->查询装备数据同步调用操作函数
* Input:          BaseAttrRpcQueryEquipAskWraper& Ask 查询装备数据请求
* Output:         BaseAttrRpcQueryEquipReplyWraper& Reply 查询装备数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcQueryEquip( INT64 UserId, BaseAttrRpcQueryEquipAskWraper& Ask, BaseAttrRpcQueryEquipReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUpdateNewbieGuide
* Description:    战队基础数据-->更新新手引导同步调用操作函数
* Input:          BaseAttrRpcUpdateNewbieGuideAskWraper& Ask 更新新手引导请求
* Output:         BaseAttrRpcUpdateNewbieGuideReplyWraper& Reply 更新新手引导回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcUpdateNewbieGuide( INT64 UserId, BaseAttrRpcUpdateNewbieGuideAskWraper& Ask, BaseAttrRpcUpdateNewbieGuideReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSysTips
* Description:    战队基础数据-->系统提示异步通知操作函数
* Input:          BaseAttrRpcSysTipsNotifyWraper& Notify 系统提示通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleBaseAttr::SendToClientSysTips( INT64 UserId, BaseAttrRpcSysTipsNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcChangPKState
* Description:    战队基础数据-->修改PK状态同步调用操作函数
* Input:          BaseAttrRpcChangPKStateAskWraper& Ask 修改PK状态请求
* Output:         BaseAttrRpcChangPKStateReplyWraper& Reply 修改PK状态回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcChangPKState( INT64 UserId, BaseAttrRpcChangPKStateAskWraper& Ask, BaseAttrRpcChangPKStateReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChangePKProtect
* Description:    战队基础数据-->修改PK保护同步调用操作函数
* Input:          BaseAttrRpcChangePKProtectAskWraper& Ask 修改PK保护请求
* Output:         BaseAttrRpcChangePKProtectReplyWraper& Reply 修改PK保护回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleBaseAttr::RpcChangePKProtect( INT64 UserId, BaseAttrRpcChangePKProtectAskWraper& Ask, BaseAttrRpcChangePKProtectReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



