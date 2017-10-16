DropItemController = class("DropItemController",BaseController)

function DropItemController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=DropItemController.new(DropItemModel:getInstance())
	end 
	return self.instance
end

function DropItemController:ctor(model)
	DropItemController.super.ctor(self,model)
	
	
	self.model:registerDropItemNoticeCBNotify(handler(self,self.DropItemNoticeCBNotify))
	self.model:registerDelDropItemCBNotify(handler(self,self.DelDropItemCBNotify))

end

function DropItemController:modelDataUpdate( syncId, idx )

end





function DropItemController:DropItemNoticeCBNotify(ret_msg)
end
function DropItemController:DelDropItemCBNotify(ret_msg)
end





