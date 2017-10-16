AchievementController = class("AchievementController",BaseController)

function AchievementController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=AchievementController.new(AchievementModel:getInstance())
	end 
	return self.instance
end

function AchievementController:ctor(model)
	AchievementController.super.ctor(self,model)
	
	

end

function AchievementController:modelDataUpdate( syncId, idx )

end










