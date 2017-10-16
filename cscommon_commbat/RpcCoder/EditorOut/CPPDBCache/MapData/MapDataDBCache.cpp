/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     MapDataDBCache.cpp
* Author:       甘业清
* Description:  场景数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "MapDataDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataMapData);

//场景数据实现类构造函数
DataMapData::DataMapData()
{
	m_mapDataWraperVersionName[1] = "MapDataUselessWraperV1";
	
}

//场景数据实现类析构函数
DataMapData::~DataMapData()
{

}


//获取模块ID
UINT8 DataMapData::GetModuleId()
{
	return MODULE_ID_MAPDATA;
}

//获取模块名字
TStr DataMapData::GetModuleName()
{
	return "MapData";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataMapData::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataMapData::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataMapData::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataMapData::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataMapData::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	MapDataUselessWraperV1* pDataWraper = (MapDataUselessWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_MAPDATA_X1:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetX1(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
