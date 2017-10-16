/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ActivityScheduleDBCache.cpp
* Author:       甘业清
* Description:  活动日常数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "ActivityScheduleDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataActivitySchedule);

//活动日常实现类构造函数
DataActivitySchedule::DataActivitySchedule()
{
	m_mapDataWraperVersionName[1] = "ActivityScheduleActiveDateWraperV1";
	
}

//活动日常实现类析构函数
DataActivitySchedule::~DataActivitySchedule()
{

}


//获取模块ID
UINT8 DataActivitySchedule::GetModuleId()
{
	return MODULE_ID_ACTIVITYSCHEDULE;
}

//获取模块名字
TStr DataActivitySchedule::GetModuleName()
{
	return "ActivitySchedule";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataActivitySchedule::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataActivitySchedule::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataActivitySchedule::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataActivitySchedule::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataActivitySchedule::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	ActivityScheduleActiveDateWraperV1* pDataWraper = (ActivityScheduleActiveDateWraperV1*)GetModuleData(key);
	if( pDataWraper == NULL )
	{
		assert(false);
		return false;
	}
	
	INT64 lValue = 0;
	int   iValue = 0;
	
	switch (syncId)
	{
	case SYNCID_ACTIVITYSCHEDULE_VALUE:
		if( Index<0 )
		{
			pDataWraper->ClearValue();
			break;
		}
		if (Index >= pDataWraper->SizeValue())
		{
			int Count = Index -pDataWraper->SizeValue() + 1;
			for (int i = 0; i < Count; i++)
				pDataWraper->AddValue(ActivityScheduleActiveValueWraperV1());
		}
		{
			ActivityScheduleActiveValueWraperV1 tmpValueWraper;
			tmpValueWraper.ParseFromArray(pBuffer,dataLen);
			pDataWraper->SetValue(Index,tmpValueWraper);
		}
		break;
	case SYNCID_ACTIVITYSCHEDULE_TIME:
		ReadVarint32FromArray(pBuffer,&iValue);
		pDataWraper->SetTime(iValue);
		break;

	default:
		break;
	}
	pDataWraper->OnDataChange();
	lValue ++;
	iValue ++;
	return true;
}
