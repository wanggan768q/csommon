/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcActivityStormImp.cpp
* Author:       甘业清
* Description:  活动 风暴类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ActivityStormModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSignUp
* Description:    活动 风暴-->报名同步调用操作函数
* Input:          ActivityStormRpcSignUpAskWraper& Ask 报名请求
* Output:         ActivityStormRpcSignUpReplyWraper& Reply 报名回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivityStorm::RpcSignUp( INT64 UserId, ActivityStormRpcSignUpAskWraper& Ask, ActivityStormRpcSignUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCancelSignUp
* Description:    活动 风暴-->取消报名同步调用操作函数
* Input:          ActivityStormRpcCancelSignUpAskWraper& Ask 取消报名请求
* Output:         ActivityStormRpcCancelSignUpReplyWraper& Reply 取消报名回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivityStorm::RpcCancelSignUp( INT64 UserId, ActivityStormRpcCancelSignUpAskWraper& Ask, ActivityStormRpcCancelSignUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInsertBattlefield
* Description:    活动 风暴-->进入战场同步调用操作函数
* Input:          ActivityStormRpcInsertBattlefieldAskWraper& Ask 进入战场请求
* Output:         ActivityStormRpcInsertBattlefieldReplyWraper& Reply 进入战场回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivityStorm::RpcInsertBattlefield( INT64 UserId, ActivityStormRpcInsertBattlefieldAskWraper& Ask, ActivityStormRpcInsertBattlefieldReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientBattlefieldMessage
* Description:    活动 风暴-->战场信息异步通知操作函数
* Input:          ActivityStormRpcBattlefieldMessageNotifyWraper& Notify 战场信息通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivityStorm::SendToClientBattlefieldMessage( INT64 UserId, ActivityStormRpcBattlefieldMessageNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientTimeOutMessage
* Description:    活动 风暴-->超时消息主推异步通知操作函数
* Input:          ActivityStormRpcTimeOutMessageNotifyWraper& Notify 超时消息主推通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivityStorm::SendToClientTimeOutMessage( INT64 UserId, ActivityStormRpcTimeOutMessageNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSyncData
* Description:    活动 风暴-->同步数据同步调用操作函数
* Input:          ActivityStormRpcSyncDataAskWraper& Ask 同步数据请求
* Output:         ActivityStormRpcSyncDataReplyWraper& Reply 同步数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivityStorm::RpcSyncData( INT64 UserId, ActivityStormRpcSyncDataAskWraper& Ask, ActivityStormRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientJoinLevevNotify
* Description:    活动 风暴-->加入离开notify异步通知操作函数
* Input:          ActivityStormRpcJoinLevevNotifyNotifyWraper& Notify 加入离开notify通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivityStorm::SendToClientJoinLevevNotify( INT64 UserId, ActivityStormRpcJoinLevevNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcCanceInsertBattle
* Description:    活动 风暴-->取消进入战场同步调用操作函数
* Input:          ActivityStormRpcCanceInsertBattleAskWraper& Ask 取消进入战场请求
* Output:         ActivityStormRpcCanceInsertBattleReplyWraper& Reply 取消进入战场回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivityStorm::RpcCanceInsertBattle( INT64 UserId, ActivityStormRpcCanceInsertBattleAskWraper& Ask, ActivityStormRpcCanceInsertBattleReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientResetSignUpNotify
* Description:    活动 风暴-->重置报名异步通知操作函数
* Input:          ActivityStormRpcResetSignUpNotifyNotifyWraper& Notify 重置报名通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivityStorm::SendToClientResetSignUpNotify( INT64 UserId, ActivityStormRpcResetSignUpNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



