BagController = class("BagController",BaseController)

function BagController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=BagController.new(BagModel:getInstance())
	end 
	return self.instance
end

function BagController:ctor(model)
	BagController.super.ctor(self,model)
	
	
	self.model:registerBagAddNewItemCBNotify(handler(self,self.BagAddNewItemCBNotify))
	self.model:registerGetNewItemCBNotify(handler(self,self.GetNewItemCBNotify))
	self.model:registerBagErrorCBNotify(handler(self,self.BagErrorCBNotify))
	self.model:registerTalismanAttrChangeCBNotify(handler(self,self.TalismanAttrChangeCBNotify))

end

function BagController:modelDataUpdate( syncId, idx )

end





function BagController:BagAddNewItemCBNotify(ret_msg)
end
function BagController:GetNewItemCBNotify(ret_msg)
end
function BagController:BagErrorCBNotify(ret_msg)
end
function BagController:TalismanAttrChangeCBNotify(ret_msg)
end





