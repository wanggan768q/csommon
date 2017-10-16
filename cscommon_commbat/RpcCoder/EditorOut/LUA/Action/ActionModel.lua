--将变量写入下方
local ModuleId = 1;




require("app.Action.ActionV1Data_pb")
require("app.Action.ActionRpc_pb")

ActionModel = class("ActionModel",BaseModel)

function ActionModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActionModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ActionModel:ctor()
	ActionModel.super.ctor(self)
	self.rpc_pb = ActionRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=ActionV1Data_pb


end

-- 更新数据
function ActionModel:UpdateField(Id, data, Index, len)
	if
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.Action = {}

