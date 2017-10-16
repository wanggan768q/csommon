--将变量写入下方
local ModuleId = 44;
local RPC_CODE_MAIL_MAILHEAD_REQUEST = 4451
local RPC_CODE_MAIL_OPENMAIL_REQUEST = 4452
local RPC_CODE_MAIL_NEWMAIL_NOTIFY = 4453;
local RPC_CODE_MAIL_DELMAIL_REQUEST = 4454
local RPC_CODE_MAIL_GETREWARD_REQUEST = 4455
local RPC_CODE_MAIL_ONEKEYGETREWARD_REQUEST = 4456





require("app.Mail.MailRpc_pb")

MailModel = class("MailModel",BaseModel)

function MailModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MailModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function MailModel:ctor()
	MailModel.super.ctor(self)
	self.rpc_pb = MailRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_MAIL_NEWMAIL_NOTIFY,handler(self,self.NewMailCB))

  


end

-- 更新数据
function MailModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function MailModel:MailHead(Count,UId,_hanlder)
	local PB = self.rpc_pb.MailRpcMailHeadAsk()
	PB.Count = Count
	PB.UId = UId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcMailHeadReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_MAILHEAD_REQUEST, pb_data, callback)
	self:showNetTip()
end
function MailModel:OpenMail(UId,_hanlder)
	local PB = self.rpc_pb.MailRpcOpenMailAsk()
	PB.UId = UId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcOpenMailReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_OPENMAIL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function MailModel:DelMail(UidList,_hanlder)
	local PB = self.rpc_pb.MailRpcDelMailAsk()
	for i,v in ipairs(UidList) do
		table.insert(PB.UidList,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcDelMailReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_DELMAIL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function MailModel:GetReward(UId,_hanlder)
	local PB = self.rpc_pb.MailRpcGetRewardAsk()
	PB.UId = UId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcGetRewardReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_GETREWARD_REQUEST, pb_data, callback)
	self:showNetTip()
end
function MailModel:OneKeyGetReward(_hanlder)
	local PB = self.rpc_pb.MailRpcOneKeyGetRewardAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.MailRpcOneKeyGetRewardReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_MAIL_ONEKEYGETREWARD_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function MailModel:registerNewMailCBNotify(_hanlder)
	if not self.NewMailCBNotifyCallBack then
		self.NewMailCBNotifyCallBack = {}
	end
	table.insert(self.NewMailCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function MailModel:NewMailCB(notifyMsg)
	if self.NewMailCBNotifyCallBack then
		local ret_msg = self.rpc_pb.MailRpcNewMailNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.NewMailCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function MailModel:unregisterNewMailCBNotify(_hanlder)
	if nil ~= self.NewMailCBNotifyCallBack then
		for i,callback in ipairs(self.NewMailCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.NewMailCBNotifyCallBack, i )
			end
		end
	end
end





askList.Mail = {}

local t = {}
t.name = "MailHead"
t.para = {{name="Count",t=1},{name="UId",t=1}}
t.hand = MailModel.MailHead
t.pb = MailRpc_pb.MailRpcMailHeadAsk()
table.insert(askList.Mail,t)

local t = {}
t.name = "OpenMail"
t.para = {{name="UId",t=1}}
t.hand = MailModel.OpenMail
t.pb = MailRpc_pb.MailRpcOpenMailAsk()
table.insert(askList.Mail,t)

local t = {}
t.name = "DelMail"
t.para = {{name="UidList",t=1}}
t.hand = MailModel.DelMail
t.pb = MailRpc_pb.MailRpcDelMailAsk()
table.insert(askList.Mail,t)

local t = {}
t.name = "GetReward"
t.para = {{name="UId",t=1}}
t.hand = MailModel.GetReward
t.pb = MailRpc_pb.MailRpcGetRewardAsk()
table.insert(askList.Mail,t)

local t = {}
t.name = "OneKeyGetReward"
t.para = {}
t.hand = MailModel.OneKeyGetReward
t.pb = MailRpc_pb.MailRpcOneKeyGetRewardAsk()
table.insert(askList.Mail,t)

