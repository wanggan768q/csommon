--将变量写入下方
local ModuleId = 35;
local RPC_CODE_DROPITEM_DROPITEMNOTICE_NOTIFY = 3551;
local RPC_CODE_DROPITEM_PICKUPITEM_REQUEST = 3552
local RPC_CODE_DROPITEM_DELDROPITEM_NOTIFY = 3553;





require("app.DropItem.DropItemRpc_pb")

DropItemModel = class("DropItemModel",BaseModel)

function DropItemModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=DropItemModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function DropItemModel:ctor()
	DropItemModel.super.ctor(self)
	self.rpc_pb = DropItemRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_DROPITEM_DROPITEMNOTICE_NOTIFY,handler(self,self.DropItemNoticeCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_DROPITEM_DELDROPITEM_NOTIFY,handler(self,self.DelDropItemCB))

  


end

-- 更新数据
function DropItemModel:UpdateField(Id, data, Index, len)

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function DropItemModel:PickupItem(UId,_hanlder)
	local PB = self.rpc_pb.DropItemRpcPickupItemAsk()
	PB.UId = UId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.DropItemRpcPickupItemReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_DROPITEM_PICKUPITEM_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function DropItemModel:registerDropItemNoticeCBNotify(_hanlder)
	if not self.DropItemNoticeCBNotifyCallBack then
		self.DropItemNoticeCBNotifyCallBack = {}
	end
	table.insert(self.DropItemNoticeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DropItemModel:DropItemNoticeCB(notifyMsg)
	if self.DropItemNoticeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DropItemRpcDropItemNoticeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DropItemNoticeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function DropItemModel:unregisterDropItemNoticeCBNotify(_hanlder)
	if nil ~= self.DropItemNoticeCBNotifyCallBack then
		for i,callback in ipairs(self.DropItemNoticeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DropItemNoticeCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function DropItemModel:registerDelDropItemCBNotify(_hanlder)
	if not self.DelDropItemCBNotifyCallBack then
		self.DelDropItemCBNotifyCallBack = {}
	end
	table.insert(self.DelDropItemCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function DropItemModel:DelDropItemCB(notifyMsg)
	if self.DelDropItemCBNotifyCallBack then
		local ret_msg = self.rpc_pb.DropItemRpcDelDropItemNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.DelDropItemCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function DropItemModel:unregisterDelDropItemCBNotify(_hanlder)
	if nil ~= self.DelDropItemCBNotifyCallBack then
		for i,callback in ipairs(self.DelDropItemCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.DelDropItemCBNotifyCallBack, i )
			end
		end
	end
end





askList.DropItem = {}

local t = {}
t.name = "PickupItem"
t.para = {{name="UId",t=1}}
t.hand = DropItemModel.PickupItem
t.pb = DropItemRpc_pb.DropItemRpcPickupItemAsk()
table.insert(askList.DropItem,t)

