ShopController = class("ShopController",BaseController)

function ShopController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ShopController.new(ShopModel:getInstance())
	end 
	return self.instance
end

function ShopController:ctor(model)
	ShopController.super.ctor(self,model)
	
	

end

function ShopController:modelDataUpdate( syncId, idx )

end










