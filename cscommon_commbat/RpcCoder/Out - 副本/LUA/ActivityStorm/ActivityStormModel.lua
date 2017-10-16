--将变量写入下方
local ModuleId = 30;
local RPC_CODE_ACTIVITYSTORM_SIGNUP_REQUEST = 3051
local RPC_CODE_ACTIVITYSTORM_CANCELSIGNUP_REQUEST = 3052
local RPC_CODE_ACTIVITYSTORM_INSERTBATTLEFIELD_REQUEST = 3053
local RPC_CODE_ACTIVITYSTORM_BATTLEFIELDMESSAGE_NOTIFY = 3054;
local RPC_CODE_ACTIVITYSTORM_TIMEOUTMESSAGE_NOTIFY = 3055;
local RPC_CODE_ACTIVITYSTORM_SYNCDATA_REQUEST = 3056
local RPC_CODE_ACTIVITYSTORM_JOINLEVEVNOTIFY_NOTIFY = 3057;
local RPC_CODE_ACTIVITYSTORM_CANCEINSERTBATTLE_REQUEST = 3058
local RPC_CODE_ACTIVITYSTORM_RESETSIGNUPNOTIFY_NOTIFY = 3059;





require("app.ActivityStorm.ActivityStormRpc_pb")

ActivityStormModel = class("ActivityStormModel",BaseModel)

function ActivityStormModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityStormModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ActivityStormModel:ctor()
	ActivityStormModel.super.ctor(self)
	self.rpc_pb = ActivityStormRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITYSTORM_BATTLEFIELDMESSAGE_NOTIFY,handler(self,self.BattlefieldMessageCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITYSTORM_TIMEOUTMESSAGE_NOTIFY,handler(self,self.TimeOutMessageCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITYSTORM_JOINLEVEVNOTIFY_NOTIFY,handler(self,self.JoinLevevNotifyCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITYSTORM_RESETSIGNUPNOTIFY_NOTIFY,handler(self,self.ResetSignUpNotifyCB))

  


end

-- 更新数据
function ActivityStormModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function ActivityStormModel:SignUp(_hanlder)
	local PB = self.rpc_pb.ActivityStormRpcSignUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityStormRpcSignUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSTORM_SIGNUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function ActivityStormModel:CancelSignUp(_hanlder)
	local PB = self.rpc_pb.ActivityStormRpcCancelSignUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityStormRpcCancelSignUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSTORM_CANCELSIGNUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function ActivityStormModel:InsertBattlefield(_hanlder)
	local PB = self.rpc_pb.ActivityStormRpcInsertBattlefieldAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityStormRpcInsertBattlefieldReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSTORM_INSERTBATTLEFIELD_REQUEST, pb_data, callback)
	self:showNetTip()
end
function ActivityStormModel:SyncData(_hanlder)
	local PB = self.rpc_pb.ActivityStormRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityStormRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSTORM_SYNCDATA_REQUEST, pb_data, callback)
end
function ActivityStormModel:CanceInsertBattle(_hanlder)
	local PB = self.rpc_pb.ActivityStormRpcCanceInsertBattleAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityStormRpcCanceInsertBattleReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSTORM_CANCEINSERTBATTLE_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function ActivityStormModel:registerBattlefieldMessageCBNotify(_hanlder)
	if not self.BattlefieldMessageCBNotifyCallBack then
		self.BattlefieldMessageCBNotifyCallBack = {}
	end
	table.insert(self.BattlefieldMessageCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityStormModel:BattlefieldMessageCB(notifyMsg)
	if self.BattlefieldMessageCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityStormRpcBattlefieldMessageNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BattlefieldMessageCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ActivityStormModel:unregisterBattlefieldMessageCBNotify(_hanlder)
	if nil ~= self.BattlefieldMessageCBNotifyCallBack then
		for i,callback in ipairs(self.BattlefieldMessageCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BattlefieldMessageCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ActivityStormModel:registerTimeOutMessageCBNotify(_hanlder)
	if not self.TimeOutMessageCBNotifyCallBack then
		self.TimeOutMessageCBNotifyCallBack = {}
	end
	table.insert(self.TimeOutMessageCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityStormModel:TimeOutMessageCB(notifyMsg)
	if self.TimeOutMessageCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityStormRpcTimeOutMessageNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TimeOutMessageCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ActivityStormModel:unregisterTimeOutMessageCBNotify(_hanlder)
	if nil ~= self.TimeOutMessageCBNotifyCallBack then
		for i,callback in ipairs(self.TimeOutMessageCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TimeOutMessageCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ActivityStormModel:registerJoinLevevNotifyCBNotify(_hanlder)
	if not self.JoinLevevNotifyCBNotifyCallBack then
		self.JoinLevevNotifyCBNotifyCallBack = {}
	end
	table.insert(self.JoinLevevNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityStormModel:JoinLevevNotifyCB(notifyMsg)
	if self.JoinLevevNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityStormRpcJoinLevevNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.JoinLevevNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ActivityStormModel:unregisterJoinLevevNotifyCBNotify(_hanlder)
	if nil ~= self.JoinLevevNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.JoinLevevNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.JoinLevevNotifyCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ActivityStormModel:registerResetSignUpNotifyCBNotify(_hanlder)
	if not self.ResetSignUpNotifyCBNotifyCallBack then
		self.ResetSignUpNotifyCBNotifyCallBack = {}
	end
	table.insert(self.ResetSignUpNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityStormModel:ResetSignUpNotifyCB(notifyMsg)
	if self.ResetSignUpNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityStormRpcResetSignUpNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ResetSignUpNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ActivityStormModel:unregisterResetSignUpNotifyCBNotify(_hanlder)
	if nil ~= self.ResetSignUpNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.ResetSignUpNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ResetSignUpNotifyCBNotifyCallBack, i )
			end
		end
	end
end





askList.ActivityStorm = {}

local t = {}
t.name = "SignUp"
t.para = {}
t.hand = ActivityStormModel.SignUp
t.pb = ActivityStormRpc_pb.ActivityStormRpcSignUpAsk()
table.insert(askList.ActivityStorm,t)

local t = {}
t.name = "CancelSignUp"
t.para = {}
t.hand = ActivityStormModel.CancelSignUp
t.pb = ActivityStormRpc_pb.ActivityStormRpcCancelSignUpAsk()
table.insert(askList.ActivityStorm,t)

local t = {}
t.name = "InsertBattlefield"
t.para = {}
t.hand = ActivityStormModel.InsertBattlefield
t.pb = ActivityStormRpc_pb.ActivityStormRpcInsertBattlefieldAsk()
table.insert(askList.ActivityStorm,t)

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = ActivityStormModel.SyncData
t.pb = ActivityStormRpc_pb.ActivityStormRpcSyncDataAsk()
table.insert(askList.ActivityStorm,t)

local t = {}
t.name = "CanceInsertBattle"
t.para = {}
t.hand = ActivityStormModel.CanceInsertBattle
t.pb = ActivityStormRpc_pb.ActivityStormRpcCanceInsertBattleAsk()
table.insert(askList.ActivityStorm,t)

