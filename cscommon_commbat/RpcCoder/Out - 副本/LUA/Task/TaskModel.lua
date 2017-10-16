--将变量写入下方
local ModuleId = 24;
local RPC_CODE_TASK_SYNCDATA_REQUEST = 2451
local RPC_CODE_TASK_COMPLETETASK_REQUEST = 2452
local RPC_CODE_TASK_SUBMITTASK_REQUEST = 2453
local RPC_CODE_TASK_UPDATETASK_NOTIFY = 2454;
local RPC_CODE_TASK_ACCEPTTASK_REQUEST = 2455
local RPC_CODE_TASK_STARTPROFTASK_REQUEST = 2456
local RPC_CODE_TASK_STARTONEDRAGON_REQUEST = 2457
local RPC_CODE_TASK_ADDTASK_NOTIFY = 2458;
local RPC_CODE_TASK_DELTASK_NOTIFY = 2459;
local RPC_CODE_TASK_STARTGUILDSPY_REQUEST = 2460


TASK_ALLTASKARRAY = 2402
TASK_UNACCEPTEDTASKARRAY = 2403
TASK_PROFTASKID = 2404
TASK_PROFTASKCOMPCOUNT = 2405
TASK_ONEDRAGONTASKID = 2406
TASK_ONEDRAGONRINGNUM = 2407
TASK_ONEDRAGONCOMPLATECOUNT = 2408
TASK_ONEDRAGONDUNGEONID = 2409
TASK_GUILDSPYCOMPLATECOUNT = 2410


require("app.Task.TaskV1Data_pb")
require("app.Task.TaskRpc_pb")

TaskModel = class("TaskModel",BaseModel)

function TaskModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TaskModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function TaskModel:ctor()
	TaskModel.super.ctor(self)
	self.rpc_pb = TaskRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_TASK_UPDATETASK_NOTIFY,handler(self,self.UpdateTaskCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TASK_ADDTASK_NOTIFY,handler(self,self.AddTaskCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_TASK_DELTASK_NOTIFY,handler(self,self.DelTaskCB))

  
	self.data_pb=TaskV1Data_pb
	self.m_AllTaskArray = {}
	self.m_UnacceptedTaskArray = {}
	self.m_ProfTaskId = 0
	self.m_ProfTaskCompCount = 0
	self.m_OneDragonTaskId = {}
	self.m_OneDragonRingNum = 0
	self.m_OneDragonComplateCount = 0
	self.m_OneDragonDungeonId = 0
	self.m_GuildSpyComplateCount = 0


end

-- 更新数据
function TaskModel:UpdateField(Id, data, Index, len)
	if  Id == TASK_ALLTASKARRAY then
		if Index < 0 then
			self.m_AllTaskArray = {}
		else
			if self.m_AllTaskArray[Index] == nil then
				self.m_AllTaskArray[Index] = TaskV1Data_pb.TaskTaskObjV1()
			end
			self.m_AllTaskArray[Index]:ParseFromString(data)
		end
	elseif  Id == TASK_UNACCEPTEDTASKARRAY then
		if Index < 0 then
			self.m_UnacceptedTaskArray = {}
		else
			if self.m_UnacceptedTaskArray[Index] == nil then
				self.m_UnacceptedTaskArray[Index] = TaskV1Data_pb.TaskUnacceptedTaskObjV1()
			end
			self.m_UnacceptedTaskArray[Index]:ParseFromString(data)
		end
	elseif  Id == TASK_PROFTASKID then
		local num = ReadVarint32(data)
		self.m_ProfTaskId = num
	elseif  Id == TASK_PROFTASKCOMPCOUNT then
		local num = ReadVarint32(data)
		self.m_ProfTaskCompCount = num
	elseif  Id == TASK_ONEDRAGONTASKID then
		if Index<0 then
			self.m_OneDragonTaskId = {}
		else
			local num = ReadVarint32(data)
			self.m_OneDragonTaskId[Index] = num
		end
	elseif  Id == TASK_ONEDRAGONRINGNUM then
		local num = ReadVarint32(data)
		self.m_OneDragonRingNum = num
	elseif  Id == TASK_ONEDRAGONCOMPLATECOUNT then
		local num = ReadVarint32(data)
		self.m_OneDragonComplateCount = num
	elseif  Id == TASK_ONEDRAGONDUNGEONID then
		local num = ReadVarint32(data)
		self.m_OneDragonDungeonId = num
	elseif  Id == TASK_GUILDSPYCOMPLATECOUNT then
		local num = ReadVarint32(data)
		self.m_GuildSpyComplateCount = num
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function TaskModel:SyncData(_hanlder)
	local PB = self.rpc_pb.TaskRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.TaskRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TASK_SYNCDATA_REQUEST, pb_data, callback)
