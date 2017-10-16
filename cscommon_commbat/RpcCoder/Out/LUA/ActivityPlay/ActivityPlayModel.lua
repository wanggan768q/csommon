--将变量写入下方
local ModuleId = 38;





require("app.ActivityPlay.ActivityPlayRpc_pb")

ActivityPlayModel = class("ActivityPlayModel",BaseModel)

function ActivityPlayModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ActivityPlayModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ActivityPlayModel:ctor()
	ActivityPlayModel.super.ctor(self)
	self.rpc_pb = ActivityPlayRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  


end

-- 更新数据
function ActivityPlayModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.ActivityPlay = {}

