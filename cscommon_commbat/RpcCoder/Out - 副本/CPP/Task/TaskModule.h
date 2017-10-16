/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTask.h
* Author:       甘业清
* Description:  任务类，包含以下内容
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

#ifndef __MODULE_TASK_H
#define __MODULE_TASK_H


#include "ModuleBase.h"
#include "TaskRpcWraper.h"
#include "TaskV1Data.h"
#include "TaskV1DataWraper.h"




//任务实现类
class ModuleTask : public ModuleBase
{
	DECLARE_INSTANCE(ModuleTask);
public:
	friend class			ModuleMgr;

public:
	//任务实现类构造函数
	ModuleTask();
	
	//任务实现类析构函数
	virtual					~ModuleTask();

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
	* Description:    任务-->数据同步同步调用操作函数
	* Input:          TaskRpcSyncDataAskWraper& Ask 数据同步请求
	* Output:         TaskRpcSyncDataReplyWraper& Reply 数据同步回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncData( INT64 UserId, TaskRpcSyncDataAskWraper& Ask, TaskRpcSyncDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcCompleteTask
	* Description:    任务-->完成任务目标同步调用操作函数
	* Input:          TaskRpcCompleteTaskAskWraper& Ask 完成任务目标请求
	* Output:         TaskRpcCompleteTaskReplyWraper& Reply 完成任务目标回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcCompleteTask( INT64 UserId, TaskRpcCompleteTaskAskWraper& Ask, TaskRpcCompleteTaskReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcSubmitTask
	* Description:    任务-->提交任务同步调用操作函数
	* Input:          TaskRpcSubmitTaskAskWraper& Ask 提交任务请求
	* Output:         TaskRpcSubmitTaskReplyWraper& Reply 提交任务回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSubmitTask( INT64 UserId, TaskRpcSubmitTaskAskWraper& Ask, TaskRpcSubmitTaskReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientUpdateTask
	* Description:    任务-->更新任务异步通知操作函数
	* Input:          TaskRpcUpdateTaskNotifyWraper& Notify 更新任务通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientUpdateTask( INT64 UserId, TaskRpcUpdateTaskNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAcceptTask
	* Description:    任务-->接受任务同步调用操作函数
	* Input:          TaskRpcAcceptTaskAskWraper& Ask 接受任务请求
	* Output:         TaskRpcAcceptTaskReplyWraper& Reply 接受任务回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAcceptTask( INT64 UserId, TaskRpcAcceptTaskAskWraper& Ask, TaskRpcAcceptTaskReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcStartProfTask
	* Description:    任务-->开始师门任务同步调用操作函数
	* Input:          TaskRpcStartProfTaskAskWraper& Ask 开始师门任务请求
	* Output:         TaskRpcStartProfTaskReplyWraper& Reply 开始师门任务回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcStartProfTask( INT64 UserId, TaskRpcStartProfTaskAskWraper& Ask, TaskRpcStartProfTaskReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcStartOneDragon
	* Description:    任务-->开始一条龙同步调用操作函数
	* Input:          TaskRpcStartOneDragonAskWraper& Ask 开始一条龙请求
	* Output:         TaskRpcStartOneDragonReplyWraper& Reply 开始一条龙回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcStartOneDragon( INT64 UserId, TaskRpcStartOneDragonAskWraper& Ask, TaskRpcStartOneDragonReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientAddTask
	* Description:    任务-->增加任务异步通知操作函数
	* Input:          TaskRpcAddTaskNotifyWraper& Notify 增加任务通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientAddTask( INT64 UserId, TaskRpcAddTaskNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDelTask
	* Description:    任务-->删除任务异步通知操作函数
	* Input:          TaskRpcDelTaskNotifyWraper& Notify 删除任务通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientDelTask( INT64 UserId, TaskRpcDelTaskNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcStartGuildSpy
	* Description:    任务-->开始帮会刺探同步调用操作函数
	* Input:          TaskRpcStartGuildSpyAskWraper& Ask 开始帮会刺探请求
	* Output:         TaskRpcStartGuildSpyReplyWraper& Reply 开始帮会刺探回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcStartGuildSpy( INT64 UserId, TaskRpcStartGuildSpyAskWraper& Ask, TaskRpcStartGuildSpyReplyWraper& Reply );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif