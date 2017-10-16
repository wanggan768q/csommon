/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcTeamImp.cpp
* Author:       甘业清
* Description:  组队类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "TeamModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcCreateTeam
* Description:    组队-->创建队伍同步调用操作函数
* Input:          TeamRpcCreateTeamAskWraper& Ask 创建队伍请求
* Output:         TeamRpcCreateTeamReplyWraper& Reply 创建队伍回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcCreateTeam( INT64 UserId, TeamRpcCreateTeamAskWraper& Ask, TeamRpcCreateTeamReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcApplyForTeam
* Description:    组队-->申请入队同步调用操作函数
* Input:          TeamRpcApplyForTeamAskWraper& Ask 申请入队请求
* Output:         TeamRpcApplyForTeamReplyWraper& Reply 申请入队回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcApplyForTeam( INT64 UserId, TeamRpcApplyForTeamAskWraper& Ask, TeamRpcApplyForTeamReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcQuitTeam
* Description:    组队-->离开队伍异步通知操作函数
* Input:          TeamRpcQuitTeamNotifyWraper& Notify 离开队伍通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleTeam::RpcQuitTeam( INT64 UserId, TeamRpcQuitTeamNotifyWraper& Notify )
{

	//逻辑代码


	return 0;
}

/********************************************************************************************
* Function:       RpcBreakUp
* Description:    组队-->解散队伍同步调用操作函数
* Input:          TeamRpcBreakUpAskWraper& Ask 解散队伍请求
* Output:         TeamRpcBreakUpReplyWraper& Reply 解散队伍回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcBreakUp( INT64 UserId, TeamRpcBreakUpAskWraper& Ask, TeamRpcBreakUpReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInviteToTeam
* Description:    组队-->邀请入队同步调用操作函数
* Input:          TeamRpcInviteToTeamAskWraper& Ask 邀请入队请求
* Output:         TeamRpcInviteToTeamReplyWraper& Reply 邀请入队回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcInviteToTeam( INT64 UserId, TeamRpcInviteToTeamAskWraper& Ask, TeamRpcInviteToTeamReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChangeTeamTarget
* Description:    组队-->更改队伍目标同步调用操作函数
* Input:          TeamRpcChangeTeamTargetAskWraper& Ask 更改队伍目标请求
* Output:         TeamRpcChangeTeamTargetReplyWraper& Reply 更改队伍目标回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcChangeTeamTarget( INT64 UserId, TeamRpcChangeTeamTargetAskWraper& Ask, TeamRpcChangeTeamTargetReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientBeInvitedNotice
* Description:    组队-->被邀请入队通知异步通知操作函数
* Input:          TeamRpcBeInvitedNoticeNotifyWraper& Notify 被邀请入队通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientBeInvitedNotice( INT64 UserId, TeamRpcBeInvitedNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcBeInviteHandle
* Description:    组队-->被邀请处理同步调用操作函数
* Input:          TeamRpcBeInviteHandleAskWraper& Ask 被邀请处理请求
* Output:         TeamRpcBeInviteHandleReplyWraper& Reply 被邀请处理回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcBeInviteHandle( INT64 UserId, TeamRpcBeInviteHandleAskWraper& Ask, TeamRpcBeInviteHandleReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcNearbyTeam
* Description:    组队-->附近队伍同步调用操作函数
* Input:          TeamRpcNearbyTeamAskWraper& Ask 附近队伍请求
* Output:         TeamRpcNearbyTeamReplyWraper& Reply 附近队伍回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcNearbyTeam( INT64 UserId, TeamRpcNearbyTeamAskWraper& Ask, TeamRpcNearbyTeamReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientApplyNoticeCaptain
* Description:    组队-->申请入队通知,所有人都可以看,但只有队长才能同意异步通知操作函数
* Input:          TeamRpcApplyNoticeCaptainNotifyWraper& Notify 有人申请入队,队长收到通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientApplyNoticeCaptain( INT64 UserId, TeamRpcApplyNoticeCaptainNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcApplyHandleAgree
* Description:    组队-->申请入队,队长同意入队同步调用操作函数
* Input:          TeamRpcApplyHandleAgreeAskWraper& Ask 申请入队,队长同意入队请求
* Output:         TeamRpcApplyHandleAgreeReplyWraper& Reply 申请入队,队长同意入队回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcApplyHandleAgree( INT64 UserId, TeamRpcApplyHandleAgreeAskWraper& Ask, TeamRpcApplyHandleAgreeReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientUpdateMyTeamNotice
* Description:    组队-->更新我的队伍通知异步通知操作函数
* Input:          TeamRpcUpdateMyTeamNoticeNotifyWraper& Notify 更新我的队伍通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientUpdateMyTeamNotice( INT64 UserId, TeamRpcUpdateMyTeamNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientLeaveTeamNotice
* Description:    组队-->离开队伍通知异步通知操作函数
* Input:          TeamRpcLeaveTeamNoticeNotifyWraper& Notify 离开队伍通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientLeaveTeamNotice( INT64 UserId, TeamRpcLeaveTeamNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientBreakUpNotice
* Description:    组队-->解散队伍通知异步通知操作函数
* Input:          TeamRpcBreakUpNoticeNotifyWraper& Notify 解散队伍通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientBreakUpNotice( INT64 UserId, TeamRpcBreakUpNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcReqMyTeamData
* Description:    组队-->请求我的队伍数据异步通知操作函数
* Input:          TeamRpcReqMyTeamDataNotifyWraper& Notify 请求我的队伍数据通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleTeam::RpcReqMyTeamData( INT64 UserId, TeamRpcReqMyTeamDataNotifyWraper& Notify )
{

	//逻辑代码


	return 0;
}

/********************************************************************************************
* Function:       SendToClientDeleteFromApplyList
* Description:    组队-->申请列表处理后删除申请的玩家异步通知操作函数
* Input:          TeamRpcDeleteFromApplyListNotifyWraper& Notify 申请列表处理后删除申请的玩家通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientDeleteFromApplyList( INT64 UserId, TeamRpcDeleteFromApplyListNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcAppointCaptain
* Description:    组队-->任命队长同步调用操作函数
* Input:          TeamRpcAppointCaptainAskWraper& Ask 任命队长请求
* Output:         TeamRpcAppointCaptainReplyWraper& Reply 任命队长回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcAppointCaptain( INT64 UserId, TeamRpcAppointCaptainAskWraper& Ask, TeamRpcAppointCaptainReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientCaptainChangeNotice
* Description:    组队-->队长换人通知异步通知操作函数
* Input:          TeamRpcCaptainChangeNoticeNotifyWraper& Notify 队长换人通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientCaptainChangeNotice( INT64 UserId, TeamRpcCaptainChangeNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientTeamMemberHPChangeNotice
* Description:    组队-->队员血量变化通知异步通知操作函数
* Input:          TeamRpcTeamMemberHPChangeNoticeNotifyWraper& Notify 队员血量变化通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientTeamMemberHPChangeNotice( INT64 UserId, TeamRpcTeamMemberHPChangeNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientInviteHandleNotice
* Description:    组队-->邀请组队的人收到被邀请人的处理通知异步通知操作函数
* Input:          TeamRpcInviteHandleNoticeNotifyWraper& Notify 邀请组队的人收到被邀请人的处理通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientInviteHandleNotice( INT64 UserId, TeamRpcInviteHandleNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcNearbyRoleList
* Description:    组队-->附加玩家列表，邀请时使用同步调用操作函数
* Input:          TeamRpcNearbyRoleListAskWraper& Ask 附加玩家列表，邀请时使用请求
* Output:         TeamRpcNearbyRoleListReplyWraper& Reply 附加玩家列表，邀请时使用回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcNearbyRoleList( INT64 UserId, TeamRpcNearbyRoleListAskWraper& Ask, TeamRpcNearbyRoleListReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcKickRole
* Description:    组队-->队长踢人同步调用操作函数
* Input:          TeamRpcKickRoleAskWraper& Ask 队长踢人请求
* Output:         TeamRpcKickRoleReplyWraper& Reply 队长踢人回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcKickRole( INT64 UserId, TeamRpcKickRoleAskWraper& Ask, TeamRpcKickRoleReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientBeingKickedNotice
* Description:    组队-->被踢通知异步通知操作函数
* Input:          TeamRpcBeingKickedNoticeNotifyWraper& Notify 被踢通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientBeingKickedNotice( INT64 UserId, TeamRpcBeingKickedNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientAddNewMemberNotice
* Description:    组队-->队员增加新成员通知异步通知操作函数
* Input:          TeamRpcAddNewMemberNoticeNotifyWraper& Notify 队员增加新成员通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientAddNewMemberNotice( INT64 UserId, TeamRpcAddNewMemberNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcCaptainAutoMatch
* Description:    组队-->队长自己匹配同步调用操作函数
* Input:          TeamRpcCaptainAutoMatchAskWraper& Ask 队长自己匹配请求
* Output:         TeamRpcCaptainAutoMatchReplyWraper& Reply 队长自己匹配回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcCaptainAutoMatch( INT64 UserId, TeamRpcCaptainAutoMatchAskWraper& Ask, TeamRpcCaptainAutoMatchReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcNormalAutoMatch
* Description:    组队-->非队长匹配同步调用操作函数
* Input:          TeamRpcNormalAutoMatchAskWraper& Ask 非队长匹配请求
* Output:         TeamRpcNormalAutoMatchReplyWraper& Reply 非队长匹配回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcNormalAutoMatch( INT64 UserId, TeamRpcNormalAutoMatchAskWraper& Ask, TeamRpcNormalAutoMatchReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcFollow
* Description:    组队-->跟随同步调用操作函数
* Input:          TeamRpcFollowAskWraper& Ask 跟随请求
* Output:         TeamRpcFollowReplyWraper& Reply 跟随回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcFollow( INT64 UserId, TeamRpcFollowAskWraper& Ask, TeamRpcFollowReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcClearApplyList
* Description:    组队-->清空申请列表同步调用操作函数
* Input:          TeamRpcClearApplyListAskWraper& Ask 清空申请列表请求
* Output:         TeamRpcClearApplyListReplyWraper& Reply 清空申请列表回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
int ModuleTeam::RpcClearApplyList( INT64 UserId, TeamRpcClearApplyListAskWraper& Ask, TeamRpcClearApplyListReplyWraper& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



