/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcChatImp.cpp
* Author:       甘业清
* Description:  聊天类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ChatModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSendChat
* Description:    聊天-->发送聊天同步调用操作函数
* Input:          ChatRpcSendChatAskWraper& Ask 发送聊天请求
* Output:         ChatRpcSendChatReplyWraper& Reply 发送聊天回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleChat::RpcSendChat( INT64 UserId, ChatRpcSendChatAskWraper& Ask, ChatRpcSendChatReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSyncChat
* Description:    聊天-->同步聊天异步通知操作函数
* Input:          ChatRpcSyncChatNotifyWraper& Notify 同步聊天通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleChat::SendToClientSyncChat( INT64 UserId, ChatRpcSyncChatNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncPrivateChatMsg
* Description:    聊天-->同步私聊留言异步通知操作函数
* Input:          ChatRpcSyncPrivateChatMsgNotifyWraper& Notify 同步私聊留言通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleChat::SendToClientSyncPrivateChatMsg( INT64 UserId, ChatRpcSyncPrivateChatMsgNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSvrChat
* Description:    聊天-->服务器发送聊天异步通知操作函数
* Input:          ChatRpcSvrChatNotifyWraper& Notify 服务器发送聊天通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleChat::SendToClientSvrChat( INT64 UserId, ChatRpcSvrChatNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



