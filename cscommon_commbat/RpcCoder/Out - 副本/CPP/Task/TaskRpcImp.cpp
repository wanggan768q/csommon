/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcTaskImp.cpp
* Author:       甘业清
* Description:  任务类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "TaskModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    任务-->数据同步同步调用操作函数
* Input:          TaskRpcSyncDataAskWraper& Ask 数据同步请求
* Output:         TaskRpcSyncDataReplyWraper& Reply 数据同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTask::RpcSyncData( INT64 UserId, TaskRpcSyncDataAskWraper& Ask, TaskRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCompleteTask
* Description:    任务-->完成任务目标同步调用操作函数
* Input:          TaskRpcCompleteTaskAskWraper& Ask 完成任务目标请求
* Output:         TaskRpcCompleteTaskReplyWraper& Reply 完成任务目标回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTask::RpcCompleteTask( INT64 UserId, TaskRpcCompleteTaskAskWraper& Ask, TaskRpcCompleteTaskReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSubmitTask
* Description:    任务-->提交任务同步调用操作函数
* Input:          TaskRpcSubmitTaskAskWraper& Ask 提交任务请求
* Output:         TaskRpcSubmitTaskReplyWraper& Reply 提交任务回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTask::RpcSubmitTask( INT64 UserId, TaskRpcSubmitTaskAskWraper& Ask, TaskRpcSubmitTaskReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientUpdateTask
* Description:    任务-->更新任务异步通知操作函数
* Input:          TaskRpcUpdateTaskNotifyWraper& Notify 更新任务通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTask::SendToClientUpdateTask( INT64 UserId, TaskRpcUpdateTaskNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcAcceptTask
* Description:    任务-->接受任务同步调用操作函数
* Input:          TaskRpcAcceptTaskAskWraper& Ask 接受任务请求
* Output:         TaskRpcAcceptTaskReplyWraper& Reply 接受任务回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTask::RpcAcceptTask( INT64 UserId, TaskRpcAcceptTaskAskWraper& Ask, TaskRpcAcceptTaskReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcStartProfTask
* Description:    任务-->开始师门任务同步调用操作函数
* Input:          TaskRpcStartProfTaskAskWraper& Ask 开始师门任务请求
* Output:         TaskRpcStartProfTaskReplyWraper& Reply 开始师门任务回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTask::RpcStartProfTask( INT64 UserId, TaskRpcStartProfTaskAskWraper& Ask, TaskRpcStartProfTaskReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcStartOneDragon
* Description:    任务-->开始一条龙同步调用操作函数
* Input:          TaskRpcStartOneDragonAskWraper& Ask 开始一条龙请求
* Output:         TaskRpcStartOneDragonReplyWraper& Reply 开始一条龙回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTask::RpcStartOneDragon( INT64 UserId, TaskRpcStartOneDragonAskWraper& Ask, TaskRpcStartOneDragonReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientAddTask
* Description:    任务-->增加任务异步通知操作函数
* Input:          TaskRpcAddTaskNotifyWraper& Notify 增加任务通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTask::SendToClientAddTask( INT64 UserId, TaskRpcAddTaskNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDelTask
* Description:    任务-->删除任务异步通知操作函数
* Input:          TaskRpcDelTaskNotifyWraper& Notify 删除任务通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTask::SendToClientDelTask( INT64 UserId, TaskRpcDelTaskNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcStartGuildSpy
* Description:    任务-->开始帮会刺探同步调用操作函数
* Input:          TaskRpcStartGuildSpyAskWraper& Ask 开始帮会刺探请求
* Output:         TaskRpcStartGuildSpyReplyWraper& Reply 开始帮会刺探回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTask::RpcStartGuildSpy( INT64 UserId, TaskRpcStartGuildSpyAskWraper& Ask, TaskRpcStartGuildSpyReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



