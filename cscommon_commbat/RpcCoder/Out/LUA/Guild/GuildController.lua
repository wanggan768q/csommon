GuildController = class("GuildController",BaseController)

function GuildController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=GuildController.new(GuildModel:getInstance())
	end 
	return self.instance
end

function GuildController:ctor(model)
	GuildController.super.ctor(self,model)
	
	
	self.model:registerBeInvitedNoticeCBNotify(handler(self,self.BeInvitedNoticeCBNotify))
	self.model:registerSyncMyTeamDataCBNotify(handler(self,self.SyncMyTeamDataCBNotify))
	self.model:registerSyncNoticeOfGuildBaseDataCBNotify(handler(self,self.SyncNoticeOfGuildBaseDataCBNotify))
	self.model:registerSyncNoticeOfGuildMemberChangeCBNotify(handler(self,self.SyncNoticeOfGuildMemberChangeCBNotify))
	self.model:registerSyncNoticeOfAddMemberCBNotify(handler(self,self.SyncNoticeOfAddMemberCBNotify))
	self.model:registerSyncNoticeOfDelMemberCBNotify(handler(self,self.SyncNoticeOfDelMemberCBNotify))
	self.model:registerSyncNoticeOfAddEventCBNotify(handler(self,self.SyncNoticeOfAddEventCBNotify))
	self.model:registerSyncNoticeOfAddApplyListCBNotify(handler(self,self.SyncNoticeOfAddApplyListCBNotify))
	self.model:registerSyncNoticeOfDelApplyListCBNotify(handler(self,self.SyncNoticeOfDelApplyListCBNotify))
	self.model:registerSyncNoticeOfChangeAnnouncementCBNotify(handler(self,self.SyncNoticeOfChangeAnnouncementCBNotify))
	self.model:registerSyncNoticeOfBreakupCBNotify(handler(self,self.SyncNoticeOfBreakupCBNotify))
	self.model:registerSyncNoticeOfHallLvUpCBNotify(handler(self,self.SyncNoticeOfHallLvUpCBNotify))
	self.model:registerSyncNoticeOfHouseLvUpCBNotify(handler(self,self.SyncNoticeOfHouseLvUpCBNotify))
	self.model:registerSyncNoticeOfStorerommLvUpCBNotify(handler(self,self.SyncNoticeOfStorerommLvUpCBNotify))
	self.model:registerSyncNoticeOfKongfuHallLvUpCBNotify(handler(self,self.SyncNoticeOfKongfuHallLvUpCBNotify))
	self.model:registerRpcSyncNoticeOfCreateGuildDungeonCBNotify(handler(self,self.RpcSyncNoticeOfCreateGuildDungeonCBNotify))
	self.model:registerSyncNoticeOfOpenGuildWarCBNotify(handler(self,self.SyncNoticeOfOpenGuildWarCBNotify))

end

function GuildController:modelDataUpdate( syncId, idx )

end





function GuildController:BeInvitedNoticeCBNotify(ret_msg)
end
function GuildController:SyncMyTeamDataCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfGuildBaseDataCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfGuildMemberChangeCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfAddMemberCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfDelMemberCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfAddEventCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfAddApplyListCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfDelApplyListCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfChangeAnnouncementCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfBreakupCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfHallLvUpCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfHouseLvUpCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfStorerommLvUpCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfKongfuHallLvUpCBNotify(ret_msg)
end
function GuildController:RpcSyncNoticeOfCreateGuildDungeonCBNotify(ret_msg)
end
function GuildController:SyncNoticeOfOpenGuildWarCBNotify(ret_msg)
end





