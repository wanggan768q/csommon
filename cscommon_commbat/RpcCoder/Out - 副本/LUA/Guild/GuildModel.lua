--将变量写入下方
local ModuleId = 34;
local RPC_CODE_GUILD_SYNCDATA_REQUEST = 3451
local RPC_CODE_GUILD_CREATEGUILD_REQUEST = 3452
local RPC_CODE_GUILD_APPLYGUILD_REQUEST = 3453
local RPC_CODE_GUILD_QUICKAPPLY_REQUEST = 3454
local RPC_CODE_GUILD_CHANGEGUILDNAME_REQUEST = 3455
local RPC_CODE_GUILD_CHANGEANNOUNCEMENT_REQUEST = 3456
local RPC_CODE_GUILD_REQGUILDLIST_REQUEST = 3457
local RPC_CODE_GUILD_APPOINTDUTY_REQUEST = 3458
local RPC_CODE_GUILD_KICKOUT_REQUEST = 3459
local RPC_CODE_GUILD_EXITGUILD_REQUEST = 3460
local RPC_CODE_GUILD_BREAKUP_REQUEST = 3461
local RPC_CODE_GUILD_INVITETOJOIN_REQUEST = 3462
local RPC_CODE_GUILD_BEINVITEDNOTICE_NOTIFY = 3463;
local RPC_CODE_GUILD_BEINVITEDHANDLE_REQUEST = 3464
local RPC_CODE_GUILD_RESIGNDUTY_REQUEST = 3465
local RPC_CODE_GUILD_SYNCMYTEAMDATA_NOTIFY = 3466;
local RPC_CODE_GUILD_SYNCNOTICEOFGUILDBASEDATA_NOTIFY = 3467;
local RPC_CODE_GUILD_SYNCNOTICEOFGUILDMEMBERCHANGE_NOTIFY = 3468;
local RPC_CODE_GUILD_SYNCNOTICEOFADDMEMBER_NOTIFY = 3469;
local RPC_CODE_GUILD_SYNCNOTICEOFDELMEMBER_NOTIFY = 3470;
local RPC_CODE_GUILD_SYNCNOTICEOFADDEVENT_NOTIFY = 3471;
local RPC_CODE_GUILD_SYNCNOTICEOFADDAPPLYLIST_NOTIFY = 3472;
local RPC_CODE_GUILD_SYNCNOTICEOFDELAPPLYLIST_NOTIFY = 3473;
local RPC_CODE_GUILD_SYNCNOTICEOFCHANGEANNOUNCEMENT_NOTIFY = 3474;
local RPC_CODE_GUILD_SYNCNOTICEOFBREAKUP_NOTIFY = 3475;
local RPC_CODE_GUILD_HALLLVUP_REQUEST = 3476
local RPC_CODE_GUILD_HOUSELVUP_REQUEST = 3477
local RPC_CODE_GUILD_STOREROOMLVUP_REQUEST = 3478
local RPC_CODE_GUILD_KONGFUHALLLVUP_REQUEST = 3479
local RPC_CODE_GUILD_SYNCNOTICEOFHALLLVUP_NOTIFY = 3480;
local RPC_CODE_GUILD_SYNCNOTICEOFHOUSELVUP_NOTIFY = 3481;
local RPC_CODE_GUILD_SYNCNOTICEOFSTOREROMMLVUP_NOTIFY = 3482;
local RPC_CODE_GUILD_SYNCNOTICEOFKONGFUHALLLVUP_NOTIFY = 3483;
local RPC_CODE_GUILD_APPLYGUILDHANDLE_REQUEST = 3484
local RPC_CODE_GUILD_CREATEGUILDDUNGEON_REQUEST = 3485
local RPC_CODE_GUILD_ENTERGUILDDUNGEON_REQUEST = 3486
local RPC_CODE_GUILD_RPCSYNCNOTICEOFCREATEGUILDDUNGEON_NOTIFY = 3487;
local RPC_CODE_GUILD_CREATEGUILDWAR_REQUEST = 3488
local RPC_CODE_GUILD_SYNCNOTICEOFOPENGUILDWAR_NOTIFY = 3489;
local RPC_CODE_GUILD_ENTERGUILDWAR_REQUEST = 3490
local RPC_CODE_GUILD_OPENSCIENCEATTR_REQUEST = 3491
local RPC_CODE_GUILD_GUILDSCIENCELVUP_REQUEST = 3492





