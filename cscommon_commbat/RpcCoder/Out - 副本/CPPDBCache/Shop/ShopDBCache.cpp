/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ShopDBCache.cpp
* Author:       甘业清
* Description:  商城数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "ShopDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataShop);

//商城实现类构造函数
DataShop::DataShop()
{
	m_mapDataWraperVersionName[1] = "ShopShopDataWraperV1";
	
}

//商城实现类析构函数
DataShop::~DataShop()
{

}


//获取模块ID
UINT8 DataShop::GetModuleId()
{
	return MODULE_ID_SHOP;
}

//获取模块名字
TStr DataShop::GetModuleName()
{
	return "Shop";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataShop::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataShop::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataShop::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataShop::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataShop::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	ShopShopDataWraperV1* pDataWraper = (ShopShopDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_SHOP_SHOPARRAY:
		if( Index<0 )
		{
			pDataWraper->ClearShopArray();
			break;
		}
		if (Index >= pDataWraper->SizeShopArray())
		{
			int Count = Index -pDataWraper->SizeShopArray() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddShopArray(ShopShopObjWraperV1());
		}
		{
			ShopShopObjWraperV1 tmpShopArrayWraper;
			tmpShopArrayWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetShopArray(Index,tmpShopArrayWraper);
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
