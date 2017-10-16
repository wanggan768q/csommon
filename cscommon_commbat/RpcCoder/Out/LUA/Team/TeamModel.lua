--将变量写入下方
local ModuleId = 26;
local RPC_CODE_TEAM_CREATETEAM_REQUEST = 2651
local RPC_CODE_TEAM_APPLYFORTEAM_REQUEST = 2652
local RPC_CODE_TEAM_QUITTEAM_NOTIFY = 2653;
local RPC_CODE_TEAM_BREAKUP_REQUEST = 2654
local RPC_CODE_TEAM_INVITETOTEAM_REQUEST = 2655
local RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST = 2656
local RPC_CODE_TEAM_BEINVITEDNOTICE_NOTIFY = 2657;
local RPC_CODE_TEAM_BEINVITEHANDLE_REQUEST = 2658
local RPC_CODE_TEAM_NEARBYTEAM_REQUEST = 2659
local RPC_CODE_TEAM_APPLYNOTICECAPTAIN_NOTIFY = 2660;
local RPC_CODE_TEAM_APPLYHANDLEAGREE_REQUEST = 2661
local RPC_CODE_TEAM_UPDATEMYTEAMNOTICE_NOTIFY = 2662;
local RPC_CODE_TEAM_LEAVETEAMNOTICE_NOTIFY = 2663;
local RPC_CODE_TEAM_BREAKUPNOTICE_NOTIFY = 2664;
local RPC_CODE_TEAM_REQMYTEAMDATA_NOTIFY = 2665;
local RPC_CODE_TEAM_DELETEFROMAPPLYLIST_NOTIFY = 2666;
local RPC_CODE_TEAM_APPOINTCAPTAIN_REQUEST = 2667
local RPC_CODE_TEAM_CAPTAINCHANGENOTICE_NOTIFY = 2668;
local RPC_CODE_TEAM_TEAMMEMBERHPCHANGENOTICE_NOTIFY = 2669;
local RPC_CODE_TEAM_INVITEHANDLENOTICE_NOTIFY = 2670;
local RPC_CODE_TEAM_NEARBYROLELIST_REQUEST = 2671
local RPC_CODE_TEAM_KICKROLE_REQUEST = 2672
local RPC_CODE_TEAM_BEINGKICKEDNOTICE_NOTIFY = 2673;
local RPC_CODE_TEAM_ADDNEWMEMBERNOTICE_NOTIFY = 2674;
local RPC_CODE_TEAM_CAPTAINAUTOMATCH_REQUEST = 2675
local RPC_CODE_TEAM_NORMALAUTOMATCH_REQUEST = 2676
local RPC_CODE_TEAM_FOLLOW_REQUEST = 2677
local RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST = 2678





require("app.Team.TeamRpc_pb")

TeamModel = class("TeamModel",BaseModel)

function TeamModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TeamModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function TeamModel:ctor()
	TeamModel.super.ctor(self)
	self.rpc_pb = TeamRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_BEINVITEDNOTICE_NOTIFY,handler(self,self.BeInvitedNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_APPLYNOTICECAPTAIN_NOTIFY,handler(self,self.ApplyNoticeCaptainCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_UPDATEMYTEAMNOTICE_NOTIFY,handler(self,self.UpdateMyTeamNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_LEAVETEAMNOTICE_NOTIFY,handler(self,self.LeaveTeamNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_BREAKUPNOTICE_NOTIFY,handler(self,self.BreakUpNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_DELETEFROMAPPLYLIST_NOTIFY,handler(self,self.DeleteFromApplyListCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_CAPTAINCHANGENOTICE_NOTIFY,handler(self,self.CaptainChangeNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_TEAMMEMBERHPCHANGENOTICE_NOTIFY,handler(self,self.TeamMemberHPChangeNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_INVITEHANDLENOTICE_NOTIFY,handler(self,self.InviteHandleNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_BEINGKICKEDNOTICE_NOTIFY,handler(self,self.BeingKickedNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TEAM_ADDNEWMEMBERNOTICE_NOTIFY,handler(self,self.AddNewMemberNoticeCB))

  


end

-- 更新数据
function TeamModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function TeamModel:CreateTeam(TargetId,TargetMinLv,TargetMaxLv,_hanlder)
	local PB = self.rpc_pb.TeamRpcCreateTeamAsk()
	PB.TargetId = TargetId
	PB.TargetMinLv = TargetMinLv
	PB.TargetMaxLv = TargetMaxLv
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcCreateTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CREATETEAM_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:ApplyForTeam(TeamId,_hanlder)
	local PB = self.rpc_pb.TeamRpcApplyForTeamAsk()
	PB.TeamId = TeamId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcApplyForTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPLYFORTEAM_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:BreakUp(_hanlder)
	local PB = self.rpc_pb.TeamRpcBreakUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcBreakUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_BREAKUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:InviteToTeam(UserId,_hanlder)
	local PB = self.rpc_pb.TeamRpcInviteToTeamAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcInviteToTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_INVITETOTEAM_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:ChangeTeamTarget(TargetId,TargetMinLv,TargetMaxLv,_hanlder)
	local PB = self.rpc_pb.TeamRpcChangeTeamTargetAsk()
	PB.TargetId = TargetId
	PB.TargetMinLv = TargetMinLv
	PB.TargetMaxLv = TargetMaxLv
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcChangeTeamTargetReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:BeInviteHandle(TeamId,UserId,Handle,_hanlder)
	local PB = self.rpc_pb.TeamRpcBeInviteHandleAsk()
	PB.TeamId = TeamId
	PB.UserId = UserId
	PB.Handle = Handle
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcBeInviteHandleReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_BEINVITEHANDLE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:NearbyTeam(TargetId,_hanlder)
	local PB = self.rpc_pb.TeamRpcNearbyTeamAsk()
	PB.TargetId = TargetId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcNearbyTeamReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_NEARBYTEAM_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:ApplyHandleAgree(UserId,TeamId,Handle,_hanlder)
	local PB = self.rpc_pb.TeamRpcApplyHandleAgreeAsk()
	PB.UserId = UserId
	PB.TeamId = TeamId
	PB.Handle = Handle
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcApplyHandleAgreeReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPLYHANDLEAGREE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:AppointCaptain(UserId,_hanlder)
	local PB = self.rpc_pb.TeamRpcAppointCaptainAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcAppointCaptainReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_APPOINTCAPTAIN_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:NearbyRoleList(_hanlder)
	local PB = self.rpc_pb.TeamRpcNearbyRoleListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcNearbyRoleListReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_NEARBYROLELIST_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:KickRole(UserId,_hanlder)
	local PB = self.rpc_pb.TeamRpcKickRoleAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcKickRoleReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_KICKROLE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:CaptainAutoMatch(Oper,_hanlder)
	local PB = self.rpc_pb.TeamRpcCaptainAutoMatchAsk()
	PB.Oper = Oper
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcCaptainAutoMatchReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CAPTAINAUTOMATCH_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:NormalAutoMatch(Oper,Target,_hanlder)
	local PB = self.rpc_pb.TeamRpcNormalAutoMatchAsk()
	PB.Oper = Oper
	PB.Target = Target
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcNormalAutoMatchReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_NORMALAUTOMATCH_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:Follow(_hanlder)
	local PB = self.rpc_pb.TeamRpcFollowAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcFollowReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_FOLLOW_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TeamModel:ClearApplyList(_hanlder)
	local PB = self.rpc_pb.TeamRpcClearApplyListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TeamRpcClearApplyListReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function TeamModel:QuitTeamNotify()
	local PB = self.rpc_pb.TeamRpcQuitTeamNotify()
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_TEAM_QUITTEAM_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function TeamModel:registerBeInvitedNoticeCBNotify(_hanlder)
	if not self.BeInvitedNoticeCBNotifyCallBack then
		self.BeInvitedNoticeCBNotifyCallBack = {}
	end
	table.insert(self.BeInvitedNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:BeInvitedNoticeCB(notifyMsg)
	if self.BeInvitedNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcBeInvitedNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BeInvitedNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterBeInvitedNoticeCBNotify(_hanlder)
	if nil ~= self.BeInvitedNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.BeInvitedNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BeInvitedNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerApplyNoticeCaptainCBNotify(_hanlder)
	if not self.ApplyNoticeCaptainCBNotifyCallBack then
		self.ApplyNoticeCaptainCBNotifyCallBack = {}
	end
	table.insert(self.ApplyNoticeCaptainCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:ApplyNoticeCaptainCB(notifyMsg)
	if self.ApplyNoticeCaptainCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcApplyNoticeCaptainNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ApplyNoticeCaptainCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterApplyNoticeCaptainCBNotify(_hanlder)
	if nil ~= self.ApplyNoticeCaptainCBNotifyCallBack then
		for i,callback in ipairs(self.ApplyNoticeCaptainCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ApplyNoticeCaptainCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerUpdateMyTeamNoticeCBNotify(_hanlder)
	if not self.UpdateMyTeamNoticeCBNotifyCallBack then
		self.UpdateMyTeamNoticeCBNotifyCallBack = {}
	end
	table.insert(self.UpdateMyTeamNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:UpdateMyTeamNoticeCB(notifyMsg)
	if self.UpdateMyTeamNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcUpdateMyTeamNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateMyTeamNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterUpdateMyTeamNoticeCBNotify(_hanlder)
	if nil ~= self.UpdateMyTeamNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateMyTeamNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateMyTeamNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerLeaveTeamNoticeCBNotify(_hanlder)
	if not self.LeaveTeamNoticeCBNotifyCallBack then
		self.LeaveTeamNoticeCBNotifyCallBack = {}
	end
	table.insert(self.LeaveTeamNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:LeaveTeamNoticeCB(notifyMsg)
	if self.LeaveTeamNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcLeaveTeamNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.LeaveTeamNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterLeaveTeamNoticeCBNotify(_hanlder)
	if nil ~= self.LeaveTeamNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.LeaveTeamNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.LeaveTeamNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerBreakUpNoticeCBNotify(_hanlder)
	if not self.BreakUpNoticeCBNotifyCallBack then
		self.BreakUpNoticeCBNotifyCallBack = {}
	end
	table.insert(self.BreakUpNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:BreakUpNoticeCB(notifyMsg)
	if self.BreakUpNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcBreakUpNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BreakUpNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterBreakUpNoticeCBNotify(_hanlder)
	if nil ~= self.BreakUpNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.BreakUpNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BreakUpNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:ReqMyTeamDataNotify()
	local PB = self.rpc_pb.TeamRpcReqMyTeamDataNotify()
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_TEAM_REQMYTEAMDATA_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function TeamModel:registerDeleteFromApplyListCBNotify(_hanlder)
	if not self.DeleteFromApplyListCBNotifyCallBack then
		self.DeleteFromApplyListCBNotifyCallBack = {}
	end
	table.insert(self.DeleteFromApplyListCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:DeleteFromApplyListCB(notifyMsg)
	if self.DeleteFromApplyListCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcDeleteFromApplyListNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DeleteFromApplyListCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterDeleteFromApplyListCBNotify(_hanlder)
	if nil ~= self.DeleteFromApplyListCBNotifyCallBack then
		for i,callback in ipairs(self.DeleteFromApplyListCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DeleteFromApplyListCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerCaptainChangeNoticeCBNotify(_hanlder)
	if not self.CaptainChangeNoticeCBNotifyCallBack then
		self.CaptainChangeNoticeCBNotifyCallBack = {}
	end
	table.insert(self.CaptainChangeNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:CaptainChangeNoticeCB(notifyMsg)
	if self.CaptainChangeNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcCaptainChangeNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.CaptainChangeNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterCaptainChangeNoticeCBNotify(_hanlder)
	if nil ~= self.CaptainChangeNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.CaptainChangeNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.CaptainChangeNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerTeamMemberHPChangeNoticeCBNotify(_hanlder)
	if not self.TeamMemberHPChangeNoticeCBNotifyCallBack then
		self.TeamMemberHPChangeNoticeCBNotifyCallBack = {}
	end
	table.insert(self.TeamMemberHPChangeNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:TeamMemberHPChangeNoticeCB(notifyMsg)
	if self.TeamMemberHPChangeNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcTeamMemberHPChangeNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TeamMemberHPChangeNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterTeamMemberHPChangeNoticeCBNotify(_hanlder)
	if nil ~= self.TeamMemberHPChangeNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.TeamMemberHPChangeNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TeamMemberHPChangeNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerInviteHandleNoticeCBNotify(_hanlder)
	if not self.InviteHandleNoticeCBNotifyCallBack then
		self.InviteHandleNoticeCBNotifyCallBack = {}
	end
	table.insert(self.InviteHandleNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:InviteHandleNoticeCB(notifyMsg)
	if self.InviteHandleNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcInviteHandleNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.InviteHandleNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterInviteHandleNoticeCBNotify(_hanlder)
	if nil ~= self.InviteHandleNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.InviteHandleNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.InviteHandleNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerBeingKickedNoticeCBNotify(_hanlder)
	if not self.BeingKickedNoticeCBNotifyCallBack then
		self.BeingKickedNoticeCBNotifyCallBack = {}
	end
	table.insert(self.BeingKickedNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:BeingKickedNoticeCB(notifyMsg)
	if self.BeingKickedNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcBeingKickedNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BeingKickedNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterBeingKickedNoticeCBNotify(_hanlder)
	if nil ~= self.BeingKickedNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.BeingKickedNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BeingKickedNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TeamModel:registerAddNewMemberNoticeCBNotify(_hanlder)
	if not self.AddNewMemberNoticeCBNotifyCallBack then
		self.AddNewMemberNoticeCBNotifyCallBack = {}
	end
	table.insert(self.AddNewMemberNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TeamModel:AddNewMemberNoticeCB(notifyMsg)
	if self.AddNewMemberNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TeamRpcAddNewMemberNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AddNewMemberNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TeamModel:unregisterAddNewMemberNoticeCBNotify(_hanlder)
	if nil ~= self.AddNewMemberNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.AddNewMemberNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AddNewMemberNoticeCBNotifyCallBack, i )
			end
		end
	end
end





askList.Team = {}

local t = {}
t.name = "CreateTeam"
t.para = {{name="TargetId",t=1},{name="TargetMinLv",t=1},{name="TargetMaxLv",t=1}}
t.hand = TeamModel.CreateTeam
t.pb = TeamRpc_pb.TeamRpcCreateTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "ApplyForTeam"
t.para = {{name="TeamId",t=1}}
t.hand = TeamModel.ApplyForTeam
t.pb = TeamRpc_pb.TeamRpcApplyForTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "BreakUp"
t.para = {}
t.hand = TeamModel.BreakUp
t.pb = TeamRpc_pb.TeamRpcBreakUpAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "InviteToTeam"
t.para = {{name="UserId",t=1}}
t.hand = TeamModel.InviteToTeam
t.pb = TeamRpc_pb.TeamRpcInviteToTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "ChangeTeamTarget"
t.para = {{name="TargetId",t=1},{name="TargetMinLv",t=1},{name="TargetMaxLv",t=1}}
t.hand = TeamModel.ChangeTeamTarget
t.pb = TeamRpc_pb.TeamRpcChangeTeamTargetAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "BeInviteHandle"
t.para = {{name="TeamId",t=1},{name="UserId",t=1},{name="Handle",t=1}}
t.hand = TeamModel.BeInviteHandle
t.pb = TeamRpc_pb.TeamRpcBeInviteHandleAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "NearbyTeam"
t.para = {{name="TargetId",t=1}}
t.hand = TeamModel.NearbyTeam
t.pb = TeamRpc_pb.TeamRpcNearbyTeamAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "ApplyHandleAgree"
t.para = {{name="UserId",t=1},{name="TeamId",t=1},{name="Handle",t=1}}
t.hand = TeamModel.ApplyHandleAgree
t.pb = TeamRpc_pb.TeamRpcApplyHandleAgreeAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "AppointCaptain"
t.para = {{name="UserId",t=1}}
t.hand = TeamModel.AppointCaptain
t.pb = TeamRpc_pb.TeamRpcAppointCaptainAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "NearbyRoleList"
t.para = {}
t.hand = TeamModel.NearbyRoleList
t.pb = TeamRpc_pb.TeamRpcNearbyRoleListAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "KickRole"
t.para = {{name="UserId",t=1}}
t.hand = TeamModel.KickRole
t.pb = TeamRpc_pb.TeamRpcKickRoleAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "CaptainAutoMatch"
t.para = {{name="Oper",t=1}}
t.hand = TeamModel.CaptainAutoMatch
t.pb = TeamRpc_pb.TeamRpcCaptainAutoMatchAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "NormalAutoMatch"
t.para = {{name="Oper",t=1},{name="Target",t=1}}
t.hand = TeamModel.NormalAutoMatch
t.pb = TeamRpc_pb.TeamRpcNormalAutoMatchAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "Follow"
t.para = {}
t.hand = TeamModel.Follow
t.pb = TeamRpc_pb.TeamRpcFollowAsk()
table.insert(askList.Team,t)

local t = {}
t.name = "ClearApplyList"
t.para = {}
t.hand = TeamModel.ClearApplyList
t.pb = TeamRpc_pb.TeamRpcClearApplyListAsk()
table.insert(askList.Team,t)

