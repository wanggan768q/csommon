/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcGuildImp.cpp
* Author:       甘业清
* Description:  帮派类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "GuildModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    帮派-->登陆后，同步一次数据同步调用操作函数
* Input:          GuildRpcSyncDataAskWraper& Ask 登陆后，同步一次数据请求
* Output:         GuildRpcSyncDataReplyWraper& Reply 登陆后，同步一次数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcSyncData( INT64 UserId, GuildRpcSyncDataAskWraper& Ask, GuildRpcSyncDataReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCreateGuild
* Description:    帮派-->创建帮会同步调用操作函数
* Input:          GuildRpcCreateGuildAskWraper& Ask 创建帮会请求
* Output:         GuildRpcCreateGuildReplyWraper& Reply 创建帮会回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcCreateGuild( INT64 UserId, GuildRpcCreateGuildAskWraper& Ask, GuildRpcCreateGuildReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcApplyGuild
* Description:    帮派-->申请入帮同步调用操作函数
* Input:          GuildRpcApplyGuildAskWraper& Ask 申请入帮请求
* Output:         GuildRpcApplyGuildReplyWraper& Reply 申请入帮回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcApplyGuild( INT64 UserId, GuildRpcApplyGuildAskWraper& Ask, GuildRpcApplyGuildReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcQuickApply
* Description:    帮派-->快速申请同步调用操作函数
* Input:          GuildRpcQuickApplyAskWraper& Ask 快速申请请求
* Output:         GuildRpcQuickApplyReplyWraper& Reply 快速申请回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcQuickApply( INT64 UserId, GuildRpcQuickApplyAskWraper& Ask, GuildRpcQuickApplyReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChangeGuildName
* Description:    帮派-->修改帮会名字同步调用操作函数
* Input:          GuildRpcChangeGuildNameAskWraper& Ask 修改帮会名字请求
* Output:         GuildRpcChangeGuildNameReplyWraper& Reply 修改帮会名字回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcChangeGuildName( INT64 UserId, GuildRpcChangeGuildNameAskWraper& Ask, GuildRpcChangeGuildNameReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChangeAnnouncement
* Description:    帮派-->修改公告同步调用操作函数
* Input:          GuildRpcChangeAnnouncementAskWraper& Ask 修改公告请求
* Output:         GuildRpcChangeAnnouncementReplyWraper& Reply 修改公告回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcChangeAnnouncement( INT64 UserId, GuildRpcChangeAnnouncementAskWraper& Ask, GuildRpcChangeAnnouncementReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcReqGuildList
* Description:    帮派-->请求帮会列表同步调用操作函数
* Input:          GuildRpcReqGuildListAskWraper& Ask 请求帮会列表请求
* Output:         GuildRpcReqGuildListReplyWraper& Reply 请求帮会列表回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcReqGuildList( INT64 UserId, GuildRpcReqGuildListAskWraper& Ask, GuildRpcReqGuildListReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAppointDuty
* Description:    帮派-->任命职位同步调用操作函数
* Input:          GuildRpcAppointDutyAskWraper& Ask 任命职位请求
* Output:         GuildRpcAppointDutyReplyWraper& Reply 任命职位回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcAppointDuty( INT64 UserId, GuildRpcAppointDutyAskWraper& Ask, GuildRpcAppointDutyReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcKickout
* Description:    帮派-->踢人同步调用操作函数
* Input:          GuildRpcKickoutAskWraper& Ask 踢人请求
* Output:         GuildRpcKickoutReplyWraper& Reply 踢人回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcKickout( INT64 UserId, GuildRpcKickoutAskWraper& Ask, GuildRpcKickoutReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcExitGuild
* Description:    帮派-->退出帮会同步调用操作函数
* Input:          GuildRpcExitGuildAskWraper& Ask 退出帮会请求
* Output:         GuildRpcExitGuildReplyWraper& Reply 退出帮会回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcExitGuild( INT64 UserId, GuildRpcExitGuildAskWraper& Ask, GuildRpcExitGuildReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcBreakUp
* Description:    帮派-->解散帮会同步调用操作函数
* Input:          GuildRpcBreakUpAskWraper& Ask 解散帮会请求
* Output:         GuildRpcBreakUpReplyWraper& Reply 解散帮会回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcBreakUp( INT64 UserId, GuildRpcBreakUpAskWraper& Ask, GuildRpcBreakUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInviteToJoin
* Description:    帮派-->邀请入帮同步调用操作函数
* Input:          GuildRpcInviteToJoinAskWraper& Ask 邀请入帮请求
* Output:         GuildRpcInviteToJoinReplyWraper& Reply 邀请入帮回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcInviteToJoin( INT64 UserId, GuildRpcInviteToJoinAskWraper& Ask, GuildRpcInviteToJoinReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientBeInvitedNotice
* Description:    帮派-->被邀请提示异步通知操作函数
* Input:          GuildRpcBeInvitedNoticeNotifyWraper& Notify 被邀请提示通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientBeInvitedNotice( INT64 UserId, GuildRpcBeInvitedNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcBeInvitedHandle
* Description:    帮派-->被邀请处理同步调用操作函数
* Input:          GuildRpcBeInvitedHandleAskWraper& Ask 被邀请处理请求
* Output:         GuildRpcBeInvitedHandleReplyWraper& Reply 被邀请处理回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcBeInvitedHandle( INT64 UserId, GuildRpcBeInvitedHandleAskWraper& Ask, GuildRpcBeInvitedHandleReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcResignDuty
* Description:    帮派-->辞职同步调用操作函数
* Input:          GuildRpcResignDutyAskWraper& Ask 辞职请求
* Output:         GuildRpcResignDutyReplyWraper& Reply 辞职回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcResignDuty( INT64 UserId, GuildRpcResignDutyAskWraper& Ask, GuildRpcResignDutyReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSyncMyTeamData
* Description:    帮派-->发送我的帮会数据异步通知操作函数
* Input:          GuildRpcSyncMyTeamDataNotifyWraper& Notify 发送我的帮会数据通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncMyTeamData( INT64 UserId, GuildRpcSyncMyTeamDataNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfGuildBaseData
* Description:    帮派-->同步帮会基础数据异步通知操作函数
* Input:          GuildRpcSyncNoticeOfGuildBaseDataNotifyWraper& Notify 同步帮会基础数据通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfGuildBaseData( INT64 UserId, GuildRpcSyncNoticeOfGuildBaseDataNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfGuildMemberChange
* Description:    帮派-->同步帮会成员数据变化异步通知操作函数
* Input:          GuildRpcSyncNoticeOfGuildMemberChangeNotifyWraper& Notify 同步帮会成员数据变化通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfGuildMemberChange( INT64 UserId, GuildRpcSyncNoticeOfGuildMemberChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfAddMember
* Description:    帮派-->同步帮会增加成员异步通知操作函数
* Input:          GuildRpcSyncNoticeOfAddMemberNotifyWraper& Notify 同步帮会增加成员通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfAddMember( INT64 UserId, GuildRpcSyncNoticeOfAddMemberNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfDelMember
* Description:    帮派-->同步帮会删除成员异步通知操作函数
* Input:          GuildRpcSyncNoticeOfDelMemberNotifyWraper& Notify 同步帮会删除成员通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfDelMember( INT64 UserId, GuildRpcSyncNoticeOfDelMemberNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfAddEvent
* Description:    帮派-->同步帮会增加事件异步通知操作函数
* Input:          GuildRpcSyncNoticeOfAddEventNotifyWraper& Notify 同步帮会增加事件通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfAddEvent( INT64 UserId, GuildRpcSyncNoticeOfAddEventNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfAddApplyList
* Description:    帮派-->同步帮会增加申请列表异步通知操作函数
* Input:          GuildRpcSyncNoticeOfAddApplyListNotifyWraper& Notify 同步帮会增加申请列表通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfAddApplyList( INT64 UserId, GuildRpcSyncNoticeOfAddApplyListNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfDelApplyList
* Description:    帮派-->同步帮会删除申请列表异步通知操作函数
* Input:          GuildRpcSyncNoticeOfDelApplyListNotifyWraper& Notify 同步帮会删除申请列表通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfDelApplyList( INT64 UserId, GuildRpcSyncNoticeOfDelApplyListNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfChangeAnnouncement
* Description:    帮派-->同步帮会公告修改异步通知操作函数
* Input:          GuildRpcSyncNoticeOfChangeAnnouncementNotifyWraper& Notify 同步帮会公告修改通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfChangeAnnouncement( INT64 UserId, GuildRpcSyncNoticeOfChangeAnnouncementNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfBreakup
* Description:    帮派-->通知解散异步通知操作函数
* Input:          GuildRpcSyncNoticeOfBreakupNotifyWraper& Notify 通知解散通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfBreakup( INT64 UserId, GuildRpcSyncNoticeOfBreakupNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcHallLvUp
* Description:    帮派-->帮会大厅升级同步调用操作函数
* Input:          GuildRpcHallLvUpAskWraper& Ask 帮会大厅升级请求
* Output:         GuildRpcHallLvUpReplyWraper& Reply 帮会大厅升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcHallLvUp( INT64 UserId, GuildRpcHallLvUpAskWraper& Ask, GuildRpcHallLvUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcHouseLvUp
* Description:    帮派-->帮会房屋升级同步调用操作函数
* Input:          GuildRpcHouseLvUpAskWraper& Ask 帮会房屋升级请求
* Output:         GuildRpcHouseLvUpReplyWraper& Reply 帮会房屋升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcHouseLvUp( INT64 UserId, GuildRpcHouseLvUpAskWraper& Ask, GuildRpcHouseLvUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcStoreroomLvUp
* Description:    帮派-->帮会库房升级同步调用操作函数
* Input:          GuildRpcStoreroomLvUpAskWraper& Ask 帮会库房升级请求
* Output:         GuildRpcStoreroomLvUpReplyWraper& Reply 帮会库房升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcStoreroomLvUp( INT64 UserId, GuildRpcStoreroomLvUpAskWraper& Ask, GuildRpcStoreroomLvUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcKongfuHallLvUp
* Description:    帮派-->帮会练武堂升级同步调用操作函数
* Input:          GuildRpcKongfuHallLvUpAskWraper& Ask 帮会练武堂升级请求
* Output:         GuildRpcKongfuHallLvUpReplyWraper& Reply 帮会练武堂升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcKongfuHallLvUp( INT64 UserId, GuildRpcKongfuHallLvUpAskWraper& Ask, GuildRpcKongfuHallLvUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfHallLvUp
* Description:    帮派-->同步帮会大厅升级异步通知操作函数
* Input:          GuildRpcSyncNoticeOfHallLvUpNotifyWraper& Notify 同步帮会大厅升级通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfHallLvUp( INT64 UserId, GuildRpcSyncNoticeOfHallLvUpNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfHouseLvUp
* Description:    帮派-->同步帮会房屋升级异步通知操作函数
* Input:          GuildRpcSyncNoticeOfHouseLvUpNotifyWraper& Notify 同步帮会房屋升级通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfHouseLvUp( INT64 UserId, GuildRpcSyncNoticeOfHouseLvUpNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfStorerommLvUp
* Description:    帮派-->同步帮会库房升级异步通知操作函数
* Input:          GuildRpcSyncNoticeOfStorerommLvUpNotifyWraper& Notify 同步帮会库房升级通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfStorerommLvUp( INT64 UserId, GuildRpcSyncNoticeOfStorerommLvUpNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfKongfuHallLvUp
* Description:    帮派-->同步练武堂升级异步通知操作函数
* Input:          GuildRpcSyncNoticeOfKongfuHallLvUpNotifyWraper& Notify 同步练武堂升级通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfKongfuHallLvUp( INT64 UserId, GuildRpcSyncNoticeOfKongfuHallLvUpNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcApplyGuildHandle
* Description:    帮派-->申请入帮，帮主处理同步调用操作函数
* Input:          GuildRpcApplyGuildHandleAskWraper& Ask 申请入帮，帮主处理请求
* Output:         GuildRpcApplyGuildHandleReplyWraper& Reply 申请入帮，帮主处理回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcApplyGuildHandle( INT64 UserId, GuildRpcApplyGuildHandleAskWraper& Ask, GuildRpcApplyGuildHandleReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCreateGuildDungeon
* Description:    帮派-->创建帮会副本同步调用操作函数
* Input:          GuildRpcCreateGuildDungeonAskWraper& Ask 创建帮会副本请求
* Output:         GuildRpcCreateGuildDungeonReplyWraper& Reply 创建帮会副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcCreateGuildDungeon( INT64 UserId, GuildRpcCreateGuildDungeonAskWraper& Ask, GuildRpcCreateGuildDungeonReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEnterGuildDungeon
* Description:    帮派-->进入帮会副本同步调用操作函数
* Input:          GuildRpcEnterGuildDungeonAskWraper& Ask 进入帮会副本请求
* Output:         GuildRpcEnterGuildDungeonReplyWraper& Reply 进入帮会副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcEnterGuildDungeon( INT64 UserId, GuildRpcEnterGuildDungeonAskWraper& Ask, GuildRpcEnterGuildDungeonReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientRpcSyncNoticeOfCreateGuildDungeon
* Description:    帮派-->同步帮会副本创建异步通知操作函数
* Input:          GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotifyWraper& Notify 同步帮会副本创建通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientRpcSyncNoticeOfCreateGuildDungeon( INT64 UserId, GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcCreateGuildWar
* Description:    帮派-->创建帮会战同步调用操作函数
* Input:          GuildRpcCreateGuildWarAskWraper& Ask 创建帮会战请求
* Output:         GuildRpcCreateGuildWarReplyWraper& Reply 创建帮会战回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcCreateGuildWar( INT64 UserId, GuildRpcCreateGuildWarAskWraper& Ask, GuildRpcCreateGuildWarReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSyncNoticeOfOpenGuildWar
* Description:    帮派-->同步帮会战是否开启异步通知操作函数
* Input:          GuildRpcSyncNoticeOfOpenGuildWarNotifyWraper& Notify 同步帮会战是否开启通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGuild::SendToClientSyncNoticeOfOpenGuildWar( INT64 UserId, GuildRpcSyncNoticeOfOpenGuildWarNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcEnterGuildWar
* Description:    帮派-->进入帮会战同步调用操作函数
* Input:          GuildRpcEnterGuildWarAskWraper& Ask 进入帮会战请求
* Output:         GuildRpcEnterGuildWarReplyWraper& Reply 进入帮会战回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcEnterGuildWar( INT64 UserId, GuildRpcEnterGuildWarAskWraper& Ask, GuildRpcEnterGuildWarReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcOpenScienceAttr
* Description:    帮派-->开启帮会修炼项目同步调用操作函数
* Input:          GuildRpcOpenScienceAttrAskWraper& Ask 开启帮会修炼项目请求
* Output:         GuildRpcOpenScienceAttrReplyWraper& Reply 开启帮会修炼项目回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcOpenScienceAttr( INT64 UserId, GuildRpcOpenScienceAttrAskWraper& Ask, GuildRpcOpenScienceAttrReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGuildScienceLvUp
* Description:    帮派-->帮会属性升级同步调用操作函数
* Input:          GuildRpcGuildScienceLvUpAskWraper& Ask 帮会属性升级请求
* Output:         GuildRpcGuildScienceLvUpReplyWraper& Reply 帮会属性升级回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleGuild::RpcGuildScienceLvUp( INT64 UserId, GuildRpcGuildScienceLvUpAskWraper& Ask, GuildRpcGuildScienceLvUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



