/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTeam.h
* Author:       甘业清
* Description:  组队类，包含以下内容
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

#ifndef __MODULE_TEAM_H
#define __MODULE_TEAM_H


#include "ModuleBase.h"
#include "TeamRpcWraper.h"
#include "TeamV1Data.h"
#include "TeamV1DataWraper.h"




//组队实现类
class ModuleTeam : public ModuleBase
{
	DECLARE_INSTANCE(ModuleTeam);
public:
	friend class			ModuleMgr;

public:
	//组队实现类构造函数
	ModuleTeam();
	
	//组队实现类析构函数
	virtual					~ModuleTeam();

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
	* Function:       RpcCreateTeam
	* Description:    组队-->创建队伍同步调用操作函数
	* Input:          TeamRpcCreateTeamAskWraper& Ask 创建队伍请求
	* Output:         TeamRpcCreateTeamReplyWraper& Reply 创建队伍回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcCreateTeam( INT64 UserId, TeamRpcCreateTeamAskWraper& Ask, TeamRpcCreateTeamReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcApplyForTeam
	* Description:    组队-->申请入队同步调用操作函数
	* Input:          TeamRpcApplyForTeamAskWraper& Ask 申请入队请求
	* Output:         TeamRpcApplyForTeamReplyWraper& Reply 申请入队回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcApplyForTeam( INT64 UserId, TeamRpcApplyForTeamAskWraper& Ask, TeamRpcApplyForTeamReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcQuitTeam
	* Description:    组队-->离开队伍异步通知操作函数
	* Input:          TeamRpcQuitTeamNotifyWraper& Notify 离开队伍通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	virtual int RpcQuitTeam( INT64 UserId, TeamRpcQuitTeamNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcBreakUp
	* Description:    组队-->解散队伍同步调用操作函数
	* Input:          TeamRpcBreakUpAskWraper& Ask 解散队伍请求
	* Output:         TeamRpcBreakUpReplyWraper& Reply 解散队伍回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBreakUp( INT64 UserId, TeamRpcBreakUpAskWraper& Ask, TeamRpcBreakUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcInviteToTeam
	* Description:    组队-->邀请入队同步调用操作函数
	* Input:          TeamRpcInviteToTeamAskWraper& Ask 邀请入队请求
	* Output:         TeamRpcInviteToTeamReplyWraper& Reply 邀请入队回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcInviteToTeam( INT64 UserId, TeamRpcInviteToTeamAskWraper& Ask, TeamRpcInviteToTeamReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcChangeTeamTarget
	* Description:    组队-->更改队伍目标同步调用操作函数
	* Input:          TeamRpcChangeTeamTargetAskWraper& Ask 更改队伍目标请求
	* Output:         TeamRpcChangeTeamTargetReplyWraper& Reply 更改队伍目标回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcChangeTeamTarget( INT64 UserId, TeamRpcChangeTeamTargetAskWraper& Ask, TeamRpcChangeTeamTargetReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientBeInvitedNotice
	* Description:    组队-->被邀请入队通知异步通知操作函数
	* Input:          TeamRpcBeInvitedNoticeNotifyWraper& Notify 被邀请入队通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientBeInvitedNotice( INT64 UserId, TeamRpcBeInvitedNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcBeInviteHandle
	* Description:    组队-->被邀请处理同步调用操作函数
	* Input:          TeamRpcBeInviteHandleAskWraper& Ask 被邀请处理请求
	* Output:         TeamRpcBeInviteHandleReplyWraper& Reply 被邀请处理回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBeInviteHandle( INT64 UserId, TeamRpcBeInviteHandleAskWraper& Ask, TeamRpcBeInviteHandleReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcNearbyTeam
	* Description:    组队-->附近队伍同步调用操作函数
	* Input:          TeamRpcNearbyTeamAskWraper& Ask 附近队伍请求
	* Output:         TeamRpcNearbyTeamReplyWraper& Reply 附近队伍回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcNearbyTeam( INT64 UserId, TeamRpcNearbyTeamAskWraper& Ask, TeamRpcNearbyTeamReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientApplyNoticeCaptain
	* Description:    组队-->申请入队通知,所有人都可以看,但只有队长才能同意异步通知操作函数
	* Input:          TeamRpcApplyNoticeCaptainNotifyWraper& Notify 有人申请入队,队长收到通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientApplyNoticeCaptain( INT64 UserId, TeamRpcApplyNoticeCaptainNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcApplyHandleAgree
	* Description:    组队-->申请入队,队长同意入队同步调用操作函数
	* Input:          TeamRpcApplyHandleAgreeAskWraper& Ask 申请入队,队长同意入队请求
	* Output:         TeamRpcApplyHandleAgreeReplyWraper& Reply 申请入队,队长同意入队回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcApplyHandleAgree( INT64 UserId, TeamRpcApplyHandleAgreeAskWraper& Ask, TeamRpcApplyHandleAgreeReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientUpdateMyTeamNotice
	* Description:    组队-->更新我的队伍通知异步通知操作函数
	* Input:          TeamRpcUpdateMyTeamNoticeNotifyWraper& Notify 更新我的队伍通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientUpdateMyTeamNotice( INT64 UserId, TeamRpcUpdateMyTeamNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientLeaveTeamNotice
	* Description:    组队-->离开队伍通知异步通知操作函数
	* Input:          TeamRpcLeaveTeamNoticeNotifyWraper& Notify 离开队伍通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientLeaveTeamNotice( INT64 UserId, TeamRpcLeaveTeamNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientBreakUpNotice
	* Description:    组队-->解散队伍通知异步通知操作函数
	* Input:          TeamRpcBreakUpNoticeNotifyWraper& Notify 解散队伍通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientBreakUpNotice( INT64 UserId, TeamRpcBreakUpNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcReqMyTeamData
	* Description:    组队-->请求我的队伍数据异步通知操作函数
	* Input:          TeamRpcReqMyTeamDataNotifyWraper& Notify 请求我的队伍数据通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	virtual int RpcReqMyTeamData( INT64 UserId, TeamRpcReqMyTeamDataNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDeleteFromApplyList
	* Description:    组队-->申请列表处理后删除申请的玩家异步通知操作函数
	* Input:          TeamRpcDeleteFromApplyListNotifyWraper& Notify 申请列表处理后删除申请的玩家通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientDeleteFromApplyList( INT64 UserId, TeamRpcDeleteFromApplyListNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAppointCaptain
	* Description:    组队-->任命队长同步调用操作函数
	* Input:          TeamRpcAppointCaptainAskWraper& Ask 任命队长请求
	* Output:         TeamRpcAppointCaptainReplyWraper& Reply 任命队长回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAppointCaptain( INT64 UserId, TeamRpcAppointCaptainAskWraper& Ask, TeamRpcAppointCaptainReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientCaptainChangeNotice
	* Description:    组队-->队长换人通知异步通知操作函数
	* Input:          TeamRpcCaptainChangeNoticeNotifyWraper& Notify 队长换人通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientCaptainChangeNotice( INT64 UserId, TeamRpcCaptainChangeNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientTeamMemberHPChangeNotice
	* Description:    组队-->队员血量变化通知异步通知操作函数
	* Input:          TeamRpcTeamMemberHPChangeNoticeNotifyWraper& Notify 队员血量变化通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientTeamMemberHPChangeNotice( INT64 UserId, TeamRpcTeamMemberHPChangeNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientInviteHandleNotice
	* Description:    组队-->邀请组队的人收到被邀请人的处理通知异步通知操作函数
	* Input:          TeamRpcInviteHandleNoticeNotifyWraper& Notify 邀请组队的人收到被邀请人的处理通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientInviteHandleNotice( INT64 UserId, TeamRpcInviteHandleNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcNearbyRoleList
	* Description:    组队-->附加玩家列表，邀请时使用同步调用操作函数
	* Input:          TeamRpcNearbyRoleListAskWraper& Ask 附加玩家列表，邀请时使用请求
	* Output:         TeamRpcNearbyRoleListReplyWraper& Reply 附加玩家列表，邀请时使用回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcNearbyRoleList( INT64 UserId, TeamRpcNearbyRoleListAskWraper& Ask, TeamRpcNearbyRoleListReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcKickRole
	* Description:    组队-->队长踢人同步调用操作函数
	* Input:          TeamRpcKickRoleAskWraper& Ask 队长踢人请求
	* Output:         TeamRpcKickRoleReplyWraper& Reply 队长踢人回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcKickRole( INT64 UserId, TeamRpcKickRoleAskWraper& Ask, TeamRpcKickRoleReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientBeingKickedNotice
	* Description:    组队-->被踢通知异步通知操作函数
	* Input:          TeamRpcBeingKickedNoticeNotifyWraper& Notify 被踢通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientBeingKickedNotice( INT64 UserId, TeamRpcBeingKickedNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientAddNewMemberNotice
	* Description:    组队-->队员增加新成员通知异步通知操作函数
	* Input:          TeamRpcAddNewMemberNoticeNotifyWraper& Notify 队员增加新成员通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientAddNewMemberNotice( INT64 UserId, TeamRpcAddNewMemberNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCaptainAutoMatch
	* Description:    组队-->队长自己匹配同步调用操作函数
	* Input:          TeamRpcCaptainAutoMatchAskWraper& Ask 队长自己匹配请求
	* Output:         TeamRpcCaptainAutoMatchReplyWraper& Reply 队长自己匹配回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcCaptainAutoMatch( INT64 UserId, TeamRpcCaptainAutoMatchAskWraper& Ask, TeamRpcCaptainAutoMatchReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcNormalAutoMatch
	* Description:    组队-->非队长匹配同步调用操作函数
	* Input:          TeamRpcNormalAutoMatchAskWraper& Ask 非队长匹配请求
	* Output:         TeamRpcNormalAutoMatchReplyWraper& Reply 非队长匹配回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcNormalAutoMatch( INT64 UserId, TeamRpcNormalAutoMatchAskWraper& Ask, TeamRpcNormalAutoMatchReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcFollow
	* Description:    组队-->跟随同步调用操作函数
	* Input:          TeamRpcFollowAskWraper& Ask 跟随请求
	* Output:         TeamRpcFollowReplyWraper& Reply 跟随回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcFollow( INT64 UserId, TeamRpcFollowAskWraper& Ask, TeamRpcFollowReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcClearApplyList
	* Description:    组队-->清空申请列表同步调用操作函数
	* Input:          TeamRpcClearApplyListAskWraper& Ask 清空申请列表请求
	* Output:         TeamRpcClearApplyListReplyWraper& Reply 清空申请列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcClearApplyList( INT64 UserId, TeamRpcClearApplyListAskWraper& Ask, TeamRpcClearApplyListReplyWraper& Reply );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif