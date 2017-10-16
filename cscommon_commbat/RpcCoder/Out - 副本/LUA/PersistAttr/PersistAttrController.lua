PersistAttrController = class("PersistAttrController",BaseController)

function PersistAttrController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=PersistAttrController.new(PersistAttrModel:getInstance())
	end 
	return self.instance
end

function PersistAttrController:ctor(model)
	PersistAttrController.super.ctor(self,model)
	
	

end

function PersistAttrController:modelDataUpdate( syncId, idx )

end










