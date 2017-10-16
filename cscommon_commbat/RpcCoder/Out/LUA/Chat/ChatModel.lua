--将变量写入下方
local ModuleId = 36;
local RPC_CODE_CHAT_SENDCHAT_REQUEST = 3651
local RPC_CODE_CHAT_SYNCCHAT_NOTIFY = 3652;
local RPC_CODE_CHAT_SYNCPRIVATECHATMSG_NOTIFY = 3653;
local RPC_CODE_CHAT_SVRCHAT_NOTIFY = 3654;





require("app.Chat.ChatRpc_pb")

ChatModel = class("ChatModel",BaseModel)

function ChatModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ChatModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ChatModel:ctor()
	ChatModel.super.ctor(self)
	self.rpc_pb = ChatRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_SYNCCHAT_NOTIFY,handler(self,self.SyncChatCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_SYNCPRIVATECHATMSG_NOTIFY,handler(self,self.SyncPrivateChatMsgCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_CHAT_SVRCHAT_NOTIFY,handler(self,self.SvrChatCB))

  


end

-- 更新数据
function ChatModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function ChatModel:SendChat(ChatMsg,_hanlder)
	local PB = self.rpc_pb.ChatRpcSendChatAsk()
	PB.ChatMsg = ChatMsg
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ChatRpcSendChatReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_CHAT_SENDCHAT_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function ChatModel:registerSyncChatCBNotify(_hanlder)
	if not self.SyncChatCBNotifyCallBack then
		self.SyncChatCBNotifyCallBack = {}
	end
	table.insert(self.SyncChatCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChatModel:SyncChatCB(notifyMsg)
	if self.SyncChatCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ChatRpcSyncChatNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncChatCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ChatModel:unregisterSyncChatCBNotify(_hanlder)
	if nil ~= self.SyncChatCBNotifyCallBack then
		for i,callback in ipairs(self.SyncChatCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncChatCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ChatModel:registerSyncPrivateChatMsgCBNotify(_hanlder)
	if not self.SyncPrivateChatMsgCBNotifyCallBack then
		self.SyncPrivateChatMsgCBNotifyCallBack = {}
	end
	table.insert(self.SyncPrivateChatMsgCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChatModel:SyncPrivateChatMsgCB(notifyMsg)
	if self.SyncPrivateChatMsgCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ChatRpcSyncPrivateChatMsgNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SyncPrivateChatMsgCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ChatModel:unregisterSyncPrivateChatMsgCBNotify(_hanlder)
	if nil ~= self.SyncPrivateChatMsgCBNotifyCallBack then
		for i,callback in ipairs(self.SyncPrivateChatMsgCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SyncPrivateChatMsgCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ChatModel:registerSvrChatCBNotify(_hanlder)
	if not self.SvrChatCBNotifyCallBack then
		self.SvrChatCBNotifyCallBack = {}
	end
	table.insert(self.SvrChatCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ChatModel:SvrChatCB(notifyMsg)
	if self.SvrChatCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ChatRpcSvrChatNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SvrChatCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ChatModel:unregisterSvrChatCBNotify(_hanlder)
	if nil ~= self.SvrChatCBNotifyCallBack then
		for i,callback in ipairs(self.SvrChatCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SvrChatCBNotifyCallBack, i )
			end
		end
	end
end





askList.Chat = {}

local t = {}
t.name = "SendChat"
t.para = {{name="ChatMsg",t=3}}
t.hand = ChatModel.SendChat
t.pb = ChatRpc_pb.ChatRpcSendChatAsk()
table.insert(askList.Chat,t)

