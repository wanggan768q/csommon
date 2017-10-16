DungeonController = class("DungeonController",BaseController)

function DungeonController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=DungeonController.new(DungeonModel:getInstance())
	end 
	return self.instance
end

function DungeonController:ctor(model)
	DungeonController.super.ctor(self,model)
	
	
	self.model:registerOpenCBNotify(handler(self,self.OpenCBNotify))
	self.model:registerTransferCBNotify(handler(self,self.TransferCBNotify))

end

function DungeonController:modelDataUpdate( syncId, idx )

end





function DungeonController:OpenCBNotify(ret_msg)
end
function DungeonController:TransferCBNotify(ret_msg)
end





