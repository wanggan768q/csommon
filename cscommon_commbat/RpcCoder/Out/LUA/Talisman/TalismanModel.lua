--将变量写入下方
local ModuleId = 18;
local RPC_CODE_TALISMAN_SYNCDATA_REQUEST = 1851
local RPC_CODE_TALISMAN_ACTIVE_REQUEST = 1852
local RPC_CODE_TALISMAN_UPGRADE_REQUEST = 1853


TALISMAN_FABAOARR = 1801


require("app.Talisman.TalismanV1Data_pb")
require("app.Talisman.TalismanRpc_pb")

TalismanModel = class("TalismanModel",BaseModel)

function TalismanModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=TalismanModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function TalismanModel:ctor()
	TalismanModel.super.ctor(self)
	self.rpc_pb = TalismanRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=TalismanV1Data_pb
	self.m_FabaoArr = {}


end

-- 更新数据
function TalismanModel:UpdateField(Id, data, Index, len)
	if  Id == TALISMAN_FABAOARR then
		if Index < 0 then
			self.m_FabaoArr = {}
		else
			if self.m_FabaoArr[Index] == nil then
				self.m_FabaoArr[Index] = TalismanV1Data_pb.TalismanFabaoInfoV1()
			end
			self.m_FabaoArr[Index]:ParseFromString(data)
		end
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function TalismanModel:SyncData(_hanlder)
	local PB = self.rpc_pb.TalismanRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.TalismanRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TALISMAN_SYNCDATA_REQUEST, pb_data, callback)
end
function TalismanModel:Active(ID,_hanlder)
	local PB = self.rpc_pb.TalismanRpcActiveAsk()
	PB.ID = ID
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TalismanRpcActiveReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TALISMAN_ACTIVE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function TalismanModel:Upgrade(ID,Type,_hanlder)
	local PB = self.rpc_pb.TalismanRpcUpgradeAsk()
	PB.ID = ID
	PB.Type = Type
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.TalismanRpcUpgradeReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_TALISMAN_UPGRADE_REQUEST, pb_data, callback)
	self:showNetTip()
end








askList.Talisman = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = TalismanModel.SyncData
t.pb = TalismanRpc_pb.TalismanRpcSyncDataAsk()
table.insert(askList.Talisman,t)

local t = {}
t.name = "Active"
t.para = {{name="ID",t=1}}
t.hand = TalismanModel.Active
t.pb = TalismanRpc_pb.TalismanRpcActiveAsk()
table.insert(askList.Talisman,t)

local t = {}
t.name = "Upgrade"
t.para = {{name="ID",t=1},{name="Type",t=1}}
t.hand = TalismanModel.Upgrade
t.pb = TalismanRpc_pb.TalismanRpcUpgradeAsk()
table.insert(askList.Talisman,t)

