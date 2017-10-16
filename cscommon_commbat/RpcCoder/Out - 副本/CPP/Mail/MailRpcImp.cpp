/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcMailImp.cpp
* Author:       甘业清
* Description:  邮件类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "MailModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcMailHead
* Description:    邮件-->获得邮件头同步调用操作函数
* Input:          MailRpcMailHeadAskWraper& Ask 获得邮件头请求
* Output:         MailRpcMailHeadReplyWraper& Reply 获得邮件头回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleMail::RpcMailHead( INT64 UserId, MailRpcMailHeadAskWraper& Ask, MailRpcMailHeadReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcOpenMail
* Description:    邮件-->获得邮件内容同步调用操作函数
* Input:          MailRpcOpenMailAskWraper& Ask 获得邮件内容请求
* Output:         MailRpcOpenMailReplyWraper& Reply 获得邮件内容回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleMail::RpcOpenMail( INT64 UserId, MailRpcOpenMailAskWraper& Ask, MailRpcOpenMailReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientNewMail
* Description:    邮件-->获得新邮件异步通知操作函数
* Input:          MailRpcNewMailNotifyWraper& Notify 获得新邮件通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMail::SendToClientNewMail( INT64 UserId, MailRpcNewMailNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcDelMail
* Description:    邮件-->删除邮件同步调用操作函数
* Input:          MailRpcDelMailAskWraper& Ask 删除邮件请求
* Output:         MailRpcDelMailReplyWraper& Reply 删除邮件回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleMail::RpcDelMail( INT64 UserId, MailRpcDelMailAskWraper& Ask, MailRpcDelMailReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetReward
* Description:    邮件-->领取奖励同步调用操作函数
* Input:          MailRpcGetRewardAskWraper& Ask 领取奖励请求
* Output:         MailRpcGetRewardReplyWraper& Reply 领取奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleMail::RpcGetReward( INT64 UserId, MailRpcGetRewardAskWraper& Ask, MailRpcGetRewardReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcOneKeyGetReward
* Description:    邮件-->一键领取同步调用操作函数
* Input:          MailRpcOneKeyGetRewardAskWraper& Ask 一键领取请求
* Output:         MailRpcOneKeyGetRewardReplyWraper& Reply 一键领取回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleMail::RpcOneKeyGetReward( INT64 UserId, MailRpcOneKeyGetRewardAskWraper& Ask, MailRpcOneKeyGetRewardReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



