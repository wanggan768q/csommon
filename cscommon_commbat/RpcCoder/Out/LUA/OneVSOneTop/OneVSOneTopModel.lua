--将变量写入下方
local ModuleId = 42;





require("app.OneVSOneTop.OneVSOneTopRpc_pb")

OneVSOneTopModel = class("OneVSOneTopModel",BaseModel)

function OneVSOneTopModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=OneVSOneTopModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function OneVSOneTopModel:ctor()
	OneVSOneTopModel.super.ctor(self)
	self.rpc_pb = OneVSOneTopRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function OneVSOneTopModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.OneVSOneTop = {}

