/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcTransportImp.cpp
* Author:       甘业清
* Description:  货运类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "TransportModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    货运-->数据同步同步调用操作函数
* Input:          TransportRpcSyncDataAskWraper& Ask 数据同步请求
* Output:         TransportRpcSyncDataReplyWraper& Reply 数据同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTransport::RpcSyncData( INT64 UserId, TransportRpcSyncDataAskWraper& Ask, TransportRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcFill
* Description:    货运-->填充同步调用操作函数
* Input:          TransportRpcFillAskWraper& Ask 填充请求
* Output:         TransportRpcFillReplyWraper& Reply 填充回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTransport::RpcFill( INT64 UserId, TransportRpcFillAskWraper& Ask, TransportRpcFillReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcHelpOther
* Description:    货运-->帮助请求同步调用操作函数
* Input:          TransportRpcHelpOtherAskWraper& Ask 帮助请求请求
* Output:         TransportRpcHelpOtherReplyWraper& Reply 帮助请求回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTransport::RpcHelpOther( INT64 UserId, TransportRpcHelpOtherAskWraper& Ask, TransportRpcHelpOtherReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAskHelp
* Description:    货运-->请求帮助同步调用操作函数
* Input:          TransportRpcAskHelpAskWraper& Ask 请求帮助请求
* Output:         TransportRpcAskHelpReplyWraper& Reply 请求帮助回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTransport::RpcAskHelp( INT64 UserId, TransportRpcAskHelpAskWraper& Ask, TransportRpcAskHelpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSetSail
* Description:    货运-->起航请求同步调用操作函数
* Input:          TransportRpcSetSailAskWraper& Ask 起航请求请求
* Output:         TransportRpcSetSailReplyWraper& Reply 起航请求回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTransport::RpcSetSail( INT64 UserId, TransportRpcSetSailAskWraper& Ask, TransportRpcSetSailReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAddTransport
* Description:    货运-->添加货物同步调用操作函数
* Input:          TransportRpcAddTransportAskWraper& Ask 添加货物请求
* Output:         TransportRpcAddTransportReplyWraper& Reply 添加货物回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTransport::RpcAddTransport( INT64 UserId, TransportRpcAddTransportAskWraper& Ask, TransportRpcAddTransportReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientIsHelped
* Description:    货运-->自己被帮助通知异步通知操作函数
* Input:          TransportRpcIsHelpedNotifyWraper& Notify 自己被帮助通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTransport::SendToClientIsHelped( INT64 UserId, TransportRpcIsHelpedNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



