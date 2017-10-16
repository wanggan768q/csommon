OneVSOneController = class("OneVSOneController",BaseController)

function OneVSOneController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=OneVSOneController.new(OneVSOneModel:getInstance())
	end 
	return self.instance
end

function OneVSOneController:ctor(model)
	OneVSOneController.super.ctor(self,model)
	
	
	self.model:registerActMessageCBNotify(handler(self,self.ActMessageCBNotify))
	self.model:registerACTResultNotifyCBNotify(handler(self,self.ACTResultNotifyCBNotify))

end

function OneVSOneController:modelDataUpdate( syncId, idx )

end





function OneVSOneController:ActMessageCBNotify(ret_msg)
end
function OneVSOneController:ACTResultNotifyCBNotify(ret_msg)
end





