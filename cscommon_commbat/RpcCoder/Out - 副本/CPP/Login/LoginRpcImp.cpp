/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcLoginImp.cpp
* Author:       甘业清
* Description:  登录模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "LoginModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcKeyAuth
* Description:    登录模块-->密钥认证同步调用操作函数
* Input:          LoginRpcKeyAuthAskWraper& Ask 密钥认证请求
* Output:         LoginRpcKeyAuthReplyWraper& Reply 密钥认证回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleLogin::RpcKeyAuth( INT64 UserId, LoginRpcKeyAuthAskWraper& Ask, LoginRpcKeyAuthReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientKickOff
* Description:    登录模块-->被踢下线异步通知操作函数
* Input:          LoginRpcKickOffNotifyWraper& Notify 被踢下线通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleLogin::SendToClientKickOff( INT64 UserId, LoginRpcKickOffNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



