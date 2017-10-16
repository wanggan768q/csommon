/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     DramaModuleDBCache.cpp
* Author:       甘业清
* Description:  剧情模块数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "DramaModuleDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataDramaModule);

//剧情模块实现类构造函数
DataDramaModule::DataDramaModule()
{
	m_mapDataWraperVersionName[1] = "DramaModuleUseLessWraperV1";
	
}

//剧情模块实现类析构函数
DataDramaModule::~DataDramaModule()
{

}


//获取模块ID
UINT8 DataDramaModule::GetModuleId()
{
	return MODULE_ID_DRAMAMODULE;
}

//获取模块名字
TStr DataDramaModule::GetModuleName()
{
	return "DramaModule";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataDramaModule::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataDramaModule::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataDramaModule::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataDramaModule::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataDramaModule::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	DramaModuleUseLessWraperV1* pDataWraper = (DramaModuleUseLessWraperV1*)GetModuleData(key);
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
