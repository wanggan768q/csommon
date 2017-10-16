/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcPersistAttrImp.cpp
* Author:       甘业清
* Description:  常驻内存属性模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "PersistAttrModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    常驻内存属性模块-->同步背包数据同步调用操作函数
* Input:          PersistAttrRpcSyncDataAskWraper& Ask 同步背包数据请求
* Output:         PersistAttrRpcSyncDataReplyWraper& Reply 同步背包数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModulePersistAttr::RpcSyncData( INT64 UserId, PersistAttrRpcSyncDataAskWraper& Ask, PersistAttrRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



