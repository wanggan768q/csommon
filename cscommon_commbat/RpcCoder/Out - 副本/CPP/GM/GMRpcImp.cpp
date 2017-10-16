/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcGMImp.cpp
* Author:       甘业清
* Description:  GM指令类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "GMModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcAction
* Description:    GM指令-->指令动作同步调用操作函数
* Input:          GMRpcActionAskWraper& Ask 指令动作请求
* Output:         GMRpcActionReplyWraper& Reply 指令动作回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGM::RpcAction( INT64 UserId, GMRpcActionAskWraper& Ask, GMRpcActionReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



