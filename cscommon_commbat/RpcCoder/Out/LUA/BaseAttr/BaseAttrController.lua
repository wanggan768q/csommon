BaseAttrController = class("BaseAttrController",BaseController)

function BaseAttrController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=BaseAttrController.new(BaseAttrModel:getInstance())
	end 
	return self.instance
end

function BaseAttrController:ctor(model)
	BaseAttrController.super.ctor(self,model)
	
	
	self.model:registerSysTipsCBNotify(handler(self,self.SysTipsCBNotify))

end

function BaseAttrController:modelDataUpdate( syncId, idx )

end





function BaseAttrController:SysTipsCBNotify(ret_msg)
end





