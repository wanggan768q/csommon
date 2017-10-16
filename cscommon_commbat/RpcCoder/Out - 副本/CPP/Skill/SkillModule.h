/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleSkill.h
* Author:       甘业清
* Description:  技能类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_SKILL_H
#define __MODULE_SKILL_H


#include "ModuleBase.h"
#include "SkillRpcWraper.h"
#include "SkillV1Data.h"
#include "SkillV1DataWraper.h"




//技能实现类
class ModuleSkill : public ModuleBase
{
	DECLARE_INSTANCE(ModuleSkill);
public:
	friend class			ModuleMgr;

public:
	//技能实现类构造函数
	ModuleSkill();
	
	//技能实现类析构函数
	virtual					~ModuleSkill();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetModuleDataVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//获取初始化顺序
	virtual int				GetInitializeOrder();
	
	//获取结束退出顺序
	virtual int				GetFinalizeOrder();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 userId, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 userId, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 userId );

	//是否要同步数据到客户端
	virtual bool			NotSyncToClient( UINT16 usSyncId );
	
	//同步数据修改后回调
	virtual void			NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex=-1);

public:
	/********************************************************************************************
	* Function:       RpcSyncData
	* Description:    技能-->数据同步同步调用操作函数
	* Input:          SkillRpcSyncDataAskWraper& Ask 数据同步请求
	* Output:         SkillRpcSyncDataReplyWraper& Reply 数据同步回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncData( INT64 UserId, SkillRpcSyncDataAskWraper& Ask, SkillRpcSyncDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcLearn
	* Description:    技能-->学习同步调用操作函数
	* Input:          SkillRpcLearnAskWraper& Ask 学习请求
	* Output:         SkillRpcLearnReplyWraper& Reply 学习回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcLearn( INT64 UserId, SkillRpcLearnAskWraper& Ask, SkillRpcLearnReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcLvUp
	* Description:    技能-->升级同步调用操作函数
	* Input:          SkillRpcLvUpAskWraper& Ask 升级请求
	* Output:         SkillRpcLvUpReplyWraper& Reply 升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcLvUp( INT64 UserId, SkillRpcLvUpAskWraper& Ask, SkillRpcLvUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcChangeShortcut
	* Description:    技能-->修改快捷栏同步调用操作函数
	* Input:          SkillRpcChangeShortcutAskWraper& Ask 修改快捷栏请求
	* Output:         SkillRpcChangeShortcutReplyWraper& Reply 修改快捷栏回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcChangeShortcut( INT64 UserId, SkillRpcChangeShortcutAskWraper& Ask, SkillRpcChangeShortcutReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcUseShortcut
	* Description:    技能-->使用技能方案同步调用操作函数
	* Input:          SkillRpcUseShortcutAskWraper& Ask 使用技能方案请求
	* Output:         SkillRpcUseShortcutReplyWraper& Reply 使用技能方案回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcUseShortcut( INT64 UserId, SkillRpcUseShortcutAskWraper& Ask, SkillRpcUseShortcutReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcOneKeyLvUp
	* Description:    技能-->一键升级同步调用操作函数
	* Input:          SkillRpcOneKeyLvUpAskWraper& Ask 一键升级请求
	* Output:         SkillRpcOneKeyLvUpReplyWraper& Reply 一键升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcOneKeyLvUp( INT64 UserId, SkillRpcOneKeyLvUpAskWraper& Ask, SkillRpcOneKeyLvUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcTalentLvUp
	* Description:    技能-->天赋槽位升级同步调用操作函数
	* Input:          SkillRpcTalentLvUpAskWraper& Ask 天赋槽位升级请求
	* Output:         SkillRpcTalentLvUpReplyWraper& Reply 天赋槽位升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcTalentLvUp( INT64 UserId, SkillRpcTalentLvUpAskWraper& Ask, SkillRpcTalentLvUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcTalentChangeSkill
	* Description:    技能-->天赋槽位切换技能同步调用操作函数
	* Input:          SkillRpcTalentChangeSkillAskWraper& Ask 天赋槽位切换技能请求
	* Output:         SkillRpcTalentChangeSkillReplyWraper& Reply 天赋槽位切换技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcTalentChangeSkill( INT64 UserId, SkillRpcTalentChangeSkillAskWraper& Ask, SkillRpcTalentChangeSkillReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcTalentReset
	* Description:    技能-->天赋重置同步调用操作函数
	* Input:          SkillRpcTalentResetAskWraper& Ask 天赋重置请求
	* Output:         SkillRpcTalentResetReplyWraper& Reply 天赋重置回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcTalentReset( INT64 UserId, SkillRpcTalentResetAskWraper& Ask, SkillRpcTalentResetReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcLifeSkillUp
	* Description:    技能-->升级生活技能同步调用操作函数
	* Input:          SkillRpcLifeSkillUpAskWraper& Ask 升级生活技能请求
	* Output:         SkillRpcLifeSkillUpReplyWraper& Reply 升级生活技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcLifeSkillUp( INT64 UserId, SkillRpcLifeSkillUpAskWraper& Ask, SkillRpcLifeSkillUpReplyWraper& Reply );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif