--将变量写入下方
local ModuleId = 43;
local RPC_CODE_STORYDUNGEON_SYNCDATA_REQUEST = 4351
local RPC_CODE_STORYDUNGEON_CHALLENGE_REQUEST = 4352
local RPC_CODE_STORYDUNGEON_WAITFORCONFIRMATION_NOTIFY = 4353;
local RPC_CODE_STORYDUNGEON_CONFIRMENTER_REQUEST = 4354
local RPC_CODE_STORYDUNGEON_PLAYERCONFIRMRESULT_NOTIFY = 4355;


STORYDUNGEON_STORYDUNGEON = 4301
STORYDUNGEON_CHALLENGENUM = 4302


require("app.StoryDungeon.StoryDungeonV1Data_pb")
require("app.StoryDungeon.StoryDungeonRpc_pb")

StoryDungeonModel = class("StoryDungeonModel",BaseModel)

function StoryDungeonModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=StoryDungeonModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function StoryDungeonModel:ctor()
	StoryDungeonModel.super.ctor(self)
	self.rpc_pb = StoryDungeonRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_STORYDUNGEON_WAITFORCONFIRMATION_NOTIFY,handler(self,self.WaitForConfirmationCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_STORYDUNGEON_PLAYERCONFIRMRESULT_NOTIFY,handler(self,self.PlayerConfirmResultCB))

  
	self.data_pb=StoryDungeonV1Data_pb
	self.m_StoryDungeon = {}
	self.m_ChallengeNum = 0


end

-- 更新数据
function StoryDungeonModel:UpdateField(Id, data, Index, len)
	if  Id == STORYDUNGEON_STORYDUNGEON then
		if Index < 0 then
			self.m_StoryDungeon = {}
		else
			if self.m_StoryDungeon[Index] == nil then
				self.m_StoryDungeon[Index] = StoryDungeonV1Data_pb.StoryDungeonStoryDungeonObjV1()
			end
			self.m_StoryDungeon[Index]:ParseFromString(data)
		end
	elseif  Id == STORYDUNGEON_CHALLENGENUM then
		local num = ReadVarint32(data)
		self.m_ChallengeNum = num
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function StoryDungeonModel:SyncData(_hanlder)
	local PB = self.rpc_pb.StoryDungeonRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.StoryDungeonRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_STORYDUNGEON_SYNCDATA_REQUEST, pb_data, callback)
end
function StoryDungeonModel:Challenge(Id,_hanlder)
	local PB = self.rpc_pb.StoryDungeonRpcChallengeAsk()
	PB.Id = Id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.StoryDungeonRpcChallengeReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_STORYDUNGEON_CHALLENGE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function StoryDungeonModel:ConfirmEnter(IsAgree,_hanlder)
	local PB = self.rpc_pb.StoryDungeonRpcConfirmEnterAsk()
	PB.IsAgree = IsAgree
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.StoryDungeonRpcConfirmEnterReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_STORYDUNGEON_CONFIRMENTER_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function StoryDungeonModel:registerWaitForConfirmationCBNotify(_hanlder)
	if not self.WaitForConfirmationCBNotifyCallBack then
		self.WaitForConfirmationCBNotifyCallBack = {}
	end
	table.insert(self.WaitForConfirmationCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function StoryDungeonModel:WaitForConfirmationCB(notifyMsg)
	if self.WaitForConfirmationCBNotifyCallBack then
		local ret_msg = self.rpc_pb.StoryDungeonRpcWaitForConfirmationNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.WaitForConfirmationCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function StoryDungeonModel:unregisterWaitForConfirmationCBNotify(_hanlder)
	if nil ~= self.WaitForConfirmationCBNotifyCallBack then
		for i,callback in ipairs(self.WaitForConfirmationCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.WaitForConfirmationCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function StoryDungeonModel:registerPlayerConfirmResultCBNotify(_hanlder)
	if not self.PlayerConfirmResultCBNotifyCallBack then
		self.PlayerConfirmResultCBNotifyCallBack = {}
	end
	table.insert(self.PlayerConfirmResultCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function StoryDungeonModel:PlayerConfirmResultCB(notifyMsg)
	if self.PlayerConfirmResultCBNotifyCallBack then
		local ret_msg = self.rpc_pb.StoryDungeonRpcPlayerConfirmResultNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.PlayerConfirmResultCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function StoryDungeonModel:unregisterPlayerConfirmResultCBNotify(_hanlder)
	if nil ~= self.PlayerConfirmResultCBNotifyCallBack then
		for i,callback in ipairs(self.PlayerConfirmResultCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.PlayerConfirmResultCBNotifyCallBack, i )
			end
		end
	end
end





askList.StoryDungeon = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = StoryDungeonModel.SyncData
t.pb = StoryDungeonRpc_pb.StoryDungeonRpcSyncDataAsk()
table.insert(askList.StoryDungeon,t)

local t = {}
t.name = "Challenge"
t.para = {{name="Id",t=1}}
t.hand = StoryDungeonModel.Challenge
t.pb = StoryDungeonRpc_pb.StoryDungeonRpcChallengeAsk()
table.insert(askList.StoryDungeon,t)

local t = {}
t.name = "ConfirmEnter"
t.para = {{name="IsAgree",t=3}}
t.hand = StoryDungeonModel.ConfirmEnter
t.pb = StoryDungeonRpc_pb.StoryDungeonRpcConfirmEnterAsk()
table.insert(askList.StoryDungeon,t)

