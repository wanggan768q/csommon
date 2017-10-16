--将变量写入下方
local ModuleId = 12;
local RPC_CODE_DUNGEON_ENTER_REQUEST = 1251
local RPC_CODE_DUNGEON_OPEN_NOTIFY = 1252;
local RPC_CODE_DUNGEON_TRYENTER_REQUEST = 1253
local RPC_CODE_DUNGEON_TRANSFER_NOTIFY = 1254;





require("app.Dungeon.DungeonRpc_pb")

DungeonModel = class("DungeonModel",BaseModel)

function DungeonModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=DungeonModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function DungeonModel:ctor()
	DungeonModel.super.ctor(self)
	self.rpc_pb = DungeonRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_OPEN_NOTIFY,handler(self,self.OpenCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DUNGEON_TRANSFER_NOTIFY,handler(self,self.TransferCB))

  


end

-- 更新数据
function DungeonModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function DungeonModel:Enter(DungeonId,DungeonType,BirthPoint,FaceDir,GuildId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcEnterAsk()
	PB.DungeonId = DungeonId
	PB.DungeonType = DungeonType
	PB.BirthPoint = BirthPoint
	PB.FaceDir = FaceDir
	PB.GuildId = GuildId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcEnterReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_ENTER_REQUEST, pb_data, callback)
	self:showNetTip()
end
function DungeonModel:TryEnter(DungeonId,BirthPoint,FaceDir,GuildId,_hanlder)
	local PB = self.rpc_pb.DungeonRpcTryEnterAsk()
	PB.DungeonId = DungeonId
	PB.BirthPoint = BirthPoint
	PB.FaceDir = FaceDir
	PB.GuildId = GuildId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.DungeonRpcTryEnterReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DUNGEON_TRYENTER_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function DungeonModel:registerOpenCBNotify(_hanlder)
	if not self.OpenCBNotifyCallBack then
		self.OpenCBNotifyCallBack = {}
	end
	table.insert(self.OpenCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DungeonModel:OpenCB(notifyMsg)
	if self.OpenCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcOpenNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.OpenCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function DungeonModel:unregisterOpenCBNotify(_hanlder)
	if nil ~= self.OpenCBNotifyCallBack then
		for i,callback in ipairs(self.OpenCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.OpenCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function DungeonModel:registerTransferCBNotify(_hanlder)
	if not self.TransferCBNotifyCallBack then
		self.TransferCBNotifyCallBack = {}
	end
	table.insert(self.TransferCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DungeonModel:TransferCB(notifyMsg)
	if self.TransferCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DungeonRpcTransferNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TransferCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function DungeonModel:unregisterTransferCBNotify(_hanlder)
	if nil ~= self.TransferCBNotifyCallBack then
		for i,callback in ipairs(self.TransferCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TransferCBNotifyCallBack, i )
			end
		end
	end
end





askList.Dungeon = {}

local t = {}
t.name = "Enter"
t.para = {{name="DungeonId",t=1},{name="DungeonType",t=1},{name="BirthPoint",t=1},{name="FaceDir",t=1},{name="GuildId",t=1}}
t.hand = DungeonModel.Enter
t.pb = DungeonRpc_pb.DungeonRpcEnterAsk()
table.insert(askList.Dungeon,t)

local t = {}
t.name = "TryEnter"
t.para = {{name="DungeonId",t=1},{name="BirthPoint",t=1},{name="FaceDir",t=1},{name="GuildId",t=1}}
t.hand = DungeonModel.TryEnter
t.pb = DungeonRpc_pb.DungeonRpcTryEnterAsk()
table.insert(askList.Dungeon,t)

