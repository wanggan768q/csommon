--将变量写入下方
local ModuleId = 28;


ONLINEDATA_BAGRECYCLEBIN = 2801
ONLINEDATA_ROLEATTR = 2802
ONLINEDATA_RECOMMENDFRIENDOFFSET = 2804
ONLINEDATA_RECOMMENDFRIENDFLUSHTIME = 2805
ONLINEDATA_RECOMMENDFRIENDLASTLIST = 2806
ONLINEDATA_FOLLOWMEUSERID = 2807
ONLINEDATA_FOLLOWWHO = 2809
ONLINEDATA_THIEFOBJID = 2810


require("app.OnlineData.OnlineDataV1Data_pb")
require("app.OnlineData.OnlineDataRpc_pb")

OnlineDataModel = class("OnlineDataModel",BaseModel)

function OnlineDataModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=OnlineDataModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function OnlineDataModel:ctor()
	OnlineDataModel.super.ctor(self)
	self.rpc_pb = OnlineDataRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=OnlineDataV1Data_pb
	self.m_BagRecycleBin = {}
	self.m_RoleAttr = {}
	self.m_RecommendFriendOffset = 0
	self.m_RecommendFriendFlushTime = 0
	self.m_RecommendFriendLastList = {}
	self.m_FollowmeUserId = {}
	self.m_FollowWho = 0
	self.m_ThiefObjId = 0


end

-- 更新数据
function OnlineDataModel:UpdateField(Id, data, Index, len)
	if  Id == ONLINEDATA_BAGRECYCLEBIN then
		if Index < 0 then
			self.m_BagRecycleBin = {}
		else
			if self.m_BagRecycleBin[Index] == nil then
				self.m_BagRecycleBin[Index] = OnlineDataV1Data_pb.OnlineDataBagRecycleGridObjV1()
			end
			self.m_BagRecycleBin[Index]:ParseFromString(data)
		end
	elseif  Id == ONLINEDATA_ROLEATTR then
		if Index < 0 then
			self.m_RoleAttr = {}
		else
			if self.m_RoleAttr[Index] == nil then
				self.m_RoleAttr[Index] = OnlineDataV1Data_pb.OnlineDataRoleAttrObjV1()
			end
			self.m_RoleAttr[Index]:ParseFromString(data)
		end
	elseif  Id == ONLINEDATA_RECOMMENDFRIENDOFFSET then
		local num = ReadVarint32(data)
		self.m_RecommendFriendOffset = num
	elseif  Id == ONLINEDATA_RECOMMENDFRIENDFLUSHTIME then
		local num = ReadVarint32(data)
		self.m_RecommendFriendFlushTime = num
	elseif  Id == ONLINEDATA_RECOMMENDFRIENDLASTLIST then
		if Index<0 then
			self.m_RecommendFriendLastList = {}
		else
			local num = ReadVarint64(data)
			self.m_RecommendFriendLastList[Index] = num
		end
	elseif  Id == ONLINEDATA_FOLLOWMEUSERID then
		if Index<0 then
			self.m_FollowmeUserId = {}
		else
			local num = ReadVarint64(data)
			self.m_FollowmeUserId[Index] = num
		end
	elseif  Id == ONLINEDATA_FOLLOWWHO then
		local num = ReadVarint64(data)
		self.m_FollowWho = num
	elseif  Id == ONLINEDATA_THIEFOBJID then
		local num = ReadVarint64(data)
		self.m_ThiefObjId = num
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.OnlineData = {}

