/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcActivityEscapeImp.cpp
* Author:       甘业清
* Description:  活动 大逃杀类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ActivityEscapeModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSignUp
* Description:    活动 大逃杀-->报名进入同步调用操作函数
* Input:          ActivityEscapeRpcSignUpAskWraper& Ask 报名进入请求
* Output:         ActivityEscapeRpcSignUpReplyWraper& Reply 报名进入回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivityEscape::RpcSignUp( INT64 UserId, ActivityEscapeRpcSignUpAskWraper& Ask, ActivityEscapeRpcSignUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



