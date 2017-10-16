--将变量写入下方
local ModuleId = 1;
local RPC_CODE_ZHANDOU_MOVE_REQUEST = 151
local RPC_CODE_ZHANDOU_TALK_NOTIFY = 152;




require("app.ZhanDou.ZhanDouV1Data_pb")
require("app.ZhanDou.ZhanDouRpc_pb")

ZhanDouModel = class("ZhanDouModel",BaseModel)

function ZhanDouModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ZhanDouModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ZhanDouModel:ctor()
	ZhanDouModel.super.ctor(self)
	self.rpc_pb = ZhanDouRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_ZHANDOU_TALK_NOTIFY,handler(self,self.TalkCB))

  
	self.data_pb=ZhanDouV1Data_pb


end

-- 更新数据
function ZhanDouModel:UpdateField(Id, data, Index, len)
	if
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function ZhanDouModel:Move(_hanlder)
	local PB = self.rpc_pb.ZhanDouRpcMoveAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ZhanDouRpcMoveReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ZHANDOU_MOVE_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function ZhanDouModel:registerTalkCBNotify(_hanlder)
	if not self.TalkCBNotifyCallBack then
		self.TalkCBNotifyCallBack = {}
	end
	table.insert(self.TalkCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ZhanDouModel:TalkCB(notifyMsg)
	if self.TalkCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ZhanDouRpcTalkNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TalkCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ZhanDouModel:unregisterTalkCBNotify(_hanlder)
	if nil ~= self.TalkCBNotifyCallBack then
		for i,callback in ipairs(self.TalkCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TalkCBNotifyCallBack, i )
			end
		end
	end
end





askList.ZhanDou = {}

local t = {}
t.name = "Move"
t.para = {}
t.hand = ZhanDouModel.Move
t.pb = ZhanDouRpc_pb.ZhanDouRpcMoveAsk()
table.insert(askList.ZhanDou,t)

