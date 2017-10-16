/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     TestModuleDBCache.cpp
* Author:       甘业清
* Description:  TestModule数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "TestModuleDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataTestModule);

//TestModule实现类构造函数
DataTestModule::DataTestModule()
{
	m_mapDataWraperVersionName[1] = "TestModuleUselessWraperV1";
	
}

//TestModule实现类析构函数
DataTestModule::~DataTestModule()
{

}


//获取模块ID
UINT8 DataTestModule::GetModuleId()
{
	return MODULE_ID_TESTMODULE;
}

//获取模块名字
TStr DataTestModule::GetModuleName()
{
	return "TestModule";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataTestModule::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataTestModule::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataTestModule::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataTestModule::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataTestModule::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	TestModuleUselessWraperV1* pDataWraper = (TestModuleUselessWraperV1*)GetModuleData(key);
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
