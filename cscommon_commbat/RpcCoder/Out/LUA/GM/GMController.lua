GMController = class("GMController",BaseController)

function GMController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=GMController.new(GMModel:getInstance())
	end 
	return self.instance
end

function GMController:ctor(model)
	GMController.super.ctor(self,model)
	
	

end

function GMController:modelDataUpdate( syncId, idx )

end










