/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTalisman.h
* Author:       甘业清
* Description:  法宝类，包含以下内容
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

#ifndef __MODULE_TALISMAN_H
#define __MODULE_TALISMAN_H


#include "ModuleBase.h"
#include "TalismanRpcWraper.h"
#include "TalismanV1Data.h"
#include "TalismanV1DataWraper.h"




//法宝实现类
class ModuleTalisman : public ModuleBase
{
	DECLARE_INSTANCE(ModuleTalisman);
public:
	friend class			ModuleMgr;

public:
	//法宝实现类构造函数
	ModuleTalisman();
	
	//法宝实现类析构函数
	virtual					~ModuleTalisman();

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
	* Description:    法宝-->数据同步同步调用操作函数
	* Input:          TalismanRpcSyncDataAskWraper& Ask 数据同步请求
	* Output:         TalismanRpcSyncDataReplyWraper& Reply 数据同步回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncData( INT64 UserId, TalismanRpcSyncDataAskWraper& Ask, TalismanRpcSyncDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcActive
	* Description:    法宝-->激活同步调用操作函数
	* Input:          TalismanRpcActiveAskWraper& Ask 激活请求
	* Output:         TalismanRpcActiveReplyWraper& Reply 激活回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcActive( INT64 UserId, TalismanRpcActiveAskWraper& Ask, TalismanRpcActiveReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcUpgrade
	* Description:    法宝-->升级同步调用操作函数
	* Input:          TalismanRpcUpgradeAskWraper& Ask 升级请求
	* Output:         TalismanRpcUpgradeReplyWraper& Reply 升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcUpgrade( INT64 UserId, TalismanRpcUpgradeAskWraper& Ask, TalismanRpcUpgradeReplyWraper& Reply );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif