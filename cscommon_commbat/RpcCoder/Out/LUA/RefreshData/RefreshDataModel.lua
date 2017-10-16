--将变量写入下方
local ModuleId = 39;


REFRESHDATA_LASTREFRESHTIME = 3901


require("app.RefreshData.RefreshDataV1Data_pb")
require("app.RefreshData.RefreshDataRpc_pb")

RefreshDataModel = class("RefreshDataModel",BaseModel)

function RefreshDataModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=RefreshDataModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function RefreshDataModel:ctor()
	RefreshDataModel.super.ctor(self)
	self.rpc_pb = RefreshDataRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=RefreshDataV1Data_pb
	self.m_LastRefreshTime = 0


end

-- 更新数据
function RefreshDataModel:UpdateField(Id, data, Index, len)
	if  Id == REFRESHDATA_LASTREFRESHTIME then
		local num = ReadVarint32(data)
		self.m_LastRefreshTime = num
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件








askList.RefreshData = {}

