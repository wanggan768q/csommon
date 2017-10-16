FightController = class("FightController",BaseController)

function FightController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=FightController.new(FightModel:getInstance())
	end 
	return self.instance
end

function FightController:ctor(model)
	FightController.super.ctor(self,model)
	
	
	self.model:registerActionCBNotify(handler(self,self.ActionCBNotify))
	self.model:registerResultCBNotify(handler(self,self.ResultCBNotify))
	self.model:registerStartCBNotify(handler(self,self.StartCBNotify))

end

function FightController:modelDataUpdate( syncId, idx )

end





function FightController:ActionCBNotify(ret_msg)
end
function FightController:ResultCBNotify(ret_msg)
end
function FightController:StartCBNotify(ret_msg)
end





