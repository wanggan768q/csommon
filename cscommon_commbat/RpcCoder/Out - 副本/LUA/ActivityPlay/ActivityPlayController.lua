ActivityPlayController = class("ActivityPlayController",BaseController)

function ActivityPlayController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityPlayController.new(ActivityPlayModel:getInstance())
	end 
	return self.instance
end

function ActivityPlayController:ctor(model)
	ActivityPlayController.super.ctor(self,model)
	
	

end

function ActivityPlayController:modelDataUpdate( syncId, idx )

end










