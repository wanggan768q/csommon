--将变量写入下方
local ModuleId = 9;
local RPC_CODE_FIGHT_READY_REQUEST = 951
local RPC_CODE_FIGHT_ACTION_NOTIFY = 952;
local RPC_CODE_FIGHT_RESULT_NOTIFY = 953;
local RPC_CODE_FIGHT_ENTER_REQUEST = 954
local RPC_CODE_FIGHT_START_NOTIFY = 955;





require("app.Fight.FightRpc_pb")

FightModel = class("FightModel",BaseModel)

function FightModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=FightModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function FightModel:ctor()
	FightModel.super.ctor(self)
	self.rpc_pb = FightRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_ACTION_NOTIFY,handler(self,self.ActionCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_RESULT_NOTIFY,handler(self,self.ResultCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_FIGHT_START_NOTIFY,handler(self,self.StartCB))

  


end

-- 更新数据
function FightModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function FightModel:Ready(_hanlder)
	local PB = self.rpc_pb.FightRpcReadyAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FightRpcReadyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FIGHT_READY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FightModel:Enter(UserId,DungeonKey,SessionKey,_hanlder)
	local PB = self.rpc_pb.FightRpcEnterAsk()
	PB.UserId = UserId
	PB.DungeonKey = DungeonKey
	PB.SessionKey = SessionKey
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FightRpcEnterReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FIGHT_ENTER_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function FightModel:registerActionCBNotify(_hanlder)
	if not self.ActionCBNotifyCallBack then
		self.ActionCBNotifyCallBack = {}
	end
	table.insert(self.ActionCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function FightModel:ActionCB(notifyMsg)
	if self.ActionCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcActionNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ActionCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function FightModel:unregisterActionCBNotify(_hanlder)
	if nil ~= self.ActionCBNotifyCallBack then
		for i,callback in ipairs(self.ActionCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ActionCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function FightModel:ActionNotify(DataFrame)
	local PB = self.rpc_pb.FightRpcActionNotify()
	PB.Data = Data
	PB.Frame = Frame
	local pb_data = PB:SerializeToString()
	MLayerMgr.SendNotify(RPC_CODE_FIGHT_ACTION_NOTIFY, pb_data)
end
-- 给c层 注册服务器通知回调
function FightModel:registerResultCBNotify(_hanlder)
	if not self.ResultCBNotifyCallBack then
		self.ResultCBNotifyCallBack = {}
	end
	table.insert(self.ResultCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function FightModel:ResultCB(notifyMsg)
	if self.ResultCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcResultNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ResultCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function FightModel:unregisterResultCBNotify(_hanlder)
	if nil ~= self.ResultCBNotifyCallBack then
		for i,callback in ipairs(self.ResultCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ResultCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function FightModel:registerStartCBNotify(_hanlder)
	if not self.StartCBNotifyCallBack then
		self.StartCBNotifyCallBack = {}
	end
	table.insert(self.StartCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function FightModel:StartCB(notifyMsg)
	if self.StartCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FightRpcStartNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.StartCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function FightModel:unregisterStartCBNotify(_hanlder)
	if nil ~= self.StartCBNotifyCallBack then
		for i,callback in ipairs(self.StartCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.StartCBNotifyCallBack, i )
			end
		end
	end
end





askList.Fight = {}

local t = {}
t.name = "Ready"
t.para = {}
t.hand = FightModel.Ready
t.pb = FightRpc_pb.FightRpcReadyAsk()
table.insert(askList.Fight,t)

local t = {}
t.name = "Enter"
t.para = {{name="UserId",t=1},{name="DungeonKey",t=2},{name="SessionKey",t=2}}
t.hand = FightModel.Enter
t.pb = FightRpc_pb.FightRpcEnterAsk()
table.insert(askList.Fight,t)

