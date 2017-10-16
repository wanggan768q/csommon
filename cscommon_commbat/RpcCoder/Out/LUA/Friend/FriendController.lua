FriendController = class("FriendController",BaseController)

function FriendController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=FriendController.new(FriendModel:getInstance())
	end 
	return self.instance
end

function FriendController:ctor(model)
	FriendController.super.ctor(self,model)
	
	
	self.model:registerFriendOnlineOfflineCBNotify(handler(self,self.FriendOnlineOfflineCBNotify))

end

function FriendController:modelDataUpdate( syncId, idx )

end





function FriendController:FriendOnlineOfflineCBNotify(ret_msg)
end





