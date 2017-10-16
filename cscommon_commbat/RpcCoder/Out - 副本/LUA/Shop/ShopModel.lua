--将变量写入下方
local ModuleId = 22;
local RPC_CODE_SHOP_SYNCDATA_REQUEST = 2251
local RPC_CODE_SHOP_BUY_REQUEST = 2252
local RPC_CODE_SHOP_REFRESHITEM_REQUEST = 2253


SHOP_SHOPARRAY = 2201


require("app.Shop.ShopV1Data_pb")
require("app.Shop.ShopRpc_pb")

ShopModel = class("ShopModel",BaseModel)

function ShopModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=ShopModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function ShopModel:ctor()
	ShopModel.super.ctor(self)
	self.rpc_pb = ShopRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))

  
	self.data_pb=ShopV1Data_pb
	self.m_ShopArray = {}


end

-- 更新数据
function ShopModel:UpdateField(Id, data, Index, len)
	if  Id == SHOP_SHOPARRAY then
		if Index < 0 then
			self.m_ShopArray = {}
		else
			if self.m_ShopArray[Index] == nil then
				self.m_ShopArray[Index] = ShopV1Data_pb.ShopShopObjV1()
			end
			self.m_ShopArray[Index]:ParseFromString(data)
		end
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function ShopModel:SyncData(_hanlder)
	local PB = self.rpc_pb.ShopRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.ShopRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SHOP_SYNCDATA_REQUEST, pb_data, callback)
end
function ShopModel:Buy(ShopType,ItemId,Pos,_hanlder)
	local PB = self.rpc_pb.ShopRpcBuyAsk()
	PB.ShopType = ShopType
	PB.ItemId = ItemId
	PB.Pos = Pos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ShopRpcBuyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SHOP_BUY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function ShopModel:RefreshItem(ShopType,_hanlder)
	local PB = self.rpc_pb.ShopRpcRefreshItemAsk()
	PB.ShopType = ShopType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.ShopRpcRefreshItemReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_SHOP_REFRESHITEM_REQUEST, pb_data, callback)
	self:showNetTip()
end








askList.Shop = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = ShopModel.SyncData
t.pb = ShopRpc_pb.ShopRpcSyncDataAsk()
table.insert(askList.Shop,t)

local t = {}
t.name = "Buy"
t.para = {{name="ShopType",t=1},{name="ItemId",t=1},{name="Pos",t=1}}
t.hand = ShopModel.Buy
t.pb = ShopRpc_pb.ShopRpcBuyAsk()
table.insert(askList.Shop,t)

local t = {}
t.name = "RefreshItem"
t.para = {{name="ShopType",t=1}}
t.hand = ShopModel.RefreshItem
t.pb = ShopRpc_pb.ShopRpcRefreshItemAsk()
table.insert(askList.Shop,t)

