LoginController = class("LoginController",BaseController)

function LoginController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=LoginController.new(LoginModel:getInstance())
	end 
	return self.instance
end

function LoginController:ctor(model)
	LoginController.super.ctor(self,model)
	
	
	self.model:registerKickOffCBNotify(handler(self,self.KickOffCBNotify))

end

function LoginController:modelDataUpdate( syncId, idx )

end





function LoginController:KickOffCBNotify(ret_msg)
end





