/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcOneVSOneImp.cpp
* Author:       甘业清
* Description:  一v一类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "OneVSOneModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcFlush
* Description:    一v一-->刷新自己的数据同步调用操作函数
* Input:          OneVSOneRpcFlushAskWraper& Ask 刷新自己的数据请求
* Output:         OneVSOneRpcFlushReplyWraper& Reply 刷新自己的数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleOneVSOne::RpcFlush( INT64 UserId, OneVSOneRpcFlushAskWraper& Ask, OneVSOneRpcFlushReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAct
* Description:    一v一-->发起挑战同步调用操作函数
* Input:          OneVSOneRpcActAskWraper& Ask 发起挑战请求
* Output:         OneVSOneRpcActReplyWraper& Reply 发起挑战回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleOneVSOne::RpcAct( INT64 UserId, OneVSOneRpcActAskWraper& Ask, OneVSOneRpcActReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientActMessage
* Description:    一v一-->挑战消息异步通知操作函数
* Input:          OneVSOneRpcActMessageNotifyWraper& Notify 挑战消息通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleOneVSOne::SendToClientActMessage( INT64 UserId, OneVSOneRpcActMessageNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcReplyAct
* Description:    一v一-->回应谁的挑战同步调用操作函数
* Input:          OneVSOneRpcReplyActAskWraper& Ask 回应谁的挑战请求
* Output:         OneVSOneRpcReplyActReplyWraper& Reply 回应谁的挑战回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleOneVSOne::RpcReplyAct( INT64 UserId, OneVSOneRpcReplyActAskWraper& Ask, OneVSOneRpcReplyActReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetTop
* Description:    一v一-->排行榜数据同步调用操作函数
* Input:          OneVSOneRpcGetTopAskWraper& Ask 排行榜数据请求
* Output:         OneVSOneRpcGetTopReplyWraper& Reply 排行榜数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleOneVSOne::RpcGetTop( INT64 UserId, OneVSOneRpcGetTopAskWraper& Ask, OneVSOneRpcGetTopReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAdjustmentSkill
* Description:    一v一-->调整技能同步调用操作函数
* Input:          OneVSOneRpcAdjustmentSkillAskWraper& Ask 调整技能请求
* Output:         OneVSOneRpcAdjustmentSkillReplyWraper& Reply 调整技能回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleOneVSOne::RpcAdjustmentSkill( INT64 UserId, OneVSOneRpcAdjustmentSkillAskWraper& Ask, OneVSOneRpcAdjustmentSkillReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetSkill
* Description:    一v一-->获取设置的技能同步调用操作函数
* Input:          OneVSOneRpcGetSkillAskWraper& Ask 获取设置的技能请求
* Output:         OneVSOneRpcGetSkillReplyWraper& Reply 获取设置的技能回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleOneVSOne::RpcGetSkill( INT64 UserId, OneVSOneRpcGetSkillAskWraper& Ask, OneVSOneRpcGetSkillReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetActMessage
* Description:    一v一-->获得攻守的信息同步调用操作函数
* Input:          OneVSOneRpcGetActMessageAskWraper& Ask 获得攻守的信息请求
* Output:         OneVSOneRpcGetActMessageReplyWraper& Reply 获得攻守的信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleOneVSOne::RpcGetActMessage( INT64 UserId, OneVSOneRpcGetActMessageAskWraper& Ask, OneVSOneRpcGetActMessageReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientACTResultNotify
* Description:    一v一-->战斗结果Notify 叶青给我我就给客户端异步通知操作函数
* Input:          OneVSOneRpcACTResultNotifyNotifyWraper& Notify 战斗结果Notify 叶青给我我就给客户端通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleOneVSOne::SendToClientACTResultNotify( INT64 UserId, OneVSOneRpcACTResultNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



