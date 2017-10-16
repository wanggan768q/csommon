--将变量写入下方
local ModuleId = 41;
local RPC_CODE_ONEVSONE_FLUSH_REQUEST = 4151
local RPC_CODE_ONEVSONE_ACT_REQUEST = 4152
local RPC_CODE_ONEVSONE_ACTMESSAGE_NOTIFY = 4153;
local RPC_CODE_ONEVSONE_REPLYACT_REQUEST = 4154
local RPC_CODE_ONEVSONE_GETTOP_REQUEST = 4155
local RPC_CODE_ONEVSONE_ADJUSTMENTSKILL_REQUEST = 4156
local RPC_CODE_ONEVSONE_GETSKILL_REQUEST = 4157
local RPC_CODE_ONEVSONE_GETACTMESSAGE_REQUEST = 4158
local RPC_CODE_ONEVSONE_ACTRESULTNOTIFY_NOTIFY = 4159;





require("app.OneVSOne.OneVSOneRpc_pb")

OneVSOneModel = class("OneVSOneModel",BaseModel)

function OneVSOneModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=OneVSOneModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function OneVSOneModel:ctor()
	OneVSOneModel.super.ctor(self)
	self.rpc_pb = OneVSOneRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_ONEVSONE_ACTMESSAGE_NOTIFY,handler(self,self.ActMessageCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ONEVSONE_ACTRESULTNOTIFY_NOTIFY,handler(self,self.ACTResultNotifyCB))

  


end

-- 更新数据
function OneVSOneModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function OneVSOneModel:Flush(IsOpen,_hanlder)
	local PB = self.rpc_pb.OneVSOneRpcFlushAsk()
	PB.IsOpen = IsOpen
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.OneVSOneRpcFlushReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ONEVSONE_FLUSH_REQUEST, pb_data, callback)
	self:showNetTip()
end
function OneVSOneModel:Act(UserId,Ranking,_hanlder)
	local PB = self.rpc_pb.OneVSOneRpcActAsk()
	PB.UserId = UserId
	PB.Ranking = Ranking
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.OneVSOneRpcActReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ONEVSONE_ACT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function OneVSOneModel:ReplyAct(UserId,IsOK,_hanlder)
	local PB = self.rpc_pb.OneVSOneRpcReplyActAsk()
	PB.UserId = UserId
	PB.IsOK = IsOK
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.OneVSOneRpcReplyActReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ONEVSONE_REPLYACT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function OneVSOneModel:GetTop(_hanlder)
	local PB = self.rpc_pb.OneVSOneRpcGetTopAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.OneVSOneRpcGetTopReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ONEVSONE_GETTOP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function OneVSOneModel:AdjustmentSkill(SkillDate,_hanlder)
	local PB = self.rpc_pb.OneVSOneRpcAdjustmentSkillAsk()
	for i,v in ipairs(SkillDate) do
		table.insert(PB.SkillDate,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.OneVSOneRpcAdjustmentSkillReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ONEVSONE_ADJUSTMENTSKILL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function OneVSOneModel:GetSkill(_hanlder)
	local PB = self.rpc_pb.OneVSOneRpcGetSkillAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.OneVSOneRpcGetSkillReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ONEVSONE_GETSKILL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function OneVSOneModel:GetActMessage(_hanlder)
	local PB = self.rpc_pb.OneVSOneRpcGetActMessageAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.OneVSOneRpcGetActMessageReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ONEVSONE_GETACTMESSAGE_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function OneVSOneModel:registerActMessageCBNotify(_hanlder)
	if not self.ActMessageCBNotifyCallBack then
		self.ActMessageCBNotifyCallBack = {}
	end
	table.insert(self.ActMessageCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function OneVSOneModel:ActMessageCB(notifyMsg)
	if self.ActMessageCBNotifyCallBack then
		local ret_msg = self.rpc_pb.OneVSOneRpcActMessageNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ActMessageCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function OneVSOneModel:unregisterActMessageCBNotify(_hanlder)
	if nil ~= self.ActMessageCBNotifyCallBack then
		for i,callback in ipairs(self.ActMessageCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ActMessageCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function OneVSOneModel:registerACTResultNotifyCBNotify(_hanlder)
	if not self.ACTResultNotifyCBNotifyCallBack then
		self.ACTResultNotifyCBNotifyCallBack = {}
	end
	table.insert(self.ACTResultNotifyCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function OneVSOneModel:ACTResultNotifyCB(notifyMsg)
	if self.ACTResultNotifyCBNotifyCallBack then
		local ret_msg = self.rpc_pb.OneVSOneRpcACTResultNotifyNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ACTResultNotifyCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function OneVSOneModel:unregisterACTResultNotifyCBNotify(_hanlder)
	if nil ~= self.ACTResultNotifyCBNotifyCallBack then
		for i,callback in ipairs(self.ACTResultNotifyCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ACTResultNotifyCBNotifyCallBack, i )
			end
		end
	end
end





askList.OneVSOne = {}

local t = {}
t.name = "Flush"
t.para = {{name="IsOpen",t=1}}
t.hand = OneVSOneModel.Flush
t.pb = OneVSOneRpc_pb.OneVSOneRpcFlushAsk()
table.insert(askList.OneVSOne,t)

local t = {}
t.name = "Act"
t.para = {{name="UserId",t=1},{name="Ranking",t=1}}
t.hand = OneVSOneModel.Act
t.pb = OneVSOneRpc_pb.OneVSOneRpcActAsk()
table.insert(askList.OneVSOne,t)

local t = {}
t.name = "ReplyAct"
t.para = {{name="UserId",t=1},{name="IsOK",t=1}}
t.hand = OneVSOneModel.ReplyAct
t.pb = OneVSOneRpc_pb.OneVSOneRpcReplyActAsk()
table.insert(askList.OneVSOne,t)

local t = {}
t.name = "GetTop"
t.para = {}
t.hand = OneVSOneModel.GetTop
t.pb = OneVSOneRpc_pb.OneVSOneRpcGetTopAsk()
table.insert(askList.OneVSOne,t)

local t = {}
t.name = "AdjustmentSkill"
t.para = {{name="SkillDate",t=3}}
t.hand = OneVSOneModel.AdjustmentSkill
t.pb = OneVSOneRpc_pb.OneVSOneRpcAdjustmentSkillAsk()
table.insert(askList.OneVSOne,t)

local t = {}
t.name = "GetSkill"
t.para = {}
t.hand = OneVSOneModel.GetSkill
t.pb = OneVSOneRpc_pb.OneVSOneRpcGetSkillAsk()
table.insert(askList.OneVSOne,t)

local t = {}
t.name = "GetActMessage"
t.para = {}
t.hand = OneVSOneModel.GetActMessage
t.pb = OneVSOneRpc_pb.OneVSOneRpcGetActMessageAsk()
table.insert(askList.OneVSOne,t)

