--将变量写入下方
local ModuleId = 2;
local RPC_CODE_ACHIEVEMENT_GETTHEREWARDS_REQUEST = 251
local RPC_CODE_ACHIEVEMENT_SYNCDATA_REQUEST = 252


ACHIEVEMENT_ACHIDATA = 201


require("app.Achievement.AchievementV1Data_pb")
require("app.Achievement.AchievementRpc_pb")

AchievementModel = class("AchievementModel",BaseModel)

function AchievementModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=AchievementModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function AchievementModel:ctor()
	AchievementModel.super.ctor(self)
	self.rpc_pb = AchievementRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=AchievementV1Data_pb
	self.m_AchiData = {}


end

-- 更新数据
function AchievementModel:UpdateField(Id, data, Index, len)
	if  Id == ACHIEVEMENT_ACHIDATA then
		if Index < 0 then
			self.m_AchiData = {}
		else
			if self.m_AchiData[Index] == nil then
				self.m_AchiData[Index] = AchievementV1Data_pb.AchievementAchiObjV1()
			end
			self.m_AchiData[Index]:ParseFromString(data)
		end
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function AchievementModel:GetTheRewards(GroupId,_hanlder)
	local PB = self.rpc_pb.AchievementRpcGetTheRewardsAsk()
	PB.GroupId = GroupId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.AchievementRpcGetTheRewardsReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACHIEVEMENT_GETTHEREWARDS_REQUEST, pb_data, callback)
	self:showNetTip()
end
function AchievementModel:SyncData(_hanlder)
	local PB = self.rpc_pb.AchievementRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.AchievementRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACHIEVEMENT_SYNCDATA_REQUEST, pb_data, callback)
end








askList.Achievement = {}

local t = {}
t.name = "GetTheRewards"
t.para = {{name="GroupId",t=1}}
t.hand = AchievementModel.GetTheRewards
t.pb = AchievementRpc_pb.AchievementRpcGetTheRewardsAsk()
table.insert(askList.Achievement,t)

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = AchievementModel.SyncData
t.pb = AchievementRpc_pb.AchievementRpcSyncDataAsk()
table.insert(askList.Achievement,t)

