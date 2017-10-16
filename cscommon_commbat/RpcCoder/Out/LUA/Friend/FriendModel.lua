--将变量写入下方
local ModuleId = 33;
local RPC_CODE_FRIEND_SYNCFRIENDDATA_REQUEST = 3351
local RPC_CODE_FRIEND_ADDFRIEND_REQUEST = 3352
local RPC_CODE_FRIEND_DELFRIEND_REQUEST = 3353
local RPC_CODE_FRIEND_ADDBLACKLIST_REQUEST = 3354
local RPC_CODE_FRIEND_DELBLACKLIST_REQUEST = 3355
local RPC_CODE_FRIEND_ADDCONTACT_REQUEST = 3356
local RPC_CODE_FRIEND_DELCONTACT_REQUEST = 3357
local RPC_CODE_FRIEND_SEARCHPLAYER_REQUEST = 3358
local RPC_CODE_FRIEND_RECOMMEND_REQUEST = 3359
local RPC_CODE_FRIEND_VIEWUSERSIMPLEINFO_REQUEST = 3360
local RPC_CODE_FRIEND_FRIENDONLINEOFFLINE_NOTIFY = 3361;


FRIEND_FRIENDLIST = 3301
FRIEND_BLACKLIST = 3302
FRIEND_CONTACTSLIST = 3303
FRIEND_STRANGERFRIENDLIST = 3304


require("app.Friend.FriendV1Data_pb")
require("app.Friend.FriendRpc_pb")

FriendModel = class("FriendModel",BaseModel)

function FriendModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=FriendModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function FriendModel:ctor()
	FriendModel.super.ctor(self)
	self.rpc_pb = FriendRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_FRIEND_FRIENDONLINEOFFLINE_NOTIFY,handler(self,self.FriendOnlineOfflineCB))

  
	self.data_pb=FriendV1Data_pb
	self.m_FriendList = {}
	self.m_BlackList = {}
	self.m_ContactsList = {}
	self.m_StrangerFriendList = {}


end

-- 更新数据
function FriendModel:UpdateField(Id, data, Index, len)
	if  Id == FRIEND_FRIENDLIST then
		if Index < 0 then
			self.m_FriendList = {}
		else
			if self.m_FriendList[Index] == nil then
				self.m_FriendList[Index] = FriendV1Data_pb.FriendFriendObjV1()
			end
			self.m_FriendList[Index]:ParseFromString(data)
		end
	elseif  Id == FRIEND_BLACKLIST then
		if Index < 0 then
			self.m_BlackList = {}
		else
			if self.m_BlackList[Index] == nil then
				self.m_BlackList[Index] = FriendV1Data_pb.FriendFriendObjV1()
			end
			self.m_BlackList[Index]:ParseFromString(data)
		end
	elseif  Id == FRIEND_CONTACTSLIST then
		if Index < 0 then
			self.m_ContactsList = {}
		else
			if self.m_ContactsList[Index] == nil then
				self.m_ContactsList[Index] = FriendV1Data_pb.FriendFriendObjV1()
			end
			self.m_ContactsList[Index]:ParseFromString(data)
		end
	elseif  Id == FRIEND_STRANGERFRIENDLIST then
		if Index<0 then
			self.m_StrangerFriendList = {}
		else
			local num = ReadVarint64(data)
			self.m_StrangerFriendList[Index] = num
		end
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function FriendModel:SyncFriendData(_hanlder)
	local PB = self.rpc_pb.FriendRpcSyncFriendDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcSyncFriendDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_SYNCFRIENDDATA_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:AddFriend(UserId,_hanlder)
	local PB = self.rpc_pb.FriendRpcAddFriendAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcAddFriendReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_ADDFRIEND_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:DelFriend(UserId,_hanlder)
	local PB = self.rpc_pb.FriendRpcDelFriendAsk()
	for i,v in ipairs(UserId) do
		table.insert(PB.UserId,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcDelFriendReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_DELFRIEND_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:AddBlackList(UserId,_hanlder)
	local PB = self.rpc_pb.FriendRpcAddBlackListAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcAddBlackListReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_ADDBLACKLIST_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:DelBlackList(UserId,_hanlder)
	local PB = self.rpc_pb.FriendRpcDelBlackListAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcDelBlackListReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_DELBLACKLIST_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:AddContact(UserId,_hanlder)
	local PB = self.rpc_pb.FriendRpcAddContactAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcAddContactReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_ADDCONTACT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:DelContact(UserId,_hanlder)
	local PB = self.rpc_pb.FriendRpcDelContactAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcDelContactReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_DELCONTACT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:SearchPlayer(SearchString,_hanlder)
	local PB = self.rpc_pb.FriendRpcSearchPlayerAsk()
	PB.SearchString = SearchString
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcSearchPlayerReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_SEARCHPLAYER_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:Recommend(_hanlder)
	local PB = self.rpc_pb.FriendRpcRecommendAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcRecommendReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_RECOMMEND_REQUEST, pb_data, callback)
	self:showNetTip()
