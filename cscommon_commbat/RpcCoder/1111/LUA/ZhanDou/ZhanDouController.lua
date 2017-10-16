ZhanDouController = class("ZhanDouController",BaseController)

function ZhanDouController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ZhanDouController.new(ZhanDouModel:getInstance())
	end 
	return self.instance
end

function ZhanDouController:ctor(model)
	ZhanDouController.super.ctor(self,model)
	
	
	self.model:registerTalkCBNotify(handler(self,self.TalkCBNotify))

end

function ZhanDouController:modelDataUpdate( syncId, idx )

end





function ZhanDouController:TalkCBNotify(ret_msg)
end





