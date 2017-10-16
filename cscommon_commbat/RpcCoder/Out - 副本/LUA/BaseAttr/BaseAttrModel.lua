--将变量写入下方
local ModuleId = 13;
local RPC_CODE_BASEATTR_SYNCDATA_REQUEST = 1351
local RPC_CODE_BASEATTR_GETRANKREWARD_REQUEST = 1352
local RPC_CODE_BASEATTR_UPGRADERANK_REQUEST = 1353
local RPC_CODE_BASEATTR_CHOOSEROLE_REQUEST = 1354
local RPC_CODE_BASEATTR_LEVELUP_REQUEST = 1355
local RPC_CODE_BASEATTR_GETTIMER_REQUEST = 1356
local RPC_CODE_BASEATTR_REVIVE_REQUEST = 1357
local RPC_CODE_BASEATTR_QUERYEQUIP_REQUEST = 1358
local RPC_CODE_BASEATTR_UPDATENEWBIEGUIDE_REQUEST = 1359
local RPC_CODE_BASEATTR_SYSTIPS_NOTIFY = 1360;
local RPC_CODE_BASEATTR_CHANGPKSTATE_REQUEST = 1361
local RPC_CODE_BASEATTR_CHANGEPKPROTECT_REQUEST = 1362


BASEATTR_HEADID = 1301
BASEATTR_EXP = 1302
BASEATTR_CREATETIME = 1303
BASEATTR_LASTLOGINTIME = 1304
BASEATTR_LAST2LOGINDATE = 1305
BASEATTR_LASTLOGOUTTIME = 1306
BASEATTR_MONEY = 1307
BASEATTR_DIAMOND = 1308
BASEATTR_STRENGTH = 1310
BASEATTR_FEATS = 1311
BASEATTR_GOTRANKREWARDTIME = 1312
BASEATTR_MAXMILITARY = 1314
BASEATTR_MASTERATTRS = 1315
BASEATTR_CURMILITARY = 1318
BASEATTR_USERNAME = 1319
BASEATTR_USERID = 1320
BASEATTR_PLATNAME = 1321
BASEATTR_ACCOUNTID = 1322
BASEATTR_LEVEL = 1323
BASEATTR_RANK = 1324
BASEATTR_FIGHTPOWER = 1325
BASEATTR_SEC = 1326
BASEATTR_MILITARY = 1327
BASEATTR_TEAMID = 1328
BASEATTR_PROF = 1329
BASEATTR_DUNGEONREMAINCOUNT = 1330
BASEATTR_MAPID = 1331
BASEATTR_POSX = 1332
BASEATTR_POSY = 1333
BASEATTR_POSZ = 1334
BASEATTR_RY = 1335
BASEATTR_SKILLCDARR = 1336
BASEATTR_BUFFCDARR = 1337
BASEATTR_CURRENTSCENE = 1338
BASEATTR_GUILDID = 1339
BASEATTR_EXITGUILDTIME = 1340
BASEATTR_APPLYGUILDID = 1341
BASEATTR_CURGUILDCONTRIBUTION = 1342
BASEATTR_MAXGUILDCONTRIBUTION = 1343
BASEATTR_BINDMONEY = 1344
BASEATTR_GEM = 1345
BASEATTR_SERVERTIME = 1347
BASEATTR_NEWBIEGUIDE = 1348
BASEATTR_THIEFREWARDNUM = 1349
BASEATTR_SUBDUEMONSTERREWARDNUM = 1350
BASEATTR_WORLDBOSSREMAINTIMES = 1351
BASEATTR_WORLDBOSSHURT = 1352
BASEATTR_FUNCTIONOPENLIST = 1354
BASEATTR_TOTALENERGYVALUE = 1355
BASEATTR_ENERGYARRAY = 1357
BASEATTR_PKSTATE = 1358
BASEATTR_PKPROTECT = 1359
BASEATTR_GUILDSCIENARRAY = 1360
BASEATTR_SCIENCETOTALMONEY = 1361


require("app.BaseAttr.BaseAttrV1Data_pb")
require("app.BaseAttr.BaseAttrRpc_pb")

BaseAttrModel = class("BaseAttrModel",BaseModel)

function BaseAttrModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=BaseAttrModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function BaseAttrModel:ctor()
	BaseAttrModel.super.ctor(self)
	self.rpc_pb = BaseAttrRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_BASEATTR_SYSTIPS_NOTIFY,handler(self,self.SysTipsCB))

  
	self.data_pb=BaseAttrV1Data_pb
	self.m_HeadID = 0
	self.m_Exp = 0
	self.m_CreateTime = 0
	self.m_LastLoginTime = 0
	self.m_Last2LoginDate = 0
	self.m_LastLogoutTime = 0
	self.m_Money = 0
	self.m_Diamond = 0
	self.m_Strength = 0
	self.m_Feats = 0
	self.m_GotRankRewardTime = 0
	self.m_MaxMilitary = 0
	self.m_MasterAttrs = {}
	self.m_CurMilitary = 0
	self.m_UserName = ""
	self.m_UserId = 0
	self.m_PlatName = ""
	self.m_AccountId = 0
	self.m_Level = 0
	self.m_Rank = 0
	self.m_FightPower = 0
	self.m_Sec = 0
	self.m_Military = 0
	self.m_TeamId = 0
	self.m_Prof = 0
	self.m_DungeonRemainCount = 0
	self.m_MapId = 0
	self.m_PosX = BaseAttrV1Data_pb.BaseAttrfloatV1()
	self.m_PosY = BaseAttrV1Data_pb.BaseAttrfloatV1()
	self.m_PosZ = BaseAttrV1Data_pb.BaseAttrfloatV1()
	self.m_Ry = 0
	self.m_SkillCdArr = {}
	self.m_BuffCdArr = {}
	self.m_CurrentScene = BaseAttrV1Data_pb.BaseAttrSceneInfoV1()
	self.m_GuildId = 0
	self.m_ExitGuildTime = 0
	self.m_ApplyGuildId = {}
	self.m_CurGuildContribution = 0
	self.m_MaxGuildContribution = 0
	self.m_BindMoney = 0
	self.m_Gem = 0
	self.m_ServerTime = 0
	self.m_NewbieGuide = {}
	self.m_ThiefRewardNum = 0
	self.m_SubdueMonsterRewardNum = 0
	self.m_WorldBossRemainTimes = 0
	self.m_WorldBossHurt = 0
	self.m_FunctionOpenList = {}
	self.m_TotalEnergyValue = 0
	self.m_EnergyArray = {}
	self.m_PKState = 0
	self.m_PKProtect = {}
	self.m_GuildScienArray = {}
	self.m_ScienceTotalMoney = 0


end

