TalismanController = class("TalismanController",BaseController)

function TalismanController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TalismanController.new(TalismanModel:getInstance())
	end 
	return self.instance
end

function TalismanController:ctor(model)
	TalismanController.super.ctor(self,model)
	
	

end

function TalismanController:modelDataUpdate( syncId, idx )

end










