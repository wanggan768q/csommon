ActivityScheduleController = class("ActivityScheduleController",BaseController)

function ActivityScheduleController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityScheduleController.new(ActivityScheduleModel:getInstance())
	end 
	return self.instance
end

function ActivityScheduleController:ctor(model)
	ActivityScheduleController.super.ctor(self,model)
	
	
	self.model:registerThiefBeOpenedCBNotify(handler(self,self.ThiefBeOpenedCBNotify))
	self.model:registerThiefRefreshCBNotify(handler(self,self.ThiefRefreshCBNotify))
	self.model:registerSubdueMonsterBeOpenedCBNotify(handler(self,self.SubdueMonsterBeOpenedCBNotify))
	self.model:registerSubdueMonsterRefreshCBNotify(handler(self,self.SubdueMonsterRefreshCBNotify))

end

function ActivityScheduleController:modelDataUpdate( syncId, idx )

end





function ActivityScheduleController:ThiefBeOpenedCBNotify(ret_msg)
end
function ActivityScheduleController:ThiefRefreshCBNotify(ret_msg)
end
function ActivityScheduleController:SubdueMonsterBeOpenedCBNotify(ret_msg)
end
function ActivityScheduleController:SubdueMonsterRefreshCBNotify(ret_msg)
end





