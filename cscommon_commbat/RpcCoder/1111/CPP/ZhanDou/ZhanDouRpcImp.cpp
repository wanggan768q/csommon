/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcZhanDouImp.cpp
* Author:       甘业清
* Description:  战斗类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ZhanDouModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcMove
* Description:    战斗-->zou同步调用操作函数
* Input:          ZhanDouRpcMoveAskWraper& Ask zou请求
* Output:         ZhanDouRpcMoveReplyWraper& Reply zou回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleZhanDou::RpcMove( INT64 UserId, ZhanDouRpcMoveAskWraper& Ask, ZhanDouRpcMoveReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientTalk
* Description:    战斗-->聊天异步通知操作函数
* Input:          ZhanDouRpcTalkNotifyWraper& Notify 聊天通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleZhanDou::SendToClientTalk( INT64 UserId, ZhanDouRpcTalkNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



