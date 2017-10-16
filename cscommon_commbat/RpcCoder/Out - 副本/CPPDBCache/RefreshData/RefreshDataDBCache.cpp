/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     RefreshDataDBCache.cpp
* Author:       甘业清
* Description:  刷新数据数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "RefreshDataDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataRefreshData);

//刷新数据实现类构造函数
DataRefreshData::DataRefreshData()
{
	m_mapDataWraperVersionName[1] = "RefreshDataRefreshDataWraperV1";
	
}

//刷新数据实现类析构函数
DataRefreshData::~DataRefreshData()
{

}


//获取模块ID
UINT8 DataRefreshData::GetModuleId()
{
	return MODULE_ID_REFRESHDATA;
}

//获取模块名字
TStr DataRefreshData::GetModuleName()
{
	return "RefreshData";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataRefreshData::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataRefreshData::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataRefreshData::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataRefreshData::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataRefreshData::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	RefreshDataRefreshDataWraperV1* pDataWraper = (RefreshDataRefreshDataWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_REFRESHDATA_LASTREFRESHTIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetLastRefreshTime(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
