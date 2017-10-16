/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcTalismanImp.cpp
* Author:       甘业清
* Description:  法宝类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "TalismanModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    法宝-->数据同步同步调用操作函数
* Input:          TalismanRpcSyncDataAskWraper& Ask 数据同步请求
* Output:         TalismanRpcSyncDataReplyWraper& Reply 数据同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTalisman::RpcSyncData( INT64 UserId, TalismanRpcSyncDataAskWraper& Ask, TalismanRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcActive
* Description:    法宝-->激活同步调用操作函数
* Input:          TalismanRpcActiveAskWraper& Ask 激活请求
* Output:         TalismanRpcActiveReplyWraper& Reply 激活回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTalisman::RpcActive( INT64 UserId, TalismanRpcActiveAskWraper& Ask, TalismanRpcActiveReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUpgrade
* Description:    法宝-->升级同步调用操作函数
* Input:          TalismanRpcUpgradeAskWraper& Ask 升级请求
* Output:         TalismanRpcUpgradeReplyWraper& Reply 升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTalisman::RpcUpgrade( INT64 UserId, TalismanRpcUpgradeAskWraper& Ask, TalismanRpcUpgradeReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



