/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     BagDBCache.cpp
* Author:       甘业清
* Description:  背包数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "BagDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataBag);

//背包实现类构造函数
DataBag::DataBag()
{
	m_mapDataWraperVersionName[1] = "BagPackageDataWraperV1";
	
}

//背包实现类析构函数
DataBag::~DataBag()
{

}


//获取模块ID
UINT8 DataBag::GetModuleId()
{
	return MODULE_ID_BAG;
}

//获取模块名字
TStr DataBag::GetModuleName()
{
	return "Bag";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataBag::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataBag::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataBag::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataBag::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataBag::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	BagPackageDataWraperV1* pDataWraper = (BagPackageDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_BAG_GRIDARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearGridArray();
			break;
		}
		if (Index >= pDataWraper->SizeGridArray())
		{
			int Count = Index -pDataWraper->SizeGridArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddGridArray(BagGridInfoWraperV1());
		}
		{
			BagGridInfoWraperV1 tmpGridArrayWraper;
			tmpGridArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetGridArray(Index,tmpGridArrayWraper);
		}
		break;
	case SYNCID_BAG_EQUIPALLDATA:
		if( Index<0 )
		{
			pDataWraper->ClearEquipAllData();
			break;
		}
		if (Index >= pDataWraper->SizeEquipAllData())
		{
			int Count = Index -pDataWraper->SizeEquipAllData() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddEquipAllData(BagEquipObjWraper());
		}
		{
			BagEquipObjWraper tmpEquipAllDataWraper;
			tmpEquipAllDataWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetEquipAllData(Index,tmpEquipAllDataWraper);
		}
		break;
	case SYNCID_BAG_WEAREQUIPCONTAINER:
		if( Index<0 )
		{
			pDataWraper->ClearWearEquipContainer();
			break;
		}
		if (Index >= pDataWraper->SizeWearEquipContainer())
		{
			int Count = Index -pDataWraper->SizeWearEquipContainer() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddWearEquipContainer(BagGridInfoWraperV1());
		}
		{
			BagGridInfoWraperV1 tmpWearEquipContainerWraper;
			tmpWearEquipContainerWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetWearEquipContainer(Index,tmpWearEquipContainerWraper);
		}
		break;
	case SYNCID_BAG_STORAGEBAGGRID:
		if( Index<0 )
		{
			pDataWraper->ClearStorageBagGrid();
			break;
		}
		if (Index >= pDataWraper->SizeStorageBagGrid())
		{
			int Count = Index -pDataWraper->SizeStorageBagGrid() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddStorageBagGrid(BagGridInfoWraperV1());
		}
		{
			BagGridInfoWraperV1 tmpStorageBagGridWraper;
			tmpStorageBagGridWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetStorageBagGrid(Index,tmpStorageBagGridWraper);
		}
		break;
	case SYNCID_BAG_STORAGEBANK:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetStorageBank(iValue);
		break;
	case SYNCID_BAG_TALISMANDATA:
		if( Index<0 )
		{
			pDataWraper->ClearTalismanData();
			break;
		}
		if (Index >= pDataWraper->SizeTalismanData())
		{
			int Count = Index -pDataWraper->SizeTalismanData() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddTalismanData(BagTalismanObjWraperV1());
		}
		{
			BagTalismanObjWraperV1 tmpTalismanDataWraper;
			tmpTalismanDataWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetTalismanData(Index,tmpTalismanDataWraper);
		}
		break;
	case SYNCID_BAG_TALISMANFOREVERATTR:
		if( Index<0 )
		{
			pDataWraper->ClearTalismanForeverAttr();
			break;
		}
		if (Index >= pDataWraper->SizeTalismanForeverAttr())
		{
			int Count = Index -pDataWraper->SizeTalismanForeverAttr() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddTalismanForeverAttr(-1);
		}
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTalismanForeverAttr(Index,iValue);
		break;
	case SYNCID_BAG_AUTOPICKUP:
		if( Index<0 )
		{
			pDataWraper->ClearAutoPickup();
			break;
		}
		if (Index >= pDataWraper->SizeAutoPickup())
		{
			int Count = Index -pDataWraper->SizeAutoPickup() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddAutoPickup(KeyValue2IntBoolWraper());
		}
		{
			KeyValue2IntBoolWraper tmpAutoPickupWraper;
			tmpAutoPickupWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetAutoPickup(Index,tmpAutoPickupWraper);
		}
		break;
	case SYNCID_BAG_USEITEMDAY:
		if( Index<0 )
		{
			pDataWraper->ClearUseItemDay();
			break;
		}
		if (Index >= pDataWraper->SizeUseItemDay())
		{
			int Count = Index -pDataWraper->SizeUseItemDay() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddUseItemDay(KeyValue2IntIntWraper());
		}
		{
			KeyValue2IntIntWraper tmpUseItemDayWraper;
			tmpUseItemDayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetUseItemDay(Index,tmpUseItemDayWraper);
		}
		break;
	case SYNCID_BAG_USEITEMWEEK:
		if( Index<0 )
		{
			pDataWraper->ClearUseItemWeek();
			break;
		}
		if (Index >= pDataWraper->SizeUseItemWeek())
		{
			int Count = Index -pDataWraper->SizeUseItemWeek() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddUseItemWeek(KeyValue2IntIntWraper());
		}
		{
			KeyValue2IntIntWraper tmpUseItemWeekWraper;
			tmpUseItemWeekWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetUseItemWeek(Index,tmpUseItemWeekWraper);
		}
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
