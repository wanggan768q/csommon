/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBaseAttr.h
* Author:       甘业清
* Description:  战队基础数据类，包含以下内容
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

#ifndef __MODULE_BASEATTR_H
#define __MODULE_BASEATTR_H


#include "ModuleBase.h"
#include "BaseAttrRpcWraper.h"
#include "BaseAttrV1Data.h"
#include "BaseAttrV1DataWraper.h"




//战队基础数据实现类
class ModuleBaseAttr : public ModuleBase
{
	DECLARE_INSTANCE(ModuleBaseAttr);
public:
	friend class			ModuleMgr;

public:
	//战队基础数据实现类构造函数
	ModuleBaseAttr();
	
	//战队基础数据实现类析构函数
	virtual					~ModuleBaseAttr();

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
	* Description:    战队基础数据-->同步玩家数据同步调用操作函数
	* Input:          BaseAttrRpcSyncDataAskWraper& Ask 同步玩家数据请求
	* Output:         BaseAttrRpcSyncDataReplyWraper& Reply 同步玩家数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncData( INT64 UserId, BaseAttrRpcSyncDataAskWraper& Ask, BaseAttrRpcSyncDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcGetRankReward
	* Description:    战队基础数据-->领取官阶奖励同步调用操作函数
	* Input:          BaseAttrRpcGetRankRewardAskWraper& Ask 领取官阶奖励请求
	* Output:         BaseAttrRpcGetRankRewardReplyWraper& Reply 领取官阶奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcGetRankReward( INT64 UserId, BaseAttrRpcGetRankRewardAskWraper& Ask, BaseAttrRpcGetRankRewardReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcUpGradeRank
	* Description:    战队基础数据-->提升官阶同步调用操作函数
	* Input:          BaseAttrRpcUpGradeRankAskWraper& Ask 提升官阶请求
	* Output:         BaseAttrRpcUpGradeRankReplyWraper& Reply 提升官阶回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcUpGradeRank( INT64 UserId, BaseAttrRpcUpGradeRankAskWraper& Ask, BaseAttrRpcUpGradeRankReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcChooseRole
	* Description:    战队基础数据-->选人同步调用操作函数
	* Input:          BaseAttrRpcChooseRoleAskWraper& Ask 选人请求
	* Output:         BaseAttrRpcChooseRoleReplyWraper& Reply 选人回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcChooseRole( INT64 UserId, BaseAttrRpcChooseRoleAskWraper& Ask, BaseAttrRpcChooseRoleReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcLevelUp
	* Description:    战队基础数据-->升级同步调用操作函数
	* Input:          BaseAttrRpcLevelUpAskWraper& Ask 升级请求
	* Output:         BaseAttrRpcLevelUpReplyWraper& Reply 升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcLevelUp( INT64 UserId, BaseAttrRpcLevelUpAskWraper& Ask, BaseAttrRpcLevelUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcGetTimer
	* Description:    战队基础数据-->获取时间同步调用操作函数
	* Input:          BaseAttrRpcGetTimerAskWraper& Ask 获取时间请求
	* Output:         BaseAttrRpcGetTimerReplyWraper& Reply 获取时间回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcGetTimer( INT64 UserId, BaseAttrRpcGetTimerAskWraper& Ask, BaseAttrRpcGetTimerReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcRevive
	* Description:    战队基础数据-->复活同步调用操作函数
	* Input:          BaseAttrRpcReviveAskWraper& Ask 复活请求
	* Output:         BaseAttrRpcReviveReplyWraper& Reply 复活回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcRevive( INT64 UserId, BaseAttrRpcReviveAskWraper& Ask, BaseAttrRpcReviveReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcQueryEquip
	* Description:    战队基础数据-->查询装备数据同步调用操作函数
	* Input:          BaseAttrRpcQueryEquipAskWraper& Ask 查询装备数据请求
	* Output:         BaseAttrRpcQueryEquipReplyWraper& Reply 查询装备数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcQueryEquip( INT64 UserId, BaseAttrRpcQueryEquipAskWraper& Ask, BaseAttrRpcQueryEquipReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcUpdateNewbieGuide
	* Description:    战队基础数据-->更新新手引导同步调用操作函数
	* Input:          BaseAttrRpcUpdateNewbieGuideAskWraper& Ask 更新新手引导请求
	* Output:         BaseAttrRpcUpdateNewbieGuideReplyWraper& Reply 更新新手引导回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcUpdateNewbieGuide( INT64 UserId, BaseAttrRpcUpdateNewbieGuideAskWraper& Ask, BaseAttrRpcUpdateNewbieGuideReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientSysTips
	* Description:    战队基础数据-->系统提示异步通知操作函数
	* Input:          BaseAttrRpcSysTipsNotifyWraper& Notify 系统提示通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSysTips( INT64 UserId, BaseAttrRpcSysTipsNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangPKState
	* Description:    战队基础数据-->修改PK状态同步调用操作函数
	* Input:          BaseAttrRpcChangPKStateAskWraper& Ask 修改PK状态请求
	* Output:         BaseAttrRpcChangPKStateReplyWraper& Reply 修改PK状态回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcChangPKState( INT64 UserId, BaseAttrRpcChangPKStateAskWraper& Ask, BaseAttrRpcChangPKStateReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcChangePKProtect
	* Description:    战队基础数据-->修改PK保护同步调用操作函数
	* Input:          BaseAttrRpcChangePKProtectAskWraper& Ask 修改PK保护请求
	* Output:         BaseAttrRpcChangePKProtectReplyWraper& Reply 修改PK保护回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcChangePKProtect( INT64 UserId, BaseAttrRpcChangePKProtectAskWraper& Ask, BaseAttrRpcChangePKProtectReplyWraper& Reply );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif