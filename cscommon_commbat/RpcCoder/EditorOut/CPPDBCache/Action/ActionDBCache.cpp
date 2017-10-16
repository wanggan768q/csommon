/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ActionDBCache.cpp
* Author:       甘业清
* Description:  Action数据类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "ActionDBCache.h"
#include "BASE.h"


IMPLEMENT_INSTANCE(DataAction);

//Action实现类构造函数
DataAction::DataAction()
{
	m_mapDataWraperVersionName[1] = "ActionUselessWraperV1";
	
}

//Action实现类析构函数
DataAction::~DataAction()
{

}


//获取模块ID
UINT8 DataAction::GetModuleId()
{
	return MODULE_ID_ACTION;
}

//获取模块名字
TStr DataAction::GetModuleName()
{
	return "Action";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> DataAction::GetDataWraperVersionName()
{

	return m_mapDataWraperVersionName;
}

//模块同步(保存)数据升级函数
bool DataAction::UpdateModuleData(ModuleDataInterface* pre, ModuleDataInterface* cur )
{
	
	return true;
}
//模块数据保存类型
SavedDataTypeE	DataAction::GetSavedDataType()
{
	return SAVE_USER_DATA;
}

//是否保存数据到数据库中
bool DataAction::IsSaveModuleDataToDB()
{

	return true;
}

//增量更新通知
bool DataAction::OnIncrementUpdate( INT64 key, int syncId, int Index, const char* pBuffer, int dataLen )
{
	ActionUselessWraperV1* pDataWraper = (ActionUselessWraperV1*)GetModuleData(key);
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
