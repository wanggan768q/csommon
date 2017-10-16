--将变量写入下方
local ModuleId = 29;
local RPC_CODE_SKILL_SYNCDATA_REQUEST = 2951
local RPC_CODE_SKILL_LEARN_REQUEST = 2952
local RPC_CODE_SKILL_LVUP_REQUEST = 2953
local RPC_CODE_SKILL_CHANGESHORTCUT_REQUEST = 2954
local RPC_CODE_SKILL_USESHORTCUT_REQUEST = 2955
local RPC_CODE_SKILL_ONEKEYLVUP_REQUEST = 2956
local RPC_CODE_SKILL_TALENTLVUP_REQUEST = 2957
local RPC_CODE_SKILL_TALENTCHANGESKILL_REQUEST = 2958
local RPC_CODE_SKILL_TALENTRESET_REQUEST = 2959
local RPC_CODE_SKILL_LIFESKILLUP_REQUEST = 2960


SKILL_SKILLARRAY = 2901
SKILL_SHORTCUTARRAY = 2902
SKILL_SHORTCUTID = 2903
SKILL_TALENTSKILL = 2904
SKILL_TOTALCOSTEXP = 2905
SKILL_TALENTLEVEL = 2906
SKILL_TALENTPOINT = 2907
SKILL_LIFESKILLARRAY = 2908


require("app.Skill.SkillV1Data_pb")
require("app.Skill.SkillRpc_pb")

SkillModel = class("SkillModel",BaseModel)

function SkillModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=SkillModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function SkillModel:ctor()
	SkillModel.super.ctor(self)
	self.rpc_pb = SkillRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=SkillV1Data_pb
	self.m_SkillArray = {}
	self.m_ShortcutArray = {}
	self.m_ShortcutId = 0
	self.m_TalentSkill = {}
	self.m_TotalCostExp = 0
	self.m_TalentLevel = 0
	self.m_TalentPoint = 0
	self.m_LifeSkillArray = {}


end

-- 更新数据
function SkillModel:UpdateField(Id, data, Index, len)
	if  Id == SKILL_SKILLARRAY then
		if Index < 0 then
			self.m_SkillArray = {}
		else
			if self.m_SkillArray[Index] == nil then
				self.m_SkillArray[Index] = SkillV1Data_pb.SkillSkillObjV1()
			end
			self.m_SkillArray[Index]:ParseFromString(data)
		end
	elseif  Id == SKILL_SHORTCUTARRAY then
		if Index < 0 then
			self.m_ShortcutArray = {}
		else
			if self.m_ShortcutArray[Index] == nil then
				self.m_ShortcutArray[Index] = SkillV1Data_pb.SkillShortcutObjV1()
			end
			self.m_ShortcutArray[Index]:ParseFromString(data)
		end
	elseif  Id == SKILL_SHORTCUTID then
		local num = ReadVarint32(data)
		self.m_ShortcutId = num
	elseif  Id == SKILL_TALENTSKILL then
		if Index < 0 then
			self.m_TalentSkill = {}
		else
			if self.m_TalentSkill[Index] == nil then
				self.m_TalentSkill[Index] = SkillV1Data_pb.SkillTalentSlotV1()
			end
			self.m_TalentSkill[Index]:ParseFromString(data)
		end
	elseif  Id == SKILL_TOTALCOSTEXP then
		local num = ReadVarint32(data)
		self.m_TotalCostExp = num
	elseif  Id == SKILL_TALENTLEVEL then
		local num = ReadVarint32(data)
		self.m_TalentLevel = num
	elseif  Id == SKILL_TALENTPOINT then
		local num = ReadVarint32(data)
		self.m_TalentPoint = num
	elseif  Id == SKILL_LIFESKILLARRAY then
		if Index < 0 then
			self.m_LifeSkillArray = {}
		else
			if self.m_LifeSkillArray[Index] == nil then
				self.m_LifeSkillArray[Index] = SkillV1Data_pb.SkillSkillObjV1()
			end
			self.m_LifeSkillArray[Index]:ParseFromString(data)
		end
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function SkillModel:SyncData(_hanlder)
	local PB = self.rpc_pb.SkillRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_SYNCDATA_REQUEST, pb_data, callback)
