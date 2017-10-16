/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcDropItemImp.cpp
* Author:       甘业清
* Description:  掉落物类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "DropItemModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientDropItemNotice
* Description:    掉落物-->物品掉落通知异步通知操作函数
* Input:          DropItemRpcDropItemNoticeNotifyWraper& Notify 物品掉落通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDropItem::SendToClientDropItemNotice( INT64 UserId, DropItemRpcDropItemNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcPickupItem
* Description:    掉落物-->捡物品同步调用操作函数
* Input:          DropItemRpcPickupItemAskWraper& Ask 捡物品请求
* Output:         DropItemRpcPickupItemReplyWraper& Reply 捡物品回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleDropItem::RpcPickupItem( INT64 UserId, DropItemRpcPickupItemAskWraper& Ask, DropItemRpcPickupItemReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientDelDropItem
* Description:    掉落物-->删除掉落异步通知操作函数
* Input:          DropItemRpcDelDropItemNotifyWraper& Notify 删除掉落通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDropItem::SendToClientDelDropItem( INT64 UserId, DropItemRpcDelDropItemNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