end
function TaskModel:CompleteTask(TaskId,Target,_hanlder)
	local PB = self.rpc_pb.TaskRpcCompleteTaskAsk()
	PB.TaskId = TaskId
	PB.Target = Target
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TaskRpcCompleteTaskReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TASK_COMPLETETASK_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TaskModel:SubmitTask(TaskId,_hanlder)
	local PB = self.rpc_pb.TaskRpcSubmitTaskAsk()
	PB.TaskId = TaskId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TaskRpcSubmitTaskReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TASK_SUBMITTASK_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TaskModel:AcceptTask(TaskId,_hanlder)
	local PB = self.rpc_pb.TaskRpcAcceptTaskAsk()
	PB.TaskId = TaskId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TaskRpcAcceptTaskReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TASK_ACCEPTTASK_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TaskModel:StartProfTask(_hanlder)
	local PB = self.rpc_pb.TaskRpcStartProfTaskAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TaskRpcStartProfTaskReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TASK_STARTPROFTASK_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TaskModel:StartOneDragon(_hanlder)
	local PB = self.rpc_pb.TaskRpcStartOneDragonAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TaskRpcStartOneDragonReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TASK_STARTONEDRAGON_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TaskModel:StartGuildSpy(_hanlder)
	local PB = self.rpc_pb.TaskRpcStartGuildSpyAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TaskRpcStartGuildSpyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TASK_STARTGUILDSPY_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function TaskModel:registerUpdateTaskCBNotify(_hanlder)
	if not self.UpdateTaskCBNotifyCallBack then
		self.UpdateTaskCBNotifyCallBack = {}
	end
	table.insert(self.UpdateTaskCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TaskModel:UpdateTaskCB(notifyMsg)
	if self.UpdateTaskCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TaskRpcUpdateTaskNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.UpdateTaskCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TaskModel:unregisterUpdateTaskCBNotify(_hanlder)
	if nil ~= self.UpdateTaskCBNotifyCallBack then
		for i,callback in ipairs(self.UpdateTaskCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.UpdateTaskCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TaskModel:registerAddTaskCBNotify(_hanlder)
	if not self.AddTaskCBNotifyCallBack then
		self.AddTaskCBNotifyCallBack = {}
	end
	table.insert(self.AddTaskCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TaskModel:AddTaskCB(notifyMsg)
	if self.AddTaskCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TaskRpcAddTaskNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.AddTaskCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TaskModel:unregisterAddTaskCBNotify(_hanlder)
	if nil ~= self.AddTaskCBNotifyCallBack then
		for i,callback in ipairs(self.AddTaskCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.AddTaskCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function TaskModel:registerDelTaskCBNotify(_hanlder)
	if not self.DelTaskCBNotifyCallBack then
		self.DelTaskCBNotifyCallBack = {}
	end
	table.insert(self.DelTaskCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function TaskModel:DelTaskCB(notifyMsg)
	if self.DelTaskCBNotifyCallBack then
		local ret_msg = self.rpc_pb.TaskRpcDelTaskNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DelTaskCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function TaskModel:unregisterDelTaskCBNotify(_hanlder)
	if nil ~= self.DelTaskCBNotifyCallBack then
		for i,callback in ipairs(self.DelTaskCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DelTaskCBNotifyCallBack, i )
			end
		end
	end
end





askList.Task = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = TaskModel.SyncData
t.pb = TaskRpc_pb.TaskRpcSyncDataAsk()
table.insert(askList.Task,t)

local t = {}
t.name = "CompleteTask"
t.para = {{name="TaskId",t=1},{name="Target",t=1}}
t.hand = TaskModel.CompleteTask
t.pb = TaskRpc_pb.TaskRpcCompleteTaskAsk()
table.insert(askList.Task,t)

local t = {}
t.name = "SubmitTask"
t.para = {{name="TaskId",t=1}}
t.hand = TaskModel.SubmitTask
t.pb = TaskRpc_pb.TaskRpcSubmitTaskAsk()
table.insert(askList.Task,t)

local t = {}
t.name = "AcceptTask"
t.para = {{name="TaskId",t=1}}
t.hand = TaskModel.AcceptTask
t.pb = TaskRpc_pb.TaskRpcAcceptTaskAsk()
table.insert(askList.Task,t)

local t = {}
t.name = "StartProfTask"
t.para = {}
t.hand = TaskModel.StartProfTask
t.pb = TaskRpc_pb.TaskRpcStartProfTaskAsk()
table.insert(askList.Task,t)

local t = {}
t.name = "StartOneDragon"
t.para = {}
t.hand = TaskModel.StartOneDragon
t.pb = TaskRpc_pb.TaskRpcStartOneDragonAsk()
table.insert(askList.Task,t)

local t = {}
t.name = "StartGuildSpy"
t.para = {}
t.hand = TaskModel.StartGuildSpy
t.pb = TaskRpc_pb.TaskRpcStartGuildSpyAsk()
table.insert(askList.Task,t)