end
function FriendModel:ViewUserSimpleInfo(UserId,_hanlder)
	local PB = self.rpc_pb.FriendRpcViewUserSimpleInfoAsk()
	PB.UserId = UserId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.FriendRpcViewUserSimpleInfoReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_FRIEND_VIEWUSERSIMPLEINFO_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function FriendModel:registerFriendOnlineOfflineCBNotify(_hanlder)
	if not self.FriendOnlineOfflineCBNotifyCallBack then
		self.FriendOnlineOfflineCBNotifyCallBack = {}
	end
	table.insert(self.FriendOnlineOfflineCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function FriendModel:FriendOnlineOfflineCB(notifyMsg)
	if self.FriendOnlineOfflineCBNotifyCallBack then
		local ret_msg = self.rpc_pb.FriendRpcOnlineOfflineNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.FriendOnlineOfflineCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function FriendModel:unregisterFriendOnlineOfflineCBNotify(_hanlder)
	if nil ~= self.FriendOnlineOfflineCBNotifyCallBack then
		for i,callback in ipairs(self.FriendOnlineOfflineCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.FriendOnlineOfflineCBNotifyCallBack, i )
			end
		end
	end
end





askList.Friend = {}

local t = {}
t.name = "SyncFriendData"
t.para = {}
t.hand = FriendModel.SyncFriendData
t.pb = FriendRpc_pb.FriendRpcSyncFriendDataAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "AddFriend"
t.para = {{name="UserId",t=1}}
t.hand = FriendModel.AddFriend
t.pb = FriendRpc_pb.FriendRpcAddFriendAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "DelFriend"
t.para = {{name="UserId",t=1}}
t.hand = FriendModel.DelFriend
t.pb = FriendRpc_pb.FriendRpcDelFriendAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "AddBlackList"
t.para = {{name="UserId",t=1}}
t.hand = FriendModel.AddBlackList
t.pb = FriendRpc_pb.FriendRpcAddBlackListAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "DelBlackList"
t.para = {{name="UserId",t=1}}
t.hand = FriendModel.DelBlackList
t.pb = FriendRpc_pb.FriendRpcDelBlackListAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "AddContact"
t.para = {{name="UserId",t=1}}
t.hand = FriendModel.AddContact
t.pb = FriendRpc_pb.FriendRpcAddContactAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "DelContact"
t.para = {{name="UserId",t=1}}
t.hand = FriendModel.DelContact
t.pb = FriendRpc_pb.FriendRpcDelContactAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "SearchPlayer"
t.para = {{name="SearchString",t=2}}
t.hand = FriendModel.SearchPlayer
t.pb = FriendRpc_pb.FriendRpcSearchPlayerAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "Recommend"
t.para = {}
t.hand = FriendModel.Recommend
t.pb = FriendRpc_pb.FriendRpcRecommendAsk()
table.insert(askList.Friend,t)

local t = {}
t.name = "ViewUserSimpleInfo"
t.para = {{name="UserId",t=1}}
t.hand = FriendModel.ViewUserSimpleInfo
t.pb = FriendRpc_pb.FriendRpcViewUserSimpleInfoAsk()
table.insert(askList.Friend,t)

