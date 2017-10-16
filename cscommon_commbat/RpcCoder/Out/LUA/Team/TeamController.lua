TeamController = class("TeamController",BaseController)

function TeamController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TeamController.new(TeamModel:getInstance())
	end 
	return self.instance
end

function TeamController:ctor(model)
	TeamController.super.ctor(self,model)
	
	
	self.model:registerQuitTeamCBNotify(handler(self,self.QuitTeamCBNotify))
	self.model:registerBeInvitedNoticeCBNotify(handler(self,self.BeInvitedNoticeCBNotify))
	self.model:registerApplyNoticeCaptainCBNotify(handler(self,self.ApplyNoticeCaptainCBNotify))
	self.model:registerUpdateMyTeamNoticeCBNotify(handler(self,self.UpdateMyTeamNoticeCBNotify))
	self.model:registerLeaveTeamNoticeCBNotify(handler(self,self.LeaveTeamNoticeCBNotify))
	self.model:registerBreakUpNoticeCBNotify(handler(self,self.BreakUpNoticeCBNotify))
	self.model:registerReqMyTeamDataCBNotify(handler(self,self.ReqMyTeamDataCBNotify))
	self.model:registerDeleteFromApplyListCBNotify(handler(self,self.DeleteFromApplyListCBNotify))
	self.model:registerCaptainChangeNoticeCBNotify(handler(self,self.CaptainChangeNoticeCBNotify))
	self.model:registerTeamMemberHPChangeNoticeCBNotify(handler(self,self.TeamMemberHPChangeNoticeCBNotify))
	self.model:registerInviteHandleNoticeCBNotify(handler(self,self.InviteHandleNoticeCBNotify))
	self.model:registerBeingKickedNoticeCBNotify(handler(self,self.BeingKickedNoticeCBNotify))
	self.model:registerAddNewMemberNoticeCBNotify(handler(self,self.AddNewMemberNoticeCBNotify))

end

function TeamController:modelDataUpdate( syncId, idx )

end





function TeamController:QuitTeamCBNotify(ret_msg)
end
function TeamController:BeInvitedNoticeCBNotify(ret_msg)
end
function TeamController:ApplyNoticeCaptainCBNotify(ret_msg)
end
function TeamController:UpdateMyTeamNoticeCBNotify(ret_msg)
end
function TeamController:LeaveTeamNoticeCBNotify(ret_msg)
end
function TeamController:BreakUpNoticeCBNotify(ret_msg)
end
function TeamController:ReqMyTeamDataCBNotify(ret_msg)
end
function TeamController:DeleteFromApplyListCBNotify(ret_msg)
end
function TeamController:CaptainChangeNoticeCBNotify(ret_msg)
end
function TeamController:TeamMemberHPChangeNoticeCBNotify(ret_msg)
end
function TeamController:InviteHandleNoticeCBNotify(ret_msg)
end
function TeamController:BeingKickedNoticeCBNotify(ret_msg)
end
function TeamController:AddNewMemberNoticeCBNotify(ret_msg)
end





