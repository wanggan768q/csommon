ActivityStormController = class("ActivityStormController",BaseController)

function ActivityStormController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityStormController.new(ActivityStormModel:getInstance())
	end 
	return self.instance
end

function ActivityStormController:ctor(model)
	ActivityStormController.super.ctor(self,model)
	
	
	self.model:registerBattlefieldMessageCBNotify(handler(self,self.BattlefieldMessageCBNotify))
	self.model:registerTimeOutMessageCBNotify(handler(self,self.TimeOutMessageCBNotify))
	self.model:registerJoinLevevNotifyCBNotify(handler(self,self.JoinLevevNotifyCBNotify))
	self.model:registerResetSignUpNotifyCBNotify(handler(self,self.ResetSignUpNotifyCBNotify))

end

function ActivityStormController:modelDataUpdate( syncId, idx )

end





function ActivityStormController:BattlefieldMessageCBNotify(ret_msg)
end
function ActivityStormController:TimeOutMessageCBNotify(ret_msg)
end
function ActivityStormController:JoinLevevNotifyCBNotify(ret_msg)
end
function ActivityStormController:ResetSignUpNotifyCBNotify(ret_msg)
end





