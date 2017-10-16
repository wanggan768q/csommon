ActionController = class("ActionController",BaseController)

function ActionController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActionController.new(ActionModel:getInstance())
	end 
	return self.instance
end

function ActionController:ctor(model)
	ActionController.super.ctor(self,model)
	
	

end

function ActionController:modelDataUpdate( syncId, idx )

end










