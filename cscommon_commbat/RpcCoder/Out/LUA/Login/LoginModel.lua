--将变量写入下方
local ModuleId = 5;
local RPC_CODE_LOGIN_KEYAUTH_REQUEST = 551
local RPC_CODE_LOGIN_KICKOFF_NOTIFY = 552;





require("app.Login.LoginRpc_pb")

LoginModel = class("LoginModel",BaseModel)

function LoginModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=LoginModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function LoginModel:ctor()
	LoginModel.super.ctor(self)
	self.rpc_pb = LoginRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_LOGIN_KICKOFF_NOTIFY,handler(self,self.KickOffCB))

  


end

-- 更新数据
function LoginModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function LoginModel:KeyAuth(DistId,RsaData,_hanlder)
	local PB = self.rpc_pb.LoginRpcKeyAuthAsk()
	PB.DistId = DistId
	PB.RsaData = RsaData
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.LoginRpcKeyAuthReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_LOGIN_KEYAUTH_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function LoginModel:registerKickOffCBNotify(_hanlder)
	if not self.KickOffCBNotifyCallBack then
		self.KickOffCBNotifyCallBack = {}
	end
	table.insert(self.KickOffCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function LoginModel:KickOffCB(notifyMsg)
	if self.KickOffCBNotifyCallBack then
		local ret_msg = self.rpc_pb.LoginRpcKickOffNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.KickOffCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function LoginModel:unregisterKickOffCBNotify(_hanlder)
	if nil ~= self.KickOffCBNotifyCallBack then
		for i,callback in ipairs(self.KickOffCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.KickOffCBNotifyCallBack, i )
			end
		end
	end
end





askList.Login = {}

local t = {}
t.name = "KeyAuth"
t.para = {{name="DistId",t=1},{name="RsaData",t=2}}
t.hand = LoginModel.KeyAuth
t.pb = LoginRpc_pb.LoginRpcKeyAuthAsk()
table.insert(askList.Login,t)

