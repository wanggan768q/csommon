--将变量写入下方
local ModuleId = 14;
local RPC_CODE_BAG_SYNCDATA_REQUEST = 1451
local RPC_CODE_BAG_SELL_REQUEST = 1452
local RPC_CODE_BAG_DECOMPOSE_REQUEST = 1453
local RPC_CODE_BAG_USE_REQUEST = 1454
local RPC_CODE_BAG_EQUIPWEAR_REQUEST = 1455
local RPC_CODE_BAG_EQUIPUNDRESS_REQUEST = 1456
local RPC_CODE_BAG_EQUIPENHANCE_REQUEST = 1457
local RPC_CODE_BAG_EQUIPPOLISHED_REQUEST = 1458
local RPC_CODE_BAG_EQUIPPOLISHEDREPLACE_REQUEST = 1459
local RPC_CODE_BAG_BAGTIDY_REQUEST = 1460
local RPC_CODE_BAG_BAGRECYCLESELL_REQUEST = 1461
local RPC_CODE_BAG_BAGRECYCLEBUY_REQUEST = 1462
local RPC_CODE_BAG_UNLOCKGRID_REQUEST = 1463
local RPC_CODE_BAG_SPLIT_REQUEST = 1464
local RPC_CODE_BAG_EQUIPBASEATTRPLISHED_REQUEST = 1465
local RPC_CODE_BAG_EQUIPBASEATTRPOLISHEDREPLACE_REQUEST = 1466
local RPC_CODE_BAG_EQUIPEXATTRMODIFY_REQUEST = 1467
local RPC_CODE_BAG_EQUIPINLAYGEM_REQUEST = 1468
local RPC_CODE_BAG_EQUIPGEMSLOTUNLOCK_REQUEST = 1469
local RPC_CODE_BAG_EQUIPENHANCESWAP_REQUEST = 1470
local RPC_CODE_BAG_EQUIPGEMREMOVE_REQUEST = 1471
local RPC_CODE_BAG_BAGPUTINSTORAGE_REQUEST = 1472
local RPC_CODE_BAG_BAGFETCHFROMSTORAGE_REQUEST = 1473
local RPC_CODE_BAG_BAGSTORAGESAVEMONEY_REQUEST = 1474
local RPC_CODE_BAG_BAGSTORAGEDRAWMONEY_REQUEST = 1475
local RPC_CODE_BAG_STORAGETIDY_REQUEST = 1476
local RPC_CODE_BAG_TALISMANLVUP_REQUEST = 1477
local RPC_CODE_BAG_TALISMANINHERIT_REQUEST = 1478
local RPC_CODE_BAG_BAGADDNEWITEM_NOTIFY = 1479;
local RPC_CODE_BAG_BAGSETAUTOPICKUP_REQUEST = 1480
local RPC_CODE_BAG_GETNEWITEM_NOTIFY = 1481;
local RPC_CODE_BAG_BAGERROR_NOTIFY = 1482;
local RPC_CODE_BAG_TALISMANREFINDSTAR_REQUEST = 1483
local RPC_CODE_BAG_TALISMANUPSLOTSKILLLEVEL_REQUEST = 1484
local RPC_CODE_BAG_TALISMANATTRCHANGE_NOTIFY = 1485;
local RPC_CODE_BAG_TALISMANGATHERSPRITE_REQUEST = 1486


BAG_GRIDARRAY = 1401
BAG_EQUIPALLDATA = 1404
BAG_WEAREQUIPCONTAINER = 1405
BAG_STORAGEBAGGRID = 1407
BAG_STORAGEBANK = 1408
BAG_TALISMANDATA = 1409
BAG_TALISMANFOREVERATTR = 1410
BAG_AUTOPICKUP = 1411
BAG_USEITEMDAY = 1415
BAG_USEITEMWEEK = 1416


require("app.Bag.BagV1Data_pb")
require("app.Bag.BagRpc_pb")

BagModel = class("BagModel",BaseModel)

function BagModel:getInstance( ... )
	-- body
	if self.instance==nil then 
		self.instance=BagModel.new()
	end 
	return self.instance
end

-- 初始化 向MLayerMgr注册 更新数据 和 消息通知的 回调
function BagModel:ctor()
	BagModel.super.ctor(self)
	self.rpc_pb = BagRpc_pb
  --注册
  MLayerMgr.RegUpdateHd(ModuleId, handler(self,self.UpdateField))
	MLayerMgr.RegNotifyHd(RPC_CODE_BAG_BAGADDNEWITEM_NOTIFY,handler(self,self.BagAddNewItemCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_BAG_GETNEWITEM_NOTIFY,handler(self,self.GetNewItemCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_BAG_BAGERROR_NOTIFY,handler(self,self.BagErrorCB))
	MLayerMgr.RegNotifyHd(RPC_CODE_BAG_TALISMANATTRCHANGE_NOTIFY,handler(self,self.TalismanAttrChangeCB))

  
	self.data_pb=BagV1Data_pb
	self.m_GridArray = {}
	self.m_EquipAllData = {}
	self.m_WearEquipContainer = {}
	self.m_StorageBagGrid = {}
	self.m_StorageBank = 0
	self.m_TalismanData = {}
	self.m_TalismanForeverAttr = {}
	self.m_AutoPickup = {}
	self.m_UseItemDay = {}
	self.m_UseItemWeek = {}


end

-- 更新数据
function BagModel:UpdateField(Id, data, Index, len)
	if  Id == BAG_GRIDARRAY then
		if Index < 0 then
			self.m_GridArray = {}
		else
			if self.m_GridArray[Index] == nil then
				self.m_GridArray[Index] = BagV1Data_pb.BagGridInfoV1()
			end
			self.m_GridArray[Index]:ParseFromString(data)
		end
	elseif  Id == BAG_EQUIPALLDATA then
		if Index < 0 then
			self.m_EquipAllData = {}
		else
			if self.m_EquipAllData[Index] == nil then
				self.m_EquipAllData[Index] = BagV1Data_pb.BagBagEquipObjV1()
			end
			self.m_EquipAllData[Index]:ParseFromString(data)
		end
	elseif  Id == BAG_WEAREQUIPCONTAINER then
		if Index < 0 then
			self.m_WearEquipContainer = {}
		else
			if self.m_WearEquipContainer[Index] == nil then
				self.m_WearEquipContainer[Index] = BagV1Data_pb.BagGridInfoV1()
			end
			self.m_WearEquipContainer[Index]:ParseFromString(data)
		end
	elseif  Id == BAG_STORAGEBAGGRID then
		if Index < 0 then
			self.m_StorageBagGrid = {}
		else
			if self.m_StorageBagGrid[Index] == nil then
				self.m_StorageBagGrid[Index] = BagV1Data_pb.BagGridInfoV1()
			end
			self.m_StorageBagGrid[Index]:ParseFromString(data)
		end
	elseif  Id == BAG_STORAGEBANK then
		local num = ReadVarint32(data)
		self.m_StorageBank = num
	elseif  Id == BAG_TALISMANDATA then
		if Index < 0 then
			self.m_TalismanData = {}
		else
			if self.m_TalismanData[Index] == nil then
				self.m_TalismanData[Index] = BagV1Data_pb.BagTalismanObjV1()
			end
			self.m_TalismanData[Index]:ParseFromString(data)
		end
	elseif  Id == BAG_TALISMANFOREVERATTR then
		if Index<0 then
			self.m_TalismanForeverAttr = {}
		else
			local num = ReadVarint32(data)
			self.m_TalismanForeverAttr[Index] = num
		end
	elseif  Id == BAG_AUTOPICKUP then
		if Index < 0 then
			self.m_AutoPickup = {}
		else
			if self.m_AutoPickup[Index] == nil then
				self.m_AutoPickup[Index] = BagV1Data_pb.BagKeyValue2IntBoolV1()
			end
			self.m_AutoPickup[Index]:ParseFromString(data)
		end
	elseif  Id == BAG_USEITEMDAY then
		if Index < 0 then
			self.m_UseItemDay = {}
		else
			if self.m_UseItemDay[Index] == nil then
				self.m_UseItemDay[Index] = BagV1Data_pb.BagKeyValue2IntIntV1()
			end
			self.m_UseItemDay[Index]:ParseFromString(data)
		end
	elseif  Id == BAG_USEITEMWEEK then
		if Index < 0 then
			self.m_UseItemWeek = {}
		else
			if self.m_UseItemWeek[Index] == nil then
				self.m_UseItemWeek[Index] = BagV1Data_pb.BagKeyValue2IntIntV1()
			end
			self.m_UseItemWeek[Index]:ParseFromString(data)
		end
	else
		 print("error Updata")
	end

	
	self:dataCallback(Id,Index)
end


-- 业务事件
function BagModel:SyncData(_hanlder)
	local PB = self.rpc_pb.BagRpcSyncDataAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcSyncDataReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_SYNCDATA_REQUEST, pb_data, callback)
end
function BagModel:Sell(ItemID,Pos,Num,_hanlder)
	local PB = self.rpc_pb.BagRpcSellAsk()
	PB.ItemID = ItemID
	PB.Pos = Pos
	PB.Num = Num
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcSellReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_SELL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:Decompose(ItemID,Pos,_hanlder)
	local PB = self.rpc_pb.BagRpcDecomposeAsk()
	PB.ItemID = ItemID
	PB.Pos = Pos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcDecomposeReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_DECOMPOSE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:Use(ItemID,Pos,_hanlder)
	local PB = self.rpc_pb.BagRpcUseAsk()
	PB.ItemID = ItemID
	PB.Pos = Pos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcUseReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_USE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipWear(ItemId,BagPos,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipWearAsk()
	PB.ItemId = ItemId
	PB.BagPos = BagPos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipWearReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPWEAR_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipUndress(ItemId,EquipPos,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipUndressAsk()
	PB.ItemId = ItemId
	PB.EquipPos = EquipPos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipUndressReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPUNDRESS_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipEnhance(ItemId,Pos,BagContainerType,Lv,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipEnhanceAsk()
	PB.ItemId = ItemId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	PB.Lv = Lv
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipEnhanceReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPENHANCE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipPolished(ItemId,Pos,BagContainerType,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipPolishedAsk()
	PB.ItemId = ItemId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipPolishedReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPPOLISHED_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipPolishedReplace(ItemId,Pos,BagContainerType,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipPolishedReplaceAsk()
	PB.ItemId = ItemId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipPolishedReplaceReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPPOLISHEDREPLACE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:BagTidy(_hanlder)
	local PB = self.rpc_pb.BagRpcBagTidyAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagTidyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGTIDY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:BagRecycleSell(GridList,_hanlder)
	local PB = self.rpc_pb.BagRpcBagRecycleSellAsk()
	for i,v in ipairs(GridList) do
		table.insert(PB.GridList,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagRecycleSellReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGRECYCLESELL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:BagRecycleBuy(GridPos,_hanlder)
	local PB = self.rpc_pb.BagRpcBagRecycleBuyAsk()
	PB.GridPos = GridPos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagRecycleBuyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGRECYCLEBUY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:UnlockGrid(GridCount,_hanlder)
	local PB = self.rpc_pb.BagRpcUnlockGridAsk()
	PB.GridCount = GridCount
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcUnlockGridReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_UNLOCKGRID_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:Split(TemplateId,Pos,Num,_hanlder)
	local PB = self.rpc_pb.BagRpcSplitAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.Num = Num
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcSplitReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_SPLIT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipBaseAttrPlished(TemplateId,Pos,BagContainerType,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipBaseAttrPlishedAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipBaseAttrPlishedReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPBASEATTRPLISHED_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipBaseAttrPolishedReplace(TemplateId,Pos,BagContainerType,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipBaseAttrPolishedReplaceAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipBaseAttrPolishedReplaceReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPBASEATTRPOLISHEDREPLACE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipExAttrModify(TemplateId,Pos,BagContainerType,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipExAttrModifyAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipExAttrModifyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPEXATTRMODIFY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipInlayGem(TemplateId,Pos,BagContainerType,SlotPos,GemId,GemPos,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipInlayGemAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	PB.SlotPos = SlotPos
	PB.GemId = GemId
	PB.GemPos = GemPos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipInlayGemReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPINLAYGEM_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipGemSlotUnlock(TemplateId,Pos,BagContainerType,SlotPos,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipGemSlotUnlockAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	PB.SlotPos = SlotPos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipGemSlotUnlockReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPGEMSLOTUNLOCK_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipEnhanceSwap(TemplateId1,Pos1,TemplateId2,Pos2,BagContainerType1,BagContainerType2,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipEnhanceSwapAsk()
	PB.TemplateId1 = TemplateId1
	PB.Pos1 = Pos1
	PB.TemplateId2 = TemplateId2
	PB.Pos2 = Pos2
	PB.BagContainerType1 = BagContainerType1
	PB.BagContainerType2 = BagContainerType2
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipEnhanceSwapReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPENHANCESWAP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:EquipGemRemove(TemplateId,Pos,BagContainerType,SlotPos,_hanlder)
	local PB = self.rpc_pb.BagRpcEquipGemRemoveAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.BagContainerType = BagContainerType
	PB.SlotPos = SlotPos
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcEquipGemRemoveReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_EQUIPGEMREMOVE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:BagPutInStorage(TemplateId,Pos,Num,_hanlder)
	local PB = self.rpc_pb.BagRpcBagPutInStorageAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.Num = Num
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagPutInStorageReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGPUTINSTORAGE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:BagFetchFromStorage(TemplateId,Pos,Num,_hanlder)
	local PB = self.rpc_pb.BagRpcBagFetchFromStorageAsk()
	PB.TemplateId = TemplateId
	PB.Pos = Pos
	PB.Num = Num
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagFetchFromStorageReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGFETCHFROMSTORAGE_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:BagStorageSaveMoney(Money,_hanlder)
	local PB = self.rpc_pb.BagRpcBagStorageSaveMoneyAsk()
	PB.Money = Money
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagStorageSaveMoneyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGSTORAGESAVEMONEY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:BagStorageDrawMoney(Money,_hanlder)
	local PB = self.rpc_pb.BagRpcBagStorageDrawMoneyAsk()
	PB.Money = Money
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagStorageDrawMoneyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGSTORAGEDRAWMONEY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:StorageTidy(_hanlder)
	local PB = self.rpc_pb.BagRpcStorageTidyAsk()
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcStorageTidyReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_STORAGETIDY_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:TalismanLvup(CostTalisman,_hanlder)
	local PB = self.rpc_pb.BagRpcTalismanLvupAsk()
	for i,v in ipairs(CostTalisman) do
		table.insert(PB.CostTalisman,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTalismanLvupReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TALISMANLVUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:TalismanInherit(RightSideTalisman,_hanlder)
	local PB = self.rpc_pb.BagRpcTalismanInheritAsk()
	PB.RightSideTalisman = RightSideTalisman
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTalismanInheritReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TALISMANINHERIT_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:BagSetAutoPickup(AutoPick,_hanlder)
	local PB = self.rpc_pb.BagRpcBagSetAutoPickupAsk()
	for i,v in ipairs(AutoPick) do
		table.insert(PB.AutoPick,v)
	end
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcBagSetAutoPickupReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_BAGSETAUTOPICKUP_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:TalismanRefindStar(FabaoId,_hanlder)
	local PB = self.rpc_pb.BagRpcTalismanRefindStarAsk()
	PB.FabaoId = FabaoId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTalismanRefindStarReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TALISMANREFINDSTAR_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:TalismanUpSlotSkillLevel(FabaoId,SlotId,_hanlder)
	local PB = self.rpc_pb.BagRpcTalismanUpSlotSkillLevelAsk()
	PB.FabaoId = FabaoId
	PB.SlotId = SlotId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTalismanUpSlotSkillLevelReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TALISMANUPSLOTSKILLLEVEL_REQUEST, pb_data, callback)
	self:showNetTip()
end
function BagModel:TalismanGatherSprite(FabaoId,GatherSpriteId,SlotId,_hanlder)
	local PB = self.rpc_pb.BagRpcTalismanGatherSpriteAsk()
	PB.FabaoId = FabaoId
	PB.GatherSpriteId = GatherSpriteId
	PB.SlotId = SlotId
	local pb_data = PB:SerializeToString()
	local function callback(_data)
		self:hideNetTip()
		if _hanlder then
			local ret_msg = self.rpc_pb.BagRpcTalismanGatherSpriteReply()
			ret_msg:ParseFromString(_data)
			 _hanlder(ret_msg)
		end
	end
	MLayerMgr.SendAsk(RPC_CODE_BAG_TALISMANGATHERSPRITE_REQUEST, pb_data, callback)
	self:showNetTip()
end



-- 给c层 注册服务器通知回调
function BagModel:registerBagAddNewItemCBNotify(_hanlder)
	if not self.BagAddNewItemCBNotifyCallBack then
		self.BagAddNewItemCBNotifyCallBack = {}
	end
	table.insert(self.BagAddNewItemCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BagModel:BagAddNewItemCB(notifyMsg)
	if self.BagAddNewItemCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BagRpcBagAddNewItemNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BagAddNewItemCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function BagModel:unregisterBagAddNewItemCBNotify(_hanlder)
	if nil ~= self.BagAddNewItemCBNotifyCallBack then
		for i,callback in ipairs(self.BagAddNewItemCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BagAddNewItemCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function BagModel:registerGetNewItemCBNotify(_hanlder)
	if not self.GetNewItemCBNotifyCallBack then
		self.GetNewItemCBNotifyCallBack = {}
	end
	table.insert(self.GetNewItemCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BagModel:GetNewItemCB(notifyMsg)
	if self.GetNewItemCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BagRpcGetNewItemNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.GetNewItemCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function BagModel:unregisterGetNewItemCBNotify(_hanlder)
	if nil ~= self.GetNewItemCBNotifyCallBack then
		for i,callback in ipairs(self.GetNewItemCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.GetNewItemCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function BagModel:registerBagErrorCBNotify(_hanlder)
	if not self.BagErrorCBNotifyCallBack then
		self.BagErrorCBNotifyCallBack = {}
	end
	table.insert(self.BagErrorCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BagModel:BagErrorCB(notifyMsg)
	if self.BagErrorCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BagRpcBagErrorNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.BagErrorCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function BagModel:unregisterBagErrorCBNotify(_hanlder)
	if nil ~= self.BagErrorCBNotifyCallBack then
		for i,callback in ipairs(self.BagErrorCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.BagErrorCBNotifyCallBack, i )
			end
		end
	end
end
-- 给c层 注册服务器通知回调
function BagModel:registerTalismanAttrChangeCBNotify(_hanlder)
	if not self.TalismanAttrChangeCBNotifyCallBack then
		self.TalismanAttrChangeCBNotifyCallBack = {}
	end
	table.insert(self.TalismanAttrChangeCBNotifyCallBack,_hanlder)
end
-- 收到服务器的通知，广播给c层注册的模块
function BagModel:TalismanAttrChangeCB(notifyMsg)
	if self.TalismanAttrChangeCBNotifyCallBack then
		local ret_msg = self.rpc_pb.BagRpcTalismanAttrChangeNotify() 
		 ret_msg:ParseFromString(notifyMsg)
		 for i,callback in ipairs(self.TalismanAttrChangeCBNotifyCallBack) do
			callback(ret_msg)
		end
	end
end
function BagModel:unregisterTalismanAttrChangeCBNotify(_hanlder)
	if nil ~= self.TalismanAttrChangeCBNotifyCallBack then
		for i,callback in ipairs(self.TalismanAttrChangeCBNotifyCallBack ) do
			if callback == _hanlder then
				table.remove(self.TalismanAttrChangeCBNotifyCallBack, i )
			end
		end
	end
end





askList.Bag = {}

local t = {}
t.name = "SyncData"
t.para = {}
t.hand = BagModel.SyncData
t.pb = BagRpc_pb.BagRpcSyncDataAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "Sell"
t.para = {{name="ItemID",t=1},{name="Pos",t=1},{name="Num",t=1}}
t.hand = BagModel.Sell
t.pb = BagRpc_pb.BagRpcSellAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "Decompose"
t.para = {{name="ItemID",t=1},{name="Pos",t=1}}
t.hand = BagModel.Decompose
t.pb = BagRpc_pb.BagRpcDecomposeAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "Use"
t.para = {{name="ItemID",t=1},{name="Pos",t=1}}
t.hand = BagModel.Use
t.pb = BagRpc_pb.BagRpcUseAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipWear"
t.para = {{name="ItemId",t=1},{name="BagPos",t=1}}
t.hand = BagModel.EquipWear
t.pb = BagRpc_pb.BagRpcEquipWearAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipUndress"
t.para = {{name="ItemId",t=1},{name="EquipPos",t=1}}
t.hand = BagModel.EquipUndress
t.pb = BagRpc_pb.BagRpcEquipUndressAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipEnhance"
t.para = {{name="ItemId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1},{name="Lv",t=1}}
t.hand = BagModel.EquipEnhance
t.pb = BagRpc_pb.BagRpcEquipEnhanceAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipPolished"
t.para = {{name="ItemId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1}}
t.hand = BagModel.EquipPolished
t.pb = BagRpc_pb.BagRpcEquipPolishedAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipPolishedReplace"
t.para = {{name="ItemId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1}}
t.hand = BagModel.EquipPolishedReplace
t.pb = BagRpc_pb.BagRpcEquipPolishedReplaceAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagTidy"
t.para = {}
t.hand = BagModel.BagTidy
t.pb = BagRpc_pb.BagRpcBagTidyAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagRecycleSell"
t.para = {{name="GridList",t=3}}
t.hand = BagModel.BagRecycleSell
t.pb = BagRpc_pb.BagRpcBagRecycleSellAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagRecycleBuy"
t.para = {{name="GridPos",t=1}}
t.hand = BagModel.BagRecycleBuy
t.pb = BagRpc_pb.BagRpcBagRecycleBuyAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "UnlockGrid"
t.para = {{name="GridCount",t=1}}
t.hand = BagModel.UnlockGrid
t.pb = BagRpc_pb.BagRpcUnlockGridAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "Split"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="Num",t=1}}
t.hand = BagModel.Split
t.pb = BagRpc_pb.BagRpcSplitAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipBaseAttrPlished"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1}}
t.hand = BagModel.EquipBaseAttrPlished
t.pb = BagRpc_pb.BagRpcEquipBaseAttrPlishedAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipBaseAttrPolishedReplace"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1}}
t.hand = BagModel.EquipBaseAttrPolishedReplace
t.pb = BagRpc_pb.BagRpcEquipBaseAttrPolishedReplaceAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipExAttrModify"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1}}
t.hand = BagModel.EquipExAttrModify
t.pb = BagRpc_pb.BagRpcEquipExAttrModifyAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipInlayGem"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1},{name="SlotPos",t=1},{name="GemId",t=1},{name="GemPos",t=1}}
t.hand = BagModel.EquipInlayGem
t.pb = BagRpc_pb.BagRpcEquipInlayGemAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipGemSlotUnlock"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1},{name="SlotPos",t=1}}
t.hand = BagModel.EquipGemSlotUnlock
t.pb = BagRpc_pb.BagRpcEquipGemSlotUnlockAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipEnhanceSwap"
t.para = {{name="TemplateId1",t=1},{name="Pos1",t=1},{name="TemplateId2",t=1},{name="Pos2",t=1},{name="BagContainerType1",t=1},{name="BagContainerType2",t=1}}
t.hand = BagModel.EquipEnhanceSwap
t.pb = BagRpc_pb.BagRpcEquipEnhanceSwapAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "EquipGemRemove"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="BagContainerType",t=1},{name="SlotPos",t=1}}
t.hand = BagModel.EquipGemRemove
t.pb = BagRpc_pb.BagRpcEquipGemRemoveAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagPutInStorage"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="Num",t=1}}
t.hand = BagModel.BagPutInStorage
t.pb = BagRpc_pb.BagRpcBagPutInStorageAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagFetchFromStorage"
t.para = {{name="TemplateId",t=1},{name="Pos",t=1},{name="Num",t=1}}
t.hand = BagModel.BagFetchFromStorage
t.pb = BagRpc_pb.BagRpcBagFetchFromStorageAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagStorageSaveMoney"
t.para = {{name="Money",t=1}}
t.hand = BagModel.BagStorageSaveMoney
t.pb = BagRpc_pb.BagRpcBagStorageSaveMoneyAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagStorageDrawMoney"
t.para = {{name="Money",t=1}}
t.hand = BagModel.BagStorageDrawMoney
t.pb = BagRpc_pb.BagRpcBagStorageDrawMoneyAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "StorageTidy"
t.para = {}
t.hand = BagModel.StorageTidy
t.pb = BagRpc_pb.BagRpcStorageTidyAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "TalismanLvup"
t.para = {{name="CostTalisman",t=1}}
t.hand = BagModel.TalismanLvup
t.pb = BagRpc_pb.BagRpcTalismanLvupAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "TalismanInherit"
t.para = {{name="RightSideTalisman",t=1}}
t.hand = BagModel.TalismanInherit
t.pb = BagRpc_pb.BagRpcTalismanInheritAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "BagSetAutoPickup"
t.para = {{name="AutoPick",t=3}}
t.hand = BagModel.BagSetAutoPickup
t.pb = BagRpc_pb.BagRpcBagSetAutoPickupAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "TalismanRefindStar"
t.para = {{name="FabaoId",t=1}}
t.hand = BagModel.TalismanRefindStar
t.pb = BagRpc_pb.BagRpcTalismanRefindStarAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "TalismanUpSlotSkillLevel"
t.para = {{name="FabaoId",t=1},{name="SlotId",t=1}}
t.hand = BagModel.TalismanUpSlotSkillLevel
t.pb = BagRpc_pb.BagRpcTalismanUpSlotSkillLevelAsk()
table.insert(askList.Bag,t)

local t = {}
t.name = "TalismanGatherSprite"
t.para = {{name="FabaoId",t=1},{name="GatherSpriteId",t=1},{name="SlotId",t=1}}
t.hand = BagModel.TalismanGatherSprite
t.pb = BagRpc_pb.BagRpcTalismanGatherSpriteAsk()
table.insert(askList.Bag,t)

