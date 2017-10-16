/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTransport.h
* Author:       甘业清
* Description:  货运类，包含以下内容
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

#ifndef __MODULE_TRANSPORT_H
#define __MODULE_TRANSPORT_H


#include "ModuleBase.h"
#include "TransportRpcWraper.h"
#include "TransportV1Data.h"
#include "TransportV1DataWraper.h"




//货运实现类
class ModuleTransport : public ModuleBase
{
	DECLARE_INSTANCE(ModuleTransport);
public:
	friend class			ModuleMgr;

public:
	//货运实现类构造函数
	ModuleTransport();
	
	//货运实现类析构函数
	virtual					~ModuleTransport();

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
	* Description:    货运-->数据同步同步调用操作函数
	* Input:          TransportRpcSyncDataAskWraper& Ask 数据同步请求
	* Output:         TransportRpcSyncDataReplyWraper& Reply 数据同步回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncData( INT64 UserId, TransportRpcSyncDataAskWraper& Ask, TransportRpcSyncDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcFill
	* Description:    货运-->填充同步调用操作函数
	* Input:          TransportRpcFillAskWraper& Ask 填充请求
	* Output:         TransportRpcFillReplyWraper& Reply 填充回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcFill( INT64 UserId, TransportRpcFillAskWraper& Ask, TransportRpcFillReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcHelpOther
	* Description:    货运-->帮助请求同步调用操作函数
	* Input:          TransportRpcHelpOtherAskWraper& Ask 帮助请求请求
	* Output:         TransportRpcHelpOtherReplyWraper& Reply 帮助请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcHelpOther( INT64 UserId, TransportRpcHelpOtherAskWraper& Ask, TransportRpcHelpOtherReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcAskHelp
	* Description:    货运-->请求帮助同步调用操作函数
	* Input:          TransportRpcAskHelpAskWraper& Ask 请求帮助请求
	* Output:         TransportRpcAskHelpReplyWraper& Reply 请求帮助回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAskHelp( INT64 UserId, TransportRpcAskHelpAskWraper& Ask, TransportRpcAskHelpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcSetSail
	* Description:    货运-->起航请求同步调用操作函数
	* Input:          TransportRpcSetSailAskWraper& Ask 起航请求请求
	* Output:         TransportRpcSetSailReplyWraper& Reply 起航请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSetSail( INT64 UserId, TransportRpcSetSailAskWraper& Ask, TransportRpcSetSailReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcAddTransport
	* Description:    货运-->添加货物同步调用操作函数
	* Input:          TransportRpcAddTransportAskWraper& Ask 添加货物请求
	* Output:         TransportRpcAddTransportReplyWraper& Reply 添加货物回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAddTransport( INT64 UserId, TransportRpcAddTransportAskWraper& Ask, TransportRpcAddTransportReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientIsHelped
	* Description:    货运-->自己被帮助通知异步通知操作函数
	* Input:          TransportRpcIsHelpedNotifyWraper& Notify 自己被帮助通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientIsHelped( INT64 UserId, TransportRpcIsHelpedNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif