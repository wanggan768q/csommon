--将变量写入下方
local ModuleId = 31;
local RPC_CODE_ACTIVITYESCAPE_SIGNUP_REQUEST = 3151





require("app.ActivityEscape.ActivityEscapeRpc_pb")

ActivityEscapeModel = class("ActivityEscapeModel",BaseModel)

function ActivityEscapeModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityEscapeModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ActivityEscapeModel:ctor()
	ActivityEscapeModel.super.ctor(self)
	self.rpc_pb = ActivityEscapeRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function ActivityEscapeModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function ActivityEscapeModel:SignUp(_hanlder)
	local PB = self.rpc_pb.ActivityEscapeRpcSignUpAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ActivityEscapeRpcSignUpReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_ACTIVITYESCAPE_SIGNUP_REQUEST, pb_data, callback)
	self:showNetTip()
end








askList.ActivityEscape = {}

local t = {}
t.name = "SignUp"
t.para = {}
t.hand = ActivityEscapeModel.SignUp
t.pb = ActivityEscapeRpc_pb.ActivityEscapeRpcSignUpAsk()
table.insert(askList.ActivityEscape,t)

