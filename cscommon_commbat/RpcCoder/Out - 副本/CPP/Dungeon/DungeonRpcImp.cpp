/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcDungeonImp.cpp
* Author:       甘业清
* Description:  进出副本模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "DungeonModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcEnter
* Description:    进出副本模块-->进入同步调用操作函数
* Input:          DungeonRpcEnterAskWraper& Ask 进入请求
* Output:         DungeonRpcEnterReplyWraper& Reply 进入回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleDungeon::RpcEnter( INT64 UserId, DungeonRpcEnterAskWraper& Ask, DungeonRpcEnterReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientOpen
* Description:    进出副本模块-->打开副本通知异步通知操作函数
* Input:          DungeonRpcOpenNotifyWraper& Notify 打开副本通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDungeon::SendToClientOpen( INT64 UserId, DungeonRpcOpenNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcTryEnter
* Description:    进出副本模块-->能否进入同步调用操作函数
* Input:          DungeonRpcTryEnterAskWraper& Ask 能否进入请求
* Output:         DungeonRpcTryEnterReplyWraper& Reply 能否进入回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleDungeon::RpcTryEnter( INT64 UserId, DungeonRpcTryEnterAskWraper& Ask, DungeonRpcTryEnterReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientTransfer
* Description:    进出副本模块-->传送异步通知操作函数
* Input:          DungeonRpcTransferNotifyWraper& Notify 传送通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDungeon::SendToClientTransfer( INT64 UserId, DungeonRpcTransferNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



