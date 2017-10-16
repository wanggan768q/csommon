/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     MMOMapDataDBCache.cpp
* Author:       甘业清
* Description:  45度MMO地图数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "MMOMapDataDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataMMOMapData);

//45度MMO地图数据实现类构造函数
DataMMOMapData::DataMMOMapData()
{
	m_mapDataWraperVersionName[1] = "MMOMapDataUselessWraperV1";
	
}

//45度MMO地图数据实现类析构函数
DataMMOMapData::~DataMMOMapData()
{

}


//获取模块ID
UINT8 DataMMOMapData::GetModuleId()
{
	return MODULE_ID_MMOMAPDATA;
}

//获取模块名字
TStr DataMMOMapData::GetModuleName()
{
	return "MMOMapData";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataMMOMapData::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataMMOMapData::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataMMOMapData::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataMMOMapData::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataMMOMapData::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	MMOMapDataUselessWraperV1* pDataWraper = (MMOMapDataUselessWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
