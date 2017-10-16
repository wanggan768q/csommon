OnlineDataController = class("OnlineDataController",BaseController)

function OnlineDataController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=OnlineDataController.new(OnlineDataModel:getInstance())
	end 
	return self.instance
end

function OnlineDataController:ctor(model)
	OnlineDataController.super.ctor(self,model)
	
	

end

function OnlineDataController:modelDataUpdate( syncId, idx )

end










