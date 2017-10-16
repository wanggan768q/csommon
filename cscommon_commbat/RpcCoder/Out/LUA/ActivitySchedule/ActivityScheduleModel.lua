--将变量写入下方
local ModuleId = 32;
local RPC_CODE_ACTIVITYSCHEDULE_SYNCDATA_REQUEST = 3251
local RPC_CODE_ACTIVITYSCHEDULE_THIEFBEOPENED_NOTIFY = 3252;
local RPC_CODE_ACTIVITYSCHEDULE_THIEFREFRESH_NOTIFY = 3253;
local RPC_CODE_ACTIVITYSCHEDULE_THIEFOPENMONSTER_REQUEST = 3254
local RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERENTER_REQUEST = 3255
local RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERBEOPENED_NOTIFY = 3256;
local RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERREFRESH_NOTIFY = 3257;
local RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSENTERDUNGEON_REQUEST = 3258
local RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSSYNCDATA_REQUEST = 3259


ACTIVITYSCHEDULE_VALUE = 3201
ACTIVITYSCHEDULE_TIME = 3202


require("app.ActivitySchedule.ActivityScheduleV1Data_pb")
require("app.ActivitySchedule.ActivityScheduleRpc_pb")

ActivityScheduleModel = class("ActivityScheduleModel",BaseModel)

function ActivityScheduleModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityScheduleModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ActivityScheduleModel:ctor()
	ActivityScheduleModel.super.ctor(self)
	self.rpc_pb = ActivityScheduleRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITYSCHEDULE_THIEFBEOPENED_NOTIFY,handler(self,self.ThiefBeOpenedCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITYSCHEDULE_THIEFREFRESH_NOTIFY,handler(self,self.ThiefRefreshCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERBEOPENED_NOTIFY,handler(self,self.SubdueMonsterBeOpenedCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERREFRESH_NOTIFY,handler(self,self.SubdueMonsterRefreshCB))

  
	self.data_pb=ActivityScheduleV1Data_pb
	self.m_Value = {}
	self.m_Time = 0


end

-- 更新数据
function ActivityScheduleModel:UpdateField(Id, data, Index, len)
	if  Id == ACTIVITYSCHEDULE_VALUE then
		if Index < 0 then
			self.m_Value = {}
		else
			if self.m_Value[Index] == nil then
				self.m_Value[Index] = ActivityScheduleV1Data_pb.ActivityScheduleActiveValueV1()
			end
			self.m_Value[Index]:ParseFromString(data)
		end
	elseif  Id == ACTIVITYSCHEDULE_TIME then
		local num = ReadVarint32(data)
		self.m_Time = num
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function ActivityScheduleModel:SyncData(_hanlder)
	local PB = self.rpc_pb.ActivityScheduleRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityScheduleRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSCHEDULE_SYNCDATA_REQUEST, pb_data, callback)
end
function ActivityScheduleModel:ThiefOpenMonster(ThiefData,_hanlder)
	local PB = self.rpc_pb.ActivityScheduleRpcThiefOpenMonsterAsk()
	PB.ThiefData = ThiefData
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityScheduleRpcThiefOpenMonsterReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSCHEDULE_THIEFOPENMONSTER_REQUEST, pb_data, callback)
	self:showNetTip()
end
function ActivityScheduleModel:SubdueMonsterEnter(SubdueMonsterData,_hanlder)
	local PB = self.rpc_pb.ActivityScheduleRpcSubdueMonsterEnterAsk()
	PB.SubdueMonsterData = SubdueMonsterData
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityScheduleRpcSubdueMonsterEnterReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSCHEDULE_SUBDUEMONSTERENTER_REQUEST, pb_data, callback)
	self:showNetTip()
end
function ActivityScheduleModel:WorldBossEnterDungeon(_hanlder)
	local PB = self.rpc_pb.ActivityScheduleRpcWorldBossEnterDungeonAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityScheduleRpcWorldBossEnterDungeonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSENTERDUNGEON_REQUEST, pb_data, callback)
	self:showNetTip()
end
function ActivityScheduleModel:WorldBossSyncData(_hanlder)
	local PB = self.rpc_pb.ActivityScheduleRpcWorldBossSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityScheduleRpcWorldBossSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYSCHEDULE_WORLDBOSSSYNCDATA_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function ActivityScheduleModel:registerThiefBeOpenedCBNotify(_hanlder)
	if not self.ThiefBeOpenedCBNotifyCallBack then
		self.ThiefBeOpenedCBNotifyCallBack = {}
	end
	table.insert(self.ThiefBeOpenedCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityScheduleModel:ThiefBeOpenedCB(notifyMsg)
	if self.ThiefBeOpenedCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityScheduleRpcThiefBeOpenedNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ThiefBeOpenedCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ActivityScheduleModel:unregisterThiefBeOpenedCBNotify(_hanlder)
	if nil ~= self.ThiefBeOpenedCBNotifyCallBack then
		for i,callback in ipairs(self.ThiefBeOpenedCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ThiefBeOpenedCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ActivityScheduleModel:registerThiefRefreshCBNotify(_hanlder)
	if not self.ThiefRefreshCBNotifyCallBack then
		self.ThiefRefreshCBNotifyCallBack = {}
	end
	table.insert(self.ThiefRefreshCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityScheduleModel:ThiefRefreshCB(notifyMsg)
	if self.ThiefRefreshCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityScheduleRpcThiefRefreshNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.ThiefRefreshCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ActivityScheduleModel:unregisterThiefRefreshCBNotify(_hanlder)
	if nil ~= self.ThiefRefreshCBNotifyCallBack then
		for i,callback in ipairs(self.ThiefRefreshCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.ThiefRefreshCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ActivityScheduleModel:registerSubdueMonsterBeOpenedCBNotify(_hanlder)
	if not self.SubdueMonsterBeOpenedCBNotifyCallBack then
		self.SubdueMonsterBeOpenedCBNotifyCallBack = {}
	end
	table.insert(self.SubdueMonsterBeOpenedCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityScheduleModel:SubdueMonsterBeOpenedCB(notifyMsg)
	if self.SubdueMonsterBeOpenedCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityScheduleRpcSubdueMonsterBeOpenedNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SubdueMonsterBeOpenedCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ActivityScheduleModel:unregisterSubdueMonsterBeOpenedCBNotify(_hanlder)
	if nil ~= self.SubdueMonsterBeOpenedCBNotifyCallBack then
		for i,callback in ipairs(self.SubdueMonsterBeOpenedCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SubdueMonsterBeOpenedCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function ActivityScheduleModel:registerSubdueMonsterRefreshCBNotify(_hanlder)
	if not self.SubdueMonsterRefreshCBNotifyCallBack then
		self.SubdueMonsterRefreshCBNotifyCallBack = {}
	end
	table.insert(self.SubdueMonsterRefreshCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function ActivityScheduleModel:SubdueMonsterRefreshCB(notifyMsg)
	if self.SubdueMonsterRefreshCBNotifyCallBack then
		local ret_msg = self.rpc_pb.ActivityScheduleRpcSubdueMonsterRefreshNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SubdueMonsterRefreshCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function ActivityScheduleModel:unregisterSubdueMonsterRefreshCBNotify(_hanlder)
	if nil ~= self.SubdueMonsterRefreshCBNotifyCallBack then
		for i,callback in ipairs(self.SubdueMonsterRefreshCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SubdueMonsterRefreshCBNotifyCallBack, i )
			end
		end
	end
end





askList.ActivitySchedule = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = ActivityScheduleModel.SyncData
t.pb = ActivityScheduleRpc_pb.ActivityScheduleRpcSyncDataAsk()
table.insert(askList.ActivitySchedule,t)

local t = {}
t.name = "ThiefOpenMonster"
t.para = {{name="ThiefData",t=3}}
t.hand = ActivityScheduleModel.ThiefOpenMonster
t.pb = ActivityScheduleRpc_pb.ActivityScheduleRpcThiefOpenMonsterAsk()
table.insert(askList.ActivitySchedule,t)

local t = {}
t.name = "SubdueMonsterEnter"
t.para = {{name="SubdueMonsterData",t=3}}
t.hand = ActivityScheduleModel.SubdueMonsterEnter
t.pb = ActivityScheduleRpc_pb.ActivityScheduleRpcSubdueMonsterEnterAsk()
table.insert(askList.ActivitySchedule,t)

local t = {}
t.name = "WorldBossEnterDungeon"
t.para = {}
t.hand = ActivityScheduleModel.WorldBossEnterDungeon
t.pb = ActivityScheduleRpc_pb.ActivityScheduleRpcWorldBossEnterDungeonAsk()
table.insert(askList.ActivitySchedule,t)

local t = {}
t.name = "WorldBossSyncData"
t.para = {}
t.hand = ActivityScheduleModel.WorldBossSyncData
t.pb = ActivityScheduleRpc_pb.ActivityScheduleRpcWorldBossSyncDataAsk()
table.insert(askList.ActivitySchedule,t)

