/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ZhanDouDBCache.cpp
* Author:       甘业清
* Description:  战斗数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "ZhanDouDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataZhanDou);

//战斗实现类构造函数
DataZhanDou::DataZhanDou()
{
	m_mapDataWraperVersionName[1] = "ZhanDouUserDataWraperV1";
	
}

//战斗实现类析构函数
DataZhanDou::~DataZhanDou()
{

}


//获取模块ID
UINT8 DataZhanDou::GetModuleId()
{
	return MODULE_ID_ZHANDOU;
}

//获取模块名字
TStr DataZhanDou::GetModuleName()
{
	return "ZhanDou";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataZhanDou::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataZhanDou::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataZhanDou::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataZhanDou::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataZhanDou::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	ZhanDouUserDataWraperV1* pDataWraper = (ZhanDouUserDataWraperV1*)GetModuleData(key);
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
