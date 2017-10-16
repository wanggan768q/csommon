/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleOneVSOne.h
* Author:       甘业清
* Description:  一v一类，包含以下内容
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

#ifndef __MODULE_ONEVSONE_H
#define __MODULE_ONEVSONE_H


#include "ModuleBase.h"
#include "OneVSOneRpcWraper.h"
#include "OneVSOneV1Data.h"
#include "OneVSOneV1DataWraper.h"




//一v一实现类
class ModuleOneVSOne : public ModuleBase
{
	DECLARE_INSTANCE(ModuleOneVSOne);
public:
	friend class			ModuleMgr;

public:
	//一v一实现类构造函数
	ModuleOneVSOne();
	
	//一v一实现类析构函数
	virtual					~ModuleOneVSOne();

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
	* Function:       RpcFlush
	* Description:    一v一-->刷新自己的数据同步调用操作函数
	* Input:          OneVSOneRpcFlushAskWraper& Ask 刷新自己的数据请求
	* Output:         OneVSOneRpcFlushReplyWraper& Reply 刷新自己的数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcFlush( INT64 UserId, OneVSOneRpcFlushAskWraper& Ask, OneVSOneRpcFlushReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcAct
	* Description:    一v一-->发起挑战同步调用操作函数
	* Input:          OneVSOneRpcActAskWraper& Ask 发起挑战请求
	* Output:         OneVSOneRpcActReplyWraper& Reply 发起挑战回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAct( INT64 UserId, OneVSOneRpcActAskWraper& Ask, OneVSOneRpcActReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientActMessage
	* Description:    一v一-->挑战消息异步通知操作函数
	* Input:          OneVSOneRpcActMessageNotifyWraper& Notify 挑战消息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientActMessage( INT64 UserId, OneVSOneRpcActMessageNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcReplyAct
	* Description:    一v一-->回应谁的挑战同步调用操作函数
	* Input:          OneVSOneRpcReplyActAskWraper& Ask 回应谁的挑战请求
	* Output:         OneVSOneRpcReplyActReplyWraper& Reply 回应谁的挑战回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcReplyAct( INT64 UserId, OneVSOneRpcReplyActAskWraper& Ask, OneVSOneRpcReplyActReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcGetTop
	* Description:    一v一-->排行榜数据同步调用操作函数
	* Input:          OneVSOneRpcGetTopAskWraper& Ask 排行榜数据请求
	* Output:         OneVSOneRpcGetTopReplyWraper& Reply 排行榜数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcGetTop( INT64 UserId, OneVSOneRpcGetTopAskWraper& Ask, OneVSOneRpcGetTopReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcAdjustmentSkill
	* Description:    一v一-->调整技能同步调用操作函数
	* Input:          OneVSOneRpcAdjustmentSkillAskWraper& Ask 调整技能请求
	* Output:         OneVSOneRpcAdjustmentSkillReplyWraper& Reply 调整技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAdjustmentSkill( INT64 UserId, OneVSOneRpcAdjustmentSkillAskWraper& Ask, OneVSOneRpcAdjustmentSkillReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcGetSkill
	* Description:    一v一-->获取设置的技能同步调用操作函数
	* Input:          OneVSOneRpcGetSkillAskWraper& Ask 获取设置的技能请求
	* Output:         OneVSOneRpcGetSkillReplyWraper& Reply 获取设置的技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcGetSkill( INT64 UserId, OneVSOneRpcGetSkillAskWraper& Ask, OneVSOneRpcGetSkillReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcGetActMessage
	* Description:    一v一-->获得攻守的信息同步调用操作函数
	* Input:          OneVSOneRpcGetActMessageAskWraper& Ask 获得攻守的信息请求
	* Output:         OneVSOneRpcGetActMessageReplyWraper& Reply 获得攻守的信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcGetActMessage( INT64 UserId, OneVSOneRpcGetActMessageAskWraper& Ask, OneVSOneRpcGetActMessageReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientACTResultNotify
	* Description:    一v一-->战斗结果Notify 叶青给我我就给客户端异步通知操作函数
	* Input:          OneVSOneRpcACTResultNotifyNotifyWraper& Notify 战斗结果Notify 叶青给我我就给客户端通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientACTResultNotify( INT64 UserId, OneVSOneRpcACTResultNotifyNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif