/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleFriend.h
* Author:       甘业清
* Description:  好友类，包含以下内容
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

#ifndef __MODULE_FRIEND_H
#define __MODULE_FRIEND_H


#include "ModuleBase.h"
#include "FriendRpcWraper.h"
#include "FriendV1Data.h"
#include "FriendV1DataWraper.h"




//好友实现类
class ModuleFriend : public ModuleBase
{
	DECLARE_INSTANCE(ModuleFriend);
public:
	friend class			ModuleMgr;

public:
	//好友实现类构造函数
	ModuleFriend();
	
	//好友实现类析构函数
	virtual					~ModuleFriend();

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
	* Function:       RpcSyncFriendData
	* Description:    好友-->每次打开界面，请求一次数据同步调用操作函数
	* Input:          FriendRpcSyncFriendDataAskWraper& Ask 每次打开界面，请求一次数据请求
	* Output:         FriendRpcSyncFriendDataReplyWraper& Reply 每次打开界面，请求一次数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncFriendData( INT64 UserId, FriendRpcSyncFriendDataAskWraper& Ask, FriendRpcSyncFriendDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcAddFriend
	* Description:    好友-->增加好友同步调用操作函数
	* Input:          FriendRpcAddFriendAskWraper& Ask 增加好友请求
	* Output:         FriendRpcAddFriendReplyWraper& Reply 增加好友回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAddFriend( INT64 UserId, FriendRpcAddFriendAskWraper& Ask, FriendRpcAddFriendReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcDelFriend
	* Description:    好友-->删除好友同步调用操作函数
	* Input:          FriendRpcDelFriendAskWraper& Ask 删除好友请求
	* Output:         FriendRpcDelFriendReplyWraper& Reply 删除好友回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcDelFriend( INT64 UserId, FriendRpcDelFriendAskWraper& Ask, FriendRpcDelFriendReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcAddBlackList
	* Description:    好友-->增加黑名单同步调用操作函数
	* Input:          FriendRpcAddBlackListAskWraper& Ask 增加黑名单请求
	* Output:         FriendRpcAddBlackListReplyWraper& Reply 增加黑名单回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAddBlackList( INT64 UserId, FriendRpcAddBlackListAskWraper& Ask, FriendRpcAddBlackListReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcDelBlackList
	* Description:    好友-->删除黑名单同步调用操作函数
	* Input:          FriendRpcDelBlackListAskWraper& Ask 删除黑名单请求
	* Output:         FriendRpcDelBlackListReplyWraper& Reply 删除黑名单回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcDelBlackList( INT64 UserId, FriendRpcDelBlackListAskWraper& Ask, FriendRpcDelBlackListReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcAddContact
	* Description:    好友-->增加最近联系人同步调用操作函数
	* Input:          FriendRpcAddContactAskWraper& Ask 增加最近联系人请求
	* Output:         FriendRpcAddContactReplyWraper& Reply 增加最近联系人回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAddContact( INT64 UserId, FriendRpcAddContactAskWraper& Ask, FriendRpcAddContactReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcDelContact
	* Description:    好友-->删除最近联系人同步调用操作函数
	* Input:          FriendRpcDelContactAskWraper& Ask 删除最近联系人请求
	* Output:         FriendRpcDelContactReplyWraper& Reply 删除最近联系人回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcDelContact( INT64 UserId, FriendRpcDelContactAskWraper& Ask, FriendRpcDelContactReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcSearchPlayer
	* Description:    好友-->搜索好友同步调用操作函数
	* Input:          FriendRpcSearchPlayerAskWraper& Ask 搜索好友请求
	* Output:         FriendRpcSearchPlayerReplyWraper& Reply 搜索好友回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSearchPlayer( INT64 UserId, FriendRpcSearchPlayerAskWraper& Ask, FriendRpcSearchPlayerReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcRecommend
	* Description:    好友-->推荐玩家同步调用操作函数
	* Input:          FriendRpcRecommendAskWraper& Ask 推荐玩家请求
	* Output:         FriendRpcRecommendReplyWraper& Reply 推荐玩家回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcRecommend( INT64 UserId, FriendRpcRecommendAskWraper& Ask, FriendRpcRecommendReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcViewUserSimpleInfo
	* Description:    好友-->查看资料简单数据同步调用操作函数
	* Input:          FriendRpcViewUserSimpleInfoAskWraper& Ask 查看资料简单数据请求
	* Output:         FriendRpcViewUserSimpleInfoReplyWraper& Reply 查看资料简单数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcViewUserSimpleInfo( INT64 UserId, FriendRpcViewUserSimpleInfoAskWraper& Ask, FriendRpcViewUserSimpleInfoReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientFriendOnlineOffline
	* Description:    好友-->好友上下线异步通知操作函数
	* Input:          FriendRpcOnlineOfflineNotifyWraper& Notify 好友上下线通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientFriendOnlineOffline( INT64 UserId, FriendRpcOnlineOfflineNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif