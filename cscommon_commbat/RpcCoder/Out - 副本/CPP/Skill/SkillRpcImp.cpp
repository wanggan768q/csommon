/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcSkillImp.cpp
* Author:       甘业清
* Description:  技能类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "SkillModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    技能-->数据同步同步调用操作函数
* Input:          SkillRpcSyncDataAskWraper& Ask 数据同步请求
* Output:         SkillRpcSyncDataReplyWraper& Reply 数据同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcSyncData( INT64 UserId, SkillRpcSyncDataAskWraper& Ask, SkillRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLearn
* Description:    技能-->学习同步调用操作函数
* Input:          SkillRpcLearnAskWraper& Ask 学习请求
* Output:         SkillRpcLearnReplyWraper& Reply 学习回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcLearn( INT64 UserId, SkillRpcLearnAskWraper& Ask, SkillRpcLearnReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLvUp
* Description:    技能-->升级同步调用操作函数
* Input:          SkillRpcLvUpAskWraper& Ask 升级请求
* Output:         SkillRpcLvUpReplyWraper& Reply 升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcLvUp( INT64 UserId, SkillRpcLvUpAskWraper& Ask, SkillRpcLvUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChangeShortcut
* Description:    技能-->修改快捷栏同步调用操作函数
* Input:          SkillRpcChangeShortcutAskWraper& Ask 修改快捷栏请求
* Output:         SkillRpcChangeShortcutReplyWraper& Reply 修改快捷栏回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcChangeShortcut( INT64 UserId, SkillRpcChangeShortcutAskWraper& Ask, SkillRpcChangeShortcutReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUseShortcut
* Description:    技能-->使用技能方案同步调用操作函数
* Input:          SkillRpcUseShortcutAskWraper& Ask 使用技能方案请求
* Output:         SkillRpcUseShortcutReplyWraper& Reply 使用技能方案回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcUseShortcut( INT64 UserId, SkillRpcUseShortcutAskWraper& Ask, SkillRpcUseShortcutReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcOneKeyLvUp
* Description:    技能-->一键升级同步调用操作函数
* Input:          SkillRpcOneKeyLvUpAskWraper& Ask 一键升级请求
* Output:         SkillRpcOneKeyLvUpReplyWraper& Reply 一键升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcOneKeyLvUp( INT64 UserId, SkillRpcOneKeyLvUpAskWraper& Ask, SkillRpcOneKeyLvUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTalentLvUp
* Description:    技能-->天赋槽位升级同步调用操作函数
* Input:          SkillRpcTalentLvUpAskWraper& Ask 天赋槽位升级请求
* Output:         SkillRpcTalentLvUpReplyWraper& Reply 天赋槽位升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcTalentLvUp( INT64 UserId, SkillRpcTalentLvUpAskWraper& Ask, SkillRpcTalentLvUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTalentChangeSkill
* Description:    技能-->天赋槽位切换技能同步调用操作函数
* Input:          SkillRpcTalentChangeSkillAskWraper& Ask 天赋槽位切换技能请求
* Output:         SkillRpcTalentChangeSkillReplyWraper& Reply 天赋槽位切换技能回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcTalentChangeSkill( INT64 UserId, SkillRpcTalentChangeSkillAskWraper& Ask, SkillRpcTalentChangeSkillReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTalentReset
* Description:    技能-->天赋重置同步调用操作函数
* Input:          SkillRpcTalentResetAskWraper& Ask 天赋重置请求
* Output:         SkillRpcTalentResetReplyWraper& Reply 天赋重置回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcTalentReset( INT64 UserId, SkillRpcTalentResetAskWraper& Ask, SkillRpcTalentResetReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLifeSkillUp
* Description:    技能-->升级生活技能同步调用操作函数
* Input:          SkillRpcLifeSkillUpAskWraper& Ask 升级生活技能请求
* Output:         SkillRpcLifeSkillUpReplyWraper& Reply 升级生活技能回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleSkill::RpcLifeSkillUp( INT64 UserId, SkillRpcLifeSkillUpAskWraper& Ask, SkillRpcLifeSkillUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



