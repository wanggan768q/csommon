/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcActivityScheduleImp.cpp
* Author:       甘业清
* Description:  活动日常类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ActivityScheduleModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    活动日常-->活动日常数据同步调用操作函数
* Input:          ActivityScheduleRpcSyncDataAskWraper& Ask 活动日常数据请求
* Output:         ActivityScheduleRpcSyncDataReplyWraper& Reply 活动日常数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivitySchedule::RpcSyncData( INT64 UserId, ActivityScheduleRpcSyncDataAskWraper& Ask, ActivityScheduleRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientThiefBeOpened
* Description:    活动日常-->江洋大盗被开启通知异步通知操作函数
* Input:          ActivityScheduleRpcThiefBeOpenedNotifyWraper& Notify 江洋大盗被开启通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivitySchedule::SendToClientThiefBeOpened( INT64 UserId, ActivityScheduleRpcThiefBeOpenedNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientThiefRefresh
* Description:    活动日常-->江洋大盗刷新异步通知操作函数
* Input:          ActivityScheduleRpcThiefRefreshNotifyWraper& Notify 江洋大盗刷新通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivitySchedule::SendToClientThiefRefresh( INT64 UserId, ActivityScheduleRpcThiefRefreshNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcThiefOpenMonster
* Description:    活动日常-->江洋大盗开怪同步调用操作函数
* Input:          ActivityScheduleRpcThiefOpenMonsterAskWraper& Ask 江洋大盗开怪请求
* Output:         ActivityScheduleRpcThiefOpenMonsterReplyWraper& Reply 江洋大盗开怪回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivitySchedule::RpcThiefOpenMonster( INT64 UserId, ActivityScheduleRpcThiefOpenMonsterAskWraper& Ask, ActivityScheduleRpcThiefOpenMonsterReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSubdueMonsterEnter
* Description:    活动日常-->降妖进入副本同步调用操作函数
* Input:          ActivityScheduleRpcSubdueMonsterEnterAskWraper& Ask 降妖进入副本请求
* Output:         ActivityScheduleRpcSubdueMonsterEnterReplyWraper& Reply 降妖进入副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivitySchedule::RpcSubdueMonsterEnter( INT64 UserId, ActivityScheduleRpcSubdueMonsterEnterAskWraper& Ask, ActivityScheduleRpcSubdueMonsterEnterReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSubdueMonsterBeOpened
* Description:    活动日常-->降妖被其他人开启异步通知操作函数
* Input:          ActivityScheduleRpcSubdueMonsterBeOpenedNotifyWraper& Notify 降妖被其他人开启通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivitySchedule::SendToClientSubdueMonsterBeOpened( INT64 UserId, ActivityScheduleRpcSubdueMonsterBeOpenedNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSubdueMonsterRefresh
* Description:    活动日常-->降妖除魔刷新Npc异步通知操作函数
* Input:          ActivityScheduleRpcSubdueMonsterRefreshNotifyWraper& Notify 降妖除魔刷新Npc通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivitySchedule::SendToClientSubdueMonsterRefresh( INT64 UserId, ActivityScheduleRpcSubdueMonsterRefreshNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcWorldBossEnterDungeon
* Description:    活动日常-->世界Boss进行副本同步调用操作函数
* Input:          ActivityScheduleRpcWorldBossEnterDungeonAskWraper& Ask 世界Boss进行副本请求
* Output:         ActivityScheduleRpcWorldBossEnterDungeonReplyWraper& Reply 世界Boss进行副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivitySchedule::RpcWorldBossEnterDungeon( INT64 UserId, ActivityScheduleRpcWorldBossEnterDungeonAskWraper& Ask, ActivityScheduleRpcWorldBossEnterDungeonReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcWorldBossSyncData
* Description:    活动日常-->世界Boss,打开界面刷新数据同步调用操作函数
* Input:          ActivityScheduleRpcWorldBossSyncDataAskWraper& Ask 世界Boss,打开界面刷新数据请求
* Output:         ActivityScheduleRpcWorldBossSyncDataReplyWraper& Reply 世界Boss,打开界面刷新数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleActivitySchedule::RpcWorldBossSyncData( INT64 UserId, ActivityScheduleRpcWorldBossSyncDataAskWraper& Ask, ActivityScheduleRpcWorldBossSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



