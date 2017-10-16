MailController = class("MailController",BaseController)

function MailController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MailController.new(MailModel:getInstance())
	end 
	return self.instance
end

function MailController:ctor(model)
	MailController.super.ctor(self,model)
	
	
	self.model:registerNewMailCBNotify(handler(self,self.NewMailCBNotify))

end

function MailController:modelDataUpdate( syncId, idx )

end





function MailController:NewMailCBNotify(ret_msg)
end





