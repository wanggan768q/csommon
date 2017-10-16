/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleActivityStorm.h
* Author:       甘业清
* Description:  活动 风暴类，包含以下内容
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

#ifndef __MODULE_ACTIVITYSTORM_H
#define __MODULE_ACTIVITYSTORM_H


#include "ModuleBase.h"
#include "ActivityStormRpcWraper.h"
#include "ActivityStormV1Data.h"
#include "ActivityStormV1DataWraper.h"




//活动 风暴实现类
class ModuleActivityStorm : public ModuleBase
{
	DECLARE_INSTANCE(ModuleActivityStorm);
public:
	friend class			ModuleMgr;

public:
	//活动 风暴实现类构造函数
	ModuleActivityStorm();
	
	//活动 风暴实现类析构函数
	virtual					~ModuleActivityStorm();

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
	* Function:       RpcSignUp
	* Description:    活动 风暴-->报名同步调用操作函数
	* Input:          ActivityStormRpcSignUpAskWraper& Ask 报名请求
	* Output:         ActivityStormRpcSignUpReplyWraper& Reply 报名回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSignUp( INT64 UserId, ActivityStormRpcSignUpAskWraper& Ask, ActivityStormRpcSignUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcCancelSignUp
	* Description:    活动 风暴-->取消报名同步调用操作函数
	* Input:          ActivityStormRpcCancelSignUpAskWraper& Ask 取消报名请求
	* Output:         ActivityStormRpcCancelSignUpReplyWraper& Reply 取消报名回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcCancelSignUp( INT64 UserId, ActivityStormRpcCancelSignUpAskWraper& Ask, ActivityStormRpcCancelSignUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcInsertBattlefield
	* Description:    活动 风暴-->进入战场同步调用操作函数
	* Input:          ActivityStormRpcInsertBattlefieldAskWraper& Ask 进入战场请求
	* Output:         ActivityStormRpcInsertBattlefieldReplyWraper& Reply 进入战场回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcInsertBattlefield( INT64 UserId, ActivityStormRpcInsertBattlefieldAskWraper& Ask, ActivityStormRpcInsertBattlefieldReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientBattlefieldMessage
	* Description:    活动 风暴-->战场信息异步通知操作函数
	* Input:          ActivityStormRpcBattlefieldMessageNotifyWraper& Notify 战场信息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientBattlefieldMessage( INT64 UserId, ActivityStormRpcBattlefieldMessageNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientTimeOutMessage
	* Description:    活动 风暴-->超时消息主推异步通知操作函数
	* Input:          ActivityStormRpcTimeOutMessageNotifyWraper& Notify 超时消息主推通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientTimeOutMessage( INT64 UserId, ActivityStormRpcTimeOutMessageNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSyncData
	* Description:    活动 风暴-->同步数据同步调用操作函数
	* Input:          ActivityStormRpcSyncDataAskWraper& Ask 同步数据请求
	* Output:         ActivityStormRpcSyncDataReplyWraper& Reply 同步数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncData( INT64 UserId, ActivityStormRpcSyncDataAskWraper& Ask, ActivityStormRpcSyncDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientJoinLevevNotify
	* Description:    活动 风暴-->加入离开notify异步通知操作函数
	* Input:          ActivityStormRpcJoinLevevNotifyNotifyWraper& Notify 加入离开notify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientJoinLevevNotify( INT64 UserId, ActivityStormRpcJoinLevevNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCanceInsertBattle
	* Description:    活动 风暴-->取消进入战场同步调用操作函数
	* Input:          ActivityStormRpcCanceInsertBattleAskWraper& Ask 取消进入战场请求
	* Output:         ActivityStormRpcCanceInsertBattleReplyWraper& Reply 取消进入战场回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcCanceInsertBattle( INT64 UserId, ActivityStormRpcCanceInsertBattleAskWraper& Ask, ActivityStormRpcCanceInsertBattleReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientResetSignUpNotify
	* Description:    活动 风暴-->重置报名异步通知操作函数
	* Input:          ActivityStormRpcResetSignUpNotifyNotifyWraper& Notify 重置报名通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientResetSignUpNotify( INT64 UserId, ActivityStormRpcResetSignUpNotifyNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif