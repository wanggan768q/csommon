/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcAchievementImp.cpp
* Author:       甘业清
* Description:  成就类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "AchievementModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcGetTheRewards
* Description:    成就-->领取奖励同步调用操作函数
* Input:          AchievementRpcGetTheRewardsAskWraper& Ask 领取奖励请求
* Output:         AchievementRpcGetTheRewardsReplyWraper& Reply 领取奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleAchievement::RpcGetTheRewards( INT64 UserId, AchievementRpcGetTheRewardsAskWraper& Ask, AchievementRpcGetTheRewardsReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSyncData
* Description:    成就-->同步数据同步调用操作函数
* Input:          AchievementRpcSyncDataAskWraper& Ask 同步数据请求
* Output:         AchievementRpcSyncDataReplyWraper& Reply 同步数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleAchievement::RpcSyncData( INT64 UserId, AchievementRpcSyncDataAskWraper& Ask, AchievementRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



