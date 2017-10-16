RefreshDataController = class("RefreshDataController",BaseController)

function RefreshDataController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=RefreshDataController.new(RefreshDataModel:getInstance())
	end 
	return self.instance
end

function RefreshDataController:ctor(model)
	RefreshDataController.super.ctor(self,model)
	
	

end

function RefreshDataController:modelDataUpdate( syncId, idx )

end










