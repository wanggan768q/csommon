MMOMapDataController = class("MMOMapDataController",BaseController)

function MMOMapDataController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MMOMapDataController.new(MMOMapDataModel:getInstance())
	end 
	return self.instance
end

function MMOMapDataController:ctor(model)
	MMOMapDataController.super.ctor(self,model)
	
	

end

function MMOMapDataController:modelDataUpdate( syncId, idx )

end










