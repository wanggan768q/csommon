StoryDungeonController = class("StoryDungeonController",BaseController)

function StoryDungeonController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=StoryDungeonController.new(StoryDungeonModel:getInstance())
	end 
	return self.instance
end

function StoryDungeonController:ctor(model)
	StoryDungeonController.super.ctor(self,model)
	
	
	self.model:registerWaitForConfirmationCBNotify(handler(self,self.WaitForConfirmationCBNotify))
	self.model:registerPlayerConfirmResultCBNotify(handler(self,self.PlayerConfirmResultCBNotify))

end

function StoryDungeonController:modelDataUpdate( syncId, idx )

end





function StoryDungeonController:WaitForConfirmationCBNotify(ret_msg)
end
function StoryDungeonController:PlayerConfirmResultCBNotify(ret_msg)
end





