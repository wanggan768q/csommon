/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcFriendImp.cpp
* Author:       甘业清
* Description:  好友类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "FriendModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncFriendData
* Description:    好友-->每次打开界面，请求一次数据同步调用操作函数
* Input:          FriendRpcSyncFriendDataAskWraper& Ask 每次打开界面，请求一次数据请求
* Output:         FriendRpcSyncFriendDataReplyWraper& Reply 每次打开界面，请求一次数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcSyncFriendData( INT64 UserId, FriendRpcSyncFriendDataAskWraper& Ask, FriendRpcSyncFriendDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAddFriend
* Description:    好友-->增加好友同步调用操作函数
* Input:          FriendRpcAddFriendAskWraper& Ask 增加好友请求
* Output:         FriendRpcAddFriendReplyWraper& Reply 增加好友回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcAddFriend( INT64 UserId, FriendRpcAddFriendAskWraper& Ask, FriendRpcAddFriendReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDelFriend
* Description:    好友-->删除好友同步调用操作函数
* Input:          FriendRpcDelFriendAskWraper& Ask 删除好友请求
* Output:         FriendRpcDelFriendReplyWraper& Reply 删除好友回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcDelFriend( INT64 UserId, FriendRpcDelFriendAskWraper& Ask, FriendRpcDelFriendReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAddBlackList
* Description:    好友-->增加黑名单同步调用操作函数
* Input:          FriendRpcAddBlackListAskWraper& Ask 增加黑名单请求
* Output:         FriendRpcAddBlackListReplyWraper& Reply 增加黑名单回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcAddBlackList( INT64 UserId, FriendRpcAddBlackListAskWraper& Ask, FriendRpcAddBlackListReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDelBlackList
* Description:    好友-->删除黑名单同步调用操作函数
* Input:          FriendRpcDelBlackListAskWraper& Ask 删除黑名单请求
* Output:         FriendRpcDelBlackListReplyWraper& Reply 删除黑名单回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcDelBlackList( INT64 UserId, FriendRpcDelBlackListAskWraper& Ask, FriendRpcDelBlackListReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAddContact
* Description:    好友-->增加最近联系人同步调用操作函数
* Input:          FriendRpcAddContactAskWraper& Ask 增加最近联系人请求
* Output:         FriendRpcAddContactReplyWraper& Reply 增加最近联系人回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcAddContact( INT64 UserId, FriendRpcAddContactAskWraper& Ask, FriendRpcAddContactReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDelContact
* Description:    好友-->删除最近联系人同步调用操作函数
* Input:          FriendRpcDelContactAskWraper& Ask 删除最近联系人请求
* Output:         FriendRpcDelContactReplyWraper& Reply 删除最近联系人回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcDelContact( INT64 UserId, FriendRpcDelContactAskWraper& Ask, FriendRpcDelContactReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSearchPlayer
* Description:    好友-->搜索好友同步调用操作函数
* Input:          FriendRpcSearchPlayerAskWraper& Ask 搜索好友请求
* Output:         FriendRpcSearchPlayerReplyWraper& Reply 搜索好友回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcSearchPlayer( INT64 UserId, FriendRpcSearchPlayerAskWraper& Ask, FriendRpcSearchPlayerReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRecommend
* Description:    好友-->推荐玩家同步调用操作函数
* Input:          FriendRpcRecommendAskWraper& Ask 推荐玩家请求
* Output:         FriendRpcRecommendReplyWraper& Reply 推荐玩家回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcRecommend( INT64 UserId, FriendRpcRecommendAskWraper& Ask, FriendRpcRecommendReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcViewUserSimpleInfo
* Description:    好友-->查看资料简单数据同步调用操作函数
* Input:          FriendRpcViewUserSimpleInfoAskWraper& Ask 查看资料简单数据请求
* Output:         FriendRpcViewUserSimpleInfoReplyWraper& Reply 查看资料简单数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleFriend::RpcViewUserSimpleInfo( INT64 UserId, FriendRpcViewUserSimpleInfoAskWraper& Ask, FriendRpcViewUserSimpleInfoReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientFriendOnlineOffline
* Description:    好友-->好友上下线异步通知操作函数
* Input:          FriendRpcOnlineOfflineNotifyWraper& Notify 好友上下线通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFriend::SendToClientFriendOnlineOffline( INT64 UserId, FriendRpcOnlineOfflineNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



