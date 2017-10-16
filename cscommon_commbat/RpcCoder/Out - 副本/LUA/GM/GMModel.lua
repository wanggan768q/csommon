--将变量写入下方
local ModuleId = 17;
local RPC_CODE_GM_ACTION_REQUEST = 1751





require("app.GM.GMRpc_pb")

GMModel = class("GMModel",BaseModel)

function GMModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=GMModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function GMModel:ctor()
	GMModel.super.ctor(self)
	self.rpc_pb = GMRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function GMModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function GMModel:Action(Value,_hanlder)
	local PB = self.rpc_pb.GMRpcActionAsk()
	PB.Value = Value
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.GMRpcActionReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_GM_ACTION_REQUEST, pb_data, callback)
	self:showNetTip()
end








askList.GM = {}

local t = {}
t.name = "Action"
t.para = {{name="Value",t=2}}
t.hand = GMModel.Action
t.pb = GMRpc_pb.GMRpcActionAsk()
table.insert(askList.GM,t)

