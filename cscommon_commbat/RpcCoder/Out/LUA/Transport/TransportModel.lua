--将变量写入下方
local ModuleId = 40;
local RPC_CODE_TRANSPORT_SYNCDATA_REQUEST = 4051
local RPC_CODE_TRANSPORT_FILL_REQUEST = 4052
local RPC_CODE_TRANSPORT_HELPOTHER_REQUEST = 4053
local RPC_CODE_TRANSPORT_ASKHELP_REQUEST = 4054
local RPC_CODE_TRANSPORT_SETSAIL_REQUEST = 4055
local RPC_CODE_TRANSPORT_ADDTRANSPORT_REQUEST = 4056
local RPC_CODE_TRANSPORT_ISHELPED_NOTIFY = 4057;


TRANSPORT_GOODSARRAY = 4001
TRANSPORT_ASKNUM = 4002
TRANSPORT_HELPNUM = 4003
TRANSPORT_REWARDARRY = 4004
TRANSPORT_REWARDFLAG = 4006
TRANSPORT_PICKTASKFLAG = 4007


require("app.Transport.TransportV1Data_pb")
require("app.Transport.TransportRpc_pb")

TransportModel = class("TransportModel",BaseModel)

function TransportModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TransportModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function TransportModel:ctor()
	TransportModel.super.ctor(self)
	self.rpc_pb = TransportRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_TRANSPORT_ISHELPED_NOTIFY,handler(self,self.IsHelpedCB))

  
	self.data_pb=TransportV1Data_pb
	self.m_GoodsArray = {}
	self.m_AskNum = 0
	self.m_HelpNum = 0
	self.m_RewardArry = {}
	self.m_RewardFlag = TransportV1Data_pb.TransportboolV1()
	self.m_PickTaskFlag = TransportV1Data_pb.TransportboolV1()


end

-- 更新数据
function TransportModel:UpdateField(Id, data, Index, len)
	if  Id == TRANSPORT_GOODSARRAY then
		if Index < 0 then
			self.m_GoodsArray = {}
		else
			if self.m_GoodsArray[Index] == nil then
				self.m_GoodsArray[Index] = TransportV1Data_pb.TransportGoodsObjV1()
			end
			self.m_GoodsArray[Index]:ParseFromString(data)
		end
	elseif  Id == TRANSPORT_ASKNUM then
		local num = ReadVarint32(data)
		self.m_AskNum = num
	elseif  Id == TRANSPORT_HELPNUM then
		local num = ReadVarint32(data)
		self.m_HelpNum = num
	elseif  Id == TRANSPORT_REWARDARRY then
		if Index < 0 then
			self.m_RewardArry = {}
		else
			if self.m_RewardArry[Index] == nil then
				self.m_RewardArry[Index] = TransportV1Data_pb.TransportRewardObjV1()
			end
			self.m_RewardArry[Index]:ParseFromString(data)
		end
	elseif  Id == TRANSPORT_REWARDFLAG then
		self.m_RewardFlag:ParseFromString(data)
	elseif  Id == TRANSPORT_PICKTASKFLAG then
		self.m_PickTaskFlag:ParseFromString(data)
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function TransportModel:SyncData(_hanlder)
	local PB = self.rpc_pb.TransportRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.TransportRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TRANSPORT_SYNCDATA_REQUEST, pb_data, callback)
end
function TransportModel:Fill(FillID,_hanlder)
	local PB = self.rpc_pb.TransportRpcFillAsk()
	PB.FillID = FillID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TransportRpcFillReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TRANSPORT_FILL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TransportModel:HelpOther(ItemID,UserId,_hanlder)
	local PB = self.rpc_pb.TransportRpcHelpOtherAsk()
	PB.ItemID = ItemID
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TransportRpcHelpOtherReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TRANSPORT_HELPOTHER_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TransportModel:AskHelp(ItemID,_hanlder)
	local PB = self.rpc_pb.TransportRpcAskHelpAsk()
	PB.ItemID = ItemID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TransportRpcAskHelpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TRANSPORT_ASKHELP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TransportModel:SetSail(_hanlder)
	local PB = self.rpc_pb.TransportRpcSetSailAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TransportRpcSetSailReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TRANSPORT_SETSAIL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TransportModel:AddTransport(Lv,_hanlder)
	local PB = self.rpc_pb.TransportRpcAddTransportAsk()
	PB.Lv = Lv
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TransportRpcAddTransportReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TRANSPORT_ADDTRANSPORT_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function TransportModel:registerIsHelpedCBNotify(_hanlder)
	if not self.IsHelpedCBNotifyCallBack then
		self.IsHelpedCBNotifyCallBack = {}
	end
	table.insert(self.IsHelpedCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TransportModel:IsHelpedCB(notifyMsg)
	if self.IsHelpedCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TransportRpcIsHelpedNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.IsHelpedCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TransportModel:unregisterIsHelpedCBNotify(_hanlder)
	if nil ~= self.IsHelpedCBNotifyCallBack then
		for i,callback in ipairs(self.IsHelpedCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.IsHelpedCBNotifyCallBack, i )
			end
		end
	end
end





askList.Transport = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = TransportModel.SyncData
t.pb = TransportRpc_pb.TransportRpcSyncDataAsk()
table.insert(askList.Transport,t)

local t = {}
t.name = "Fill"
t.para = {{name="FillID",t=1}}
t.hand = TransportModel.Fill
t.pb = TransportRpc_pb.TransportRpcFillAsk()
table.insert(askList.Transport,t)

local t = {}
t.name = "HelpOther"
t.para = {{name="ItemID",t=1},{name="UserId",t=1}}
t.hand = TransportModel.HelpOther
t.pb = TransportRpc_pb.TransportRpcHelpOtherAsk()
table.insert(askList.Transport,t)

local t = {}
t.name = "AskHelp"
t.para = {{name="ItemID",t=1}}
t.hand = TransportModel.AskHelp
t.pb = TransportRpc_pb.TransportRpcAskHelpAsk()
table.insert(askList.Transport,t)

local t = {}
t.name = "SetSail"
t.para = {}
t.hand = TransportModel.SetSail
t.pb = TransportRpc_pb.TransportRpcSetSailAsk()
table.insert(askList.Transport,t)

local t = {}
t.name = "AddTransport"
t.para = {{name="Lv",t=1}}
t.hand = TransportModel.AddTransport
t.pb = TransportRpc_pb.TransportRpcAddTransportAsk()
table.insert(askList.Transport,t)

