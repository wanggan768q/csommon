/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMail.h
* Author:       甘业清
* Description:  邮件类，包含以下内容
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

#ifndef __MODULE_MAIL_H
#define __MODULE_MAIL_H


#include "ModuleBase.h"
#include "MailRpcWraper.h"




//邮件实现类
class ModuleMail : public ModuleBase
{
	DECLARE_INSTANCE(ModuleMail);
public:
	friend class			ModuleMgr;

public:
	//邮件实现类构造函数
	ModuleMail();
	
	//邮件实现类析构函数
	virtual					~ModuleMail();

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
	* Function:       RpcMailHead
	* Description:    邮件-->获得邮件头同步调用操作函数
	* Input:          MailRpcMailHeadAskWraper& Ask 获得邮件头请求
	* Output:         MailRpcMailHeadReplyWraper& Reply 获得邮件头回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcMailHead( INT64 UserId, MailRpcMailHeadAskWraper& Ask, MailRpcMailHeadReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcOpenMail
	* Description:    邮件-->获得邮件内容同步调用操作函数
	* Input:          MailRpcOpenMailAskWraper& Ask 获得邮件内容请求
	* Output:         MailRpcOpenMailReplyWraper& Reply 获得邮件内容回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcOpenMail( INT64 UserId, MailRpcOpenMailAskWraper& Ask, MailRpcOpenMailReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientNewMail
	* Description:    邮件-->获得新邮件异步通知操作函数
	* Input:          MailRpcNewMailNotifyWraper& Notify 获得新邮件通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientNewMail( INT64 UserId, MailRpcNewMailNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcDelMail
	* Description:    邮件-->删除邮件同步调用操作函数
	* Input:          MailRpcDelMailAskWraper& Ask 删除邮件请求
	* Output:         MailRpcDelMailReplyWraper& Reply 删除邮件回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcDelMail( INT64 UserId, MailRpcDelMailAskWraper& Ask, MailRpcDelMailReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcGetReward
	* Description:    邮件-->领取奖励同步调用操作函数
	* Input:          MailRpcGetRewardAskWraper& Ask 领取奖励请求
	* Output:         MailRpcGetRewardReplyWraper& Reply 领取奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcGetReward( INT64 UserId, MailRpcGetRewardAskWraper& Ask, MailRpcGetRewardReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcOneKeyGetReward
	* Description:    邮件-->一键领取同步调用操作函数
	* Input:          MailRpcOneKeyGetRewardAskWraper& Ask 一键领取请求
	* Output:         MailRpcOneKeyGetRewardReplyWraper& Reply 一键领取回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcOneKeyGetReward( INT64 UserId, MailRpcOneKeyGetRewardAskWraper& Ask, MailRpcOneKeyGetRewardReplyWraper& Reply );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif