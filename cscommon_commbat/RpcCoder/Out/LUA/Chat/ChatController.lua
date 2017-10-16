ChatController = class("ChatController",BaseController)

function ChatController:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ChatController.new(ChatModel:getInstance())
	end 
	return self.instance
end

function ChatController:ctor(model)
	ChatController.super.ctor(self,model)
	
	
	self.model:registerSyncChatCBNotify(handler(self,self.SyncChatCBNotify))
	self.model:registerSyncPrivateChatMsgCBNotify(handler(self,self.SyncPrivateChatMsgCBNotify))
	self.model:registerSvrChatCBNotify(handler(self,self.SvrChatCBNotify))

end

function ChatController:modelDataUpdate( syncId, idx )

end





function ChatController:SyncChatCBNotify(ret_msg)
end
function ChatController:SyncPrivateChatMsgCBNotify(ret_msg)
end
function ChatController:SvrChatCBNotify(ret_msg)
end





