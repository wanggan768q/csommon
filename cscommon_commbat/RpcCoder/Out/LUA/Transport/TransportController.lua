TransportController = class("TransportController",BaseController)

function TransportController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TransportController.new(TransportModel:getInstance())
	end 
	return self.instance
end

function TransportController:ctor(model)
	TransportController.super.ctor(self,model)
	
	
	self.model:registerIsHelpedCBNotify(handler(self,self.IsHelpedCBNotify))

end

function TransportController:modelDataUpdate( syncId, idx )

end





function TransportController:IsHelpedCBNotify(ret_msg)
end





