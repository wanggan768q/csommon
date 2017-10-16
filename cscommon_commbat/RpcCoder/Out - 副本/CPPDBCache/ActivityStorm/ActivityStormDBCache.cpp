/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ActivityStormDBCache.cpp
* Author:       甘业清
* Description:  活动 风暴数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "ActivityStormDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataActivityStorm);

//活动 风暴实现类构造函数
DataActivityStorm::DataActivityStorm()
{
	m_mapDataWraperVersionName[1] = "ActivityStormActivityStormWraperV1";
	
}

//活动 风暴实现类析构函数
DataActivityStorm::~DataActivityStorm()
{

}


//获取模块ID
UINT8 DataActivityStorm::GetModuleId()
{
	return MODULE_ID_ACTIVITYSTORM;
}

//获取模块名字
TStr DataActivityStorm::GetModuleName()
{
	return "ActivityStorm";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataActivityStorm::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataActivityStorm::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataActivityStorm::GetSavedDataType()
{
	return SAVE_MODULE_DATA;
}

//是否保存数据到数据库中
bool DataActivityStorm::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataActivityStorm::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	ActivityStormActivityStormWraperV1* pDataWraper = (ActivityStormActivityStormWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_ACTIVITYSTORM_TYPE:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetType(iValue);
		break;
	case SYNCID_ACTIVITYSTORM_TIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTime(iValue);
		break;
	case SYNCID_ACTIVITYSTORM_ACTID:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetActID(iValue);
		break;
	case SYNCID_ACTIVITYSTORM_LVD:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetLvD(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