-- 更新数据
function BaseAttrModel:UpdateField(Id, data, Index, len)
	if  Id == BASEATTR_HEADID then
		local num = ReadVarint32(data)
		self.m_HeadID = num
	elseif  Id == BASEATTR_EXP then
		local num = ReadVarint32(data)
		self.m_Exp = num
	elseif  Id == BASEATTR_CREATETIME then
		local num = ReadVarint32(data)
		self.m_CreateTime = num
	elseif  Id == BASEATTR_LASTLOGINTIME then
		local num = ReadVarint32(data)
		self.m_LastLoginTime = num
	elseif  Id == BASEATTR_LAST2LOGINDATE then
		local num = ReadVarint32(data)
		self.m_Last2LoginDate = num
	elseif  Id == BASEATTR_LASTLOGOUTTIME then
		local num = ReadVarint32(data)
		self.m_LastLogoutTime = num
	elseif  Id == BASEATTR_MONEY then
		local num = ReadVarint32(data)
		self.m_Money = num
	elseif  Id == BASEATTR_DIAMOND then
		local num = ReadVarint32(data)
		self.m_Diamond = num
	elseif  Id == BASEATTR_STRENGTH then
		local num = ReadVarint32(data)
		self.m_Strength = num
	elseif  Id == BASEATTR_FEATS then
		local num = ReadVarint32(data)
		self.m_Feats = num
	elseif  Id == BASEATTR_GOTRANKREWARDTIME then
		local num = ReadVarint32(data)
		self.m_GotRankRewardTime = num
	elseif  Id == BASEATTR_MAXMILITARY then
		local num = ReadVarint32(data)
		self.m_MaxMilitary = num
	elseif  Id == BASEATTR_MASTERATTRS then
		if Index<0 then
			self.m_MasterAttrs = {}
		else
			local num = ReadVarint32(data)
			self.m_MasterAttrs[Index] = num
		end
	elseif  Id == BASEATTR_CURMILITARY then
		local num = ReadVarint32(data)
		self.m_CurMilitary = num
	elseif  Id == BASEATTR_USERNAME then
		self.m_UserName = tostring(data)
	elseif  Id == BASEATTR_USERID then
		local num = ReadVarint64(data)
		self.m_UserId = num
	elseif  Id == BASEATTR_PLATNAME then
		self.m_PlatName = tostring(data)
	elseif  Id == BASEATTR_ACCOUNTID then
		local num = ReadVarint64(data)
		self.m_AccountId = num
	elseif  Id == BASEATTR_LEVEL then
		local num = ReadVarint32(data)
		self.m_Level = num
	elseif  Id == BASEATTR_RANK then
		local num = ReadVarint32(data)
		self.m_Rank = num
	elseif  Id == BASEATTR_FIGHTPOWER then
		local num = ReadVarint32(data)
		self.m_FightPower = num
	elseif  Id == BASEATTR_SEC then
		local num = ReadVarint32(data)
		self.m_Sec = num
	elseif  Id == BASEATTR_MILITARY then
		local num = ReadVarint32(data)
		self.m_Military = num
	elseif  Id == BASEATTR_TEAMID then
		local num = ReadVarint32(data)
		self.m_TeamId = num
	elseif  Id == BASEATTR_PROF then
		local num = ReadVarint32(data)
		self.m_Prof = num
	elseif  Id == BASEATTR_DUNGEONREMAINCOUNT then
		local num = ReadVarint32(data)
		self.m_DungeonRemainCount = num
	elseif  Id == BASEATTR_MAPID then
		local num = ReadVarint32(data)
		self.m_MapId = num
	elseif  Id == BASEATTR_POSX then
		self.m_PosX:ParseFromString(data)
	elseif  Id == BASEATTR_POSY then
		self.m_PosY:ParseFromString(data)
	elseif  Id == BASEATTR_POSZ then
		self.m_PosZ:ParseFromString(data)
	elseif  Id == BASEATTR_RY then
		local num = ReadVarint32(data)
		self.m_Ry = num
	elseif  Id == BASEATTR_SKILLCDARR then
		if Index < 0 then
			self.m_SkillCdArr = {}
		else
			if self.m_SkillCdArr[Index] == nil then
				self.m_SkillCdArr[Index] = BaseAttrV1Data_pb.BaseAttrSkillCdInfoV1()
			end
			self.m_SkillCdArr[Index]:ParseFromString(data)
		end
	elseif  Id == BASEATTR_BUFFCDARR then
		if Index < 0 then
			self.m_BuffCdArr = {}
		else
			if self.m_BuffCdArr[Index] == nil then
				self.m_BuffCdArr[Index] = BaseAttrV1Data_pb.BaseAttrBuffCdInfoV1()
			end
			self.m_BuffCdArr[Index]:ParseFromString(data)
		end
	elseif  Id == BASEATTR_CURRENTSCENE then
		self.m_CurrentScene:ParseFromString(data)
	elseif  Id == BASEATTR_GUILDID then
		local num = ReadVarint32(data)
		self.m_GuildId = num
	elseif  Id == BASEATTR_EXITGUILDTIME then
		local num = ReadVarint32(data)
		self.m_ExitGuildTime = num
	elseif  Id == BASEATTR_APPLYGUILDID then
		if Index<0 then
			self.m_ApplyGuildId = {}
		else
			local num = ReadVarint32(data)
			self.m_ApplyGuildId[Index] = num
		end
	elseif  Id == BASEATTR_CURGUILDCONTRIBUTION then
		local num = ReadVarint32(data)
		self.m_CurGuildContribution = num
	elseif  Id == BASEATTR_MAXGUILDCONTRIBUTION then
		local num = ReadVarint32(data)
		self.m_MaxGuildContribution = num
	elseif  Id == BASEATTR_BINDMONEY then
		local num = ReadVarint32(data)
		self.m_BindMoney = num
	elseif  Id == BASEATTR_GEM then
		local num = ReadVarint32(data)
		self.m_Gem = num
	elseif  Id == BASEATTR_SERVERTIME then
		local num = ReadVarint32(data)
		self.m_ServerTime = num
	elseif  Id == BASEATTR_NEWBIEGUIDE then
		if Index < 0 then
			self.m_NewbieGuide = {}
		else
			if self.m_NewbieGuide[Index] == nil then
				self.m_NewbieGuide[Index] = BaseAttrV1Data_pb.BaseAttrKeyValue2IntIntV1()
			end
			self.m_NewbieGuide[Index]:ParseFromString(data)
		end
	elseif  Id == BASEATTR_THIEFREWARDNUM then
		local num = ReadVarint32(data)
		self.m_ThiefRewardNum = num
	elseif  Id == BASEATTR_SUBDUEMONSTERREWARDNUM then
		local num = ReadVarint32(data)
		self.m_SubdueMonsterRewardNum = num
	elseif  Id == BASEATTR_WORLDBOSSREMAINTIMES then
		local num = ReadVarint32(data)
		self.m_WorldBossRemainTimes = num
	elseif  Id == BASEATTR_WORLDBOSSHURT then
		local num = ReadVarint32(data)
		self.m_WorldBossHurt = num
	elseif  Id == BASEATTR_FUNCTIONOPENLIST then
		if Index < 0 then
			self.m_FunctionOpenList = {}
		else
			if self.m_FunctionOpenList[Index] == nil then
				self.m_FunctionOpenList[Index] = BaseAttrV1Data_pb.BaseAttrIconOpenInfoV1()
			end
			self.m_FunctionOpenList[Index]:ParseFromString(data)
		end
	elseif  Id == BASEATTR_TOTALENERGYVALUE then
		local num = ReadVarint32(data)
		self.m_TotalEnergyValue = num
	elseif  Id == BASEATTR_ENERGYARRAY then
		if Index < 0 then
			self.m_EnergyArray = {}
		else
			if self.m_EnergyArray[Index] == nil then
				self.m_EnergyArray[Index] = BaseAttrV1Data_pb.BaseAttrEnergyInfoV1()
			end
			self.m_EnergyArray[Index]:ParseFromString(data)
		end
	elseif  Id == BASEATTR_PKSTATE then
		local num = ReadVarint32(data)
		self.m_PKState = num
	elseif  Id == BASEATTR_PKPROTECT then
		if Index < 0 then
			self.m_PKProtect = {}
		else
			if self.m_PKProtect[Index] == nil then
				self.m_PKProtect[Index] = BaseAttrV1Data_pb.BaseAttrKeyValue2IntBoolV1()
			end
			self.m_PKProtect[Index]:ParseFromString(data)
		end
	elseif  Id == BASEATTR_GUILDSCIENARRAY then
		if Index < 0 then
			self.m_GuildScienArray = {}
		else
			if self.m_GuildScienArray[Index] == nil then
				self.m_GuildScienArray[Index] = BaseAttrV1Data_pb.BaseAttrScienceInfoV1()
			end
			self.m_GuildScienArray[Index]:ParseFromString(data)
		end
	elseif  Id == BASEATTR_SCIENCETOTALMONEY then
		local num = ReadVarint32(data)
		self.m_ScienceTotalMoney = num
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function BaseAttrModel:SyncData(_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_SYNCDATA_REQUEST, pb_data, callback)
end
function BaseAttrModel:GetRankReward(_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcGetRankRewardAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcGetRankRewardReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_GETRANKREWARD_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:UpGradeRank(_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcUpGradeRankAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcUpGradeRankReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_UPGRADERANK_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:ChooseRole(Prof,_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcChooseRoleAsk()
	PB.Prof = Prof
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcChooseRoleReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_CHOOSEROLE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:LevelUp(_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcLevelUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcLevelUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_LEVELUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:GetTimer(_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcGetTimerAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcGetTimerReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_GETTIMER_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:Revive(_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcReviveAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcReviveReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_REVIVE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:QueryEquip(UserId,Pos,TemplateID,Index,_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcQueryEquipAsk()
	PB.UserId = UserId
	PB.Pos = Pos
	PB.TemplateID = TemplateID
	PB.Index = Index
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcQueryEquipReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_QUERYEQUIP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:UpdateNewbieGuide(GroupId,Step,_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcUpdateNewbieGuideAsk()
	PB.GroupId = GroupId
	PB.Step = Step
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcUpdateNewbieGuideReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_UPDATENEWBIEGUIDE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:ChangPKState(ChangState,_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcChangPKStateAsk()
	PB.ChangState = ChangState
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcChangPKStateReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_CHANGPKSTATE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BaseAttrModel:ChangePKProtect(ProtectList,_hanlder)
	local PB = self.rpc_pb.BaseAttrRpcChangePKProtectAsk()
	for i,v in ipairs(ProtectList) do
		table.insert(PB.ProtectList,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BaseAttrRpcChangePKProtectReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BASEATTR_CHANGEPKPROTECT_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function BaseAttrModel:registerSysTipsCBNotify(_hanlder)
	if not self.SysTipsCBNotifyCallBack then
		self.SysTipsCBNotifyCallBack = {}
	end
	table.insert(self.SysTipsCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BaseAttrModel:SysTipsCB(notifyMsg)
	if self.SysTipsCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BaseAttrRpcSysTipsNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.SysTipsCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function BaseAttrModel:unregisterSysTipsCBNotify(_hanlder)
	if nil ~= self.SysTipsCBNotifyCallBack then
		for i,callback in ipairs(self.SysTipsCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.SysTipsCBNotifyCallBack, i )
			end
		end
	end
end





askList.BaseAttr = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = BaseAttrModel.SyncData
t.pb = BaseAttrRpc_pb.BaseAttrRpcSyncDataAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "GetRankReward"
t.para = {}
t.hand = BaseAttrModel.GetRankReward
t.pb = BaseAttrRpc_pb.BaseAttrRpcGetRankRewardAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "UpGradeRank"
t.para = {}
t.hand = BaseAttrModel.UpGradeRank
t.pb = BaseAttrRpc_pb.BaseAttrRpcUpGradeRankAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "ChooseRole"
t.para = {{name="Prof",t=1}}
t.hand = BaseAttrModel.ChooseRole
t.pb = BaseAttrRpc_pb.BaseAttrRpcChooseRoleAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "LevelUp"
t.para = {}
t.hand = BaseAttrModel.LevelUp
t.pb = BaseAttrRpc_pb.BaseAttrRpcLevelUpAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "GetTimer"
t.para = {}
t.hand = BaseAttrModel.GetTimer
t.pb = BaseAttrRpc_pb.BaseAttrRpcGetTimerAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "Revive"
t.para = {}
t.hand = BaseAttrModel.Revive
t.pb = BaseAttrRpc_pb.BaseAttrRpcReviveAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "QueryEquip"
t.para = {{name="UserId",t=1},{name="Pos",t=1},{name="TemplateID",t=1},{name="Index",t=1}}
t.hand = BaseAttrModel.QueryEquip
t.pb = BaseAttrRpc_pb.BaseAttrRpcQueryEquipAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "UpdateNewbieGuide"
t.para = {{name="GroupId",t=1},{name="Step",t=1}}
t.hand = BaseAttrModel.UpdateNewbieGuide
t.pb = BaseAttrRpc_pb.BaseAttrRpcUpdateNewbieGuideAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "ChangPKState"
t.para = {{name="ChangState",t=1}}
t.hand = BaseAttrModel.ChangPKState
t.pb = BaseAttrRpc_pb.BaseAttrRpcChangPKStateAsk()
table.insert(askList.BaseAttr,t)

local t = {}
t.name = "ChangePKProtect"
t.para = {{name="ProtectList",t=3}}
t.hand = BaseAttrModel.ChangePKProtect
t.pb = BaseAttrRpc_pb.BaseAttrRpcChangePKProtectAsk()
table.insert(askList.BaseAttr,t)

