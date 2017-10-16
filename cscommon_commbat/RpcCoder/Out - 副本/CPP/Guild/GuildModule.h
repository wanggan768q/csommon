/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleGuild.h
* Author:       甘业清
* Description:  帮派类，包含以下内容
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

#ifndef __MODULE_GUILD_H
#define __MODULE_GUILD_H


#include "ModuleBase.h"
#include "GuildRpcWraper.h"
#include "GuildV1Data.h"
#include "GuildV1DataWraper.h"




//帮派实现类
class ModuleGuild : public ModuleBase
{
	DECLARE_INSTANCE(ModuleGuild);
public:
	friend class			ModuleMgr;

public:
	//帮派实现类构造函数
	ModuleGuild();
	
	//帮派实现类析构函数
	virtual					~ModuleGuild();

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
	* Description:    帮派-->登陆后，同步一次数据同步调用操作函数
	* Input:          GuildRpcSyncDataAskWraper& Ask 登陆后，同步一次数据请求
	* Output:         GuildRpcSyncDataReplyWraper& Reply 登陆后，同步一次数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcSyncData( INT64 UserId, GuildRpcSyncDataAskWraper& Ask, GuildRpcSyncDataReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcCreateGuild
	* Description:    帮派-->创建帮会同步调用操作函数
	* Input:          GuildRpcCreateGuildAskWraper& Ask 创建帮会请求
	* Output:         GuildRpcCreateGuildReplyWraper& Reply 创建帮会回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcCreateGuild( INT64 UserId, GuildRpcCreateGuildAskWraper& Ask, GuildRpcCreateGuildReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcApplyGuild
	* Description:    帮派-->申请入帮同步调用操作函数
	* Input:          GuildRpcApplyGuildAskWraper& Ask 申请入帮请求
	* Output:         GuildRpcApplyGuildReplyWraper& Reply 申请入帮回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcApplyGuild( INT64 UserId, GuildRpcApplyGuildAskWraper& Ask, GuildRpcApplyGuildReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcQuickApply
	* Description:    帮派-->快速申请同步调用操作函数
	* Input:          GuildRpcQuickApplyAskWraper& Ask 快速申请请求
	* Output:         GuildRpcQuickApplyReplyWraper& Reply 快速申请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcQuickApply( INT64 UserId, GuildRpcQuickApplyAskWraper& Ask, GuildRpcQuickApplyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcChangeGuildName
	* Description:    帮派-->修改帮会名字同步调用操作函数
	* Input:          GuildRpcChangeGuildNameAskWraper& Ask 修改帮会名字请求
	* Output:         GuildRpcChangeGuildNameReplyWraper& Reply 修改帮会名字回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcChangeGuildName( INT64 UserId, GuildRpcChangeGuildNameAskWraper& Ask, GuildRpcChangeGuildNameReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcChangeAnnouncement
	* Description:    帮派-->修改公告同步调用操作函数
	* Input:          GuildRpcChangeAnnouncementAskWraper& Ask 修改公告请求
	* Output:         GuildRpcChangeAnnouncementReplyWraper& Reply 修改公告回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcChangeAnnouncement( INT64 UserId, GuildRpcChangeAnnouncementAskWraper& Ask, GuildRpcChangeAnnouncementReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcReqGuildList
	* Description:    帮派-->请求帮会列表同步调用操作函数
	* Input:          GuildRpcReqGuildListAskWraper& Ask 请求帮会列表请求
	* Output:         GuildRpcReqGuildListReplyWraper& Reply 请求帮会列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcReqGuildList( INT64 UserId, GuildRpcReqGuildListAskWraper& Ask, GuildRpcReqGuildListReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcAppointDuty
	* Description:    帮派-->任命职位同步调用操作函数
	* Input:          GuildRpcAppointDutyAskWraper& Ask 任命职位请求
	* Output:         GuildRpcAppointDutyReplyWraper& Reply 任命职位回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcAppointDuty( INT64 UserId, GuildRpcAppointDutyAskWraper& Ask, GuildRpcAppointDutyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcKickout
	* Description:    帮派-->踢人同步调用操作函数
	* Input:          GuildRpcKickoutAskWraper& Ask 踢人请求
	* Output:         GuildRpcKickoutReplyWraper& Reply 踢人回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcKickout( INT64 UserId, GuildRpcKickoutAskWraper& Ask, GuildRpcKickoutReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcExitGuild
	* Description:    帮派-->退出帮会同步调用操作函数
	* Input:          GuildRpcExitGuildAskWraper& Ask 退出帮会请求
	* Output:         GuildRpcExitGuildReplyWraper& Reply 退出帮会回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcExitGuild( INT64 UserId, GuildRpcExitGuildAskWraper& Ask, GuildRpcExitGuildReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcBreakUp
	* Description:    帮派-->解散帮会同步调用操作函数
	* Input:          GuildRpcBreakUpAskWraper& Ask 解散帮会请求
	* Output:         GuildRpcBreakUpReplyWraper& Reply 解散帮会回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBreakUp( INT64 UserId, GuildRpcBreakUpAskWraper& Ask, GuildRpcBreakUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcInviteToJoin
	* Description:    帮派-->邀请入帮同步调用操作函数
	* Input:          GuildRpcInviteToJoinAskWraper& Ask 邀请入帮请求
	* Output:         GuildRpcInviteToJoinReplyWraper& Reply 邀请入帮回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcInviteToJoin( INT64 UserId, GuildRpcInviteToJoinAskWraper& Ask, GuildRpcInviteToJoinReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientBeInvitedNotice
	* Description:    帮派-->被邀请提示异步通知操作函数
	* Input:          GuildRpcBeInvitedNoticeNotifyWraper& Notify 被邀请提示通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientBeInvitedNotice( INT64 UserId, GuildRpcBeInvitedNoticeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcBeInvitedHandle
	* Description:    帮派-->被邀请处理同步调用操作函数
	* Input:          GuildRpcBeInvitedHandleAskWraper& Ask 被邀请处理请求
	* Output:         GuildRpcBeInvitedHandleReplyWraper& Reply 被邀请处理回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcBeInvitedHandle( INT64 UserId, GuildRpcBeInvitedHandleAskWraper& Ask, GuildRpcBeInvitedHandleReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcResignDuty
	* Description:    帮派-->辞职同步调用操作函数
	* Input:          GuildRpcResignDutyAskWraper& Ask 辞职请求
	* Output:         GuildRpcResignDutyReplyWraper& Reply 辞职回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcResignDuty( INT64 UserId, GuildRpcResignDutyAskWraper& Ask, GuildRpcResignDutyReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientSyncMyTeamData
	* Description:    帮派-->发送我的帮会数据异步通知操作函数
	* Input:          GuildRpcSyncMyTeamDataNotifyWraper& Notify 发送我的帮会数据通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncMyTeamData( INT64 UserId, GuildRpcSyncMyTeamDataNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfGuildBaseData
	* Description:    帮派-->同步帮会基础数据异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfGuildBaseDataNotifyWraper& Notify 同步帮会基础数据通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfGuildBaseData( INT64 UserId, GuildRpcSyncNoticeOfGuildBaseDataNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfGuildMemberChange
	* Description:    帮派-->同步帮会成员数据变化异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfGuildMemberChangeNotifyWraper& Notify 同步帮会成员数据变化通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfGuildMemberChange( INT64 UserId, GuildRpcSyncNoticeOfGuildMemberChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfAddMember
	* Description:    帮派-->同步帮会增加成员异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfAddMemberNotifyWraper& Notify 同步帮会增加成员通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfAddMember( INT64 UserId, GuildRpcSyncNoticeOfAddMemberNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfDelMember
	* Description:    帮派-->同步帮会删除成员异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfDelMemberNotifyWraper& Notify 同步帮会删除成员通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfDelMember( INT64 UserId, GuildRpcSyncNoticeOfDelMemberNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfAddEvent
	* Description:    帮派-->同步帮会增加事件异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfAddEventNotifyWraper& Notify 同步帮会增加事件通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfAddEvent( INT64 UserId, GuildRpcSyncNoticeOfAddEventNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfAddApplyList
	* Description:    帮派-->同步帮会增加申请列表异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfAddApplyListNotifyWraper& Notify 同步帮会增加申请列表通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfAddApplyList( INT64 UserId, GuildRpcSyncNoticeOfAddApplyListNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfDelApplyList
	* Description:    帮派-->同步帮会删除申请列表异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfDelApplyListNotifyWraper& Notify 同步帮会删除申请列表通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfDelApplyList( INT64 UserId, GuildRpcSyncNoticeOfDelApplyListNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfChangeAnnouncement
	* Description:    帮派-->同步帮会公告修改异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfChangeAnnouncementNotifyWraper& Notify 同步帮会公告修改通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfChangeAnnouncement( INT64 UserId, GuildRpcSyncNoticeOfChangeAnnouncementNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfBreakup
	* Description:    帮派-->通知解散异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfBreakupNotifyWraper& Notify 通知解散通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfBreakup( INT64 UserId, GuildRpcSyncNoticeOfBreakupNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcHallLvUp
	* Description:    帮派-->帮会大厅升级同步调用操作函数
	* Input:          GuildRpcHallLvUpAskWraper& Ask 帮会大厅升级请求
	* Output:         GuildRpcHallLvUpReplyWraper& Reply 帮会大厅升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcHallLvUp( INT64 UserId, GuildRpcHallLvUpAskWraper& Ask, GuildRpcHallLvUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcHouseLvUp
	* Description:    帮派-->帮会房屋升级同步调用操作函数
	* Input:          GuildRpcHouseLvUpAskWraper& Ask 帮会房屋升级请求
	* Output:         GuildRpcHouseLvUpReplyWraper& Reply 帮会房屋升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcHouseLvUp( INT64 UserId, GuildRpcHouseLvUpAskWraper& Ask, GuildRpcHouseLvUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcStoreroomLvUp
	* Description:    帮派-->帮会库房升级同步调用操作函数
	* Input:          GuildRpcStoreroomLvUpAskWraper& Ask 帮会库房升级请求
	* Output:         GuildRpcStoreroomLvUpReplyWraper& Reply 帮会库房升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcStoreroomLvUp( INT64 UserId, GuildRpcStoreroomLvUpAskWraper& Ask, GuildRpcStoreroomLvUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcKongfuHallLvUp
	* Description:    帮派-->帮会练武堂升级同步调用操作函数
	* Input:          GuildRpcKongfuHallLvUpAskWraper& Ask 帮会练武堂升级请求
	* Output:         GuildRpcKongfuHallLvUpReplyWraper& Reply 帮会练武堂升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcKongfuHallLvUp( INT64 UserId, GuildRpcKongfuHallLvUpAskWraper& Ask, GuildRpcKongfuHallLvUpReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfHallLvUp
	* Description:    帮派-->同步帮会大厅升级异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfHallLvUpNotifyWraper& Notify 同步帮会大厅升级通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfHallLvUp( INT64 UserId, GuildRpcSyncNoticeOfHallLvUpNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfHouseLvUp
	* Description:    帮派-->同步帮会房屋升级异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfHouseLvUpNotifyWraper& Notify 同步帮会房屋升级通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfHouseLvUp( INT64 UserId, GuildRpcSyncNoticeOfHouseLvUpNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfStorerommLvUp
	* Description:    帮派-->同步帮会库房升级异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfStorerommLvUpNotifyWraper& Notify 同步帮会库房升级通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfStorerommLvUp( INT64 UserId, GuildRpcSyncNoticeOfStorerommLvUpNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfKongfuHallLvUp
	* Description:    帮派-->同步练武堂升级异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfKongfuHallLvUpNotifyWraper& Notify 同步练武堂升级通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfKongfuHallLvUp( INT64 UserId, GuildRpcSyncNoticeOfKongfuHallLvUpNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcApplyGuildHandle
	* Description:    帮派-->申请入帮，帮主处理同步调用操作函数
	* Input:          GuildRpcApplyGuildHandleAskWraper& Ask 申请入帮，帮主处理请求
	* Output:         GuildRpcApplyGuildHandleReplyWraper& Reply 申请入帮，帮主处理回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcApplyGuildHandle( INT64 UserId, GuildRpcApplyGuildHandleAskWraper& Ask, GuildRpcApplyGuildHandleReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcCreateGuildDungeon
	* Description:    帮派-->创建帮会副本同步调用操作函数
	* Input:          GuildRpcCreateGuildDungeonAskWraper& Ask 创建帮会副本请求
	* Output:         GuildRpcCreateGuildDungeonReplyWraper& Reply 创建帮会副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcCreateGuildDungeon( INT64 UserId, GuildRpcCreateGuildDungeonAskWraper& Ask, GuildRpcCreateGuildDungeonReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcEnterGuildDungeon
	* Description:    帮派-->进入帮会副本同步调用操作函数
	* Input:          GuildRpcEnterGuildDungeonAskWraper& Ask 进入帮会副本请求
	* Output:         GuildRpcEnterGuildDungeonReplyWraper& Reply 进入帮会副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEnterGuildDungeon( INT64 UserId, GuildRpcEnterGuildDungeonAskWraper& Ask, GuildRpcEnterGuildDungeonReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientRpcSyncNoticeOfCreateGuildDungeon
	* Description:    帮派-->同步帮会副本创建异步通知操作函数
	* Input:          GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotifyWraper& Notify 同步帮会副本创建通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientRpcSyncNoticeOfCreateGuildDungeon( INT64 UserId, GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCreateGuildWar
	* Description:    帮派-->创建帮会战同步调用操作函数
	* Input:          GuildRpcCreateGuildWarAskWraper& Ask 创建帮会战请求
	* Output:         GuildRpcCreateGuildWarReplyWraper& Reply 创建帮会战回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcCreateGuildWar( INT64 UserId, GuildRpcCreateGuildWarAskWraper& Ask, GuildRpcCreateGuildWarReplyWraper& Reply );

	/********************************************************************************************
	* Function:       SendToClientSyncNoticeOfOpenGuildWar
	* Description:    帮派-->同步帮会战是否开启异步通知操作函数
	* Input:          GuildRpcSyncNoticeOfOpenGuildWarNotifyWraper& Notify 同步帮会战是否开启通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	virtual void SendToClientSyncNoticeOfOpenGuildWar( INT64 UserId, GuildRpcSyncNoticeOfOpenGuildWarNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcEnterGuildWar
	* Description:    帮派-->进入帮会战同步调用操作函数
	* Input:          GuildRpcEnterGuildWarAskWraper& Ask 进入帮会战请求
	* Output:         GuildRpcEnterGuildWarReplyWraper& Reply 进入帮会战回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcEnterGuildWar( INT64 UserId, GuildRpcEnterGuildWarAskWraper& Ask, GuildRpcEnterGuildWarReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcOpenScienceAttr
	* Description:    帮派-->开启帮会修炼项目同步调用操作函数
	* Input:          GuildRpcOpenScienceAttrAskWraper& Ask 开启帮会修炼项目请求
	* Output:         GuildRpcOpenScienceAttrReplyWraper& Reply 开启帮会修炼项目回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcOpenScienceAttr( INT64 UserId, GuildRpcOpenScienceAttrAskWraper& Ask, GuildRpcOpenScienceAttrReplyWraper& Reply );

	/********************************************************************************************
	* Function:       RpcGuildScienceLvUp
	* Description:    帮派-->帮会属性升级同步调用操作函数
	* Input:          GuildRpcGuildScienceLvUpAskWraper& Ask 帮会属性升级请求
	* Output:         GuildRpcGuildScienceLvUpReplyWraper& Reply 帮会属性升级回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	virtual int RpcGuildScienceLvUp( INT64 UserId, GuildRpcGuildScienceLvUpAskWraper& Ask, GuildRpcGuildScienceLvUpReplyWraper& Reply );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif