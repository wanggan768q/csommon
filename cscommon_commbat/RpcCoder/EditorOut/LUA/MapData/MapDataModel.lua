--将变量写入下方
local ModuleId = 20;


MAPDATA_X1 = 2001


require("app.MapData.MapDataV1Data_pb")
require("app.MapData.MapDataRpc_pb")

MapDataModel = class("MapDataModel",BaseModel)

function MapDataModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=MapDataModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function MapDataModel:ctor()
	MapDataModel.super.ctor(self)
	self.rpc_pb = MapDataRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=MapDataV1Data_pb
	self.m_X1 = 0


end

-- 更新数据
function MapDataModel:UpdateField(Id, data, Index, len)
	if  Id == MAPDATA_X1 then
		local num = ReadVarint32(data)
		self.m_X1 = num
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.MapData = {}

