/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcStoryDungeonImp.cpp
* Author:       甘业清
* Description:  剧情副本类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "StoryDungeonModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    剧情副本-->SyncData同步调用操作函数
* Input:          StoryDungeonRpcSyncDataAskWraper& Ask SyncData请求
* Output:         StoryDungeonRpcSyncDataReplyWraper& Reply SyncData回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleStoryDungeon::RpcSyncData( INT64 UserId, StoryDungeonRpcSyncDataAskWraper& Ask, StoryDungeonRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChallenge
* Description:    剧情副本-->挑战副本同步调用操作函数
* Input:          StoryDungeonRpcChallengeAskWraper& Ask 挑战副本请求
* Output:         StoryDungeonRpcChallengeReplyWraper& Reply 挑战副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleStoryDungeon::RpcChallenge( INT64 UserId, StoryDungeonRpcChallengeAskWraper& Ask, StoryDungeonRpcChallengeReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientWaitForConfirmation
* Description:    剧情副本-->等待玩家确认是否选择进入异步通知操作函数
* Input:          StoryDungeonRpcWaitForConfirmationNotifyWraper& Notify 等待玩家确认是否选择进入通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleStoryDungeon::SendToClientWaitForConfirmation( INT64 UserId, StoryDungeonRpcWaitForConfirmationNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcConfirmEnter
* Description:    剧情副本-->确认是否进入同步调用操作函数
* Input:          StoryDungeonRpcConfirmEnterAskWraper& Ask 确认是否进入请求
* Output:         StoryDungeonRpcConfirmEnterReplyWraper& Reply 确认是否进入回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleStoryDungeon::RpcConfirmEnter( INT64 UserId, StoryDungeonRpcConfirmEnterAskWraper& Ask, StoryDungeonRpcConfirmEnterReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientPlayerConfirmResult
* Description:    剧情副本-->玩家确认或拒绝进入异步通知操作函数
* Input:          StoryDungeonRpcPlayerConfirmResultNotifyWraper& Notify 玩家确认或拒绝进入通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleStoryDungeon::SendToClientPlayerConfirmResult( INT64 UserId, StoryDungeonRpcPlayerConfirmResultNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



