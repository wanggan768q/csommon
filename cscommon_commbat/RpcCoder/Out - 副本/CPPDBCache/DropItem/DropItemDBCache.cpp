/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     DropItemDBCache.cpp
* Author:       甘业清
* Description:  掉落物数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "DropItemDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataDropItem);

//掉落物实现类构造函数
DataDropItem::DataDropItem()
{
	m_mapDataWraperVersionName[1] = "DropItemDropItemWraperV1";
	
}

//掉落物实现类析构函数
DataDropItem::~DataDropItem()
{

}


//获取模块ID
UINT8 DataDropItem::GetModuleId()
{
	return MODULE_ID_DROPITEM;
}

//获取模块名字
TStr DataDropItem::GetModuleName()
{
	return "DropItem";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataDropItem::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataDropItem::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataDropItem::GetSavedDataType()
{
	return SAVE_MODULE_DATA;
}

//是否保存数据到数据库中
bool DataDropItem::IsSaveModuleDataToDB()
{

	return false;
}

//增量更新通知
bool DataDropItem::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	DropItemDropItemWraperV1* pDataWraper = (DropItemDropItemWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_DROPITEM_DROPITEM:
		if( Index<0 )
		{
			pDataWraper->ClearDropItem();
			break;
		}
		if (Index >= pDataWraper->SizeDropItem())
		{
			int Count = Index -pDataWraper->SizeDropItem() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddDropItem(DropItemObjWraper());
		}
		{
			DropItemObjWraper tmpDropItemWraper;
			tmpDropItemWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetDropItem(Index,tmpDropItemWraper);
		}
		break;
	case SYNCID_DROPITEM_EQUIPALLDATA:
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

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