require("app.Guild.GuildRpc_pb")

GuildModel = class("GuildModel",BaseModel)

function GuildModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=GuildModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function GuildModel:ctor()
	GuildModel.super.ctor(self)
	self.rpc_pb = GuildRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_BEINVITEDNOTICE_NOTIFY,handler(self,self.BeInvitedNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCMYTEAMDATA_NOTIFY,handler(self,self.SyncMyTeamDataCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFGUILDBASEDATA_NOTIFY,handler(self,self.SyncNoticeOfGuildBaseDataCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFGUILDMEMBERCHANGE_NOTIFY,handler(self,self.SyncNoticeOfGuildMemberChangeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFADDMEMBER_NOTIFY,handler(self,self.SyncNoticeOfAddMemberCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFDELMEMBER_NOTIFY,handler(self,self.SyncNoticeOfDelMemberCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFADDEVENT_NOTIFY,handler(self,self.SyncNoticeOfAddEventCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFADDAPPLYLIST_NOTIFY,handler(self,self.SyncNoticeOfAddApplyListCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFDELAPPLYLIST_NOTIFY,handler(self,self.SyncNoticeOfDelApplyListCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFCHANGEANNOUNCEMENT_NOTIFY,handler(self,self.SyncNoticeOfChangeAnnouncementCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFBREAKUP_NOTIFY,handler(self,self.SyncNoticeOfBreakupCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFHALLLVUP_NOTIFY,handler(self,self.SyncNoticeOfHallLvUpCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFHOUSELVUP_NOTIFY,handler(self,self.SyncNoticeOfHouseLvUpCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFSTOREROMMLVUP_NOTIFY,handler(self,self.SyncNoticeOfStorerommLvUpCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFKONGFUHALLLVUP_NOTIFY,handler(self,self.SyncNoticeOfKongfuHallLvUpCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_RPCSYNCNOTICEOFCREATEGUILDDUNGEON_NOTIFY,handler(self,self.RpcSyncNoticeOfCreateGuildDungeonCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_GUILD_SYNCNOTICEOFOPENGUILDWAR_NOTIFY,handler(self,self.SyncNoticeOfOpenGuildWarCB))

  


end

-- 更新数据
function GuildModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function GuildModel:SyncData(_hanlder)
	local PB = self.rpc_pb.GuildRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_SYNCDATA_REQUEST, pb_data, callback)
end
function GuildModel:CreateGuild(GuildName,Announcement,_hanlder)
	local PB = self.rpc_pb.GuildRpcCreateGuildAsk()
	PB.GuildName = GuildName
	PB.Announcement = Announcement
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcCreateGuildReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_CREATEGUILD_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:ApplyGuild(Guild,Oper,_hanlder)
	local PB = self.rpc_pb.GuildRpcApplyGuildAsk()
	PB.Guild = Guild
	PB.Oper = Oper
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcApplyGuildReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_APPLYGUILD_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:QuickApply(_hanlder)
	local PB = self.rpc_pb.GuildRpcQuickApplyAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcQuickApplyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_QUICKAPPLY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:ChangeGuildName(GuildName,_hanlder)
	local PB = self.rpc_pb.GuildRpcChangeGuildNameAsk()
	PB.GuildName = GuildName
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcChangeGuildNameReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_CHANGEGUILDNAME_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:ChangeAnnouncement(Announcement,_hanlder)
	local PB = self.rpc_pb.GuildRpcChangeAnnouncementAsk()
	PB.Announcement = Announcement
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcChangeAnnouncementReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_CHANGEANNOUNCEMENT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:ReqGuildList(_hanlder)
	local PB = self.rpc_pb.GuildRpcReqGuildListAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcReqGuildListReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_REQGUILDLIST_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:AppointDuty(UserId,Duty,_hanlder)
	local PB = self.rpc_pb.GuildRpcAppointDutyAsk()
	PB.UserId = UserId
	PB.Duty = Duty
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcAppointDutyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_APPOINTDUTY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:Kickout(UserId,_hanlder)
	local PB = self.rpc_pb.GuildRpcKickoutAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcKickoutReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_KICKOUT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:ExitGuild(_hanlder)
	local PB = self.rpc_pb.GuildRpcExitGuildAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcExitGuildReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_EXITGUILD_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:BreakUp(_hanlder)
	local PB = self.rpc_pb.GuildRpcBreakUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcBreakUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_BREAKUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:InviteToJoin(UserId,_hanlder)
	local PB = self.rpc_pb.GuildRpcInviteToJoinAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcInviteToJoinReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_INVITETOJOIN_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:BeInvitedHandle(Guild,Oper,_hanlder)
	local PB = self.rpc_pb.GuildRpcBeInvitedHandleAsk()
	PB.Guild = Guild
	PB.Oper = Oper
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcBeInvitedHandleReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_BEINVITEDHANDLE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:ResignDuty(_hanlder)
	local PB = self.rpc_pb.GuildRpcResignDutyAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcResignDutyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_RESIGNDUTY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:HallLvUp(_hanlder)
	local PB = self.rpc_pb.GuildRpcHallLvUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcHallLvUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_HALLLVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:HouseLvUp(_hanlder)
	local PB = self.rpc_pb.GuildRpcHouseLvUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcHouseLvUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_HOUSELVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:StoreroomLvUp(_hanlder)
	local PB = self.rpc_pb.GuildRpcStoreroomLvUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcStoreroomLvUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_STOREROOMLVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:KongfuHallLvUp(_hanlder)
	local PB = self.rpc_pb.GuildRpcKongfuHallLvUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcKongfuHallLvUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_KONGFUHALLLVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:ApplyGuildHandle(UserId,Oper,_hanlder)
	local PB = self.rpc_pb.GuildRpcApplyGuildHandleAsk()
	PB.UserId = UserId
	PB.Oper = Oper
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcApplyGuildHandleReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_APPLYGUILDHANDLE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:CreateGuildDungeon(DungeonNum,_hanlder)
	local PB = self.rpc_pb.GuildRpcCreateGuildDungeonAsk()
	PB.DungeonNum = DungeonNum
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcCreateGuildDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_CREATEGUILDDUNGEON_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:EnterGuildDungeon(Index,_hanlder)
	local PB = self.rpc_pb.GuildRpcEnterGuildDungeonAsk()
	PB.Index = Index
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcEnterGuildDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ENTERGUILDDUNGEON_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:CreateGuildWar(Guild,_hanlder)
	local PB = self.rpc_pb.GuildRpcCreateGuildWarAsk()
	PB.Guild = Guild
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcCreateGuildWarReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_CREATEGUILDWAR_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:EnterGuildWar(_hanlder)
	local PB = self.rpc_pb.GuildRpcEnterGuildWarAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcEnterGuildWarReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_ENTERGUILDWAR_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:OpenScienceAttr(ScienceId,_hanlder)
	local PB = self.rpc_pb.GuildRpcOpenScienceAttrAsk()
	PB.ScienceId = ScienceId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcOpenScienceAttrReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_OPENSCIENCEATTR_REQUEST, pb_data, callback)
	self:showNetTip()
end
function GuildModel:GuildScienceLvUp(ScienceId,IsKeyUpLv,_hanlder)
	local PB = self.rpc_pb.GuildRpcGuildScienceLvUpAsk()
	PB.ScienceId = ScienceId
	PB.IsKeyUpLv = IsKeyUpLv
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GuildRpcGuildScienceLvUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GUILD_GUILDSCIENCELVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function GuildModel:registerBeInvitedNoticeCBNotify(_hanlder)
	if not self.BeInvitedNoticeCBNotifyCallBack then
		self.BeInvitedNoticeCBNotifyCallBack = {}
	end
	table.insert(self.BeInvitedNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:BeInvitedNoticeCB(notifyMsg)
	if self.BeInvitedNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcBeInvitedNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BeInvitedNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterBeInvitedNoticeCBNotify(_hanlder)
	if nil ~= self.BeInvitedNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.BeInvitedNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BeInvitedNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncMyTeamDataCBNotify(_hanlder)
	if not self.SyncMyTeamDataCBNotifyCallBack then
		self.SyncMyTeamDataCBNotifyCallBack = {}
	end
	table.insert(self.SyncMyTeamDataCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncMyTeamDataCB(notifyMsg)
	if self.SyncMyTeamDataCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncMyTeamDataNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncMyTeamDataCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncMyTeamDataCBNotify(_hanlder)
	if nil ~= self.SyncMyTeamDataCBNotifyCallBack then
		for i,callback in ipairs(self.SyncMyTeamDataCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncMyTeamDataCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfGuildBaseDataCBNotify(_hanlder)
	if not self.SyncNoticeOfGuildBaseDataCBNotifyCallBack then
		self.SyncNoticeOfGuildBaseDataCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfGuildBaseDataCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfGuildBaseDataCB(notifyMsg)
	if self.SyncNoticeOfGuildBaseDataCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfGuildBaseDataNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfGuildBaseDataCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfGuildBaseDataCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfGuildBaseDataCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfGuildBaseDataCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfGuildBaseDataCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfGuildMemberChangeCBNotify(_hanlder)
	if not self.SyncNoticeOfGuildMemberChangeCBNotifyCallBack then
		self.SyncNoticeOfGuildMemberChangeCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfGuildMemberChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfGuildMemberChangeCB(notifyMsg)
	if self.SyncNoticeOfGuildMemberChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfGuildMemberChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfGuildMemberChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfGuildMemberChangeCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfGuildMemberChangeCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfGuildMemberChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfGuildMemberChangeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfAddMemberCBNotify(_hanlder)
	if not self.SyncNoticeOfAddMemberCBNotifyCallBack then
		self.SyncNoticeOfAddMemberCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfAddMemberCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfAddMemberCB(notifyMsg)
	if self.SyncNoticeOfAddMemberCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfAddMemberNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfAddMemberCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfAddMemberCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfAddMemberCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfAddMemberCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfAddMemberCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfDelMemberCBNotify(_hanlder)
	if not self.SyncNoticeOfDelMemberCBNotifyCallBack then
		self.SyncNoticeOfDelMemberCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfDelMemberCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfDelMemberCB(notifyMsg)
	if self.SyncNoticeOfDelMemberCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfDelMemberNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfDelMemberCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfDelMemberCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfDelMemberCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfDelMemberCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfDelMemberCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfAddEventCBNotify(_hanlder)
	if not self.SyncNoticeOfAddEventCBNotifyCallBack then
		self.SyncNoticeOfAddEventCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfAddEventCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfAddEventCB(notifyMsg)
	if self.SyncNoticeOfAddEventCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfAddEventNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfAddEventCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfAddEventCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfAddEventCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfAddEventCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfAddEventCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfAddApplyListCBNotify(_hanlder)
	if not self.SyncNoticeOfAddApplyListCBNotifyCallBack then
		self.SyncNoticeOfAddApplyListCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfAddApplyListCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfAddApplyListCB(notifyMsg)
	if self.SyncNoticeOfAddApplyListCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfAddApplyListNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfAddApplyListCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfAddApplyListCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfAddApplyListCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfAddApplyListCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfAddApplyListCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfDelApplyListCBNotify(_hanlder)
	if not self.SyncNoticeOfDelApplyListCBNotifyCallBack then
		self.SyncNoticeOfDelApplyListCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfDelApplyListCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfDelApplyListCB(notifyMsg)
	if self.SyncNoticeOfDelApplyListCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfDelApplyListNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfDelApplyListCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfDelApplyListCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfDelApplyListCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfDelApplyListCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfDelApplyListCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfChangeAnnouncementCBNotify(_hanlder)
	if not self.SyncNoticeOfChangeAnnouncementCBNotifyCallBack then
		self.SyncNoticeOfChangeAnnouncementCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfChangeAnnouncementCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfChangeAnnouncementCB(notifyMsg)
	if self.SyncNoticeOfChangeAnnouncementCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfChangeAnnouncementNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfChangeAnnouncementCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfChangeAnnouncementCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfChangeAnnouncementCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfChangeAnnouncementCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfChangeAnnouncementCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfBreakupCBNotify(_hanlder)
	if not self.SyncNoticeOfBreakupCBNotifyCallBack then
		self.SyncNoticeOfBreakupCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfBreakupCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfBreakupCB(notifyMsg)
	if self.SyncNoticeOfBreakupCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfBreakupNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfBreakupCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfBreakupCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfBreakupCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfBreakupCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfBreakupCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfHallLvUpCBNotify(_hanlder)
	if not self.SyncNoticeOfHallLvUpCBNotifyCallBack then
		self.SyncNoticeOfHallLvUpCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfHallLvUpCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfHallLvUpCB(notifyMsg)
	if self.SyncNoticeOfHallLvUpCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfHallLvUpNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfHallLvUpCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfHallLvUpCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfHallLvUpCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfHallLvUpCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfHallLvUpCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfHouseLvUpCBNotify(_hanlder)
	if not self.SyncNoticeOfHouseLvUpCBNotifyCallBack then
		self.SyncNoticeOfHouseLvUpCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfHouseLvUpCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfHouseLvUpCB(notifyMsg)
	if self.SyncNoticeOfHouseLvUpCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfHouseLvUpNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfHouseLvUpCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfHouseLvUpCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfHouseLvUpCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfHouseLvUpCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfHouseLvUpCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfStorerommLvUpCBNotify(_hanlder)
	if not self.SyncNoticeOfStorerommLvUpCBNotifyCallBack then
		self.SyncNoticeOfStorerommLvUpCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfStorerommLvUpCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfStorerommLvUpCB(notifyMsg)
	if self.SyncNoticeOfStorerommLvUpCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfStorerommLvUpNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfStorerommLvUpCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfStorerommLvUpCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfStorerommLvUpCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfStorerommLvUpCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfStorerommLvUpCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfKongfuHallLvUpCBNotify(_hanlder)
	if not self.SyncNoticeOfKongfuHallLvUpCBNotifyCallBack then
		self.SyncNoticeOfKongfuHallLvUpCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfKongfuHallLvUpCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfKongfuHallLvUpCB(notifyMsg)
	if self.SyncNoticeOfKongfuHallLvUpCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfKongfuHallLvUpNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfKongfuHallLvUpCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfKongfuHallLvUpCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfKongfuHallLvUpCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfKongfuHallLvUpCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfKongfuHallLvUpCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerRpcSyncNoticeOfCreateGuildDungeonCBNotify(_hanlder)
	if not self.RpcSyncNoticeOfCreateGuildDungeonCBNotifyCallBack then
		self.RpcSyncNoticeOfCreateGuildDungeonCBNotifyCallBack = {}
	end
	table.insert(self.RpcSyncNoticeOfCreateGuildDungeonCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:RpcSyncNoticeOfCreateGuildDungeonCB(notifyMsg)
	if self.RpcSyncNoticeOfCreateGuildDungeonCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcRpcSyncNoticeOfCreateGuildDungeonNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.RpcSyncNoticeOfCreateGuildDungeonCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterRpcSyncNoticeOfCreateGuildDungeonCBNotify(_hanlder)
	if nil ~= self.RpcSyncNoticeOfCreateGuildDungeonCBNotifyCallBack then
		for i,callback in ipairs(self.RpcSyncNoticeOfCreateGuildDungeonCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.RpcSyncNoticeOfCreateGuildDungeonCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function GuildModel:registerSyncNoticeOfOpenGuildWarCBNotify(_hanlder)
	if not self.SyncNoticeOfOpenGuildWarCBNotifyCallBack then
		self.SyncNoticeOfOpenGuildWarCBNotifyCallBack = {}
	end
	table.insert(self.SyncNoticeOfOpenGuildWarCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function GuildModel:SyncNoticeOfOpenGuildWarCB(notifyMsg)
	if self.SyncNoticeOfOpenGuildWarCBNotifyCallBack then
		local ret_msg = self.rpc_pb.GuildRpcSyncNoticeOfOpenGuildWarNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncNoticeOfOpenGuildWarCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function GuildModel:unregisterSyncNoticeOfOpenGuildWarCBNotify(_hanlder)
	if nil ~= self.SyncNoticeOfOpenGuildWarCBNotifyCallBack then
		for i,callback in ipairs(self.SyncNoticeOfOpenGuildWarCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncNoticeOfOpenGuildWarCBNotifyCallBack, i )
			end
		end
	end
end





askList.Guild = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = GuildModel.SyncData
t.pb = GuildRpc_pb.GuildRpcSyncDataAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "CreateGuild"
t.para = {{name="GuildName",t=2},{name="Announcement",t=2}}
t.hand = GuildModel.CreateGuild
t.pb = GuildRpc_pb.GuildRpcCreateGuildAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ApplyGuild"
t.para = {{name="Guild",t=1},{name="Oper",t=1}}
t.hand = GuildModel.ApplyGuild
t.pb = GuildRpc_pb.GuildRpcApplyGuildAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "QuickApply"
t.para = {}
t.hand = GuildModel.QuickApply
t.pb = GuildRpc_pb.GuildRpcQuickApplyAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ChangeGuildName"
t.para = {{name="GuildName",t=2}}
t.hand = GuildModel.ChangeGuildName
t.pb = GuildRpc_pb.GuildRpcChangeGuildNameAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ChangeAnnouncement"
t.para = {{name="Announcement",t=2}}
t.hand = GuildModel.ChangeAnnouncement
t.pb = GuildRpc_pb.GuildRpcChangeAnnouncementAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ReqGuildList"
t.para = {}
t.hand = GuildModel.ReqGuildList
t.pb = GuildRpc_pb.GuildRpcReqGuildListAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "AppointDuty"
t.para = {{name="UserId",t=1},{name="Duty",t=1}}
t.hand = GuildModel.AppointDuty
t.pb = GuildRpc_pb.GuildRpcAppointDutyAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "Kickout"
t.para = {{name="UserId",t=1}}
t.hand = GuildModel.Kickout
t.pb = GuildRpc_pb.GuildRpcKickoutAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ExitGuild"
t.para = {}
t.hand = GuildModel.ExitGuild
t.pb = GuildRpc_pb.GuildRpcExitGuildAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "BreakUp"
t.para = {}
t.hand = GuildModel.BreakUp
t.pb = GuildRpc_pb.GuildRpcBreakUpAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "InviteToJoin"
t.para = {{name="UserId",t=1}}
t.hand = GuildModel.InviteToJoin
t.pb = GuildRpc_pb.GuildRpcInviteToJoinAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "BeInvitedHandle"
t.para = {{name="Guild",t=1},{name="Oper",t=1}}
t.hand = GuildModel.BeInvitedHandle
t.pb = GuildRpc_pb.GuildRpcBeInvitedHandleAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ResignDuty"
t.para = {}
t.hand = GuildModel.ResignDuty
t.pb = GuildRpc_pb.GuildRpcResignDutyAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "HallLvUp"
t.para = {}
t.hand = GuildModel.HallLvUp
t.pb = GuildRpc_pb.GuildRpcHallLvUpAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "HouseLvUp"
t.para = {}
t.hand = GuildModel.HouseLvUp
t.pb = GuildRpc_pb.GuildRpcHouseLvUpAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "StoreroomLvUp"
t.para = {}
t.hand = GuildModel.StoreroomLvUp
t.pb = GuildRpc_pb.GuildRpcStoreroomLvUpAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "KongfuHallLvUp"
t.para = {}
t.hand = GuildModel.KongfuHallLvUp
t.pb = GuildRpc_pb.GuildRpcKongfuHallLvUpAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "ApplyGuildHandle"
t.para = {{name="UserId",t=1},{name="Oper",t=1}}
t.hand = GuildModel.ApplyGuildHandle
t.pb = GuildRpc_pb.GuildRpcApplyGuildHandleAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "CreateGuildDungeon"
t.para = {{name="DungeonNum",t=1}}
t.hand = GuildModel.CreateGuildDungeon
t.pb = GuildRpc_pb.GuildRpcCreateGuildDungeonAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "EnterGuildDungeon"
t.para = {{name="Index",t=1}}
t.hand = GuildModel.EnterGuildDungeon
t.pb = GuildRpc_pb.GuildRpcEnterGuildDungeonAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "CreateGuildWar"
t.para = {{name="Guild",t=1}}
t.hand = GuildModel.CreateGuildWar
t.pb = GuildRpc_pb.GuildRpcCreateGuildWarAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "EnterGuildWar"
t.para = {}
t.hand = GuildModel.EnterGuildWar
t.pb = GuildRpc_pb.GuildRpcEnterGuildWarAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "OpenScienceAttr"
t.para = {{name="ScienceId",t=1}}
t.hand = GuildModel.OpenScienceAttr
t.pb = GuildRpc_pb.GuildRpcOpenScienceAttrAsk()
table.insert(askList.Guild,t)

local t = {}
t.name = "GuildScienceLvUp"
t.para = {{name="ScienceId",t=1},{name="IsKeyUpLv",t=3}}
t.hand = GuildModel.GuildScienceLvUp
t.pb = GuildRpc_pb.GuildRpcGuildScienceLvUpAsk()
table.insert(askList.Guild,t)

