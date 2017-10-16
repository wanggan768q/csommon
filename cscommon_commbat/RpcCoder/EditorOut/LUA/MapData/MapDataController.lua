MapDataController = class("MapDataController",BaseController)

function MapDataController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MapDataController.new(MapDataModel:getInstance())
	end 
	return self.instance
end

function MapDataController:ctor(model)
	MapDataController.super.ctor(self,model)
	
	

end

function MapDataController:modelDataUpdate( syncId, idx )

end










