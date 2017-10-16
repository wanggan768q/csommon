ActivityEscapeController = class("ActivityEscapeController",BaseController)

function ActivityEscapeController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityEscapeController.new(ActivityEscapeModel:getInstance())
	end 
	return self.instance
end

function ActivityEscapeController:ctor(model)
	ActivityEscapeController.super.ctor(self,model)
	
	

end

function ActivityEscapeController:modelDataUpdate( syncId, idx )

end










