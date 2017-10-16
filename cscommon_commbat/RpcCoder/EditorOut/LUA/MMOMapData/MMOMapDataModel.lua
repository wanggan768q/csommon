--将变量写入下方
local ModuleId = 21;




require("app.MMOMapData.MMOMapDataV1Data_pb")
require("app.MMOMapData.MMOMapDataRpc_pb")

MMOMapDataModel = class("MMOMapDataModel",BaseModel)

function MMOMapDataModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MMOMapDataModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function MMOMapDataModel:ctor()
	MMOMapDataModel.super.ctor(self)
	self.rpc_pb = MMOMapDataRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=MMOMapDataV1Data_pb


end

-- 更新数据
function MMOMapDataModel:UpdateField(Id, data, Index, len)
	if
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.MMOMapData = {}