end
function SkillModel:Learn(SkillId,_hanlder)
	local PB = self.rpc_pb.SkillRpcLearnAsk()
	PB.SkillId = SkillId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcLearnReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_LEARN_REQUEST, pb_data, callback)
	self:showNetTip()
end
function SkillModel:LvUp(SkillId,_hanlder)
	local PB = self.rpc_pb.SkillRpcLvUpAsk()
	PB.SkillId = SkillId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcLvUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_LVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function SkillModel:ChangeShortcut(SkillId,Pos,Id,_hanlder)
	local PB = self.rpc_pb.SkillRpcChangeShortcutAsk()
	PB.SkillId = SkillId
	PB.Pos = Pos
	PB.Id = Id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcChangeShortcutReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_CHANGESHORTCUT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function SkillModel:UseShortcut(Id,_hanlder)
	local PB = self.rpc_pb.SkillRpcUseShortcutAsk()
	PB.Id = Id
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcUseShortcutReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_USESHORTCUT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function SkillModel:OneKeyLvUp(SkillId,_hanlder)
	local PB = self.rpc_pb.SkillRpcOneKeyLvUpAsk()
	PB.SkillId = SkillId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcOneKeyLvUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_ONEKEYLVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function SkillModel:TalentLvUp(Talent,_hanlder)
	local PB = self.rpc_pb.SkillRpcTalentLvUpAsk()
	for i,v in ipairs(Talent) do
		table.insert(PB.Talent,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcTalentLvUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_TALENTLVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function SkillModel:TalentChangeSkill(Index,SkillId,_hanlder)
	local PB = self.rpc_pb.SkillRpcTalentChangeSkillAsk()
	PB.Index = Index
	PB.SkillId = SkillId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcTalentChangeSkillReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_TALENTCHANGESKILL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function SkillModel:TalentReset(_hanlder)
	local PB = self.rpc_pb.SkillRpcTalentResetAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcTalentResetReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_TALENTRESET_REQUEST, pb_data, callback)
	self:showNetTip()
end
function SkillModel:LifeSkillUp(LifeSkillId,_hanlder)
	local PB = self.rpc_pb.SkillRpcLifeSkillUpAsk()
	PB.LifeSkillId = LifeSkillId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.SkillRpcLifeSkillUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SKILL_LIFESKILLUP_REQUEST, pb_data, callback)
	self:showNetTip()
end








askList.Skill = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = SkillModel.SyncData
t.pb = SkillRpc_pb.SkillRpcSyncDataAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "Learn"
t.para = {{name="SkillId",t=1}}
t.hand = SkillModel.Learn
t.pb = SkillRpc_pb.SkillRpcLearnAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "LvUp"
t.para = {{name="SkillId",t=1}}
t.hand = SkillModel.LvUp
t.pb = SkillRpc_pb.SkillRpcLvUpAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "ChangeShortcut"
t.para = {{name="SkillId",t=1},{name="Pos",t=1},{name="Id",t=1}}
t.hand = SkillModel.ChangeShortcut
t.pb = SkillRpc_pb.SkillRpcChangeShortcutAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "UseShortcut"
t.para = {{name="Id",t=1}}
t.hand = SkillModel.UseShortcut
t.pb = SkillRpc_pb.SkillRpcUseShortcutAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "OneKeyLvUp"
t.para = {{name="SkillId",t=1}}
t.hand = SkillModel.OneKeyLvUp
t.pb = SkillRpc_pb.SkillRpcOneKeyLvUpAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "TalentLvUp"
t.para = {{name="Talent",t=3}}
t.hand = SkillModel.TalentLvUp
t.pb = SkillRpc_pb.SkillRpcTalentLvUpAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "TalentChangeSkill"
t.para = {{name="Index",t=1},{name="SkillId",t=1}}
t.hand = SkillModel.TalentChangeSkill
t.pb = SkillRpc_pb.SkillRpcTalentChangeSkillAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "TalentReset"
t.para = {}
t.hand = SkillModel.TalentReset
t.pb = SkillRpc_pb.SkillRpcTalentResetAsk()
table.insert(askList.Skill,t)

local t = {}
t.name = "LifeSkillUp"
t.para = {{name="LifeSkillId",t=1}}
t.hand = SkillModel.LifeSkillUp
t.pb = SkillRpc_pb.SkillRpcLifeSkillUpAsk()
table.insert(askList.Skill,t)

