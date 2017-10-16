/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcFightImp.cpp
* Author:       甘业清
* Description:  战斗类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "FightModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcReady
* Description:    战斗-->游戏准备就绪同步调用操作函数
* Input:          FightRpcReadyAskWraper& Ask 准备就绪请求
* Output:         FightRpcReadyReplyWraper& Reply 准备就绪回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFight::RpcReady( INT64 UserId, FightRpcReadyAskWraper& Ask, FightRpcReadyReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAction
* Description:    战斗-->动作异步通知操作函数
* Input:          FightRpcActionNotifyWraper& Notify 动作通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleFight::RpcAction( INT64 UserId, FightRpcActionNotifyWraper& Notify )
{

	//检测字段[动作数据]数据范围
	if( Notify.GetData().length()<6 ) 
	{
		assert(false);
		return 0;
	}
	if( Notify.GetData().length()>128) 
	{
		assert(false);
		return 0;
	}

	//检测字段[当前帧号]数据范围
	if( Notify.GetFrame()<-1 && Notify.GetFrame()!=-1)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetFrame()>10000000 && Notify.GetFrame()!=-1)
	{
		assert(false);
		return 0;
	}

	//逻辑代码


	return 0;
}

/********************************************************************************************
* Function:       SendToClientAction
* Description:    战斗-->动作异步通知操作函数
* Input:          FightRpcActionNotifyWraper& Notify 动作通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientAction( INT64 UserId, FightRpcActionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientResult
* Description:    战斗-->战斗结果异步通知操作函数
* Input:          FightRpcResultNotifyWraper& Notify 战斗结果通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientResult( INT64 UserId, FightRpcResultNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcEnter
* Description:    战斗-->进入副本同步调用操作函数
* Input:          FightRpcEnterAskWraper& Ask 进入副本请求
* Output:         FightRpcEnterReplyWraper& Reply 进入副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFight::RpcEnter( INT64 UserId, FightRpcEnterAskWraper& Ask, FightRpcEnterReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientStart
* Description:    战斗-->战斗开始异步通知操作函数
* Input:          FightRpcStartNotifyWraper& Notify 战斗开始通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientStart( INT64 UserId, FightRpcStartNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



