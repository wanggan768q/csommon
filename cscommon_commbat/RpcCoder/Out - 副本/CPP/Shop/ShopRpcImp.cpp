/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcShopImp.cpp
* Author:       甘业清
* Description:  商城类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ShopModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    商城-->数据同步同步调用操作函数
* Input:          ShopRpcSyncDataAskWraper& Ask 数据同步请求
* Output:         ShopRpcSyncDataReplyWraper& Reply 数据同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleShop::RpcSyncData( INT64 UserId, ShopRpcSyncDataAskWraper& Ask, ShopRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcBuy
* Description:    商城-->购买同步调用操作函数
* Input:          ShopRpcBuyAskWraper& Ask 购买请求
* Output:         ShopRpcBuyReplyWraper& Reply 购买回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleShop::RpcBuy( INT64 UserId, ShopRpcBuyAskWraper& Ask, ShopRpcBuyReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRefreshItem
* Description:    商城-->刷新道具同步调用操作函数
* Input:          ShopRpcRefreshItemAskWraper& Ask 刷新道具请求
* Output:         ShopRpcRefreshItemReplyWraper& Reply 刷新道具回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleShop::RpcRefreshItem( INT64 UserId, ShopRpcRefreshItemAskWraper& Ask, ShopRpcRefreshItemReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



