--将变量写入下方
local ModuleId = 10;
local RPC_CODE_PERSISTATTR_SYNCDATA_REQUEST = 1051


PERSISTATTR_USERNAME = 1001
PERSISTATTR_USERID = 1003
PERSISTATTR_PLATNAME = 1004
PERSISTATTR_ACCOUNTID = 1021
PERSISTATTR_LEVEL = 1030
PERSISTATTR_RANK = 1031
PERSISTATTR_FIGHTPOWER = 1032
PERSISTATTR_SEC = 1033
PERSISTATTR_PROF = 1035
PERSISTATTR_ONLINESTATE = 1036
PERSISTATTR_TEAMID = 1037
PERSISTATTR_SHOPSCORE = 1039
PERSISTATTR_DUNGEONID = 1042
PERSISTATTR_SESSIONKEY = 1043
PERSISTATTR_GUILDID = 1044


require("app.PersistAttr.PersistAttrV1Data_pb")
require("app.PersistAttr.PersistAttrRpc_pb")

PersistAttrModel = class("PersistAttrModel",BaseModel)

function PersistAttrModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=PersistAttrModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function PersistAttrModel:ctor()
	PersistAttrModel.super.ctor(self)
	self.rpc_pb = PersistAttrRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=PersistAttrV1Data_pb
	self.m_UserName = ""
	self.m_UserId = 0
	self.m_PlatName = ""
	self.m_AccountId = 0
	self.m_Level = 0
	self.m_Rank = 0
	self.m_FightPower = 0
	self.m_Sec = 0
	self.m_Prof = 0
	self.m_OnlineState = 0
	self.m_TeamId = 0
	self.m_ShopScore = 0
	self.m_DungeonId = 0
	self.m_SessionKey = ""
	self.m_GuildId = 0


end

-- 更新数据
function PersistAttrModel:UpdateField(Id, data, Index, len)
	if  Id == PERSISTATTR_USERNAME then
		self.m_UserName = tostring(data)
	elseif  Id == PERSISTATTR_USERID then
		local num = ReadVarint64(data)
		self.m_UserId = num
	elseif  Id == PERSISTATTR_PLATNAME then
		self.m_PlatName = tostring(data)
	elseif  Id == PERSISTATTR_ACCOUNTID then
		local num = ReadVarint64(data)
		self.m_AccountId = num
	elseif  Id == PERSISTATTR_LEVEL then
		local num = ReadVarint32(data)
		self.m_Level = num
	elseif  Id == PERSISTATTR_RANK then
		local num = ReadVarint32(data)
		self.m_Rank = num
	elseif  Id == PERSISTATTR_FIGHTPOWER then
		local num = ReadVarint32(data)
		self.m_FightPower = num
	elseif  Id == PERSISTATTR_SEC then
		local num = ReadVarint32(data)
		self.m_Sec = num
	elseif  Id == PERSISTATTR_PROF then
		local num = ReadVarint32(data)
		self.m_Prof = num
	elseif  Id == PERSISTATTR_ONLINESTATE then
		local num = ReadVarint32(data)
		self.m_OnlineState = num
	elseif  Id == PERSISTATTR_TEAMID then
		local num = ReadVarint32(data)
		self.m_TeamId = num
	elseif  Id == PERSISTATTR_SHOPSCORE then
		local num = ReadVarint32(data)
		self.m_ShopScore = num
	elseif  Id == PERSISTATTR_DUNGEONID then
		local num = ReadVarint32(data)
		self.m_DungeonId = num
	elseif  Id == PERSISTATTR_SESSIONKEY then
		self.m_SessionKey = tostring(data)
	elseif  Id == PERSISTATTR_GUILDID then
		local num = ReadVarint32(data)
		self.m_GuildId = num
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function PersistAttrModel:SyncData(_hanlder)
	local PB = self.rpc_pb.PersistAttrRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.PersistAttrRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_PERSISTATTR_SYNCDATA_REQUEST, pb_data, callback)
end








askList.PersistAttr = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = PersistAttrModel.SyncData
t.pb = PersistAttrRpc_pb.PersistAttrRpcSyncDataAsk()
table.insert(askList.PersistAttr,t)

